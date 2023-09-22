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
    rcc->reset();
    SET_BIT(PWR->CR3, PWR_CR3_LDOEN);
    MODIFY_REG(PWR->D3CR, PWR_D3CR_VOS, (PWR_D3CR_VOS_0|PWR_D3CR_VOS_1));
    while(!READ_BIT(PWR->D3CR, PWR_D3CR_VOSRDY));
    SET_BIT(SYSCFG->PWRCR, SYSCFG_PWRCR_ODEN);
    rcc->enableHse(true);
    while(!rcc->isHseReady() && retry++ < 0x7FFF);
    CHECK_RETURN(retry != 0x7FFF, E_RESULT_TIMEOUT);
    CHECK_RETURN(rcc->selectPLLSrc(RCC_PLL_CLK_SRC_HSE), E_RESULT_BAD_INIT_FLOW);
    CHECK_RETURN(rcc->setPLL1DIVM(pllm), E_RESULT_BAD_INIT_FLOW);
    CHECK_RETURN(rcc->setPLL1DIVN(plln-1), E_RESULT_BAD_INIT_FLOW);
    CHECK_RETURN(rcc->setPLL1DIVP(pllp-1), E_RESULT_BAD_INIT_FLOW);
    CHECK_RETURN(rcc->setPLL1DIVQ(pllq-1), E_RESULT_BAD_INIT_FLOW);
    CHECK_RETURN(rcc->setPLL1DIVR(pllr-1), E_RESULT_BAD_INIT_FLOW);
    CHECK_RETURN(rcc->setPLL1InputFreqRange(RCC_PLL1_INPUT_FREQ_RANGE_4MHZ_8MHZ),E_RESULT_BAD_INIT_FLOW);
    CHECK_RETURN(rcc->setPLL1VOCRange(RCC_PLL1_VOC_TYPE_192MHZ_TO_836MHZ),E_RESULT_BAD_INIT_FLOW);
    CHECK_RETURN(rcc->enablePLL1DIVPClk(true), E_RESULT_BAD_INIT_FLOW);
    CHECK_RETURN(rcc->enablePLL1DIVQClk(true), E_RESULT_BAD_INIT_FLOW);
    CHECK_RETURN(rcc->enablePLL1DIVRClk(true), E_RESULT_BAD_INIT_FLOW);
    rcc->enablePLL1(true);
    while (!rcc->isPLL1Ready());

    //PLL2
    CHECK_RETURN(rcc->setPLL2DIVM(pllm), E_RESULT_BAD_INIT_FLOW);
    CHECK_RETURN(rcc->setPLL2DIVN(plln-1), E_RESULT_BAD_INIT_FLOW);
    CHECK_RETURN(rcc->setPLL2DIVP(pllp-1), E_RESULT_BAD_INIT_FLOW);
    CHECK_RETURN(rcc->setPLL2DIVQ(pllq-1), E_RESULT_BAD_INIT_FLOW);
    CHECK_RETURN(rcc->setPLL2DIVR(pllr-1), E_RESULT_BAD_INIT_FLOW);
    CHECK_RETURN(rcc->setPLL2InputFreqRange(RCC_PLL2_INPUT_FREQ_RANGE_1MHZ_2MHZ),E_RESULT_BAD_INIT_FLOW);
    CHECK_RETURN(rcc->setPLL2VOCRange(RCC_PLL2_VOC_TYPE_192MHZ_TO_836MHZ),E_RESULT_BAD_INIT_FLOW);
    CHECK_RETURN(rcc->enablePLL2DIVPClk(true), E_RESULT_BAD_INIT_FLOW);
    CHECK_RETURN(rcc->enablePLL2DIVQClk(true), E_RESULT_BAD_INIT_FLOW);
    CHECK_RETURN(rcc->enablePLL2DIVRClk(true), E_RESULT_BAD_INIT_FLOW);
    rcc->enablePLL2(true);
    while (!rcc->isPLL2Ready());

    rcc->setD1CPREPreScaler(RCC_D1_CPRE_PRESCALER_DIV1);//=sys_clk
    rcc->setD1HPREPAHBreScaler(RCC_D1_HPRE_AHB_PRESCALER_DIV2);//AHB 240M
    rcc->selectSysClkSrc(RCC_SYS_CLK_SRC_PLL1);//sys_clk = 480
    while(rcc->getSysClkSrcSta() != RCC_SYS_CLK_PLL1);

    MODIFY_REG(FLASH->ACR, FLASH_ACR_LATENCY, FLASH_ACR_LATENCY_2WS);//2个CPU等待周期VOS1
    MODIFY_REG(FLASH->ACR, FLASH_ACR_WRHIGHFREQ, FLASH_ACR_WRHIGHFREQ_1);//<285

    rcc->setD1PPREAPB3PreScaler(RCC_D1_PPRE_APB3_PRESCALER_DIV2);
    rcc->setD2PPRE1APB1PreScaler(RCC_D2_PPRE1_APB1_PRESCALER_DIV2);
    rcc->setD2PPRE2APB2PreScaler(RCC_D2_PPRE2_APB2_PRESCALER_DIV2);
    rcc->setD3PPREAPB4PreScaler(RCC_D3_PPRE_APB4_PRESCALER_DIV2);
    rcc->enableSYSCFGPerClk(true);//syscfg clk for exit interrupt

    CHECK_RETURN(rcc->enableCsi(true),E_RESULT_BAD_INIT_FLOW);//enable CSI
    SET_BIT(SYSCFG->CCCSR, SYSCFG_CCCSR_EN);//I/O compensation cell enable

    rcc->selectUSART16KernelClkSrc(RCC_D2_USART16_CLK_PLL2_Q_CK);
    return E_RESULT_OK;
}

void printfSysMessage()
{
    printf("RCC INIT: \r\n");
    printf("SYSCLK:  %lu \r\n",RCCControl::getInstance()->getSysClkFreq());
    printf("AHBCLK:  %lu \r\n",RCCControl::getInstance()->getHClkFreq());
    printf("APB1CLK: %lu \r\n",RCCControl::getInstance()->getAPB1ClkFreq());
    printf("APB2CLK: %lu \r\n",RCCControl::getInstance()->getAPB2ClkFreq());
    printf("APB3CLK: %lu \r\n",RCCControl::getInstance()->getAPB3ClkFreq());
    printf("APB4CLK: %lu \r\n",RCCControl::getInstance()->getAPB4ClkFreq());
}

bool hwInit()
{
    mpuMemoryProtection();
    SCB_EnableICache();		// 使能ICache
	SCB_EnableDCache();		// 使能DCache
    NVIC_SetPriorityGrouping(0x00000003);
    if(clockInit(192, 5, 2, 4, 2) != E_RESULT_OK)//sysclk 480M
    {
        return false;
    }
    SystemCoreClockUpdate();
    initTick(TICK_INT_PRIORITY);
    delayInit(RCCControl::getInstance()->getSysClkFreq());

    GPIO usartGpio(GPIOA, GPIO_NUM_9 | GPIO_NUM_10, GPIO_MODE_AF_PP, GPIO_SPEED_MID, GPIO_PUPD_PU);
    usartGpio.setAF(0x7);
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