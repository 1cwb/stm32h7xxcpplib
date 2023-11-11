#pragma once
#include "common.hpp"

#if defined(UART9)
#define IS_DMA_UART_USART_REQUEST(__REQUEST__) ((((__REQUEST__) >= DMA_REQUEST_USART1_RX)  &&  ((__REQUEST__) <= DMA_REQUEST_USART3_TX)) || \
                                                 (((__REQUEST__) >= DMA_REQUEST_UART4_RX)  &&  ((__REQUEST__) <= DMA_REQUEST_UART5_TX )) || \
                                                 (((__REQUEST__) >= DMA_REQUEST_USART6_RX) &&  ((__REQUEST__) <= DMA_REQUEST_USART6_TX)) || \
                                                 (((__REQUEST__) >= DMA_REQUEST_UART7_RX)  &&  ((__REQUEST__) <= DMA_REQUEST_UART8_TX )) || \
                                                 (((__REQUEST__) >= DMA_REQUEST_UART9_RX)  &&  ((__REQUEST__) <= DMA_REQUEST_USART10_TX )))
#else
#define IS_DMA_UART_USART_REQUEST(__REQUEST__) ((((__REQUEST__) >= DMA_REQUEST_USART1_RX)  &&  ((__REQUEST__) <= DMA_REQUEST_USART3_TX)) || \
                                                 (((__REQUEST__) >= DMA_REQUEST_UART4_RX)  &&  ((__REQUEST__) <= DMA_REQUEST_UART5_TX )) || \
                                                 (((__REQUEST__) >= DMA_REQUEST_USART6_RX) &&  ((__REQUEST__) <= DMA_REQUEST_USART6_TX)) || \
                                                 (((__REQUEST__) >= DMA_REQUEST_UART7_RX)  &&  ((__REQUEST__) <= DMA_REQUEST_UART8_TX )))

#endif
/** @defgroup DMA_Request_selection DMA Request selection
  * @brief    DMA Request selection
  * @{
  */
/* DMAMUX1 requests */
enum DMARequest
{
DMA_REQUEST_MEM2MEM          =    0U  ,/*!< memory to memory transfer   */
DMA_REQUEST_GENERATOR0       =    1U  ,/*!< DMAMUX1 request generator 0 */
DMA_REQUEST_GENERATOR1       =    2U  ,/*!< DMAMUX1 request generator 1 */
DMA_REQUEST_GENERATOR2       =    3U  ,/*!< DMAMUX1 request generator 2 */
DMA_REQUEST_GENERATOR3       =    4U  ,/*!< DMAMUX1 request generator 3 */
DMA_REQUEST_GENERATOR4       =    5U  ,/*!< DMAMUX1 request generator 4 */
DMA_REQUEST_GENERATOR5       =    6U  ,/*!< DMAMUX1 request generator 5 */
DMA_REQUEST_GENERATOR6       =    7U  ,/*!< DMAMUX1 request generator 6 */
DMA_REQUEST_GENERATOR7       =    8U  ,/*!< DMAMUX1 request generator 7 */
DMA_REQUEST_ADC1             =    9U  ,/*!< DMAMUX1 ADC1 request */
DMA_REQUEST_ADC2             =    10U ,/*!< DMAMUX1 ADC2 request */
DMA_REQUEST_TIM1_CH1         =    11U , /*!< DMAMUX1 TIM1 CH1 request  */
DMA_REQUEST_TIM1_CH2         =    12U , /*!< DMAMUX1 TIM1 CH2 request  */
DMA_REQUEST_TIM1_CH3         =    13U , /*!< DMAMUX1 TIM1 CH3 request  */
DMA_REQUEST_TIM1_CH4         =    14U , /*!< DMAMUX1 TIM1 CH4 request  */
DMA_REQUEST_TIM1_UP          =    15U , /*!< DMAMUX1 TIM1 UP request   */
DMA_REQUEST_TIM1_TRIG        =    16U , /*!< DMAMUX1 TIM1 TRIG request */
DMA_REQUEST_TIM1_COM         =    17U , /*!< DMAMUX1 TIM1 COM request  */
DMA_REQUEST_TIM2_CH1         =    18U , /*!< DMAMUX1 TIM2 CH1 request  */
DMA_REQUEST_TIM2_CH2         =    19U , /*!< DMAMUX1 TIM2 CH2 request  */
DMA_REQUEST_TIM2_CH3         =    20U , /*!< DMAMUX1 TIM2 CH3 request  */
DMA_REQUEST_TIM2_CH4         =    21U , /*!< DMAMUX1 TIM2 CH4 request  */
DMA_REQUEST_TIM2_UP          =    22U , /*!< DMAMUX1 TIM2 UP request   */
DMA_REQUEST_TIM3_CH1         =    23U , /*!< DMAMUX1 TIM3 CH1 request  */
DMA_REQUEST_TIM3_CH2         =    24U , /*!< DMAMUX1 TIM3 CH2 request  */
DMA_REQUEST_TIM3_CH3         =    25U , /*!< DMAMUX1 TIM3 CH3 request  */
DMA_REQUEST_TIM3_CH4         =    26U , /*!< DMAMUX1 TIM3 CH4 request  */
DMA_REQUEST_TIM3_UP          =    27U , /*!< DMAMUX1 TIM3 UP request   */
DMA_REQUEST_TIM3_TRIG        =    28U , /*!< DMAMUX1 TIM3 TRIG request */
DMA_REQUEST_TIM4_CH1         =    29U , /*!< DMAMUX1 TIM4 CH1 request  */
DMA_REQUEST_TIM4_CH2         =    30U , /*!< DMAMUX1 TIM4 CH2 request  */
DMA_REQUEST_TIM4_CH3         =    31U , /*!< DMAMUX1 TIM4 CH3 request  */
DMA_REQUEST_TIM4_UP          =    32U , /*!< DMAMUX1 TIM4 UP request   */
DMA_REQUEST_I2C1_RX          =    33U , /*!< DMAMUX1 I2C1 RX request   */
DMA_REQUEST_I2C1_TX          =    34U , /*!< DMAMUX1 I2C1 TX request   */
DMA_REQUEST_I2C2_RX          =    35U , /*!< DMAMUX1 I2C2 RX request   */
DMA_REQUEST_I2C2_TX          =    36U , /*!< DMAMUX1 I2C2 TX request   */
DMA_REQUEST_SPI1_RX          =    37U , /*!< DMAMUX1 SPI1 RX request   */
DMA_REQUEST_SPI1_TX          =    38U , /*!< DMAMUX1 SPI1 TX request   */
DMA_REQUEST_SPI2_RX          =    39U , /*!< DMAMUX1 SPI2 RX request   */
DMA_REQUEST_SPI2_TX          =    40U , /*!< DMAMUX1 SPI2 TX request   */
DMA_REQUEST_USART1_RX        =    41U , /*!< DMAMUX1 USART1 RX request */
DMA_REQUEST_USART1_TX        =    42U , /*!< DMAMUX1 USART1 TX request */
DMA_REQUEST_USART2_RX        =    43U , /*!< DMAMUX1 USART2 RX request */
DMA_REQUEST_USART2_TX        =    44U , /*!< DMAMUX1 USART2 TX request */
DMA_REQUEST_USART3_RX        =    45U , /*!< DMAMUX1 USART3 RX request */
DMA_REQUEST_USART3_TX        =    46U , /*!< DMAMUX1 USART3 TX request */
DMA_REQUEST_TIM8_CH1         =    47U , /*!< DMAMUX1 TIM8 CH1 request  */
DMA_REQUEST_TIM8_CH2         =    48U , /*!< DMAMUX1 TIM8 CH2 request  */
DMA_REQUEST_TIM8_CH3         =    49U , /*!< DMAMUX1 TIM8 CH3 request  */
DMA_REQUEST_TIM8_CH4         =    50U , /*!< DMAMUX1 TIM8 CH4 request  */
DMA_REQUEST_TIM8_UP          =    51U , /*!< DMAMUX1 TIM8 UP request   */
DMA_REQUEST_TIM8_TRIG        =    52U , /*!< DMAMUX1 TIM8 TRIG request */
DMA_REQUEST_TIM8_COM         =    53U , /*!< DMAMUX1 TIM8 COM request  */
DMA_REQUEST_TIM5_CH1         =    55U , /*!< DMAMUX1 TIM5 CH1 request  */
DMA_REQUEST_TIM5_CH2         =    56U , /*!< DMAMUX1 TIM5 CH2 request  */
DMA_REQUEST_TIM5_CH3         =    57U , /*!< DMAMUX1 TIM5 CH3 request  */
DMA_REQUEST_TIM5_CH4         =    58U , /*!< DMAMUX1 TIM5 CH4 request  */
DMA_REQUEST_TIM5_UP          =    59U , /*!< DMAMUX1 TIM5 UP request   */
DMA_REQUEST_TIM5_TRIG        =    60U , /*!< DMAMUX1 TIM5 TRIG request */
DMA_REQUEST_SPI3_RX          =    61U , /*!< DMAMUX1 SPI3 RX request   */
DMA_REQUEST_SPI3_TX          =    62U , /*!< DMAMUX1 SPI3 TX request   */
DMA_REQUEST_UART4_RX         =    63U , /*!< DMAMUX1 UART4 RX request */
DMA_REQUEST_UART4_TX         =    64U , /*!< DMAMUX1 UART4 TX request */
DMA_REQUEST_UART5_RX         =    65U , /*!< DMAMUX1 UART5 RX request */
DMA_REQUEST_UART5_TX         =    66U , /*!< DMAMUX1 UART5 TX request */
DMA_REQUEST_DAC1_CH1         =    67U , /*!< DMAMUX1 DAC1 Channel 1 request */
DMA_REQUEST_DAC1_CH2         =    68U , /*!< DMAMUX1 DAC1 Channel 2 request */
DMA_REQUEST_TIM6_UP          =    69U , /*!< DMAMUX1 TIM6 UP request   */
DMA_REQUEST_TIM7_UP          =    70U , /*!< DMAMUX1 TIM7 UP request   */
DMA_REQUEST_USART6_RX        =    71U , /*!< DMAMUX1 USART6 RX request */
DMA_REQUEST_USART6_TX        =    72U , /*!< DMAMUX1 USART6 TX request */
DMA_REQUEST_I2C3_RX          =    73U , /*!< DMAMUX1 I2C3 RX request   */
DMA_REQUEST_I2C3_TX          =    74U , /*!< DMAMUX1 I2C3 TX request   */
#if defined (PSSI)    
DMA_REQUEST_DCMI_PSSI        =    75U , /*!< DMAMUX1 DCMI/PSSI request    */
DMA_REQUEST_DCMI             =    DMA_REQUEST_DCMI_PSSI, /* Legacy define */
#else    
DMA_REQUEST_DCMI             =    75U , /*!< DMAMUX1 DCMI request         */
#endif /* PSSI */    
    
DMA_REQUEST_CRYP_IN          =    76U , /*!< DMAMUX1 CRYP IN request   */
DMA_REQUEST_CRYP_OUT         =    77U , /*!< DMAMUX1 CRYP OUT request  */
DMA_REQUEST_HASH_IN          =    78U , /*!< DMAMUX1 HASH IN request   */
DMA_REQUEST_UART7_RX         =    79U , /*!< DMAMUX1 UART7 RX request  */
DMA_REQUEST_UART7_TX         =    80U , /*!< DMAMUX1 UART7 TX request  */
DMA_REQUEST_UART8_RX         =    81U , /*!< DMAMUX1 UART8 RX request  */
DMA_REQUEST_UART8_TX         =    82U , /*!< DMAMUX1 UART8 TX request  */
DMA_REQUEST_SPI4_RX          =    83U , /*!< DMAMUX1 SPI4 RX request   */
DMA_REQUEST_SPI4_TX          =    84U , /*!< DMAMUX1 SPI4 TX request   */
DMA_REQUEST_SPI5_RX          =    85U , /*!< DMAMUX1 SPI5 RX request   */
DMA_REQUEST_SPI5_TX          =    86U , /*!< DMAMUX1 SPI5 TX request   */
DMA_REQUEST_SAI1_A           =    87U , /*!< DMAMUX1 SAI1 A request    */
DMA_REQUEST_SAI1_B           =    88U , /*!< DMAMUX1 SAI1 B request    */
#if defined(SAI2)    
DMA_REQUEST_SAI2_A           =    89U , /*!< DMAMUX1 SAI2 A request    */
DMA_REQUEST_SAI2_B           =    90U , /*!< DMAMUX1 SAI2 B request    */
#endif /* SAI2 */    
    
DMA_REQUEST_SWPMI_RX         =    91U , /*!< DMAMUX1 SWPMI RX request  */
DMA_REQUEST_SWPMI_TX         =    92U , /*!< DMAMUX1 SWPMI TX request  */
DMA_REQUEST_SPDIF_RX_DT      =    93U , /*!< DMAMUX1 SPDIF RXDT request*/
DMA_REQUEST_SPDIF_RX_CS      =    94U , /*!< DMAMUX1 SPDIF RXCS request*/
#if defined(HRTIM1)    
DMA_REQUEST_HRTIM_MASTER     =    95U , /*!< DMAMUX1 HRTIM1 Master request 1 */
DMA_REQUEST_HRTIM_TIMER_A    =    96U , /*!< DMAMUX1 HRTIM1 Timer A request 2 */
DMA_REQUEST_HRTIM_TIMER_B    =    97U , /*!< DMAMUX1 HRTIM1 Timer B request 3 */
DMA_REQUEST_HRTIM_TIMER_C    =    98U , /*!< DMAMUX1 HRTIM1 Timer C request 4 */
DMA_REQUEST_HRTIM_TIMER_D    =    99U , /*!< DMAMUX1 HRTIM1 Timer D request 5 */
DMA_REQUEST_HRTIM_TIMER_E    =   100U , /*!< DMAMUX1 HRTIM1 Timer E request 6*/
#endif /* HRTIM1 */    
    
DMA_REQUEST_DFSDM1_FLT0      =   101U , /*!< DMAMUX1 DFSDM Filter0 request */
DMA_REQUEST_DFSDM1_FLT1      =   102U , /*!< DMAMUX1 DFSDM Filter1 request */
DMA_REQUEST_DFSDM1_FLT2      =   103U , /*!< DMAMUX1 DFSDM Filter2 request */
DMA_REQUEST_DFSDM1_FLT3      =   104U , /*!< DMAMUX1 DFSDM Filter3 request */
DMA_REQUEST_TIM15_CH1        =   105U , /*!< DMAMUX1 TIM15 CH1 request  */
DMA_REQUEST_TIM15_UP         =   106U , /*!< DMAMUX1 TIM15 UP request   */
DMA_REQUEST_TIM15_TRIG       =   107U , /*!< DMAMUX1 TIM15 TRIG request */
DMA_REQUEST_TIM15_COM        =   108U , /*!< DMAMUX1 TIM15 COM request  */
DMA_REQUEST_TIM16_CH1        =   109U , /*!< DMAMUX1 TIM16 CH1 request  */
DMA_REQUEST_TIM16_UP         =   110U , /*!< DMAMUX1 TIM16 UP request   */
DMA_REQUEST_TIM17_CH1        =   111U , /*!< DMAMUX1 TIM17 CH1 request  */
DMA_REQUEST_TIM17_UP         =   112U , /*!< DMAMUX1 TIM17 UP request   */
    
#if defined(SAI3)    
DMA_REQUEST_SAI3_A           =   113U , /*!< DMAMUX1 SAI3 A request  */
DMA_REQUEST_SAI3_B           =   114U , /*!< DMAMUX1 SAI3 B request  */
#endif /* SAI3 */    
    
#if defined(ADC3)    
DMA_REQUEST_ADC3             =   115U , /*!< DMAMUX1 ADC3 request  */
#endif /* ADC3 */    
    
#if defined(UART9)    
DMA_REQUEST_UART9_RX         =   116U , /*!< DMAMUX1 UART9 request  */
DMA_REQUEST_UART9_TX         =   117U , /*!< DMAMUX1 UART9 request  */
#endif /* UART9 */    
    
#if defined(USART10)    
DMA_REQUEST_USART10_RX       =   118U , /*!< DMAMUX1 USART10 request  */
DMA_REQUEST_USART10_TX       =   119U , /*!< DMAMUX1 USART10 request  */
#endif /* USART10 */    
    
#if defined(FMAC)    
DMA_REQUEST_FMAC_READ        =   120U , /*!< DMAMUX1 FMAC Read request  */
DMA_REQUEST_FMAC_WRITE       =   121U , /*!< DMAMUX1 FMAC Write request */
#endif /* FMAC */    
    
#if defined(CORDIC)    
DMA_REQUEST_CORDIC_READ      =   122U , /*!< DMAMUX1 CORDIC Read request  */
DMA_REQUEST_CORDIC_WRITE     =   123U , /*!< DMAMUX1 CORDIC Write request */
#endif /* CORDIC */    
    
#if defined(I2C5)    
DMA_REQUEST_I2C5_RX          =   124U , /*!< DMAMUX1 I2C5 RX request   */
DMA_REQUEST_I2C5_TX          =   125U , /*!< DMAMUX1 I2C5 TX request   */
#endif /* I2C5 */    
    
#if defined(TIM23)    
DMA_REQUEST_TIM23_CH1        =    126U , /*!< DMAMUX1 TIM23 CH1 request  */
DMA_REQUEST_TIM23_CH2        =    127U , /*!< DMAMUX1 TIM23 CH2 request  */
DMA_REQUEST_TIM23_CH3        =    128U , /*!< DMAMUX1 TIM23 CH3 request  */
DMA_REQUEST_TIM23_CH4        =    129U , /*!< DMAMUX1 TIM23 CH4 request  */
DMA_REQUEST_TIM23_UP         =    130U , /*!< DMAMUX1 TIM23 UP request   */
DMA_REQUEST_TIM23_TRIG       =    131U , /*!< DMAMUX1 TIM23 TRIG request */
#endif /* TIM23 */    

#if defined(TIM24)    
DMA_REQUEST_TIM24_CH1        =    132U , /*!< DMAMUX1 TIM24 CH1 request  */
DMA_REQUEST_TIM24_CH2        =    133U , /*!< DMAMUX1 TIM24 CH2 request  */
DMA_REQUEST_TIM24_CH3        =    134U , /*!< DMAMUX1 TIM24 CH3 request  */
DMA_REQUEST_TIM24_CH4        =    135U , /*!< DMAMUX1 TIM24 CH4 request  */
DMA_REQUEST_TIM24_UP         =    136U , /*!< DMAMUX1 TIM24 UP request   */
DMA_REQUEST_TIM24_TRIG       =    137U , /*!< DMAMUX1 TIM24 TRIG request */
#endif /* TIM24 */    
};
enum BDMARequest
{
    /* DMAMUX2 requests */    
    BDMA_REQUEST_MEM2MEM         =     0U , /*!< memory to memory transfer   */
    BDMA_REQUEST_GENERATOR0      =     1U , /*!< DMAMUX2 request generator 0 */
    BDMA_REQUEST_GENERATOR1      =     2U , /*!< DMAMUX2 request generator 1 */
    BDMA_REQUEST_GENERATOR2      =     3U , /*!< DMAMUX2 request generator 2 */
    BDMA_REQUEST_GENERATOR3      =     4U , /*!< DMAMUX2 request generator 3 */
    BDMA_REQUEST_GENERATOR4      =     5U , /*!< DMAMUX2 request generator 4 */
    BDMA_REQUEST_GENERATOR5      =     6U , /*!< DMAMUX2 request generator 5 */
    BDMA_REQUEST_GENERATOR6      =     7U , /*!< DMAMUX2 request generator 6 */
    BDMA_REQUEST_GENERATOR7      =     8U , /*!< DMAMUX2 request generator 7 */
    BDMA_REQUEST_LPUART1_RX      =     9U , /*!< DMAMUX2 LP_UART1_RX request */
    BDMA_REQUEST_LPUART1_TX      =    10U , /*!< DMAMUX2 LP_UART1_TX request */
    BDMA_REQUEST_SPI6_RX         =    11U , /*!< DMAMUX2 SPI6 RX request     */
    BDMA_REQUEST_SPI6_TX         =    12U , /*!< DMAMUX2 SPI6 TX request     */
    BDMA_REQUEST_I2C4_RX         =    13U , /*!< DMAMUX2 I2C4 RX request     */
    BDMA_REQUEST_I2C4_TX         =    14U , /*!< DMAMUX2 I2C4 TX request     */
    #if defined(SAI4)    
    BDMA_REQUEST_SAI4_A          =    15U , /*!< DMAMUX2 SAI4 A request      */
    BDMA_REQUEST_SAI4_B          =    16U , /*!< DMAMUX2 SAI4 B request      */
    #endif /* SAI4 */    
    #if defined(ADC3)    
    BDMA_REQUEST_ADC3            =    17U , /*!< DMAMUX2 ADC3 request        */
    #endif /* ADC3 */    
    #if defined(DAC2)    
    BDMA_REQUEST_DAC2_CH1        =    17U , /*!< DMAMUX2 DAC2 CH1 request    */
    #endif /* DAC2 */
    #if defined(DFSDM2_Channel0)
    BDMA_REQUEST_DFSDM2_FLT0     =    18U , /*!< DMAMUX2 DFSDM2 request      */
    #endif /* DFSDM1_Channel0 */
};
/** @defgroup DMA_Error_Code DMA Error Code
  * @brief    DMA Error Code
  * @{
  */
enum DMAError
{
    DMA_ERROR_NONE            =  (0x00000000U),    /*!< No error                                */
    DMA_ERROR_TE              =  (0x00000001U),    /*!< Transfer error                          */
    DMA_ERROR_FE              =  (0x00000002U),    /*!< FIFO error                              */
    DMA_ERROR_DME             =  (0x00000004U),    /*!< Direct Mode error                       */
    DMA_ERROR_TIMEOUT         =  (0x00000020U),    /*!< Timeout error                           */
    DMA_ERROR_PARAM           =  (0x00000040U),    /*!< Parameter error                         */
    DMA_ERROR_NO_XFER         =  (0x00000080U),    /*!< Abort requested with no Xfer ongoing    */
    DMA_ERROR_NOT_SUPPORTED   =  (0x00000100U),    /*!< Not supported mode                      */
    DMA_ERROR_SYNC            =  (0x00000200U),    /*!< DMAMUX sync overrun  error              */
    DMA_ERROR_REQGEN          =  (0x00000400U),    /*!< DMAMUX request generator overrun  error */
    DMA_ERROR_BUSY            =  (0x00000800U)     /*!< DMA Busy                          error */
};
/**
  * @brief  HAL DMA State structures definition
  */
enum DMAState
{
    DMA_STATE_RESET             = 0x00U,  /*!< DMA not yet initialized or disabled */
    DMA_STATE_READY             = 0x01U,  /*!< DMA initialized and ready for use   */
    DMA_STATE_BUSY              = 0x02U,  /*!< DMA process is ongoing              */
    DMA_STATE_ERROR             = 0x03U,  /*!< DMA error state                     */
    DMA_STATE_ABORT             = 0x04U,  /*!< DMA Abort state                     */
};
/** @defgroup DMAEx_MUX_SyncPolarity_selection DMAEx MUX SyncPolarity selection
  * @brief    DMAEx MUX SyncPolarity selection
  * @{
  */
enum DMAMUXSyncPolarity
{
    DMAMUX_SYNC_NO_EVENT        =  0x00000000U,             /*!< block synchronization events                    */
    DMAMUX_SYNC_RISING          =  DMAMUX_CxCR_SPOL_0,      /*!< synchronize with rising edge events             */
    DMAMUX_SYNC_FALLING         =  DMAMUX_CxCR_SPOL_1,      /*!< synchronize with falling edge events            */
    DMAMUX_SYNC_RISING_FALLING  =  DMAMUX_CxCR_SPOL         /*!< synchronize with rising and falling edge events */
};
enum DMAMUX1SyncID
{
    DMAMUX1_SYNC_DMAMUX1_CH0_EVT   =  0U,   /*!< DMAMUX1 synchronization Signal is DMAMUX1 Channel0 Event */
    DMAMUX1_SYNC_DMAMUX1_CH1_EVT   =  1U,   /*!< DMAMUX1 synchronization Signal is DMAMUX1 Channel1 Event */
    DMAMUX1_SYNC_DMAMUX1_CH2_EVT   =  2U,   /*!< DMAMUX1 synchronization Signal is DMAMUX1 Channel2 Event */
    DMAMUX1_SYNC_LPTIM1_OUT        =  3U,   /*!< DMAMUX1 synchronization Signal is LPTIM1 OUT             */
    DMAMUX1_SYNC_LPTIM2_OUT        =  4U,   /*!< DMAMUX1 synchronization Signal is LPTIM2 OUT             */
    DMAMUX1_SYNC_LPTIM3_OUT        =  5U,   /*!< DMAMUX1 synchronization Signal is LPTIM3 OUT             */
    DMAMUX1_SYNC_EXTI0             =  6U,   /*!< DMAMUX1 synchronization Signal is EXTI0 IT               */
    DMAMUX1_SYNC_TIM12_TRGO        =  7U    /*!< DMAMUX1 synchronization Signal is TIM12 TRGO             */
};
enum DMAMUX2SyncID
{
    DMAMUX2_SYNC_DMAMUX2_CH0_EVT   =  0U,   /*!< DMAMUX2 synchronization Signal is DMAMUX2 Channel0 Event */
    DMAMUX2_SYNC_DMAMUX2_CH1_EVT   =  1U,   /*!< DMAMUX2 synchronization Signal is DMAMUX2 Channel1 Event */
    DMAMUX2_SYNC_DMAMUX2_CH2_EVT   =  2U,   /*!< DMAMUX2 synchronization Signal is DMAMUX2 Channel2 Event */
    DMAMUX2_SYNC_DMAMUX2_CH3_EVT   =  3U,   /*!< DMAMUX2 synchronization Signal is DMAMUX2 Channel3 Event */
    DMAMUX2_SYNC_DMAMUX2_CH4_EVT   =  4U,   /*!< DMAMUX2 synchronization Signal is DMAMUX2 Channel4 Event */
    DMAMUX2_SYNC_DMAMUX2_CH5_EVT   =  5U,   /*!< DMAMUX2 synchronization Signal is DMAMUX2 Channel5 Event */
    DMAMUX2_SYNC_LPUART1_RX_WKUP   =  6U,   /*!< DMAMUX2 synchronization Signal is LPUART1 RX Wakeup      */
    DMAMUX2_SYNC_LPUART1_TX_WKUP   =  7U,   /*!< DMAMUX2 synchronization Signal is LPUART1 TX Wakeup      */
    DMAMUX2_SYNC_LPTIM2_OUT        =  8U,   /*!< DMAMUX2 synchronization Signal is LPTIM2 output          */
    DMAMUX2_SYNC_LPTIM3_OUT        =  9U,   /*!< DMAMUX2 synchronization Signal is LPTIM3 output          */
    DMAMUX2_SYNC_I2C4_WKUP         = 10U,   /*!< DMAMUX2 synchronization Signal is I2C4 Wakeup            */
    DMAMUX2_SYNC_SPI6_WKUP         = 11U,   /*!< DMAMUX2 synchronization Signal is SPI6 Wakeup            */
    DMAMUX2_SYNC_COMP1_OUT         = 12U,   /*!< DMAMUX2 synchronization Signal is Comparator 1 output    */
    DMAMUX2_SYNC_RTC_WKUP          = 13U,   /*!< DMAMUX2 synchronization Signal is RTC Wakeup             */
    DMAMUX2_SYNC_EXTI0             = 14U,   /*!< DMAMUX2 synchronization Signal is EXTI0 IT               */
    DMAMUX2_SYNC_EXTI2             = 15U    /*!< DMAMUX2 synchronization Signal is EXTI2 IT               */
};
/** @defgroup DMAEx_MUX_RequestGeneneratorPolarity_selection DMAEx MUX RequestGeneneratorPolarity selection
  * @brief    DMAEx MUX RequestGeneneratorPolarity selection
  * @{
  */
enum DMAMuxReqGenPolarity
{
    HAL_DMAMUX_REQ_GEN_NO_EVENT           =     0x00000000U,           /*!< block request generator events                     */
    HAL_DMAMUX_REQ_GEN_RISING             =     DMAMUX_RGxCR_GPOL_0,  /*!< generate request on rising edge events             */
    HAL_DMAMUX_REQ_GEN_FALLING            =     DMAMUX_RGxCR_GPOL_1,  /*!< generate request on falling edge events            */
    HAL_DMAMUX_REQ_GEN_RISING_FALLING     =     DMAMUX_RGxCR_GPOL    /*!< generate request on rising and falling edge events */
};
/** @defgroup DMAEx_MUX_SignalGeneratorID_selection DMAEx MUX SignalGeneratorID selection
  * @brief    DMAEx MUX SignalGeneratorID selection
  * @{
  */
enum DMAMUX1ReqGenID
{
    DMAMUX1_REQ_GEN_DMAMUX1_CH0_EVT   =   0U,   /*!< DMAMUX1 Request generator Signal is DMAMUX1 Channel0 Event */
    DMAMUX1_REQ_GEN_DMAMUX1_CH1_EVT   =   1U,   /*!< DMAMUX1 Request generator Signal is DMAMUX1 Channel1 Event */
    DMAMUX1_REQ_GEN_DMAMUX1_CH2_EVT   =   2U,   /*!< DMAMUX1 Request generator Signal is DMAMUX1 Channel2 Event */
    DMAMUX1_REQ_GEN_LPTIM1_OUT        =   3U,   /*!< DMAMUX1 Request generator Signal is LPTIM1 OUT             */
    DMAMUX1_REQ_GEN_LPTIM2_OUT        =   4U,   /*!< DMAMUX1 Request generator Signal is LPTIM2 OUT             */
    DMAMUX1_REQ_GEN_LPTIM3_OUT        =   5U,   /*!< DMAMUX1 Request generator Signal is LPTIM3 OUT             */
    DMAMUX1_REQ_GEN_EXTI0             =   6U,   /*!< DMAMUX1 Request generator Signal is EXTI0 IT               */
    DMAMUX1_REQ_GEN_TIM12_TRGO        =   7U    /*!< DMAMUX1 Request generator Signal is TIM12 TRGO             */
};
enum DMAMUX2ReqGenID
{
    DMAMUX2_REQ_GEN_DMAMUX2_CH0_EVT   =    0U,   /*!< DMAMUX2 Request generator Signal is DMAMUX2 Channel0 Event */
    DMAMUX2_REQ_GEN_DMAMUX2_CH1_EVT   =    1U,   /*!< DMAMUX2 Request generator Signal is DMAMUX2 Channel1 Event */
    DMAMUX2_REQ_GEN_DMAMUX2_CH2_EVT   =    2U,   /*!< DMAMUX2 Request generator Signal is DMAMUX2 Channel2 Event */
    DMAMUX2_REQ_GEN_DMAMUX2_CH3_EVT   =    3U,   /*!< DMAMUX2 Request generator Signal is DMAMUX2 Channel3 Event */
    DMAMUX2_REQ_GEN_DMAMUX2_CH4_EVT   =    4U,   /*!< DMAMUX2 Request generator Signal is DMAMUX2 Channel4 Event */
    DMAMUX2_REQ_GEN_DMAMUX2_CH5_EVT   =    5U,   /*!< DMAMUX2 Request generator Signal is DMAMUX2 Channel5 Event */
    DMAMUX2_REQ_GEN_DMAMUX2_CH6_EVT   =    6U,   /*!< DMAMUX2 Request generator Signal is DMAMUX2 Channel6 Event */
    DMAMUX2_REQ_GEN_LPUART1_RX_WKUP   =    7U,   /*!< DMAMUX2 Request generator Signal is LPUART1 RX Wakeup      */
    DMAMUX2_REQ_GEN_LPUART1_TX_WKUP   =    8U,   /*!< DMAMUX2 Request generator Signal is LPUART1 TX Wakeup      */
    DMAMUX2_REQ_GEN_LPTIM2_WKUP       =    9U,   /*!< DMAMUX2 Request generator Signal is LPTIM2 Wakeup          */
    DMAMUX2_REQ_GEN_LPTIM2_OUT        =   10U,   /*!< DMAMUX2 Request generator Signal is LPTIM2 OUT             */
    DMAMUX2_REQ_GEN_LPTIM3_WKUP       =   11U,   /*!< DMAMUX2 Request generator Signal is LPTIM3 Wakeup          */
    DMAMUX2_REQ_GEN_LPTIM3_OUT        =   12U,    /*!< DMAMUX2 Request generator Signal is LPTIM3 OUT             */
    #if defined(LPTIM4)
    DMAMUX2_REQ_GEN_LPTIM4_WKUP       =   13U,   /*!< DMAMUX2 Request generator Signal is LPTIM4 Wakeup          */
    #endif /* LPTIM4 */
    #if defined(LPTIM5)
    DMAMUX2_REQ_GEN_LPTIM5_WKUP       =   14U,   /*!< DMAMUX2 Request generator Signal is LPTIM5 Wakeup          */
    #endif /* LPTIM5 */
    DMAMUX2_REQ_GEN_I2C4_WKUP         =   15U,   /*!< DMAMUX2 Request generator Signal is I2C4 Wakeup            */
    DMAMUX2_REQ_GEN_SPI6_WKUP         =   16U,   /*!< DMAMUX2 Request generator Signal is SPI6 Wakeup            */
    DMAMUX2_REQ_GEN_COMP1_OUT         =   17U,   /*!< DMAMUX2 Request generator Signal is Comparator 1 output    */
    DMAMUX2_REQ_GEN_COMP2_OUT         =   18U,   /*!< DMAMUX2 Request generator Signal is Comparator 2 output    */
    DMAMUX2_REQ_GEN_RTC_WKUP          =   19U,   /*!< DMAMUX2 Request generator Signal is RTC Wakeup             */
    DMAMUX2_REQ_GEN_EXTI0             =   20U,   /*!< DMAMUX2 Request generator Signal is EXTI0                  */
    DMAMUX2_REQ_GEN_EXTI2             =   21U,   /*!< DMAMUX2 Request generator Signal is EXTI2                  */
    DMAMUX2_REQ_GEN_I2C4_IT_EVT       =   22U,   /*!< DMAMUX2 Request generator Signal is I2C4 IT Event          */
    DMAMUX2_REQ_GEN_SPI6_IT           =   23U,   /*!< DMAMUX2 Request generator Signal is SPI6 IT                */
    DMAMUX2_REQ_GEN_LPUART1_TX_IT     =   24U,   /*!< DMAMUX2 Request generator Signal is LPUART1 Tx IT          */
    DMAMUX2_REQ_GEN_LPUART1_RX_IT     =   25U,   /*!< DMAMUX2 Request generator Signal is LPUART1 Rx IT          */
    #if defined(ADC3)
    DMAMUX2_REQ_GEN_ADC3_IT           =   26U,   /*!< DMAMUX2 Request generator Signal is ADC3 IT                */
    DMAMUX2_REQ_GEN_ADC3_AWD1_OUT     =   27U,   /*!< DMAMUX2 Request generator Signal is ADC3 Analog Watchdog 1 output */
    #endif /* ADC3 */
    DMAMUX2_REQ_GEN_BDMA_CH0_IT       =   28U,   /*!< DMAMUX2 Request generator Signal is BDMA Channel 0 IT      */
    DMAMUX2_REQ_GEN_BDMA_CH1_IT       =   29U    /*!< DMAMUX2 Request generator Signal is BDMA Channel 1 IT      */
};
//===================================================================================================================
/** @defgroup DMA_Data_transfer_direction DMA Data transfer direction
  * @brief    DMA data transfer direction
  * @{
  */
enum DMATransDirection
{
    DMA_PERIPH_TO_MEMORY     =    ((uint32_t)0x00000000U),      /*!< Peripheral to memory direction */
    DMA_MEMORY_TO_PERIPH     =    ((uint32_t)DMA_SxCR_DIR_0),   /*!< Memory to peripheral direction */
    DMA_MEMORY_TO_MEMORY     =    ((uint32_t)DMA_SxCR_DIR_1)    /*!< Memory to memory direction     */
};
enum BDMATransDirection
{
    BDMA_PERIPH_TO_MEMORY     =    (0x00000000U),                /*!< Peripheral to memory direction */
    BDMA_MEMORY_TO_PERIPH     =    ((uint32_t)BDMA_CCR_DIR),     /*!< Memory to peripheral direction */
    BDMA_MEMORY_TO_MEMORY     =    ((uint32_t)BDMA_CCR_MEM2MEM)  /*!< Memory to memory direction     */
};
/** @defgroup DMA_Peripheral_incremented_mode DMA Peripheral incremented mode
  * @brief    DMA peripheral incremented mode
  * @{
  */
enum DMAPeripheralIncrementMode
{
    DMA_PINC_ENABLE     =   ((uint32_t)DMA_SxCR_PINC),  /*!< Peripheral increment mode enable  */
    DMA_PINC_DISABLE    =   ((uint32_t)0x00000000U)     /*!< Peripheral increment mode disable */
};
/** @defgroup DMA_Memory_incremented_mode DMA Memory incremented mode
  * @brief    DMA memory incremented mode
  * @{
  */
enum DMAMemoryIncrementMode
{
    DMA_MINC_ENABLE     =    ((uint32_t)DMA_SxCR_MINC),  /*!< Memory increment mode enable  */
    DMA_MINC_DISABLE    =    ((uint32_t)0x00000000U)     /*!< Memory increment mode disable */
};
/** @defgroup DMA_Peripheral_data_size DMA Peripheral data size
  * @brief    DMA peripheral data size
  * @{
  */
enum DMAPeripheralAlignMent
{
    DMA_PDATAALIGN_BYTE      =    ((uint32_t)0x00000000U),       /*!< Peripheral data alignment: Byte      */
    DMA_PDATAALIGN_HALFWORD  =    ((uint32_t)DMA_SxCR_PSIZE_0),  /*!< Peripheral data alignment: HalfWord  */
    DMA_PDATAALIGN_WORD      =    ((uint32_t)DMA_SxCR_PSIZE_1)   /*!< Peripheral data alignment: Word      */
};
/** @defgroup DMA_Memory_data_size DMA Memory data size
  * @brief    DMA memory data size
  * @{
  */
enum DMAMemoryAlignMent
{
    DMA_MDATAALIGN_BYTE       =   ((uint32_t)0x00000000U),       /*!< Memory data alignment: Byte     */
    DMA_MDATAALIGN_HALFWORD   =   ((uint32_t)DMA_SxCR_MSIZE_0),  /*!< Memory data alignment: HalfWord */
    DMA_MDATAALIGN_WORD       =   ((uint32_t)DMA_SxCR_MSIZE_1)   /*!< Memory data alignment: Word     */
};
/** @defgroup DMA_mode DMA mode
  * @brief    DMA mode
  * @{
  */
enum DMAMode
{
    DMA_NORMAL            =  ((uint32_t)0x00000000U),                  /*!< Normal mode                                    */
    DMA_CIRCULAR          =  ((uint32_t)DMA_SxCR_CIRC),                /*!< Circular mode                                  */
    DMA_PFCTRL            =  ((uint32_t)DMA_SxCR_PFCTRL),              /*!< Peripheral flow control mode                   */
    DMA_DOUBLE_BUFFER_M0  =  ((uint32_t)DMA_SxCR_DBM),                 /*!< Double buffer mode with first target memory M0 */
    DMA_DOUBLE_BUFFER_M1  =  ((uint32_t)(DMA_SxCR_DBM | DMA_SxCR_CT))  /*!< Double buffer mode with first target memory M1 */
};
/** @defgroup DMA_Priority_level DMA Priority level
  * @brief    DMA priority levels
  * @{
  */
enum DMAPriorityLevel
{
    DMA_PRIORITY_LOW         =    ((uint32_t)0x00000000U),    /*!< Priority level: Low       */
    DMA_PRIORITY_MEDIUM      =    ((uint32_t)DMA_SxCR_PL_0),  /*!< Priority level: Medium    */
    DMA_PRIORITY_HIGH        =    ((uint32_t)DMA_SxCR_PL_1),  /*!< Priority level: High      */
    DMA_PRIORITY_VERY_HIGH   =    ((uint32_t)DMA_SxCR_PL)     /*!< Priority level: Very High */
};
/** @defgroup DMA_FIFO_direct_mode DMA FIFO direct mode
  * @brief    DMA FIFO direct mode
  * @{
  */
enum DMAFifoMode
{
    DMA_FIFOMODE_DISABLE    =    ((uint32_t)0x00000000U),       /*!< FIFO mode disable */
    DMA_FIFOMODE_ENABLE     =    ((uint32_t)DMA_SxFCR_DMDIS)    /*!< FIFO mode enable  */
};
/** @defgroup DMA_FIFO_threshold_level DMA FIFO threshold level
  * @brief    DMA FIFO level
  * @{
  */
enum DMAFifoThreshold
{
    DMA_FIFO_THRESHOLD_1QUARTERFULL    =   ((uint32_t)0x00000000U),       /*!< FIFO threshold 1 quart full configuration  */
    DMA_FIFO_THRESHOLD_HALFFULL        =   ((uint32_t)DMA_SxFCR_FTH_0),  /*!< FIFO threshold half full configuration     */
    DMA_FIFO_THRESHOLD_3QUARTERSFULL   =   ((uint32_t)DMA_SxFCR_FTH_1),  /*!< FIFO threshold 3 quarts full configuration */
    DMA_FIFO_THRESHOLD_FULL            =   ((uint32_t)DMA_SxFCR_FTH)    /*!< FIFO threshold full configuration          */
};
/** @defgroup DMA_Memory_burst DMA Memory burst
  * @brief    DMA memory burst
  * @{
  */
enum DMAMemoryBurst
{
    DMA_MBURST_SINGLE   =    ((uint32_t)0x00000000U),
    DMA_MBURST_INC4     =    ((uint32_t)DMA_SxCR_MBURST_0),
    DMA_MBURST_INC8     =    ((uint32_t)DMA_SxCR_MBURST_1),
    DMA_MBURST_INC16    =    ((uint32_t)DMA_SxCR_MBURST)
};
/** @defgroup DMA_Peripheral_burst DMA Peripheral burst
  * @brief    DMA peripheral burst
  * @{
  */
enum DMAPeripheralBurst
{
    DMA_PBURST_SINGLE   =    ((uint32_t)0x00000000U),
    DMA_PBURST_INC4     =    ((uint32_t)DMA_SxCR_PBURST_0),
    DMA_PBURST_INC8     =    ((uint32_t)DMA_SxCR_PBURST_1),
    DMA_PBURST_INC16    =    ((uint32_t)DMA_SxCR_PBURST)
};
/** @defgroup DMA_interrupt_enable_definitions DMA interrupt enable definitions
  * @brief    DMA interrupts definition
  * @{
  */
enum DMAISRType
{
    DMA_IT_TC           =             ((uint32_t)DMA_SxCR_TCIE),
    DMA_IT_HT           =             ((uint32_t)DMA_SxCR_HTIE),
    DMA_IT_TE           =             ((uint32_t)DMA_SxCR_TEIE),
    DMA_IT_DME          =             ((uint32_t)DMA_SxCR_DMEIE),
    DMA_IT_FE           =             ((uint32_t)0x00000080U)
};
/** @defgroup DMA_flag_definitions DMA flag definitions
  * @brief    DMA flag definitions
  * @{
  */
enum DMAFlag
{
    DMA_FLAG_FEIF0_4         =          ((uint32_t)0x00000001U),
    DMA_FLAG_DMEIF0_4        =          ((uint32_t)0x00000004U),
    DMA_FLAG_TEIF0_4         =          ((uint32_t)0x00000008U),
    DMA_FLAG_HTIF0_4         =          ((uint32_t)0x00000010U),
    DMA_FLAG_TCIF0_4         =          ((uint32_t)0x00000020U),
    DMA_FLAG_FEIF1_5         =          ((uint32_t)0x00000040U),
    DMA_FLAG_DMEIF1_5        =          ((uint32_t)0x00000100U),
    DMA_FLAG_TEIF1_5         =          ((uint32_t)0x00000200U),
    DMA_FLAG_HTIF1_5         =          ((uint32_t)0x00000400U),
    DMA_FLAG_TCIF1_5         =          ((uint32_t)0x00000800U),
    DMA_FLAG_FEIF2_6         =          ((uint32_t)0x00010000U),
    DMA_FLAG_DMEIF2_6        =          ((uint32_t)0x00040000U),
    DMA_FLAG_TEIF2_6         =          ((uint32_t)0x00080000U),
    DMA_FLAG_HTIF2_6         =          ((uint32_t)0x00100000U),
    DMA_FLAG_TCIF2_6         =          ((uint32_t)0x00200000U),
    DMA_FLAG_FEIF3_7         =          ((uint32_t)0x00400000U),
    DMA_FLAG_DMEIF3_7        =          ((uint32_t)0x01000000U),
    DMA_FLAG_TEIF3_7         =          ((uint32_t)0x02000000U),
    DMA_FLAG_HTIF3_7         =          ((uint32_t)0x04000000U),
    DMA_FLAG_TCIF3_7         =          ((uint32_t)0x08000000U)
};
/** @defgroup BDMA_flag_definitions BDMA flag definitions
  * @brief    BDMA flag definitions
  * @{
  */
enum BDMAFlag
{
    BDMA_FLAG_GL0           =           ((uint32_t)0x00000001),
    BDMA_FLAG_TC0           =           ((uint32_t)0x00000002),
    BDMA_FLAG_HT0           =           ((uint32_t)0x00000004),
    BDMA_FLAG_TE0           =           ((uint32_t)0x00000008),
    BDMA_FLAG_GL1           =           ((uint32_t)0x00000010),
    BDMA_FLAG_TC1           =           ((uint32_t)0x00000020),
    BDMA_FLAG_HT1           =           ((uint32_t)0x00000040),
    BDMA_FLAG_TE1           =           ((uint32_t)0x00000080),
    BDMA_FLAG_GL2           =           ((uint32_t)0x00000100),
    BDMA_FLAG_TC2           =           ((uint32_t)0x00000200),
    BDMA_FLAG_HT2           =           ((uint32_t)0x00000400),
    BDMA_FLAG_TE2           =           ((uint32_t)0x00000800),
    BDMA_FLAG_GL3           =           ((uint32_t)0x00001000),
    BDMA_FLAG_TC3           =           ((uint32_t)0x00002000),
    BDMA_FLAG_HT3           =           ((uint32_t)0x00004000),
    BDMA_FLAG_TE3           =           ((uint32_t)0x00008000),
    BDMA_FLAG_GL4           =           ((uint32_t)0x00010000),
    BDMA_FLAG_TC4           =           ((uint32_t)0x00020000),
    BDMA_FLAG_HT4           =           ((uint32_t)0x00040000),
    BDMA_FLAG_TE4           =           ((uint32_t)0x00080000),
    BDMA_FLAG_GL5           =           ((uint32_t)0x00100000),
    BDMA_FLAG_TC5           =           ((uint32_t)0x00200000),
    BDMA_FLAG_HT5           =           ((uint32_t)0x00400000),
    BDMA_FLAG_TE5           =           ((uint32_t)0x00800000),
    BDMA_FLAG_GL6           =           ((uint32_t)0x01000000),
    BDMA_FLAG_TC6           =           ((uint32_t)0x02000000),
    BDMA_FLAG_HT6           =           ((uint32_t)0x04000000),
    BDMA_FLAG_TE6           =           ((uint32_t)0x08000000),
    BDMA_FLAG_GL7           =           ((uint32_t)0x10000000),
    BDMA_FLAG_TC7           =           ((uint32_t)0x20000000),
    BDMA_FLAG_HT7           =           ((uint32_t)0x40000000),
    BDMA_FLAG_TE7           =           ((uint32_t)0x80000000)
};
/**
  * @brief DMA Memory definition
  */
enum DMAMemory
{
  DMA_MEMORY0      = 0x00U,    /*!< Memory 0     */
  DMA_MEMORY1      = 0x01U,    /*!< Memory 1     */
};
/**
  * @brief  HAL DMA Transfer complete level structure definition
  */
enum DMALevelTransfer
{
  DMA_FULL_TRANSFER      = 0x00U,    /*!< Full transfer     */
  DMA_HALF_TRANSFER      = 0x01U,    /*!< Half Transfer     */
};
enum DMAMUXOverRunType
{
    DMAMUX_OVERRUN_TYPE_SYNC,
    DMAMUX_OVERRUN_TYPE_GEN
};
enum DMATransferIsrType
{
    DMA_TRANSFER_HALF,
    DMA_TRANSFER_HALF_MEMORY1,
    DMA_TRANSFER_COMPLETE,
    DMA_TRANSFER_COMPLETE_MEMORY1,
    DMA_TRANSFER_ERROR,
    DMA_TRANSFER_ABORT,
};
union DMABaseType
{
    DMA_Stream_TypeDef* stream_;
    BDMA_Channel_TypeDef* channel_;
};

struct DMAConfig
{
    union
    {
        DMARequest dma_;
        BDMARequest bdma_;
    }request_;
    union
    {
        DMATransDirection dma_;
        BDMATransDirection bdma_;
    }direction_;             
    DMAPeripheralIncrementMode periphInc_;                    
    DMAMemoryIncrementMode memInc_;                     
    DMAPeripheralAlignMent periphDataAlignment_; 
    DMAMemoryAlignMent memDataAlignment_;    
    DMAMode mode_;                    
    DMAPriorityLevel priority_;            
    DMAFifoMode fifoMode_;            
    DMAFifoThreshold fifoThreshold_;       
    DMAMemoryBurst memBurst_;                
    DMAPeripheralBurst periphBurst_;
    DMABaseType dmaStreamOrChannel_;
};

/**
  * @brief  HAL DMAMUX Synchronization configuration structure definition
  */
struct DMAMuxSyncConfig
{
    union
    {
        DMAMUX1SyncID mux1SyncId_;
        DMAMUX2SyncID mux2SyncId_;
    }id;

    uint32_t syncSignalID_;  /*!< Specifies the synchronization signal gating the DMA request in periodic mode.
                                This parameter can be a value of @ref DMAEx_MUX_SyncSignalID_selection */
    DMAMUXSyncPolarity syncPolarity_;  /*!< Specifies the polarity of the signal on which the DMA request is synchronized.
                                This parameter can be a value of @ref DMAEx_MUX_SyncPolarity_selection */
    FunctionalState syncEnable_;  /*!< Specifies if the synchronization shall be enabled or disabled
                                        This parameter can take the value ENABLE or DISABLE*/
    FunctionalState eventEnable_;    /*!< Specifies if an event shall be generated once the RequestNumber is reached.
                                        This parameter can take the value ENABLE or DISABLE */
    uint32_t requestNumber_; /*!< Specifies the number of DMA request that will be authorized after a sync event.
                                This parameters can be in the range 1 to 32 */
};
struct DMAMuxReqGeneratorConfig
{
    union
    {
        DMAMUX1ReqGenID mux1ReqGenId_;
        DMAMUX2ReqGenID mux2ReqGenId_;
    }id;
    DMAMuxReqGenPolarity polarity_;         /*!< Specifies the polarity of the signal on which the request is generated.
                                            This parameter can be a value of @ref DMAEx_MUX_RequestGeneneratorPolarity_selection */
    uint32_t requestNumber_;                /*!< Specifies the number of DMA request that will be generated after a signal event.
                                            This parameters can be in the range 1 to 32 */
};
struct DMABaseRegisters
{
  __IO uint32_t ISR;   /*!< DMA interrupt status register */
  __IO uint32_t Reserved0;
  __IO uint32_t IFCR;  /*!< DMA interrupt flag clear register */
};
struct BDMABaseRegisters
{
  __IO uint32_t ISR;   /*!< BDMA interrupt status register */
  __IO uint32_t IFCR;  /*!< BDMA interrupt flag clear register */
};
class DMA
{
    using DMAInterruptCb = std::function<void(DMA*, DMATransferIsrType)>;
    using DMAMUXInterruptCb = std::function<void(DMA*, DMAMUXOverRunType)>;
public:
    DMA():state_(DMA_STATE_RESET),errorCode_(DMA_ERROR_NONE),streamBaseAddress_(0),streamIndex_(0),
    muxChannel_(nullptr),muxChannelStatus_(nullptr),muxChannelStatusMask_(0),muxRequestGen_(nullptr),
    muxRequestGenStatus_(nullptr),muxRequestGenStatusMask_(0),dmax_(nullptr),pdmacfg_(nullptr)
    {
        
    }
    ~DMA()
    {
    }
    DMA(const DMA&) = delete;
    DMA(DMA&&) = delete;
    DMA& operator=(const DMA&) = delete;
    DMA& operator=(DMA&&) = delete;
    eResult dmaInit(DMAConfig* dmacfg)
    {
        uint32_t registerValue = 0U;
        uint32_t tickstart = getTick();
        DMABaseRegisters *regsDma = nullptr;
        BDMABaseRegisters *regsBdma = nullptr;

        /* Check the DMA peripheral handle */
        CHECK_RETURN(pdmacfg_, E_RESULT_NULL_POINT);

        pdmacfg_ = dmacfg;
        /* Check the parameters */
        CHECK_RETURN(IS_DMA_STREAM_INSTANCE(pdmacfg_->dmaStreamOrChannel_.stream_) || IS_BDMA_CHANNEL_INSTANCE(pdmacfg_->dmaStreamOrChannel_.channel_), E_RESULT_INVALID_PARAM);

        if(IS_DMA_STREAM_INSTANCE(pdmacfg_->dmaStreamOrChannel_.stream_) != 0U) /* DMA1 or DMA2 instance */
        {
            /* Check the memory burst, peripheral burst and FIFO threshold parameters only
             Change DMA peripheral state */
            state_ = DMA_STATE_BUSY;
            /* Disable the peripheral */
            dmaEnable(false);

            /* Check if the DMA Stream is effectively disabled */
            while((((DMA_Stream_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.stream_)->CR & DMA_SxCR_EN) != 0U)
            {
                /* Check for the Timeout */
                if((getTick() - tickstart ) > 5)
                {
                    /* Update error code */
                    errorCode_ = DMA_ERROR_TIMEOUT;

                    /* Change the DMA state */
                    state_ = DMA_STATE_ERROR;

                    return E_RESULT_ERROR;
                }
            }

            /* Get the CR register value */
            registerValue = ((DMA_Stream_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.stream_)->CR;

            /* Clear CHSEL, MBURST, PBURST, PL, MSIZE, PSIZE, MINC, PINC, CIRC, DIR, CT and DBM bits */
            registerValue &= ((uint32_t)~(DMA_SxCR_MBURST | DMA_SxCR_PBURST | \
                                DMA_SxCR_PL    | DMA_SxCR_MSIZE  | DMA_SxCR_PSIZE  | \
                                DMA_SxCR_MINC  | DMA_SxCR_PINC   | DMA_SxCR_CIRC   | \
                                DMA_SxCR_DIR   | DMA_SxCR_CT     | DMA_SxCR_DBM));

            /* Prepare the DMA Stream configuration */
            registerValue |=  pdmacfg_->direction_.dma_ |
                    pdmacfg_->periphInc_           | pdmacfg_->memInc_           |
                    pdmacfg_->periphDataAlignment_ | pdmacfg_->memDataAlignment_ |
                    pdmacfg_->mode_                | pdmacfg_->priority_;

            /* the Memory burst and peripheral burst are not used when the FIFO is disabled */
            if(pdmacfg_->fifoMode_ == DMA_FIFOMODE_ENABLE)
            {
                /* Get memory burst and peripheral burst */
                registerValue |=  pdmacfg_->memBurst_ | pdmacfg_->periphBurst_;
            }

            /* Work around for Errata 2.22: UART/USART- DMA transfer lock: DMA stream could be
                                            lock when transferring data to/from USART/UART */
            #if (STM32H7_DEV_ID == 0x450UL)
            if((DBGMCU->IDCODE & 0xFFFF0000U) >= 0x20000000U)
            {
            #endif /* STM32H7_DEV_ID == 0x450UL */
                if(IS_DMA_UART_USART_REQUEST(pdmacfg_->request_.dma_) != 0U)
                {
                    registerValue |= DMA_SxCR_TRBUFF;
                }
            #if (STM32H7_DEV_ID == 0x450UL)
            }
            #endif /* STM32H7_DEV_ID == 0x450UL */

            /* Write to DMA Stream CR register */
            ((DMA_Stream_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.stream_)->CR = registerValue;

            /* Get the FCR register value */
            registerValue = ((DMA_Stream_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.stream_)->FCR;

            /* Clear Direct mode and FIFO threshold bits */
            registerValue &= (uint32_t)~(DMA_SxFCR_DMDIS | DMA_SxFCR_FTH);

            /* Prepare the DMA Stream FIFO configuration */
            registerValue |= pdmacfg_->fifoMode_;

            /* the FIFO threshold is not used when the FIFO mode is disabled */
            if(pdmacfg_->fifoMode_ == DMA_FIFOMODE_ENABLE)
            {
                /* Get the FIFO threshold */
                registerValue |= pdmacfg_->fifoThreshold_;

                /* Check compatibility between FIFO threshold level and size of the memory burst */
                /* for INCR4, INCR8, INCR16 */
                if(pdmacfg_->memBurst_ != DMA_MBURST_SINGLE)
                {
                    if (checkFifoParam() != E_RESULT_OK)
                    {
                        /* Update error code */
                        errorCode_ = DMA_ERROR_PARAM;

                        /* Change the DMA state */
                        state_ = DMA_STATE_READY;

                        return E_RESULT_ERROR;
                    }
                }
            }
            /* Write to DMA Stream FCR */
            ((DMA_Stream_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.stream_)->FCR = registerValue;

            /* Initialize StreamBaseAddress and StreamIndex parameters to be used to calculate
            DMA steam Base Address needed by HAL_DMA_IRQHandler() and HAL_DMA_PollForTransfer() */
            regsDma = (DMABaseRegisters *)calcBaseAndBitshift();

            /* Clear all interrupt flags */
            regsDma->IFCR = 0x3FUL << (streamIndex_ & 0x1FU);
        }
        else if(IS_BDMA_CHANNEL_INSTANCE(pdmacfg_->dmaStreamOrChannel_.channel_) != 0U) /* BDMA instance(s) */
        {
            /* Change DMA peripheral state */
            state_ = DMA_STATE_BUSY;

            /* Get the CR register value */
            registerValue = ((BDMA_Channel_TypeDef *)pdmacfg_->dmaStreamOrChannel_.channel_)->CCR;

            /* Clear PL, MSIZE, PSIZE, MINC, PINC, CIRC, DIR, MEM2MEM, DBM and CT bits */
            registerValue &= ((uint32_t)~(BDMA_CCR_PL    | BDMA_CCR_MSIZE   | BDMA_CCR_PSIZE  | \
                                        BDMA_CCR_MINC  | BDMA_CCR_PINC    | BDMA_CCR_CIRC   | \
                                        BDMA_CCR_DIR   | BDMA_CCR_MEM2MEM | BDMA_CCR_DBM    | \
                                        BDMA_CCR_CT));

            /* Prepare the DMA Channel configuration */
            registerValue |=    pdmacfg_->direction_.bdma_              |
                                (pdmacfg_->periphInc_ >> 3U)            |
                                (pdmacfg_->memInc_ >> 3U)               |
                                (pdmacfg_->periphDataAlignment_ >> 3U)  |
                                (pdmacfg_->memDataAlignment_ >> 3U)     |
                                (pdmacfg_->mode_ >> 3U)                 |
                                (pdmacfg_->priority_ >> 4U);

            /* Write to DMA Channel CR register */
            ((BDMA_Channel_TypeDef *)pdmacfg_->dmaStreamOrChannel_.channel_)->CCR = registerValue;

            /* calculation of the channel index */
            streamIndex_ = (((uint32_t)((uint32_t*)pdmacfg_->dmaStreamOrChannel_.channel_) - (uint32_t)BDMA_Channel0) / ((uint32_t)BDMA_Channel1 - (uint32_t)BDMA_Channel0)) << 2U;

            /* Initialize StreamBaseAddress and StreamIndex parameters to be used to calculate
            DMA steam Base Address needed by HAL_DMA_IRQHandler() and HAL_DMA_PollForTransfer() */
            regsBdma = (BDMABaseRegisters *)calcBaseAndBitshift();

            /* Clear all interrupt flags */
            regsBdma->IFCR = ((BDMA_IFCR_CGIF0) << (streamIndex_ & 0x1FU));
        }
        else
        {
            errorCode_ = DMA_ERROR_PARAM;
            state_     = DMA_STATE_ERROR;

            return E_RESULT_ERROR;
        }
        if(IS_DMA_STREAM_DMAMUX_INSTANCE(pdmacfg_->dmaStreamOrChannel_.stream_) || IS_BDMA_CHANNEL_DMAMUX_INSTANCE(pdmacfg_->dmaStreamOrChannel_.channel_)) /* No DMAMUX available for BDMA1 */
        {
            /* Initialize parameters for DMAMUX channel :
            DMAmuxChannel, DMAmuxChannelStatus and DMAmuxChannelStatusMask
            */
            calcDMAMUXChannelBaseAndMask();

            if(IS_DMA_STREAM_DMAMUX_INSTANCE(pdmacfg_->dmaStreamOrChannel_.stream_) && (pdmacfg_->direction_.dma_ == DMA_MEMORY_TO_MEMORY))
            {
                /* if memory to memory force the request to 0*/
                pdmacfg_->request_.dma_ = DMA_REQUEST_MEM2MEM;
                /* Set peripheral request  to DMAMUX channel */
                muxChannel_->CCR = (pdmacfg_->request_.dma_ & DMAMUX_CxCR_DMAREQ_ID);
            }
            else if(IS_BDMA_CHANNEL_DMAMUX_INSTANCE(pdmacfg_->dmaStreamOrChannel_.channel_) && (pdmacfg_->direction_.bdma_ == BDMA_MEMORY_TO_MEMORY))
            {
                /* if memory to memory force the request to 0*/
                pdmacfg_->request_.bdma_ = BDMA_REQUEST_MEM2MEM;
                /* Set peripheral request  to DMAMUX channel */
                muxChannel_->CCR = (pdmacfg_->request_.bdma_ & DMAMUX_CxCR_DMAREQ_ID);
            }

            /* Clear the DMAMUX synchro overrun flag */
            muxChannelStatus_->CFR = muxChannelStatusMask_;

            /* Initialize parameters for DMAMUX request generator :
            if the DMA request is DMA_REQUEST_GENERATOR0 to DMA_REQUEST_GENERATOR7
            */
            if((IS_DMA_STREAM_DMAMUX_INSTANCE(pdmacfg_->dmaStreamOrChannel_.stream_) && (pdmacfg_->request_.dma_ >= DMA_REQUEST_GENERATOR0) && (pdmacfg_->request_.dma_ <= DMA_REQUEST_GENERATOR7)) || 
                    (IS_BDMA_CHANNEL_DMAMUX_INSTANCE(pdmacfg_->dmaStreamOrChannel_.channel_) && (pdmacfg_->request_.bdma_ >= BDMA_REQUEST_GENERATOR0) && (pdmacfg_->request_.bdma_ <= BDMA_REQUEST_GENERATOR7)))
            {
                /* Initialize parameters for DMAMUX request generator :
                DMAmuxRequestGen, DMAmuxRequestGenStatus and DMAmuxRequestGenStatusMask */
                calcDMAMUXRequestGenBaseAndMask();

                /* Reset the DMAMUX request generator register */
                muxRequestGen_->RGCR = 0U;

                /* Clear the DMAMUX request generator overrun flag */
                muxRequestGenStatus_->RGCFR = muxRequestGenStatusMask_;
            }
            else
            {
                muxRequestGen_ = 0U;
                muxRequestGenStatus_ = 0U;
                muxRequestGenStatusMask_ = 0U;
            }
        }

        /* Initialize the error code */
        errorCode_ = DMA_ERROR_NONE;
        /* Initialize the DMA state */
        state_ = DMA_STATE_READY;

        //Init DMA Interrupt
        if(IS_DMA_STREAM_DMAMUX_INSTANCE(pdmacfg_->dmaStreamOrChannel_.stream_))
        {
            registerDMAIsrCb(pdmacfg_->dmaStreamOrChannel_.stream_, [](void* param, uint8_t bDMAMuxISR){
                DMA* pdma = reinterpret_cast<DMA*>(param);
                if(!pdma)
                {
                    return;
                }
                if(bDMAMuxISR)
                {
                    pdma->muxIsrHandler();
                }
                else
                {
                    pdma->dmaIRQHandler();
                }
            }, this);
        }
        else if(IS_BDMA_CHANNEL_DMAMUX_INSTANCE(pdmacfg_->dmaStreamOrChannel_.channel_))
        {
            registerBDMAIsrCb(pdmacfg_->dmaStreamOrChannel_.channel_, [](void* param, uint8_t bDMAMuxISR){
                DMA* pdma = reinterpret_cast<DMA*>(param);
                if(!pdma)
                {
                    return;
                }
                if(bDMAMuxISR)
                {
                    pdma->muxIsrHandler();
                }
                else
                {
                    pdma->dmaIRQHandler();
                }
            }, this);
        }
        enableIsrInReg();

        return E_RESULT_OK;
    }
    eResult dmaDeInit()
    {
        DMABaseRegisters *regs_dma;
        BDMABaseRegisters *regs_bdma;

        /* Check the DMA peripheral handle */
        CHECK_RETURN(pdmacfg_, E_RESULT_NULL_POINT);

        /* Disable the selected DMA Streamx */
        dmaEnable(false);

        if(IS_DMA_STREAM_DMAMUX_INSTANCE(pdmacfg_->dmaStreamOrChannel_.stream_))
        {
            unRegisterDMAIsrCb(pdmacfg_->dmaStreamOrChannel_.stream_);
        }
        else
        {
            unRegisterBDMAIsrCb(pdmacfg_->dmaStreamOrChannel_.channel_);
        }
        disableIsrInReg();
        if(IS_DMA_STREAM_INSTANCE(pdmacfg_->dmaStreamOrChannel_.stream_) != 0U) /* DMA1 or DMA2 instance */
        {
            /* Reset DMA Streamx control register */
            ((DMA_Stream_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.stream_)->CR   = 0U;

            /* Reset DMA Streamx number of data to transfer register */
            ((DMA_Stream_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.stream_)->NDTR = 0U;

            /* Reset DMA Streamx peripheral address register */
            ((DMA_Stream_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.stream_)->PAR  = 0U;

            /* Reset DMA Streamx memory 0 address register */
            ((DMA_Stream_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.stream_)->M0AR = 0U;

            /* Reset DMA Streamx memory 1 address register */
            ((DMA_Stream_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.stream_)->M1AR = 0U;

            /* Reset DMA Streamx FIFO control register */
            ((DMA_Stream_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.stream_)->FCR  = (uint32_t)0x00000021U;

            /* Get DMA steam Base Address */
            regs_dma = (DMABaseRegisters *)calcBaseAndBitshift();

            /* Clear all interrupt flags at correct offset within the register */
            regs_dma->IFCR = 0x3FUL << (streamIndex_ & 0x1FU);
        }
        else if(IS_BDMA_CHANNEL_INSTANCE(pdmacfg_->dmaStreamOrChannel_.channel_) != 0U) /* BDMA instance(s) */
        {
            /* Reset DMA Channel control register */
            ((BDMA_Channel_TypeDef *)pdmacfg_->dmaStreamOrChannel_.channel_)->CCR  = 0U;

            /* Reset DMA Channel Number of Data to Transfer register */
            ((BDMA_Channel_TypeDef *)pdmacfg_->dmaStreamOrChannel_.channel_)->CNDTR = 0U;

            /* Reset DMA Channel peripheral address register */
            ((BDMA_Channel_TypeDef *)pdmacfg_->dmaStreamOrChannel_.channel_)->CPAR  = 0U;

            /* Reset DMA Channel memory 0 address register */
            ((BDMA_Channel_TypeDef *)pdmacfg_->dmaStreamOrChannel_.channel_)->CM0AR = 0U;

            /* Reset DMA Channel memory 1 address register */
            ((BDMA_Channel_TypeDef *)pdmacfg_->dmaStreamOrChannel_.channel_)->CM1AR = 0U;

            /* Get DMA steam Base Address */
            regs_bdma = (BDMABaseRegisters *)calcBaseAndBitshift();

            /* Clear all interrupt flags at correct offset within the register */
            regs_bdma->IFCR = ((BDMA_IFCR_CGIF0) << (streamIndex_ & 0x1FU));
        }
        else
        {
            /* Return error status */
            return E_RESULT_ERROR;
        }

        /* Initialize parameters for DMAMUX channel :
        DMAmuxChannel, DMAmuxChannelStatus and DMAmuxChannelStatusMask */
        calcDMAMUXChannelBaseAndMask();

        if(muxChannel_ != nullptr)
        {
            /* Resett he DMAMUX channel that corresponds to the DMA stream */
            muxChannel_->CCR = 0U;

            /* Clear the DMAMUX synchro overrun flag */
            muxChannelStatus_->CFR = muxChannelStatusMask_;
        }

        if(IS_DMA_STREAM_INSTANCE(pdmacfg_->dmaStreamOrChannel_.stream_) && (pdmacfg_->request_.dma_ >= DMA_REQUEST_GENERATOR0) && (pdmacfg_->request_.dma_ <= DMA_REQUEST_GENERATOR7))
        {
            /* Initialize parameters for DMAMUX request generator :
            DMAmuxRequestGen, DMAmuxRequestGenStatus and DMAmuxRequestGenStatusMask */
            calcDMAMUXRequestGenBaseAndMask();

            /* Reset the DMAMUX request generator register */
            muxRequestGen_->RGCR = 0U;

            /* Clear the DMAMUX request generator overrun flag */
            muxRequestGenStatus_->RGCFR = muxRequestGenStatusMask_;
        }
        else if(IS_BDMA_CHANNEL_INSTANCE(pdmacfg_->dmaStreamOrChannel_.channel_) && (pdmacfg_->request_.bdma_ >= BDMA_REQUEST_GENERATOR0) && (pdmacfg_->request_.bdma_ <= BDMA_REQUEST_GENERATOR7))
        {
            /* Initialize parameters for DMAMUX request generator :
            DMAmuxRequestGen, DMAmuxRequestGenStatus and DMAmuxRequestGenStatusMask */
            calcDMAMUXRequestGenBaseAndMask();

            /* Reset the DMAMUX request generator register */
            muxRequestGen_->RGCR = 0U;

            /* Clear the DMAMUX request generator overrun flag */
            muxRequestGenStatus_->RGCFR = muxRequestGenStatusMask_;
        }

        muxRequestGen_ = nullptr;
        muxRequestGenStatus_ = nullptr;
        muxRequestGenStatusMask_ = 0U;

        /* Initialize the error code */
        errorCode_ = DMA_ERROR_NONE;

        /* Initialize the DMA state */
        state_ = DMA_STATE_RESET;

        return E_RESULT_OK;
    }
    eResult start(uint32_t srcAddress, uint32_t dstAddress, uint32_t dataLength)
    {
        eResult result = E_RESULT_OK;
        CHECK_RETURN(pdmacfg_, E_RESULT_NULL_POINT);
        CHECK_RETURN((((dataLength) >= 0x01U) && ((dataLength) < 0x10000U)), E_RESULT_INVALID_PARAM);
        if(DMA_STATE_READY == state_)
        {
            /* Change DMA peripheral state */
            state_ = DMA_STATE_BUSY;

            /* Initialize the error code */
            errorCode_ = DMA_ERROR_NONE;

            /* Disable the peripheral */
            dmaEnable(false);

            /* Configure the source, destination address and the data length */
            dmaSetConfig(srcAddress, dstAddress, dataLength);

            /* Enable the Peripheral */
            dmaEnable(true);
        }
        else
        {
            /* Set the error code to busy */
            errorCode_ = DMA_ERROR_BUSY;

            /* Return error status */
            result = E_RESULT_ERROR;
        }
        return result;
    }
    eResult abort()
    {
        /* calculate DMA base and stream number */
        DMABaseRegisters *regs_dma;
        BDMABaseRegisters *regs_bdma;
        const __IO uint32_t *enableRegister;

        uint32_t tickstart = getTick();

        /* Check the DMA peripheral handle */
        CHECK_RETURN(pdmacfg_, E_RESULT_NULL_POINT);

        /* Check the DMA peripheral state */
        if(state_ != DMA_STATE_BUSY)
        {
            errorCode_ = DMA_ERROR_NO_XFER;
            return E_RESULT_ERROR;
        }
        else
        {
            /* Disable all the transfer interrupts */
            if(IS_DMA_STREAM_INSTANCE(pdmacfg_->dmaStreamOrChannel_.stream_) != 0U) /* DMA1 or DMA2 instance */
            {
                /* Disable DMA All Interrupts  */
                ((DMA_Stream_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.stream_)->CR  &= ~(DMA_IT_TC | DMA_IT_TE | DMA_IT_DME | DMA_IT_HT);
                ((DMA_Stream_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.stream_)->FCR &= ~(DMA_IT_FE);

                enableRegister = (__IO uint32_t *)(&(((DMA_Stream_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.stream_)->CR));
            }
            else /* BDMA channel */
            {
                /* Disable DMA All Interrupts */
                ((BDMA_Channel_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.channel_)->CCR  &= ~(BDMA_CCR_TCIE | BDMA_CCR_HTIE | BDMA_CCR_TEIE);

                enableRegister = (__IO uint32_t *)(&(((BDMA_Channel_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.channel_)->CCR));
            }

            if(IS_DMA_STREAM_DMAMUX_INSTANCE(pdmacfg_->dmaStreamOrChannel_.stream_) || IS_BDMA_CHANNEL_DMAMUX_INSTANCE(pdmacfg_->dmaStreamOrChannel_.channel_)) /* No DMAMUX available for BDMA1 */
            {
                /* disable the DMAMUX sync overrun IT */
                muxChannel_->CCR &= ~DMAMUX_CxCR_SOIE;
            }

            /* Disable the stream */
            dmaEnable(false);

            /* Check if the DMA Stream is effectively disabled */
            while(((*enableRegister) & DMA_SxCR_EN) != 0U)
            {
                /* Check for the Timeout */
                if((getTick() - tickstart ) > 5)
                {
                    /* Update error code */
                    errorCode_ = DMA_ERROR_TIMEOUT;

                    /* Change the DMA state */
                    state_ = DMA_STATE_ERROR;

                    return E_RESULT_ERROR;
                }
            }

            /* Clear all interrupt flags at correct offset within the register */
            if(IS_DMA_STREAM_INSTANCE(pdmacfg_->dmaStreamOrChannel_.stream_) != 0U) /* DMA1 or DMA2 instance */
            {
                regs_dma = (DMABaseRegisters *)streamBaseAddress_;
                regs_dma->IFCR = 0x3FUL << (streamIndex_ & 0x1FU);
            }
            else /* BDMA channel */
            {
                regs_bdma = (BDMABaseRegisters *)streamBaseAddress_;
                regs_bdma->IFCR = ((BDMA_IFCR_CGIF0) << (streamIndex_ & 0x1FU));
            }

            if(IS_DMA_STREAM_DMAMUX_INSTANCE(pdmacfg_->dmaStreamOrChannel_.stream_) || IS_BDMA_CHANNEL_DMAMUX_INSTANCE(pdmacfg_->dmaStreamOrChannel_.channel_)) /* No DMAMUX available for BDMA1 */
            {
                /* Clear the DMAMUX synchro overrun flag */
                muxChannelStatus_->CFR = muxChannelStatusMask_;

            if(muxRequestGen_ != nullptr)
            {
                /* if using DMAMUX request generator, disable the DMAMUX request generator overrun IT */
                /* disable the request gen overrun IT */
                muxRequestGen_->RGCR &= ~DMAMUX_RGxCR_OIE;

                /* Clear the DMAMUX request generator overrun flag */
                muxRequestGenStatus_->RGCFR = muxRequestGenStatusMask_;
            }
            }

            /* Change the DMA state */
            state_ = DMA_STATE_READY;
        }

        return E_RESULT_OK;
    }
    eResult pollForTransfer(DMALevelTransfer completeLevel, uint32_t timeout)
    {
        eResult result = E_RESULT_OK;
        uint32_t cpltlevel_mask;
        uint32_t tickstart = getTick();

        /* IT status register */
        __IO uint32_t *isr_reg;
        /* IT clear flag register */
        __IO uint32_t *ifcr_reg;

        /* Check the DMA peripheral handle */
        CHECK_RETURN(pdmacfg_, E_RESULT_NULL_POINT);

        if(DMA_STATE_BUSY != state_)
        {
            /* No transfer ongoing */
            errorCode_ = DMA_ERROR_NO_XFER;
            return E_RESULT_ERROR;
        }

        if(IS_DMA_STREAM_INSTANCE(pdmacfg_->dmaStreamOrChannel_.stream_) != 0U) /* DMA1 or DMA2 instance */
        {
            /* Polling mode not supported in circular mode and double buffering mode */
            if ((((DMA_Stream_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.stream_)->CR & DMA_SxCR_CIRC) != 0U)
            {
                errorCode_ = DMA_ERROR_NOT_SUPPORTED;
                return E_RESULT_ERROR;
            }

            /* Get the level transfer complete flag */
            if(completeLevel == DMA_FULL_TRANSFER)
            {
                /* Transfer Complete flag */
                cpltlevel_mask = DMA_FLAG_TCIF0_4 << (streamIndex_ & 0x1FU);
            }
            else
            {
                /* Half Transfer Complete flag */
                cpltlevel_mask = DMA_FLAG_HTIF0_4 << (streamIndex_ & 0x1FU);
            }

            isr_reg  = &(((DMABaseRegisters *)streamBaseAddress_)->ISR);
            ifcr_reg = &(((DMABaseRegisters *)streamBaseAddress_)->IFCR);
        }
        else /* BDMA channel */
        {
            /* Polling mode not supported in circular mode */
            if ((((BDMA_Channel_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.channel_)->CCR & BDMA_CCR_CIRC) != 0U)
            {
                errorCode_ = DMA_ERROR_NOT_SUPPORTED;
                return E_RESULT_ERROR;
            }

            /* Get the level transfer complete flag */
            if(completeLevel == DMA_FULL_TRANSFER)
            {
                /* Transfer Complete flag */
                cpltlevel_mask = BDMA_FLAG_TC0 << (streamIndex_ & 0x1FU);
            }
            else
            {
                /* Half Transfer Complete flag */
                cpltlevel_mask = BDMA_FLAG_HT0 << (streamIndex_ & 0x1FU);
            }

            isr_reg  = &(((BDMABaseRegisters *)streamBaseAddress_)->ISR);
            ifcr_reg = &(((BDMABaseRegisters *)streamBaseAddress_)->IFCR);
        }

        while(((*isr_reg) & cpltlevel_mask) == 0U)
        {
            if(IS_DMA_STREAM_INSTANCE(pdmacfg_->dmaStreamOrChannel_.stream_) != 0U) /* DMA1 or DMA2 instance */
            {
                if(((*isr_reg) & (DMA_FLAG_FEIF0_4 << (streamIndex_ & 0x1FU))) != 0U)
                {
                    /* Update error code */
                   errorCode_ |= DMA_ERROR_FE;

                    /* Clear the FIFO error flag */
                    (*ifcr_reg) = DMA_FLAG_FEIF0_4 << (streamIndex_ & 0x1FU);
                }

                if(((*isr_reg) & (DMA_FLAG_DMEIF0_4 << (streamIndex_ & 0x1FU))) != 0U)
                {
                    /* Update error code */
                    errorCode_ |= DMA_ERROR_DME;

                    /* Clear the Direct Mode error flag */
                    (*ifcr_reg) = DMA_FLAG_DMEIF0_4 << (streamIndex_ & 0x1FU);
                }

                if(((*isr_reg) & (DMA_FLAG_TEIF0_4 << (streamIndex_ & 0x1FU))) != 0U)
                {
                    /* Update error code */
                    errorCode_ |= DMA_ERROR_TE;

                    /* Clear the transfer error flag */
                    (*ifcr_reg) = DMA_FLAG_TEIF0_4 << (streamIndex_ & 0x1FU);

                    /* Change the DMA state */
                    state_ = DMA_STATE_READY;

                    return E_RESULT_ERROR;
                }
            }
            else /* BDMA channel */
            {
                if(((*isr_reg) & (BDMA_FLAG_TE0 << (streamIndex_ & 0x1FU))) != 0U)
                {
                    /* When a DMA transfer error occurs */
                    /* A hardware clear of its EN bits is performed */
                    /* Clear all flags */
                    (*isr_reg) = ((BDMA_ISR_GIF0) << (streamIndex_ & 0x1FU));

                    /* Update error code */
                    errorCode_ = DMA_ERROR_TE;

                    /* Change the DMA state */
                    state_ = DMA_STATE_READY;

                    return E_RESULT_ERROR;
                }
            }

            /* Check for the Timeout (Not applicable in circular mode)*/
            if(timeout != 0xFFFFFFFFU)
            {
                if(((getTick() - tickstart ) > timeout)||(timeout == 0U))
                {
                    /* Update error code */
                    errorCode_ = DMA_ERROR_TIMEOUT;

                    /* if timeout then abort the current transfer */
                    /* No need to check return value: as in this case we will return HAL_ERROR with HAL_DMA_ERROR_TIMEOUT error code  */
                    (void) abort();
                    /*
                        Note that the Abort function will
                        - Clear the transfer error flags
                        - Unlock
                        - Set the State
                    */

                    return E_RESULT_ERROR;
                }
            }

            if(IS_DMA_STREAM_DMAMUX_INSTANCE(pdmacfg_->dmaStreamOrChannel_.stream_) || IS_BDMA_CHANNEL_DMAMUX_INSTANCE(pdmacfg_->dmaStreamOrChannel_.channel_)) /* No DMAMUX available for BDMA1 */
            {
                /* Check for DMAMUX Request generator (if used) overrun status */
                if(muxRequestGen_ != nullptr)
                {
                    /* if using DMAMUX request generator Check for DMAMUX request generator overrun */
                    if((muxRequestGenStatus_->RGSR & muxRequestGenStatusMask_) != 0U)
                    {
                        /* Clear the DMAMUX request generator overrun flag */
                        muxRequestGenStatus_->RGCFR = muxRequestGenStatusMask_;

                        /* Update error code */
                        errorCode_ |= DMA_ERROR_REQGEN;
                    }
                }

                /* Check for DMAMUX Synchronization overrun */
                if((muxChannelStatus_->CSR & muxChannelStatusMask_) != 0U)
                {
                    /* Clear the DMAMUX synchro overrun flag */
                    muxChannelStatus_->CFR = muxChannelStatusMask_;

                    /* Update error code */
                    errorCode_ |= DMA_ERROR_SYNC;
                }
            }
        }

        /* Get the level transfer complete flag */
        if(completeLevel == DMA_FULL_TRANSFER)
        {
            /* Clear the half transfer and transfer complete flags */
            if(IS_DMA_STREAM_INSTANCE(pdmacfg_->dmaStreamOrChannel_.stream_) != 0U) /* DMA1 or DMA2 instance */
            {
                (*ifcr_reg) = (DMA_FLAG_HTIF0_4 | DMA_FLAG_TCIF0_4) << (streamIndex_ & 0x1FU);
            }
            else /* BDMA channel */
            {
                (*ifcr_reg) = (BDMA_FLAG_TC0 << (streamIndex_ & 0x1FU));
            }

            state_ = DMA_STATE_READY;
        }
        else /*CompleteLevel = HAL_DMA_HALF_TRANSFER*/
        {
            /* Clear the half transfer and transfer complete flags */
            if(IS_DMA_STREAM_INSTANCE(pdmacfg_->dmaStreamOrChannel_.stream_) != 0U) /* DMA1 or DMA2 instance */
            {
                (*ifcr_reg) = (DMA_FLAG_HTIF0_4) << (streamIndex_ & 0x1FU);
            }
            else /* BDMA channel */
            {
                (*ifcr_reg) = (BDMA_FLAG_HT0 << (streamIndex_ & 0x1FU));
            }
        }
        return E_RESULT_OK;
    }
    eResult configMuxSync(DMAMuxSyncConfig* pSyncConfig)
    {
        uint32_t syncSignalID = 0;
        uint32_t syncPolarity = 0;

        /* Check the parameters */
        CHECK_RETURN(pdmacfg_, E_RESULT_NULL_POINT);
        CHECK_RETURN(IS_DMA_STREAM_DMAMUX_INSTANCE(pdmacfg_->dmaStreamOrChannel_.stream_) || IS_BDMA_CHANNEL_DMAMUX_INSTANCE(pdmacfg_->dmaStreamOrChannel_.channel_), E_RESULT_INVALID_PARAM);
        CHECK_RETURN((pSyncConfig->requestNumber_ > 0U && pSyncConfig->requestNumber_ <= 32U), E_RESULT_INVALID_PARAM);

        if(pSyncConfig->requestNumber_ == ENABLE)
        {
            if(IS_DMA_STREAM_INSTANCE(pdmacfg_->dmaStreamOrChannel_.stream_) != 0U) /* DMA1 or DMA2 instance */
            {
                syncSignalID = pSyncConfig->id.mux1SyncId_;
            }
            else
            {
                syncSignalID = pSyncConfig->id.mux2SyncId_;
            }
            syncPolarity = pSyncConfig->syncPolarity_;
        }

        /*Check if the DMA state is ready */
        if(state_ == DMA_STATE_READY)
        {
            /* Disable the synchronization and event generation before applying a new config */
            CLEAR_BIT(muxChannel_->CCR,(DMAMUX_CxCR_SE | DMAMUX_CxCR_EGE));

            /* Set the new synchronization parameters (and keep the request ID filled during the Init)*/
            MODIFY_REG(muxChannel_->CCR, \
                    (~DMAMUX_CxCR_DMAREQ_ID) , \
                    (syncSignalID << DMAMUX_CxCR_SYNC_ID_Pos)       | \
                    ((pSyncConfig->requestNumber_ - 1U) << DMAMUX_CxCR_NBREQ_Pos) | \
                    syncPolarity | ((uint32_t)pSyncConfig->syncEnable_ << DMAMUX_CxCR_SE_Pos)    | \
                    ((uint32_t)pSyncConfig->eventEnable_ << DMAMUX_CxCR_EGE_Pos));
            return E_RESULT_OK;
        }
        else
        {
            return E_RESULT_ERROR;
        }
    }
    eResult configMuxRequestGenerator(DMAMuxReqGeneratorConfig* pReqGenConfig)
    {
        eResult status = E_RESULT_OK;
        DMAState tempState = state_;
        uint32_t signalID;
        /* Check the parameters */
        CHECK_RETURN(pdmacfg_, E_RESULT_NULL_POINT);
        CHECK_RETURN(IS_DMA_STREAM_DMAMUX_INSTANCE(pdmacfg_->dmaStreamOrChannel_.stream_) || IS_BDMA_CHANNEL_DMAMUX_INSTANCE(pdmacfg_->dmaStreamOrChannel_.channel_), E_RESULT_INVALID_PARAM);
        CHECK_RETURN((pReqGenConfig->requestNumber_ > 0U && pReqGenConfig->requestNumber_ <= 32U), E_RESULT_INVALID_PARAM);

        if(IS_DMA_STREAM_INSTANCE(pdmacfg_->dmaStreamOrChannel_.stream_) != 0U) /* DMA1 or DMA2 instance */
        {
            signalID = pReqGenConfig->id.mux1ReqGenId_;
        }
        else
        {
            signalID = pReqGenConfig->id.mux2ReqGenId_;
        }

        /* check if the DMA state is ready
            and DMA is using a DMAMUX request generator block
        */
        if(muxRequestGen_ == nullptr)
        {
            /* error status */
            status = E_RESULT_NULL_POINT;
        }
        else if(((muxRequestGen_->RGCR & DMAMUX_RGxCR_GE) == 0U) && (tempState == DMA_STATE_READY))
        {
            /* RequestGenerator must be disable prior to the configuration i.e GE bit is 0 */

            /* Set the request generator new parameters */
            muxRequestGen_->RGCR = signalID | ((pReqGenConfig->requestNumber_ - 1U) << DMAMUX_RGxCR_GNBREQ_Pos)| pReqGenConfig->polarity_;
            return E_RESULT_OK;
        }
        else
        {
            status = E_RESULT_WRONG_STATUS;
        }
        return status;
    }
    eResult enableMuxRequestGenerator (bool bEnable)
    {
        /* Check the parameters */
        CHECK_RETURN(pdmacfg_, E_RESULT_NULL_POINT);
        CHECK_RETURN(IS_DMA_STREAM_DMAMUX_INSTANCE(pdmacfg_->dmaStreamOrChannel_.stream_) || IS_BDMA_CHANNEL_DMAMUX_INSTANCE(pdmacfg_->dmaStreamOrChannel_.channel_), E_RESULT_INVALID_PARAM);

        /* check if the DMA state is ready
            and DMA is using a DMAMUX request generator block */
        if((state_ != DMA_STATE_RESET) && (muxRequestGen_ != 0U))
        {
            /* Enable the request generator*/
            if(bEnable)
            {
                muxRequestGen_->RGCR |= DMAMUX_RGxCR_GE;
            }
            else
            {
                muxRequestGen_->RGCR &= ~DMAMUX_RGxCR_GE;
            }
            return E_RESULT_OK;
        }
        else
        {
            return E_RESULT_ERROR;
        }
    }
    //双缓冲模式
    eResult multiBufferStart(uint32_t srcAddress, uint32_t dstAddress, uint32_t secondMemAddress, uint32_t dataLength)
    {
        eResult result = E_RESULT_OK;
        __IO uint32_t *ifcRegisterBase = nullptr; /* DMA Stream Interrupt Clear register */

        /* Check the parameters */
        CHECK_RETURN(pdmacfg_, E_RESULT_NULL_POINT);
        CHECK_RETURN(((dataLength >= 0x01U) && (dataLength < 0x10000U)), E_RESULT_OUT_OF_RANGE);
        CHECK_RETURN(IS_DMA_STREAM_INSTANCE(pdmacfg_->dmaStreamOrChannel_.stream_) || IS_BDMA_CHANNEL_INSTANCE(pdmacfg_->dmaStreamOrChannel_.channel_), E_RESULT_INVALID_PARAM);

        /* Memory-to-memory transfer not supported in double buffering mode */
        if (pdmacfg_->direction_.dma_ == DMA_MEMORY_TO_MEMORY)
        {
            errorCode_ = DMA_ERROR_NOT_SUPPORTED;
            result = E_RESULT_ERROR;
        }
        else
        {
            if(DMA_STATE_READY == state_)
            {
                /* Change DMA peripheral state */
                state_ = DMA_STATE_BUSY;

                /* Initialize the error code */
                errorCode_ = DMA_ERROR_NONE;

                if(IS_DMA_STREAM_INSTANCE(pdmacfg_->dmaStreamOrChannel_.stream_) != 0U) /* DMA1 or DMA2 instance */
                {
                    /* Enable the Double buffer mode */
                    ((DMA_Stream_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.stream_)->CR |= DMA_SxCR_DBM;

                    /* Configure DMA Stream destination address */
                    ((DMA_Stream_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.stream_)->M1AR = secondMemAddress;

                    /* Calculate the interrupt clear flag register (IFCR) base address  */
                    ifcRegisterBase = (uint32_t *)((uint32_t)(streamBaseAddress_ + 8U));

                    /* Clear all flags */
                    *ifcRegisterBase = 0x3FUL << (streamIndex_ & 0x1FU);
                }
                else /* BDMA instance(s) */
                {
                    /* Enable the Double buffer mode */
                    ((BDMA_Channel_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.channel_)->CCR |= (BDMA_CCR_DBM | BDMA_CCR_CIRC);

                    /* Configure DMA Stream destination address */
                    ((BDMA_Channel_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.channel_)->CM1AR = secondMemAddress;

                    /* Calculate the interrupt clear flag register (IFCR) base address  */
                    ifcRegisterBase = (uint32_t *)((uint32_t)(streamBaseAddress_ + 4U));

                    /* Clear all flags */
                    *ifcRegisterBase = (BDMA_ISR_GIF0) << (streamIndex_ & 0x1FU);
                }

                if((IS_DMA_STREAM_DMAMUX_INSTANCE(pdmacfg_->dmaStreamOrChannel_.stream_) || IS_BDMA_CHANNEL_DMAMUX_INSTANCE(pdmacfg_->dmaStreamOrChannel_.channel_)) != 0U) /* No DMAMUX available for BDMA1 */
                {
                    /* Configure the source, destination address and the data length */
                    multiBufferSetConfig(srcAddress, dstAddress, dataLength);

                    /* Clear the DMAMUX synchro overrun flag */
                    muxChannelStatus_->CFR = muxChannelStatusMask_;

                    if(muxRequestGen_ != nullptr)
                    {
                        /* Clear the DMAMUX request generator overrun flag */
                        muxRequestGenStatus_->RGCFR = muxRequestGenStatusMask_;
                    }
                }

                /* Enable the peripheral */
                dmaEnable(true);
            }
            else
            {
                /* Set the error code to busy */
                errorCode_ = DMA_ERROR_BUSY;

                /* Return error status */
                result = E_RESULT_ERROR;
            }
        }
        return result;
    }
    eResult changeMemory(uint32_t address, DMAMemory memory)
    {
        CHECK_RETURN(pdmacfg_, E_RESULT_NULL_POINT);
        if(IS_DMA_STREAM_INSTANCE(pdmacfg_->dmaStreamOrChannel_.stream_) != 0U) /* DMA1 or DMA2 instance */
        {
            if(memory == DMA_MEMORY0)
            {
            /* change the memory0 address */
            ((DMA_Stream_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.stream_)->M0AR = address;
            }
            else
            {
            /* change the memory1 address */
            ((DMA_Stream_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.stream_)->M1AR = address;
            }
        }
        else /* BDMA instance(s) */
        {
            if(memory == DMA_MEMORY0)
            {
            /* change the memory0 address */
            ((BDMA_Channel_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.channel_)->CM0AR = address;
            }
            else
            {
            /* change the memory1 address */
            ((BDMA_Channel_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.channel_)->CM1AR = address;
            }
        }
        return E_RESULT_OK;
    }
    void enableIsr(uint32_t PreemptPriority, uint32_t SubPriority)
    {
        if(NVIC_GetEnableIRQ(getIrqType()) == 0U)
        {
            NVIC_SetPriority(getIrqType(), NVIC_EncodePriority(NVIC_GetPriorityGrouping(), PreemptPriority, SubPriority));
            NVIC_EnableIRQ(getIrqType());
        }
    }
    void disableIsr()
    {
        NVIC_DisableIRQ(getIrqType());
    }
    void enableIsrInReg()
    {
        if(IS_DMA_STREAM_INSTANCE(pdmacfg_->dmaStreamOrChannel_.stream_) != 0U) /* DMA1 or DMA2 instance */
        {
            /* Enable Common interrupts*/
            MODIFY_REG(((DMA_Stream_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.stream_)->CR, (DMA_IT_TC | DMA_IT_TE | DMA_IT_DME | DMA_IT_HT), (DMA_IT_TC | DMA_IT_TE | DMA_IT_DME | DMA_IT_HT));
        }
        else /* BDMA channel */
        {
            /* Enable Common interrupts */
            MODIFY_REG(((BDMA_Channel_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.channel_)->CCR, (BDMA_CCR_TCIE | BDMA_CCR_HTIE | BDMA_CCR_TEIE), (BDMA_CCR_TCIE | BDMA_CCR_HTIE | BDMA_CCR_TEIE));
        }
        if(IS_DMA_STREAM_DMAMUX_INSTANCE(pdmacfg_->dmaStreamOrChannel_.stream_) || IS_BDMA_CHANNEL_DMAMUX_INSTANCE(pdmacfg_->dmaStreamOrChannel_.channel_)) /* No DMAMUX available for BDMA1 */
        {
            /* Check if DMAMUX Synchronization is enabled */
            if((muxChannel_->CCR & DMAMUX_CxCR_SE) != 0U)
            {
                /* Enable DMAMUX sync overrun IT*/
                muxChannel_->CCR |= DMAMUX_CxCR_SOIE;
            }

            if(muxRequestGen_ != 0U)
            {
                /* if using DMAMUX request generator, enable the DMAMUX request generator overrun IT*/
                /* enable the request gen overrun IT */
                muxRequestGen_->RGCR |= DMAMUX_RGxCR_OIE;
            }
        }
    }
    void disableIsrInReg()
    {
        if(IS_DMA_STREAM_INSTANCE(pdmacfg_->dmaStreamOrChannel_.stream_) != 0U) /* DMA1 or DMA2 instance */
        {
            /* Disable Common interrupts*/
            CLEAR_BIT(((DMA_Stream_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.stream_)->CR, (DMA_IT_TC | DMA_IT_TE | DMA_IT_DME | DMA_IT_HT));
        }
        else /* BDMA channel */
        {
            /* Disable Common interrupts */
            CLEAR_BIT(((BDMA_Channel_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.channel_)->CCR, (BDMA_CCR_TCIE | BDMA_CCR_HTIE | BDMA_CCR_TEIE));
        }
        if(IS_DMA_STREAM_DMAMUX_INSTANCE(pdmacfg_->dmaStreamOrChannel_.stream_) || IS_BDMA_CHANNEL_DMAMUX_INSTANCE(pdmacfg_->dmaStreamOrChannel_.channel_)) /* No DMAMUX available for BDMA1 */
        {
            /* Check if DMAMUX Synchronization is enabled */
            if((muxChannel_->CCR & DMAMUX_CxCR_SOIE) != 0U)
            {
                /* Disable DMAMUX sync overrun IT*/
                muxChannel_->CCR &= ~DMAMUX_CxCR_SOIE;
            }
            if(muxRequestGen_ != 0U)
            {
                /* if using DMAMUX request generator, Disable the DMAMUX request generator overrun IT*/
                /* Disable the request gen overrun IT */
                muxRequestGen_->RGCR &= ~DMAMUX_RGxCR_OIE;
            }
        }
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
        if(IS_DMA_STREAM_INSTANCE(pdmacfg_->dmaStreamOrChannel_.stream_))
        {
            if(NVIC_GetEnableIRQ(DMAMUX1_OVR_IRQn) == 0U)
            {
                NVIC_SetPriority(DMAMUX1_OVR_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), PreemptPriority, SubPriority));
                NVIC_EnableIRQ(DMAMUX1_OVR_IRQn);
            }
        }
        else if (IS_BDMA_CHANNEL_INSTANCE(pdmacfg_->dmaStreamOrChannel_.channel_))
        {
            if(NVIC_GetEnableIRQ(DMAMUX2_OVR_IRQn) == 0U)
            {
                NVIC_SetPriority(DMAMUX2_OVR_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), PreemptPriority, SubPriority));
                NVIC_EnableIRQ(DMAMUX2_OVR_IRQn);
            }
        }
    }
    void disableDMAMUXIsr()
    {
        if(IS_DMA_STREAM_INSTANCE(pdmacfg_->dmaStreamOrChannel_.stream_))
        {
            NVIC_DisableIRQ(DMAMUX1_OVR_IRQn);
        }
        else if (IS_BDMA_CHANNEL_INSTANCE(pdmacfg_->dmaStreamOrChannel_.channel_))
        {
            NVIC_DisableIRQ(DMAMUX2_OVR_IRQn);
        }
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
    IRQn_Type getIrqType()
    {
        IRQn_Type irqtype = DMA1_Stream0_IRQn;
        if(IS_DMA_STREAM_INSTANCE(pdmacfg_->dmaStreamOrChannel_.stream_))
        {
            switch (reinterpret_cast<uint32_t>(pdmacfg_->dmaStreamOrChannel_.stream_))
            {
                case DMA1_Stream0_BASE:
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
        }
        else if(IS_BDMA_CHANNEL_INSTANCE(pdmacfg_->dmaStreamOrChannel_.channel_))
        {
            switch (reinterpret_cast<uint32_t> (pdmacfg_->dmaStreamOrChannel_.channel_))
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
        }
        return irqtype;
    }
    void dmaIRQHandler()
    {
        uint32_t tmpisr_dma, tmpisr_bdma;
        uint32_t ccr_reg;
        __IO uint32_t count = 0U;
        uint32_t timeout = SystemCoreClock / 9600U;

        /* calculate DMA base and stream number */
        DMABaseRegisters  *regs_dma  = (DMABaseRegisters *)streamBaseAddress_;
        BDMABaseRegisters *regs_bdma = (BDMABaseRegisters *)streamBaseAddress_;

        tmpisr_dma  = regs_dma->ISR;
        tmpisr_bdma = regs_bdma->ISR;

        if(IS_DMA_STREAM_INSTANCE(pdmacfg_->dmaStreamOrChannel_.stream_) != 0U)  /* DMA1 or DMA2 instance */
        {
            /* Transfer Error Interrupt management ***************************************/
            if ((tmpisr_dma & (DMA_FLAG_TEIF0_4 << (streamIndex_ & 0x1FU))) != 0U)
            {
                if(getITSource(DMA_IT_TE) != 0U)
                {
                    /* Disable the transfer error interrupt */
                    ((DMA_Stream_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.stream_)->CR  &= ~(DMA_IT_TE);

                    /* Clear the transfer error flag */
                    regs_dma->IFCR = DMA_FLAG_TEIF0_4 << (streamIndex_ & 0x1FU);

                    /* Update error code */
                    errorCode_ |= DMA_ERROR_TE;
                }
            }
            /* FIFO Error Interrupt management ******************************************/
            if ((tmpisr_dma & (DMA_FLAG_FEIF0_4 << (streamIndex_ & 0x1FU))) != 0U)
            {
                if(getITSource(DMA_IT_FE) != 0U)
                {
                    /* Clear the FIFO error flag */
                    regs_dma->IFCR = DMA_FLAG_FEIF0_4 << (streamIndex_ & 0x1FU);

                    /* Update error code */
                    errorCode_ |= DMA_ERROR_FE;
                }
            }
            /* Direct Mode Error Interrupt management ***********************************/
            if ((tmpisr_dma & (DMA_FLAG_DMEIF0_4 << (streamIndex_ & 0x1FU))) != 0U)
            {
                if(getITSource(DMA_IT_DME) != 0U)
                {
                    /* Clear the direct mode error flag */
                    regs_dma->IFCR = DMA_FLAG_DMEIF0_4 << (streamIndex_ & 0x1FU);

                    /* Update error code */
                    errorCode_ |= DMA_ERROR_DME;
                }
            }
            /* Half Transfer Complete Interrupt management ******************************/
            if ((tmpisr_dma & (DMA_FLAG_HTIF0_4 << (streamIndex_ & 0x1FU))) != 0U)
            {
                if(getITSource(DMA_IT_HT) != 0U)
                {
                    /* Clear the half transfer complete flag */
                    regs_dma->IFCR = DMA_FLAG_HTIF0_4 << (streamIndex_ & 0x1FU);

                    /* Multi_Buffering mode enabled */
                    if(((((DMA_Stream_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.stream_)->CR) & (uint32_t)(DMA_SxCR_DBM)) != 0U)
                    {
                        /* Current memory buffer used is Memory 0 */
                        if((((DMA_Stream_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.stream_)->CR & DMA_SxCR_CT) == 0U)
                        {
                            if(dmacb_)
                            {
                                /* Half transfer callback */
                                dmacb_(this, DMA_TRANSFER_HALF);
                            }
                        }
                        /* Current memory buffer used is Memory 1 */
                        else
                        {
                            if(dmacb_)
                            {
                                /* Half transfer callback */
                                dmacb_(this, DMA_TRANSFER_HALF_MEMORY1);
                            }
                        }
                    }
                    else
                    {
                        /* Disable the half transfer interrupt if the DMA mode is not CIRCULAR */
                        if((((DMA_Stream_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.stream_)->CR & DMA_SxCR_CIRC) == 0U)
                        {
                            /* Disable the half transfer interrupt */
                            ((DMA_Stream_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.stream_)->CR  &= ~(DMA_IT_HT);
                        }
                        if(dmacb_)
                        {
                            /* Half transfer callback */
                            dmacb_(this, DMA_TRANSFER_HALF);
                        }
                    }
                }
            }
            /* Transfer Complete Interrupt management ***********************************/
            if ((tmpisr_dma & (DMA_FLAG_TCIF0_4 << (streamIndex_ & 0x1FU))) != 0U)
            {
                if(getITSource(DMA_IT_TC) != 0U)
                {
                    /* Clear the transfer complete flag */
                    regs_dma->IFCR = DMA_FLAG_TCIF0_4 << (streamIndex_ & 0x1FU);

                    if(DMA_STATE_ABORT == state_)
                    {
                        /* Disable all the transfer interrupts */
                        ((DMA_Stream_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.stream_)->CR  &= ~(DMA_IT_TC | DMA_IT_TE | DMA_IT_DME);
                        ((DMA_Stream_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.stream_)->FCR &= ~(DMA_IT_FE);
                        ((DMA_Stream_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.stream_)->CR  &= ~(DMA_IT_HT);

                        /* Clear all interrupt flags at correct offset within the register */
                        regs_dma->IFCR = 0x3FUL << (streamIndex_ & 0x1FU);

                        /* Change the DMA state */
                        state_ = DMA_STATE_READY;

                        if(dmacb_)
                        {
                            /* Half transfer callback */
                            dmacb_(this, DMA_TRANSFER_ABORT);
                        }
                        return;
                    }

                    if(((((DMA_Stream_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.stream_)->CR) & (uint32_t)(DMA_SxCR_DBM)) != 0U)
                    {
                        /* Current memory buffer used is Memory 0 */
                        if((((DMA_Stream_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.stream_)->CR & DMA_SxCR_CT) == 0U)
                        {
                            if(dmacb_)
                            {
                                /* Transfer complete Callback for memory1 */
                                dmacb_(this, DMA_TRANSFER_COMPLETE_MEMORY1);
                            }
                        }
                        /* Current memory buffer used is Memory 1 */
                        else
                        {
                            if(dmacb_)
                            {
                                /* Transfer complete Callback for memory0 */
                                dmacb_(this, DMA_TRANSFER_COMPLETE);
                            }
                        }
                    }
                    /* Disable the transfer complete interrupt if the DMA mode is not CIRCULAR */
                    else
                    {
                        if((((DMA_Stream_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.stream_)->CR & DMA_SxCR_CIRC) == 0U)
                        {
                            /* Disable the transfer complete interrupt */
                            ((DMA_Stream_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.stream_)->CR  &= ~(DMA_IT_TC);

                            /* Change the DMA state */
                            state_ = DMA_STATE_READY;
                        }
                        if(dmacb_)
                        {
                            /* Transfer complete Callback for memory0 */
                            dmacb_(this, DMA_TRANSFER_COMPLETE);
                        }
                    }
                }
            }
            /* manage error case */
            if(errorCode_ != DMA_ERROR_NONE)
            {
                if((errorCode_ & DMA_ERROR_TE) != 0U)
                {
                    state_ = DMA_STATE_ABORT;

                    /* Disable the stream */
                    dmaEnable(false);

                    do
                    {
                        if (++count > timeout)
                        {
                            break;
                        }
                    }
                    while((((DMA_Stream_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.stream_)->CR & DMA_SxCR_EN) != 0U);

                    if((((DMA_Stream_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.stream_)->CR & DMA_SxCR_EN) != 0U)
                    {
                        /* Change the DMA state to error if DMA disable fails */
                        state_ = DMA_STATE_ERROR;
                    }
                    else
                    {
                        /* Change the DMA state to Ready if DMA disable success */
                        state_ = DMA_STATE_READY;
                    }
                }

                if(dmacb_)
                {
                    /* Transfer error */
                    dmacb_(this, DMA_TRANSFER_ERROR);
                }
            }
        }
        else if(IS_BDMA_CHANNEL_INSTANCE(pdmacfg_->dmaStreamOrChannel_.channel_) != 0U)  /* BDMA instance(s) */
        {
            ccr_reg = (((BDMA_Channel_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.channel_)->CCR);

            /* Half Transfer Complete Interrupt management ******************************/
            if (((tmpisr_bdma & (BDMA_FLAG_HT0 << (streamIndex_ & 0x1FU))) != 0U) && ((ccr_reg & BDMA_CCR_HTIE) != 0U))
            {
                /* Clear the half transfer complete flag */
                regs_bdma->IFCR = (BDMA_ISR_HTIF0 << (streamIndex_ & 0x1FU));

                /* Disable the transfer complete interrupt if the DMA mode is Double Buffering */
                if((ccr_reg & BDMA_CCR_DBM) != 0U)
                {
                    /* Current memory buffer used is Memory 0 */
                    if((ccr_reg & BDMA_CCR_CT) == 0U)
                    {
                        if(dmacb_)
                        {
                            /* Half transfer Callback for Memory 1 */
                            dmacb_(this, DMA_TRANSFER_HALF_MEMORY1);
                        }
                    }
                    /* Current memory buffer used is Memory 1 */
                    else
                    {
                        if(dmacb_)
                        {
                            /* Half transfer Callback for Memory 0 */
                            dmacb_(this, DMA_TRANSFER_HALF);
                        }
                    }
                }
                else
                {
                    if((ccr_reg & BDMA_CCR_CIRC) == 0U)
                    {
                        /* Disable the half transfer interrupt */
                        ((BDMA_Channel_TypeDef *)pdmacfg_->dmaStreamOrChannel_.channel_)->CCR &= ~DMAToBDMAISR(DMA_IT_HT);
                    }

                    /* DMA peripheral state is not updated in Half Transfer */
                    /* but in Transfer Complete case */
                    if(dmacb_)
                    {
                        /* Half transfer Callback for Memory 0 */
                        dmacb_(this, DMA_TRANSFER_HALF);
                    }
                }
            }

            /* Transfer Complete Interrupt management ***********************************/
            else if (((tmpisr_bdma & (BDMA_FLAG_TC0 << (streamIndex_ & 0x1FU))) != 0U) && ((ccr_reg & BDMA_CCR_TCIE) != 0U))
            {
                /* Clear the transfer complete flag */
                regs_bdma->IFCR = (BDMA_ISR_TCIF0) << (streamIndex_ & 0x1FU);

                /* Disable the transfer complete interrupt if the DMA mode is Double Buffering */
                if((ccr_reg & BDMA_CCR_DBM) != 0U)
                {
                    /* Current memory buffer used is Memory 0 */
                    if((ccr_reg & BDMA_CCR_CT) == 0U)
                    {
                        if(dmacb_)
                        {
                            /* Transfer complete Callback for Memory 1 */
                            dmacb_(this, DMA_TRANSFER_COMPLETE_MEMORY1);
                        }
                    }
                    /* Current memory buffer used is Memory 1 */
                    else
                    {
                        if(dmacb_)
                        {
                            /* Transfer complete Callback for Memory 0 */
                            dmacb_(this, DMA_TRANSFER_COMPLETE);
                        }
                    }
                }
                else
                {
                    if((ccr_reg & BDMA_CCR_CIRC) == 0U)
                    {
                        /* Disable the transfer complete and error interrupt, if the DMA mode is not CIRCULAR */
                        ((BDMA_Channel_TypeDef *)pdmacfg_->dmaStreamOrChannel_.channel_)->CCR &= ~DMAToBDMAISR(DMA_IT_TE | DMA_IT_TC);

                        /* Change the DMA state */
                        state_ = DMA_STATE_READY;
                    }

                    if(dmacb_)
                    {
                        /* Transfer complete Callback for Memory 0 */
                        dmacb_(this, DMA_TRANSFER_COMPLETE);
                    }
                }
            }
            /* Transfer Error Interrupt management **************************************/
            else if (((tmpisr_bdma & (BDMA_FLAG_TE0 << (streamIndex_ & 0x1FU))) != 0U) && ((ccr_reg & BDMA_CCR_TEIE) != 0U))
            {
                /* When a DMA transfer error occurs */
                /* A hardware clear of its EN bits is performed */
                /* Disable ALL DMA IT */
                ((BDMA_Channel_TypeDef *)pdmacfg_->dmaStreamOrChannel_.channel_)->CCR &= ~DMAToBDMAISR(DMA_IT_TC | DMA_IT_HT | DMA_IT_TE);

                /* Clear all flags */
                regs_bdma->IFCR = (BDMA_ISR_GIF0) << (streamIndex_ & 0x1FU);

                /* Update error code */
                errorCode_ = DMA_ERROR_TE;

                /* Change the DMA state */
                state_ = DMA_STATE_READY;

                if(dmacb_)
                {
                    /* Transfer error */
                    dmacb_(this, DMA_TRANSFER_ERROR);
                }
            }
            else
            {
            /* Nothing To Do */
            }
        }
        else
        {
            /* Nothing To Do */
        }
    }
    void muxIsrHandler()
    {
        /* Check for DMAMUX Synchronization overrun */
        if((muxChannelStatus_->CSR & muxChannelStatusMask_) != 0U)
        {
            /* Disable the synchro overrun interrupt */
            muxChannel_->CCR &= ~DMAMUX_CxCR_SOIE;

            /* Clear the DMAMUX synchro overrun flag */
            muxChannelStatus_->CFR =muxChannelStatusMask_;

            /* Update error code */
            errorCode_ |= DMA_ERROR_SYNC;
            if(dmamuxcb_)
            {
                dmamuxcb_(this, DMAMUX_OVERRUN_TYPE_SYNC);
            }
        }
        if(muxRequestGen_ != nullptr)
        {
            /* if using a DMAMUX request generator block Check for DMAMUX request generator overrun */
            if((muxRequestGenStatus_->RGSR & muxRequestGenStatusMask_) != 0U)
            {
                /* Disable the request gen overrun interrupt */
                muxRequestGen_->RGCR &= ~DMAMUX_RGxCR_OIE;

                /* Clear the DMAMUX request generator overrun flag */
                muxRequestGenStatus_->RGCFR = muxRequestGenStatusMask_;

                /* Update error code */
                errorCode_ |= DMA_ERROR_REQGEN;

                if(dmamuxcb_)
                {
                    /* Transfer error callback */
                    dmamuxcb_(this, DMAMUX_OVERRUN_TYPE_GEN);
                }
            }
        }
    }
    void dmaEnable(bool bEnable)
    {
        if(bEnable)
        {
            IS_DMA_STREAM_INSTANCE(pdmacfg_->dmaStreamOrChannel_.stream_) ? \
            (((DMA_Stream_TypeDef *)pdmacfg_->dmaStreamOrChannel_.stream_)->CR |=  DMA_SxCR_EN) : (((BDMA_Channel_TypeDef *)pdmacfg_->dmaStreamOrChannel_.channel_)->CCR |=  BDMA_CCR_EN);
        }
        else
        {
            IS_DMA_STREAM_INSTANCE(pdmacfg_->dmaStreamOrChannel_.stream_) ? \
            (((DMA_Stream_TypeDef *)pdmacfg_->dmaStreamOrChannel_.stream_)->CR &=  ~DMA_SxCR_EN) : (((BDMA_Channel_TypeDef *)pdmacfg_->dmaStreamOrChannel_.channel_)->CCR &=  ~BDMA_CCR_EN);
        }
    }
    void multiBufferSetConfig(uint32_t srcAddress, uint32_t dstAddress, uint32_t dataLength)
    {
        if(IS_DMA_STREAM_INSTANCE(pdmacfg_->dmaStreamOrChannel_.stream_) != 0U) /* DMA1 or DMA2 instance */
        {
            /* Configure DMA Stream data length */
            ((DMA_Stream_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.stream_)->NDTR = dataLength;

            if((pdmacfg_->direction_.dma_) == DMA_MEMORY_TO_PERIPH)
            {
                /* Configure DMA Stream destination address */
                ((DMA_Stream_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.stream_)->PAR = dstAddress;

                /* Configure DMA Stream source address */
                ((DMA_Stream_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.stream_)->M0AR = srcAddress;
            }
            else
            {
                /* Configure DMA Stream source address */
                ((DMA_Stream_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.stream_)->PAR = srcAddress;

                /* Configure DMA Stream destination address */
                ((DMA_Stream_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.stream_)->M0AR = dstAddress;
            }
        }
        else /* BDMA instance(s) */
        {
            /* Configure DMA Stream data length */
            ((BDMA_Channel_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.channel_)->CNDTR = dataLength;

            if((pdmacfg_->direction_.bdma_) == BDMA_MEMORY_TO_PERIPH)
            {
                /* Configure DMA Stream destination address */
                ((BDMA_Channel_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.channel_)->CPAR = dstAddress;

                /* Configure DMA Stream source address */
                ((BDMA_Channel_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.channel_)->CM0AR = srcAddress;
            }
            else
            {
                /* Configure DMA Stream source address */
                ((BDMA_Channel_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.channel_)->CPAR = srcAddress;

                /* Configure DMA Stream destination address */
                ((BDMA_Channel_TypeDef   *)pdmacfg_->dmaStreamOrChannel_.channel_)->CM0AR = dstAddress;
            }
        }
    }
    eResult checkFifoParam()
    {
        eResult result = E_RESULT_OK;

        /* Memory Data size equal to Byte */
        if (pdmacfg_->memDataAlignment_ == DMA_MDATAALIGN_BYTE)
        {
            switch (pdmacfg_->fifoThreshold_)
            {
                case DMA_FIFO_THRESHOLD_1QUARTERFULL:
                case DMA_FIFO_THRESHOLD_3QUARTERSFULL:
                    if ((pdmacfg_->memBurst_ & DMA_SxCR_MBURST_1) == DMA_SxCR_MBURST_1)
                    {
                        result = E_RESULT_ERROR;
                    }
                    break;
                case DMA_FIFO_THRESHOLD_HALFFULL:
                    if (pdmacfg_->memBurst_ == DMA_MBURST_INC16)
                    {
                        result = E_RESULT_ERROR;
                    }
                    break;
                case DMA_FIFO_THRESHOLD_FULL:
                    break;
                default:
                    break;
            }
        }
        /* Memory Data size equal to Half-Word */
        else if (pdmacfg_->memDataAlignment_ == DMA_MDATAALIGN_HALFWORD)
        {
            switch (pdmacfg_->fifoThreshold_)
            {
                case DMA_FIFO_THRESHOLD_1QUARTERFULL:
                case DMA_FIFO_THRESHOLD_3QUARTERSFULL:
                        result = E_RESULT_ERROR;
                    break;

                case DMA_FIFO_THRESHOLD_HALFFULL:
                    if ((pdmacfg_->memBurst_ & DMA_SxCR_MBURST_1) == DMA_SxCR_MBURST_1)
                    {
                        result = E_RESULT_ERROR;
                    }
                    break;

                case DMA_FIFO_THRESHOLD_FULL:
                    if (pdmacfg_->memBurst_ == DMA_MBURST_INC16)
                    {
                        result = E_RESULT_ERROR;
                    }
                    break;

                default:
                    break;
            }
        }
        /* Memory Data size equal to Word */
        else
        {
            switch (pdmacfg_->fifoThreshold_)
            {
                case DMA_FIFO_THRESHOLD_1QUARTERFULL:
                case DMA_FIFO_THRESHOLD_HALFFULL:
                case DMA_FIFO_THRESHOLD_3QUARTERSFULL:
                    result = E_RESULT_ERROR;
                    break;

                case DMA_FIFO_THRESHOLD_FULL:
                    if ((pdmacfg_->memBurst_ & DMA_SxCR_MBURST_1) == DMA_SxCR_MBURST_1)
                    {
                        result = E_RESULT_ERROR;
                    }
                break;

                default:
                    break;
            }
        }
        return result;
    }
    uint32_t calcBaseAndBitshift()
    {
        if(IS_DMA_STREAM_INSTANCE(pdmacfg_->dmaStreamOrChannel_.stream_) != 0U) /* DMA1 or DMA2 instance */
        {
            uint32_t streamNumber = (((uint32_t)((uint32_t*)pdmacfg_->dmaStreamOrChannel_.stream_) & 0xFFU) - 16U) / 24U;

            /* lookup table for necessary bitshift of flags within status registers */
            static const uint8_t flagBitshiftOffset[8U] = {0U, 6U, 16U, 22U, 0U, 6U, 16U, 22U};
            streamIndex_ = flagBitshiftOffset[streamNumber & 0x7U];

            if (streamNumber > 3U)
            {
                /* return pointer to HISR and HIFCR */
                streamBaseAddress_ = (((uint32_t)((uint32_t*)pdmacfg_->dmaStreamOrChannel_.stream_) & (uint32_t)(~0x3FFU)) + 4U);
            }
            else
            {
                /* return pointer to LISR and LIFCR */
                streamBaseAddress_ = ((uint32_t)((uint32_t*)pdmacfg_->dmaStreamOrChannel_.stream_) & (uint32_t)(~0x3FFU));
            }
        }
        else /* BDMA instance(s) */
        {
            /* return pointer to ISR and IFCR */
            streamBaseAddress_ = ((uint32_t)((uint32_t*)pdmacfg_->dmaStreamOrChannel_.channel_) & (uint32_t)(~0xFFU));
        }

        return streamBaseAddress_;
    }
    void calcDMAMUXChannelBaseAndMask()
    {
        uint32_t streamNumber = 0;
        uint32_t streamBaseaddress = 0;//(uint32_t)((uint32_t*)hdma->Instance);

        if(IS_BDMA_CHANNEL_DMAMUX_INSTANCE(pdmacfg_->dmaStreamOrChannel_.channel_) != 0U)
        {
            /* BDMA Channels are connected to DMAMUX2 channels */
            streamNumber = (((uint32_t)((uint32_t*)pdmacfg_->dmaStreamOrChannel_.channel_) & 0xFFU) - 8U) / 20U;
            muxChannel_ = (DMAMUX_Channel_TypeDef *)((uint32_t)(((uint32_t)DMAMUX2_Channel0) + (streamNumber * 4U)));
            muxChannelStatus_ = DMAMUX2_ChannelStatus;
            muxChannelStatusMask_ = 1UL << (streamNumber & 0x1FU);
        }
        else
        {
            /* DMA1/DMA2 Streams are connected to DMAMUX1 channels */
            streamNumber = (((uint32_t)((uint32_t*)pdmacfg_->dmaStreamOrChannel_.stream_) & 0xFFU) - 16U) / 24U;
            streamBaseaddress = (uint32_t)((uint32_t*)pdmacfg_->dmaStreamOrChannel_.stream_);
            if((streamBaseaddress <= ((uint32_t)DMA2_Stream7) ) && \
            (streamBaseaddress >= ((uint32_t)DMA2_Stream0)))
            {
                streamNumber += 8U;
            }
            muxChannel_ = (DMAMUX_Channel_TypeDef *)((uint32_t)(((uint32_t)DMAMUX1_Channel0) + (streamNumber * 4U)));
            muxChannelStatus_ = DMAMUX1_ChannelStatus;
            muxChannelStatusMask_ = 1UL << (streamNumber & 0x1FU);
        }
    }
    void calcDMAMUXRequestGenBaseAndMask()
    {
        if(IS_BDMA_CHANNEL_DMAMUX_INSTANCE(pdmacfg_->dmaStreamOrChannel_.channel_) != 0U)
        {
            uint32_t request =  pdmacfg_->request_.bdma_ & DMAMUX_CxCR_DMAREQ_ID;
            if((request >= BDMA_REQUEST_GENERATOR0) && (request <= BDMA_REQUEST_GENERATOR7))
            {
                /* BDMA Channels are connected to DMAMUX2 request generator blocks */
                muxRequestGen_ = (DMAMUX_RequestGen_TypeDef *)((uint32_t)(((uint32_t)DMAMUX2_RequestGenerator0) + ((request - 1U) * 4U)));

                muxRequestGenStatus_ = DMAMUX2_RequestGenStatus;
                muxRequestGenStatusMask_ = 1UL << (request - 1U);
            }
        }
        else
        {
            uint32_t request =  pdmacfg_->request_.dma_ & DMAMUX_CxCR_DMAREQ_ID;
            if((request >= DMA_REQUEST_GENERATOR0) && (request <= DMA_REQUEST_GENERATOR7))
            {
                /* DMA1 and DMA2 Streams use DMAMUX1 request generator blocks */
                muxRequestGen_ = (DMAMUX_RequestGen_TypeDef *)((uint32_t)(((uint32_t)DMAMUX1_RequestGenerator0) + ((request - 1U) * 4U)));

                muxRequestGenStatus_ = DMAMUX1_RequestGenStatus;
                muxRequestGenStatusMask_ = 1UL << (request - 1U);
            }
        }
    }
    void dmaSetConfig(uint32_t srcAddress, uint32_t dstAddress, uint32_t dataLength)
    {
        /* calculate DMA base and stream number */
        DMABaseRegisters  *regs_dma  = (DMABaseRegisters *)streamBaseAddress_;
        BDMABaseRegisters *regs_bdma = (BDMABaseRegisters *)streamBaseAddress_;

        if(IS_DMA_STREAM_INSTANCE(pdmacfg_->dmaStreamOrChannel_.stream_) || IS_BDMA_CHANNEL_INSTANCE(pdmacfg_->dmaStreamOrChannel_.channel_)) /* No DMAMUX available for BDMA1 */
        {
            /* Clear the DMAMUX synchro overrun flag */
            muxChannelStatus_->CFR = muxChannelStatusMask_;

            if(muxRequestGen_ != nullptr)
            {
                /* Clear the DMAMUX request generator overrun flag */
                muxRequestGenStatus_->RGCFR = muxRequestGenStatusMask_;
            }
        }

        if(IS_DMA_STREAM_INSTANCE(pdmacfg_->dmaStreamOrChannel_.stream_) != 0U) /* DMA1 or DMA2 instance */
        {
            /* Clear all interrupt flags at correct offset within the register */
            regs_dma->IFCR = 0x3FUL << (streamIndex_ & 0x1FU);

            /* Clear DBM bit */
            ((DMA_Stream_TypeDef *)pdmacfg_->dmaStreamOrChannel_.stream_)->CR &= (uint32_t)(~DMA_SxCR_DBM);

            /* Configure DMA Stream data length */
            ((DMA_Stream_TypeDef *)pdmacfg_->dmaStreamOrChannel_.stream_)->NDTR = dataLength;

            /* Peripheral to Memory */
            if((pdmacfg_->direction_.dma_) == DMA_MEMORY_TO_PERIPH)
            {
                /* Configure DMA Stream destination address */
                ((DMA_Stream_TypeDef *)pdmacfg_->dmaStreamOrChannel_.stream_)->PAR = dstAddress;

                /* Configure DMA Stream source address */
                ((DMA_Stream_TypeDef *)pdmacfg_->dmaStreamOrChannel_.stream_)->M0AR = srcAddress;
            }
            /* Memory to Peripheral */
            else
            {
                /* Configure DMA Stream source address */
                ((DMA_Stream_TypeDef *)pdmacfg_->dmaStreamOrChannel_.stream_)->PAR = srcAddress;

                /* Configure DMA Stream destination address */
                ((DMA_Stream_TypeDef *)pdmacfg_->dmaStreamOrChannel_.stream_)->M0AR = dstAddress;
            }
        }
        else if(IS_BDMA_CHANNEL_INSTANCE(pdmacfg_->dmaStreamOrChannel_.channel_) != 0U) /* BDMA instance(s) */
        {
            /* Clear all flags */
            regs_bdma->IFCR = (BDMA_ISR_GIF0) << (streamIndex_ & 0x1FU);

            /* Configure DMA Channel data length */
            ((BDMA_Channel_TypeDef *)pdmacfg_->dmaStreamOrChannel_.channel_)->CNDTR = dataLength;

            /* Peripheral to Memory */
            if((pdmacfg_->direction_.bdma_) == BDMA_MEMORY_TO_PERIPH)
            {
            /* Configure DMA Channel destination address */
            ((BDMA_Channel_TypeDef *)pdmacfg_->dmaStreamOrChannel_.channel_)->CPAR = dstAddress;

            /* Configure DMA Channel source address */
            ((BDMA_Channel_TypeDef *)pdmacfg_->dmaStreamOrChannel_.channel_)->CM0AR = srcAddress;
            }
            /* Memory to Peripheral */
            else
            {
            /* Configure DMA Channel source address */
            ((BDMA_Channel_TypeDef *)pdmacfg_->dmaStreamOrChannel_.channel_)->CPAR = srcAddress;

            /* Configure DMA Channel destination address */
            ((BDMA_Channel_TypeDef *)pdmacfg_->dmaStreamOrChannel_.channel_)->CM0AR = dstAddress;
            }
        }
        else
        {
            /* Nothing To Do */
        }
    }
    inline uint32_t DMAToBDMAISR(uint32_t isrType)
    {
        if(((isrType) & (DMA_IT_TC | DMA_IT_HT | DMA_IT_TE)) == (DMA_IT_TC | DMA_IT_HT | DMA_IT_TE))
        {
            return (BDMA_CCR_TCIE | BDMA_CCR_HTIE |BDMA_CCR_TEIE);
        }
        else if(((isrType) & (DMA_IT_TC | DMA_IT_HT)) == (DMA_IT_TC | DMA_IT_HT))
        {
            return (BDMA_CCR_TCIE | BDMA_CCR_HTIE);
        }
        else if(((isrType) & (DMA_IT_HT | DMA_IT_TE)) == (DMA_IT_HT | DMA_IT_TE))
        {
            return (BDMA_CCR_HTIE |BDMA_CCR_TEIE);
        }
        else if(((isrType) & (DMA_IT_TC | DMA_IT_TE)) == (DMA_IT_TC | DMA_IT_TE))
        {
            return (BDMA_CCR_TCIE |BDMA_CCR_TEIE);
        }
        else if((isrType) == DMA_IT_TC)
        {
            return BDMA_CCR_TCIE;
        }
        else if((isrType) == DMA_IT_HT)
        {
            return BDMA_CCR_HTIE;
        }
        else if((isrType) == DMA_IT_TE)
        {
            return BDMA_CCR_TEIE;
        }
        else
        {
            return (uint32_t)0x00000000;
        }
    }
    inline uint32_t getITSource(uint32_t type)
    {
        if(IS_DMA_STREAM_INSTANCE(pdmacfg_->dmaStreamOrChannel_.stream_))
        {
            if(type != DMA_IT_FE)
            {
                return ((DMA_Stream_TypeDef *)pdmacfg_->dmaStreamOrChannel_.stream_)->CR & type;
            }
            else
            {
                return ((DMA_Stream_TypeDef *)pdmacfg_->dmaStreamOrChannel_.stream_)->FCR & type; 
            }
        }
        else if(IS_BDMA_CHANNEL_INSTANCE(pdmacfg_->dmaStreamOrChannel_.channel_))
        {
            return ((BDMA_Channel_TypeDef *)pdmacfg_->dmaStreamOrChannel_.channel_)->CCR & (DMAToBDMAISR(type));
        }
        return 0;
    }
    DMAState getDMAState() const
    {
        return state_;
    }
    uint32_t getError() const
    {
        return errorCode_;
    }
private:
    __IO DMAState       state_;  
    uint32_t            errorCode_;     
    uint32_t                         streamBaseAddress_;         
    uint32_t                         streamIndex_;               
    DMAMUX_Channel_TypeDef           *muxChannel_;            
    DMAMUX_ChannelStatus_TypeDef     *muxChannelStatus_;      
    uint32_t                         muxChannelStatusMask_;   
    DMAMUX_RequestGen_TypeDef        *muxRequestGen_;         
    DMAMUX_RequestGenStatus_TypeDef  *muxRequestGenStatus_;   
    uint32_t                         muxRequestGenStatusMask_;

    DMA_TypeDef * dmax_;
    DMAConfig* pdmacfg_;

    DMAInterruptCb dmacb_;
    DMAMUXInterruptCb dmamuxcb_;
};