#pragma once
#include "common.hpp"

enum RCCOscilLatorType
{
    RCC_OSCILLATORTYPE_NONE    =   (0x00000000U),
    RCC_OSCILLATORTYPE_HSE     =   (0x00000001U),
    RCC_OSCILLATORTYPE_HSI     =   (0x00000002U),
    RCC_OSCILLATORTYPE_LSE     =   (0x00000004U),
    RCC_OSCILLATORTYPE_LSI     =   (0x00000008U),
    RCC_OSCILLATORTYPE_CSI     =   (0x00000010U),
    RCC_OSCILLATORTYPE_HSI48   =   (0x00000020U)
};
enum RCCSysClkSrcSta
{
    RCC_SYS_CLK_HSI = RCC_CFGR_SWS_HSI,                       /*!< HSI used as system clock */
    RCC_SYS_CLK_CSI = RCC_CFGR_SWS_CSI,                       /*!< CSI used as system clock */
    RCC_SYS_CLK_HSE = RCC_CFGR_SWS_HSE,                       /*!< HSE used as system clock */
    RCC_SYS_CLK_PLL1 = RCC_CFGR_SWS_PLL1                      /*!< PLL1 used as system clock */
};
enum RCCSysClkSrc
{
    RCC_SYS_CLK_SRC_HSI = RCC_CFGR_SW_HSI,                        /*!< HSI selection as system clock */
    RCC_SYS_CLK_SRC_CSI = RCC_CFGR_SW_CSI,                        /*!< CSI selection as system clock */
    RCC_SYS_CLK_SRC_HSE = RCC_CFGR_SW_HSE,                        /*!< HSE selection as system clock */
    RCC_SYS_CLK_SRC_PLL1 = RCC_CFGR_SW_PLL1                       /*!< PLL1 selection as system clock */
};
enum RCCHsiDiv
{
    RCC_HSI_DIV_1  =  RCC_CR_HSIDIV_1,
    RCC_HSI_DIV_2  =  RCC_CR_HSIDIV_2,
    RCC_HSI_DIV_4  =  RCC_CR_HSIDIV_4,
    RCC_HSI_DIV_8  =  RCC_CR_HSIDIV_8
};
enum RCCHseDivForRtc
{
    RCC_HSE_PRE_DIV_FOR_RTC_NCLK = 0,
    RCC_HSE_PRE_DIV_FOR_RTC_0    =    RCC_CFGR_RTCPRE_0,      /*!< 0x00000100 */
    RCC_HSE_PRE_DIV_FOR_RTC_1    =    RCC_CFGR_RTCPRE_1,      /*!< 0x00000200 */
    RCC_HSE_PRE_DIV_FOR_RTC_2    =    RCC_CFGR_RTCPRE_2,      /*!< 0x00000400 */
    RCC_HSE_PRE_DIV_FOR_RTC_3    =    RCC_CFGR_RTCPRE_3,      /*!< 0x00000800 */
    RCC_HSE_PRE_DIV_FOR_RTC_4    =    RCC_CFGR_RTCPRE_4,      /*!< 0x00001000 */
    RCC_HSE_PRE_DIV_FOR_RTC_5    =    RCC_CFGR_RTCPRE_5      /*!< 0x00002000 */
};
enum RCCMco1PreScaler
{
    RCC_MCO1PRE_SCALER_DISABLE = 0,
    RCC_MCO1PRE_SCALER_0    =    RCC_CFGR_MCO1PRE_0,                     
    RCC_MCO1PRE_SCALER_1    =    RCC_CFGR_MCO1PRE_1,                     
    RCC_MCO1PRE_SCALER_2    =    RCC_CFGR_MCO1PRE_2,                     
    RCC_MCO1PRE_SCALER_3    =    RCC_CFGR_MCO1PRE_3                      
};
enum RCCMco1ClkSrc
{
    RCC_MCO1CLK_SELECT_HSI = 0,
    RCC_MCO1CLK_SELECT_LSE = RCC_CFGR_MCO1_0 ,
    RCC_MCO1CLK_SELECT_HSE = RCC_CFGR_MCO1_1 ,
    RCC_MCO1CLK_SELECT_HSI48 = RCC_CFGR_MCO1_2 
};
enum RCCMco2PreScaler
{
    RCC_MCO2PRE_SCALER_DISABLE = 0,
    RCC_MCO2PRE_SCALER_0    =    RCC_CFGR_MCO2PRE_0,                     
    RCC_MCO2PRE_SCALER_1    =    RCC_CFGR_MCO2PRE_1,                     
    RCC_MCO2PRE_SCALER_2    =    RCC_CFGR_MCO2PRE_2,                     
    RCC_MCO2PRE_SCALER_3    =    RCC_CFGR_MCO2PRE_3                      
};
enum RCCMco2ClkSrc
{
    RCC_MCO1CLK_SELECT_SYS_CK = 0,
    RCC_MCO2CLK_SELECT_LSE = RCC_CFGR_MCO2_0,
    RCC_MCO2CLK_SELECT_HSE = RCC_CFGR_MCO2_1,
    RCC_MCO2CLK_SELECT_HSI48 = RCC_CFGR_MCO2_2 
};
enum RCCD1HPREAHBPrescaler
{
    RCC_D1_HPRE_AHB_PRESCALER_DIV1   =    RCC_D1CFGR_HPRE_DIV1,
    RCC_D1_HPRE_AHB_PRESCALER_DIV2   =    RCC_D1CFGR_HPRE_DIV2,
    RCC_D1_HPRE_AHB_PRESCALER_DIV4   =    RCC_D1CFGR_HPRE_DIV4,
    RCC_D1_HPRE_AHB_PRESCALER_DIV8   =    RCC_D1CFGR_HPRE_DIV8,
    RCC_D1_HPRE_AHB_PRESCALER_DIV16  =    RCC_D1CFGR_HPRE_DIV16,
    RCC_D1_HPRE_AHB_PRESCALER_DIV28  =    RCC_D1CFGR_HPRE_DIV64,
    RCC_D1_HPRE_AHB_PRESCALER_DIV128 =    RCC_D1CFGR_HPRE_DIV128,
    RCC_D1_HPRE_AHB_PRESCALER_DIV256 =    RCC_D1CFGR_HPRE_DIV256,
    RCC_D1_HPRE_AHB_PRESCALER_DIV512 =    RCC_D1CFGR_HPRE_DIV512 
};
enum RCCD1PPREAPB3Prescaler
{
    RCC_D1_PPRE_APB3_PRESCALER_DIV1 = RCC_D1CFGR_D1PPRE_DIV1,    
    RCC_D1_PPRE_APB3_PRESCALER_DIV2 = RCC_D1CFGR_D1PPRE_DIV2,    
    RCC_D1_PPRE_APB3_PRESCALER_DIV4 = RCC_D1CFGR_D1PPRE_DIV4,    
    RCC_D1_PPRE_APB3_PRESCALER_DIV8 = RCC_D1CFGR_D1PPRE_DIV8,    
    RCC_D1_PPRE_APB3_PRESCALER_DIV16 = RCC_D1CFGR_D1PPRE_DIV16
};
enum RCCD1CPREPrescaler
{
    RCC_D1_CPRE_PRESCALER_DIV1   =    RCC_D1CFGR_D1CPRE_DIV1,    
    RCC_D1_CPRE_PRESCALER_DIV2   =    RCC_D1CFGR_D1CPRE_DIV2,    
    RCC_D1_CPRE_PRESCALER_DIV4   =    RCC_D1CFGR_D1CPRE_DIV4,    
    RCC_D1_CPRE_PRESCALER_DIV8   =    RCC_D1CFGR_D1CPRE_DIV8,   
    RCC_D1_CPRE_PRESCALER_DIV16   =    RCC_D1CFGR_D1CPRE_DIV16,   
    RCC_D1_CPRE_PRESCALER_DIV64   =    RCC_D1CFGR_D1CPRE_DIV64,   
    RCC_D1_CPRE_PRESCALER_DIV128   =    RCC_D1CFGR_D1CPRE_DIV128,  
    RCC_D1_CPRE_PRESCALER_DIV256   =   RCC_D1CFGR_D1CPRE_DIV256,
    RCC_D1_CPRE_PRESCALER_DIV512   =    RCC_D1CFGR_D1CPRE_DIV512  
};

enum RCCD2PPRE1APB1Prescaler
{
    RCC_D2_PPRE1_APB1_PRESCALER_DIV1   =   RCC_D2CFGR_D2PPRE1_DIV1,     
    RCC_D2_PPRE1_APB1_PRESCALER_DIV2   =   RCC_D2CFGR_D2PPRE1_DIV2,     
    RCC_D2_PPRE1_APB1_PRESCALER_DIV4   =   RCC_D2CFGR_D2PPRE1_DIV4,     
    RCC_D2_PPRE1_APB1_PRESCALER_DIV8   =   RCC_D2CFGR_D2PPRE1_DIV8,     
    RCC_D2_PPRE1_APB1_PRESCALER_DIV16   =   RCC_D2CFGR_D2PPRE1_DIV16    
};
enum RCCD2PPRE2APB2Prescaler
{
    RCC_D2_PPRE2_APB2_PRESCALER_DIV1   =   RCC_D2CFGR_D2PPRE2_DIV1,     
    RCC_D2_PPRE2_APB2_PRESCALER_DIV2   =   RCC_D2CFGR_D2PPRE2_DIV2,     
    RCC_D2_PPRE2_APB2_PRESCALER_DIV4   =   RCC_D2CFGR_D2PPRE2_DIV4,     
    RCC_D2_PPRE2_APB2_PRESCALER_DIV8   =   RCC_D2CFGR_D2PPRE2_DIV8,     
    RCC_D2_PPRE2_APB2_PRESCALER_DIV16   =   RCC_D2CFGR_D2PPRE2_DIV16    
};
enum RCCD3PPREAPB4Prescaler
{
    RCC_D3_PPRE_APB4_PRESCALER_DIV1  =  RCC_D3CFGR_D3PPRE_DIV1,      
    RCC_D3_PPRE_APB4_PRESCALER_DIV2  =  RCC_D3CFGR_D3PPRE_DIV2,      
    RCC_D3_PPRE_APB4_PRESCALER_DIV4  =  RCC_D3CFGR_D3PPRE_DIV4,      
    RCC_D3_PPRE_APB4_PRESCALER_DIV8  =  RCC_D3CFGR_D3PPRE_DIV8,      
    RCC_D3_PPRE_APB4_PRESCALER_DIV16  =  RCC_D3CFGR_D3PPRE_DIV16     
};
enum RCCPLLClkSrc
{
    RCC_PLL_CLK_SRC_HSI  =    RCC_PLLCKSELR_PLLSRC_HSI,     
    RCC_PLL_CLK_SRC_CSI  =    RCC_PLLCKSELR_PLLSRC_CSI,     
    RCC_PLL_CLK_SRC_HSE  =    RCC_PLLCKSELR_PLLSRC_HSE,     
    RCC_PLL_CLK_SRC_NONE  =    RCC_PLLCKSELR_PLLSRC_NONE
};
enum RCCPLL1VOCRange
{
    RCC_PLL1_VOC_TYPE_192MHZ_TO_836MHZ,
    RCC_PLL1_VOC_TYPE_150MHZ_TO_420MHZ
};
enum RCCPLL1InputFreqRange
{
    RCC_PLL1_INPUT_FREQ_RANGE_1MHZ_2MHZ    =    RCC_PLLCFGR_PLL1RGE_0,
    RCC_PLL1_INPUT_FREQ_RANGE_2MHZ_4MHZ    =    RCC_PLLCFGR_PLL1RGE_1,
    RCC_PLL1_INPUT_FREQ_RANGE_4MHZ_8MHZ    =    RCC_PLLCFGR_PLL1RGE_2,
    RCC_PLL1_INPUT_FREQ_RANGE_8MHZ_16MHZ    =    RCC_PLLCFGR_PLL1RGE_3
};
enum RCCPLL2VOCRange
{
    RCC_PLL2_VOC_TYPE_192MHZ_TO_836MHZ,
    RCC_PLL2_VOC_TYPE_150MHZ_TO_420MHZ
};
enum RCCPLL2InputFreqRange
{
    RCC_PLL2_INPUT_FREQ_RANGE_1MHZ_2MHZ    =    RCC_PLLCFGR_PLL2RGE_0,
    RCC_PLL2_INPUT_FREQ_RANGE_2MHZ_4MHZ    =    RCC_PLLCFGR_PLL2RGE_1,
    RCC_PLL2_INPUT_FREQ_RANGE_4MHZ_8MHZ    =    RCC_PLLCFGR_PLL2RGE_2,
    RCC_PLL2_INPUT_FREQ_RANGE_8MHZ_16MHZ    =    RCC_PLLCFGR_PLL2RGE_3
};
enum RCCPLL3VOCRange
{
    RCC_PLL3_VOC_TYPE_192MHZ_TO_836MHZ,
    RCC_PLL3_VOC_TYPE_150MHZ_TO_420MHZ
};
enum RCCPLL3InputFreqRange
{
    RCC_PLL3_INPUT_FREQ_RANGE_1MHZ_2MHZ    =    RCC_PLLCFGR_PLL3RGE_0,
    RCC_PLL3_INPUT_FREQ_RANGE_2MHZ_4MHZ    =    RCC_PLLCFGR_PLL3RGE_1,
    RCC_PLL3_INPUT_FREQ_RANGE_4MHZ_8MHZ    =    RCC_PLLCFGR_PLL3RGE_2,
    RCC_PLL3_INPUT_FREQ_RANGE_8MHZ_16MHZ    =    RCC_PLLCFGR_PLL3RGE_3
};
enum RCCD1FMCClkSrc
{
    RCC_FMC_SELETC_HCLK3 = 0,
    RCC_FMC_SELETC_PLL1_Q_CK  =  RCC_D1CCIPR_FMCSEL_0,
    RCC_FMC_SELETC_PLL2_R_CK  = RCC_D1CCIPR_FMCSEL_1
};
enum RCCD1QSPIClkSrc
{
    RCC_QSPI_SELETC_HCLK3  = 0,
    RCC_QSPI_SELETC_PLL1_Q_CK =  RCC_D1CCIPR_QSPISEL_0,
    RCC_QSPI_SELETC_PLL2_R_CK = RCC_D1CCIPR_QSPISEL_1
};
enum RCCD1SDMMCClkSrc
{
    RCC_SDMMC_SELETC_PLL1_Q_CK,
    RCC_SDMMC_SELETC_PLL2_R_CK
};
enum RCCD1PERCKSrc
{
    RCC_PERCK_SELETC_HSI_KER_CK = 0,
    RCC_PERCK_SELETC_CSI_KER_CK = RCC_D1CCIPR_CKPERSEL_0,
    RCC_PERCK_SELETC_HSE_CK = RCC_D1CCIPR_CKPERSEL_1
};

enum RCCD2SAI1AndDFSDM1AclkSrc
{
    RCC_D2SAI1_DFSDM1_ACLK_PLL1_Q_CK    =    0,
    RCC_D2SAI1_DFSDM1_ACLK_PLL2_P_CK    =    RCC_D2CCIP1R_SAI1SEL_0,
    RCC_D2SAI1_DFSDM1_ACLK_PLL3_P_CK    =    RCC_D2CCIP1R_SAI1SEL_1,
    RCC_D2SAI1_DFSDM1_ACLK_PER_CK       =    RCC_D2CCIP1R_SAI1SEL_2
};
enum RCCD2SAI23ClkkSrc
{
    RCC_D2SAI23_CLK_PLL1_Q_CK    =    0,
    RCC_D2SAI23_CLK_PLL2_P_CK    =    RCC_D2CCIP1R_SAI23SEL_0,
    RCC_D2SAI23_CLK_PLL3_P_CK    =    RCC_D2CCIP1R_SAI23SEL_1,
    RCC_D2SAI23_CLK_PER_CK       =    RCC_D2CCIP1R_SAI23SEL_2
};
enum RCCD2SPIAndI2S123ClkSrc
{
    RCC_D2SPI_I2S_123_CLK_PLL1_Q_CK    =    0,
    RCC_D2SPI_I2S_123_CLK_PLL2_P_CK    =    RCC_D2CCIP1R_SPI123SEL_0,
    RCC_D2SPI_I2S_123_CLK_PLL3_P_CK    =    RCC_D2CCIP1R_SPI123SEL_1,
    RCC_D2SPI_I2S_123_CLK_PER_CK       =    RCC_D2CCIP1R_SPI123SEL_2
};
enum RCCD2SPI45ClkSrc
{
    RCC_D2SPI45_CLK_APB     =    0,
    RCC_D2SPI45_CLK_PLL2_Q_CK     =    RCC_D2CCIP1R_SPI45SEL_0,
    RCC_D2SPI45_CLK_PLL3_Q_CK     =    RCC_D2CCIP1R_SPI45SEL_1,
    RCC_D2SPI45_CLK_HSI_KER_CK    =    RCC_D2CCIP1R_SPI45SEL_2
};
enum RCCD2SPDIFClkSrc
{
    RCC_D2SPDIF_CLK_PLL1_Q_CK     =    0,
    RCC_D2SPDIF_CLK_PLL2_R_CK     =    RCC_D2CCIP1R_SPDIFSEL_0,
    RCC_D2SPDIF_CLK_PLL3_R_CK     =    RCC_D2CCIP1R_SPDIFSEL_1
};
enum RCCD2DFSDM1ClkSrc
{
    RCC_D2DFSDM1_CLK_PCLK2,
    RCC_D2DFSDM1_CLK_SYS_CK
};
enum RCCD2FDCANClkSrc
{
    RCC_D2FDCAN_CLK_HSE_CK  =    0,
    RCC_D2FDCAN_CLK_PLL1_Q_CK  =   RCC_D2CCIP1R_FDCANSEL_0,
    RCC_D2FDCAN_CLK_PLL2_Q_CK  =   RCC_D2CCIP1R_FDCANSEL_1
};
enum RCCD2SWPClkSrc
{
    RCC_D2SWP_CLK_PCLK,
    RCC_D2SWP_CLK_HSI_KER_CK
};
enum RCCD2USART234578ClkSrc
{
    RCC_D2_USART234578_CLK_PCLK1       =   0,
    RCC_D2_USART234578_CLK_PLL2_Q_CK    =        RCC_D2CCIP2R_USART28SEL_0,
    RCC_D2_USART234578_CLK_PLL3_Q_CK    =       RCC_D2CCIP2R_USART28SEL_1,
    RCC_D2_USART234578_CLK_CSI_KER_CK  =        RCC_D2CCIP2R_USART28SEL_2
};
enum RCCD2USART16ClkSrc
{
    RCC_D2_USART16_CLK_PCLK2           =    0,
    RCC_D2_USART16_CLK_PLL2_Q_CK        =    RCC_D2CCIP2R_USART16SEL_0, 
    RCC_D2_USART16_CLK_PLL3_Q_CK        =    RCC_D2CCIP2R_USART16SEL_1,
    RCC_D2_USART16_CLK_CSI_KER_CK      =    RCC_D2CCIP2R_USART16SEL_2
};
enum RCCD2RNGClkSrc
{   
    RCC_D2_RNG_CKL_HSI_48_CK     =   0,
    RCC_D2_RNG_CKL_PLL1_Q_CK     =   RCC_D2CCIP2R_RNGSEL_0,
    RCC_D2_RNG_CKL_LSE_CK        =   RCC_D2CCIP2R_RNGSEL_1
};
enum RCCD2I2C123ClkSrc
{
    RCC_D2_I2C123_CLK_PCLK1    =    0,
    RCC_D2_I2C123_CLK_PLL3_R_CK =   RCC_D2CCIP2R_I2C123SEL_0,
    RCC_D2_I2C123_CLK_HSI_KER_CK =   RCC_D2CCIP2R_I2C123SEL_1
};
enum RCCD2USBClkSrc
{
    RCC_D2_USB_CLK_DISABLE  = 0,
    RCC_D2_USB_CLK_PLL1_Q_CK  =  RCC_D2CCIP2R_USBSEL_0,
    RCC_D2_USB_CLK_PLL3_Q_CK  =  RCC_D2CCIP2R_USBSEL_1,
    RCC_D2_USB_CLK_HSI_48_CK  =  RCC_D2CCIP2R_USBSEL
};
enum RCCD2LPTIM1ClkSrc
{   
    RCC_D2_LPTIM1_CLK_PCLK1  =  0,
    RCC_D2_LPTIM1_CLK_PLL2_P_CK = RCC_D2CCIP2R_LPTIM1SEL_0,
    RCC_D2_LPTIM1_CLK_PLL3_R_CK = RCC_D2CCIP2R_LPTIM1SEL_1,
    RCC_D2_LPTIM1_CLK_LSI_CK    = RCC_D2CCIP2R_LPTIM1SEL_2
};
enum RCCD3LPUART1ClkSrc 
{
    RCC_D3_LPUART1_CLK_PCLK_D3      =    0,
    RCC_D3_LPUART1_CLK_PLL2_Q_CK    =    RCC_D3CCIPR_LPUART1SEL_0,
    RCC_D3_LPUART1_CLK_PLL3_Q_CK    =    RCC_D3CCIPR_LPUART1SEL_1,
    RCC_D3_LPUART1_CLK_CSI_KER_CK   =    RCC_D3CCIPR_LPUART1SEL_2
};
enum RCCD3I2C4ClkSrc
{
    RCC_D3_I2C4_CLK_PCLK4       =    0,
    RCC_D3_I2C4_CLK_PLL3_R_CK   =   RCC_D3CCIPR_I2C4SEL_0,
    RCC_D3_I2C4_CLK_HSI_KER_CK  =   RCC_D3CCIPR_I2C4SEL_1,
    RCC_D3_I2C4_CLK_CSI_KER_CK  =   RCC_D3CCIPR_I2C4SEL
};
enum RCCD3LPTIM2ClkSrc
{   
    RCC_D3_LPTIM2_CLK_PCLK4        =    0,
    RCC_D3_LPTIM2_CLK_PLL2_P_CK    =    RCC_D3CCIPR_LPTIM2SEL_0,
    RCC_D3_LPTIM2_CLK_PLL3_R_CK    =    RCC_D3CCIPR_LPTIM2SEL_1,
    RCC_D3_LPTIM2_CLK_LSI_CK       =    RCC_D3CCIPR_LPTIM2SEL_2
};
enum RCCD3LPTIM345ClkSrc
{   
    RCC_D3_LPTIM345_CLK_PCLK4        =    0,
    RCC_D3_LPTIM345_CLK_PLL2_P_CK    =    RCC_D3CCIPR_LPTIM345SEL_0,
    RCC_D3_LPTIM345_CLK_PLL3_R_CK    =    RCC_D3CCIPR_LPTIM345SEL_1,
    RCC_D3_LPTIM345_CLK_LSI_CK       =    RCC_D3CCIPR_LPTIM345SEL_2
};
enum RCCD3ADCClkSrc
{   
    RCC_D3_ADC_CLK_PLL2_P_CK   =   0,
    RCC_D3_ADC_CLK_PLL3_R_CK   =   RCC_D3CCIPR_ADCSEL_0,
    RCC_D3_ADC_CLK_PER_CK      =   RCC_D3CCIPR_ADCSEL_1
};
enum RCCD3SAI4AClkSrc
{
    RCC_D3_SAI4A_CLK_PLL1_Q_CK   =   0,
    RCC_D3_SAI4A_CLK_PLL2_P_CK   =   RCC_D3CCIPR_SAI4ASEL_0,
    RCC_D3_SAI4A_CLK_PLL3_P_CK   =   RCC_D3CCIPR_SAI4ASEL_1,
    RCC_D3_SAI4A_CLK_PER_CK      =   RCC_D3CCIPR_SAI4ASEL_2
};
enum RCCD3SAI4BClkSrc
{
    RCC_D3_SAI4B_CLK_PLL1_Q_CK   =   0,
    RCC_D3_SAI4B_CLK_PLL2_P_CK   =   RCC_D3CCIPR_SAI4BSEL_0,
    RCC_D3_SAI4B_CLK_PLL3_P_CK   =   RCC_D3CCIPR_SAI4BSEL_1,
    RCC_D3_SAI4B_CLK_PER_CK      =   RCC_D3CCIPR_SAI4BSEL_2
};
enum RCCD3SPI6ClkSrc
{
    RCC_D3SPI6_CLK_PCLK4   =   0,
    RCC_D3SPI6_CLK_PLL2_Q_CK   =   RCC_D3CCIPR_SPI6SEL_0,
    RCC_D3SPI6_CLK_PLL3_Q_CK   =   RCC_D3CCIPR_SPI6SEL_1,
    RCC_D3SPI6_CLK_CSI_KER_CK    =   RCC_D3CCIPR_SPI6SEL_2
};
enum RCCLSEOscDriverCap
{
    RCC_BDCR_LSE_OSC_DRV_CAP_LOWEST     =     0, 
    RCC_BDCR_LSE_OSC_DRV_CAP_MEDIUM_LOW = RCC_BDCR_LSEDRV_0,
    RCC_BDCR_LSE_OSC_DRV_CAP_MEDIUM_HIGH = RCC_BDCR_LSEDRV_1,
    RCC_BDCR_LSE_OSC_DRV_CAP_MEDIUM_HIGHEST = RCC_BDCR_LSEDRV 
};
enum RCCRTCClkSrc
{
    RCC_RTC_CLK_SRC_NONE    =   0,
    RCC_RTC_CLK_SRC_LSE     =   RCC_BDCR_RTCSEL_0,
    RCC_RTC_CLK_SRC_LSI     =   RCC_BDCR_RTCSEL_1,
    RCC_RTC_CLK_SRC_HSE     =   RCC_BDCR_RTCSEL
};
enum RCCPLLCLKType
{
    RCC_PLL1_CLK_FREQ_P,
    RCC_PLL1_CLK_FREQ_Q,
    RCC_PLL1_CLK_FREQ_R,
    RCC_PLL2_CLK_FREQ_P,
    RCC_PLL2_CLK_FREQ_Q,
    RCC_PLL2_CLK_FREQ_R,
    RCC_PLL3_CLK_FREQ_P,
    RCC_PLL3_CLK_FREQ_Q,
    RCC_PLL3_CLK_FREQ_R,
};
class RCCControl
{
public:
    static RCCControl* getInstance()
    {
        static RCCControl rcc_;
        return &rcc_;
    } 
    RCCSysClkSrcSta getSysClkSrcSta()
    {
        return ((RCCSysClkSrcSta)(RCC->CFGR & RCC_CFGR_SWS));
    }
    void selectSysClkSrc(RCCSysClkSrc src)
    {
        MODIFY_REG(RCC->CFGR, RCC_CFGR_SW, src);
    }
    bool selectSysClkAfterWkupFromSysStop(bool bSelectCSI)
    {
        if((READ_BIT(RCC->CR, RCC_CR_CSSHSEON) && getSysClkSrcSta() == RCC_SYS_CLK_HSE) || READ_BIT(RCC->CFGR, RCC_SYS_CLK_SRC_HSE))
        {
            return false;
        }
        bSelectCSI ? SET_BIT(RCC->CFGR, RCC_CFGR_STOPWUCK) : CLEAR_BIT(RCC->CFGR, RCC_CFGR_STOPWUCK);
        return true;
    }
    void selectKernelClkAfterWkupFromSysStop(bool bSelectCSI)
    {
        bSelectCSI ? SET_BIT(RCC->CFGR, RCC_CFGR_STOPKERWUCK) : CLEAR_BIT(RCC->CFGR, RCC_CFGR_STOPKERWUCK);
    }
    void hseDivisionForRtc(RCCHseDivForRtc div)
    {
        MODIFY_REG(RCC->CFGR, RCC_CFGR_RTCPRE, div);
    }
    void selectHighResolutionTimerClkPreScaler(bool bselectRccCck/*CUP clock*/)
    {
        bselectRccCck ?  SET_BIT(RCC->CFGR, RCC_CFGR_HRTIMSEL) : CLEAR_BIT(RCC->CFGR, RCC_CFGR_HRTIMSEL);
    }
    void selectTimersClkPreScaler(bool b4xclock)
    {
        b4xclock ?  SET_BIT(RCC->CFGR, RCC_CFGR_TIMPRE) : CLEAR_BIT(RCC->CFGR, RCC_CFGR_TIMPRE);
    }
    void setMco1PreScaler(RCCMco1PreScaler preScaler)
    {
        MODIFY_REG(RCC->CFGR, RCC_CFGR_MCO1PRE, preScaler);
    }
    void selectMco1ClkSrc(RCCMco1ClkSrc src)
    {
        MODIFY_REG(RCC->CFGR, RCC_CFGR_MCO1, src);
    }
    void setMco2PreScaler(RCCMco2PreScaler preScaler)
    {
        MODIFY_REG(RCC->CFGR, RCC_CFGR_MCO2PRE, preScaler);
    }
    void selectMco2ClkSrc(RCCMco2ClkSrc src)
    {
        MODIFY_REG(RCC->CFGR, RCC_CFGR_MCO2,  src);
    }
    void setD1HPREPAHBreScaler(RCCD1HPREAHBPrescaler div)
    {
        MODIFY_REG(RCC->D1CFGR, RCC_D1CFGR_HPRE, div);
    }
    void setD1PPREAPB3PreScaler(RCCD1PPREAPB3Prescaler div)
    {
        MODIFY_REG(RCC->D1CFGR, RCC_D1CFGR_D1PPRE, div);
    }
    void setD1CPREPreScaler(RCCD1CPREPrescaler div)
    {
        MODIFY_REG(RCC->D1CFGR, RCC_D1CFGR_D1CPRE, div);
    }
    void setD2PPRE1APB1PreScaler(RCCD2PPRE1APB1Prescaler div)
    {
        MODIFY_REG(RCC->D2CFGR, RCC_D2CFGR_D2PPRE1, div);
    }
    void setD2PPRE2APB2PreScaler(RCCD2PPRE2APB2Prescaler div)
    {
        MODIFY_REG(RCC->D2CFGR, RCC_D2CFGR_D2PPRE2, div);
    }
    void setD3PPREAPB4PreScaler(RCCD3PPREAPB4Prescaler div)
    {
        MODIFY_REG(RCC->D3CFGR, RCC_D3CFGR_D3PPRE, div);
    }
    bool selectPLLSrc(RCCPLLClkSrc src)
    {
        if(READ_BIT(RCC->CR, RCC_CR_PLL1ON) || READ_BIT(RCC->CR, RCC_CR_PLL2ON) || READ_BIT(RCC->CR, RCC_CR_PLL3ON))
        {
            return false;
        }
        MODIFY_REG(RCC->PLLCKSELR, RCC_PLLCKSELR_PLLSRC, src);
        return true;
    }
    RCCPLLClkSrc getPLLSrc()
    {
        return (RCCPLLClkSrc)(READ_BIT(RCC->PLLCKSELR, RCC_PLLCKSELR_PLLSRC));
    }
    bool setPLL1DIVM(uint32_t div)
    {
        if(READ_BIT(RCC->CR, RCC_CR_PLL1ON))
        {
            return false;
        }
        MODIFY_REG(RCC->PLLCKSELR, RCC_PLLCKSELR_DIVM1, (RCC_PLLCKSELR_DIVM1_Msk & (div << RCC_PLLCKSELR_DIVM1_Pos)));
        return true;
    }
    bool setPLL2DIVM(uint32_t div)
    {
        if(READ_BIT(RCC->CR, RCC_CR_PLL2ON))
        {
            return false;
        }
        MODIFY_REG(RCC->PLLCKSELR, RCC_PLLCKSELR_DIVM2, (RCC_PLLCKSELR_DIVM2_Msk & (div << RCC_PLLCKSELR_DIVM2_Pos)));
        return true;
    }
    bool setPLL3DIVM(uint32_t div)
    {
        if(READ_BIT(RCC->CR, RCC_CR_PLL3ON))
        {
            return false;
        }
        MODIFY_REG(RCC->PLLCKSELR, RCC_PLLCKSELR_DIVM3, (RCC_PLLCKSELR_DIVM3_Msk & (div << RCC_PLLCKSELR_DIVM3_Pos)));
        return true;
    }
    bool setPLL1VOCRange(RCCPLL1VOCRange voct)
    {
        if(READ_BIT(RCC->CR, RCC_CR_PLL1ON))
        {
            return false;
        }
        if(voct == RCC_PLL1_VOC_TYPE_192MHZ_TO_836MHZ)
        {
            CLEAR_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLL1VCOSEL);
        }
        else if(voct == RCC_PLL1_VOC_TYPE_150MHZ_TO_420MHZ)
        {
            SET_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLL1VCOSEL);
        }
        return true;
    }
    bool setPLL1InputFreqRange(RCCPLL1InputFreqRange range)
    {
        if(READ_BIT(RCC->CR, RCC_CR_PLL1ON))
        {
            return false;
        }
        MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLL1RGE,  range);
        return true;
    }
    bool setPLL2VOCRange(RCCPLL2VOCRange voct)
    {
        if(READ_BIT(RCC->CR, RCC_CR_PLL2ON))
        {
            return false;
        }
        if(voct == RCC_PLL2_VOC_TYPE_192MHZ_TO_836MHZ)
        {
            CLEAR_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLL2VCOSEL);
        }
        else if(voct == RCC_PLL2_VOC_TYPE_150MHZ_TO_420MHZ)
        {
            SET_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLL2VCOSEL);
        }
        return true;
    }
    bool setPLL2InputFreqRange(RCCPLL2InputFreqRange range)
    {
        if(READ_BIT(RCC->CR, RCC_CR_PLL2ON))
        {
            return false;
        }
        MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLL2RGE,  range);
        return true;
    }
    bool setPLL3VOCRange(RCCPLL3VOCRange voct)
    {
        if(READ_BIT(RCC->CR, RCC_CR_PLL3ON))
        {
            return false;
        }
        if(voct == RCC_PLL3_VOC_TYPE_192MHZ_TO_836MHZ)
        {
            CLEAR_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLL3VCOSEL);
        }
        else if(voct == RCC_PLL3_VOC_TYPE_150MHZ_TO_420MHZ)
        {
            SET_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLL3VCOSEL);
        }
        return true;
    }
    bool setPLL3InputFreqRange(RCCPLL3InputFreqRange range)
    {
        if(READ_BIT(RCC->CR, RCC_CR_PLL3ON))
        {
            return false;
        }
        MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLL3RGE,  range);
        return true;
    }
    bool enablePLL1DIVPClk(bool benable)
    {
        if(READ_BIT(RCC->CR, RCC_CR_PLL1ON) || READ_BIT(RCC->CR, RCC_CR_PLL1RDY))
        {
            return false;
        }
        benable ? SET_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVP1EN) : CLEAR_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVP1EN);
        return true;
    }
    bool enablePLL1DIVQClk(bool benable)
    {
        if(READ_BIT(RCC->CR, RCC_CR_PLL1ON) || READ_BIT(RCC->CR, RCC_CR_PLL1RDY))
        {
            return false;
        }
        benable ? SET_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVQ1EN) : CLEAR_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVQ1EN);
        return true;
    }
    bool enablePLL1DIVRClk(bool benable)
    {
        if(READ_BIT(RCC->CR, RCC_CR_PLL1ON) || READ_BIT(RCC->CR, RCC_CR_PLL1RDY))
        {
            return false;
        }
        benable ? SET_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVR1EN) : CLEAR_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVR1EN);
        return true;
    }
    bool enablePLL2DIVPClk(bool benable)
    {
        if(READ_BIT(RCC->CR, RCC_CR_PLL2ON) || READ_BIT(RCC->CR, RCC_CR_PLL2RDY))
        {
            return false;
        }
        benable ? SET_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVP2EN) : CLEAR_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVP2EN);
        return true;
    }
    bool enablePLL2DIVQClk(bool benable)
    {
        if(READ_BIT(RCC->CR, RCC_CR_PLL2ON) || READ_BIT(RCC->CR, RCC_CR_PLL2RDY))
        {
            return false;
        }
        benable ? SET_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVQ2EN) : CLEAR_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVQ2EN);
        return true;
    }
    bool enablePLL2DIVRClk(bool benable)
    {
        if(READ_BIT(RCC->CR, RCC_CR_PLL2ON) || READ_BIT(RCC->CR, RCC_CR_PLL2RDY))
        {
            return false;
        }
        benable ? SET_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVR2EN) : CLEAR_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVR2EN);
        return true;
    }
    bool enablePLL3DIVPClk(bool benable)
    {
        if(READ_BIT(RCC->CR, RCC_CR_PLL3ON) || READ_BIT(RCC->CR, RCC_CR_PLL3RDY))
        {
            return false;
        }
        benable ? SET_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVP3EN) : CLEAR_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVP3EN);
        return true;
    }
    bool enablePLL3DIVQClk(bool benable)
    {
        if(READ_BIT(RCC->CR, RCC_CR_PLL3ON) || READ_BIT(RCC->CR, RCC_CR_PLL3RDY))
        {
            return false;
        }
        benable ? SET_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVQ3EN) : CLEAR_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVQ3EN);
        return true;
    }
    bool enablePLL3DIVRClk(bool benable)
    {
        if(READ_BIT(RCC->CR, RCC_CR_PLL3ON) || READ_BIT(RCC->CR, RCC_CR_PLL3RDY))
        {
            return false;
        }
        benable ? SET_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVR3EN) : CLEAR_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVR3EN);
        return true;
    }
    bool setPLL1DIVN(uint32_t val)
    {
        if(READ_BIT(RCC->CR, RCC_CR_PLL1ON) || READ_BIT(RCC->CR, RCC_CR_PLL1RDY))
        {
            return false;
        }
        MODIFY_REG(RCC->PLL1DIVR, RCC_PLL1DIVR_N1, ((val << RCC_PLL1DIVR_N1_Pos) & RCC_PLL1DIVR_N1_Msk));
        return true;
    }
    bool setPLL1DIVP(uint32_t val)
    {
        if(READ_BIT(RCC->CR, RCC_CR_PLL1ON) || READ_BIT(RCC->CR, RCC_CR_PLL1RDY))
        {
            return false;
        }
        MODIFY_REG(RCC->PLL1DIVR, RCC_PLL1DIVR_P1, ((val << RCC_PLL1DIVR_P1_Pos) & RCC_PLL1DIVR_P1_Msk));
        return true;
    }
    bool setPLL1DIVQ(uint32_t val)
    {
        if(READ_BIT(RCC->CR, RCC_CR_PLL1ON) || READ_BIT(RCC->CR, RCC_CR_PLL1RDY))
        {
            return false;
        }
        MODIFY_REG(RCC->PLL1DIVR, RCC_PLL1DIVR_Q1, ((val << RCC_PLL1DIVR_Q1_Pos) & RCC_PLL1DIVR_Q1_Msk));
        return true;
    }
    bool setPLL1DIVR(uint32_t val)
    {
        if(READ_BIT(RCC->CR, RCC_CR_PLL1ON) || READ_BIT(RCC->CR, RCC_CR_PLL1RDY))
        {
            return false;
        }
        MODIFY_REG(RCC->PLL1DIVR, RCC_PLL1DIVR_R1, ((val << RCC_PLL1DIVR_R1_Pos) & RCC_PLL1DIVR_R1_Msk));
        return true;
    }

    bool setPLL2DIVN(uint32_t val)
    {
        if(READ_BIT(RCC->CR, RCC_CR_PLL2ON) || READ_BIT(RCC->CR, RCC_CR_PLL2RDY))
        {
            return false;
        }
        MODIFY_REG(RCC->PLL2DIVR, RCC_PLL2DIVR_N2, ((val << RCC_PLL2DIVR_N2_Pos) & RCC_PLL2DIVR_N2_Msk));
        return true;
    }
    bool setPLL2DIVP(uint32_t val)
    {
        if(READ_BIT(RCC->CR, RCC_CR_PLL2ON) || READ_BIT(RCC->CR, RCC_CR_PLL2RDY))
        {
            return false;
        }
        MODIFY_REG(RCC->PLL2DIVR, RCC_PLL2DIVR_P2, ((val << RCC_PLL2DIVR_P2_Pos) & RCC_PLL2DIVR_P2_Msk));
        return true;
    }
    bool setPLL2DIVQ(uint32_t val)
    {
        if(READ_BIT(RCC->CR, RCC_CR_PLL2ON) || READ_BIT(RCC->CR, RCC_CR_PLL2RDY))
        {
            return false;
        }
        MODIFY_REG(RCC->PLL2DIVR, RCC_PLL2DIVR_Q2, ((val << RCC_PLL2DIVR_Q2_Pos) & RCC_PLL2DIVR_Q2_Msk));
        return true;
    }
    bool setPLL2DIVR(uint32_t val)
    {
        if(READ_BIT(RCC->CR, RCC_CR_PLL2ON) || READ_BIT(RCC->CR, RCC_CR_PLL2RDY))
        {
            return false;
        }
        MODIFY_REG(RCC->PLL2DIVR, RCC_PLL2DIVR_R2, ((val << RCC_PLL2DIVR_R2_Pos) & RCC_PLL2DIVR_R2_Msk));
        return true;
    }
    bool setPLL3DIVN(uint32_t val)
    {
        if(READ_BIT(RCC->CR, RCC_CR_PLL3ON) || READ_BIT(RCC->CR, RCC_CR_PLL3RDY))
        {
            return false;
        }
        MODIFY_REG(RCC->PLL3DIVR, RCC_PLL3DIVR_N3, ((val << RCC_PLL3DIVR_N3_Pos) & RCC_PLL3DIVR_N3_Msk));
        return true;
    }
    bool setPLL3DIVP(uint32_t val)
    {
        if(READ_BIT(RCC->CR, RCC_CR_PLL3ON) || READ_BIT(RCC->CR, RCC_CR_PLL3RDY))
        {
            return false;
        }
        MODIFY_REG(RCC->PLL3DIVR, RCC_PLL3DIVR_P3, ((val << RCC_PLL3DIVR_P3_Pos) & RCC_PLL3DIVR_P3_Msk));
        return true;
    }
    bool setPLL3DIVQ(uint32_t val)
    {
        if(READ_BIT(RCC->CR, RCC_CR_PLL3ON) || READ_BIT(RCC->CR, RCC_CR_PLL3RDY))
        {
            return false;
        }
        MODIFY_REG(RCC->PLL3DIVR, RCC_PLL3DIVR_Q3, ((val << RCC_PLL3DIVR_Q3_Pos) & RCC_PLL3DIVR_Q3_Msk));
        return true;
    }
    bool setPLL3DIVR(uint32_t val)
    {
        if(READ_BIT(RCC->CR, RCC_CR_PLL3ON) || READ_BIT(RCC->CR, RCC_CR_PLL3RDY))
        {
            return false;
        }
        MODIFY_REG(RCC->PLL3DIVR, RCC_PLL3DIVR_R3, ((val << RCC_PLL3DIVR_R3_Pos) & RCC_PLL3DIVR_R3_Msk));
        return true;
    }
    bool enableHsi(bool benable)
    {
        if(!benable && getSysClkSrcSta() == RCC_SYS_CLK_HSI)
        {
            //hsi system clk, can not be disable
            return false;
        }
        benable ? SET_BIT(RCC->CR, RCC_CR_HSION) : CLEAR_BIT(RCC->CR, RCC_CR_HSION);
        return true;
    }
    void enableHisInStopMode(bool benable)
    {
        benable ? SET_BIT(RCC->CR, RCC_CR_HSIKERON) : CLEAR_BIT(RCC->CR, RCC_CR_HSIKERON);
    }
    bool isHsiReady()
    {
        return READ_BIT(RCC->CR, RCC_CR_HSIRDY) == RCC_CR_HSIRDY ? true : false;
    }
    void hsiDiv(RCCHsiDiv div)
    {
        MODIFY_REG(RCC->CR, RCC_CR_HSIDIV, div);
    }
    bool bHsiDivUpdate()
    {
        return READ_BIT(RCC->CR, RCC_CR_HSIDIVF) ? true : false;
    }
    bool enableCsi(bool benable)
    {
        if(!benable && getSysClkSrcSta() == RCC_SYS_CLK_CSI)
        {
            //csi system clk, can not be disable
            return false;
        }
        benable ? SET_BIT(RCC->CR, RCC_CR_CSION) : CLEAR_BIT(RCC->CR, RCC_CR_CSION);
        return true;
    }
    bool isCsiReady()
    {
        return READ_BIT(RCC->CR, RCC_CR_CSIRDY) ==  RCC_CR_CSIRDY ? true : false;
    }
    void enableCisInStopMode(bool benable)
    {
        benable ? SET_BIT(RCC->CR, RCC_CR_CSIKERON) : CLEAR_BIT(RCC->CR, RCC_CR_CSIKERON);
    }
    void enableHsi48(bool benable)
    {
        benable ? SET_BIT(RCC->CR, RCC_CR_HSI48ON) : CLEAR_BIT(RCC->CR, RCC_CR_HSI48ON);
    }
    bool isHsi48Ready()
    {
        return READ_BIT(RCC->CR, RCC_CR_HSI48RDY) == RCC_CR_HSI48RDY ? true : false;
    }
    bool isD1clkReady()
    {
        return READ_BIT(RCC->CR, RCC_CR_D1CKRDY) == RCC_CR_D1CKRDY ? true : false;
    }
    bool isD2clkReady()
    {
        return READ_BIT(RCC->CR, RCC_CR_D2CKRDY) == RCC_CR_D2CKRDY ? true : false;
    }
    bool enableHse(bool benable)
    {
        if(!benable && getSysClkSrcSta() == RCC_SYS_CLK_HSE)
        {
            //hse system clk, can not be disable
            return false;
        }
        benable ? SET_BIT(RCC->CR, RCC_CR_HSEON) : CLEAR_BIT(RCC->CR, RCC_CR_HSEON);
        return true;
    }
    bool isHseReady()
    {
        return READ_BIT(RCC->CR, RCC_CR_HSERDY) == RCC_CR_HSERDY ? true : false;
    }
    bool hseBypass(bool bbypass)
    {
        if(getSysClkSrcSta() == RCC_SYS_CLK_HSE && READ_BIT(RCC->CR, RCC_CR_HSEON))
        {
            return false;
        }
        bbypass ? SET_BIT(RCC->CR, RCC_CR_HSERDY) : CLEAR_BIT(RCC->CR, RCC_CR_HSERDY);
        return true;
    }
    void enableHseSecuritySystem(bool benable)
    {
        benable ? SET_BIT(RCC->CR, RCC_CR_CSSHSEON) : CLEAR_BIT(RCC->CR, RCC_CR_CSSHSEON);
    }
    bool enablePLL1(bool benable)
    {
        if(!benable && getSysClkSrcSta() == RCC_SYS_CLK_PLL1)
        {
            return false;
        }
        benable ? SET_BIT(RCC->CR, RCC_CR_PLL1ON) : CLEAR_BIT(RCC->CR, RCC_CR_PLL1ON);
        return true;
    }
    bool isPLL1Ready()
    {
        return READ_BIT(RCC->CR, RCC_CR_PLL1RDY) == RCC_CR_PLL1RDY ? true : false;
    }
    bool enablePLL2(bool benable)
    {
        benable ? SET_BIT(RCC->CR, RCC_CR_PLL2ON) : CLEAR_BIT(RCC->CR, RCC_CR_PLL1ON);
        return true;
    }
    bool isPLL2Ready()
    {
        return READ_BIT(RCC->CR, RCC_CR_PLL2RDY) == RCC_CR_PLL2RDY ? true : false;
    }
    bool enablePLL3(bool benable)
    {
        benable ? SET_BIT(RCC->CR, RCC_CR_PLL3ON) : CLEAR_BIT(RCC->CR, RCC_CR_PLL1ON);
        return true;
    }
    bool isPLL3Ready()
    {
        return READ_BIT(RCC->CR, RCC_CR_PLL3RDY) == RCC_CR_PLL3RDY ? true : false;
    }
    //D1
    void selectFMCKernelClkSrcFromD1(RCCD1FMCClkSrc src)
    {
        MODIFY_REG(RCC->D1CCIPR, RCC_D1CCIPR_FMCSEL, src);
    }
    void selectQSPIKernelClkSrcFromD1(RCCD1QSPIClkSrc src)
    {
        MODIFY_REG(RCC->D1CCIPR, RCC_D1CCIPR_QSPISEL, src);
    }
    void selectSDMMCClkSrcFromD1(RCCD1SDMMCClkSrc src)
    {
        if(src == RCC_SDMMC_SELETC_PLL1_Q_CK)
        {
            CLEAR_BIT(RCC->D1CCIPR, RCC_D1CCIPR_SDMMCSEL);
        }
        else if(src == RCC_SDMMC_SELETC_PLL2_R_CK)
        {
            SET_BIT(RCC->D1CCIPR, RCC_D1CCIPR_SDMMCSEL);
        }
    }
    void selectPerCkSrc(RCCD1PERCKSrc src)
    {
        MODIFY_REG(RCC->D1CCIPR, RCC_D1CCIPR_CKPERSEL, src);
    }
    //D2
    void selectSAI1AndDFSDM1KernelAckSrc(RCCD2SAI1AndDFSDM1AclkSrc src)
    {
        MODIFY_REG(RCC->D2CCIP1R, RCC_D2CCIP1R_SAI1SEL, src);
    }
    void selectSAI23ClkSrc(RCCD2SAI23ClkkSrc src)
    {
        MODIFY_REG(RCC->D2CCIP1R, RCC_D2CCIP1R_SAI23SEL, src);
    }
    void selectSPIAndI2S123KernelClkSrc(RCCD2SPIAndI2S123ClkSrc src)
    {
        MODIFY_REG(RCC->D2CCIP1R, RCC_D2CCIP1R_SPI123SEL, src);
    }
    void selectSPI45KernelClkSrc(RCCD2SPI45ClkSrc src)
    {
        MODIFY_REG(RCC->D2CCIP1R, RCC_D2CCIP1R_SPI45SEL, src);
    }
    void selectSPDIFRXKernelClkSrc(RCCD2SPDIFClkSrc src)
    {
        MODIFY_REG(RCC->D2CCIP1R, RCC_D2CCIP1R_SPDIFSEL, src);
    }
    void selectDFSDM1KernelClkSrc(RCCD2DFSDM1ClkSrc src)
    {
        if(src == RCC_D2DFSDM1_CLK_PCLK2)
        {
            CLEAR_BIT(RCC->D2CCIP1R, RCC_D2CCIP1R_DFSDM1SEL);
        }
        else
        {
            SET_BIT(RCC->D2CCIP1R, RCC_D2CCIP1R_DFSDM1SEL);
        }
    }
    void selectFDCANKernelClkSrc(RCCD2FDCANClkSrc src)
    {
        MODIFY_REG(RCC->D2CCIP1R, RCC_D2CCIP1R_FDCANSEL, src);
    }
    void selectSWPMIKernelClkSrc(RCCD2SWPClkSrc src)
    {
        if(src == RCC_D2SWP_CLK_PCLK)
        {
            CLEAR_BIT(RCC->D2CCIP1R, RCC_D2CCIP1R_SWPSEL);
        }
        else
        {
            SET_BIT(RCC->D2CCIP1R, RCC_D2CCIP1R_SWPSEL);
        }
    }
    void selectUSART234578KernelClkSrc(RCCD2USART234578ClkSrc src)
    {
        MODIFY_REG(RCC->D2CCIP2R, RCC_D2CCIP2R_USART28SEL, src);
    }
    RCCD2USART234578ClkSrc getUSART234578KernelClkSrc()
    {
        return (RCCD2USART234578ClkSrc)(READ_BIT(RCC->D2CCIP2R, RCC_D2CCIP2R_USART28SEL));
    }
    void selectUSART16KernelClkSrc(RCCD2USART16ClkSrc src)
    {
        MODIFY_REG(RCC->D2CCIP2R, RCC_D2CCIP2R_USART16SEL, src);
    }
    RCCD2USART16ClkSrc getUSART16KernelClkSrc()
    {
        return (RCCD2USART16ClkSrc)(READ_BIT(RCC->D2CCIP2R, RCC_D2CCIP2R_USART16SEL));
    }
    void selectRNGKernelClkSrc(RCCD2RNGClkSrc src)
    {
        MODIFY_REG(RCC->D2CCIP2R, RCC_D2CCIP2R_RNGSEL, src);
    }
    void selectI2C123KernelClkSrc(RCCD2I2C123ClkSrc src)
    {
        MODIFY_REG(RCC->D2CCIP2R, RCC_D2CCIP2R_I2C123SEL, src);
    }
    void selectUSBKernelClkSrc(RCCD2USBClkSrc src)
    {
        MODIFY_REG(RCC->D2CCIP2R, RCC_D2CCIP2R_USBSEL, src);
    }
    void selectLPTIM1KernelClkSrc(RCCD2LPTIM1ClkSrc src)
    {
        MODIFY_REG(RCC->D2CCIP2R, RCC_D2CCIP2R_LPTIM1SEL, src);
    }
    void selectLPUART1KernelClkSrc(RCCD3LPUART1ClkSrc src)
    {
        MODIFY_REG(RCC->D3CCIPR, RCC_D3CCIPR_LPUART1SEL, src);
    }
    void selectI2C4KernelClkSrc(RCCD3I2C4ClkSrc src)
    {
        MODIFY_REG(RCC->D3CCIPR, RCC_D3CCIPR_I2C4SEL, src);
    }
    void selectLPTIM2KernelClkSrc(RCCD3LPTIM2ClkSrc src)
    {
        MODIFY_REG(RCC->D3CCIPR, RCC_D3CCIPR_LPTIM2SEL, src);
    }
    void selectLPTIM2KernelClkSrc(RCCD3LPTIM345ClkSrc src)
    {
        MODIFY_REG(RCC->D3CCIPR, RCC_D3CCIPR_LPTIM345SEL, src);
    }
    void selectADCKernelClkSrc(RCCD3ADCClkSrc src)
    {
        MODIFY_REG(RCC->D3CCIPR, RCC_D3CCIPR_ADCSEL, src);
    }
    void selectSAI4AKernelClkSrc(RCCD3SAI4AClkSrc src)
    {
        MODIFY_REG(RCC->D3CCIPR, RCC_D3CCIPR_SAI4ASEL, src);
    }
    void selectSAI4BKernelClkSrc(RCCD3SAI4BClkSrc src)
    {
        MODIFY_REG(RCC->D3CCIPR, RCC_D3CCIPR_SAI4BSEL, src);
    }
    void selectSPI6KernelClkSrc(RCCD3SPI6ClkSrc src)
    {
        MODIFY_REG(RCC->D3CCIPR, RCC_D3CCIPR_SPI6SEL, src);
    }

    void enableLSIReadyIsr(bool benable)
    {
        benable ? SET_BIT(RCC->CIER, RCC_CIER_LSIRDYIE) : CLEAR_BIT(RCC->CIER, RCC_CIER_LSIRDYIE);
    }
    void enableLSEReadyIsr(bool benable)
    {
        benable ? SET_BIT(RCC->CIER, RCC_CIER_LSERDYIE) : CLEAR_BIT(RCC->CIER, RCC_CIER_LSERDYIE);
    }
    void enableHSIReadyIsr(bool benable)
    {
        benable ? SET_BIT(RCC->CIER, RCC_CIER_HSIRDYIE) : CLEAR_BIT(RCC->CIER, RCC_CIER_HSIRDYIE);
    }
    void enableHSEReadyIsr(bool benable)
    {
        benable ? SET_BIT(RCC->CIER, RCC_CIER_HSERDYIE) : CLEAR_BIT(RCC->CIER, RCC_CIER_HSERDYIE);
    }
    void enableCSIReadyIsr(bool benable)
    {
        benable ? SET_BIT(RCC->CIER, RCC_CIER_CSIRDYIE) : CLEAR_BIT(RCC->CIER, RCC_CIER_CSIRDYIE);
    }
    void enableHSI48ReadyIsr(bool benable)
    {
        benable ? SET_BIT(RCC->CIER, RCC_CIER_HSI48RDYIE) : CLEAR_BIT(RCC->CIER, RCC_CIER_HSI48RDYIE);
    }
    void enablePLL1ReadyIsr(bool benable)
    {
        benable ? SET_BIT(RCC->CIER, RCC_CIER_PLL1RDYIE) : CLEAR_BIT(RCC->CIER, RCC_CIER_PLL1RDYIE);
    }
    void enablePLL2ReadyIsr(bool benable)
    {
        benable ? SET_BIT(RCC->CIER, RCC_CIER_PLL2RDYIE) : CLEAR_BIT(RCC->CIER, RCC_CIER_PLL2RDYIE);
    }
    void enablePLL3ReadyIsr(bool benable)
    {
        benable ? SET_BIT(RCC->CIER, RCC_CIER_PLL3RDYIE) : CLEAR_BIT(RCC->CIER, RCC_CIER_PLL3RDYIE);
    }
    void enableLSESecuritySystemFaultIsr(bool benable)
    {
        benable ? SET_BIT(RCC->CIER, RCC_CIER_LSECSSIE) : CLEAR_BIT(RCC->CIER, RCC_CIER_LSECSSIE);
    }

    bool isLSIReadyIsr()
    {
        return READ_BIT(RCC->CIFR, RCC_CIFR_LSIRDYF) == RCC_CIFR_LSIRDYF ? true : false;
    }
    bool isLSEReadyIsr()
    {
        return READ_BIT(RCC->CIFR, RCC_CIFR_LSERDYF) == RCC_CIFR_LSERDYF ? true : false;
    }
    bool isHSIReadyIsr()
    {
        return READ_BIT(RCC->CIFR, RCC_CIFR_HSIRDYF) == RCC_CIFR_HSIRDYF ? true : false;
    }
    bool isHSEReadyIsr()
    {
        return READ_BIT(RCC->CIFR, RCC_CIFR_HSERDYF) == RCC_CIFR_HSERDYF ? true : false;
    }
    bool isCSIReadyIsr()
    {
        return READ_BIT(RCC->CIFR, RCC_CIFR_CSIRDYF) == RCC_CIFR_CSIRDYF ? true : false;
    }
    bool isHSI48ReadyIsr()
    {
        return READ_BIT(RCC->CIFR, RCC_CIFR_HSI48RDYF) == RCC_CIFR_HSI48RDYF ? true : false;
    }
    bool isPLL1ReadyIsr()
    {
        return READ_BIT(RCC->CIFR, RCC_CIFR_PLLRDYF) == RCC_CIFR_PLLRDYF ? true : false;
    }
    bool isPLL2ReadyIsr()
    {
        return READ_BIT(RCC->CIFR, RCC_CIFR_PLL2RDYF) == RCC_CIFR_PLL2RDYF ? true : false;
    }
    bool isPLL3ReadyIsr()
    {
        return READ_BIT(RCC->CIFR, RCC_CIFR_PLL3RDYF) == RCC_CIFR_PLL3RDYF ? true : false;
    }
    bool isLSESecuritySystemFaultIsr()
    {
        return READ_BIT(RCC->CIFR, RCC_CIFR_LSECSSF);
    }
    bool isHSESecuritySystemFaultIsr()
    {
        return READ_BIT(RCC->CIFR, RCC_CIFR_HSECSSF);
    }

    void clrLSIReadyFlagIsr()
    {
        CLEAR_BIT(RCC->CICR, RCC_CICR_LSIRDYC);
    }
    void clrLSEReadyFlagIsr()
    {
        READ_BIT(RCC->CICR, RCC_CICR_LSERDYC);
    }
    void clrHSIReadyFlagIsr()
    {
        READ_BIT(RCC->CICR, RCC_CICR_HSIRDYC);
    }
    void clrHSEReadyFlagIsr()
    {
        READ_BIT(RCC->CICR, RCC_CICR_HSERDYC);
    }
    void clrCSIReadyFlagIsr()
    {
        READ_BIT(RCC->CICR, RCC_CICR_CSIRDYC);
    }
    void clrHSI48ReadyFlagIsr()
    {
        READ_BIT(RCC->CICR, RCC_CICR_HSI48RDYC);
    }
    void clrPLL1ReadyFlagIsr()
    {
        READ_BIT(RCC->CICR, RCC_CICR_PLLRDYC);
    }
    void clrPLL2ReadyFlagIsr()
    {
        READ_BIT(RCC->CICR, RCC_CICR_PLL2RDYC);
    }
    void clrPLL3ReadyFlagIsr()
    {
        READ_BIT(RCC->CICR, RCC_CICR_PLL3RDYC);
    }
    void clrLSESecuritySystemFaultFlagIsr()
    {
        READ_BIT(RCC->CICR, RCC_CICR_LSECSSC);
    }
    void clrHSESecuritySystemFaultFlagIsr()
    {
        READ_BIT(RCC->CICR, RCC_CICR_HSECSSC);
    }
    void enableLSEOscillator(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->BDCR, RCC_BDCR_LSEON) : CLEAR_BIT(RCC->BDCR, RCC_BDCR_LSEON);
    }
    bool isLSEOscillatorReady()
    {
        return READ_BIT(RCC->BDCR, RCC_BDCR_LSERDY) == RCC_BDCR_LSERDY ? true : false;
    }
    bool bypassLSEOscillator(bool bBypass)
    {
        if(isLSEOscillatorReady())
        {
            return false;
        }
        bBypass ? SET_BIT(RCC->BDCR, RCC_BDCR_LSEBYP) : CLEAR_BIT(RCC->BDCR, RCC_BDCR_LSEBYP);
        return true;
    }
    void setLSEOscillatorDriverCapability(RCCLSEOscDriverCap capbility)
    {
        MODIFY_REG(RCC->BDCR, RCC_BDCR_LSEDRV, capbility);
    }
    void enableLSESecuritySystem(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->BDCR, RCC_BDCR_LSECSSON) : CLEAR_BIT(RCC->BDCR, RCC_BDCR_LSECSSON);
    }
    bool isLSESecuritySystemFault()
    {
        return READ_BIT(RCC->BDCR, RCC_BDCR_LSECSSD);
    }
    bool selectRTCClkSrc(RCCRTCClkSrc src)
    {
        if(READ_BIT(RCC->BDCR, RCC_BDCR_LSECSSON))
        {
            return false;
        }
        MODIFY_REG(RCC->BDCR, RCC_BDCR_RTCSEL, src);
        return true;
    }
    void enableRTCClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->BDCR, RCC_BDCR_RTCEN) : CLEAR_BIT(RCC->BDCR, RCC_BDCR_RTCEN);
    }
    void resetBackUpDoMainSoftware(bool bRst)
    {
        bRst ? SET_BIT(RCC->BDCR, RCC_BDCR_BDRST) : CLEAR_BIT(RCC->BDCR, RCC_BDCR_BDRST);
    }
    //LSI
    void enbaleLSIOscillator(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->CSR, RCC_CSR_LSION) : CLEAR_BIT(RCC->BDCR, RCC_CSR_LSION);
    }
    bool isLSIOscillatorReady()
    {
        return READ_BIT(RCC->CSR, RCC_CSR_LSIRDY) == RCC_CSR_LSIRDY ? true : false;
    }
    void resetWWDG1()
    {
         SET_BIT(RCC->GCR, RCC_GCR_WW1RSC);
    }

    void enableMDMAPerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->AHB3ENR, RCC_AHB3ENR_MDMAEN) : CLEAR_BIT(RCC->AHB3ENR, RCC_AHB3ENR_MDMAEN);
    }
    void enableDMA2DPerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->AHB3ENR, RCC_AHB3ENR_DMA2DEN) : CLEAR_BIT(RCC->AHB3ENR, RCC_AHB3ENR_DMA2DEN);
    }
    void enableJPGDECPerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->AHB3ENR, RCC_AHB3ENR_JPGDECEN) : CLEAR_BIT(RCC->AHB3ENR, RCC_AHB3ENR_JPGDECEN);
    }
    void enableFMCPerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->AHB3ENR, RCC_AHB3ENR_FMCEN) : CLEAR_BIT(RCC->AHB3ENR, RCC_AHB3ENR_FMCEN);
    }
    void enableQSPIPerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->AHB3ENR, RCC_AHB3ENR_QSPIEN) : CLEAR_BIT(RCC->AHB3ENR, RCC_AHB3ENR_QSPIEN);
    }
    void enableSDMMC1PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->AHB3ENR, RCC_AHB3ENR_SDMMC1EN) : CLEAR_BIT(RCC->AHB3ENR, RCC_AHB3ENR_SDMMC1EN);
    }
    void enableDMA1Clk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DMA1EN) : CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DMA1EN);
    }
    void enableDMA2Clk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DMA2EN) : CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DMA2EN);
    }
    void enableADC12PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_ADC12EN) : CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_ADC12EN);
    }
    void enableETH1MACClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_ETH1MACEN) : CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_ETH1MACEN);
    }
    void enableETH1TXClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_ETH1TXEN) : CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_ETH1TXEN);
    }
    void enableETH1RXClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_ETH1RXEN) : CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_ETH1RXEN);
    }
    void enableUSB1OTGPerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_USB1OTGHSEN) : CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_USB1OTGHSEN);
    }
    void enableUSB1ULPIClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_USB1OTGHSULPIEN) : CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_USB1OTGHSULPIEN);
    }
    void enableUSB2OTGPerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_USB2OTGHSEN) : CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_USB2OTGHSEN);
    }
    void enableUSB2ULPIClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_USB2OTGHSULPIEN) : CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_USB2OTGHSULPIEN);
    }
    void enableDCMIPerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_DCMIEN) : CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_DCMIEN);
    }
    void enableCRYPTPerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_CRYPEN) : CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_CRYPEN);
    }
    void enableHASHPerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_HASHEN) : CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_HASHEN);
    }
    void enableRNGPerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_RNGEN) : CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_RNGEN);
    }
    void enableSDMMC2PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SDMMC2EN) : CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SDMMC2EN);
    }
    void enableSRAM1Clk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SRAM1EN) : CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SRAM1EN);
    }
    void enableSRAM2Clk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SRAM2EN) : CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SRAM2EN);
    }
    void enableSRAM3Clk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SRAM3EN) : CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SRAM3EN);
    }
    void enableGPIOPerClk(GPIO_TypeDef *gpio, bool bEnabale)
    {
        uint32_t offset = (((uint32_t)gpio -  (uint32_t)GPIOA_BASE) / 0x400);
        bEnabale ? SET_BIT(RCC->AHB4ENR, 1UL << offset) : CLEAR_BIT(RCC->AHB4ENR, 1UL << offset);
    }
    void enableCRCPerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->AHB4ENR, RCC_AHB4ENR_CRCEN) : CLEAR_BIT(RCC->AHB4ENR, RCC_AHB4ENR_CRCEN);
    }
    void enableBDMAClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->AHB4ENR, RCC_AHB4ENR_BDMAEN) : CLEAR_BIT(RCC->AHB4ENR, RCC_AHB4ENR_BDMAEN);
    }
    void enableADC3PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->AHB4ENR, RCC_AHB4ENR_ADC3EN) : CLEAR_BIT(RCC->AHB4ENR, RCC_AHB4ENR_ADC3EN);
    }
    void enableHSEMPerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->AHB4ENR, RCC_AHB4ENR_HSEMEN) : CLEAR_BIT(RCC->AHB4ENR, RCC_AHB4ENR_HSEMEN);
    }
    void enableBKPRAMPerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->AHB4ENR, RCC_AHB4ENR_BKPRAMEN) : CLEAR_BIT(RCC->AHB4ENR, RCC_AHB4ENR_BKPRAMEN);
    }
    void enableLTDCPerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB3ENR, RCC_APB3ENR_LTDCEN) : CLEAR_BIT(RCC->APB3ENR, RCC_APB3ENR_LTDCEN);
    }
    void enableWWDG1Clk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB3ENR, RCC_APB3ENR_WWDG1EN) : CLEAR_BIT(RCC->APB3ENR, RCC_APB3ENR_WWDG1EN);
    }
    void enableTIM2PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB1LENR, RCC_APB1LENR_TIM2EN) : CLEAR_BIT(RCC->APB1LENR, RCC_APB1LENR_TIM2EN);
    }
    void enableTIM3PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB1LENR, RCC_APB1LENR_TIM3EN) : CLEAR_BIT(RCC->APB1LENR, RCC_APB1LENR_TIM3EN);
    }
    void enableTIM4PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB1LENR, RCC_APB1LENR_TIM4EN) : CLEAR_BIT(RCC->APB1LENR, RCC_APB1LENR_TIM4EN);
    }
    void enableTIM5PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB1LENR, RCC_APB1LENR_TIM5EN) : CLEAR_BIT(RCC->APB1LENR, RCC_APB1LENR_TIM5EN);
    }
    void enableTIM6PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB1LENR, RCC_APB1LENR_TIM6EN) : CLEAR_BIT(RCC->APB1LENR, RCC_APB1LENR_TIM6EN);
    }
    void enableTIM7PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB1LENR, RCC_APB1LENR_TIM7EN) : CLEAR_BIT(RCC->APB1LENR, RCC_APB1LENR_TIM7EN);
    }
    void enableTIM12PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB1LENR, RCC_APB1LENR_TIM12EN) : CLEAR_BIT(RCC->APB1LENR, RCC_APB1LENR_TIM12EN);
    }
    void enableTIM13PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB1LENR, RCC_APB1LENR_TIM13EN) : CLEAR_BIT(RCC->APB1LENR, RCC_APB1LENR_TIM13EN);
    }
    void enableTIM14PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB1LENR, RCC_APB1LENR_TIM14EN) : CLEAR_BIT(RCC->APB1LENR, RCC_APB1LENR_TIM14EN);
    }
    void enableLPTIM1PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB1LENR, RCC_APB1LENR_LPTIM1EN) : CLEAR_BIT(RCC->APB1LENR, RCC_APB1LENR_LPTIM1EN);
    }
    void enableSPI2PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB1LENR, RCC_APB1LENR_SPI2EN) : CLEAR_BIT(RCC->APB1LENR, RCC_APB1LENR_SPI2EN);
    }
    void enableSPI3PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB1LENR, RCC_APB1LENR_SPI3EN) : CLEAR_BIT(RCC->APB1LENR, RCC_APB1LENR_SPI3EN);
    }
    void enableSPDIFRXPerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB1LENR, RCC_APB1LENR_SPDIFRXEN) : CLEAR_BIT(RCC->APB1LENR, RCC_APB1LENR_SPDIFRXEN);
    }
    void enableUSART2PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB1LENR, RCC_APB1LENR_USART2EN) : CLEAR_BIT(RCC->APB1LENR, RCC_APB1LENR_USART2EN);
    }
    void enableUSART3PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB1LENR, RCC_APB1LENR_USART3EN) : CLEAR_BIT(RCC->APB1LENR, RCC_APB1LENR_USART3EN);
    }
    void enableUART4PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB1LENR, RCC_APB1LENR_UART4EN) : CLEAR_BIT(RCC->APB1LENR, RCC_APB1LENR_UART4EN);
    }
    void enableUART5PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB1LENR, RCC_APB1LENR_UART5EN) : CLEAR_BIT(RCC->APB1LENR, RCC_APB1LENR_UART5EN);
    }
    void enableI2C1PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB1LENR, RCC_APB1LENR_I2C1EN) : CLEAR_BIT(RCC->APB1LENR, RCC_APB1LENR_I2C1EN);
    }
    void enableI2C2PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB1LENR, RCC_APB1LENR_I2C2EN) : CLEAR_BIT(RCC->APB1LENR, RCC_APB1LENR_I2C2EN);
    }
    void enableI2C3PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB1LENR, RCC_APB1LENR_I2C3EN) : CLEAR_BIT(RCC->APB1LENR, RCC_APB1LENR_I2C3EN);
    }
    void enableDAC12PerClk(bool bEnabale/*dac1, 2*/)
    {
        bEnabale ? SET_BIT(RCC->APB1LENR, RCC_APB1LENR_DAC12EN) : CLEAR_BIT(RCC->APB1LENR, RCC_APB1LENR_DAC12EN);
    }
    void enableUART7PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB1LENR, RCC_APB1LENR_UART7EN) : CLEAR_BIT(RCC->APB1LENR, RCC_APB1LENR_UART7EN);
    }
    void enableUART8PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB1LENR, RCC_APB1LENR_UART8EN) : CLEAR_BIT(RCC->APB1LENR, RCC_APB1LENR_UART8EN);
    }
    void enableCRSPerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB1HENR, RCC_APB1HENR_CRSEN) : CLEAR_BIT(RCC->APB1HENR, RCC_APB1HENR_CRSEN);
    }
    void enableSWPMIPerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB1HENR, RCC_APB1HENR_SWPMIEN) : CLEAR_BIT(RCC->APB1HENR, RCC_APB1HENR_SWPMIEN);
    }
    void enableOPAMPPerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB1HENR, RCC_APB1HENR_OPAMPEN) : CLEAR_BIT(RCC->APB1HENR, RCC_APB1HENR_OPAMPEN);
    }
    void enableMDIOSPerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB1HENR, RCC_APB1HENR_MDIOSEN) : CLEAR_BIT(RCC->APB1HENR, RCC_APB1HENR_MDIOSEN);
    }
    void enableFDCANPerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB1HENR, RCC_APB1HENR_FDCANEN) : CLEAR_BIT(RCC->APB1HENR, RCC_APB1HENR_FDCANEN);
    }

    void enableTIM1PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM1EN) : CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM1EN);
    }
    void enableTIM8PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM8EN) : CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM8EN);
    }
    void enableUSART1PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB2ENR, RCC_APB2ENR_USART1EN) : CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_USART1EN);
    }
    void enableUSART6PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB2ENR, RCC_APB2ENR_USART6EN) : CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_USART6EN);
    }
    void enableSPI1PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN) : CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN);
    }
    void enableSPI4PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI4EN) : CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI4EN);
    }
    void enableTIM15PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM15EN) : CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM15EN);
    }
    void enableTIM16PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM16EN) : CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM16EN);
    }
    void enableTIM17PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM17EN) : CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM17EN);
    }
    void enableSPI5PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI5EN) : CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI5EN);
    }
    void enableSAI1PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SAI1EN) : CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_SAI1EN);
    }
    void enableSAI2PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SAI2EN) : CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_SAI2EN);
    }
    void enableSAI3PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SAI3EN) : CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_SAI3EN);
    }
    void enableDFSDM1PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB2ENR, RCC_APB2ENR_DFSDM1EN) : CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_DFSDM1EN);
    }
    void enableHRTIMPerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB2ENR, RCC_APB2ENR_HRTIMEN) : CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_HRTIMEN);
    }
    void enableSYSCFGPerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB4ENR, RCC_APB4ENR_SYSCFGEN) : CLEAR_BIT(RCC->APB4ENR, RCC_APB4ENR_SYSCFGEN);
    }
    void enableLPUART1PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB4ENR, RCC_APB4ENR_LPUART1EN) : CLEAR_BIT(RCC->APB4ENR, RCC_APB4ENR_LPUART1EN);
    }
    void enableSPI6PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB4ENR, RCC_APB4ENR_SPI6EN) : CLEAR_BIT(RCC->APB4ENR, RCC_APB4ENR_SPI6EN);
    }
    void enableI2C4PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB4ENR, RCC_APB4ENR_I2C4EN) : CLEAR_BIT(RCC->APB4ENR, RCC_APB4ENR_I2C4EN);
    }
    void enableLPTIM2PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB4ENR, RCC_APB4ENR_LPTIM2EN) : CLEAR_BIT(RCC->APB4ENR, RCC_APB4ENR_LPTIM2EN);
    }
    void enableLPTIM3PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB4ENR, RCC_APB4ENR_LPTIM3EN) : CLEAR_BIT(RCC->APB4ENR, RCC_APB4ENR_LPTIM3EN);
    }
    void enableLPTIM4PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB4ENR, RCC_APB4ENR_LPTIM4EN) : CLEAR_BIT(RCC->APB4ENR, RCC_APB4ENR_LPTIM4EN);
    }
    void enableLPTIM5PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB4ENR, RCC_APB4ENR_LPTIM5EN) : CLEAR_BIT(RCC->APB4ENR, RCC_APB4ENR_LPTIM5EN);
    }
    void enableCOMP12PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB4ENR, RCC_APB4ENR_COMP12EN) : CLEAR_BIT(RCC->APB4ENR, RCC_APB4ENR_COMP12EN);
    }
    void enableVREFPerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB4ENR, RCC_APB4ENR_VREFEN) : CLEAR_BIT(RCC->APB4ENR, RCC_APB4ENR_VREFEN);
    }
    void enableRTCAPBPerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB4ENR, RCC_APB4ENR_RTCAPBEN) : CLEAR_BIT(RCC->APB4ENR, RCC_APB4ENR_RTCAPBEN);
    }
    void enableSAI4PerClk(bool bEnabale)
    {
        bEnabale ? SET_BIT(RCC->APB4ENR, RCC_APB4ENR_SAI4EN) : CLEAR_BIT(RCC->APB4ENR, RCC_APB4ENR_SAI4EN);
    }

    void reset()
    {
        RCC->CR |= RCC_CR_HSION;
        /* Reset CFGR register */
        RCC->CFGR = 0x00000000;

        /* Reset HSEON, CSSON , CSION,RC48ON, CSIKERON PLL1ON, PLL2ON and PLL3ON bits */
        RCC->CR &= 0xEAF6ED7FU;

        /* Reset D1CFGR register */
        RCC->D1CFGR = 0x00000000;

        /* Reset D2CFGR register */
        RCC->D2CFGR = 0x00000000;

        /* Reset D3CFGR register */
        RCC->D3CFGR = 0x00000000;

        /* Reset PLLCKSELR register */
        RCC->PLLCKSELR = 0x00000000;

        /* Reset PLLCFGR register */
        RCC->PLLCFGR = 0x00000000;
        /* Reset PLL1DIVR register */
        RCC->PLL1DIVR = 0x00000000;
        /* Reset PLL1FRACR register */
        RCC->PLL1FRACR = 0x00000000;

        /* Reset PLL2DIVR register */
        RCC->PLL2DIVR = 0x00000000;

        /* Reset PLL2FRACR register */

        RCC->PLL2FRACR = 0x00000000;
        /* Reset PLL3DIVR register */
        RCC->PLL3DIVR = 0x00000000;

        /* Reset PLL3FRACR register */
        RCC->PLL3FRACR = 0x00000000;

        /* Reset HSEBYP bit */
        RCC->CR &= 0xFFFBFFFFU;

        /* Disable all interrupts */
        RCC->CIER = 0x00000000;
    }
    uint32_t getCsiClkFreq()
    {
        return CSI_VALUE;
    }
    uint32_t getPLLClkFreq(RCCPLLCLKType pllx)
    {
        uint32_t clk = 0;
        uint32_t pllm = 0, pllp = 0, pllq = 0, pllr = 0;
        uint32_t hsivalue = 0;
        float pllvco = 0;
        switch(pllx)
        {
            case RCC_PLL1_CLK_FREQ_P:
            case RCC_PLL1_CLK_FREQ_Q:
            case RCC_PLL1_CLK_FREQ_R:
                pllm = (READ_BIT(RCC->PLLCKSELR, RCC_PLLCKSELR_DIVM1) >> RCC_PLLCKSELR_DIVM1_Pos);
                if(pllm != 0 && isPLL1Ready())
                {
                    switch (getPLLSrc())
                    {
                        case RCC_PLL_CLK_SRC_HSI:
                            hsivalue = (HSI_VALUE >> (READ_BIT(RCC->CR, RCC_CR_HSIDIV) >> RCC_CR_HSIDIV_Pos )) ;
                            pllvco = ( (float)hsivalue / (float)pllm) * ((float)(uint32_t)READ_BIT(RCC->PLL1DIVR, RCC_PLL1DIVR_N1) + (float)1 );
                            break;
                        case RCC_PLL_CLK_SRC_CSI:
                            pllvco = ( (float)CSI_VALUE / (float)pllm) * ((float)(uint32_t)READ_BIT(RCC->PLL1DIVR, RCC_PLL1DIVR_N1) + (float)1 );
                            break;
                        case RCC_PLL_CLK_SRC_HSE:
                            pllvco = ( (float)HSE_VALUE / (float)pllm) * ((float)(uint32_t)READ_BIT(RCC->PLL1DIVR, RCC_PLL1DIVR_N1) + (float)1 );
                            break;
                        default:
                            pllvco = ( (float)CSI_VALUE / (float)pllm) * ((float)(uint32_t)READ_BIT(RCC->PLL1DIVR, RCC_PLL1DIVR_N1) + (float)1 );
                            break;
                    }
                    if(pllx == RCC_PLL1_CLK_FREQ_P && READ_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVP1EN))
                    {
                        pllp = (READ_BIT(RCC->PLL1DIVR, RCC_PLL1DIVR_P1) >> RCC_PLL1DIVR_P1_Pos) + 1U;
                        clk =  (uint32_t)(float)(pllvco/(float)pllp);
                    }
                    else if(pllx == RCC_PLL1_CLK_FREQ_Q && READ_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVQ1EN))
                    {
                        pllq = (READ_BIT(RCC->PLL1DIVR, RCC_PLL1DIVR_Q1) >> RCC_PLL1DIVR_Q1_Pos) + 1U;
                        clk =  (uint32_t)(float)(pllvco/(float)pllq);
                    }
                    else if(pllx == RCC_PLL1_CLK_FREQ_R && READ_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVR1EN))
                    {
                        pllr = (READ_BIT(RCC->PLL1DIVR, RCC_PLL1DIVR_R1) >> RCC_PLL1DIVR_R1_Pos) + 1U;
                        clk =  (uint32_t)(float)(pllvco/(float)pllr);
                    }
                }
                break;
            case RCC_PLL2_CLK_FREQ_P:
            case RCC_PLL2_CLK_FREQ_Q:
            case RCC_PLL2_CLK_FREQ_R:
                pllm = (READ_BIT(RCC->PLLCKSELR, RCC_PLLCKSELR_DIVM2) >> RCC_PLLCKSELR_DIVM2_Pos);
                if(pllm != 0 && isPLL2Ready())
                {
                    switch (getPLLSrc())
                    {
                        case RCC_PLL_CLK_SRC_HSI:
                            hsivalue = (HSI_VALUE >> (READ_BIT(RCC->CR, RCC_CR_HSIDIV) >> RCC_CR_HSIDIV_Pos )) ;
                            pllvco = ( (float)hsivalue / (float)pllm) * ((float)(uint32_t)READ_BIT(RCC->PLL2DIVR, RCC_PLL2DIVR_N2) + (float)1 );
                            break;
                        case RCC_PLL_CLK_SRC_CSI:
                            pllvco = ( (float)CSI_VALUE / (float)pllm) * ((float)(uint32_t)READ_BIT(RCC->PLL2DIVR, RCC_PLL2DIVR_N2) + (float)1 );
                            break;
                        case RCC_PLL_CLK_SRC_HSE:
                            pllvco = ( (float)HSE_VALUE / (float)pllm) * ((float)(uint32_t)READ_BIT(RCC->PLL2DIVR, RCC_PLL2DIVR_N2) + (float)1 );
                            break;
                        default:
                            pllvco = ( (float)CSI_VALUE / (float)pllm) * ((float)(uint32_t)READ_BIT(RCC->PLL2DIVR, RCC_PLL2DIVR_N2) + (float)1 );
                            break;
                    }
                    if(pllx == RCC_PLL2_CLK_FREQ_P && READ_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVP2EN))
                    {
                        pllp = (READ_BIT(RCC->PLL2DIVR, RCC_PLL2DIVR_P2) >> RCC_PLL2DIVR_P2_Pos) + 1U;
                        clk =  (uint32_t)(float)(pllvco/(float)pllp);
                    }
                    else if(pllx == RCC_PLL2_CLK_FREQ_Q && READ_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVQ2EN))
                    {
                        pllq = (READ_BIT(RCC->PLL2DIVR, RCC_PLL2DIVR_Q2) >> RCC_PLL2DIVR_Q2_Pos) + 1U;
                        clk =  (uint32_t)(float)(pllvco/(float)pllq);
                    }
                    else if(pllx == RCC_PLL2_CLK_FREQ_R && READ_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVR2EN))
                    {
                        pllr = (READ_BIT(RCC->PLL2DIVR, RCC_PLL2DIVR_R2) >> RCC_PLL2DIVR_R2_Pos) + 1U;
                        clk =  (uint32_t)(float)(pllvco/(float)pllr);
                    }
                }
                break;
            case RCC_PLL3_CLK_FREQ_P:
            case RCC_PLL3_CLK_FREQ_Q:
            case RCC_PLL3_CLK_FREQ_R:
                pllm = (READ_BIT(RCC->PLLCKSELR, RCC_PLLCKSELR_DIVM1) >> RCC_PLLCKSELR_DIVM1_Pos);
                if(pllm != 0 && isPLL3Ready())
                {
                    switch (getPLLSrc())
                    {
                        case RCC_PLL_CLK_SRC_HSI:
                            hsivalue = (HSI_VALUE >> (READ_BIT(RCC->CR, RCC_CR_HSIDIV) >> RCC_CR_HSIDIV_Pos )) ;
                            pllvco = ( (float)hsivalue / (float)pllm) * ((float)(uint32_t)READ_BIT(RCC->PLL3DIVR, RCC_PLL3DIVR_N3) + (float)1 );
                            break;
                        case RCC_PLL_CLK_SRC_CSI:
                            pllvco = ( (float)CSI_VALUE / (float)pllm) * ((float)(uint32_t)READ_BIT(RCC->PLL3DIVR, RCC_PLL3DIVR_N3) + (float)1 );
                            break;
                        case RCC_PLL_CLK_SRC_HSE:
                            pllvco = ( (float)HSE_VALUE / (float)pllm) * ((float)(uint32_t)READ_BIT(RCC->PLL3DIVR, RCC_PLL3DIVR_N3) + (float)1 );
                            break;
                        default:
                            pllvco = ( (float)CSI_VALUE / (float)pllm) * ((float)(uint32_t)READ_BIT(RCC->PLL3DIVR, RCC_PLL3DIVR_N3) + (float)1 );
                            break;
                    }
                    if(pllx == RCC_PLL3_CLK_FREQ_P && READ_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVP3EN))
                    {
                        pllp = (READ_BIT(RCC->PLL3DIVR, RCC_PLL3DIVR_P3) >> RCC_PLL3DIVR_P3_Pos) + 1U;
                        clk =  (uint32_t)(float)(pllvco/(float)pllp);
                    }
                    else if(pllx == RCC_PLL3_CLK_FREQ_Q && READ_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVQ3EN))
                    {
                        pllq = (READ_BIT(RCC->PLL3DIVR, RCC_PLL3DIVR_Q3) >> RCC_PLL3DIVR_Q3_Pos) + 1U;
                        clk =  (uint32_t)(float)(pllvco/(float)pllq);
                    }
                    else if(pllx == RCC_PLL3_CLK_FREQ_R && READ_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVR3EN))
                    {
                        pllr = (READ_BIT(RCC->PLL3DIVR, RCC_PLL3DIVR_R3) >> RCC_PLL3DIVR_R3_Pos) + 1U;
                        clk =  (uint32_t)(float)(pllvco/(float)pllr);
                    }
                }
                break;
            default:
                break;
        }
        return clk;
    }
    uint32_t getSysClkFreq()
    {
        RCCSysClkSrcSta src = getSysClkSrcSta();
        uint32_t sysclk = 0;
        switch(src)
        {
            case RCC_SYS_CLK_HSI:
                sysclk = (uint32_t) (HSI_VALUE >> (READ_BIT(RCC->CR, RCC_CR_HSIDIV) >> RCC_CR_HSIDIV_Pos ));
                break;
            case RCC_SYS_CLK_CSI:
                sysclk = (uint32_t) (CSI_VALUE);
                break;
            case RCC_SYS_CLK_HSE:
                sysclk = (uint32_t) (HSE_VALUE);
                break;
            case RCC_SYS_CLK_PLL1:
                sysclk = getPLLClkFreq(RCC_PLL1_CLK_FREQ_P);
                break;
            default:
                break;
        }
        return sysclk;
    }
    uint32_t getHClkFreq()
    {
        uint32_t hclk = getSysClkFreq() >>  D1CorePrescTable[READ_BIT(RCC->D1CFGR, RCC_D1CFGR_D1CPRE)>> RCC_D1CFGR_D1CPRE_Pos];
        hclk >>= ((D1CorePrescTable[(RCC->D1CFGR & RCC_D1CFGR_HPRE)>> RCC_D1CFGR_HPRE_Pos]) & 0x1FU);
        return hclk;
    }
    uint32_t getAPB1ClkFreq()
    {
        uint32_t clk = 0;
        switch ((RCCD2PPRE1APB1Prescaler)READ_BIT(RCC->D2CFGR, RCC_D2CFGR_D2PPRE1))
        {
        case RCC_D2_PPRE1_APB1_PRESCALER_DIV1:
            clk = (getHClkFreq() >> 0);
            break;
        case RCC_D2_PPRE1_APB1_PRESCALER_DIV2:
            clk = (getHClkFreq() >> 1);
            break;
        case RCC_D2_PPRE1_APB1_PRESCALER_DIV4:
            clk = (getHClkFreq() >> 2);
            break;
        case RCC_D2_PPRE1_APB1_PRESCALER_DIV8:
            clk = (getHClkFreq() >> 3);
            break;
        case RCC_D2_PPRE1_APB1_PRESCALER_DIV16:
            clk = (getHClkFreq() >> 4);
            break;
        default:
            break;
        }
        return clk;
    }
    uint32_t getAPB2ClkFreq()
    {
        uint32_t clk = 0;
        switch ((RCCD2PPRE2APB2Prescaler)READ_BIT(RCC->D2CFGR, RCC_D2CFGR_D2PPRE2))
        {
        case RCC_D2_PPRE2_APB2_PRESCALER_DIV1:
            clk = (getHClkFreq() >> 0);
            break;
        case RCC_D2_PPRE2_APB2_PRESCALER_DIV2:
            clk = (getHClkFreq() >> 1);
            break;
        case RCC_D2_PPRE2_APB2_PRESCALER_DIV4:
            clk = (getHClkFreq() >> 2);
            break;
        case RCC_D2_PPRE2_APB2_PRESCALER_DIV8:
            clk = (getHClkFreq() >> 3);
            break;
        case RCC_D2_PPRE2_APB2_PRESCALER_DIV16:
            clk = (getHClkFreq() >> 4);
            break;
        default:
            break;
        }
        return clk;
    }
    uint32_t getAPB3ClkFreq()
    {
        uint32_t clk = 0;
        switch ((RCCD1PPREAPB3Prescaler)READ_BIT(RCC->D1CFGR, RCC_D1CFGR_D1PPRE))
        {
        case RCC_D1_PPRE_APB3_PRESCALER_DIV1:
            clk = (getHClkFreq() >> 0);
            break;
        case RCC_D1_PPRE_APB3_PRESCALER_DIV2:
            clk = (getHClkFreq() >> 1);
            break;
        case RCC_D1_PPRE_APB3_PRESCALER_DIV4:
            clk = (getHClkFreq() >> 2);
            break;
        case RCC_D1_PPRE_APB3_PRESCALER_DIV8:
            clk = (getHClkFreq() >> 3);
            break;
        case RCC_D1_PPRE_APB3_PRESCALER_DIV16:
            clk = (getHClkFreq() >> 4);
            break;
        default:
            break;
        }
        return clk;
    }
    uint32_t getAPB4ClkFreq()
    {
        uint32_t clk = 0;
        switch ((RCCD3PPREAPB4Prescaler)READ_BIT(RCC->D3CFGR, RCC_D3CFGR_D3PPRE))
        {
        case RCC_D3_PPRE_APB4_PRESCALER_DIV1:
            clk = (getHClkFreq() >> 0);
            break;
        case RCC_D3_PPRE_APB4_PRESCALER_DIV2:
            clk = (getHClkFreq() >> 1);
            break;
        case RCC_D3_PPRE_APB4_PRESCALER_DIV4:
            clk = (getHClkFreq() >> 2);
            break;
        case RCC_D3_PPRE_APB4_PRESCALER_DIV8:
            clk = (getHClkFreq() >> 3);
            break;
        case RCC_D3_PPRE_APB4_PRESCALER_DIV16:
            clk = (getHClkFreq() >> 4);
            break;
        default:
            break;
        }
        return clk;
    }
private:
    RCCControl()
    {

    }
    ~RCCControl()
    {

    }
    RCCControl(const RCCControl&) = delete;
    RCCControl(RCCControl&&) = delete;
    RCCControl& operator=(const RCCControl&) = delete;
    RCCControl& operator=(RCCControl&&) = delete;
    static const uint8_t D1CorePrescTable[16];
};
const uint8_t RCCControl::D1CorePrescTable[16] = {0, 0, 0, 0, 1, 2, 3, 4, 1, 2, 3, 4, 6, 7, 8, 9};