#pragma once
#include "mthread.hpp"

#define IDLE_THREAD_STACK_SIZE  512
ALIGN(4) static uint8_t threadStack[IDLE_THREAD_STACK_SIZE];

static void test(void*p)
{
    while(true)
    {
        printf("idle run...\r\n");
    }
}

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
        printf("mainth this = %p, idleThread_ = %p\r\n",this, &idleThread_);
        idleThread_.init(
                    "tidle",
                    test,
                    nullptr,
                    &threadStack[0],
                    sizeof(threadStack),
                    THREAD_PRIORITY_MAX - 1,
                    32);

        /* startup */
        idleThread_.startup();
    }
private:
    mIdle()
    {
        //memset(threadStack, 0, sizeof(threadStack));
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
