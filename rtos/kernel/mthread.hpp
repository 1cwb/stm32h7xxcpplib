#pragma once
#include "rtoscommon.hpp"
#include "mobject.hpp"
#include "cpuport.h"
#include "mclock.hpp"
#include <functional>

class mthread
{
    using mThreadCallbackFunc = std::function<void()>;
public:
    mthread()
    {
        thData_.extiThread = threadExti;
        thData_.yieldThread = threadYield;
    }
    ~mthread()
    {

    }
    mthread(const mthread&) = delete;
    mthread(mthread&&) = delete;
    mthread& operator=(const mthread&) = delete;
    mthread& operator=(mthread&&) = delete;
    static void threadExti()
    {
        register long level;

        /* get current thread */
        struct thread_t* & thread = mSchedule::getInstance()->getCurrentThread();

        /* disable interrupt */
        level = HW::hwInterruptDisable();

        threadCleanupExecute(thread);

        /* remove from schedule */
        mSchedule::getInstance()->scheduleRemoveThread(thread);
        /* change stat */
        thread->stat = THREAD_CLOSE;

        /* remove it from timer list */ //TONY fix me
        //rt_timer_detach(&thread->thread_timer);

        if (mObject::getInstance()->objectIsSystemobject((mObject_t*)thread))
        {
            mObject::getInstance()->objectDetach((mObject_t*)thread);
        }
        else
        {
            /* insert to defunct thread list */
            thread->tlist.insertAfterTo(mSchedule::getInstance()->getThreadDefunct());
        }

        /* switch to next task */
        mSchedule::getInstance()->schedule();

        /* enable interrupt */
        HW::hwInterruptEnable(level);
    }
    mResult init(const char       *name,
                 void             *stackStart,
                 uint32_t         stackSize,
                 uint8_t          priority,
                 uint32_t         tick,
                 const mThreadCallbackFunc& func)
    {
        cb_ = std::move(func);
        return this->init(name, threadFunc, (void*)this, stackStart, stackSize,priority,tick);
    }
    mResult init(const char       *name,
                 void (*entry)(void *parameter),
                 void             *parameter,
                 void             *stackStart,
                 uint32_t         stackSize,
                 uint8_t          priority,
                 uint32_t         tick)
    {
        /* thread check */
        MASSERT(stackStart != nullptr);
        //printf("[%s] stack addr = %p\r\n",name,stackStart);
        /* initialize thread object */
        mObject::getInstance()->objectInit((mObject_t*)this, M_OBJECT_CLASS_THREAD, name);

        return threadInit(name,
                        entry,
                        parameter,
                        stackStart,
                        stackSize,
                        priority,
                        tick);
    }
    /**
     * This function will return self thread object
     *
     * @return the self thread object
     */
    static thread_t* threadSelf(void)
    {
        return mSchedule::getInstance()->getCurrentThread();
    }

    /**
     * This function will start a thread and put it to system ready queue
     *
     * @param thread the thread to be started
     *
     * @return the operation status, RT_EOK on OK, -RT_ERROR on error
     */
    mResult startup()
    {
        /* thread check */
        MASSERT((thData_.stat & THREAD_STAT_MASK) == THREAD_INIT);
        MASSERT(mObject::getInstance()->objectGetType((mObject_t*)(&thData_)) == M_OBJECT_CLASS_THREAD);

        /* set current priority to initialize priority */
        thData_.currentPriority = thData_.initPriority;

        /* calculate priority attribute */
    #if THREAD_PRIORITY_MAX > 32
        thData_.number      = thData_.currentPriority >> 3;            /* 5bit */
        thData_.numberMask = 1L << thData_.number;
        thData_.highMask   = 1L << (thData_.currentPriority & 0x07);  /* 3bit */
    #else
        thData_.numberMask = 1L << thData_.currentPriority;
    #endif

        /*RT_DEBUG_LOG(RT_DEBUG_THREAD, ("startup a thread:%s with priority:%d\n",
                                    thData_.name, thData_.initPriority));*/
        /* change thread stat */
        thData_.stat = THREAD_SUSPEND;
        /* then resume it */
        threadResume();
        if (threadSelf() != nullptr)
        {
            /* do a scheduling */
            mSchedule::getInstance()->schedule();
        }
        return M_RESULT_EOK;
    }
    /**
     * This function will let current thread yield processor, and scheduler will
     * choose a highest thread to run. After yield processor, the current thread
     * is still in READY state.
     *
     * @return RT_EOK
     */
    static mResult threadYield(void)
    {
        register long level;

        /* set to current thread */
        struct thread_t*& thread = mSchedule::getInstance()->getCurrentThread();

        /* disable interrupt */
        level = HW::hwInterruptDisable();

        /* if the thread stat is READY and on ready queue list */
        if ((thread->stat & THREAD_STAT_MASK) == THREAD_READY &&
            thread->tlist.next != thread->tlist.prev)
        {
            /* remove thread from thread list */
            thread->tlist.removeSelf();

            /* put thread to end of ready queue */
            thread->tlist.insertBeforeTo(mSchedule::getInstance()->getThreadPriorityTable(thread->currentPriority));

            /* enable interrupt */
            HW::hwInterruptEnable(level);

            mSchedule::getInstance()->schedule();

            return M_RESULT_EOK;
        }

        /* enable interrupt */
        HW::hwInterruptEnable(level);

        return M_RESULT_EOK;
    }

    /**
     * This function will let current thread sleep for some ticks.
     *
     * @param tick the sleep ticks
     *
     * @return RT_EOK
     */
    static mResult threadSleep(uint32_t tick)
    {
        register long temp;
        /* set to current thread */
        struct thread_t*& thread = mSchedule::getInstance()->getCurrentThread();

        /* disable interrupt */
        temp = HW::hwInterruptDisable();

        MASSERT(thread != nullptr);
        MASSERT(mObject::getInstance()->objectGetType((mObject_t*)(thread)) == M_OBJECT_CLASS_THREAD);

        /* suspend thread */
        threadSuspend(thread);

        /* reset the timeout of thread timer and start it */ //tony fix me
        //rt_timer_control(&(thread->thread_timer), RT_TIMER_CTRL_SET_TIME, &tick);
        //rt_timer_start(&(thread->thread_timer));

        /* enable interrupt */
        HW::hwInterruptEnable(temp);

        mSchedule::getInstance()->schedule();

        /* clear error number of this thread to RT_EOK */
        if (thread->error == -M_RESULT_ETIMEOUT)
            thread->error = M_RESULT_EOK;

        return M_RESULT_EOK;
    }

    /**
     * This function will let current thread delay for some ticks.
     *
     * @param tick the delay ticks
     *
     * @return RT_EOK
     */
    static mResult threadDelay(uint32_t tick)
    {
        return threadSleep(tick);
    }

    /**
     * This function will let current thread delay until (*tick + inc_tick).
     *
     * @param tick the tick of last wakeup.
     * @param inc_tick the increment tick
     *
     * @return RT_EOK
     */
    static mResult threadDelayUntil(uint32_t *tick, uint32_t incTick)
    {
        register long level;
        struct thread_t *thread;

        MASSERT(tick != nullptr);

        /* set to current thread */
        thread = threadSelf();
        MASSERT(thread != nullptr);
        MASSERT(mObject::getInstance()->objectGetType((mObject_t*)thread) == M_OBJECT_CLASS_THREAD);

        /* disable interrupt */
        level = HW::hwInterruptDisable();

        if (mClock::getInstance()->tickGet() - *tick < incTick)
        {
            *tick = *tick + incTick - mClock::getInstance()->tickGet();

            /* suspend thread */
            threadSuspend(thread);

            /* reset the timeout of thread timer and start it *///tony Fix me
            //rt_timer_control(&(thread->thread_timer), RT_TIMER_CTRL_SET_TIME, tick);
            //rt_timer_start(&(thread->thread_timer));

            /* enable interrupt */
            HW::hwInterruptEnable(level);

            mSchedule::getInstance()->schedule();

            /* clear error number of this thread to RT_EOK */
            if (thread->error == -M_RESULT_ETIMEOUT)
            {
                thread->error = M_RESULT_EOK;
            }
        }
        else
        {
            HW::hwInterruptEnable(level);
        }

        /* get the wakeup tick */
        *tick = mClock::getInstance()->tickGet();

        return M_RESULT_EOK;
    }

    /**
     * This function will let current thread delay for some milliseconds.
     *
     * @param ms the delay ms time
     *
     * @return RT_EOK
     */
    static mResult threadMdelay(int32_t ms)
    {
        uint32_t tick;

        tick = mClock::getInstance()->tickFromMillisecond(ms);

        return threadSleep(tick);
    }

    /**
     * This function will control thread behaviors according to control command.
     *
     * @param thread the specified thread to be controlled
     * @param cmd the control command, which includes
     *  RT_THREAD_CTRL_CHANGE_PRIORITY for changing priority level of thread;
     *  RT_THREAD_CTRL_STARTUP for starting a thread;
     *  RT_THREAD_CTRL_CLOSE for delete a thread;
     *  RT_THREAD_CTRL_BIND_CPU for bind the thread to a CPU.
     * @param arg the argument of control command
     *
     * @return RT_EOK
     */
    mResult threadControl(mthreadCtrlCmd cmd, void *arg)
    {
        register long temp;

        /* thread check */
        MASSERT(mObject::getInstance()->objectGetType((mObject_t*)(&thData_)) == M_OBJECT_CLASS_THREAD);

        switch (cmd)
        {
        case THREAD_CTRL_CHANGE_PRIORITY:
            /* disable interrupt */
            temp = HW::hwInterruptDisable();

            /* for ready thread, change queue */
            if ((thData_.stat & THREAD_STAT_MASK) == THREAD_READY)
            {
                /* remove thread from schedule queue first */
                mSchedule::getInstance()->scheduleRemoveThread(&thData_);

                /* change thread priority */
                thData_.currentPriority = *(uint8_t *)arg;

                /* recalculate priority attribute */
    #if THREAD_PRIORITY_MAX > 32
                thData_.number      = thData_.current_priority >> 3;            /* 5bit */
                thData_.number_mask = 1 << thData_.number;
                thData_.high_mask   = 1 << (thData_.current_priority & 0x07);   /* 3bit */
    #else
                thData_.numberMask = 1 << thData_.currentPriority;
    #endif

                /* insert thread to schedule queue again */
                mSchedule::getInstance()->scheduleInsertThread(&thData_);
            }
            else
            {
                thData_.currentPriority = *(uint8_t *)arg;

                /* recalculate priority attribute */
    #if THREAD_PRIORITY_MAX > 32
                thData_.number      = thData_.currentPriority >> 3;            /* 5bit */
                thData_.numberMask = 1 << thData_.number;
                thData_.highMask   = 1 << (thData_.currentPriority & 0x07);   /* 3bit */
    #else
                thData_.numberMask = 1 << thData_.currentPriority;
    #endif
            }

            /* enable interrupt */
            HW::hwInterruptEnable(temp);
            break;

        case THREAD_CTRL_STARTUP:
            return startup();

        case THREAD_CTRL_CLOSE:

            if (mObject::getInstance()->objectIsSystemobject((mObject_t*)(&thData_)))
            {
                return threadDetach();
            }
    #ifdef RT_USING_HEAP
            else
            {
                return rt_thread_delete();
            }
    #endif

        default:
            break;
        }

        return M_RESULT_EOK;
    }

    /**
     * This function will suspend the specified thread.
     *
     * @param thread the thread to be suspended
     *
     * @return the operation status, RT_EOK on OK, -RT_ERROR on error
     *
     * @note if suspend self thread, after this function call, the
     * rt_schedule() must be invoked.
     */
    static mResult threadSuspend(thread_t* thread)
    {
        register long temp;

        /* thread check */
        MASSERT(thread != nullptr);
        MASSERT(mObject::getInstance()->objectGetType((mObject_t*)(thread)) == M_OBJECT_CLASS_THREAD);
        //RT_DEBUG_LOG(RT_DEBUG_THREAD, ("thread suspend:  %s\n", thread->name));

        if ((thread->stat & THREAD_STAT_MASK) != THREAD_READY)
        {
            /*RT_DEBUG_LOG(RT_DEBUG_THREAD, ("thread suspend: thread disorder, 0x%2x\n",
                                        thread->stat));*/

            return M_RESULT_ERROR;
        }

        /* disable interrupt */
        temp = HW::hwInterruptDisable();

        /* change thread stat */
        mSchedule::getInstance()->scheduleRemoveThread(thread);
        thread->stat = THREAD_SUSPEND | (thread->stat & ~THREAD_STAT_MASK);

        /* stop thread timer anyway *///tony Fix me
        //rt_timer_stop(&(thread->thread_timer));

        /* enable interrupt */
        HW::hwInterruptEnable(temp);

        //RT_OBJECT_HOOK_CALL(rt_thread_suspend_hook, (thread));
        return M_RESULT_EOK;
    }

    /**
     * This function will resume a thread and put it to system ready queue.
     *
     * @param thread the thread to be resumed
     *
     * @return the operation status, RT_EOK on OK, -RT_ERROR on error
     */
    mResult threadResume()
    {
        register long temp;

        /* thread check */
        MASSERT(mObject::getInstance()->objectGetType((mObject_t*)(&thData_)) == M_OBJECT_CLASS_THREAD);

        //RT_DEBUG_LOG(RT_DEBUG_THREAD, ("thread resume:  %s\n", thread->name));

        if ((thData_.stat & THREAD_STAT_MASK) != THREAD_SUSPEND)
        {
            /*RT_DEBUG_LOG(RT_DEBUG_THREAD, ("thread resume: thread disorder, %d\n",
                                        thread->stat));*/

            return M_RESULT_ERROR;
        }

        /* disable interrupt */
        temp = HW::hwInterruptDisable();

        /* remove from suspend list */
        thData_.tlist.removeSelf();

        //tony fix me
        //rt_timer_stop(&thData_.thread_timer);

        /* enable interrupt */
        HW::hwInterruptEnable(temp);

        /* insert to schedule ready list */
        mSchedule::getInstance()->scheduleInsertThread(&thData_);

        //RT_OBJECT_HOOK_CALL(rt_thread_resume_hook, (thread));
        return M_RESULT_EOK;
    }

    /**
     * This function is the timeout function for thread, normally which is invoked
     * when thread is timeout to wait some resource.
     *
     * @param parameter the parameter of thread timeout function
     */
    static void threadTimeout(void *parameter)
    {
        struct thread_t *thread;

        thread = (struct thread_t *)parameter;

        /* thread check */
        MASSERT(thread != nullptr);
        MASSERT((thread->stat & THREAD_STAT_MASK) == THREAD_SUSPEND);
        MASSERT(mObject::getInstance()->objectGetType((mObject_t*)(thread)) == M_OBJECT_CLASS_THREAD);

        /* set error number */
        thread->error = -M_RESULT_ETIMEOUT;

        /* remove from suspend list */
        thread->tlist.removeSelf();

        /* insert to schedule ready list */
        mSchedule::getInstance()->scheduleInsertThread(thread);

        /* do schedule */
        mSchedule::getInstance()->schedule();
    }

    /**
     * This function will find the specified thread.
     *
     * @param name the name of thread finding
     *
     * @return the found thread
     *
     * @note please don't invoke this function in interrupt status.
     */
    static thread_t* threadFind(char *name)
    {
        return (thread_t*)mObject::getInstance()->objectFind(name, M_OBJECT_CLASS_THREAD);
    }
    /**
     * This function will detach a thread. The thread object will be removed from
     * thread queue and detached/deleted from system object management.
     *
     * @param thread the thread to be deleted
     *
     * @return the operation status, RT_EOK on OK, -RT_ERROR on error
     */
    mResult threadDetach()
    {
        long lock;

        /* thread check */
        MASSERT(mObject::getInstance()->objectGetType((mObject_t*)(&thData_)) == M_OBJECT_CLASS_THREAD);
        MASSERT(mObject::getInstance()->objectIsSystemobject((mObject_t*)(&thData_)));

        if ((thData_.stat & THREAD_STAT_MASK) == THREAD_CLOSE)
            return M_RESULT_EOK;

        if ((thData_.stat & THREAD_STAT_MASK) != THREAD_INIT)
        {
            /* remove from schedule */
            mSchedule::getInstance()->scheduleRemoveThread(&thData_);
        }

        threadCleanupExecute(&thData_);

        /* release thread timer *///tony Fix me
        //rt_timer_detach(&(thData_.threadTimer));

        /* change stat */
        thData_.stat = THREAD_CLOSE;

        if (mObject::getInstance()->objectIsSystemobject((mObject_t*)(&thData_)))
        {
            mObject::getInstance()->objectDetach((mObject_t*)(&thData_));
        }
        else
        {
            /* disable interrupt */
            lock = HW::hwInterruptDisable();
            /* insert to defunct thread list */
            thData_.tlist.insertAfterTo(mSchedule::getInstance()->getThreadDefunct());
            /* enable interrupt */
            HW::hwInterruptEnable(lock);
        }

        return M_RESULT_EOK;
    }
private:
    mResult threadInit( const char       *name,
                        void (*entry)(void *parameter),
                        void             *parameter,
                        void             *stackStart,
                        uint32_t         stackSize,
                        uint8_t          priority,
                        uint32_t         tick)
    {
        /* init thread list */
        //rt_list_init(&(thData_.tlist));

        thData_.entry = (void *)entry;
        thData_.parameter = parameter;

        /* stack init */
        thData_.stackAddr = stackStart;
        thData_.stackSize = stackSize;

        /* init thread stack */
        memset(thData_.stackAddr, '#', thData_.stackSize);
    #ifdef ARCH_CPU_STACK_GROWS_UPWARD
        thData_.sp = (void *)CPUPORT::hwStackInit(thData_.entry, thData_.parameter,
                                            (void *)((char *)thData_.stackAddr),
                                            (void *)this);
    #else
        thData_.sp = (void *)CPUPORT::hwStackInit(thData_.entry, thData_.parameter,
                                            (uint8_t *)((char *)thData_.stackAddr + thData_.stackSize - sizeof(unsigned long)),
                                            (void *)this);
    #endif

        /* priority init */
        if(priority >= THREAD_PRIORITY_MAX)
        {
            priority = THREAD_PRIORITY_MAX - 1;
        }
        thData_.initPriority    = priority;
        thData_.currentPriority = priority;

        thData_.numberMask = 0;
    #if THREAD_PRIORITY_MAX > 32
        thData_.number = 0;
        thData_.highMask = 0;
    #endif

        /* tick init */
        thData_.initTick      = tick;
        thData_.remainingTick = tick;

        /* error and flags */
        thData_.error = M_RESULT_EOK;
        thData_.stat  = THREAD_INIT;

        /* initialize cleanup function and user data */
        thData_.cleanup   = 0;
        thData_.userData = 0;

        /* initialize thread timer */
        /*rt_timer_init(&(thData_.thread_timer),
                    thData_.name,
                    rt_thread_timeout,
                    thread,
                    0,
                    RT_TIMER_FLAG_ONE_SHOT);

        RT_OBJECT_HOOK_CALL(rt_thread_inited_hook, (thread));*/

        return M_RESULT_EOK;
    }
    /* must be invoke witch rt_hw_interrupt_disable */
    static void threadCleanupExecute(thread_t* thread)
    {
        register long level;
        level = HW::hwInterruptDisable();

        /* invoke thread cleanup */
        if (thread->cleanup != nullptr)
            thread->cleanup(thread);

        HW::hwInterruptEnable(level);
    }
    static void threadFunc(void* p)
    {
        mthread* thread = reinterpret_cast<mthread*>(p);
        if(thread)
        {
            if(thread->cb_)
            {
                thread->cb_();
            }
        }
    }
private:
    thread_t thData_;
    mThreadCallbackFunc cb_;
};