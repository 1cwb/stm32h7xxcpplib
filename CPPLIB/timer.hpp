#pragma once
#include "common.hpp"

enum TIMXCR1CountMode
{
    TIM_COUNTERMODE_UP              =   0x00000000U,                          /*!< Counter used as up-counter   */
    TIM_COUNTERMODE_DOWN            =   TIM_CR1_DIR,                          /*!< Counter used as down-counter */
    TIM_COUNTERMODE_CENTERALIGNED1  =   TIM_CR1_CMS_0,                        /*!< Center-aligned mode 1        */
    TIM_COUNTERMODE_CENTERALIGNED2  =   TIM_CR1_CMS_1,                        /*!< Center-aligned mode 2        */
    TIM_COUNTERMODE_CENTERALIGNED3  =   TIM_CR1_CMS                           /*!< Center-aligned mode 3        */
};

enum TIMCR1ClkDivi
{
    TIM_CLOCKDIVISION_DIV1       =      0x00000000U,                          /*!< Clock division: tDTS=tCK_INT   */
    TIM_CLOCKDIVISION_DIV2       =      TIM_CR1_CKD_0,                        /*!< Clock division: tDTS=2*tCK_INT */
    TIM_CLOCKDIVISION_DIV4       =      TIM_CR1_CKD_1,                        /*!< Clock division: tDTS=4*tCK_INT */
};

enum TIMChannelState
{
  HAL_TIM_CHANNEL_STATE_RESET             = 0x00U,    /*!< TIM Channel initial state                         */
  HAL_TIM_CHANNEL_STATE_READY             = 0x01U,    /*!< TIM Channel ready for use                         */
  HAL_TIM_CHANNEL_STATE_BUSY              = 0x02U,    /*!< An internal process is ongoing on the TIM channel */
};

enum TIMISRType
{
    TIM_IT_UPDATE         =          TIM_DIER_UIE,  
    TIM_IT_CC1            =          TIM_DIER_CC1IE,  
    TIM_IT_CC2            =          TIM_DIER_CC2IE,  
    TIM_IT_CC3            =          TIM_DIER_CC3IE,  
    TIM_IT_CC4            =          TIM_DIER_CC4IE,  
    TIM_IT_COM            =          TIM_DIER_COMIE,  
    TIM_IT_TRIGGER        =          TIM_DIER_TIE,  
    TIM_IT_BREAK          =          TIM_DIER_BIE   
};

/** @defgroup TIM_Slave_Mode TIM Slave mode
  * @{
  */
enum TIMSlaveMode
{
    TIM_SLAVEMODE_DISABLE               =    0x00000000U,                                        /*!< Slave mode disabled           */
    TIM_SLAVEMODE_RESET                 =    TIM_SMCR_SMS_2,                                     /*!< Reset Mode                    */
    TIM_SLAVEMODE_GATED                 =    (TIM_SMCR_SMS_2 | TIM_SMCR_SMS_0),                  /*!< Gated Mode                    */
    TIM_SLAVEMODE_TRIGGER               =    (TIM_SMCR_SMS_2 | TIM_SMCR_SMS_1),                  /*!< Trigger Mode                  */
    TIM_SLAVEMODE_EXTERNAL1             =    (TIM_SMCR_SMS_2 | TIM_SMCR_SMS_1 | TIM_SMCR_SMS_0), /*!< External Clock Mode 1         */
    TIM_SLAVEMODE_COMBINED_RESETTRIGGER =    TIM_SMCR_SMS_3                                     /*!< Combined reset + trigger mode */
};
/** @defgroup TIM_Flag_definition TIM Flag Definition
  * @{
  */
enum TIMISRFlag
{
    TIM_FLAG_UPDATE           =         TIM_SR_UIF,                           /*!< Update interrupt flag         */
    TIM_FLAG_CC1              =         TIM_SR_CC1IF,                         /*!< Capture/Compare 1 interrupt flag */
    TIM_FLAG_CC2              =         TIM_SR_CC2IF,                         /*!< Capture/Compare 2 interrupt flag */
    TIM_FLAG_CC3              =         TIM_SR_CC3IF,                         /*!< Capture/Compare 3 interrupt flag */
    TIM_FLAG_CC4              =         TIM_SR_CC4IF,                         /*!< Capture/Compare 4 interrupt flag */
    TIM_FLAG_CC5              =         TIM_SR_CC5IF,                         /*!< Capture/Compare 5 interrupt flag */
    TIM_FLAG_CC6              =         TIM_SR_CC6IF,                         /*!< Capture/Compare 6 interrupt flag */
    TIM_FLAG_COM              =         TIM_SR_COMIF,                         /*!< Commutation interrupt flag    */
    TIM_FLAG_TRIGGER          =         TIM_SR_TIF,                           /*!< Trigger interrupt flag        */
    TIM_FLAG_BREAK            =         TIM_SR_BIF,                           /*!< Break interrupt flag          */
    TIM_FLAG_BREAK2           =         TIM_SR_B2IF,                          /*!< Break 2 interrupt flag        */
    TIM_FLAG_SYSTEM_BREAK     =         TIM_SR_SBIF,                          /*!< System Break interrupt flag   */
    TIM_FLAG_CC1OF            =         TIM_SR_CC1OF,                         /*!< Capture 1 overcapture flag    */
    TIM_FLAG_CC2OF            =         TIM_SR_CC2OF,                         /*!< Capture 2 overcapture flag    */
    TIM_FLAG_CC3OF            =         TIM_SR_CC3OF,                         /*!< Capture 3 overcapture flag    */
    TIM_FLAG_CC4OF            =         TIM_SR_CC4OF                          /*!< Capture 4 overcapture flag    */
};
enum TIMActiveChannel
{
    TIM_ACTIVE_CHANNEL_1        = 0x01U,    /*!< The active channel is 1     */
    TIM_ACTIVE_CHANNEL_2        = 0x02U,    /*!< The active channel is 2     */
    TIM_ACTIVE_CHANNEL_3        = 0x04U,    /*!< The active channel is 3     */
    TIM_ACTIVE_CHANNEL_4        = 0x08U,    /*!< The active channel is 4     */
    TIM_ACTIVE_CHANNEL_5        = 0x10U,    /*!< The active channel is 5     */
    TIM_ACTIVE_CHANNEL_6        = 0x20U,    /*!< The active channel is 6     */
    TIM_ACTIVE_CHANNEL_CLEARED  = 0x00U     /*!< All active channels cleared */
};
class COMMONTIMER
{
    using TIMInterruptCb = std::function<void(COMMONTIMER*, TIMISRFlag)>;
public:
    COMMONTIMER(TIM_TypeDef* timer) : timer_(timer), activeChannel_(TIM_ACTIVE_CHANNEL_CLEARED)
    {
        enableClk();
    }
    ~COMMONTIMER()
    {

    }
    COMMONTIMER(const COMMONTIMER&) = delete;
    COMMONTIMER(COMMONTIMER&&) = delete;
    COMMONTIMER& operator=(const COMMONTIMER&) = delete;
    COMMONTIMER& operator=(COMMONTIMER&&) = delete;

    eResult init(uint32_t period, uint32_t prescaler, TIMXCR1CountMode countMode = TIM_COUNTERMODE_UP, uint32_t repetCount = 0, TIMCR1ClkDivi div = TIM_CLOCKDIVISION_DIV1, bool autoReload = true)
    {
        CHECK_RETURN(IS_TIM_INSTANCE(timer_), E_RESULT_INVALID_PARAM);
        uint32_t tmpcr1 = timer_->CR1;
        if(IS_TIM_COUNTER_MODE_SELECT_INSTANCE(timer_))
        {
            MODIFY_REG(tmpcr1, (TIM_CR1_DIR | TIM_CR1_CMS), countMode);
        }
        if (IS_TIM_CLOCK_DIVISION_INSTANCE(timer_))
        {
            MODIFY_REG(tmpcr1, TIM_CR1_CKD, div);
        }
        /* Set the auto-reload preload */
        MODIFY_REG(tmpcr1, TIM_CR1_ARPE, autoReload ? (1 << TIM_CR1_ARPE_Pos) : (0 << TIM_CR1_ARPE_Pos));
        timer_->CR1 = tmpcr1;

        timer_->ARR = static_cast<uint32_t>(period);
        /* Set the Prescaler value */
        timer_->PSC = static_cast<uint32_t>(prescaler);
        if (IS_TIM_REPETITION_COUNTER_INSTANCE(timer_))
        {
            /* Set the Repetition Counter value */
            timer_->RCR = repetCount;
        }

        /* Generate an update event to reload the Prescaler
            and the repetition counter (only for advanced timer) value immediately */
        timer_->EGR = TIM_EGR_UG;
        setAllChannelState(HAL_TIM_CHANNEL_STATE_READY);
        setAllChannelNState(HAL_TIM_CHANNEL_STATE_READY);

        return E_RESULT_OK;
    }
    eResult start()
    {
        CHECK_RETURN(IS_TIM_INSTANCE(timer_), E_RESULT_INVALID_PARAM);
        /* Enable the Peripheral, except in trigger mode where enable is automatically done with trigger */
        if (IS_TIM_SLAVE_INSTANCE(timer_))
        {
            if(!(READ_BIT(timer_->SMCR, TIM_SMCR_SMS) == TIM_SLAVEMODE_TRIGGER || READ_BIT(timer_->SMCR, TIM_SMCR_SMS) == TIM_SLAVEMODE_COMBINED_RESETTRIGGER))
            {
                SET_BIT(timer_->CR1, TIM_CR1_CEN);
            }
        }
        else
        {
            SET_BIT(timer_->CR1, TIM_CR1_CEN);
        }
        return E_RESULT_OK;
    }
    void stop()
    {
        if (IS_TIM_SLAVE_INSTANCE(timer_))
        {
            if(!(READ_BIT(timer_->SMCR, TIM_SMCR_SMS) == TIM_SLAVEMODE_TRIGGER || READ_BIT(timer_->SMCR, TIM_SMCR_SMS) == TIM_SLAVEMODE_COMBINED_RESETTRIGGER))
            {
                CLEAR_BIT(timer_->CR1, TIM_CR1_CEN);
            }
        }
        else
        {
            CLEAR_BIT(timer_->CR1, TIM_CR1_CEN);
        }
    }
    void enableIsr(TIMISRType it, uint32_t PreemptPriority, uint32_t SubPriority)
    {
        registerTimIsrCb(timer_,[](void* param){
            COMMONTIMER* ptim = reinterpret_cast<COMMONTIMER*>(param);
            if(ptim)
            {
                ptim->handlerISREvent();
            }
        },this);
        NVIC_SetPriority(getIrqType(it), NVIC_EncodePriority(NVIC_GetPriorityGrouping(), PreemptPriority, SubPriority));
        NVIC_EnableIRQ(getIrqType(it));
        SET_BIT(timer_->DIER, it);
    }
    void disableIsr(TIMISRType it)
    {
        CLEAR_BIT(timer_->DIER, it);
    }
    void registerInterruptCb(const TIMInterruptCb& isrcb)
    {
        timcb_ = isrcb;
    }
    void unregisterInterruptCb()
    {
        if(timcb_)
        {
            timcb_ = TIMInterruptCb();
        }
    }
    uint32_t getClk()
    {
        uint32_t clk = 0;
        RCCControl* rcc = RCCControl::getInstance();
        uint32_t prescaler = READ_BIT(timer_->PSC,TIM_PSC_PSC);
        switch(reinterpret_cast<uint32_t>(timer_))
        {
            case TIM1_BASE:
            case TIM8_BASE:
            case TIM15_BASE:
            case TIM16_BASE:
            case TIM17_BASE:
                if(rcc->getD2PPRE2APB2PreScale() != RCC_D2_PPRE2_APB2_PRESCALER_DIV1)
                {
                    clk = rcc->getAPB2ClkFreq()*2;
                }
                else
                {
                    clk = rcc->getAPB2ClkFreq();
                }
                break;
            case TIM2_BASE:
            case TIM3_BASE:
            case TIM4_BASE:
            case TIM5_BASE:
            case TIM6_BASE:
            case TIM7_BASE:
            case TIM12_BASE:
            case TIM13_BASE:
            case TIM14_BASE:
                if(rcc->getD2PPRE1APB1PreScaler() != RCC_D2_PPRE1_APB1_PRESCALER_DIV1)
                {
                    clk = rcc->getAPB1ClkFreq()*2;
                }
                else
                {
                    clk = rcc->getAPB1ClkFreq();
                }
                break;
            default:
                break;
        }
        return clk/(prescaler+1);
    }
    uint32_t getTimeoutTimer()
    {
        uint32_t period = READ_BIT(timer_->ARR, TIM_ARR_ARR)+1;
        return period*1000/getClk();
    }
    TIMActiveChannel getActiveChannel() const
    {
        return activeChannel_;
    }
private:
    void handlerISREvent()
    {
        /* Capture compare 1 event */
        if(READ_BIT(timer_->SR, TIM_FLAG_CC1) == TIM_FLAG_CC1)
        {
            if(READ_BIT(timer_->DIER, TIM_IT_CC1) == TIM_IT_CC1)
            {
                CLEAR_BIT(timer_->SR, TIM_FLAG_CC1);
                activeChannel_ = TIM_ACTIVE_CHANNEL_1;
                /* Input capture event */
                if (READ_BIT(timer_->CCMR1, TIM_CCMR1_CC1S) != 0x00U)
                {
                    if(timcb_)
                    {
                        timcb_(this, TIM_FLAG_CC1);
                    }
                }
                else /* Output compare event */
                {
                    if(timcb_)
                    {
                        timcb_(this, TIM_FLAG_CC1);
                    }
                }
                activeChannel_ = TIM_ACTIVE_CHANNEL_CLEARED;
            }
        }
        /* Capture compare 2 event */
        if(READ_BIT(timer_->SR, TIM_FLAG_CC2) == TIM_FLAG_CC2)
        {
            if(READ_BIT(timer_->DIER, TIM_IT_CC2) == TIM_IT_CC2)
            {
                CLEAR_BIT(timer_->SR, TIM_FLAG_CC2);
                activeChannel_ = TIM_ACTIVE_CHANNEL_2;
                /* Input capture event */
                if (READ_BIT(timer_->CCMR1, TIM_CCMR1_CC2S) != 0x00U)
                {
                    if(timcb_)
                    {
                        timcb_(this, TIM_FLAG_CC2);
                    }
                }
                else /* Output compare event */
                {
                    if(timcb_)
                    {
                        timcb_(this, TIM_FLAG_CC2);
                    }
                }
                activeChannel_ = TIM_ACTIVE_CHANNEL_CLEARED;
            }
        }
        /* Capture compare 3 event */
        if(READ_BIT(timer_->SR, TIM_FLAG_CC3) == TIM_FLAG_CC3)
        {
            if(READ_BIT(timer_->DIER, TIM_IT_CC3) == TIM_IT_CC3)
            {
                CLEAR_BIT(timer_->SR, TIM_FLAG_CC3);
                activeChannel_ = TIM_ACTIVE_CHANNEL_3;
                /* Input capture event */
                if (READ_BIT(timer_->CCMR2, TIM_CCMR2_CC3S) != 0x00U)
                {
                    if(timcb_)
                    {
                        timcb_(this, TIM_FLAG_CC3);
                    }
                }
                else /* Output compare event */
                {
                    if(timcb_)
                    {
                        timcb_(this, TIM_FLAG_CC3);
                    }
                }
                activeChannel_ = TIM_ACTIVE_CHANNEL_CLEARED;
            }
        }
        /* Capture compare 4 event */
        if(READ_BIT(timer_->SR, TIM_FLAG_CC4) == TIM_FLAG_CC4)
        {
            if(READ_BIT(timer_->DIER, TIM_IT_CC4) == TIM_IT_CC4)
            {
                CLEAR_BIT(timer_->SR, TIM_FLAG_CC4);
                activeChannel_ = TIM_ACTIVE_CHANNEL_3;
                /* Input capture event */
                if (READ_BIT(timer_->CCMR2, TIM_CCMR2_CC4S) != 0x00U)
                {
                    if(timcb_)
                    {
                        timcb_(this, TIM_FLAG_CC4);
                    }
                }
                else /* Output compare event */
                {
                    if(timcb_)
                    {
                        timcb_(this, TIM_FLAG_CC4);
                    }
                }
                activeChannel_ = TIM_ACTIVE_CHANNEL_CLEARED;
            }
        }
        /* TIM Update event */
        if(READ_BIT(timer_->SR, TIM_FLAG_UPDATE) == TIM_FLAG_UPDATE)
        {
            if(READ_BIT(timer_->DIER, TIM_IT_UPDATE) == TIM_IT_UPDATE)
            {
                CLEAR_BIT(timer_->SR, TIM_FLAG_UPDATE);
                if(timcb_)
                {
                    timcb_(this, TIM_FLAG_UPDATE);
                }
            }
        }
        /* TIM Break input event */
        if(READ_BIT(timer_->SR, TIM_FLAG_BREAK) == TIM_FLAG_BREAK)
        {
            if(READ_BIT(timer_->DIER, TIM_IT_BREAK) == TIM_IT_BREAK)
            {
                CLEAR_BIT(timer_->SR, TIM_FLAG_BREAK);
                if(timcb_)
                {
                    timcb_(this, TIM_FLAG_BREAK);
                }
            }
        }
        /* TIM Break2 input event */
        if(READ_BIT(timer_->SR, TIM_FLAG_BREAK2) == TIM_FLAG_BREAK2)
        {
            if(READ_BIT(timer_->DIER, TIM_IT_BREAK) == TIM_IT_BREAK)
            {
                CLEAR_BIT(timer_->SR, TIM_FLAG_BREAK2);
                if(timcb_)
                {
                    timcb_(this, TIM_FLAG_BREAK2);
                }
            }
        }
        /* TIM Trigger detection event */
        if(READ_BIT(timer_->SR, TIM_FLAG_TRIGGER) == TIM_FLAG_TRIGGER)
        {
            if(READ_BIT(timer_->DIER, TIM_IT_TRIGGER) == TIM_IT_TRIGGER)
            {
                CLEAR_BIT(timer_->SR, TIM_FLAG_TRIGGER);
                if(timcb_)
                {
                    timcb_(this, TIM_FLAG_TRIGGER);
                }
            }
        }
        /* TIM commutation event */
        if(READ_BIT(timer_->SR, TIM_FLAG_COM) == TIM_FLAG_COM)
        {
            if(READ_BIT(timer_->DIER, TIM_IT_COM) == TIM_IT_COM)
            {
                CLEAR_BIT(timer_->SR, TIM_FLAG_COM);
                if(timcb_)
                {
                    timcb_(this, TIM_FLAG_COM);
                }
            }
        }
    }
    inline void setAllChannelState(TIMChannelState sta)
    {
        for(auto& it : channelState_)
        {
            it = sta;
        }
    }
    inline void setAllChannelNState(TIMChannelState sta)
    {
        for(auto& it : channelNState_)
        {
            it = sta;
        }
    }
    void enableClk(bool bEnable = true)
    {
        RCCControl* rcc = RCCControl::getInstance();
        switch (reinterpret_cast<uint32_t>(timer_))
        {
            case TIM1_BASE:
                rcc->enableTIM1PerClk(bEnable);
                break;
            case TIM2_BASE:
                rcc->enableTIM2PerClk(bEnable);
                break;
            case TIM3_BASE:
                rcc->enableTIM3PerClk(bEnable);
                break;
            case TIM4_BASE:
                rcc->enableTIM4PerClk(bEnable);
                break;
            case TIM5_BASE:
                rcc->enableTIM5PerClk(bEnable);
                break;
            case TIM6_BASE:
                rcc->enableTIM6PerClk(bEnable);
            case TIM7_BASE:
                rcc->enableTIM7PerClk(bEnable);
                break;
            case TIM8_BASE:
                rcc->enableTIM8PerClk(bEnable);
                break;
            case TIM12_BASE:
                rcc->enableTIM12PerClk(bEnable);
                break;
            case TIM13_BASE:
                rcc->enableTIM13PerClk(bEnable);
                break;
            case TIM14_BASE:
                rcc->enableTIM14PerClk(bEnable);
                break;
            case TIM15_BASE:
                rcc->enableTIM15PerClk(bEnable);
                break;
            case TIM16_BASE:
                rcc->enableTIM16PerClk(bEnable);
                break;
            case TIM17_BASE:
                rcc->enableTIM17PerClk(bEnable);
                break;
            default:
                break;
        }
    }
    IRQn_Type getIrqType(TIMISRType it)
    {
        IRQn_Type type = TIM1_UP_IRQn;
        switch (reinterpret_cast<uint32_t>(timer_))
        {
            case TIM1_BASE:
                switch (it)
                {
                case TIM_IT_UPDATE:
                    type = TIM1_UP_IRQn;
                    break;
                case TIM_IT_CC1:
                case TIM_IT_CC2:
                case TIM_IT_CC3:
                case TIM_IT_CC4:
                    type = TIM1_CC_IRQn;
                    break;
                case TIM_IT_COM:
                case TIM_IT_TRIGGER:
                    type = TIM1_TRG_COM_IRQn;
                    break;
                case TIM_IT_BREAK:
                    type = TIM1_BRK_IRQn;
                    break;
                default:
                    break;
                }
                break;
            case TIM2_BASE:
                type = TIM2_IRQn;
                break;
            case TIM3_BASE:
                type = TIM3_IRQn;
                break;
            case TIM4_BASE:
                type = TIM4_IRQn;
                break;
            case TIM5_BASE:
                type = TIM5_IRQn;
                break;
            case TIM6_BASE:
                type = TIM6_DAC_IRQn;
            case TIM7_BASE:
                type = TIM7_IRQn;
                break;
            case TIM8_BASE:
                switch (it)
                {
                    case TIM_IT_UPDATE:
                        type = TIM8_UP_TIM13_IRQn;
                        break;
                    case TIM_IT_CC1:
                    case TIM_IT_CC2:
                    case TIM_IT_CC3:
                    case TIM_IT_CC4:
                        type = TIM8_CC_IRQn;
                        break;
                    case TIM_IT_COM:
                    case TIM_IT_TRIGGER:
                        type = TIM8_TRG_COM_TIM14_IRQn;
                        break;
                    case TIM_IT_BREAK:
                        type = TIM8_BRK_TIM12_IRQn;
                        break;
                    default:
                        break;
                }
                break;
            case TIM12_BASE:
                type = TIM8_BRK_TIM12_IRQn;
                break;
            case TIM13_BASE:
                type = TIM8_UP_TIM13_IRQn;
                break;
            case TIM14_BASE:
                type = TIM8_TRG_COM_TIM14_IRQn;
                break;
            case TIM15_BASE:
                type = TIM15_IRQn;
                break;
            case TIM16_BASE:
                type = TIM16_IRQn;
                break;
            case TIM17_BASE:
                type = TIM17_IRQn;
                break;
            default:
                break;
        }
        return type;
    }
private:
    TIM_TypeDef* timer_;
    __IO TIMActiveChannel activeChannel_;
    __IO TIMChannelState  channelState_[6];   /*!< TIM channel operation state                       */
    __IO TIMChannelState  channelNState_[4];  /*!< TIM complementary channel operation state         */
    TIMInterruptCb timcb_;
};