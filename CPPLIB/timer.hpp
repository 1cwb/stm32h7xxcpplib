#pragma once
#include "common.hpp"
#include <cmath>
/** @defgroup TIM_Trigger_Selection TIM Trigger Selection
  * @{
  */
#define TIM_TS_ITR0          0x00000000U                                                       /*!< Internal Trigger 0 (ITR0)              */
#define TIM_TS_ITR1          TIM_SMCR_TS_0                                                     /*!< Internal Trigger 1 (ITR1)              */
#define TIM_TS_ITR2          TIM_SMCR_TS_1                                                     /*!< Internal Trigger 2 (ITR2)              */
#define TIM_TS_ITR3          (TIM_SMCR_TS_0 | TIM_SMCR_TS_1)                                   /*!< Internal Trigger 3 (ITR3)              */
#define TIM_TS_ITR4          (TIM_SMCR_TS_3)                                                   /*!< Internal Trigger 4 (ITR4)              */
#define TIM_TS_ITR5          (TIM_SMCR_TS_0 | TIM_SMCR_TS_3)                                   /*!< Internal Trigger 5 (ITR5)              */
#define TIM_TS_ITR6          (TIM_SMCR_TS_1 | TIM_SMCR_TS_3)                                   /*!< Internal Trigger 6 (ITR6)              */
#define TIM_TS_ITR7          (TIM_SMCR_TS_0 | TIM_SMCR_TS_1 | TIM_SMCR_TS_3)                   /*!< Internal Trigger 7 (ITR7)              */
#define TIM_TS_ITR8          (TIM_SMCR_TS_2 | TIM_SMCR_TS_3)                                   /*!< Internal Trigger 8 (ITR8)              */
#define TIM_TS_ITR9          (TIM_SMCR_TS_0 | TIM_SMCR_TS_2 | TIM_SMCR_TS_3)                   /*!< Internal Trigger 9 (ITR9)              */
#define TIM_TS_ITR10         (TIM_SMCR_TS_1 | TIM_SMCR_TS_2 | TIM_SMCR_TS_3)                   /*!< Internal Trigger 10 (ITR10)            */
#define TIM_TS_ITR11         (TIM_SMCR_TS_0 | TIM_SMCR_TS_1 | TIM_SMCR_TS_2 | TIM_SMCR_TS_3)   /*!< Internal Trigger 11 (ITR11)            */
#define TIM_TS_ITR12         (TIM_SMCR_TS_4)                                                   /*!< Internal Trigger 12 (ITR12)            */
#define TIM_TS_ITR13         (TIM_SMCR_TS_0 | TIM_SMCR_TS_4)                                   /*!< Internal Trigger 13 (ITR13)            */
#define TIM_TS_TI1F_ED       TIM_SMCR_TS_2                                                     /*!< TI1 Edge Detector (TI1F_ED)            */
#define TIM_TS_TI1FP1        (TIM_SMCR_TS_0 | TIM_SMCR_TS_2)                                   /*!< Filtered Timer Input 1 (TI1FP1)        */
#define TIM_TS_TI2FP2        (TIM_SMCR_TS_1 | TIM_SMCR_TS_2)                                   /*!< Filtered Timer Input 2 (TI2FP2)        */
#define TIM_TS_ETRF          (TIM_SMCR_TS_0 | TIM_SMCR_TS_1 | TIM_SMCR_TS_2)                   /*!< Filtered External Trigger input (ETRF) */
#define TIM_TS_NONE          0x0000FFFFU                                                       /*!< No trigger selected                    */

/** @defgroup TIM_Input_Channel_Polarity TIM Input Channel polarity
  * @{
  */
#define  TIM_INPUTCHANNELPOLARITY_RISING      0x00000000U                       /*!< Polarity for TIx source */
#define  TIM_INPUTCHANNELPOLARITY_FALLING     TIM_CCER_CC1P                     /*!< Polarity for TIx source */
#define  TIM_INPUTCHANNELPOLARITY_BOTHEDGE    (TIM_CCER_CC1P | TIM_CCER_CC1NP)  /*!< Polarity for TIx source */

/** @defgroup TIM_Clock_Source TIM Clock Source
  * @{
  */
enum TIMCLKSrc
{
    TIM_CLOCKSOURCE_ETRMODE1  =  TIM_TS_ETRF,          /*!< External clock source mode 1 (ETRF)                   */
    TIM_CLOCKSOURCE_INTERNAL  =  TIM_SMCR_ETPS_0,      /*!< Internal clock source                                 */
    TIM_CLOCKSOURCE_ETRMODE2  =  TIM_SMCR_ETPS_1,      /*!< External clock source mode 2                          */
    TIM_CLOCKSOURCE_TI1ED     =  TIM_TS_TI1F_ED,       /*!< External clock source mode 1 (TTI1FP1 + edge detect.) */
    TIM_CLOCKSOURCE_TI1       =  TIM_TS_TI1FP1,        /*!< External clock source mode 1 (TTI1FP1)                */
    TIM_CLOCKSOURCE_TI2       =  TIM_TS_TI2FP2,        /*!< External clock source mode 1 (TTI2FP2)                */
    TIM_CLOCKSOURCE_ITR0      =  TIM_TS_ITR0,          /*!< External clock source mode 1 (ITR0)                   */
    TIM_CLOCKSOURCE_ITR1      =  TIM_TS_ITR1,          /*!< External clock source mode 1 (ITR1)                   */
    TIM_CLOCKSOURCE_ITR2      =  TIM_TS_ITR2,          /*!< External clock source mode 1 (ITR2)                   */
    TIM_CLOCKSOURCE_ITR3      =  TIM_TS_ITR3,          /*!< External clock source mode 1 (ITR3)                   */
    TIM_CLOCKSOURCE_ITR4      =  TIM_TS_ITR4,          /*!< External clock source mode 1 (ITR4)                   */
    TIM_CLOCKSOURCE_ITR5      =  TIM_TS_ITR5,          /*!< External clock source mode 1 (ITR5)                   */
    TIM_CLOCKSOURCE_ITR6      =  TIM_TS_ITR6,          /*!< External clock source mode 1 (ITR6)                   */
    TIM_CLOCKSOURCE_ITR7      =  TIM_TS_ITR7,          /*!< External clock source mode 1 (ITR7)                   */
    TIM_CLOCKSOURCE_ITR8      =  TIM_TS_ITR8           /*!< External clock source mode 1 (ITR8)                   */
};
/** @defgroup TIM_Clock_Prescaler TIM Clock Prescaler
  * @{
  */
enum TIMExtCLKPrecaler
{
    TIM_CLOCKPRESCALER_DIV1     =      0x00000000U,               /*!< No prescaler is used                                                     */
    TIM_CLOCKPRESCALER_DIV2     =      TIM_SMCR_ETPS_0,           /*!< Prescaler for External ETR Clock: Capture performed once every 2 events. */
    TIM_CLOCKPRESCALER_DIV4     =      TIM_SMCR_ETPS_1,           /*!< Prescaler for External ETR Clock: Capture performed once every 4 events. */
    TIM_CLOCKPRESCALER_DIV8     =      TIM_SMCR_ETPS              /*!< Prescaler for External ETR Clock: Capture performed once every 8 events. */
};
/** @defgroup TIM_Clock_Polarity TIM Clock Polarity
  * @{
  */
enum TIMExtCLKPolarity
{
    TIM_CLOCKPOLARITY_INVERTED      =     TIM_SMCR_ETP,                      /*!< Polarity for ETRx clock sources */
    TIM_CLOCKPOLARITY_NONINVERTED   =     0x00000000U,                       /*!< Polarity for ETRx clock sources */
    TIM_CLOCKPOLARITY_RISING        =     0x00000000U,                       /*!< Polarity for TIx clock sources */
    TIM_CLOCKPOLARITY_FALLING       =     TIM_CCER_CC1P,                     /*!< Polarity for TIx clock sources */
    TIM_CLOCKPOLARITY_BOTHEDGE      =     (TIM_CCER_CC1P | TIM_CCER_CC1NP)   /*!< Polarity for TIx clock sources */
};
enum TIMXCR1CountMode
{
    TIM_COUNTERMODE_UP              =   0x00000000U,                          /*!< Counter used as up-counter   */
    TIM_COUNTERMODE_DOWN            =   TIM_CR1_DIR,                          /*!< Counter used as down-counter */
    TIM_COUNTERMODE_CENTERALIGNED1  =   TIM_CR1_CMS_0,                        /*!< Center-aligned mode 1        */
    TIM_COUNTERMODE_CENTERALIGNED2  =   TIM_CR1_CMS_1,                        /*!< Center-aligned mode 2        */
    TIM_COUNTERMODE_CENTERALIGNED3  =   TIM_CR1_CMS                           /*!< Center-aligned mode 3        */
};

enum TIMCR1ClkDivi
{
    TIM_CLOCKDIVISION_DIV1       =      0x00000000U,                          /*!< Clock division: tDTS=tCK_INT   */
    TIM_CLOCKDIVISION_DIV2       =      TIM_CR1_CKD_0,                        /*!< Clock division: tDTS=2*tCK_INT */
    TIM_CLOCKDIVISION_DIV4       =      TIM_CR1_CKD_1,                        /*!< Clock division: tDTS=4*tCK_INT */
};

enum TIMChannelState
{
  TIM_CHANNEL_STATE_RESET             = 0x00U,    /*!< TIM Channel initial state                         */
  TIM_CHANNEL_STATE_READY             = 0x01U,    /*!< TIM Channel ready for use                         */
  TIM_CHANNEL_STATE_BUSY              = 0x02U,    /*!< An internal process is ongoing on the TIM channel */
};

enum TIMISRType
{
    TIM_IT_UPDATE         =          TIM_DIER_UIE,  
    TIM_IT_CC1            =          TIM_DIER_CC1IE,  
    TIM_IT_CC2            =          TIM_DIER_CC2IE,  
    TIM_IT_CC3            =          TIM_DIER_CC3IE,  
    TIM_IT_CC4            =          TIM_DIER_CC4IE,  
    TIM_IT_COM            =          TIM_DIER_COMIE,  
    TIM_IT_TRIGGER        =          TIM_DIER_TIE,  
    TIM_IT_BREAK          =          TIM_DIER_BIE,
    TIM_IT_DISABLE_ALL    =          (TIM_IT_UPDATE|TIM_IT_CC1|TIM_IT_CC2|TIM_IT_CC3|TIM_IT_CC4|TIM_IT_COM|TIM_IT_TRIGGER|TIM_IT_BREAK)
};
/** @defgroup TIM_Slave_Mode TIM Slave mode
  * @{
  */
enum TIMSlaveMode
{
    TIM_SLAVEMODE_DISABLE               =    0x00000000U,                                        /*!< Slave mode disabled           */
    TIM_SLAVEMODE_RESET                 =    TIM_SMCR_SMS_2,                                     /*!< Reset Mode                    */
    TIM_SLAVEMODE_GATED                 =    (TIM_SMCR_SMS_2 | TIM_SMCR_SMS_0),                  /*!< Gated Mode                    */
    TIM_SLAVEMODE_TRIGGER               =    (TIM_SMCR_SMS_2 | TIM_SMCR_SMS_1),                  /*!< Trigger Mode                  */
    TIM_SLAVEMODE_EXTERNAL1             =    (TIM_SMCR_SMS_2 | TIM_SMCR_SMS_1 | TIM_SMCR_SMS_0), /*!< External Clock Mode 1         */
    TIM_SLAVEMODE_COMBINED_RESETTRIGGER =    TIM_SMCR_SMS_3                                     /*!< Combined reset + trigger mode */
};
/** @defgroup TIM_Flag_definition TIM Flag Definition
  * @{
  */
enum TIMISRFlag
{
    TIM_FLAG_UPDATE           =         TIM_SR_UIF,                           /*!< Update interrupt flag         */
    TIM_FLAG_CC1              =         TIM_SR_CC1IF,                         /*!< Capture/Compare 1 interrupt flag */
    TIM_FLAG_CC2              =         TIM_SR_CC2IF,                         /*!< Capture/Compare 2 interrupt flag */
    TIM_FLAG_CC3              =         TIM_SR_CC3IF,                         /*!< Capture/Compare 3 interrupt flag */
    TIM_FLAG_CC4              =         TIM_SR_CC4IF,                         /*!< Capture/Compare 4 interrupt flag */
    TIM_FLAG_CC5              =         TIM_SR_CC5IF,                         /*!< Capture/Compare 5 interrupt flag */
    TIM_FLAG_CC6              =         TIM_SR_CC6IF,                         /*!< Capture/Compare 6 interrupt flag */
    TIM_FLAG_COM              =         TIM_SR_COMIF,                         /*!< Commutation interrupt flag    */
    TIM_FLAG_TRIGGER          =         TIM_SR_TIF,                           /*!< Trigger interrupt flag        */
    TIM_FLAG_BREAK            =         TIM_SR_BIF,                           /*!< Break interrupt flag          */
    TIM_FLAG_BREAK2           =         TIM_SR_B2IF,                          /*!< Break 2 interrupt flag        */
    TIM_FLAG_SYSTEM_BREAK     =         TIM_SR_SBIF,                          /*!< System Break interrupt flag   */
    TIM_FLAG_CC1OF            =         TIM_SR_CC1OF,                         /*!< Capture 1 overcapture flag    */
    TIM_FLAG_CC2OF            =         TIM_SR_CC2OF,                         /*!< Capture 2 overcapture flag    */
    TIM_FLAG_CC3OF            =         TIM_SR_CC3OF,                         /*!< Capture 3 overcapture flag    */
    TIM_FLAG_CC4OF            =         TIM_SR_CC4OF                          /*!< Capture 4 overcapture flag    */
};
enum TIMActiveChannel
{
    TIM_ACTIVE_CHANNEL_1        = 0x01U,    /*!< The active channel is 1     */
    TIM_ACTIVE_CHANNEL_2        = 0x02U,    /*!< The active channel is 2     */
    TIM_ACTIVE_CHANNEL_3        = 0x04U,    /*!< The active channel is 3     */
    TIM_ACTIVE_CHANNEL_4        = 0x08U,    /*!< The active channel is 4     */
    TIM_ACTIVE_CHANNEL_5        = 0x10U,    /*!< The active channel is 5     */
    TIM_ACTIVE_CHANNEL_6        = 0x20U,    /*!< The active channel is 6     */
    TIM_ACTIVE_CHANNEL_CLEARED  = 0x00U     /*!< All active channels cleared */
};
/** @defgroup TIM_Channel TIM Channel
  * @{
  */
enum TIMCCChannel
{
    TIM_CHANNEL_1       =           0x00000000U,                          /*!< Capture/compare channel 1 identifier      */
    TIM_CHANNEL_2       =           0x00000004U,                          /*!< Capture/compare channel 2 identifier      */
    TIM_CHANNEL_3       =           0x00000008U,                          /*!< Capture/compare channel 3 identifier      */
    TIM_CHANNEL_4       =           0x0000000CU,                          /*!< Capture/compare channel 4 identifier      */
    TIM_CHANNEL_5       =           0x00000010U,                          /*!< Compare channel 5 identifier              */
    TIM_CHANNEL_6       =           0x00000014U,                          /*!< Compare channel 6 identifier              */
    TIM_CHANNEL_ALL     =           0x0000003CU                           /*!< Global Capture/compare channel identifier  */
};
/** @defgroup Channel_CC_State TIM Capture/Compare Channel State
  * @{
  */
enum TIMCCChannelStatus
{
    TIM_CCx_ENABLE         =          0x00000001U,                            /*!< Input or output channel is enabled */
    TIM_CCx_DISABLE        =          0x00000000U                             /*!< Input or output channel is disabled */
};
enum TIMCCNChannelStatus
{
    TIM_CCxN_ENABLE        =          0x00000004U,                            /*!< Complementary output channel is enabled */
    TIM_CCxN_DISABLE       =          0x00000000U                             /*!< Complementary output channel is enabled */
};
enum TIMOCPWMMode
{
    TIM_OCMODE_PWM1               =      (TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1),                    /*!< PWM mode 1                             */
    TIM_OCMODE_PWM2               =      (TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_0), /*!< PWM mode 2                             */
    TIM_OCMODE_COMBINED_PWM1      =      (TIM_CCMR1_OC1M_3 | TIM_CCMR1_OC1M_2),                     /*!< Combined PWM mode 1                    */
    TIM_OCMODE_COMBINED_PWM2      =      (TIM_CCMR1_OC1M_3 | TIM_CCMR1_OC1M_0 | TIM_CCMR1_OC1M_2),  /*!< Combined PWM mode 2                    */
    TIM_OCMODE_ASSYMETRIC_PWM1    =      (TIM_CCMR1_OC1M_3 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2),  /*!< Asymmetric PWM mode 1                  */
    TIM_OCMODE_ASSYMETRIC_PWM2    =      TIM_CCMR1_OC1M                                            /*!< Asymmetric PWM mode 2                  */
};
enum TIMOCMode
{
    TIM_OCMODE_TIMING              =     0x00000000U,                                              /*!< Frozen                                 */
    TIM_OCMODE_ACTIVE              =     TIM_CCMR1_OC1M_0,                                         /*!< Set channel to active level on match   */
    TIM_OCMODE_INACTIVE            =     TIM_CCMR1_OC1M_1,                                         /*!< Set channel to inactive level on match */
    TIM_OCMODE_TOGGLE              =     (TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_0),                    /*!< Toggle                                 */
    TIM_OCMODE_FORCED_ACTIVE       =     (TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_0),                   /*!< Force active level                     */
    TIM_OCMODE_FORCED_INACTIVE     =     TIM_CCMR1_OC1M_2,                                         /*!< Force inactive level                   */
    TIM_OCMODE_RETRIGERRABLE_OPM1  =    TIM_CCMR1_OC1M_3,                                          /*!< Retrigerrable OPM mode 1               */
    TIM_OCMODE_RETRIGERRABLE_OPM2  =    (TIM_CCMR1_OC1M_3 | TIM_CCMR1_OC1M_0)                     /*!< Retrigerrable OPM mode 2               */                                       /*!< Asymmetric PWM mode 2                  */
};
/** @defgroup TIM_Output_Compare_Polarity TIM Output Compare Polarity
  * @{
  */
enum TIMOCPolarity
{
    TIM_OCPOLARITY_HIGH       =        0x00000000U,                          /*!< Capture/Compare output polarity  */
    TIM_OCPOLARITY_LOW        =        TIM_CCER_CC1P                        /*!< Capture/Compare output polarity  */
};
/** @defgroup TIM_Output_Compare_N_Polarity TIM Complementary Output Compare Polarity
  * @{
  */
enum TIMOCNPolarity
{
    TIM_OCNPOLARITY_HIGH       =        0x00000000U,                          /*!< Capture/Compare output polarity  */
    TIM_OCNPOLARITY_LOW        =        TIM_CCER_CC1NP                        /*!< Capture/Compare output polarity  */
};
/** @defgroup TIM_Output_Compare_Idle_State TIM Output Compare Idle State
  * @{
  */
enum TIMOCIDLEState
{
    TIM_OCIDLESTATE_SET        =       TIM_CR2_OIS1,                         /*!< Output Idle state: OCx=1 when MOE=0 */
    TIM_OCIDLESTATE_RESET      =       0x00000000U                           /*!< Output Idle state: OCx=0 when MOE=0 */
};
/** @defgroup TIM_Output_Compare_N_Idle_State TIM Complementary Output Compare Idle State
  * @{
  */
enum TIMOCNIDLEState
{
    TIM_OCNIDLESTATE_SET        =       TIM_CR2_OIS1N,                         /*!< Complementary output Idle state: OCxN=1 when MOE=0 */
    TIM_OCNIDLESTATE_RESET      =       0x00000000U                            /*!< Complementary output Idle state: OCxN=0 when MOE=0 */
};
/** @defgroup TIM_Output_Fast_State TIM Output Fast State
  * @{
  */
enum TIMOCFast
{
    TIM_OCFAST_DISABLE       =       0x00000000U,                          /*!< Output Compare fast disable */
    TIM_OCFAST_ENABLE        =       TIM_CCMR1_OC1FE                      /*!< Output Compare fast enable  */
};
enum TIMEventGenerat
{
    TIM_EVENT_GEN_UG = TIM_EGR_UG,
    TIM_EVENT_GEN_CC1G = TIM_EGR_CC1G,
    TIM_EVENT_GEN_CC2G = TIM_EGR_CC2G,
    TIM_EVENT_GEN_CC3G = TIM_EGR_CC3G,
    TIM_EVENT_GEN_CC4G = TIM_EGR_CC4G,
    TIM_EVENT_GEN_COMG = TIM_EGR_COMG,
    TIM_EVENT_GEN_TG = TIM_EGR_TG,
    TIM_EVENT_GEN_BG = TIM_EGR_BG,
    TIM_EVENT_GEN_BG2 = TIM_EGR_B2G
};

/** @defgroup TIM_OSSR_Off_State_Selection_for_Run_mode_state TIM OSSR OffState Selection for Run mode state
  * @{
  */
enum TIMOSSRStatus
{
    TIM_OSSR_ENABLE   =        TIM_BDTR_OSSR,                  /*!< When inactive, OC/OCN outputs are enabled (still controlled by the timer)           */
    TIM_OSSR_DISABLE  =        0x00000000U                     /*!< When inactive, OC/OCN outputs are disabled (not controlled any longer by the timer) */
};
/** @defgroup TIM_OSSI_Off_State_Selection_for_Idle_mode_state TIM OSSI OffState Selection for Idle mode state
  * @{
  */
enum TIMOSSIStatus
{
    TIM_OSSI_ENABLE       =        TIM_BDTR_OSSI,                  /*!< When inactive, OC/OCN outputs are enabled (still controlled by the timer)           */
    TIM_OSSI_DISABLE      =        0x00000000U                     /*!< When inactive, OC/OCN outputs are disabled (not controlled any longer by the timer) */
};
/** @defgroup TIM_Lock_level  TIM Lock level
  * @{
  */
enum TIMLockLevel
{
    TIM_LOCKLEVEL_OFF      =          0x00000000U,                          /*!< LOCK OFF     */
    TIM_LOCKLEVEL_1        =          TIM_BDTR_LOCK_0,                      /*!< LOCK Level 1 */
    TIM_LOCKLEVEL_2        =          TIM_BDTR_LOCK_1,                      /*!< LOCK Level 2 */
    TIM_LOCKLEVEL_3        =          TIM_BDTR_LOCK                         /*!< LOCK Level 3 */
};
/** @defgroup TIM_Break_Input_enable_disable TIM Break Input Enable
  * @{
  */
enum TIMBreakStatus
{
    TIM_BREAK_ENABLE      =        TIM_BDTR_BKE,                         /*!< Break input BRK is enabled  */
    TIM_BREAK_DISABLE     =        0x00000000U                           /*!< Break input BRK is disabled */
};
/** @defgroup TIM_Break_Polarity TIM Break Input Polarity
  * @{
  */
enum TIMBreakPolarity
{
    TIM_BREAKPOLARITY_LOW       =       0x00000000U,                          /*!< Break input BRK is active low  */
    TIM_BREAKPOLARITY_HIGH      =       TIM_BDTR_BKP                          /*!< Break input BRK is active high */
};
/** @defgroup TIM_Break2_Input_enable_disable TIM Break input 2 Enable
  * @{
  */
enum TIMBreak2Status
{
    TIM_BREAK2_DISABLE        =         0x00000000U,                          /*!< Break input BRK2 is disabled  */
    TIM_BREAK2_ENABLE         =         TIM_BDTR_BK2E                         /*!< Break input BRK2 is enabled  */
};
/** @defgroup TIM_Break2_Polarity TIM Break Input 2 Polarity
  * @{
  */
enum TIMBreak2Polarity
{
    TIM_BREAK2POLARITY_LOW      =       0x00000000U,                          /*!< Break input BRK2 is active low   */
    TIM_BREAK2POLARITY_HIGH     =       TIM_BDTR_BK2P                        /*!< Break input BRK2 is active high  */
};
/** @defgroup TIM_AOE_Bit_Set_Reset TIM Automatic Output Enable
  * @{
  */
enum TIMAutomaticOutputStatus
{
    TIM_AUTOMATICOUTPUT_DISABLE    =    0x00000000U,                          /*!< MOE can be set only by software */
    TIM_AUTOMATICOUTPUT_ENABLE     =    TIM_BDTR_AOE                          /*!< MOE can be set by software or automatically at the next update event (if none of the break inputs BRK and BRK2 is active) */
};
/** @defgroup TIM_Input_Capture_Polarity TIM Input Capture Polarity
  * @{
  */
enum TIMICPolarity
{
    TIM_ICPOLARITY_RISING       =      TIM_INPUTCHANNELPOLARITY_RISING,      /*!< Capture triggered by rising edge on timer input                  */
    TIM_ICPOLARITY_FALLING      =      TIM_INPUTCHANNELPOLARITY_FALLING,     /*!< Capture triggered by falling edge on timer input                 */
    TIM_ICPOLARITY_BOTHEDGE     =      TIM_INPUTCHANNELPOLARITY_BOTHEDGE     /*!< Capture triggered by both rising and falling edges on timer input*/
};
/** @defgroup TIM_Encoder_Input_Polarity TIM Encoder Input Polarity
  * @{
  */
enum TIMEncoderInputPolarity
{
    TIM_ENCODERINPUTPOLARITY_RISING  =  TIM_INPUTCHANNELPOLARITY_RISING,      /*!< Encoder input with rising edge polarity  */
    TIM_ENCODERINPUTPOLARITY_FALLING =  TIM_INPUTCHANNELPOLARITY_FALLING     /*!< Encoder input with falling edge polarity */
};
/** @defgroup TIM_Input_Capture_Selection TIM Input Capture Selection
  * @{
  */
enum TIMICSelection
{
    TIM_ICSELECTION_DIRECTTI      =     TIM_CCMR1_CC1S_0,                     /*!< TIM Input 1, 2, 3 or 4 is selected to be connected to IC1, IC2, IC3 or IC4, respectively */
    TIM_ICSELECTION_INDIRECTTI    =     TIM_CCMR1_CC1S_1,                     /*!< TIM Input 1, 2, 3 or 4 is selected to be connected to IC2, IC1, IC4 or IC3, respectively */
    TIM_ICSELECTION_TRC           =     TIM_CCMR1_CC1S                        /*!< TIM Input 1, 2, 3 or 4 is selected to be connected to TRC */
};
/** @defgroup TIM_Input_Capture_Prescaler TIM Input Capture Prescaler
  * @{
  */
enum TIMICPrescaler
{
    TIM_ICPSC_DIV1          =        0x00000000U,                          /*!< Capture performed each time an edge is detected on the capture input */
    TIM_ICPSC_DIV2          =        TIM_CCMR1_IC1PSC_0,                   /*!< Capture performed once every 2 events                                */
    TIM_ICPSC_DIV4          =        TIM_CCMR1_IC1PSC_1,                   /*!< Capture performed once every 4 events                                */
    TIM_ICPSC_DIV8          =        TIM_CCMR1_IC1PSC                      /*!< Capture performed once every 8 events                                */
};
/** @defgroup TIM_Encoder_Mode TIM Encoder Mode
  * @{
  */
enum TIMEncoderMode
{
    TIM_ENCODERMODE_TI1     =       TIM_SMCR_SMS_0,                      /*!< Quadrature encoder mode 1, x2 mode, counts up/down on TI1FP1 edge depending on TI2FP2 level  */
    TIM_ENCODERMODE_TI2     =       TIM_SMCR_SMS_1,                      /*!< Quadrature encoder mode 2, x2 mode, counts up/down on TI2FP2 edge depending on TI1FP1 level. */
    TIM_ENCODERMODE_TI12    =       (TIM_SMCR_SMS_1 | TIM_SMCR_SMS_0)   /*!< Quadrature encoder mode 3, x4 mode, counts up/down on both TI1FP1 and TI2FP2 edges depending on the level of the other input. */
};

struct PWMBreakDeadTimeConfig
{
  TIMOSSRStatus             offStateRunMode;      /*!< TIM off state in run mode, This parameter can be a value of @ref TIM_OSSR_Off_State_Selection_for_Run_mode_state */
  TIMOSSIStatus             offStateIDLEMode;     /*!< TIM off state in IDLE mode, This parameter can be a value of @ref TIM_OSSI_Off_State_Selection_for_Idle_mode_state */
  TIMLockLevel              lockLevel;            /*!< TIM Lock level, This parameter can be a value of @ref TIM_Lock_level */
  uint32_t                  deadTime;             /*!< TIM dead Time, This parameter can be a number between Min_Data = 0x00 and Max_Data = 0xFF */
  TIMBreakStatus            breakState;           /*!< TIM Break State, This parameter can be a value of @ref TIM_Break_Input_enable_disable */
  TIMBreakPolarity          breakPolarity;        /*!< TIM Break input polarity, This parameter can be a value of @ref TIM_Break_Polarity */
  uint32_t                  breakFilter;          /*!< Specifies the break input filter.This parameter can be a number between Min_Data = 0x0 and Max_Data = 0xF */
  TIMBreak2Status           break2State;          /*!< TIM Break2 State, This parameter can be a value of @ref TIM_Break2_Input_enable_disable */
  TIMBreak2Polarity         break2Polarity;       /*!< TIM Break2 input polarity, This parameter can be a value of @ref TIM_Break2_Polarity */
  uint32_t                  break2Filter;         /*!< TIM break2 input filter.This parameter can be a number between Min_Data = 0x0 and Max_Data = 0xF */
  TIMAutomaticOutputStatus  automaticOutput;      /*!< TIM Automatic Output Enable state, This parameter can be a value of @ref TIM_AOE_Bit_Set_Reset */
};

class COMMONTIMER
{
    using TIMInterruptCb = std::function<void(COMMONTIMER*, TIMISRFlag)>;
public:
    COMMONTIMER(TIM_TypeDef* timer) : timer_(timer), timarr_(0), activeChannel_(TIM_ACTIVE_CHANNEL_CLEARED)
    {
        enableClk();
        setAllChannelState(TIM_CHANNEL_STATE_RESET);
        setAllChannelNState(TIM_CHANNEL_STATE_RESET);
    }
    ~COMMONTIMER()
    {

    }
    COMMONTIMER(const COMMONTIMER&) = delete;
    COMMONTIMER(COMMONTIMER&&) = delete;
    COMMONTIMER& operator=(const COMMONTIMER&) = delete;
    COMMONTIMER& operator=(COMMONTIMER&&) = delete;
    eResult timInit(uint32_t freqHz, TIMXCR1CountMode countMode = TIM_COUNTERMODE_UP, uint32_t repetCount = 0, TIMCR1ClkDivi div = TIM_CLOCKDIVISION_DIV1, bool autoReload = true)
    {
        uint32_t period = 0;
        uint32_t prescaler = 0;
        uint32_t targetVal = 0;
        if(READ_BIT(timer_->SMCR, TIM_SMCR_ECE) == TIM_SMCR_ECE)
        {
            return E_RESULT_WRONG_STATUS;//ONLY INTERNAL CLKSRC CAN DO THIS
        }
        if(freqHz < 100)
        {
            targetVal = getInputClk() / 10000;
            prescaler = getInputClk() / targetVal;
            period = (getInputClk() / prescaler) / freqHz;
        }
        else if(freqHz < 3663/*getInputClk()/65536(16bit)*/)
        {
            targetVal = getInputClk() / 100;
            prescaler = getInputClk() / targetVal;
            period = (getInputClk() / prescaler) / freqHz;
        }
        else
        {
            prescaler = 1;
            period = getInputClk() / freqHz;
        }
        return timInit(period - 1, prescaler - 1, countMode, repetCount, div, autoReload);
    }
    eResult setTimFreq(uint32_t freqHz)
    {
        uint32_t period = 0;
        uint32_t prescaler = 0;
        uint32_t targetVal = 0;
        if(READ_BIT(timer_->SMCR, TIM_SMCR_ECE) == TIM_SMCR_ECE)
        {
            return E_RESULT_WRONG_STATUS;//ONLY INTERNAL CLKSRC CAN DO THIS
        }
        if(freqHz < 100)
        {
            targetVal = getInputClk() / 10000;
            prescaler = getInputClk() / targetVal;
            period = (getInputClk() / prescaler) / freqHz;
        }
        else if(freqHz < 3000)
        {
            targetVal = getInputClk() / 100;
            prescaler = getInputClk() / targetVal;
            period = (getInputClk() / prescaler) / freqHz;
        }
        else
        {
            prescaler = 1;
            period = getInputClk() / freqHz;
        }
        timarr_ = period;
        /* Set the Prescaler value */
        timer_->PSC = static_cast<uint32_t>(prescaler - 1);
        timer_->ARR = static_cast<uint32_t>(period - 1);
        generateEvent(TIM_EVENT_GEN_UG);
        return E_RESULT_OK;
    }
    eResult timInit(uint32_t period, uint32_t prescaler, TIMXCR1CountMode countMode = TIM_COUNTERMODE_UP, uint32_t repetCount = 0, TIMCR1ClkDivi div = TIM_CLOCKDIVISION_DIV1, bool autoReload = true)
    {
        CHECK_RETURN(IS_TIM_INSTANCE(timer_), E_RESULT_INVALID_PARAM);
        timarr_ = period + 1;
        uint32_t tmpcr1 = timer_->CR1;
        if(IS_TIM_COUNTER_MODE_SELECT_INSTANCE(timer_))
        {
            MODIFY_REG(tmpcr1, (TIM_CR1_DIR | TIM_CR1_CMS), countMode);
        }
        if (IS_TIM_CLOCK_DIVISION_INSTANCE(timer_))
        {
            MODIFY_REG(tmpcr1, TIM_CR1_CKD, div);
        }
        /* Set the auto-reload preload */
        MODIFY_REG(tmpcr1, TIM_CR1_ARPE, autoReload ? (1 << TIM_CR1_ARPE_Pos) : (0 << TIM_CR1_ARPE_Pos));
        timer_->CR1 = tmpcr1;

        timer_->ARR = static_cast<uint32_t>(period);
        /* Set the Prescaler value */
        timer_->PSC = static_cast<uint32_t>(prescaler);
        if (IS_TIM_REPETITION_COUNTER_INSTANCE(timer_))
        {
            /* Set the Repetition Counter value */
            timer_->RCR = repetCount;
        }

        /* Generate an update event to reload the Prescaler
            and the repetition counter (only for advanced timer) value immediately */
        timer_->EGR = TIM_EGR_UG;
        setAllChannelState(TIM_CHANNEL_STATE_READY);
        setAllChannelNState(TIM_CHANNEL_STATE_READY);

        registerTimIsrCb(timer_,[](void* param){
            COMMONTIMER* ptim = reinterpret_cast<COMMONTIMER*>(param);
            if(ptim)
            {
                ptim->handlerISREvent();
            }
        },this);

        return E_RESULT_OK;
    }
    void timDeinit()
    {
        stop();
        disableIsr(TIM_IT_DISABLE_ALL);
        unregisterInterruptCb();
        setAllChannelState(TIM_CHANNEL_STATE_RESET);
        setAllChannelNState(TIM_CHANNEL_STATE_RESET);
        enableClk(false);
    }
    eResult start()
    {
        CHECK_RETURN(IS_TIM_INSTANCE(timer_), E_RESULT_INVALID_PARAM);
        /* Enable the Peripheral, except in trigger mode where enable is automatically done with trigger */
        if (IS_TIM_SLAVE_INSTANCE(timer_))
        {
            if(!(READ_BIT(timer_->SMCR, TIM_SMCR_SMS) == TIM_SLAVEMODE_TRIGGER || READ_BIT(timer_->SMCR, TIM_SMCR_SMS) == TIM_SLAVEMODE_COMBINED_RESETTRIGGER))
            {
                SET_BIT(timer_->CR1, TIM_CR1_CEN);
            }
        }
        else
        {
            SET_BIT(timer_->CR1, TIM_CR1_CEN);
        }
        return E_RESULT_OK;
    }
    void stop()
    {
        if (IS_TIM_SLAVE_INSTANCE(timer_))
        {
            if(!(READ_BIT(timer_->SMCR, TIM_SMCR_SMS) == TIM_SLAVEMODE_TRIGGER || READ_BIT(timer_->SMCR, TIM_SMCR_SMS) == TIM_SLAVEMODE_COMBINED_RESETTRIGGER))
            {
                CLEAR_BIT(timer_->CR1, TIM_CR1_CEN);
            }
        }
        else
        {
            CLEAR_BIT(timer_->CR1, TIM_CR1_CEN);
        }
    }
    void enableIsr(TIMISRType it, uint32_t PreemptPriority, uint32_t SubPriority)
    {
        if(NVIC_GetEnableIRQ(getIrqType(it)) == 0U)
        {
            NVIC_SetPriority(getIrqType(it), NVIC_EncodePriority(NVIC_GetPriorityGrouping(), PreemptPriority, SubPriority));
            NVIC_EnableIRQ(getIrqType(it));
        }
        if(READ_BIT(timer_->DIER, it) != it)
        {
            SET_BIT(timer_->DIER, it);
        }
    }
    void disableIsr(TIMISRType it)
    {
        CLEAR_BIT(timer_->DIER, it);
    }
    void registerInterruptCb(const TIMInterruptCb& isrcb)
    {
        timcb_ = isrcb;
    }
    void unregisterInterruptCb()
    {
        if(timcb_)
        {
            timcb_ = TIMInterruptCb();
        }
    }
    uint32_t getInputClk()
    {
        uint32_t clk = 0;
        RCCControl* rcc = RCCControl::getInstance();
        switch(reinterpret_cast<uint32_t>(timer_))
        {
            case TIM1_BASE:
            case TIM8_BASE:
            case TIM15_BASE:
            case TIM16_BASE:
            case TIM17_BASE:
                if(rcc->GetAPB2Prescaler() != RCC_APB2_DIV_1)
                {
                    clk = rcc->GetPCLK2ClockFreq()*2;
                }
                else
                {
                    clk = rcc->GetPCLK2ClockFreq();
                }
                break;
            case TIM2_BASE:
            case TIM3_BASE:
            case TIM4_BASE:
            case TIM5_BASE:
            case TIM6_BASE:
            case TIM7_BASE:
            case TIM12_BASE:
            case TIM13_BASE:
            case TIM14_BASE:
                if(rcc->GetAPB1Prescaler() != RCC_APB1_DIV_1)
                {
                    clk = rcc->GetPCLK1ClockFreq()*2;
                }
                else
                {
                    clk = rcc->GetPCLK1ClockFreq();
                }
                break;
            default:
                break;
        }
        return clk;
    }
    uint32_t getTimeoutTimerNs()
    {
        uint32_t period = READ_BIT(timer_->ARR, TIM_ARR_ARR)+1;
        printf("period = %lu\r\n",period);
        uint32_t prescaler = READ_BIT(timer_->PSC,TIM_PSC_PSC)+1;
        printf("prescaler = %lu\r\n",prescaler);
        return period*1000000000/(getInputClk()/prescaler);
    }
    uint32_t getTimFreq()
    {
        uint32_t period = READ_BIT(timer_->ARR, TIM_ARR_ARR)+1;
        uint32_t prescaler = READ_BIT(timer_->PSC,TIM_PSC_PSC)+1;
        return (getInputClk()/prescaler)/(period);
    }
    TIMActiveChannel getActiveChannel() const
    {
        return activeChannel_;
    }
    eResult selectClockSource(TIMCLKSrc clockSource, TIMExtCLKPolarity clockPolarity, TIMExtCLKPrecaler clockPrescaler, uint32_t clockFilter)
    {
        eResult status = E_RESULT_OK;
        uint32_t tmpsmcr = 0;
        uint32_t tmpccmr1 = 0;
        uint32_t tmpccer = 0;
        /* Reset the SMS, TS, ECE, ETPS and ETRF bits */
        tmpsmcr = timer_->SMCR;
        tmpsmcr &= ~(TIM_SMCR_SMS | TIM_SMCR_TS);
        tmpsmcr &= ~(TIM_SMCR_ETF | TIM_SMCR_ETPS | TIM_SMCR_ECE | TIM_SMCR_ETP);
        timer_->SMCR = tmpsmcr;

        switch (clockSource)
        {
            case TIM_CLOCKSOURCE_INTERNAL:
            {
                if(!IS_TIM_INSTANCE(timer_))
                {
                    status = E_RESULT_INVALID_PARAM;
                }
                break;
            }
            case TIM_CLOCKSOURCE_ETRMODE1:
            {
                /* Check whether or not the timer instance supports external trigger input mode 1 (ETRF)*/
                if(IS_TIM_CLOCKSOURCE_ETRMODE1_INSTANCE(timer_))
                {
                    if(clockFilter < 0xFU)
                    {
                        status = E_RESULT_OUT_OF_RANGE;
                        break;
                    }
                    tmpsmcr = timer_->SMCR;

                    /* Reset the ETR Bits */
                    tmpsmcr &= ~(TIM_SMCR_ETF | TIM_SMCR_ETPS | TIM_SMCR_ECE | TIM_SMCR_ETP);
                    /* Set the Prescaler, the Filter value and the Polarity */
                    tmpsmcr |= (uint32_t)(clockPrescaler | (clockPolarity | (clockFilter << 8U)));
                    /* Write to TIMx SMCR */
                    timer_->SMCR = tmpsmcr;
                    /* Select the External clock mode1 and the ETRF trigger */
                    tmpsmcr = timer_->SMCR;
                    tmpsmcr |= (TIM_SLAVEMODE_EXTERNAL1 | TIM_CLOCKSOURCE_ETRMODE1);
                    /* Write to TIMx SMCR */
                    timer_->SMCR = tmpsmcr;
                }
                break;
            }
            case TIM_CLOCKSOURCE_ETRMODE2:
            {
                /* Check whether or not the timer instance supports external trigger input mode 2 (ETRF)*/
                if(IS_TIM_CLOCKSOURCE_ETRMODE2_INSTANCE(timer_))
                {
                        if(clockFilter < 0xFU)
                        {
                            status = E_RESULT_OUT_OF_RANGE;
                            break;
                        }
                        tmpsmcr = timer_->SMCR;

                        /* Reset the ETR Bits */
                        tmpsmcr &= ~(TIM_SMCR_ETF | TIM_SMCR_ETPS | TIM_SMCR_ECE | TIM_SMCR_ETP);
                        /* Set the Prescaler, the Filter value and the Polarity */
                        tmpsmcr |= (uint32_t)(clockPrescaler | (clockPolarity | (clockFilter << 8U)));
                        /* Write to TIMx SMCR */
                        timer_->SMCR = tmpsmcr;
                        /* Enable the External clock mode2 */
                        timer_->SMCR |= TIM_SMCR_ECE;
                }
                break;
            }
            case TIM_CLOCKSOURCE_TI1:
            {
                /* Check whether or not the timer instance supports external clock mode 1 */
                if(IS_TIM_CLOCKSOURCE_TIX_INSTANCE(timer_))
                {
                    if(clockFilter < 0xFU)
                    {
                        status = E_RESULT_OUT_OF_RANGE;
                        break;
                    }

                    /* Disable the Channel 1: Reset the CC1E Bit */
                    tmpccer = timer_->CCER;
                    timer_->CCER &= ~TIM_CCER_CC1E;
                    tmpccmr1 = timer_->CCMR1;

                    /* Set the filter */
                    tmpccmr1 &= ~TIM_CCMR1_IC1F;
                    tmpccmr1 |= (clockFilter << 4U);

                    /* Select the Polarity and set the CC1E Bit */
                    tmpccer &= ~(TIM_CCER_CC1P | TIM_CCER_CC1NP);
                    tmpccer |= clockPolarity;

                    /* Write to TIMx CCMR1 and CCER registers */
                    timer_->CCMR1 = tmpccmr1;
                    timer_->CCER = tmpccer;

                    /* Get the TIMx SMCR register value */
                    tmpsmcr = timer_->SMCR;
                    /* Reset the TS Bits */
                    tmpsmcr &= ~TIM_SMCR_TS;
                    /* Set the Input Trigger source and the slave mode*/
                    tmpsmcr |= (TIM_CLOCKSOURCE_TI1 | TIM_SLAVEMODE_EXTERNAL1);
                    /* Write to TIMx SMCR */
                    timer_->SMCR = tmpsmcr;
                }
                break;
            }
            case TIM_CLOCKSOURCE_TI2:
            {
                /* Check whether or not the timer instance supports external clock mode 1 (ETRF)*/
                if(IS_TIM_CLOCKSOURCE_TIX_INSTANCE(timer_))
                {
                    if(clockFilter < 0xFU)
                    {
                        status = E_RESULT_OUT_OF_RANGE;
                        break;
                    }

                    /* Disable the Channel 2: Reset the CC2E Bit */
                    timer_->CCER &= ~TIM_CCER_CC2E;
                    tmpccmr1 = timer_->CCMR1;
                    tmpccer = timer_->CCER;

                    /* Set the filter */
                    tmpccmr1 &= ~TIM_CCMR1_IC2F;
                    tmpccmr1 |= (clockFilter << 12U);

                    /* Select the Polarity and set the CC2E Bit */
                    tmpccer &= ~(TIM_CCER_CC2P | TIM_CCER_CC2NP);
                    tmpccer |= (clockPolarity << 4U);

                    /* Write to TIMx CCMR1 and CCER registers */
                    timer_->CCMR1 = tmpccmr1 ;
                    timer_->CCER = tmpccer;

                    /* Get the TIMx SMCR register value */
                    tmpsmcr = timer_->SMCR;
                    /* Reset the TS Bits */
                    tmpsmcr &= ~TIM_SMCR_TS;
                    /* Set the Input Trigger source and the slave mode*/
                    tmpsmcr |= (TIM_CLOCKSOURCE_TI2 | TIM_SLAVEMODE_EXTERNAL1);
                    /* Write to TIMx SMCR */
                    timer_->SMCR = tmpsmcr;
                }
                break;
            }
            case TIM_CLOCKSOURCE_TI1ED:
            {
                /* Check whether or not the timer instance supports external clock mode 1 */
                if(IS_TIM_CLOCKSOURCE_TIX_INSTANCE(timer_))
                {
                    if(clockFilter < 0xFU)
                    {
                        status = E_RESULT_OUT_OF_RANGE;
                        break;
                    }

                    /* Disable the Channel 1: Reset the CC1E Bit */
                    tmpccer = timer_->CCER;
                    timer_->CCER &= ~TIM_CCER_CC1E;
                    tmpccmr1 = timer_->CCMR1;

                    /* Set the filter */
                    tmpccmr1 &= ~TIM_CCMR1_IC1F;
                    tmpccmr1 |= (clockFilter << 4U);

                    /* Select the Polarity and set the CC1E Bit */
                    tmpccer &= ~(TIM_CCER_CC1P | TIM_CCER_CC1NP);
                    tmpccer |= clockPolarity;

                    /* Write to TIMx CCMR1 and CCER registers */
                    timer_->CCMR1 = tmpccmr1;
                    timer_->CCER = tmpccer;

                    /* Get the TIMx SMCR register value */
                    tmpsmcr = timer_->SMCR;
                    /* Reset the TS Bits */
                    tmpsmcr &= ~TIM_SMCR_TS;
                    /* Set the Input Trigger source and the slave mode*/
                    tmpsmcr |= (TIM_CLOCKSOURCE_TI1ED | TIM_SLAVEMODE_EXTERNAL1);
                    /* Write to TIMx SMCR */
                    timer_->SMCR = tmpsmcr;
                }
                break;
            }
            case TIM_CLOCKSOURCE_ITR0:
            case TIM_CLOCKSOURCE_ITR1:
            case TIM_CLOCKSOURCE_ITR2:
            case TIM_CLOCKSOURCE_ITR3:
            case TIM_CLOCKSOURCE_ITR4:
            case TIM_CLOCKSOURCE_ITR5:
            case TIM_CLOCKSOURCE_ITR6:
            case TIM_CLOCKSOURCE_ITR7:
            case TIM_CLOCKSOURCE_ITR8:
            {
                /* Check whether or not the timer instance supports internal trigger input */
                if(IS_TIM_CLOCKSOURCE_ITRX_INSTANCE(timer_))
                {
                    /* Get the TIMx SMCR register value */
                    tmpsmcr = timer_->SMCR;
                    /* Reset the TS Bits */
                    tmpsmcr &= ~TIM_SMCR_TS;
                    /* Set the Input Trigger source and the slave mode*/
                    tmpsmcr |= (clockSource | TIM_SLAVEMODE_EXTERNAL1);
                    /* Write to TIMx SMCR */
                    timer_->SMCR = tmpsmcr;
                }
                break;
            }
            default:
                status = E_RESULT_ERROR;
            break;
        }
        return status;
    }
    eResult pwmConfig(TIMCCChannel ch, uint32_t duty, TIMOCPWMMode pwmMode, TIMOCPolarity polarity = TIM_OCPOLARITY_HIGH, TIMOCNPolarity npolarity = TIM_OCNPOLARITY_HIGH,  TIMOCIDLEState idleState = TIM_OCIDLESTATE_RESET, TIMOCNIDLEState nidleState = TIM_OCNIDLESTATE_RESET, TIMOCFast fast = TIM_OCFAST_DISABLE)
    {
        if(duty < 1)
        {
            duty = 1;
        }
        if(duty > 100)
        {
            duty = 100;
        }
        uint32_t pulse = ((timarr_ * duty) / 100) - 1;
        eResult result = E_RESULT_OK;
        switch (ch)
        {
            case TIM_CHANNEL_1:
            {
                /* Check the parameters */
                if(!IS_TIM_CC1_INSTANCE(timer_))
                {
                    result = E_RESULT_INVALID_PARAM;
                    break;
                }
                /* Configure the Channel 1 in PWM mode */
                timOC1SetConfig(pulse, pwmMode, polarity, npolarity, idleState, nidleState);
                /* Set the Preload enable bit for channel1 */
                timer_->CCMR1 |= TIM_CCMR1_OC1PE;

                /* Configure the Output Fast mode */
                timer_->CCMR1 &= ~TIM_CCMR1_OC1FE;
                timer_->CCMR1 |= fast;
                break;
            }
            case TIM_CHANNEL_2:
            {
                /* Check the parameters */
                if(!IS_TIM_CC2_INSTANCE(timer_))
                {
                    result = E_RESULT_INVALID_PARAM;
                    break;
                }
                /* Configure the Channel 2 in PWM mode */
                timOC2SetConfig(pulse, pwmMode, polarity, npolarity, idleState, nidleState);

                /* Set the Preload enable bit for channel2 */
                timer_->CCMR1 |= TIM_CCMR1_OC2PE;

                /* Configure the Output Fast mode */
                timer_->CCMR1 &= ~TIM_CCMR1_OC2FE;
                timer_->CCMR1 |= fast << 8U;
                break;
            }
            case TIM_CHANNEL_3:
            {
                /* Check the parameters */
                if(!IS_TIM_CC3_INSTANCE(timer_))
                {
                    result = E_RESULT_INVALID_PARAM;
                    break;
                }

                /* Configure the Channel 3 in PWM mode */
                timOC3SetConfig(pulse, pwmMode, polarity, npolarity, idleState, nidleState);

                /* Set the Preload enable bit for channel3 */
                timer_->CCMR2 |= TIM_CCMR2_OC3PE;

                /* Configure the Output Fast mode */
                timer_->CCMR2 &= ~TIM_CCMR2_OC3FE;
                timer_->CCMR2 |= fast;
                break;
            }

            case TIM_CHANNEL_4:
            {
                /* Check the parameters */
                if(!IS_TIM_CC4_INSTANCE(timer_))
                {
                    result = E_RESULT_INVALID_PARAM;
                    break;
                }
                /* Configure the Channel 4 in PWM mode */
                timOC4SetConfig(pulse, pwmMode, polarity, npolarity, idleState, nidleState);

                /* Set the Preload enable bit for channel4 */
                timer_->CCMR2 |= TIM_CCMR2_OC4PE;

                /* Configure the Output Fast mode */
                timer_->CCMR2 &= ~TIM_CCMR2_OC4FE;
                timer_->CCMR2 |= fast << 8U;
                break;
            }

            case TIM_CHANNEL_5:
            {
                /* Check the parameters */
                if(!IS_TIM_CC5_INSTANCE(timer_))
                {
                    result = E_RESULT_INVALID_PARAM;
                    break;
                }
                /* Configure the Channel 5 in PWM mode */
                timOC5SetConfig(pulse, pwmMode, polarity, npolarity, idleState, nidleState);

                /* Set the Preload enable bit for channel5*/
                timer_->CCMR3 |= TIM_CCMR3_OC5PE;

                /* Configure the Output Fast mode */
                timer_->CCMR3 &= ~TIM_CCMR3_OC5FE;
                timer_->CCMR3 |= fast;
                break;
            }

            case TIM_CHANNEL_6:
            {
                /* Check the parameters */
                if(!IS_TIM_CC6_INSTANCE(timer_))
                {
                    result = E_RESULT_INVALID_PARAM;
                    break;
                }
                
                /* Configure the Channel 6 in PWM mode */
                timOC6SetConfig(pulse, pwmMode, polarity, npolarity, idleState, nidleState);

                /* Set the Preload enable bit for channel6 */
                timer_->CCMR3 |= TIM_CCMR3_OC6PE;

                /* Configure the Output Fast mode */
                timer_->CCMR3 &= ~TIM_CCMR3_OC6FE;
                timer_->CCMR3 |= fast << 8U;
                break;
            }

            default:
                result = E_RESULT_ERROR;
            break;
        }
        return result;
    }
    eResult pwmStart(TIMCCChannel ch)
    {
        uint32_t tmpsmcr;

        /* Check the parameters */
        if(!IS_TIM_CCX_INSTANCE(timer_, ch))
        {
            return E_RESULT_INVALID_PARAM;
        }

        /* Check the TIM channel state */
        if (getChannelState(ch) != TIM_CHANNEL_STATE_READY)
        {
            return E_RESULT_WRONG_STATUS;
        }

        /* Set the TIM channel state */
        setChannelState(ch, TIM_CHANNEL_STATE_BUSY);

        /* Enable the Capture compare channel */
        enabletimCCxChannel(ch, TIM_CCx_ENABLE);

        if (IS_TIM_BREAK_INSTANCE(timer_) != RESET)
        {
            /* Enable the main output */
            timer_->BDTR|=(TIM_BDTR_MOE);
        }

        /* Enable the Peripheral, except in trigger mode where enable is automatically done with trigger */
        if (IS_TIM_SLAVE_INSTANCE(timer_))
        {
            tmpsmcr = timer_->SMCR & TIM_SMCR_SMS;
            if (!(tmpsmcr == TIM_SLAVEMODE_TRIGGER || tmpsmcr == TIM_SLAVEMODE_COMBINED_RESETTRIGGER))
            {
                if(READ_BIT(timer_->CR1, TIM_CR1_CEN) == TIM_CR1_CEN)
                {
                    //return E_RESULT_WRONG_STATUS;
                }
            }
        }
        else
        {
            if(READ_BIT(timer_->CR1, TIM_CR1_CEN) == TIM_CR1_CEN)
            {
                //return E_RESULT_WRONG_STATUS;
            }
        }

        /* Return function status */
        return E_RESULT_OK;
    }
    eResult pwmStop(TIMCCChannel ch)
    {
        /* Check the parameters */
        if(!IS_TIM_CCX_INSTANCE(timer_, ch))
        {
            return E_RESULT_INVALID_PARAM;
        }

        /* Disable the Capture compare channel */
        enabletimCCxChannel(ch, TIM_CCx_DISABLE);

        if (IS_TIM_BREAK_INSTANCE(timer_) != RESET)
        {
            /* Disable the Main Output */
            timer_->BDTR&=(~TIM_BDTR_MOE);
        }

        /* Set the TIM channel state */
        setChannelState(ch, TIM_CHANNEL_STATE_READY);

        /* Return function status */
        return E_RESULT_OK;
    }
    eResult pwmSetDuty(TIMCCChannel ch, uint32_t duty)
    {
        if(duty < 1)
        {
            duty = 1;
        }
        if(duty > 100)
        {
            duty = 100;
        }
        uint32_t pulse = ((timarr_ * duty) / 100) - 1;
        switch(ch)
        {
            case TIM_CHANNEL_1:
                timer_->CCR1 = pulse;
                break;
            case TIM_CHANNEL_2:
                timer_->CCR2 = pulse;
                break;
            case TIM_CHANNEL_3:
                timer_->CCR3 = pulse;
                break;
            case TIM_CHANNEL_4:
                timer_->CCR4 = pulse;
                break;
            case TIM_CHANNEL_5:
                timer_->CCR5 = pulse;
                break;
            case TIM_CHANNEL_6:
                timer_->CCR6 = pulse;
                break;
            default:
                break;
        }
        return E_RESULT_OK;
    }
    void setCompare(TIMCCChannel ch, uint32_t pulse)
    {
        switch(ch)
        {
            case TIM_CHANNEL_1:
                timer_->CCR1 = pulse;
                break;
            case TIM_CHANNEL_2:
                timer_->CCR2 = pulse;
                break;
            case TIM_CHANNEL_3:
                timer_->CCR3 = pulse;
                break;
            case TIM_CHANNEL_4:
                timer_->CCR4 = pulse;
                break;
            case TIM_CHANNEL_5:
                timer_->CCR5 = pulse;
                break;
            case TIM_CHANNEL_6:
                timer_->CCR6 = pulse;
                break;
            default:
                break;
        }
    }
    eResult ocConfig(TIMCCChannel ch, uint32_t pulse, TIMOCMode ocMode, TIMOCPolarity polarity = TIM_OCPOLARITY_HIGH, TIMOCNPolarity npolarity = TIM_OCNPOLARITY_LOW,  TIMOCIDLEState idleState = TIM_OCIDLESTATE_RESET, TIMOCNIDLEState nidleState = TIM_OCNIDLESTATE_RESET)
    {
       eResult result = E_RESULT_OK;
        switch (ch)
        {
            case TIM_CHANNEL_1:
            {
                /* Check the parameters */
                if(!IS_TIM_CC1_INSTANCE(timer_))
                {
                    result = E_RESULT_INVALID_PARAM;
                    break;
                }
                 /* Configure the TIM Channel 1 in Output Compare */
                timOC1SetConfig(pulse, ocMode, polarity, npolarity, idleState, nidleState);
                /* Set the Preload enable bit for channel1 */
                timer_->CCMR1 |= TIM_CCMR1_OC1PE;
                break;
            }
            case TIM_CHANNEL_2:
            {
                /* Check the parameters */
                if(!IS_TIM_CC2_INSTANCE(timer_))
                {
                    result = E_RESULT_INVALID_PARAM;
                    break;
                }
                /* Configure the TIM Channel 2 in Output Compare */
                timOC2SetConfig(pulse, ocMode, polarity, npolarity, idleState, nidleState);
                /* Set the Preload enable bit for channel2 */
                timer_->CCMR1 |= TIM_CCMR1_OC2PE;
                break;
            }
            case TIM_CHANNEL_3:
            {
                /* Check the parameters */
                if(!IS_TIM_CC3_INSTANCE(timer_))
                {
                    result = E_RESULT_INVALID_PARAM;
                    break;
                }

                /* Configure the TIM Channel 3 in Output Compare */
                timOC3SetConfig(pulse, ocMode, polarity, npolarity, idleState, nidleState);
                /* Set the Preload enable bit for channel3 */
                timer_->CCMR2 |= TIM_CCMR2_OC3PE;
                break;
            }

            case TIM_CHANNEL_4:
            {
                /* Check the parameters */
                if(!IS_TIM_CC4_INSTANCE(timer_))
                {
                    result = E_RESULT_INVALID_PARAM;
                    break;
                }
                /* Configure the TIM Channel 4 in Output Compare */
                timOC4SetConfig(pulse, ocMode, polarity, npolarity, idleState, nidleState);
                /* Set the Preload enable bit for channel4 */
                timer_->CCMR2 |= TIM_CCMR2_OC4PE;
                break;
            }

            case TIM_CHANNEL_5:
            {
                /* Check the parameters */
                if(!IS_TIM_CC5_INSTANCE(timer_))
                {
                    result = E_RESULT_INVALID_PARAM;
                    break;
                }
                /* Configure the TIM Channel 5 in Output Compare */
                timOC5SetConfig(pulse, ocMode, polarity, npolarity, idleState, nidleState);
                /* Set the Preload enable bit for channel5*/
                timer_->CCMR3 |= TIM_CCMR3_OC5PE;
                break;
            }

            case TIM_CHANNEL_6:
            {
                /* Check the parameters */
                if(!IS_TIM_CC6_INSTANCE(timer_))
                {
                    result = E_RESULT_INVALID_PARAM;
                    break;
                }
                
                /* Configure the TIM Channel 6 in Output Compare */
                timOC6SetConfig(pulse, ocMode, polarity, npolarity, idleState, nidleState);
                /* Set the Preload enable bit for channel6 */
                timer_->CCMR3 |= TIM_CCMR3_OC6PE;
                break;
            }

            default:
                result = E_RESULT_ERROR;
            break;
        }
        return result;
    }
    eResult ocStart(TIMCCChannel ch)
    {
        uint32_t tmpsmcr;
        if(!IS_TIM_CCX_INSTANCE(timer_, ch))
        {
            return E_RESULT_INVALID_PARAM;
        }
        if(getChannelState(ch) != TIM_CHANNEL_STATE_READY)
        {
            return E_RESULT_WRONG_STATUS;
        }
        setChannelState(ch, TIM_CHANNEL_STATE_BUSY);

        /* Enable the Capture compare channel */
        enabletimCCxChannel(ch, TIM_CCx_ENABLE);

        if (IS_TIM_BREAK_INSTANCE(timer_) != RESET)
        {
            /* Enable the main output */
            timer_->BDTR|=(TIM_BDTR_MOE);
        }

        /* Enable the Peripheral, except in trigger mode where enable is automatically done with trigger */
        if (IS_TIM_SLAVE_INSTANCE(timer_))
        {
            tmpsmcr = timer_->SMCR & TIM_SMCR_SMS;
            if (!(tmpsmcr == TIM_SLAVEMODE_TRIGGER || tmpsmcr == TIM_SLAVEMODE_COMBINED_RESETTRIGGER))
            {
                if(READ_BIT(timer_->CR1, TIM_CR1_CEN) == TIM_CR1_CEN)
                {
                    //enable timer in timer start();
                }
            }
        }
        else
        {
            if(READ_BIT(timer_->CR1, TIM_CR1_CEN) == TIM_CR1_CEN)
            {
                //enable timer in timer start();
            }
        }
        return E_RESULT_OK;
    }
    eResult ocStop(TIMCCChannel ch)
    {
        /* Check the parameters */
        if(!IS_TIM_CCX_INSTANCE(timer_, ch))
        {
            return E_RESULT_INVALID_PARAM;
        }

        /* Disable the Capture compare channel */
        enabletimCCxChannel(ch, TIM_CCx_DISABLE);

        if (IS_TIM_BREAK_INSTANCE(timer_) != RESET)
        {
            /* Disable the Main Output */
            timer_->BDTR&=(~TIM_BDTR_MOE);
        }

        /* Set the TIM channel state */
        setChannelState(ch, TIM_CHANNEL_STATE_READY);

        /* Return function status */
        return E_RESULT_OK;
    }
    eResult pwmConfigBreakDeadTime(PWMBreakDeadTimeConfig* pconfig)
    {
        if(!IS_TIM_BREAK_INSTANCE(timer_) || !pconfig || pconfig->breakFilter > 0xFUL || pconfig->deadTime > 0xFFUL)
        {
            return E_RESULT_INVALID_PARAM;
        }
        /* Keep this variable initialized to 0 as it is used to configure BDTR register */
        uint32_t tmpbdtr = 0U;
        /* Set the BDTR bits */
        MODIFY_REG(tmpbdtr, TIM_BDTR_DTG, pconfig->deadTime);
        MODIFY_REG(tmpbdtr, TIM_BDTR_LOCK, pconfig->lockLevel);
        MODIFY_REG(tmpbdtr, TIM_BDTR_OSSI, pconfig->offStateIDLEMode);
        MODIFY_REG(tmpbdtr, TIM_BDTR_OSSR, pconfig->offStateRunMode);
        MODIFY_REG(tmpbdtr, TIM_BDTR_BKE, pconfig->breakState);
        MODIFY_REG(tmpbdtr, TIM_BDTR_BKP, pconfig->breakPolarity);
        MODIFY_REG(tmpbdtr, TIM_BDTR_AOE, pconfig->automaticOutput);
        MODIFY_REG(tmpbdtr, TIM_BDTR_BKF, (pconfig->breakFilter << TIM_BDTR_BKF_Pos));

        if (IS_TIM_BKIN2_INSTANCE(timer_))
        {
            /* Check the parameters */
            if(pconfig->break2Filter > 0xFUL)
            {
                return E_RESULT_INVALID_PARAM;
            }
            /* Set the BREAK2 input related BDTR bits */
            MODIFY_REG(tmpbdtr, TIM_BDTR_BK2F, (pconfig->break2Filter << TIM_BDTR_BK2F_Pos));
            MODIFY_REG(tmpbdtr, TIM_BDTR_BK2E, pconfig->break2State);
            MODIFY_REG(tmpbdtr, TIM_BDTR_BK2P, pconfig->break2Polarity);
        }

        /* Set TIMx_BDTR */
        timer_->BDTR = tmpbdtr;
        return E_RESULT_OK;
    }
    eResult pwmNstart(TIMCCChannel ch)
    {
        uint32_t tmpsmcr;

        /* Check the parameters */
        CHECK_RETURN(IS_TIM_CCXN_INSTANCE(timer_, ch), E_RESULT_INVALID_PARAM);
        /* Check the TIM complementary channel state */
        CHECK_RETURN(getChannelNState(ch) == TIM_CHANNEL_STATE_READY, E_RESULT_WRONG_STATUS);

        /* Set the TIM complementary channel state */
        setChannelNState(ch, TIM_CHANNEL_STATE_BUSY);

        /* Enable the complementary PWM output  */
        enabletimCCxNChannel(ch, TIM_CCxN_ENABLE);

        /* Enable the Main Output */
        timer_->BDTR|=(TIM_BDTR_MOE);

        /* Enable the Peripheral, except in trigger mode where enable is automatically done with trigger */
        if (IS_TIM_SLAVE_INSTANCE(timer_))
        {
            tmpsmcr = timer_->SMCR & TIM_SMCR_SMS;
            if (!(tmpsmcr == TIM_SLAVEMODE_TRIGGER || tmpsmcr == TIM_SLAVEMODE_COMBINED_RESETTRIGGER))
            {
            //__HAL_TIM_ENABLE(htim);
            }
        }
        else
        {
           // __HAL_TIM_ENABLE(htim);
        }
        /* Return function status */
        return E_RESULT_OK;
    }
    eResult pwmNstop(TIMCCChannel ch)
    {
        /* Check the parameters */
        CHECK_RETURN(IS_TIM_CCXN_INSTANCE(timer_, ch), E_RESULT_INVALID_PARAM);

        /* Disable the complementary PWM output  */
        enabletimCCxNChannel(ch, TIM_CCxN_DISABLE);

        /* Disable the Main Output */
        timer_->BDTR&=~(TIM_BDTR_MOE);

        /* Set the TIM complementary channel state */
        setChannelNState(ch, TIM_CHANNEL_STATE_READY);
        return E_RESULT_OK;
    }
    uint32_t calcuDTGns(uint32_t deadTime)
    {
        uint32_t fclk = getInputClk();
        float Tdtsns = 0.0;
        float timeRange[8] = {0.0f};
        float result = 0;
        uint32_t dtgVal = 0;
        if(READ_BIT(timer_->CR1, TIM_CR1_CKD) == TIM_CLOCKDIVISION_DIV1)
        {
            Tdtsns = 1000000000.0f / (float)fclk;
        }
        else if(READ_BIT(timer_->CR1, TIM_CR1_CKD) == TIM_CLOCKDIVISION_DIV2)
        {
            Tdtsns = 2000000000.0f / (float)fclk;
        }
        else if(READ_BIT(timer_->CR1, TIM_CR1_CKD) == TIM_CLOCKDIVISION_DIV4)
        {
            Tdtsns = 4000000000.0f / (float)fclk;
        }
        timeRange[0] = Tdtsns * 0.0f;
        timeRange[1] = Tdtsns * 127.0f;
        timeRange[2] = 64.0f*2.0f*Tdtsns;//(64+DTG[5:0])xtdtg，其中 Tdtg=2xtDTS。
        timeRange[3] = 127.0f*2.0f*Tdtsns;
        timeRange[4] = 32.0f*8.0f*Tdtsns;
        timeRange[5] = 63.0f*8.0f*Tdtsns;
        timeRange[6] = 32.0f*16.0f*Tdtsns;
        timeRange[7] = 63.0f*16.0f*Tdtsns;

        if(deadTime > timeRange[0] && deadTime < timeRange[1])
        {
            result = (float)deadTime / Tdtsns;
        }
        else if(deadTime > timeRange[2] && deadTime < timeRange[3])
        {
            result = (float)deadTime / (Tdtsns*2) - 64;
            dtgVal |= 2 << 6;
        }
        else if(deadTime > timeRange[4] && deadTime < timeRange[5])
        {
            result = (float)deadTime / (Tdtsns*8) - 32;
            dtgVal |= 6 << 4;
        }
        else if(deadTime > timeRange[6] && deadTime < timeRange[7])
        {
            result = (float)deadTime / (Tdtsns*16) - 32;
            dtgVal |= 7 << 4;
        }
        dtgVal |= ::lroundf(result);
        return dtgVal;
    }
    void generateEvent(TIMEventGenerat EventSource)
    {
        /* Set the event sources */
        timer_->EGR = EventSource;
    }
    void setRepetCount(uint32_t repetCount)
    {
        if (IS_TIM_REPETITION_COUNTER_INSTANCE(timer_))
        {
            /* Set the Repetition Counter value */
            timer_->RCR = repetCount;
            generateEvent(TIM_EVENT_GEN_UG);
        }
    }
    eResult icConfig(TIMCCChannel ch, TIMICPolarity polarity, TIMICSelection selection, TIMICPrescaler prescaler, uint32_t filter = 0x00)
    {
        CHECK_RETURN(filter <= 0x0f, E_RESULT_INVALID_PARAM);
        CHECK_RETURN(IS_TIM_CC1_INSTANCE(timer_), E_RESULT_INVALID_PARAM);

        eResult status = E_RESULT_OK;

        if (ch == TIM_CHANNEL_1)
        {
            /* TI1 Configuration */
            ti1SetConfig(polarity, selection, filter);

            /* Reset the IC1PSC Bits */
            timer_->CCMR1 &= ~TIM_CCMR1_IC1PSC;

            /* Set the IC1PSC value */
            timer_->CCMR1 |= prescaler;
        }
        else if (ch == TIM_CHANNEL_2)
        {
            /* TI2 Configuration */
            CHECK_RETURN(IS_TIM_CC2_INSTANCE(timer_), E_RESULT_INVALID_PARAM);

            ti2SetConfig(polarity, selection, filter);

            /* Reset the IC2PSC Bits */
            timer_->CCMR1 &= ~TIM_CCMR1_IC2PSC;

            /* Set the IC2PSC value */
            timer_->CCMR1 |= (prescaler << 8U);
        }
        else if (ch == TIM_CHANNEL_3)
        {
            /* TI3 Configuration */
            CHECK_RETURN(IS_TIM_CC3_INSTANCE(timer_), E_RESULT_INVALID_PARAM);

            ti3SetConfig(polarity, selection, filter);

            /* Reset the IC3PSC Bits */
            timer_->CCMR2 &= ~TIM_CCMR2_IC3PSC;

            /* Set the IC3PSC value */
            timer_->CCMR2 |= prescaler;
        }
        else if (ch == TIM_CHANNEL_4)
        {
            /* TI4 Configuration */
            CHECK_RETURN(IS_TIM_CC4_INSTANCE(timer_), E_RESULT_INVALID_PARAM);

            ti4SetConfig(polarity, selection, filter);

            /* Reset the IC4PSC Bits */
            timer_->CCMR2 &= ~TIM_CCMR2_IC4PSC;

            /* Set the IC4PSC value */
            timer_->CCMR2 |= (prescaler << 8U);
        }
        else
        {
            status = E_RESULT_ERROR;
        }
        return status;
    }
    eResult icStart(TIMCCChannel ch)
    {
        uint32_t tmpsmcr;
        TIMChannelState chState = getChannelState(ch);
        TIMChannelState chNState = getChannelNState(ch);

        /* Check the parameters */
        CHECK_RETURN(IS_TIM_CCX_INSTANCE(timer_, ch), E_RESULT_INVALID_PARAM);

        /* Check the TIM channel state */
        if ((chState != TIM_CHANNEL_STATE_READY)
            || (chNState != TIM_CHANNEL_STATE_READY))
        {
            return E_RESULT_WRONG_STATUS;
        }

        /* Set the TIM channel state */
        setChannelState(ch, TIM_CHANNEL_STATE_BUSY);
        setChannelNState(ch, TIM_CHANNEL_STATE_BUSY);

        /* Enable the Input Capture channel */

        enabletimCCxChannel(ch, TIM_CCx_ENABLE);

        /* Enable the Peripheral, except in trigger mode where enable is automatically done with trigger */
        if (IS_TIM_SLAVE_INSTANCE(timer_))
        {
            tmpsmcr = timer_->SMCR & TIM_SMCR_SMS;
            if (!(tmpsmcr == TIM_SLAVEMODE_TRIGGER || tmpsmcr == TIM_SLAVEMODE_COMBINED_RESETTRIGGER))
            {
                //__HAL_TIM_ENABLE(htim);
            }
        }
        else
        {
            //__HAL_TIM_ENABLE(htim);
        }
        /* Return function status */
        return E_RESULT_OK;
    }
    eResult icStop(TIMCCChannel ch)
    {
        /* Check the parameters */
        CHECK_RETURN(IS_TIM_CCX_INSTANCE(timer_, ch), E_RESULT_INVALID_PARAM);

        /* Disable the Input Capture channel */
        enabletimCCxChannel(ch, TIM_CCx_DISABLE);

        /* Set the TIM channel state */
        setChannelState(ch, TIM_CHANNEL_STATE_READY);
        setChannelNState(ch, TIM_CHANNEL_STATE_READY);
        return E_RESULT_OK;
    }
    uint32_t readCapturedValue(TIMCCChannel ch)
    {
        uint32_t tmpreg = 0U;

        switch (ch)
        {
            case TIM_CHANNEL_1:
            {
                /* Check the parameters */
                CHECK_RETURN(IS_TIM_CC1_INSTANCE(timer_), E_RESULT_INVALID_PARAM);
                /* Return the capture 1 value */
                tmpreg =  timer_->CCR1;
                break;
            }
            case TIM_CHANNEL_2:
            {
                /* Check the parameters */
                CHECK_RETURN(IS_TIM_CC2_INSTANCE(timer_), E_RESULT_INVALID_PARAM);
                /* Return the capture 2 value */
                tmpreg =   timer_->CCR2;
                break;
            }
            case TIM_CHANNEL_3:
            {
                /* Check the parameters */
                CHECK_RETURN(IS_TIM_CC3_INSTANCE(timer_), E_RESULT_INVALID_PARAM);

                /* Return the capture 3 value */
                tmpreg =   timer_->CCR3;

                break;
            }
            case TIM_CHANNEL_4:
            {
                /* Check the parameters */
                CHECK_RETURN(IS_TIM_CC4_INSTANCE(timer_), E_RESULT_INVALID_PARAM);
                /* Return the capture 4 value */
                tmpreg =   timer_->CCR4;
                break;
            }
            default:
            break;
        }
        return tmpreg;
    }
    uint32_t getPeriod() const
    {
        return timarr_;
    }
    eResult encoderConfig(TIMEncoderMode encoderMode, TIMEncoderInputPolarity ic1Polarity, TIMICSelection ic1Selection, TIMICPrescaler ic1Prescaler, uint32_t ic1Filter, TIMEncoderInputPolarity ic2Polarity, TIMICSelection ic2Selection, TIMICPrescaler ic2Prescaler, uint32_t ic2Filter)
    {
        uint32_t tmpsmcr;
        uint32_t tmpccmr1;
        uint32_t tmpccer;

        CHECK_RETURN(ic1Filter <= 0xFU, E_RESULT_INVALID_PARAM);
        CHECK_RETURN(ic2Filter <= 0xFU, E_RESULT_INVALID_PARAM);

          /* Reset the SMS and ECE bits */
        timer_->SMCR &= ~(TIM_SMCR_SMS | TIM_SMCR_ECE);

        /* Get the TIMx SMCR register value */
        tmpsmcr = timer_->SMCR;

        /* Get the TIMx CCMR1 register value */
        tmpccmr1 = timer_->CCMR1;

        /* Get the TIMx CCER register value */
        tmpccer = timer_->CCER;

        /* Set the encoder Mode */
        tmpsmcr |= encoderMode;

        /* Select the Capture Compare 1 and the Capture Compare 2 as input */
        tmpccmr1 &= ~(TIM_CCMR1_CC1S | TIM_CCMR1_CC2S);
        tmpccmr1 |= (ic1Selection | (ic2Selection << 8U));

        /* Set the Capture Compare 1 and the Capture Compare 2 prescalers and filters */
        tmpccmr1 &= ~(TIM_CCMR1_IC1PSC | TIM_CCMR1_IC2PSC);
        tmpccmr1 &= ~(TIM_CCMR1_IC1F | TIM_CCMR1_IC2F);
        tmpccmr1 |= ic1Prescaler | (ic2Prescaler << 8U);
        tmpccmr1 |= (ic1Filter << 4U) | (ic2Filter << 12U);

        /* Set the TI1 and the TI2 Polarities */
        tmpccer &= ~(TIM_CCER_CC1P | TIM_CCER_CC2P);
        tmpccer &= ~(TIM_CCER_CC1NP | TIM_CCER_CC2NP);
        tmpccer |= ic1Polarity | (ic2Polarity << 4U);

        /* Write to TIMx SMCR */
        timer_->SMCR = tmpsmcr;

        /* Write to TIMx CCMR1 */
        timer_->CCMR1 = tmpccmr1;

        /* Write to TIMx CCER */
        timer_->CCER = tmpccer;

        return E_RESULT_OK;
    }
    eResult encoderStart(TIMCCChannel ch)
    {
        TIMChannelState channel1State = getChannelState(TIM_CHANNEL_1);
        TIMChannelState channel2State = getChannelState(TIM_CHANNEL_2);
        TIMChannelState complementaryChannel1State = getChannelNState(TIM_CHANNEL_1);
        TIMChannelState complementaryChannel2State = getChannelNState(TIM_CHANNEL_2);

        /* Check the parameters */
        CHECK_RETURN(IS_TIM_ENCODER_INTERFACE_INSTANCE(timer_), E_RESULT_INVALID_PARAM);

        /* Set the TIM channel(s) state */
        if (ch == TIM_CHANNEL_1)
        {
            if ((channel1State != TIM_CHANNEL_STATE_READY)
                || (complementaryChannel1State != TIM_CHANNEL_STATE_READY))
            {
                return E_RESULT_WRONG_STATUS;
            }
            else
            {
                setChannelState(TIM_CHANNEL_1, TIM_CHANNEL_STATE_BUSY);
                setChannelNState(TIM_CHANNEL_1, TIM_CHANNEL_STATE_BUSY);
            }
        }
        else if (ch == TIM_CHANNEL_2)
        {
            if ((channel2State != TIM_CHANNEL_STATE_READY)
                || (complementaryChannel2State != TIM_CHANNEL_STATE_READY))
            {
                return E_RESULT_WRONG_STATUS;
            }
            else
            {
                setChannelState(TIM_CHANNEL_2, TIM_CHANNEL_STATE_BUSY);
                setChannelNState(TIM_CHANNEL_2, TIM_CHANNEL_STATE_BUSY);
            }
        }
        else
        {
            if ((channel1State != TIM_CHANNEL_STATE_READY)
                || (channel2State != TIM_CHANNEL_STATE_READY)
                || (complementaryChannel1State != TIM_CHANNEL_STATE_READY)
                || (complementaryChannel2State != TIM_CHANNEL_STATE_READY))
            {
                return E_RESULT_WRONG_STATUS;
            }
            else
            {
                setChannelState(TIM_CHANNEL_1, TIM_CHANNEL_STATE_BUSY);
                setChannelState(TIM_CHANNEL_2, TIM_CHANNEL_STATE_BUSY);
                setChannelNState(TIM_CHANNEL_1, TIM_CHANNEL_STATE_BUSY);
                setChannelNState(TIM_CHANNEL_2, TIM_CHANNEL_STATE_BUSY);
            }
        }
        /* Enable the encoder interface channels */
        switch (ch)
        {
            case TIM_CHANNEL_1:
            {
                enabletimCCxChannel(TIM_CHANNEL_1, TIM_CCx_ENABLE);
                break;
            }
            case TIM_CHANNEL_2:
            {
                enabletimCCxChannel(TIM_CHANNEL_2, TIM_CCx_ENABLE);
                break;
            }
            default :
            {
                enabletimCCxChannel(TIM_CHANNEL_1, TIM_CCx_ENABLE);
                enabletimCCxChannel(TIM_CHANNEL_2, TIM_CCx_ENABLE);
                break;
            }
        }
        /* Return function status */
        return E_RESULT_OK;
    }
    eResult encoderStop(TIMCCChannel ch)
    {
        /* Check the parameters */
        CHECK_RETURN(IS_TIM_ENCODER_INTERFACE_INSTANCE(timer_), E_RESULT_INVALID_PARAM);

        /* Disable the Input Capture channels 1 and 2
            (in the EncoderInterface the two possible channels that can be used are TIM_CHANNEL_1 and TIM_CHANNEL_2) */
        switch (ch)
        {
            case TIM_CHANNEL_1:
            {
                enabletimCCxChannel(TIM_CHANNEL_1, TIM_CCx_DISABLE);
                break;
            }

            case TIM_CHANNEL_2:
            {
                enabletimCCxChannel(TIM_CHANNEL_2, TIM_CCx_DISABLE);
                break;
            }

            default :
            {
                enabletimCCxChannel(TIM_CHANNEL_1, TIM_CCx_DISABLE);
                enabletimCCxChannel(TIM_CHANNEL_2, TIM_CCx_DISABLE);
                break;
            }
        }
        /* Set the TIM channel(s) state */
        if ((ch == TIM_CHANNEL_1) || (ch == TIM_CHANNEL_2))
        {
            setChannelState(ch, TIM_CHANNEL_STATE_READY);
            setChannelNState(ch, TIM_CHANNEL_STATE_READY);
        }
        else
        {
            setChannelState(TIM_CHANNEL_1, TIM_CHANNEL_STATE_READY);
            setChannelState(TIM_CHANNEL_2, TIM_CHANNEL_STATE_READY);
            setChannelNState(TIM_CHANNEL_1, TIM_CHANNEL_STATE_READY);
            setChannelNState(TIM_CHANNEL_2, TIM_CHANNEL_STATE_READY);
        }

        /* Return function status */
        return E_RESULT_OK;
    }
private:
    void handlerISREvent()
    {
        /* Capture compare 1 event */
        if(READ_BIT(timer_->SR, TIM_FLAG_CC1) == TIM_FLAG_CC1)
        {
            if(READ_BIT(timer_->DIER, TIM_IT_CC1) == TIM_IT_CC1)
            {
                CLEAR_BIT(timer_->SR, TIM_FLAG_CC1);
                activeChannel_ = TIM_ACTIVE_CHANNEL_1;
                /* Input capture event */
                if (READ_BIT(timer_->CCMR1, TIM_CCMR1_CC1S) != 0x00U)
                {
                    if(timcb_)
                    {
                        timcb_(this, TIM_FLAG_CC1);
                    }
                }
                else /* Output compare event */
                {
                    if(timcb_)
                    {
                        timcb_(this, TIM_FLAG_CC1);
                    }
                }
                activeChannel_ = TIM_ACTIVE_CHANNEL_CLEARED;
            }
        }
        /* Capture compare 2 event */
        if(READ_BIT(timer_->SR, TIM_FLAG_CC2) == TIM_FLAG_CC2)
        {
            if(READ_BIT(timer_->DIER, TIM_IT_CC2) == TIM_IT_CC2)
            {
                CLEAR_BIT(timer_->SR, TIM_FLAG_CC2);
                activeChannel_ = TIM_ACTIVE_CHANNEL_2;
                /* Input capture event */
                if (READ_BIT(timer_->CCMR1, TIM_CCMR1_CC2S) != 0x00U)
                {
                    if(timcb_)
                    {
                        timcb_(this, TIM_FLAG_CC2);
                    }
                }
                else /* Output compare event */
                {
                    if(timcb_)
                    {
                        timcb_(this, TIM_FLAG_CC2);
                    }
                }
                activeChannel_ = TIM_ACTIVE_CHANNEL_CLEARED;
            }
        }
        /* Capture compare 3 event */
        if(READ_BIT(timer_->SR, TIM_FLAG_CC3) == TIM_FLAG_CC3)
        {
            if(READ_BIT(timer_->DIER, TIM_IT_CC3) == TIM_IT_CC3)
            {
                CLEAR_BIT(timer_->SR, TIM_FLAG_CC3);
                activeChannel_ = TIM_ACTIVE_CHANNEL_3;
                /* Input capture event */
                if (READ_BIT(timer_->CCMR2, TIM_CCMR2_CC3S) != 0x00U)
                {
                    if(timcb_)
                    {
                        timcb_(this, TIM_FLAG_CC3);
                    }
                }
                else /* Output compare event */
                {
                    if(timcb_)
                    {
                        timcb_(this, TIM_FLAG_CC3);
                    }
                }
                activeChannel_ = TIM_ACTIVE_CHANNEL_CLEARED;
            }
        }
        /* Capture compare 4 event */
        if(READ_BIT(timer_->SR, TIM_FLAG_CC4) == TIM_FLAG_CC4)
        {
            if(READ_BIT(timer_->DIER, TIM_IT_CC4) == TIM_IT_CC4)
            {
                CLEAR_BIT(timer_->SR, TIM_FLAG_CC4);
                activeChannel_ = TIM_ACTIVE_CHANNEL_3;
                /* Input capture event */
                if (READ_BIT(timer_->CCMR2, TIM_CCMR2_CC4S) != 0x00U)
                {
                    if(timcb_)
                    {
                        timcb_(this, TIM_FLAG_CC4);
                    }
                }
                else /* Output compare event */
                {
                    if(timcb_)
                    {
                        timcb_(this, TIM_FLAG_CC4);
                    }
                }
                activeChannel_ = TIM_ACTIVE_CHANNEL_CLEARED;
            }
        }
        /* TIM Update event */
        if(READ_BIT(timer_->SR, TIM_FLAG_UPDATE) == TIM_FLAG_UPDATE)
        {
            if(READ_BIT(timer_->DIER, TIM_IT_UPDATE) == TIM_IT_UPDATE)
            {
                CLEAR_BIT(timer_->SR, TIM_FLAG_UPDATE);
                if(timcb_)
                {
                    timcb_(this, TIM_FLAG_UPDATE);
                }
            }
        }
        /* TIM Break input event */
        if(READ_BIT(timer_->SR, TIM_FLAG_BREAK) == TIM_FLAG_BREAK)
        {
            if(READ_BIT(timer_->DIER, TIM_IT_BREAK) == TIM_IT_BREAK)
            {
                CLEAR_BIT(timer_->SR, TIM_FLAG_BREAK);
                if(timcb_)
                {
                    timcb_(this, TIM_FLAG_BREAK);
                }
            }
        }
        /* TIM Break2 input event */
        if(READ_BIT(timer_->SR, TIM_FLAG_BREAK2) == TIM_FLAG_BREAK2)
        {
            if(READ_BIT(timer_->DIER, TIM_IT_BREAK) == TIM_IT_BREAK)
            {
                CLEAR_BIT(timer_->SR, TIM_FLAG_BREAK2);
                if(timcb_)
                {
                    timcb_(this, TIM_FLAG_BREAK2);
                }
            }
        }
        /* TIM Trigger detection event */
        if(READ_BIT(timer_->SR, TIM_FLAG_TRIGGER) == TIM_FLAG_TRIGGER)
        {
            if(READ_BIT(timer_->DIER, TIM_IT_TRIGGER) == TIM_IT_TRIGGER)
            {
                CLEAR_BIT(timer_->SR, TIM_FLAG_TRIGGER);
                if(timcb_)
                {
                    timcb_(this, TIM_FLAG_TRIGGER);
                }
            }
        }
        /* TIM commutation event */
        if(READ_BIT(timer_->SR, TIM_FLAG_COM) == TIM_FLAG_COM)
        {
            if(READ_BIT(timer_->DIER, TIM_IT_COM) == TIM_IT_COM)
            {
                CLEAR_BIT(timer_->SR, TIM_FLAG_COM);
                if(timcb_)
                {
                    timcb_(this, TIM_FLAG_COM);
                }
            }
        }
    }
    inline void setAllChannelState(TIMChannelState sta)
    {
        for(auto& it : channelState_)
        {
            it = sta;
        }
    }
    inline void setAllChannelNState(TIMChannelState sta)
    {
        for(auto& it : channelNState_)
        {
            it = sta;
        }
    }
    inline TIMChannelState getChannelState(TIMCCChannel ch)
    {
        return  (((ch) == TIM_CHANNEL_1) ? channelState_[0] :
                ((ch) == TIM_CHANNEL_2) ? channelState_[1] :
                ((ch) == TIM_CHANNEL_3) ? channelState_[2] :
                ((ch) == TIM_CHANNEL_4) ? channelState_[3] :
                ((ch) == TIM_CHANNEL_5) ? channelState_[4] :
                channelState_[5]);
    }
    inline TIMChannelState getChannelNState(TIMCCChannel ch)
    {
        return  (((ch) == TIM_CHANNEL_1) ? channelNState_[0] :\
                ((ch) == TIM_CHANNEL_2) ? channelNState_[1] :\
                ((ch) == TIM_CHANNEL_3) ? channelNState_[2] :\
                channelNState_[3]);
    }
    inline void setChannelState(TIMCCChannel ch, TIMChannelState state)
    {
        (((ch) == TIM_CHANNEL_1) ? (channelState_[0] = (state)) :\
        ((ch) == TIM_CHANNEL_2) ? (channelState_[1] = (state)) :\
        ((ch) == TIM_CHANNEL_3) ? (channelState_[2] = (state)) :\
        ((ch) == TIM_CHANNEL_4) ? (channelState_[3] = (state)) :\
        ((ch) == TIM_CHANNEL_5) ? (channelState_[4] = (state)) :\
        (channelState_[5] = (state)));
    }
    inline void setChannelNState(TIMCCChannel ch, TIMChannelState state)
    {
        (((ch) == TIM_CHANNEL_1) ? (channelNState_[0] = (state)) :\
        ((ch) == TIM_CHANNEL_2) ? (channelNState_[1] = (state)) :\
        ((ch) == TIM_CHANNEL_3) ? (channelNState_[2] = (state)) :\
        (channelNState_[3] = (state)));
    }
    void enableClk(bool bEnable = true)
    {
        RCCControl* rcc = RCCControl::getInstance();
        switch (reinterpret_cast<uint32_t>(timer_))
        {
            case TIM1_BASE:
                rcc->APB2GRP1EnableClock(RCC_APB2_GRP1_PERIPH_TIM1);
                break;
            case TIM2_BASE:
                rcc->APB1GRP1EnableClock(RCC_APB1_GRP1_PERIPH_TIM2);
                break;
            case TIM3_BASE:
                rcc->APB1GRP1EnableClock(RCC_APB1_GRP1_PERIPH_TIM3);
                break;
            case TIM4_BASE:
                rcc->APB1GRP1EnableClock(RCC_APB1_GRP1_PERIPH_TIM4);
                break;
            case TIM5_BASE:
                rcc->APB1GRP1EnableClock(RCC_APB1_GRP1_PERIPH_TIM5);
                break;
            case TIM6_BASE:
                rcc->APB1GRP1EnableClock(RCC_APB1_GRP1_PERIPH_TIM6);
                break;
            case TIM7_BASE:
                rcc->APB1GRP1EnableClock(RCC_APB1_GRP1_PERIPH_TIM7);
                break;
            case TIM8_BASE:
                rcc->APB2GRP1EnableClock(RCC_APB2_GRP1_PERIPH_TIM8);
                break;
            case TIM12_BASE:
                rcc->APB1GRP1EnableClock(RCC_APB1_GRP1_PERIPH_TIM12);
                break;
            case TIM13_BASE:
                rcc->APB1GRP1EnableClock(RCC_APB1_GRP1_PERIPH_TIM13);
                break;
            case TIM14_BASE:
                rcc->APB1GRP1EnableClock(RCC_APB1_GRP1_PERIPH_TIM14);
                break;
            case TIM15_BASE:
                rcc->APB2GRP1EnableClock(RCC_APB2_GRP1_PERIPH_TIM15);
                break;
            case TIM16_BASE:
                rcc->APB2GRP1EnableClock(RCC_APB2_GRP1_PERIPH_TIM16);
                break;
            case TIM17_BASE:
                rcc->APB2GRP1EnableClock(RCC_APB2_GRP1_PERIPH_TIM17);
                break;
            default:
                break;
        }
    }
    IRQn_Type getIrqType(TIMISRType it)
    {
        IRQn_Type type = TIM1_UP_IRQn;
        switch (reinterpret_cast<uint32_t>(timer_))
        {
            case TIM1_BASE:
                switch (it)
                {
                case TIM_IT_UPDATE:
                    type = TIM1_UP_IRQn;
                    break;
                case TIM_IT_CC1:
                case TIM_IT_CC2:
                case TIM_IT_CC3:
                case TIM_IT_CC4:
                    type = TIM1_CC_IRQn;
                    break;
                case TIM_IT_COM:
                case TIM_IT_TRIGGER:
                    type = TIM1_TRG_COM_IRQn;
                    break;
                case TIM_IT_BREAK:
                    type = TIM1_BRK_IRQn;
                    break;
                default:
                    break;
                }
                break;
            case TIM2_BASE:
                type = TIM2_IRQn;
                break;
            case TIM3_BASE:
                type = TIM3_IRQn;
                break;
            case TIM4_BASE:
                type = TIM4_IRQn;
                break;
            case TIM5_BASE:
                type = TIM5_IRQn;
                break;
            case TIM6_BASE:
                type = TIM6_DAC_IRQn;
            case TIM7_BASE:
                type = TIM7_IRQn;
                break;
            case TIM8_BASE:
                switch (it)
                {
                    case TIM_IT_UPDATE:
                        type = TIM8_UP_TIM13_IRQn;
                        break;
                    case TIM_IT_CC1:
                    case TIM_IT_CC2:
                    case TIM_IT_CC3:
                    case TIM_IT_CC4:
                        type = TIM8_CC_IRQn;
                        break;
                    case TIM_IT_COM:
                    case TIM_IT_TRIGGER:
                        type = TIM8_TRG_COM_TIM14_IRQn;
                        break;
                    case TIM_IT_BREAK:
                        type = TIM8_BRK_TIM12_IRQn;
                        break;
                    default:
                        break;
                }
                break;
            case TIM12_BASE:
                type = TIM8_BRK_TIM12_IRQn;
                break;
            case TIM13_BASE:
                type = TIM8_UP_TIM13_IRQn;
                break;
            case TIM14_BASE:
                type = TIM8_TRG_COM_TIM14_IRQn;
                break;
            case TIM15_BASE:
                type = TIM15_IRQn;
                break;
            case TIM16_BASE:
                type = TIM16_IRQn;
                break;
            case TIM17_BASE:
                type = TIM17_IRQn;
                break;
            default:
                break;
        }
        return type;
    }
    void timOC1SetConfig(uint32_t pulse, uint32_t mode, TIMOCPolarity polarity, TIMOCNPolarity npolarity,  TIMOCIDLEState idleState, TIMOCNIDLEState nidleState)
    {
        uint32_t tmpccmrx;
        uint32_t tmpccer;
        uint32_t tmpcr2;

        /* Disable the Channel 1: Reset the CC1E Bit */
        timer_->CCER &= ~TIM_CCER_CC1E;
        /* Get the TIMx CCER register value */
        tmpccer = timer_->CCER;
        /* Get the TIMx CR2 register value */
        tmpcr2 =  timer_->CR2;

        /* Get the TIMx CCMR1 register value */
        tmpccmrx = timer_->CCMR1;

        /* Reset the Output Compare Mode Bits */
        tmpccmrx &= ~TIM_CCMR1_OC1M;
        tmpccmrx &= ~TIM_CCMR1_CC1S;
        /* Select the Output Compare Mode */
        tmpccmrx |= mode;

        /* Reset the Output Polarity level */
        tmpccer &= ~TIM_CCER_CC1P;
        /* Set the Output Compare Polarity */
        tmpccer |= polarity;

        if (IS_TIM_CCXN_INSTANCE(timer_, TIM_CHANNEL_1))
        {
            /* Reset the Output N Polarity level */
            tmpccer &= ~TIM_CCER_CC1NP;
            /* Set the Output N Polarity */
            tmpccer |= npolarity;
            /* Reset the Output N State */
            tmpccer &= ~TIM_CCER_CC1NE;
        }

        if (IS_TIM_BREAK_INSTANCE(timer_))
        {
            /* Reset the Output Compare and Output Compare N IDLE State */
            tmpcr2 &= ~TIM_CR2_OIS1;
            tmpcr2 &= ~TIM_CR2_OIS1N;
            /* Set the Output Idle state */
            tmpcr2 |= idleState;
            /* Set the Output N Idle state */
            tmpcr2 |= nidleState;
        }

        /* Write to TIMx CR2 */
        timer_->CR2 = tmpcr2;

        /* Write to TIMx CCMR1 */
        timer_->CCMR1 = tmpccmrx;

        /* Set the Capture Compare Register value */
        timer_->CCR1 = pulse;

        /* Write to TIMx CCER */
        timer_->CCER = tmpccer;
    }

    void timOC2SetConfig(uint32_t pulse, uint32_t mode, TIMOCPolarity polarity, TIMOCNPolarity npolarity,  TIMOCIDLEState idleState, TIMOCNIDLEState nidleState)
    {
        uint32_t tmpccmrx;
        uint32_t tmpccer;
        uint32_t tmpcr2;

        /* Disable the Channel 2: Reset the CC2E Bit */
        timer_->CCER &= ~TIM_CCER_CC2E;

        /* Get the TIMx CCER register value */
        tmpccer = timer_->CCER;
        /* Get the TIMx CR2 register value */
        tmpcr2 =  timer_->CR2;

        /* Get the TIMx CCMR1 register value */
        tmpccmrx = timer_->CCMR1;

        /* Reset the Output Compare mode and Capture/Compare selection Bits */
        tmpccmrx &= ~TIM_CCMR1_OC2M;
        tmpccmrx &= ~TIM_CCMR1_CC2S;

        /* Select the Output Compare Mode */
        tmpccmrx |= (mode << 8U);

        /* Reset the Output Polarity level */
        tmpccer &= ~TIM_CCER_CC2P;
        /* Set the Output Compare Polarity */
        tmpccer |= (polarity << 4U);

        if (IS_TIM_CCXN_INSTANCE(timer_, TIM_CHANNEL_2))
        {
            /* Reset the Output N Polarity level */
            tmpccer &= ~TIM_CCER_CC2NP;
            /* Set the Output N Polarity */
            tmpccer |= (npolarity << 4U);
            /* Reset the Output N State */
            tmpccer &= ~TIM_CCER_CC2NE;
        }

        if (IS_TIM_BREAK_INSTANCE(timer_))
        {
            /* Reset the Output Compare and Output Compare N IDLE State */
            tmpcr2 &= ~TIM_CR2_OIS2;
            tmpcr2 &= ~TIM_CR2_OIS2N;
            /* Set the Output Idle state */
            tmpcr2 |= (idleState << 2U);
            /* Set the Output N Idle state */
            tmpcr2 |= (nidleState << 2U);
        }

        /* Write to TIMx CR2 */
        timer_->CR2 = tmpcr2;

        /* Write to TIMx CCMR1 */
        timer_->CCMR1 = tmpccmrx;

        /* Set the Capture Compare Register value */
        timer_->CCR2 = pulse;

        /* Write to TIMx CCER */
        timer_->CCER = tmpccer;
    }
    void timOC3SetConfig(uint32_t pulse, uint32_t mode, TIMOCPolarity polarity, TIMOCNPolarity npolarity,  TIMOCIDLEState idleState, TIMOCNIDLEState nidleState)
    {
        uint32_t tmpccmrx;
        uint32_t tmpccer;
        uint32_t tmpcr2;

        /* Disable the Channel 3: Reset the CC2E Bit */
        timer_->CCER &= ~TIM_CCER_CC3E;

        /* Get the TIMx CCER register value */
        tmpccer = timer_->CCER;
        /* Get the TIMx CR2 register value */
        tmpcr2 =  timer_->CR2;

        /* Get the TIMx CCMR2 register value */
        tmpccmrx = timer_->CCMR2;

        /* Reset the Output Compare mode and Capture/Compare selection Bits */
        tmpccmrx &= ~TIM_CCMR2_OC3M;
        tmpccmrx &= ~TIM_CCMR2_CC3S;
        /* Select the Output Compare Mode */
        tmpccmrx |= mode;

        /* Reset the Output Polarity level */
        tmpccer &= ~TIM_CCER_CC3P;
        /* Set the Output Compare Polarity */
        tmpccer |= (polarity << 8U);

        if (IS_TIM_CCXN_INSTANCE(timer_, TIM_CHANNEL_3))
        {
            /* Reset the Output N Polarity level */
            tmpccer &= ~TIM_CCER_CC3NP;
            /* Set the Output N Polarity */
            tmpccer |= (npolarity << 8U);
            /* Reset the Output N State */
            tmpccer &= ~TIM_CCER_CC3NE;
        }

        if (IS_TIM_BREAK_INSTANCE(timer_))
        {
            /* Reset the Output Compare and Output Compare N IDLE State */
            tmpcr2 &= ~TIM_CR2_OIS3;
            tmpcr2 &= ~TIM_CR2_OIS3N;
            /* Set the Output Idle state */
            tmpcr2 |= (idleState << 4U);
            /* Set the Output N Idle state */
            tmpcr2 |= (nidleState << 4U);
        }

        /* Write to TIMx CR2 */
        timer_->CR2 = tmpcr2;

        /* Write to TIMx CCMR2 */
        timer_->CCMR2 = tmpccmrx;

        /* Set the Capture Compare Register value */
        timer_->CCR3 = pulse;

        /* Write to TIMx CCER */
        timer_->CCER = tmpccer;
    }
    void timOC4SetConfig(uint32_t pulse, uint32_t mode, TIMOCPolarity polarity, TIMOCNPolarity npolarity,  TIMOCIDLEState idleState, TIMOCNIDLEState nidleState)
    {
        uint32_t tmpccmrx;
        uint32_t tmpccer;
        uint32_t tmpcr2;

        /* Disable the Channel 4: Reset the CC4E Bit */
        timer_->CCER &= ~TIM_CCER_CC4E;

        /* Get the TIMx CCER register value */
        tmpccer = timer_->CCER;
        /* Get the TIMx CR2 register value */
        tmpcr2 =  timer_->CR2;

        /* Get the TIMx CCMR2 register value */
        tmpccmrx = timer_->CCMR2;

        /* Reset the Output Compare mode and Capture/Compare selection Bits */
        tmpccmrx &= ~TIM_CCMR2_OC4M;
        tmpccmrx &= ~TIM_CCMR2_CC4S;

        /* Select the Output Compare Mode */
        tmpccmrx |= (mode << 8U);

        /* Reset the Output Polarity level */
        tmpccer &= ~TIM_CCER_CC4P;
        /* Set the Output Compare Polarity */
        tmpccer |= (polarity << 12U);

        if (IS_TIM_BREAK_INSTANCE(timer_))
        {
            /* Reset the Output Compare IDLE State */
            tmpcr2 &= ~TIM_CR2_OIS4;

            /* Set the Output Idle state */
            tmpcr2 |= (idleState << 6U);
        }

        /* Write to TIMx CR2 */
        timer_->CR2 = tmpcr2;

        /* Write to TIMx CCMR2 */
        timer_->CCMR2 = tmpccmrx;

        /* Set the Capture Compare Register value */
        timer_->CCR4 = pulse;

        /* Write to TIMx CCER */
        timer_->CCER = tmpccer;
    }
    void timOC5SetConfig(uint32_t pulse, uint32_t mode, TIMOCPolarity polarity, TIMOCNPolarity npolarity,  TIMOCIDLEState idleState, TIMOCNIDLEState nidleState)
    {
        uint32_t tmpccmrx;
        uint32_t tmpccer;
        uint32_t tmpcr2;

        /* Disable the output: Reset the CCxE Bit */
        timer_->CCER &= ~TIM_CCER_CC5E;

        /* Get the TIMx CCER register value */
        tmpccer = timer_->CCER;
        /* Get the TIMx CR2 register value */
        tmpcr2 =  timer_->CR2;
        /* Get the TIMx CCMR1 register value */
        tmpccmrx = timer_->CCMR3;

        /* Reset the Output Compare Mode Bits */
        tmpccmrx &= ~(TIM_CCMR3_OC5M);
        /* Select the Output Compare Mode */
        tmpccmrx |= mode;

        /* Reset the Output Polarity level */
        tmpccer &= ~TIM_CCER_CC5P;
        /* Set the Output Compare Polarity */
        tmpccer |= (polarity << 16U);

        if (IS_TIM_BREAK_INSTANCE(timer_))
        {
            /* Reset the Output Compare IDLE State */
            tmpcr2 &= ~TIM_CR2_OIS5;
            /* Set the Output Idle state */
            tmpcr2 |= (idleState << 8U);
        }
        /* Write to TIMx CR2 */
        timer_->CR2 = tmpcr2;

        /* Write to TIMx CCMR3 */
        timer_->CCMR3 = tmpccmrx;

        /* Set the Capture Compare Register value */
        timer_->CCR5 = pulse;

        /* Write to TIMx CCER */
        timer_->CCER = tmpccer;
    }
    void timOC6SetConfig(uint32_t pulse, uint32_t mode, TIMOCPolarity polarity, TIMOCNPolarity npolarity,  TIMOCIDLEState idleState, TIMOCNIDLEState nidleState)
    {
        uint32_t tmpccmrx;
        uint32_t tmpccer;
        uint32_t tmpcr2;

        /* Disable the output: Reset the CCxE Bit */
        timer_->CCER &= ~TIM_CCER_CC6E;

        /* Get the TIMx CCER register value */
        tmpccer = timer_->CCER;
        /* Get the TIMx CR2 register value */
        tmpcr2 =  timer_->CR2;
        /* Get the TIMx CCMR1 register value */
        tmpccmrx = timer_->CCMR3;

        /* Reset the Output Compare Mode Bits */
        tmpccmrx &= ~(TIM_CCMR3_OC6M);
        /* Select the Output Compare Mode */
        tmpccmrx |= (mode << 8U);

        /* Reset the Output Polarity level */
        tmpccer &= (uint32_t)~TIM_CCER_CC6P;
        /* Set the Output Compare Polarity */
        tmpccer |= (polarity << 20U);

        if (IS_TIM_BREAK_INSTANCE(timer_))
        {
            /* Reset the Output Compare IDLE State */
            tmpcr2 &= ~TIM_CR2_OIS6;
            /* Set the Output Idle state */
            tmpcr2 |= (idleState << 10U);
        }

        /* Write to TIMx CR2 */
        timer_->CR2 = tmpcr2;

        /* Write to TIMx CCMR3 */
        timer_->CCMR3 = tmpccmrx;

        /* Set the Capture Compare Register value */
        timer_->CCR6 = pulse;

        /* Write to TIMx CCER */
        timer_->CCER = tmpccer;
    }
    eResult enabletimCCxChannel(TIMCCChannel ch, TIMCCChannelStatus channelState)
    {
        uint32_t tmp;

        /* Check the parameters */
        if(!IS_TIM_CC1_INSTANCE(timer_))
        {
            return E_RESULT_INVALID_PARAM;
        }
        tmp = TIM_CCER_CC1E << (ch & 0x1FU); /* 0x1FU = 31 bits max shift */

        /* Reset the CCxE Bit */
        timer_->CCER &= ~tmp;

        /* Set or reset the CCxE Bit */
        timer_->CCER |= (uint32_t)(channelState << (ch & 0x1FU)); /* 0x1FU = 31 bits max shift */
        return E_RESULT_OK;
    }
    void enabletimCCxNChannel(TIMCCChannel ch, TIMCCNChannelStatus ChannelNState)
    {
        uint32_t tmp;

        tmp = TIM_CCER_CC1NE << (ch & 0x1FU); /* 0x1FU = 31 bits max shift */

        /* Reset the CCxNE Bit */
        timer_->CCER &=  ~tmp;

        /* Set or reset the CCxNE Bit */
        timer_->CCER |= (uint32_t)(ChannelNState << (ch & 0x1FU)); /* 0x1FU = 31 bits max shift */
    }
    void ti1SetConfig(TIMICPolarity polarity, TIMICSelection selection, uint32_t filter)
    {
        uint32_t tmpccmr1;
        uint32_t tmpccer;

        /* Disable the Channel 1: Reset the CC1E Bit */
        timer_->CCER &= ~TIM_CCER_CC1E;
        tmpccmr1 = timer_->CCMR1;
        tmpccer = timer_->CCER;

        /* Select the Input */
        if (IS_TIM_CC2_INSTANCE(timer_) != RESET)
        {
            tmpccmr1 &= ~TIM_CCMR1_CC1S;
            tmpccmr1 |= selection;
        }
        else
        {
            tmpccmr1 |= TIM_CCMR1_CC1S_0;
        }

        /* Set the filter */
        tmpccmr1 &= ~TIM_CCMR1_IC1F;
        tmpccmr1 |= ((filter << 4U) & TIM_CCMR1_IC1F);

        /* Select the Polarity and set the CC1E Bit */
        tmpccer &= ~(TIM_CCER_CC1P | TIM_CCER_CC1NP);
        tmpccer |= (polarity & (TIM_CCER_CC1P | TIM_CCER_CC1NP));

        /* Write to TIMx CCMR1 and CCER registers */
        timer_->CCMR1 = tmpccmr1;
        timer_->CCER = tmpccer;
    }
    void ti2SetConfig(TIMICPolarity polarity, TIMICSelection selection, uint32_t filter)
    {
        uint32_t tmpccmr1;
        uint32_t tmpccer;

        /* Disable the Channel 2: Reset the CC2E Bit */
        timer_->CCER &= ~TIM_CCER_CC2E;
        tmpccmr1 = timer_->CCMR1;
        tmpccer = timer_->CCER;

        /* Select the Input */
        tmpccmr1 &= ~TIM_CCMR1_CC2S;
        tmpccmr1 |= (selection << 8U);

        /* Set the filter */
        tmpccmr1 &= ~TIM_CCMR1_IC2F;
        tmpccmr1 |= ((filter << 12U) & TIM_CCMR1_IC2F);

        /* Select the Polarity and set the CC2E Bit */
        tmpccer &= ~(TIM_CCER_CC2P | TIM_CCER_CC2NP);
        tmpccer |= ((polarity << 4U) & (TIM_CCER_CC2P | TIM_CCER_CC2NP));

        /* Write to TIMx CCMR1 and CCER registers */
        timer_->CCMR1 = tmpccmr1 ;
        timer_->CCER = tmpccer;
    }
    void ti3SetConfig(TIMICPolarity polarity, TIMICSelection selection, uint32_t filter)
    {
        uint32_t tmpccmr2;
        uint32_t tmpccer;

        /* Disable the Channel 3: Reset the CC3E Bit */
        timer_->CCER &= ~TIM_CCER_CC3E;
        tmpccmr2 = timer_->CCMR2;
        tmpccer = timer_->CCER;

        /* Select the Input */
        tmpccmr2 &= ~TIM_CCMR2_CC3S;
        tmpccmr2 |= selection;

        /* Set the filter */
        tmpccmr2 &= ~TIM_CCMR2_IC3F;
        tmpccmr2 |= ((filter << 4U) & TIM_CCMR2_IC3F);

        /* Select the Polarity and set the CC3E Bit */
        tmpccer &= ~(TIM_CCER_CC3P | TIM_CCER_CC3NP);
        tmpccer |= ((polarity << 8U) & (TIM_CCER_CC3P | TIM_CCER_CC3NP));

        /* Write to TIMx CCMR2 and CCER registers */
        timer_->CCMR2 = tmpccmr2;
        timer_->CCER = tmpccer;
    }
    void ti4SetConfig(TIMICPolarity polarity, TIMICSelection selection, uint32_t filter)
    {
        uint32_t tmpccmr2;
        uint32_t tmpccer;

        /* Disable the Channel 4: Reset the CC4E Bit */
        timer_->CCER &= ~TIM_CCER_CC4E;
        tmpccmr2 = timer_->CCMR2;
        tmpccer = timer_->CCER;

        /* Select the Input */
        tmpccmr2 &= ~TIM_CCMR2_CC4S;
        tmpccmr2 |= (selection << 8U);

        /* Set the filter */
        tmpccmr2 &= ~TIM_CCMR2_IC4F;
        tmpccmr2 |= ((filter << 12U) & TIM_CCMR2_IC4F);

        /* Select the Polarity and set the CC4E Bit */
        tmpccer &= ~(TIM_CCER_CC4P | TIM_CCER_CC4NP);
        tmpccer |= ((polarity << 12U) & (TIM_CCER_CC4P | TIM_CCER_CC4NP));

        /* Write to TIMx CCMR2 and CCER registers */
        timer_->CCMR2 = tmpccmr2;
        timer_->CCER = tmpccer ;
    }
private:
    TIM_TypeDef* timer_;
    __IO uint32_t timarr_;
    __IO TIMActiveChannel activeChannel_;
    __IO TIMChannelState  channelState_[6];   /*!< TIM channel operation state                       */
    __IO TIMChannelState  channelNState_[4];  /*!< TIM complementary channel operation state         */
    TIMInterruptCb timcb_;
};