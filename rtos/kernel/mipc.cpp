#include "mipc.h"
#include "mthread.h"

/**
 * This function will initialize an IPC object
 *
 * @param ipc the IPC object
 *
 * @return the operation status, RT_EOK on successful
 */
mResult mIpc::ipcObjectInit(mIpcObject_t* ipcObj)
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
mResult  mIpc::ipcListSuspend(mIpcObject_t* ipcObj, struct thread_t *thread, mIpcFlag flag)
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
mResult  mIpc::ipcListResume(mIpcObject_t* ipcObj)
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
mResult mIpc::ipcListResumeAll(mIpcObject_t* ipcObj)
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
        thread->error = M_RESULT_ERROR;

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
mResult mSemaphore::semCreateEx(const char *name, uint32_t value, mIpcFlag flag)
{
    //RT_DEBUG_NOT_IN_INTERRUPT;
    MASSERT(value < 0x10000U);

    /* initialize ipc object */
    mObject::getInstance()->objectAdd((mObject_t*)this, M_OBJECT_CLASS_SEMAPHORE, name);
    /* set initial value */
    sem_.value = value;

    /* set parent */
    sem_.flag = flag;

    return M_RESULT_EOK;
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
mResult mSemaphore::semDelete()
{
    //RT_DEBUG_NOT_IN_INTERRUPT;

    /* parameter check */
    MASSERT(mObject::getInstance()->objectGetType((mObject_t*)this) == M_OBJECT_CLASS_SEMAPHORE);
    MASSERT(!mObject::getInstance()->objectIsSystemobject((mObject_t*)this));

    if(mObject::getInstance()->objectIsSystemobject((mObject_t*)this))
    {
        return M_RESULT_ERROR;
    }
    /* wakeup all suspended threads */
    ipcListResumeAll(reinterpret_cast<mIpcObject_t*>(this));

    /* delete semaphore object */
    delete this;

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
    ipcListResumeAll(reinterpret_cast<mIpcObject_t*>(this));

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
mResult  mSemaphore::semControl(mIpcCmd cmd, void *arg)
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
        ipcListResumeAll((mIpcObject_t*)this);

        /* set new value */
        sem_.value = (uint16_t)value;

        /* enable interrupt */
        HW::hwInterruptEnable(level);

        mSchedule::getInstance()->schedule();

        return M_RESULT_EOK;
    }

    return M_RESULT_ERROR;
}

/**
 * This function will initialize a mutex and put it under control of resource
 * management.
 *
 * @param mutex the mutex object
 * @param name the name of mutex
 * @param flag the flag of mutex
 *
 * @return the operation status, RT_EOK on successful
 */
mResult mMutex::init(const char *name, uint8_t flag)
{
    /* initialize object */
    mObject::getInstance()->objectInit((mObject_t*)(this),M_OBJECT_CLASS_MUTEX, name);

    /* initialize ipc object */
    ipcObjectInit((mIpcObject_t*) (this));

    mutex_.value = 1;
    mutex_.owner = nullptr;
    mutex_.originalPriority = 0xFF;
    mutex_.hold = 0;

    /* set flag */
    mutex_.flag = flag;

    return M_RESULT_EOK;
}
/**
 * This function will detach a mutex from resource management
 *
 * @param mutex the mutex object
 *
 * @return the operation status, RT_EOK on successful
 *
 * @see rt_mutex_delete
 */
mResult mMutex::detach()
{
    /* parameter check */
    MASSERT(mObject::getInstance()->objectGetType((mObject_t*)this) == M_OBJECT_CLASS_MUTEX);
    MASSERT(mObject::getInstance()->objectIsSystemobject((mObject_t*)this));

    /* wakeup all suspended threads */
    ipcListResumeAll((mIpcObject_t*)this);

    /* detach semaphore object */
    mObject::getInstance()->objectDetach((mObject_t*)(this));

    return M_RESULT_EOK;
}
/**
 * This function will take a mutex, if the mutex is unavailable, the
 * thread shall wait for a specified time.
 *
 * @param mutex the mutex object
 * @param time the waiting time
 *
 * @return the error code
 */
mResult mMutex::mutexTake(int32_t time)
{
    register long temp;
    struct thread_t *thread;

    /* this function must not be used in interrupt even if time = 0 */
    //RT_DEBUG_IN_THREAD_CONTEXT;

    /* parameter check */
    MASSERT(mObject::getInstance()->objectGetType((mObject_t*)this) == M_OBJECT_CLASS_MUTEX);

    /* get current thread */
    thread = mthread::threadSelf();

    /* disable interrupt */
    temp = HW::hwInterruptDisable();

    /*RT_DEBUG_LOG(RT_DEBUG_IPC,
                 ("mutex_take: current thread %s, mutex value: %d, hold: %d\n",
                  thread->name, mutex->value, mutex->hold));*/

    /* reset thread error */
    thread->error = M_RESULT_EOK;

    if (mutex_.owner == thread)
    {
        if(mutex_.hold < MUTEX_HOLD_MAX)
        {
            /* it's the same thread */
            mutex_.hold ++;
        }
        else
        {
            HW::hwInterruptEnable(temp); /* enable interrupt */
            return M_RESULT_EFULL; /* value overflowed */
        }
    }
    else
    {
        /* The value of mutex is 1 in initial status. Therefore, if the
         * value is great than 0, it indicates the mutex is avaible.
         */
        if (mutex_.value > 0)
        {
            /* mutex is available */
            mutex_.value --;

            /* set mutex owner and original priority */
            mutex_.owner             = thread;
            mutex_.originalPriority = thread->currentPriority;
            if(mutex_.hold < MUTEX_HOLD_MAX)
            {
                mutex_.hold ++;
            }
            else
            {
                HW::hwInterruptEnable(temp); /* enable interrupt */
                return M_RESULT_EFULL; /* value overflowed */
            }
        }
        else
        {
            /* no waiting, return with timeout */
            if (time == 0)
            {
                /* set error as timeout */
                thread->error = M_RESULT_ETIMEOUT;

                /* enable interrupt */
                HW::hwInterruptEnable(temp);

                return M_RESULT_EFULL;
            }
            else
            {
                /* mutex is unavailable, push to suspend list */
                /*RT_DEBUG_LOG(RT_DEBUG_IPC, ("mutex_take: suspend thread: %s\n",
                                            thread->name));*/

                /* change the owner thread priority of mutex */
                if (thread->currentPriority < mutex_.owner->currentPriority)
                {
                    /* change the owner thread priority */
                    reinterpret_cast<mthread*>(mutex_.owner)->threadControl(THREAD_CTRL_CHANGE_PRIORITY, &thread->currentPriority);
                }

                /* suspend current thread */
                ipcListSuspend((mIpcObject_t*)this , thread, (mIpcFlag)mutex_.flag);
                
                /* has waiting time, start thread timer */
                if (time > 0)
                {
                    /*RT_DEBUG_LOG(RT_DEBUG_IPC,
                                 ("mutex_take: start the timer of thread:%s\n",
                                  thread->name));*/

                    /* reset the timeout of thread timer and start it */
                    reinterpret_cast<mthread*>(thread)->getThTimer()->setTimerAndStart(time);
                }

                /* enable interrupt */
                HW::hwInterruptEnable(temp);

                /* do schedule */
                mSchedule::getInstance()->schedule();

                if (thread->error != M_RESULT_EOK)
                {
                    /* return error */
                    return thread->error;
                }
                else
                {
                    /* the mutex is taken successfully. */
                    /* disable interrupt */
                    temp = HW::hwInterruptDisable();
                }
            }
        }
    }

    /* enable interrupt */
    HW::hwInterruptEnable(temp);

    //RT_OBJECT_HOOK_CALL(rt_object_take_hook, (&(mutex->parent.parent)));

    return M_RESULT_EOK;
}

/**
 * This function will release a mutex, if there are threads suspended on mutex,
 * it will be waked up.
 *
 * @param mutex the mutex object
 *
 * @return the error code
 */
mResult mMutex::mutexRelease()
{
    register long temp;
    struct thread_t *thread;
    bool needSchedule;

    /* parameter check */
    MASSERT(mObject::getInstance()->objectGetType((mObject_t*)this) == M_OBJECT_CLASS_MUTEX);

    needSchedule = false;

    /* only thread could release mutex because we need test the ownership */
    //RT_DEBUG_IN_THREAD_CONTEXT;

    /* get current thread */
    thread = mthread::threadSelf();

    /* disable interrupt */
    temp = HW::hwInterruptDisable();

    /*RT_DEBUG_LOG(RT_DEBUG_IPC,
                 ("mutex_release:current thread %s, mutex value: %d, hold: %d\n",
                  thread->name, mutex->value, mutex->hold));*/

    //RT_OBJECT_HOOK_CALL(rt_object_put_hook, (&(mutex->parent.parent)));

    /* mutex only can be released by owner */
    if (thread != mutex_.owner)
    {
        thread->error = M_RESULT_ERROR;

        /* enable interrupt */
        HW::hwInterruptEnable(temp);

        return M_RESULT_ERROR;
    }

    /* decrease hold */
    mutex_.hold --;
    /* if no hold */
    if (mutex_.hold == 0)
    {
        /* change the owner thread to original priority */
        if (mutex_.originalPriority != mutex_.owner->currentPriority)
        {
            reinterpret_cast<mthread*>(mutex_.owner)->threadControl(THREAD_CTRL_CHANGE_PRIORITY, &mutex_.originalPriority);

        }

        /* wakeup suspended thread */
        if (!mutex_.suspendThread.isEmpty())
        {
            /* get suspended thread */
            thread = listEntry(mutex_.suspendThread.next,
                                   struct thread_t,
                                   tlist);

            /*RT_DEBUG_LOG(RT_DEBUG_IPC, ("mutex_release: resume thread: %s\n",
                                        thread->name));*/

            /* set new owner and priority */
            mutex_.owner             = thread;
            mutex_.originalPriority = thread->currentPriority;
            if(mutex_.hold < MUTEX_HOLD_MAX)
            {
                mutex_.hold ++;
            }
            else
            {
                HW::hwInterruptEnable(temp); /* enable interrupt */
                return M_RESULT_EFULL; /* value overflowed */
            }

            /* resume thread */
            ipcListResume((mIpcObject_t*)(this));

            needSchedule = true;
        }
        else
        {
            if(mutex_.value < MUTEX_VALUE_MAX)
            {
                /* increase value */
                mutex_.value ++;
            }
            else
            {
                HW::hwInterruptEnable(temp); /* enable interrupt */
                return M_RESULT_EFULL; /* value overflowed */
            }

            /* clear owner */
            mutex_.owner             = nullptr;
            mutex_.originalPriority = 0xff;
        }
    }

    /* enable interrupt */
    HW::hwInterruptEnable(temp);

    /* perform a schedule */
    if (needSchedule == true)
    {
        mSchedule::getInstance()->schedule();
    }

    return M_RESULT_EOK;
}