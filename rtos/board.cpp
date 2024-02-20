#include "isrcommon.h"
#include "rtoscommon.hpp"
#include "mhw.hpp"
#include "mirq.hpp"
#include "mclock.hpp"
#include "systeminit.h"
//#include "mcomponents.hpp"


extern "C" void SysTick_Handler(void)
{
    mIrq::getInstance()->interruptEnter();
	incTick();
    mClock::getInstance()->tickIncrease();
    mIrq::getInstance()->interruptLeave();
}

void boardInit(void)
{
    if(!hwInit())
    {
        while(1);
    }
}