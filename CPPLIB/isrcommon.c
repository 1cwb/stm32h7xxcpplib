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
	printf("pin = %lu\r\n",pinNum);
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