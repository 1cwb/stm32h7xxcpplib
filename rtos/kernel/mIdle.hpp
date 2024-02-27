#pragma once
#include "mthread.hpp"

#define IDLE_THREAD_STACK_SIZE  1024
ALIGN(4) static uint8_t threadStack[IDLE_THREAD_STACK_SIZE];

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

                        }
                    });

        /* startup */
        idleThread_.startup();
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
