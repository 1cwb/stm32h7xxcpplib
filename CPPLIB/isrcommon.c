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
void timxIsrCallback(TIM_TypeDef *timx)
{
	for(int i = 0; i < 13; i++)
	{
		if(timIsrCbBuff[i].timx == timx)
		{
			if(timIsrCbBuff[i].cb)
			{
				timIsrCbBuff[i].cb(timIsrCbBuff[i].param);
				break;
			}
		}
	}
}

void TIM1_BRK_IRQHandler(void)
{
	timxIsrCallback(TIM1);
}
void TIM1_UP_IRQHandler(void)
{
	timxIsrCallback(TIM1);
}
void TIM1_TRG_COM_IRQHandler(void)
{
	timxIsrCallback(TIM1);
}
void TIM1_CC_IRQHandler(void)
{
	timxIsrCallback(TIM1);
}
void TIM2_IRQHandler(void)
{
	timxIsrCallback(TIM2);
}
void TIM3_IRQHandler(void)
{
	timxIsrCallback(TIM3);
}
void TIM4_IRQHandler(void)
{
	timxIsrCallback(TIM4);
}
void TIM5_IRQHandler(void)
{
	timxIsrCallback(TIM5);
}
void TIM6_DAC_IRQHandler(void)
{
	timxIsrCallback(TIM6);
}
void TIM7_IRQHandler(void)
{
	timxIsrCallback(TIM7);
}
void TIM8_BRK_TIM12_IRQHandler(void)
{
	if(READ_BIT(TIM8->SR, TIM_SR_BIF) == TIM_SR_BIF)
	{
		timxIsrCallback(TIM8);
	}
	else
	{
		timxIsrCallback(TIM12);
	}
}
void TIM8_UP_TIM13_IRQHandler(void)
{
	if(READ_BIT(TIM8->SR, TIM_SR_UIF) == TIM_SR_UIF)
	{
		timxIsrCallback(TIM8);
	}
	else
	{
		timxIsrCallback(TIM13);
	}
}
void TIM8_TRG_COM_TIM14_IRQHandler(void)
{
	if(READ_BIT(TIM8->SR, TIM_SR_COMIF) == TIM_SR_COMIF || READ_BIT(TIM8->SR, TIM_SR_TIF) == TIM_SR_TIF)
	{
		timxIsrCallback(TIM8);
	}
	else
	{
		timxIsrCallback(TIM14);
	}
}
void TIM8_CC_IRQHandler(void)
{
	timxIsrCallback(TIM8);
}
void TIM15_IRQHandler(void)
{
	timxIsrCallback(TIM15);
}
void TIM16_IRQHandler(void)
{
	timxIsrCallback(TIM16);
}
void TIM17_IRQHandler(void)
{
	timxIsrCallback(TIM17);
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
	if(DMAIsrCbBuff[0].cb)
	{
		DMAIsrCbBuff[0].cb(DMAIsrCbBuff[0].param, 0);
	}
}
void DMA1_Stream1_IRQHandler()
{
	if(DMAIsrCbBuff[1].cb)
	{
		DMAIsrCbBuff[1].cb(DMAIsrCbBuff[1].param, 0);
	}
}
void DMA1_Stream2_IRQHandler()
{
	if(DMAIsrCbBuff[2].cb)
	{
		DMAIsrCbBuff[2].cb(DMAIsrCbBuff[2].param, 0);
	}
}
void DMA1_Stream3_IRQHandler()
{
	if(DMAIsrCbBuff[3].cb)
	{
		DMAIsrCbBuff[3].cb(DMAIsrCbBuff[3].param, 0);
	}
}
void DMA1_Stream4_IRQHandler()
{
	if(DMAIsrCbBuff[4].cb)
	{
		DMAIsrCbBuff[4].cb(DMAIsrCbBuff[4].param, 0);
	}
}
void DMA1_Stream5_IRQHandler()
{
	if(DMAIsrCbBuff[5].cb)
	{
		DMAIsrCbBuff[5].cb(DMAIsrCbBuff[5].param, 0);
	}
}
void DMA1_Stream6_IRQHandler()
{
	if(DMAIsrCbBuff[6].cb)
	{
		DMAIsrCbBuff[6].cb(DMAIsrCbBuff[6].param, 0);
	}
}
void DMA1_Stream7_IRQHandler()
{
		if(DMAIsrCbBuff[7].cb)
	{
		DMAIsrCbBuff[7].cb(DMAIsrCbBuff[7].param, 0);
	}
}
void DMA2_Stream0_IRQHandler()
{
	if(DMAIsrCbBuff[8].cb)
	{
		DMAIsrCbBuff[8].cb(DMAIsrCbBuff[8].param, 0);
	}
}
void DMA2_Stream1_IRQHandler()
{
	if(DMAIsrCbBuff[9].cb)
	{
		DMAIsrCbBuff[9].cb(DMAIsrCbBuff[9].param, 0);
	}
}
void DMA2_Stream2_IRQHandler()
{
	if(DMAIsrCbBuff[10].cb)
	{
		DMAIsrCbBuff[10].cb(DMAIsrCbBuff[10].param, 0);
	}
}
void DMA2_Stream3_IRQHandler()
{
	if(DMAIsrCbBuff[11].cb)
	{
		DMAIsrCbBuff[11].cb(DMAIsrCbBuff[11].param, 0);
	}
}
void DMA2_Stream4_IRQHandler()
{
	if(DMAIsrCbBuff[12].cb)
	{
		DMAIsrCbBuff[12].cb(DMAIsrCbBuff[12].param, 0);
	}
}
void DMA2_Stream5_IRQHandler()
{
	if(DMAIsrCbBuff[13].cb)
	{
		DMAIsrCbBuff[13].cb(DMAIsrCbBuff[13].param, 0);
	}
}
void DMA2_Stream6_IRQHandler()
{
	if(DMAIsrCbBuff[14].cb)
	{
		DMAIsrCbBuff[14].cb(DMAIsrCbBuff[14].param, 0);
	}
}
void DMA2_Stream7_IRQHandler()
{
	if(DMAIsrCbBuff[15].cb)
	{
		DMAIsrCbBuff[15].cb(DMAIsrCbBuff[15].param, 0);
	}
}
void BDMA_Channel0_IRQHandler()
{
	if(BDMAIsrCbBuff[0].cb)
	{
		BDMAIsrCbBuff[0].cb(BDMAIsrCbBuff[0].param, 0);
	}
}
void BDMA_Channel1_IRQHandler()
{
	if(BDMAIsrCbBuff[1].cb)
	{
		BDMAIsrCbBuff[1].cb(BDMAIsrCbBuff[1].param, 0);
	}
}
void BDMA_Channel2_IRQHandler()
{
	if(BDMAIsrCbBuff[2].cb)
	{
		BDMAIsrCbBuff[2].cb(BDMAIsrCbBuff[2].param, 0);
	}
}
void BDMA_Channel3_IRQHandler()
{
	if(BDMAIsrCbBuff[3].cb)
	{
		BDMAIsrCbBuff[3].cb(BDMAIsrCbBuff[3].param, 0);
	}
}
void BDMA_Channel4_IRQHandler()
{
	if(BDMAIsrCbBuff[4].cb)
	{
		BDMAIsrCbBuff[4].cb(BDMAIsrCbBuff[4].param, 0);
	}
}
void BDMA_Channel5_IRQHandler()
{
	if(BDMAIsrCbBuff[5].cb)
	{
		BDMAIsrCbBuff[5].cb(BDMAIsrCbBuff[5].param, 0);
	}
}
void BDMA_Channel6_IRQHandler()
{
	if(BDMAIsrCbBuff[6].cb)
	{
		BDMAIsrCbBuff[6].cb(BDMAIsrCbBuff[6].param, 0);
	}
}
void BDMA_Channel7_IRQHandler()
{
	if(BDMAIsrCbBuff[7].cb)
	{
		BDMAIsrCbBuff[7].cb(BDMAIsrCbBuff[7].param, 0);
	}
}
void DMAMUX1_OVR_IRQHandler()
{
	for(int i = 0; i < 16; i++)
	{
		if(DMAIsrCbBuff[i].cb)
		{
			DMAIsrCbBuff[i].cb(DMAIsrCbBuff[i].param, 1);
		}
	}
}
void DMAMUX2_OVR_IRQHandler()
{
	for(int i = 0; i < 8; i++)
	{
		if(BDMAIsrCbBuff[i].cb)
		{
			BDMAIsrCbBuff[i].cb(BDMAIsrCbBuff[i].param, 1);
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