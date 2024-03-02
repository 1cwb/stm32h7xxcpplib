#include "isrcommon.h"
#include "rtoscommon.h"
#include "mhw.h"
#include "mirq.h"
#include "mclock.h"
#include "systeminit.h"
#include "common.hpp"
#include "mmem.h"

#define MEM_HEAP_SIZE 50 * 1024 // 256K
D2_MEM_ALIGN(M_ALIGN_SIZE) static uint8_t memHeap[MEM_HEAP_SIZE];

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
    mMem::getInstance()->init(memHeap, memHeap + MEM_HEAP_SIZE);
}
