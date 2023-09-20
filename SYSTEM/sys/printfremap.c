#include <stdio.h>
#include "stm32h7xx.h"
static USART_TypeDef *usart = USART1;

int _read (int fd, char *pBuffer, int size)  
{  
    for (int i = 0; i < size; i++)  
    {  
        while((usart->ISR&(1 << 5))==0);          //等待上一次串口数据发送完成  
        usart->RDR = (uint8_t) pBuffer[i];    //写DR,串口1将发送数据
    }
    return size;
}
int _write (int fd, char *pBuffer, int size)  
{  
    for (int i = 0; i < size; i++)  
    {  
        while((usart->ISR&(1 << 6))==0);    //等待上一次串口数据发送完成  
        usart->TDR = (uint8_t) pBuffer[i];    //写DR,串口1将发送数据
    }
    return size;
}