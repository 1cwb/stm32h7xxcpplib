#pragma once
#include "rtoscommon.h"

class mIpc
{
public:
    mIpc()
    {
    }
    ~mIpc()
    {

    }
    mIpc(const mIpc&) = delete;
    mIpc(mIpc&&) = delete;
    mIpc& operator=(const mIpc&) = delete;
    mIpc& operator=(mIpc&&) = delete;
    /**
     * This function will initialize an IPC object
     *
     * @param ipc the IPC object
     *
     * @return the operation status, RT_EOK on successful
     */
    mResult ipcObjectInit(mIpcObject_t* ipcObj);
    /**
     * This function will suspend a thread to a specified list. IPC object or some
     * double-queue object (mailbox etc.) contains this kind of list.
     *
     * @param list the IPC suspended thread list
     * @param thread the thread object to be suspended
     * @param flag the IPC object flag,
     *        which shall be RT_IPC_FLAG_FIFO/RT_IPC_FLAG_PRIO.
     *
     * @return the operation status, RT_EOK on successful
     */
    mResult ipcListSuspend(mIpcObject_t* ipcObj, struct thread_t *thread, mIpcFlag flag);

    /**
     * This function will resume the first thread in the list of a IPC object:
     * - remove the thread from suspend queue of IPC object
     * - put the thread into system ready queue
     *
     * @param list the thread list
     *
     * @return the operation status, RT_EOK on successful
     */
    mResult ipcListResume(mIpcObject_t* ipcObj);

    /**
     * This function will resume all suspended threads in a list, including
     * suspend list of IPC object and private list of mailbox etc.
     *
     * @param list of the threads to resume
     *
     * @return the operation status, RT_EOK on successful
     */
    mResult ipcListResumeAll(mIpcObject_t* ipcObj);
};

class mSemaphore : public mIpc
{
public:
    mSemaphore()
    {
    }
    ~mSemaphore()
    {

    }
    mSemaphore(const mSemaphore&) = delete;
    mSemaphore(mSemaphore&&) = delete;
    mSemaphore& operator=(const mSemaphore&) = delete;
    mSemaphore& operator=(mSemaphore&&) = delete;

    static mSemaphore* semCreate(const char *name, uint32_t value, mIpcFlag flag)
    {
        mSemaphore* sem = new mSemaphore;
        if(sem)
        {
            sem->semCreateEx(name, value, flag);
            return sem;
        }
        return nullptr;
    }
    /**
     * This function will delete a semaphore object and release the memory
     *
     * @param sem the semaphore object
     *
     * @return the error code
     *
     * @see rt_sem_detach
     */
    mResult semDelete();
        /**
     * This function will initialize a semaphore and put it under control of
     * resource management.
     *
     * @param sem the semaphore object
     * @param name the name of semaphore
     * @param value the initial value of semaphore
     * @param flag the flag of semaphore
     *
     * @return the operation status, RT_EOK on successful
     */
    mResult init(const char *name, uint32_t value, mIpcFlag flag);
    /**
     * This function will detach a semaphore from resource management
     *
     * @param sem the semaphore object
     *
     * @return the operation status, RT_EOK on successful
     *
     * @see rt_sem_delete
     */
    mResult detach();
    /**
     * This function will take a semaphore, if the semaphore is unavailable, the
     * thread shall wait for a specified time.
     *
     * @param sem the semaphore object
     * @param time the waiting time
     *
     * @return the error code
     */
    mResult semTake(int32_t time);

    /**
     * This function will try to take a semaphore and immediately return
     *
     * @param sem the semaphore object
     *
     * @return the error code
     */
    mResult semTrytake();

    /**
     * This function will release a semaphore, if there are threads suspended on
     * semaphore, it will be waked up.
     *
     * @param sem the semaphore object
     *
     * @return the error code
     */
    mResult semRelease();

    /**
     * This function can get or set some extra attributions of a semaphore object.
     *
     * @param sem the semaphore object
     * @param cmd the execution command
     * @param arg the execution argument
     *
     * @return the error code
     */
    mResult semControl(mIpcCmd cmd, void *arg);
private:

        /**
     * This function will create a semaphore from system resource
     *
     * @param name the name of semaphore
     * @param value the initial value of semaphore
     * @param flag the flag of semaphore
     *
     * @return the created semaphore, RT_NULL on error happen
     *
     * @see rt_sem_init
     */
    mResult semCreateEx(const char *name, uint32_t value, mIpcFlag flag);

private:
    mSemaphore_t sem_;
};
