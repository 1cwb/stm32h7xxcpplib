#include "mipc.h"
#include "mthread.h"

/**
 * This function will initialize an IPC object
 *
 * @param ipc the IPC object
 *
 * @return the operation status, RT_EOK on successful
 */
inline mResult mIpc::ipcObjectInit(mIpcObject_t* ipcObj)
{
    return M_RESULT_EOK;
}
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
inline mResult  mIpc::ipcListSuspend(mIpcObject_t* ipcObj, struct thread_t *thread, mIpcFlag flag)
{
    /* suspend thread */
    mthread::threadSuspend(thread);
    switch (flag)
    {
    case IPC_FLAG_FIFO:
        thread->tlist.insertBeforeTo(&ipcObj->suspendThread);
        break;

    case IPC_FLAG_PRIO:
        {
            struct mList_t *n;
            struct thread_t *sthread;

            /* find a suitable position */
            for (n = ipcObj->suspendThread.next; n != &ipcObj->suspendThread; n = n->next)
            {
                sthread = listEntry(n, struct thread_t, tlist);

                /* find out */
                if (thread->currentPriority < sthread->currentPriority)
                {
                    /* insert this thread before the sthread */
                    thread->tlist.insertBeforeTo(&(sthread->tlist));
                    break;
                }
            }

            /*
            * not found a suitable position,
            * append to the end of suspend_thread list
            */
            if (n == &ipcObj->suspendThread)
            {
                thread->tlist.insertBeforeTo(&ipcObj->suspendThread);
            }
        }
        break;

    default:
        break;
    }

    return M_RESULT_EOK;
}

/**
 * This function will resume the first thread in the list of a IPC object:
 * - remove the thread from suspend queue of IPC object
 * - put the thread into system ready queue
 *
 * @param list the thread list
 *
 * @return the operation status, RT_EOK on successful
 */
inline mResult  mIpc::ipcListResume(mIpcObject_t* ipcObj)
{
    struct thread_t *thread;

    /* get thread entry */
    thread = listEntry(ipcObj->suspendThread.next, struct thread_t, tlist);

    //RT_DEBUG_LOG(RT_DEBUG_IPC, ("resume thread:%s\n", thread->name));

    /* resume it */
    reinterpret_cast<mthread*>(thread)->threadResume();
    return M_RESULT_EOK;
}

/**
 * This function will resume all suspended threads in a list, including
 * suspend list of IPC object and private list of mailbox etc.
 *
 * @param list of the threads to resume
 *
 * @return the operation status, RT_EOK on successful
 */
inline mResult mIpc::ipcListResumeAll(mIpcObject_t* ipcObj)
{
    struct thread_t *thread;
    register unsigned long temp;

    /* wakeup all suspended threads */
    while (!ipcObj->suspendThread.isEmpty())
    {
        /* disable interrupt */
        temp = HW::hwInterruptDisable();

        /* get next suspended thread */
        thread = listEntry(ipcObj->suspendThread.next, struct thread_t, tlist);
        /* set error code to RT_ERROR */
        thread->error = -M_RESULT_ERROR;

        /*
        * resume thread
        * In rt_thread_resume function, it will remove current thread from
        * suspended list
        */
        reinterpret_cast<mthread*>(thread)->threadResume();

        /* enable interrupt */
        HW::hwInterruptEnable(temp);
    }

    return M_RESULT_EOK;
}
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
mResult  mSemaphore::init(const char *name, uint32_t value, mIpcFlag flag)
{
    MASSERT(value < 0x10000U);

    /* initialize object */
    mObject::getInstance()->objectInit((mObject_t*)(this),M_OBJECT_CLASS_SEMAPHORE, name);

    /* initialize ipc object */
    ipcObjectInit(reinterpret_cast<mIpcObject_t*>(&sem_));

    /* set initial value */
    sem_.value = (uint16_t)value;

    /* set parent */
    sem_.flag = flag;
    return M_RESULT_EOK;
}
/**
 * This function will detach a semaphore from resource management
 *
 * @param sem the semaphore object
 *
 * @return the operation status, RT_EOK on successful
 *
 * @see rt_sem_delete
 */
mResult  mSemaphore::detach()
{
    /* parameter check */
    MASSERT(mObject::getInstance()->objectGetType((mObject_t*)&sem_) == M_OBJECT_CLASS_SEMAPHORE);
    MASSERT(mObject::getInstance()->objectIsSystemobject((mObject_t*)&sem_));

    /* wakeup all suspended threads */
    ipcListResumeAll(reinterpret_cast<mIpcObject_t*>(&sem_));

    /* detach semaphore object */
    mObject::getInstance()->objectDetach((mObject_t*)this);
    return M_RESULT_EOK;
}
/**
 * This function will take a semaphore, if the semaphore is unavailable, the
 * thread shall wait for a specified time.
 *
 * @param sem the semaphore object
 * @param time the waiting time
 *
 * @return the error code
 */
mResult  mSemaphore::semTake(int32_t time)
{
    register long temp;
    struct thread_t *thread;

    /* parameter check */
    MASSERT(mObject::getInstance()->objectGetType((mObject_t*)&sem_) == M_OBJECT_CLASS_SEMAPHORE);

    /* disable interrupt */
    temp = HW::hwInterruptDisable();

    /*RT_DEBUG_LOG(RT_DEBUG_IPC, ("thread %s take sem:%s, which value is: %d\n",
                                rt_thread_self()->name,
                                ((struct rt_object *)sem)->name,
                                sem->value));*/

    if (sem_.value > 0)
    {
        /* semaphore is available */
        sem_.value --;

        /* enable interrupt */
        HW::hwInterruptEnable(temp);
    }
    else
    {
        /* no waiting, return with timeout */
        if (time == 0)
        {
            HW::hwInterruptEnable(temp);

            return M_RESULT_ETIMEOUT;
        }
        else
        {
            /* current context checking */
            //RT_DEBUG_IN_THREAD_CONTEXT;

            /* semaphore is unavailable, push to suspend list */
            /* get current thread */
            thread = (thread_t*)mthread::threadSelf();

            /* reset thread error number */
            thread->error = M_RESULT_EOK;

            /*RT_DEBUG_LOG(RT_DEBUG_IPC, ("sem take: suspend thread - %s\n",
                                        thread->name));*/

            /* suspend thread */
            ipcListSuspend(reinterpret_cast<mIpcObject_t*>(&sem_), thread, (mIpcFlag)(sem_.flag));

            /* has waiting time, start thread timer */
            if (time > 0)
            {
                /*RT_DEBUG_LOG(RT_DEBUG_IPC, ("set thread:%s to timer list\n",
                                            thread->name));*/

                /* reset the timeout of thread timer and start it */
                reinterpret_cast<mthread*>(thread)->getThTimer()->timerControl(TIMER_CTRL_SET_TIME, &time);
                reinterpret_cast<mthread*>(thread)->getThTimer()->start();
            }

            /* enable interrupt */
            HW::hwInterruptEnable(temp);

            /* do schedule */
            mSchedule::getInstance()->schedule();

            if (thread->error != M_RESULT_EOK)
            {
                return (mResult)thread->error;
            }
        }
    }

    return M_RESULT_EOK;
}

/**
 * This function will try to take a semaphore and immediately return
 *
 * @param sem the semaphore object
 *
 * @return the error code
 */
mResult  mSemaphore::semTrytake()
{
    return semTake(0);
}

/**
 * This function will release a semaphore, if there are threads suspended on
 * semaphore, it will be waked up.
 *
 * @param sem the semaphore object
 *
 * @return the error code
 */
mResult  mSemaphore::semRelease()
{
    register long temp;
    register bool needSchedule;

    /* parameter check */
    MASSERT(mObject::getInstance()->objectGetType((mObject_t*)&sem_) == M_OBJECT_CLASS_SEMAPHORE);

    needSchedule = false;

    /* disable interrupt */
    temp = HW::hwInterruptDisable();

    /*RT_DEBUG_LOG(RT_DEBUG_IPC, ("thread %s releases sem:%s, which value is: %d\n",
                                rt_thread_self()->name,
                                ((struct rt_object *)sem)->name,
                                sem->value));*/

    if (!sem_.suspendThread.isEmpty())
    {
        /* resume the suspended thread */
        ipcListResume((mIpcObject_t*)&sem_);
        needSchedule = true;
    }
    else
    {
        if(sem_.value < SEM_VALUE_MAX)
        {
            sem_.value ++; /* increase value */
        }
        else
        {
            HW::hwInterruptEnable(temp); /* enable interrupt */
            return M_RESULT_EFULL; /* value overflowed */
        }
    }

    /* enable interrupt */
    HW::hwInterruptEnable(temp);

    /* resume a thread, re-schedule */
    if (needSchedule)
    {
        mSchedule::getInstance()->schedule();
    }
    return M_RESULT_EOK;
}

/**
 * This function can get or set some extra attributions of a semaphore object.
 *
 * @param sem the semaphore object
 * @param cmd the execution command
 * @param arg the execution argument
 *
 * @return the error code
 */
mResult  mSemaphore::rt_sem_control(mIpcCmd cmd, void *arg)
{
    long level;

    /* parameter check */

    MASSERT(mObject::getInstance()->objectGetType((mObject_t*)&sem_) == M_OBJECT_CLASS_SEMAPHORE);

    if (cmd == IPC_CMD_RESET)
    {
        unsigned long value;

        /* get value */
        value = (unsigned long)arg;
        /* disable interrupt */
        level = HW::hwInterruptDisable();

        /* resume all waiting thread */
        ipcListResumeAll((mIpcObject_t*)&sem_);

        /* set new value */
        sem_.value = (uint16_t)value;

        /* enable interrupt */
        HW::hwInterruptEnable(level);

        mSchedule::getInstance()->schedule();

        return M_RESULT_EOK;
    }

    return M_RESULT_ERROR;
}