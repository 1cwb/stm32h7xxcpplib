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

typedef void (*TIM_ISR_CB)(void* param);
void registerTimIsrCb(TIM_TypeDef* timx, TIM_ISR_CB cb, void* param);
void unRegisterTimIsrCb(TIM_TypeDef* timx);

typedef void (*DMA_ISR_CB)(void* param, uint8_t bDMAMuxISR);
void registerDMAIsrCb(DMA_Stream_TypeDef* stream, DMA_ISR_CB cb, void* param);
void unRegisterDMAIsrCb(DMA_Stream_TypeDef* stream);

void registerBDMAIsrCb(BDMA_Channel_TypeDef* channel, DMA_ISR_CB cb, void* param);
void unRegisterBDMAIsrCb(BDMA_Channel_TypeDef* channel);

/*typedef void (*DMAMUX_ISR_CB)(void* param);
void registerDMAMUX1IsrCb(DMAMUX_ISR_CB cb, void* param);
void unRegisterDMAMUX1IsrCb();

void registerDMAMUX2IsrCb(DMAMUX_ISR_CB cb, void* param);
void unRegisterDMAMUX2IsrCb();*/

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