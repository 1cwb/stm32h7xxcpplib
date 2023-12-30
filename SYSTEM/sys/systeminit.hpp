#pragma once
#include "rcc.hpp"
#include "usart.hpp"
#include "gpio.hpp"
#include "delay.hpp"
#include "mpu.hpp"
#include "iwdg.hpp"
#include "wwdg.hpp"

void mpuMemoryProtection(void)
{
    CORTEXM7MPU::mpuDisable();
    CORTEXM7MPU::mpuSetProtection(0x20000000,
                        MPU_REGION_SIZE_1MB,
                        MPU_REGION_NUMBER0,
                        MPU_INSTRUCTION_ACCESS_ENABLE,
                        MPU_REGION_FULL_ACCESS,
                        MPU_ACCESS_NOT_SHAREABLE,
                        MPU_ACCESS_CACHEABLE,
                        MPU_ACCESS_BUFFERABLE);
    CORTEXM7MPU::mpuSetProtection(0x90000000,
                        MPU_REGION_SIZE_8MB,
                        MPU_REGION_NUMBER1,
                        MPU_INSTRUCTION_ACCESS_ENABLE,
                        MPU_REGION_FULL_ACCESS,
                        MPU_ACCESS_NOT_SHAREABLE,
                        MPU_ACCESS_CACHEABLE,
                        MPU_ACCESS_BUFFERABLE);
    CORTEXM7MPU::mpuSetProtection(0xC0000000,
                        MPU_REGION_SIZE_32MB,
                        MPU_REGION_NUMBER2,
                        MPU_INSTRUCTION_ACCESS_ENABLE,
                        MPU_REGION_FULL_ACCESS,
                        MPU_ACCESS_NOT_SHAREABLE,
                        MPU_ACCESS_CACHEABLE,
                        MPU_ACCESS_NOT_BUFFERABLE);
    CORTEXM7MPU::mpuEnable(MPU_PRIVILEGED_DEFAULT);
}

eResult clockInit(uint32_t plln, uint32_t pllm, uint32_t pllp, uint32_t pllq, uint32_t pllr)
{
    uint16_t retry = 0;
    RCCControl* rcc = RCCControl::getInstance();
    rcc->DeInit();
    SET_BIT(PWR->CR3, PWR_CR3_LDOEN);
    MODIFY_REG(PWR->D3CR, PWR_D3CR_VOS, (PWR_D3CR_VOS_0|PWR_D3CR_VOS_1));
    while(!READ_BIT(PWR->D3CR, PWR_D3CR_VOSRDY));
    SET_BIT(SYSCFG->PWRCR, SYSCFG_PWRCR_ODEN);
    rcc->HSEEnable();
    while(!rcc->HSEIsReady() && retry++ < 0x7FFF);
    CHECK_RETURN(retry != 0x7FFF, E_RESULT_TIMEOUT);
    rcc->PLLSetSource(RCC_PLLSOURCE_HSE);
    rcc->PLL1SetM(pllm);
    rcc->PLL1SetN(plln);
    rcc->PLL1SetP(pllp);
    rcc->PLL1SetQ(pllq);
    rcc->PLL1SetR(pllr);
    rcc->PLL1SetVCOInputRange(RCC_PLLINPUTRANGE_4_8);
    rcc->PLL1SetVCOOutputRange(RCC_PLLVCORANGE_WIDE);
    rcc->PLL1PEnable();
    rcc->PLL1QEnable();
    rcc->PLL1REnable();
    rcc->PLL1Enable();
    while (!rcc->PLL1IsReady());

    //PLL2
    rcc->PLL2SetM(pllm);
    rcc->PLL2SetN(plln);
    rcc->PLL2SetP(pllp);
    rcc->PLL2SetQ(pllq);
    rcc->PLL2SetR(pllr);
    rcc->PLL2SetVCOInputRange(RCC_PLLINPUTRANGE_4_8);
    rcc->PLL2SetVCOOutputRange(RCC_PLLVCORANGE_WIDE);
    rcc->PLL2PEnable();
    rcc->PLL2QEnable();
    rcc->PLL2REnable();
    rcc->PLL2Enable();
    while (!rcc->PLL2IsReady());

    rcc->SetSysPrescaler(RCC_SYSCLK_DIV_1);//=sys_clk
    rcc->SetAHBPrescaler(RCC_AHB_DIV_2);//AHB 240M
    rcc->SetSysClkSource(RCC_SYS_CLKSOURCE_PLL1);//sys_clk = 480
    while(rcc->GetSysClkSource() != RCC_SYS_CLKSOURCE_STATUS_PLL1);

    MODIFY_REG(FLASH->ACR, FLASH_ACR_LATENCY, FLASH_ACR_LATENCY_2WS);//2个CPU等待周期VOS1
    MODIFY_REG(FLASH->ACR, FLASH_ACR_WRHIGHFREQ, FLASH_ACR_WRHIGHFREQ_1);//<285

    rcc->SetAPB3Prescaler(RCC_APB3_DIV_2);
    rcc->SetAPB1Prescaler(RCC_APB1_DIV_2);
    rcc->SetAPB2Prescaler(RCC_APB2_DIV_2);
    rcc->SetAPB4Prescaler(RCC_APB4_DIV_2);
    rcc->APB4GRP1EnableClock(RCC_APB4_GRP1_PERIPH_SYSCFG);//syscfg clk for exit interrupt

    rcc->CSIEnable();//enable CSI
    SET_BIT(SYSCFG->CCCSR, SYSCFG_CCCSR_EN);//I/O compensation cell enable

    rcc->SetUSARTClockSource(RCC_USART16_CLKSOURCE_PLL2Q);

    //enable lsi hsi
    rcc->HSIEnable();
    while(!rcc->HSEIsReady());

    rcc->LSIEnable();
    while(!rcc->LSIIsReady());
    return E_RESULT_OK;
}

void printfSysMessage()
{
    printf("RCC INIT: \r\n");
    printf("SYSCLK:  %lu \r\n",RCCControl::getInstance()->GetSystemClockFreq());
    printf("AHBCLK:  %lu \r\n",RCCControl::getInstance()->GetHCLKClockFreq());
    printf("APB1CLK: %lu \r\n",RCCControl::getInstance()->GetPCLK1ClockFreq());
    printf("APB2CLK: %lu \r\n",RCCControl::getInstance()->GetPCLK2ClockFreq());
    printf("APB3CLK: %lu \r\n",RCCControl::getInstance()->GetPCLK3ClockFreq());
    printf("APB4CLK: %lu \r\n",RCCControl::getInstance()->GetPCLK4ClockFreq());
}

bool hwInit()
{
    mpuMemoryProtection();
    SCB_EnableICache();		// 使能ICache
	SCB_EnableDCache();		// 使能DCache
    NVIC_SetPriorityGrouping(0x00000003);
    if(clockInit(PLLN_VALUE, PLLM_VALUE, PLLP_VALUE, PLLQ_VALUE, PLLR_VALUE) != E_RESULT_OK)//sysclk 480M
    {
        return false;
    }
    SystemCoreClockUpdate();
    initTick(TICK_INT_PRIORITY);
    delayInit(RCCControl::getInstance()->GetSystemClockFreq());

    GPIO usartGpio(GPIOA, GPIO_NUM_9 | GPIO_NUM_10, GPIO_MODE_AF_PP, GPIO_SPEED_MID, GPIO_PUPD_PU);
    usartGpio.setAF(GPIO_AF7_USART1);
    static USART uart1(USART1, 115200, UART_MODE_TX_RX);
    uart1.enableFIFO(true);
    uart1.enableErrIsr(true);
    uart1.enableRXFIFONotEmptyIsr(true);
    uart1.setNvicPriority(3,3);
    uart1.enableNVICIrq();
    uart1.registerInterruptCb([](USART* usart_, uint32_t states, uint32_t errorstates){
        if(usart_->getState() & UART_STATE_RX_REG_OR_RFIFO_NOT_EMPTY)
        {
            uint8_t res=USART1->RDR;
            printf("recv %c\n",res);
        }
        if(errorstates)
        printf("xxxxxxxxx errorstates =%lu\n",errorstates);
    });
    printfSysMessage();
    //IWDG::getInstance()->start(IWDG_PRE_DIVI_64,500);
    WWDG::getInstance()->start(0x7F, 0X7F, WWDG_TIME_BASE_DIVI_128);
    WWDG::getInstance()->registerInterruptCb([](WWDG* wdg){
        //printf("timeout befor = %lu\r\n",WWDG::getInstance()->getTimeOutMs());
    wdg->feedDog();
        //printf("timeout = %lu\r\n",WWDG::getInstance()->getTimeOutMs());
    });
    WWDG::getInstance()->enableIsr(2,0);
    return true;
}