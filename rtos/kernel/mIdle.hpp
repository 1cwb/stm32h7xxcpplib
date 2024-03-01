#pragma once
#include "mthread.hpp"
#include "mmem.h"

#define IDLE_THREAD_STACK_SIZE  1024
ALIGN(M_ALIGN_SIZE) static uint8_t threadStack[IDLE_THREAD_STACK_SIZE];

class mIdle
{
public:
    static mIdle* getInstance()
    {
        static mIdle idle;
        return &idle;
    }
    void threadIdleInit(void)
    {
        /* initialize thread */
        idleThread_.init(
                    "tidle",
                    &threadStack[0],
                    sizeof(threadStack),
                    THREAD_PRIORITY_MAX - 1,
                    32,
                    []()
                    {
                        while(true)
                        {
                            exec();
                        }
                    });

        /* startup */
        idleThread_.startup();
    }
    static void exec()
    {
        /* Loop until there is no dead thread. So one call to rt_thread_idle_excute
        * will do all the cleanups. */
        /* disable interrupt */
        while (1)
        {
            long lock;
            thread_t* thread;

            lock = HW::hwInterruptDisable();

            /* check whether list is empty */
            if (mSchedule::getInstance()->getThreadDefunct()->isEmpty())
            {
                HW::hwInterruptEnable(lock);
                break;
            }
            /* get defunct thread */
            thread = listEntry(mSchedule::getInstance()->getThreadDefunct()->next, struct thread_t, tlist);
            /* remove defunct thread */
            thread->tlist.removeSelf();
            /* release thread's stack */
            printf("delete thread now\r\n");
            delete [] reinterpret_cast<uint8_t*>(thread->stackAddr);
            /* delete thread object */
            delete reinterpret_cast<mthread*>(thread);
            HW::hwInterruptEnable(lock);
        }
    }
private:
    mIdle()
    {

    }
    ~mIdle()
    {

    }
    mIdle(const mIdle&) = delete;
    mIdle(mIdle&&) = delete;
    mIdle& operator=(const mIdle&) = delete;
    mIdle& operator=(mIdle&&) = delete;

    mthread idleThread_;
};
