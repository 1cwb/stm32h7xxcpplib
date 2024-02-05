#include <stdio.h>
#include "isrcommon.h"

typedef struct usartIsrSt
{
	USART_ISR_CB cb;
	USART_TypeDef *uartx;
	void* param;
}usartIsrSt;

static usartIsrSt usartIsrCbBuff[8] = {0};

void registerUsartIsrCb(USART_TypeDef *uartx, USART_ISR_CB cb, void* param)
{
	if(uartx == USART1)
	{
		usartIsrCbBuff[0].cb =  cb;
		usartIsrCbBuff[0].uartx =  uartx;
		usartIsrCbBuff[0].param =  param;
	}
	else if(uartx == USART2)
	{
		usartIsrCbBuff[1].cb =  cb;
		usartIsrCbBuff[1].uartx =  uartx;
		usartIsrCbBuff[1].param =  param;
	}
	else if(uartx == USART3)
	{
		usartIsrCbBuff[2].cb =  cb;
		usartIsrCbBuff[2].uartx =  uartx;
		usartIsrCbBuff[2].param =  param;
	}
	else if(uartx == UART4)
	{
		usartIsrCbBuff[3].cb =  cb;
		usartIsrCbBuff[3].uartx =  uartx;
		usartIsrCbBuff[3].param =  param;
	}
	else if(uartx == UART5)
	{
		usartIsrCbBuff[4].cb =  cb;
		usartIsrCbBuff[4].uartx =  uartx;
		usartIsrCbBuff[4].param =  param;
	}
	else if(uartx == USART6)
	{
		usartIsrCbBuff[5].cb =  cb;
		usartIsrCbBuff[5].uartx =  uartx;
		usartIsrCbBuff[5].param =  param;
	}
	else if(uartx == UART7)
	{
		usartIsrCbBuff[6].cb =  cb;
		usartIsrCbBuff[6].uartx =  uartx;
		usartIsrCbBuff[6].param =  param;
	}
	else if(uartx == UART8)
	{
		usartIsrCbBuff[7].cb =  cb;
		usartIsrCbBuff[7].uartx =  uartx;
		usartIsrCbBuff[7].param =  param;
	}
}
void unRegisterUsartIsrCb(USART_TypeDef *uartx)
{
	if(uartx == USART1)
	{
		usartIsrCbBuff[0].cb =  NULL;
		usartIsrCbBuff[0].uartx =  NULL;
		usartIsrCbBuff[0].param =  NULL;
	}
	else if(uartx == USART2)
	{
		usartIsrCbBuff[1].cb =  NULL;
		usartIsrCbBuff[1].uartx =  NULL;
		usartIsrCbBuff[1].param =  NULL;
	}
	else if(uartx == USART3)
	{
		usartIsrCbBuff[2].cb =  NULL;
		usartIsrCbBuff[2].uartx =  NULL;
		usartIsrCbBuff[2].param =  NULL;
	}
	else if(uartx == UART4)
	{
		usartIsrCbBuff[3].cb =  NULL;
		usartIsrCbBuff[3].uartx =  NULL;
		usartIsrCbBuff[3].param =  NULL;
	}
	else if(uartx == UART5)
	{
		usartIsrCbBuff[4].cb =  NULL;
		usartIsrCbBuff[4].uartx =  NULL;
		usartIsrCbBuff[4].param =  NULL;
	}
	else if(uartx == USART6)
	{
		usartIsrCbBuff[5].cb =  NULL;
		usartIsrCbBuff[5].uartx =  NULL;
		usartIsrCbBuff[5].param =  NULL;
	}
	else if(uartx == UART7)
	{
		usartIsrCbBuff[6].cb =  NULL;
		usartIsrCbBuff[6].uartx =  NULL;
		usartIsrCbBuff[6].param =  NULL;
	}
	else if(uartx == UART8)
	{
		usartIsrCbBuff[7].cb =  NULL;
		usartIsrCbBuff[7].uartx =  NULL;
		usartIsrCbBuff[7].param =  NULL;
	}
}
//isr callback remap
void usartxIsrCallback(USART_TypeDef *uartx)
{
	for(uint8_t i = 0; i < 8; i++)
	{
		if(usartIsrCbBuff[i].uartx == uartx)
		{
			if(usartIsrCbBuff[i].cb)
			{
				usartIsrCbBuff[i].cb(usartIsrCbBuff[i].uartx, usartIsrCbBuff[i].param);
				break;
			}
		}
	}
}

void USART1_IRQHandler(void)
{
	usartxIsrCallback(USART1);
}
void USART2_IRQHandler(void)
{
	usartxIsrCallback(USART2);
}
void USART3_IRQHandler(void)
{
	usartxIsrCallback(USART3);
}
void UART4_IRQHandler(void)
{
	usartxIsrCallback(UART4);
}
void UART5_IRQHandler(void)
{
	usartxIsrCallback(UART5);
}
void USART6_IRQHandler(void)
{
	usartxIsrCallback(USART6);
}
void UART7_IRQHandler(void)
{
	usartxIsrCallback(UART7);
}
void UART8_IRQHandler(void)
{
	usartxIsrCallback(UART8);
}

/*EXTI HANDLER*/
typedef struct gpioIsrSt
{
	GPIO_EXTI_ISR_CB cb;
	GPIO_TypeDef *gpiox;
	uint32_t pin;
	void* param;
}gpioIsrSt;

static gpioIsrSt gpioIsrCbBuff[16] = {0};
void registerGpioIsrCb(GPIO_TypeDef *gpiox, uint32_t pinNum, GPIO_EXTI_ISR_CB cb, void* param)
{
	gpioIsrCbBuff[pinNum].gpiox = gpiox;
	gpioIsrCbBuff[pinNum].cb = cb;
	gpioIsrCbBuff[pinNum].pin = BIT(pinNum);
	gpioIsrCbBuff[pinNum].param = param;
}

void unRegisterGpioIsrCb(GPIO_TypeDef *gpiox, uint32_t pinNum)
{
	if(gpioIsrCbBuff[pinNum].gpiox == gpiox && BIT(pinNum) == gpioIsrCbBuff[pinNum].pin)
	{
		gpioIsrCbBuff[pinNum].gpiox = NULL;
		gpioIsrCbBuff[pinNum].cb = NULL;
		gpioIsrCbBuff[pinNum].pin = 0xFFFFFF;
		gpioIsrCbBuff[pinNum].param = NULL;
	}
}

void gpioxIsrCallback(uint32_t pinNum)
{
	if(gpioIsrCbBuff[pinNum].cb && gpioIsrCbBuff[pinNum].gpiox && gpioIsrCbBuff[pinNum].pin == BIT(pinNum))
	{
		gpioIsrCbBuff[pinNum].cb(gpioIsrCbBuff[pinNum].gpiox, gpioIsrCbBuff[pinNum].pin, gpioIsrCbBuff[pinNum].param);
	}
}

void EXTI0_IRQHandler()
{
	if(GPIO_EXTI_GET_IT(BIT(0)))
	{
		GPIO_EXTI_CLEAR_IT(BIT(0));
		gpioxIsrCallback(0);
	}
}
void EXTI1_IRQHandler()
{
	if(GPIO_EXTI_GET_IT(BIT(1)))
	{
		GPIO_EXTI_CLEAR_IT(BIT(1));
		gpioxIsrCallback(1);
	}
}
void EXTI2_IRQHandler()
{
	if(GPIO_EXTI_GET_IT(BIT(2)))
	{
		GPIO_EXTI_CLEAR_IT(BIT(2));
		gpioxIsrCallback(2);
	}
}
void EXTI3_IRQHandler()
{
	if(GPIO_EXTI_GET_IT(BIT(3)))
	{
		GPIO_EXTI_CLEAR_IT(BIT(3));
		gpioxIsrCallback(3);
	}
}
void EXTI4_IRQHandler()
{
	if(GPIO_EXTI_GET_IT(BIT(4)))
	{
		GPIO_EXTI_CLEAR_IT(BIT(4));
		gpioxIsrCallback(4);
	}
}
void EXTI9_5_IRQHandler()
{
	if(GPIO_EXTI_GET_IT(BIT(5)))
	{
		GPIO_EXTI_CLEAR_IT(BIT(5));
		gpioxIsrCallback(5);
	}
	else if(GPIO_EXTI_GET_IT(BIT(6)))
	{
		GPIO_EXTI_CLEAR_IT(BIT(6));
		gpioxIsrCallback(6);
	}
	else if(GPIO_EXTI_GET_IT(BIT(7)))
	{
		GPIO_EXTI_CLEAR_IT(BIT(7));
		gpioxIsrCallback(7);
	}
	else if(GPIO_EXTI_GET_IT(BIT(8)))
	{
		GPIO_EXTI_CLEAR_IT(BIT(8));
		gpioxIsrCallback(8);
	}
	else if(GPIO_EXTI_GET_IT(BIT(9)))
	{
		GPIO_EXTI_CLEAR_IT(BIT(9));
		gpioxIsrCallback(9);
	}
}
void EXTI15_10_IRQHandler()
{
	if(GPIO_EXTI_GET_IT(BIT(10)))
	{
		GPIO_EXTI_CLEAR_IT(BIT(10));
		gpioxIsrCallback(10);
	}
	else if(GPIO_EXTI_GET_IT(BIT(11)))
	{
		GPIO_EXTI_CLEAR_IT(BIT(11));
		gpioxIsrCallback(11);
	}
	else if(GPIO_EXTI_GET_IT(BIT(12)))
	{
		GPIO_EXTI_CLEAR_IT(BIT(12));
		gpioxIsrCallback(12);
	}
	else if(GPIO_EXTI_GET_IT(BIT(13)))
	{
		GPIO_EXTI_CLEAR_IT(BIT(13));
		gpioxIsrCallback(13);
	}
	else if(GPIO_EXTI_GET_IT(BIT(14)))
	{
		GPIO_EXTI_CLEAR_IT(BIT(14));
		gpioxIsrCallback(14);
	}
	else if(GPIO_EXTI_GET_IT(BIT(15)))
	{
		GPIO_EXTI_CLEAR_IT(BIT(15));
		gpioxIsrCallback(15);
	}
}

typedef struct wwdgIsrSt
{
	WWDG_ISR_CB cb;
	void* param;
}wwdgIsrSt;

static wwdgIsrSt wwdgIsrCallback = {NULL, NULL};
void registerWwdgIsrCb(WWDG_ISR_CB cb, void* param)
{
	wwdgIsrCallback.cb = cb;
	wwdgIsrCallback.param = param;
}
void unRegisterWwdgIsrCb()
{
	wwdgIsrCallback.cb = NULL;
	wwdgIsrCallback.param = NULL;
}

void WWDG_IRQHandler(void)
{
	if(wwdgIsrCallback.cb)
	{
		wwdgIsrCallback.cb(wwdgIsrCallback.param);
	}
}

typedef struct timIsrSt
{
	TIM_ISR_CB cb;
	TIM_TypeDef *timx;
	void* param;
}timIsrSt;

static timIsrSt timIsrCbBuff[14] = {0};

void registerTimIsrCb(TIM_TypeDef* timx, TIM_ISR_CB cb, void* param)
{
	if(timx == TIM1)
	{
		timIsrCbBuff[0].timx = timx;
		timIsrCbBuff[0].cb = cb;
		timIsrCbBuff[0].param = param;
	}
	else if(timx == TIM2)
	{
		timIsrCbBuff[1].timx = timx;
		timIsrCbBuff[1].cb = cb;
		timIsrCbBuff[1].param = param;
	}
	else if(timx == TIM3)
	{
		timIsrCbBuff[2].timx = timx;
		timIsrCbBuff[2].cb = cb;
		timIsrCbBuff[2].param = param;
	}
	else if(timx == TIM4)
	{
		timIsrCbBuff[3].timx = timx;
		timIsrCbBuff[3].cb = cb;
		timIsrCbBuff[3].param = param;
	}
	else if(timx == TIM5)
	{
		timIsrCbBuff[4].timx = timx;
		timIsrCbBuff[4].cb = cb;
		timIsrCbBuff[4].param = param;
	}
	else if(timx == TIM6)
	{
		timIsrCbBuff[5].timx = timx;
		timIsrCbBuff[5].cb = cb;
		timIsrCbBuff[5].param = param;
	}
	else if(timx == TIM7)
	{
		timIsrCbBuff[6].timx = timx;
		timIsrCbBuff[6].cb = cb;
		timIsrCbBuff[6].param = param;
	}
	else if(timx == TIM8)
	{
		timIsrCbBuff[7].timx = timx;
		timIsrCbBuff[7].cb = cb;
		timIsrCbBuff[7].param = param;
	}
	else if(timx == TIM12)
	{
		timIsrCbBuff[8].timx = timx;
		timIsrCbBuff[8].cb = cb;
		timIsrCbBuff[8].param = param;
	}
	else if(timx == TIM13)
	{
		timIsrCbBuff[9].timx = timx;
		timIsrCbBuff[9].cb = cb;
		timIsrCbBuff[9].param = param;
	}
	else if(timx == TIM14)
	{
		timIsrCbBuff[10].timx = timx;
		timIsrCbBuff[10].cb = cb;
		timIsrCbBuff[10].param = param;
	}
	else if(timx == TIM15)
	{
		timIsrCbBuff[11].timx = timx;
		timIsrCbBuff[11].cb = cb;
		timIsrCbBuff[11].param = param;
	}
	else if(timx == TIM16)
	{
		timIsrCbBuff[12].timx = timx;
		timIsrCbBuff[12].cb = cb;
		timIsrCbBuff[12].param = param;
	}
	else if(timx == TIM17)
	{
		timIsrCbBuff[13].timx = timx;
		timIsrCbBuff[13].cb = cb;
		timIsrCbBuff[13].param = param;
	}
}
void unRegisterTimIsrCb(TIM_TypeDef* timx)
{
	if(timx == TIM1)
	{
		timIsrCbBuff[0].timx = NULL;
		timIsrCbBuff[0].cb = NULL;
		timIsrCbBuff[0].param = NULL;
	}
	else if(timx == TIM2)
	{
		timIsrCbBuff[1].timx = NULL;
		timIsrCbBuff[1].cb = NULL;
		timIsrCbBuff[1].param = NULL;
	}
	else if(timx == TIM3)
	{
		timIsrCbBuff[2].timx = NULL;
		timIsrCbBuff[2].cb = NULL;
		timIsrCbBuff[2].param = NULL;
	}
	else if(timx == TIM4)
	{
		timIsrCbBuff[3].timx = NULL;
		timIsrCbBuff[3].cb = NULL;
		timIsrCbBuff[3].param = NULL;
	}
	else if(timx == TIM5)
	{
		timIsrCbBuff[4].timx = NULL;
		timIsrCbBuff[4].cb = NULL;
		timIsrCbBuff[4].param = NULL;
	}
	else if(timx == TIM6)
	{
		timIsrCbBuff[5].timx = NULL;
		timIsrCbBuff[5].cb = NULL;
		timIsrCbBuff[5].param = NULL;
	}
	else if(timx == TIM7)
	{
		timIsrCbBuff[6].timx = NULL;
		timIsrCbBuff[6].cb = NULL;
		timIsrCbBuff[6].param = NULL;
	}
	else if(timx == TIM8)
	{
		timIsrCbBuff[7].timx = NULL;
		timIsrCbBuff[7].cb = NULL;
		timIsrCbBuff[7].param = NULL;
	}
	else if(timx == TIM12)
	{
		timIsrCbBuff[8].timx = NULL;
		timIsrCbBuff[8].cb = NULL;
		timIsrCbBuff[8].param = NULL;
	}
	else if(timx == TIM13)
	{
		timIsrCbBuff[9].timx = NULL;
		timIsrCbBuff[9].cb = NULL;
		timIsrCbBuff[9].param = NULL;
	}
	else if(timx == TIM14)
	{
		timIsrCbBuff[10].timx = NULL;
		timIsrCbBuff[10].cb = NULL;
		timIsrCbBuff[10].param = NULL;
	}
	else if(timx == TIM15)
	{
		timIsrCbBuff[11].timx = NULL;
		timIsrCbBuff[11].cb = NULL;
		timIsrCbBuff[11].param = NULL;
	}
	else if(timx == TIM16)
	{
		timIsrCbBuff[12].timx = NULL;
		timIsrCbBuff[12].cb = NULL;
		timIsrCbBuff[12].param = NULL;
	}
	else if(timx == TIM17)
	{
		timIsrCbBuff[13].timx = NULL;
		timIsrCbBuff[13].cb = NULL;
		timIsrCbBuff[13].param = NULL;
	}
}
void timxIsrCallback(TIM_TypeDef *timx, TIMISRFlag flags)
{
	for(int i = 0; i < 14; i++)
	{
		if(timIsrCbBuff[i].timx == timx)
		{
			if(timIsrCbBuff[i].cb)
			{
				timIsrCbBuff[i].cb(timIsrCbBuff[i].param, flags);
				break;
			}
		}
	}
}

static void handlerISREvent(TIM_TypeDef *timer_)
{
	TIMISRFlag flag = TIM_FLAG_NONE;
	/* Capture compare 1 event */
	if((READ_BIT(timer_->DIER, TIM_IT_CC1) == TIM_IT_CC1) && (READ_BIT(timer_->SR, TIM_FLAG_CC1) == TIM_FLAG_CC1))
	{
		CLEAR_BIT(timer_->SR, TIM_FLAG_CC1);
		/* Input capture event */
		if (READ_BIT(timer_->CCMR1, TIM_CCMR1_CC1S) != 0x00U)
		{
			flag = TIM_FLAG_CC1;
			timxIsrCallback(timer_, flag);
		}
		else /* Output compare event */
		{
			flag = TIM_FLAG_CC1;
			timxIsrCallback(timer_, flag);
		}
	}
	/* Capture compare 2 event */
	if((READ_BIT(timer_->DIER, TIM_IT_CC2) == TIM_IT_CC2) && (READ_BIT(timer_->SR, TIM_FLAG_CC2) == TIM_FLAG_CC2))
	{
		CLEAR_BIT(timer_->SR, TIM_FLAG_CC2);
		/* Input capture event */
		if (READ_BIT(timer_->CCMR1, TIM_CCMR1_CC2S) != 0x00U)
		{
			flag = TIM_FLAG_CC2;
			timxIsrCallback(timer_, flag);
		}
		else /* Output compare event */
		{
			flag = TIM_FLAG_CC2;
			timxIsrCallback(timer_, flag);
		}
	}
	/* Capture compare 3 event */
	if((READ_BIT(timer_->DIER, TIM_IT_CC3) == TIM_IT_CC3) && (READ_BIT(timer_->SR, TIM_FLAG_CC3) == TIM_FLAG_CC3))
	{
		CLEAR_BIT(timer_->SR, TIM_FLAG_CC3);
		/* Input capture event */
		if (READ_BIT(timer_->CCMR2, TIM_CCMR2_CC3S) != 0x00U)
		{
			flag = TIM_FLAG_CC3;
			timxIsrCallback(timer_, flag);
		}
		else /* Output compare event */
		{
			flag = TIM_FLAG_CC3;
			timxIsrCallback(timer_, flag);
		}
	}
	/* Capture compare 4 event */
	if((READ_BIT(timer_->DIER, TIM_IT_CC4) == TIM_IT_CC4) && (READ_BIT(timer_->SR, TIM_FLAG_CC4) == TIM_FLAG_CC4))
	{
		CLEAR_BIT(timer_->SR, TIM_FLAG_CC4);
		/* Input capture event */
		if (READ_BIT(timer_->CCMR2, TIM_CCMR2_CC4S) != 0x00U)
		{
			flag = TIM_FLAG_CC4;
			timxIsrCallback(timer_, flag);
		}
		else /* Output compare event */
		{
			flag = TIM_FLAG_CC4;
			timxIsrCallback(timer_, flag);
		}
	}
	/* TIM Update event */
	if((READ_BIT(timer_->DIER, TIM_IT_UPDATE) == TIM_IT_UPDATE) && (READ_BIT(timer_->SR, TIM_FLAG_UPDATE) == TIM_FLAG_UPDATE))
	{
		CLEAR_BIT(timer_->SR, TIM_FLAG_UPDATE);
		flag = TIM_FLAG_UPDATE;
		timxIsrCallback(timer_, flag);
	}
	/* TIM Break input event */
	if((READ_BIT(timer_->DIER, TIM_IT_BREAK) == TIM_IT_BREAK) && (READ_BIT(timer_->SR, TIM_FLAG_BREAK) == TIM_FLAG_BREAK))
	{
		CLEAR_BIT(timer_->SR, TIM_FLAG_BREAK);
		flag = TIM_FLAG_BREAK;
		timxIsrCallback(timer_, flag);
	}
	/* TIM Break2 input event */
	if((READ_BIT(timer_->DIER, TIM_IT_BREAK) == TIM_IT_BREAK) && (READ_BIT(timer_->SR, TIM_FLAG_BREAK2) == TIM_FLAG_BREAK2))
	{
		CLEAR_BIT(timer_->SR, TIM_FLAG_BREAK2);
		flag = TIM_FLAG_BREAK2;
		timxIsrCallback(timer_, flag);
	}
	/* TIM Trigger detection event */
	if((READ_BIT(timer_->DIER, TIM_IT_TRIGGER) == TIM_IT_TRIGGER) && (READ_BIT(timer_->SR, TIM_FLAG_TRIGGER) == TIM_FLAG_TRIGGER))
	{
		CLEAR_BIT(timer_->SR, TIM_FLAG_TRIGGER);
		flag = TIM_FLAG_TRIGGER;
		timxIsrCallback(timer_, flag);
	}
	/* TIM commutation event */
	if((READ_BIT(timer_->DIER, TIM_IT_COM) == TIM_IT_COM) && (READ_BIT(timer_->SR, TIM_FLAG_COM) == TIM_FLAG_COM))
	{
		CLEAR_BIT(timer_->SR, TIM_FLAG_COM);
		flag = TIM_FLAG_COM;
		timxIsrCallback(timer_, flag);
	}
}

void TIM1_BRK_IRQHandler(void)
{
	handlerISREvent(TIM1);
}
void TIM1_UP_IRQHandler(void)
{
	handlerISREvent(TIM1);
}
void TIM1_TRG_COM_IRQHandler(void)
{
	handlerISREvent(TIM1);
}
void TIM1_CC_IRQHandler(void)
{
	handlerISREvent(TIM1);
}
void TIM2_IRQHandler(void)
{
	handlerISREvent(TIM2);
}
void TIM3_IRQHandler(void)
{
	handlerISREvent(TIM3);
}
void TIM4_IRQHandler(void)
{
	handlerISREvent(TIM4);
}
void TIM5_IRQHandler(void)
{
	handlerISREvent(TIM5);
}
void TIM6_DAC_IRQHandler(void)
{
	handlerISREvent(TIM6);
}
void TIM7_IRQHandler(void)
{
	handlerISREvent(TIM7);
}
void TIM8_BRK_TIM12_IRQHandler(void)
{
	if(READ_BIT(TIM8->SR, TIM_SR_BIF) == TIM_SR_BIF)
	{
		handlerISREvent(TIM8);
	}
	else
	{
		handlerISREvent(TIM12);
	}
}
void TIM8_UP_TIM13_IRQHandler(void)
{
	if(READ_BIT(TIM8->SR, TIM_SR_UIF) == TIM_SR_UIF)
	{
		handlerISREvent(TIM8);
	}
	else
	{
		handlerISREvent(TIM13);
	}
}
void TIM8_TRG_COM_TIM14_IRQHandler(void)
{
	if(READ_BIT(TIM8->SR, TIM_SR_COMIF) == TIM_SR_COMIF || READ_BIT(TIM8->SR, TIM_SR_TIF) == TIM_SR_TIF)
	{
		handlerISREvent(TIM8);
	}
	else
	{
		handlerISREvent(TIM14);
	}
}
void TIM8_CC_IRQHandler(void)
{
	handlerISREvent(TIM8);
}
void TIM15_IRQHandler(void)
{
	handlerISREvent(TIM15);
}
void TIM16_IRQHandler(void)
{
	handlerISREvent(TIM16);
}
void TIM17_IRQHandler(void)
{
	handlerISREvent(TIM17);
}

typedef struct lptimIsrSt
{
	LPTIM_ISR_CB cb;
	LPTIM_TypeDef *timx;
	void* param;
}lptimIsrSt;

static lptimIsrSt lptimIsrCbBuff[5] = {0};

void registerLPTimIsrCb(LPTIM_TypeDef* timx, LPTIM_ISR_CB cb, void* param)
{
	if(timx == LPTIM1)
	{
		lptimIsrCbBuff[0].timx = timx;
		lptimIsrCbBuff[0].cb = cb;
		lptimIsrCbBuff[0].param = param;
	}
	else if(timx == LPTIM2)
	{
		lptimIsrCbBuff[1].timx = timx;
		lptimIsrCbBuff[1].cb = cb;
		lptimIsrCbBuff[1].param = param;
	}
	else if(timx == LPTIM3)
	{
		lptimIsrCbBuff[2].timx = timx;
		lptimIsrCbBuff[2].cb = cb;
		lptimIsrCbBuff[2].param = param;
	}
	else if(timx == LPTIM4)
	{
		lptimIsrCbBuff[3].timx = timx;
		lptimIsrCbBuff[3].cb = cb;
		lptimIsrCbBuff[3].param = param;
	}
	else if(timx == LPTIM5)
	{
		lptimIsrCbBuff[4].timx = timx;
		lptimIsrCbBuff[4].cb = cb;
		lptimIsrCbBuff[4].param = param;
	}
}
void unRegisterLPTimIsrCb(LPTIM_TypeDef* timx)
{
	if(timx == LPTIM1)
	{
		lptimIsrCbBuff[0].timx = NULL;
		lptimIsrCbBuff[0].cb = NULL;
		lptimIsrCbBuff[0].param = NULL;
	}
	else if(timx == LPTIM2)
	{
		lptimIsrCbBuff[1].timx = NULL;
		lptimIsrCbBuff[1].cb = NULL;
		lptimIsrCbBuff[1].param = NULL;
	}
	else if(timx == LPTIM3)
	{
		lptimIsrCbBuff[2].timx = NULL;
		lptimIsrCbBuff[2].cb = NULL;
		lptimIsrCbBuff[2].param = NULL;
	}
	else if(timx == LPTIM4)
	{
		lptimIsrCbBuff[3].timx = NULL;
		lptimIsrCbBuff[3].cb = NULL;
		lptimIsrCbBuff[3].param = NULL;
	}
	else if(timx == LPTIM5)
	{
		lptimIsrCbBuff[4].timx = NULL;
		lptimIsrCbBuff[4].cb = NULL;
		lptimIsrCbBuff[4].param = NULL;
	}
}
void lptimxIsrCallback(LPTIM_TypeDef *timx, LPTIMIsrFlgas flags)
{
	for(int i = 0; i < 5; i++)
	{
		if(lptimIsrCbBuff[i].timx == timx)
		{
			if(lptimIsrCbBuff[i].cb)
			{
				lptimIsrCbBuff[i].cb(lptimIsrCbBuff[i].param, flags);
				break;
			}
		}
	}
}
void lptimHandlerISREvent(LPTIM_TypeDef *timx)
{
	LPTIMIsrFlgas flags = LPTIM_ISR_FLAG_NONE;
	if((READ_BIT(timx->IER, LPTIM_IER_CMPMIE) == LPTIM_IER_CMPMIE) && (READ_BIT(timx->ISR, LPTIM_ISR_CMPM) == LPTIM_ISR_CMPM))
	{
		SET_BIT(timx->ICR, LPTIM_ICR_CMPMCF);
		flags = LPTIM_ISR_FLAG_CMPM;
		lptimxIsrCallback(timx, flags);
	}
	if((READ_BIT(timx->ISR, LPTIM_ISR_CMPOK) == LPTIM_ISR_CMPOK) && (READ_BIT(timx->ISR, LPTIM_ISR_CMPOK) == LPTIM_ISR_CMPOK))
	{
		SET_BIT(timx->ICR, LPTIM_ICR_CMPOKCF);
		flags = LPTIM_ISR_FLAG_CMPOK;
		lptimxIsrCallback(timx, flags);
	}
	if((READ_BIT(timx->ISR, LPTIM_ISR_ARRM) == LPTIM_ISR_ARRM) && (READ_BIT(timx->ISR, LPTIM_ISR_ARRM) == LPTIM_ISR_ARRM))
	{
		SET_BIT(timx->ICR, LPTIM_ICR_ARRMCF);
		flags = LPTIM_ISR_FLAG_ARRM;
		lptimxIsrCallback(timx, flags);
	}
	if((READ_BIT(timx->ISR, LPTIM_ISR_ARROK) == LPTIM_ISR_ARROK) && (READ_BIT(timx->ISR, LPTIM_ISR_ARROK) == LPTIM_ISR_ARROK))
	{
		SET_BIT(timx->ICR, LPTIM_ICR_ARROKCF);
		flags = LPTIM_ISR_FLAG_ARROK;
		lptimxIsrCallback(timx, flags);
	}
	if((READ_BIT(timx->ISR, LPTIM_ISR_EXTTRIG) == LPTIM_ISR_EXTTRIG) && (READ_BIT(timx->ISR, LPTIM_ISR_EXTTRIG) == LPTIM_ISR_EXTTRIG))
	{
		SET_BIT(timx->ICR, LPTIM_ICR_EXTTRIGCF);
		flags = LPTIM_ISR_FLAG_EXTTRIG;
		lptimxIsrCallback(timx, flags);
	}
	if((READ_BIT(timx->ISR, LPTIM_ISR_UP) == LPTIM_ISR_UP) && (READ_BIT(timx->ISR, LPTIM_ISR_UP) == LPTIM_ISR_UP))
	{
		SET_BIT(timx->ICR, LPTIM_ICR_UPCF);
		flags = LPTIM_ISR_FLAG_UP;
		lptimxIsrCallback(timx, flags);
	}
	if((READ_BIT(timx->ISR, LPTIM_ISR_DOWN) == LPTIM_ISR_DOWN) && (READ_BIT(timx->ISR, LPTIM_ISR_DOWN) == LPTIM_ISR_DOWN))
	{
		SET_BIT(timx->ICR, LPTIM_ICR_DOWNCF);
		flags = LPTIM_ISR_FLAG_DOWN;
		lptimxIsrCallback(timx, flags);
	}
}
void LPTIM1_IRQHandler()
{
	lptimHandlerISREvent(LPTIM1);
}
void LPTIM2_IRQHandler()
{
	lptimHandlerISREvent(LPTIM2);
}
void LPTIM3_IRQHandler()
{
	lptimHandlerISREvent(LPTIM3);
}
void LPTIM4_IRQHandler()
{
	lptimHandlerISREvent(LPTIM4);
}
void LPTIM5_IRQHandler()
{
	lptimHandlerISREvent(LPTIM5);
}

typedef struct DMAIsrSt
{
	DMA_ISR_CB cb;
	DMA_Stream_TypeDef *stream;
	void* param;
}DMAIsrSt;
typedef struct BDMAIsrSt
{
	DMA_ISR_CB cb;
	BDMA_Channel_TypeDef *channel;
	void* param;
}BDMAIsrSt;
static DMAIsrSt DMAIsrCbBuff[16] = {0};
static BDMAIsrSt BDMAIsrCbBuff[8] = {0};

void registerDMAIsrCb(DMA_Stream_TypeDef* stream, DMA_ISR_CB cb, void* param)
{
	switch((uint32_t)stream)
	{
		case (uint32_t)DMA1_Stream0:
			DMAIsrCbBuff[0].cb = cb;
			DMAIsrCbBuff[0].stream = stream;
			DMAIsrCbBuff[0].param = param;
			break;
		case (uint32_t)DMA1_Stream1:
			DMAIsrCbBuff[1].cb = cb;
			DMAIsrCbBuff[1].stream = stream;
			DMAIsrCbBuff[1].param = param;
			break;
		case (uint32_t)DMA1_Stream2:
			DMAIsrCbBuff[2].cb = cb;
			DMAIsrCbBuff[2].stream = stream;
			DMAIsrCbBuff[2].param = param;
			break;
		case (uint32_t)DMA1_Stream3:
			DMAIsrCbBuff[3].cb = cb;
			DMAIsrCbBuff[3].stream = stream;
			DMAIsrCbBuff[3].param = param;
			break;
		case (uint32_t)DMA1_Stream4:
	    	DMAIsrCbBuff[4].cb = cb;
			DMAIsrCbBuff[4].stream = stream;
			DMAIsrCbBuff[4].param = param;
			break;
		case (uint32_t)DMA1_Stream5:
			DMAIsrCbBuff[5].cb = cb;
			DMAIsrCbBuff[5].stream = stream;
			DMAIsrCbBuff[5].param = param;
			break;
		case (uint32_t)DMA1_Stream6:
			DMAIsrCbBuff[6].cb = cb;
			DMAIsrCbBuff[6].stream = stream;
			DMAIsrCbBuff[6].param = param;
			break;
		case (uint32_t)DMA1_Stream7:
			DMAIsrCbBuff[7].cb = cb;
			DMAIsrCbBuff[7].stream = stream;
			DMAIsrCbBuff[7].param = param;
			break;
		case (uint32_t)DMA2_Stream0:
			DMAIsrCbBuff[8].cb = cb;
			DMAIsrCbBuff[8].stream = stream;
			DMAIsrCbBuff[8].param = param;
			break;
		case (uint32_t)DMA2_Stream1:
			DMAIsrCbBuff[9].cb = cb;
			DMAIsrCbBuff[9].stream = stream;
			DMAIsrCbBuff[9].param = param;
			break;
		case (uint32_t)DMA2_Stream2:
			DMAIsrCbBuff[10].cb = cb;
			DMAIsrCbBuff[10].stream = stream;
			DMAIsrCbBuff[10].param = param;
			break;
		case (uint32_t)DMA2_Stream3:
			DMAIsrCbBuff[11].cb = cb;
			DMAIsrCbBuff[11].stream = stream;
			DMAIsrCbBuff[11].param = param;
			break;
		case (uint32_t)DMA2_Stream4:
			DMAIsrCbBuff[12].cb = cb;
			DMAIsrCbBuff[12].stream = stream;
			DMAIsrCbBuff[12].param = param;
			break;
		case (uint32_t)DMA2_Stream5:
			DMAIsrCbBuff[13].cb = cb;
			DMAIsrCbBuff[13].stream = stream;
			DMAIsrCbBuff[13].param = param;
			break;
		case (uint32_t)DMA2_Stream6:
			DMAIsrCbBuff[14].cb = cb;
			DMAIsrCbBuff[14].stream = stream;
			DMAIsrCbBuff[14].param = param;
			break;
		case (uint32_t)DMA2_Stream7:
			DMAIsrCbBuff[15].cb = cb;
			DMAIsrCbBuff[15].stream = stream;
			DMAIsrCbBuff[15].param = param;
			break;
		default:
			break;
	}
}
void unRegisterDMAIsrCb(DMA_Stream_TypeDef* stream)
{
	for(int i = 0; i < 16; i++)
	{
		if(((uint32_t)stream) == ((uint32_t)DMAIsrCbBuff[i].stream))
		{
			DMAIsrCbBuff[i].cb = NULL;
			DMAIsrCbBuff[i].stream = NULL;
			DMAIsrCbBuff[i].param = NULL;
			break;
		}
	}
}

void registerBDMAIsrCb(BDMA_Channel_TypeDef* channel, DMA_ISR_CB cb, void* param)
{
	switch ((uint32_t) channel)
	{
	case (uint32_t)BDMA_Channel0:
		BDMAIsrCbBuff[0].cb = cb;
		BDMAIsrCbBuff[0].channel = channel;
		BDMAIsrCbBuff[0].param = param;
		break;
	case (uint32_t)BDMA_Channel1:
		BDMAIsrCbBuff[1].cb = cb;
		BDMAIsrCbBuff[1].channel = channel;
		BDMAIsrCbBuff[1].param = param;
		break;
	case (uint32_t)BDMA_Channel2:
		BDMAIsrCbBuff[2].cb = cb;
		BDMAIsrCbBuff[2].channel = channel;
		BDMAIsrCbBuff[2].param = param;
		break;
	case (uint32_t)BDMA_Channel3:
		BDMAIsrCbBuff[3].cb = cb;
		BDMAIsrCbBuff[3].channel = channel;
		BDMAIsrCbBuff[3].param = param;
		break;
	case (uint32_t)BDMA_Channel4:
		BDMAIsrCbBuff[4].cb = cb;
		BDMAIsrCbBuff[4].channel = channel;
		BDMAIsrCbBuff[4].param = param;
		break;
	case (uint32_t)BDMA_Channel5:
		BDMAIsrCbBuff[5].cb = cb;
		BDMAIsrCbBuff[5].channel = channel;
		BDMAIsrCbBuff[5].param = param;
		break;
	case (uint32_t)BDMA_Channel6:
		BDMAIsrCbBuff[6].cb = cb;
		BDMAIsrCbBuff[6].channel = channel;
		BDMAIsrCbBuff[6].param = param;
		break;
	case (uint32_t)BDMA_Channel7:
		BDMAIsrCbBuff[7].cb = cb;
		BDMAIsrCbBuff[7].channel = channel;
		BDMAIsrCbBuff[7].param = param;
		break;
	default:
		break;
	}
}
void unRegisterBDMAIsrCb(BDMA_Channel_TypeDef* channel)
{
	for(int i = 0; i < 8; i++)
	{
		if(((uint32_t)channel) == ((uint32_t)BDMAIsrCbBuff[i].channel))
		{
			BDMAIsrCbBuff[i].cb = NULL;
			BDMAIsrCbBuff[i].channel = NULL;
			BDMAIsrCbBuff[i].param = NULL;
			break;
		}
	}
}
void DMA1_Stream0_IRQHandler()
{
	DMATransferIsrType isrType = DMA_ISR_ERROR;
	if((READ_BIT(DMA1_Stream0->CR, DMA_SxCR_HTIE) == DMA_SxCR_HTIE) && (READ_BIT(DMA1->LISR, DMA_LISR_HTIF0) == (DMA_LISR_HTIF0)))
	{
		WRITE_REG(DMA1->LIFCR, DMA_LIFCR_CHTIF0);
		isrType = DMA_TRANSFER_HALF;
		if(DMAIsrCbBuff[0].cb)
		{
			DMAIsrCbBuff[0].cb(DMAIsrCbBuff[0].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA1_Stream0->CR, DMA_SxCR_TCIE) == DMA_SxCR_TCIE) && READ_BIT(DMA1->LISR, DMA_LISR_TCIF0) == (DMA_LISR_TCIF0))
	{
		WRITE_REG(DMA1->LIFCR, DMA_LIFCR_CTCIF0);
		isrType = DMA_TRANSFER_COMPLETE;
		if(DMAIsrCbBuff[0].cb)
		{
			DMAIsrCbBuff[0].cb(DMAIsrCbBuff[0].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA1_Stream0->CR, DMA_SxCR_TEIE) == DMA_SxCR_TEIE) && READ_BIT(DMA1->LISR, DMA_LISR_TEIF0) == (DMA_LISR_TEIF0))
	{
		WRITE_REG(DMA1->LIFCR, DMA_LIFCR_CTEIF0);
		isrType = DMA_TRANSFER_ERROR;
		if(DMAIsrCbBuff[0].cb)
		{
			DMAIsrCbBuff[0].cb(DMAIsrCbBuff[0].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA1_Stream0->CR, DMA_SxCR_DMEIE) == DMA_SxCR_DMEIE) && READ_BIT(DMA1->LISR, DMA_LISR_DMEIF0) == (DMA_LISR_DMEIF0))
	{
		WRITE_REG(DMA1->LIFCR, DMA_LIFCR_CDMEIF0);
		isrType = DMA_DIRECTOR_MODE_ERROR;
		if(DMAIsrCbBuff[0].cb)
		{
			DMAIsrCbBuff[0].cb(DMAIsrCbBuff[0].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA1_Stream0->FCR, DMA_SxFCR_FEIE) == DMA_SxFCR_FEIE) && READ_BIT(DMA1->LISR, DMA_LISR_FEIF0) == (DMA_LISR_FEIF0))
	{
		WRITE_REG(DMA1->LIFCR, DMA_LIFCR_CFEIF0);
		isrType = DMA_FIFO_ERROR;
		if(DMAIsrCbBuff[0].cb)
		{
			DMAIsrCbBuff[0].cb(DMAIsrCbBuff[0].param, 0, isrType);
		}
	}
}
void DMA1_Stream1_IRQHandler()
{
	DMATransferIsrType isrType = DMA_ISR_ERROR;
	if((READ_BIT(DMA1_Stream1->CR, DMA_SxCR_HTIE) == DMA_SxCR_HTIE) && (READ_BIT(DMA1->LISR, DMA_LISR_HTIF1) == (DMA_LISR_HTIF1)))
	{
		WRITE_REG(DMA1->LIFCR, DMA_LIFCR_CHTIF1);
		isrType = DMA_TRANSFER_HALF;
		if(DMAIsrCbBuff[1].cb)
		{
			DMAIsrCbBuff[1].cb(DMAIsrCbBuff[1].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA1_Stream1->CR, DMA_SxCR_TCIE) == DMA_SxCR_TCIE) && READ_BIT(DMA1->LISR, DMA_LISR_TCIF1) == (DMA_LISR_TCIF1))
	{
		WRITE_REG(DMA1->LIFCR, DMA_LIFCR_CTCIF1);
		isrType = DMA_TRANSFER_COMPLETE;
		if(DMAIsrCbBuff[1].cb)
		{
			DMAIsrCbBuff[1].cb(DMAIsrCbBuff[1].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA1_Stream1->CR, DMA_SxCR_TEIE) == DMA_SxCR_TEIE) && READ_BIT(DMA1->LISR, DMA_LISR_TEIF1) == (DMA_LISR_TEIF1))
	{
		WRITE_REG(DMA1->LIFCR, DMA_LIFCR_CTEIF1);
		isrType = DMA_TRANSFER_ERROR;
		if(DMAIsrCbBuff[1].cb)
		{
			DMAIsrCbBuff[1].cb(DMAIsrCbBuff[1].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA1_Stream1->CR, DMA_SxCR_DMEIE) == DMA_SxCR_DMEIE) && READ_BIT(DMA1->LISR, DMA_LISR_DMEIF1) == (DMA_LISR_DMEIF1))
	{
		WRITE_REG(DMA1->LIFCR, DMA_LIFCR_CDMEIF1);
		isrType = DMA_DIRECTOR_MODE_ERROR;
		if(DMAIsrCbBuff[1].cb)
		{
			DMAIsrCbBuff[1].cb(DMAIsrCbBuff[1].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA1_Stream1->FCR, DMA_SxFCR_FEIE) == DMA_SxFCR_FEIE) && READ_BIT(DMA1->LISR, DMA_LISR_FEIF1) == (DMA_LISR_FEIF1))
	{
		WRITE_REG(DMA1->LIFCR, DMA_LIFCR_CFEIF1);
		isrType = DMA_FIFO_ERROR;
		if(DMAIsrCbBuff[1].cb)
		{
			DMAIsrCbBuff[1].cb(DMAIsrCbBuff[1].param, 0, isrType);
		}
	}
}
void DMA1_Stream2_IRQHandler()
{
	DMATransferIsrType isrType = DMA_ISR_ERROR;
	if((READ_BIT(DMA1_Stream2->CR, DMA_SxCR_HTIE) == DMA_SxCR_HTIE) && (READ_BIT(DMA1->LISR, DMA_LISR_HTIF2) == (DMA_LISR_HTIF2)))
	{
		WRITE_REG(DMA1->LIFCR, DMA_LIFCR_CHTIF2);
		isrType = DMA_TRANSFER_HALF;
		if(DMAIsrCbBuff[2].cb)
		{
			DMAIsrCbBuff[2].cb(DMAIsrCbBuff[2].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA1_Stream2->CR, DMA_SxCR_TCIE) == DMA_SxCR_TCIE) && READ_BIT(DMA1->LISR, DMA_LISR_TCIF2) == (DMA_LISR_TCIF2))
	{
		WRITE_REG(DMA1->LIFCR, DMA_LIFCR_CTCIF2);
		isrType = DMA_TRANSFER_COMPLETE;
		if(DMAIsrCbBuff[2].cb)
		{
			DMAIsrCbBuff[2].cb(DMAIsrCbBuff[2].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA1_Stream2->CR, DMA_SxCR_TEIE) == DMA_SxCR_TEIE) && READ_BIT(DMA1->LISR, DMA_LISR_TEIF2) == (DMA_LISR_TEIF2))
	{
		WRITE_REG(DMA1->LIFCR, DMA_LIFCR_CTEIF2);
		isrType = DMA_TRANSFER_ERROR;
		if(DMAIsrCbBuff[2].cb)
		{
			DMAIsrCbBuff[2].cb(DMAIsrCbBuff[2].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA1_Stream2->CR, DMA_SxCR_DMEIE) == DMA_SxCR_DMEIE) && READ_BIT(DMA1->LISR, DMA_LISR_DMEIF2) == (DMA_LISR_DMEIF2))
	{
		WRITE_REG(DMA1->LIFCR, DMA_LIFCR_CDMEIF2);
		isrType = DMA_DIRECTOR_MODE_ERROR;
		if(DMAIsrCbBuff[2].cb)
		{
			DMAIsrCbBuff[2].cb(DMAIsrCbBuff[2].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA1_Stream2->FCR, DMA_SxFCR_FEIE) == DMA_SxFCR_FEIE) && READ_BIT(DMA1->LISR, DMA_LISR_FEIF2) == (DMA_LISR_FEIF2))
	{
		WRITE_REG(DMA1->LIFCR, DMA_LIFCR_CFEIF2);
		isrType = DMA_FIFO_ERROR;
		if(DMAIsrCbBuff[2].cb)
		{
			DMAIsrCbBuff[2].cb(DMAIsrCbBuff[2].param, 0, isrType);
		}
	}
}
void DMA1_Stream3_IRQHandler()
{
	DMATransferIsrType isrType = DMA_ISR_ERROR;
	if((READ_BIT(DMA1_Stream3->CR, DMA_SxCR_HTIE) == DMA_SxCR_HTIE) && (READ_BIT(DMA1->LISR, DMA_LISR_HTIF3) == (DMA_LISR_HTIF3)))
	{
		WRITE_REG(DMA1->LIFCR, DMA_LIFCR_CHTIF3);
		isrType = DMA_TRANSFER_HALF;
		if(DMAIsrCbBuff[3].cb)
		{
			DMAIsrCbBuff[3].cb(DMAIsrCbBuff[3].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA1_Stream3->CR, DMA_SxCR_TCIE) == DMA_SxCR_TCIE) && READ_BIT(DMA1->LISR, DMA_LISR_TCIF3) == (DMA_LISR_TCIF3))
	{
		WRITE_REG(DMA1->LIFCR, DMA_LIFCR_CTCIF3);
		isrType = DMA_TRANSFER_COMPLETE;
		if(DMAIsrCbBuff[3].cb)
		{
			DMAIsrCbBuff[3].cb(DMAIsrCbBuff[3].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA1_Stream3->CR, DMA_SxCR_TEIE) == DMA_SxCR_TEIE) && READ_BIT(DMA1->LISR, DMA_LISR_TEIF3) == (DMA_LISR_TEIF3))
	{
		WRITE_REG(DMA1->LIFCR, DMA_LIFCR_CTEIF3);
		isrType = DMA_TRANSFER_ERROR;
		if(DMAIsrCbBuff[3].cb)
		{
			DMAIsrCbBuff[3].cb(DMAIsrCbBuff[3].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA1_Stream3->CR, DMA_SxCR_DMEIE) == DMA_SxCR_DMEIE) && READ_BIT(DMA1->LISR, DMA_LISR_DMEIF3) == (DMA_LISR_DMEIF3))
	{
		WRITE_REG(DMA1->LIFCR, DMA_LIFCR_CDMEIF3);
		isrType = DMA_DIRECTOR_MODE_ERROR;
		if(DMAIsrCbBuff[3].cb)
		{
			DMAIsrCbBuff[3].cb(DMAIsrCbBuff[3].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA1_Stream3->FCR, DMA_SxFCR_FEIE) == DMA_SxFCR_FEIE) && READ_BIT(DMA1->LISR, DMA_LISR_FEIF3) == (DMA_LISR_FEIF3))
	{
		WRITE_REG(DMA1->LIFCR, DMA_LIFCR_CFEIF3);
		isrType = DMA_FIFO_ERROR;
		if(DMAIsrCbBuff[3].cb)
		{
			DMAIsrCbBuff[3].cb(DMAIsrCbBuff[3].param, 0, isrType);
		}
	}
}
void DMA1_Stream4_IRQHandler()
{
	DMATransferIsrType isrType = DMA_ISR_ERROR;
	if((READ_BIT(DMA1_Stream4->CR, DMA_SxCR_HTIE) == DMA_SxCR_HTIE) && READ_BIT(DMA1->HISR, DMA_HISR_HTIF4) == (DMA_HISR_HTIF4))
	{
		WRITE_REG(DMA1->HIFCR, DMA_HIFCR_CHTIF4);
		isrType = DMA_TRANSFER_HALF;
		if(DMAIsrCbBuff[4].cb)
		{
			DMAIsrCbBuff[4].cb(DMAIsrCbBuff[4].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA1_Stream4->CR, DMA_SxCR_TCIE) == DMA_SxCR_TCIE) && READ_BIT(DMA1->HISR, DMA_HISR_TCIF4) == (DMA_HISR_TCIF4))
	{
		WRITE_REG(DMA1->HIFCR, DMA_HIFCR_CTCIF4);
		isrType = DMA_TRANSFER_COMPLETE;
		if(DMAIsrCbBuff[4].cb)
		{
			DMAIsrCbBuff[4].cb(DMAIsrCbBuff[4].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA1_Stream4->CR, DMA_SxCR_TEIE) == DMA_SxCR_TEIE) && READ_BIT(DMA1->HISR, DMA_HISR_TEIF4) == (DMA_HISR_TEIF4))
	{
		WRITE_REG(DMA1->HIFCR, DMA_HIFCR_CTEIF4);
		isrType = DMA_TRANSFER_ERROR;
		if(DMAIsrCbBuff[4].cb)
		{
			DMAIsrCbBuff[4].cb(DMAIsrCbBuff[4].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA1_Stream4->CR, DMA_SxCR_DMEIE) == DMA_SxCR_DMEIE) && READ_BIT(DMA1->HISR, DMA_HISR_DMEIF4) == (DMA_HISR_DMEIF4))
	{
		WRITE_REG(DMA1->HIFCR, DMA_HIFCR_CDMEIF4);
		isrType = DMA_DIRECTOR_MODE_ERROR;
		if(DMAIsrCbBuff[4].cb)
		{
			DMAIsrCbBuff[4].cb(DMAIsrCbBuff[4].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA1_Stream4->FCR, DMA_SxFCR_FEIE) == DMA_SxFCR_FEIE) && READ_BIT(DMA1->HISR, DMA_HISR_FEIF4) == (DMA_HISR_FEIF4))
	{
		WRITE_REG(DMA1->HIFCR, DMA_HIFCR_CFEIF4);
		isrType = DMA_FIFO_ERROR;
		if(DMAIsrCbBuff[4].cb)
		{
			DMAIsrCbBuff[4].cb(DMAIsrCbBuff[4].param, 0, isrType);
		}
	}
}
void DMA1_Stream5_IRQHandler()
{
	DMATransferIsrType isrType = DMA_ISR_ERROR;
	if((READ_BIT(DMA1_Stream5->CR, DMA_SxCR_HTIE) == DMA_SxCR_HTIE) && READ_BIT(DMA1->HISR, DMA_HISR_HTIF5) == (DMA_HISR_HTIF5))
	{
		WRITE_REG(DMA1->HIFCR, DMA_HIFCR_CHTIF5);
		isrType = DMA_TRANSFER_HALF;
		if(DMAIsrCbBuff[5].cb)
		{
			DMAIsrCbBuff[5].cb(DMAIsrCbBuff[5].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA1_Stream5->CR, DMA_SxCR_TCIE) == DMA_SxCR_TCIE) && READ_BIT(DMA1->HISR, DMA_HISR_TCIF5) == (DMA_HISR_TCIF5))
	{
		WRITE_REG(DMA1->HIFCR, DMA_HIFCR_CTCIF5);
		isrType = DMA_TRANSFER_COMPLETE;
		if(DMAIsrCbBuff[5].cb)
		{
			DMAIsrCbBuff[5].cb(DMAIsrCbBuff[5].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA1_Stream5->CR, DMA_SxCR_TEIE) == DMA_SxCR_TEIE) && READ_BIT(DMA1->HISR, DMA_HISR_TEIF5) == (DMA_HISR_TEIF5))
	{
		WRITE_REG(DMA1->HIFCR, DMA_HIFCR_CTEIF5);
		isrType = DMA_TRANSFER_ERROR;
		if(DMAIsrCbBuff[5].cb)
		{
			DMAIsrCbBuff[5].cb(DMAIsrCbBuff[5].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA1_Stream5->CR, DMA_SxCR_DMEIE) == DMA_SxCR_DMEIE) && READ_BIT(DMA1->HISR, DMA_HISR_DMEIF5) == (DMA_HISR_DMEIF5))
	{
		WRITE_REG(DMA1->HIFCR, DMA_HIFCR_CDMEIF5);
		isrType = DMA_DIRECTOR_MODE_ERROR;
		if(DMAIsrCbBuff[5].cb)
		{
			DMAIsrCbBuff[5].cb(DMAIsrCbBuff[5].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA1_Stream5->FCR, DMA_SxFCR_FEIE) == DMA_SxFCR_FEIE) && READ_BIT(DMA1->HISR, DMA_HISR_FEIF5) == (DMA_HISR_FEIF5))
	{
		WRITE_REG(DMA1->HIFCR, DMA_HIFCR_CFEIF5);
		isrType = DMA_FIFO_ERROR;
		if(DMAIsrCbBuff[5].cb)
		{
			DMAIsrCbBuff[5].cb(DMAIsrCbBuff[5].param, 0, isrType);
		}
	}
}
void DMA1_Stream6_IRQHandler()
{
	DMATransferIsrType isrType = DMA_ISR_ERROR;
	if((READ_BIT(DMA1_Stream6->CR, DMA_SxCR_HTIE) == DMA_SxCR_HTIE) && READ_BIT(DMA1->HISR, DMA_HISR_HTIF6) == (DMA_HISR_HTIF6))
	{
		WRITE_REG(DMA1->HIFCR, DMA_HIFCR_CHTIF6);
		isrType = DMA_TRANSFER_HALF;
		if(DMAIsrCbBuff[6].cb)
		{
			DMAIsrCbBuff[6].cb(DMAIsrCbBuff[6].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA1_Stream6->CR, DMA_SxCR_TCIE) == DMA_SxCR_TCIE) && READ_BIT(DMA1->HISR, DMA_HISR_TCIF6) == (DMA_HISR_TCIF6))
	{
		WRITE_REG(DMA1->HIFCR, DMA_HIFCR_CTCIF6);
		isrType = DMA_TRANSFER_COMPLETE;
		if(DMAIsrCbBuff[6].cb)
		{
			DMAIsrCbBuff[6].cb(DMAIsrCbBuff[6].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA1_Stream6->CR, DMA_SxCR_TEIE) == DMA_SxCR_TEIE) && READ_BIT(DMA1->HISR, DMA_HISR_TEIF6) == (DMA_HISR_TEIF6))
	{
		WRITE_REG(DMA1->HIFCR, DMA_HIFCR_CTEIF6);
		isrType = DMA_TRANSFER_ERROR;
		if(DMAIsrCbBuff[6].cb)
		{
			DMAIsrCbBuff[6].cb(DMAIsrCbBuff[6].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA1_Stream6->CR, DMA_SxCR_DMEIE) == DMA_SxCR_DMEIE) && READ_BIT(DMA1->HISR, DMA_HISR_DMEIF6) == (DMA_HISR_DMEIF6))
	{
		WRITE_REG(DMA1->HIFCR, DMA_HIFCR_CDMEIF6);
		isrType = DMA_DIRECTOR_MODE_ERROR;
		if(DMAIsrCbBuff[6].cb)
		{
			DMAIsrCbBuff[6].cb(DMAIsrCbBuff[6].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA1_Stream6->FCR, DMA_SxFCR_FEIE) == DMA_SxFCR_FEIE) && READ_BIT(DMA1->HISR, DMA_HISR_FEIF6) == (DMA_HISR_FEIF6))
	{
		WRITE_REG(DMA1->HIFCR, DMA_HIFCR_CFEIF6);
		isrType = DMA_FIFO_ERROR;
		if(DMAIsrCbBuff[6].cb)
		{
			DMAIsrCbBuff[6].cb(DMAIsrCbBuff[6].param, 0, isrType);
		}
	}
}
void DMA1_Stream7_IRQHandler()
{
	DMATransferIsrType isrType = DMA_ISR_ERROR;
	if((READ_BIT(DMA1_Stream7->CR, DMA_SxCR_HTIE) == DMA_SxCR_HTIE) && READ_BIT(DMA1->HISR, DMA_HISR_HTIF7) == (DMA_HISR_HTIF7))
	{
		WRITE_REG(DMA1->HIFCR, DMA_HIFCR_CHTIF7);
		isrType = DMA_TRANSFER_HALF;
		if(DMAIsrCbBuff[7].cb)
		{
			DMAIsrCbBuff[7].cb(DMAIsrCbBuff[7].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA1_Stream7->CR, DMA_SxCR_TCIE) == DMA_SxCR_TCIE) && READ_BIT(DMA1->HISR, DMA_HISR_TCIF7) == (DMA_HISR_TCIF7))
	{
		WRITE_REG(DMA1->HIFCR, DMA_HIFCR_CTCIF7);
		isrType = DMA_TRANSFER_COMPLETE;
		if(DMAIsrCbBuff[7].cb)
		{
			DMAIsrCbBuff[7].cb(DMAIsrCbBuff[7].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA1_Stream7->CR, DMA_SxCR_TEIE) == DMA_SxCR_TEIE) && READ_BIT(DMA1->HISR, DMA_HISR_TEIF7) == (DMA_HISR_TEIF7))
	{
		WRITE_REG(DMA1->HIFCR, DMA_HIFCR_CTEIF7);
		isrType = DMA_TRANSFER_ERROR;
		if(DMAIsrCbBuff[7].cb)
		{
			DMAIsrCbBuff[7].cb(DMAIsrCbBuff[7].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA1_Stream7->CR, DMA_SxCR_DMEIE) == DMA_SxCR_DMEIE) && READ_BIT(DMA1->HISR, DMA_HISR_DMEIF7) == (DMA_HISR_DMEIF7))
	{
		WRITE_REG(DMA1->HIFCR, DMA_HIFCR_CDMEIF7);
		isrType = DMA_DIRECTOR_MODE_ERROR;
		if(DMAIsrCbBuff[7].cb)
		{
			DMAIsrCbBuff[7].cb(DMAIsrCbBuff[7].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA1_Stream7->FCR, DMA_SxFCR_FEIE) == DMA_SxFCR_FEIE) && READ_BIT(DMA1->HISR, DMA_HISR_FEIF7) == (DMA_HISR_FEIF7))
	{
		WRITE_REG(DMA1->HIFCR, DMA_HIFCR_CFEIF7);
		isrType = DMA_FIFO_ERROR;
		if(DMAIsrCbBuff[7].cb)
		{
			DMAIsrCbBuff[7].cb(DMAIsrCbBuff[7].param, 0, isrType);
		}
	}
}
void DMA2_Stream0_IRQHandler()
{
	DMATransferIsrType isrType = DMA_ISR_ERROR;
	if((READ_BIT(DMA2_Stream0->CR, DMA_SxCR_HTIE) == DMA_SxCR_HTIE) && (READ_BIT(DMA2->LISR, DMA_LISR_HTIF0) == (DMA_LISR_HTIF0)))
	{
		WRITE_REG(DMA2->LIFCR, DMA_LIFCR_CHTIF0);
		isrType = DMA_TRANSFER_HALF;
		if(DMAIsrCbBuff[8].cb)
		{
			DMAIsrCbBuff[8].cb(DMAIsrCbBuff[8].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA2_Stream0->CR, DMA_SxCR_TCIE) == DMA_SxCR_TCIE) && READ_BIT(DMA2->LISR, DMA_LISR_TCIF0) == (DMA_LISR_TCIF0))
	{
		WRITE_REG(DMA2->LIFCR, DMA_LIFCR_CTCIF0);
		isrType = DMA_TRANSFER_COMPLETE;
		if(DMAIsrCbBuff[8].cb)
		{
			DMAIsrCbBuff[8].cb(DMAIsrCbBuff[8].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA2_Stream0->CR, DMA_SxCR_TEIE) == DMA_SxCR_TEIE) && READ_BIT(DMA2->LISR, DMA_LISR_TEIF0) == (DMA_LISR_TEIF0))
	{
		WRITE_REG(DMA2->LIFCR, DMA_LIFCR_CTEIF0);
		isrType = DMA_TRANSFER_ERROR;
		if(DMAIsrCbBuff[8].cb)
		{
			DMAIsrCbBuff[8].cb(DMAIsrCbBuff[8].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA2_Stream0->CR, DMA_SxCR_DMEIE) == DMA_SxCR_DMEIE) && READ_BIT(DMA2->LISR, DMA_LISR_DMEIF0) == (DMA_LISR_DMEIF0))
	{
		WRITE_REG(DMA2->LIFCR, DMA_LIFCR_CDMEIF0);
		isrType = DMA_DIRECTOR_MODE_ERROR;
		if(DMAIsrCbBuff[8].cb)
		{
			DMAIsrCbBuff[8].cb(DMAIsrCbBuff[8].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA2_Stream0->FCR, DMA_SxFCR_FEIE) == DMA_SxFCR_FEIE) && READ_BIT(DMA2->LISR, DMA_LISR_FEIF0) == (DMA_LISR_FEIF0))
	{
		WRITE_REG(DMA2->LIFCR, DMA_LIFCR_CFEIF0);
		isrType = DMA_FIFO_ERROR;
		if(DMAIsrCbBuff[8].cb)
		{
			DMAIsrCbBuff[8].cb(DMAIsrCbBuff[8].param, 0, isrType);
		}
	}
}
void DMA2_Stream1_IRQHandler()
{
	DMATransferIsrType isrType = DMA_ISR_ERROR;
	if((READ_BIT(DMA2_Stream1->CR, DMA_SxCR_HTIE) == DMA_SxCR_HTIE) && (READ_BIT(DMA2->LISR, DMA_LISR_HTIF1) == (DMA_LISR_HTIF1)))
	{
		WRITE_REG(DMA2->LIFCR, DMA_LIFCR_CHTIF1);
		isrType = DMA_TRANSFER_HALF;
		if(DMAIsrCbBuff[9].cb)
		{
			DMAIsrCbBuff[9].cb(DMAIsrCbBuff[9].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA2_Stream1->CR, DMA_SxCR_TCIE) == DMA_SxCR_TCIE) && READ_BIT(DMA2->LISR, DMA_LISR_TCIF1) == (DMA_LISR_TCIF1))
	{
		WRITE_REG(DMA2->LIFCR, DMA_LIFCR_CTCIF1);
		isrType = DMA_TRANSFER_COMPLETE;
		if(DMAIsrCbBuff[9].cb)
		{
			DMAIsrCbBuff[9].cb(DMAIsrCbBuff[9].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA2_Stream1->CR, DMA_SxCR_TEIE) == DMA_SxCR_TEIE) && READ_BIT(DMA2->LISR, DMA_LISR_TEIF1) == (DMA_LISR_TEIF1))
	{
		WRITE_REG(DMA2->LIFCR, DMA_LIFCR_CTEIF1);
		isrType = DMA_TRANSFER_ERROR;
		if(DMAIsrCbBuff[9].cb)
		{
			DMAIsrCbBuff[9].cb(DMAIsrCbBuff[9].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA2_Stream1->CR, DMA_SxCR_DMEIE) == DMA_SxCR_DMEIE) && READ_BIT(DMA2->LISR, DMA_LISR_DMEIF1) == (DMA_LISR_DMEIF1))
	{
		WRITE_REG(DMA2->LIFCR, DMA_LIFCR_CDMEIF1);
		isrType = DMA_DIRECTOR_MODE_ERROR;
		if(DMAIsrCbBuff[9].cb)
		{
			DMAIsrCbBuff[9].cb(DMAIsrCbBuff[9].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA2_Stream1->FCR, DMA_SxFCR_FEIE) == DMA_SxFCR_FEIE) && READ_BIT(DMA2->LISR, DMA_LISR_FEIF1) == (DMA_LISR_FEIF1))
	{
		WRITE_REG(DMA2->LIFCR, DMA_LIFCR_CFEIF1);
		isrType = DMA_FIFO_ERROR;
		if(DMAIsrCbBuff[9].cb)
		{
			DMAIsrCbBuff[9].cb(DMAIsrCbBuff[9].param, 0, isrType);
		}
	}
}
void DMA2_Stream2_IRQHandler()
{
	DMATransferIsrType isrType = DMA_ISR_ERROR;
	if((READ_BIT(DMA2_Stream2->CR, DMA_SxCR_HTIE) == DMA_SxCR_HTIE) && (READ_BIT(DMA2->LISR, DMA_LISR_HTIF2) == (DMA_LISR_HTIF2)))
	{
		WRITE_REG(DMA2->LIFCR, DMA_LIFCR_CHTIF2);
		isrType = DMA_TRANSFER_HALF;
		if(DMAIsrCbBuff[10].cb)
		{
			DMAIsrCbBuff[10].cb(DMAIsrCbBuff[10].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA2_Stream2->CR, DMA_SxCR_TCIE) == DMA_SxCR_TCIE) && READ_BIT(DMA2->LISR, DMA_LISR_TCIF2) == (DMA_LISR_TCIF2))
	{
		WRITE_REG(DMA2->LIFCR, DMA_LIFCR_CTCIF2);
		isrType = DMA_TRANSFER_COMPLETE;
		if(DMAIsrCbBuff[10].cb)
		{
			DMAIsrCbBuff[10].cb(DMAIsrCbBuff[10].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA2_Stream2->CR, DMA_SxCR_TEIE) == DMA_SxCR_TEIE) && READ_BIT(DMA2->LISR, DMA_LISR_TEIF2) == (DMA_LISR_TEIF2))
	{
		WRITE_REG(DMA2->LIFCR, DMA_LIFCR_CTEIF2);
		isrType = DMA_TRANSFER_ERROR;
		if(DMAIsrCbBuff[10].cb)
		{
			DMAIsrCbBuff[10].cb(DMAIsrCbBuff[10].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA2_Stream2->CR, DMA_SxCR_DMEIE) == DMA_SxCR_DMEIE) && READ_BIT(DMA2->LISR, DMA_LISR_DMEIF2) == (DMA_LISR_DMEIF2))
	{
		WRITE_REG(DMA2->LIFCR, DMA_LIFCR_CDMEIF2);
		isrType = DMA_DIRECTOR_MODE_ERROR;
		if(DMAIsrCbBuff[10].cb)
		{
			DMAIsrCbBuff[10].cb(DMAIsrCbBuff[10].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA2_Stream2->FCR, DMA_SxFCR_FEIE) == DMA_SxFCR_FEIE) && READ_BIT(DMA2->LISR, DMA_LISR_FEIF2) == (DMA_LISR_FEIF2))
	{
		WRITE_REG(DMA2->LIFCR, DMA_LIFCR_CFEIF2);
		isrType = DMA_FIFO_ERROR;
		if(DMAIsrCbBuff[10].cb)
		{
			DMAIsrCbBuff[10].cb(DMAIsrCbBuff[10].param, 0, isrType);
		}
	}
}
void DMA2_Stream3_IRQHandler()
{
	DMATransferIsrType isrType = DMA_ISR_ERROR;
	if((READ_BIT(DMA2_Stream3->CR, DMA_SxCR_HTIE) == DMA_SxCR_HTIE) && (READ_BIT(DMA2->LISR, DMA_LISR_HTIF3) == (DMA_LISR_HTIF3)))
	{
		WRITE_REG(DMA2->LIFCR, DMA_LIFCR_CHTIF3);
		isrType = DMA_TRANSFER_HALF;
		if(DMAIsrCbBuff[11].cb)
		{
			DMAIsrCbBuff[11].cb(DMAIsrCbBuff[11].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA2_Stream3->CR, DMA_SxCR_TCIE) == DMA_SxCR_TCIE) && READ_BIT(DMA2->LISR, DMA_LISR_TCIF3) == (DMA_LISR_TCIF3))
	{
		WRITE_REG(DMA2->LIFCR, DMA_LIFCR_CTCIF3);
		isrType = DMA_TRANSFER_COMPLETE;
		if(DMAIsrCbBuff[11].cb)
		{
			DMAIsrCbBuff[11].cb(DMAIsrCbBuff[11].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA2_Stream3->CR, DMA_SxCR_TEIE) == DMA_SxCR_TEIE) && READ_BIT(DMA2->LISR, DMA_LISR_TEIF3) == (DMA_LISR_TEIF3))
	{
		WRITE_REG(DMA2->LIFCR, DMA_LIFCR_CTEIF3);
		isrType = DMA_TRANSFER_ERROR;
		if(DMAIsrCbBuff[11].cb)
		{
			DMAIsrCbBuff[11].cb(DMAIsrCbBuff[11].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA2_Stream3->CR, DMA_SxCR_DMEIE) == DMA_SxCR_DMEIE) && READ_BIT(DMA2->LISR, DMA_LISR_DMEIF3) == (DMA_LISR_DMEIF3))
	{
		WRITE_REG(DMA2->LIFCR, DMA_LIFCR_CDMEIF3);
		isrType = DMA_DIRECTOR_MODE_ERROR;
		if(DMAIsrCbBuff[11].cb)
		{
			DMAIsrCbBuff[11].cb(DMAIsrCbBuff[11].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA2_Stream3->FCR, DMA_SxFCR_FEIE) == DMA_SxFCR_FEIE) && READ_BIT(DMA2->LISR, DMA_LISR_FEIF3) == (DMA_LISR_FEIF3))
	{
		WRITE_REG(DMA2->LIFCR, DMA_LIFCR_CFEIF3);
		isrType = DMA_FIFO_ERROR;
		if(DMAIsrCbBuff[11].cb)
		{
			DMAIsrCbBuff[11].cb(DMAIsrCbBuff[11].param, 0, isrType);
		}
	}
}
void DMA2_Stream4_IRQHandler()
{
	DMATransferIsrType isrType = DMA_ISR_ERROR;
	if((READ_BIT(DMA2_Stream4->CR, DMA_SxCR_HTIE) == DMA_SxCR_HTIE) && READ_BIT(DMA2->HISR, DMA_HISR_HTIF4) == (DMA_HISR_HTIF4))
	{
		WRITE_REG(DMA2->HIFCR, DMA_HIFCR_CHTIF4);
		isrType = DMA_TRANSFER_HALF;
		if(DMAIsrCbBuff[12].cb)
		{
			DMAIsrCbBuff[12].cb(DMAIsrCbBuff[12].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA2_Stream4->CR, DMA_SxCR_TCIE) == DMA_SxCR_TCIE) && READ_BIT(DMA2->HISR, DMA_HISR_TCIF4) == (DMA_HISR_TCIF4))
	{
		WRITE_REG(DMA2->HIFCR, DMA_HIFCR_CTCIF4);
		isrType = DMA_TRANSFER_COMPLETE;
		if(DMAIsrCbBuff[12].cb)
		{
			DMAIsrCbBuff[12].cb(DMAIsrCbBuff[12].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA2_Stream4->CR, DMA_SxCR_TEIE) == DMA_SxCR_TEIE) && READ_BIT(DMA2->HISR, DMA_HISR_TEIF4) == (DMA_HISR_TEIF4))
	{
		WRITE_REG(DMA2->HIFCR, DMA_HIFCR_CTEIF4);
		isrType = DMA_TRANSFER_ERROR;
		if(DMAIsrCbBuff[12].cb)
		{
			DMAIsrCbBuff[12].cb(DMAIsrCbBuff[12].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA2_Stream4->CR, DMA_SxCR_DMEIE) == DMA_SxCR_DMEIE) && READ_BIT(DMA2->HISR, DMA_HISR_DMEIF4) == (DMA_HISR_DMEIF4))
	{
		WRITE_REG(DMA2->HIFCR, DMA_HIFCR_CDMEIF4);
		isrType = DMA_DIRECTOR_MODE_ERROR;
		if(DMAIsrCbBuff[12].cb)
		{
			DMAIsrCbBuff[12].cb(DMAIsrCbBuff[12].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA2_Stream4->FCR, DMA_SxFCR_FEIE) == DMA_SxFCR_FEIE) && READ_BIT(DMA2->HISR, DMA_HISR_FEIF4) == (DMA_HISR_FEIF4))
	{
		WRITE_REG(DMA2->HIFCR, DMA_HIFCR_CFEIF4);
		isrType = DMA_FIFO_ERROR;
		if(DMAIsrCbBuff[12].cb)
		{
			DMAIsrCbBuff[12].cb(DMAIsrCbBuff[12].param, 0, isrType);
		}
	}
}
void DMA2_Stream5_IRQHandler()
{
	DMATransferIsrType isrType = DMA_ISR_ERROR;
	if((READ_BIT(DMA2_Stream5->CR, DMA_SxCR_HTIE) == DMA_SxCR_HTIE) && READ_BIT(DMA2->HISR, DMA_HISR_HTIF5) == (DMA_HISR_HTIF5))
	{
		WRITE_REG(DMA2->HIFCR, DMA_HIFCR_CHTIF5);
		isrType = DMA_TRANSFER_HALF;
		if(DMAIsrCbBuff[13].cb)
		{
			DMAIsrCbBuff[13].cb(DMAIsrCbBuff[13].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA2_Stream5->CR, DMA_SxCR_TCIE) == DMA_SxCR_TCIE) && READ_BIT(DMA2->HISR, DMA_HISR_TCIF5) == (DMA_HISR_TCIF5))
	{
		WRITE_REG(DMA2->HIFCR, DMA_HIFCR_CTCIF5);
		isrType = DMA_TRANSFER_COMPLETE;
		if(DMAIsrCbBuff[13].cb)
		{
			DMAIsrCbBuff[13].cb(DMAIsrCbBuff[13].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA2_Stream5->CR, DMA_SxCR_TEIE) == DMA_SxCR_TEIE) && READ_BIT(DMA2->HISR, DMA_HISR_TEIF5) == (DMA_HISR_TEIF5))
	{
		WRITE_REG(DMA2->HIFCR, DMA_HIFCR_CTEIF5);
		isrType = DMA_TRANSFER_ERROR;
		if(DMAIsrCbBuff[13].cb)
		{
			DMAIsrCbBuff[13].cb(DMAIsrCbBuff[13].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA2_Stream5->CR, DMA_SxCR_DMEIE) == DMA_SxCR_DMEIE) && READ_BIT(DMA2->HISR, DMA_HISR_DMEIF5) == (DMA_HISR_DMEIF5))
	{
		WRITE_REG(DMA2->HIFCR, DMA_HIFCR_CDMEIF5);
		isrType = DMA_DIRECTOR_MODE_ERROR;
		if(DMAIsrCbBuff[13].cb)
		{
			DMAIsrCbBuff[13].cb(DMAIsrCbBuff[13].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA2_Stream5->FCR, DMA_SxFCR_FEIE) == DMA_SxFCR_FEIE) && READ_BIT(DMA2->HISR, DMA_HISR_FEIF5) == (DMA_HISR_FEIF5))
	{
		WRITE_REG(DMA2->HIFCR, DMA_HIFCR_CFEIF5);
		isrType = DMA_FIFO_ERROR;
		if(DMAIsrCbBuff[13].cb)
		{
			DMAIsrCbBuff[13].cb(DMAIsrCbBuff[13].param, 0, isrType);
		}
	}
}
void DMA2_Stream6_IRQHandler()
{
	DMATransferIsrType isrType = DMA_ISR_ERROR;
	if((READ_BIT(DMA2_Stream6->CR, DMA_SxCR_HTIE) == DMA_SxCR_HTIE) && READ_BIT(DMA2->HISR, DMA_HISR_HTIF6) == (DMA_HISR_HTIF6))
	{
		WRITE_REG(DMA2->HIFCR, DMA_HIFCR_CHTIF6);
		isrType = DMA_TRANSFER_HALF;
		if(DMAIsrCbBuff[14].cb)
		{
			DMAIsrCbBuff[14].cb(DMAIsrCbBuff[14].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA2_Stream6->CR, DMA_SxCR_TCIE) == DMA_SxCR_TCIE) && READ_BIT(DMA2->HISR, DMA_HISR_TCIF6) == (DMA_HISR_TCIF6))
	{
		WRITE_REG(DMA2->HIFCR, DMA_HIFCR_CTCIF6);
		isrType = DMA_TRANSFER_COMPLETE;
		if(DMAIsrCbBuff[14].cb)
		{
			DMAIsrCbBuff[14].cb(DMAIsrCbBuff[14].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA2_Stream6->CR, DMA_SxCR_TEIE) == DMA_SxCR_TEIE) && READ_BIT(DMA2->HISR, DMA_HISR_TEIF6) == (DMA_HISR_TEIF6))
	{
		WRITE_REG(DMA2->HIFCR, DMA_HIFCR_CTEIF6);
		isrType = DMA_TRANSFER_ERROR;
		if(DMAIsrCbBuff[14].cb)
		{
			DMAIsrCbBuff[14].cb(DMAIsrCbBuff[14].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA2_Stream6->CR, DMA_SxCR_DMEIE) == DMA_SxCR_DMEIE) && READ_BIT(DMA2->HISR, DMA_HISR_DMEIF6) == (DMA_HISR_DMEIF6))
	{
		WRITE_REG(DMA2->HIFCR, DMA_HIFCR_CDMEIF6);
		isrType = DMA_DIRECTOR_MODE_ERROR;
		if(DMAIsrCbBuff[14].cb)
		{
			DMAIsrCbBuff[14].cb(DMAIsrCbBuff[14].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA2_Stream6->FCR, DMA_SxFCR_FEIE) == DMA_SxFCR_FEIE) && READ_BIT(DMA2->HISR, DMA_HISR_FEIF6) == (DMA_HISR_FEIF6))
	{
		WRITE_REG(DMA2->HIFCR, DMA_HIFCR_CFEIF6);
		isrType = DMA_FIFO_ERROR;
		if(DMAIsrCbBuff[14].cb)
		{
			DMAIsrCbBuff[14].cb(DMAIsrCbBuff[14].param, 0, isrType);
		}
	}
}
void DMA2_Stream7_IRQHandler()
{
	DMATransferIsrType isrType = DMA_ISR_ERROR;
	if((READ_BIT(DMA2_Stream7->CR, DMA_SxCR_HTIE) == DMA_SxCR_HTIE) && READ_BIT(DMA2->HISR, DMA_HISR_HTIF7) == (DMA_HISR_HTIF7))
	{
		WRITE_REG(DMA2->HIFCR, DMA_HIFCR_CHTIF7);
		isrType = DMA_TRANSFER_HALF;
		if(DMAIsrCbBuff[15].cb)
		{
			DMAIsrCbBuff[15].cb(DMAIsrCbBuff[15].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA2_Stream7->CR, DMA_SxCR_TCIE) == DMA_SxCR_TCIE) && READ_BIT(DMA2->HISR, DMA_HISR_TCIF7) == (DMA_HISR_TCIF7))
	{
		WRITE_REG(DMA2->HIFCR, DMA_HIFCR_CTCIF7);
		isrType = DMA_TRANSFER_COMPLETE;
		if(DMAIsrCbBuff[15].cb)
		{
			DMAIsrCbBuff[15].cb(DMAIsrCbBuff[15].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA2_Stream7->CR, DMA_SxCR_TEIE) == DMA_SxCR_TEIE) && READ_BIT(DMA2->HISR, DMA_HISR_TEIF7) == (DMA_HISR_TEIF7))
	{
		WRITE_REG(DMA2->HIFCR, DMA_HIFCR_CTEIF7);
		isrType = DMA_TRANSFER_ERROR;
		if(DMAIsrCbBuff[15].cb)
		{
			DMAIsrCbBuff[15].cb(DMAIsrCbBuff[15].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA2_Stream7->CR, DMA_SxCR_DMEIE) == DMA_SxCR_DMEIE) && READ_BIT(DMA2->HISR, DMA_HISR_DMEIF7) == (DMA_HISR_DMEIF7))
	{
		WRITE_REG(DMA2->HIFCR, DMA_HIFCR_CDMEIF7);
		isrType = DMA_DIRECTOR_MODE_ERROR;
		if(DMAIsrCbBuff[15].cb)
		{
			DMAIsrCbBuff[15].cb(DMAIsrCbBuff[15].param, 0, isrType);
		}
	}
	if((READ_BIT(DMA2_Stream7->FCR, DMA_SxFCR_FEIE) == DMA_SxFCR_FEIE) && READ_BIT(DMA2->HISR, DMA_HISR_FEIF7) == (DMA_HISR_FEIF7))
	{
		WRITE_REG(DMA2->HIFCR, DMA_HIFCR_CFEIF7);
		isrType = DMA_FIFO_ERROR;
		if(DMAIsrCbBuff[15].cb)
		{
			DMAIsrCbBuff[15].cb(DMAIsrCbBuff[15].param, 0, isrType);
		}
	}
}
void BDMA_Channel0_IRQHandler()
{
	BDMATransferIsrType isrType = BDMA_ISR_GLOBAL_ERROR;
	if((READ_BIT(BDMA->ISR, BDMA_ISR_GIF0) == (BDMA_ISR_GIF0)))
	{
		WRITE_REG(BDMA->IFCR, BDMA_IFCR_CGIF0);
		isrType = BDMA_ISR_GLOBAL_ERROR;
		if(BDMAIsrCbBuff[0].cb)
		{
			BDMAIsrCbBuff[0].cb(BDMAIsrCbBuff[0].param, 0, isrType);
		}
	}
	if((READ_BIT(BDMA_Channel0->CCR, BDMA_CCR_TCIE) == (BDMA_CCR_TCIE)) && (READ_BIT(BDMA->ISR, BDMA_ISR_TCIF0) == (BDMA_ISR_TCIF0)))
	{
		WRITE_REG(BDMA->IFCR, BDMA_IFCR_CTCIF0);
		isrType = BDMA_TRANSFER_COMPLETE;
		if(BDMAIsrCbBuff[0].cb)
		{
			BDMAIsrCbBuff[0].cb(BDMAIsrCbBuff[0].param, 0, isrType);
		}
	}
	if((READ_BIT(BDMA_Channel0->CCR, BDMA_CCR_HTIE) == (BDMA_CCR_HTIE)) && (READ_BIT(BDMA->ISR, BDMA_ISR_HTIF0) == (BDMA_ISR_HTIF0)))
	{
		WRITE_REG(BDMA->IFCR, BDMA_IFCR_CHTIF0);
		isrType = BDMA_TRANSFER_HALF;
		if(BDMAIsrCbBuff[0].cb)
		{
			BDMAIsrCbBuff[0].cb(BDMAIsrCbBuff[0].param, 0, isrType);
		}
	}
	if((READ_BIT(BDMA_Channel0->CCR, BDMA_CCR_TEIE) == (BDMA_CCR_TEIE)) && (READ_BIT(BDMA->ISR, BDMA_ISR_TEIF0) == (BDMA_ISR_TEIF0)))
	{
		WRITE_REG(BDMA->IFCR, BDMA_IFCR_CTEIF0);
		isrType = BDMA_TRANSFER_ERROR;
		if(BDMAIsrCbBuff[0].cb)
		{
			BDMAIsrCbBuff[0].cb(BDMAIsrCbBuff[0].param, 0, isrType);
		}
	}
}
void BDMA_Channel1_IRQHandler()
{
	BDMATransferIsrType isrType = BDMA_ISR_GLOBAL_ERROR;
	if((READ_BIT(BDMA->ISR, BDMA_ISR_GIF1) == (BDMA_ISR_GIF1)))
	{
		WRITE_REG(BDMA->IFCR, BDMA_IFCR_CGIF1);
		isrType = BDMA_ISR_GLOBAL_ERROR;
		if(BDMAIsrCbBuff[1].cb)
		{
			BDMAIsrCbBuff[1].cb(BDMAIsrCbBuff[1].param, 0, isrType);
		}
	}
	if((READ_BIT(BDMA_Channel1->CCR, BDMA_CCR_TCIE) == (BDMA_CCR_TCIE)) && (READ_BIT(BDMA->ISR, BDMA_ISR_TCIF1) == (BDMA_ISR_TCIF1)))
	{
		WRITE_REG(BDMA->IFCR, BDMA_IFCR_CTCIF1);
		isrType = BDMA_TRANSFER_COMPLETE;
		if(BDMAIsrCbBuff[1].cb)
		{
			BDMAIsrCbBuff[1].cb(BDMAIsrCbBuff[1].param, 0, isrType);
		}
	}
	if((READ_BIT(BDMA_Channel1->CCR, BDMA_CCR_HTIE) == (BDMA_CCR_HTIE)) && (READ_BIT(BDMA->ISR, BDMA_ISR_HTIF1) == (BDMA_ISR_HTIF1)))
	{
		WRITE_REG(BDMA->IFCR, BDMA_IFCR_CHTIF1);
		isrType = BDMA_TRANSFER_HALF;
		if(BDMAIsrCbBuff[1].cb)
		{
			BDMAIsrCbBuff[1].cb(BDMAIsrCbBuff[1].param, 0, isrType);
		}
	}
	if((READ_BIT(BDMA_Channel1->CCR, BDMA_CCR_TEIE) == (BDMA_CCR_TEIE)) && (READ_BIT(BDMA->ISR, BDMA_ISR_TEIF1) == (BDMA_ISR_TEIF1)))
	{
		WRITE_REG(BDMA->IFCR, BDMA_IFCR_CTEIF1);
		isrType = BDMA_TRANSFER_ERROR;
		if(BDMAIsrCbBuff[1].cb)
		{
			BDMAIsrCbBuff[1].cb(BDMAIsrCbBuff[1].param, 0, isrType);
		}
	}
}
void BDMA_Channel2_IRQHandler()
{
	BDMATransferIsrType isrType = BDMA_ISR_GLOBAL_ERROR;
	if((READ_BIT(BDMA->ISR, BDMA_ISR_GIF2) == (BDMA_ISR_GIF2)))
	{
		WRITE_REG(BDMA->IFCR, BDMA_IFCR_CGIF2);
		isrType = BDMA_ISR_GLOBAL_ERROR;
		if(BDMAIsrCbBuff[2].cb)
		{
			BDMAIsrCbBuff[2].cb(BDMAIsrCbBuff[2].param, 0, isrType);
		}
	}
	if((READ_BIT(BDMA_Channel2->CCR, BDMA_CCR_TCIE) == (BDMA_CCR_TCIE)) && (READ_BIT(BDMA->ISR, BDMA_ISR_TCIF2) == (BDMA_ISR_TCIF2)))
	{
		WRITE_REG(BDMA->IFCR, BDMA_IFCR_CTCIF2);
		isrType = BDMA_TRANSFER_COMPLETE;
		if(BDMAIsrCbBuff[2].cb)
		{
			BDMAIsrCbBuff[2].cb(BDMAIsrCbBuff[2].param, 0, isrType);
		}
	}
	if((READ_BIT(BDMA_Channel2->CCR, BDMA_CCR_HTIE) == (BDMA_CCR_HTIE)) && (READ_BIT(BDMA->ISR, BDMA_ISR_HTIF2) == (BDMA_ISR_HTIF2)))
	{
		WRITE_REG(BDMA->IFCR, BDMA_IFCR_CHTIF2);
		isrType = BDMA_TRANSFER_HALF;
		if(BDMAIsrCbBuff[2].cb)
		{
			BDMAIsrCbBuff[2].cb(BDMAIsrCbBuff[2].param, 0, isrType);
		}
	}
	if((READ_BIT(BDMA_Channel2->CCR, BDMA_CCR_TEIE) == (BDMA_CCR_TEIE)) && (READ_BIT(BDMA->ISR, BDMA_ISR_TEIF2) == (BDMA_ISR_TEIF2)))
	{
		WRITE_REG(BDMA->IFCR, BDMA_IFCR_CTEIF2);
		isrType = BDMA_TRANSFER_ERROR;
		if(BDMAIsrCbBuff[2].cb)
		{
			BDMAIsrCbBuff[2].cb(BDMAIsrCbBuff[2].param, 0, isrType);
		}
	}
}
void BDMA_Channel3_IRQHandler()
{
	BDMATransferIsrType isrType = BDMA_ISR_GLOBAL_ERROR;
	if((READ_BIT(BDMA->ISR, BDMA_ISR_GIF3) == (BDMA_ISR_GIF3)))
	{
		WRITE_REG(BDMA->IFCR, BDMA_IFCR_CGIF3);
		isrType = BDMA_ISR_GLOBAL_ERROR;
		if(BDMAIsrCbBuff[3].cb)
		{
			BDMAIsrCbBuff[3].cb(BDMAIsrCbBuff[3].param, 0, isrType);
		}
	}
	if((READ_BIT(BDMA_Channel3->CCR, BDMA_CCR_TCIE) == (BDMA_CCR_TCIE)) && (READ_BIT(BDMA->ISR, BDMA_ISR_TCIF3) == (BDMA_ISR_TCIF3)))
	{
		WRITE_REG(BDMA->IFCR, BDMA_IFCR_CTCIF3);
		isrType = BDMA_TRANSFER_COMPLETE;
		if(BDMAIsrCbBuff[3].cb)
		{
			BDMAIsrCbBuff[3].cb(BDMAIsrCbBuff[3].param, 0, isrType);
		}
	}
	if((READ_BIT(BDMA_Channel3->CCR, BDMA_CCR_HTIE) == (BDMA_CCR_HTIE)) && (READ_BIT(BDMA->ISR, BDMA_ISR_HTIF3) == (BDMA_ISR_HTIF3)))
	{
		WRITE_REG(BDMA->IFCR, BDMA_IFCR_CHTIF3);
		isrType = BDMA_TRANSFER_HALF;
		if(BDMAIsrCbBuff[3].cb)
		{
			BDMAIsrCbBuff[3].cb(BDMAIsrCbBuff[3].param, 0, isrType);
		}
	}
	if((READ_BIT(BDMA_Channel3->CCR, BDMA_CCR_TEIE) == (BDMA_CCR_TEIE)) && (READ_BIT(BDMA->ISR, BDMA_ISR_TEIF3) == (BDMA_ISR_TEIF3)))
	{
		WRITE_REG(BDMA->IFCR, BDMA_IFCR_CTEIF3);
		isrType = BDMA_TRANSFER_ERROR;
		if(BDMAIsrCbBuff[3].cb)
		{
			BDMAIsrCbBuff[3].cb(BDMAIsrCbBuff[3].param, 0, isrType);
		}
	}
}
void BDMA_Channel4_IRQHandler()
{
	BDMATransferIsrType isrType = BDMA_ISR_GLOBAL_ERROR;
	if((READ_BIT(BDMA->ISR, BDMA_ISR_GIF4) == (BDMA_ISR_GIF4)))
	{
		WRITE_REG(BDMA->IFCR, BDMA_IFCR_CGIF4);
		isrType = BDMA_ISR_GLOBAL_ERROR;
		if(BDMAIsrCbBuff[4].cb)
		{
			BDMAIsrCbBuff[4].cb(BDMAIsrCbBuff[4].param, 0, isrType);
		}
	}
	if((READ_BIT(BDMA_Channel4->CCR, BDMA_CCR_TCIE) == (BDMA_CCR_TCIE)) && (READ_BIT(BDMA->ISR, BDMA_ISR_TCIF4) == (BDMA_ISR_TCIF4)))
	{
		WRITE_REG(BDMA->IFCR, BDMA_IFCR_CTCIF4);
		isrType = BDMA_TRANSFER_COMPLETE;
		if(BDMAIsrCbBuff[4].cb)
		{
			BDMAIsrCbBuff[4].cb(BDMAIsrCbBuff[4].param, 0, isrType);
		}
	}
	if((READ_BIT(BDMA_Channel4->CCR, BDMA_CCR_HTIE) == (BDMA_CCR_HTIE)) && (READ_BIT(BDMA->ISR, BDMA_ISR_HTIF4) == (BDMA_ISR_HTIF4)))
	{
		WRITE_REG(BDMA->IFCR, BDMA_IFCR_CHTIF4);
		isrType = BDMA_TRANSFER_HALF;
		if(BDMAIsrCbBuff[4].cb)
		{
			BDMAIsrCbBuff[4].cb(BDMAIsrCbBuff[4].param, 0, isrType);
		}
	}
	if((READ_BIT(BDMA_Channel4->CCR, BDMA_CCR_TEIE) == (BDMA_CCR_TEIE)) && (READ_BIT(BDMA->ISR, BDMA_ISR_TEIF4) == (BDMA_ISR_TEIF4)))
	{
		WRITE_REG(BDMA->IFCR, BDMA_IFCR_CTEIF4);
		isrType = BDMA_TRANSFER_ERROR;
		if(BDMAIsrCbBuff[4].cb)
		{
			BDMAIsrCbBuff[4].cb(BDMAIsrCbBuff[4].param, 0, isrType);
		}
	}
}
void BDMA_Channel5_IRQHandler()
{
	BDMATransferIsrType isrType = BDMA_ISR_GLOBAL_ERROR;
	if((READ_BIT(BDMA->ISR, BDMA_ISR_GIF5) == (BDMA_ISR_GIF5)))
	{
		WRITE_REG(BDMA->IFCR, BDMA_IFCR_CGIF5);
		isrType = BDMA_ISR_GLOBAL_ERROR;
		if(BDMAIsrCbBuff[5].cb)
		{
			BDMAIsrCbBuff[5].cb(BDMAIsrCbBuff[5].param, 0, isrType);
		}
	}
	if((READ_BIT(BDMA_Channel5->CCR, BDMA_CCR_TCIE) == (BDMA_CCR_TCIE)) && (READ_BIT(BDMA->ISR, BDMA_ISR_TCIF5) == (BDMA_ISR_TCIF5)))
	{
		WRITE_REG(BDMA->IFCR, BDMA_IFCR_CTCIF5);
		isrType = BDMA_TRANSFER_COMPLETE;
		if(BDMAIsrCbBuff[5].cb)
		{
			BDMAIsrCbBuff[5].cb(BDMAIsrCbBuff[5].param, 0, isrType);
		}
	}
	if((READ_BIT(BDMA_Channel5->CCR, BDMA_CCR_HTIE) == (BDMA_CCR_HTIE)) && (READ_BIT(BDMA->ISR, BDMA_ISR_HTIF5) == (BDMA_ISR_HTIF5)))
	{
		WRITE_REG(BDMA->IFCR, BDMA_IFCR_CHTIF5);
		isrType = BDMA_TRANSFER_HALF;
		if(BDMAIsrCbBuff[5].cb)
		{
			BDMAIsrCbBuff[5].cb(BDMAIsrCbBuff[5].param, 0, isrType);
		}
	}
	if((READ_BIT(BDMA_Channel5->CCR, BDMA_CCR_TEIE) == (BDMA_CCR_TEIE)) && (READ_BIT(BDMA->ISR, BDMA_ISR_TEIF5) == (BDMA_ISR_TEIF5)))
	{
		WRITE_REG(BDMA->IFCR, BDMA_IFCR_CTEIF5);
		isrType = BDMA_TRANSFER_ERROR;
		if(BDMAIsrCbBuff[5].cb)
		{
			BDMAIsrCbBuff[5].cb(BDMAIsrCbBuff[5].param, 0, isrType);
		}
	}
}
void BDMA_Channel6_IRQHandler()
{
	BDMATransferIsrType isrType = BDMA_ISR_GLOBAL_ERROR;
	if((READ_BIT(BDMA->ISR, BDMA_ISR_GIF6) == (BDMA_ISR_GIF6)))
	{
		WRITE_REG(BDMA->IFCR, BDMA_IFCR_CGIF6);
		isrType = BDMA_ISR_GLOBAL_ERROR;
		if(BDMAIsrCbBuff[6].cb)
		{
			BDMAIsrCbBuff[6].cb(BDMAIsrCbBuff[6].param, 0, isrType);
		}
	}
	if((READ_BIT(BDMA_Channel6->CCR, BDMA_CCR_TCIE) == (BDMA_CCR_TCIE)) && (READ_BIT(BDMA->ISR, BDMA_ISR_TCIF6) == (BDMA_ISR_TCIF6)))
	{
		WRITE_REG(BDMA->IFCR, BDMA_IFCR_CTCIF6);
		isrType = BDMA_TRANSFER_COMPLETE;
		if(BDMAIsrCbBuff[6].cb)
		{
			BDMAIsrCbBuff[6].cb(BDMAIsrCbBuff[6].param, 0, isrType);
		}
	}
	if((READ_BIT(BDMA_Channel6->CCR, BDMA_CCR_HTIE) == (BDMA_CCR_HTIE)) && (READ_BIT(BDMA->ISR, BDMA_ISR_HTIF6) == (BDMA_ISR_HTIF6)))
	{
		WRITE_REG(BDMA->IFCR, BDMA_IFCR_CHTIF6);
		isrType = BDMA_TRANSFER_HALF;
		if(BDMAIsrCbBuff[6].cb)
		{
			BDMAIsrCbBuff[6].cb(BDMAIsrCbBuff[6].param, 0, isrType);
		}
	}
	if((READ_BIT(BDMA_Channel6->CCR, BDMA_CCR_TEIE) == (BDMA_CCR_TEIE)) && (READ_BIT(BDMA->ISR, BDMA_ISR_TEIF6) == (BDMA_ISR_TEIF6)))
	{
		WRITE_REG(BDMA->IFCR, BDMA_IFCR_CTEIF6);
		isrType = BDMA_TRANSFER_ERROR;
		if(BDMAIsrCbBuff[6].cb)
		{
			BDMAIsrCbBuff[6].cb(BDMAIsrCbBuff[6].param, 0, isrType);
		}
	}
}
void BDMA_Channel7_IRQHandler()
{
	BDMATransferIsrType isrType = BDMA_ISR_GLOBAL_ERROR;
	if((READ_BIT(BDMA->ISR, BDMA_ISR_GIF7) == (BDMA_ISR_GIF7)))
	{
		WRITE_REG(BDMA->IFCR, BDMA_IFCR_CGIF7_Pos);
		isrType = BDMA_ISR_GLOBAL_ERROR;
		if(BDMAIsrCbBuff[7].cb)
		{
			BDMAIsrCbBuff[7].cb(BDMAIsrCbBuff[7].param, 0, isrType);
		}
	}
	if((READ_BIT(BDMA_Channel7->CCR, BDMA_CCR_TCIE) == (BDMA_CCR_TCIE)) && (READ_BIT(BDMA->ISR, BDMA_ISR_TCIF7) == (BDMA_ISR_TCIF7)))
	{
		WRITE_REG(BDMA->IFCR, BDMA_IFCR_CTCIF7);
		isrType = BDMA_TRANSFER_COMPLETE;
		if(BDMAIsrCbBuff[7].cb)
		{
			BDMAIsrCbBuff[7].cb(BDMAIsrCbBuff[7].param, 0, isrType);
		}
	}
	if((READ_BIT(BDMA_Channel7->CCR, BDMA_CCR_HTIE) == (BDMA_CCR_HTIE)) && (READ_BIT(BDMA->ISR, BDMA_ISR_HTIF7) == (BDMA_ISR_HTIF7)))
	{
		WRITE_REG(BDMA->IFCR, BDMA_IFCR_CHTIF7);
		isrType = BDMA_TRANSFER_HALF;
		if(BDMAIsrCbBuff[7].cb)
		{
			BDMAIsrCbBuff[7].cb(BDMAIsrCbBuff[7].param, 0, isrType);
		}
	}
	if((READ_BIT(BDMA_Channel7->CCR, BDMA_CCR_TEIE) == (BDMA_CCR_TEIE)) && (READ_BIT(BDMA->ISR, BDMA_ISR_TEIF7) == (BDMA_ISR_TEIF7)))
	{
		WRITE_REG(BDMA->IFCR, BDMA_IFCR_CTEIF7);
		isrType = BDMA_TRANSFER_ERROR;
		if(BDMAIsrCbBuff[7].cb)
		{
			BDMAIsrCbBuff[7].cb(BDMAIsrCbBuff[7].param, 0, isrType);
		}
	}
}
void DMAMUX1_OVR_IRQHandler()
{
	for(int i = 0; i < 16; i++)
	{
		if(DMAIsrCbBuff[i].cb)
		{
			DMAIsrCbBuff[i].cb(DMAIsrCbBuff[i].param, 1, 0);
		}
	}
}
void DMAMUX2_OVR_IRQHandler()
{
	for(int i = 0; i < 8; i++)
	{
		if(BDMAIsrCbBuff[i].cb)
		{
			BDMAIsrCbBuff[i].cb(BDMAIsrCbBuff[i].param, 1, 0);
		}
	}
}
typedef struct RTCIsrSt
{
	RTC_ISR_CB cb;
	void* param;
}RTCIsrSt;
static RTCIsrSt RTCIsrCbBuff[3] = {0};
void registerRTCIsrCb(RTCEnableIT isrType, RTC_ISR_CB cb, void* param)
{
	if(isrType == RTC_CR_ALARMB_IE || isrType == RTC_CR_ALARMB_IE)
	{
		RTCIsrCbBuff[0].cb = cb;
		RTCIsrCbBuff[0].param = param;
	}
	else if(isrType == RTC_CR_WAKEUP_IE)
	{
		RTCIsrCbBuff[1].cb = cb;
		RTCIsrCbBuff[1].param = param;
	}
	else if(isrType == RTC_CR_TIME_STAMP_IE || isrType == RTC_TAMPCR_TAMP3_IE || isrType == RTC_TAMPCR_TAMP2_IE || isrType == RTC_TAMPCR_TAMP1_IE || isrType == RTC_TAMPCR_TAMP_IE)
	{
		RTCIsrCbBuff[2].cb = cb;
		RTCIsrCbBuff[2].param = param;
	}
}
void unRegisterRTCIsrCb(RTCEnableIT isrType)
{
	if(isrType == RTC_CR_ALARMB_IE || isrType == RTC_CR_ALARMB_IE)
	{
		RTCIsrCbBuff[0].cb = NULL;
		RTCIsrCbBuff[0].param = NULL;
	}
	else if(isrType == RTC_CR_WAKEUP_IE)
	{
		RTCIsrCbBuff[1].cb = NULL;
		RTCIsrCbBuff[1].param = NULL;
	}
	else if(isrType == RTC_CR_TIME_STAMP_IE || isrType == RTC_TAMPCR_TAMP3_IE || isrType == RTC_TAMPCR_TAMP2_IE || isrType == RTC_TAMPCR_TAMP1_IE || isrType == RTC_TAMPCR_TAMP_IE)
	{
		RTCIsrCbBuff[2].cb = NULL;
		RTCIsrCbBuff[2].param = NULL;
	}
}

void TAMP_STAMP_IRQHandler(void)
{
	WRITE_REG(EXTI->PR1, EXTI_IMR1_IM18);
	if((READ_BIT(RTC->CR, RTC_CR_TSIE) == (RTC_CR_TSIE)) && ((READ_BIT(RTC->ISR, RTC_ISR_ITSF) == (RTC_ISR_ITSF)) || (READ_BIT(RTC->ISR, RTC_ISR_TSF) == (RTC_ISR_TSF))))
	{
		RTCRIsrFlags flag = (READ_BIT(RTC->ISR, RTC_ISR_ITSF) == (RTC_ISR_ITSF)) ? RTC_ISR_LITSF : RTC_ISR_LTSF;
		WRITE_REG(RTC->ISR, (~((RTC_ISR_ITSF | RTC_ISR_INIT | RTC_ISR_TSF) & 0x0000FFFFU) | (RTC->ISR & RTC_ISR_INIT)));
		if(RTCIsrCbBuff[2].cb && RTCIsrCbBuff[2].param)
		{
			RTCIsrCbBuff[2].cb(RTCIsrCbBuff[2].param, flag);
		}
	}
	if((READ_BIT(RTC->ISR, RTC_ISR_TSOVF) == (RTC_ISR_TSOVF)))
	{
		WRITE_REG(RTC->ISR, (~((RTC_ISR_TSOVF | RTC_ISR_INIT) & 0x0000FFFFU) | (RTC->ISR & RTC_ISR_INIT)));
		if(RTCIsrCbBuff[2].cb && RTCIsrCbBuff[2].param)
		{
			RTCIsrCbBuff[2].cb(RTCIsrCbBuff[2].param, RTC_ISR_LTSOVF);
		}
	}
	if((READ_BIT(RTC->TAMPCR, RTC_TAMPCR_TAMP3IE) == (RTC_TAMPCR_TAMP3IE)) && (READ_BIT(RTC->ISR, RTC_ISR_TAMP3F) == (RTC_ISR_TAMP3F)))
	{
		WRITE_REG(RTC->ISR, (~((RTC_ISR_TAMP3F | RTC_ISR_INIT) & 0x0000FFFFU) | (RTC->ISR & RTC_ISR_INIT)));
		if(RTCIsrCbBuff[2].cb && RTCIsrCbBuff[2].param)
		{
			RTCIsrCbBuff[2].cb(RTCIsrCbBuff[2].param, RTC_ISR_LTAMP3F);
		}
	}
	if((READ_BIT(RTC->TAMPCR, RTC_TAMPCR_TAMP2IE) == (RTC_TAMPCR_TAMP2IE)) && (READ_BIT(RTC->ISR, RTC_ISR_TAMP2F) == (RTC_ISR_TAMP2F)))
	{
		WRITE_REG(RTC->ISR, (~((RTC_ISR_TAMP2F | RTC_ISR_INIT) & 0x0000FFFFU) | (RTC->ISR & RTC_ISR_INIT)));
		if(RTCIsrCbBuff[2].cb && RTCIsrCbBuff[2].param)
		{
			RTCIsrCbBuff[2].cb(RTCIsrCbBuff[2].param, RTC_ISR_LTAMP2F);
		}
	}
	if((READ_BIT(RTC->TAMPCR, RTC_TAMPCR_TAMP1IE) == (RTC_TAMPCR_TAMP1IE)) && (READ_BIT(RTC->ISR, RTC_ISR_TAMP1F) == (RTC_ISR_TAMP1F)))
	{
		WRITE_REG(RTC->ISR, (~((RTC_ISR_TAMP1F | RTC_ISR_INIT) & 0x0000FFFFU) | (RTC->ISR & RTC_ISR_INIT)));
		if(RTCIsrCbBuff[2].cb && RTCIsrCbBuff[2].param)
		{
			RTCIsrCbBuff[2].cb(RTCIsrCbBuff[2].param, RTC_ISR_LTAMP1F);
		}
	}
}
void RTC_WKUP_IRQHandler(void)
{
	WRITE_REG(EXTI->PR1, EXTI_IMR1_IM19);
	if((READ_BIT(RTC->CR, RTC_CR_WUTIE) == (RTC_CR_WUTIE)) && (READ_BIT(RTC->ISR, RTC_ISR_WUTF) == (RTC_ISR_WUTF)))
	{
		WRITE_REG(RTC->ISR, (~((RTC_ISR_WUTF | RTC_ISR_INIT) & 0x0000FFFFU) | (RTC->ISR & RTC_ISR_INIT)));
		if(RTCIsrCbBuff[1].cb && RTCIsrCbBuff[1].param)
		{
			RTCIsrCbBuff[1].cb(RTCIsrCbBuff[1].param, RTC_ISR_LWUTF);
		}
	}
}
void RTC_Alarm_IRQHandler(void)
{
	WRITE_REG(EXTI->PR1, EXTI_IMR1_IM17);
	if((READ_BIT(RTC->CR, RTC_CR_ALRBIE) == (RTC_CR_ALRBIE)) && (READ_BIT(RTC->ISR, RTC_ISR_ALRBF) == (RTC_ISR_ALRBF)))
	{
		WRITE_REG(RTC->ISR, (~((RTC_ISR_ALRBF | RTC_ISR_INIT) & 0x0000FFFFU) | (RTC->ISR & RTC_ISR_INIT)));
		if(RTCIsrCbBuff[0].cb && RTCIsrCbBuff[1].param)
		{
			RTCIsrCbBuff[0].cb(RTCIsrCbBuff[1].param, RTC_ISR_LALRBF);
		}
	}
	if((READ_BIT(RTC->CR, RTC_CR_ALRAIE) == (RTC_CR_ALRAIE)) && (READ_BIT(RTC->ISR, RTC_ISR_ALRAF) == (RTC_ISR_ALRAF)))
	{
		WRITE_REG(RTC->ISR, (~((RTC_ISR_ALRAF | RTC_ISR_INIT) & 0x0000FFFFU) | (RTC->ISR & RTC_ISR_INIT)));
		if(RTCIsrCbBuff[0].cb && RTCIsrCbBuff[1].param)
		{
			RTCIsrCbBuff[0].cb(RTCIsrCbBuff[1].param, RTC_ISR_LALRAF);
		}
	}
}
/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
	incTick();
}

//for lib tick
__IO uint32_t uwTick;
uint32_t uwTickPrio   = (1UL << __NVIC_PRIO_BITS); /* Invalid PRIO */
TickFreqTypeDef uwTickFreq = TICK_FREQ_1KHZ;  /* 1KHz */

int32_t initTick(uint32_t TickPriority)
{
	/* Check uwTickFreq for MisraC 2012 (even if uwTickFreq is a enum type that don't take the value zero)*/
	if((uint32_t)uwTickFreq == 0UL)
	{
		return -1;
	}
    SystemCoreClockUpdate();
    /* Configure the SysTick to have interrupt in 1ms time basis*/
    if (SysTick_Config(SystemCoreClock / (1000UL / (uint32_t)uwTickFreq)) > 0U)
    {
      return -2;
    }
	/* Configure the SysTick IRQ priority */
	if (TickPriority < (1UL << __NVIC_PRIO_BITS))
	{
		NVIC_SetPriority(SysTick_IRQn, TickPriority);
		uwTickPrio = TickPriority;
	}
	else
	{
		return -3;
	}
	/* Return function status */
	return 0;
}

void incTick(void)
{
  uwTick += (uint32_t)uwTickFreq;
}

uint32_t getTick(void)
{
  return uwTick;
}
uint32_t getTickPrio(void)
{
  return uwTickPrio;
}
int setTickFreq(TickFreqTypeDef Freq)
{
  int status  = 0;
  TickFreqTypeDef prevTickFreq;

  if (uwTickFreq != Freq)
  {
    /* Back up uwTickFreq frequency */
    prevTickFreq = uwTickFreq;

    /* Update uwTickFreq global variable used by HAL_InitTick() */
    uwTickFreq = Freq;

    /* Apply the new tick Freq  */
    status = initTick(uwTickPrio);
    if (status != 0)
    {
      /* Restore previous tick frequency */
      uwTickFreq = prevTickFreq;
    }
  }
  return status;
}

TickFreqTypeDef getTickFreq(void)
{
  return uwTickFreq;
}

void delayTick(uint32_t Delay)
{
  uint32_t tickstart = getTick();
  uint32_t wait = Delay;

  /* Add a freq to guarantee minimum wait */
  if (wait < MAX_DELAY)
  {
    wait += (uint32_t)(uwTickFreq);
  }

  while ((getTick() - tickstart) < wait)
  {
  }
}