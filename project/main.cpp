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
    timer1.timInit(50);
    timer1.pwmConfig(TIM_CHANNEL_1, 50, TIM_OCMODE_PWM1);
    timer1.registerInterruptCb([&led](COMMONTIMER* timer, TIMISRFlag isrflag){
        if(isrflag == TIM_FLAG_UPDATE)
        {
            led.reverse();
            //printf("timer 1\n");
        }
        if(isrflag == TIM_FLAG_CC1)
        {
            //printf("cc isr\n");
        }
    });
    timer1.pwmStart(TIM_CHANNEL_1);
    timer1.enableIsr(TIM_IT_UPDATE, 5,0);
    timer1.enableIsr(TIM_IT_CC1, 5,0);
    timer1.start();
    printf("get greq = %lu\r\n",timer1.getTimFreq());
    //delayTick(5000);
    //timer1.setTimFreq(10);
    timer1.pwmSetDuty(TIM_CHANNEL_1, 30);
    printf("get greq = %lu\r\n",timer1.getTimFreq());
    printf("get time = %lu\r\n",timer1.getTimeoutTimerMs());

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
    });
    timer4.pwmStart(TIM_CHANNEL_4);
    timer4.enableIsr(TIM_IT_UPDATE, 5,0);
    timer4.enableIsr(TIM_IT_CC4, 5,0);
    timer4.start();
    uint32_t i = 0;
    while(1)
    {

        delayTick(30);
        timer4.pwmSetDuty(TIM_CHANNEL_4, i++);
        if(i > 100) i = 0;

    }
    return 0;
}
