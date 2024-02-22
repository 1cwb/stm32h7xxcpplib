//#pragma once 
#include "rtoscommon.hpp"
#include "mthread.hpp"
#include "mirq.hpp"
#include "mobject.hpp"
#include "mscheduler.hpp"
#include "mIdle.hpp"
#include "board.h"

#define MAIN_THREAD_STACK_SIZE 1024*10
#define MAIN_THREAD_PRIORITY 0
#define MAIN_THREAD_TICK_TIME 20
#ifndef RT_USING_HEAP
/* if there is not enable heap, we should use static thread and stack. */
ALIGN(4) __attribute__((section(".dtcmram"))) static uint8_t mainStack[MAIN_THREAD_STACK_SIZE];
#endif

void mainThreadEntry(void *parameter)
{
    extern int main(void);
    main();
}

class mComponets
{
public:
    static mComponets* getInstance()
    {
        static mComponets com;
        return &com;
    }
    void startUp()
    {
        HW::hwInterruptDisable();
        mSchedule::getInstance()->systemSchedulerInit();
        applicationInit();
        mIdle::getInstance()->threadIdleInit();
        mSchedule::getInstance()->systemSchedulerStart();
    }
    void applicationInit(void)
    {
    #ifdef RT_USING_HEAP
        tid = rt_thread_create("main", mainThread_entry, RT_NULL,
                            RT_mainThread_STACK_SIZE, RT_mainThread_PRIORITY, 20);
        RT_ASSERT(tid != RT_NULL);
    #else
        mResult result;
        result = mainThread_.init("main", mainThreadEntry, nullptr,
                                mainStack, sizeof(mainStack), MAIN_THREAD_PRIORITY, MAIN_THREAD_TICK_TIME);
        MASSERT(result == M_RESULT_EOK);

        /* if not define RT_USING_HEAP, using to eliminate the warning */
        (void)result;
    #endif

        mainThread_.startup();
    }
private:
    mComponets()
    {
    }
    ~mComponets()
    {

    }
    mComponets(const mComponets&) = delete;
    mComponets(mComponets&&) = delete;
    mComponets& operator=(const mComponets&) = delete;
    mComponets& operator=(mComponets&&) = delete;

    mthread mainThread_;
};

extern "C" int entry(void)
{
    boardInit();
    mComponets::getInstance()->startUp();
    return 0;
}