#pragma once
#include "common.hpp"
#include "rcc.hpp"
#include <cmath>
#include <functional>

#define WWDG_CNT_MAX_VAL    0x7f   //[6:0]

enum WWDGTimeBaseDivi
{
    WWDG_TIME_BASE_DIVI_1,
    WWDG_TIME_BASE_DIVI_2,
    WWDG_TIME_BASE_DIVI_4,
    WWDG_TIME_BASE_DIVI_8,
    WWDG_TIME_BASE_DIVI_16,
    WWDG_TIME_BASE_DIVI_32,
    WWDG_TIME_BASE_DIVI_64,
    WWDG_TIME_BASE_DIVI_128,
    WWDG_TIME_BASE_DIVI_NONE
};

class WWDG
{
    using WWDGInterruptCb = std::function<void(WWDG* wwdg)>;
public:
    static WWDG* getInstance()
    {
        static WWDG wwdg;
        return &wwdg;
    }
    void start(uint8_t countVal, uint8_t windowVal, WWDGTimeBaseDivi divi)
    {
        if(divi == WWDG_TIME_BASE_DIVI_NONE)
        {
            return;
        }
        if(tbdivi_ != WWDG_TIME_BASE_DIVI_NONE)
        {
            return;
        }
        tbdivi_ = divi;
        tCnt_ &= countVal;
        windVal_ &= windowVal;
        RCCControl::getInstance()->enableWWDG1Clk(true);
        RCCControl::getInstance()->resetWWDG1();
        MODIFY_REG(WWDG1->CFR, WWDG_CFR_WDGTB, (tbdivi_ << WWDG_CFR_WDGTB_Pos));
        MODIFY_REG(WWDG1->CFR, WWDG_CFR_W, (windVal_  << WWDG_CFR_W_Pos));
        MODIFY_REG(WWDG1->CR, WWDG_CR_T, (tCnt_  << WWDG_CR_T_Pos));
        SET_BIT(WWDG1->CR, WWDG_CR_WDGA);
        registerWwdgIsrCb([](void* param){
            if(READ_BIT(WWDG1->SR, WWDG_SR_EWIF))
            {
                CLEAR_BIT(WWDG1->SR, WWDG_SR_EWIF);
                WWDG* pwwdg = reinterpret_cast<WWDG*>(param);
                if(pwwdg)
                {
                    if(pwwdg->cb_)
                    {
                        pwwdg->cb_(pwwdg);
                    }
                }
            }
        }, this);
    }
    void feedDog()
    {
        MODIFY_REG(WWDG1->CR, WWDG_CR_T, (tCnt_  << WWDG_CR_T_Pos));
    }
    //Twwdg=(4096× 2^WDGTB[2:0]× (T[5:0]+1)) /Fpclk3;
    uint32_t getTimeOutMs()
    {
        return ((4096 * (uint32_t)pow(2, tbdivi_) * (READ_BIT(WWDG1->CR, 0X3F)+1))/(RCCControl::getInstance()->getAPB3ClkFreq()/1000));
    }
    void enableIsr(uint32_t PreemptPriority, uint32_t SubPriority)
    {
        NVIC_SetPriority(WWDG_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), PreemptPriority, SubPriority));
        NVIC_EnableIRQ(WWDG_IRQn);
        SET_BIT(WWDG1->CFR, WWDG_CFR_EWI);
    }
    void disableIsr()
    {
        CLEAR_BIT(WWDG1->CFR, WWDG_CFR_EWI);
    }
    void registerInterruptCb(const WWDGInterruptCb& isrcb)
    {
        cb_ = isrcb;
    }
    void unregisterInterruptCb()
    {
        if(cb_)
        {
            cb_ = WWDGInterruptCb();
        }
    }
private:
    WWDG() : tbdivi_(WWDG_TIME_BASE_DIVI_NONE),tCnt_(WWDG_CNT_MAX_VAL),windVal_(WWDG_CNT_MAX_VAL)
    {

    }
    ~WWDG()
    {

    }
    WWDG(const WWDG&) = delete;
    WWDG(WWDG&&) = delete;
    WWDG& operator=(const WWDG&) = delete;
    WWDG& operator=(WWDG&&) = delete;

    WWDGTimeBaseDivi tbdivi_;
    uint8_t tCnt_;
    uint8_t windVal_;
    WWDGInterruptCb cb_;
};