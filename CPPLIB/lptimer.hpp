#pragma once 
#include "common.hpp"

/** @defgroup LPTIM_LL_EC_GET_FLAG Get Flags Defines
  * @brief    Flags defines which can be used with lptimReadReg function
  * @{
  */
enum LPTMOperatingMode
{
    LPTIM_OPERATING_MODE_CONTINUOUS  =  LPTIM_CR_CNTSTRT, /*!<LP Timer starts in continuous mode*/
    LPTIM_OPERATING_MODE_ONESHOT     =  LPTIM_CR_SNGSTRT  /*!<LP Tilmer starts in single mode*/
};
enum LPTMUpdateMode
{
    LPTIM_UPDATE_MODE_IMMEDIATE     =   0x00000000U,        /*!<Preload is disabled: registers are updated after each APB bus write access*/
    LPTIM_UPDATE_MODE_ENDOFPERIOD   =   LPTIM_CFGR_PRELOAD  /*!<preload is enabled: registers are updated at the end of the current LPTIM period*/
};
enum LPTMCounterMode
{
    LPTIM_COUNTER_MODE_INTERNAL    =    0x00000000U,          /*!<The counter is incremented following each internal clock pulse*/
    LPTIM_COUNTER_MODE_EXTERNAL    =    LPTIM_CFGR_COUNTMODE  /*!<The counter is incremented following each valid clock pulse on the LPTIM external Input1*/
};
enum LPTIMOutputWaveformType
{
    LPTIM_OUTPUT_WAVEFORM_PWM      =    0x00000000U,     /*!<LPTIM  generates either a PWM waveform or a One pulse waveform depending on chosen operating mode CONTINUOUS or SINGLE*/
    LPTIM_OUTPUT_WAVEFORM_SETONCE  =    LPTIM_CFGR_WAVE  /*!<LPTIM  generates a Set Once waveform*/
};
enum LPTIMOutputPolarity
{
    LPTIM_OUTPUT_POLARITY_REGULAR   =   0x00000000U,             /*!<The LPTIM output reflects the compare results between LPTIMx_ARR and LPTIMx_CMP registers*/
    LPTIM_OUTPUT_POLARITY_INVERSE   =   LPTIM_CFGR_WAVPOL        /*!<The LPTIM output reflects the inverse of the compare results between LPTIMx_ARR and LPTIMx_CMP registers*/
};
enum LPTMPrescaler
{
    LPTIM_PRESCALER_DIV1         =      0x00000000U,                               /*!<Prescaler division factor is set to 1*/
    LPTIM_PRESCALER_DIV2         =      LPTIM_CFGR_PRESC_0,                        /*!<Prescaler division factor is set to 2*/
    LPTIM_PRESCALER_DIV4         =      LPTIM_CFGR_PRESC_1,                        /*!<Prescaler division factor is set to 4*/
    LPTIM_PRESCALER_DIV8         =      (LPTIM_CFGR_PRESC_1 | LPTIM_CFGR_PRESC_0), /*!<Prescaler division factor is set to 8*/
    LPTIM_PRESCALER_DIV16        =      LPTIM_CFGR_PRESC_2,                        /*!<Prescaler division factor is set to 16*/
    LPTIM_PRESCALER_DIV32        =      (LPTIM_CFGR_PRESC_2 | LPTIM_CFGR_PRESC_0), /*!<Prescaler division factor is set to 32*/
    LPTIM_PRESCALER_DIV64        =      (LPTIM_CFGR_PRESC_2 | LPTIM_CFGR_PRESC_1), /*!<Prescaler division factor is set to 64*/
    LPTIM_PRESCALER_DIV128       =      LPTIM_CFGR_PRESC                           /*!<Prescaler division factor is set to 128*/
};
enum LPTMTriggerSource
{
    LPTIM_TRIG_SOURCE_GPIO          =   0x00000000U,                                                          /*!<External input trigger is connected to TIMx_ETR input*/
    LPTIM_TRIG_SOURCE_RTCALARMA     =   LPTIM_CFGR_TRIGSEL_0,                                                 /*!<External input trigger is connected to RTC Alarm A*/
    LPTIM_TRIG_SOURCE_RTCALARMB     =   LPTIM_CFGR_TRIGSEL_1,                                                 /*!<External input trigger is connected to RTC Alarm B*/
    LPTIM_TRIG_SOURCE_RTCTAMP1      =   (LPTIM_CFGR_TRIGSEL_1 | LPTIM_CFGR_TRIGSEL_0),                        /*!<External input trigger is connected to RTC Tamper 1*/
    LPTIM_TRIG_SOURCE_RTCTAMP2      =   LPTIM_CFGR_TRIGSEL_2,                                                 /*!<External input trigger is connected to RTC Tamper 2*/
    LPTIM_TRIG_SOURCE_RTCTAMP3      =   (LPTIM_CFGR_TRIGSEL_2 | LPTIM_CFGR_TRIGSEL_0),                        /*!<External input trigger is connected to RTC Tamper 3*/
    LPTIM_TRIG_SOURCE_COMP1         =   (LPTIM_CFGR_TRIGSEL_2 | LPTIM_CFGR_TRIGSEL_1),                        /*!<External input trigger is connected to COMP1 output*/
    LPTIM_TRIG_SOURCE_COMP2         =   LPTIM_CFGR_TRIGSEL,                                                   /*!<External input trigger is connected to COMP2 output*/
    LPTIM_TRIG_SOURCE_LPTIM2        =   0x00000000U,                                                          /*!<External input trigger is connected to LPTIM2 output*/
    LPTIM_TRIG_SOURCE_LPTIM3        =   LPTIM_CFGR_TRIGSEL_0,                                                 /*!<External input trigger is connected to LPTIM3 output*/
    LPTIM_TRIG_SOURCE_LPTIM4        =   LPTIM_CFGR_TRIGSEL_1,                                                 /*!<External input trigger is connected to LPTIM4 output*/
    LPTIM_TRIG_SOURCE_LPTIM5        =   (LPTIM_CFGR_TRIGSEL_1 | LPTIM_CFGR_TRIGSEL_0),                        /*!<External input trigger is connected to LPTIM5 output*/
    LPTIM_TRIG_SOURCE_SAI1_FS_A     =   LPTIM_CFGR_TRIGSEL_2,                                                 /*!<External input trigger is connected to SAI1 FS A output*/
    LPTIM_TRIG_SOURCE_SAI1_FS_B     =   (LPTIM_CFGR_TRIGSEL_2 | LPTIM_CFGR_TRIGSEL_0),                        /*!<External input trigger is connected to SAI1 FS B output*/
    LPTIM_TRIG_SOURCE_SAI2_FS_A     =   LPTIM_CFGR_TRIGSEL_2,                                                 /*!<External input trigger is connected to SAI2 FS A output*/
    LPTIM_TRIG_SOURCE_SAI2_FS_B     =   (LPTIM_CFGR_TRIGSEL_2 | LPTIM_CFGR_TRIGSEL_0),                        /*!<External input trigger is connected to SAI2 FS B output*/
    LPTIM_TRIG_SOURCE_SAI4_FS_A     =   (LPTIM_CFGR_TRIGSEL_1 | LPTIM_CFGR_TRIGSEL_0),                        /*!<External input trigger is connected to SAI4 FS A output*/
    LPTIM_TRIG_SOURCE_SAI4_FS_B     =   LPTIM_CFGR_TRIGSEL_2,                                                 /*!<External input trigger is connected to SAI4 FS B output*/
    LPTIM_TRIG_SOURCE_DFSDM2_BRK    =  (LPTIM_CFGR_TRIGSEL_2 | LPTIM_CFGR_TRIGSEL_1)                          /*!<External input trigger is connected to DFSDM2_BRK[0] */
};
enum LPTMTrigFilter
{
    LPTIM_TRIG_FILTER_NONE      =       0x00000000U,         /*!<Any trigger active level change is considered as a valid trigger*/
    LPTIM_TRIG_FILTER_2         =       LPTIM_CFGR_TRGFLT_0, /*!<Trigger active level change must be stable for at least 2 clock periods before it is considered as valid trigger*/
    LPTIM_TRIG_FILTER_4         =       LPTIM_CFGR_TRGFLT_1, /*!<Trigger active level change must be stable for at least 4 clock periods before it is considered as valid trigger*/
    LPTIM_TRIG_FILTER_8         =       LPTIM_CFGR_TRGFLT    /*!<Trigger active level change must be stable for at least 8 clock periods before it is considered as valid trigger*/
};
enum LPTMTrigPolarity
{
    LPTIM_TRIG_POLARITY_RISING           =   LPTIM_CFGR_TRIGEN_0, /*!<LPTIM counter starts when a rising edge is detected*/
    LPTIM_TRIG_POLARITY_FALLING          =   LPTIM_CFGR_TRIGEN_1, /*!<LPTIM counter starts when a falling edge is detected*/
    LPTIM_TRIG_POLARITY_RISING_FALLING   =   LPTIM_CFGR_TRIGEN    /*!<LPTIM counter starts when a rising or a falling edge is detected*/
};
enum LPTMClkFromSourceType
{
    LPTIM_CLK_SOURCE_INTERNAL     =     0x00000000U,      /*!<LPTIM is clocked by internal clock source (APB clock or any of the embedded oscillators)*/
    LPTIM_CLK_SOURCE_EXTERNAL     =     LPTIM_CFGR_CKSEL  /*!<LPTIM is clocked by an external clock source through the LPTIM external Input1*/
};
/** @defgroup LPTIM_LL_EC_CLK_FILTER Clock Filter
  * @{
  */
enum LPTMClkFilter
{
    LPTIM_CLK_FILTER_NONE      =        0x00000000U,        /*!<Any external clock signal level change is considered as a valid transition*/
    LPTIM_CLK_FILTER_2         =        LPTIM_CFGR_CKFLT_0, /*!<External clock signal level change must be stable for at least 2 clock periods before it is considered as valid transition*/
    LPTIM_CLK_FILTER_4         =        LPTIM_CFGR_CKFLT_1, /*!<External clock signal level change must be stable for at least 4 clock periods before it is considered as valid transition*/
    LPTIM_CLK_FILTER_8         =        LPTIM_CFGR_CKFLT    /*!<External clock signal level change must be stable for at least 8 clock periods before it is considered as valid transition*/
};
enum LPTMClkPolarity
{
    LPTIM_CLK_POLARITY_RISING          =  0x00000000U,        /*!< The rising edge is the active edge used for counting*/
    LPTIM_CLK_POLARITY_FALLING         =  LPTIM_CFGR_CKPOL_0, /*!< The falling edge is the active edge used for counting*/
    LPTIM_CLK_POLARITY_RISING_FALLING  =  LPTIM_CFGR_CKPOL_1  /*!< Both edges are active edges*/
};
enum LPTMEncoderMode
{
    LPTIM_ENCODER_MODE_RISING           =  0x00000000U,        /*!< The rising edge is the active edge used for counting*/
    LPTIM_ENCODER_MODE_FALLING          =  LPTIM_CFGR_CKPOL_0, /*!< The falling edge is the active edge used for counting*/
    LPTIM_ENCODER_MODE_RISING_FALLING   =  LPTIM_CFGR_CKPOL_1  /*!< Both edges are active edges*/
};
enum LPTMInput1Src
{
    LPTIM_INPUT1_SRC_GPIO         =   0x00000000U,                                            /*!< For LPTIM1 and LPTIM2 */
    LPTIM_INPUT1_SRC_COMP1        =   LPTIM_CFGR2_IN1SEL_0,                                   /*!< For LPTIM1 and LPTIM2 */
    LPTIM_INPUT1_SRC_COMP2        =   LPTIM_CFGR2_IN1SEL_1,                                   /*!< For LPTIM2 */
    LPTIM_INPUT1_SRC_COMP1_COMP2  =   (LPTIM_CFGR2_IN1SEL_1 | LPTIM_CFGR2_IN1SEL_0),          /*!< For LPTIM2 */
    LPTIM_INPUT1_SRC_SAI4_FS_A    =   LPTIM_CFGR2_IN1SEL_0,                                   /*!< For LPTIM3 */
    LPTIM_INPUT1_SRC_SAI4_FS_B    =   LPTIM_CFGR2_IN1SEL_1                                    /*!< For LPTIM3 */
};
enum LPTMInput2Src
{
    LPTIM_INPUT2_SRC_GPIO     =    0x00000000U,                   /*!< For LPTIM1 */
    LPTIM_INPUT2_SRC_COMP2    =    LPTIM_CFGR2_IN2SEL_0           /*!< For LPTIM1 */
};
struct LPTIM_InitTypeDef
{
    LPTMClkFromSourceType ClockSource;
    LPTMPrescaler Prescaler;
    LPTIMOutputWaveformType Waveform;
    LPTIMOutputPolarity Polarity;
};

class LPTIMER
{
    using LPTIMInterruptCb = std::function<void(LPTIMER*, LPTIMIsrFlgas)>;
public:
    LPTIMER(LPTIM_TypeDef* timer) : timer_(timer)
    {
        enableClk();
    }
    ~LPTIMER()
    {

    }
    LPTIMER(const LPTIMER&) = delete;
    LPTIMER(LPTIMER&&) = delete;
    LPTIMER& operator=(const LPTIMER&) = delete;
    LPTIMER& operator=(LPTIMER&&) = delete;

    inline void lptimEnable()
    {
        SET_BIT(timer_->CR, LPTIM_CR_ENABLE);
    }
    inline bool lptimIsEnabled()
    {
        return (((READ_BIT(timer_->CR, LPTIM_CR_ENABLE) == LPTIM_CR_ENABLE) ? true : false));
    }
    inline void lptimStartCounter(LPTMOperatingMode OperatingMode)
    {
        MODIFY_REG(timer_->CR, LPTIM_CR_CNTSTRT | LPTIM_CR_SNGSTRT, OperatingMode);
    }
    inline void lptimEnableResetAfterRead()
    {
        SET_BIT(timer_->CR, LPTIM_CR_RSTARE);
    }
    inline void lptimDisableResetAfterRead()
    {
        CLEAR_BIT(timer_->CR, LPTIM_CR_RSTARE);
    }
    inline bool lptimIsEnabledResetAfterRead()
    {
        return (((READ_BIT(timer_->CR, LPTIM_CR_RSTARE) == LPTIM_CR_RSTARE) ? true : false));
    }
    inline void lptimResetCounter()
    {
        SET_BIT(timer_->CR, LPTIM_CR_COUNTRST);
    }
    inline void lptimSetUpdateMode(LPTMUpdateMode UpdateMode)
    {
        MODIFY_REG(timer_->CFGR, LPTIM_CFGR_PRELOAD, UpdateMode);
    }
    inline LPTMUpdateMode lptimGetUpdateMode()
    {
        return (LPTMUpdateMode)(READ_BIT(timer_->CFGR, LPTIM_CFGR_PRELOAD));
    }
    inline void lptimSetAutoReload(uint32_t AutoReload)
    {
        MODIFY_REG(timer_->ARR, LPTIM_ARR_ARR, AutoReload);
    }
    inline uint32_t lptimGetAutoReload()
    {
        return (uint32_t)(READ_BIT(timer_->ARR, LPTIM_ARR_ARR));
    }
    inline void lptimSetCompare(uint32_t CompareValue)
    {
        MODIFY_REG(timer_->CMP, LPTIM_CMP_CMP, CompareValue);
    }
    inline uint32_t lptimGetCompare()
    {
        return (uint32_t)(READ_BIT(timer_->CMP, LPTIM_CMP_CMP));
    }
    inline uint32_t lptimGetCounter()
    {
        return (uint32_t)(READ_BIT(timer_->CNT, LPTIM_CNT_CNT));
    }
    inline void lptimSetCounterMode(LPTMCounterMode CounterMode)
    {
        MODIFY_REG(timer_->CFGR, LPTIM_CFGR_COUNTMODE, CounterMode);
    }
    inline LPTMCounterMode lptimGetCounterMode()
    {
        return (LPTMCounterMode)(READ_BIT(timer_->CFGR, LPTIM_CFGR_COUNTMODE));
    }
    inline void lptimConfigOutput(LPTIMOutputWaveformType Waveform, LPTIMOutputPolarity Polarity)
    {
        MODIFY_REG(timer_->CFGR, LPTIM_CFGR_WAVE | LPTIM_CFGR_WAVPOL, Waveform | Polarity);
    }
    inline void lptimSetWaveform(LPTIMOutputWaveformType Waveform)
    {
        MODIFY_REG(timer_->CFGR, LPTIM_CFGR_WAVE, Waveform);
    }
    inline LPTIMOutputWaveformType lptimGetWaveform()
    {
        return (LPTIMOutputWaveformType)(READ_BIT(timer_->CFGR, LPTIM_CFGR_WAVE));
    }
    inline void lptimSetPolarity(LPTIMOutputPolarity Polarity)
    {
        MODIFY_REG(timer_->CFGR, LPTIM_CFGR_WAVPOL, Polarity);
    }
    inline LPTIMOutputPolarity lptimGetPolarity()
    {
        return (LPTIMOutputPolarity)(READ_BIT(timer_->CFGR, LPTIM_CFGR_WAVPOL));
    }
    inline void lptimSetPrescaler(LPTMPrescaler Prescaler)
    {
        MODIFY_REG(timer_->CFGR, LPTIM_CFGR_PRESC, Prescaler);
    }
    inline LPTMPrescaler lptimGetPrescaler()
    {
        return (LPTMPrescaler)(READ_BIT(timer_->CFGR, LPTIM_CFGR_PRESC));
    }
    inline void lptimSetInput1Src(LPTMInput1Src Src)
    {
        MODIFY_REG(timer_->CFGR2, LPTIM_CFGR2_IN1SEL, Src);
    }
    inline void lptimSetInput2Src(LPTMInput2Src Src)
    {
        MODIFY_REG(timer_->CFGR2, LPTIM_CFGR2_IN2SEL, Src);
    }
    inline void lptimEnableTimeout()
    {
        SET_BIT(timer_->CFGR, LPTIM_CFGR_TIMOUT);
    }
    inline void lptimDisableTimeout()
    {
        CLEAR_BIT(timer_->CFGR, LPTIM_CFGR_TIMOUT);
    }
    inline bool lptimIsEnabledTimeout()
    {
        return (((READ_BIT(timer_->CFGR, LPTIM_CFGR_TIMOUT) == LPTIM_CFGR_TIMOUT) ? true : false));
    }
    inline void lptimTrigSw()
    {
        CLEAR_BIT(timer_->CFGR, LPTIM_CFGR_TRIGEN);
    }
    inline void lptimConfigTrigger(LPTMTriggerSource Source, LPTMTrigFilter Filter, LPTMTrigPolarity Polarity)
    {
        MODIFY_REG(timer_->CFGR, LPTIM_CFGR_TRIGSEL | LPTIM_CFGR_TRGFLT | LPTIM_CFGR_TRIGEN, Source | Filter | Polarity);
    }
    inline LPTMTriggerSource lptimGetTriggerSource()
    {
        return (LPTMTriggerSource)(READ_BIT(timer_->CFGR, LPTIM_CFGR_TRIGSEL));
    }
    inline LPTMTrigFilter lptimGetTriggerFilter()
    {
        return (LPTMTrigFilter)(READ_BIT(timer_->CFGR, LPTIM_CFGR_TRGFLT));
    }
    inline LPTMTrigPolarity lptimGetTriggerPolarity()
    {
        return (LPTMTrigPolarity)(READ_BIT(timer_->CFGR, LPTIM_CFGR_TRIGEN));
    }
    inline void lptimSetClockedSourceType(LPTMClkFromSourceType ClockSource)
    {
        MODIFY_REG(timer_->CFGR, LPTIM_CFGR_CKSEL, ClockSource);
    }
    inline LPTMClkFromSourceType lptimGetClockedSourceType()
    {
        return (LPTMClkFromSourceType)(READ_BIT(timer_->CFGR, LPTIM_CFGR_CKSEL));
    }
    inline void lptimConfigClock(LPTMClkFilter ClockFilter, LPTMClkPolarity ClockPolarity)
    {
        MODIFY_REG(timer_->CFGR, LPTIM_CFGR_CKFLT | LPTIM_CFGR_CKPOL, ClockFilter | ClockPolarity);
    }
    inline LPTMClkPolarity lptimGetClockPolarity()
    {
        return (LPTMClkPolarity)(READ_BIT(timer_->CFGR, LPTIM_CFGR_CKPOL));
    }
    inline LPTMClkFilter lptimGetClockFilter()
    {
        return (LPTMClkFilter)(READ_BIT(timer_->CFGR, LPTIM_CFGR_CKFLT));
    }
    inline void lptimSetEncoderMode(LPTMEncoderMode EncoderMode)
    {
        MODIFY_REG(timer_->CFGR, LPTIM_CFGR_CKPOL, EncoderMode);
    }
    inline LPTMEncoderMode lptimGetEncoderMode()
    {
        return (LPTMEncoderMode)(READ_BIT(timer_->CFGR, LPTIM_CFGR_CKPOL));
    }
    inline void lptimEnableEncoderMode()
    {
        SET_BIT(timer_->CFGR, LPTIM_CFGR_ENC);
    }
    inline void lptimDisableEncoderMode()
    {
        CLEAR_BIT(timer_->CFGR, LPTIM_CFGR_ENC);
    }
    inline bool lptimIsEnabledEncoderMode()
    {
        return (((READ_BIT(timer_->CFGR, LPTIM_CFGR_ENC) == LPTIM_CFGR_ENC) ? true : false));
    }
    inline void lptimClearFlagCMPM()
    {
        SET_BIT(timer_->ICR, LPTIM_ICR_CMPMCF);
    }
    inline bool lptimIsActiveFlagCMPM()
    {
        return (((READ_BIT(timer_->ISR, LPTIM_ISR_CMPM) == LPTIM_ISR_CMPM) ? true : false));
    }
    inline void lptimClearFlagARRM()
    {
        SET_BIT(timer_->ICR, LPTIM_ICR_ARRMCF);
    }
    inline bool lptimIsActiveFlagARRM()
    {
        return (((READ_BIT(timer_->ISR, LPTIM_ISR_ARRM) == LPTIM_ISR_ARRM) ? true : false));
    }
    inline void lptimClearFlagEXTTRIG()
    {
        SET_BIT(timer_->ICR, LPTIM_ICR_EXTTRIGCF);
    }
    inline bool lptimIsActiveFlagEXTTRIG()
    {
        return (((READ_BIT(timer_->ISR, LPTIM_ISR_EXTTRIG) == LPTIM_ISR_EXTTRIG) ? true : false));
    }
    inline void lptimClearFlagCMPOK()
    {
        SET_BIT(timer_->ICR, LPTIM_ICR_CMPOKCF);
    }
    inline bool lptimIsActiveFlagCMPOK()
    {
        return (((READ_BIT(timer_->ISR, LPTIM_ISR_CMPOK) == LPTIM_ISR_CMPOK) ? true : false));
    }
    inline void lptimClearFlagARROK()
    {
        SET_BIT(timer_->ICR, LPTIM_ICR_ARROKCF);
    }
    inline bool lptimIsActiveFlagARROK()
    {
        return (((READ_BIT(timer_->ISR, LPTIM_ISR_ARROK) == LPTIM_ISR_ARROK) ? true : false));
    }
    inline void lptimClearFlagUP()
    {
        SET_BIT(timer_->ICR, LPTIM_ICR_UPCF);
    }
    inline bool lptimIsActiveFlagUP()
    {
        return (((READ_BIT(timer_->ISR, LPTIM_ISR_UP) == LPTIM_ISR_UP) ? true : false));
    }
    inline void lptimClearFlagDOWN()
    {
        SET_BIT(timer_->ICR, LPTIM_ICR_DOWNCF);
    }
    inline bool lptimIsActiveFlagDOWN()
    {
        return (((READ_BIT(timer_->ISR, LPTIM_ISR_DOWN) == LPTIM_ISR_DOWN) ? true : false));
    }
    inline void lptimEnableITCMPM()
    {
        SET_BIT(timer_->IER, LPTIM_IER_CMPMIE);
    }
    inline void lptimDisableITCMPM()
    {
        CLEAR_BIT(timer_->IER, LPTIM_IER_CMPMIE);
    }
    inline bool lptimIsEnabledITCMPM()
    {
        return (((READ_BIT(timer_->IER, LPTIM_IER_CMPMIE) == LPTIM_IER_CMPMIE) ? true : false));
    }
    inline void lptimEnableITARRM()
    {
        SET_BIT(timer_->IER, LPTIM_IER_ARRMIE);
    }
    inline void lptimDisableITARRM()
    {
        CLEAR_BIT(timer_->IER, LPTIM_IER_ARRMIE);
    }
    inline bool lptimIsEnabledITARRM()
    {
        return (((READ_BIT(timer_->IER, LPTIM_IER_ARRMIE) == LPTIM_IER_ARRMIE) ? true : false));
    }
    inline void lptimEnableITEXTTRIG()
    {
        SET_BIT(timer_->IER, LPTIM_IER_EXTTRIGIE);
    }
    inline void lptimDisableITEXTTRIG()
    {
        CLEAR_BIT(timer_->IER, LPTIM_IER_EXTTRIGIE);
    }
    inline bool lptimIsEnabledITEXTTRIG()
    {
    return (((READ_BIT(timer_->IER, LPTIM_IER_EXTTRIGIE) == LPTIM_IER_EXTTRIGIE) ? true : false));
    }
    inline void lptimEnableITCMPOK()
    {
        SET_BIT(timer_->IER, LPTIM_IER_CMPOKIE);
    }
    inline void lptimDisableITCMPOK()
    {
        CLEAR_BIT(timer_->IER, LPTIM_IER_CMPOKIE);
    }
    inline bool lptimIsEnabledITCMPOK()
    {
        return (((READ_BIT(timer_->IER, LPTIM_IER_CMPOKIE) == LPTIM_IER_CMPOKIE) ? true : false));
    }
    inline void lptimEnableITARROK()
    {
        SET_BIT(timer_->IER, LPTIM_IER_ARROKIE);
    }
    inline void lptimDisableITARROK()
    {
        CLEAR_BIT(timer_->IER, LPTIM_IER_ARROKIE);
    }
    inline bool lptimIsEnabledITARROK()
    {
        return (((READ_BIT(timer_->IER, LPTIM_IER_ARROKIE) == LPTIM_IER_ARROKIE) ? true : false));
    }
    inline void lptimEnableITUP()
    {
        SET_BIT(timer_->IER, LPTIM_IER_UPIE);
    }
    inline void lptimDisableITUP()
    {
        CLEAR_BIT(timer_->IER, LPTIM_IER_UPIE);
    }
    inline bool lptimIsEnabledITUP()
    {
        return (((READ_BIT(timer_->IER, LPTIM_IER_UPIE) == LPTIM_IER_UPIE) ? true : false));
    }
    inline void lptimEnableITDOWN()
    {
        SET_BIT(timer_->IER, LPTIM_IER_DOWNIE);
    }
    inline void lptimDisableITDOWN()
    {
        CLEAR_BIT(timer_->IER, LPTIM_IER_DOWNIE);
    }
    inline bool lptimIsEnabledITDOWN()
    {
        return ((READ_BIT(timer_->IER, LPTIM_IER_DOWNIE) == LPTIM_IER_DOWNIE) ? true : false);
    }
    void lptimDeInit()
    {
        if (timer_ == LPTIM1)
        {
            RCCControl::getInstance()->APB1GRP1ForceReset(RCC_APB1_GRP1_PERIPH_LPTIM1);
            RCCControl::getInstance()->APB1GRP1ReleaseReset(RCC_APB1_GRP1_PERIPH_LPTIM1);
        }
        else if (timer_ == LPTIM2)
        {
            RCCControl::getInstance()->APB4GRP1ForceReset(RCC_APB4_GRP1_PERIPH_LPTIM2);
            RCCControl::getInstance()->APB4GRP1ReleaseReset(RCC_APB4_GRP1_PERIPH_LPTIM2);
        }
        else if (timer_ == LPTIM3)
        {
            RCCControl::getInstance()->APB4GRP1ForceReset(RCC_APB4_GRP1_PERIPH_LPTIM3);
            RCCControl::getInstance()->APB4GRP1ReleaseReset(RCC_APB4_GRP1_PERIPH_LPTIM3);
        }
        else if (timer_ == LPTIM4)
        {
            RCCControl::getInstance()->APB4GRP1ForceReset(RCC_APB4_GRP1_PERIPH_LPTIM4);
            RCCControl::getInstance()->APB4GRP1ReleaseReset(RCC_APB4_GRP1_PERIPH_LPTIM4);
        }
        else if (timer_ == LPTIM5)
        {
            RCCControl::getInstance()->APB4GRP1ForceReset(RCC_APB4_GRP1_PERIPH_LPTIM5);
            RCCControl::getInstance()->APB4GRP1ReleaseReset(RCC_APB4_GRP1_PERIPH_LPTIM5);
        }
    }
    eResult lptimInit(LPTMClkFromSourceType ClockSource, LPTMPrescaler Prescaler)
    {
        eResult result = E_RESULT_OK;
        /* The LPTIMx_CFGR register must only be modified when the LPTIM is disabled
            (ENABLE bit is reset to 0).
        */
        if (lptimIsEnabled())
        {
            result = E_RESULT_WRONG_STATUS;
        }
        else
        {
            lptimDisable();
            /* Set CKSEL bitfield according to ClockSource value */
            /* Set PRESC bitfield according to Prescaler value */
            /* Set WAVE bitfield according to Waveform value */
            /* Set WAVEPOL bitfield according to Polarity value */
            MODIFY_REG(timer_->CFGR,
                    (LPTIM_CFGR_CKSEL | LPTIM_CFGR_PRESC), ClockSource | Prescaler);
            registerLPTimIsrCb(timer_,[](void* param, LPTIMIsrFlgas flags){
                LPTIMER* pltim = reinterpret_cast<LPTIMER*>(param);
                if(pltim)
                {
                    if(pltim->timcb_)
                    {
                        pltim->timcb_(pltim, flags);
                    }
                }
            } ,this);
        }
        return result;
    }
    void lptimDisable()
    {
        uint32_t sysclkFreq = RCCControl::getInstance()->GetSystemClockFreq();
        RCCLPTIMxClkSource tmpclksource;
        uint32_t tmpIER;
        uint32_t tmpCFGR;
        uint32_t tmpCMP;
        uint32_t tmpARR;
        uint32_t primask_bit;
        uint32_t tmpCFGR2;

        /* Enter critical section */
        primask_bit = __get_PRIMASK();
        __set_PRIMASK(1) ;

        /********** Save LPTIM Config *********/
        /* Save LPTIM source clock */
        switch ((uint32_t)timer_)
        {
            case LPTIM1_BASE:
            tmpclksource = RCCControl::getInstance()->GetLPTIMClockSource(RCC_LPTIM1_CLKSOURCE);
            break;
            case LPTIM2_BASE:
            tmpclksource = RCCControl::getInstance()->GetLPTIMClockSource(RCC_LPTIM2_CLKSOURCE);
            break;
        #if defined(LPTIM3)&&defined(LPTIM4)&&defined(LPTIM5)
            case LPTIM3_BASE:
            case LPTIM4_BASE:
            case LPTIM5_BASE:
            tmpclksource = RCCControl::getInstance()->GetLPTIMClockSource(RCC_LPTIM345_CLKSOURCE);
            break;
        #elif defined(LPTIM3)
            case LPTIM3_BASE:
            tmpclksource = RCCControl::getInstance()->GetLPTIMClockSource(RCC_LPTIM3_CLKSOURCE);
            break;
        #endif /* LPTIM3 && LPTIM4 && LPTIM5 */
            default:
            tmpclksource = RCCControl::getInstance()->GetLPTIMClockSource(RCC_LPTIM1_CLKSOURCE);
            break;
        }

        /* Save LPTIM configuration registers */
        tmpIER = timer_->IER;
        tmpCFGR = timer_->CFGR;
        tmpCMP = timer_->CMP;
        tmpARR = timer_->ARR;
        tmpCFGR2 = timer_->CFGR2;

        /************* Reset LPTIM ************/
        lptimDeInit();

        if ((tmpCMP != 0UL) || (tmpARR != 0UL))
        {
            /* Force LPTIM source kernel clock from APB */
            switch ((uint32_t)timer_)
            {
            case LPTIM1_BASE:
                RCCControl::getInstance()->SetLPTIMClockSource(RCC_LPTIM1_CLKSOURCE_PCLK1);
                break;
            case LPTIM2_BASE:
                RCCControl::getInstance()->SetLPTIMClockSource(RCC_LPTIM2_CLKSOURCE_PCLK4);
                break;
        #if defined(LPTIM3)&&defined(LPTIM4)&&defined(LPTIM5)
            case LPTIM3_BASE:
            case LPTIM4_BASE:
            case LPTIM5_BASE:
                RCCControl::getInstance()->SetLPTIMClockSource(RCC_LPTIM345_CLKSOURCE_PCLK4);
                break;
        #elif defined(LPTIM3)
            case LPTIM3_BASE:
                RCCControl::getInstance()->SetLPTIMClockSource(RCC_LPTIM3_CLKSOURCE_PCLK4);
                break;
        #endif /* LPTIM3 && LPTIM4 && LPTIM5*/
            default:
                break;
            }

            if (tmpCMP != 0UL)
            {
                /* Restore CMP and ARR registers (LPTIM should be enabled first) */
                timer_->CR |= LPTIM_CR_ENABLE;
                timer_->CMP = tmpCMP;

                /* Polling on CMP write ok status after above restore operation */
                do
                {
                    sysclkFreq--; /* Used for timeout */
                } while (((lptimIsActiveFlagCMPOK() != 1UL)) && ((sysclkFreq) > 0UL));

                lptimClearFlagCMPOK();
            }

            if (tmpARR != 0UL)
            {
                timer_->CR |= LPTIM_CR_ENABLE;
                timer_->ARR = tmpARR;

                sysclkFreq = RCCControl::getInstance()->GetSystemClockFreq();
                /* Polling on ARR write ok status after above restore operation */
                do
                {
                    sysclkFreq--; /* Used for timeout */
                } while (((lptimIsActiveFlagARROK() != 1UL)) && ((sysclkFreq) > 0UL));

                lptimClearFlagARROK();
            }


            /* Restore LPTIM source kernel clock */
            RCCControl::getInstance()->SetLPTIMClockSource(tmpclksource);
        }

        /* Restore configuration registers (LPTIM should be disabled first) */
        timer_->CR &= ~(LPTIM_CR_ENABLE);
        timer_->IER = tmpIER;
        timer_->CFGR = tmpCFGR;
        timer_->CFGR2 = tmpCFGR2;

        /* Exit critical section: restore previous priority mask */
        __set_PRIMASK(primask_bit);
    }
    // LSE = 32768Hz
    // 分频设置为 LPTIM_PRESCALER_DIV1，即未分频
    // ARR 自动重载寄存器 = 31
    // 那么 PWM 频率 = LSE / （ ARR + 1） = 32768Hz / (31 + 1) = 1024Hz
    // 占空比 = 1 - (Comprare + 1)/ (ARR + 1)
    // = 1 - (15 + 1)/(31 + 1)
    // = 50%
    void lptimCountStart(uint32_t Period)
    {
        /* If clock source is not ULPTIM clock and counter source is external, then it must not be prescaled */
        if(lptimGetClockedSourceType() != LPTIM_CLK_SOURCE_EXTERNAL && lptimGetCounterMode() == LPTIM_COUNTER_MODE_EXTERNAL)
        {
            lptimSetPrescaler(LPTIM_PRESCALER_DIV1);
        }
        lptimEnable();
        lptimClearFlagARROK();
        lptimSetAutoReload(Period);
        lptimStartCounter(LPTIM_OPERATING_MODE_CONTINUOUS);
    }
    void lptimCountStop()
    {
        lptimDisable();
    }
    eResult lptimTimeoutStart(uint32_t Period, uint32_t Timeout)
    {
        if(lptimIsEnabled())
        {
            return E_RESULT_WRONG_STATUS;
        }
        lptimEnableTimeout();
        lptimEnable();
        lptimClearFlagARROK();
        lptimSetAutoReload(Period);
        lptimClearFlagCMPOK();
        lptimSetCompare(Timeout);
        lptimStartCounter(LPTIM_OPERATING_MODE_CONTINUOUS);
        return E_RESULT_OK;
    }
    eResult lptimTimeoutStop()
    {
        if(!lptimIsEnabled())
        {
            return E_RESULT_WRONG_STATUS;
        }
        lptimDisable();
        lptimDisableTimeout();
        return E_RESULT_OK;
    }
    eResult lptimPwmStart(uint32_t period, uint32_t pulse, LPTIMOutputPolarity outputPolarity = LPTIM_OUTPUT_POLARITY_REGULAR)
    {
        if(lptimIsEnabled())
        {
            return E_RESULT_WRONG_STATUS;
        }
        /* Reset WAVE bit to set PWM mode */
        lptimSetWaveform(LPTIM_OUTPUT_WAVEFORM_PWM);
        lptimSetPolarity(outputPolarity);
        /* Enable the Peripheral */
        lptimEnable();

        /* Clear flag */
        lptimClearFlagARROK();

        /* Load the period value in the autoreload register */
        lptimSetAutoReload(period);

        /* Clear flag */
        lptimClearFlagCMPOK();

        /* Load the pulse value in the compare register */
        lptimSetCompare(pulse);

        /* Start timer in continuous mode */
        lptimStartCounter(LPTIM_OPERATING_MODE_CONTINUOUS);
        return E_RESULT_OK;
    }
    eResult lptimPwmStop()
    {
        if(!lptimIsEnabled())
        {
            return E_RESULT_WRONG_STATUS;
        }
        /* Disable the Peripheral */
        lptimDisable();

        return E_RESULT_OK;
    }
    eResult lptimOnePulseStart(uint32_t period, uint32_t pulse, LPTIMOutputPolarity outputPolarity = LPTIM_OUTPUT_POLARITY_REGULAR)
    {
        if(lptimIsEnabled())
        {
            return E_RESULT_WRONG_STATUS;
        }

        /* Reset WAVE bit to set one pulse mode */
        lptimSetWaveform(LPTIM_OUTPUT_WAVEFORM_PWM);
        lptimSetPolarity(outputPolarity);
        /* Enable the Peripheral */
        lptimEnable();

        /* Clear flag */
        lptimClearFlagARROK();

        /* Load the period value in the autoreload register */
        lptimSetAutoReload(period);

        /* Clear flag */
        lptimClearFlagCMPOK();

        /* Load the pulse value in the compare register */
        lptimSetCompare(pulse);

        /* Start timer in single (one shot) mode */
        lptimStartCounter(LPTIM_OPERATING_MODE_ONESHOT);

        /* Return function status */
        return E_RESULT_OK;
    }

    eResult lptimOnePulseStop()
    {
        if(!lptimIsEnabled())
        {
            return E_RESULT_WRONG_STATUS;
        }
        /* Disable the Peripheral */
        lptimDisable();
        return E_RESULT_OK;
    }
    eResult lptimEncoderStart(uint32_t period, LPTMEncoderMode encodeModePolarity = LPTIM_ENCODER_MODE_RISING)
    {
        if(lptimIsEnabled())
        {
            return E_RESULT_WRONG_STATUS;
        }

        /* Check the parameters */
        CHECK_RETURN(lptimGetClockedSourceType() == LPTIM_CLK_SOURCE_INTERNAL, E_RESULT_INVALID_PARAM);
        CHECK_RETURN(lptimGetPrescaler() == LPTIM_PRESCALER_DIV1, E_RESULT_INVALID_PARAM);

        /* Set Input polarity */
        lptimSetEncoderMode(encodeModePolarity);

        /* Set ENC bit to enable the encoder interface */
        lptimEnableEncoderMode();

        /* Enable the Peripheral */
        lptimEnable();

        /* Clear flag */
        lptimClearFlagARROK();

        /* Load the period value in the autoreload register */
        lptimSetAutoReload(period);

        /* Start timer in continuous mode */
        lptimStartCounter(LPTIM_OPERATING_MODE_CONTINUOUS);

        /* Return function status */
        return E_RESULT_OK;
    }
    eResult lptimEncoderStop()
    {
        if(!lptimIsEnabled())
        {
            return E_RESULT_WRONG_STATUS;
        }
        /* Disable the Peripheral */
        lptimDisable();

        /* Reset ENC bit to disable the encoder interface */
        lptimDisableEncoderMode();

        /* Return function status */
        return E_RESULT_OK;
    }
    uint32_t lptimReadCounter()
    {
        return lptimGetCounter();
    }
    uint32_t lptimReadAutoReload()
    {
        return lptimGetAutoReload();
    }
    uint32_t lptimReadCompare()
    {
        return lptimGetCompare();
    }
    void enableLPTIMIsr(uint32_t PreemptPriority, uint32_t SubPriority)
    {
        if(NVIC_GetEnableIRQ(getIrqType()) == 0U)
        {
            NVIC_SetPriority(getIrqType(), NVIC_EncodePriority(NVIC_GetPriorityGrouping(), PreemptPriority, SubPriority));
            NVIC_EnableIRQ(getIrqType());
        }
    }
    void disableLPTIMIsr()
    {
        NVIC_DisableIRQ(getIrqType());
    }
    void registerInterruptCb(const LPTIMInterruptCb& isrcb)
    {
        timcb_ = isrcb;
    }
    void unregisterInterruptCb()
    {
        if(timcb_)
        {
            timcb_ = LPTIMInterruptCb();
        }
    }
    RCCLPTIMxClkSource getClockSource()
    {
        RCCLPTIMxClkSource source = RCC_LPTIMX_CLOCK_SOURCE_NONE;
        switch (reinterpret_cast<uint32_t>(timer_))
        {
            case LPTIM1_BASE:
                source = RCCControl::getInstance()->GetLPTIMClockSource(RCC_LPTIM1_CLKSOURCE);
                break;
            case LPTIM2_BASE:
                source = RCCControl::getInstance()->GetLPTIMClockSource(RCC_LPTIM2_CLKSOURCE);
                break;
            case LPTIM3_BASE:
            case LPTIM4_BASE:
            case LPTIM5_BASE:
                source = RCCControl::getInstance()->GetLPTIMClockSource(RCC_LPTIM345_CLKSOURCE);
                break;
            default:
                break;
        }
        return source;
    }
private:
    void enableClk(bool bEnable = true)
    {
        RCCControl* rcc = RCCControl::getInstance();
        switch (reinterpret_cast<uint32_t>(timer_))
        {
            case LPTIM1_BASE:
                rcc->APB1GRP1EnableClock(RCC_APB1_GRP1_PERIPH_LPTIM1);
                break;
            case LPTIM2_BASE:
                rcc->APB4GRP1EnableClock(RCC_APB4_GRP1_PERIPH_LPTIM2);
                break;
            case LPTIM3_BASE:
                rcc->APB4GRP1EnableClock(RCC_APB4_GRP1_PERIPH_LPTIM3);
                break;
            case LPTIM4_BASE:
                rcc->APB4GRP1EnableClock(RCC_APB4_GRP1_PERIPH_LPTIM4);
                break;
            case LPTIM5_BASE:
                rcc->APB4GRP1EnableClock(RCC_APB4_GRP1_PERIPH_LPTIM5);
                break;
            default:
                break;
        }
    }
    IRQn_Type getIrqType()
    {
        IRQn_Type type = LPTIM1_IRQn;
        switch (reinterpret_cast<uint32_t>(timer_))
        {
            case LPTIM1_BASE:
                type = LPTIM1_IRQn;
                break;
            case LPTIM2_BASE:
                type = LPTIM2_IRQn;
                break;
            case LPTIM3_BASE:
                type = LPTIM3_IRQn;
                break;
            case LPTIM4_BASE:
                type = LPTIM4_IRQn;
                break;
            case LPTIM5_BASE:
                type = LPTIM5_IRQn;
                break;
            default:
                break;
        }
        return type;
    }
private:
    LPTIM_TypeDef* timer_;
    //LPTIM_InitTypeDef* lptimx_;
    LPTIMInterruptCb timcb_;
};
