#pragma once 
#include "common.hpp"

/* Masks Definition */
#define RTC_INIT_MASK              0xFFFFFFFFU
#define RTC_RSF_MASK               0xFFFFFF5FU

/* Write protection defines */
#define RTC_WRITE_PROTECTION_DISABLE  0xFFU
#define RTC_WRITE_PROTECTION_ENABLE_1 0xCAU
#define RTC_WRITE_PROTECTION_ENABLE_2 0x53U

/* Defines used to combine date & time */
#define RTC_OFFSET_WEEKDAY            24U
#define RTC_OFFSET_DAY                16U
#define RTC_OFFSET_MONTH              8U
#define RTC_OFFSET_HOUR               16U
#define RTC_OFFSET_MINUTE             8U

/** @defgroup EC_FORMAT FORMAT
  * @{
  */
enum RTCDataFormat
{
    RTC_FORMAT_BIN         =         0x00000000U, /*!< Binary data format */
    RTC_FORMAT_BCD         =         0x00000001U  /*!< BCD data format */
};

/** @defgroup EC_ALMA_WEEKDAY_SELECTION RTC Alarm A Date WeekDay
  * @{
  */
enum RTCAlarmAWeekDaySelect
{
    RTC_ALMA_DATEWEEKDAYSEL_DATE    =  0x00000000U,             /*!< Alarm A Date is selected */
    RTC_ALMA_DATEWEEKDAYSEL_WEEKDAY =  RTC_ALRMAR_WDSEL         /*!< Alarm A WeekDay is selected */
};

/** @defgroup EC_ALMB_WEEKDAY_SELECTION RTC Alarm B Date WeekDay
  * @{
  */
enum RTCAlarmBWeekDaySelect
{
    RTC_ALMB_DATEWEEKDAYSEL_DATE        =  0x00000000U,             /*!< Alarm B Date is selected */
    RTC_ALMB_DATEWEEKDAYSEL_WEEKDAY     =  RTC_ALRMBR_WDSEL         /*!< Alarm B WeekDay is selected */
};

/** @defgroup EC_GET_FLAG Get Flags Defines
  * @brief    Flags defines which can be used with RTC_ReadReg function
  * @{
  */
enum RTCRIsrFlags
{
    #if defined(TAMP)
    RTC_SCR_ITSF        =          RTC_SCR_CITSF,
    RTC_SCR_TSOVF       =          RTC_SCR_CTSOVF,
    RTC_SCR_TSF         =          RTC_SCR_CTSF,
    RTC_SCR_WUTF        =          RTC_SCR_CWUTF,
    RTC_SCR_ALRBF       =          RTC_SCR_CALRBF,
    RTC_SCR_ALRAF       =          RTC_SCR_CALRAF,
    RTC_ICSR_RECALPF    =          RTC_ICSR_RECALPF,
    RTC_ICSR_INITF      =          RTC_ICSR_INITF,
    RTC_ICSR_RSF        =          RTC_ICSR_RSF,
    RTC_ICSR_INITS      =          RTC_ICSR_INITS,
    RTC_ICSR_SHPF       =          RTC_ICSR_SHPF,
    RTC_ICSR_WUTWF      =          RTC_ICSR_WUTWF,
    #else
    RTC_ISR_ITSF        =          RTC_ISR_ITSF,
    RTC_ISR_RECALPF     =          RTC_ISR_RECALPF,
    RTC_ISR_TAMP3F      =          RTC_ISR_TAMP3F,
    RTC_ISR_TAMP2F      =          RTC_ISR_TAMP2F,
    RTC_ISR_TAMP1F      =          RTC_ISR_TAMP1F,
    RTC_ISR_TSOVF       =          RTC_ISR_TSOVF,
    RTC_ISR_TSF         =          RTC_ISR_TSF,
    RTC_ISR_WUTF        =          RTC_ISR_WUTF,
    RTC_ISR_ALRBF       =          RTC_ISR_ALRBF,
    RTC_ISR_ALRAF       =          RTC_ISR_ALRAF,
    RTC_ISR_INITF       =          RTC_ISR_INITF,
    RTC_ISR_RSF         =          RTC_ISR_RSF,
    RTC_ISR_INITS       =          RTC_ISR_INITS,
    RTC_ISR_SHPF        =          RTC_ISR_SHPF,
    RTC_ISR_WUTWF       =          RTC_ISR_WUTWF,
    RTC_ISR_ALRBWF      =          RTC_ISR_ALRBWF,
    RTC_ISR_ALRAWF      =          RTC_ISR_ALRAWF
    #endif /* TAMP */
};

/** @defgroup EC_IT IT Defines
  * @brief    IT defines which can be used with RTC_ReadReg and  RTC_WriteReg functions
  * @{
  */
enum RTCEnableIT
{
    RTC_CR_TSIE             =       RTC_CR_TSIE,
    RTC_CR_WUTIE            =       RTC_CR_WUTIE,
    RTC_CR_ALRBIE           =       RTC_CR_ALRBIE,
    RTC_CR_ALRAIE           =       RTC_CR_ALRAIE,
#if !defined(TAMP)
    RTC_TAMPCR_TAMP3IE      =       RTC_TAMPCR_TAMP3IE,
    RTC_TAMPCR_TAMP2IE      =       RTC_TAMPCR_TAMP2IE,
    RTC_TAMPCR_TAMP1IE      =       RTC_TAMPCR_TAMP1IE,
    RTC_TAMPCR_TAMPIE       =       RTC_TAMPCR_TAMPIE
#endif /* !TAMP */
};

/** @defgroup EC_WEEKDAY  WEEK DAY
  * @{
  */
enum RTCWeekDay
{
    RTC_WEEKDAY_MONDAY         =       (uint8_t)0x01, /*!< Monday    */
    RTC_WEEKDAY_TUESDAY        =       (uint8_t)0x02, /*!< Tuesday   */
    RTC_WEEKDAY_WEDNESDAY      =       (uint8_t)0x03, /*!< Wednesday */
    RTC_WEEKDAY_THURSDAY       =       (uint8_t)0x04, /*!< Thrusday  */
    RTC_WEEKDAY_FRIDAY         =       (uint8_t)0x05, /*!< Friday    */
    RTC_WEEKDAY_SATURDAY       =       (uint8_t)0x06, /*!< Saturday  */
    RTC_WEEKDAY_SUNDAY         =       (uint8_t)0x07, /*!< Sunday    */
};

/** @defgroup EC_MONTH  MONTH
  * @{
  */
enum RTCMonth
{
    RTC_MONTH_JANUARY       =       (uint8_t)0x01,  /*!< January   */
    RTC_MONTH_FEBRUARY      =       (uint8_t)0x02,  /*!< February  */
    RTC_MONTH_MARCH         =       (uint8_t)0x03,  /*!< March     */
    RTC_MONTH_APRIL         =       (uint8_t)0x04,  /*!< April     */
    RTC_MONTH_MAY           =       (uint8_t)0x05,  /*!< May       */
    RTC_MONTH_JUNE          =       (uint8_t)0x06,  /*!< June      */
    RTC_MONTH_JULY          =       (uint8_t)0x07,  /*!< July      */
    RTC_MONTH_AUGUST        =       (uint8_t)0x08,  /*!< August    */
    RTC_MONTH_SEPTEMBER     =       (uint8_t)0x09,  /*!< September */
    RTC_MONTH_OCTOBER       =       (uint8_t)0x10,  /*!< October   */
    RTC_MONTH_NOVEMBER      =       (uint8_t)0x11,  /*!< November  */
    RTC_MONTH_DECEMBER      =       (uint8_t)0x12,  /*!< December  */
};

/** @defgroup EC_HOURFORMAT  HOUR FORMAT
  * @{
  */
enum RTCHourFormat
{
    RTC_HOURFORMAT_24HOUR     =      0x00000000U,           /*!< 24 hour/day format */
    RTC_HOURFORMAT_AMPM       =      RTC_CR_FMT             /*!< AM/PM hour format */
};

/** @defgroup EC_ALARMOUT  ALARM OUTPUT
  * @{
  */
enum RTCAlarmOutputSet
{
    RTC_ALARMOUT_DISABLE      =     0x00000000U,             /*!< Output disabled */
    RTC_ALARMOUT_ALMA         =     RTC_CR_OSEL_0,           /*!< Alarm A output enabled */
    RTC_ALARMOUT_ALMB         =     RTC_CR_OSEL_1,           /*!< Alarm B output enabled */
    RTC_ALARMOUT_WAKEUP       =     RTC_CR_OSEL,             /*!< Wakeup output enabled */
};

/** @defgroup EC_ALARM_OUTPUTTYPE  ALARM OUTPUT TYPE
  * @{
  */
enum RTCAlarmOutputType
{
#if defined(TAMP)
    RTC_ALARM_OUTPUTTYPE_OPENDRAIN     =     RTC_CR_TAMPALRM_TYPE,   /*!< RTC_ALARM is open-drain output */
    RTC_ALARM_OUTPUTTYPE_PUSHPULL      =     0x00000000U,            /*!< RTC_ALARM is push-pull output */
#else
    RTC_ALARM_OUTPUTTYPE_OPENDRAIN     =     0x00000000U,            /*!< RTC_ALARM, when mapped on PC13, is open-drain output */
    RTC_ALARM_OUTPUTTYPE_PUSHPULL      =     RTC_OR_ALARMOUTTYPE     /*!< RTC_ALARM, when mapped on PC13, is push-pull output */
#endif /* TAMP */
};
/** @defgroup EC_OUTPUTPOLARITY_PIN  OUTPUT POLARITY PIN
  * @{
  */
enum RTCOutputPolarity
{
    RTC_OUTPUTPOLARITY_PIN_HIGH    =   0x00000000U,           /*!< Pin is high when ALRAF/ALRBF/WUTF is asserted (depending on OSEL)*/
    RTC_OUTPUTPOLARITY_PIN_LOW     =   RTC_CR_POL            /*!< Pin is low when ALRAF/ALRBF/WUTF is asserted (depending on OSEL) */
};
/** @defgroup EC_TIME_FORMAT TIME FORMAT
  * @{
  */
enum RTCTimeFormat
{
    RTC_TIME_FORMAT_AM_OR_24    =     0x00000000U,           /*!< AM or 24-hour format */
    RTC_TIME_FORMAT_PM          =     RTC_TR_PM              /*!< PM */
};
/** @defgroup EC_SHIFT_SECOND  SHIFT SECOND
  * @{
  */
enum RTCShitfSecond
{
    RTC_SHIFT_SECOND_DELAY      =    0x00000000U,           /* Delay (seconds) = SUBFS / (PREDIV_S + 1) */
    RTC_SHIFT_SECOND_ADVANCE    =    RTC_SHIFTR_ADD1S       /* Advance (seconds) = (1 - (SUBFS / (PREDIV_S + 1))) */
};
/** @defgroup EC_ALMA_MASK  ALARMA MASK
  * @{
  */
enum RTCAlarmAMask
{
    RTC_ALMA_MASK_NONE          =   0x00000000U,             /*!< No masks applied on Alarm A*/
    RTC_ALMA_MASK_DATEWEEKDAY   =   RTC_ALRMAR_MSK4,         /*!< Date/day do not care in Alarm A comparison */
    RTC_ALMA_MASK_HOURS         =   RTC_ALRMAR_MSK3,         /*!< Hours do not care in Alarm A comparison */
    RTC_ALMA_MASK_MINUTES       =   RTC_ALRMAR_MSK2,         /*!< Minutes do not care in Alarm A comparison */
    RTC_ALMA_MASK_SECONDS       =   RTC_ALRMAR_MSK1,         /*!< Seconds do not care in Alarm A comparison */
    RTC_ALMA_MASK_ALL           =   (RTC_ALRMAR_MSK4 | RTC_ALRMAR_MSK3 | RTC_ALRMAR_MSK2 | RTC_ALRMAR_MSK1) /*!< Masks all */
};

/** @defgroup EC_ALMA_TIME_FORMAT  ALARMA TIME FORMAT
  * @{
  */
enum RTCAlarmATimeFormat
{
    RTC_ALMA_TIME_FORMAT_AM    =    0x00000000U,           /*!< AM or 24-hour format */
    RTC_ALMA_TIME_FORMAT_PM    =    RTC_ALRMAR_PM          /*!< PM */
};

/** @defgroup EC_ALMB_MASK  ALARMB MASK
  * @{
  */
enum RTCAlarmBMask
{
    RTC_ALMB_MASK_NONE          =    0x00000000U,             /*!< No masks applied on Alarm B*/
    RTC_ALMB_MASK_DATEWEEKDAY   =    RTC_ALRMBR_MSK4,         /*!< Date/day do not care in Alarm B comparison */
    RTC_ALMB_MASK_HOURS         =    RTC_ALRMBR_MSK3,         /*!< Hours do not care in Alarm B comparison */
    RTC_ALMB_MASK_MINUTES       =    RTC_ALRMBR_MSK2,         /*!< Minutes do not care in Alarm B comparison */
    RTC_ALMB_MASK_SECONDS       =    RTC_ALRMBR_MSK1,         /*!< Seconds do not care in Alarm B comparison */
    RTC_ALMB_MASK_ALL           =    (RTC_ALRMBR_MSK4 | RTC_ALRMBR_MSK3 | RTC_ALRMBR_MSK2 | RTC_ALRMBR_MSK1) /*!< Masks all */
};

/** @defgroup EC_ALMB_TIME_FORMAT  ALARMB TIME FORMAT
  * @{
  */
enum RTCAlarmBTimeFormat
{
    RTC_ALMB_TIME_FORMAT_AM     =    0x00000000U,           /*!< AM or 24-hour format */
    RTC_ALMB_TIME_FORMAT_PM     =    RTC_ALRMBR_PM          /*!< PM */
};

/** @defgroup EC_TIMESTAMP_EDGE  TIMESTAMP EDGE
  * @{
  */
enum RTCTimeStampEdge
{
    RTC_TIMESTAMP_EDGE_RISING   =   0x00000000U,           /*!< RTC_TS input rising edge generates a time-stamp event */
    RTC_TIMESTAMP_EDGE_FALLING  =   RTC_CR_TSEDGE          /*!< RTC_TS input falling edge generates a time-stamp even */
};

/** @defgroup EC_TS_TIME_FORMAT  TIMESTAMP TIME FORMAT
  * @{
  */
enum RTCTsTimeFormat
{
    RTC_TS_TIME_FORMAT_AM    =      0x00000000U,           /*!< AM or 24-hour format */
    RTC_TS_TIME_FORMAT_PM    =      RTC_TSTR_PM            /*!< PM */
};

/** @defgroup EC_TAMPER  TAMPER
  * @{
  */
enum RTCTamperInput
{
    #if defined(TAMP)
    RTC_TAMPER_1         =           TAMP_CR1_TAMP1E, /*!< Tamper 1 input detection */
    RTC_TAMPER_2         =           TAMP_CR1_TAMP2E, /*!< Tamper 2 input detection */
    RTC_TAMPER_3         =           TAMP_CR1_TAMP3E, /*!< Tamper 3 input detection */
    #else
    RTC_TAMPER_1         =           RTC_TAMPCR_TAMP1E, /*!< RTC_TAMP1 input detection */
    RTC_TAMPER_2         =           RTC_TAMPCR_TAMP2E, /*!< RTC_TAMP2 input detection */
    RTC_TAMPER_3         =           RTC_TAMPCR_TAMP3E, /*!< RTC_TAMP3 input detection */
    #endif
};

/** @defgroup EC_TAMPER_MASK  TAMPER MASK
  * @{
  */
enum RTCTamperMask
{
    #if defined(TAMP)
    RTC_TAMPER_MASK_TAMPER1    =     TAMP_CR2_TAMP1MSK, /*!< Tamper 1 event generates a trigger event. TAMP1F is masked and internally cleared by hardware. The backup registers are not erased */
    RTC_TAMPER_MASK_TAMPER2    =     TAMP_CR2_TAMP2MSK, /*!< Tamper 2 event generates a trigger event. TAMP2F is masked and internally cleared by hardware. The backup registers are not erased. */
    RTC_TAMPER_MASK_TAMPER3    =     TAMP_CR2_TAMP3MSK, /*!< Tamper 3 event generates a trigger event. TAMP3F is masked and internally cleared by hardware. The backup registers are not erased. */
    #else
    RTC_TAMPER_MASK_TAMPER1    =     RTC_TAMPCR_TAMP1MF, /*!< Tamper 1 event generates a trigger event. TAMP1F is masked and internally cleared by hardware.The backup registers are not erased */
    RTC_TAMPER_MASK_TAMPER2    =     RTC_TAMPCR_TAMP2MF, /*!< Tamper 2 event generates a trigger event. TAMP2F is masked and internally cleared by hardware. The backup registers are not erased. */
    RTC_TAMPER_MASK_TAMPER3    =     RTC_TAMPCR_TAMP3MF, /*!< Tamper 3 event generates a trigger event. TAMP3F is masked and internally cleared by hardware. The backup registers are not erased */
    #endif
};

/** @defgroup EC_TAMPER_NOERASE  TAMPER NO ERASE
  * @{
  */
enum RTCTamperNoErase
{
    #if defined(TAMP)
    RTC_TAMPER_NOERASE_TAMPER1  =   TAMP_CR2_TAMP1NOERASE, /*!< Tamper 1 event does not erase the backup registers. */
    RTC_TAMPER_NOERASE_TAMPER2  =   TAMP_CR2_TAMP2NOERASE, /*!< Tamper 2 event does not erase the backup registers. */
    RTC_TAMPER_NOERASE_TAMPER3  =   TAMP_CR2_TAMP3NOERASE, /*!< Tamper 3 event does not erase the backup registers. */
    #else
    RTC_TAMPER_NOERASE_TAMPER1   =  RTC_TAMPCR_TAMP1NOERASE, /*!< Tamper 1 event does not erase the backup registers. */
    RTC_TAMPER_NOERASE_TAMPER2   =  RTC_TAMPCR_TAMP2NOERASE, /*!< Tamper 2 event does not erase the backup registers. */
    RTC_TAMPER_NOERASE_TAMPER3   =  RTC_TAMPCR_TAMP3NOERASE, /*!< Tamper 3 event does not erase the backup registers. */
    #endif
};

/** @defgroup EC_TAMPER_DURATION  TAMPER DURATION
  * @{
  */
enum RTCTamperDuration
{
    #if defined(TAMP)
    RTC_TAMPER_DURATION_1RTCCLK  =  0x00000000U,            /*!< Tamper pins are pre-charged before sampling during 1 RTCCLK cycle  */
    RTC_TAMPER_DURATION_2RTCCLK  =  TAMP_FLTCR_TAMPPRCH_0  /*!< Tamper pins are pre-charged before sampling during 2 RTCCLK cycles */
    RTC_TAMPER_DURATION_4RTCCLK  =  TAMP_FLTCR_TAMPPRCH_1,  /*!< Tamper pins are pre-charged before sampling during 4 RTCCLK cycles */
    RTC_TAMPER_DURATION_8RTCCLK  =  TAMP_FLTCR_TAMPPRCH,    /*!< Tamper pins are pre-charged before sampling during 8 RTCCLK cycles */
    #else
    RTC_TAMPER_DURATION_1RTCCLK  =  0x00000000U,            /*!< Tamper pins are pre-charged before sampling during 1 RTCCLK cycle  */
    RTC_TAMPER_DURATION_2RTCCLK  =  RTC_TAMPCR_TAMPPRCH_0,  /*!< Tamper pins are pre-charged before sampling during 2 RTCCLK cycles */
    RTC_TAMPER_DURATION_4RTCCLK  =  RTC_TAMPCR_TAMPPRCH_1,  /*!< Tamper pins are pre-charged before sampling during 4 RTCCLK cycles */
    RTC_TAMPER_DURATION_8RTCCLK  =  RTC_TAMPCR_TAMPPRCH,    /*!< Tamper pins are pre-charged before sampling during 8 RTCCLK cycles */
    #endif
};

/** @defgroup EC_TAMPER_FILTER  TAMPER FILTER
  * @{
  */
enum RTCTamperFilter
{
    #if defined(TAMP)
    RTC_TAMPER_FILTER_DISABLE   =   0x00000000U,             /*!< Tamper filter is disabled */
    RTC_TAMPER_FILTER_2SAMPLE   =   TAMP_FLTCR_TAMPFLT_0,    /*!< Tamper is activated after 2 consecutive samples at the active level */
    RTC_TAMPER_FILTER_4SAMPLE   =   TAMP_FLTCR_TAMPFLT_1,    /*!< Tamper is activated after 4 consecutive samples at the active level */
    RTC_TAMPER_FILTER_8SAMPLE   =   TAMP_FLTCR_TAMPFLT       /*!< Tamper is activated after 8 consecutive samples at the active level. */
    #else
    RTC_TAMPER_FILTER_DISABLE   =   0x00000000U,              /*!< Tamper filter is disabled */
    RTC_TAMPER_FILTER_2SAMPLE   =   RTC_TAMPCR_TAMPFLT_0,     /*!< Tamper is activated after 2 consecutive samples at the active level */
    RTC_TAMPER_FILTER_4SAMPLE   =   RTC_TAMPCR_TAMPFLT_1,     /*!< Tamper is activated after 4 consecutive samples at the active level */
    RTC_TAMPER_FILTER_8SAMPLE   =   RTC_TAMPCR_TAMPFLT,       /*!< Tamper is activated after 8 consecutive samples at the active level. */
    #endif
};

/** @defgroup EC_TAMPER_SAMPLFREQDIV  TAMPER SAMPLING FREQUENCY DIVIDER
  * @{
  */
enum RTCTamperSamplingFreqDiv
{
    #if defined(TAMP)
    RTC_TAMPER_SAMPLFREQDIV_32768     =     0x00000000U,                                     /*!< Each of the tamper inputs are sampled with a frequency =  RTCCLK / 32768 */
    RTC_TAMPER_SAMPLFREQDIV_16384     =     TAMP_FLTCR_TAMPFREQ_0,                           /*!< Each of the tamper inputs are sampled with a frequency =  RTCCLK / 16384 */
    RTC_TAMPER_SAMPLFREQDIV_8192      =     TAMP_FLTCR_TAMPFREQ_1,                           /*!< Each of the tamper inputs are sampled with a frequency =  RTCCLK / 8192 */
    RTC_TAMPER_SAMPLFREQDIV_4096      =     (TAMP_FLTCR_TAMPFREQ_1 | TAMP_FLTCR_TAMPFREQ_0), /*!< Each of the tamper inputs are sampled with a frequency =  RTCCLK / 4096 */
    RTC_TAMPER_SAMPLFREQDIV_2048      =     TAMP_FLTCR_TAMPFREQ_2,                           /*!< Each of the tamper inputs are sampled with a frequency =  RTCCLK / 2048 */
    RTC_TAMPER_SAMPLFREQDIV_1024      =     (TAMP_FLTCR_TAMPFREQ_2 | TAMP_FLTCR_TAMPFREQ_0), /*!< Each of the tamper inputs are sampled with a frequency =  RTCCLK / 1024 */
    RTC_TAMPER_SAMPLFREQDIV_512       =     (TAMP_FLTCR_TAMPFREQ_2 | TAMP_FLTCR_TAMPFREQ_1), /*!< Each of the tamper inputs are sampled with a frequency =  RTCCLK / 512 */
    RTC_TAMPER_SAMPLFREQDIV_256       =     TAMP_FLTCR_TAMPFREQ,                             /*!< Each of the tamper inputs are sampled with a frequency =  RTCCLK / 256 */
    #else
    RTC_TAMPER_SAMPLFREQDIV_32768     =      0x00000000U,                                     /*!< Each of the tamper inputs are sampled with a frequency =  RTCCLK / 32768 */
    RTC_TAMPER_SAMPLFREQDIV_16384     =      RTC_TAMPCR_TAMPFREQ_0,                           /*!< Each of the tamper inputs are sampled with a frequency =  RTCCLK / 16384 */
    RTC_TAMPER_SAMPLFREQDIV_8192      =      RTC_TAMPCR_TAMPFREQ_1,                           /*!< Each of the tamper inputs are sampled with a frequency =  RTCCLK / 8192 */
    RTC_TAMPER_SAMPLFREQDIV_4096      =      (RTC_TAMPCR_TAMPFREQ_1 | RTC_TAMPCR_TAMPFREQ_0), /*!< Each of the tamper inputs are sampled with a frequency =  RTCCLK / 4096 */
    RTC_TAMPER_SAMPLFREQDIV_2048      =      RTC_TAMPCR_TAMPFREQ_2,                           /*!< Each of the tamper inputs are sampled with a frequency =  RTCCLK / 2048 */
    RTC_TAMPER_SAMPLFREQDIV_1024      =      (RTC_TAMPCR_TAMPFREQ_2 | RTC_TAMPCR_TAMPFREQ_0), /*!< Each of the tamper inputs are sampled with a frequency =  RTCCLK / 1024 */
    RTC_TAMPER_SAMPLFREQDIV_512       =      (RTC_TAMPCR_TAMPFREQ_2 | RTC_TAMPCR_TAMPFREQ_1), /*!< Each of the tamper inputs are sampled with a frequency =  RTCCLK / 512 */
    RTC_TAMPER_SAMPLFREQDIV_256       =      RTC_TAMPCR_TAMPFREQ,                             /*!< Each of the tamper inputs are sampled with a frequency =  RTCCLK / 256 */
    #endif
};

/** @defgroup EC_TAMPER_ACTIVELEVEL  TAMPER ACTIVE LEVEL
  * @{
  */
enum RTCTamperActiveLevel
{
    #if defined(TAMP)
    RTC_TAMPER_ACTIVELEVEL_TAMP1  =  TAMP_CR2_TAMP1TRG, /*!< Tamper 1 input falling edge (if TAMPFLT = 00) or staying high (if TAMPFLT != 00) triggers a tamper detection event */
    RTC_TAMPER_ACTIVELEVEL_TAMP2  =  TAMP_CR2_TAMP2TRG, /*!< Tamper 2 input falling edge (if TAMPFLT = 00) or staying high (if TAMPFLT != 00) triggers a tamper detection event */
    RTC_TAMPER_ACTIVELEVEL_TAMP3  =  TAMP_CR2_TAMP3TRG, /*!< Tamper 3 input falling edge (if TAMPFLT = 00) or staying high (if TAMPFLT != 00) triggers a tamper detection event */
    #else
    RTC_TAMPER_ACTIVELEVEL_TAMP1  =  RTC_TAMPCR_TAMP1TRG, /*!< RTC_TAMP1 input falling edge (if TAMPFLT = 00) or staying high (if TAMPFLT != 00) triggers a tamper detection event*/
    RTC_TAMPER_ACTIVELEVEL_TAMP2  =  RTC_TAMPCR_TAMP2TRG, /*!< RTC_TAMP2 input falling edge (if TAMPFLT = 00) or staying high (if TAMPFLT != 00) triggers a tamper detection event*/
    RTC_TAMPER_ACTIVELEVEL_TAMP3  =  RTC_TAMPCR_TAMP3TRG, /*!< RTC_TAMP3 input falling edge (if TAMPFLT = 00) or staying high (if TAMPFLT != 00) triggers a tamper detection event*/
    #endif
};

#if defined(TAMP)
/** @defgroup EC_ACTIVE_MODE   ACTIVE TAMPER MODE
  * @{
  */
enum RTCTamperActiveMode
{
    RTC_TAMPER_ATAMP_TAMP1AM       =        TAMP_ATCR1_TAMP1AM, /*!< tamper 1 is active */
    RTC_TAMPER_ATAMP_TAMP2AM       =        TAMP_ATCR1_TAMP2AM, /*!< tamper 2 is active */
    RTC_TAMPER_ATAMP_TAMP3AM       =        TAMP_ATCR1_TAMP3AM, /*!< tamper 3 is active */
};

/** @defgroup EC_ACTIVE_ASYNC_PRESCALER   ACTIVE TAMPER ASYNCHRONOUS PRESCALER CLOCK
  * @{
  */
enum RTCTamperAsyncPrescaler
{
    RTC_TAMPER_ATAMP_ASYNCPRES_RTCCLK          =        0U,                                                                      /*!< RTCCLK */
    RTC_TAMPER_ATAMP_ASYNCPRES_RTCCLK_2        =        TAMP_ATCR1_ATCKSEL_0,                                                    /*!< RTCCLK/2 */
    RTC_TAMPER_ATAMP_ASYNCPRES_RTCCLK_4        =        TAMP_ATCR1_ATCKSEL_1,                                                    /*!< RTCCLK/4 */
    RTC_TAMPER_ATAMP_ASYNCPRES_RTCCLK_8        =        (TAMP_ATCR1_ATCKSEL_1 | TAMP_ATCR1_ATCKSEL_0),                           /*!< RTCCLK/8 */
    RTC_TAMPER_ATAMP_ASYNCPRES_RTCCLK_16       =        TAMP_ATCR1_ATCKSEL_2,                                                    /*!< RTCCLK/16 */
    RTC_TAMPER_ATAMP_ASYNCPRES_RTCCLK_32       =        (TAMP_ATCR1_ATCKSEL_2 | TAMP_ATCR1_ATCKSEL_0),                           /*!< RTCCLK/32 */
    RTC_TAMPER_ATAMP_ASYNCPRES_RTCCLK_64       =        (TAMP_ATCR1_ATCKSEL_2 | TAMP_ATCR1_ATCKSEL_1),                           /*!< RTCCLK/64 */
    RTC_TAMPER_ATAMP_ASYNCPRES_RTCCLK_128      =        (TAMP_ATCR1_ATCKSEL_2 | TAMP_ATCR1_ATCKSEL_1 | TAMP_ATCR1_ATCKSEL_0)     /*!< RTCCLK/128 */
};

/** @defgroup EC_ACTIVE_OUTPUT_SELECTION   ACTIVE TAMPER OUTPUT SELECTION
  * @{
  */
enum RTCTamperOutputSelection
{
    RTC_TAMPER_ATAMP1IN_ATAMP1OUT     =     (0UL << TAMP_ATCR2_ATOSEL1_Pos),
    RTC_TAMPER_ATAMP1IN_ATAMP2OUT     =     (1UL << TAMP_ATCR2_ATOSEL1_Pos),
    RTC_TAMPER_ATAMP1IN_ATAMP3OUT     =     (2UL << TAMP_ATCR2_ATOSEL1_Pos),   
    RTC_TAMPER_ATAMP2IN_ATAMP1OUT     =     (0UL << TAMP_ATCR2_ATOSEL2_Pos),
    RTC_TAMPER_ATAMP2IN_ATAMP2OUT     =     (1UL << TAMP_ATCR2_ATOSEL2_Pos),
    RTC_TAMPER_ATAMP2IN_ATAMP3OUT     =     (2UL << TAMP_ATCR2_ATOSEL2_Pos),   
    RTC_TAMPER_ATAMP3IN_ATAMP1OUT     =     (0UL << TAMP_ATCR2_ATOSEL3_Pos),
    RTC_TAMPER_ATAMP3IN_ATAMP2OUT     =     (1UL << TAMP_ATCR2_ATOSEL3_Pos),
    RTC_TAMPER_ATAMP3IN_ATAMP3OUT     =     (2UL << TAMP_ATCR2_ATOSEL3_Pos),
};
#endif /* TAMP */

/** @defgroup EC_WAKEUPCLOCK_DIV  WAKEUP CLOCK DIV
  * @{
  */
enum RTCWakeupClockDiv
{
    RTC_WAKEUPCLOCK_DIV_16         =     0x00000000U,                           /*!< RTC/16 clock is selected */
    RTC_WAKEUPCLOCK_DIV_8          =     RTC_CR_WUCKSEL_0,                      /*!< RTC/8 clock is selected */
    RTC_WAKEUPCLOCK_DIV_4          =     RTC_CR_WUCKSEL_1,                      /*!< RTC/4 clock is selected */
    RTC_WAKEUPCLOCK_DIV_2          =     (RTC_CR_WUCKSEL_1 | RTC_CR_WUCKSEL_0), /*!< RTC/2 clock is selected */
    RTC_WAKEUPCLOCK_CKSPRE         =     RTC_CR_WUCKSEL_2,                      /*!< ck_spre (usually 1 Hz) clock is selected */
    RTC_WAKEUPCLOCK_CKSPRE_WUT     =     (RTC_CR_WUCKSEL_2 | RTC_CR_WUCKSEL_1), /*!< ck_spre (usually 1 Hz) clock is selected and 2exp16 is added to the WUT counter value*/  
};

/** @defgroup EC_BKP  BACKUP
  * @{
  */
enum RTCBackUpReg
{
    RTC_BKP_DR0             =       0x00000000U,
    RTC_BKP_DR1             =       0x00000001U,
    RTC_BKP_DR2             =       0x00000002U,
    RTC_BKP_DR3             =       0x00000003U,
    RTC_BKP_DR4             =       0x00000004U,
    RTC_BKP_DR5             =       0x00000005U,
    RTC_BKP_DR6             =       0x00000006U,
    RTC_BKP_DR7             =       0x00000007U,
    RTC_BKP_DR8             =       0x00000008U,
    RTC_BKP_DR9             =       0x00000009U,
    RTC_BKP_DR10            =       0x0000000AU,
    RTC_BKP_DR11            =       0x0000000BU,
    RTC_BKP_DR12            =       0x0000000CU,
    RTC_BKP_DR13            =       0x0000000DU,
    RTC_BKP_DR14            =       0x0000000EU,
    RTC_BKP_DR15            =       0x0000000FU,
    RTC_BKP_DR16            =       0x00000010U,
    RTC_BKP_DR17            =       0x00000011U,
    RTC_BKP_DR18            =       0x00000012U,
    RTC_BKP_DR19            =       0x00000013U,
    RTC_BKP_DR20            =       0x00000014U,
    RTC_BKP_DR21            =       0x00000015U,
    RTC_BKP_DR22            =       0x00000016U,
    RTC_BKP_DR23            =       0x00000017U,
    RTC_BKP_DR24            =       0x00000018U,
    RTC_BKP_DR25            =       0x00000019U,
    RTC_BKP_DR26            =       0x0000001AU,
    RTC_BKP_DR27            =       0x0000001BU,
    RTC_BKP_DR28            =       0x0000001CU,
    RTC_BKP_DR29            =       0x0000001DU,
    RTC_BKP_DR30            =       0x0000001EU,
    RTC_BKP_DR31            =       0x0000001FU,
};

/** @defgroup EC_CALIB_OUTPUT  Calibration output
  * @{
  */
enum RTCCalibrationOutput
{
    RTC_CALIB_OUTPUT_NONE      =     0x00000000U,                 /*!< Calibration output disabled */
    RTC_CALIB_OUTPUT_1HZ       =     (RTC_CR_COE | RTC_CR_COSEL), /*!< Calibration output is 1 Hz */
    RTC_CALIB_OUTPUT_512HZ     =      RTC_CR_COE                  /*!< Calibration output is 512 Hz */
};

/** @defgroup EC_CALIB_INSERTPULSE  Calibration pulse insertion
  * @{
  */
enum RTCCalibrationInsertPulse
{
    RTC_CALIB_INSERTPULSE_NONE   =   0x00000000U,           /*!< No RTCCLK pulses are added */
    RTC_CALIB_INSERTPULSE_SET    =   RTC_CALR_CALP,         /*!< One RTCCLK pulse is effectively inserted every 2exp11 pulses (frequency increased by 488.5 ppm) */   
};

/** @defgroup EC_CALIB_PERIOD  Calibration period
  * @{
  */
enum RTCCalibrationPeriod
{
    RTC_CALIB_PERIOD_32SEC     =     0x00000000U,           /*!< Use a 32-second calibration cycle period */
    RTC_CALIB_PERIOD_16SEC     =     RTC_CALR_CALW16,       /*!< Use a 16-second calibration cycle period */
    RTC_CALIB_PERIOD_8SEC      =     RTC_CALR_CALW8         /*!< Use a 8-second calibration cycle period */
};

/**
  * @brief  RTC Init structures definition
  */
typedef struct
{
  uint32_t HourFormat;   /*!< Specifies the RTC Hours Format.
                              This parameter can be a value of @ref EC_HOURFORMAT

                              This feature can be modified afterwards using unitary function
                              @ref RTC_SetHourFormat(). */

  uint32_t AsynchPrescaler; /*!< Specifies the RTC Asynchronous Predivider value.
                              This parameter must be a number between Min_Data = 0x00 and Max_Data = 0x7F

                              This feature can be modified afterwards using unitary function
                              @ref RTC_SetAsynchPrescaler(). */

  uint32_t SynchPrescaler;  /*!< Specifies the RTC Synchronous Predivider value.
                              This parameter must be a number between Min_Data = 0x00 and Max_Data = 0x7FFF

                              This feature can be modified afterwards using unitary function
                              @ref RTC_SetSynchPrescaler(). */
} RTC_InitTypeDef;

/**
  * @brief  RTC Time structure definition
  */
typedef struct
{
  uint32_t TimeFormat; /*!< Specifies the RTC AM/PM Time.
                            This parameter can be a value of @ref EC_TIME_FORMAT

                            This feature can be modified afterwards using unitary function @ref RTC_TIME_SetFormat(). */

  uint8_t Hours;       /*!< Specifies the RTC Time Hours.
                            This parameter must be a number between Min_Data = 0 and Max_Data = 12 if the @ref RTC_TIME_FORMAT_PM is selected.
                            This parameter must be a number between Min_Data = 0 and Max_Data = 23 if the @ref RTC_TIME_FORMAT_AM_OR_24 is selected.

                            This feature can be modified afterwards using unitary function @ref RTC_TIME_SetHour(). */

  uint8_t Minutes;     /*!< Specifies the RTC Time Minutes.
                            This parameter must be a number between Min_Data = 0 and Max_Data = 59

                            This feature can be modified afterwards using unitary function @ref RTC_TIME_SetMinute(). */

  uint8_t Seconds;     /*!< Specifies the RTC Time Seconds.
                            This parameter must be a number between Min_Data = 0 and Max_Data = 59

                            This feature can be modified afterwards using unitary function @ref RTC_TIME_SetSecond(). */
} RTC_TimeTypeDef;

/**
  * @brief  RTC Date structure definition
  */
typedef struct
{
  uint8_t WeekDay;  /*!< Specifies the RTC Date WeekDay.
                         This parameter can be a value of @ref EC_WEEKDAY

                         This feature can be modified afterwards using unitary function @ref RTC_DATE_SetWeekDay(). */

  uint8_t Month;    /*!< Specifies the RTC Date Month.
                         This parameter can be a value of @ref EC_MONTH

                         This feature can be modified afterwards using unitary function @ref RTC_DATE_SetMonth(). */

  uint8_t Day;      /*!< Specifies the RTC Date Day.
                         This parameter must be a number between Min_Data = 1 and Max_Data = 31

                         This feature can be modified afterwards using unitary function @ref RTC_DATE_SetDay(). */

  uint8_t Year;     /*!< Specifies the RTC Date Year.
                         This parameter must be a number between Min_Data = 0 and Max_Data = 99

                         This feature can be modified afterwards using unitary function @ref RTC_DATE_SetYear(). */
} RTC_DateTypeDef;

/**
  * @brief  RTC Alarm structure definition
  */
typedef struct
{
  RTC_TimeTypeDef AlarmTime;  /*!< Specifies the RTC Alarm Time members. */

  uint32_t AlarmMask;            /*!< Specifies the RTC Alarm Masks.
                                      This parameter can be a value of @ref EC_ALMA_MASK for ALARM A or @ref EC_ALMB_MASK for ALARM B.

                                      This feature can be modified afterwards using unitary function @ref RTC_ALMA_SetMask() for ALARM A
                                      or @ref RTC_ALMB_SetMask() for ALARM B
                                 */

  uint32_t AlarmDateWeekDaySel;  /*!< Specifies the RTC Alarm is on day or WeekDay.
                                      This parameter can be a value of @ref EC_ALMA_WEEKDAY_SELECTION for ALARM A or @ref EC_ALMB_WEEKDAY_SELECTION for ALARM B

                                      This feature can be modified afterwards using unitary function @ref RTC_ALMA_EnableWeekday() or @ref RTC_ALMA_DisableWeekday()
                                      for ALARM A or @ref RTC_ALMB_EnableWeekday() or @ref RTC_ALMB_DisableWeekday() for ALARM B
                                 */

  uint8_t AlarmDateWeekDay;      /*!< Specifies the RTC Alarm Day/WeekDay.
                                      If AlarmDateWeekDaySel set to day, this parameter  must be a number between Min_Data = 1 and Max_Data = 31.

                                      This feature can be modified afterwards using unitary function @ref RTC_ALMA_SetDay()
                                      for ALARM A or @ref RTC_ALMB_SetDay() for ALARM B.

                                      If AlarmDateWeekDaySel set to Weekday, this parameter can be a value of @ref EC_WEEKDAY.

                                      This feature can be modified afterwards using unitary function @ref RTC_ALMA_SetWeekDay()
                                      for ALARM A or @ref RTC_ALMB_SetWeekDay() for ALARM B.
                                 */
} RTC_AlarmTypeDef;

class RTC
{
    
};