#include "mpu.hpp"
#include <stdio.h>
#include <stdlib.h>
#include "delay.hpp"
#include "w25qxx.h"
#include "sdram.h"
#include "gpio.hpp"
#include "usart.hpp"
#include "rcc.hpp"
#include "systeminit.hpp"
#include "led.hpp"
#include "iwdg.hpp"
#include "timer.hpp"
#include "dma.hpp"
#if 0
int main(void)
{
    if(!hwInit())
    {
        while(1);
    }
    LED led(GPIOC, GPIO_NUM_13);
     GPIO d0(GPIOB, GPIO_NUM_0|GPIO_NUM_1|GPIO_NUM_3, GPIO_MODE_INPUT, GPIO_SPEED_FAST, GPIO_PUPD_PU);
     d0.registerInterruptCb([](GPIO* g, GPIONumBit p){
         printf("d0 pin %d isr\r\n",p);
     });
     d0.enableIsr(GPIO_MODE_IT_FALLING,2,0);
    
    // GPIO A0(GPIOA, GPIO_NUM_0|GPIO_NUM_1|GPIO_NUM_3|GPIO_NUM_11|GPIO_NUM_12, GPIO_MODE_INPUT, GPIO_SPEED_FAST, GPIO_PUPD_PU);
    //     A0.registerInterruptCb([](GPIO* g, GPIONumBit p){
    //     printf("a0 pin %d isr\r\n",p);
    // });
    // A0.enableIsr(GPIO_MODE_IT_FALLING,2,0);
    GPIO tim2ch1(GPIOA, GPIO_NUM_0, GPIO_MODE_AF_PP, GPIO_SPEED_HIGH, GPIO_PUPD_PU);
    tim2ch1.setAF(GPIO_AF1_TIM2);
    COMMONTIMER timer1(TIM2);
    timer1.timInit(20000000);
    timer1.pwmConfig(TIM_CHANNEL_1, 50, TIM_OCMODE_PWM1);
    timer1.registerInterruptCb([&led](COMMONTIMER* timer, TIMISRFlag isrflag){
        if(isrflag == TIM_FLAG_UPDATE)
        {
            //led.reverse();
            //printf("timer 1\n");
        }
        if(isrflag == TIM_FLAG_CC1)
        {
            //printf("cc isr\n");
        }
    });
        //timer1.enableIsr(TIM_IT_UPDATE, 5,0);
    //timer1.enableIsr(TIM_IT_CC1, 5,0);
    timer1.start();
    delayTick(3000);
    timer1.pwmStart(TIM_CHANNEL_1);
    printf("get greq = %lu\r\n",timer1.getTimFreq());
    //delayTick(5000);
    //timer1.setTimFreq(10);
    timer1.pwmSetDuty(TIM_CHANNEL_1, 30);
    printf("get greq = %lu\r\n",timer1.getTimFreq());
    printf("get time = %lu NS\r\n",timer1.getTimeoutTimerNs());

   GPIO tim4ch4(GPIOD, GPIO_NUM_15, GPIO_MODE_AF_PP, GPIO_SPEED_HIGH, GPIO_PUPD_PU);
    tim4ch4.setAF(GPIO_AF2_TIM4);
    COMMONTIMER timer4(TIM4);
    timer4.timInit(50);
    timer4.pwmConfig(TIM_CHANNEL_4, 50, TIM_OCMODE_PWM1);
    timer4.registerInterruptCb([&led](COMMONTIMER* timer, TIMISRFlag isrflag){
        if(isrflag == TIM_FLAG_UPDATE)
        {
            //led.reverse();
            //printf("timer 1\n");
        }
        if(isrflag == TIM_FLAG_CC1)
        {
            //printf("cc isr\n");
        }
        //printf("xxxxxxxx\r\n");
    });
    timer4.pwmStart(TIM_CHANNEL_4);
    timer4.enableIsr(TIM_IT_UPDATE, 5,0);
    timer4.enableIsr(TIM_IT_CC4, 5,0);
    timer4.start();
    uint32_t i = 0;
    while(1)
    {

        delayTick(30);
        //timer4.pwmSetDuty(TIM_CHANNEL_4, i++);
        //timer1.pwmSetDuty(TIM_CHANNEL_1, i++);
        if(i > 100) i = 0;

    }
    return 0;
}
#endif
#if 0
int main(void)
{
    if(!hwInit())
    {
        while(1);
    }
    LED led(GPIOC, GPIO_NUM_13);
     GPIO d0(GPIOB, GPIO_NUM_0|GPIO_NUM_1|GPIO_NUM_3, GPIO_MODE_INPUT, GPIO_SPEED_FAST, GPIO_PUPD_PU);
     d0.registerInterruptCb([](GPIO* g, GPIONumBit p){
         printf("d0 pin %d isr\r\n",p);
     });
     d0.enableIsr(GPIO_MODE_IT_FALLING,2,0);
    
    // GPIO A0(GPIOA, GPIO_NUM_0|GPIO_NUM_1|GPIO_NUM_3|GPIO_NUM_11|GPIO_NUM_12, GPIO_MODE_INPUT, GPIO_SPEED_FAST, GPIO_PUPD_PU);
    //     A0.registerInterruptCb([](GPIO* g, GPIONumBit p){
    //     printf("a0 pin %d isr\r\n",p);
    // });
    // A0.enableIsr(GPIO_MODE_IT_FALLING,2,0);
    GPIO tim2ch1(GPIOA, GPIO_NUM_0, GPIO_MODE_AF_PP, GPIO_SPEED_HIGH, GPIO_PUPD_PU);
    tim2ch1.setAF(GPIO_AF1_TIM2);
    COMMONTIMER timer2(TIM2);
    timer2.timInit(50);
    timer2.ocConfig(TIM_CHANNEL_1, 50, TIM_OCMODE_TOGGLE);
    timer2.registerInterruptCb([&led](COMMONTIMER* timer, TIMISRFlag isrflag){
        if(isrflag == TIM_FLAG_UPDATE)
        {
            //led.reverse();
            //printf("timer 1\n");
        }
        if(isrflag == TIM_FLAG_CC1)  
        {  
            //printf("cc isr\n");
            //led.reverse();
        }
    });
        timer2.enableIsr(TIM_IT_UPDATE, 5,0);
        timer2.enableIsr(TIM_IT_CC1, 5,0);
    timer2.start();
    delayTick(3000);
    timer2.ocStart(TIM_CHANNEL_1);
    printf("get greq = %lu\r\n",timer2.getTimFreq());
    //delayTick(5000);
    //timer1.setTimFreq(10);
    printf("get greq = %lu\r\n",timer2.getTimFreq());
    printf("get time = %lu\r\n",timer2.getTimeoutTimerMs());

    uint32_t i = 0;
    while(1)
    {
        delayTick(30);
    }
    return 0;
}
#endif
#if 0
int main(void)
{
    if(!hwInit())
    {
        while(1);
    }
    LED led(GPIOC, GPIO_NUM_13);

    GPIO tim1ch1(GPIOA, GPIO_NUM_8, GPIO_MODE_AF_PP, GPIO_SPEED_HIGH, GPIO_PUPD_PU);
    tim1ch1.setAF(GPIO_AF1_TIM1);
    GPIO tim1ch1n(GPIOB, GPIO_NUM_13, GPIO_MODE_AF_PP, GPIO_SPEED_HIGH, GPIO_PUPD_PU);
    tim1ch1n.setAF(GPIO_AF1_TIM1);
    GPIO tim1brk(GPIOB, GPIO_NUM_12, GPIO_MODE_AF_PP, GPIO_SPEED_HIGH, GPIO_PUPD_PD);
    tim1brk.setAF(GPIO_AF1_TIM1);
    COMMONTIMER timer1(TIM1);
    timer1.timInit(10000);
    timer1.pwmConfig(TIM_CHANNEL_1, 50, TIM_OCMODE_PWM1,TIM_OCPOLARITY_HIGH,TIM_OCNPOLARITY_HIGH, TIM_OCIDLESTATE_SET/*空闲时的电平*/, TIM_OCNIDLESTATE_RESET);
    PWMBreakDeadTimeConfig pconfig = {TIM_OSSR_ENABLE,
                                        TIM_OSSI_ENABLE,
                                        TIM_LOCKLEVEL_1,
                                        timer1.calcuDTGns(3000),
                                        TIM_BREAK_ENABLE,
                                        TIM_BREAKPOLARITY_HIGH,
                                        0,
                                        TIM_BREAK2_DISABLE,
                                        TIM_BREAK2POLARITY_LOW,
                                        0,
                                        TIM_AUTOMATICOUTPUT_ENABLE
    };

    timer1.pwmConfigBreakDeadTime(&pconfig);
    timer1.registerInterruptCb([&led](COMMONTIMER* timer, TIMISRFlag isrflag){
        if(isrflag == TIM_FLAG_UPDATE)
        {
            //led.reverse();
            //printf("timer 1\n");
        }
        if(isrflag == TIM_FLAG_CC1)
        {
            //printf("cc isr\n");
        }
        if(isrflag == TIM_FLAG_BREAK)
        {
            printf("BREAK FLAG\r\n");
        }
    });
    //timer1.enableIsr(TIM_IT_UPDATE, 5,0);
    //timer1.enableIsr(TIM_IT_CC1, 5,0);
    //timer1.enableIsr(TIM_IT_BREAK, 5,0);
    timer1.start();
    timer1.pwmStart(TIM_CHANNEL_1);
    timer1.pwmNstart(TIM_CHANNEL_1);

    while(1)
    {
        delayTick(3000);
    }
    return 0;
}
#endif
#if 0
int main(void)
{
    /* Captured Values */
    uint32_t               uwIC2Value1 = 0;
    uint32_t               uwIC2Value2 = 0;
    uint32_t               uwDiffCapture = 0;

    /* Capture index */
    uint16_t               uhCaptureIndex = 0;

    /* Frequency Value */
    uint32_t               uwFrequency = 0;

    if(!hwInit())
    {
        while(1);
    }
    LED led(GPIOE, GPIO_NUM_9);
#if 1
    //TIM2 PWM OUT
    GPIO tim2ch1(GPIOA, GPIO_NUM_3, GPIO_MODE_AF_PP, GPIO_SPEED_HIGH, GPIO_PUPD_PU);
    tim2ch1.setAF(GPIO_AF1_TIM2);
    COMMONTIMER timer2(TIM2);
    timer2.timInit(20000000);
    timer2.pwmConfig(TIM_CHANNEL_4, 50, TIM_OCMODE_PWM1);
    timer2.pwmStart(TIM_CHANNEL_4);
    timer2.start();


    //TIM5 INPUT
    GPIO tim5ch1(GPIOA, GPIO_NUM_0, GPIO_MODE_AF_PP, GPIO_SPEED_HIGH, GPIO_PUPD_PD);
    tim5ch1.setAF(GPIO_AF2_TIM5);
    COMMONTIMER timer5(TIM5);
    timer5.timInit(1);
    //CHECK_RETURN_WITH_INFO(timer5.timInit(0xFFFFFFFF - 1, 240-1), " init fail");
    //timer4.pwmConfig(TIM_CHANNEL_4, 50, TIM_OCMODE_PWM1);
    CHECK_RETURN_WITH_INFO(timer5.icConfig(TIM_CHANNEL_1, TIM_ICPOLARITY_RISING, TIM_ICSELECTION_DIRECTTI, TIM_ICPSC_DIV1), "icConfig fail");
    timer5.registerInterruptCb([&](COMMONTIMER* timer, TIMISRFlag isrflag){
        if(isrflag == TIM_FLAG_UPDATE)
        {
            //led.reverse();
            printf("timer 2\n");
        }
        if(isrflag == TIM_FLAG_CC1)
        {
            if(uhCaptureIndex == 0)
            {
                /* Get the 1st Input Capture value */
                uwIC2Value1 = timer5.readCapturedValue(TIM_CHANNEL_1);
                uhCaptureIndex = 1;
            }
            else if(uhCaptureIndex == 1)
            {
                uwIC2Value2 = timer5.readCapturedValue(TIM_CHANNEL_1);
                /* Capture computation */
                if (uwIC2Value2 > uwIC2Value1)
                {
                    uwDiffCapture = (uwIC2Value2 - uwIC2Value1); 
                }
                else if (uwIC2Value2 < uwIC2Value1)
                {
                    /* 0xFFFF is max TIM1_CCRx value */
                    uwDiffCapture = ((timer5.getPeriod() - uwIC2Value1) + uwIC2Value2) + 1;
                }
                uwFrequency = timer5.getInputClk() / uwDiffCapture;
                uhCaptureIndex = 0;
                printf("freq = %lu\r\n",uwFrequency);
            }
        }
    });
    timer5.enableIsr(TIM_IT_UPDATE, 5,0);
    timer5.enableIsr(TIM_IT_CC1, 5,0);
    CHECK_RETURN_WITH_INFO(timer5.icStart(TIM_CHANNEL_1), "icStart fail");
    timer5.start();
#endif
    uint32_t i = 0;
    while(1)
    {
        delayTick(500);
        led.reverse();
        printf("hellow world i = %lu\r\n",i++);
    }
    return 0;
}
#endif

#if 0
static uint8_t sendBuff[] = "----------------------------------------------------------------------=====================++++++++++++++++++++++++++-";
int main(void)
{
    if(!hwInit())
    {
        while(1);
    }
    LED led(GPIOE, GPIO_NUM_9, false);
    LED led1(GPIOA, GPIO_NUM_7, true);
    DMA dmax(DMA2, DMA_STREAM_7);
    DMA_InitTypeDef DMA_InitStruct;
    DMA_InitStruct.Direction = DMA_DIRECTION_MEMORY_TO_PERIPH;
    DMA_InitStruct.PeriphOrM2MSrcAddress = (uint32_t)&(USART1->TDR);  
    DMA_InitStruct.MemoryOrM2MDstAddress = (uint32_t)sendBuff;             
    DMA_InitStruct.Mode = DMA_MODE_NORMAL;                   
    DMA_InitStruct.PeriphOrM2MSrcIncMode = DMA_PERIPH_NOINCREMENT;  
    DMA_InitStruct.MemoryOrM2MDstIncMode = DMA_MEMORY_INCREMENT;  
    DMA_InitStruct.PeriphOrM2MSrcDataSize = DMA_PDATAALIGN_BYTE; 
    DMA_InitStruct.MemoryOrM2MDstDataSize = DMA_MDATAALIGN_BYTE; 
    DMA_InitStruct.NbData = sizeof(sendBuff);                 
    DMA_InitStruct.PeriphRequest = DMAMUX1_REQ_USART1_TX;
    DMA_InitStruct.Priority = DMA_PRIORITY_MEDIUM;               
    DMA_InitStruct.FIFOMode = DMA_FIFOMODE_DISABLE;               
    DMA_InitStruct.FIFOThreshold = DMA_FIFOTHRESHOLD_FULL;          
    DMA_InitStruct.MemBurst = DMA_MBURST_SINGLE;               
    DMA_InitStruct.PeriphBurst = DMA_PBURST_SINGLE;   
    dmax.dmaDeInit();
    dmax.dmaInit(&DMA_InitStruct);
    dmax.dmaEnableITTransterHalf();
    dmax.dmaEnableITTransferComplete();
    dmax.enableDmaIsr(2,2);
    dmax.registerInterruptCb([&](DMA* pdma, DMATransferIsrType type){
        printf("ooo type is%u\r\n",type);

    });
    ATOMIC_SET_BIT(USART1->CR3, USART_CR3_DMAT);
    delayTick(3000);
    dmax.dmaEnableStream();
    while(1)
    {
        delayTick(100);
        led.reverse();
        led1.reverse();
        //printf("hellow world +++\r\n");
    }
    return 0;
}
#endif

#if 0
#include "lptimer.hpp"
#include "isrcommon.h"
int main(void)
{
    uint32_t a = 0, b = 0, c = 0;
    if(!hwInit())
    {
        while(1);
    }
    LED led(GPIOE, GPIO_NUM_9, false);
    LED led1(GPIOA, GPIO_NUM_7, true);

    LPTIMER lptim2(LPTIM2);
    RCCControl::getInstance()->SetLPTIMClockSource(RCC_LPTIM2_CLKSOURCE_LSI);
    printf("lptim2 input clk = %lu, src = %u\r\n",RCCControl::getInstance()->GetLPTIMClockFreq(RCC_LPTIM2_CLKSOURCE),RCCControl::getInstance()->GetLPTIMClockSource(RCC_LPTIM2_CLKSOURCE));
    lptim2.lptimInit(LPTIM_CLK_SOURCE_INTERNAL, LPTIM_PRESCALER_DIV1);
    lptim2.registerInterruptCb([&](LPTIMER* lptimx, LPTIMIsrFlgas flags){
        if(flags == LPTIM_ISR_FLAG_CMPM)
        {
            led.reverse();
            //printf("isr CMPM\r\n");
            a++;
        }
        if(flags == LPTIM_ISR_FLAG_ARRM)
        {
            led1.reverse();
            //printf("isr ARRM\r\n");
            b++;
        }
        if(flags == LPTIM_ISR_FLAG_NONE)
        {
            //printf("isr FLAG NONE\r\n");
            c++;
        }
    });
    lptim2.lptimEnableITARRM();
    lptim2.lptimEnableITCMPM();
    lptim2.enableLPTIMIsr(2,2);
    lptim2.lptimTimeoutStart(16000-1,8000-1);
    printf("tony get lptim clk = %lu\r\n",RCCControl::getInstance()->GetLPTIMClockFreq(RCC_LPTIM2_CLKSOURCE));
    printf("tony timeout time = %lu\r\n",RCCControl::getInstance()->GetLPTIMClockFreq(RCC_LPTIM2_CLKSOURCE)*1000/30000);
    while(1)
    {
        delayTick(100);
        printf(" a = %lu, b = %lu, c=%lu\r\n",a,b,c);
    }
    return 0;
}
#endif
#if 1
#include "rtc.hpp"
#include "lptimer.hpp"
#include "isrcommon.h"
int main(void)
{
    if(!hwInit())
    {
        while(1);
    }
    //LED led(GPIOE, GPIO_NUM_9, false);
    GPIO tim1ch1(GPIOE,GPIO_NUM_9,GPIO_MODE_AF_PP,GPIO_SPEED_HIGH,GPIO_PUPD_NONE);
    tim1ch1.setAF(GPIO_AF1_TIM1);

    LED led1(GPIOA, GPIO_NUM_7, true);
 
    COMMONTIMER timer1(TIM1);
    timer1.timInit(2000);
    timer1.pwmConfig(TIM_CHANNEL_1,50,TIM_OCMODE_PWM1);
    timer1.registerInterruptCb([&](COMMONTIMER* timer, TIMISRFlag flag) {
        if(timer)
        {
            if(flag == TIM_FLAG_UPDATE)
            {
                //printf("tony xxxx\r\n");
                //led.reverse();
                led1.reverse();
            }
            else
            {
                //printf("mmmmmmmmm flag = %lu\r\n",flag);
            }
        }
    });
    timer1.enableIsr(TIM_IT_UPDATE,2,2);
    timer1.pwmStart(TIM_CHANNEL_1);
    timer1.start();
    uint32_t i = 0;
    uint16_t m = 0;
    while(1)
    {
        delayTick(100);
        if(m == 0)
        {
            if(i<95)
            {
                i+=5;
            }
            else
            {
                m = 1;
            }
        }
        else
        {
            if(i>=5)
            {
                i-=5;
            }
            else
            {
                m = 0;
            }
        }

        timer1.pwmSetDuty(TIM_CHANNEL_1,i);
        printf("--------------\r\n");
    }
    return 0;
}
#endif