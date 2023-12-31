#pragma once
#include "common.hpp"
#include "rcc.hpp"

/* Array used to get the DMA stream register offset versus stream index dmaSTREAM_x */
constexpr static const uint8_t DMA_STR_OFFSET_TAB[] =
{
    (uint8_t)(DMA1_Stream0_BASE - DMA1_BASE),
    (uint8_t)(DMA1_Stream1_BASE - DMA1_BASE),
    (uint8_t)(DMA1_Stream2_BASE - DMA1_BASE),
    (uint8_t)(DMA1_Stream3_BASE - DMA1_BASE),
    (uint8_t)(DMA1_Stream4_BASE - DMA1_BASE),
    (uint8_t)(DMA1_Stream5_BASE - DMA1_BASE),
    (uint8_t)(DMA1_Stream6_BASE - DMA1_BASE),
    (uint8_t)(DMA1_Stream7_BASE - DMA1_BASE)
};
constexpr static const uint8_t BDMA_CH_OFFSET_TAB[] =
{
    (uint8_t)(BDMA_Channel0_BASE - BDMA_BASE),
    (uint8_t)(BDMA_Channel1_BASE - BDMA_BASE),
    (uint8_t)(BDMA_Channel2_BASE - BDMA_BASE),
    (uint8_t)(BDMA_Channel3_BASE - BDMA_BASE),
    (uint8_t)(BDMA_Channel4_BASE - BDMA_BASE),
    (uint8_t)(BDMA_Channel5_BASE - BDMA_BASE),
    (uint8_t)(BDMA_Channel6_BASE - BDMA_BASE),
    (uint8_t)(BDMA_Channel7_BASE - BDMA_BASE)
};
/** @defgroup 
  * @brief    write these reg to clean flag
  * @{
  */
enum DMAMUXCleanSyncEvnetOverunFlag
{
    CLEAN_DMAMUX_CFR_CSOF0       =      DMAMUX_CFR_CSOF0,      /*!< Synchronization Event Overrun Flag Channel 0   */
    CLEAN_DMAMUX_CFR_CSOF1       =      DMAMUX_CFR_CSOF1,      /*!< Synchronization Event Overrun Flag Channel 1   */
    CLEAN_DMAMUX_CFR_CSOF2       =      DMAMUX_CFR_CSOF2,      /*!< Synchronization Event Overrun Flag Channel 2   */
    CLEAN_DMAMUX_CFR_CSOF3       =      DMAMUX_CFR_CSOF3,      /*!< Synchronization Event Overrun Flag Channel 3   */
    CLEAN_DMAMUX_CFR_CSOF4       =      DMAMUX_CFR_CSOF4,      /*!< Synchronization Event Overrun Flag Channel 4   */
    CLEAN_DMAMUX_CFR_CSOF5       =      DMAMUX_CFR_CSOF5,      /*!< Synchronization Event Overrun Flag Channel 5   */
    CLEAN_DMAMUX_CFR_CSOF6       =      DMAMUX_CFR_CSOF6,      /*!< Synchronization Event Overrun Flag Channel 6   */
    CLEAN_DMAMUX_CFR_CSOF7       =      DMAMUX_CFR_CSOF7,      /*!< Synchronization Event Overrun Flag Channel 7   */
    CLEAN_DMAMUX_CFR_CSOF8       =      DMAMUX_CFR_CSOF8,      /*!< Synchronization Event Overrun Flag Channel 8   */
    CLEAN_DMAMUX_CFR_CSOF9       =      DMAMUX_CFR_CSOF9,      /*!< Synchronization Event Overrun Flag Channel 9   */
    CLEAN_DMAMUX_CFR_CSOF10      =      DMAMUX_CFR_CSOF10,     /*!< Synchronization Event Overrun Flag Channel 10  */
    CLEAN_DMAMUX_CFR_CSOF11      =      DMAMUX_CFR_CSOF11,     /*!< Synchronization Event Overrun Flag Channel 11  */
    CLEAN_DMAMUX_CFR_CSOF12      =      DMAMUX_CFR_CSOF12,     /*!< Synchronization Event Overrun Flag Channel 12  */
    CLEAN_DMAMUX_CFR_CSOF13      =      DMAMUX_CFR_CSOF13,     /*!< Synchronization Event Overrun Flag Channel 13  */
    CLEAN_DMAMUX_CFR_CSOF14      =      DMAMUX_CFR_CSOF14,     /*!< Synchronization Event Overrun Flag Channel 14  */
    CLEAN_DMAMUX_CFR_CSOF15      =      DMAMUX_CFR_CSOF15,     /*!< Synchronization Event Overrun Flag Channel 15  */
};
enum DMAMUXCleanReqEvnetOverunFlag
{
    CLEAN_DMAMUX_RGCFR_RGCOF0    =      DMAMUX_RGCFR_COF0,     /*!< Request Generator 0 Trigger Event Overrun Flag */
    CLEAN_DMAMUX_RGCFR_RGCOF1    =      DMAMUX_RGCFR_COF1,     /*!< Request Generator 1 Trigger Event Overrun Flag */
    CLEAN_DMAMUX_RGCFR_RGCOF2    =      DMAMUX_RGCFR_COF2,     /*!< Request Generator 2 Trigger Event Overrun Flag */
    CLEAN_DMAMUX_RGCFR_RGCOF3    =      DMAMUX_RGCFR_COF3,     /*!< Request Generator 3 Trigger Event Overrun Flag */
    CLEAN_DMAMUX_RGCFR_RGCOF4    =      DMAMUX_RGCFR_COF4,     /*!< Request Generator 4 Trigger Event Overrun Flag */
    CLEAN_DMAMUX_RGCFR_RGCOF5    =      DMAMUX_RGCFR_COF5,     /*!< Request Generator 5 Trigger Event Overrun Flag */
    CLEAN_DMAMUX_RGCFR_RGCOF6    =      DMAMUX_RGCFR_COF6,     /*!< Request Generator 6 Trigger Event Overrun Flag */
    CLEAN_DMAMUX_RGCFR_RGCOF7    =      DMAMUX_RGCFR_COF7      /*!< Request Generator 7 Trigger Event Overrun Flag */
};
/** @defgroup 
  * @brief    read these reg to get flag
  * @{
  */
enum DMAMUXGetSyncOverunFlga
{
    GET_DMAMUX_CSR_SOF0        =        DMAMUX_CSR_SOF0,       /*!< Synchronization Event Overrun Flag Channel 0   */
    GET_DMAMUX_CSR_SOF1        =        DMAMUX_CSR_SOF1,       /*!< Synchronization Event Overrun Flag Channel 1   */
    GET_DMAMUX_CSR_SOF2        =        DMAMUX_CSR_SOF2,       /*!< Synchronization Event Overrun Flag Channel 2   */
    GET_DMAMUX_CSR_SOF3        =        DMAMUX_CSR_SOF3,       /*!< Synchronization Event Overrun Flag Channel 3   */
    GET_DMAMUX_CSR_SOF4        =        DMAMUX_CSR_SOF4,       /*!< Synchronization Event Overrun Flag Channel 4   */
    GET_DMAMUX_CSR_SOF5        =        DMAMUX_CSR_SOF5,       /*!< Synchronization Event Overrun Flag Channel 5   */
    GET_DMAMUX_CSR_SOF6        =        DMAMUX_CSR_SOF6,       /*!< Synchronization Event Overrun Flag Channel 6   */
    GET_DMAMUX_CSR_SOF7        =        DMAMUX_CSR_SOF7,       /*!< Synchronization Event Overrun Flag Channel 7   */
    GET_DMAMUX_CSR_SOF8        =        DMAMUX_CSR_SOF8,       /*!< Synchronization Event Overrun Flag Channel 8   */
    GET_DMAMUX_CSR_SOF9        =        DMAMUX_CSR_SOF9,       /*!< Synchronization Event Overrun Flag Channel 9   */
    GET_DMAMUX_CSR_SOF10       =        DMAMUX_CSR_SOF10,      /*!< Synchronization Event Overrun Flag Channel 10  */
    GET_DMAMUX_CSR_SOF11       =        DMAMUX_CSR_SOF11,      /*!< Synchronization Event Overrun Flag Channel 11  */
    GET_DMAMUX_CSR_SOF12       =        DMAMUX_CSR_SOF12,      /*!< Synchronization Event Overrun Flag Channel 12  */
    GET_DMAMUX_CSR_SOF13       =        DMAMUX_CSR_SOF13,      /*!< Synchronization Event Overrun Flag Channel 13  */
    GET_DMAMUX_CSR_SOF14       =        DMAMUX_CSR_SOF14,      /*!< Synchronization Event Overrun Flag Channel 14  */
    GET_DMAMUX_CSR_SOF15       =        DMAMUX_CSR_SOF15       /*!< Synchronization Event Overrun Flag Channel 15  */
};
enum DMAMUXGetReqOverunFlga
{
    GET_DMAMUX_RGSR_RGOF0       =       DMAMUX_RGSR_OF0,       /*!< Request Generator 0 Trigger Event Overrun Flag */
    GET_DMAMUX_RGSR_RGOF1       =       DMAMUX_RGSR_OF1,       /*!< Request Generator 1 Trigger Event Overrun Flag */
    GET_DMAMUX_RGSR_RGOF2       =       DMAMUX_RGSR_OF2,       /*!< Request Generator 2 Trigger Event Overrun Flag */
    GET_DMAMUX_RGSR_RGOF3       =       DMAMUX_RGSR_OF3,       /*!< Request Generator 3 Trigger Event Overrun Flag */
    GET_DMAMUX_RGSR_RGOF4       =       DMAMUX_RGSR_OF4,       /*!< Request Generator 4 Trigger Event Overrun Flag */
    GET_DMAMUX_RGSR_RGOF5       =       DMAMUX_RGSR_OF5,       /*!< Request Generator 5 Trigger Event Overrun Flag */
    GET_DMAMUX_RGSR_RGOF6       =       DMAMUX_RGSR_OF6,       /*!< Request Generator 6 Trigger Event Overrun Flag */
    GET_DMAMUX_RGSR_RGOF7       =       DMAMUX_RGSR_OF7        /*!< Request Generator 7 Trigger Event Overrun Flag */
};

/** @defgroup IT Defines
  * @brief    IT DEFINE FOR SYNC AND REQ
  * @{
  */
enum DMAMUXSyncOrReqIsr
{
    GET_DMAMUX_CCR_SOIE         =       DMAMUX_CxCR_SOIE,          /*!< Synchronization Event Overrun Interrupt               */
    GET_DMAMUX_RGCR_RGOIE       =       DMAMUX_RGxCR_OIE           /*!< Request Generation Trigger Event Overrun Interrupt    */
};

/** @defgroup DMAMUX1_Request_selection DMAMUX1 Request selection
  * @brief    DMAMUX1 Request selection
  * @{
  */
/* DMAMUX1 requests */
enum DMAMUX1Requests
{
    DMAMUX1_REQ_MEM2MEM       =   0U,   /*!< memory to memory transfer       */
    DMAMUX1_REQ_GENERATOR0    =   1U,   /*!< DMAMUX1 request generator 0     */
    DMAMUX1_REQ_GENERATOR1    =   2U,   /*!< DMAMUX1 request generator 1     */
    DMAMUX1_REQ_GENERATOR2    =   3U,   /*!< DMAMUX1 request generator 2     */
    DMAMUX1_REQ_GENERATOR3    =   4U,   /*!< DMAMUX1 request generator 3     */
    DMAMUX1_REQ_GENERATOR4    =   5U,   /*!< DMAMUX1 request generator 4     */
    DMAMUX1_REQ_GENERATOR5    =   6U,   /*!< DMAMUX1 request generator 5     */
    DMAMUX1_REQ_GENERATOR6    =   7U,   /*!< DMAMUX1 request generator 6     */
    DMAMUX1_REQ_GENERATOR7    =   8U,   /*!< DMAMUX1 request generator 7     */
    DMAMUX1_REQ_ADC1          =   9U,   /*!< DMAMUX1 ADC1 request            */
    DMAMUX1_REQ_ADC2          =   10U,  /*!< DMAMUX1 ADC2 request            */
    DMAMUX1_REQ_TIM1_CH1      =   11U,  /*!< DMAMUX1 TIM1 CH1 request        */
    DMAMUX1_REQ_TIM1_CH2      =   12U,  /*!< DMAMUX1 TIM1 CH2 request        */
    DMAMUX1_REQ_TIM1_CH3      =   13U,  /*!< DMAMUX1 TIM1 CH3 request        */
    DMAMUX1_REQ_TIM1_CH4      =   14U,  /*!< DMAMUX1 TIM1 CH4 request        */
    DMAMUX1_REQ_TIM1_UP       =   15U,  /*!< DMAMUX1 TIM1 UP request         */
    DMAMUX1_REQ_TIM1_TRIG     =   16U,  /*!< DMAMUX1 TIM1 TRIG request       */
    DMAMUX1_REQ_TIM1_COM      =   17U,  /*!< DMAMUX1 TIM1 COM request        */
    DMAMUX1_REQ_TIM2_CH1      =   18U,  /*!< DMAMUX1 TIM2 CH1 request        */
    DMAMUX1_REQ_TIM2_CH2      =   19U,  /*!< DMAMUX1 TIM2 CH2 request        */
    DMAMUX1_REQ_TIM2_CH3      =   20U,  /*!< DMAMUX1 TIM2 CH3 request        */
    DMAMUX1_REQ_TIM2_CH4      =   21U,  /*!< DMAMUX1 TIM2 CH4 request        */
    DMAMUX1_REQ_TIM2_UP       =   22U,  /*!< DMAMUX1 TIM2 UP request         */
    DMAMUX1_REQ_TIM3_CH1      =   23U,  /*!< DMAMUX1 TIM3 CH1 request        */
    DMAMUX1_REQ_TIM3_CH2      =   24U,  /*!< DMAMUX1 TIM3 CH2 request        */
    DMAMUX1_REQ_TIM3_CH3      =   25U,  /*!< DMAMUX1 TIM3 CH3 request        */
    DMAMUX1_REQ_TIM3_CH4      =   26U,  /*!< DMAMUX1 TIM3 CH4 request        */
    DMAMUX1_REQ_TIM3_UP       =   27U,  /*!< DMAMUX1 TIM3 UP request         */
    DMAMUX1_REQ_TIM3_TRIG     =   28U,  /*!< DMAMUX1 TIM3 TRIG request       */
    DMAMUX1_REQ_TIM4_CH1      =   29U,  /*!< DMAMUX1 TIM4 CH1 request        */
    DMAMUX1_REQ_TIM4_CH2      =   30U,  /*!< DMAMUX1 TIM4 CH2 request        */
    DMAMUX1_REQ_TIM4_CH3      =   31U,  /*!< DMAMUX1 TIM4 CH3 request        */
    DMAMUX1_REQ_TIM4_UP       =   32U,  /*!< DMAMUX1 TIM4 UP request         */
    DMAMUX1_REQ_I2C1_RX       =   33U,  /*!< DMAMUX1 I2C1 RX request         */
    DMAMUX1_REQ_I2C1_TX       =   34U,  /*!< DMAMUX1 I2C1 TX request         */
    DMAMUX1_REQ_I2C2_RX       =   35U,  /*!< DMAMUX1 I2C2 RX request         */
    DMAMUX1_REQ_I2C2_TX       =   36U,  /*!< DMAMUX1 I2C2 TX request         */
    DMAMUX1_REQ_SPI1_RX       =   37U,  /*!< DMAMUX1 SPI1 RX request         */
    DMAMUX1_REQ_SPI1_TX       =   38U,  /*!< DMAMUX1 SPI1 TX request         */
    DMAMUX1_REQ_SPI2_RX       =   39U,  /*!< DMAMUX1 SPI2 RX request         */
    DMAMUX1_REQ_SPI2_TX       =   40U,  /*!< DMAMUX1 SPI2 TX request         */
    DMAMUX1_REQ_USART1_RX     =   41U,  /*!< DMAMUX1 USART1 RX request       */
    DMAMUX1_REQ_USART1_TX     =   42U,  /*!< DMAMUX1 USART1 TX request       */
    DMAMUX1_REQ_USART2_RX     =   43U,  /*!< DMAMUX1 USART2 RX request       */
    DMAMUX1_REQ_USART2_TX     =   44U,  /*!< DMAMUX1 USART2 TX request       */
    DMAMUX1_REQ_USART3_RX     =   45U,  /*!< DMAMUX1 USART3 RX request       */
    DMAMUX1_REQ_USART3_TX     =   46U,  /*!< DMAMUX1 USART3 TX request       */
    DMAMUX1_REQ_TIM8_CH1      =   47U,  /*!< DMAMUX1 TIM8 CH1 request        */
    DMAMUX1_REQ_TIM8_CH2      =   48U,  /*!< DMAMUX1 TIM8 CH2 request        */
    DMAMUX1_REQ_TIM8_CH3      =   49U,  /*!< DMAMUX1 TIM8 CH3 request        */
    DMAMUX1_REQ_TIM8_CH4      =   50U,  /*!< DMAMUX1 TIM8 CH4 request        */
    DMAMUX1_REQ_TIM8_UP       =   51U,  /*!< DMAMUX1 TIM8 UP request         */
    DMAMUX1_REQ_TIM8_TRIG     =   52U,  /*!< DMAMUX1 TIM8 TRIG request       */
    DMAMUX1_REQ_TIM8_COM      =   53U,  /*!< DMAMUX1 TIM8 COM request        */
    DMAMUX1_REQ_TIM5_CH1      =   55U,  /*!< DMAMUX1 TIM5 CH1 request        */
    DMAMUX1_REQ_TIM5_CH2      =   56U,  /*!< DMAMUX1 TIM5 CH2 request        */
    DMAMUX1_REQ_TIM5_CH3      =   57U,  /*!< DMAMUX1 TIM5 CH3 request        */
    DMAMUX1_REQ_TIM5_CH4      =   58U,  /*!< DMAMUX1 TIM5 CH4 request        */
    DMAMUX1_REQ_TIM5_UP       =   59U,  /*!< DMAMUX1 TIM5 UP request         */
    DMAMUX1_REQ_TIM5_TRIG     =   60U,  /*!< DMAMUX1 TIM5 TRIG request       */
    DMAMUX1_REQ_SPI3_RX       =   61U,  /*!< DMAMUX1 SPI3 RX request         */
    DMAMUX1_REQ_SPI3_TX       =   62U,  /*!< DMAMUX1 SPI3 TX request         */
    DMAMUX1_REQ_UART4_RX      =   63U,  /*!< DMAMUX1 UART4 RX request        */
    DMAMUX1_REQ_UART4_TX      =   64U,  /*!< DMAMUX1 UART4 TX request        */
    DMAMUX1_REQ_UART5_RX      =   65U,  /*!< DMAMUX1 UART5 RX request        */
    DMAMUX1_REQ_UART5_TX      =   66U,  /*!< DMAMUX1 UART5 TX request        */
    DMAMUX1_REQ_DAC1_CH1      =   67U,  /*!< DMAMUX1 DAC1 Channel 1 request  */
    DMAMUX1_REQ_DAC1_CH2      =   68U,  /*!< DMAMUX1 DAC1 Channel 2 request  */
    DMAMUX1_REQ_TIM6_UP       =   69U,  /*!< DMAMUX1 TIM6 UP request         */
    DMAMUX1_REQ_TIM7_UP       =   70U,  /*!< DMAMUX1 TIM7 UP request         */
    DMAMUX1_REQ_USART6_RX     =   71U,  /*!< DMAMUX1 USART6 RX request       */
    DMAMUX1_REQ_USART6_TX     =   72U,  /*!< DMAMUX1 USART6 TX request       */
    DMAMUX1_REQ_I2C3_RX       =   73U,  /*!< DMAMUX1 I2C3 RX request         */
    DMAMUX1_REQ_I2C3_TX       =   74U,  /*!< DMAMUX1 I2C3 TX request         */
#if defined (PSSI)
    DMAMUX1_REQ_DCMI_PSSI     =   75U,  /*!< DMAMUX1 DCMI/PSSI request       */
    DMAMUX1_REQ_DCMI          =   LL_DMAMUX1_REQ_DCMI_PSSI, /* Legacy define */
#else
    DMAMUX1_REQ_DCMI          =   75U,  /*!< DMAMUX1 DCMI request            */
#endif /* PSSI */
    DMAMUX1_REQ_CRYP_IN       =   76U,  /*!< DMAMUX1 CRYP IN request         */
    DMAMUX1_REQ_CRYP_OUT      =   77U,  /*!< DMAMUX1 CRYP OUT request        */
    DMAMUX1_REQ_HASH_IN       =   78U,  /*!< DMAMUX1 HASH IN request         */
    DMAMUX1_REQ_UART7_RX      =   79U,  /*!< DMAMUX1 UART7 RX request        */
    DMAMUX1_REQ_UART7_TX      =   80U,  /*!< DMAMUX1 UART7 TX request        */
    DMAMUX1_REQ_UART8_RX      =   81U,  /*!< DMAMUX1 UART8 RX request        */
    DMAMUX1_REQ_UART8_TX      =   82U,  /*!< DMAMUX1 UART8 TX request        */
    DMAMUX1_REQ_SPI4_RX       =   83U,  /*!< DMAMUX1 SPI4 RX request         */
    DMAMUX1_REQ_SPI4_TX       =   84U,  /*!< DMAMUX1 SPI4 TX request         */
    DMAMUX1_REQ_SPI5_RX       =   85U,  /*!< DMAMUX1 SPI5 RX request         */
    DMAMUX1_REQ_SPI5_TX       =   86U,  /*!< DMAMUX1 SPI5 TX request         */
    DMAMUX1_REQ_SAI1_A        =   87U,  /*!< DMAMUX1 SAI1 A request          */
    DMAMUX1_REQ_SAI1_B        =   88U,  /*!< DMAMUX1 SAI1 B request          */
#if defined(SAI2)
    DMAMUX1_REQ_SAI2_A        =   89U,  /*!< DMAMUX1 SAI2 A request          */
    DMAMUX1_REQ_SAI2_B        =   90U,  /*!< DMAMUX1 SAI2 B request          */
#endif /* SAI2 */
    DMAMUX1_REQ_SWPMI_RX      =   91U,  /*!< DMAMUX1 SWPMI RX request        */
    DMAMUX1_REQ_SWPMI_TX      =   92U,  /*!< DMAMUX1 SWPMI TX request        */
    DMAMUX1_REQ_SPDIF_RX_DT   =   93U,  /*!< DMAMUX1 SPDIF RXDT request      */
    DMAMUX1_REQ_SPDIF_RX_CS   =   94U,  /*!< DMAMUX1 SPDIF RXCS request      */
#if defined (HRTIM1)
    DMAMUX1_REQ_HRTIM_MASTER  =   95U,  /*!< DMAMUX1 HRTIM1 Master request 1 */
    DMAMUX1_REQ_HRTIM_TIMER_A =   96U,  /*!< DMAMUX1 HRTIM1 Timer A request 2 */
    DMAMUX1_REQ_HRTIM_TIMER_B =   97U,  /*!< DMAMUX1 HRTIM1 Timer B request 3 */
    DMAMUX1_REQ_HRTIM_TIMER_C =   98U,  /*!< DMAMUX1 HRTIM1 Timer C request 4 */
    DMAMUX1_REQ_HRTIM_TIMER_D =   99U,  /*!< DMAMUX1 HRTIM1 Timer D request 5 */
    DMAMUX1_REQ_HRTIM_TIMER_E =  100U,  /*!< DMAMUX1 HRTIM1 Timer E request 6 */
#endif /* HRTIM1 */
    DMAMUX1_REQ_DFSDM1_FLT0   =  101U,  /*!< DMAMUX1 DFSDM1 Filter0 request  */
    DMAMUX1_REQ_DFSDM1_FLT1   =  102U,  /*!< DMAMUX1 DFSDM1 Filter1 request  */
    DMAMUX1_REQ_DFSDM1_FLT2   =  103U,  /*!< DMAMUX1 DFSDM1 Filter2 request  */
    DMAMUX1_REQ_DFSDM1_FLT3   =  104U,  /*!< DMAMUX1 DFSDM1 Filter3 request  */
    DMAMUX1_REQ_TIM15_CH1     =  105U,  /*!< DMAMUX1 TIM15 CH1 request       */
    DMAMUX1_REQ_TIM15_UP      =  106U,  /*!< DMAMUX1 TIM15 UP request        */
    DMAMUX1_REQ_TIM15_TRIG    =  107U,  /*!< DMAMUX1 TIM15 TRIG request      */
    DMAMUX1_REQ_TIM15_COM     =  108U,  /*!< DMAMUX1 TIM15 COM request       */
    DMAMUX1_REQ_TIM16_CH1     =  109U,  /*!< DMAMUX1 TIM16 CH1 request       */
    DMAMUX1_REQ_TIM16_UP      =  110U,  /*!< DMAMUX1 TIM16 UP request        */
    DMAMUX1_REQ_TIM17_CH1     =  111U,  /*!< DMAMUX1 TIM17 CH1 request       */
    DMAMUX1_REQ_TIM17_UP      =  112U,  /*!< DMAMUX1 TIM17 UP request        */
#if defined (SAI3)
    DMAMUX1_REQ_SAI3_A        =  113U,  /*!< DMAMUX1 SAI3 A request          */
    DMAMUX1_REQ_SAI3_B        =  114U,  /*!< DMAMUX1 SAI3 B request          */
#endif /* SAI3 */
#if defined (ADC3)
    DMAMUX1_REQ_ADC3          =  115U,  /*!< DMAMUX1 ADC3  request           */
#endif /* ADC3 */
#if defined (UART9)
    DMAMUX1_REQ_UART9_RX      =  116U,  /*!< DMAMUX1 UART9 RX request        */
    DMAMUX1_REQ_UART9_TX      =  117U,  /*!< DMAMUX1 UART9 TX request        */
#endif /* UART9 */
#if defined (USART10)
    DMAMUX1_REQ_USART10_RX    =  118U,  /*!< DMAMUX1 USART10 RX request      */
    DMAMUX1_REQ_USART10_TX    =  119U,  /*!< DMAMUX1 USART10 TX request      */
#endif /* USART10 */
#if defined(FMAC)
    DMAMUX1_REQ_FMAC_READ     =  120U,  /*!< DMAMUX1 FMAC Read request       */
    DMAMUX1_REQ_FMAC_WRITE    =  121U,  /*!< DMAMUX1 FMAC Write request      */
#endif /* FMAC */
#if defined(CORDIC)
    DMAMUX1_REQ_CORDIC_READ   =  122U,  /*!< DMAMUX1 CORDIC Read request     */
    DMAMUX1_REQ_CORDIC_WRITE  =  123U,  /*!< DMAMUX1 CORDIC Write request    */
#endif /* CORDIC */
#if defined(I2C5)
    DMAMUX1_REQ_I2C5_RX       =  124U,  /*!< DMAMUX1 I2C5 RX request         */
    DMAMUX1_REQ_I2C5_TX       =  125U,  /*!< DMAMUX1 I2C5 TX request         */
#endif /* I2C5 */
#if defined(TIM23)
    DMAMUX1_REQ_TIM23_CH1     =  126U,  /*!< DMAMUX1 TIM23 CH1 request  */
    DMAMUX1_REQ_TIM23_CH2     =  127U,  /*!< DMAMUX1 TIM23 CH2 request  */
    DMAMUX1_REQ_TIM23_CH3     =  128U,  /*!< DMAMUX1 TIM23 CH3 request  */
    DMAMUX1_REQ_TIM23_CH4     =  129U,  /*!< DMAMUX1 TIM23 CH4 request  */
    DMAMUX1_REQ_TIM23_UP      =  130U,  /*!< DMAMUX1 TIM23 UP request   */
    DMAMUX1_REQ_TIM23_TRIG    =  131U,  /*!< DMAMUX1 TIM23 TRIG request */
#endif /* TIM23 */
#if defined(TIM24)
    DMAMUX1_REQ_TIM24_CH1     =  132U,  /*!< DMAMUX1 TIM24 CH1 request  */
    DMAMUX1_REQ_TIM24_CH2     =  133U,  /*!< DMAMUX1 TIM24 CH2 request  */
    DMAMUX1_REQ_TIM24_CH3     =  134U,  /*!< DMAMUX1 TIM24 CH3 request  */
    DMAMUX1_REQ_TIM24_CH4     =  135U,  /*!< DMAMUX1 TIM24 CH4 request  */
    DMAMUX1_REQ_TIM24_UP      =  136U,  /*!< DMAMUX1 TIM24 UP request   */
    DMAMUX1_REQ_TIM24_TRIG    =  137U   /*!< DMAMUX1 TIM24 TRIG request */
#endif /* TIM24 */
};

/** @defgroup DMAMUX2_Request_selection DMAMUX2 Request selection
  * @brief    DMAMUX2 Request selection
  * @{
  */
/* DMAMUX2 requests */
enum DMAMUX2Requests
{
    DMAMUX2_REQ_MEM2MEM       =   0U,  /*!< memory to memory transfer        */
    DMAMUX2_REQ_GENERATOR0    =   1U,  /*!< DMAMUX2 request generator 0      */
    DMAMUX2_REQ_GENERATOR1    =   2U,  /*!< DMAMUX2 request generator 1      */
    DMAMUX2_REQ_GENERATOR2    =   3U,  /*!< DMAMUX2 request generator 2      */
    DMAMUX2_REQ_GENERATOR3    =   4U,  /*!< DMAMUX2 request generator 3      */
    DMAMUX2_REQ_GENERATOR4    =   5U,  /*!< DMAMUX2 request generator 4      */
    DMAMUX2_REQ_GENERATOR5    =   6U,  /*!< DMAMUX2 request generator 5      */
    DMAMUX2_REQ_GENERATOR6    =   7U,  /*!< DMAMUX2 request generator 6      */
    DMAMUX2_REQ_GENERATOR7    =   8U,  /*!< DMAMUX2 request generator 7      */
    DMAMUX2_REQ_LPUART1_RX    =   9U,  /*!< DMAMUX2 LP_UART1_RX request      */
    DMAMUX2_REQ_LPUART1_TX    =  10U,  /*!< DMAMUX2 LP_UART1_TX request      */
    DMAMUX2_REQ_SPI6_RX       =  11U,  /*!< DMAMUX2 SPI6 RX request          */
    DMAMUX2_REQ_SPI6_TX       =  12U,  /*!< DMAMUX2 SPI6 TX request          */
    DMAMUX2_REQ_I2C4_RX       =  13U,  /*!< DMAMUX2 I2C4 RX request          */
    DMAMUX2_REQ_I2C4_TX       =  14U,  /*!< DMAMUX2 I2C4 TX request          */
#if defined (SAI4)
    DMAMUX2_REQ_SAI4_A        =  15U,  /*!< DMAMUX2 SAI4 A request           */
    DMAMUX2_REQ_SAI4_B        =  16U,  /*!< DMAMUX2 SAI4 B request           */
#endif /* SAI4 */
#if defined (ADC3)
    DMAMUX2_REQ_ADC3          =  17U,  /*!< DMAMUX2 ADC3 request             */
#endif /* ADC3 */
#if defined (DAC2)
    DMAMUX2_REQ_DAC2_CH1      =  17U,  /*!< DMAMUX2 DAC2 CH1 request         */
#endif /* DAC2 */
#if defined (DFSDM2_Channel0)
    DMAMUX2_REQ_DFSDM2_FLT0   =  18U   /*!< DMAMUX2 DFSDM2 Filter0 request   */
#endif /* DFSDM2_Channel0 */
};

/** @defgroup DMAMUX_LL_EC_CHANNEL DMAMUX Channel
  * @{
  */
enum DMAMUXChannel
{
    DMAMUX_CHANNEL_0   =  0x00000000U,  /*!< DMAMUX1 Channel 0  connected to DMA1 Channel 0 , DMAMUX2 Channel 0 connected to BDMA Channel 0 */
    DMAMUX_CHANNEL_1   =  0x00000001U,  /*!< DMAMUX1 Channel 1  connected to DMA1 Channel 1 , DMAMUX2 Channel 1 connected to BDMA Channel 1 */
    DMAMUX_CHANNEL_2   =  0x00000002U,  /*!< DMAMUX1 Channel 2  connected to DMA1 Channel 2 , DMAMUX2 Channel 2 connected to BDMA Channel 2 */
    DMAMUX_CHANNEL_3   =  0x00000003U,  /*!< DMAMUX1 Channel 3  connected to DMA1 Channel 3 , DMAMUX2 Channel 3 connected to BDMA Channel 3 */
    DMAMUX_CHANNEL_4   =  0x00000004U,  /*!< DMAMUX1 Channel 4  connected to DMA1 Channel 4 , DMAMUX2 Channel 4 connected to BDMA Channel 4 */
    DMAMUX_CHANNEL_5   =  0x00000005U,  /*!< DMAMUX1 Channel 5  connected to DMA1 Channel 5 , DMAMUX2 Channel 5 connected to BDMA Channel 5 */
    DMAMUX_CHANNEL_6   =  0x00000006U,  /*!< DMAMUX1 Channel 6  connected to DMA1 Channel 6 , DMAMUX2 Channel 6 connected to BDMA Channel 6 */
    DMAMUX_CHANNEL_7   =  0x00000007U,  /*!< DMAMUX1 Channel 7  connected to DMA1 Channel 7 , DMAMUX2 Channel 7 connected to BDMA Channel 7 */
    DMAMUX_CHANNEL_8   =  0x00000008U,  /*!< DMAMUX1 Channel 8  connected to DMA2 Channel 0 */
    DMAMUX_CHANNEL_9   =  0x00000009U,  /*!< DMAMUX1 Channel 9  connected to DMA2 Channel 1 */
    DMAMUX_CHANNEL_10  =  0x0000000AU,  /*!< DMAMUX1 Channel 10 connected to DMA2 Channel 2 */
    DMAMUX_CHANNEL_11  =  0x0000000BU,  /*!< DMAMUX1 Channel 11 connected to DMA2 Channel 3 */
    DMAMUX_CHANNEL_12  =  0x0000000CU,  /*!< DMAMUX1 Channel 12 connected to DMA2 Channel 4 */
    DMAMUX_CHANNEL_13  =  0x0000000DU,  /*!< DMAMUX1 Channel 13 connected to DMA2 Channel 5 */
    DMAMUX_CHANNEL_14  =  0x0000000EU,  /*!< DMAMUX1 Channel 14 connected to DMA2 Channel 6 */
    DMAMUX_CHANNEL_15  =  0x0000000FU   /*!< DMAMUX1 Channel 15 connected to DMA2 Channel 7 */
};

/** @defgroup DMAMUX_LL_EC_SYNC_NO Synchronization Signal Polarity
  * @{
  */
enum DMAMUXSyncSignalPolarity
{
    DMAMUX_SYNC_NO_EVENT           = 0x00000000U,                               /*!< All requests are blocked                            */
    DMAMUX_SYNC_POL_RISING         = DMAMUX_CxCR_SPOL_0,                        /*!< Synchronization on event on rising edge             */
    DMAMUX_SYNC_POL_FALLING        = DMAMUX_CxCR_SPOL_1,                        /*!< Synchronization on event on falling edge            */
    DMAMUX_SYNC_POL_RISING_FALLING = (DMAMUX_CxCR_SPOL_0 | DMAMUX_CxCR_SPOL_1)  /*!< Synchronization on event on rising and falling edge */
};

/** @defgroup DMAMUX_LL_EC_SYNC_EVT Synchronization Signal Event
  * @{
  */
enum DMAMUX1SyncSignalEventID
{
    DMAMUX1_SYNC_DMAMUX1_CH0_EVT  =  0x00000000U,   /*!< DMAMUX1 synchronization Signal is DMAMUX1 Channel0 Event */
    DMAMUX1_SYNC_DMAMUX1_CH1_EVT  =  0x01000000U,   /*!< DMAMUX1 synchronization Signal is DMAMUX1 Channel1 Event */
    DMAMUX1_SYNC_DMAMUX1_CH2_EVT  =  0x02000000U,   /*!< DMAMUX1 synchronization Signal is DMAMUX1 Channel2 Event */
    DMAMUX1_SYNC_LPTIM1_OUT       =  0x03000000U,   /*!< DMAMUX1 synchronization Signal is LPTIM1 OUT             */
    DMAMUX1_SYNC_LPTIM2_OUT       =  0x04000000U,   /*!< DMAMUX1 synchronization Signal is LPTIM2 OUT             */
    DMAMUX1_SYNC_LPTIM3_OUT       =  0x05000000U,   /*!< DMAMUX1 synchronization Signal is LPTIM3 OUT             */
    DMAMUX1_SYNC_EXTI0            =  0x06000000U,   /*!< DMAMUX1 synchronization Signal is EXTI0 IT               */
    DMAMUX1_SYNC_TIM12_TRGO       =  0x07000000U    /*!< DMAMUX1 synchronization Signal is TIM12 TRGO             */
};

enum DMAMUX2SyncSignalEventID
{
    DMAMUX2_SYNC_DMAMUX2_CH0_EVT =  0x00000000U,   /*!< DMAMUX2 synchronization Signal is DMAMUX2 Channel0 Event */
    DMAMUX2_SYNC_DMAMUX2_CH1_EVT =  0x01000000U,   /*!< DMAMUX2 synchronization Signal is DMAMUX2 Channel1 Event */
    DMAMUX2_SYNC_DMAMUX2_CH2_EVT =  0x02000000U,   /*!< DMAMUX2 synchronization Signal is DMAMUX2 Channel2 Event */
    DMAMUX2_SYNC_DMAMUX2_CH3_EVT =  0x03000000U,   /*!< DMAMUX2 synchronization Signal is DMAMUX2 Channel3 Event */
    DMAMUX2_SYNC_DMAMUX2_CH4_EVT =  0x04000000U,   /*!< DMAMUX2 synchronization Signal is DMAMUX2 Channel4 Event */
    DMAMUX2_SYNC_DMAMUX2_CH5_EVT =  0x05000000U,   /*!< DMAMUX2 synchronization Signal is DMAMUX2 Channel5 Event */
    DMAMUX2_SYNC_LPUART1_RX_WKUP =  0x06000000U,   /*!< DMAMUX2 synchronization Signal is LPUART1 RX Wakeup      */
    DMAMUX2_SYNC_LPUART1_TX_WKUP =  0x07000000U,   /*!< DMAMUX2 synchronization Signal is LPUART1 TX Wakeup      */
    DMAMUX2_SYNC_LPTIM2_OUT      =  0x08000000U,   /*!< DMAMUX2 synchronization Signal is LPTIM2 output          */
    DMAMUX2_SYNC_LPTIM3_OUT      =  0x09000000U,   /*!< DMAMUX2 synchronization Signal is LPTIM3 output          */
    DMAMUX2_SYNC_I2C4_WKUP       =  0x0A000000U,   /*!< DMAMUX2 synchronization Signal is I2C4 Wakeup            */
    DMAMUX2_SYNC_SPI6_WKUP       =  0x0B000000U,   /*!< DMAMUX2 synchronization Signal is SPI6 Wakeup            */
    DMAMUX2_SYNC_COMP1_OUT       =  0x0C000000U,   /*!< DMAMUX2 synchronization Signal is Comparator 1 output    */
    DMAMUX2_SYNC_RTC_WKUP        =  0x0D000000U,   /*!< DMAMUX2 synchronization Signal is RTC Wakeup             */
    DMAMUX2_SYNC_EXTI0           =  0x0E000000U,   /*!< DMAMUX2 synchronization Signal is EXTI0 IT               */
    DMAMUX2_SYNC_EXTI2           =  0x0F000000U    /*!< DMAMUX2 synchronization Signal is EXTI2 IT               */
};

/** @defgroup DMAMUX_LL_EC_REQUEST_GENERATOR Request Generator Channel
  * @{
  */
enum DMAMUXReqGenChannel
{
    DMAMUX_REQ_GEN_0      =     0x00000000U,
    DMAMUX_REQ_GEN_1      =     0x00000001U,
    DMAMUX_REQ_GEN_2      =     0x00000002U,
    DMAMUX_REQ_GEN_3      =     0x00000003U,
    DMAMUX_REQ_GEN_4      =     0x00000004U,
    DMAMUX_REQ_GEN_5      =     0x00000005U,
    DMAMUX_REQ_GEN_6      =     0x00000006U,
    DMAMUX_REQ_GEN_7      =     0x00000007U
};

/** @defgroup DMAMUX_LL_EC_REQUEST_GEN_POLARITY External Request Signal Generation Polarity
  * @{
  */
enum DMAMUXReqSignalGenPolarity
{
    DMAMUX_REQ_GEN_NO_EVENT            =  0x00000000U,                                  /*!< No external DMA request  generation                        */
    DMAMUX_REQ_GEN_POL_RISING          =  DMAMUX_RGxCR_GPOL_0,                          /*!< External DMA request generation on event on rising edge    */
    DMAMUX_REQ_GEN_POL_FALLING         =  DMAMUX_RGxCR_GPOL_1,                          /*!< External DMA request generation on event on falling edge   */
    DMAMUX_REQ_GEN_POL_RISING_FALLING  =  (DMAMUX_RGxCR_GPOL_0 | DMAMUX_RGxCR_GPOL_1)   /*!< External DMA request generation on rising and falling edge */
};

/** @defgroup DMAMUX_LL_EC_REQUEST_GEN External Request Signal Generation
  * @{
  */
enum DMAMUX1ExtReqSignalGenID
{
    DMAMUX1_REQ_GEN_DMAMUX1_CH0_EVT = 0U,   /*!< DMAMUX1 Request generator Signal is DMAMUX1 Channel0 Event        */
    DMAMUX1_REQ_GEN_DMAMUX1_CH1_EVT = 1U,   /*!< DMAMUX1 Request generator Signal is DMAMUX1 Channel1 Event        */
    DMAMUX1_REQ_GEN_DMAMUX1_CH2_EVT = 2U,   /*!< DMAMUX1 Request generator Signal is DMAMUX1 Channel2 Event        */
    DMAMUX1_REQ_GEN_LPTIM1_OUT      = 3U,   /*!< DMAMUX1 Request generator Signal is LPTIM1 OUT                    */
    DMAMUX1_REQ_GEN_LPTIM2_OUT      = 4U,   /*!< DMAMUX1 Request generator Signal is LPTIM2 OUT                    */
    DMAMUX1_REQ_GEN_LPTIM3_OUT      = 5U,   /*!< DMAMUX1 Request generator Signal is LPTIM3 OUT                    */
    DMAMUX1_REQ_GEN_EXTI0           = 6U,   /*!< DMAMUX1 Request generator Signal is EXTI0 IT                      */
    DMAMUX1_REQ_GEN_TIM12_TRGO      = 7U    /*!< DMAMUX1 Request generator Signal is TIM12 TRGO                    */
};

enum DMAMUX2ExtReqSignalGenID
{
    DMAMUX2_REQ_GEN_DMAMUX2_CH0_EVT   =   0U,   /*!< DMAMUX2 Request generator Signal is DMAMUX2 Channel0 Event        */
    DMAMUX2_REQ_GEN_DMAMUX2_CH1_EVT   =   1U,   /*!< DMAMUX2 Request generator Signal is DMAMUX2 Channel1 Event        */
    DMAMUX2_REQ_GEN_DMAMUX2_CH2_EVT   =   2U,   /*!< DMAMUX2 Request generator Signal is DMAMUX2 Channel2 Event        */
    DMAMUX2_REQ_GEN_DMAMUX2_CH3_EVT   =   3U,   /*!< DMAMUX2 Request generator Signal is DMAMUX2 Channel3 Event        */
    DMAMUX2_REQ_GEN_DMAMUX2_CH4_EVT   =   4U,   /*!< DMAMUX2 Request generator Signal is DMAMUX2 Channel4 Event        */
    DMAMUX2_REQ_GEN_DMAMUX2_CH5_EVT   =   5U,   /*!< DMAMUX2 Request generator Signal is DMAMUX2 Channel5 Event        */
    DMAMUX2_REQ_GEN_DMAMUX2_CH6_EVT   =   6U,   /*!< DMAMUX2 Request generator Signal is DMAMUX2 Channel6 Event        */
    DMAMUX2_REQ_GEN_LPUART1_RX_WKUP   =   7U,   /*!< DMAMUX2 Request generator Signal is LPUART1 RX Wakeup             */
    DMAMUX2_REQ_GEN_LPUART1_TX_WKUP   =   8U,   /*!< DMAMUX2 Request generator Signal is LPUART1 TX Wakeup             */
    DMAMUX2_REQ_GEN_LPTIM2_WKUP       =   9U,   /*!< DMAMUX2 Request generator Signal is LPTIM2 Wakeup                 */
    DMAMUX2_REQ_GEN_LPTIM2_OUT        =  10U,   /*!< DMAMUX2 Request generator Signal is LPTIM2 OUT                    */
    DMAMUX2_REQ_GEN_LPTIM3_WKUP       =  11U,   /*!< DMAMUX2 Request generator Signal is LPTIM3 Wakeup                 */
    DMAMUX2_REQ_GEN_LPTIM3_OUT        =  12U,    /*!< DMAMUX2 Request generator Signal is LPTIM3 OUT                    */
#if defined (LPTIM4)
    DMAMUX2_REQ_GEN_LPTIM4_WKUP       =  13U,   /*!< DMAMUX2 Request generator Signal is LPTIM4 Wakeup                 */
#endif /* LPTIM4 */
#if defined (LPTIM5)
    DMAMUX2_REQ_GEN_LPTIM5_WKUP       =  14U,   /*!< DMAMUX2 Request generator Signal is LPTIM5 Wakeup                 */
#endif /* LPTIM5 */
    DMAMUX2_REQ_GEN_I2C4_WKUP         =  15U,   /*!< DMAMUX2 Request generator Signal is I2C4 Wakeup                   */
    DMAMUX2_REQ_GEN_SPI6_WKUP         =  16U,   /*!< DMAMUX2 Request generator Signal is SPI6 Wakeup                   */
    DMAMUX2_REQ_GEN_COMP1_OUT         =  17U,   /*!< DMAMUX2 Request generator Signal is Comparator 1 output           */
    DMAMUX2_REQ_GEN_COMP2_OUT         =  18U,   /*!< DMAMUX2 Request generator Signal is Comparator 2 output           */
    DMAMUX2_REQ_GEN_RTC_WKUP          =  19U,   /*!< DMAMUX2 Request generator Signal is RTC Wakeup                    */
    DMAMUX2_REQ_GEN_EXTI0             =  20U,   /*!< DMAMUX2 Request generator Signal is EXTI0                         */
    DMAMUX2_REQ_GEN_EXTI2             =  21U,   /*!< DMAMUX2 Request generator Signal is EXTI2                         */
    DMAMUX2_REQ_GEN_I2C4_IT_EVT       =  22U,   /*!< DMAMUX2 Request generator Signal is I2C4 IT Event                 */
    DMAMUX2_REQ_GEN_SPI6_IT           =  23U,   /*!< DMAMUX2 Request generator Signal is SPI6 IT                       */
    DMAMUX2_REQ_GEN_LPUART1_TX_IT     =  24U,   /*!< DMAMUX2 Request generator Signal is LPUART1 Tx IT                 */
    DMAMUX2_REQ_GEN_LPUART1_RX_IT     =  25U,   /*!< DMAMUX2 Request generator Signal is LPUART1 Rx IT                 */
#if defined (ADC3)
    DMAMUX2_REQ_GEN_ADC3_IT           =  26U,   /*!< DMAMUX2 Request generator Signal is ADC3 IT                       */
    DMAMUX2_REQ_GEN_ADC3_AWD1_OUT     =  27U,   /*!< DMAMUX2 Request generator Signal is ADC3 Analog Watchdog 1 output */
#endif /* ADC3 */
    DMAMUX2_REQ_GEN_BDMA_CH0_IT       =  28U,   /*!< DMAMUX2 Request generator Signal is BDMA Channel 0 IT             */
    DMAMUX2_REQ_GEN_BDMA_CH1_IT       =  29U    /*!< DMAMUX2 Request generator Signal is BDMA Channel 1 IT             */
};


/** @defgroup DMA_LL_EC_STREAM STREAM
  * @{
  */
enum DMAStreamNum
{
    DMA_STREAM_0         =          0x00000000U,
    DMA_STREAM_1         =          0x00000001U,
    DMA_STREAM_2         =          0x00000002U,
    DMA_STREAM_3         =          0x00000003U,
    DMA_STREAM_4         =          0x00000004U,
    DMA_STREAM_5         =          0x00000005U,
    DMA_STREAM_6         =          0x00000006U,
    DMA_STREAM_7         =          0x00000007U,
    DMA_STREAM_ALL       =          0xFFFF0000U
};

enum DMADirection
{
    DMA_DIRECTION_PERIPH_TO_MEMORY =  0x00000000U,            /*!< Peripheral to memory direction */
    DMA_DIRECTION_MEMORY_TO_PERIPH =  DMA_SxCR_DIR_0,         /*!< Memory to peripheral direction */
    DMA_DIRECTION_MEMORY_TO_MEMORY =  DMA_SxCR_DIR_1          /*!< Memory to memory direction     */
};

enum DMAMode
{
    DMA_MODE_NORMAL        =        0x00000000U,               /*!< Normal Mode                  */
    DMA_MODE_CIRCULAR      =        DMA_SxCR_CIRC,             /*!< Circular Mode                */
    DMA_MODE_PFCTRL        =        DMA_SxCR_PFCTRL,           /*!< Peripheral flow control mode */
};

enum DMADoubleBufferMode
{
    DMA_DOUBLEBUFFER_MODE_DISABLE  =  0x00000000U,               /*!< Disable double buffering mode */
    DMA_DOUBLEBUFFER_MODE_ENABLE   =  DMA_SxCR_DBM               /*!< Enable double buffering mode  */
};

enum DMAPeriphIncMode
{
    DMA_PERIPH_NOINCREMENT    =    0x00000000U,               /*!< Peripheral increment mode Disable */
    DMA_PERIPH_INCREMENT      =    DMA_SxCR_PINC              /*!< Peripheral increment mode Enable  */
};

enum DMAMemoryIncMode
{
    DMA_MEMORY_NOINCREMENT     =    0x00000000U,               /*!< Memory increment mode Disable */
    DMA_MEMORY_INCREMENT       =    DMA_SxCR_MINC              /*!< Memory increment mode Enable  */
};

enum DMAPeriphDataAlign
{
    DMA_PDATAALIGN_BYTE       =    0x00000000U,               /*!< Peripheral data alignment : Byte     */
    DMA_PDATAALIGN_HALFWORD   =    DMA_SxCR_PSIZE_0,          /*!< Peripheral data alignment : HalfWord */
    DMA_PDATAALIGN_WORD       =    DMA_SxCR_PSIZE_1           /*!< Peripheral data alignment : Word     */
};

enum DMAMemoryDataAlign
{
    DMA_MDATAALIGN_BYTE       =     0x00000000U,               /*!< Memory data alignment : Byte     */
    DMA_MDATAALIGN_HALFWORD   =     DMA_SxCR_MSIZE_0,          /*!< Memory data alignment : HalfWord */
    DMA_MDATAALIGN_WORD       =     DMA_SxCR_MSIZE_1           /*!< Memory data alignment : Word     */
};

enum DMAIncOffsetSize
{
    DMA_OFFSETSIZE_PSIZE       =    0x00000000U,               /*!< Peripheral increment offset size is linked to the PSIZE           */
    DMA_OFFSETSIZE_FIXEDTO4    =    DMA_SxCR_PINCOS            /*!< Peripheral increment offset size is fixed to 4 (32-bit alignment) */
};

enum DMAPriority
{
    DMA_PRIORITY_LOW          =     0x00000000U,               /*!< Priority level : Low       */
    DMA_PRIORITY_MEDIUM       =     DMA_SxCR_PL_0,             /*!< Priority level : Medium    */
    DMA_PRIORITY_HIGH         =     DMA_SxCR_PL_1,             /*!< Priority level : High      */
    DMA_PRIORITY_VERYHIGH     =     DMA_SxCR_PL                /*!< Priority level : Very_High */
};

enum DMAMemoryBurst
{
    DMA_MBURST_SINGLE       =      0x00000000U,                             /*!< Memory burst single transfer configuration      */
    DMA_MBURST_INC4         =      DMA_SxCR_MBURST_0,                       /*!< Memory burst of 4 beats transfer configuration  */
    DMA_MBURST_INC8         =      DMA_SxCR_MBURST_1,                       /*!< Memory burst of 8 beats transfer configuration  */
    DMA_MBURST_INC16        =      (DMA_SxCR_MBURST_0 | DMA_SxCR_MBURST_1)  /*!< Memory burst of 16 beats transfer configuration */
};

enum DMAPeriphBurst
{
    DMA_PBURST_SINGLE        =      0x00000000U,                             /*!< Peripheral burst single transfer configuration      */
    DMA_PBURST_INC4          =      DMA_SxCR_PBURST_0,                       /*!< Peripheral burst of 4 beats transfer configuration  */
    DMA_PBURST_INC8          =      DMA_SxCR_PBURST_1,                       /*!< Peripheral burst of 8 beats transfer configuration  */
    DMA_PBURST_INC16         =      (DMA_SxCR_PBURST_0 | DMA_SxCR_PBURST_1)  /*!< Peripheral burst of 16 beats transfer configuration */
};

enum DMAFIFOMode
{
    DMA_FIFOMODE_DISABLE      =     0x00000000U,                             /*!< FIFO mode disable (direct mode is enabled) */
    DMA_FIFOMODE_ENABLE       =     DMA_SxFCR_DMDIS                          /*!< FIFO mode enable                           */
};

enum DMAFIFOStatus
{
    DMA_FIFOSTATUS_0_25       =     0x00000000U,                             /*!< 0 < fifo_level < 1/4    */
    DMA_FIFOSTATUS_25_50      =     DMA_SxFCR_FS_0,                          /*!< 1/4 < fifo_level < 1/2  */
    DMA_FIFOSTATUS_50_75      =     DMA_SxFCR_FS_1,                          /*!< 1/2 < fifo_level < 3/4  */
    DMA_FIFOSTATUS_75_100     =     (DMA_SxFCR_FS_1 | DMA_SxFCR_FS_0),       /*!< 3/4 < fifo_level < full */
    DMA_FIFOSTATUS_EMPTY      =     DMA_SxFCR_FS_2,                          /*!< FIFO is empty           */
    DMA_FIFOSTATUS_FULL       =     (DMA_SxFCR_FS_2 | DMA_SxFCR_FS_0)        /*!< FIFO is full            */
};

enum DMAFIFOThreshould
{
    DMA_FIFOTHRESHOLD_1_4     =     0x00000000U,                             /*!< FIFO threshold 1 quart full configuration  */
    DMA_FIFOTHRESHOLD_1_2     =     DMA_SxFCR_FTH_0,                         /*!< FIFO threshold half full configuration     */
    DMA_FIFOTHRESHOLD_3_4     =     DMA_SxFCR_FTH_1,                         /*!< FIFO threshold 3 quarts full configuration */
    DMA_FIFOTHRESHOLD_FULL    =     DMA_SxFCR_FTH                            /*!< FIFO threshold full configuration          */
};

enum DMACurrentTargetMemory
{
    DMA_CURRENTTARGETMEM0     =     0x00000000U,                             /*!< Set CurrentTarget Memory to Memory 0  */
    DMA_CURRENTTARGETMEM1     =     DMA_SxCR_CT                              /*!< Set CurrentTarget Memory to Memory 1  */
};

enum DMAMUXOverRunType
{
    DMAMUX_OVERRUN_TYPE_SYNC,
    DMAMUX_OVERRUN_TYPE_GEN
};

enum BDMAChannelNum
{
    BDMA_CHANNEL_0        =          0x00000000U, /*!< DMA Channel 0  */
    BDMA_CHANNEL_1        =          0x00000001U, /*!< BDMA Channel 1 */
    BDMA_CHANNEL_2        =          0x00000002U, /*!< BDMA Channel 2 */
    BDMA_CHANNEL_3        =          0x00000003U, /*!< BDMA Channel 3 */
    BDMA_CHANNEL_4        =          0x00000004U, /*!< BDMA Channel 4 */
    BDMA_CHANNEL_5        =          0x00000005U, /*!< BDMA Channel 5 */
    BDMA_CHANNEL_6        =          0x00000006U, /*!< BDMA Channel 6 */
    BDMA_CHANNEL_7        =          0x00000007U, /*!< BDMA Channel 7 */
    BDMA_CHANNEL_ALL      =          0xFFFF0000U  /*!< BDMA Channel all (used only for function @ref bdmaDeInit(). */
};

enum BDMADirection
{
    BDMA_DIRECTION_PERIPH_TO_MEMORY    =     0x00000000U,              /*!< Peripheral to memory direction       */
    BDMA_DIRECTION_MEMORY_TO_PERIPH    =     BDMA_CCR_DIR,             /*!< Memory to peripheral direction       */
    BDMA_DIRECTION_MEMORY_TO_MEMORY    =     BDMA_CCR_MEM2MEM          /*!< Memory to memory direction           */
};
enum BDMAMode
{
    BDMA_MODE_NORMAL        =        0x00000000U,              /*!< Normal Mode                          */
    BDMA_MODE_CIRCULAR      =        BDMA_CCR_CIRC             /*!< Circular Mode                        */
};
enum BDMADoubleBufferMode
{
    BDMA_DOUBLEBUFFER_MODE_DISABLE      =   0x00000000U,              /*!< Disable double buffering mode        */
    BDMA_DOUBLEBUFFER_MODE_ENABLE       =   BDMA_CCR_DBM              /*!< Enable double buffering mode         */
};
enum BDMAPeriphIncMode
{
    BDMA_PERIPH_INCREMENT       =     BDMA_CCR_PINC,            /*!< Peripheral increment mode Enable     */
    BDMA_PERIPH_NOINCREMENT     =     0x00000000U               /*!< Peripheral increment mode Disable    */
};
enum BDMAMemoryIncMode
{
    BDMA_MEMORY_INCREMENT      =     BDMA_CCR_MINC,            /*!< Memory increment mode Enable         */
    BDMA_MEMORY_NOINCREMENT    =     0x00000000U               /*!< Memory increment mode Disable        */
};
enum BDMAPeriphDataAlign
{
    BDMA_PDATAALIGN_BYTE        =      0x00000000U,              /*!< Peripheral data alignment : Byte     */
    BDMA_PDATAALIGN_HALFWORD    =      BDMA_CCR_PSIZE_0,         /*!< Peripheral data alignment : HalfWord */
    BDMA_PDATAALIGN_WORD        =      BDMA_CCR_PSIZE_1          /*!< Peripheral data alignment : Word     */
};
enum BDMAMemoryDataAlign
{
    BDMA_MDATAALIGN_BYTE       =     0x00000000U,              /*!< Memory data alignment : Byte         */
    BDMA_MDATAALIGN_HALFWORD   =     BDMA_CCR_MSIZE_0,         /*!< Memory data alignment : HalfWord     */
    BDMA_MDATAALIGN_WORD       =     BDMA_CCR_MSIZE_1          /*!< Memory data alignment : Word         */
};
enum BDMAPriority
{
    BDMA_PRIORITY_LOW          =     0x00000000U,              /*!< Priority level : Low                 */
    BDMA_PRIORITY_MEDIUM       =     BDMA_CCR_PL_0,            /*!< Priority level : Medium              */
    BDMA_PRIORITY_HIGH         =     BDMA_CCR_PL_1,            /*!< Priority level : High                */
    BDMA_PRIORITY_VERYHIGH     =     BDMA_CCR_PL               /*!< Priority level : Very_High           */
};
enum BDMACurrentTargetMemory
{
    BDMA_CURRENTTARGETMEM0       =      0x00000000U,              /*!< Set CurrentTarget Memory to Memory 0 */
    BDMA_CURRENTTARGETMEM1       =      BDMA_CCR_CT               /*!< Set CurrentTarget Memory to Memory 1 */
};
struct DMA_InitTypeDef
{
    uint32_t             PeriphOrM2MSrcAddress;  
    uint32_t             MemoryOrM2MDstAddress;  
    DMADirection         Direction;              
    DMAMode              Mode;                   
    DMAPeriphIncMode     PeriphOrM2MSrcIncMode;  
    DMAMemoryIncMode     MemoryOrM2MDstIncMode;  
    DMAPeriphDataAlign   PeriphOrM2MSrcDataSize; 
    DMAMemoryDataAlign   MemoryOrM2MDstDataSize; 
    uint32_t             NbData;                 
    DMAMUX1Requests      PeriphRequest;
    DMAPriority          Priority;               
    DMAFIFOMode          FIFOMode;               
    DMAFIFOThreshould    FIFOThreshold;          
    DMAMemoryBurst       MemBurst;               
    DMAPeriphBurst       PeriphBurst;          
};
struct BDMAInitTypeDef
{
    uint32_t                PeriphOrM2MSrcAddress;
    uint32_t                MemoryOrM2MDstAddress;
    BDMADirection           Direction;
    BDMAMode                Mode;
    BDMAPeriphIncMode       PeriphOrM2MSrcIncMode;
    BDMAMemoryIncMode       MemoryOrM2MDstIncMode;
    BDMAPeriphDataAlign     PeriphOrM2MSrcDataSize; 
    BDMAMemoryDataAlign     MemoryOrM2MDstDataSize; 
    uint32_t                NbData;                 
    DMAMUX2Requests         PeriphRequest;          
    BDMAPriority            Priority;
};

class DMAMUX
{
public:
    DMAMUX(DMAMUX_Channel_TypeDef *dmamux, DMA_TypeDef* dmax, DMAStreamNum streamNum)
    {
        dmaMuxBase_ = dmamux;
        dmaMuxChannelNum_ = (DMAMUXChannel)(streamNum + DMARemapToDMAMUXChannel(dmax));
        dmaMuxChannel_ = ((DMAMUX_Channel_TypeDef *)(uint32_t)((uint32_t)dmaMuxBase_ + (DMAMUX_CCR_SIZE * (streamNum)) + (uint32_t)(DMAMUX_CCR_SIZE * DMARemapToDMAMUXChannel(dmax))));
    }
    DMAMUX(DMAMUX_Channel_TypeDef *dmamux, BDMAChannelNum channelNum)
    {
        dmaMuxBase_ = dmamux;
        dmaMuxChannelNum_ = (DMAMUXChannel)(channelNum);
        dmaMuxChannel_ = ((DMAMUX_Channel_TypeDef *)(uint32_t)((uint32_t)dmaMuxBase_ + (DMAMUX_CCR_SIZE * (channelNum))));
    }
    ~DMAMUX()
    {

    }
    DMAMUX(const DMAMUX&) = delete;
    DMAMUX(DMAMUX&&) = delete;
    DMAMUX& operator=(const DMAMUX&) = delete;
    DMAMUX& operator=(DMAMUX&&) = delete;
    void initDmaMuxReqGenChannelNum(DMAMUXReqGenChannel channelNum)
    {
        dmaMuxRequestGenChannelNum_ = channelNum;
    }
    DMAMUX_Channel_TypeDef * getDmaMuxChannel()
    {
        return dmaMuxChannel_;
    }
    inline void dmaMuxSetSyncRequestNb(uint32_t RequestNb)
    {
        MODIFY_REG(dmaMuxChannel_->CCR, DMAMUX_CxCR_NBREQ, (RequestNb - 1U) << DMAMUX_CxCR_NBREQ_Pos);
    }
    inline uint32_t dmaMuxGetSyncRequestNb()
    {
      return (uint32_t)((READ_BIT(dmaMuxChannel_->CCR, DMAMUX_CxCR_NBREQ) >> DMAMUX_CxCR_NBREQ_Pos) + 1U);
    }
    inline void dmaMuxSetSyncPolarity(DMAMUXSyncSignalPolarity Polarity)
    {
        MODIFY_REG(dmaMuxChannel_->CCR, DMAMUX_CxCR_SPOL, Polarity);
    }
    inline DMAMUXSyncSignalPolarity dmaMuxGetSyncPolarity()
    {
        return (DMAMUXSyncSignalPolarity)(READ_BIT(dmaMuxChannel_->CCR, DMAMUX_CxCR_SPOL));
    }
    inline void dmaMuxEnableEventGeneration()
    {
        SET_BIT(dmaMuxChannel_->CCR, DMAMUX_CxCR_EGE);
    }
    inline void dmaMuxDisableEventGeneration()
    {
        CLEAR_BIT(dmaMuxChannel_->CCR, DMAMUX_CxCR_EGE);
    }
    inline bool dmaMuxIsEnabledEventGeneration()
    {
        return ((READ_BIT(dmaMuxChannel_->CCR, DMAMUX_CxCR_EGE) == (DMAMUX_CxCR_EGE)) ? true : false);
    }
    inline void dmaMuxEnableSync()
    {
        SET_BIT(dmaMuxChannel_->CCR, DMAMUX_CxCR_SE);
    }
    inline void dmaMuxDisableSync()
    {
        CLEAR_BIT(dmaMuxChannel_->CCR, DMAMUX_CxCR_SE);
    }
    inline bool dmaMuxIsEnabledSync()
    {
      return ((READ_BIT(dmaMuxChannel_->CCR, DMAMUX_CxCR_SE) == (DMAMUX_CxCR_SE)) ? true : false);
    }
    DMAMUX_RequestGen_TypeDef* getDMAMUXRequestGenChannelAddr() const
    {
        return ((DMAMUX_RequestGen_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_REQ_GEN_OFFSET + (DMAMUX_RGCR_SIZE * dmaMuxRequestGenChannelNum_)));
    }
    inline void dmaMuxEnableRequestGen()
    {
        SET_BIT(((DMAMUX_RequestGen_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_REQ_GEN_OFFSET + (DMAMUX_RGCR_SIZE * dmaMuxRequestGenChannelNum_)))->RGCR, DMAMUX_RGxCR_GE);
    }
    inline void dmaMuxDisableRequestGen()
    {
        CLEAR_BIT(((DMAMUX_RequestGen_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_REQ_GEN_OFFSET + (DMAMUX_RGCR_SIZE * dmaMuxRequestGenChannelNum_)))->RGCR, DMAMUX_RGxCR_GE);
    }
    inline bool dmaMuxIsEnabledRequestGen()
    {
        return ((READ_BIT(((DMAMUX_RequestGen_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_REQ_GEN_OFFSET + (DMAMUX_RGCR_SIZE * dmaMuxRequestGenChannelNum_)))->RGCR, DMAMUX_RGxCR_GE) == (DMAMUX_RGxCR_GE)) ? true : false);
    }
    inline void dmaMuxSetRequestGenPolarity(DMAMUXReqSignalGenPolarity Polarity)
    {
        MODIFY_REG(((DMAMUX_RequestGen_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_REQ_GEN_OFFSET + (DMAMUX_RGCR_SIZE * dmaMuxRequestGenChannelNum_)))->RGCR, DMAMUX_RGxCR_GPOL, Polarity);
    }
    inline DMAMUXReqSignalGenPolarity dmaMuxGetRequestGenPolarity()
    {
        return (DMAMUXReqSignalGenPolarity)(READ_BIT(((DMAMUX_RequestGen_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_REQ_GEN_OFFSET + (DMAMUX_RGCR_SIZE * dmaMuxRequestGenChannelNum_)))->RGCR, DMAMUX_RGxCR_GPOL));
    }
    inline void dmaMuxSetGenRequestNb(uint32_t RequestNb)
    {
        MODIFY_REG(((DMAMUX_RequestGen_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_REQ_GEN_OFFSET + (DMAMUX_RGCR_SIZE * dmaMuxRequestGenChannelNum_)))->RGCR, DMAMUX_RGxCR_GNBREQ, (RequestNb - 1U) << DMAMUX_RGxCR_GNBREQ_Pos);
    }
    inline uint32_t dmaMuxGetGenRequestNb()
    {
        return (uint32_t)((READ_BIT(((DMAMUX_RequestGen_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_REQ_GEN_OFFSET + (DMAMUX_RGCR_SIZE * dmaMuxRequestGenChannelNum_)))->RGCR, DMAMUX_RGxCR_GNBREQ) >> DMAMUX_RGxCR_GNBREQ_Pos) + 1U);
    }
    inline bool dmaMuxIsActiveFlagSyncEventOverrun()
    {
        bool bFlag = false;
        switch (dmaMuxChannelNum_)
        {
            case DMAMUX_CHANNEL_0:
                bFlag = ((READ_BIT(((DMAMUX_ChannelStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_CH_STATUS_OFFSET))->CSR, DMAMUX_CSR_SOF0) == (DMAMUX_CSR_SOF0)) ? true : false);
                break;
            case DMAMUX_CHANNEL_1:
                bFlag = ((READ_BIT(((DMAMUX_ChannelStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_CH_STATUS_OFFSET))->CSR, DMAMUX_CSR_SOF1) == (DMAMUX_CSR_SOF1)) ? true : false);
                break;
            case DMAMUX_CHANNEL_2:
                bFlag = ((READ_BIT(((DMAMUX_ChannelStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_CH_STATUS_OFFSET))->CSR, DMAMUX_CSR_SOF2) == (DMAMUX_CSR_SOF2)) ? true : false);
                break;
            case DMAMUX_CHANNEL_3:
                bFlag = ((READ_BIT(((DMAMUX_ChannelStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_CH_STATUS_OFFSET))->CSR, DMAMUX_CSR_SOF3) == (DMAMUX_CSR_SOF3)) ? true : false);
                break;
            case DMAMUX_CHANNEL_4:
                bFlag = ((READ_BIT(((DMAMUX_ChannelStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_CH_STATUS_OFFSET))->CSR, DMAMUX_CSR_SOF4) == (DMAMUX_CSR_SOF4)) ? true : false);
                break;
            case DMAMUX_CHANNEL_5:
                bFlag = ((READ_BIT(((DMAMUX_ChannelStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_CH_STATUS_OFFSET))->CSR, DMAMUX_CSR_SOF5) == (DMAMUX_CSR_SOF5)) ? true : false);
                break;
            case DMAMUX_CHANNEL_6:
                bFlag = ((READ_BIT(((DMAMUX_ChannelStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_CH_STATUS_OFFSET))->CSR, DMAMUX_CSR_SOF6) == (DMAMUX_CSR_SOF6)) ? true : false);
                break;
            case DMAMUX_CHANNEL_7:
                bFlag = ((READ_BIT(((DMAMUX_ChannelStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_CH_STATUS_OFFSET))->CSR, DMAMUX_CSR_SOF7) == (DMAMUX_CSR_SOF7)) ? true : false);
                break;
            case DMAMUX_CHANNEL_8:
                bFlag = ((READ_BIT(((DMAMUX_ChannelStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_CH_STATUS_OFFSET))->CSR, DMAMUX_CSR_SOF8) == (DMAMUX_CSR_SOF8)) ? true : false);
                break;
            case DMAMUX_CHANNEL_9:
                bFlag = ((READ_BIT(((DMAMUX_ChannelStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_CH_STATUS_OFFSET))->CSR, DMAMUX_CSR_SOF9) == (DMAMUX_CSR_SOF9)) ? true : false);
                break;
            case DMAMUX_CHANNEL_10:
                bFlag = ((READ_BIT(((DMAMUX_ChannelStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_CH_STATUS_OFFSET))->CSR, DMAMUX_CSR_SOF10) == (DMAMUX_CSR_SOF10)) ? true : false);
                break;
            case DMAMUX_CHANNEL_11:
                bFlag = ((READ_BIT(((DMAMUX_ChannelStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_CH_STATUS_OFFSET))->CSR, DMAMUX_CSR_SOF11) == (DMAMUX_CSR_SOF11)) ? true : false);
                break;
            case DMAMUX_CHANNEL_12:
                bFlag = ((READ_BIT(((DMAMUX_ChannelStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_CH_STATUS_OFFSET))->CSR, DMAMUX_CSR_SOF12) == (DMAMUX_CSR_SOF12)) ? true : false);
                break;
            case DMAMUX_CHANNEL_13:
                bFlag = ((READ_BIT(((DMAMUX_ChannelStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_CH_STATUS_OFFSET))->CSR, DMAMUX_CSR_SOF13) == (DMAMUX_CSR_SOF13)) ? true : false);
                break;
            case DMAMUX_CHANNEL_14:
                bFlag = ((READ_BIT(((DMAMUX_ChannelStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_CH_STATUS_OFFSET))->CSR, DMAMUX_CSR_SOF14) == (DMAMUX_CSR_SOF14)) ? true : false);
                break;
            case DMAMUX_CHANNEL_15:
                bFlag = ((READ_BIT(((DMAMUX_ChannelStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_CH_STATUS_OFFSET))->CSR, DMAMUX_CSR_SOF15) == (DMAMUX_CSR_SOF15)) ? true : false);
                break;
            default:
                bFlag = false;
                break;
        }
        return bFlag;
    }
    inline bool dmaMuxIsActiveFlagReqGenTrigEventOverrun()
    {
        bool bFlag = false;
        switch (dmaMuxRequestGenChannelNum_)
        {
        case DMAMUX_REQ_GEN_0:
            bFlag = ((READ_BIT(((DMAMUX_RequestGenStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_REQ_GEN_STATUS_OFFSET))->RGSR, DMAMUX_RGSR_OF0) == (DMAMUX_RGSR_OF0)) ? true : false);
            break;
        case DMAMUX_REQ_GEN_1:
            bFlag = ((READ_BIT(((DMAMUX_RequestGenStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_REQ_GEN_STATUS_OFFSET))->RGSR, DMAMUX_RGSR_OF1) == (DMAMUX_RGSR_OF1)) ? true : false);
            break;
        case DMAMUX_REQ_GEN_2:
            bFlag = ((READ_BIT(((DMAMUX_RequestGenStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_REQ_GEN_STATUS_OFFSET))->RGSR, DMAMUX_RGSR_OF2) == (DMAMUX_RGSR_OF2)) ? true : false);
            break;
        case DMAMUX_REQ_GEN_3:
            bFlag = ((READ_BIT(((DMAMUX_RequestGenStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_REQ_GEN_STATUS_OFFSET))->RGSR, DMAMUX_RGSR_OF3) == (DMAMUX_RGSR_OF3)) ? true : false);
            break;
        case DMAMUX_REQ_GEN_4:
            bFlag = ((READ_BIT(((DMAMUX_RequestGenStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_REQ_GEN_STATUS_OFFSET))->RGSR, DMAMUX_RGSR_OF4) == (DMAMUX_RGSR_OF4)) ? true : false);
            break;
        case DMAMUX_REQ_GEN_5:
            bFlag = ((READ_BIT(((DMAMUX_RequestGenStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_REQ_GEN_STATUS_OFFSET))->RGSR, DMAMUX_RGSR_OF5) == (DMAMUX_RGSR_OF5)) ? true : false);
            break;
        case DMAMUX_REQ_GEN_6:
            bFlag = ((READ_BIT(((DMAMUX_RequestGenStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_REQ_GEN_STATUS_OFFSET))->RGSR, DMAMUX_RGSR_OF6) == (DMAMUX_RGSR_OF6)) ? true : false);
            break;
        case DMAMUX_REQ_GEN_7:
            bFlag = ((READ_BIT(((DMAMUX_RequestGenStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_REQ_GEN_STATUS_OFFSET))->RGSR, DMAMUX_RGSR_OF7) == (DMAMUX_RGSR_OF7)) ? 1UL : 0UL);
            break;
          break;
        
        default:
          bFlag = false;
          break;
        }
        return bFlag;
    }
 

/**
  * @brief  Clear Synchronization Event Overrun Flag Channel 0.
  * @rmtoll CFR          CSOF0         dmaMuxClearFlag_SO0
  * @param  DMAMUXx DMAMUXx DMAMUXx Instance
  * @retval None
  */
    inline void dmaMuxClearFlagSyncEventOverrun()
    {
        switch (dmaMuxChannelNum_)
        {
            case DMAMUX_CHANNEL_0:
                SET_BIT(((DMAMUX_ChannelStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_CH_STATUS_OFFSET))->CFR, DMAMUX_CFR_CSOF0);
                break;
            case DMAMUX_CHANNEL_1:
                SET_BIT(((DMAMUX_ChannelStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_CH_STATUS_OFFSET))->CFR, DMAMUX_CFR_CSOF1);
                break;
            case DMAMUX_CHANNEL_2:
                SET_BIT(((DMAMUX_ChannelStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_CH_STATUS_OFFSET))->CFR, DMAMUX_CFR_CSOF2);
                break;
            case DMAMUX_CHANNEL_3:
                SET_BIT(((DMAMUX_ChannelStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_CH_STATUS_OFFSET))->CFR, DMAMUX_CFR_CSOF3);
                break;
            case DMAMUX_CHANNEL_4:
                SET_BIT(((DMAMUX_ChannelStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_CH_STATUS_OFFSET))->CFR, DMAMUX_CFR_CSOF4);
                break;
            case DMAMUX_CHANNEL_5:
                SET_BIT(((DMAMUX_ChannelStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_CH_STATUS_OFFSET))->CFR, DMAMUX_CFR_CSOF5);
                break;
            case DMAMUX_CHANNEL_6:
                SET_BIT(((DMAMUX_ChannelStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_CH_STATUS_OFFSET))->CFR, DMAMUX_CFR_CSOF6);
                break;
            case DMAMUX_CHANNEL_7:
                SET_BIT(((DMAMUX_ChannelStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_CH_STATUS_OFFSET))->CFR, DMAMUX_CFR_CSOF7);
                break;
            case DMAMUX_CHANNEL_8:
                SET_BIT(((DMAMUX_ChannelStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_CH_STATUS_OFFSET))->CFR, DMAMUX_CFR_CSOF8);
                break;
            case DMAMUX_CHANNEL_9:
                SET_BIT(((DMAMUX_ChannelStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_CH_STATUS_OFFSET))->CFR, DMAMUX_CFR_CSOF9);
                break;
            case DMAMUX_CHANNEL_10:
                SET_BIT(((DMAMUX_ChannelStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_CH_STATUS_OFFSET))->CFR, DMAMUX_CFR_CSOF10);
                break;
            case DMAMUX_CHANNEL_11:
                SET_BIT(((DMAMUX_ChannelStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_CH_STATUS_OFFSET))->CFR, DMAMUX_CFR_CSOF11);
                break;
            case DMAMUX_CHANNEL_12:
                SET_BIT(((DMAMUX_ChannelStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_CH_STATUS_OFFSET))->CFR, DMAMUX_CFR_CSOF12);
                break;
            case DMAMUX_CHANNEL_13:
                SET_BIT(((DMAMUX_ChannelStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_CH_STATUS_OFFSET))->CFR, DMAMUX_CFR_CSOF13);
                break;
            case DMAMUX_CHANNEL_14:
                SET_BIT(((DMAMUX_ChannelStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_CH_STATUS_OFFSET))->CFR, DMAMUX_CFR_CSOF14);
                break;
            case DMAMUX_CHANNEL_15:
                SET_BIT(((DMAMUX_ChannelStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_CH_STATUS_OFFSET))->CFR, DMAMUX_CFR_CSOF15);
                break;
            default:
                break;
        }
    }
    inline void dmaMuxClearFlagReqGenTrigEventOverrun()
    {
        switch (dmaMuxRequestGenChannelNum_)
        {
        case DMAMUX_REQ_GEN_0:
            SET_BIT(((DMAMUX_RequestGenStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_REQ_GEN_STATUS_OFFSET))->RGCFR, DMAMUX_RGCFR_COF0);
            break;
        case DMAMUX_REQ_GEN_1:
            SET_BIT(((DMAMUX_RequestGenStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_REQ_GEN_STATUS_OFFSET))->RGCFR, DMAMUX_RGCFR_COF1);
            break;
        case DMAMUX_REQ_GEN_2:
            SET_BIT(((DMAMUX_RequestGenStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_REQ_GEN_STATUS_OFFSET))->RGCFR, DMAMUX_RGCFR_COF2);
            break;
        case DMAMUX_REQ_GEN_3:
            SET_BIT(((DMAMUX_RequestGenStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_REQ_GEN_STATUS_OFFSET))->RGCFR, DMAMUX_RGCFR_COF3);
            break;
        case DMAMUX_REQ_GEN_4:
            SET_BIT(((DMAMUX_RequestGenStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_REQ_GEN_STATUS_OFFSET))->RGCFR, DMAMUX_RGCFR_COF4);
            break;
        case DMAMUX_REQ_GEN_5:
            SET_BIT(((DMAMUX_RequestGenStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_REQ_GEN_STATUS_OFFSET))->RGCFR, DMAMUX_RGCFR_COF5);
            break;
        case DMAMUX_REQ_GEN_6:
            SET_BIT(((DMAMUX_RequestGenStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_REQ_GEN_STATUS_OFFSET))->RGCFR, DMAMUX_RGCFR_COF6);
            break;
        case DMAMUX_REQ_GEN_7:
            SET_BIT(((DMAMUX_RequestGenStatus_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_REQ_GEN_STATUS_OFFSET))->RGCFR, DMAMUX_RGCFR_COF7);
            break;
          break;

        default:
          break;
        }
    }
    inline void dmaMuxEnableITSyncEventOverrun()
    {
        SET_BIT(((DMAMUX_Channel_TypeDef *)((uint32_t)((uint32_t)dmaMuxBase_ + (DMAMUX_CCR_SIZE * (dmaMuxChannelNum_)))))->CCR, DMAMUX_CxCR_SOIE);
    }
    inline void dmaMuxDisableITSyncEventOverrun()
    {
        CLEAR_BIT(((DMAMUX_Channel_TypeDef *)((uint32_t)((uint32_t)dmaMuxBase_ + (DMAMUX_CCR_SIZE * (dmaMuxChannelNum_)))))->CCR, DMAMUX_CxCR_SOIE);
    }
    inline bool dmaMuxIsEnabledITSyncEventOverrun()
    {
        return (READ_BIT(dmaMuxChannel_->CCR, DMAMUX_CxCR_SOIE) & DMAMUX_CxCR_SOIE ? true : false);
    }
    inline void dmaMuxEnableITReqGenTrigEventOverrun()
    {
        SET_BIT(((DMAMUX_RequestGen_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_REQ_GEN_OFFSET + (DMAMUX_RGCR_SIZE * dmaMuxRequestGenChannelNum_)))->RGCR, DMAMUX_RGxCR_OIE);
    }
    inline void dmaMuxDisableITReqGenTrigEventOverrun()
    {
        CLEAR_BIT(((DMAMUX_RequestGen_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_REQ_GEN_OFFSET + (DMAMUX_RGCR_SIZE * dmaMuxRequestGenChannelNum_)))->RGCR, DMAMUX_RGxCR_OIE);
    }
    inline bool dmaMuxIsEnabledITReqGenTrigEventOverrun()
    {
        return ((READ_BIT(((DMAMUX_RequestGen_TypeDef *)((uint32_t)dmaMuxBase_ + DMAMUX_REQ_GEN_OFFSET + (DMAMUX_RGCR_SIZE * dmaMuxRequestGenChannelNum_)))->RGCR, DMAMUX_RGxCR_OIE) == (DMAMUX_RGxCR_OIE)) ? true : false);
    }
private:
    /**
     * @brief  Helper macro to convert DMA Instance DMAx into DMAMUX channel
     * @note   DMAMUX channel 0 to 7 are mapped to DMA1 stream 0 to 7.
     *         DMAMUX channel 8 to 15 are mapped to DMA2 stream 0 to 7.
     * @param  dma DMAx
     * @retval Channel_Offset (dmaMuxCHANNEL_8 or 0).
     */
    inline uint32_t DMARemapToDMAMUXChannel(DMA_TypeDef* dma) const
    {
        return (((uint32_t)(dma) == ((uint32_t)DMA1)) ? 0UL : 8UL);
    }
private:
    /* Define used to get DMAMUX CCR register size */
    constexpr static const uint32_t DMAMUX_CCR_SIZE                =  0x00000004U;
    /* Define used to get DMAMUX RGCR register size */
    constexpr static const uint32_t DMAMUX_RGCR_SIZE               =    0x00000004U;
    /* Define used to get DMAMUX RequestGenerator offset */
    constexpr static const uint32_t DMAMUX_REQ_GEN_OFFSET          =   (DMAMUX1_RequestGenerator0_BASE - DMAMUX1_BASE);
    /* Define used to get DMAMUX Channel Status offset */
    constexpr static const uint32_t DMAMUX_CH_STATUS_OFFSET        =    (DMAMUX1_ChannelStatus_BASE - DMAMUX1_BASE);
    /* Define used to get DMAMUX RequestGenerator status offset */
    constexpr static const uint32_t DMAMUX_REQ_GEN_STATUS_OFFSET   =  (DMAMUX1_RequestGenStatus_BASE - DMAMUX1_BASE);

    DMAMUX_Channel_TypeDef *dmaMuxChannel_;
    DMAMUX_Channel_TypeDef *dmaMuxBase_;
    DMAMUXChannel dmaMuxChannelNum_;
    DMAMUXReqGenChannel dmaMuxRequestGenChannelNum_;
    DMAMUX_RequestGen_TypeDef *dmaMuxRequestGenChannelAddr_;
};
class DMA : public DMAMUX
{
    using DMAInterruptCb = std::function<void(DMA*, DMATransferIsrType)>;
    using DMAMUXInterruptCb = std::function<void(DMA*, DMAMUXOverRunType)>;
public:
    DMA(DMA_TypeDef* dmax, DMAStreamNum streamNum):DMAMUX(DMAMUX1, dmax, streamNum)
    {
        dmax_ = dmax;
        streamNum_ = streamNum;
        dmaStreamAddr_ = (DMA_Stream_TypeDef*)((uint32_t)(dmax_) + DMA_STR_OFFSET_TAB[streamNum_]);
        if(dmax_ == DMA1)
        {
            RCCControl::getInstance()->AHB1GRP1EnableClock(RCC_AHB1_GRP1_PERIPH_DMA1);
        }
        else if(dmax_ == DMA2)
        {
            RCCControl::getInstance()->AHB1GRP1EnableClock(RCC_AHB1_GRP1_PERIPH_DMA2);
        }
    }
    ~DMA()
    {
    }
    DMA(const DMA&) = delete;
    DMA(DMA&&) = delete;
    DMA& operator=(const DMA&) = delete;
    DMA& operator=(DMA&&) = delete;

    eResult dmaInit(DMA_InitTypeDef *DMA_InitStruct)
    {
        CHECK_RETURN(DMA_InitStruct, E_RESULT_NULL_POINT);
        dmaConfigTransfer(DMA_InitStruct->Direction | \
                              DMA_InitStruct->Mode                    | \
                              DMA_InitStruct->PeriphOrM2MSrcIncMode   | \
                              DMA_InitStruct->MemoryOrM2MDstIncMode   | \
                              DMA_InitStruct->PeriphOrM2MSrcDataSize  | \
                              DMA_InitStruct->MemoryOrM2MDstDataSize  | \
                              DMA_InitStruct->Priority
                            );

        if (DMA_InitStruct->FIFOMode != DMA_FIFOMODE_DISABLE)
        {
            dmaConfigFifo(DMA_InitStruct->FIFOMode, DMA_InitStruct->FIFOThreshold);
            dmaSetMemoryBurstxfer(DMA_InitStruct->MemBurst);
            dmaSetPeriphBurstxfer(DMA_InitStruct->PeriphBurst);
        }
        dmaSetMemoryAddress(DMA_InitStruct->MemoryOrM2MDstAddress);
        dmaSetPeriphAddress(DMA_InitStruct->PeriphOrM2MSrcAddress);
        dmaSetDataLength(DMA_InitStruct->NbData);
        dmaMuxSetPeriphRequest(DMA_InitStruct->PeriphRequest);
        if(DMA_InitStruct->PeriphRequest >= DMAMUX1_REQ_GENERATOR0 && DMA_InitStruct->PeriphRequest <= DMAMUX1_REQ_GENERATOR7)
        {
            initDmaMuxReqGenChannelNum((DMAMUXReqGenChannel)(DMA_InitStruct->PeriphRequest - 1));
        }
        registerDMAIsrCb(dmaStreamAddr_, [](void* param, uint8_t bDMAMuxISR, uint32_t isrtype){
            DMA* pdmax = reinterpret_cast<DMA*>(param);
            if(pdmax)
            {
                if(!bDMAMuxISR)
                {
                    if(pdmax->dmacb_)
                    {
                        pdmax->dmacb_(pdmax, (DMATransferIsrType)isrtype);
                    }
                }
                else
                {
                    if(pdmax->dmaMuxIsEnabledITReqGenTrigEventOverrun() && pdmax->dmaMuxIsActiveFlagReqGenTrigEventOverrun())
                    {
                        pdmax->dmaMuxClearFlagReqGenTrigEventOverrun();
                        if(pdmax->dmamuxcb_)
                        {
                            pdmax->dmamuxcb_(pdmax, DMAMUX_OVERRUN_TYPE_GEN);
                        }
                    }
                    else if(pdmax->dmaMuxIsEnabledITSyncEventOverrun() && pdmax->dmaMuxIsActiveFlagSyncEventOverrun())
                    {
                        pdmax->dmaMuxClearFlagSyncEventOverrun();
                        if(pdmax->dmamuxcb_)
                        {
                            pdmax->dmamuxcb_(pdmax, DMAMUX_OVERRUN_TYPE_SYNC);
                        }
                    }
                }
            }
        }, this);
        
        return E_RESULT_OK;
    }
    eResult dmaDeInit()
    {
        eResult status = E_RESULT_OK;

        /* Disable the selected Stream */
        dmaDisableStream();

        /* Reset DMAx_Streamy configuration register */
        WRITE_REG(dmaStreamAddr_->CR, 0U);

        /* Reset DMAx_Streamy remaining bytes register */
        WRITE_REG(dmaStreamAddr_->NDTR, 0U);

        /* Reset DMAx_Streamy peripheral address register */
        WRITE_REG(dmaStreamAddr_->PAR, 0U);

        /* Reset DMAx_Streamy memory address register */
        WRITE_REG(dmaStreamAddr_->M0AR, 0U);

        /* Reset DMAx_Streamy memory address register */
        WRITE_REG(dmaStreamAddr_->M1AR, 0U);

        /* Reset DMAx_Streamy FIFO control register */
        WRITE_REG(dmaStreamAddr_->FCR, 0x00000021U);

        /* Reset Channel register field for DMAx Stream */
        dmaMuxSetPeriphRequest(DMAMUX1_REQ_MEM2MEM);

        if (streamNum_ == DMA_STREAM_0)
        {
          /* Reset the Stream0 pending flags */
          dmax_->LIFCR = 0x0000003FU;
        }
        else if (streamNum_ == DMA_STREAM_1)
        {
          /* Reset the Stream1 pending flags */
          dmax_->LIFCR = 0x00000F40U;
        }
        else if (streamNum_ == DMA_STREAM_2)
        {
          /* Reset the Stream2 pending flags */
          dmax_->LIFCR = 0x003F0000U;
        }
        else if (streamNum_ == DMA_STREAM_3)
        {
          /* Reset the Stream3 pending flags */
          dmax_->LIFCR = 0x0F400000U;
        }
        else if (streamNum_ == DMA_STREAM_4)
        {
          /* Reset the Stream4 pending flags */
          dmax_->HIFCR = 0x0000003FU;
        }
        else if (streamNum_ == DMA_STREAM_5)
        {
          /* Reset the Stream5 pending flags */
          dmax_->HIFCR = 0x00000F40U;
        }
        else if (streamNum_ == DMA_STREAM_6)
        {
          /* Reset the Stream6 pending flags */
          dmax_->HIFCR = 0x003F0000U;
        }
        else if (streamNum_ == DMA_STREAM_7)
        {
          /* Reset the Stream7 pending flags */
          dmax_->HIFCR = 0x0F400000U;
        }
        else
        {
          status = E_RESULT_ERROR;
        }
        return status;
    }

    inline void dmaEnableStream()
    {
        SET_BIT(dmaStreamAddr_->CR, DMA_SxCR_EN);
    }
    inline void dmaDisableStream()
    {
        CLEAR_BIT(dmaStreamAddr_->CR, DMA_SxCR_EN);
    }
    inline uint32_t dmaIsEnabledStream()
    {
        return ((READ_BIT(dmaStreamAddr_->CR, DMA_SxCR_EN) == (DMA_SxCR_EN)) ? 1UL : 0UL);
    }
    /* @param  Configuration This parameter must be a combination of all the following values:
    *         @arg @ref DMA_DIRECTION_PERIPH_TO_MEMORY or @ref DMA_DIRECTION_MEMORY_TO_PERIPH or @ref DMA_DIRECTION_MEMORY_TO_MEMORY
    *         @arg @ref DMA_MODE_NORMAL or @ref DMA_MODE_CIRCULAR  or @ref DMA_MODE_PFCTRL
    *         @arg @ref DMA_PERIPH_INCREMENT or @ref DMA_PERIPH_NOINCREMENT
    *         @arg @ref DMA_MEMORY_INCREMENT or @ref DMA_MEMORY_NOINCREMENT
    *         @arg @ref DMA_PDATAALIGN_BYTE or @ref DMA_PDATAALIGN_HALFWORD or @ref DMA_PDATAALIGN_WORD
    *         @arg @ref DMA_MDATAALIGN_BYTE or @ref DMA_MDATAALIGN_HALFWORD or @ref DMA_MDATAALIGN_WORD
    *         @arg @ref DMA_PRIORITY_LOW or @ref DMA_PRIORITY_MEDIUM or @ref DMA_PRIORITY_HIGH or @ref DMA_PRIORITY_VERYHIGH
    * */
    inline void dmaConfigTransfer(uint32_t Configuration)
    {
        MODIFY_REG(dmaStreamAddr_->CR,DMA_SxCR_DIR | DMA_SxCR_CIRC | DMA_SxCR_PINC | DMA_SxCR_MINC | DMA_SxCR_PSIZE | DMA_SxCR_MSIZE | DMA_SxCR_PL | DMA_SxCR_PFCTRL, Configuration);
    }
    inline void dmaSetDataTransferDirection(DMADirection direction)
    {
        MODIFY_REG(dmaStreamAddr_->CR, DMA_SxCR_DIR, direction);
    }
    inline DMADirection dmaGetDataTransferDirection()
    {
        return (DMADirection)(READ_BIT(dmaStreamAddr_->CR, DMA_SxCR_DIR));
    }
    inline void dmaSetMode(DMAMode Mode)
    {
        MODIFY_REG(dmaStreamAddr_->CR, DMA_SxCR_CIRC | DMA_SxCR_PFCTRL, Mode);
    }
    inline DMAMode dmaGetMode()
    {
        return (DMAMode)(READ_BIT(dmaStreamAddr_->CR, DMA_SxCR_CIRC | DMA_SxCR_PFCTRL));
    }
    inline void dmaSetPeriphIncMode(DMAPeriphIncMode IncrementMode)
    {
        MODIFY_REG(dmaStreamAddr_->CR, DMA_SxCR_PINC, IncrementMode);
    }
    inline DMAPeriphIncMode dmaGetPeriphIncMode()
    {
        return (DMAPeriphIncMode)(READ_BIT(dmaStreamAddr_->CR, DMA_SxCR_PINC));
    }
    inline void dmaSetMemoryIncMode(DMAMemoryIncMode IncrementMode)
    {
        MODIFY_REG(dmaStreamAddr_->CR, DMA_SxCR_MINC, IncrementMode);
    }
    inline DMAMemoryIncMode dmaGetMemoryIncMode()
    {
        return (DMAMemoryIncMode)(READ_BIT(dmaStreamAddr_->CR, DMA_SxCR_MINC));
    }
    inline void dmaSetPeriphDataAlign(DMAPeriphDataAlign  Align)
    {
        MODIFY_REG(dmaStreamAddr_->CR, DMA_SxCR_PSIZE, Align);
    }
    inline DMAPeriphDataAlign dmaGetPeriphSize()
    {
        return (DMAPeriphDataAlign)(READ_BIT(dmaStreamAddr_->CR, DMA_SxCR_PSIZE));
    }
    inline void dmaSetMemoryDataAlign(DMAMemoryDataAlign  Align)
    {
        MODIFY_REG(dmaStreamAddr_->CR, DMA_SxCR_MSIZE, Align);
    }
    inline DMAMemoryDataAlign dmaGetMemorySize()
    {
        return (DMAMemoryDataAlign)(READ_BIT(dmaStreamAddr_->CR, DMA_SxCR_MSIZE));
    }
    inline void dmaSetIncOffsetSize(DMAIncOffsetSize OffsetSize)
    {
        MODIFY_REG(dmaStreamAddr_->CR, DMA_SxCR_PINCOS, OffsetSize);
    }
    inline DMAIncOffsetSize dmaGetIncOffsetSize()
    {
        return (DMAIncOffsetSize)(READ_BIT(dmaStreamAddr_->CR, DMA_SxCR_PINCOS));
    }
    inline void dmaSetStreamPriorityLevel(DMAPriority Priority)
    {
        MODIFY_REG(dmaStreamAddr_->CR, DMA_SxCR_PL, Priority);
    }
    inline DMAPriority dmaGetStreamPriorityLevel()
    {
        return (DMAPriority)(READ_BIT(dmaStreamAddr_->CR, DMA_SxCR_PL));
    }
    inline void dmaEnableBufferableTransfer()
    {
        SET_BIT(dmaStreamAddr_->CR, DMA_SxCR_TRBUFF);
    }
    inline void dmaDisableBufferableTransfer()
    {
        CLEAR_BIT(dmaStreamAddr_->CR, DMA_SxCR_TRBUFF);
    }
    inline void dmaSetDataLength(uint32_t NbData)
    {
        MODIFY_REG(dmaStreamAddr_->NDTR, DMA_SxNDT, NbData);
    }
    inline uint32_t dmaGetDataLength()
    {
        return (READ_BIT(dmaStreamAddr_->NDTR, DMA_SxNDT));
    }
    inline void dmaMuxSetPeriphRequest(DMAMUX1Requests Request)
    {
        MODIFY_REG(getDmaMuxChannel()->CCR, DMAMUX_CxCR_DMAREQ_ID, Request);
    }
    inline DMAMUX1Requests dmaGetPeriphRequest()
    {
        return (DMAMUX1Requests)(READ_BIT(getDmaMuxChannel()->CCR, DMAMUX_CxCR_DMAREQ_ID));
    }
    inline void dmaMuxSetSyncID(DMAMUX1SyncSignalEventID SyncID)
    {
        MODIFY_REG(getDmaMuxChannel()->CCR, DMAMUX_CxCR_SYNC_ID, SyncID);
    }
    inline DMAMUX1SyncSignalEventID dmaMuxGetSyncID()
    {
        return (DMAMUX1SyncSignalEventID)(READ_BIT(getDmaMuxChannel()->CCR, DMAMUX_CxCR_SYNC_ID));
    }
    inline void dmaMuxSetRequestSignalID(DMAMUX1ExtReqSignalGenID RequestSignalID)
    {
        MODIFY_REG(getDMAMUXRequestGenChannelAddr()->RGCR, DMAMUX_RGxCR_SIG_ID, RequestSignalID);
    }
    inline DMAMUX1ExtReqSignalGenID dmaMuxGetRequestSignalID()
    {
        return (DMAMUX1ExtReqSignalGenID)(READ_BIT(getDMAMUXRequestGenChannelAddr()->RGCR, DMAMUX_RGxCR_SIG_ID));
    }
    inline void dmaSetMemoryBurstxfer(DMAMemoryBurst Mburst)
    {
        MODIFY_REG(dmaStreamAddr_->CR, DMA_SxCR_MBURST, Mburst);
    }
    inline DMAMemoryBurst dmaGetMemoryBurstxfer()
    {
        return (DMAMemoryBurst)(READ_BIT(dmaStreamAddr_->CR, DMA_SxCR_MBURST));
    }
    inline void dmaSetPeriphBurstxfer(DMAPeriphBurst Pburst)
    {
        MODIFY_REG(dmaStreamAddr_->CR, DMA_SxCR_PBURST, Pburst);
    }
    inline DMAPeriphBurst dmaGetPeriphBurstxfer()
    {
        return (DMAPeriphBurst)(READ_BIT(dmaStreamAddr_->CR, DMA_SxCR_PBURST));
    }
    inline void dmaSetCurrentTargetMem(DMACurrentTargetMemory CurrentMemory)
    {
        MODIFY_REG(dmaStreamAddr_->CR, DMA_SxCR_CT, CurrentMemory);
    }
    inline DMACurrentTargetMemory dmaGetCurrentTargetMem()
    {
        return (DMACurrentTargetMemory)(READ_BIT(dmaStreamAddr_->CR, DMA_SxCR_CT));
    }
    inline void dmaEnableDoubleBufferMode()
    {
        SET_BIT(dmaStreamAddr_->CR, DMA_SxCR_DBM);
    }
    inline void dmaDisableDoubleBufferMode()
    {
        CLEAR_BIT(dmaStreamAddr_->CR, DMA_SxCR_DBM);
    }
    inline DMAFIFOStatus dmaGetFIFOStatus()
    {
        return (DMAFIFOStatus)(READ_BIT(dmaStreamAddr_->FCR, DMA_SxFCR_FS));
    }
    inline void dmaDisableFifoMode()
    {
        CLEAR_BIT(dmaStreamAddr_->FCR, DMA_SxFCR_DMDIS);
    }
    inline void dmaEnableFifoMode()
    {
        SET_BIT(dmaStreamAddr_->FCR, DMA_SxFCR_DMDIS);
    }
    inline void dmaSetFIFOThreshold(DMAFIFOThreshould Threshold)
    {
        MODIFY_REG(dmaStreamAddr_->FCR, DMA_SxFCR_FTH, Threshold);
    }
    inline DMAFIFOThreshould dmaGetFIFOThreshold()
    {
        return (DMAFIFOThreshould)(READ_BIT(dmaStreamAddr_->FCR, DMA_SxFCR_FTH));
    }
    inline void dmaConfigFifo(DMAFIFOMode FifoMode, DMAFIFOThreshould FifoThreshold)
    {
        MODIFY_REG(dmaStreamAddr_->FCR, DMA_SxFCR_FTH | DMA_SxFCR_DMDIS, FifoMode | FifoThreshold);
    }
    inline void dmaConfigAddresses(uint32_t SrcAddress, uint32_t DstAddress, DMADirection Direction)
    {
        /* Direction Memory to Periph */
        if (Direction == DMA_DIRECTION_MEMORY_TO_PERIPH)
        {
            WRITE_REG(dmaStreamAddr_->M0AR, SrcAddress);
            WRITE_REG(dmaStreamAddr_->PAR, DstAddress);
        }
        /* Direction Periph to Memory and Memory to Memory */
        else
        {
            WRITE_REG(dmaStreamAddr_->PAR, SrcAddress);
            WRITE_REG(dmaStreamAddr_->M0AR, DstAddress);
        }
    }
    inline void dmaSetMemoryAddress(uint32_t MemoryAddress)
    {
        WRITE_REG(dmaStreamAddr_->M0AR, MemoryAddress);
    }
    inline void dmaSetPeriphAddress(uint32_t PeriphAddress)
    {
        WRITE_REG(dmaStreamAddr_->PAR, PeriphAddress);
    }
    inline uint32_t dmaGetMemoryAddress()
    {
        return (READ_REG(dmaStreamAddr_->M0AR));
    }
    inline uint32_t dmaGetPeriphAddress()
    {
        return (READ_REG(dmaStreamAddr_->PAR));
    }
    inline void dmaSetM2MSrcAddress(uint32_t MemoryAddress)
    {
        WRITE_REG(dmaStreamAddr_->PAR, MemoryAddress);
    }
    inline void dmaSetM2MDstAddress(uint32_t MemoryAddress)
    {
      WRITE_REG(dmaStreamAddr_->M0AR, MemoryAddress);
    }
    inline uint32_t dmaGetM2MSrcAddress()
    {
        return (READ_REG(dmaStreamAddr_->PAR));
    }
    inline uint32_t dmaGetM2MDstAddress()
    {
        return (READ_REG(dmaStreamAddr_->M0AR));
    }
    inline void dmaSetMemory1Address(uint32_t Address)
    {
        MODIFY_REG(dmaStreamAddr_->M1AR, DMA_SxM1AR_M1A, Address);
    }
    inline uint32_t dmaGetMemory1Address()
    {
        return (dmaStreamAddr_->M1AR);
    }
    inline bool dmaIsActiveFlagTransferHalf()
    {
        bool bFlag = false;
        switch (streamNum_)
        {
            case DMA_STREAM_0:
                bFlag = ((READ_BIT(dmax_->LISR, DMA_LISR_HTIF0) == (DMA_LISR_HTIF0)) ? true : false);
                break;
            case DMA_STREAM_1:
                bFlag = ((READ_BIT(dmax_->LISR, DMA_LISR_HTIF1) == (DMA_LISR_HTIF1)) ? true : false);
                break;
            case DMA_STREAM_2:
                bFlag = ((READ_BIT(dmax_->LISR, DMA_LISR_HTIF2) == (DMA_LISR_HTIF2)) ? true : false);
                break;
            case DMA_STREAM_3:
                bFlag = ((READ_BIT(dmax_->LISR, DMA_LISR_HTIF3) == (DMA_LISR_HTIF3)) ? true : false);
                break;
            case DMA_STREAM_4:
                bFlag = ((READ_BIT(dmax_->HISR, DMA_HISR_HTIF4) == (DMA_HISR_HTIF4)) ? true : false);
                break;
            case DMA_STREAM_5:
                bFlag = ((READ_BIT(dmax_->HISR, DMA_HISR_HTIF5) == (DMA_HISR_HTIF5)) ? true : false);  
                break;
            case DMA_STREAM_6:
                bFlag = ((READ_BIT(dmax_->HISR, DMA_HISR_HTIF6) == (DMA_HISR_HTIF6)) ? true : false);
                break;
            case DMA_STREAM_7:
                bFlag = ((READ_BIT(dmax_->HISR, DMA_HISR_HTIF7) == (DMA_HISR_HTIF7)) ? true : false);
                break;
            default:
                bFlag = false;
                break;
        }
        return bFlag;
    }
    inline uint32_t dmaIsActiveFlagTransferComplete()
    {
        bool bFlag = false;
        switch (streamNum_)
        {
            case DMA_STREAM_0:
                bFlag = ((READ_BIT(dmax_->LISR, DMA_LISR_TCIF0) == (DMA_LISR_TCIF0)) ? true : false);
                break;
            case DMA_STREAM_1:
                bFlag = ((READ_BIT(dmax_->LISR, DMA_LISR_TCIF1) == (DMA_LISR_TCIF1)) ? true : false);
                break;
            case DMA_STREAM_2:
                bFlag = ((READ_BIT(dmax_->LISR, DMA_LISR_TCIF2) == (DMA_LISR_TCIF2)) ? true : false);
                break;
            case DMA_STREAM_3:
                bFlag = ((READ_BIT(dmax_->LISR, DMA_LISR_TCIF3) == (DMA_LISR_TCIF3)) ? true : false);
                break;
            case DMA_STREAM_4:
                bFlag = ((READ_BIT(dmax_->HISR, DMA_HISR_TCIF4) == (DMA_HISR_TCIF4)) ? true : false);
                break;
            case DMA_STREAM_5:
                bFlag = ((READ_BIT(dmax_->HISR, DMA_HISR_TCIF5) == (DMA_HISR_TCIF5)) ? true : false);  
                break;
            case DMA_STREAM_6:
                bFlag = ((READ_BIT(dmax_->HISR, DMA_HISR_TCIF6) == (DMA_HISR_TCIF6)) ? true : false);
                break;
            case DMA_STREAM_7:
                bFlag = ((READ_BIT(dmax_->HISR, DMA_HISR_TCIF7) == (DMA_HISR_TCIF7)) ? true : false);
                break;
            default:
                bFlag = false;
                break;
        }
        return bFlag;
    }
    inline uint32_t dmaIsActiveFlagTransferError()
    {
        bool bFlag = false;
        switch (streamNum_)
        {
            case DMA_STREAM_0:
                bFlag = ((READ_BIT(dmax_->LISR, DMA_LISR_TEIF0) == (DMA_LISR_TEIF0)) ? true : false);
                break;
            case DMA_STREAM_1:
                bFlag = ((READ_BIT(dmax_->LISR, DMA_LISR_TEIF1) == (DMA_LISR_TEIF1)) ? true : false);
                break;
            case DMA_STREAM_2:
                bFlag = ((READ_BIT(dmax_->LISR, DMA_LISR_TEIF2) == (DMA_LISR_TEIF2)) ? true : false);
                break;
            case DMA_STREAM_3:
                bFlag = ((READ_BIT(dmax_->LISR, DMA_LISR_TEIF3) == (DMA_LISR_TEIF3)) ? true : false);
                break;
            case DMA_STREAM_4:
                bFlag = ((READ_BIT(dmax_->HISR, DMA_HISR_TEIF4) == (DMA_HISR_TEIF4)) ? true : false);
                break;
            case DMA_STREAM_5:
                bFlag = ((READ_BIT(dmax_->HISR, DMA_HISR_TEIF5) == (DMA_HISR_TEIF5)) ? true : false);  
                break;
            case DMA_STREAM_6:
                bFlag = ((READ_BIT(dmax_->HISR, DMA_HISR_TEIF6) == (DMA_HISR_TEIF6)) ? true : false);
                break;
            case DMA_STREAM_7:
                bFlag = ((READ_BIT(dmax_->HISR, DMA_HISR_TEIF7) == (DMA_HISR_TEIF7)) ? true : false);
                break;
            default:
                bFlag = false;
                break;
        }
        return bFlag;
    }
    inline uint32_t dmaIsActiveFlagDirectModeError()
    {
        bool bFlag = false;
        switch (streamNum_)
        {
            case DMA_STREAM_0:
                bFlag = ((READ_BIT(dmax_->LISR, DMA_LISR_DMEIF0) == (DMA_LISR_DMEIF0)) ? true : false);
                break;
            case DMA_STREAM_1:
                bFlag = ((READ_BIT(dmax_->LISR, DMA_LISR_DMEIF1) == (DMA_LISR_DMEIF1)) ? true : false);
                break;
            case DMA_STREAM_2:
                bFlag = ((READ_BIT(dmax_->LISR, DMA_LISR_DMEIF2) == (DMA_LISR_DMEIF2)) ? true : false);
                break;
            case DMA_STREAM_3:
                bFlag = ((READ_BIT(dmax_->LISR, DMA_LISR_DMEIF3) == (DMA_LISR_DMEIF3)) ? true : false);
                break;
            case DMA_STREAM_4:
                bFlag = ((READ_BIT(dmax_->HISR, DMA_HISR_DMEIF4) == (DMA_HISR_DMEIF4)) ? true : false);
                break;
            case DMA_STREAM_5:
                bFlag = ((READ_BIT(dmax_->HISR, DMA_HISR_DMEIF5) == (DMA_HISR_DMEIF5)) ? true : false);  
                break;
            case DMA_STREAM_6:
                bFlag = ((READ_BIT(dmax_->HISR, DMA_HISR_DMEIF6) == (DMA_HISR_DMEIF6)) ? true : false);
                break;
            case DMA_STREAM_7:
                bFlag = ((READ_BIT(dmax_->HISR, DMA_HISR_DMEIF7) == (DMA_HISR_DMEIF7)) ? true : false);
                break;
            default:
                bFlag = false;
                break;
        }
        return bFlag;
    }
    inline uint32_t dmaIsActiveFlagFIFOError()
    {
        bool bFlag = false;
        switch (streamNum_)
        {
            case DMA_STREAM_0:
                bFlag = ((READ_BIT(dmax_->LISR, DMA_LISR_FEIF0) == (DMA_LISR_FEIF0)) ? true : false);
                break;
            case DMA_STREAM_1:
                bFlag = ((READ_BIT(dmax_->LISR, DMA_LISR_FEIF1) == (DMA_LISR_FEIF1)) ? true : false);
                break;
            case DMA_STREAM_2:
                bFlag = ((READ_BIT(dmax_->LISR, DMA_LISR_FEIF2) == (DMA_LISR_FEIF2)) ? true : false);
                break;
            case DMA_STREAM_3:
                bFlag = ((READ_BIT(dmax_->LISR, DMA_LISR_FEIF3) == (DMA_LISR_FEIF3)) ? true : false);
                break;
            case DMA_STREAM_4:
                bFlag = ((READ_BIT(dmax_->HISR, DMA_HISR_FEIF4) == (DMA_HISR_FEIF4)) ? true : false);
                break;
            case DMA_STREAM_5:
                bFlag = ((READ_BIT(dmax_->HISR, DMA_HISR_FEIF5) == (DMA_HISR_FEIF5)) ? true : false);  
                break;
            case DMA_STREAM_6:
                bFlag = ((READ_BIT(dmax_->HISR, DMA_HISR_FEIF6) == (DMA_HISR_FEIF6)) ? true : false);
                break;
            case DMA_STREAM_7:
                bFlag = ((READ_BIT(dmax_->HISR, DMA_HISR_FEIF7) == (DMA_HISR_FEIF7)) ? true : false);
                break;
            default:
                bFlag = false;
                break;
        }
        return bFlag;
    }
    inline void dmaClearFlagTransferHalf()
    {
        switch (streamNum_)
        {
            case DMA_STREAM_0:
                WRITE_REG(dmax_->LIFCR, DMA_LIFCR_CHTIF0);
                break;
            case DMA_STREAM_1:
                WRITE_REG(dmax_->LIFCR, DMA_LIFCR_CHTIF1);
                break;
            case DMA_STREAM_2:
                WRITE_REG(dmax_->LIFCR, DMA_LIFCR_CHTIF2);
                break;
            case DMA_STREAM_3:
                WRITE_REG(dmax_->LIFCR, DMA_LIFCR_CHTIF3);
                break;
            case DMA_STREAM_4:
                WRITE_REG(dmax_->HIFCR, DMA_HIFCR_CHTIF4);
                break;
            case DMA_STREAM_5:
                WRITE_REG(dmax_->HIFCR, DMA_HIFCR_CHTIF5); 
                break;
            case DMA_STREAM_6:
                WRITE_REG(dmax_->HIFCR, DMA_HIFCR_CHTIF6);
                break;
            case DMA_STREAM_7:
                WRITE_REG(dmax_->HIFCR, DMA_HIFCR_CHTIF7);
                break;
            default:
                break;
        }
    }
    inline void dmaClearFlagTransferComplete()
    {
        switch (streamNum_)
        {
            case DMA_STREAM_0:
                WRITE_REG(dmax_->LIFCR, DMA_LIFCR_CTCIF0);
                break;
            case DMA_STREAM_1:
                WRITE_REG(dmax_->LIFCR, DMA_LIFCR_CTCIF1);
                break;
            case DMA_STREAM_2:
                WRITE_REG(dmax_->LIFCR, DMA_LIFCR_CTCIF2);
                break;
            case DMA_STREAM_3:
                WRITE_REG(dmax_->LIFCR, DMA_LIFCR_CTCIF3);
                break;
            case DMA_STREAM_4:
                WRITE_REG(dmax_->HIFCR, DMA_HIFCR_CTCIF4);
                break;
            case DMA_STREAM_5:
                WRITE_REG(dmax_->HIFCR, DMA_HIFCR_CTCIF5); 
                break;
            case DMA_STREAM_6:
                WRITE_REG(dmax_->HIFCR, DMA_HIFCR_CTCIF6);
                break;
            case DMA_STREAM_7:
                WRITE_REG(dmax_->HIFCR, DMA_HIFCR_CTCIF7);
                break;
            default:
                break;
        }
    }
    inline void dmaClearFlagTransferError()
    {
        switch (streamNum_)
        {
            case DMA_STREAM_0:
                WRITE_REG(dmax_->LIFCR, DMA_LIFCR_CTEIF0);
                break;
            case DMA_STREAM_1:
                WRITE_REG(dmax_->LIFCR, DMA_LIFCR_CTEIF1);
                break;
            case DMA_STREAM_2:
                WRITE_REG(dmax_->LIFCR, DMA_LIFCR_CTEIF2);
                break;
            case DMA_STREAM_3:
                WRITE_REG(dmax_->LIFCR, DMA_LIFCR_CTEIF3);
                break;
            case DMA_STREAM_4:
                WRITE_REG(dmax_->HIFCR, DMA_HIFCR_CTEIF4);
                break;
            case DMA_STREAM_5:
                WRITE_REG(dmax_->HIFCR, DMA_HIFCR_CTEIF5); 
                break;
            case DMA_STREAM_6:
                WRITE_REG(dmax_->HIFCR, DMA_HIFCR_CTEIF6);
                break;
            case DMA_STREAM_7:
                WRITE_REG(dmax_->HIFCR, DMA_HIFCR_CTEIF7);
                break;
            default:
                break;
        }
    }
    inline void dmaClearFlagDirectModeError()
    {
        switch (streamNum_)
        {
            case DMA_STREAM_0:
                WRITE_REG(dmax_->LIFCR, DMA_LIFCR_CDMEIF0);
                break;
            case DMA_STREAM_1:
                WRITE_REG(dmax_->LIFCR, DMA_LIFCR_CDMEIF1);
                break;
            case DMA_STREAM_2:
                WRITE_REG(dmax_->LIFCR, DMA_LIFCR_CDMEIF2);
                break;
            case DMA_STREAM_3:
                WRITE_REG(dmax_->LIFCR, DMA_LIFCR_CDMEIF3);
                break;
            case DMA_STREAM_4:
                WRITE_REG(dmax_->HIFCR, DMA_HIFCR_CDMEIF4);
                break;
            case DMA_STREAM_5:
                WRITE_REG(dmax_->HIFCR, DMA_HIFCR_CDMEIF5); 
                break;
            case DMA_STREAM_6:
                WRITE_REG(dmax_->HIFCR, DMA_HIFCR_CDMEIF6);
                break;
            case DMA_STREAM_7:
                WRITE_REG(dmax_->HIFCR, DMA_HIFCR_CDMEIF7);
                break;
            default:
                break;
        }
    }
    inline void dmaClearFlagFIFOError()
    {
        switch (streamNum_)
        {
            case DMA_STREAM_0:
                WRITE_REG(dmax_->LIFCR, DMA_LIFCR_CFEIF0);
                break;
            case DMA_STREAM_1:
                WRITE_REG(dmax_->LIFCR, DMA_LIFCR_CFEIF1);
                break;
            case DMA_STREAM_2:
                WRITE_REG(dmax_->LIFCR, DMA_LIFCR_CFEIF2);
                break;
            case DMA_STREAM_3:
                WRITE_REG(dmax_->LIFCR, DMA_LIFCR_CFEIF3);
                break;
            case DMA_STREAM_4:
                WRITE_REG(dmax_->HIFCR, DMA_HIFCR_CFEIF4);
                break;
            case DMA_STREAM_5:
                WRITE_REG(dmax_->HIFCR, DMA_HIFCR_CFEIF5); 
                break;
            case DMA_STREAM_6:
                WRITE_REG(dmax_->HIFCR, DMA_HIFCR_CFEIF6);
                break;
            case DMA_STREAM_7:
                WRITE_REG(dmax_->HIFCR, DMA_HIFCR_CFEIF7);
                break;
            default:
                break;
        }
    }
    inline void dmaEnableITTransterHalf()
    {
        SET_BIT(dmaStreamAddr_->CR, DMA_SxCR_HTIE);
    }
    inline void dmaEnableITTransterError()
    {
        SET_BIT(dmaStreamAddr_->CR, DMA_SxCR_TEIE);
    }
    inline void dmaEnableITTransferComplete()
    {
        SET_BIT(dmaStreamAddr_->CR, DMA_SxCR_TCIE);
    }
    inline void dmaEnableITDirectModeError()
    {
        SET_BIT(dmaStreamAddr_->CR, DMA_SxCR_DMEIE);
    }
    inline void dmaEnableITFIFOError()
    {
        SET_BIT(dmaStreamAddr_->FCR, DMA_SxFCR_FEIE);
    }
    inline void dmaDisableITTransterHalf()
    {
        CLEAR_BIT(dmaStreamAddr_->CR, DMA_SxCR_HTIE);
    }
    inline void dmaDisableITTransterError()
    {
        CLEAR_BIT(dmaStreamAddr_->CR, DMA_SxCR_TEIE);
    }
    inline void dmaDisableITTransferComplete()
    {
        CLEAR_BIT(dmaStreamAddr_->CR, DMA_SxCR_TCIE);
    }
    inline void dmaDisableITDirectModeError()
    {
        CLEAR_BIT(dmaStreamAddr_->CR, DMA_SxCR_DMEIE);
    }
    inline void dmaDisableITFIFOError()
    {
        CLEAR_BIT(dmaStreamAddr_->FCR, DMA_SxFCR_FEIE);
    }
    inline bool dmaIsEnabledITTransterHalf()
    {
        return ((READ_BIT(dmaStreamAddr_->CR, DMA_SxCR_HTIE) == DMA_SxCR_HTIE) ? true : false);
    }
    inline bool dmaIsEnabledITTransterError()
    {
        return ((READ_BIT(dmaStreamAddr_->CR, DMA_SxCR_TEIE) == DMA_SxCR_TEIE) ? true : false);
    }
    inline bool dmaIsEnabledITTransferComplete()
    {
        return ((READ_BIT(dmaStreamAddr_->CR, DMA_SxCR_TCIE) == DMA_SxCR_TCIE) ? true : false);
    }
    inline bool dmaIsEnabledITDirectModeError()
    {
        return ((READ_BIT(dmaStreamAddr_->CR, DMA_SxCR_DMEIE) == DMA_SxCR_DMEIE) ? true : false);
    }
    inline bool dmaIsEnabledITFIFOError()
    {
        return ((READ_BIT(dmaStreamAddr_->FCR, DMA_SxFCR_FEIE) == DMA_SxFCR_FEIE) ? true : false);
    }
    void enableDmaIsr(uint32_t PreemptPriority, uint32_t SubPriority)
    {
        if(NVIC_GetEnableIRQ(getIrqType()) == 0U)
        {
            NVIC_SetPriority(getIrqType(), NVIC_EncodePriority(NVIC_GetPriorityGrouping(), PreemptPriority, SubPriority));
            NVIC_EnableIRQ(getIrqType());
        }
    }
    void disableDmaIsr()
    {
        NVIC_DisableIRQ(getIrqType());
    }
    void registerInterruptCb(const DMAInterruptCb& isrcb)
    {
        dmacb_ = isrcb;
    }
    void unregisterInterruptCb()
    {
        if(dmacb_)
        {
            dmacb_ = DMAInterruptCb();
        }
    }
     void enableDMAMUXIsr(uint32_t PreemptPriority, uint32_t SubPriority)
    {
        if(NVIC_GetEnableIRQ(DMAMUX1_OVR_IRQn) == 0U)
        {
            NVIC_SetPriority(DMAMUX1_OVR_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), PreemptPriority, SubPriority));
            NVIC_EnableIRQ(DMAMUX1_OVR_IRQn);
        }
    }
    void disableDMAMUXIsr()
    {
        NVIC_DisableIRQ(DMAMUX1_OVR_IRQn);
    }
    void registerDMAMUXInterruptCb(const DMAMUXInterruptCb& isrcb)
    {
        dmamuxcb_ = isrcb;
    }
    void unregisterDMAMUXInterruptCb()
    {
        if(dmamuxcb_)
        {
            dmamuxcb_ = DMAMUXInterruptCb();
        }
    }
private:
    inline DMA_TypeDef* DMAGetInstance(DMA_Stream_TypeDef* stream)
    {
        return (((uint32_t)(stream) > ((uint32_t)DMA1_Stream7)) ?  DMA2 : DMA1);
    }
    inline DMAStreamNum DMAGetStreamIndex(DMA_Stream_TypeDef* stream)
    {
        return   \
        (((uint32_t)(stream) == ((uint32_t)DMA1_Stream0)) ? DMA_STREAM_0 : \
        ((uint32_t)(stream) == ((uint32_t)DMA2_Stream0)) ? DMA_STREAM_0 : \
        ((uint32_t)(stream) == ((uint32_t)DMA1_Stream1)) ? DMA_STREAM_1 : \
        ((uint32_t)(stream) == ((uint32_t)DMA2_Stream1)) ? DMA_STREAM_1 : \
        ((uint32_t)(stream) == ((uint32_t)DMA1_Stream2)) ? DMA_STREAM_2 : \
        ((uint32_t)(stream) == ((uint32_t)DMA2_Stream2)) ? DMA_STREAM_2 : \
        ((uint32_t)(stream) == ((uint32_t)DMA1_Stream3)) ? DMA_STREAM_3 : \
        ((uint32_t)(stream) == ((uint32_t)DMA2_Stream3)) ? DMA_STREAM_3 : \
        ((uint32_t)(stream) == ((uint32_t)DMA1_Stream4)) ? DMA_STREAM_4 : \
        ((uint32_t)(stream) == ((uint32_t)DMA2_Stream4)) ? DMA_STREAM_4 : \
        ((uint32_t)(stream) == ((uint32_t)DMA1_Stream5)) ? DMA_STREAM_5 : \
        ((uint32_t)(stream) == ((uint32_t)DMA2_Stream5)) ? DMA_STREAM_5 : \
        ((uint32_t)(stream) == ((uint32_t)DMA1_Stream6)) ? DMA_STREAM_6 : \
        ((uint32_t)(stream) == ((uint32_t)DMA2_Stream6)) ? DMA_STREAM_6 : \
        DMA_STREAM_7);
    };
    inline DMA_Stream_TypeDef* DMAGetStreamInstance(DMA_TypeDef* dma, DMAStreamNum dmaStream)
    {
        return \
        ((((uint32_t)(dma) == ((uint32_t)DMA1)) && ((uint32_t)(dmaStream) == ((uint32_t)DMA_STREAM_0))) ? DMA1_Stream0 : \
        (((uint32_t)(dma) == ((uint32_t)DMA2)) && ((uint32_t)(dmaStream) == ((uint32_t)DMA_STREAM_0))) ? DMA2_Stream0 : \
        (((uint32_t)(dma) == ((uint32_t)DMA1)) && ((uint32_t)(dmaStream) == ((uint32_t)DMA_STREAM_1))) ? DMA1_Stream1 : \
        (((uint32_t)(dma) == ((uint32_t)DMA2)) && ((uint32_t)(dmaStream) == ((uint32_t)DMA_STREAM_1))) ? DMA2_Stream1 : \
        (((uint32_t)(dma) == ((uint32_t)DMA1)) && ((uint32_t)(dmaStream) == ((uint32_t)DMA_STREAM_2))) ? DMA1_Stream2 : \
        (((uint32_t)(dma) == ((uint32_t)DMA2)) && ((uint32_t)(dmaStream) == ((uint32_t)DMA_STREAM_2))) ? DMA2_Stream2 : \
        (((uint32_t)(dma) == ((uint32_t)DMA1)) && ((uint32_t)(dmaStream) == ((uint32_t)DMA_STREAM_3))) ? DMA1_Stream3 : \
        (((uint32_t)(dma) == ((uint32_t)DMA2)) && ((uint32_t)(dmaStream) == ((uint32_t)DMA_STREAM_3))) ? DMA2_Stream3 : \
        (((uint32_t)(dma) == ((uint32_t)DMA1)) && ((uint32_t)(dmaStream) == ((uint32_t)DMA_STREAM_4))) ? DMA1_Stream4 : \
        (((uint32_t)(dma) == ((uint32_t)DMA2)) && ((uint32_t)(dmaStream) == ((uint32_t)DMA_STREAM_4))) ? DMA2_Stream4 : \
        (((uint32_t)(dma) == ((uint32_t)DMA1)) && ((uint32_t)(dmaStream) == ((uint32_t)DMA_STREAM_5))) ? DMA1_Stream5 : \
        (((uint32_t)(dma) == ((uint32_t)DMA2)) && ((uint32_t)(dmaStream) == ((uint32_t)DMA_STREAM_5))) ? DMA2_Stream5 : \
        (((uint32_t)(dma) == ((uint32_t)DMA1)) && ((uint32_t)(dmaStream) == ((uint32_t)DMA_STREAM_6))) ? DMA1_Stream6 : \
        (((uint32_t)(dma) == ((uint32_t)DMA2)) && ((uint32_t)(dmaStream) == ((uint32_t)DMA_STREAM_6))) ? DMA2_Stream6 : \
        (((uint32_t)(dma) == ((uint32_t)DMA1)) && ((uint32_t)(dmaStream) == ((uint32_t)DMA_STREAM_7))) ? DMA1_Stream7 : \
        DMA2_Stream7);
    }
    IRQn_Type getIrqType()
    {
        IRQn_Type irqtype = DMA1_Stream0_IRQn;
        switch (reinterpret_cast<uint32_t>(dmaStreamAddr_))
        {
            case (uint32_t)DMA1_Stream0_BASE:
                irqtype = DMA1_Stream0_IRQn;
                break;
            case (uint32_t)DMA1_Stream1_BASE:
                irqtype = DMA1_Stream1_IRQn;
                break;
            case (uint32_t)DMA1_Stream2_BASE:
                irqtype = DMA1_Stream2_IRQn;
                break;
            case (uint32_t)DMA1_Stream3_BASE:
                irqtype = DMA1_Stream3_IRQn;
                break;
            case (uint32_t)DMA1_Stream4_BASE:
                irqtype = DMA1_Stream4_IRQn;
                break;
            case (uint32_t)DMA1_Stream5_BASE:
                irqtype = DMA1_Stream5_IRQn;
                break;
            case (uint32_t)DMA1_Stream6_BASE:
                irqtype = DMA1_Stream6_IRQn;
                break;
            case (uint32_t)DMA1_Stream7_BASE:
                irqtype = DMA1_Stream7_IRQn;
                break;
            case (uint32_t)DMA2_Stream0_BASE:
                irqtype = DMA2_Stream0_IRQn;
                break;
            case (uint32_t)DMA2_Stream1_BASE:
                irqtype = DMA2_Stream1_IRQn;
                break;
            case (uint32_t)DMA2_Stream2_BASE:
                irqtype = DMA2_Stream2_IRQn;
                break;
            case (uint32_t)DMA2_Stream3_BASE:
                irqtype = DMA2_Stream3_IRQn;
                break;
            case (uint32_t)DMA2_Stream4_BASE:
                irqtype = DMA2_Stream4_IRQn;
                break;
            case (uint32_t)DMA2_Stream5_BASE:
                irqtype = DMA2_Stream5_IRQn;
                break;
            case (uint32_t)DMA2_Stream6_BASE:
                irqtype = DMA2_Stream6_IRQn;
                break;
            case (uint32_t)DMA2_Stream7_BASE:
                irqtype = DMA2_Stream7_IRQn;
                break;
            default:
                break;
        }
        return irqtype;
    }
private:
    DMA_TypeDef *dmax_;
    DMA_Stream_TypeDef * dmaStreamAddr_;
    DMAStreamNum streamNum_;
    DMA_InitTypeDef handle_;
    DMAInterruptCb dmacb_;
    DMAMUXInterruptCb dmamuxcb_;
};

class BDMAX : public DMAMUX
{
    using BDMAInterruptCb = std::function<void(BDMAX*, BDMATransferIsrType)>;
    using BDMAMUXInterruptCb = std::function<void(BDMAX*, DMAMUXOverRunType)>;
public:
    BDMAX(BDMA_TypeDef* bdmax, BDMAChannelNum channelNum) : DMAMUX(DMAMUX2, channelNum)
    {
        bdmax_ = bdmax;
        channelNum_ = channelNum;
        bdmaChannelAddr_ = ((BDMA_Channel_TypeDef *)((uint32_t)(bdmax_) + BDMA_CH_OFFSET_TAB[channelNum_]));
        RCCControl::getInstance()->AHB4GRP1EnableClock(RCC_AHB4_GRP1_PERIPH_BDMA);
    }
    ~BDMAX()
    {
    }
    BDMAX(const BDMAX&) = delete;
    BDMAX(DMA&&) = delete;
    BDMAX& operator=(const BDMAX&) = delete;
    BDMAX& operator=(BDMAX&&) = delete;
    eResult bdmaInit(BDMAInitTypeDef *BDMA_InitStruct)
    {
        /*---------------------------- DMAx CCR Configuration ------------------------
        * Configure DMAx_Channely: data transfer direction, data transfer mode,
        *                          peripheral and memory increment mode,
        *                          data size alignment and  priority level with parameters :
        * - Direction:      BDMA_CCR_DIR and BDMA_CCR_MEM2MEM bits
        * - Mode:           BDMA_CCR_CIRC bit
        * - PeriphOrM2MSrcIncMode:  BDMA_CCR_PINC bit
        * - MemoryOrM2MDstIncMode:  BDMA_CCR_MINC bit
        * - PeriphOrM2MSrcDataSize: BDMA_CCR_PSIZE[1:0] bits
        * - MemoryOrM2MDstDataSize: BDMA_CCR_MSIZE[1:0] bits
        * - Priority:               BDMA_CCR_PL[1:0] bits
        */
        bdmaConfigTransfer(BDMA_InitStruct->Direction                   | \
                                BDMA_InitStruct->Mode                   | \
                                BDMA_InitStruct->PeriphOrM2MSrcIncMode  | \
                                BDMA_InitStruct->MemoryOrM2MDstIncMode  | \
                                BDMA_InitStruct->PeriphOrM2MSrcDataSize | \
                                BDMA_InitStruct->MemoryOrM2MDstDataSize | \
                                BDMA_InitStruct->Priority);

        /*-------------------------- DMAx CMAR Configuration -------------------------
        * Configure the memory or destination base address with parameter :
        * - MemoryOrM2MDstAddress: BDMA_CMAR_MA[31:0] bits
        */
        bdmaSetMemoryAddress(BDMA_InitStruct->MemoryOrM2MDstAddress);

        /*-------------------------- DMAx CPAR Configuration -------------------------
        * Configure the peripheral or source base address with parameter :
        * - PeriphOrM2MSrcAddress: BDMA_CPAR_PA[31:0] bits
        */
        bdmaSetPeriphAddress(BDMA_InitStruct->PeriphOrM2MSrcAddress);

        /*--------------------------- DMAx CNDTR Configuration -----------------------
        * Configure the peripheral base address with parameter :
        * - NbData: BDMA_CNDTR_NDT[15:0] bits
        */
        bdmaSetDataLength(BDMA_InitStruct->NbData);

        /*--------------------------- DMAMUXx CCR Configuration ----------------------
        * Configure the DMA request for DMA Channels on DMAMUX Channel x with parameter :
        * - PeriphRequest: BDMA_CxCR[7:0] bits
        */
        bdmaSetPeriphRequest(BDMA_InitStruct->PeriphRequest);

        if(BDMA_InitStruct->PeriphRequest >= DMAMUX2_REQ_GENERATOR0 && BDMA_InitStruct->PeriphRequest <= DMAMUX2_REQ_GENERATOR7)
        {
            initDmaMuxReqGenChannelNum((DMAMUXReqGenChannel)(BDMA_InitStruct->PeriphRequest - 1));
        }
        registerBDMAIsrCb(bdmaChannelAddr_, [](void* param, uint8_t bBDMAMuxISR, uint32_t isrtype){
            BDMAX* pbdma = reinterpret_cast<BDMAX*>(param);
            if(pbdma)
            {
                if(!bBDMAMuxISR)
                {
                    if(pbdma->bdmacb_)
                    {
                        pbdma->bdmacb_(pbdma, (BDMATransferIsrType)isrtype);
                    }
                }
                else
                {
                    if(pbdma->dmaMuxIsEnabledITReqGenTrigEventOverrun() && pbdma->dmaMuxIsActiveFlagReqGenTrigEventOverrun())
                    {
                        pbdma->dmaMuxClearFlagReqGenTrigEventOverrun();
                        if(pbdma->bdmamuxcb_)
                        {
                            pbdma->bdmamuxcb_(pbdma, DMAMUX_OVERRUN_TYPE_GEN);
                        }
                    }
                    else if(pbdma->dmaMuxIsEnabledITSyncEventOverrun() && pbdma->dmaMuxIsActiveFlagSyncEventOverrun())
                    {
                        pbdma->dmaMuxClearFlagSyncEventOverrun();
                        if(pbdma->bdmamuxcb_)
                        {
                            pbdma->bdmamuxcb_(pbdma, DMAMUX_OVERRUN_TYPE_SYNC);
                        }
                    }
                }
            }
        }, this);
        return E_RESULT_OK;
    }
    eResult bdmaDeInit()
    {
        /* Disable the selected DMAx_Channely */
        bdmaDisableChannel();
        /* Reset DMAx_Channely control register */
        WRITE_REG(bdmaChannelAddr_->CCR, 0U);

        /* Reset DMAx_Channely remaining bytes register */
        WRITE_REG(bdmaChannelAddr_->CNDTR, 0U);

        /* Reset DMAx_Channely peripheral address register */
        WRITE_REG(bdmaChannelAddr_->CPAR, 0U);

        /* Reset DMAx_Channely memory 0 address register */
        WRITE_REG(bdmaChannelAddr_->CM0AR, 0U);

        /* Reset DMAx_Channely memory 1 address register */
        WRITE_REG(bdmaChannelAddr_->CM1AR, 0U);

        /* Reset Request register field for BDMAx Channel */
        bdmaSetPeriphRequest(DMAMUX2_REQ_MEM2MEM);
        bdmaClearFlagGlobalIsr();
        return E_RESULT_OK;
    }
    inline void bdmaEnableChannel()
    {
        SET_BIT(bdmaChannelAddr_->CCR, BDMA_CCR_EN);
    }
    inline void bdmaDisableChannel()
    {
        CLEAR_BIT(bdmaChannelAddr_->CCR, BDMA_CCR_EN);
    }
    inline bool bdmaIsEnabledChannel()
    {
    return ((READ_BIT(bdmaChannelAddr_->CCR, BDMA_CCR_EN) == (BDMA_CCR_EN)) ? true : false);
    }
    inline void bdmaConfigTransfer(uint32_t Configuration)
    {
        MODIFY_REG(bdmaChannelAddr_->CCR,
                    BDMA_CCR_DIR | BDMA_CCR_MEM2MEM | BDMA_CCR_CIRC | BDMA_CCR_PINC | BDMA_CCR_MINC | BDMA_CCR_PSIZE | BDMA_CCR_MSIZE | BDMA_CCR_PL,
                    Configuration);
    }
    inline void bdmaSetDataTransferDirection(BDMADirection Direction)
    {
        MODIFY_REG(bdmaChannelAddr_->CCR, BDMA_CCR_DIR | BDMA_CCR_MEM2MEM, Direction);
    }
    inline BDMADirection bdmaGetDataTransferDirection()
    {
        return (BDMADirection)(READ_BIT(bdmaChannelAddr_->CCR, BDMA_CCR_DIR | BDMA_CCR_MEM2MEM));
    }
    inline void bdmaSetMode(BDMAMode Mode)
    {
        MODIFY_REG(bdmaChannelAddr_->CCR, BDMA_CCR_CIRC, Mode);
    }
    inline BDMAMode bdmaGetMode()
    {
        return (BDMAMode)(READ_BIT(bdmaChannelAddr_->CCR,  BDMA_CCR_CIRC));
    }
    inline void bdmaSetPeriphIncMode(BDMAPeriphIncMode PeriphOrM2MSrcIncMode)
    {
        MODIFY_REG(bdmaChannelAddr_->CCR, BDMA_CCR_PINC, PeriphOrM2MSrcIncMode);
    }
    inline BDMAPeriphIncMode bdmaGetPeriphIncMode()
    {
        return (BDMAPeriphIncMode)(READ_BIT(bdmaChannelAddr_->CCR, BDMA_CCR_PINC));
    }
    inline void bdmaSetMemoryIncMode(BDMAMemoryIncMode MemoryOrM2MDstIncMode)
    {
        MODIFY_REG(bdmaChannelAddr_->CCR, BDMA_CCR_MINC,  MemoryOrM2MDstIncMode);
    }
    inline BDMAMemoryIncMode bdmaGetMemoryIncMode()
    {
        return (BDMAMemoryIncMode)(READ_BIT(bdmaChannelAddr_->CCR, BDMA_CCR_MINC));
    }
    inline void bdmaSetPeriphSize(BDMAPeriphDataAlign PeriphOrM2MSrcDataSize)
    {
        MODIFY_REG(bdmaChannelAddr_->CCR, BDMA_CCR_PSIZE, PeriphOrM2MSrcDataSize);
    }
    inline BDMAPeriphDataAlign bdmaGetPeriphSize()
    {
        return (BDMAPeriphDataAlign)(READ_BIT(bdmaChannelAddr_->CCR,  BDMA_CCR_PSIZE));
    }
    inline void bdmaSetMemorySize(BDMAMemoryDataAlign MemoryOrM2MDstDataSize)
    {
        MODIFY_REG(bdmaChannelAddr_->CCR, BDMA_CCR_MSIZE, MemoryOrM2MDstDataSize);
    }
    inline BDMAMemoryDataAlign bdmaGetMemorySize()
    {
        return (BDMAMemoryDataAlign)(READ_BIT(bdmaChannelAddr_->CCR, BDMA_CCR_MSIZE));
    }
    inline void bdmaSetChannelPriorityLevel(BDMAPriority Priority)
    {
        MODIFY_REG(bdmaChannelAddr_->CCR, BDMA_CCR_PL, Priority);
    }
    inline BDMAPriority bdmaGetChannelPriorityLevel()
    {
        return (BDMAPriority)(READ_BIT(bdmaChannelAddr_->CCR, BDMA_CCR_PL));
    }
    inline void bdmaSetDataLength(uint32_t NbData)
    {
        MODIFY_REG(bdmaChannelAddr_->CNDTR, BDMA_CNDTR_NDT, NbData);
    }
    inline uint32_t bdmaGetDataLength()
    {
        return (READ_BIT(bdmaChannelAddr_->CNDTR, BDMA_CNDTR_NDT));
    }
    inline void bdmaSetCurrentTargetMem(BDMACurrentTargetMemory CurrentMemory)
    {
        MODIFY_REG(bdmaChannelAddr_->CCR, BDMA_CCR_CT, CurrentMemory);
    }
    inline BDMACurrentTargetMemory bdmaGetCurrentTargetMem()
    {
        return (BDMACurrentTargetMemory)(READ_BIT(bdmaChannelAddr_->CCR, BDMA_CCR_CT));
    }
    inline void bdmaEnableDoubleBufferMode()
    {
        SET_BIT(bdmaChannelAddr_->CCR, BDMA_CCR_DBM);
    }
    inline void bdmaDisableDoubleBufferMode()
    {
        CLEAR_BIT(bdmaChannelAddr_->CCR, BDMA_CCR_DBM);
    }
    inline void bdmaConfigAddresses(uint32_t SrcAddress, uint32_t DstAddress, BDMADirection Direction)
    {
        /* Direction Memory to Periph */
        if (Direction == BDMA_DIRECTION_MEMORY_TO_PERIPH)
        {
            WRITE_REG(bdmaChannelAddr_->CM0AR, SrcAddress);
            WRITE_REG(bdmaChannelAddr_->CPAR, DstAddress);
        }
        /* Direction Periph to Memory and Memory to Memory */
        else
        {
            WRITE_REG(bdmaChannelAddr_->CPAR, SrcAddress);
            WRITE_REG(bdmaChannelAddr_->CM0AR, DstAddress);
        }
    }
    inline void bdmaSetMemoryAddress(uint32_t MemoryAddress)
    {
        WRITE_REG(bdmaChannelAddr_->CM0AR, MemoryAddress);
    }
    inline void bdmaSetPeriphAddress(uint32_t PeriphAddress)
    {
        WRITE_REG(bdmaChannelAddr_->CPAR, PeriphAddress);
    }
    inline uint32_t bdmaGetMemoryAddress()
    {
        return (READ_REG(bdmaChannelAddr_->CM0AR));
    }
    inline uint32_t bdmaGetPeriphAddress()
    {
        return (READ_REG(bdmaChannelAddr_->CPAR));
    }

/**
  * @brief  Set the Memory to Memory Source address.
  */
    inline void bdmaSetM2MSrcAddress(uint32_t MemoryAddress)
    {
        WRITE_REG(bdmaChannelAddr_->CPAR, MemoryAddress);
    }

/**
  * @brief  Set the Memory to Memory Destination address.
  */
    inline void bdmaSetM2MDstAddress(uint32_t MemoryAddress)
    {
        WRITE_REG(bdmaChannelAddr_->CM0AR, MemoryAddress);
    }
    inline uint32_t bdmaGetM2MSrcAddress()
    {
        return (READ_REG(bdmaChannelAddr_->CPAR));
    }
    inline uint32_t bdmaGetM2MDstAddress()
    {
        return (READ_REG(bdmaChannelAddr_->CM0AR));
    }

/**
  * @brief Set Memory 1 address (used in case of Double buffer mode).
  */
    inline void bdmaSetMemory1Address(uint32_t Address)
    {
        MODIFY_REG(bdmaChannelAddr_->CM1AR, BDMA_CM1AR_MA, Address);
    }

/**
  * @brief Get Memory 1 address (used in case of Double buffer mode).
  */
    inline uint32_t bdmaGetMemory1Address()
    {
        return (bdmaChannelAddr_->CM1AR);
    }
    inline void bdmaSetPeriphRequest(DMAMUX2Requests Request)
    {
        MODIFY_REG(getDmaMuxChannel()->CCR, DMAMUX_CxCR_DMAREQ_ID, Request);
    }
    inline DMAMUX2Requests bdmaGetPeriphRequest()
    {
        return (DMAMUX2Requests)(READ_BIT(getDmaMuxChannel()->CCR, DMAMUX_CxCR_DMAREQ_ID));
    }
    inline void dmaMuxSetSyncID(DMAMUX2SyncSignalEventID SyncID)
    {
        MODIFY_REG(getDmaMuxChannel()->CCR, DMAMUX_CxCR_SYNC_ID, SyncID);
    }
    inline DMAMUX2SyncSignalEventID dmaMuxGetSyncID()
    {
        return (DMAMUX2SyncSignalEventID)(READ_BIT(getDmaMuxChannel()->CCR, DMAMUX_CxCR_SYNC_ID));
    }
    inline void dmaMuxSetRequestSignalID(DMAMUX2ExtReqSignalGenID RequestSignalID)
    {
        MODIFY_REG(getDMAMUXRequestGenChannelAddr()->RGCR, DMAMUX_RGxCR_SIG_ID, RequestSignalID);
    }
    inline DMAMUX2ExtReqSignalGenID dmaMuxGetRequestSignalID()
    {
        return (DMAMUX2ExtReqSignalGenID)(READ_BIT(getDMAMUXRequestGenChannelAddr()->RGCR, DMAMUX_RGxCR_SIG_ID));
    }
/** @defgroup BDMA_LL_EF_FLAG_Management FLAG_Management
  * @{
  */
/**
  * @brief  Get Channel 0 global interrupt flag.
  * @rmtoll ISR          GIF0          bdmaIsActiveFlag_GI0
  * @param  BDMAx BDMA Instance
  * @retval State of bit (1 or 0).
  */

    inline bool bdmaIsActiveFlagGlobalIsr()
    {
        bool bFlag = false;
        switch(channelNum_)
        {
            case BDMA_CHANNEL_0:
                bFlag = ((READ_BIT(bdmax_->ISR, BDMA_ISR_GIF0) == (BDMA_ISR_GIF0)) ? true : false);
                break;
            case BDMA_CHANNEL_1:
                bFlag = ((READ_BIT(bdmax_->ISR, BDMA_ISR_GIF1) == (BDMA_ISR_GIF1)) ? true : false);
                break;
            case BDMA_CHANNEL_2:
                bFlag = ((READ_BIT(bdmax_->ISR, BDMA_ISR_GIF2) == (BDMA_ISR_GIF2)) ? true : false);
                break;
            case BDMA_CHANNEL_3:
                bFlag = ((READ_BIT(bdmax_->ISR, BDMA_ISR_GIF3) == (BDMA_ISR_GIF3)) ? true : false);
                break;
            case BDMA_CHANNEL_4:
                bFlag = ((READ_BIT(bdmax_->ISR, BDMA_ISR_GIF4) == (BDMA_ISR_GIF4)) ? true : false);
                break;
            case BDMA_CHANNEL_5:
                bFlag = ((READ_BIT(bdmax_->ISR, BDMA_ISR_GIF5) == (BDMA_ISR_GIF5)) ? true : false);
                break;
            case BDMA_CHANNEL_6:
                bFlag = ((READ_BIT(bdmax_->ISR, BDMA_ISR_GIF6) == (BDMA_ISR_GIF6)) ? true : false);
                break;
            case BDMA_CHANNEL_7:
                bFlag = ((READ_BIT(bdmax_->ISR, BDMA_ISR_GIF7) == (BDMA_ISR_GIF7)) ? true : false);
                break;
            default:
                bFlag = false;
                break;
        }
        return bFlag;
    }
    inline bool bdmaIsActiveFlagTransterComplete()
    {
        bool bFlag = false;
        switch(channelNum_)
        {
            case BDMA_CHANNEL_0:
                bFlag = ((READ_BIT(bdmax_->ISR, BDMA_ISR_TCIF0) == (BDMA_ISR_TCIF0)) ? true : false);
                break;
            case BDMA_CHANNEL_1:
                bFlag = ((READ_BIT(bdmax_->ISR, BDMA_ISR_TCIF1) == (BDMA_ISR_TCIF1)) ? true : false);
                break;
            case BDMA_CHANNEL_2:
                bFlag = ((READ_BIT(bdmax_->ISR, BDMA_ISR_TCIF2) == (BDMA_ISR_TCIF2)) ? true : false);
                break;
            case BDMA_CHANNEL_3:
                bFlag = ((READ_BIT(bdmax_->ISR, BDMA_ISR_TCIF3) == (BDMA_ISR_TCIF3)) ? true : false);
                break;
            case BDMA_CHANNEL_4:
                bFlag = ((READ_BIT(bdmax_->ISR, BDMA_ISR_TCIF4) == (BDMA_ISR_TCIF4)) ? true : false);
                break;
            case BDMA_CHANNEL_5:
                bFlag = ((READ_BIT(bdmax_->ISR, BDMA_ISR_TCIF5) == (BDMA_ISR_TCIF5)) ? true : false);
                break;
            case BDMA_CHANNEL_6:
                bFlag = ((READ_BIT(bdmax_->ISR, BDMA_ISR_TCIF6) == (BDMA_ISR_TCIF6)) ? true : false);
                break;
            case BDMA_CHANNEL_7:
                bFlag = ((READ_BIT(bdmax_->ISR, BDMA_ISR_TCIF7) == (BDMA_ISR_TCIF7)) ? true : false);
                break;
            default:
                bFlag = false;
                break;
        }
        return bFlag;
    }
    inline bool bdmaIsActiveFlagTransterHalf()
    {
        bool bFlag = false;
        switch(channelNum_)
        {
            case BDMA_CHANNEL_0:
                bFlag = ((READ_BIT(bdmax_->ISR, BDMA_ISR_HTIF0) == (BDMA_ISR_HTIF0)) ? true : false);
                break;
            case BDMA_CHANNEL_1:
                bFlag = ((READ_BIT(bdmax_->ISR, BDMA_ISR_HTIF1) == (BDMA_ISR_HTIF1)) ? true : false);
                break;
            case BDMA_CHANNEL_2:
                bFlag = ((READ_BIT(bdmax_->ISR, BDMA_ISR_HTIF2) == (BDMA_ISR_HTIF2)) ? true : false);
                break;
            case BDMA_CHANNEL_3:
                bFlag = ((READ_BIT(bdmax_->ISR, BDMA_ISR_HTIF3) == (BDMA_ISR_HTIF3)) ? true : false);
                break;
            case BDMA_CHANNEL_4:
                bFlag = ((READ_BIT(bdmax_->ISR, BDMA_ISR_HTIF4) == (BDMA_ISR_HTIF4)) ? true : false);
                break;
            case BDMA_CHANNEL_5:
                bFlag = ((READ_BIT(bdmax_->ISR, BDMA_ISR_HTIF5) == (BDMA_ISR_HTIF5)) ? true : false);
                break;
            case BDMA_CHANNEL_6:
                bFlag = ((READ_BIT(bdmax_->ISR, BDMA_ISR_HTIF6) == (BDMA_ISR_HTIF6)) ? true : false);
                break;
            case BDMA_CHANNEL_7:
                bFlag = ((READ_BIT(bdmax_->ISR, BDMA_ISR_HTIF7) == (BDMA_ISR_HTIF7)) ? true : false);
                break;
            default:
                bFlag = false;
                break;
        }
        return bFlag;
    }
    inline bool bdmaIsActiveFlagTransterError()
    {
        bool bFlag = false;
        switch(channelNum_)
        {
            case BDMA_CHANNEL_0:
                bFlag = ((READ_BIT(bdmax_->ISR, BDMA_ISR_TEIF0) == (BDMA_ISR_TEIF0)) ? true : false);
                break;
            case BDMA_CHANNEL_1:
                bFlag = ((READ_BIT(bdmax_->ISR, BDMA_ISR_TEIF1) == (BDMA_ISR_TEIF1)) ? true : false);
                break;
            case BDMA_CHANNEL_2:
                bFlag = ((READ_BIT(bdmax_->ISR, BDMA_ISR_TEIF2) == (BDMA_ISR_TEIF2)) ? true : false);
                break;
            case BDMA_CHANNEL_3:
                bFlag = ((READ_BIT(bdmax_->ISR, BDMA_ISR_TEIF3) == (BDMA_ISR_TEIF3)) ? true : false);
                break;
            case BDMA_CHANNEL_4:
                bFlag = ((READ_BIT(bdmax_->ISR, BDMA_ISR_TEIF4) == (BDMA_ISR_TEIF4)) ? true : false);
                break;
            case BDMA_CHANNEL_5:
                bFlag = ((READ_BIT(bdmax_->ISR, BDMA_ISR_TEIF5) == (BDMA_ISR_TEIF5)) ? true : false);
                break;
            case BDMA_CHANNEL_6:
                bFlag = ((READ_BIT(bdmax_->ISR, BDMA_ISR_TEIF6) == (BDMA_ISR_TEIF6)) ? true : false);
                break;
            case BDMA_CHANNEL_7:
                bFlag = ((READ_BIT(bdmax_->ISR, BDMA_ISR_TEIF7) == (BDMA_ISR_TEIF7)) ? true : false);
                break;
            default:
                bFlag = false;
                break;
        }
        return bFlag;
    }
/**
  * @brief  Clear Channel 0 global interrupt flag.
  * @note Do not Clear Channel 0 global interrupt flag when the channel in ON.
    Instead clear specific flags transfer complete, half transfer & transfer
    error flag with LL_DMA_ClearFlag_TC0, LL_DMA_ClearFlag_HT0,
    LL_DMA_ClearFlag_TE0. bug id 2.3.1 in Product Errata Sheet.
  * @rmtoll IFCR         CGIF0         bdmaClearFlag_GI0
  * @param  BDMAx BDMA Instance
  * @retval None
  */
    inline void bdmaClearFlagGlobalIsr()
    {
        switch(channelNum_)
        {
            case BDMA_CHANNEL_0:
                WRITE_REG(bdmax_->IFCR, BDMA_IFCR_CGIF0);
                break;
            case BDMA_CHANNEL_1:
                WRITE_REG(bdmax_->IFCR, BDMA_IFCR_CGIF1);
                break;
            case BDMA_CHANNEL_2:
                WRITE_REG(bdmax_->IFCR, BDMA_IFCR_CGIF2);
                break;
            case BDMA_CHANNEL_3:
                WRITE_REG(bdmax_->IFCR, BDMA_IFCR_CGIF3);
                break;
            case BDMA_CHANNEL_4:
                WRITE_REG(bdmax_->IFCR, BDMA_IFCR_CGIF4);
                break;
            case BDMA_CHANNEL_5:
                WRITE_REG(bdmax_->IFCR, BDMA_IFCR_CGIF5);
                break;
            case BDMA_CHANNEL_6:
                WRITE_REG(bdmax_->IFCR, BDMA_IFCR_CGIF6);
                break;
            case BDMA_CHANNEL_7:
                WRITE_REG(bdmax_->IFCR, BDMA_IFCR_CGIF7);
                break;
            default:
                break;
        }
    }
    inline void bdmaClearFlagTransferComplete()
    {
        switch(channelNum_)
        {
            case BDMA_CHANNEL_0:
                WRITE_REG(bdmax_->IFCR, BDMA_IFCR_CTCIF0);
                break;
            case BDMA_CHANNEL_1:
                WRITE_REG(bdmax_->IFCR, BDMA_IFCR_CTCIF1);
                break;
            case BDMA_CHANNEL_2:
                WRITE_REG(bdmax_->IFCR, BDMA_IFCR_CTCIF2);
                break;
            case BDMA_CHANNEL_3:
                WRITE_REG(bdmax_->IFCR, BDMA_IFCR_CTCIF3);
                break;
            case BDMA_CHANNEL_4:
                WRITE_REG(bdmax_->IFCR, BDMA_IFCR_CTCIF4);
                break;
            case BDMA_CHANNEL_5:
                WRITE_REG(bdmax_->IFCR, BDMA_IFCR_CTCIF5);
                break;
            case BDMA_CHANNEL_6:
                WRITE_REG(bdmax_->IFCR, BDMA_IFCR_CTCIF6);
                break;
            case BDMA_CHANNEL_7:
                WRITE_REG(bdmax_->IFCR, BDMA_IFCR_CTCIF7);
                break;
            default:
                break;
        }
    }
    inline void bdmaClearFlagTransferHalf()
    {
        switch(channelNum_)
        {
            case BDMA_CHANNEL_0:
                WRITE_REG(bdmax_->IFCR, BDMA_IFCR_CHTIF0);
                break;
            case BDMA_CHANNEL_1:
                WRITE_REG(bdmax_->IFCR, BDMA_IFCR_CHTIF1);
                break;
            case BDMA_CHANNEL_2:
                WRITE_REG(bdmax_->IFCR, BDMA_IFCR_CHTIF2);
                break;
            case BDMA_CHANNEL_3:
                WRITE_REG(bdmax_->IFCR, BDMA_IFCR_CHTIF3);
                break;
            case BDMA_CHANNEL_4:
                WRITE_REG(bdmax_->IFCR, BDMA_IFCR_CHTIF4);
                break;
            case BDMA_CHANNEL_5:
                WRITE_REG(bdmax_->IFCR, BDMA_IFCR_CHTIF5);
                break;
            case BDMA_CHANNEL_6:
                WRITE_REG(bdmax_->IFCR, BDMA_IFCR_CHTIF6);
                break;
            case BDMA_CHANNEL_7:
                WRITE_REG(bdmax_->IFCR, BDMA_IFCR_CHTIF7);
                break;
            default:
                break;
        }
    }
    inline void bdmaClearFlagTransferError()
    {
        switch(channelNum_)
        {
            case BDMA_CHANNEL_0:
                WRITE_REG(bdmax_->IFCR, BDMA_IFCR_CTEIF0);
                break;
            case BDMA_CHANNEL_1:
                WRITE_REG(bdmax_->IFCR, BDMA_IFCR_CTEIF1);
                break;
            case BDMA_CHANNEL_2:
                WRITE_REG(bdmax_->IFCR, BDMA_IFCR_CTEIF2);
                break;
            case BDMA_CHANNEL_3:
                WRITE_REG(bdmax_->IFCR, BDMA_IFCR_CTEIF3);
                break;
            case BDMA_CHANNEL_4:
                WRITE_REG(bdmax_->IFCR, BDMA_IFCR_CTEIF4);
                break;
            case BDMA_CHANNEL_5:
                WRITE_REG(bdmax_->IFCR, BDMA_IFCR_CTEIF5);
                break;
            case BDMA_CHANNEL_6:
                WRITE_REG(bdmax_->IFCR, BDMA_IFCR_CTEIF6);
                break;
            case BDMA_CHANNEL_7:
                WRITE_REG(bdmax_->IFCR, BDMA_IFCR_CTEIF7);
                break;
            default:
                break;
        }
    }
    inline void bdmaEnableITTransferComplete()
    {
        SET_BIT(bdmaChannelAddr_->CCR, BDMA_CCR_TCIE);
    }
    inline void bdmaEnableITTransferHalf()
    {
        SET_BIT(bdmaChannelAddr_->CCR, BDMA_CCR_HTIE);
    }
    inline void bdmaEnableITTransterError()
    {
        SET_BIT(bdmaChannelAddr_->CCR, BDMA_CCR_TEIE);
    }
    inline void bdmaDisableITTransferComplete()
    {
        CLEAR_BIT(bdmaChannelAddr_->CCR, BDMA_CCR_TCIE);
    }
    inline void bdmaDisableITTransferHalf()
    {
        CLEAR_BIT(bdmaChannelAddr_->CCR, BDMA_CCR_HTIE);
    }
    inline void bdmaDisableITTransterError()
    {
        CLEAR_BIT(bdmaChannelAddr_->CCR, BDMA_CCR_TEIE);
    }
    inline bool bdmaIsEnabledITTransferComplete()
    {
        return ((READ_BIT(bdmaChannelAddr_->CCR, BDMA_CCR_TCIE) == (BDMA_CCR_TCIE)) ? true : false);
    }
    inline bool bdmaIsEnabledITTransferHalf()
    {
        return ((READ_BIT(bdmaChannelAddr_->CCR, BDMA_CCR_HTIE) == (BDMA_CCR_HTIE)) ? true : false);
    }
    inline bool bdmaIsEnabledITTransterError()
    {
      return ((READ_BIT(bdmaChannelAddr_->CCR, BDMA_CCR_TEIE) == (BDMA_CCR_TEIE)) ? true : false);
    }
    void enableBdmaIsr(uint32_t PreemptPriority, uint32_t SubPriority)
    {
        if(NVIC_GetEnableIRQ(getIrqType()) == 0U)
        {
            NVIC_SetPriority(getIrqType(), NVIC_EncodePriority(NVIC_GetPriorityGrouping(), PreemptPriority, SubPriority));
            NVIC_EnableIRQ(getIrqType());
        }
    }
    void disableBdmaIsr()
    {
        NVIC_DisableIRQ(getIrqType());
    }
    void registerInterruptCb(const BDMAInterruptCb& isrcb)
    {
        bdmacb_ = isrcb;
    }
    void unregisterInterruptCb()
    {
        if(bdmacb_)
        {
            bdmacb_ = BDMAInterruptCb();
        }
    }
     void enableDMAMUXIsr(uint32_t PreemptPriority, uint32_t SubPriority)
    {
        if(NVIC_GetEnableIRQ(DMAMUX2_OVR_IRQn) == 0U)
        {
            NVIC_SetPriority(DMAMUX2_OVR_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), PreemptPriority, SubPriority));
            NVIC_EnableIRQ(DMAMUX2_OVR_IRQn);
        }
    }
    void disableDMAMUXIsr()
    {
        NVIC_DisableIRQ(DMAMUX2_OVR_IRQn);
    }
    void registerDMAMUXInterruptCb(const BDMAMUXInterruptCb& isrcb)
    {
        bdmamuxcb_ = isrcb;
    }
    void unregisterDMAMUXInterruptCb()
    {
        if(bdmamuxcb_)
        {
            bdmamuxcb_ = BDMAMUXInterruptCb();
        }
    }
private:
    IRQn_Type getIrqType()
    {
        IRQn_Type irqtype = BDMA_Channel0_IRQn;
        switch (reinterpret_cast<uint32_t>(bdmaChannelAddr_))
        {
            case (uint32_t)BDMA_Channel0_BASE:
                irqtype = BDMA_Channel0_IRQn;
                break;
            case (uint32_t)BDMA_Channel1_BASE:
                irqtype = BDMA_Channel1_IRQn;
                break;
            case (uint32_t)BDMA_Channel2_BASE:
                irqtype = BDMA_Channel2_IRQn;
                break;
            case (uint32_t)BDMA_Channel3_BASE:
                irqtype = BDMA_Channel3_IRQn;
                break;
            case (uint32_t)BDMA_Channel4_BASE:
                irqtype = BDMA_Channel4_IRQn;
                break;
            case (uint32_t)BDMA_Channel5_BASE:
                irqtype = BDMA_Channel5_IRQn;
                break;
            case (uint32_t)BDMA_Channel6_BASE:
                irqtype = BDMA_Channel6_IRQn;
                break;
            case (uint32_t)BDMA_Channel7_BASE:
                irqtype = BDMA_Channel7_IRQn;
                break;
            default:
                break;
        }
        return irqtype;
    }
    inline BDMAChannelNum BDMAGetChannelIndex(const BDMA_Channel_TypeDef* channel) const
    {
        return  (((uint32_t)(channel) == ((uint32_t)BDMA_Channel0)) ? BDMA_CHANNEL_0 : \
                ((uint32_t)(channel) == ((uint32_t)BDMA_Channel1)) ? BDMA_CHANNEL_1 : \
                ((uint32_t)(channel) == ((uint32_t)BDMA_Channel2)) ? BDMA_CHANNEL_2 : \
                ((uint32_t)(channel) == ((uint32_t)BDMA_Channel3)) ? BDMA_CHANNEL_3 : \
                ((uint32_t)(channel) == ((uint32_t)BDMA_Channel4)) ? BDMA_CHANNEL_4 : \
                ((uint32_t)(channel) == ((uint32_t)BDMA_Channel5)) ? BDMA_CHANNEL_5 : \
                ((uint32_t)(channel) == ((uint32_t)BDMA_Channel6)) ? BDMA_CHANNEL_6 : \
                BDMA_CHANNEL_7);
    }
    inline BDMA_Channel_TypeDef* BDMAGetChannelInstance(const BDMAChannelNum channelNum) const
    {
        return  ((((uint32_t)(bdmax_) == ((uint32_t)BDMA)) && ((uint32_t)(channelNum) == ((uint32_t)BDMA_CHANNEL_0))) ? BDMA_Channel0 : \
                (((uint32_t)(bdmax_) == ((uint32_t)BDMA)) && ((uint32_t)(channelNum) == ((uint32_t)BDMA_CHANNEL_1))) ? BDMA_Channel1 : \
                (((uint32_t)(bdmax_) == ((uint32_t)BDMA)) && ((uint32_t)(channelNum) == ((uint32_t)BDMA_CHANNEL_2))) ? BDMA_Channel2 : \
                (((uint32_t)(bdmax_) == ((uint32_t)BDMA)) && ((uint32_t)(channelNum) == ((uint32_t)BDMA_CHANNEL_3))) ? BDMA_Channel3 : \
                (((uint32_t)(bdmax_) == ((uint32_t)BDMA)) && ((uint32_t)(channelNum) == ((uint32_t)BDMA_CHANNEL_4))) ? BDMA_Channel4 : \
                (((uint32_t)(bdmax_) == ((uint32_t)BDMA)) && ((uint32_t)(channelNum) == ((uint32_t)BDMA_CHANNEL_5))) ? BDMA_Channel5 : \
                (((uint32_t)(bdmax_) == ((uint32_t)BDMA)) && ((uint32_t)(channelNum) == ((uint32_t)BDMA_CHANNEL_6))) ? BDMA_Channel6 : \
                BDMA_Channel7);
    }
private:
    BDMA_TypeDef * bdmax_;
    BDMA_Channel_TypeDef *bdmaChannelAddr_;
    BDMAChannelNum channelNum_;
    BDMAInterruptCb bdmacb_;
    BDMAMUXInterruptCb bdmamuxcb_;
};