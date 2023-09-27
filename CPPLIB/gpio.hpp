#pragma once
#include "common.hpp"
#include "gpioex.h"
#include "rcc.hpp"
#include <functional>

#define GPIO_MODE_Pos                           0u
#define GPIO_MODE                               (0x3uL << GPIO_MODE_Pos)
#define MODE_INPUT                              (0x0uL << GPIO_MODE_Pos)
#define MODE_OUTPUT                             (0x1uL << GPIO_MODE_Pos)
#define MODE_AF                                 (0x2uL << GPIO_MODE_Pos)
#define MODE_ANALOG                             (0x3uL << GPIO_MODE_Pos)
#define OUTPUT_TYPE_Pos                         4u
#define OUTPUT_TYPE                             (0x1uL << OUTPUT_TYPE_Pos)
#define OUTPUT_PP                               (0x0uL << OUTPUT_TYPE_Pos)
#define OUTPUT_OD                               (0x1uL << OUTPUT_TYPE_Pos)
#define EXTI_MODE_Pos                           16u
#define EXTI_MODE                               (0x3uL << EXTI_MODE_Pos)
#define EXTI_IT                                 (0x1uL << EXTI_MODE_Pos)
#define EXTI_EVT                                (0x2uL << EXTI_MODE_Pos)
#define TRIGGER_MODE_Pos                         20u
#define TRIGGER_MODE                            (0x7uL << TRIGGER_MODE_Pos)
#define TRIGGER_RISING                          (0x1uL << TRIGGER_MODE_Pos)
#define TRIGGER_FALLING                         (0x2uL << TRIGGER_MODE_Pos)
#define TRIGGER_LEVEL                           (0x4uL << TRIGGER_MODE_Pos)

enum GPIOExtiMode
{
    GPIO_MODE_IT_DISABLE          =      0,
    GPIO_MODE_IT_RISING           =     (EXTI_IT | TRIGGER_RISING),                     /*!< External Interrupt Mode with Rising edge trigger detection         */
    GPIO_MODE_IT_FALLING          =     (EXTI_IT | TRIGGER_FALLING),                   /*!< External Interrupt Mode with Falling edge trigger detection        */
    GPIO_MODE_IT_RISING_FALLING   =     (EXTI_IT | TRIGGER_RISING | TRIGGER_FALLING),   /*!< External Interrupt Mode with Rising/Falling edge trigger detection */  
    GPIO_MODE_EVT_RISING          =     (EXTI_EVT | TRIGGER_RISING),                    /*!< External Event Mode with Rising edge trigger detection             */
    GPIO_MODE_EVT_FALLING         =     (EXTI_EVT | TRIGGER_FALLING),                   /*!< External Event Mode with Falling edge trigger detection            */
    GPIO_MODE_EVT_RISING_FALLING  =     (EXTI_EVT | TRIGGER_RISING | TRIGGER_FALLING)  /*!< External Event Mode with Rising/Falling edge trigger detection     */
};

enum GPIONumBit
{
    GPIO_NUM_0 = BIT(0),
    GPIO_NUM_1 = BIT(1),
    GPIO_NUM_2 = BIT(2),
    GPIO_NUM_3 = BIT(3),
    GPIO_NUM_4 = BIT(4),
    GPIO_NUM_5 = BIT(5),
    GPIO_NUM_6 = BIT(6),
    GPIO_NUM_7 = BIT(7),
    GPIO_NUM_8 = BIT(8),
    GPIO_NUM_9 = BIT(9),
    GPIO_NUM_10 = BIT(10),
    GPIO_NUM_11 = BIT(11),
    GPIO_NUM_12 = BIT(12),
    GPIO_NUM_13 = BIT(13),
    GPIO_NUM_14 = BIT(14),
    GPIO_NUM_15 = BIT(15)
};
enum GPIOMode
{
    GPIO_MODE_INPUT       =     MODE_INPUT,
    GPIO_MODE_OUTPUT_PP   =     MODE_OUTPUT | OUTPUT_PP,
    GPIO_MODE_OUTPUT_OD   =     MODE_OUTPUT | OUTPUT_OD,
    GPIO_MODE_AF_PP       =     MODE_AF | OUTPUT_PP,
    GPIO_MODE_AF_OD       =     MODE_AF | OUTPUT_OD,
    GPIO_MODE_ANALOG      =     MODE_ANALOG
};

enum GPIOSpeed
{
    GPIO_SPEED_LOW,				//GPIO 12M
    GPIO_SPEED_MID,				//GPIO 60M
    GPIO_SPEED_FAST,			//GPIO 85M
    GPIO_SPEED_HIGH				//GPIO 100M
};

enum GPIOPupd
{
    GPIO_PUPD_NONE,		        //不带上下拉
    GPIO_PUPD_PU,		        //上拉
    GPIO_PUPD_PD,		        //下拉
    GPIO_PUPD_RES,		        //保留 
};

enum GPIOOType
{
    GPIO_OTYPE_PP,
    GPIO_OTYPE_OD
};

enum GPIOLevel
{
    GPIO_LEVEL_L,
    GPIO_LEVEL_H
};
class GPIO
{
    using GPIOEXTIInterruptCb = std::function<void(GPIO*, GPIONumBit)>;
public:
    GPIO(GPIO_TypeDef* GPIOx, uint32_t ioNum, GPIOMode mode, GPIOSpeed speed, GPIOPupd pupd):gpiox_(GPIOx),mode_(mode)
    {
        RCCControl::getInstance()->enableGPIOPerClk(GPIOx, true);
        init(ioNum, mode, speed, pupd);
    }
    ~GPIO()
    {
    }
    GPIO(const GPIO&) = delete;
    GPIO(GPIO&&) = delete;
    GPIO& operator=(const GPIO&) = delete;
    GPIO& operator=(GPIO&&) = delete;

    //AFx:0~15,代表AF0~AF15.
    //AF0~15设置情况(这里仅是列出常用的,详细的请见STM32H743xx数据手册,Table 9~19):
    //AF0:MCO/SWD/SWCLK/RTC;   		AF1:TIM1/2/TIM16/17/LPTIM1;		AF2:TIM3~5/TIM12/HRTIM1/SAI1;	AF3:TIM8/LPTIM2~5/HRTIM1/LPUART1;
    //AF4:I2C1~I2C4/TIM15/USART1;	AF5:SPI1~SPI6/CEC;         		AF6:SPI3/SAI1~3/UART4/I2C4; 	AF7:SPI2/3/6/USART1~3/6/UART7/SDIO1;
    //AF8:USART4/5/8/SPDIF/SAI2/4;	AF9;FDCAN1~2/TIM13/14/LCD/QSPI; AF10:USB_OTG1/2/SAI2/4/QSPI;  	AF11:ETH/UART7/SDIO2/I2C4/COMP1/2;
    //AF12:FMC/SDIO1/OTG2/LCD;		AF13:DCIM/DSI/LCD/COMP1/2; 		AF14:LCD/UART5;					AF15:EVENTOUT;
    bool setAF(uint32_t gpionum, uint8_t AFx)
    {
        uint16_t pos = 0;
        if(!(gpionum & gpioPibBitNum_))
        {
            return false;
        }
        for(pos = 0; pos < 16; pos++)
        {
            if((gpionum & BIT(pos)) && (gpioPibBitNum_ & BIT(pos)))
            {
                MODIFY_REG(gpiox_->AFR[pos>>3], (0X0F<<((pos&0X07)*4)), AFx<<((pos&0X07)*4));
            }
        }
        return true;
    }
    bool setAF(uint8_t AFx)
    {
        return setAF(gpioPibBitNum_, AFx);
    }
    void resetAF(uint32_t gpionum)
    {
        setAF(gpionum, 0x00);
    }
    void resetAF()
    {
        setAF(0x00);
    }
    void setLevel(GPIOLevel level, uint32_t gpionum)
    {
        if((gpionum & gpioPibBitNum_) == gpionum)
        {
            level ? SET_BIT(gpiox_->BSRR, gpionum) : SET_BIT(gpiox_->BSRR, gpionum << 16);
        }
    }
    void setLevel(GPIOLevel level)
    {
        level ? SET_BIT(gpiox_->BSRR, gpioPibBitNum_) : SET_BIT(gpiox_->BSRR, gpioPibBitNum_ << 16);
    }
    GPIOLevel getLevel(GPIONumBit gpionum)
    {
        return READ_BIT(gpiox_->IDR, gpionum) ? GPIO_LEVEL_H : GPIO_LEVEL_L;
    }
    GPIOLevel getLevel()
    {
        return READ_BIT(gpiox_->IDR, gpioPibBitNum_) ? GPIO_LEVEL_H : GPIO_LEVEL_L;
    }
    bool enableIsr(uint32_t gpionum, GPIOExtiMode extiMode, uint32_t PreemptPriority, uint32_t SubPriority)
    {
        if(mode_ != GPIO_MODE_INPUT)
        {
            return false;
        }
        if(!(gpionum & gpioPibBitNum_))
        {
            return false;
        }

        RCCControl::getInstance()->enableSYSCFGPerClk(true);
        uint32_t offset = (((uint32_t)gpiox_ -  (uint32_t)GPIOA_BASE) / 0x400);
        for(uint16_t pos = 0; pos < 16; pos++)
        {
            if((gpionum & BIT(pos)) && (gpioPibBitNum_ & BIT(pos)))
            {
                MODIFY_REG(SYSCFG->EXTICR[pos >> 2U], (0x0FUL << (4U * (pos & 0x03U))), (offset << (4U * (pos & 0x03U))));
                /* Clear Rising Falling edge configuration */
                (extiMode & TRIGGER_RISING) ? SET_BIT(EXTI->RTSR1, BIT(pos)) : CLEAR_BIT(EXTI->RTSR1, BIT(pos));
                (extiMode & TRIGGER_FALLING) ? SET_BIT(EXTI->FTSR1, BIT(pos)) : CLEAR_BIT(EXTI->FTSR1, BIT(pos));
                (extiMode & EXTI_EVT) ? SET_BIT(EXTI_D1->EMR1, BIT(pos)) : CLEAR_BIT(EXTI_D1->EMR1, BIT(pos));
                (extiMode & EXTI_IT) ? SET_BIT(EXTI_D1->IMR1, BIT(pos)) : CLEAR_BIT(EXTI_D1->IMR1, BIT(pos));
                if(extiMode & EXTI_EVT || extiMode & EXTI_IT)
                {
                    registerGpioIsrCb(gpiox_, pos, [](GPIO_TypeDef *gpiox, uint32_t pin, void* param){
                        GPIO* pgpio = reinterpret_cast<GPIO*>(param);
                        if(pgpio->exticb_)
                        {
                            pgpio->exticb_(pgpio, (GPIONumBit)pin);
                        }
                    }, this);
                    NVIC_SetPriority(getIrqType(pos), NVIC_EncodePriority(NVIC_GetPriorityGrouping(), PreemptPriority, SubPriority));
                    NVIC_EnableIRQ(getIrqType(pos));
                }
            }
        }
        return true;
    }
    bool enableIsr(GPIOExtiMode extiMode, uint32_t PreemptPriority, uint32_t SubPriority)
    {
        return enableIsr(gpioPibBitNum_, extiMode, PreemptPriority, SubPriority);
    }
    bool disableIsr(uint32_t gpionum)
    {
        return enableIsr(gpionum, GPIO_MODE_IT_DISABLE, 0, 0);
    }
    bool disableIsr()
    {
        return disableIsr(gpioPibBitNum_);
    }
    void registerInterruptCb(const GPIOEXTIInterruptCb& isrcb)
    {
        exticb_ = isrcb;
    }
    void unregisterInterruptCb()
    {
        if(exticb_)
        {
            exticb_ = GPIOEXTIInterruptCb();
        }
    }
private:
    void init(uint32_t ioNum, GPIOMode mode, GPIOSpeed speed, GPIOPupd pupd)
    {
        gpioPibBitNum_ = ioNum;
        uint32_t pinpos=0,pos=0,curpin=0;
        for(pinpos=0;pinpos<16;pinpos++)
        {
            pos=1<<pinpos;	//一个个位检查 
            curpin=gpioPibBitNum_&pos;//检查引脚是否要设置
            if(curpin==pos)	//需要设置
            {
                if (((mode & GPIO_MODE) == MODE_OUTPUT) || ((mode & GPIO_MODE) == MODE_AF))
                {
                    MODIFY_REG(gpiox_->OSPEEDR, GPIO_OSPEEDR_OSPEED0 << (pinpos*2U), speed<<(pinpos*2U));
                    MODIFY_REG(gpiox_->OTYPER, GPIO_OTYPER_OT0 << (pinpos), ((mode & OUTPUT_TYPE) >> OUTPUT_TYPE_Pos) << (pinpos));
                }
                if ((mode & GPIO_MODE) != MODE_ANALOG)
                {
                    MODIFY_REG(gpiox_->PUPDR, GPIO_PUPDR_PUPD0 << (pinpos*2U), pupd<<(pinpos*2U));
                }
                MODIFY_REG(gpiox_->MODER, GPIO_MODER_MODE0 << (pinpos*2U), (mode & GPIO_MODE)<<(pinpos*2U));
            }
        }
    }
    void deinit()
    {
        uint32_t pinpos=0,pos=0,curpin=0;
        for(pinpos=0;pinpos<16;pinpos++)
        {
            pos=1<<pinpos;	//一个个位检查 
            curpin=gpioPibBitNum_&pos;//检查引脚是否要设置
            if(curpin==pos)	//需要设置
            {
                CLEAR_BIT(gpiox_->MODER, GPIO_MODER_MODE0 << (pinpos*2U));
                CLEAR_BIT(gpiox_->OSPEEDR, GPIO_OSPEEDR_OSPEED0 << (pinpos*2U));
                CLEAR_BIT(gpiox_->OTYPER, GPIO_OTYPER_OT0 << (pinpos));
                CLEAR_BIT(gpiox_->PUPDR, GPIO_PUPDR_PUPD0 << (pinpos*2U));
                CLEAR_BIT(gpiox_->AFR[pinpos>>3], (0X0F<<((pinpos&0X07)*4)));
            }
        }
    }
    IRQn_Type getIrqType(uint32_t pos)
    {
        IRQn_Type type = EXTI0_IRQn;
        switch (pos)
        {
        case 0:
            type = EXTI0_IRQn;
            break;
        case 1:
            type = EXTI1_IRQn;
            break;
        case 2:
            type = EXTI2_IRQn;
            break;
        case 3:
            type = EXTI3_IRQn;
            break;
        case 4:
            type = EXTI4_IRQn;
            break;
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            type = EXTI9_5_IRQn;
            break;
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
            type = EXTI15_10_IRQn;
            break;
        default:
            break;
        }
        return type;
    }
private:
    GPIO_TypeDef* gpiox_;
    GPIOMode mode_;
    uint32_t gpioPibBitNum_;
    GPIOEXTIInterruptCb exticb_;
};