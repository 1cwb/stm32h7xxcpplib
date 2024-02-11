#pragma once
#include "common.hpp"

/** @defgroup PWR_LL_WAKEUP_PIN_OFFSET Wake-Up Pins register offsets Defines
  * @brief    Flags defines which can be used with PWR_WriteReg function
  * @{
  */
/* Wake-Up Pins PWR register offsets */
enum PWRWakeUpPinsRegOffset
{
    PWR_WAKEUP_PINS_PULL_SHIFT_OFFSET  =  2UL,
    PWR_WAKEUP_PINS_MAX_SHIFT_MASK     =  0x1FU
};
/**
  * @}
  */
/* Private macros ------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/** @defgroup PWR_LL_Exported_Constants PWR Exported Constants
  * @{
  */

/** @defgroup PWR_LL_EC_CLEAR_FLAG Clear Flags Defines
  * @brief    Flags defines which can be used with PWR_WriteReg function
  * @{
  */
enum PWRClearFlags
{
    PWR_FLAG_CPU_CSSF        =  PWR_CPUCR_CSSF,      /*!< Clear flags for CPU  */
#if defined (DUAL_CORE)
    PWR_FLAG_CPU2_CSSF       =  PWR_CPU2CR_CSSF,     /*!< Clear flags for CPU2 */
#endif /* DUAL_CORE */
    PWR_FLAG_WKUPCR_WKUPC6   =  PWR_WKUPCR_WKUPC6,   /*!< Clear PC1 WKUP flag  */
#if defined (PWR_WKUPCR_WKUPC5)
    PWR_FLAG_WKUPCR_WKUPC5   =  PWR_WKUPCR_WKUPC5,   /*!< Clear PI11 WKUP flag */
#endif /* defined (PWR_WKUPCR_WKUPC5) */
    PWR_FLAG_WKUPCR_WKUPC4   =  PWR_WKUPCR_WKUPC4,   /*!< Clear PC13 WKUP flag */
#if defined (PWR_WKUPCR_WKUPC3)
    PWR_FLAG_WKUPCR_WKUPC3   =  PWR_WKUPCR_WKUPC3,   /*!< Clear PI8 WKUP flag  */
#endif /* defined (PWR_WKUPCR_WKUPC3) */
    PWR_FLAG_WKUPCR_WKUPC2   =  PWR_WKUPCR_WKUPC2,   /*!< Clear PA2 WKUP flag  */
    PWR_FLAG_WKUPCR_WKUPC1   =  PWR_WKUPCR_WKUPC1    /*!< Clear PA0 WKUP flag  */
};

/** @defgroup PWR_LL_EC_GET_FLAG Get Flags Defines
  * @brief    Flags defines which can be used with PWR_ReadReg function
  * @{
  */
enum PWRGetFlags
{
    PWR_FLAG_AVDO                 =    PWR_CSR1_AVDO,       /*!< Analog voltage detector output on VDDA flag                          */
    PWR_FLAG_PVDO                 =    PWR_CSR1_PVDO,       /*!< Programmable voltage detect output flag                              */
    PWR_FLAG_ACTVOS               =    PWR_CSR1_ACTVOS,     /*!< Current VOS applied for VCORE voltage scaling flag                   */
    PWR_FLAG_ACTVOSRDY            =    PWR_CSR1_ACTVOSRDY,  /*!< Ready bit for current actual used VOS for VCORE voltage scaling flag */
#if defined (PWR_CSR1_MMCVDO)
    PWR_FLAG_MMCVDO               =    PWR_CSR1_MMCVDO,     /*!< Voltage detector output on VDDMMC flag                               */
#endif /* PWR_CSR1_MMCVDO */

    PWR_FLAG_TEMPH                =    PWR_CR2_TEMPH,       /*!< Temperature high threshold flag */
    PWR_FLAG_TEMPL                =    PWR_CR2_TEMPL,       /*!< Temperature low threshold flag  */
    PWR_FLAG_VBATH                =    PWR_CR2_VBATH,       /*!< VBAT high threshold flag        */
    PWR_FLAG_VBATL                =    PWR_CR2_VBATL,       /*!< VBAT low threshold flag         */
    PWR_FLAG_BRRDY                =    PWR_CR2_BRRDY,       /*!< Backup Regulator ready flag     */

    PWR_FLAG_USBRDY               =    PWR_CR3_USB33RDY,    /*!< USB supply ready flag           */
#if defined (PWR_CR3_SMPSEXTRDY)
    PWR_FLAG_SMPSEXTRDY           =    PWR_CR3_SMPSEXTRDY,  /*!< SMPS External supply ready flag */
#endif

#if defined (PWR_CPUCR_SBF_D2)        
    PWR_FLAG_CPU_SBF_D2           =    PWR_CPUCR_SBF_D2,    /*!< D2 domain DSTANDBY Flag  */
#endif /* PWR_CPUCR_SBF_D2 */
#if defined (PWR_CPUCR_SBF_D1)       
    PWR_FLAG_CPU_SBF_D1           =    PWR_CPUCR_SBF_D1,    /*!< D1 domain DSTANDBY Flag  */
#endif /* PWR_CPUCR_SBF_D1 */
    PWR_FLAG_CPU_SBF              =    PWR_CPUCR_SBF,       /*!< System STANDBY Flag      */
    PWR_FLAG_CPU_STOPF            =    PWR_CPUCR_STOPF,     /*!< STOP Flag                */
#if defined (DUAL_CORE)
    PWR_FLAG_CPU_HOLD2F           =    PWR_CPUCR_HOLD2F,    /*!< CPU2 in hold wakeup flag */
#endif /* DUAL_CORE */

#if defined (DUAL_CORE)
    PWR_FLAG_CPU2_SBF_D2          =    PWR_CPU2CR_SBF_D2,   /*!< D2 domain DSTANDBY Flag  */
    PWR_FLAG_CPU2_SBF_D1          =    PWR_CPU2CR_SBF_D1,   /*!< D1 domain DSTANDBY Flag  */
    PWR_FLAG_CPU2_SBF             =    PWR_CPU2CR_SBF,      /*!< System STANDBY Flag      */
    PWR_FLAG_CPU2_STOPF           =    PWR_CPU2CR_STOPF,    /*!< STOP Flag                */
    PWR_FLAG_CPU2_HOLD1F          =    PWR_CPU2CR_HOLD1F,   /*!< CPU1 in hold wakeup flag */
#endif /* DUAL_CORE */

#if defined (PWR_CPUCR_PDDS_D2)
    PWR_D3CR_VOSRDYF               =    PWR_D3CR_VOSRDY,     /*!< Voltage scaling ready flag */
#else
    PWR_SRDCR_VOSRDYF              =    PWR_SRDCR_VOSRDY,   /*!< Voltage scaling ready flag */
#endif /* PWR_CPUCR_PDDS_D2 */

    PWR_WKUPFR_WKUPF6F             =    PWR_WKUPFR_WKUPF6,  /*!< Wakeup flag on PC1  */
#if defined (PWR_WKUPFR_WKUPF5)
    PWR_WKUPFR_WKUPF5F             =    PWR_WKUPFR_WKUPF5,  /*!< Wakeup flag on PI11 */
#endif /* defined (PWR_WKUPFR_WKUPF5) */
    PWR_WKUPFR_WKUPF4F             =    PWR_WKUPFR_WKUPF4,  /*!< Wakeup flag on PC13 */
#if defined (PWR_WKUPFR_WKUPF3)
    PWR_WKUPFR_WKUPF3F             =    PWR_WKUPFR_WKUPF3,  /*!< Wakeup flag on PI8  */
#endif /* defined (PWR_WKUPFR_WKUPF3) */
    PWR_WKUPFR_WKUPF2F             =    PWR_WKUPFR_WKUPF2,  /*!< Wakeup flag on PA2  */
    PWR_WKUPFR_WKUPF1F             =    PWR_WKUPFR_WKUPF1,  /*!< Wakeup flag on PA0  */
};

/** @defgroup PWR_LL_EC_MODE_PWR Power mode
  * @{
  */
enum PWRD1CPUMode
{
#if defined (PWR_CPUCR_PDDS_D2)
    PWR_CPU_MODE_D1STOP      =  0x00000000U,           /*!< Enter D1 domain to Stop mode when the CPU enters deepsleep       */
    PWR_CPU_MODE_D1STANDBY   =  PWR_CPUCR_PDDS_D1,     /*!< Enter D1 domain to Standby mode when the CPU enters deepsleep    */
#else
    PWR_CPU_MODE_CDSTOP      =  0x00000000U,           /*!< Enter CD domain to Stop mode when the CPU enters deepsleep       */
    PWR_CPU_MODE_CDSTOP2     =  PWR_CPUCR_RETDS_CD,    /*!< Enter CD domain to Stop2 mode when the CPU enters deepsleep      */
#endif /* PWR_CPUCR_PDDS_D2 */
};
enum PWRD2CPUMode
{
#if defined (PWR_CPUCR_PDDS_D2)
    PWR_CPU_MODE_D2STOP      =  0x00000000U,           /*!< Enter D2 domain to Stop mode when the CPU enters deepsleep       */
    PWR_CPU_MODE_D2STANDBY   =  PWR_CPUCR_PDDS_D2,     /*!< Enter D2 domain to Standby mode when the CPU enters deepsleep    */
#endif /* PWR_CPUCR_PDDS_D2 */
};

enum PWRD3CPUMode
{
#if defined (PWR_CPUCR_PDDS_D2)
    PWR_CPU_MODE_D3RUN       =  PWR_CPUCR_RUN_D3,      /*!< Keep system D3 domain in Run mode when the CPU enter deepsleep   */
    PWR_CPU_MODE_D3STOP      =  0x00000000U,           /*!< Enter D3 domain to Stop mode when the CPU enters deepsleep       */
    PWR_CPU_MODE_D3STANDBY   =  PWR_CPUCR_PDDS_D3,     /*!< Enter D3 domain to Standby mode when the CPU enters deepsleep    */
#else
    PWR_CPU_MODE_SRDRUN      =  PWR_CPUCR_RUN_SRD,     /*!< Keep system SRD domain in Run mode when the CPU enter deepsleep  */
    PWR_CPU_MODE_SRDSTOP     =  0x00000000U,           /*!< Enter SRD domain to Stop mode when the CPU enters deepsleep      */
    PWR_CPU_MODE_SRDSTANDBY  =  PWR_CPUCR_PDDS_SRD,    /*!< Enter SRD domain to Standby mode when the CPU enters deepsleep   */
#endif /* PWR_CPUCR_PDDS_D2 */
};
#if defined (DUAL_CORE)
enum PWRCPU2D1Mode
{
    PWR_CPU2_MODE_D1STOP     =  0x00000000U,           /*!< Enter D1 domain to Stop mode when the CPU2 enters deepsleep      */
    PWR_CPU2_MODE_D1STANDBY  =  PWR_CPU2CR_PDDS_D1,    /*!< Enter D1 domain to Standby mode when the CPU2 enters deepsleep   */
};
enum PWRCPU2D2Mode
{
    PWR_CPU2_MODE_D2STOP     =  0x00000000U,           /*!< Enter D2 domain to Stop mode when the CPU2 enters deepsleep      */
    PWR_CPU2_MODE_D2STANDBY  =  PWR_CPU2CR_PDDS_D2,    /*!< Enter D2 domain to Standby mode when the CPU2 enters deepsleep   */
};

enum PWRCPU2D3Mode
{
    PWR_CPU2_MODE_D3RUN      =  PWR_CPU2CR_RUN_D3,     /*!< Keep system D3 domain in RUN mode when the CPU2 enter deepsleep  */
    PWR_CPU2_MODE_D3STOP     =  0x00000000U,           /*!< Enter D3 domain to Stop mode when the CPU2 enters deepsleep      */
    PWR_CPU2_MODE_D3STANDBY  =  PWR_CPU2CR_PDDS_D3,    /*!< Enter D3 domain to Standby mode when the CPU2 enter deepsleep    */
};
#endif /* DUAL_CORE */
/** @defgroup PWR_LL_EC_REGU_VOLTAGE Run mode Regulator Voltage Scaling
  * @{
  */
enum PWRREGUVoltageRunModeScaling
{
#if defined (PWR_CPUCR_PDDS_D2)
    PWR_REGU_VOLTAGE_SCALE3   =   PWR_D3CR_VOS_0,                    /*!< Select voltage scale 3 */
    PWR_REGU_VOLTAGE_SCALE2   =   PWR_D3CR_VOS_1,                    /*!< Select voltage scale 2 */
    PWR_REGU_VOLTAGE_SCALE1   =   (PWR_D3CR_VOS_0 | PWR_D3CR_VOS_1), /*!< Select voltage scale 1 */
#if defined (SYSCFG_PWRCR_ODEN) /* STM32H74xxx and STM32H75xxx lines */
    PWR_REGU_VOLTAGE_SCALE0   =   (PWR_D3CR_VOS_0 | PWR_D3CR_VOS_1), /*!< Select voltage scale 0 */
#else
    PWR_REGU_VOLTAGE_SCALE0   =   0x00000000U,                       /*!< Select voltage scale 0 */
#endif /* defined (SYSCFG_PWRCR_ODEN) */
#else
    PWR_REGU_VOLTAGE_SCALE3   =   0x00000000U,                       /*!< Select voltage scale 3 */
    PWR_REGU_VOLTAGE_SCALE2   =   PWR_D3CR_VOS_0,                    /*!< Select voltage scale 2 */
    PWR_REGU_VOLTAGE_SCALE1   =   PWR_D3CR_VOS_1,                    /*!< Select voltage scale 1 */
    PWR_REGU_VOLTAGE_SCALE0   =   (PWR_D3CR_VOS_0 | PWR_D3CR_VOS_1), /*!< Select voltage scale 0 */
#endif /* PWR_CPUCR_PDDS_D2 */
};

/** @defgroup PWR_LL_EC_STOP_MODE_REGU_VOLTAGE Stop mode Regulator Voltage Scaling
  * @{
  */
enum PWRREGUVoltageStopModeScaling
{
    PWR_REGU_VOLTAGE_SVOS_SCALE5  =  PWR_CR1_SVOS_0,                    /*!< Select voltage scale 5 when system enters STOP mode */
    PWR_REGU_VOLTAGE_SVOS_SCALE4  =  PWR_CR1_SVOS_1,                    /*!< Select voltage scale 4 when system enters STOP mode */
    PWR_REGU_VOLTAGE_SVOS_SCALE3  =  (PWR_CR1_SVOS_0 | PWR_CR1_SVOS_1), /*!< Select voltage scale 3 when system enters STOP mode */
};

/** @defgroup PWR_LL_EC_REGU_MODE_DS_MODE  Regulator Mode In Deep Sleep Mode
  * @{
  */
enum PWRREGUDeepSleepMode
{
    PWR_REGU_DSMODE_MAIN        =   0x00000000U,   /*!< Voltage Regulator in main mode during deepsleep mode      */
    PWR_REGU_DSMODE_LOW_POWER   =   PWR_CR1_LPDS,  /*!< Voltage Regulator in low-power mode during deepsleep mode */
};

/** @defgroup PWR_LL_EC_PVDLEVEL Power Digital Voltage Level Detector
  * @{
  */
enum PWRPVDLevel
{
    PWR_PVDLEVEL_0  =  PWR_CR1_PLS_LEV0,  /*!< Voltage threshold detected by PVD 1.95 V */
    PWR_PVDLEVEL_1  =  PWR_CR1_PLS_LEV1,  /*!< Voltage threshold detected by PVD 2.1 V  */
    PWR_PVDLEVEL_2  =  PWR_CR1_PLS_LEV2,  /*!< Voltage threshold detected by PVD 2.25 V */
    PWR_PVDLEVEL_3  =  PWR_CR1_PLS_LEV3,  /*!< Voltage threshold detected by PVD 2.4 V  */
    PWR_PVDLEVEL_4  =  PWR_CR1_PLS_LEV4,  /*!< Voltage threshold detected by PVD 2.55 V */
    PWR_PVDLEVEL_5  =  PWR_CR1_PLS_LEV5,  /*!< Voltage threshold detected by PVD 2.7 V  */
    PWR_PVDLEVEL_6  =  PWR_CR1_PLS_LEV6,  /*!< Voltage threshold detected by PVD 2.85 V */
    PWR_PVDLEVEL_7  =  PWR_CR1_PLS_LEV7,  /*!< External voltage level on PVD_IN pin, compared to internal VREFINT level. */
};

/** @defgroup PWR_LL_EC_AVDLEVEL Power Analog Voltage Level Detector
  * @{
  */
enum PWRAVDLevel
{
    PWR_AVDLEVEL_0  =   PWR_CR1_ALS_LEV0,  /*!< Analog Voltage threshold detected by AVD 1.7 V */
    PWR_AVDLEVEL_1  =   PWR_CR1_ALS_LEV1,  /*!< Analog Voltage threshold detected by AVD 2.1 V */
    PWR_AVDLEVEL_2  =   PWR_CR1_ALS_LEV2,  /*!< Analog Voltage threshold detected by AVD 2.5 V */
    PWR_AVDLEVEL_3  =   PWR_CR1_ALS_LEV3,  /*!< Analog Voltage threshold detected by AVD 2.8 V */
};

/** @defgroup PWR_LL_EC_BATT_CHARG_RESISTOR Battery Charge Resistor
  * @{
  */
enum PWRBATTChangeResistor
{
    PWR_BATT_CHARG_RESISTOR_5K   =  0x00000000U,   /*!< Charge the Battery through a 5 kO resistor    */
    PWR_BATT_CHARGRESISTOR_1_5K  =  PWR_CR3_VBRS,  /*!< Charge the Battery through a 1.5 kO resistor  */
};

/** @defgroup PWR_LL_EC_WAKEUP_PIN  Wakeup Pins
  * @{
  */
enum PWRWakeUpPins
{
    PWR_WAKEUP_PIN1  =  PWR_WKUPEPR_WKUPEN1,  /*!< Wake-Up pin 1 : PA0  */
    PWR_WAKEUP_PIN2  =  PWR_WKUPEPR_WKUPEN2,  /*!< Wake-Up pin 2 : PA2  */
#if defined (PWR_WKUPEPR_WKUPEN3)
    PWR_WAKEUP_PIN3  =  PWR_WKUPEPR_WKUPEN3,  /*!< Wake-Up pin 3 : PI8  */
#endif /* defined (PWR_WKUPEPR_WKUPEN3) */
    PWR_WAKEUP_PIN4  =  PWR_WKUPEPR_WKUPEN4,  /*!< Wake-Up pin 4 : PC13 */
#if defined (PWR_WKUPEPR_WKUPEN5)
    PWR_WAKEUP_PIN5  =  PWR_WKUPEPR_WKUPEN5,  /*!< Wake-Up pin 5 : PI11 */
#endif /* defined (PWR_WKUPEPR_WKUPEN5) */
    PWR_WAKEUP_PIN6  =  PWR_WKUPEPR_WKUPEN6,  /*!< Wake-Up pin 6 : PC1  */
};

/** @defgroup PWR_LL_EC_WAKEUP_PIN_PULL  Wakeup Pins pull configuration
  * @{
  */
enum PWRWakeUpPinPull
{
    PWR_WAKEUP_PIN_NOPULL   =   0x00000000UL,   /*!< Configure Wake-Up pin in no pull   */
    PWR_WAKEUP_PIN_PULLUP   =   0x00000001UL,   /*!< Configure Wake-Up pin in pull Up   */
    PWR_WAKEUP_PIN_PULLDOWN =   0x00000002UL,   /*!< Configure Wake-Up pin in pull Down */
};

/** @defgroup PWR_LL_EC_SUPPLY_PWR Power supply source configuration
  * @{
  */
enum PWRPowerSupplySource
{
    PWR_LDO_SUPPLY                    = PWR_CR3_LDOEN,                                                               /*!< Core domains are supplied from the LDO                                                                     */
#if defined (SMPS)
    PWR_DIRECT_SMPS_SUPPLY            = PWR_CR3_SMPSEN                                                              /*!< Core domains are supplied from the SMPS                                                                    */
    PWR_SMPS_1V8_SUPPLIES_LDO         = (PWR_CR3_SMPSLEVEL_0 | PWR_CR3_SMPSEN | PWR_CR3_LDOEN),                      /*!< The SMPS 1.8V output supplies the LDO which supplies the Core domains                                       */
    PWR_SMPS_2V5_SUPPLIES_LDO         = (PWR_CR3_SMPSLEVEL_1 | PWR_CR3_SMPSEN | PWR_CR3_LDOEN),                      /*!< The SMPS 2.5V output supplies the LDO which supplies the Core domains                                       */
    PWR_SMPS_1V8_SUPPLIES_EXT_AND_LDO = (PWR_CR3_SMPSLEVEL_0 | PWR_CR3_SMPSEXTHP | PWR_CR3_SMPSEN | PWR_CR3_LDOEN),  /*!< The SMPS 1.8V output supplies an external circuits and the LDO. The Core domains are supplied from the LDO */
    PWR_SMPS_2V5_SUPPLIES_EXT_AND_LDO = (PWR_CR3_SMPSLEVEL_1 | PWR_CR3_SMPSEXTHP | PWR_CR3_SMPSEN | PWR_CR3_LDOEN),  /*!< The SMPS 2.5V output supplies an external circuits and the LDO. The Core domains are supplied from the LDO */
    PWR_SMPS_1V8_SUPPLIES_EXT         = (PWR_CR3_SMPSLEVEL_0 | PWR_CR3_SMPSEXTHP | PWR_CR3_SMPSEN | PWR_CR3_BYPASS), /*!< The SMPS 1.8V output supplies an external source which supplies the Core domains                            */
    PWR_SMPS_2V5_SUPPLIES_EXT         = (PWR_CR3_SMPSLEVEL_1 | PWR_CR3_SMPSEXTHP | PWR_CR3_SMPSEN | PWR_CR3_BYPASS), /*!< The SMPS 2.5V output supplies an external source which supplies the Core domains                            */
#endif /* SMPS */
    PWR_EXTERNAL_SOURCE_SUPPLY        =  PWR_CR3_BYPASS,                                                              /*!< The SMPS and the LDO are Bypassed. The Core domains are supplied from an external source                    */
};

class PWRX
{
public:
    static PWRX* getInstance()
    {
        static PWRX pwrx;
        return &pwrx;
    }
  /** @defgroup PWR_LL_EF_Configuration Configuration
  * @{
  */

  /**
  * @brief  Set the voltage Regulator mode during deep sleep mode
  * @rmtoll CR1    LPDS         pwrSetRegulModeDS
  * @param  RegulMode This parameter can be one of the following values:
  *         @arg @ref pwrREGU_DSMODE_MAIN
  *         @arg @ref pwrREGU_DSMODE_LOW_POWER
  * @retval None
  */
  inline void pwrSetRegulModeDS(PWRREGUDeepSleepMode RegulMode)
  {
    MODIFY_REG(PWR->CR1, PWR_CR1_LPDS, RegulMode);
  }

  /**
    * @brief  Get the voltage Regulator mode during deep sleep mode
    * @rmtoll CR1    LPDS         pwrGetRegulModeDS
    * @retval Returned value can be one of the following values:
    *         @arg @ref pwrREGU_DSMODE_MAIN
    *         @arg @ref pwrREGU_DSMODE_LOW_POWER
    */
  inline PWRREGUDeepSleepMode pwrGetRegulModeDS(void)
  {
    return (PWRREGUDeepSleepMode)(READ_BIT(PWR->CR1, PWR_CR1_LPDS));
  }

  /**
    * @brief  Enable Power Voltage Detector
    * @rmtoll CR1    PVDEN       pwrEnablePVD
    * @retval None
    */
  inline void pwrEnablePVD(void)
  {
    SET_BIT(PWR->CR1, PWR_CR1_PVDEN);
  }

  /**
    * @brief  Disable Power Voltage Detector
    * @rmtoll CR1    PVDEN       pwrDisablePVD
    * @retval None
    */
  inline void pwrDisablePVD(void)
  {
    CLEAR_BIT(PWR->CR1, PWR_CR1_PVDEN);
  }

  /**
    * @brief  Check if Power Voltage Detector is enabled
    * @rmtoll CR1    PVDEN       pwrIsEnabledPVD
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsEnabledPVD(void)
  {
    return ((READ_BIT(PWR->CR1, PWR_CR1_PVDEN) == (PWR_CR1_PVDEN)) ? true : false);
  }

  /**
    * @brief  Configure the voltage threshold detected by the Power Voltage Detector
    * @rmtoll CR1    PLS       pwrSetPVDLevel
    * @param  PVDLevel This parameter can be one of the following values:
    *         @arg @ref pwrPVDLEVEL_0
    *         @arg @ref pwrPVDLEVEL_1
    *         @arg @ref pwrPVDLEVEL_2
    *         @arg @ref pwrPVDLEVEL_3
    *         @arg @ref pwrPVDLEVEL_4
    *         @arg @ref pwrPVDLEVEL_5
    *         @arg @ref pwrPVDLEVEL_6
    *         @arg @ref pwrPVDLEVEL_7
    * @retval None
    */
  inline void pwrSetPVDLevel(PWRPVDLevel PVDLevel)
  {
    MODIFY_REG(PWR->CR1, PWR_CR1_PLS, PVDLevel);
  }

  /**
    * @brief  Get the voltage threshold detection
    * @rmtoll CR1    PLS       pwrGetPVDLevel
    * @retval Returned value can be one of the following values:
    *         @arg @ref pwrPVDLEVEL_0
    *         @arg @ref pwrPVDLEVEL_1
    *         @arg @ref pwrPVDLEVEL_2
    *         @arg @ref pwrPVDLEVEL_3
    *         @arg @ref pwrPVDLEVEL_4
    *         @arg @ref pwrPVDLEVEL_5
    *         @arg @ref pwrPVDLEVEL_6
    *         @arg @ref pwrPVDLEVEL_7
    */
  inline PWRPVDLevel pwrGetPVDLevel(void)
  {
    return (PWRPVDLevel)(READ_BIT(PWR->CR1, PWR_CR1_PLS));
  }

  /**
    * @brief  Enable access to the backup domain
    * @rmtoll CR1    DBP       pwrEnableBkUpAccess
    * @retval None
    */
  inline void pwrEnableBkUpAccess(void)
  {
    SET_BIT(PWR->CR1, PWR_CR1_DBP);
  }

  /**
    * @brief  Disable access to the backup domain
    * @rmtoll CR1    DBP       pwrDisableBkUpAccess
    * @retval None
    */
  inline void pwrDisableBkUpAccess(void)
  {
    CLEAR_BIT(PWR->CR1, PWR_CR1_DBP);
  }

  /**
    * @brief  Check if the backup domain is enabled
    * @rmtoll CR1    DBP       pwrIsEnabledBkUpAccess
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsEnabledBkUpAccess(void)
  {
    return ((READ_BIT(PWR->CR1, PWR_CR1_DBP) == (PWR_CR1_DBP)) ? true : false);
  }

  /**
    * @brief  Enable the Flash Power Down in Stop Mode
    * @rmtoll CR1    FLPS       pwrEnableFlashPowerDown
    * @retval None
    */
  inline void pwrEnableFlashPowerDown(void)
  {
    SET_BIT(PWR->CR1, PWR_CR1_FLPS);
  }

  /**
    * @brief  Disable the Flash Power Down in Stop Mode
    * @rmtoll CR1    FLPS       pwrDisableFlashPowerDown
    * @retval None
    */
  inline void pwrDisableFlashPowerDown(void)
  {
    CLEAR_BIT(PWR->CR1, PWR_CR1_FLPS);
  }

  /**
    * @brief  Check if the Flash Power Down in Stop Mode is enabled
    * @rmtoll CR1    FLPS       pwrIsEnabledFlashPowerDown
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsEnabledFlashPowerDown(void)
  {
    return ((READ_BIT(PWR->CR1, PWR_CR1_FLPS) == (PWR_CR1_FLPS)) ? true : false);
  }

  #if defined (PWR_CR1_BOOSTE)
  /**
    * @brief  Enable the Analog Voltage Booster (VDDA)
    * @rmtoll CR1    BOOSTE     pwrEnableAnalogBooster
    * @retval None
    */
  inline void pwrEnableAnalogBooster(void)
  {
    SET_BIT(PWR->CR1, PWR_CR1_BOOSTE);
  }

  /**
    * @brief  Disable the Analog Voltage Booster (VDDA)
    * @rmtoll CR1    BOOSTE     pwrDisableAnalogBooster
    * @retval None
    */
  inline void pwrDisableAnalogBooster(void)
  {
    CLEAR_BIT(PWR->CR1, PWR_CR1_BOOSTE);
  }

  /**
    * @brief  Check if the Analog Voltage Booster (VDDA) is enabled
    * @rmtoll CR1    BOOSTE     pwrIsEnabledAnalogBooster
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsEnabledAnalogBooster(void)
  {
    return ((READ_BIT(PWR->CR1, PWR_CR1_BOOSTE) == (PWR_CR1_BOOSTE)) ? true : false);
  }
  #endif /* PWR_CR1_BOOSTE */

  #if defined (PWR_CR1_AVD_READY)
  /**
    * @brief  Enable the Analog Voltage Ready to isolate the BOOST IP until VDDA will be ready
    * @rmtoll CR1    AVD_READY  pwrEnableAnalogVoltageReady
    * @retval None
    */
  inline void pwrEnableAnalogVoltageReady(void)
  {
    SET_BIT(PWR->CR1, PWR_CR1_AVD_READY);
  }

  /**
    * @brief  Disable the Analog Voltage Ready (VDDA)
    * @rmtoll CR1    AVD_READY  pwrDisableAnalogVoltageReady
    * @retval None
    */
  inline void pwrDisableAnalogVoltageReady(void)
  {
    CLEAR_BIT(PWR->CR1, PWR_CR1_AVD_READY);
  }

  /**
    * @brief  Check if the Analog Voltage Booster (VDDA) is enabled
    * @rmtoll CR1    AVD_READY  pwrIsEnabledAnalogVoltageReady
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsEnabledAnalogVoltageReady(void)
  {
    return ((READ_BIT(PWR->CR1, PWR_CR1_AVD_READY) == (PWR_CR1_AVD_READY)) ? true : false);
  }
  #endif /* PWR_CR1_AVD_READY */

  /**
    * @brief  Set the internal Regulator output voltage in STOP mode
    * @rmtoll CR1    SVOS       pwrSetStopModeRegulVoltageScaling
    * @param  VoltageScaling This parameter can be one of the following values:
    *         @arg @ref pwrREGU_VOLTAGE_SVOS_SCALE3
    *         @arg @ref pwrREGU_VOLTAGE_SVOS_SCALE4
    *         @arg @ref pwrREGU_VOLTAGE_SVOS_SCALE5
    * @retval None
    */
  inline void pwrSetStopModeRegulVoltageScaling(PWRREGUVoltageStopModeScaling VoltageScaling)
  {
    MODIFY_REG(PWR->CR1, PWR_CR1_SVOS, VoltageScaling);
  }

  /**
    * @brief  Get the internal Regulator output voltage in STOP mode
    * @rmtoll CR1    SVOS       pwrGetStopModeRegulVoltageScaling
    * @retval Returned value can be one of the following values:
    *         @arg @ref pwrREGU_VOLTAGE_SVOS_SCALE3
    *         @arg @ref pwrREGU_VOLTAGE_SVOS_SCALE4
    *         @arg @ref pwrREGU_VOLTAGE_SVOS_SCALE5
    */
  inline PWRREGUVoltageStopModeScaling pwrGetStopModeRegulVoltageScaling(void)
  {
    return (PWRREGUVoltageStopModeScaling)(READ_BIT(PWR->CR1, PWR_CR1_SVOS));
  }

  /**
    * @brief  Enable Analog Power Voltage Detector
    * @rmtoll CR1    AVDEN       pwrEnableAVD
    * @retval None
    */
  inline void pwrEnableAVD(void)
  {
    SET_BIT(PWR->CR1, PWR_CR1_AVDEN);
  }

  /**
    * @brief  Disable Analog Power Voltage Detector
    * @rmtoll CR1    AVDEN       pwrDisableAVD
    * @retval None
    */
  inline void pwrDisableAVD(void)
  {
    CLEAR_BIT(PWR->CR1, PWR_CR1_AVDEN);
  }

  /**
    * @brief  Check if Analog Power Voltage Detector is enabled
    * @rmtoll CR1    AVDEN       pwrIsEnabledAVD
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsEnabledAVD(void)
  {
    return ((READ_BIT(PWR->CR1, PWR_CR1_AVDEN) == (PWR_CR1_AVDEN)) ? true : false);
  }

  /**
    * @brief  Configure the voltage threshold to be detected by the Analog Power Voltage Detector
    * @rmtoll CR1    ALS       pwrSetAVDLevel
    * @param  AVDLevel This parameter can be one of the following values:
    *         @arg @ref pwrAVDLEVEL_0
    *         @arg @ref pwrAVDLEVEL_1
    *         @arg @ref pwrAVDLEVEL_2
    *         @arg @ref pwrAVDLEVEL_3
    * @retval None
    */
  inline void pwrSetAVDLevel(PWRAVDLevel AVDLevel)
  {
    MODIFY_REG(PWR->CR1, PWR_CR1_ALS, AVDLevel);
  }

  /**
    * @brief  Get the Analog Voltage threshold to be detected by the Analog Power Voltage Detector
    * @rmtoll CR1    ALS       pwrGetAVDLevel
    * @retval Returned value can be one of the following values:
    *         @arg @ref pwrAVDLEVEL_0
    *         @arg @ref pwrAVDLEVEL_1
    *         @arg @ref pwrAVDLEVEL_2
    *         @arg @ref pwrAVDLEVEL_3
    */
  inline PWRAVDLevel pwrGetAVDLevel(void)
  {
    return (PWRAVDLevel)(READ_BIT(PWR->CR1, PWR_CR1_ALS));
  }

  #if defined (PWR_CR1_AXIRAM1SO)
  /**
    * @brief  Enable the AXI RAM1 shut-off in DStop/DStop2 mode
    * @rmtoll CR1    AXIRAM1SO     pwrEnableAXIRAM1ShutOff
    * @retval None
    */
  inline void pwrEnableAXIRAM1ShutOff(void)
  {
    SET_BIT(PWR->CR1, PWR_CR1_AXIRAM1SO);
  }

  /**
    * @brief  Disable the AXI RAM1 shut-off in DStop/DStop2 mode
    * @rmtoll CR1    AXIRAM1SO     pwrDisableAXIRAM1ShutOff
    * @retval None
    */
  inline void pwrDisableAXIRAM1ShutOff(void)
  {
    CLEAR_BIT(PWR->CR1, PWR_CR1_AXIRAM1SO);
  }

  /**
    * @brief  Check if the AXI RAM1 shut-off in DStop/DStop2 mode is enabled
    * @rmtoll CR1    AXIRAM1SO     pwrIsEnabledAXIRAM1ShutOff
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsEnabledAXIRAM1ShutOff(void)
  {
    return ((READ_BIT(PWR->CR1, PWR_CR1_AXIRAM1SO) == (PWR_CR1_AXIRAM1SO)) ? true : false);
  }
  #endif /* PWR_CR1_AXIRAM1SO */

  #if defined (PWR_CR1_AXIRAM2SO)
  /**
    * @brief  Enable the AXI RAM2 shut-off in DStop/DStop2 mode
    * @rmtoll CR1    AXIRAM2SO     pwrEnableAXIRAM2ShutOff
    * @retval None
    */
  inline void pwrEnableAXIRAM2ShutOff(void)
  {
    SET_BIT(PWR->CR1, PWR_CR1_AXIRAM2SO);
  }

  /**
    * @brief  Disable the AXI RAM2 shut-off in DStop/DStop2 mode
    * @rmtoll CR1    AXIRAM2SO     pwrDisableAXIRAM2ShutOff
    * @retval None
    */
  inline void pwrDisableAXIRAM2ShutOff(void)
  {
    CLEAR_BIT(PWR->CR1, PWR_CR1_AXIRAM2SO);
  }

  /**
    * @brief  Check if the AXI RAM2 shut-off in DStop/DStop2 mode is enabled
    * @rmtoll CR1    AXIRAM2SO     pwrIsEnabledAXIRAM2ShutOff
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsEnabledAXIRAM2ShutOff(void)
  {
    return ((READ_BIT(PWR->CR1, PWR_CR1_AXIRAM2SO) == (PWR_CR1_AXIRAM2SO)) ? true : false);
  }
  #endif /* PWR_CR1_AXIRAM2SO */

  #if defined (PWR_CR1_AXIRAM3SO)
  /**
    * @brief  Enable the AXI RAM3 shut-off in DStop/DStop2 mode
    * @rmtoll CR1    AXIRAM3SO     pwrEnableAXIRAM3ShutOff
    * @retval None
    */
  inline void pwrEnableAXIRAM3ShutOff(void)
  {
    SET_BIT(PWR->CR1, PWR_CR1_AXIRAM3SO);
  }

  /**
    * @brief  Disable the AXI RAM3 shut-off in DStop/DStop2 mode
    * @rmtoll CR1    AXIRAM3SO     pwrDisableAXIRAM3ShutOff
    * @retval None
    */
  inline void pwrDisableAXIRAM3ShutOff(void)
  {
    CLEAR_BIT(PWR->CR1, PWR_CR1_AXIRAM3SO);
  }

  /**
    * @brief  Check if the AXI RAM3 shut-off in DStop/DStop2 mode is enabled
    * @rmtoll CR1    AXIRAM3SO     pwrIsEnabledAXIRAM3ShutOff
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsEnabledAXIRAM3ShutOff(void)
  {
    return ((READ_BIT(PWR->CR1, PWR_CR1_AXIRAM3SO) == (PWR_CR1_AXIRAM3SO)) ? true : false);
  }
  #endif /* PWR_CR1_AXIRAM3SO */

  #if defined (PWR_CR1_AHBRAM1SO)
  /**
    * @brief  Enable the AHB RAM1 shut-off in DStop/DStop2 mode
    * @rmtoll CR1    AHBRAM1SO     pwrEnableAHBRAM1ShutOff
    * @retval None
    */
  inline void pwrEnableAHBRAM1ShutOff(void)
  {
    SET_BIT(PWR->CR1, PWR_CR1_AHBRAM1SO);
  }

  /**
    * @brief  Disable the AHB RAM1 shut-off in DStop/DStop2 mode
    * @rmtoll CR1    AHBRAM1SO     pwrDisableAHBRAM1ShutOff
    * @retval None
    */
  inline void pwrDisableAHBRAM1ShutOff(void)
  {
    CLEAR_BIT(PWR->CR1, PWR_CR1_AHBRAM1SO);
  }

  /**
    * @brief  Check if the AHB RAM1 shut-off in DStop/DStop2 mode is enabled
    * @rmtoll CR1    AHBRAM1SO     pwrIsEnabledAHBRAM1ShutOff
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsEnabledAHBRAM1ShutOff(void)
  {
    return ((READ_BIT(PWR->CR1, PWR_CR1_AHBRAM1SO) == (PWR_CR1_AHBRAM1SO)) ? true : false);
  }
  #endif /* PWR_CR1_AHBRAM1SO */

  #if defined (PWR_CR1_AHBRAM2SO)
  /**
    * @brief  Enable the AHB RAM2 shut-off in DStop/DStop2 mode
    * @rmtoll CR1    AHBRAM2SO     pwrEnableAHBRAM2ShutOff
    * @retval None
    */
  inline void pwrEnableAHBRAM2ShutOff(void)
  {
    SET_BIT(PWR->CR1, PWR_CR1_AHBRAM2SO);
  }

  /**
    * @brief  Disable the AHB RAM2 shut-off in DStop/DStop2 mode
    * @rmtoll CR1    AHBRAM2SO     pwrDisableAHBRAM2ShutOff
    * @retval None
    */
  inline void pwrDisableAHBRAM2ShutOff(void)
  {
    CLEAR_BIT(PWR->CR1, PWR_CR1_AHBRAM2SO);
  }

  /**
    * @brief  Check if the AHB RAM2 shut-off in DStop/DStop2 mode is enabled
    * @rmtoll CR1    AHBRAM2SO     pwrIsEnabledAHBRAM2ShutOff
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsEnabledAHBRAM2ShutOff(void)
  {
    return ((READ_BIT(PWR->CR1, PWR_CR1_AHBRAM2SO) == (PWR_CR1_AHBRAM2SO)) ? true : false);
  }
  #endif /* PWR_CR1_AHBRAM2SO */

  #if defined (PWR_CR1_ITCMSO)
  /**
    * @brief  Enable the ITCM shut-off in DStop/DStop2 mode
    * @rmtoll CR1    ITCMSO     pwrEnableITCMSOShutOff
    * @retval None
    */
  inline void pwrEnableITCMSOShutOff(void)
  {
    SET_BIT(PWR->CR1, PWR_CR1_ITCMSO);
  }

  /**
    * @brief  Disable the ITCM shut-off in DStop/DStop2 mode
    * @rmtoll CR1    ITCMSO     pwrDisableITCMSOShutOff
    * @retval None
    */
  inline void pwrDisableITCMSOShutOff(void)
  {
    CLEAR_BIT(PWR->CR1, PWR_CR1_ITCMSO);
  }

  /**
    * @brief  Check if the ITCM shut-off in DStop/DStop2 mode is enabled
    * @rmtoll CR1    ITCMSO     pwrIsEnabledITCMShutOff
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsEnabledITCMShutOff(void)
  {
    return ((READ_BIT(PWR->CR1, PWR_CR1_ITCMSO) == (PWR_CR1_ITCMSO)) ? true : false);
  }
  #endif /* PWR_CR1_ITCMSO */

  #if defined (PWR_CR1_HSITFSO)
  /**
    * @brief  Enable the USB and FDCAN shut-off in DStop/DStop2 mode
    * @rmtoll CR1    HSITFSO     pwrEnableHSITFShutOff
    * @retval None
    */
  inline void pwrEnableHSITFShutOff(void)
  {
    SET_BIT(PWR->CR1, PWR_CR1_HSITFSO);
  }

  /**
    * @brief  Disable the USB and FDCAN shut-off in DStop/DStop2 mode
    * @rmtoll CR1    HSITFSO     pwrDisableHSITFShutOff
    * @retval None
    */
  inline void pwrDisableHSITFShutOff(void)
  {
    CLEAR_BIT(PWR->CR1, PWR_CR1_HSITFSO);
  }

  /**
    * @brief  Check if the USB and FDCAN shut-off in DStop/DStop2 mode is enabled
    * @rmtoll CR1    HSITFSO     pwrIsEnabledHSITFShutOff
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsEnabledHSITFShutOff(void)
  {
    return ((READ_BIT(PWR->CR1, PWR_CR1_HSITFSO) == (PWR_CR1_HSITFSO)) ? true : false);
  }
  #endif /* PWR_CR1_HSITFSO */

  #if defined (PWR_CR1_SRDRAMSO)
  /**
    * @brief  Enable the SRD AHB RAM shut-off in DStop/DStop2 mode
    * @rmtoll CR1    SRDRAMSO     pwrEnableSRDRAMShutOff
    * @retval None
    */
  inline void pwrEnableSRDRAMShutOff(void)
  {
    SET_BIT(PWR->CR1, PWR_CR1_SRDRAMSO);
  }

  /**
    * @brief  Disable the SRD AHB RAM shut-off in DStop/DStop2 mode
    * @rmtoll CR1    SRDRAMSO     pwrDisableSRDRAMShutOff
    * @retval None
    */
  inline void pwrDisableSRDRAMShutOff(void)
  {
    CLEAR_BIT(PWR->CR1, PWR_CR1_SRDRAMSO);
  }

  /**
    * @brief  Check if the SRD AHB RAM shut-off in DStop/DStop2 mode is enabled
    * @rmtoll CR1    SRDRAMSO     pwrIsEnabledSRDRAMShutOff
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsEnabledSRDRAMShutOff(void)
  {
    return ((READ_BIT(PWR->CR1, PWR_CR1_SRDRAMSO) == (PWR_CR1_SRDRAMSO)) ? true : false);
  }
  #endif /* PWR_CR1_SRDRAMSO */

  /**
    * @brief  Enable Backup Regulator
    * @rmtoll CR2    BREN       pwrEnableBkUpRegulator
    * @note When set, the Backup Regulator (used to maintain backup SRAM content in Standby and
    *       VBAT modes) is enabled. If BRE is reset, the backup Regulator is switched off. The backup
    *       SRAM can still be used but its content will be lost in the Standby and VBAT modes. Once set,
    *       the application must wait that the Backup Regulator Ready flag (BRR) is set to indicate that
    *       the data written into the RAM will be maintained in the Standby and VBAT modes.
    * @retval None
    */
  inline void pwrEnableBkUpRegulator(void)
  {
    SET_BIT(PWR->CR2, PWR_CR2_BREN);
  }

  /**
    * @brief  Disable Backup Regulator
    * @rmtoll CR2    BREN       pwrDisableBkUpRegulator
    * @retval None
    */
  inline void pwrDisableBkUpRegulator(void)
  {
    CLEAR_BIT(PWR->CR2, PWR_CR2_BREN);
  }

  /**
    * @brief  Check if the backup Regulator is enabled
    * @rmtoll CR2    BREN      pwrIsEnabledBkUpRegulator
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsEnabledBkUpRegulator(void)
  {
    return ((READ_BIT(PWR->CR2, PWR_CR2_BREN) == (PWR_CR2_BREN)) ? true : false);
  }

  /**
    * @brief  Enable VBAT and Temperature monitoring
    * @rmtoll CR2    MONEN       pwrEnableMonitoring
    * @retval None
    */
  inline void pwrEnableMonitoring(void)
  {
    SET_BIT(PWR->CR2, PWR_CR2_MONEN);
  }

  /**
    * @brief  Disable VBAT and Temperature monitoring
    * @rmtoll CR2    MONEN       pwrDisableMonitoring
    * @retval None
    */
  inline void pwrDisableMonitoring(void)
  {
    CLEAR_BIT(PWR->CR2, PWR_CR2_MONEN);
  }

  /**
    * @brief  Check if the VBAT and Temperature monitoring is enabled
    * @rmtoll CR2    MONEN      pwrIsEnabledMonitoring
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsEnabledMonitoring(void)
  {
    return ((READ_BIT(PWR->CR2, PWR_CR2_MONEN) == (PWR_CR2_MONEN)) ? true : false);
  }

  #if defined (SMPS)
  /**
    * @brief  Configure the PWR supply
    * @rmtoll CR3          BYPASS          pwrConfigSupply
    * @rmtoll CR3          LDOEN           pwrConfigSupply
    * @rmtoll CR3          SMPSEN          pwrConfigSupply
    * @rmtoll CR3          SMPSEXTHP       pwrConfigSupply
    * @rmtoll CR3          SMPSLEVEL       pwrConfigSupply
    * @param  SupplySource This parameter can be one of the following values:
    *         @arg @ref pwrLDO_SUPPLY
    *         @arg @ref pwrDIRECT_SMPS_SUPPLY
    *         @arg @ref pwrSMPS_1V8_SUPPLIES_LDO
    *         @arg @ref pwrSMPS_2V5_SUPPLIES_LDO
    *         @arg @ref pwrSMPS_1V8_SUPPLIES_EXT_AND_LDO
    *         @arg @ref pwrSMPS_2V5_SUPPLIES_EXT_AND_LDO
    *         @arg @ref pwrSMPS_1V8_SUPPLIES_EXT
    *         @arg @ref pwrSMPS_2V5_SUPPLIES_EXT
    *         @arg @ref pwrEXTERNAL_SOURCE_SUPPLY
    * @retval None
    */
  inline void pwrConfigSupply(PWRPowerSupplySource SupplySource)
  {
    /* Set the power supply configuration */
    MODIFY_REG(PWR->CR3, (PWR_CR3_SMPSLEVEL | PWR_CR3_SMPSEXTHP | PWR_CR3_SMPSEN | PWR_CR3_LDOEN | PWR_CR3_BYPASS), SupplySource);
  }
  #else
  /**
    * @brief  Configure the PWR supply
    * @rmtoll CR3          BYPASS          pwrConfigSupply
    * @rmtoll CR3          LDOEN           pwrConfigSupply
    * @rmtoll CR3          SCUEN           pwrConfigSupply
    * @param  SupplySource This parameter can be one of the following values:
    *         @arg @ref pwrLDO_SUPPLY
    *         @arg @ref pwrEXTERNAL_SOURCE_SUPPLY
    * @retval None
    */
  inline void pwrConfigSupply(PWRPowerSupplySource SupplySource)
  {
    /* Set the power supply configuration */
    MODIFY_REG(PWR->CR3, (PWR_CR3_SCUEN | PWR_CR3_LDOEN | PWR_CR3_BYPASS), SupplySource);
  }
  #endif /* defined (SMPS) */

  #if defined (SMPS)
  /**
    * @brief  Get the PWR supply
    * @rmtoll CR3          BYPASS          pwrGetSupply
    * @rmtoll CR3          LDOEN           pwrGetSupply
    * @rmtoll CR3          SMPSEN          pwrGetSupply
    * @rmtoll CR3          SMPSEXTHP       pwrGetSupply
    * @rmtoll CR3          SMPSLEVEL       pwrGetSupply
    * @retval Returned value can be one of the following values:
    *         @arg @ref pwrLDO_SUPPLY
    *         @arg @ref pwrDIRECT_SMPS_SUPPLY
    *         @arg @ref pwrSMPS_1V8_SUPPLIES_LDO
    *         @arg @ref pwrSMPS_2V5_SUPPLIES_LDO
    *         @arg @ref pwrSMPS_1V8_SUPPLIES_EXT_AND_LDO
    *         @arg @ref pwrSMPS_2V5_SUPPLIES_EXT_AND_LDO
    *         @arg @ref pwrSMPS_1V8_SUPPLIES_EXT
    *         @arg @ref pwrSMPS_2V5_SUPPLIES_EXT
    *         @arg @ref pwrEXTERNAL_SOURCE_SUPPLY
    */
  inline PWRPowerSupplySource pwrGetSupply(void)
  {
    /* Get the power supply configuration */
    return(PWRPowerSupplySource)(READ_BIT(PWR->CR3, (PWR_CR3_SMPSLEVEL | PWR_CR3_SMPSEXTHP | PWR_CR3_SMPSEN | PWR_CR3_LDOEN | PWR_CR3_BYPASS)));
  }
  #else
  /**
    * @brief  Get the PWR supply
    * @rmtoll CR3          BYPASS          pwrGetSupply
    * @rmtoll CR3          LDOEN           pwrGetSupply
    * @rmtoll CR3          SCUEN           pwrGetSupply
    * @retval Returned value can be one of the following values:
    *         @arg @ref pwrLDO_SUPPLY
    *         @arg @ref pwrEXTERNAL_SOURCE_SUPPLY
    */
  inline PWRPowerSupplySource pwrGetSupply(void)
  {
    /* Get the power supply configuration */
    return(PWRPowerSupplySource)(READ_BIT(PWR->CR3, (PWR_CR3_SCUEN | PWR_CR3_LDOEN | PWR_CR3_BYPASS)));
  }
  #endif /* defined (SMPS) */

  /**
    * @brief  Enable battery charging
    * @rmtoll CR3          VBE           pwrEnableBatteryCharging
    * @retval None
    */
  inline void pwrEnableBatteryCharging(void)
  {
    SET_BIT(PWR->CR3, PWR_CR3_VBE);
  }

  /**
    * @brief  Disable battery charging
    * @rmtoll CR3          VBE           pwrDisableBatteryCharging
    * @retval None
    */
  inline void pwrDisableBatteryCharging(void)
  {
    CLEAR_BIT(PWR->CR3, PWR_CR3_VBE);
  }

  /**
    * @brief  Check if battery charging is enabled
    * @rmtoll CR3          VBE           pwrIsEnabledBatteryCharging
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsEnabledBatteryCharging(void)
  {
    return ((READ_BIT(PWR->CR3, PWR_CR3_VBE) == (PWR_CR3_VBE)) ? true : false);
  }

  /**
    * @brief  Set the Battery charge resistor impedance
    * @rmtoll CR3          VBRS          pwrSetBattChargResistor
    * @param  Resistor This parameter can be one of the following values:
    *         @arg @ref pwrBATT_CHARG_RESISTOR_5K
    *         @arg @ref pwrBATT_CHARGRESISTOR_1_5K
    * @retval None
    */
  inline void pwrSetBattChargResistor(PWRBATTChangeResistor Resistor)
  {
    MODIFY_REG(PWR->CR3, PWR_CR3_VBRS, Resistor);
  }

  /**
    * @brief  Get the Battery charge resistor impedance
    * @rmtoll CR3          VBRS          pwrGetBattChargResistor
    * @retval Returned value can be one of the following values:
    *         @arg @ref pwrBATT_CHARG_RESISTOR_5K
    *         @arg @ref pwrBATT_CHARGRESISTOR_1_5K
    */
  inline PWRBATTChangeResistor pwrGetBattChargResistor(void)
  {
    return (PWRBATTChangeResistor)(READ_BIT(PWR->CR3, PWR_CR3_VBRS));
  }

  /**
    * @brief  Enable the USB regulator
    * @rmtoll CR3          USBREGEN           pwrEnableUSBReg
    * @retval None
    */
  inline void pwrEnableUSBReg(void)
  {
    SET_BIT(PWR->CR3, PWR_CR3_USBREGEN);
  }

  /**
    * @brief  Disable the USB regulator
    * @rmtoll CR3          USBREGEN           pwrDisableUSBReg
    * @retval None
    */
  inline void pwrDisableUSBReg(void)
  {
    CLEAR_BIT(PWR->CR3, PWR_CR3_USBREGEN);
  }

  /**
    * @brief  Check if the USB regulator is enabled
    * @rmtoll CR3          USBREGEN           pwrIsEnabledUSBReg
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsEnabledUSBReg(void)
  {
    return ((READ_BIT(PWR->CR3, PWR_CR3_USBREGEN) == (PWR_CR3_USBREGEN)) ? true : false);
  }

  /**
    * @brief  Enable the USB voltage detector
    * @rmtoll CR3          USB33DEN           pwrEnableUSBVoltageDetector
    * @retval None
    */
  inline void pwrEnableUSBVoltageDetector(void)
  {
    SET_BIT(PWR->CR3, PWR_CR3_USB33DEN);
  }

  /**
    * @brief  Disable the USB voltage detector
    * @rmtoll CR3          USB33DEN           pwrDisableUSBVoltageDetector
    * @retval None
    */
  inline void pwrDisableUSBVoltageDetector(void)
  {
    CLEAR_BIT(PWR->CR3, PWR_CR3_USB33DEN);
  }

  /**
    * @brief  Check if the USB voltage detector is enabled
    * @rmtoll CR3          USB33DEN           pwrIsEnabledUSBVoltageDetector
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsEnabledUSBVoltageDetector(void)
  {
    return ((READ_BIT(PWR->CR3, PWR_CR3_USB33DEN) == (PWR_CR3_USB33DEN)) ? true : false);
  }

  #if defined (PWR_CPUCR_PDDS_D2)
  /**
    * @brief  Set the D1 domain Power Down mode when the CPU enters deepsleep
    * @rmtoll CPUCR     PDDS_D1       pwrCPUSetD1PowerMode
    * @param  PDMode This parameter can be one of the following values:
    *         @arg @ref pwrCPUMODE_D1STOP
    *         @arg @ref pwrCPUPWRBATTChangeResistor
    * @retval None
    */
  inline void pwrCPUSetD1PowerMode(PWRD1CPUMode PDMode)
  {
    MODIFY_REG(PWR->CPUCR, PWR_CPUCR_PDDS_D1, PDMode);
  }
  #else
  /**
    * @brief  Set the CPU domain Power Down mode when the CPU enters deepsleep
    * @rmtoll CPUCR     RETDS_CD       pwrCPUSetCDPowerMode
    * @param  PDMode This parameter can be one of the following values:
    *         @arg @ref pwrCPUMODE_CDSTOP
    *         @arg @ref pwrCPUMODE_CDSTOP2
    * @retval None
    */
  inline void pwrCPUSetCDPowerMode(PWRD1CPUMode PDMode)
  {
    MODIFY_REG(PWR->CPUCR, PWR_CPUCR_RETDS_CD, PDMode);
  }
  #endif /* PWR_CPUCR_PDDS_D2 */

  #if defined (DUAL_CORE)
  /**
    * @brief  Set the D1 domain Power Down mode when the CPU2 enters deepsleep
    * @rmtoll CPU2CR     PDDS_D1       PpwrCPU2SetD1PowerMode
    * @param  PDMode This parameter can be one of the following values:
    *         @arg @ref PpwrCPU2MODE_D1STOP
    *         @arg @ref PpwrCPU2MODE_D1STANDBY
    * @retval None
    */
  inline void pwrCPU2SetD1PowerMode(PWRCPU2D1Mode PDMode)
  {
    MODIFY_REG(PWR->CPU2CR, PWR_CPU2CR_PDDS_D1, PDMode);
  }
  #endif /* DUAL_CORE */

  #if defined (PWR_CPUCR_PDDS_D2)
  /**
    * @brief  Get the D1 Domain Power Down mode when the CPU enters deepsleep
    * @rmtoll CPUCR     PDDS_D1       pwrCPUGetD1PowerMode
    * @retval Returned value can be one of the following values:
    *         @arg @ref pwrCPUMODE_D1STOP
    *         @arg @ref pwrCPUMODE_D1STANDBY
    */
  inline PWRD1CPUMode pwrCPUGetD1PowerMode(void)
  {
    return (PWRD1CPUMode)(READ_BIT(PWR->CPUCR, PWR_CPUCR_PDDS_D1));
  }
  #else
  /**
    * @brief  Get the CD Domain Power Down mode when the CPU enters deepsleep
    * @rmtoll CPUCR     RETDS_CD       pwrCPUGetCDPowerMode
    * @retval Returned value can be one of the following values:
    *         @arg @ref pwrCPUMODE_CDSTOP
    *         @arg @ref pwrCPUMODE_CDSTOP2
    */
  inline PWRD1CPUMode pwrCPUGetCDPowerMode(void)
  {
    return (PWRD1CPUMode)(READ_BIT(PWR->CPUCR, PWR_CPUCR_RETDS_CD));
  }
  #endif /* PWR_CPUCR_PDDS_D2 */

  #if defined (DUAL_CORE)
  /**
    * @brief  Get the D1 Domain Power Down mode when the CPU2 enters deepsleep
    * @rmtoll CPU2CR     PDDS_D1       PpwrCPU2GetD1PowerMode
    * @retval Returned value can be one of the following values:
    *         @arg @ref PpwrCPU2MODE_D1STOP
    *         @arg @ref PpwrCPU2MODE_D1STANDBY
    */
  inline PWRCPU2D1Mode PpwrCPU2GetD1PowerMode(void)
  {
    return (PWRCPU2D1Mode)(READ_BIT(PWR->CPU2CR, PWR_CPU2CR_PDDS_D1));
  }
  #endif /* DUAL_CORE */

  #if defined (PWR_CPUCR_PDDS_D2)
  /**
    * @brief  Set the D2 domain Power Down mode when the CPU enters deepsleep
    * @rmtoll CPUCR     PDDS_D2       pwrCPUSetD2PowerMode
    * @param  PDMode This parameter can be one of the following values:
    *         @arg @ref pwrCPUMODE_D2STOP
    *         @arg @ref pwrCPUMODE_D2STANDBY
    * @retval None
    */
  inline void pwrCPUSetD2PowerMode(PWRD2CPUMode PDMode)
  {
    MODIFY_REG(PWR->CPUCR, PWR_CPUCR_PDDS_D2, PDMode);
  }
  #endif /* PWR_CPUCR_PDDS_D2 */

  #if defined (DUAL_CORE)
  /**
    * @brief  Set the D2 domain Power Down mode when the CPU2 enters deepsleep
    * @rmtoll CPU2CR     PDDS_D2       PpwrCPU2SetD2PowerMode
    * @param  PDMode This parameter can be one of the following values:
    *         @arg @ref PpwrCPU2MODE_D2STOP
    *         @arg @ref PpwrCPU2MODE_D2STANDBY
    * @retval None
    */
  inline void PpwrCPU2SetD2PowerMode(PWRCPU2D2Mode PDMode)
  {
    MODIFY_REG(PWR->CPU2CR, PWR_CPU2CR_PDDS_D2, PDMode);
  }
  #endif /* DUAL_CORE */

  #if defined (PWR_CPUCR_PDDS_D2)
  /**
    * @brief  Get the D2 Domain Power Down mode when the CPU enters deepsleep
    * @rmtoll CPUCR     PDDS_D2       pwrCPUGetD2PowerMode
    * @retval Returned value can be one of the following values:
    *         @arg @ref pwrCPUMODE_D2STOP
    *         @arg @ref pwrCPUMODE_D2STANDBY
    */
  inline PWRD2CPUMode pwrCPUGetD2PowerMode(void)
  {
    return (PWRD2CPUMode)(READ_BIT(PWR->CPUCR, PWR_CPUCR_PDDS_D2));
  }
  #endif /* PWR_CPUCR_PDDS_D2 */

  #if defined (DUAL_CORE)
  /**
    * @brief  Get the D2 Domain Power Down mode when the CPU2 enters deepsleep
    * @rmtoll CPU2CR     PDDS_D2       PpwrCPU2GetD2PowerMode
    * @retval Returned value can be one of the following values:
    *         @arg @ref PpwrCPU2MODE_D2STOP
    *         @arg @ref PpwrCPU2MODE_D2STANDBY
    */
  inline PWRCPU2D2Mode PpwrCPU2GetD2PowerMode(void)
  {
    return (PWRCPU2D2Mode)(READ_BIT(PWR->CPU2CR, PWR_CPU2CR_PDDS_D2));
  }
  #endif /* DUAL_CORE */

  #if defined (PWR_CPUCR_PDDS_D2)
  /**
    * @brief  Set the D3 domain Power Down mode when the CPU enters deepsleep
    * @rmtoll CPUCR     PDDS_D3       pwrCPUSetD3PowerMode
    * @param  PDMode This parameter can be one of the following values:
    *         @arg @ref pwrCPUMODE_D3STOP
    *         @arg @ref pwrCPUMODE_D3STANDBY
    * @retval None
    */
  inline void pwrCPUSetD3PowerMode(PWRD3CPUMode PDMode)
  {
    MODIFY_REG(PWR->CPUCR, PWR_CPUCR_PDDS_D3 , PDMode);
  }
  #else
  /**
    * @brief  Set the SRD domain Power Down mode when the CPU enters deepsleep
    * @rmtoll CPUCR     PDDS_SRD       pwrCPUSetSRDPowerMode
    * @param  PDMode This parameter can be one of the following values:
    *         @arg @ref pwrCPUMODE_SRDSTOP
    *         @arg @ref pwrCPUMODE_SRDSTANDBY
    * @retval None
    */
  inline void pwrCPUSetSRDPowerMode(PWRD3CPUMode PDMode)
  {
    MODIFY_REG(PWR->CPUCR, PWR_CPUCR_PDDS_SRD , PDMode);
  }
  #endif /* PWR_CPUCR_PDDS_D2 */

  #if defined (DUAL_CORE)
  /**
    * @brief  Set the D3 domain Power Down mode when the CPU2 enters deepsleep
    * @rmtoll CPU2CR     PDDS_D3       PpwrCPU2SetD3PowerMode
    * @param  PDMode This parameter can be one of the following values:
    *         @arg @ref PpwrCPU2MODE_D3STOP
    *         @arg @ref PpwrCPU2MODE_D3STANDBY
    * @retval None
    */
  inline void PpwrCPU2SetD3PowerMode(uint32_t PDMode)
  {
    MODIFY_REG(PWR->CPU2CR, PWR_CPU2CR_PDDS_D3, PDMode);
  }
  #endif /* DUAL_CORE */

  #if defined (PWR_CPUCR_PDDS_D2)
  /**
    * @brief  Get the D3 Domain Power Down mode when the CPU enters deepsleep
    * @rmtoll CPUCR     PDDS_D3       pwrCPUGetD3PowerMode
    * @retval Returned value can be one of the following values:
    *         @arg @ref pwrCPUMODE_D3STOP
    *         @arg @ref pwrCPUMODE_D3STANDBY
    */
  inline PWRD3CPUMode pwrCPUGetD3PowerMode(void)
  {
    return (PWRD3CPUMode)(READ_BIT(PWR->CPUCR, PWR_CPUCR_PDDS_D3));
  }
  #else
  /**
    * @brief  Get the SRD Domain Power Down mode when the CPU enters deepsleep
    * @rmtoll CPUCR     PDDS_SRD       pwrCPUGetSRDPowerMode
    * @retval Returned value can be one of the following values:
    *         @arg @ref pwrCPUMODE_SRDSTOP
    *         @arg @ref pwrCPUMODE_SRDSTANDBY
    */
  inline PWRD3CPUMode pwrCPUGetSRDPowerMode(void)
  {
    return (PWRD3CPUMode)(READ_BIT(PWR->CPUCR, PWR_CPUCR_PDDS_SRD));
  }
  #endif /* PWR_CPUCR_PDDS_D2 */

  #if defined (DUAL_CORE)
  /**
    * @brief  Get the D3 Domain Power Down mode when the CPU2 enters deepsleep
    * @rmtoll CPU2CR     PDDS_D3       PpwrCPU2GetD3PowerMode
    * @retval Returned value can be one of the following values:
    *         @arg @ref PpwrCPU2MODE_D3STOP
    *         @arg @ref PpwrCPU2MODE_D3STANDBY
    */
  inline PWRCPU2D3Mode PpwrCPU2GetD3PowerMode(void)
  {
    return (PWRCPU2D3Mode)(READ_BIT(PWR->CPU2CR, PWR_CPU2CR_PDDS_D3));
  }
  #endif /* DUAL_CORE */

  #if defined (DUAL_CORE)
  /**
    * @brief  Hold the CPU1 and allocated peripherals when exiting from STOP mode
    * @rmtoll CPU2CR     HOLD1       pwrHoldCPU1
    * @retval None
    */
  inline void pwrHoldCPU1(void)
  {
    SET_BIT(PWR->CPU2CR, PWR_CPU2CR_HOLD1);
  }

  /**
    * @brief  Release the CPU1 and allocated peripherals
    * @rmtoll CPU2CR     HOLD1       pwrReleaseCPU1
    * @retval None
    */
  inline void pwrReleaseCPU1(void)
  {
    CLEAR_BIT(PWR->CPU2CR, PWR_CPU2CR_HOLD1);
  }

  /**
    * @brief  Ckeck if the CPU1 and allocated peripherals are held
    * @rmtoll CPU2CR     HOLD1       pwrIsCPU1Held
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsCPU1Held(void)
  {
    return ((READ_BIT(PWR->CPU2CR, PWR_CPU2CR_HOLD1) == (PWR_CPU2CR_HOLD1))  ? true : false);
  }

  /**
    * @brief  Hold the CPU2 and allocated peripherals when exiting from STOP mode
    * @rmtoll CPUCR     HOLD2       pwrHoldCPU2
    * @retval None
    */
  inline void pwrHoldCPU2(void)
  {
    SET_BIT(PWR->CPUCR, PWR_CPUCR_HOLD2);
  }

  /**
    * @brief  Release the CPU2 and allocated peripherals
    * @rmtoll CPUCR     HOLD2       pwrReleaseCPU2
    * @retval None
    */
  inline void pwrReleaseCPU2(void)
  {
    CLEAR_BIT(PWR->CPUCR, PWR_CPUCR_HOLD2);
  }

  /**
    * @brief  Ckeck if the CPU2 and allocated peripherals are held
    * @rmtoll CPUCR     HOLD2       pwrIsCPU2Held
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsCPU2Held(void)
  {
    return ((READ_BIT(PWR->CPUCR, PWR_CPUCR_HOLD2) == (PWR_CPUCR_HOLD2)) ? true : false);
  }
  #endif /* DUAL_CORE */

  #if defined (PWR_CPUCR_PDDS_D2)
  /**
    * @brief  D3 domain remains in Run mode regardless of CPU subsystem modes
    * @rmtoll CPUCR     RUN_D3       pwrCPUEnableD3RunInLowPowerMode
    * @retval None
    */
  inline void pwrCPUEnableD3RunInLowPowerMode(void)
  {
    SET_BIT(PWR->CPUCR, PWR_CPUCR_RUN_D3);
  }
  #else
  /**
    * @brief  SRD domain remains in Run mode regardless of CPU subsystem modes
    * @rmtoll CPUCR     RUN_SRD      pwrCPUEnableSRDRunInLowPowerMode
    * @retval None
    */
  inline void pwrCPUEnableSRDRunInLowPowerMode(void)
  {
    SET_BIT(PWR->CPUCR, PWR_CPUCR_RUN_SRD);
  }
  #endif /* PWR_CPUCR_PDDS_D2 */

  #if defined (DUAL_CORE)
  /**
    * @brief  D3 domain remains in Run mode regardless of CPU2 subsystem modes
    * @rmtoll CPU2CR     RUN_D3       PpwrCPU2EnableD3RunInLowPowerMode
    * @retval None
    */
  inline void PpwrCPU2EnableD3RunInLowPowerMode(void)
  {
    SET_BIT(PWR->CPU2CR, PWR_CPU2CR_RUN_D3);
  }
  #endif /* DUAL_CORE */

  #if defined (PWR_CPUCR_PDDS_D2)
  /**
    * @brief  D3 domain follows CPU subsystem modes
    * @rmtoll CPUCR     RUN_D3       pwrCPUDisableD3RunInLowPowerMode
    * @retval None
    */
  inline void pwrCPUDisableD3RunInLowPowerMode(void)
  {
    CLEAR_BIT(PWR->CPUCR, PWR_CPUCR_RUN_D3);
  }
  #else
  /**
    * @brief  SRD domain follows CPU subsystem modes
    * @rmtoll CPUCR     RUN_SRD      pwrCPUDisableSRDRunInLowPowerMode
    * @retval None
    */
  inline void pwrCPUDisableSRDRunInLowPowerMode(void)
  {
    CLEAR_BIT(PWR->CPUCR, PWR_CPUCR_RUN_SRD);
  }
  #endif /* PWR_CPUCR_PDDS_D2 */

  #if defined (DUAL_CORE)
  /**
    * @brief  D3 domain follows CPU2 subsystem modes
    * @rmtoll CPU2CR     RUN_D3       PpwrCPU2DisableD3RunInLowPowerMode
    * @retval None
    */
  inline void PpwrCPU2DisableD3RunInLowPowerMode(void)
  {
    CLEAR_BIT(PWR->CPU2CR, PWR_CPU2CR_RUN_D3);
  }
  #endif /* DUAL_CORE */

  #if defined (PWR_CPUCR_PDDS_D2)
  /**
    * @brief  Check if D3 is kept in Run mode when CPU enters low power mode
    * @rmtoll CPUCR     RUN_D3    pwrCPUIsEnabledD3RunInLowPowerMode
    * @retval State of bit (1 or 0).
    */
  inline bool pwrCPUIsEnabledD3RunInLowPowerMode(void)
  {
    return ((READ_BIT(PWR->CPUCR, PWR_CPUCR_RUN_D3) == (PWR_CPUCR_RUN_D3)) ? true : false);
  }
  #else
  /**
    * @brief  Check if SRD is kept in Run mode when CPU enters low power mode
    * @rmtoll CPUCR     RUN_SRD    pwrCPUIsEnabledSRDRunInLowPowerMode
    * @retval State of bit (1 or 0).
    */
  inline bool pwrCPUIsEnabledSRDRunInLowPowerMode(void)
  {
    return ((READ_BIT(PWR->CPUCR, PWR_CPUCR_RUN_SRD) == (PWR_CPUCR_RUN_SRD)) ? true : false);
  }
  #endif /* PWR_CPUCR_PDDS_D2 */

  #if defined (DUAL_CORE)
  /**
    * @brief  Check if D3 is kept in Run mode when CPU2 enters low power mode
    * @rmtoll CPU2CR     RUN_D3    PpwrCPU2IsEnabledD3RunInLowPowerMode
    * @retval State of bit (1 or 0).
    */
  inline uint32_t PpwrCPU2IsEnabledD3RunInLowPowerMode(void)
  {
    return ((READ_BIT(PWR->CPU2CR, PWR_CPU2CR_RUN_D3) == (PWR_CPU2CR_RUN_D3)) ? true : false);
  }
  #endif /* DUAL_CORE */

  /**
    * @brief  Set the main internal Regulator output voltage
    * @rmtoll D3CR    VOS       pwrSetRegulVoltageScaling
    * @param  VoltageScaling This parameter can be one of the following values:
    *         @arg @ref pwrREGU_VOLTAGE_SCALE0
    *         @arg @ref pwrREGU_VOLTAGE_SCALE1
    *         @arg @ref pwrREGU_VOLTAGE_SCALE2
    *         @arg @ref pwrREGU_VOLTAGE_SCALE3
    * @note   For all H7 lines except STM32H7Axxx and STM32H7Bxxx lines, VOS0
    *         is applied when PWR_D3CR_VOS[1:0] = 0b11 and  SYSCFG_PWRCR_ODEN = 0b1.
    * @retval None
    */
  inline void pwrSetRegulVoltageScaling(PWRREGUVoltageRunModeScaling VoltageScaling)
  {
  #if defined (PWR_CPUCR_PDDS_D2)
    MODIFY_REG(PWR->D3CR, PWR_D3CR_VOS, VoltageScaling);
  #else
    MODIFY_REG(PWR->SRDCR, PWR_SRDCR_VOS, VoltageScaling);
  #endif /* PWR_CPUCR_PDDS_D2 */
  }

  /**
    * @brief  Get the main internal Regulator output voltage
    * @rmtoll D3CR    VOS       pwrGetRegulVoltageScaling
    * @note   For all H7 lines except STM32H7Axxx and STM32H7Bxxx lines, checking
    *         VOS0 need the check of PWR_D3CR_VOS[1:0] field and SYSCFG_PWRCR_ODEN bit.
    * @retval Returned value can be one of the following values:
    *         @arg @ref pwrREGU_VOLTAGE_SCALE0
    *         @arg @ref pwrREGU_VOLTAGE_SCALE1
    *         @arg @ref pwrREGU_VOLTAGE_SCALE2
    *         @arg @ref pwrREGU_VOLTAGE_SCALE3
    */
  inline PWRREGUVoltageRunModeScaling pwrGetRegulVoltageScaling(void)
  {
  #if defined (PWR_CPUCR_PDDS_D2)
    return (PWRREGUVoltageRunModeScaling)(READ_BIT(PWR->D3CR, PWR_D3CR_VOS));
  #else
    return (PWRREGUVoltageRunModeScaling)(READ_BIT(PWR->SRDCR, PWR_SRDCR_VOS));
  #endif /* PWR_CPUCR_PDDS_D2 */
  }

  /**
    * @brief  Enable the WakeUp PINx functionality
    * @rmtoll WKUPEPR   WKUPEN1       pwrEnableWakeUpPin\n
    *         WKUPEPR   WKUPEN2       pwrEnableWakeUpPin\n
    *         WKUPEPR   WKUPEN3       pwrEnableWakeUpPin\n
    *         WKUPEPR   WKUPEN4       pwrEnableWakeUpPin\n
    *         WKUPEPR   WKUPEN5       pwrEnableWakeUpPin\n
    *         WKUPEPR   WKUPEN6       pwrEnableWakeUpPin
    * @param  WakeUpPin This parameter can be one of the following values:
    *         @arg @ref pwrWAKEUP_PIN1
    *         @arg @ref pwrWAKEUP_PIN2
    *         @arg @ref pwrWAKEUP_PIN3 (*)
    *         @arg @ref pwrWAKEUP_PIN4
    *         @arg @ref pwrWAKEUP_PIN5 (*)
    *         @arg @ref pwrWAKEUP_PIN6
    *
    *         (*) value not defined in all devices.
    *
    * @retval None
    */
  inline void pwrEnableWakeUpPin(PWRWakeUpPins WakeUpPin)
  {
    SET_BIT(PWR->WKUPEPR, WakeUpPin);
  }

  /**
    * @brief  Disable the WakeUp PINx functionality
    * @rmtoll WKUPEPR   WKUPEN1       pwrDisableWakeUpPin\n
    *         WKUPEPR   WKUPEN2       pwrDisableWakeUpPin\n
    *         WKUPEPR   WKUPEN3       pwrDisableWakeUpPin\n
    *         WKUPEPR   WKUPEN4       pwrDisableWakeUpPin\n
    *         WKUPEPR   WKUPEN5       pwrDisableWakeUpPin\n
    *         WKUPEPR   WKUPEN6       pwrDisableWakeUpPin
    * @param  WakeUpPin This parameter can be one of the following values:
    *         @arg @ref pwrWAKEUP_PIN1
    *         @arg @ref pwrWAKEUP_PIN2
    *         @arg @ref pwrWAKEUP_PIN3 (*)
    *         @arg @ref pwrWAKEUP_PIN4
    *         @arg @ref pwrWAKEUP_PIN5 (*)
    *         @arg @ref pwrWAKEUP_PIN6
    *
    *         (*) value not defined in all devices.
    *
    * @retval None
    */
  inline void pwrDisableWakeUpPin(PWRWakeUpPins WakeUpPin)
  {
    CLEAR_BIT(PWR->WKUPEPR, WakeUpPin);
  }

  /**
    * @brief  Check if the WakeUp PINx functionality is enabled
    * @rmtoll WKUPEPR   WKUPEN1       pwrIsEnabledWakeUpPin\n
    *         WKUPEPR   WKUPEN2       pwrIsEnabledWakeUpPin\n
    *         WKUPEPR   WKUPEN3       pwrIsEnabledWakeUpPin\n
    *         WKUPEPR   WKUPEN4       pwrIsEnabledWakeUpPin\n
    *         WKUPEPR   WKUPEN5       pwrIsEnabledWakeUpPin\n
    *         WKUPEPR   WKUPEN6       pwrIsEnabledWakeUpPin
    * @param  WakeUpPin This parameter can be one of the following values:
    *         @arg @ref pwrWAKEUP_PIN1
    *         @arg @ref pwrWAKEUP_PIN2
    *         @arg @ref pwrWAKEUP_PIN3 (*)
    *         @arg @ref pwrWAKEUP_PIN4
    *         @arg @ref pwrWAKEUP_PIN5 (*)
    *         @arg @ref pwrWAKEUP_PIN6
    *
    *         (*) value not defined in all devices.
    *
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsEnabledWakeUpPin(PWRWakeUpPins WakeUpPin)
  {
    return ((READ_BIT(PWR->WKUPEPR, WakeUpPin) == (WakeUpPin)) ? true : false);
  }

  /**
    * @brief  Set the Wake-Up pin polarity low for the event detection
    * @rmtoll WKUPEPR   WKUPP1       pwrSetWakeUpPinPolarityLow\n
    *         WKUPEPR   WKUPP2       pwrSetWakeUpPinPolarityLow\n
    *         WKUPEPR   WKUPP3       pwrSetWakeUpPinPolarityLow\n
    *         WKUPEPR   WKUPP4       pwrSetWakeUpPinPolarityLow\n
    *         WKUPEPR   WKUPP5       pwrSetWakeUpPinPolarityLow\n
    *         WKUPEPR   WKUPP6       pwrSetWakeUpPinPolarityLow
    * @param  WakeUpPin This parameter can be one of the following values:
    *         @arg @ref pwrWAKEUP_PIN1
    *         @arg @ref pwrWAKEUP_PIN2
    *         @arg @ref pwrWAKEUP_PIN3 (*)
    *         @arg @ref pwrWAKEUP_PIN4
    *         @arg @ref pwrWAKEUP_PIN5 (*)
    *         @arg @ref pwrWAKEUP_PIN6
    *
    *         (*) value not defined in all devices.
    *
    * @retval None
    */
  inline void pwrSetWakeUpPinPolarityLow(PWRWakeUpPins WakeUpPin)
  {
    SET_BIT(PWR->WKUPEPR, (WakeUpPin << PWR_WKUPEPR_WKUPP1_Pos));
  }

  /**
    * @brief  Set the Wake-Up pin polarity high for the event detection
    * @rmtoll WKUPEPR   WKUPP1       pwrSetWakeUpPinPolarityHigh\n
    *         WKUPEPR   WKUPP2       pwrSetWakeUpPinPolarityHigh\n
    *         WKUPEPR   WKUPP3       pwrSetWakeUpPinPolarityHigh\n
    *         WKUPEPR   WKUPP4       pwrSetWakeUpPinPolarityHigh\n
    *         WKUPEPR   WKUPP5       pwrSetWakeUpPinPolarityHigh\n
    *         WKUPEPR   WKUPP6       pwrSetWakeUpPinPolarityHigh
    * @param  WakeUpPin This parameter can be one of the following values:
    *         @arg @ref pwrWAKEUP_PIN1
    *         @arg @ref pwrWAKEUP_PIN2
    *         @arg @ref pwrWAKEUP_PIN3 (*)
    *         @arg @ref pwrWAKEUP_PIN4
    *         @arg @ref pwrWAKEUP_PIN5 (*)
    *         @arg @ref pwrWAKEUP_PIN6
    *
    *         (*) value not defined in all devices.
    *
    * @retval None
    */
  inline void pwrSetWakeUpPinPolarityHigh(PWRWakeUpPins WakeUpPin)
  {
    CLEAR_BIT(PWR->WKUPEPR, (WakeUpPin << PWR_WKUPEPR_WKUPP1_Pos));
  }

  /**
    * @brief  Get the Wake-Up pin polarity for the event detection
    * @rmtoll WKUPEPR   WKUPP1       pwrIsWakeUpPinPolarityLow\n
    *         WKUPEPR   WKUPP2       pwrIsWakeUpPinPolarityLow\n
    *         WKUPEPR   WKUPP3       pwrIsWakeUpPinPolarityLow\n
    *         WKUPEPR   WKUPP4       pwrIsWakeUpPinPolarityLow\n
    *         WKUPEPR   WKUPP5       pwrIsWakeUpPinPolarityLow\n
    *         WKUPEPR   WKUPP6       pwrIsWakeUpPinPolarityLow
    * @param  WakeUpPin This parameter can be one of the following values:
    *         @arg @ref pwrWAKEUP_PIN1
    *         @arg @ref pwrWAKEUP_PIN2
    *         @arg @ref pwrWAKEUP_PIN3 (*)
    *         @arg @ref pwrWAKEUP_PIN4
    *         @arg @ref pwrWAKEUP_PIN5 (*)
    *         @arg @ref pwrWAKEUP_PIN6
    *
    *         (*) value not defined in all devices.
    *
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsWakeUpPinPolarityLow(PWRWakeUpPins WakeUpPin)
  {
    return ((READ_BIT(PWR->WKUPEPR, ((uint32_t)WakeUpPin << PWR_WKUPEPR_WKUPP1_Pos)) == ((uint32_t)WakeUpPin << PWR_WKUPEPR_WKUPP1_Pos)) ? true : false);
  }

  /**
    * @brief  Set the Wake-Up pin Pull None
    * @rmtoll WKUPEPR   WKUPPUPD1       pwrSetWakeUpPinPullNone\n
    *         WKUPEPR   WKUPPUPD2       pwrSetWakeUpPinPullNone\n
    *         WKUPEPR   WKUPPUPD3       pwrSetWakeUpPinPullNone\n
    *         WKUPEPR   WKUPPUPD4       pwrSetWakeUpPinPullNone\n
    *         WKUPEPR   WKUPPUPD5       pwrSetWakeUpPinPullNone\n
    *         WKUPEPR   WKUPPUPD6       pwrSetWakeUpPinPullNone
    * @param  WakeUpPin This parameter can be one of the following values:
    *         @arg @ref pwrWAKEUP_PIN1
    *         @arg @ref pwrWAKEUP_PIN2
    *         @arg @ref pwrWAKEUP_PIN3 (*)
    *         @arg @ref pwrWAKEUP_PIN4
    *         @arg @ref pwrWAKEUP_PIN5 (*)
    *         @arg @ref pwrWAKEUP_PIN6
    *
    *         (*) value not defined in all devices.
    *
    * @retval None
    */
  inline void pwrSetWakeUpPinPullNone(PWRWakeUpPins WakeUpPin)
  {
    MODIFY_REG(PWR->WKUPEPR, \
              (PWR_WKUPEPR_WKUPPUPD1 << ((PWR_WAKEUP_PINS_PULL_SHIFT_OFFSET * POSITION_VAL(WakeUpPin)) & PWR_WAKEUP_PINS_MAX_SHIFT_MASK)), \
              (PWR_WAKEUP_PIN_NOPULL << ((PWR_WKUPEPR_WKUPPUPD1_Pos + (PWR_WAKEUP_PINS_PULL_SHIFT_OFFSET * POSITION_VAL(WakeUpPin))) & PWR_WAKEUP_PINS_MAX_SHIFT_MASK)));
  }

  /**
    * @brief  Set the Wake-Up pin Pull Up
    * @rmtoll WKUPEPR   WKUPPUPD1       pwrSetWakeUpPinPullUp\n
    *         WKUPEPR   WKUPPUPD2       pwrSetWakeUpPinPullUp\n
    *         WKUPEPR   WKUPPUPD3       pwrSetWakeUpPinPullUp\n
    *         WKUPEPR   WKUPPUPD4       pwrSetWakeUpPinPullUp\n
    *         WKUPEPR   WKUPPUPD5       pwrSetWakeUpPinPullUp\n
    *         WKUPEPR   WKUPPUPD6       pwrSetWakeUpPinPullUp
    * @param  WakeUpPin This parameter can be one of the following values:
    *         @arg @ref pwrWAKEUP_PIN1
    *         @arg @ref pwrWAKEUP_PIN2
    *         @arg @ref pwrWAKEUP_PIN3 (*)
    *         @arg @ref pwrWAKEUP_PIN4
    *         @arg @ref pwrWAKEUP_PIN5 (*)
    *         @arg @ref pwrWAKEUP_PIN6
    *
    *         (*) value not defined in all devices.
    *
    * @retval None
    */
  inline void pwrSetWakeUpPinPullUp(PWRWakeUpPins WakeUpPin)
  {
    MODIFY_REG(PWR->WKUPEPR, \
              (PWR_WKUPEPR_WKUPPUPD1 << ((PWR_WAKEUP_PINS_PULL_SHIFT_OFFSET * POSITION_VAL(WakeUpPin)) & PWR_WAKEUP_PINS_MAX_SHIFT_MASK)), \
              (PWR_WAKEUP_PIN_PULLUP << ((PWR_WKUPEPR_WKUPPUPD1_Pos + (PWR_WAKEUP_PINS_PULL_SHIFT_OFFSET * POSITION_VAL(WakeUpPin))) & PWR_WAKEUP_PINS_MAX_SHIFT_MASK)));
  }

  /**
    * @brief  Set the Wake-Up pin Pull Down
    * @rmtoll WKUPEPR   WKUPPUPD1       pwrSetWakeUpPinPullDown\n
    *         WKUPEPR   WKUPPUPD2       pwrSetWakeUpPinPullDown\n
    *         WKUPEPR   WKUPPUPD3       pwrSetWakeUpPinPullDown\n
    *         WKUPEPR   WKUPPUPD4       pwrSetWakeUpPinPullDown\n
    *         WKUPEPR   WKUPPUPD5       pwrSetWakeUpPinPullDown\n
    *         WKUPEPR   WKUPPUPD6       pwrSetWakeUpPinPullDown
    * @param  WakeUpPin This parameter can be one of the following values:
    *         @arg @ref pwrWAKEUP_PIN1
    *         @arg @ref pwrWAKEUP_PIN2
    *         @arg @ref pwrWAKEUP_PIN3 (*)
    *         @arg @ref pwrWAKEUP_PIN4
    *         @arg @ref pwrWAKEUP_PIN5 (*)
    *         @arg @ref pwrWAKEUP_PIN6
    *
    *         (*) value not defined in all devices.
    *
    * @retval None
    */
  inline void pwrSetWakeUpPinPullDown(PWRWakeUpPins WakeUpPin)
  {
    MODIFY_REG(PWR->WKUPEPR, \
              (PWR_WKUPEPR_WKUPPUPD1 << ((PWR_WAKEUP_PINS_PULL_SHIFT_OFFSET * POSITION_VAL(WakeUpPin)) & PWR_WAKEUP_PINS_MAX_SHIFT_MASK)), \
              (PWR_WAKEUP_PIN_PULLDOWN << ((PWR_WKUPEPR_WKUPPUPD1_Pos + (PWR_WAKEUP_PINS_PULL_SHIFT_OFFSET * POSITION_VAL(WakeUpPin))) & PWR_WAKEUP_PINS_MAX_SHIFT_MASK)));
  }

  /**
    * @brief  Get the Wake-Up pin pull
    * @rmtoll WKUPEPR   WKUPPUPD1       pwrGetWakeUpPinPull\n
    *         WKUPEPR   WKUPPUPD2       pwrGetWakeUpPinPull\n
    *         WKUPEPR   WKUPPUPD3       pwrGetWakeUpPinPull\n
    *         WKUPEPR   WKUPPUPD4       pwrGetWakeUpPinPull\n
    *         WKUPEPR   WKUPPUPD5       pwrGetWakeUpPinPull\n
    *         WKUPEPR   WKUPPUPD6       pwrGetWakeUpPinPull
    * @param  WakeUpPin This parameter can be one of the following values:
    *         @arg @ref pwrWAKEUP_PIN1
    *         @arg @ref pwrWAKEUP_PIN2
    *         @arg @ref pwrWAKEUP_PIN3 (*)
    *         @arg @ref pwrWAKEUP_PIN4
    *         @arg @ref pwrWAKEUP_PIN5 (*)
    *         @arg @ref pwrWAKEUP_PIN6
    *
    *         (*) value not defined in all devices.
    *
    * @retval Returned value can be one of the following values:
    *         @arg @ref pwrWAKEUP_PIN_NOPULL
    *         @arg @ref pwrWAKEUP_PIN_PULLUP
    *         @arg @ref pwrWAKEUP_PIN_PULLDOWN
    */
  inline PWRWakeUpPinPull pwrGetWakeUpPinPull(PWRWakeUpPins WakeUpPin)
  {
    uint32_t regValue = READ_BIT(PWR->WKUPEPR, (PWR_WKUPEPR_WKUPPUPD1 << ((PWR_WAKEUP_PINS_PULL_SHIFT_OFFSET * POSITION_VAL(WakeUpPin)) & PWR_WAKEUP_PINS_MAX_SHIFT_MASK)));

    return (PWRWakeUpPinPull)(regValue >> ((PWR_WKUPEPR_WKUPPUPD1_Pos + (PWR_WAKEUP_PINS_PULL_SHIFT_OFFSET * POSITION_VAL(WakeUpPin))) & PWR_WAKEUP_PINS_MAX_SHIFT_MASK));
  }

  /** @defgroup PWR_LL_EF_FLAG_Management FLAG_Management
    * @{
    */

  /**
    * @brief  Indicate whether VDD voltage is below the selected PVD threshold
    * @rmtoll CSR1   PVDO       pwrIsActiveFlagPVDO
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsActiveFlagPVDO(void)
  {
    return ((READ_BIT(PWR->CSR1, PWR_CSR1_PVDO) == (PWR_CSR1_PVDO)) ? true : false);
  }

  /**
    * @brief  Indicate whether the voltage level is ready for current actual used VOS
    * @rmtoll CSR1   ACTVOSRDY       pwrIsActiveFlagACTVOS
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsActiveFlagACTVOS(void)
  {
    return ((READ_BIT(PWR->CSR1, PWR_CSR1_ACTVOSRDY) == (PWR_CSR1_ACTVOSRDY)) ? true : false);
  }

  /**
    * @brief  Indicate whether VDDA voltage is below the selected AVD threshold
    * @rmtoll CSR1   AVDO       pwrIsActiveFlagAVDO
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsActiveFlagAVDO(void)
  {
    return ((READ_BIT(PWR->CSR1, PWR_CSR1_AVDO) == (PWR_CSR1_AVDO)) ? true : false);
  }

  #if defined (PWR_CSR1_MMCVDO)
  /**
    * @brief  Indicate whether VDDMMC voltage is below 1V2
    * @rmtoll CSR1   MMCVDO     pwrIsActiveFlagMMCVDO
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsActiveFlagMMCVDO(void)
  {
    return ((READ_BIT(PWR->CSR1, PWR_CSR1_MMCVDO) == (PWR_CSR1_MMCVDO)) ? true : false);
  }
  #endif /* PWR_CSR1_MMCVDO */

  /**
    * @brief  Get Backup Regulator ready Flag
    * @rmtoll CR2   BRRDY       pwrIsActiveFlagBRR
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsActiveFlagBRR(void)
  {
    return ((READ_BIT(PWR->CR2, PWR_CR2_BRRDY) == (PWR_CR2_BRRDY)) ? true : false);
  }

  /**
    * @brief  Indicate whether the VBAT level is above or below low threshold
    * @rmtoll CR2   VBATL       pwrIsActiveFlagVBATL
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsActiveFlagVBATL(void)
  {
    return ((READ_BIT(PWR->CR2, PWR_CR2_VBATL) == (PWR_CR2_VBATL)) ? true : false);
  }

  /**
    * @brief  Indicate whether the VBAT level is above or below high threshold
    * @rmtoll CR2   VBATH       pwrIsActiveFlagVBATH
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsActiveFlagVBATH(void)
  {
    return ((READ_BIT(PWR->CR2, PWR_CR2_VBATH) == (PWR_CR2_VBATH)) ? true : false);
  }

  /**
    * @brief  Indicate whether the CPU temperature level is above or below low threshold
    * @rmtoll CR2   TEMPL       pwrIsActiveFlagTEMPL
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsActiveFlagTEMPL(void)
  {
    return ((READ_BIT(PWR->CR2, PWR_CR2_TEMPL) == (PWR_CR2_TEMPL)) ? true : false);
  }

  /**
    * @brief  Indicate whether the CPU temperature level is above or below high threshold
    * @rmtoll CR2   TEMPH       pwrIsActiveFlagTEMPH
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsActiveFlagTEMPH(void)
  {
    return ((READ_BIT(PWR->CR2, PWR_CR2_TEMPH) == (PWR_CR2_TEMPH)) ? true : false);
  }

  #if defined (SMPS)
  /**
    * @brief  Indicate whether the SMPS external supply is ready or not
    * @rmtoll CR3   SMPSEXTRDY       pwrIsActiveFlagSMPSEXT
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsActiveFlagSMPSEXT(void)
  {
    return ((READ_BIT(PWR->CR3, PWR_CR3_SMPSEXTRDY) == (PWR_CR3_SMPSEXTRDY)) ? true : false);
  }
  #endif /* SMPS */

  /**
    * @brief  Indicate whether the USB supply is ready or not
    * @rmtoll CR3   USBRDY       pwrIsActiveFlagUSB
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsActiveFlagUSB(void)
  {
    return ((READ_BIT(PWR->CR3, PWR_CR3_USB33RDY) == (PWR_CR3_USB33RDY)) ? true : false);
  }

  #if defined (DUAL_CORE)
  /**
    * @brief  Get HOLD2 Flag
    * @rmtoll CPUCR   HOLD2F       pwrIsActiveFlagHOLD2
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsActiveFlagHOLD2(void)
  {
    return ((READ_BIT(PWR->CPUCR, PWR_CPUCR_HOLD2F) == (PWR_CPUCR_HOLD2F)) ? true : false);
  }

  /**
    * @brief  Get HOLD1 Flag
    * @rmtoll CPU2CR   HOLD1F       pwrIsActiveFlagHOLD1
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsActiveFlagHOLD1(void)
  {
    return ((READ_BIT(PWR->CPU2CR, PWR_CPU2CR_HOLD1F) == (PWR_CPU2CR_HOLD1F)) ? true : false);
  }
  #endif /* DUAL_CORE */

  /**
    * @brief  Get CPU System Stop Flag
    * @rmtoll CPUCR   STOPF       pwrCPUIsActiveFlagSTOP
    * @retval State of bit (1 or 0).
    */
  inline bool pwrCPUIsActiveFlagSTOP(void)
  {
    return ((READ_BIT(PWR->CPUCR, PWR_CPUCR_STOPF) == (PWR_CPUCR_STOPF)) ? true : false);
  }

  #if defined (DUAL_CORE)
  /**
    * @brief  Get CPU2 System Stop Flag
    * @rmtoll CPU2CR   STOPF       pwrCPU2IsActiveFlagSTOP
    * @retval State of bit (1 or 0).
    */
  inline uint32_t pwrCPU2IsActiveFlagSTOP(void)
  {
    return ((READ_BIT(PWR->CPU2CR, PWR_CPU2CR_STOPF) == (PWR_CPU2CR_STOPF)) ? true : false);
  }
  #endif /* DUAL_CORE */

  /**
    * @brief  Get CPU System Standby Flag
    * @rmtoll CPUCR   SBF       pwrCPUIsActiveFlagSB
    * @retval State of bit (1 or 0).
    */
  inline bool pwrCPUIsActiveFlagSB(void)
  {
    return ((READ_BIT(PWR->CPUCR, PWR_CPUCR_SBF) == (PWR_CPUCR_SBF)) ? true : false);
  }

  #if defined (DUAL_CORE)
  /**
    * @brief  Get CPU2 System Standby Flag
    * @rmtoll CPU2CR   SBF       PpwrCPU2IsActiveFlagSB
    * @retval State of bit (1 or 0).
    */
  inline uint32_t pwrCPU2IsActiveFlagSB(void)
  {
    return ((READ_BIT(PWR->CPU2CR, PWR_CPU2CR_SBF) == (PWR_CPU2CR_SBF)) ? true : false);
  }
  #endif /* DUAL_CORE */

  #if defined (PWR_CPUCR_SBF_D1)
  /**
    * @brief  Get CPU D1 Domain Standby Flag
    * @rmtoll CPUCR   SBF_D1       pwrCPUIsActiveFlagSBD1
    * @retval State of bit (1 or 0).
    */
  inline bool pwrCPUIsActiveFlagSBD1(void)
  {
    return ((READ_BIT(PWR->CPUCR, PWR_CPUCR_SBF_D1) == (PWR_CPUCR_SBF_D1)) ? true : false);
  }
  #endif /* PWR_CPUCR_SBF_D1 */

  #if defined (DUAL_CORE)
  /**
    * @brief  Get CPU2 D1 Domain Standby Flag
    * @rmtoll CPU2CR   SBF_D1       PpwrCPU2IsActiveFlagSBD1
    * @retval State of bit (1 or 0).
    */
  inline uint32_t PpwrCPU2IsActiveFlagSBD1(void)
  {
    return ((READ_BIT(PWR->CPU2CR, PWR_CPU2CR_SBF_D1) == (PWR_CPU2CR_SBF_D1)) ? true : false);
  }
  #endif /* DUAL_CORE */

  #if defined (PWR_CPUCR_SBF_D2)
  /**
    * @brief  Get CPU D2 Domain Standby Flag
    * @rmtoll CPUCR   SBF_D2       pwrCPUIsActiveFlagSBD2
    * @retval State of bit (1 or 0).
    */
  inline bool pwrCPUIsActiveFlagSBD2(void)
  {
    return ((READ_BIT(PWR->CPUCR, PWR_CPUCR_SBF_D2) == (PWR_CPUCR_SBF_D2)) ? true : false);
  }
  #endif /* PWR_CPUCR_SBF_D2 */

  #if defined (DUAL_CORE)
  /**
    * @brief  Get CPU2 D2 Domain Standby Flag
    * @rmtoll CPU2CR   SBF_D2       PpwrCPU2IsActiveFlagSBD2
    * @retval State of bit (1 or 0).
    */
  inline bool pwrCPU2IsActiveFlagSBD2(void)
  {
    return ((READ_BIT(PWR->CPU2CR, PWR_CPU2CR_SBF_D2) == (PWR_CPU2CR_SBF_D2)) ? true : false);
  }
  #endif /* DUAL_CORE */


  /**
    * @brief  Indicate whether the Regulator is ready in the selected voltage range
    *         or if its output voltage is still changing to the required voltage level
    * @rmtoll D3CR   VOSRDY       pwrIsActiveFlagVOS
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsActiveFlagVOS(void)
  {
  #if defined (PWR_CPUCR_PDDS_D2)
    return ((READ_BIT(PWR->D3CR, PWR_D3CR_VOSRDY) == (PWR_D3CR_VOSRDY)) ? true : false);
  #else
    return ((READ_BIT(PWR->SRDCR, PWR_SRDCR_VOSRDY) == (PWR_SRDCR_VOSRDY)) ? true : false);
  #endif /* PWR_CPUCR_PDDS_D2 */
  }

  /**
    * @brief  Get Wake-up Flag 6
    * @rmtoll WKUPFR          WKUPF6          pwrIsActiveFlagWU6
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsActiveFlagWU6(void)
  {
    return ((READ_BIT(PWR->WKUPFR, PWR_WKUPFR_WKUPF6) == (PWR_WKUPFR_WKUPF6)) ? true : false);
  }

  #if defined (PWR_WKUPFR_WKUPF5)
  /**
    * @brief  Get Wake-up Flag 5
    * @rmtoll WKUPFR          WKUPF5          pwrIsActiveFlagWU5
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsActiveFlagWU5(void)
  {
    return ((READ_BIT(PWR->WKUPFR, PWR_WKUPFR_WKUPF5) == (PWR_WKUPFR_WKUPF5)) ? true : false);
  }
  #endif /* defined (PWR_WKUPFR_WKUPF5) */

  /**
    * @brief  Get Wake-up Flag 4
    * @rmtoll WKUPFR          WKUPF4          pwrIsActiveFlagWU4
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsActiveFlagWU4(void)
  {
    return ((READ_BIT(PWR->WKUPFR, PWR_WKUPFR_WKUPF4) == (PWR_WKUPFR_WKUPF4)) ? true : false);
  }

  #if defined (PWR_WKUPFR_WKUPF3)
  /**
    * @brief  Get Wake-up Flag 3
    * @rmtoll WKUPFR          WKUPF3          pwrIsActiveFlagWU3
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsActiveFlagWU3(void)
  {
    return ((READ_BIT(PWR->WKUPFR, PWR_WKUPFR_WKUPF3) == (PWR_WKUPFR_WKUPF3)) ? true : false);
  }
  #endif /* defined (PWR_WKUPFR_WKUPF3) */

  /**
    * @brief  Get Wake-up Flag 2
    * @rmtoll WKUPFR          WKUPF2          pwrIsActiveFlagWU2
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsActiveFlagWU2(void)
  {
    return ((READ_BIT(PWR->WKUPFR, PWR_WKUPFR_WKUPF2) == (PWR_WKUPFR_WKUPF2)) ? true : false);
  }

  /**
    * @brief  Get Wake-up Flag 1
    * @rmtoll WKUPFR          WKUPF1          pwrIsActiveFlagWU1
    * @retval State of bit (1 or 0).
    */
  inline bool pwrIsActiveFlagWU1(void)
  {
    return ((READ_BIT(PWR->WKUPFR, PWR_WKUPFR_WKUPF1) == (PWR_WKUPFR_WKUPF1)) ? true : false);
  }

  /**
    * @brief  Clear CPU STANDBY, STOP and HOLD flags
    * @rmtoll CPUCR   CSSF       pwrClearFlagCPU
    * @retval None
    */
  inline void pwrClearFlagCPU(void)
  {
    SET_BIT(PWR->CPUCR, PWR_CPUCR_CSSF);
  }

  #if defined (DUAL_CORE)
  /**
    * @brief  Clear CPU2 STANDBY, STOP and HOLD flags
    * @rmtoll CPU2CR   CSSF       pwrClearFlagCPU2
    * @retval None
    */
  inline void pwrClearFlagCPU2(void)
  {
    SET_BIT(PWR->CPU2CR, PWR_CPU2CR_CSSF);
  }
  #endif /* DUAL_CORE */

  /**
    * @brief  Clear Wake-up Flag 6
    * @rmtoll WKUPCR          WKUPC6         pwrClearFlagWU6
    * @retval None
    */
  inline void pwrClearFlagWU6(void)
  {
    WRITE_REG(PWR->WKUPCR, PWR_WKUPCR_WKUPC6);
  }

  #if defined (PWR_WKUPCR_WKUPC5)
  /**
    * @brief  Clear Wake-up Flag 5
    * @rmtoll WKUPCR          WKUPC5         pwrClearFlagWU5
    * @retval None
    */
  inline void pwrClearFlagWU5(void)
  {
    WRITE_REG(PWR->WKUPCR, PWR_WKUPCR_WKUPC5);
  }
  #endif /* defined (PWR_WKUPCR_WKUPC5) */

  /**
    * @brief  Clear Wake-up Flag 4
    * @rmtoll WKUPCR          WKUPC4         pwrClearFlagWU4
    * @retval None
    */
  inline void pwrClearFlagWU4(void)
  {
    WRITE_REG(PWR->WKUPCR, PWR_WKUPCR_WKUPC4);
  }

  #if defined (PWR_WKUPCR_WKUPC3)
  /**
    * @brief  Clear Wake-up Flag 3
    * @rmtoll WKUPCR          WKUPC3         pwrClearFlagWU3
    * @retval None
    */
  inline void pwrClearFlagWU3(void)
  {
    WRITE_REG(PWR->WKUPCR, PWR_WKUPCR_WKUPC3);
  }
  #endif /* defined (PWR_WKUPCR_WKUPC3) */

  /**
    * @brief  Clear Wake-up Flag 2
    * @rmtoll WKUPCR          WKUPC2         pwrClearFlagWU2
    * @retval None
    */
  inline void pwrClearFlagWU2(void)
  {
    WRITE_REG(PWR->WKUPCR, PWR_WKUPCR_WKUPC2);
  }

  /**
    * @brief  Clear Wake-up Flag 1
    * @rmtoll WKUPCR          WKUPC1         pwrClearFlagWU1
    * @retval None
    */
  inline void pwrClearFlagWU1(void)
  {
    WRITE_REG(PWR->WKUPCR, PWR_WKUPCR_WKUPC1);
  }

  /** @defgroup PWR_LL_EF_Init De-initialization function
    * @{
    */
  eResult pwrDeInit(void)
  {
    #if defined (PWR_WKUPCR_WKUPC3)
      WRITE_REG(PWR->WKUPCR, (PWR_WKUPCR_WKUPC1 | PWR_WKUPCR_WKUPC2 | PWR_WKUPCR_WKUPC3 | \
                              PWR_WKUPCR_WKUPC4 | PWR_WKUPCR_WKUPC5 | PWR_WKUPCR_WKUPC6));
    #else
      WRITE_REG(PWR->WKUPCR, (PWR_WKUPCR_WKUPC1 | PWR_WKUPCR_WKUPC2 | \
                              PWR_WKUPCR_WKUPC4 | PWR_WKUPCR_WKUPC6));
    #endif /* defined (PWR_WKUPCR_WKUPC3) */
      return E_RESULT_OK;
  }
private:
    PWRX()
    {

    }
    ~PWRX()
    {

    }
    PWRX(const PWRX&) = delete;
    PWRX(PWRX&&) = delete;
    PWRX& operator=(const PWRX&) = delete;
    PWRX& operator=(PWRX&&) = delete;
};