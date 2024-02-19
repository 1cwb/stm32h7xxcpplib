#pragma once
#include "rtoscommon.hpp"
#include "mhw.hpp"
class mIrq
{
public:
    static mIrq* getInstance()
    {
        static mIrq irq;
        return &irq;
    }
    inline uint8_t getInterruptNestWithoutDisableIsr() const
    {
        return interruptNest_;
    }
    inline void interruptNestReset()
    {
        interruptNest_ = 0;
    }
    /**
     * This function will be invoked by BSP, when enter interrupt service routine
     *
     * @note please don't invoke this routine in application
     *
     * @see interruptEnter
     */
    void interruptEnter(void)
    {
        long level;

        //RT_DEBUG_LOG(RT_DEBUG_IRQ, ("irq coming..., irq nest:%d\n", interruptNest_));

        level = HW::hwInterruptDisable();
        interruptNest_ ++;
        //RT_OBJECT_HOOK_CALL(rt_interrupt_enter_hook,());
        HW::hwInterruptEnable(level);
    }

    /**
     * This function will be invoked by BSP, when leave interrupt service routine
     *
     * @note please don't invoke this routine in application
     *
     * @see interruptLeave
     */
    void interruptLeave(void)
    {
        long level;

        //RT_DEBUG_LOG(RT_DEBUG_IRQ, ("irq leave, irq nest:%d\n", interruptNest_));

        level = HW::hwInterruptDisable();
        interruptNest_ --;
        //RT_OBJECT_HOOK_CALL(rt_interrupt_leave_hook,());
        HW::hwInterruptEnable(level);
    }

    /**
     * This function will return the nest of interrupt.
     *
     * User application can invoke this function to get whether current
     * context is interrupt context.
     *
     * @return the number of nested interrupts.
     */
    uint8_t interruptGetNest(void) const
    {
        uint8_t ret;
        long level;

        level = HW::hwInterruptDisable();
        ret = interruptNest_;
        HW::hwInterruptEnable(level);
        return ret;
    }

private:
    mIrq():interruptNest_(0)
    {
    }
    ~mIrq()
    {

    }
    mIrq(const mIrq&) = delete;
    mIrq(mIrq&&) = delete;
    mIrq& operator=(const mIrq&) = delete;
    mIrq& operator=(mIrq&&) = delete;

    volatile uint8_t interruptNest_;
};