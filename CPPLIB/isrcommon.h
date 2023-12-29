#pragma once
#include "stm32h7xx.h"

#ifdef __cplusplus
 extern "C" {
#endif
#define BIT(X)  (1UL << (X))
#define  TICK_INT_PRIORITY            ((uint32_t)0x0F) /*!< tick interrupt priority */
#define  MAX_DELAY      0xFFFFFFFFU

#define GPIO_EXTI_GET_IT(__EXTI_LINE__) (EXTI->PR1 & (__EXTI_LINE__))
#define GPIO_EXTI_CLEAR_IT(__EXTI_LINE__) (EXTI->PR1 = (__EXTI_LINE__))

typedef enum
{
  TICK_FREQ_10HZ         = 100U,
  TICK_FREQ_100HZ        = 10U,
  TICK_FREQ_1KHZ         = 1U,
  TICK_FREQ_DEFAULT      = TICK_FREQ_1KHZ
} TickFreqTypeDef;

typedef void (*USART_ISR_CB)(USART_TypeDef *uartx, void* param);
void registerUsartIsrCb(USART_TypeDef *uartx, USART_ISR_CB cb, void* param);
void unRegisterUsartIsrCb(USART_TypeDef *uartx);

typedef void (*GPIO_EXTI_ISR_CB)(GPIO_TypeDef *gpiox, uint32_t pin, void* param);
void registerGpioIsrCb(GPIO_TypeDef *gpiox, uint32_t pinNum, GPIO_EXTI_ISR_CB cb, void* param);
void unRegisterGpioIsrCb(GPIO_TypeDef *gpiox, uint32_t pinNum);

typedef void (*WWDG_ISR_CB)(void* param);
void registerWwdgIsrCb(WWDG_ISR_CB cb, void* param);
void unRegisterWwdgIsrCb();

typedef enum TIMISRType
{
    TIM_IT_UPDATE         =          TIM_DIER_UIE,  
    TIM_IT_CC1            =          TIM_DIER_CC1IE,  
    TIM_IT_CC2            =          TIM_DIER_CC2IE,  
    TIM_IT_CC3            =          TIM_DIER_CC3IE,  
    TIM_IT_CC4            =          TIM_DIER_CC4IE,  
    TIM_IT_COM            =          TIM_DIER_COMIE,  
    TIM_IT_TRIGGER        =          TIM_DIER_TIE,  
    TIM_IT_BREAK          =          TIM_DIER_BIE,
    TIM_IT_DISABLE_ALL    =          (TIM_IT_UPDATE|TIM_IT_CC1|TIM_IT_CC2|TIM_IT_CC3|TIM_IT_CC4|TIM_IT_COM|TIM_IT_TRIGGER|TIM_IT_BREAK)
}TIMISRType;
/** @defgroup TIM_Flag_definition TIM Flag Definition
  * @{
  */
typedef enum TIMISRFlag
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
    TIM_FLAG_CC4OF            =         TIM_SR_CC4OF,                         /*!< Capture 4 overcapture flag    */
    TIM_FLAG_NONE             =         0
}TIMISRFlag;
typedef void (*TIM_ISR_CB)(void* param, TIMISRFlag flags);
void registerTimIsrCb(TIM_TypeDef* timx, TIM_ISR_CB cb, void* param);
void unRegisterTimIsrCb(TIM_TypeDef* timx);

/** @defgroup LPTIM_LL_EC_GET_FLAG Get Flags Defines
  * @brief    Flags defines which can be used with LL_LPTIM_ReadReg function
  * @{
  */
typedef enum LPTIMIsrFlgas
{
    LPTIM_ISR_FLAG_CMPM          =          LPTIM_ISR_CMPM,     /*!< Compare match */
    LPTIM_ISR_FLAG_CMPOK         =          LPTIM_ISR_CMPOK,    /*!< Compare register update OK */
    LPTIM_ISR_FLAG_ARRM          =          LPTIM_ISR_ARRM,     /*!< Autoreload match */
    LPTIM_ISR_FLAG_EXTTRIG       =          LPTIM_ISR_EXTTRIG,  /*!< External trigger edge event */
    LPTIM_ISR_FLAG_ARROK         =          LPTIM_ISR_ARROK,    /*!< Autoreload register update OK */
    LPTIM_ISR_FLAG_UP            =          LPTIM_ISR_UP,       /*!< Counter direction change down to up */
    LPTIM_ISR_FLAG_DOWN          =          LPTIM_ISR_DOWN,     /*!< Counter direction change up to down */
    LPTIM_ISR_FLAG_NONE          =          0,
}LPTIMIsrFlgas;

typedef void (*LPTIM_ISR_CB)(void* param, LPTIMIsrFlgas flags);
void registerLPTimIsrCb(LPTIM_TypeDef* timx, LPTIM_ISR_CB cb, void* param);
void unRegisterLPTimIsrCb(LPTIM_TypeDef* timx);

typedef enum DMATransferIsrType
{
    DMA_TRANSFER_HALF,
    DMA_TRANSFER_COMPLETE,
    DMA_TRANSFER_ERROR,
    DMA_DIRECTOR_MODE_ERROR,
    DMA_FIFO_ERROR,
    DMA_ISR_ERROR
}DMATransferIsrType;

typedef enum BDMATransferIsrType
{
    BDMA_TRANSFER_HALF,
    BDMA_TRANSFER_COMPLETE,
    BDMA_TRANSFER_ERROR,
    BDMA_ISR_GLOBAL_ERROR
}BDMATransferIsrType;

typedef void (*DMA_ISR_CB)(void* param, uint8_t bDMAMuxISR, uint32_t isrtype);
void registerDMAIsrCb(DMA_Stream_TypeDef* stream, DMA_ISR_CB cb, void* param);
void unRegisterDMAIsrCb(DMA_Stream_TypeDef* stream);

void registerBDMAIsrCb(BDMA_Channel_TypeDef* channel, DMA_ISR_CB cb, void* param);
void unRegisterBDMAIsrCb(BDMA_Channel_TypeDef* channel);

int32_t initTick(uint32_t TickPriority);
void incTick(void);
uint32_t getTick(void);
uint32_t getTickPrio(void);
int setTickFreq(TickFreqTypeDef Freq);
TickFreqTypeDef getTickFreq(void);
void delayTick(uint32_t Delay);
#ifdef __cplusplus
}
#endif 