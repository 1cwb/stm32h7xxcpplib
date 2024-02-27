#pragma once
#include "rtoscommon.hpp"
#include "mscheduler.hpp"
#include "mhw.hpp"
enum mObjectInfoType
{
    M_OBJECT_INFO_THREAD = 0,                         /**< The object is a thread. */
#ifdef M_USING_SEMAPHORE
    M_OBJECT_INFO_SEMAPHORE,                          /**< The object is a semaphore. */
#endif
#ifdef M_USING_MUTEX
    M_OBJECT_INFO_MUTEX,                              /**< The object is a mutex. */
#endif
#ifdef M_USING_EVENT
    M_OBJECT_INFO_EVENT,                              /**< The object is a event. */
#endif
#ifdef M_USING_MAILBOX
    M_OBJECT_INFO_MAILBOX,                            /**< The object is a mail box. */
#endif
#ifdef M_USING_MESSAGEQUEUE
    M_OBJECT_INFO_MESSAGEQUEUE,                       /**< The object is a message queue. */
#endif
#ifdef M_USING_MEMHEAP
    M_OBJECT_INFO_MEMHEAP,                            /**< The object is a memory heap */
#endif
#ifdef M_USING_MEMPOOL
    M_OBJECT_INFO_MEMPOOL,                            /**< The object is a memory pool. */
#endif
#ifdef M_USING_DEVICE
    M_OBJECT_INFO_DEVICE,                             /**< The object is a device */
#endif
    M_OBJECT_INFO_TIMER,                              /**< The object is a timer. */
    M_OBJECT_INFO_UNKNOWN,                            /**< The object is unknown. */
};

#define _OBJ_CONTAINER_INIT(infoType, classType, module)     \
    {\
        objectContainer[infoType].type = classType;\
        objectContainer[infoType].objectSize = sizeof(module);\
    }

class mObject
{
public:
    static mObject* getInstance()
    {
        static mObject obj;
        return &obj;
    }

    /**
     * This function will return the specified type of object information.
     *
     * @param type the type of object, which can be
     *             RT_Object_Class_Thread/Semaphore/Mutex... etc
     *
     * @return the object type information or nullptr
     */
    mObjectInformation_t *objectGetInformation(mObjectClassType type)
    {
        int index;

        for (index = 0; index < M_OBJECT_INFO_UNKNOWN; index ++)
            if (objectContainer[index].type == type) return &objectContainer[index];

        return nullptr;
    }
    /**
     * This function will return the length of object list in object container.
     *
     * @param type the type of object, which can be
     *             RT_Object_Class_Thread/Semaphore/Mutex... etc
     * @return the length of object list
     */
    int objectGetLength(mObjectClassType type)
    {
        int count = 0;
        unsigned long level;
        struct mList_t *node = nullptr;
        struct mObjectInformation_t *information = nullptr;

        information = objectGetInformation(type);
        if (information == nullptr) return 0;

        level = HW::hwInterruptDisable();
        /* get the count of objects */
 
        for(node = information->objectList.next; node != &(information->objectList); node = node->next)
        {
            count ++;
        }
        HW::hwInterruptEnable(level);

        return count;
    }
    /**
     * This function will copy the object pointer of the specified type,
     * with the maximum size specified by maxlen.
     *
     * @param type the type of object, which can be
     *             RT_Object_Class_Thread/Semaphore/Mutex... etc
     * @param pointers the pointers will be saved to
     * @param maxlen the maximum number of pointers can be saved
     *
     * @return the copied number of object pointers
     */
    int objectGetPointers(mObjectClassType type, mObject_t **pointers, int maxlen)
    {
        int index = 0;
        unsigned long level;

        struct mObject_t *object;
        struct mList_t *node = nullptr;
        struct mObjectInformation_t *information = nullptr;

        if (maxlen <= 0) return 0;

        information = objectGetInformation(type);
        if (information == nullptr) return 0;

        level = HW::hwInterruptDisable();
        /* retrieve pointer of object */
        for(node = information->objectList.next; node != &(information->objectList); node = node->next)
        {
            object = listEntry(node, mObject_t, list);

            pointers[index] = object;
            index ++;

            if (index >= maxlen) break;
        }
        HW::hwInterruptEnable(level);

        return index;
    }
    /**
     * This function will initialize an object and add it to object system
     * management.
     *
     * @param object the specified object to be initialized.
     * @param type the object type.
     * @param name the object name. In system, the object's name must be unique.
     */
    void objectInit(mObject_t *object, mObjectClassType type, const char *name)
    {
        register long temp;
        struct mList_t *node = nullptr;
        struct mObjectInformation_t *information;

        /* get object information */
        information = objectGetInformation(type);
        MASSERT(information != nullptr);

        /* check object type to avoid re-initialization */

        /* enter critical */

        mSchedule::getInstance()->enterCritical();
        /* try to find object */
        for (node = information->objectList.next; node != &(information->objectList); node = node->next)
        {
            mObject_t *obj;

            obj = listEntry(node, mObject_t, list);
            if (obj) /* skip warning when disable debug */
            {
                MASSERT(obj != object);
            }
        }

        /* leave critical */
        mSchedule::getInstance()->exitCritical();

        /* initialize object's parameters */
        /* set object type to static */
        object->type = type | M_OBJECT_CLASS_STATIC;

        /* copy name */
        strncpy(object->name, name, NAME_MAX);

        //RT_OBJECT_HOOK_CALL(rt_object_attach_hook, (object));

        /* lock interrupt */
        temp = HW::hwInterruptDisable();

        /* insert object into information object list */
        object->list.insertAfterTo(&(information->objectList));

        /* unlock interrupt */
        HW::hwInterruptEnable(temp);
    }
    /**
     * This function will detach a static object from object system,
     * and the memory of static object is not freed.
     *
     * @param object the specified object to be detached.
     */
    void objectDetach(mObject_t* object)
    {
        register long temp;

        /* object check */
        MASSERT(object != nullptr);

        //RT_OBJECT_HOOK_CALL(rt_object_detach_hook, (object));

        /* reset object type */
        object->type = 0;

        /* lock interrupt */
        temp = HW::hwInterruptDisable();

        /* remove from old list */
        object->list.removeSelf();

        /* unlock interrupt */
        HW::hwInterruptEnable(temp);
    }
    /**
     * This function will return the type of object without
     * RT_Object_Class_Static flag.
     *
     * @param object the specified object to be get type.
     *
     * @return the type of object.
     */
    uint8_t objectGetType(mObject_t* object)
    {
        /* object check */
        MASSERT(object != nullptr);

        return object->type & ~M_OBJECT_CLASS_STATIC;
    }
    /**
     * This function will judge the object is system object or not.
     * Normally, the system object is a static object and the type
     * of object set to RT_Object_Class_Static.
     *
     * @param object the specified object to be judged.
     *
     * @return RT_TRUE if a system object, RT_FALSE for others.
     */
    bool objectIsSystemobject(mObject_t* object)
    {
        /* object check */
        MASSERT(object != nullptr);

        if (object->type & M_OBJECT_CLASS_STATIC)
            return true;

        return false;
    }
    /**
     * This function will find specified name object from object
     * container.
     *
     * @param name the specified name of object.
     * @param type the type of object
     *
     * @return the found object or RT_NULL if there is no this object
     * in object container.
     *
     * @note this function shall not be invoked in interrupt status.
     */
    mObject_t* objectFind(const char *name, mObjectClassType type)
    {
        struct mObject_t *object = nullptr;
        struct mList_t *node = nullptr;
        struct mObjectInformation_t *information = nullptr;

        information = mObject::objectGetInformation(type);

        /* parameter check */
        if ((name == nullptr) || (information == nullptr)) return nullptr;

        /* which is invoke in interrupt status */
        //DEBUG_NOT_IN_INTERRUPT;

        /* enter critical */
        mSchedule::getInstance()->enterCritical();

        /* try to find object */
        for(node = information->objectList.next; node != &(information->objectList); node = node->next)
        {
            object = listEntry(node, mObject_t, list);
            if (strncmp(object->name, name, NAME_MAX) == 0)
            {
                /* leave critical */
                mSchedule::getInstance()->exitCritical();

                return object;
            }
        }

        /* leave critical */
        mSchedule::getInstance()->exitCritical();

        return nullptr;
    }

    /**@}*/

private:
    void objectInfoInit()
    {
        _OBJ_CONTAINER_INIT(M_OBJECT_INFO_THREAD, M_OBJECT_CLASS_THREAD, thread_t);
#ifdef USING_SEMAPHORE
    /* initialize object container - semaphore */
        _OBJ_CONTAINER_INIT(M_OBJECT_INFO_SEMAPHORE, M_OBJECT_CLASS_SEMAPHORE, mSemaphone);
#endif
#ifdef USING_MUTEX
    /* initialize object container - mutex */
        _OBJ_CONTAINER_INIT(M_OBJECT_INFO_MUTEX, M_OBJECT_CLASS_MUTEX, mMutex_t);
#endif
#ifdef USING_EVENT
    /* initialize object container - event */
        _OBJ_CONTAINER_INIT(M_OBJECT_INFO_EVENT, M_OBJECT_CLASS_EVENT, mEvent_t);
#endif
#ifdef USING_MAILBOX
    /* initialize object container - mailbox */
        _OBJ_CONTAINER_INIT(M_OBJECT_INFO_MAILBOX, M_OBJECT_CLASS_MAILBOX, mMailBox_t);
#endif
#ifdef USING_MESSAGEQUEUE
    /* initialize object container - message queue */
        _OBJ_CONTAINER_INIT(M_OBJECT_INFO_MESSAGEQUEUE, M_OBJECT_CLASS_MESSAGEQUEUE, mMesageQueue_t);
#endif
#ifdef USING_MEMHEAP
    /* initialize object container - memory heap */
        _OBJ_CONTAINER_INIT(M_OBJECT_INFO_MEMHEAP, M_OBJECT_CLASS_MEMHEAP, mMemHeap_t);
#endif
#ifdef USING_MEMPOOL
    /* initialize object container - memory pool */
        _OBJ_CONTAINER_INIT(M_OBJECT_INFO_MEMPOOL, M_OBJECT_CLASS_MEMPOLL, mMemPool_t);
#endif
#ifdef USING_DEVICE
    /* initialize object container - device */
        _OBJ_CONTAINER_INIT(M_OBJECT_INFO_DEVICE, M_OBJECT_CLASS_DEVICE, mDevice_t);
#endif
    /* initialize object container - timer */
        _OBJ_CONTAINER_INIT(M_OBJECT_INFO_TIMER, M_OBJECT_CLASS_TIMER, mTimer_t);
    }
private:

    mObject()
    {
        objectInfoInit();
    }
    ~mObject()
    {

    }
    mObject(const mObject&) = delete;
    mObject(mObject&&) = delete;
    mObject& operator=(const mObject&) = delete;
    mObject& operator=(mObject&&) = delete;

    mObjectInformation_t objectContainer[M_OBJECT_INFO_UNKNOWN];
};