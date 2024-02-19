#pragma once
#include "rtoscommon.hpp"

#if               ( /* GNU */(defined ( __GNUC__ ) && defined ( __VFP_FP__ ) && !defined(__SOFTFP__)))
#define USE_FPU   1
#else
#define USE_FPU   0
#endif
namespace CPUPORT{
extern "C"{

/* exception and interrupt handler table */
uint32_t mInterruptFromThread;
uint32_t mtInterruptToThread;
uint32_t mtThreadSwitchInterruptFlag;


/* exception hook */
//static int32_t (*rt_exception_hook)(void *context) = nullptr;

struct exceptionStackFrame
{
    uint32_t r0;
    uint32_t r1;
    uint32_t r2;
    uint32_t r3;
    uint32_t r12;
    uint32_t lr;
    uint32_t pc;
    uint32_t psr;
};

struct stackFrame
{
#if USE_FPU
    uint32_t flag;
#endif /* USE_FPU */

    /* r4 ~ r11 register */
    uint32_t r4;
    uint32_t r5;
    uint32_t r6;
    uint32_t r7;
    uint32_t r8;
    uint32_t r9;
    uint32_t r10;
    uint32_t r11;

    struct exceptionStackFrame exceptionStackFrame;
};

struct exceptionStackFrameFpu
{
    uint32_t r0;
    uint32_t r1;
    uint32_t r2;
    uint32_t r3;
    uint32_t r12;
    uint32_t lr;
    uint32_t pc;
    uint32_t psr;

#if USE_FPU
    /* FPU register */
    uint32_t S0;
    uint32_t S1;
    uint32_t S2;
    uint32_t S3;
    uint32_t S4;
    uint32_t S5;
    uint32_t S6;
    uint32_t S7;
    uint32_t S8;
    uint32_t S9;
    uint32_t S10;
    uint32_t S11;
    uint32_t S12;
    uint32_t S13;
    uint32_t S14;
    uint32_t S15;
    uint32_t FPSCR;
    uint32_t NO_NAME;
#endif
};

struct stackFrameFpu
{
    uint32_t flag;

    /* r4 ~ r11 register */
    uint32_t r4;
    uint32_t r5;
    uint32_t r6;
    uint32_t r7;
    uint32_t r8;
    uint32_t r9;
    uint32_t r10;
    uint32_t r11;

#if USE_FPU
    /* FPU register s16 ~ s31 */
    uint32_t s16;
    uint32_t s17;
    uint32_t s18;
    uint32_t s19;
    uint32_t s20;
    uint32_t s21;
    uint32_t s22;
    uint32_t s23;
    uint32_t s24;
    uint32_t s25;
    uint32_t s26;
    uint32_t s27;
    uint32_t s28;
    uint32_t s29;
    uint32_t s30;
    uint32_t s31;
#endif

    struct exceptionStackFrameFpu exceptionStackFrame;
};

uint8_t *hwStackInit( void    *tentry,
                        void    *parameter,
                        uint8_t *stackAddr,
                        void    *texit)
{
    struct stackFrame *stackFrame;
    uint8_t         *stk;
    unsigned long       i;

    stk  = stackAddr + sizeof(uint32_t);
    stk  = (uint8_t *)ALIGN_DOWN((uint32_t)stk, 8);
    stk -= sizeof(struct stackFrame);

    stackFrame = (struct stackFrame *)stk;

    /* init all register */
    for (i = 0; i < sizeof(struct stackFrame) / sizeof(uint32_t); i ++)
    {
        ((uint32_t *)stackFrame)[i] = 0xdeadbeef;
    }

    stackFrame->exceptionStackFrame.r0  = (unsigned long)parameter; /* r0 : argument */
    stackFrame->exceptionStackFrame.r1  = 0;                        /* r1 */
    stackFrame->exceptionStackFrame.r2  = 0;                        /* r2 */
    stackFrame->exceptionStackFrame.r3  = 0;                        /* r3 */
    stackFrame->exceptionStackFrame.r12 = 0;                        /* r12 */
    stackFrame->exceptionStackFrame.lr  = (unsigned long)(((thread_t*)texit)->extiThread);     /* lr */
    stackFrame->exceptionStackFrame.pc  = (unsigned long)tentry;    /* entry point, pc */
    stackFrame->exceptionStackFrame.psr = 0x01000000L;              /* PSR */

#if USE_FPU
    stackFrame->flag = 0;
#endif /* USE_FPU */

    /* return task's current stack address */
    return stk;
}
struct exceptionInfo_t
{
    uint32_t excReturn;
    struct stackFrame stackFrame;
};
extern "C" void hwHardFaultException(exceptionInfo_t *exceptionInfo)
{
    #if 0
    extern long list_thread(void);
    struct exceptionStackFrame *exceptionStack = &exceptionInfo->stackFrame.exceptionStackFrame;
    struct stackFrame *context = &exceptionInfo->stackFrame;

    if (rt_exception_hook != RT_NULL)
    {
        rt_err_t result;

        result = rt_exception_hook(exception_stack);
        if (result == RT_EOK) return;
    }

    rt_kprintf("psr: 0x%08x\n", context->exceptionStackFrame.psr);

    rt_kprintf("r00: 0x%08x\n", context->exceptionStackFrame.r0);
    rt_kprintf("r01: 0x%08x\n", context->exceptionStackFrame.r1);
    rt_kprintf("r02: 0x%08x\n", context->exceptionStackFrame.r2);
    rt_kprintf("r03: 0x%08x\n", context->exceptionStackFrame.r3);
    rt_kprintf("r04: 0x%08x\n", context->r4);
    rt_kprintf("r05: 0x%08x\n", context->r5);
    rt_kprintf("r06: 0x%08x\n", context->r6);
    rt_kprintf("r07: 0x%08x\n", context->r7);
    rt_kprintf("r08: 0x%08x\n", context->r8);
    rt_kprintf("r09: 0x%08x\n", context->r9);
    rt_kprintf("r10: 0x%08x\n", context->r10);
    rt_kprintf("r11: 0x%08x\n", context->r11);
    rt_kprintf("r12: 0x%08x\n", context->exceptionStackFrame.r12);
    rt_kprintf(" lr: 0x%08x\n", context->exceptionStackFrame.lr);
    rt_kprintf(" pc: 0x%08x\n", context->exceptionStackFrame.pc);

    if (exceptionInfo->excReturn & (1 << 2))
    {
        rt_kprintf("hard fault on thread: %s\r\n\r\n", rt_thread_self()->name);

#ifdef RT_USING_FINSH
        list_thread();
#endif
    }
    else
    {
        rt_kprintf("hard fault on handler\r\n\r\n");
    }

    if ( (exception_info->excReturn & 0x10) == 0)
    {
        rt_kprintf("FPU active!\r\n");
    }

#ifdef RT_USING_FINSH
    hard_fault_track();
#endif /* RT_USING_FINSH */

    while (1);
    #endif
}

}//extern "C"
}//namespace CPUPORT