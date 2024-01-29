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

/* Default values used for prescaler */
#define RTC_ASYNCH_PRESC_DEFAULT     0x0000007FU
#define RTC_SYNCH_PRESC_DEFAULT      0x000000FFU

/* Values used for timeout */
#define RTC_INITMODE_TIMEOUT         1000U /* 1s when tick set to 1ms */
#define RTC_SYNCHRO_TIMEOUT          1000U /* 1s when tick set to 1ms */

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
    RTC_SCR_LITSF        =          RTC_SCR_CITSF,
    RTC_SCR_LTSOVF       =          RTC_SCR_CTSOVF,
    RTC_SCR_LTSF         =          RTC_SCR_CTSF,
    RTC_SCR_LWUTF        =          RTC_SCR_CWUTF,
    RTC_SCR_LALRBF       =          RTC_SCR_CALRBF,
    RTC_SCR_LALRAF       =          RTC_SCR_CALRAF,
    RTC_ICSR_LRECALPF    =          RTC_ICSR_RECALPF,
    RTC_ICSR_LINITF      =          RTC_ICSR_INITF,
    RTC_ICSR_LRSF        =          RTC_ICSR_RSF,
    RTC_ICSR_LINITS      =          RTC_ICSR_INITS,
    RTC_ICSR_LSHPF       =          RTC_ICSR_SHPF,
    RTC_ICSR_LWUTWF      =          RTC_ICSR_WUTWF,
    #else
    RTC_ISR_LITSF        =          RTC_ISR_ITSF,
    RTC_ISR_LRECALPF     =          RTC_ISR_RECALPF,
    RTC_ISR_LTAMP3F      =          RTC_ISR_TAMP3F,
    RTC_ISR_LTAMP2F      =          RTC_ISR_TAMP2F,
    RTC_ISR_LTAMP1F      =          RTC_ISR_TAMP1F,
    RTC_ISR_LTSOVF       =          RTC_ISR_TSOVF,
    RTC_ISR_LTSF         =          RTC_ISR_TSF,
    RTC_ISR_LWUTF        =          RTC_ISR_WUTF,
    RTC_ISR_LALRBF       =          RTC_ISR_ALRBF,
    RTC_ISR_LALRAF       =          RTC_ISR_ALRAF,
    RTC_ISR_LINITF       =          RTC_ISR_INITF,
    RTC_ISR_LRSF         =          RTC_ISR_RSF,
    RTC_ISR_LINITS       =          RTC_ISR_INITS,
    RTC_ISR_LSHPF        =          RTC_ISR_SHPF,
    RTC_ISR_LWUTWF       =          RTC_ISR_WUTWF,
    RTC_ISR_LALRBWF      =          RTC_ISR_ALRBWF,
    RTC_ISR_LALRAWF      =          RTC_ISR_ALRAWF
    #endif /* TAMP */
};

/** @defgroup EC_IT IT Defines
  * @brief    IT defines which can be used with RTC_ReadReg and  RTC_WriteReg functions
  * @{
  */
enum RTCEnableIT
{
    RTC_CR_LTSIE             =       RTC_CR_TSIE,
    RTC_CR_LWUTIE            =       RTC_CR_WUTIE,
    RTC_CR_LALRBIE           =       RTC_CR_ALRBIE,
    RTC_CR_LALRAIE           =       RTC_CR_ALRAIE,
#if !defined(TAMP)
    RTC_TAMPCR_LTAMP3IE      =       RTC_TAMPCR_TAMP3IE,
    RTC_TAMPCR_LTAMP2IE      =       RTC_TAMPCR_TAMP2IE,
    RTC_TAMPCR_LTAMP1IE      =       RTC_TAMPCR_TAMP1IE,
    RTC_TAMPCR_LTAMPIE       =       RTC_TAMPCR_TAMPIE
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
  RTCHourFormat HourFormat;   /*!< Specifies the RTC Hours Format.
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
  RTCWeekDay WeekDay;  /*!< Specifies the RTC Date WeekDay.
                         This parameter can be a value of @ref EC_WEEKDAY

                         This feature can be modified afterwards using unitary function @ref RTC_DATE_SetWeekDay(). */

  RTCMonth Month;    /*!< Specifies the RTC Date Month.
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

  union 
  {
    RTCAlarmAMask A;
    RTCAlarmBMask B;
  }AlarmMask;
                                 /*!< Specifies the RTC Alarm Masks.
                                      This parameter can be a value of @ref EC_ALMA_MASK for ALARM A or @ref EC_ALMB_MASK for ALARM B.

                                      This feature can be modified afterwards using unitary function @ref RTC_ALMA_SetMask() for ALARM A
                                      or @ref RTC_ALMB_SetMask() for ALARM B
                                 */
  union
  {
    RTCAlarmAWeekDaySelect A;
    RTCAlarmBWeekDaySelect B;
  }AlarmDateWeekDaySel;
                                  /*!< Specifies the RTC Alarm is on day or WeekDay.
                                      This parameter can be a value of @ref EC_ALMA_WEEKDAY_SELECTION for ALARM A or @ref EC_ALMB_WEEKDAY_SELECTION for ALARM B

                                      This feature can be modified afterwards using unitary function @ref RTC_ALMA_EnableWeekday() or @ref RTC_ALMA_DisableWeekday()
                                      for ALARM A or @ref RTC_ALMB_EnableWeekday() or @ref RTC_ALMB_DisableWeekday() for ALARM B
                                 */
  union
  {
    uint32_t day;
    RTCWeekDay week;
  }AlarmDateWeekDay;
                                  /*!< Specifies the RTC Alarm Day/WeekDay.
                                      If AlarmDateWeekDaySel set to day, this parameter  must be a number between Min_Data = 1 and Max_Data = 31.

                                      This feature can be modified afterwards using unitary function @ref RTC_ALMA_SetDay()
                                      for ALARM A or @ref RTC_ALMB_SetDay() for ALARM B.

                                      If AlarmDateWeekDaySel set to Weekday, this parameter can be a value of @ref EC_WEEKDAY.

                                      This feature can be modified afterwards using unitary function @ref RTC_ALMA_SetWeekDay()
                                      for ALARM A or @ref RTC_ALMB_SetWeekDay() for ALARM B.
                                 */
} RTC_AlarmTypeDef;

class RTCX
{
public:
 #ifndef TAMP
    RTCX(RTC_TypeDef* rtcx = RTC) : rtcx_(rtcx) 
    {

    }
#else
    RTCX(RTC_TypeDef* rtcx, ) : rtcx_(rtcx), tampx_(tampx)
    {

    }
#endif
    ~RTCX()
    {

    }
    RTCX(const RTCX&) = delete;
    RTCX(RTCX&&) = delete;
    RTCX& operator=(const RTCX&) = delete;
    RTCX& operator=(RTCX&&) = delete;

    inline void rtcSetHourFormat(RTCHourFormat HourFormat)
    {
      MODIFY_REG(rtcx_->CR, RTC_CR_FMT, HourFormat);
    }
    inline RTCHourFormat rtcGetHourFormat()
    {
      return (RTCHourFormat)(READ_BIT(rtcx_->CR, RTC_CR_FMT));
    }
    inline void rtcSetAlarmOutEvent(RTCAlarmOutputSet AlarmOutput)
    {
      MODIFY_REG(rtcx_->CR, RTC_CR_OSEL, AlarmOutput);
    }
    inline RTCAlarmOutputSet rtcGetAlarmOutEvent()
    {
      return (RTCAlarmOutputSet)(READ_BIT(rtcx_->CR, RTC_CR_OSEL));
    }

    #if defined(RTC_CR_TAMPALRM_TYPE)
    /**
      * @brief  Set RTC_ALARM output type (ALARM in push-pull or open-drain output)
      * @rmtoll RTC_CR           TAMPALRM_TYPE          rtcSetAlarmOutputType
      * @param  RTCx RTC Instance
      * @param  Output This parameter can be one of the following values:
      *         @arg @ref rtcALARM_OUTPUTTYPE_OPENDRAIN
      *         @arg @ref rtcALARM_OUTPUTTYPE_PUSHPULL
      * @retval None
      */
    inline void rtcSetAlarmOutputType(uint32_t Output)
    {
      MODIFY_REG(rtcx_->CR, RTC_CR_TAMPALRM_TYPE, Output);
    }

    /**
      * @brief  Get RTC_ALARM output type (ALARM in push-pull or open-drain output)
      * @rmtoll RTC_CR           TAMPALRM_TYPE          rtcSetAlarmOutputType
      * @param  RTCx RTC Instance
      * @retval Returned value can be one of the following values:
      *         @arg @ref rtcALARM_OUTPUTTYPE_OPENDRAIN
      *         @arg @ref rtcALARM_OUTPUTTYPE_PUSHPULL
      */
    inline uint32_t rtcGetAlarmOutputType()
    {
      return (uint32_t)(READ_BIT(rtcx_->CR, RTC_CR_TAMPALRM_TYPE));
    }
    #endif /* RTC_CR_TAMPALRM_TYPE */

    #if defined(RTC_ICSR_INIT)
    /**
      * @brief  Enable initialization mode
      * @note   Initialization mode is used to program time and date register (RTC_TR and RTC_DR)
      *         and prescaler register (RTC_PRER).
      *         Counters are stopped and start counting from the new value when INIT is reset.
      * @rmtoll RTC_ICSR          INIT          rtcEnableInitMode
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcEnableInitMode()
    {
      /* Set the Initialization mode */
      WRITE_REG(rtcx_->ICSR, RTC_LL_INIT_MASK);
    }

    /**
      * @brief  Disable initialization mode (Free running mode)
      * @rmtoll RTC_ICSR          INIT          rtcDisableInitMode
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcDisableInitMode()
    {
      /* Exit Initialization mode */
      WRITE_REG(rtcx_->ICSR, (uint32_t)~RTC_ICSR_INIT);
    }

    #endif /* RTC_ICSR_INIT */

    #if defined(RTC_OR_ALARMOUTTYPE)
    inline void rtcSetAlarmOutputType(RTCAlarmOutputType Output)
    {
      MODIFY_REG(rtcx_->OR, RTC_OR_ALARMOUTTYPE, Output);
    }
    inline RTCAlarmOutputType rtcGetAlarmOutputType()
    {
      return (RTCAlarmOutputType)(READ_BIT(rtcx_->OR, RTC_OR_ALARMOUTTYPE));
    }
    #endif /* RTC_OR_ALARMOUTTYPE */

    #if defined(RTC_ISR_INIT)
    /**
      * @brief  Enable initialization mode
      * @note   Initialization mode is used to program time and date register (RTC_TR and RTC_DR)
      *         and prescaler register (RTC_PRER).
      *         Counters are stopped and start counting from the new value when INIT is reset.
      * @rmtoll ISR          INIT          rtcEnableInitMode
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcEnableInitMode()
    {
      /* Set the Initialization mode */
      WRITE_REG(rtcx_->ISR, RTC_INIT_MASK);
    }

    /**
      * @brief  Disable initialization mode (Free running mode)
      * @rmtoll ISR          INIT          rtcDisableInitMode
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcDisableInitMode()
    {
      /* Exit Initialization mode */
      WRITE_REG(rtcx_->ISR, (uint32_t)~RTC_ISR_INIT);
    }
    #endif /* RTC_ISR_INIT */

    inline void rtcSetOutputPolarity(RTCOutputPolarity Polarity)
    {
      MODIFY_REG(rtcx_->CR, RTC_CR_POL, Polarity);
    }
    inline RTCOutputPolarity rtcGetOutputPolarity()
    {
      return (RTCOutputPolarity)(READ_BIT(rtcx_->CR, RTC_CR_POL));
    }
    inline void rtcEnableShadowRegBypass()
    {
      SET_BIT(rtcx_->CR, RTC_CR_BYPSHAD);
    }
    inline void rtcDisableShadowRegBypass()
    {
      CLEAR_BIT(rtcx_->CR, RTC_CR_BYPSHAD);
    }
    inline bool rtcIsShadowRegBypassEnabled()
    {
      return ((READ_BIT(rtcx_->CR, RTC_CR_BYPSHAD) == (RTC_CR_BYPSHAD)) ? true : false);
    }
    /**
      * @brief  Enable RTC_REFIN reference clock detection (50 or 60 Hz)
      * @note   Bit is write-protected. @ref rtcDisableWriteProtection function should be called before.
      * @note   It can be written in initialization mode only (@ref rtcEnableInitMode function)
      * @rmtoll RTC_CR           REFCKON       rtcEnableRefClock
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcEnableRefClock()
    {
      SET_BIT(rtcx_->CR, RTC_CR_REFCKON);
    }
    /**
      * @brief  Disable RTC_REFIN reference clock detection (50 or 60 Hz)
      * @note   Bit is write-protected. @ref rtcDisableWriteProtection function should be called before.
      * @note   It can be written in initialization mode only (@ref rtcEnableInitMode function)
      * @rmtoll RTC_CR           REFCKON       rtcDisableRefClock
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcDisableRefClock()
    {
      CLEAR_BIT(rtcx_->CR, RTC_CR_REFCKON);
    }
    /**
      * @brief  Set Asynchronous prescaler factor
      * @rmtoll RTC_PRER         PREDIV_A      rtcSetAsynchPrescaler
      * @param  RTCx RTC Instance
      * @param  AsynchPrescaler Value between Min_Data = 0 and Max_Data = 0x7F
      * @retval None
      */
    inline void rtcSetAsynchPrescaler(uint32_t AsynchPrescaler)
    {
      MODIFY_REG(rtcx_->PRER, RTC_PRER_PREDIV_A, AsynchPrescaler << RTC_PRER_PREDIV_A_Pos);
    }

    /**
      * @brief  Set Synchronous prescaler factor
      * @rmtoll RTC_PRER         PREDIV_S      rtcSetSynchPrescaler
      * @param  RTCx RTC Instance
      * @param  SynchPrescaler Value between Min_Data = 0 and Max_Data = 0x7FFF
      * @retval None
      */
    inline void rtcSetSynchPrescaler(uint32_t SynchPrescaler)
    {
      MODIFY_REG(rtcx_->PRER, RTC_PRER_PREDIV_S, SynchPrescaler);
    }

    /**
      * @brief  Get Asynchronous prescaler factor
      * @rmtoll RTC_PRER         PREDIV_A      rtcGetAsynchPrescaler
      * @param  RTCx RTC Instance
      * @retval Value between Min_Data = 0 and Max_Data = 0x7F
      */
    inline uint32_t rtcGetAsynchPrescaler()
    {
      return (uint32_t)(READ_BIT(rtcx_->PRER, RTC_PRER_PREDIV_A) >> RTC_PRER_PREDIV_A_Pos);
    }

    /**
      * @brief  Get Synchronous prescaler factor
      * @rmtoll RTC_PRER         PREDIV_S      rtcGetSynchPrescaler
      * @param  RTCx RTC Instance
      * @retval Value between Min_Data = 0 and Max_Data = 0x7FFF
      */
    inline uint32_t rtcGetSynchPrescaler()
    {
      return (uint32_t)(READ_BIT(rtcx_->PRER, RTC_PRER_PREDIV_S));
    }

    /**
      * @brief  Enable the write protection for RTC registers.
      * @rmtoll RTC_WPR          KEY           rtcEnableWriteProtection
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcEnableWriteProtection()
    {
      WRITE_REG(rtcx_->WPR, RTC_WRITE_PROTECTION_DISABLE);
    }

    /**
      * @brief  Disable the write protection for RTC registers.
      * @rmtoll RTC_WPR          KEY           rtcDisableWriteProtection
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcDisableWriteProtection()
    {
      WRITE_REG(rtcx_->WPR, RTC_WRITE_PROTECTION_ENABLE_1);
      WRITE_REG(rtcx_->WPR, RTC_WRITE_PROTECTION_ENABLE_2);
    }

    #if defined(RTC_CR_TAMPOE)
    /**
      * @brief  Enable tamper output.
      * @note When the tamper output is enabled, all external and internal tamper flags
      *       are ORed and routed to the TAMPALRM output.
      * @rmtoll RTC_CR           TAMPOE       rtcEnableTamperOutput
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcEnableTamperOutput()
    {
      SET_BIT(rtcx_->CR, RTC_CR_TAMPOE);
    }

    /**
      * @brief  Disable tamper output.
      * @rmtoll RTC_CR           TAMPOE       rtcDisableTamperOutput
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcDisableTamperOutput()
    {
      CLEAR_BIT(rtcx_->CR, RTC_CR_TAMPOE);
    }

    /**
      * @brief  Check if tamper output is enabled or not.
      * @rmtoll RTC_CR           TAMPOE       rtcIsTamperOutputEnabled
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsTamperOutputEnabled()
    {
      return ((READ_BIT(rtcx_->CR, RTC_CR_TAMPOE) == (RTC_CR_TAMPOE)) ? true : false);
    }
    #endif /* RTC_CR_TAMPOE */

    #if defined(RTC_CR_TAMPALRM_PU)
    /**
      * @brief  Enable internal pull-up in output mode.
      * @rmtoll RTC_CR           TAMPALRM_PU       rtcEnableAlarmPullUp
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcEnableAlarmPullUp()
    {
      SET_BIT(rtcx_->CR, RTC_CR_TAMPALRM_PU);
    }

    /**
      * @brief  Disable internal pull-up in output mode.
      * @rmtoll RTC_CR           TAMPALRM_PU       rtcEnableAlarmPullUp
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcDisableAlarmPullUp()
    {
      CLEAR_BIT(rtcx_->CR, RTC_CR_TAMPALRM_PU);
    }

    /**
      * @brief  Check if internal pull-up in output mode is enabled or not.
      * @rmtoll RTC_CR           TAMPALRM_PU       rtcIsAlarmPullUpEnabled
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsAlarmPullUpEnabled()
    {
      return ((READ_BIT(rtcx_->CR, RTC_CR_TAMPALRM_PU) == (RTC_CR_TAMPALRM_PU)) ? true : false);
    }
    #endif /* RTC_CR_TAMPALRM_PU */

    #if defined(RTC_CR_OUT2EN)
    /**
      * @brief  Enable RTC_OUT2 output
      * @note RTC_OUT2 mapping depends on both OSEL (@ref rtcSetAlarmOutEvent)
      *       and COE (@ref rtcCALSetOutputFreq) settings.
      * @note RTC_OUT2 isn't available ins VBAT mode.
      * @rmtoll RTC_CR           OUT2EN       rtcEnableOutput2
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcEnableOutput2()
    {
      SET_BIT(rtcx_->CR, RTC_CR_OUT2EN);
    }

    /**
      * @brief  Disable RTC_OUT2 output
      * @rmtoll RTC_CR           OUT2EN       rtcDisableOutput2
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcDisableOutput2()
    {
      CLEAR_BIT(rtcx_->CR, RTC_CR_OUT2EN);
    }

    /**
      * @brief  Check if RTC_OUT2 output is enabled or not.
      * @rmtoll RTC_CR           OUT2EN       rtcIsOutput2Enabled
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsOutput2Enabled()
    {
      return ((READ_BIT(rtcx_->CR, RTC_CR_OUT2EN) == (RTC_CR_OUT2EN)) ? true : false);
    }

    #endif /* RTC_CR_OUT2EN */

    #if defined(RTC_OR_OUT_RMP)
    /**
      * @brief  Enable RTC_OUT remap
      * @rmtoll OR           OUT_RMP       rtcEnableOutRemap
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcEnableOutRemap()
    {
      SET_BIT(rtcx_->OR, RTC_OR_OUT_RMP);
    }

    /**
      * @brief  Disable RTC_OUT remap
      * @rmtoll OR           OUT_RMP       rtcDisableOutRemap
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcDisableOutRemap()
    {
      CLEAR_BIT(rtcx_->OR, RTC_OR_OUT_RMP);
    }
    #endif /* RTC_OR_OUT_RMP */

    /**
      * @}
      */

    /** @defgroup RTC_LL_EF_Time Time
      * @{
      */

    /**
      * @brief  Set time format (AM/24-hour or PM notation)
      * @note   Bit is write-protected. @ref rtcDisableWriteProtection function should be called before.
      * @note   It can be written in initialization mode only (@ref rtcEnableInitMode function)
      * @rmtoll RTC_TR           PM            rtcTIMESetFormat
      * @param  RTCx RTC Instance
      * @param  TimeFormat This parameter can be one of the following values:
      *         @arg @ref rtcTIMEFORMAT_AM_OR_24
      *         @arg @ref rtcTIMEFORMAT_PM
      * @retval None
      */
    inline void rtcTIMESetFormat(RTCTimeFormat TimeFormat)
    {
      MODIFY_REG(rtcx_->TR, RTC_TR_PM, TimeFormat);
    }

    /**
      * @brief  Get time format (AM or PM notation)
      * @note if shadow mode is disabled (BYPSHAD=0), need to check if RSF flag is set
      *       before reading this bit
      * @note Read either RTC_SSR or RTC_TR locks the values in the higher-order calendar
      *       shadow registers until RTC_DR is read (rtcReadReg(RTC, DR)).
      * @rmtoll RTC_TR           PM            rtcTIMEGetFormat
      * @param  RTCx RTC Instance
      * @retval Returned value can be one of the following values:
      *         @arg @ref rtcTIMEFORMAT_AM_OR_24
      *         @arg @ref rtcTIMEFORMAT_PM
      */
    inline RTCTimeFormat rtcTIMEGetFormat()
    {
      return (RTCTimeFormat)(READ_BIT(rtcx_->TR, RTC_TR_PM));
    }

    /**
      * @brief  Set Hours in BCD format
      * @note   Bit is write-protected. @ref rtcDisableWriteProtection function should be called before.
      * @note   It can be written in initialization mode only (@ref rtcEnableInitMode function)
      * @note helper macro __rtcCONVERT_BIN2BCD is available to convert hour from binary to BCD format
      * @rmtoll RTC_TR           HT            rtcTIMESetHour
      *         RTC_TR           HU            rtcTIMESetHour
      * @param  RTCx RTC Instance
      * @param  Hours Value between Min_Data=0x01 and Max_Data=0x12 or between Min_Data=0x00 and Max_Data=0x23
      * @retval None
      */
    inline void rtcTIMESetHour(uint32_t Hours)
    {
      MODIFY_REG(rtcx_->TR, (RTC_TR_HT | RTC_TR_HU),
                (((Hours & 0xF0U) << (RTC_TR_HT_Pos - 4U)) | ((Hours & 0x0FU) << RTC_TR_HU_Pos)));
    }

    /**
      * @brief  Get Hours in BCD format
      * @note if shadow mode is disabled (BYPSHAD=0), need to check if RSF flag is set
      *       before reading this bit
      * @note Read either RTC_SSR or RTC_TR locks the values in the higher-order calendar
      *       shadow registers until RTC_DR is read (rtcReadReg(RTC, DR)).
      * @note helper macro __rtcCONVERT_BCD2BIN is available to convert hour from BCD to
      *       Binary format
      * @rmtoll RTC_TR           HT            rtcTIMEGetHour
      *         RTC_TR           HU            rtcTIMEGetHour
      * @param  RTCx RTC Instance
      * @retval Value between Min_Data=0x01 and Max_Data=0x12 or between Min_Data=0x00 and Max_Data=0x23
      */
    inline uint32_t rtcTIMEGetHour()
    {
      return (uint32_t)((READ_BIT(rtcx_->TR, (RTC_TR_HT | RTC_TR_HU))) >> RTC_TR_HU_Pos);
    }

    /**
      * @brief  Set Minutes in BCD format
      * @note   Bit is write-protected. @ref rtcDisableWriteProtection function should be called before.
      * @note   It can be written in initialization mode only (@ref rtcEnableInitMode function)
      * @note helper macro __rtcCONVERT_BIN2BCD is available to convert Minutes from binary to BCD format
      * @rmtoll RTC_TR           MNT           rtcTIMESetMinute
      *         RTC_TR           MNU           rtcTIMESetMinute
      * @param  RTCx RTC Instance
      * @param  Minutes Value between Min_Data=0x00 and Max_Data=0x59
      * @retval None
      */
    inline void rtcTIMESetMinute(uint32_t Minutes)
    {
      MODIFY_REG(rtcx_->TR, (RTC_TR_MNT | RTC_TR_MNU),
                (((Minutes & 0xF0U) << (RTC_TR_MNT_Pos - 4U)) | ((Minutes & 0x0FU) << RTC_TR_MNU_Pos)));
    }

    /**
      * @brief  Get Minutes in BCD format
      * @note if shadow mode is disabled (BYPSHAD=0), need to check if RSF flag is set
      *       before reading this bit
      * @note Read either RTC_SSR or RTC_TR locks the values in the higher-order calendar
      *       shadow registers until RTC_DR is read (rtcReadReg(RTC, DR)).
      * @note helper macro __rtcCONVERT_BCD2BIN is available to convert minute from BCD
      *       to Binary format
      * @rmtoll RTC_TR           MNT           rtcTIMEGetMinute
      *         RTC_TR           MNU           rtcTIMEGetMinute
      * @param  RTCx RTC Instance
      * @retval Value between Min_Data=0x00 and Max_Data=0x59
      */
    inline uint32_t rtcTIMEGetMinute()
    {
      return (uint32_t)(READ_BIT(rtcx_->TR, (RTC_TR_MNT | RTC_TR_MNU)) >> RTC_TR_MNU_Pos);
    }

    /**
      * @brief  Set Seconds in BCD format
      * @note   Bit is write-protected. @ref rtcDisableWriteProtection function should be called before.
      * @note   It can be written in initialization mode only (@ref rtcEnableInitMode function)
      * @note helper macro __rtcCONVERT_BIN2BCD is available to convert Seconds from binary to BCD format
      * @rmtoll RTC_TR           ST            rtcTIMESetSecond
      *         RTC_TR           SU            rtcTIMESetSecond
      * @param  RTCx RTC Instance
      * @param  Seconds Value between Min_Data=0x00 and Max_Data=0x59
      * @retval None
      */
    inline void rtcTIMESetSecond(uint32_t Seconds)
    {
      MODIFY_REG(rtcx_->TR, (RTC_TR_ST | RTC_TR_SU),
                (((Seconds & 0xF0U) << (RTC_TR_ST_Pos - 4U)) | ((Seconds & 0x0FU) << RTC_TR_SU_Pos)));
    }

    /**
      * @brief  Get Seconds in BCD format
      * @note if shadow mode is disabled (BYPSHAD=0), need to check if RSF flag is set
      *       before reading this bit
      * @note Read either RTC_SSR or RTC_TR locks the values in the higher-order calendar
      *       shadow registers until RTC_DR is read (rtcReadReg(RTC, DR)).
      * @note helper macro __rtcCONVERT_BCD2BIN is available to convert Seconds from BCD
      *       to Binary format
      * @rmtoll RTC_TR           ST            rtcTIMEGetSecond
      *         RTC_TR           SU            rtcTIMEGetSecond
      * @param  RTCx RTC Instance
      * @retval Value between Min_Data=0x00 and Max_Data=0x59
      */
    inline uint32_t rtcTIMEGetSecond()
    {
      return (uint32_t)(READ_BIT(rtcx_->TR, (RTC_TR_ST | RTC_TR_SU)) >> RTC_TR_SU_Pos);
    }

    /**
      * @brief  Set time (hour, minute and second) in BCD format
      * @note   Bit is write-protected. @ref rtcDisableWriteProtection function should be called before.
      * @note   It can be written in initialization mode only (@ref rtcEnableInitMode function)
      * @note TimeFormat and Hours should follow the same format
      * @rmtoll RTC_TR           PM            rtcTIMEConfig
      *         RTC_TR           HT            rtcTIMEConfig
      *         RTC_TR           HU            rtcTIMEConfig
      *         RTC_TR           MNT           rtcTIMEConfig
      *         RTC_TR           MNU           rtcTIMEConfig
      *         RTC_TR           ST            rtcTIMEConfig
      *         RTC_TR           SU            rtcTIMEConfig
      * @param  RTCx RTC Instance
      * @param  Format12_24 This parameter can be one of the following values:
      *         @arg @ref rtcTIMEFORMAT_AM_OR_24
      *         @arg @ref rtcTIMEFORMAT_PM
      * @param  Hours Value between Min_Data=0x01 and Max_Data=0x12 or between Min_Data=0x00 and Max_Data=0x23
      * @param  Minutes Value between Min_Data=0x00 and Max_Data=0x59
      * @param  Seconds Value between Min_Data=0x00 and Max_Data=0x59
      * @retval None
      */
    inline void rtcTIMEConfig(RTCTimeFormat Format12_24, uint32_t Hours, uint32_t Minutes, uint32_t Seconds)
    {
      uint32_t temp;

      temp = Format12_24                                                                                    | \
            (((Hours & 0xF0U) << (RTC_TR_HT_Pos - 4U)) | ((Hours & 0x0FU) << RTC_TR_HU_Pos))     | \
            (((Minutes & 0xF0U) << (RTC_TR_MNT_Pos - 4U)) | ((Minutes & 0x0FU) << RTC_TR_MNU_Pos)) | \
            (((Seconds & 0xF0U) << (RTC_TR_ST_Pos - 4U)) | ((Seconds & 0x0FU) << RTC_TR_SU_Pos));
      MODIFY_REG(rtcx_->TR, (RTC_TR_PM | RTC_TR_HT | RTC_TR_HU | RTC_TR_MNT | RTC_TR_MNU | RTC_TR_ST | RTC_TR_SU), temp);
    }

    /**
      * @brief  Get time (hour, minute and second) in BCD format
      * @note if shadow mode is disabled (BYPSHAD=0), need to check if RSF flag is set
      *       before reading this bit
      * @note Read either RTC_SSR or RTC_TR locks the values in the higher-order calendar
      *       shadow registers until RTC_DR is read (rtcReadReg(RTC, DR)).
      * @note helper macros __rtcGET_HOUR, __rtcGET_MINUTE and __rtcGET_SECOND
      *       are available to get independently each parameter.
      * @rmtoll RTC_TR           HT            rtcTIMEGet
      *         RTC_TR           HU            rtcTIMEGet
      *         RTC_TR           MNT           rtcTIMEGet
      *         RTC_TR           MNU           rtcTIMEGet
      *         RTC_TR           ST            rtcTIMEGet
      *         RTC_TR           SU            rtcTIMEGet
      * @param  RTCx RTC Instance
      * @retval Combination of hours, minutes and seconds (Format: 0x00HHMMSS).
      */
    inline uint32_t rtcTIMEGet()
    {
      uint32_t temp;

      temp = READ_BIT(rtcx_->TR, (RTC_TR_HT | RTC_TR_HU | RTC_TR_MNT | RTC_TR_MNU | RTC_TR_ST | RTC_TR_SU));
      return (uint32_t)((((((temp & RTC_TR_HT) >> RTC_TR_HT_Pos) << 4U) | ((temp & RTC_TR_HU) >> RTC_TR_HU_Pos)) << RTC_OFFSET_HOUR)       |  \
                        (((((temp & RTC_TR_MNT) >> RTC_TR_MNT_Pos) << 4U) | ((temp & RTC_TR_MNU) >> RTC_TR_MNU_Pos)) << RTC_OFFSET_MINUTE) | \
                        ((((temp & RTC_TR_ST) >> RTC_TR_ST_Pos) << 4U) | ((temp & RTC_TR_SU) >> RTC_TR_SU_Pos)));
    }

    /**
      * @brief  Memorize whether the daylight saving time change has been performed
      * @note   Bit is write-protected. @ref rtcDisableWriteProtection function should be called before.
      * @rmtoll RTC_CR           BKP           rtcTIMEEnableDayLightStore
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcTIMEEnableDayLightStore()
    {
      SET_BIT(rtcx_->CR, RTC_CR_BKP);
    }

    /**
      * @brief  Disable memorization whether the daylight saving time change has been performed.
      * @note   Bit is write-protected. @ref rtcDisableWriteProtection function should be called before.
      * @rmtoll RTC_CR           BKP           rtcTIMEDisableDayLightStore
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcTIMEDisableDayLightStore()
    {
      CLEAR_BIT(rtcx_->CR, RTC_CR_BKP);
    }

    /**
      * @brief  Check if RTC Day Light Saving stored operation has been enabled or not
      * @rmtoll RTC_CR           BKP           rtcTIMEIsDayLightStoreEnabled
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcTIMEIsDayLightStoreEnabled()
    {
      return ((READ_BIT(rtcx_->CR, RTC_CR_BKP) == (RTC_CR_BKP)) ? true : false);
    }

    /**
      * @brief  Subtract 1 hour (winter time change)
      * @note   Bit is write-protected. @ref rtcDisableWriteProtection function should be called before.
      * @rmtoll RTC_CR           SUB1H         rtcTIMEDecHour
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcTIMEDecHour()
    {
      SET_BIT(rtcx_->CR, RTC_CR_SUB1H);
    }

    /**
      * @brief  Add 1 hour (summer time change)
      * @note   Bit is write-protected. @ref rtcDisableWriteProtection function should be called before.
      * @rmtoll RTC_CR           ADD1H         rtcTIMEIncHour
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcTIMEIncHour()
    {
      SET_BIT(rtcx_->CR, RTC_CR_ADD1H);
    }

    /**
      * @brief  Get Sub second value in the synchronous prescaler counter.
      * @note  You can use both SubSeconds value and SecondFraction (PREDIV_S through
      *        rtcGetSynchPrescaler function) terms returned to convert Calendar
      *        SubSeconds value in second fraction ratio with time unit following
      *        generic formula:
      *          ==> Seconds fraction ratio * time_unit= [(SecondFraction-SubSeconds)/(SecondFraction+1)] * time_unit
      *        This conversion can be performed only if no shift operation is pending
      *        (ie. SHFP=0) when PREDIV_S >= SS.
      * @rmtoll RTC_SSR          SS            rtcTIMEGetSubSecond
      * @param  RTCx RTC Instance
      * @retval Sub second value (number between 0 and 65535)
      */
    inline uint32_t rtcTIMEGetSubSecond()
    {
      return (uint32_t)(READ_BIT(rtcx_->SSR, RTC_SSR_SS));
    }

    /**
      * @brief  Synchronize to a remote clock with a high degree of precision.
      * @note   This operation effectively subtracts from (delays) or advance the clock of a fraction of a second.
      * @note   Bit is write-protected. @ref rtcDisableWriteProtection function should be called before.
      * @note   When REFCKON is set, firmware must not write to Shift control register.
      * @rmtoll RTC_SHIFTR       ADD1S         rtcTIMESynchronize
      *         RTC_SHIFTR       SUBFS         rtcTIMESynchronize
      * @param  RTCx RTC Instance
      * @param  ShiftSecond This parameter can be one of the following values:
      *         @arg @ref rtcSHIFT_SECOND_DELAY
      *         @arg @ref rtcSHIFT_SECOND_ADVANCE
      * @param  Fraction Number of Seconds Fractions (any value from 0 to 0x7FFF)
      * @retval None
      */
    inline void rtcTIMESynchronize(RTCShitfSecond ShiftSecond, uint32_t Fraction)
    {
      WRITE_REG(rtcx_->SHIFTR, ShiftSecond | Fraction);
    }
    /** @defgroup RTC_LL_EF_Date Date
      * @{
      */

    /**
      * @brief  Set Year in BCD format
      * @note helper macro __rtcCONVERT_BIN2BCD is available to convert Year from binary to BCD format
      * @rmtoll RTC_DR           YT            rtcDATESetYear
      *         RTC_DR           YU            rtcDATESetYear
      * @param  RTCx RTC Instance
      * @param  Year Value between Min_Data=0x00 and Max_Data=0x99
      * @retval None
      */
    inline void rtcDATESetYear(uint32_t Year)
    {
      MODIFY_REG(rtcx_->DR, (RTC_DR_YT | RTC_DR_YU),
                (((Year & 0xF0U) << (RTC_DR_YT_Pos - 4U)) | ((Year & 0x0FU) << RTC_DR_YU_Pos)));
    }

    /**
      * @brief  Get Year in BCD format
      * @note if shadow mode is disabled (BYPSHAD=0), need to check if RSF flag is set
      *       before reading this bit
      * @note helper macro __rtcCONVERT_BCD2BIN is available to convert Year from BCD to Binary format
      * @rmtoll RTC_DR           YT            rtcDATEGetYear
      *         RTC_DR           YU            rtcDATEGetYear
      * @param  RTCx RTC Instance
      * @retval Value between Min_Data=0x00 and Max_Data=0x99
      */
    inline uint32_t rtcDATEGetYear()
    {
      return (uint32_t)((READ_BIT(rtcx_->DR, (RTC_DR_YT | RTC_DR_YU))) >> RTC_DR_YU_Pos);
    }

    /**
      * @brief  Set Week day
      * @rmtoll RTC_DR           WDU           rtcDATESetWeekDay
      * @param  RTCx RTC Instance
      * @param  WeekDay This parameter can be one of the following values:
      *         @arg @ref rtcWEEKDAY_MONDAY
      *         @arg @ref rtcWEEKDAY_TUESDAY
      *         @arg @ref rtcWEEKDAY_WEDNESDAY
      *         @arg @ref rtcWEEKDAY_THURSDAY
      *         @arg @ref rtcWEEKDAY_FRIDAY
      *         @arg @ref rtcWEEKDAY_SATURDAY
      *         @arg @ref rtcWEEKDAY_SUNDAY
      * @retval None
      */
    inline void rtcDATESetWeekDay(RTCWeekDay WeekDay)
    {
      MODIFY_REG(rtcx_->DR, RTC_DR_WDU, WeekDay << RTC_DR_WDU_Pos);
    }

    /**
      * @brief  Get Week day
      * @note if shadow mode is disabled (BYPSHAD=0), need to check if RSF flag is set
      *       before reading this bit
      * @rmtoll RTC_DR           WDU           rtcDATEGetWeekDay
      * @param  RTCx RTC Instance
      * @retval Returned value can be one of the following values:
      *         @arg @ref rtcWEEKDAY_MONDAY
      *         @arg @ref rtcWEEKDAY_TUESDAY
      *         @arg @ref rtcWEEKDAY_WEDNESDAY
      *         @arg @ref rtcWEEKDAY_THURSDAY
      *         @arg @ref rtcWEEKDAY_FRIDAY
      *         @arg @ref rtcWEEKDAY_SATURDAY
      *         @arg @ref rtcWEEKDAY_SUNDAY
      */
    inline RTCWeekDay rtcDATEGetWeekDay()
    {
      return (RTCWeekDay)(READ_BIT(rtcx_->DR, RTC_DR_WDU) >> RTC_DR_WDU_Pos);
    }

    /**
      * @brief  Set Month in BCD format
      * @note helper macro __rtcCONVERT_BIN2BCD is available to convert Month from binary to BCD format
      * @rmtoll RTC_DR           MT            rtcDATESetMonth
      *         RTC_DR           MU            rtcDATESetMonth
      * @param  RTCx RTC Instance
      * @param  Month This parameter can be one of the following values:
      *         @arg @ref rtcMONTH_JANUARY
      *         @arg @ref rtcMONTH_FEBRUARY
      *         @arg @ref rtcMONTH_MARCH
      *         @arg @ref rtcMONTH_APRIL
      *         @arg @ref rtcMONTH_MAY
      *         @arg @ref rtcMONTH_JUNE
      *         @arg @ref rtcMONTH_JULY
      *         @arg @ref rtcMONTH_AUGUST
      *         @arg @ref rtcMONTH_SEPTEMBER
      *         @arg @ref rtcMONTH_OCTOBER
      *         @arg @ref rtcMONTH_NOVEMBER
      *         @arg @ref rtcMONTH_DECEMBER
      * @retval None
      */
    inline void rtcDATESetMonth(RTCMonth Month)
    {
      MODIFY_REG(rtcx_->DR, (RTC_DR_MT | RTC_DR_MU),
                (((Month & 0xF0U) << (RTC_DR_MT_Pos - 4U)) | ((Month & 0x0FU) << RTC_DR_MU_Pos)));
    }

    /**
      * @brief  Get Month in BCD format
      * @note if shadow mode is disabled (BYPSHAD=0), need to check if RSF flag is set
      *       before reading this bit
      * @note helper macro __rtcCONVERT_BCD2BIN is available to convert Month from BCD to Binary format
      * @rmtoll RTC_DR           MT            rtcDATEGetMonth
      *         RTC_DR           MU            rtcDATEGetMonth
      * @param  RTCx RTC Instance
      * @retval Returned value can be one of the following values:
      *         @arg @ref rtcMONTH_JANUARY
      *         @arg @ref rtcMONTH_FEBRUARY
      *         @arg @ref rtcMONTH_MARCH
      *         @arg @ref rtcMONTH_APRIL
      *         @arg @ref rtcMONTH_MAY
      *         @arg @ref rtcMONTH_JUNE
      *         @arg @ref rtcMONTH_JULY
      *         @arg @ref rtcMONTH_AUGUST
      *         @arg @ref rtcMONTH_SEPTEMBER
      *         @arg @ref rtcMONTH_OCTOBER
      *         @arg @ref rtcMONTH_NOVEMBER
      *         @arg @ref rtcMONTH_DECEMBER
      */
    inline RTCMonth rtcDATEGetMonth()
    {
      return (RTCMonth)((READ_BIT(rtcx_->DR, (RTC_DR_MT | RTC_DR_MU))) >> RTC_DR_MU_Pos);
    }

    /**
      * @brief  Set Day in BCD format
      * @note helper macro __rtcCONVERT_BIN2BCD is available to convert Day from binary to BCD format
      * @rmtoll RTC_DR           DT            rtcDATESetDay
      *         RTC_DR           DU            rtcDATESetDay
      * @param  RTCx RTC Instance
      * @param  Day Value between Min_Data=0x01 and Max_Data=0x31
      * @retval None
      */
    inline void rtcDATESetDay(uint32_t Day)
    {
      MODIFY_REG(rtcx_->DR, (RTC_DR_DT | RTC_DR_DU),
                (((Day & 0xF0U) << (RTC_DR_DT_Pos - 4U)) | ((Day & 0x0FU) << RTC_DR_DU_Pos)));
    }

    /**
      * @brief  Get Day in BCD format
      * @note if shadow mode is disabled (BYPSHAD=0), need to check if RSF flag is set
      *       before reading this bit
      * @note helper macro __rtcCONVERT_BCD2BIN is available to convert Day from BCD to Binary format
      * @rmtoll RTC_DR           DT            rtcDATEGetDay
      *         RTC_DR           DU            rtcDATEGetDay
      * @param  RTCx RTC Instance
      * @retval Value between Min_Data=0x01 and Max_Data=0x31
      */
    inline uint32_t rtcDATEGetDay()
    {
      return (uint32_t)((READ_BIT(rtcx_->DR, (RTC_DR_DT | RTC_DR_DU))) >> RTC_DR_DU_Pos);
    }

    /**
      * @brief  Set date (WeekDay, Day, Month and Year) in BCD format
      * @rmtoll RTC_DR           WDU           rtcDATEConfig
      *         RTC_DR           MT            rtcDATEConfig
      *         RTC_DR           MU            rtcDATEConfig
      *         RTC_DR           DT            rtcDATEConfig
      *         RTC_DR           DU            rtcDATEConfig
      *         RTC_DR           YT            rtcDATEConfig
      *         RTC_DR           YU            rtcDATEConfig
      * @param  RTCx RTC Instance
      * @param  WeekDay This parameter can be one of the following values:
      *         @arg @ref rtcWEEKDAY_MONDAY
      *         @arg @ref rtcWEEKDAY_TUESDAY
      *         @arg @ref rtcWEEKDAY_WEDNESDAY
      *         @arg @ref rtcWEEKDAY_THURSDAY
      *         @arg @ref rtcWEEKDAY_FRIDAY
      *         @arg @ref rtcWEEKDAY_SATURDAY
      *         @arg @ref rtcWEEKDAY_SUNDAY
      * @param  Day Value between Min_Data=0x01 and Max_Data=0x31
      * @param  Month This parameter can be one of the following values:
      *         @arg @ref rtcMONTH_JANUARY
      *         @arg @ref rtcMONTH_FEBRUARY
      *         @arg @ref rtcMONTH_MARCH
      *         @arg @ref rtcMONTH_APRIL
      *         @arg @ref rtcMONTH_MAY
      *         @arg @ref rtcMONTH_JUNE
      *         @arg @ref rtcMONTH_JULY
      *         @arg @ref rtcMONTH_AUGUST
      *         @arg @ref rtcMONTH_SEPTEMBER
      *         @arg @ref rtcMONTH_OCTOBER
      *         @arg @ref rtcMONTH_NOVEMBER
      *         @arg @ref rtcMONTH_DECEMBER
      * @param  Year Value between Min_Data=0x00 and Max_Data=0x99
      * @retval None
      */
    inline void rtcDATEConfig(uint32_t WeekDay, uint32_t Day, uint32_t Month, uint32_t Year)
    {
      uint32_t temp;

      temp = (WeekDay << RTC_DR_WDU_Pos)                                                        | \
            (((Year & 0xF0U) << (RTC_DR_YT_Pos - 4U)) | ((Year & 0x0FU) << RTC_DR_YU_Pos))   | \
            (((Month & 0xF0U) << (RTC_DR_MT_Pos - 4U)) | ((Month & 0x0FU) << RTC_DR_MU_Pos)) | \
            (((Day & 0xF0U) << (RTC_DR_DT_Pos - 4U)) | ((Day & 0x0FU) << RTC_DR_DU_Pos));

      MODIFY_REG(rtcx_->DR, (RTC_DR_WDU | RTC_DR_MT | RTC_DR_MU | RTC_DR_DT | RTC_DR_DU | RTC_DR_YT | RTC_DR_YU), temp);
    }

    /**
      * @brief  Get date (WeekDay, Day, Month and Year) in BCD format
      * @note if shadow mode is disabled (BYPSHAD=0), need to check if RSF flag is set
      *       before reading this bit
      * @note helper macros __rtcGET_WEEKDAY, __rtcGET_YEAR, __rtcGET_MONTH,
      * and __rtcGET_DAY are available to get independently each parameter.
      * @rmtoll RTC_DR           WDU           rtcDATEGet
      *         RTC_DR           MT            rtcDATEGet
      *         RTC_DR           MU            rtcDATEGet
      *         RTC_DR           DT            rtcDATEGet
      *         RTC_DR           DU            rtcDATEGet
      *         RTC_DR           YT            rtcDATEGet
      *         RTC_DR           YU            rtcDATEGet
      * @param  RTCx RTC Instance
      * @retval Combination of WeekDay, Day, Month and Year (Format: 0xWWDDMMYY).
      */
    inline uint32_t rtcDATEGet()
    {
      uint32_t temp;

      temp = READ_BIT(rtcx_->DR, (RTC_DR_WDU | RTC_DR_MT | RTC_DR_MU | RTC_DR_DT | RTC_DR_DU | RTC_DR_YT | RTC_DR_YU));
      return (uint32_t)((((temp & RTC_DR_WDU) >> RTC_DR_WDU_Pos) << RTC_OFFSET_WEEKDAY) | \
                        (((((temp & RTC_DR_DT) >> RTC_DR_DT_Pos) << 4U) | ((temp & RTC_DR_DU) >> RTC_DR_DU_Pos)) << RTC_OFFSET_DAY)   | \
                        (((((temp & RTC_DR_MT) >> RTC_DR_MT_Pos) << 4U) | ((temp & RTC_DR_MU) >> RTC_DR_MU_Pos)) << RTC_OFFSET_MONTH) | \
                        ((((temp & RTC_DR_YT) >> RTC_DR_YT_Pos) << 4U) | ((temp & RTC_DR_YU) >> RTC_DR_YU_Pos)));
    }

    /**
      * @brief  Enable Alarm A
      * @note   Bit is write-protected. @ref rtcDisableWriteProtection function should be called before.
      * @rmtoll RTC_CR           ALRAE         rtcALMAEnable
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcALMAEnable()
    {
      SET_BIT(rtcx_->CR, RTC_CR_ALRAE);
    }

    /**
      * @brief  Disable Alarm A
      * @note   Bit is write-protected. @ref rtcDisableWriteProtection function should be called before.
      * @rmtoll RTC_CR           ALRAE         rtcALMADisable
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcALMADisable()
    {
      CLEAR_BIT(rtcx_->CR, RTC_CR_ALRAE);
    }

    /**
      * @brief  Specify the Alarm A masks.
      * @rmtoll RTC_ALRMAR       MSK4          rtcALMASetMask
      *         RTC_ALRMAR       MSK3          rtcALMASetMask
      *         RTC_ALRMAR       MSK2          rtcALMASetMask
      *         RTC_ALRMAR       MSK1          rtcALMASetMask
      * @param  RTCx RTC Instance
      * @param  Mask This parameter can be a combination of the following values:
      *         @arg @ref rtcALMAMASK_NONE
      *         @arg @ref rtcALMAMASK_DATEWEEKDAY
      *         @arg @ref rtcALMAMASK_HOURS
      *         @arg @ref rtcALMAMASK_MINUTES
      *         @arg @ref rtcALMAMASK_SECONDS
      *         @arg @ref rtcALMAMASK_ALL
      * @retval None
      */
    inline void rtcALMASetMask(RTCAlarmAMask Mask)
    {
      MODIFY_REG(rtcx_->ALRMAR, RTC_ALRMAR_MSK4 | RTC_ALRMAR_MSK3 | RTC_ALRMAR_MSK2 | RTC_ALRMAR_MSK1, Mask);
    }

    /**
      * @brief  Get the Alarm A masks.
      * @rmtoll RTC_ALRMAR       MSK4          rtcALMAGetMask
      *         RTC_ALRMAR       MSK3          rtcALMAGetMask
      *         RTC_ALRMAR       MSK2          rtcALMAGetMask
      *         RTC_ALRMAR       MSK1          rtcALMAGetMask
      * @param  RTCx RTC Instance
      * @retval Returned value can be can be a combination of the following values:
      *         @arg @ref rtcALMAMASK_NONE
      *         @arg @ref rtcALMAMASK_DATEWEEKDAY
      *         @arg @ref rtcALMAMASK_HOURS
      *         @arg @ref rtcALMAMASK_MINUTES
      *         @arg @ref rtcALMAMASK_SECONDS
      *         @arg @ref rtcALMAMASK_ALL
      */
    inline RTCAlarmAMask rtcALMAGetMask()
    {
      return (RTCAlarmAMask)(READ_BIT(rtcx_->ALRMAR, RTC_ALRMAR_MSK4 | RTC_ALRMAR_MSK3 | RTC_ALRMAR_MSK2 | RTC_ALRMAR_MSK1));
    }

    /**
      * @brief  Enable AlarmA Week day selection (DU[3:0] represents the week day. DT[1:0] is do not care)
      * @rmtoll RTC_ALRMAR       WDSEL         rtcALMAEnableWeekday
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcALMAEnableWeekday()
    {
      SET_BIT(rtcx_->ALRMAR, RTC_ALRMAR_WDSEL);
    }

    /**
      * @brief  Disable AlarmA Week day selection (DU[3:0] represents the date )
      * @rmtoll RTC_ALRMAR       WDSEL         rtcALMADisableWeekday
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcALMADisableWeekday()
    {
      CLEAR_BIT(rtcx_->ALRMAR, RTC_ALRMAR_WDSEL);
    }

    /**
      * @brief  Set ALARM A Day in BCD format
      * @note helper macro __rtcCONVERT_BIN2BCD is available to convert Day from binary to BCD format
      * @rmtoll RTC_ALRMAR       DT            rtcALMASetDay
      *         RTC_ALRMAR       DU            rtcALMASetDay
      * @param  RTCx RTC Instance
      * @param  Day Value between Min_Data=0x01 and Max_Data=0x31
      * @retval None
      */
    inline void rtcALMASetDay(uint32_t Day)
    {
      MODIFY_REG(rtcx_->ALRMAR, (RTC_ALRMAR_DT | RTC_ALRMAR_DU),
                (((Day & 0xF0U) << (RTC_ALRMAR_DT_Pos - 4U)) | ((Day & 0x0FU) << RTC_ALRMAR_DU_Pos)));
    }

    /**
      * @brief  Get ALARM A Day in BCD format
      * @note helper macro __rtcCONVERT_BCD2BIN is available to convert Day from BCD to Binary format
      * @rmtoll RTC_ALRMAR       DT            rtcALMAGetDay
      *         RTC_ALRMAR       DU            rtcALMAGetDay
      * @param  RTCx RTC Instance
      * @retval Value between Min_Data=0x01 and Max_Data=0x31
      */
    inline uint32_t rtcALMAGetDay()
    {
      return (uint32_t)((READ_BIT(rtcx_->ALRMAR, (RTC_ALRMAR_DT | RTC_ALRMAR_DU))) >> RTC_ALRMAR_DU_Pos);
    }

    /**
      * @brief  Set ALARM A Weekday
      * @rmtoll RTC_ALRMAR       DU            rtcALMASetWeekDay
      * @param  RTCx RTC Instance
      * @param  WeekDay This parameter can be one of the following values:
      *         @arg @ref rtcWEEKDAY_MONDAY
      *         @arg @ref rtcWEEKDAY_TUESDAY
      *         @arg @ref rtcWEEKDAY_WEDNESDAY
      *         @arg @ref rtcWEEKDAY_THURSDAY
      *         @arg @ref rtcWEEKDAY_FRIDAY
      *         @arg @ref rtcWEEKDAY_SATURDAY
      *         @arg @ref rtcWEEKDAY_SUNDAY
      * @retval None
      */
    inline void rtcALMASetWeekDay(RTCWeekDay WeekDay)
    {
      MODIFY_REG(rtcx_->ALRMAR, RTC_ALRMAR_DU, WeekDay << RTC_ALRMAR_DU_Pos);
    }

    /**
      * @brief  Get ALARM A Weekday
      * @rmtoll RTC_ALRMAR       DU            rtcALMAGetWeekDay
      * @param  RTCx RTC Instance
      * @retval Returned value can be one of the following values:
      *         @arg @ref rtcWEEKDAY_MONDAY
      *         @arg @ref rtcWEEKDAY_TUESDAY
      *         @arg @ref rtcWEEKDAY_WEDNESDAY
      *         @arg @ref rtcWEEKDAY_THURSDAY
      *         @arg @ref rtcWEEKDAY_FRIDAY
      *         @arg @ref rtcWEEKDAY_SATURDAY
      *         @arg @ref rtcWEEKDAY_SUNDAY
      */
    inline RTCWeekDay rtcALMAGetWeekDay()
    {
      return (RTCWeekDay)(READ_BIT(rtcx_->ALRMAR, RTC_ALRMAR_DU) >> RTC_ALRMAR_DU_Pos);
    }

    /**
      * @brief  Set Alarm A time format (AM/24-hour or PM notation)
      * @rmtoll RTC_ALRMAR       PM            rtcALMASetTimeFormat
      * @param  RTCx RTC Instance
      * @param  TimeFormat This parameter can be one of the following values:
      *         @arg @ref rtcALMATIME_FORMAT_AM
      *         @arg @ref rtcALMATIME_FORMAT_PM
      * @retval None
      */
    inline void rtcALMASetTimeFormat(RTCAlarmATimeFormat TimeFormat)
    {
      MODIFY_REG(rtcx_->ALRMAR, RTC_ALRMAR_PM, TimeFormat);
    }

    /**
      * @brief  Get Alarm A time format (AM or PM notation)
      * @rmtoll RTC_ALRMAR       PM            rtcALMAGetTimeFormat
      * @param  RTCx RTC Instance
      * @retval Returned value can be one of the following values:
      *         @arg @ref rtcALMATIME_FORMAT_AM
      *         @arg @ref rtcALMATIME_FORMAT_PM
      */
    inline RTCAlarmATimeFormat rtcALMAGetTimeFormat()
    {
      return (RTCAlarmATimeFormat)(READ_BIT(rtcx_->ALRMAR, RTC_ALRMAR_PM));
    }

    /**
      * @brief  Set ALARM A Hours in BCD format
      * @note helper macro __rtcCONVERT_BIN2BCD is available to convert Hours from binary to BCD format
      * @rmtoll RTC_ALRMAR       HT            rtcALMASetHour
      *         RTC_ALRMAR       HU            rtcALMASetHour
      * @param  RTCx RTC Instance
      * @param  Hours Value between Min_Data=0x01 and Max_Data=0x12 or between Min_Data=0x00 and Max_Data=0x23
      * @retval None
      */
    inline void rtcALMASetHour(uint32_t Hours)
    {
      MODIFY_REG(rtcx_->ALRMAR, (RTC_ALRMAR_HT | RTC_ALRMAR_HU),
                (((Hours & 0xF0U) << (RTC_ALRMAR_HT_Pos - 4U)) | ((Hours & 0x0FU) << RTC_ALRMAR_HU_Pos)));
    }

    /**
      * @brief  Get ALARM A Hours in BCD format
      * @note helper macro __rtcCONVERT_BCD2BIN is available to convert Hours from BCD to Binary format
      * @rmtoll RTC_ALRMAR       HT            rtcALMAGetHour
      *         RTC_ALRMAR       HU            rtcALMAGetHour
      * @param  RTCx RTC Instance
      * @retval Value between Min_Data=0x01 and Max_Data=0x12 or between Min_Data=0x00 and Max_Data=0x23
      */
    inline uint32_t rtcALMAGetHour()
    {
      return (uint32_t)((READ_BIT(rtcx_->ALRMAR, (RTC_ALRMAR_HT | RTC_ALRMAR_HU))) >> RTC_ALRMAR_HU_Pos);
    }

    /**
      * @brief  Set ALARM A Minutes in BCD format
      * @note helper macro __rtcCONVERT_BIN2BCD is available to convert Minutes from binary to BCD format
      * @rmtoll RTC_ALRMAR       MNT           rtcALMASetMinute
      *         RTC_ALRMAR       MNU           rtcALMASetMinute
      * @param  RTCx RTC Instance
      * @param  Minutes Value between Min_Data=0x00 and Max_Data=0x59
      * @retval None
      */
    inline void rtcALMASetMinute(uint32_t Minutes)
    {
      MODIFY_REG(rtcx_->ALRMAR, (RTC_ALRMAR_MNT | RTC_ALRMAR_MNU),
                (((Minutes & 0xF0U) << (RTC_ALRMAR_MNT_Pos - 4U)) | ((Minutes & 0x0FU) << RTC_ALRMAR_MNU_Pos)));
    }

    /**
      * @brief  Get ALARM A Minutes in BCD format
      * @note helper macro __rtcCONVERT_BCD2BIN is available to convert Minutes from BCD to Binary format
      * @rmtoll RTC_ALRMAR       MNT           rtcALMAGetMinute
      *         RTC_ALRMAR       MNU           rtcALMAGetMinute
      * @param  RTCx RTC Instance
      * @retval Value between Min_Data=0x00 and Max_Data=0x59
      */
    inline uint32_t rtcALMAGetMinute()
    {
      return (uint32_t)((READ_BIT(rtcx_->ALRMAR, (RTC_ALRMAR_MNT | RTC_ALRMAR_MNU))) >> RTC_ALRMAR_MNU_Pos);
    }

    /**
      * @brief  Set ALARM A Seconds in BCD format
      * @note helper macro __rtcCONVERT_BIN2BCD is available to convert Seconds from binary to BCD format
      * @rmtoll RTC_ALRMAR       ST            rtcALMASetSecond
      *         RTC_ALRMAR       SU            rtcALMASetSecond
      * @param  RTCx RTC Instance
      * @param  Seconds Value between Min_Data=0x00 and Max_Data=0x59
      * @retval None
      */
    inline void rtcALMASetSecond(uint32_t Seconds)
    {
      MODIFY_REG(rtcx_->ALRMAR, (RTC_ALRMAR_ST | RTC_ALRMAR_SU),
                (((Seconds & 0xF0U) << (RTC_ALRMAR_ST_Pos - 4U)) | ((Seconds & 0x0FU) << RTC_ALRMAR_SU_Pos)));
    }

    /**
      * @brief  Get ALARM A Seconds in BCD format
      * @note helper macro __rtcCONVERT_BCD2BIN is available to convert Seconds from BCD to Binary format
      * @rmtoll RTC_ALRMAR       ST            rtcALMAGetSecond
      *         RTC_ALRMAR       SU            rtcALMAGetSecond
      * @param  RTCx RTC Instance
      * @retval Value between Min_Data=0x00 and Max_Data=0x59
      */
    inline uint32_t rtcALMAGetSecond()
    {
      return (uint32_t)((READ_BIT(rtcx_->ALRMAR, (RTC_ALRMAR_ST | RTC_ALRMAR_SU))) >> RTC_ALRMAR_SU_Pos);
    }

    /**
      * @brief  Set Alarm A Time (hour, minute and second) in BCD format
      * @rmtoll RTC_ALRMAR       PM            rtcALMAConfigTime
      *         RTC_ALRMAR       HT            rtcALMAConfigTime
      *         RTC_ALRMAR       HU            rtcALMAConfigTime
      *         RTC_ALRMAR       MNT           rtcALMAConfigTime
      *         RTC_ALRMAR       MNU           rtcALMAConfigTime
      *         RTC_ALRMAR       ST            rtcALMAConfigTime
      *         RTC_ALRMAR       SU            rtcALMAConfigTime
      * @param  RTCx RTC Instance
      * @param  Format12_24 This parameter can be one of the following values:
      *         @arg @ref rtcALMATIME_FORMAT_AM
      *         @arg @ref rtcALMATIME_FORMAT_PM
      * @param  Hours Value between Min_Data=0x01 and Max_Data=0x12 or between Min_Data=0x00 and Max_Data=0x23
      * @param  Minutes Value between Min_Data=0x00 and Max_Data=0x59
      * @param  Seconds Value between Min_Data=0x00 and Max_Data=0x59
      * @retval None
      */
    inline void rtcALMAConfigTime(RTCAlarmATimeFormat Format12_24, uint32_t Hours, uint32_t Minutes, uint32_t Seconds)
    {
      uint32_t temp;

      temp = Format12_24 | (((Hours & 0xF0U) << (RTC_ALRMAR_HT_Pos - 4U)) | ((Hours & 0x0FU) << RTC_ALRMAR_HU_Pos))    | \
            (((Minutes & 0xF0U) << (RTC_ALRMAR_MNT_Pos - 4U)) | ((Minutes & 0x0FU) << RTC_ALRMAR_MNU_Pos)) | \
            (((Seconds & 0xF0U) << (RTC_ALRMAR_ST_Pos - 4U)) | ((Seconds & 0x0FU) << RTC_ALRMAR_SU_Pos));

      MODIFY_REG(rtcx_->ALRMAR, RTC_ALRMAR_PM | RTC_ALRMAR_HT | RTC_ALRMAR_HU | RTC_ALRMAR_MNT | RTC_ALRMAR_MNU | RTC_ALRMAR_ST | RTC_ALRMAR_SU, temp);
    }

    /**
      * @brief  Get Alarm B Time (hour, minute and second) in BCD format
      * @note helper macros __rtcGET_HOUR, __rtcGET_MINUTE and __rtcGET_SECOND
      * are available to get independently each parameter.
      * @rmtoll RTC_ALRMAR       HT            rtcALMAGetTime
      *         RTC_ALRMAR       HU            rtcALMAGetTime
      *         RTC_ALRMAR       MNT           rtcALMAGetTime
      *         RTC_ALRMAR       MNU           rtcALMAGetTime
      *         RTC_ALRMAR       ST            rtcALMAGetTime
      *         RTC_ALRMAR       SU            rtcALMAGetTime
      * @param  RTCx RTC Instance
      * @retval Combination of hours, minutes and seconds.
      */
    inline uint32_t rtcALMAGetTime()
    {
      return (uint32_t)((rtcALMAGetHour() << RTC_OFFSET_HOUR) | (rtcALMAGetMinute() << RTC_OFFSET_MINUTE) | rtcALMAGetSecond());
    }

    /**
      * @brief  Set Alarm A Mask the most-significant bits starting at this bit
      * @note This register can be written only when ALRAE is reset in RTC_CR register,
      *       or in initialization mode.
      * @rmtoll RTC_ALRMASSR     MASKSS        rtcALMASetSubSecondMask
      * @param  RTCx RTC Instance
      * @param  Mask Value between Min_Data=0x00 and Max_Data=0xF
      * @retval None
      */
    inline void rtcALMASetSubSecondMask(uint32_t Mask)
    {
      MODIFY_REG(rtcx_->ALRMASSR, RTC_ALRMASSR_MASKSS, Mask << RTC_ALRMASSR_MASKSS_Pos);
    }

    /**
      * @brief  Get Alarm A Mask the most-significant bits starting at this bit
      * @rmtoll RTC_ALRMASSR     MASKSS        rtcALMAGetSubSecondMask
      * @param  RTCx RTC Instance
      * @retval Value between Min_Data=0x00 and Max_Data=0xF
      */
    inline uint32_t rtcALMAGetSubSecondMask()
    {
      return (uint32_t)(READ_BIT(rtcx_->ALRMASSR, RTC_ALRMASSR_MASKSS) >> RTC_ALRMASSR_MASKSS_Pos);
    }

    /**
      * @brief  Set Alarm A Sub seconds value
      * @rmtoll RCT_ALRMASSR     SS            rtcALMASetSubSecond
      * @param  RTCx RTC Instance
      * @param  Subsecond Value between Min_Data=0x00 and Max_Data=0x7FFF
      * @retval None
      */
    inline void rtcALMASetSubSecond(uint32_t Subsecond)
    {
      MODIFY_REG(rtcx_->ALRMASSR, RTC_ALRMASSR_SS, Subsecond);
    }

    /**
      * @brief  Get Alarm A Sub seconds value
      * @rmtoll RCT_ALRMASSR     SS            rtcALMAGetSubSecond
      * @param  RTCx RTC Instance
      * @retval Value between Min_Data=0x00 and Max_Data=0x7FFF
      */
    inline uint32_t rtcALMAGetSubSecond()
    {
      return (uint32_t)(READ_BIT(rtcx_->ALRMASSR, RTC_ALRMASSR_SS));
    }

    /**
      * @}
      */

    /** @defgroup RTC_LL_EF_ALARMB ALARMB
      * @{
      */

    /**
      * @brief  Enable Alarm B
      * @note   Bit is write-protected. @ref rtcDisableWriteProtection function should be called before.
      * @rmtoll RTC_CR           ALRBE         rtcALMBEnable
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcALMBEnable()
    {
      SET_BIT(rtcx_->CR, RTC_CR_ALRBE);
    }

    /**
      * @brief  Disable Alarm B
      * @note   Bit is write-protected. @ref rtcDisableWriteProtection function should be called before.
      * @rmtoll RTC_CR           ALRBE         rtcALMBDisable
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcALMBDisable()
    {
      CLEAR_BIT(rtcx_->CR, RTC_CR_ALRBE);
    }

    /**
      * @brief  Specify the Alarm B masks.
      * @rmtoll RTC_ALRMBR       MSK4          rtcALMBSetMask
      *         RTC_ALRMBR       MSK3          rtcALMBSetMask
      *         RTC_ALRMBR       MSK2          rtcALMBSetMask
      *         RTC_ALRMBR       MSK1          rtcALMBSetMask
      * @param  RTCx RTC Instance
      * @param  Mask This parameter can be a combination of the following values:
      *         @arg @ref rtcALMBMASK_NONE
      *         @arg @ref rtcALMBMASK_DATEWEEKDAY
      *         @arg @ref rtcALMBMASK_HOURS
      *         @arg @ref rtcALMBMASK_MINUTES
      *         @arg @ref rtcALMBMASK_SECONDS
      *         @arg @ref rtcALMBMASK_ALL
      * @retval None
      */
    inline void rtcALMBSetMask(RTCAlarmBMask Mask)
    {
      MODIFY_REG(rtcx_->ALRMBR, RTC_ALRMBR_MSK4 | RTC_ALRMBR_MSK3 | RTC_ALRMBR_MSK2 | RTC_ALRMBR_MSK1, Mask);
    }

    /**
      * @brief  Get the Alarm B masks.
      * @rmtoll RTC_ALRMBR       MSK4          rtcALMBGetMask
      *         RTC_ALRMBR       MSK3          rtcALMBGetMask
      *         RTC_ALRMBR       MSK2          rtcALMBGetMask
      *         RTC_ALRMBR       MSK1          rtcALMBGetMask
      * @param  RTCx RTC Instance
      * @retval Returned value can be can be a combination of the following values:
      *         @arg @ref rtcALMBMASK_NONE
      *         @arg @ref rtcALMBMASK_DATEWEEKDAY
      *         @arg @ref rtcALMBMASK_HOURS
      *         @arg @ref rtcALMBMASK_MINUTES
      *         @arg @ref rtcALMBMASK_SECONDS
      *         @arg @ref rtcALMBMASK_ALL
      */
    inline RTCAlarmBMask rtcALMBGetMask()
    {
      return (RTCAlarmBMask)(READ_BIT(rtcx_->ALRMBR, RTC_ALRMBR_MSK4 | RTC_ALRMBR_MSK3 | RTC_ALRMBR_MSK2 | RTC_ALRMBR_MSK1));
    }

    /**
      * @brief  Enable AlarmB Week day selection (DU[3:0] represents the week day. DT[1:0] is do not care)
      * @rmtoll RTC_ALRMBR       WDSEL         rtcALMBEnableWeekday
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcALMBEnableWeekday()
    {
      SET_BIT(rtcx_->ALRMBR, RTC_ALRMBR_WDSEL);
    }

    /**
      * @brief  Disable AlarmB Week day selection (DU[3:0] represents the date )
      * @rmtoll RTC_ALRMBR       WDSEL         rtcALMBDisableWeekday
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcALMBDisableWeekday()
    {
      CLEAR_BIT(rtcx_->ALRMBR, RTC_ALRMBR_WDSEL);
    }

    /**
      * @brief  Set ALARM B Day in BCD format
      * @note helper macro __rtcCONVERT_BIN2BCD is available to convert Day from binary to BCD format
      * @rmtoll RTC_ALRMBR       DT            rtcALMBSetDay
      *         RTC_ALRMBR       DU            rtcALMBSetDay
      * @param  RTCx RTC Instance
      * @param  Day Value between Min_Data=0x01 and Max_Data=0x31
      * @retval None
      */
    inline void rtcALMBSetDay(uint32_t Day)
    {
      MODIFY_REG(rtcx_->ALRMBR, (RTC_ALRMBR_DT | RTC_ALRMBR_DU),
                (((Day & 0xF0U) << (RTC_ALRMBR_DT_Pos - 4U)) | ((Day & 0x0FU) << RTC_ALRMBR_DU_Pos)));
    }

    /**
      * @brief  Get ALARM B Day in BCD format
      * @note helper macro __rtcCONVERT_BCD2BIN is available to convert Day from BCD to Binary format
      * @rmtoll RTC_ALRMBR       DT            rtcALMBGetDay
      *         RTC_ALRMBR       DU            rtcALMBGetDay
      * @param  RTCx RTC Instance
      * @retval Value between Min_Data=0x01 and Max_Data=0x31
      */
    inline uint32_t rtcALMBGetDay()
    {
      return (uint32_t)((READ_BIT(rtcx_->ALRMBR, (RTC_ALRMBR_DT | RTC_ALRMBR_DU))) >> RTC_ALRMBR_DU_Pos);
    }

    /**
      * @brief  Set ALARM B Weekday
      * @rmtoll RTC_ALRMBR       DU            rtcALMBSetWeekDay
      * @param  RTCx RTC Instance
      * @param  WeekDay This parameter can be one of the following values:
      *         @arg @ref rtcWEEKDAY_MONDAY
      *         @arg @ref rtcWEEKDAY_TUESDAY
      *         @arg @ref rtcWEEKDAY_WEDNESDAY
      *         @arg @ref rtcWEEKDAY_THURSDAY
      *         @arg @ref rtcWEEKDAY_FRIDAY
      *         @arg @ref rtcWEEKDAY_SATURDAY
      *         @arg @ref rtcWEEKDAY_SUNDAY
      * @retval None
      */
    inline void rtcALMBSetWeekDay(RTCWeekDay WeekDay)
    {
      MODIFY_REG(rtcx_->ALRMBR, RTC_ALRMBR_DU, WeekDay << RTC_ALRMBR_DU_Pos);
    }

    /**
      * @brief  Get ALARM B Weekday
      * @rmtoll RTC_ALRMBR       DU            rtcALMBGetWeekDay
      * @param  RTCx RTC Instance
      * @retval Returned value can be one of the following values:
      *         @arg @ref rtcWEEKDAY_MONDAY
      *         @arg @ref rtcWEEKDAY_TUESDAY
      *         @arg @ref rtcWEEKDAY_WEDNESDAY
      *         @arg @ref rtcWEEKDAY_THURSDAY
      *         @arg @ref rtcWEEKDAY_FRIDAY
      *         @arg @ref rtcWEEKDAY_SATURDAY
      *         @arg @ref rtcWEEKDAY_SUNDAY
      */
    inline RTCWeekDay rtcALMBGetWeekDay()
    {
      return (RTCWeekDay)(READ_BIT(rtcx_->ALRMBR, RTC_ALRMBR_DU) >> RTC_ALRMBR_DU_Pos);
    }

    /**
      * @brief  Set ALARM B time format (AM/24-hour or PM notation)
      * @rmtoll RTC_ALRMBR       PM            rtcALMBSetTimeFormat
      * @param  RTCx RTC Instance
      * @param  TimeFormat This parameter can be one of the following values:
      *         @arg @ref rtcALMBTIME_FORMAT_AM
      *         @arg @ref rtcALMBTIME_FORMAT_PM
      * @retval None
      */
    inline void rtcALMBSetTimeFormat(RTCAlarmBTimeFormat TimeFormat)
    {
      MODIFY_REG(rtcx_->ALRMBR, RTC_ALRMBR_PM, TimeFormat);
    }

    /**
      * @brief  Get ALARM B time format (AM or PM notation)
      * @rmtoll RTC_ALRMBR       PM            rtcALMBGetTimeFormat
      * @param  RTCx RTC Instance
      * @retval Returned value can be one of the following values:
      *         @arg @ref rtcALMBTIME_FORMAT_AM
      *         @arg @ref rtcALMBTIME_FORMAT_PM
      */
    inline RTCAlarmBTimeFormat rtcALMBGetTimeFormat()
    {
      return (RTCAlarmBTimeFormat)(READ_BIT(rtcx_->ALRMBR, RTC_ALRMBR_PM));
    }

    /**
      * @brief  Set ALARM B Hours in BCD format
      * @note helper macro __rtcCONVERT_BIN2BCD is available to convert Hours from binary to BCD format
      * @rmtoll RTC_ALRMBR       HT            rtcALMBSetHour
      *         RTC_ALRMBR       HU            rtcALMBSetHour
      * @param  RTCx RTC Instance
      * @param  Hours Value between Min_Data=0x01 and Max_Data=0x12 or between Min_Data=0x00 and Max_Data=0x23
      * @retval None
      */
    inline void rtcALMBSetHour(uint32_t Hours)
    {
      MODIFY_REG(rtcx_->ALRMBR, (RTC_ALRMBR_HT | RTC_ALRMBR_HU),
                (((Hours & 0xF0U) << (RTC_ALRMBR_HT_Pos - 4U)) | ((Hours & 0x0FU) << RTC_ALRMBR_HU_Pos)));
    }

    /**
      * @brief  Get ALARM B Hours in BCD format
      * @note helper macro __rtcCONVERT_BCD2BIN is available to convert Hours from BCD to Binary format
      * @rmtoll RTC_ALRMBR       HT            rtcALMBGetHour
      *         RTC_ALRMBR       HU            rtcALMBGetHour
      * @param  RTCx RTC Instance
      * @retval Value between Min_Data=0x01 and Max_Data=0x12 or between Min_Data=0x00 and Max_Data=0x23
      */
    inline uint32_t rtcALMBGetHour()
    {
      return (uint32_t)((READ_BIT(rtcx_->ALRMBR, (RTC_ALRMBR_HT | RTC_ALRMBR_HU))) >> RTC_ALRMBR_HU_Pos);
    }

    /**
      * @brief  Set ALARM B Minutes in BCD format
      * @note helper macro __rtcCONVERT_BIN2BCD is available to convert Minutes from binary to BCD format
      * @rmtoll RTC_ALRMBR       MNT           rtcALMBSetMinute
      *         RTC_ALRMBR       MNU           rtcALMBSetMinute
      * @param  RTCx RTC Instance
      * @param  Minutes between Min_Data=0x00 and Max_Data=0x59
      * @retval None
      */
    inline void rtcALMBSetMinute(uint32_t Minutes)
    {
      MODIFY_REG(rtcx_->ALRMBR, (RTC_ALRMBR_MNT | RTC_ALRMBR_MNU),
                (((Minutes & 0xF0U) << (RTC_ALRMBR_MNT_Pos - 4U)) | ((Minutes & 0x0FU) << RTC_ALRMBR_MNU_Pos)));
    }

    /**
      * @brief  Get ALARM B Minutes in BCD format
      * @note helper macro __rtcCONVERT_BCD2BIN is available to convert Minutes from BCD to Binary format
      * @rmtoll RTC_ALRMBR       MNT           rtcALMBGetMinute
      *         RTC_ALRMBR       MNU           rtcALMBGetMinute
      * @param  RTCx RTC Instance
      * @retval Value between Min_Data=0x00 and Max_Data=0x59
      */
    inline uint32_t rtcALMBGetMinute()
    {
      return (uint32_t)((READ_BIT(rtcx_->ALRMBR, (RTC_ALRMBR_MNT | RTC_ALRMBR_MNU))) >> RTC_ALRMBR_MNU_Pos);
    }

    /**
      * @brief  Set ALARM B Seconds in BCD format
      * @note helper macro __rtcCONVERT_BIN2BCD is available to convert Seconds from binary to BCD format
      * @rmtoll RTC_ALRMBR       ST            rtcALMBSetSecond
      *         RTC_ALRMBR       SU            rtcALMBSetSecond
      * @param  RTCx RTC Instance
      * @param  Seconds Value between Min_Data=0x00 and Max_Data=0x59
      * @retval None
      */
    inline void rtcALMBSetSecond(uint32_t Seconds)
    {
      MODIFY_REG(rtcx_->ALRMBR, (RTC_ALRMBR_ST | RTC_ALRMBR_SU),
                (((Seconds & 0xF0U) << (RTC_ALRMBR_ST_Pos - 4U)) | ((Seconds & 0x0FU) << RTC_ALRMBR_SU_Pos)));
    }

    /**
      * @brief  Get ALARM B Seconds in BCD format
      * @note helper macro __rtcCONVERT_BCD2BIN is available to convert Seconds from BCD to Binary format
      * @rmtoll RTC_ALRMBR       ST            rtcALMBGetSecond
      *         RTC_ALRMBR       SU            rtcALMBGetSecond
      * @param  RTCx RTC Instance
      * @retval Value between Min_Data=0x00 and Max_Data=0x59
      */
    inline uint32_t rtcALMBGetSecond()
    {
      return (uint32_t)((READ_BIT(rtcx_->ALRMBR, (RTC_ALRMBR_ST | RTC_ALRMBR_SU))) >> RTC_ALRMBR_SU_Pos);
    }

    /**
      * @brief  Set Alarm B Time (hour, minute and second) in BCD format
      * @rmtoll RTC_ALRMBR       PM            rtcALMBConfigTime
      *         RTC_ALRMBR       HT            rtcALMBConfigTime
      *         RTC_ALRMBR       HU            rtcALMBConfigTime
      *         RTC_ALRMBR       MNT           rtcALMBConfigTime
      *         RTC_ALRMBR       MNU           rtcALMBConfigTime
      *         RTC_ALRMBR       ST            rtcALMBConfigTime
      *         RTC_ALRMBR       SU            rtcALMBConfigTime
      * @param  RTCx RTC Instance
      * @param  Format12_24 This parameter can be one of the following values:
      *         @arg @ref rtcALMBTIME_FORMAT_AM
      *         @arg @ref rtcALMBTIME_FORMAT_PM
      * @param  Hours Value between Min_Data=0x01 and Max_Data=0x12 or between Min_Data=0x00 and Max_Data=0x23
      * @param  Minutes Value between Min_Data=0x00 and Max_Data=0x59
      * @param  Seconds Value between Min_Data=0x00 and Max_Data=0x59
      * @retval None
      */
    inline void rtcALMBConfigTime(RTCAlarmBTimeFormat Format12_24, uint32_t Hours, uint32_t Minutes, uint32_t Seconds)
    {
      uint32_t temp;

      temp = Format12_24 | (((Hours & 0xF0U) << (RTC_ALRMBR_HT_Pos - 4U)) | ((Hours & 0x0FU) << RTC_ALRMBR_HU_Pos))    | \
            (((Minutes & 0xF0U) << (RTC_ALRMBR_MNT_Pos - 4U)) | ((Minutes & 0x0FU) << RTC_ALRMBR_MNU_Pos)) | \
            (((Seconds & 0xF0U) << (RTC_ALRMBR_ST_Pos - 4U)) | ((Seconds & 0x0FU) << RTC_ALRMBR_SU_Pos));

      MODIFY_REG(rtcx_->ALRMBR, RTC_ALRMBR_PM | RTC_ALRMBR_HT | RTC_ALRMBR_HU | RTC_ALRMBR_MNT | RTC_ALRMBR_MNU | RTC_ALRMBR_ST | RTC_ALRMBR_SU, temp);
    }

    /**
      * @brief  Get Alarm B Time (hour, minute and second) in BCD format
      * @note helper macros __rtcGET_HOUR, __rtcGET_MINUTE and __rtcGET_SECOND
      * are available to get independently each parameter.
      * @rmtoll RTC_ALRMBR       HT            rtcALMBGetTime
      *         RTC_ALRMBR       HU            rtcALMBGetTime
      *         RTC_ALRMBR       MNT           rtcALMBGetTime
      *         RTC_ALRMBR       MNU           rtcALMBGetTime
      *         RTC_ALRMBR       ST            rtcALMBGetTime
      *         RTC_ALRMBR       SU            rtcALMBGetTime
      * @param  RTCx RTC Instance
      * @retval Combination of hours, minutes and seconds.
      */
    inline uint32_t rtcALMBGetTime()
    {
      return (uint32_t)((rtcALMBGetHour() << RTC_OFFSET_HOUR) | (rtcALMBGetMinute() << RTC_OFFSET_MINUTE) | rtcALMBGetSecond());
    }

    /**
      * @brief  Set Alarm B Mask the most-significant bits starting at this bit
      * @note This register can be written only when ALRBE is reset in RTC_CR register,
      *       or in initialization mode.
      * @rmtoll RTC_ALRMBSSR     MASKSS        rtcALMBSetSubSecondMask
      * @param  RTCx RTC Instance
      * @param  Mask Value between Min_Data=0x00 and Max_Data=0xF
      * @retval None
      */
    inline void rtcALMBSetSubSecondMask(uint32_t Mask)
    {
      MODIFY_REG(rtcx_->ALRMBSSR, RTC_ALRMBSSR_MASKSS, Mask << RTC_ALRMBSSR_MASKSS_Pos);
    }

    /**
      * @brief  Get Alarm B Mask the most-significant bits starting at this bit
      * @rmtoll RTC_ALRMBSSR     MASKSS        rtcALMBGetSubSecondMask
      * @param  RTCx RTC Instance
      * @retval Value between Min_Data=0x00 and Max_Data=0xF
      */
    inline uint32_t rtcALMBGetSubSecondMask()
    {
      return (uint32_t)(READ_BIT(rtcx_->ALRMBSSR, RTC_ALRMBSSR_MASKSS)  >> RTC_ALRMBSSR_MASKSS_Pos);
    }

    /**
      * @brief  Set Alarm B Sub seconds value
      * @rmtoll RTC_ALRMBSSR     SS            rtcALMBSetSubSecond
      * @param  RTCx RTC Instance
      * @param  Subsecond Value between Min_Data=0x00 and Max_Data=0x7FFF
      * @retval None
      */
    inline void rtcALMBSetSubSecond(uint32_t Subsecond)
    {
      MODIFY_REG(rtcx_->ALRMBSSR, RTC_ALRMBSSR_SS, Subsecond);
    }

    /**
      * @brief  Get Alarm B Sub seconds value
      * @rmtoll RTC_ALRMBSSR     SS            rtcALMBGetSubSecond
      * @param  RTCx RTC Instance
      * @retval Value between Min_Data=0x00 and Max_Data=0x7FFF
      */
    inline uint32_t rtcALMBGetSubSecond()
    {
      return (uint32_t)(READ_BIT(rtcx_->ALRMBSSR, RTC_ALRMBSSR_SS));
    }

    /** @defgroup RTC_LL_EF_Timestamp Timestamp
      * @{
      */

    /**
      * @brief  Enable internal event timestamp
      * @note   Bit is write-protected. @ref rtcDisableWriteProtection function should be called before.
      * @rmtoll RTC_CR           ITSE          rtcTSEnableInternalEvent
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcTSEnableInternalEvent()
    {
      SET_BIT(rtcx_->CR, RTC_CR_ITSE);
    }

    /**
      * @brief  Disable internal event timestamp
      * @note   Bit is write-protected. @ref rtcDisableWriteProtection function should be called before.
      * @rmtoll RTC_CR           ITSE          rtcTSDisableInternalEvent
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcTSDisableInternalEvent()
    {
      CLEAR_BIT(rtcx_->CR, RTC_CR_ITSE);
    }

    /**
      * @brief  Enable Timestamp
      * @note   Bit is write-protected. @ref rtcDisableWriteProtection function should be called before.
      * @rmtoll RTC_CR           TSE           rtcTSEnable
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcTSEnable()
    {
      SET_BIT(rtcx_->CR, RTC_CR_TSE);
    }

    /**
      * @brief  Disable Timestamp
      * @note   Bit is write-protected. @ref rtcDisableWriteProtection function should be called before.
      * @rmtoll RTC_CR           TSE           rtcTSDisable
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcTSDisable()
    {
      CLEAR_BIT(rtcx_->CR, RTC_CR_TSE);
    }

    /**
      * @brief  Set Time-stamp event active edge
      * @note   Bit is write-protected. @ref rtcDisableWriteProtection function should be called before.
      * @note TSE must be reset when TSEDGE is changed to avoid unwanted TSF setting
      * @rmtoll RTC_CR           TSEDGE        rtcTSSetActiveEdge
      * @param  RTCx RTC Instance
      * @param  Edge This parameter can be one of the following values:
      *         @arg @ref rtcTIMESTAMP_EDGE_RISING
      *         @arg @ref rtcTIMESTAMP_EDGE_FALLING
      * @retval None
      */
    inline void rtcTSSetActiveEdge(RTCTimeStampEdge Edge)
    {
      MODIFY_REG(rtcx_->CR, RTC_CR_TSEDGE, Edge);
    }

    /**
      * @brief  Get Time-stamp event active edge
      * @note   Bit is write-protected. @ref rtcDisableWriteProtection function should be called before.
      * @rmtoll RTC_CR           TSEDGE        rtcTSGetActiveEdge
      * @param  RTCx RTC Instance
      * @retval Returned value can be one of the following values:
      *         @arg @ref rtcTIMESTAMP_EDGE_RISING
      *         @arg @ref rtcTIMESTAMP_EDGE_FALLING
      */
    inline RTCTimeStampEdge rtcTSGetActiveEdge()
    {
      return (RTCTimeStampEdge)(READ_BIT(rtcx_->CR, RTC_CR_TSEDGE));
    }

    /**
      * @brief  Get Timestamp AM/PM notation (AM or 24-hour format)
      * @rmtoll RTC_TSTR         PM            rtcTSGetTimeFormat
      * @param  RTCx RTC Instance
      * @retval Returned value can be one of the following values:
      *         @arg @ref rtcTSTIME_FORMAT_AM
      *         @arg @ref rtcTSTIME_FORMAT_PM
      */
    inline RTCTsTimeFormat rtcTSGetTimeFormat()
    {
      return (RTCTsTimeFormat)(READ_BIT(rtcx_->TSTR, RTC_TSTR_PM));
    }

    /**
      * @brief  Get Timestamp Hours in BCD format
      * @note helper macro __rtcCONVERT_BCD2BIN is available to convert Hours from BCD to Binary format
      * @rmtoll RTC_TSTR         HT            rtcTSGetHour
      *         RTC_TSTR         HU            rtcTSGetHour
      * @param  RTCx RTC Instance
      * @retval Value between Min_Data=0x01 and Max_Data=0x12 or between Min_Data=0x00 and Max_Data=0x23
      */
    inline uint32_t rtcTSGetHour()
    {
      return (uint32_t)(READ_BIT(rtcx_->TSTR, RTC_TSTR_HT | RTC_TSTR_HU) >> RTC_TSTR_HU_Pos);
    }

    /**
      * @brief  Get Timestamp Minutes in BCD format
      * @note helper macro __rtcCONVERT_BCD2BIN is available to convert Minutes from BCD to Binary format
      * @rmtoll RTC_TSTR         MNT           rtcTSGetMinute
      *         RTC_TSTR         MNU           rtcTSGetMinute
      * @param  RTCx RTC Instance
      * @retval Value between Min_Data=0x00 and Max_Data=0x59
      */
    inline uint32_t rtcTSGetMinute()
    {
      return (uint32_t)(READ_BIT(rtcx_->TSTR, RTC_TSTR_MNT | RTC_TSTR_MNU) >> RTC_TSTR_MNU_Pos);
    }

    /**
      * @brief  Get Timestamp Seconds in BCD format
      * @note helper macro __rtcCONVERT_BCD2BIN is available to convert Seconds from BCD to Binary format
      * @rmtoll RTC_TSTR         ST            rtcTSGetSecond
      *         RTC_TSTR         SU            rtcTSGetSecond
      * @param  RTCx RTC Instance
      * @retval Value between Min_Data=0x00 and Max_Data=0x59
      */
    inline uint32_t rtcTSGetSecond()
    {
      return (uint32_t)(READ_BIT(rtcx_->TSTR, RTC_TSTR_ST | RTC_TSTR_SU));
    }

    /**
      * @brief  Get Timestamp time (hour, minute and second) in BCD format
      * @note helper macros __rtcGET_HOUR, __rtcGET_MINUTE and __rtcGET_SECOND
      * are available to get independently each parameter.
      * @rmtoll RTC_TSTR         HT            rtcTSGetTime
      *         RTC_TSTR         HU            rtcTSGetTime
      *         RTC_TSTR         MNT           rtcTSGetTime
      *         RTC_TSTR         MNU           rtcTSGetTime
      *         RTC_TSTR         ST            rtcTSGetTime
      *         RTC_TSTR         SU            rtcTSGetTime
      * @param  RTCx RTC Instance
      * @retval Combination of hours, minutes and seconds.
      */
    inline uint32_t rtcTSGetTime()
    {
      return (uint32_t)(READ_BIT(rtcx_->TSTR,
                                RTC_TSTR_HT | RTC_TSTR_HU | RTC_TSTR_MNT | RTC_TSTR_MNU | RTC_TSTR_ST | RTC_TSTR_SU));
    }

    /**
      * @brief  Get Timestamp Week day
      * @rmtoll RTC_TSDR         WDU           rtcTSGetWeekDay
      * @param  RTCx RTC Instance
      * @retval Returned value can be one of the following values:
      *         @arg @ref rtcWEEKDAY_MONDAY
      *         @arg @ref rtcWEEKDAY_TUESDAY
      *         @arg @ref rtcWEEKDAY_WEDNESDAY
      *         @arg @ref rtcWEEKDAY_THURSDAY
      *         @arg @ref rtcWEEKDAY_FRIDAY
      *         @arg @ref rtcWEEKDAY_SATURDAY
      *         @arg @ref rtcWEEKDAY_SUNDAY
      */
    inline RTCWeekDay rtcTSGetWeekDay()
    {
      return (RTCWeekDay)(READ_BIT(rtcx_->TSDR, RTC_TSDR_WDU) >> RTC_TSDR_WDU_Pos);
    }

    /**
      * @brief  Get Timestamp Month in BCD format
      * @note helper macro __rtcCONVERT_BCD2BIN is available to convert Month from BCD to Binary format
      * @rmtoll RTC_TSDR         MT            rtcTSGetMonth
      *         RTC_TSDR         MU            rtcTSGetMonth
      * @param  RTCx RTC Instance
      * @retval Returned value can be one of the following values:
      *         @arg @ref rtcMONTH_JANUARY
      *         @arg @ref rtcMONTH_FEBRUARY
      *         @arg @ref rtcMONTH_MARCH
      *         @arg @ref rtcMONTH_APRIL
      *         @arg @ref rtcMONTH_MAY
      *         @arg @ref rtcMONTH_JUNE
      *         @arg @ref rtcMONTH_JULY
      *         @arg @ref rtcMONTH_AUGUST
      *         @arg @ref rtcMONTH_SEPTEMBER
      *         @arg @ref rtcMONTH_OCTOBER
      *         @arg @ref rtcMONTH_NOVEMBER
      *         @arg @ref rtcMONTH_DECEMBER
      */
    inline RTCMonth rtcTSGetMonth()
    {
      return (RTCMonth)(READ_BIT(rtcx_->TSDR, RTC_TSDR_MT | RTC_TSDR_MU) >> RTC_TSDR_MU_Pos);
    }

    /**
      * @brief  Get Timestamp Day in BCD format
      * @note helper macro __rtcCONVERT_BCD2BIN is available to convert Day from BCD to Binary format
      * @rmtoll RTC_TSDR         DT            rtcTSGetDay
      *         RTC_TSDR         DU            rtcTSGetDay
      * @param  RTCx RTC Instance
      * @retval Value between Min_Data=0x01 and Max_Data=0x31
      */
    inline uint32_t rtcTSGetDay()
    {
      return (uint32_t)(READ_BIT(rtcx_->TSDR, RTC_TSDR_DT | RTC_TSDR_DU));
    }

    /**
      * @brief  Get Timestamp date (WeekDay, Day and Month) in BCD format
      * @note helper macros __rtcGET_WEEKDAY, __rtcGET_MONTH,
      * and __rtcGET_DAY are available to get independently each parameter.
      * @rmtoll RTC_TSDR         WDU           rtcTSGetDate
      *         RTC_TSDR         MT            rtcTSGetDate
      *         RTC_TSDR         MU            rtcTSGetDate
      *         RTC_TSDR         DT            rtcTSGetDate
      *         RTC_TSDR         DU            rtcTSGetDate
      * @param  RTCx RTC Instance
      * @retval Combination of Weekday, Day and Month
      */
    inline uint32_t rtcTSGetDate()
    {
      return (uint32_t)(READ_BIT(rtcx_->TSDR, RTC_TSDR_WDU | RTC_TSDR_MT | RTC_TSDR_MU | RTC_TSDR_DT | RTC_TSDR_DU));
    }

    /**
      * @brief  Get time-stamp sub second value
      * @rmtoll RTC_TSSSR         SS            rtcTSGetSubSecond
      * @param  RTCx RTC Instance
      * @retval Value between Min_Data=0x00 and Max_Data=0xFFFF
      */
    inline uint32_t rtcTSGetSubSecond()
    {
      return (uint32_t)(READ_BIT(rtcx_->TSSSR, RTC_TSSSR_SS));
    }

    /**
      * @}
      */

    /** @defgroup RTC_LL_EF_Tamper_Timestamp Time-stamp on Tamper
      * @{
      */

    #if defined(RTC_TAMPCR_TAMPTS)
    /**
      * @brief  Activate timestamp on tamper detection event
      * @rmtoll RTC_CR       TAMPTS        rtcTSEnableOnTamper
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcTSEnableOnTamper()
    {
      SET_BIT(rtcx_->TAMPCR, RTC_TAMPCR_TAMPTS);
    }

    /**
      * @brief  Disable timestamp on tamper detection event
      * @rmtoll RTC_CR       TAMPTS        rtcTSDisableOnTamper
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcTSDisableOnTamper()
    {
      CLEAR_BIT(rtcx_->TAMPCR, RTC_TAMPCR_TAMPTS);
    }
    #endif /* RTC_TAMPCR_TAMPTS */

    #if defined(RTC_CR_TAMPTS)
    /**
      * @brief  Activate timestamp on tamper detection event
      * @rmtoll RTC_CR       TAMPTS        rtcTSEnableOnTamper
      * @param  RTCx RTC Instance
      * @retval None
      */

    inline void rtcTSEnableOnTamper()
    {
      SET_BIT(rtcx_->CR, RTC_CR_TAMPTS);
    }

    /**
      * @brief  Disable timestamp on tamper detection event
      * @rmtoll RTC_CR       TAMPTS        rtcTSDisableOnTamper
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcTSDisableOnTamper()
    {
      CLEAR_BIT(rtcx_->CR, RTC_CR_TAMPTS);
    }
    #endif /* RTC_CR_TAMPTS */

    /**
      * @}
      */

    /** @defgroup RTC_LL_EF_Tamper Tamper
      * @{
      */

    #if defined(RTC_TAMPCR_TAMP1E)
    /**
      * @brief  Enable RTC_TAMPx input detection
      * @rmtoll TAMPCR       TAMP1E        rtcTAMPEREnable
      *         TAMPCR       TAMP2E        rtcTAMPEREnable
      *         TAMPCR       TAMP3E        rtcTAMPEREnable
      * @param  RTCx RTC Instance
      * @param  Tamper This parameter can be a combination of the following values:
      *         @arg @ref rtcTAMPER1
      *         @arg @ref rtcTAMPER2
      *         @arg @ref rtcTAMPER3
      *
      * @retval None
      */
    inline void rtcTAMPEREnable(RTCTamperInput Tamper)
    {
      SET_BIT(rtcx_->TAMPCR, Tamper);
    }

    /**
      * @brief  Clear RTC_TAMPx input detection
      * @rmtoll TAMPCR       TAMP1E        rtcTAMPERDisable
      *         TAMPCR       TAMP2E        rtcTAMPERDisable
      *         TAMPCR       TAMP3E        rtcTAMPERDisable
      * @param  RTCx RTC Instance
      * @param  Tamper This parameter can be a combination of the following values:
      *         @arg @ref rtcTAMPER1
      *         @arg @ref rtcTAMPER2
      *         @arg @ref rtcTAMPER3
      *
      * @retval None
      */
    inline void rtcTAMPERDisable(RTCTamperInput Tamper)
    {
      CLEAR_BIT(rtcx_->TAMPCR, Tamper);
    }

    /**
      * @brief  Enable Tamper mask flag
      * @note Associated Tamper IT must not enabled when tamper mask is set.
      * @rmtoll TAMPCR       TAMP1MF       rtcTAMPEREnableMask
      *         TAMPCR       TAMP2MF       rtcTAMPEREnableMask
      *         TAMPCR       TAMP3MF       rtcTAMPEREnableMask
      * @param  RTCx RTC Instance
      * @param  Mask This parameter can be a combination of the following values:
      *         @arg @ref rtcTAMPERMASK_TAMPER1
      *         @arg @ref rtcTAMPERMASK_TAMPER2
      *         @arg @ref rtcTAMPERMASK_TAMPER3
      *
      * @retval None
      */
    inline void rtcTAMPEREnableMask(RTCTamperMask Mask)
    {
      SET_BIT(rtcx_->TAMPCR, Mask);
    }

    /**
      * @brief  Disable Tamper mask flag
      * @rmtoll TAMPCR       TAMP1MF       rtcTAMPERDisableMask
      *         TAMPCR       TAMP2MF       rtcTAMPERDisableMask
      *         TAMPCR       TAMP3MF       rtcTAMPERDisableMask
      * @param  RTCx RTC Instance
      * @param  Mask This parameter can be a combination of the following values:
      *         @arg @ref rtcTAMPERMASK_TAMPER1
      *         @arg @ref rtcTAMPERMASK_TAMPER2
      *         @arg @ref rtcTAMPERMASK_TAMPER3
      *
      * @retval None
      */
    inline void rtcTAMPERDisableMask(RTCTamperMask Mask)
    {
      CLEAR_BIT(rtcx_->TAMPCR, Mask);
    }

    /**
      * @brief  Enable backup register erase after Tamper event detection
      * @rmtoll TAMPCR       TAMP1NOERASE  rtcTAMPEREnableEraseBKP
      *         TAMPCR       TAMP2NOERASE  rtcTAMPEREnableEraseBKP
      *         TAMPCR       TAMP3NOERASE  rtcTAMPEREnableEraseBKP
      * @param  RTCx RTC Instance
      * @param  Tamper This parameter can be a combination of the following values:
      *         @arg @ref rtcTAMPERNOERASE_TAMPER1
      *         @arg @ref rtcTAMPERNOERASE_TAMPER2
      *         @arg @ref rtcTAMPERNOERASE_TAMPER3
      *
      * @retval None
      */
    inline void rtcTAMPEREnableEraseBKP(RTCTamperNoErase Tamper)
    {
      CLEAR_BIT(rtcx_->TAMPCR, Tamper);
    }

    /**
      * @brief  Disable backup register erase after Tamper event detection
      * @rmtoll TAMPCR       TAMP1NOERASE  rtcTAMPERDisableEraseBKP
      *         TAMPCR       TAMP2NOERASE  rtcTAMPERDisableEraseBKP
      *         TAMPCR       TAMP3NOERASE  rtcTAMPERDisableEraseBKP
      * @param  RTCx RTC Instance
      * @param  Tamper This parameter can be a combination of the following values:
      *         @arg @ref rtcTAMPERNOERASE_TAMPER1
      *         @arg @ref rtcTAMPERNOERASE_TAMPER2
      *         @arg @ref rtcTAMPERNOERASE_TAMPER3
      *
      * @retval None
      */
    inline void rtcTAMPERDisableEraseBKP(RTCTamperNoErase Tamper)
    {
      SET_BIT(rtcx_->TAMPCR, Tamper);
    }
    #endif /* RTC_TAMPCR_TAMP1E */

    #if defined(RTC_TAMPCR_TAMPPUDIS)
    /**
      * @brief  Disable RTC_TAMPx pull-up disable (Disable precharge of RTC_TAMPx pins)
      * @rmtoll TAMPCR       TAMPPUDIS     rtcTAMPERDisablePullUp
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcTAMPERDisablePullUp()
    {
      SET_BIT(rtcx_->TAMPCR, RTC_TAMPCR_TAMPPUDIS);
    }

    /**
      * @brief  Enable RTC_TAMPx pull-up disable ( Precharge RTC_TAMPx pins before sampling)
      * @rmtoll TAMPCR       TAMPPUDIS     rtcTAMPEREnablePullUp
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcTAMPEREnablePullUp()
    {
      CLEAR_BIT(rtcx_->TAMPCR, RTC_TAMPCR_TAMPPUDIS);
    }
    #endif /* RTC_TAMPCR_TAMPPUDIS */

    #if defined(RTC_TAMPCR_TAMPPRCH)
    /**
      * @brief  Set RTC_TAMPx precharge duration
      * @rmtoll TAMPCR       TAMPPRCH      rtcTAMPERSetPrecharge
      * @param  RTCx RTC Instance
      * @param  Duration This parameter can be one of the following values:
      *         @arg @ref rtcTAMPERDURATION_1RTCCLK
      *         @arg @ref rtcTAMPERDURATION_2RTCCLK
      *         @arg @ref rtcTAMPERDURATION_4RTCCLK
      *         @arg @ref rtcTAMPERDURATION_8RTCCLK
      * @retval None
      */
    inline void rtcTAMPERSetPrecharge(RTCTamperDuration Duration)
    {
      MODIFY_REG(rtcx_->TAMPCR, RTC_TAMPCR_TAMPPRCH, Duration);
    }

    /**
      * @brief  Get RTC_TAMPx precharge duration
      * @rmtoll TAMPCR       TAMPPRCH      rtcTAMPERGetPrecharge
      * @param  RTCx RTC Instance
      * @retval Returned value can be one of the following values:
      *         @arg @ref rtcTAMPERDURATION_1RTCCLK
      *         @arg @ref rtcTAMPERDURATION_2RTCCLK
      *         @arg @ref rtcTAMPERDURATION_4RTCCLK
      *         @arg @ref rtcTAMPERDURATION_8RTCCLK
      */
    inline RTCTamperDuration rtcTAMPERGetPrecharge()
    {
      return (RTCTamperDuration)(READ_BIT(rtcx_->TAMPCR, RTC_TAMPCR_TAMPPRCH));
    }
    #endif /* RTC_TAMPCR_TAMPPRCH */

    #if defined(RTC_TAMPCR_TAMPFLT)
    /**
      * @brief  Set RTC_TAMPx filter count
      * @rmtoll TAMPCR       TAMPFLT       rtcTAMPERSetFilterCount
      * @param  RTCx RTC Instance
      * @param  FilterCount This parameter can be one of the following values:
      *         @arg @ref rtcTAMPERFILTER_DISABLE
      *         @arg @ref rtcTAMPERFILTER_2SAMPLE
      *         @arg @ref rtcTAMPERFILTER_4SAMPLE
      *         @arg @ref rtcTAMPERFILTER_8SAMPLE
      * @retval None
      */
    inline void rtcTAMPERSetFilterCount(RTCTamperFilter FilterCount)
    {
      MODIFY_REG(rtcx_->TAMPCR, RTC_TAMPCR_TAMPFLT, FilterCount);
    }

    /**
      * @brief  Get RTC_TAMPx filter count
      * @rmtoll TAMPCR       TAMPFLT       rtcTAMPERGetFilterCount
      * @param  RTCx RTC Instance
      * @retval Returned value can be one of the following values:
      *         @arg @ref rtcTAMPERFILTER_DISABLE
      *         @arg @ref rtcTAMPERFILTER_2SAMPLE
      *         @arg @ref rtcTAMPERFILTER_4SAMPLE
      *         @arg @ref rtcTAMPERFILTER_8SAMPLE
      */
    inline RTCTamperFilter rtcTAMPERGetFilterCount()
    {
      return (RTCTamperFilter)(READ_BIT(rtcx_->TAMPCR, RTC_TAMPCR_TAMPFLT));
    }
    #endif /* RTC_TAMPCR_TAMPFLT */

    #if defined(RTC_TAMPCR_TAMPFREQ)
    /**
      * @brief  Set Tamper sampling frequency
      * @rmtoll TAMPCR       TAMPFREQ      rtcTAMPERSetSamplingFreq
      * @param  RTCx RTC Instance
      * @param  SamplingFreq This parameter can be one of the following values:
      *         @arg @ref rtcTAMPERSAMPLFREQDIV_32768
      *         @arg @ref rtcTAMPERSAMPLFREQDIV_16384
      *         @arg @ref rtcTAMPERSAMPLFREQDIV_8192
      *         @arg @ref rtcTAMPERSAMPLFREQDIV_4096
      *         @arg @ref rtcTAMPERSAMPLFREQDIV_2048
      *         @arg @ref rtcTAMPERSAMPLFREQDIV_1024
      *         @arg @ref rtcTAMPERSAMPLFREQDIV_512
      *         @arg @ref rtcTAMPERSAMPLFREQDIV_256
      * @retval None
      */
    inline void rtcTAMPERSetSamplingFreq(RTCTamperSamplingFreqDiv SamplingFreq)
    {
      MODIFY_REG(rtcx_->TAMPCR, RTC_TAMPCR_TAMPFREQ, SamplingFreq);
    }

    /**
      * @brief  Get Tamper sampling frequency
      * @rmtoll TAMPCR       TAMPFREQ      rtcTAMPERGetSamplingFreq
      * @param  RTCx RTC Instance
      * @retval Returned value can be one of the following values:
      *         @arg @ref rtcTAMPERSAMPLFREQDIV_32768
      *         @arg @ref rtcTAMPERSAMPLFREQDIV_16384
      *         @arg @ref rtcTAMPERSAMPLFREQDIV_8192
      *         @arg @ref rtcTAMPERSAMPLFREQDIV_4096
      *         @arg @ref rtcTAMPERSAMPLFREQDIV_2048
      *         @arg @ref rtcTAMPERSAMPLFREQDIV_1024
      *         @arg @ref rtcTAMPERSAMPLFREQDIV_512
      *         @arg @ref rtcTAMPERSAMPLFREQDIV_256
      */
    inline RTCTamperSamplingFreqDiv rtcTAMPERGetSamplingFreq()
    {
      return (RTCTamperSamplingFreqDiv)(READ_BIT(rtcx_->TAMPCR, RTC_TAMPCR_TAMPFREQ));
    }
    #endif /* RTC_TAMPCR_TAMPFREQ */

    #if defined(RTC_TAMPCR_TAMP1E)
    /**
      * @brief  Enable Active level for Tamper input
      * @rmtoll TAMPCR       TAMP1TRG      rtcTAMPEREnableActiveLevel
      *         TAMPCR       TAMP2TRG      rtcTAMPEREnableActiveLevel
      *         TAMPCR       TAMP3TRG      rtcTAMPEREnableActiveLevel
      * @param  RTCx RTC Instance
      * @param  Tamper This parameter can be a combination of the following values:
      *         @arg @ref rtcTAMPERACTIVELEVEL_TAMP1
      *         @arg @ref rtcTAMPERACTIVELEVEL_TAMP2
      *         @arg @ref rtcTAMPERACTIVELEVEL_TAMP3
      *
      * @retval None
      */
    inline void rtcTAMPEREnableActiveLevel(RTCTamperActiveLevel Tamper)
    {
      SET_BIT(rtcx_->TAMPCR, Tamper);
    }

    /**
      * @brief  Disable Active level for Tamper input
      * @rmtoll TAMPCR       TAMP1TRG      rtcTAMPERDisableActiveLevel
      *         TAMPCR       TAMP2TRG      rtcTAMPERDisableActiveLevel
      *         TAMPCR       TAMP3TRG      rtcTAMPERDisableActiveLevel
      * @param  RTCx RTC Instance
      * @param  Tamper This parameter can be a combination of the following values:
      *         @arg @ref rtcTAMPERACTIVELEVEL_TAMP1
      *         @arg @ref rtcTAMPERACTIVELEVEL_TAMP2
      *         @arg @ref rtcTAMPERACTIVELEVEL_TAMP3
      *
      * @retval None
      */
    inline void rtcTAMPERDisableActiveLevel(RTCTamperActiveLevel Tamper)
    {
      CLEAR_BIT(rtcx_->TAMPCR, Tamper);
    }
    #endif /* RTC_TAMPCR_TAMP1E */

    #if defined(TAMP_CR1_TAMP1E)
    /**
      * @brief  Enable TAMPx input detection
      * @rmtoll TAMP_CR1       TAMP1E        rtcTAMPEREnable
      *         TAMP_CR1       TAMP2E        rtcTAMPEREnable
      *         TAMP_CR1       TAMP3E        rtcTAMPEREnable
      * @param  TAMPx TAMP Instance
      * @param  Tamper This parameter can be a combination of the following values:
      *         @arg @ref rtcTAMPER1
      *         @arg @ref rtcTAMPER2
      *         @arg @ref rtcTAMPER3
      *
      * @retval None
      */
    inline void rtcTAMPEREnable(RTCTamperInput Tamper)
    {
      SET_BIT(tampx_->CR1, Tamper);
    }

    /**
      * @brief  Clear TAMPx input detection
      * @rmtoll TAMP_CR1       TAMP1E        rtcTAMPERDisable
      *         TAMP_CR1       TAMP2E        rtcTAMPERDisable
      *         TAMP_CR1       TAMP3E        rtcTAMPERDisable
      * @param  TAMPx TAMP Instance
      * @param  Tamper This parameter can be a combination of the following values:
      *         @arg @ref rtcTAMPER1
      *         @arg @ref rtcTAMPER2
      *         @arg @ref rtcTAMPER3
      *
      * @retval None
      */
    inline void rtcTAMPERDisable(RTCTamperInput Tamper)
    {
      CLEAR_BIT(tampx_->CR1, Tamper);
    }
    #endif /* TAMP_CR1_TAMP1E */

    #if defined(TAMP_CR2_TAMP1MSK)
    /**
      * @brief  Enable Tamper mask flag
      * @note Associated Tamper IT must not enabled when tamper mask is set.
      * @rmtoll TAMP_CR2       TAMP1MF       rtcTAMPEREnableMask
      *         TAMP_CR2       TAMP2MF       rtcTAMPEREnableMask
      *         TAMP_CR2       TAMP3MF       rtcTAMPEREnableMask
      * @param  TAMPx TAMP Instance
      * @param  Mask This parameter can be a combination of the following values:
      *         @arg @ref rtcTAMPERMASK_TAMPER1
      *         @arg @ref rtcTAMPERMASK_TAMPER2
      *         @arg @ref rtcTAMPERMASK_TAMPER3
      *
      * @retval None
      */
    inline void rtcTAMPEREnableMask(RTCTamperMask Mask)
    {
      SET_BIT(tampx_->CR2, Mask);
    }

    /**
      * @brief  Disable Tamper mask flag
      * @rmtoll TAMP_CR2       TAMP1MF       rtcTAMPERDisableMask
      *         TAMP_CR2       TAMP2MF       rtcTAMPERDisableMask
      *         TAMP_CR2       TAMP3MF       rtcTAMPERDisableMask
      * @param  TAMPx TAMP Instance
      * @param  Mask This parameter can be a combination of the following values:
      *         @arg @ref rtcTAMPERMASK_TAMPER1
      *         @arg @ref rtcTAMPERMASK_TAMPER2
      *         @arg @ref rtcTAMPERMASK_TAMPER3
      *
      * @retval None
      */
    inline void rtcTAMPERDisableMask(RTCTamperMask Mask)
    {
      CLEAR_BIT(tampx_->CR2, Mask);
    }

    /**
      * @brief  Enable backup register erase after Tamper event detection
      * @rmtoll TAMP_CR2       TAMP1NOERASE  rtcTAMPEREnableEraseBKP
      *         TAMP_CR2       TAMP2NOERASE  rtcTAMPEREnableEraseBKP
      *         TAMP_CR2       TAMP3NOERASE  rtcTAMPEREnableEraseBKP
      * @param  TAMPx TAMP Instance
      * @param  Tamper This parameter can be a combination of the following values:
      *         @arg @ref rtcTAMPERNOERASE_TAMPER1
      *         @arg @ref rtcTAMPERNOERASE_TAMPER2
      *         @arg @ref rtcTAMPERNOERASE_TAMPER3
      *
      * @retval None
      */
    inline void rtcTAMPEREnableEraseBKP(RTCTamperNoErase Tamper)
    {
      CLEAR_BIT(tampx_->CR2, Tamper);
    }

    /**
      * @brief  Disable backup register erase after Tamper event detection
      * @rmtoll TAMP_CR2       TAMP1NOERASE  rtcTAMPERDisableEraseBKP
      *         TAMP_CR2       TAMP2NOERASE  rtcTAMPERDisableEraseBKP
      *         TAMP_CR2       TAMP3NOERASE  rtcTAMPERDisableEraseBKP
      * @param  TAMPx TAMP Instance
      * @param  Tamper This parameter can be a combination of the following values:
      *         @arg @ref rtcTAMPERNOERASE_TAMPER1
      *         @arg @ref rtcTAMPERNOERASE_TAMPER2
      *         @arg @ref rtcTAMPERNOERASE_TAMPER3
      *
      * @retval None
      */
    inline void rtcTAMPERDisableEraseBKP(RTCTamperNoErase Tamper)
    {
      SET_BIT(tampx_->CR2, Tamper);
    }

    /**
      * @brief  Enable Active level for Tamper input
      * @rmtoll TAMP_CR2       TAMP1TRG      rtcTAMPEREnableActiveLevel
      *         TAMP_CR2       TAMP2TRG      rtcTAMPEREnableActiveLevel
      *         TAMP_CR2       TAMP3TRG      rtcTAMPEREnableActiveLevel
      * @param  TAMPx TAMP Instance
      * @param  Tamper This parameter can be a combination of the following values:
      *         @arg @ref rtcTAMPERACTIVELEVEL_TAMP1
      *         @arg @ref rtcTAMPERACTIVELEVEL_TAMP2
      *         @arg @ref rtcTAMPERACTIVELEVEL_TAMP3
      *
      * @retval None
      */
    inline void rtcTAMPEREnableActiveLevel(RTCTamperActiveLevel Tamper)
    {
      SET_BIT(tampx_->CR2, Tamper);
    }

    /**
      * @brief  Disable Active level for Tamper input
      * @rmtoll TAMP_CR2       TAMP1TRG      rtcTAMPERDisableActiveLevel
      *         TAMP_CR2       TAMP2TRG      rtcTAMPERDisableActiveLevel
      *         TAMP_CR2       TAMP3TRG      rtcTAMPERDisableActiveLevel
      * @param  TAMPx TAMP Instance
      * @param  Tamper This parameter can be a combination of the following values:
      *         @arg @ref rtcTAMPERACTIVELEVEL_TAMP1
      *         @arg @ref rtcTAMPERACTIVELEVEL_TAMP2
      *         @arg @ref rtcTAMPERACTIVELEVEL_TAMP3
      *
      * @retval None
      */
    inline void rtcTAMPERDisableActiveLevel(RTCTamperActiveLevel Tamper)
    {
      CLEAR_BIT(tampx_->CR2, Tamper);
    }
    #endif /* TAMP_CR2_TAMP1MSK */

    #if defined(TAMP_FLTCR_TAMPPUDIS)
    /**
      * @brief  Disable RTC_TAMPx pull-up disable (Disable precharge of RTC_TAMPx pins)
      * @rmtoll TAMP_FLTCR       TAMPPUDIS     rtcTAMPERDisablePullUp
      * @param  TAMPx TAMP Instance
      * @retval None
      */
    inline void rtcTAMPERDisablePullUp()
    {
      SET_BIT(tampx_->FLTCR, TAMP_FLTCR_TAMPPUDIS);
    }

    /**
      * @brief  Enable RTC_TAMPx pull-up disable (Precharge RTC_TAMPx pins before sampling)
      * @rmtoll TAMP_FLTCR       TAMPPUDIS     rtcTAMPEREnablePullUp
      * @param  TAMPx TAMP Instance
      * @retval None
      */
    inline void rtcTAMPEREnablePullUp()
    {
      CLEAR_BIT(tampx_->FLTCR, TAMP_FLTCR_TAMPPUDIS);
    }

    /**
      * @brief  Set RTC_TAMPx precharge duration
      * @rmtoll TAMP_FLTCR       TAMPPRCH      rtcTAMPERSetPrecharge
      * @param  TAMPx TAMP Instance
      * @param  Duration This parameter can be one of the following values:
      *         @arg @ref rtcTAMPERDURATION_1RTCCLK
      *         @arg @ref rtcTAMPERDURATION_2RTCCLK
      *         @arg @ref rtcTAMPERDURATION_4RTCCLK
      *         @arg @ref rtcTAMPERDURATION_8RTCCLK
      * @retval None
      */
    inline void rtcTAMPERSetPrecharge(RTCTamperDuration Duration)
    {
      MODIFY_REG(tampx_->FLTCR, TAMP_FLTCR_TAMPPRCH, Duration);
    }

    /**
      * @brief  Get RTC_TAMPx precharge duration
      * @rmtoll TAMP_FLTCR       TAMPPRCH      rtcTAMPERGetPrecharge
      * @param  TAMPx TAMP Instance
      * @retval Returned value can be one of the following values:
      *         @arg @ref rtcTAMPERDURATION_1RTCCLK
      *         @arg @ref rtcTAMPERDURATION_2RTCCLK
      *         @arg @ref rtcTAMPERDURATION_4RTCCLK
      *         @arg @ref rtcTAMPERDURATION_8RTCCLK
      */
    inline RTCTamperDuration rtcTAMPERGetPrecharge()
    {
      return (RTCTamperDuration)(READ_BIT(tampx_->FLTCR, TAMP_FLTCR_TAMPPRCH));
    }

    /**
      * @brief  Set RTC_TAMPx filter count
      * @rmtoll TAMP_FLTCR       TAMPFLT       rtcTAMPERSetFilterCount
      * @param  TAMPx TAMP Instance
      * @param  FilterCount This parameter can be one of the following values:
      *         @arg @ref rtcTAMPERFILTER_DISABLE
      *         @arg @ref rtcTAMPERFILTER_2SAMPLE
      *         @arg @ref rtcTAMPERFILTER_4SAMPLE
      *         @arg @ref rtcTAMPERFILTER_8SAMPLE
      * @retval None
      */
    inline void rtcTAMPERSetFilterCount(RTCTamperFilter FilterCount)
    {
      MODIFY_REG(tampx_->FLTCR, TAMP_FLTCR_TAMPFLT, FilterCount);
    }

    /**
      * @brief  Get RTC_TAMPx filter count
      * @rmtoll TAMP_FLTCR       TAMPFLT       rtcTAMPERGetFilterCount
      * @param  TAMPx TAMP Instance
      * @retval Returned value can be one of the following values:
      *         @arg @ref rtcTAMPERFILTER_DISABLE
      *         @arg @ref rtcTAMPERFILTER_2SAMPLE
      *         @arg @ref rtcTAMPERFILTER_4SAMPLE
      *         @arg @ref rtcTAMPERFILTER_8SAMPLE
      */
    inline RTCTamperFilter rtcTAMPERGetFilterCount()
    {
      return (RTCTamperFilter)(READ_BIT(tampx_->FLTCR, TAMP_FLTCR_TAMPFLT));
    }

    /**
      * @brief  Set Tamper sampling frequency
      * @rmtoll TAMP_FLTCR       TAMPFREQ      rtcTAMPERSetSamplingFreq
      * @param  TAMPx TAMP Instance
      * @param  SamplingFreq This parameter can be one of the following values:
      *         @arg @ref rtcTAMPERSAMPLFREQDIV_32768
      *         @arg @ref rtcTAMPERSAMPLFREQDIV_16384
      *         @arg @ref rtcTAMPERSAMPLFREQDIV_8192
      *         @arg @ref rtcTAMPERSAMPLFREQDIV_4096
      *         @arg @ref rtcTAMPERSAMPLFREQDIV_2048
      *         @arg @ref rtcTAMPERSAMPLFREQDIV_1024
      *         @arg @ref rtcTAMPERSAMPLFREQDIV_512
      *         @arg @ref rtcTAMPERSAMPLFREQDIV_256
      * @retval None
      */
    inline void rtcTAMPERSetSamplingFreq(RTCTamperSamplingFreqDiv)
    {
      MODIFY_REG(tampx_->FLTCR, TAMP_FLTCR_TAMPFREQ, SamplingFreq);
    }

    /**
      * @brief  Get Tamper sampling frequency
      * @rmtoll TAMP_FLTCR       TAMPFREQ      rtcTAMPERGetSamplingFreq
      * @param  TAMPx TAMP Instance
      * @retval Returned value can be one of the following values:
      *         @arg @ref rtcTAMPERSAMPLFREQDIV_32768
      *         @arg @ref rtcTAMPERSAMPLFREQDIV_16384
      *         @arg @ref rtcTAMPERSAMPLFREQDIV_8192
      *         @arg @ref rtcTAMPERSAMPLFREQDIV_4096
      *         @arg @ref rtcTAMPERSAMPLFREQDIV_2048
      *         @arg @ref rtcTAMPERSAMPLFREQDIV_1024
      *         @arg @ref rtcTAMPERSAMPLFREQDIV_512
      *         @arg @ref rtcTAMPERSAMPLFREQDIV_256
      */
    inline RTCTamperSamplingFreqDiv rtcTAMPERGetSamplingFreq()
    {
      return (RTCTamperSamplingFreqDiv)(READ_BIT(tampx_->FLTCR, TAMP_FLTCR_TAMPFREQ));
    }
    #endif /* TAMP_FLTCR_TAMPPUDIS */
    /** @defgroup RTC_LL_EF_Wakeup Wakeup
      * @{
      */

    /**
      * @brief  Enable Wakeup timer
      * @note   Bit is write-protected. @ref rtcDisableWriteProtection function should be called before.
      * @rmtoll RTC_CR           WUTE          rtcWAKEUPEnable
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcWAKEUPEnable()
    {
      SET_BIT(rtcx_->CR, RTC_CR_WUTE);
    }

    /**
      * @brief  Disable Wakeup timer
      * @note   Bit is write-protected. @ref rtcDisableWriteProtection function should be called before.
      * @rmtoll RTC_CR           WUTE          rtcWAKEUPDisable
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcWAKEUPDisable()
    {
      CLEAR_BIT(rtcx_->CR, RTC_CR_WUTE);
    }

    /**
      * @brief  Check if Wakeup timer is enabled or not
      * @rmtoll RTC_CR           WUTE          rtcWAKEUPIsEnabled
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcWAKEUPIsEnabled()
    {
      return ((READ_BIT(rtcx_->CR, RTC_CR_WUTE) == (RTC_CR_WUTE)) ? true : false);
    }

    /**
      * @brief  Select Wakeup clock
      * @note   Bit is write-protected. @ref rtcDisableWriteProtection function should be called before.
      * @note Bit can be written only when RTC_CR WUTE bit = 0 and RTC_ISR WUTWF bit = 1
      * @rmtoll RTC_CR           WUCKSEL       rtcWAKEUPSetClock
      * @param  RTCx RTC Instance
      * @param  WakeupClock This parameter can be one of the following values:
      *         @arg @ref rtcWAKEUPCLOCK_DIV_16
      *         @arg @ref rtcWAKEUPCLOCK_DIV_8
      *         @arg @ref rtcWAKEUPCLOCK_DIV_4
      *         @arg @ref rtcWAKEUPCLOCK_DIV_2
      *         @arg @ref rtcWAKEUPCLOCK_CKSPRE
      *         @arg @ref rtcWAKEUPCLOCK_CKSPRE_WUT
      * @retval None
      */
    inline void rtcWAKEUPSetClock(RTCWakeupClockDiv WakeupClock)
    {
      MODIFY_REG(rtcx_->CR, RTC_CR_WUCKSEL, WakeupClock);
    }

    /**
      * @brief  Get Wakeup clock
      * @rmtoll RTC_CR           WUCKSEL       rtcWAKEUPGetClock
      * @param  RTCx RTC Instance
      * @retval Returned value can be one of the following values:
      *         @arg @ref rtcWAKEUPCLOCK_DIV_16
      *         @arg @ref rtcWAKEUPCLOCK_DIV_8
      *         @arg @ref rtcWAKEUPCLOCK_DIV_4
      *         @arg @ref rtcWAKEUPCLOCK_DIV_2
      *         @arg @ref rtcWAKEUPCLOCK_CKSPRE
      *         @arg @ref rtcWAKEUPCLOCK_CKSPRE_WUT
      */
    inline RTCWakeupClockDiv rtcWAKEUPGetClock()
    {
      return (RTCWakeupClockDiv)(READ_BIT(rtcx_->CR, RTC_CR_WUCKSEL));
    }

    /**
      * @brief  Set Wakeup auto-reload value
      * @note Bit can be written only when WUTWF is set to 1 in RTC_ISR
      * @rmtoll RTC_WUTR         WUT           rtcWAKEUPSetAutoReload
      * @param  RTCx RTC Instance
      * @param  Value Value between Min_Data=0x00 and Max_Data=0xFFFF
      * @retval None
      */
    inline void rtcWAKEUPSetAutoReload(uint32_t Value)
    {
      MODIFY_REG(rtcx_->WUTR, RTC_WUTR_WUT, Value);
    }

    /**
      * @brief  Get Wakeup auto-reload value
      * @rmtoll RTC_WUTR         WUT           rtcWAKEUPGetAutoReload
      * @param  RTCx RTC Instance
      * @retval Value between Min_Data=0x00 and Max_Data=0xFFFF
      */
    inline uint32_t rtcWAKEUPGetAutoReload()
    {
      return (uint32_t)(READ_BIT(rtcx_->WUTR, RTC_WUTR_WUT));
    }

    /** @defgroup RTC_LL_EF_Backup_Registers Backup_Registers
      * @{
      */

    #if defined(RTC_BKP0R)
    /**
      * @brief  Writes a data in a specified RTC Backup data register.
      * @rmtoll BKPxR        BKP           rtcBAKSetRegister
      * @param  RTCx RTC Instance
      * @param  BackupRegister This parameter can be one of the following values:
      *         @arg @ref rtcBKPDR0
      *         @arg @ref rtcBKPDR1
      *         @arg @ref rtcBKPDR2
      *         @arg @ref rtcBKPDR3
      *         @arg @ref rtcBKPDR4
      *         @arg @ref rtcBKPDR5
      *         @arg @ref rtcBKPDR6
      *         @arg @ref rtcBKPDR7
      *         @arg @ref rtcBKPDR8
      *         @arg @ref rtcBKPDR9
      *         @arg @ref rtcBKPDR10
      *         @arg @ref rtcBKPDR11
      *         @arg @ref rtcBKPDR12
      *         @arg @ref rtcBKPDR13
      *         @arg @ref rtcBKPDR14
      *         @arg @ref rtcBKPDR15
      *         @arg @ref rtcBKPDR16
      *         @arg @ref rtcBKPDR17
      *         @arg @ref rtcBKPDR18
      *         @arg @ref rtcBKPDR19
      *         @arg @ref rtcBKPDR20
      *         @arg @ref rtcBKPDR21
      *         @arg @ref rtcBKPDR22
      *         @arg @ref rtcBKPDR23
      *         @arg @ref rtcBKPDR24
      *         @arg @ref rtcBKPDR25
      *         @arg @ref rtcBKPDR26
      *         @arg @ref rtcBKPDR27
      *         @arg @ref rtcBKPDR28
      *         @arg @ref rtcBKPDR29
      *         @arg @ref rtcBKPDR30
      *         @arg @ref rtcBKPDR31
      * @param  Data Value between Min_Data=0x00 and Max_Data=0xFFFFFFFF
      * @retval None
      */
    inline void rtcBAKSetRegister(RTCBackUpReg BackupRegister, uint32_t Data)
    {
      uint32_t tmp;

      tmp = (uint32_t)(&(rtcx_->BKP0R));
      tmp += (BackupRegister * 4U);

      /* Write the specified register */
      *(__IO uint32_t *)tmp = (uint32_t)Data;
    }

    /**
      * @brief  Reads data from the specified RTC Backup data Register.
      * @rmtoll BKPxR        BKP           rtcBAKGetRegister
      * @param  RTCx RTC Instance
      * @param  BackupRegister This parameter can be one of the following values:
      *         @arg @ref rtcBKPDR0
      *         @arg @ref rtcBKPDR1
      *         @arg @ref rtcBKPDR2
      *         @arg @ref rtcBKPDR3
      *         @arg @ref rtcBKPDR4
      *         @arg @ref rtcBKPDR5
      *         @arg @ref rtcBKPDR6
      *         @arg @ref rtcBKPDR7
      *         @arg @ref rtcBKPDR8
      *         @arg @ref rtcBKPDR9
      *         @arg @ref rtcBKPDR10
      *         @arg @ref rtcBKPDR11
      *         @arg @ref rtcBKPDR12
      *         @arg @ref rtcBKPDR13
      *         @arg @ref rtcBKPDR14
      *         @arg @ref rtcBKPDR15
      *         @arg @ref rtcBKPDR16
      *         @arg @ref rtcBKPDR17
      *         @arg @ref rtcBKPDR18
      *         @arg @ref rtcBKPDR19
      *         @arg @ref rtcBKPDR20
      *         @arg @ref rtcBKPDR21
      *         @arg @ref rtcBKPDR22
      *         @arg @ref rtcBKPDR23
      *         @arg @ref rtcBKPDR24
      *         @arg @ref rtcBKPDR25
      *         @arg @ref rtcBKPDR26
      *         @arg @ref rtcBKPDR27
      *         @arg @ref rtcBKPDR28
      *         @arg @ref rtcBKPDR29
      *         @arg @ref rtcBKPDR30
      *         @arg @ref rtcBKPDR31
      * @retval Value between Min_Data=0x00 and Max_Data=0xFFFFFFFF
      */
    inline uint32_t rtcBAKGetRegister(RTCBackUpReg BackupRegister)
    {
      uint32_t tmp;

      tmp = (uint32_t)(&(rtcx_->BKP0R));
      tmp += (BackupRegister * 4U);

      /* Read the specified register */
      return (*(__IO uint32_t *)tmp);
    }
    #endif /* RTC_BKP0R */

    #if defined(TAMP_BKP0R)
    /**
      * @brief  Writes a data in a specified Backup data register.
      * @rmtoll TAMP_BKPxR        BKP           rtcBKPSetRegister
      * @param  TAMPx RTC Instance
      * @param  BackupRegister This parameter can be one of the following values:
      *         @arg @ref rtcBKPDR0
      *         @arg @ref rtcBKPDR1
      *         @arg @ref rtcBKPDR2
      *         @arg @ref rtcBKPDR3
      *         @arg @ref rtcBKPDR4
      *         @arg @ref rtcBKPDR5
      *         @arg @ref rtcBKPDR6
      *         @arg @ref rtcBKPDR7
      *         @arg @ref rtcBKPDR8
      *         @arg @ref rtcBKPDR9
      *         @arg @ref rtcBKPDR10
      *         @arg @ref rtcBKPDR11
      *         @arg @ref rtcBKPDR12
      *         @arg @ref rtcBKPDR13
      *         @arg @ref rtcBKPDR14
      *         @arg @ref rtcBKPDR15
      *         @arg @ref rtcBKPDR16
      *         @arg @ref rtcBKPDR17
      *         @arg @ref rtcBKPDR18
      *         @arg @ref rtcBKPDR19
      *         @arg @ref rtcBKPDR20
      *         @arg @ref rtcBKPDR21
      *         @arg @ref rtcBKPDR22
      *         @arg @ref rtcBKPDR23
      *         @arg @ref rtcBKPDR24
      *         @arg @ref rtcBKPDR25
      *         @arg @ref rtcBKPDR26
      *         @arg @ref rtcBKPDR27
      *         @arg @ref rtcBKPDR28
      *         @arg @ref rtcBKPDR29
      *         @arg @ref rtcBKPDR30
      *         @arg @ref rtcBKPDR31
      * @param  Data Value between Min_Data=0x00 and Max_Data=0xFFFFFFFF
      * @retval None
      */
    inline void rtcBKPSetRegister(RTCBackUpReg BackupRegister, uint32_t Data)
    {
      uint32_t tmp = 0U;

      tmp = (uint32_t)(&(tampx_->BKP0R));
      tmp += (BackupRegister * 4U);

      /* Write the specified register */
      *(__IO uint32_t *)tmp = (uint32_t)Data;
    }

    /**
      * @brief  Reads data from the specified RTC Backup data Register.
      * @rmtoll TAMP_BKPxR        BKP           rtcBKPGetRegister
      * @param  TAMPx RTC Instance
      * @param  BackupRegister This parameter can be one of the following values:
      *         @arg @ref rtcBKPDR0
      *         @arg @ref rtcBKPDR1
      *         @arg @ref rtcBKPDR2
      *         @arg @ref rtcBKPDR3
      *         @arg @ref rtcBKPDR4
      *         @arg @ref rtcBKPDR5
      *         @arg @ref rtcBKPDR6
      *         @arg @ref rtcBKPDR7
      *         @arg @ref rtcBKPDR8
      *         @arg @ref rtcBKPDR9
      *         @arg @ref rtcBKPDR10
      *         @arg @ref rtcBKPDR11
      *         @arg @ref rtcBKPDR12
      *         @arg @ref rtcBKPDR13
      *         @arg @ref rtcBKPDR14
      *         @arg @ref rtcBKPDR15
      *         @arg @ref rtcBKPDR16
      *         @arg @ref rtcBKPDR17
      *         @arg @ref rtcBKPDR18
      *         @arg @ref rtcBKPDR19
      *         @arg @ref rtcBKPDR20
      *         @arg @ref rtcBKPDR21
      *         @arg @ref rtcBKPDR22
      *         @arg @ref rtcBKPDR23
      *         @arg @ref rtcBKPDR24
      *         @arg @ref rtcBKPDR25
      *         @arg @ref rtcBKPDR26
      *         @arg @ref rtcBKPDR27
      *         @arg @ref rtcBKPDR28
      *         @arg @ref rtcBKPDR29
      *         @arg @ref rtcBKPDR30
      *         @arg @ref rtcBKPDR31
      * @retval Value between Min_Data=0x00 and Max_Data=0xFFFFFFFF
      */
    inline uint32_t rtcBKPGetRegister(RTCBackUpReg BackupRegister)
    {
      uint32_t tmp = 0U;

      tmp = (uint32_t)(&(tampx_->BKP0R));
      tmp += (BackupRegister * 4U);

      /* Read the specified register */
      return (*(__IO uint32_t *)tmp);
    }
    #endif /* TAMP_BKP0R */

    /** @defgroup RTC_LL_EF_Calibration Calibration
      * @{
      */

    /**
      * @brief  Set Calibration output frequency (1 Hz or 512 Hz)
      * @note Bits are write-protected. @ref rtcDisableWriteProtection function should be called before.
      * @rmtoll RTC_CR           COE           rtcCALSetOutputFreq
      *         RTC_CR           COSEL         rtcCALSetOutputFreq
      * @param  RTCx RTC Instance
      * @param  Frequency This parameter can be one of the following values:
      *         @arg @ref rtcCALIB_OUTPUT_NONE
      *         @arg @ref rtcCALIB_OUTPUT_1HZ
      *         @arg @ref rtcCALIB_OUTPUT_512HZ
      * @retval None
      */
    inline void rtcCALSetOutputFreq(RTCCalibrationOutput Frequency)
    {
      MODIFY_REG(rtcx_->CR, RTC_CR_COE | RTC_CR_COSEL, Frequency);
    }

    /**
      * @brief  Get Calibration output frequency (1 Hz or 512 Hz)
      * @rmtoll RTC_CR           COE           rtcCALGetOutputFreq
      *         RTC_CR           COSEL         rtcCALGetOutputFreq
      * @param  RTCx RTC Instance
      * @retval Returned value can be one of the following values:
      *         @arg @ref rtcCALIB_OUTPUT_NONE
      *         @arg @ref rtcCALIB_OUTPUT_1HZ
      *         @arg @ref rtcCALIB_OUTPUT_512HZ
      */
    inline RTCCalibrationOutput rtcCALGetOutputFreq()
    {
      return (RTCCalibrationOutput)(READ_BIT(rtcx_->CR, RTC_CR_COE | RTC_CR_COSEL));
    }

    /**
      * @brief  Insert or not One RTCCLK pulse every 2exp11 pulses (frequency increased by 488.5 ppm)
      * @note   Bit is write-protected. @ref rtcDisableWriteProtection function should be called before.
      * @note   Bit can be written only when RECALPF is set to 0 in RTC_ISR
      * @rmtoll RTC_CALR         CALP          rtcCALSetPulse
      * @param  RTCx RTC Instance
      * @param  Pulse This parameter can be one of the following values:
      *         @arg @ref rtcCALIB_INSERTPULSE_NONE
      *         @arg @ref rtcCALIB_INSERTPULSE_SET
      * @retval None
      */
    inline void rtcCALSetPulse(RTCCalibrationInsertPulse Pulse)
    {
      MODIFY_REG(rtcx_->CALR, RTC_CALR_CALP, Pulse);
    }

    /**
      * @brief  Check if one RTCCLK has been inserted or not every 2exp11 pulses (frequency increased by 488.5 ppm)
      * @rmtoll RTC_CALR         CALP          rtcCALIsPulseInserted
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcCALIsPulseInserted()
    {
      return ((READ_BIT(rtcx_->CALR, RTC_CALR_CALP) == (RTC_CALR_CALP)) ? true : false);
    }

    /**
      * @brief  Set the calibration cycle period
      * @note   Bit is write-protected. @ref rtcDisableWriteProtection function should be called before.
      * @note   Bit can be written only when RECALPF is set to 0 in RTC_ISR
      * @rmtoll RTC_CALR         CALW8         rtcCALSetPeriod
      *         RTC_CALR         CALW16        rtcCALSetPeriod
      * @param  RTCx RTC Instance
      * @param  Period This parameter can be one of the following values:
      *         @arg @ref rtcCALIB_PERIOD_32SEC
      *         @arg @ref rtcCALIB_PERIOD_16SEC
      *         @arg @ref rtcCALIB_PERIOD_8SEC
      * @retval None
      */
    inline void rtcCALSetPeriod(RTCCalibrationPeriod Period)
    {
      MODIFY_REG(rtcx_->CALR, RTC_CALR_CALW8 | RTC_CALR_CALW16, Period);
    }

    /**
      * @brief  Get the calibration cycle period
      * @rmtoll RTC_CALR         CALW8         rtcCALGetPeriod
      *         RTC_CALR         CALW16        rtcCALGetPeriod
      * @param  RTCx RTC Instance
      * @retval Returned value can be one of the following values:
      *         @arg @ref rtcCALIB_PERIOD_32SEC
      *         @arg @ref rtcCALIB_PERIOD_16SEC
      *         @arg @ref rtcCALIB_PERIOD_8SEC
      */
    inline RTCCalibrationPeriod rtcCALGetPeriod()
    {
      return (RTCCalibrationPeriod)(READ_BIT(rtcx_->CALR, RTC_CALR_CALW8 | RTC_CALR_CALW16));
    }

    /**
      * @brief  Set Calibration minus
      * @note   Bit is write-protected. @ref rtcDisableWriteProtection function should be called before.
      * @note   Bit can be written only when RECALPF is set to 0 in RTC_ISR
      * @rmtoll RTC_CALR         CALM          rtcCALSetMinus
      * @param  RTCx RTC Instance
      * @param  CalibMinus Value between Min_Data=0x00 and Max_Data=0x1FF
      * @retval None
      */
    inline void rtcCALSetMinus(uint32_t CalibMinus)
    {
      MODIFY_REG(rtcx_->CALR, RTC_CALR_CALM, CalibMinus);
    }

    /**
      * @brief  Get Calibration minus
      * @rmtoll RTC_CALR         CALM          rtcCALGetMinus
      * @param  RTCx RTC Instance
      * @retval Value between Min_Data=0x00 and Max_Data= 0x1FF
      */
    inline uint32_t rtcCALGetMinus()
    {
      return (uint32_t)(READ_BIT(rtcx_->CALR, RTC_CALR_CALM));
    }

    /** @defgroup RTC_LL_EF_FLAG_Management FLAG_Management
      * @{
      */

    #if defined(RTC_ISR_ITSF)
    /**
      * @brief  Get Internal Time-stamp flag
      * @rmtoll RTC_ISR          ITSF          rtcIsActiveFlagITS
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagITS()
    {
      return ((READ_BIT(rtcx_->ISR, RTC_ISR_ITSF) == (RTC_ISR_ITSF)) ? true : false);
    }

    /**
      * @brief  Get Recalibration pending Flag
      * @rmtoll ISR          RECALPF       rtcIsActiveFlagRECALP
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagRECALP()
    {
      return ((READ_BIT(rtcx_->ISR, RTC_ISR_RECALPF) == (RTC_ISR_RECALPF)) ? true : false);
    }

    /**
      * @brief  Get RTC_TAMP3 detection flag
      * @rmtoll ISR          TAMP3F        rtcIsActiveFlagTAMP3
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagTAMP3()
    {
      return ((READ_BIT(rtcx_->ISR, RTC_ISR_TAMP3F) == (RTC_ISR_TAMP3F)) ? true : false);
    }

    /**
      * @brief  Get RTC_TAMP2 detection flag
      * @rmtoll ISR          TAMP2F        rtcIsActiveFlagTAMP2
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagTAMP2()
    {
      return ((READ_BIT(rtcx_->ISR, RTC_ISR_TAMP2F) == (RTC_ISR_TAMP2F)) ? true : false);
    }

    /**
      * @brief  Get RTC_TAMP1 detection flag
      * @rmtoll ISR          TAMP1F        rtcIsActiveFlagTAMP1
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagTAMP1()
    {
      return ((READ_BIT(rtcx_->ISR, RTC_ISR_TAMP1F) == (RTC_ISR_TAMP1F)) ? true : false);
    }

    /**
      * @brief  Get Time-stamp overflow flag
      * @rmtoll ISR          TSOVF         rtcIsActiveFlagTSOV
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagTSOV()
    {
      return ((READ_BIT(rtcx_->ISR, RTC_ISR_TSOVF) == (RTC_ISR_TSOVF)) ? true : false);
    }

    /**
      * @brief  Get Time-stamp flag
      * @rmtoll ISR          TSF           rtcIsActiveFlagTS
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagTS()
    {
      return ((READ_BIT(rtcx_->ISR, RTC_ISR_TSF) == (RTC_ISR_TSF)) ? true : false);
    }

    /**
      * @brief  Get Wakeup timer flag
      * @rmtoll ISR          WUTF          rtcIsActiveFlagWUT
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagWUT()
    {
      return ((READ_BIT(rtcx_->ISR, RTC_ISR_WUTF) == (RTC_ISR_WUTF)) ? true : false);
    }

    /**
      * @brief  Get Alarm B flag
      * @rmtoll ISR          ALRBF         rtcIsActiveFlagALRB
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool  rtcIsActiveFlagALRB()
    {
      return ((READ_BIT(rtcx_->ISR, RTC_ISR_ALRBF) == (RTC_ISR_ALRBF)) ? true : false);
    }

    /**
      * @brief  Get Alarm A flag
      * @rmtoll ISR          ALRAF         rtcIsActiveFlagALRA
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagALRA()
    {
      return ((READ_BIT(rtcx_->ISR, RTC_ISR_ALRAF) == (RTC_ISR_ALRAF)) ? true : false);
    }

    /**
      * @brief  Clear Internal Time-stamp flag
      * @rmtoll ISR          ITSF          rtcClearFlagITS
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcClearFlagITS()
    {
      WRITE_REG(rtcx_->ISR, (~((RTC_ISR_ITSF | RTC_ISR_INIT) & 0x0000FFFFU) | (rtcx_->ISR & RTC_ISR_INIT)));
    }

    /**
      * @brief  Clear RTC_TAMP3 detection flag
      * @rmtoll ISR          TAMP3F        rtcClearFlagTAMP3
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcClearFlagTAMP3()
    {
      WRITE_REG(rtcx_->ISR, (~((RTC_ISR_TAMP3F | RTC_ISR_INIT) & 0x0000FFFFU) | (rtcx_->ISR & RTC_ISR_INIT)));
    }

    /**
      * @brief  Clear RTC_TAMP2 detection flag
      * @rmtoll ISR          TAMP2F        rtcClearFlagTAMP2
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcClearFlagTAMP2()
    {
      WRITE_REG(rtcx_->ISR, (~((RTC_ISR_TAMP2F | RTC_ISR_INIT) & 0x0000FFFFU) | (rtcx_->ISR & RTC_ISR_INIT)));
    }

    /**
      * @brief  Clear RTC_TAMP1 detection flag
      * @rmtoll ISR          TAMP1F        rtcClearFlagTAMP1
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcClearFlagTAMP1()
    {
      WRITE_REG(rtcx_->ISR, (~((RTC_ISR_TAMP1F | RTC_ISR_INIT) & 0x0000FFFFU) | (rtcx_->ISR & RTC_ISR_INIT)));
    }

    /**
      * @brief  Clear Time-stamp overflow flag
      * @rmtoll ISR          TSOVF         rtcClearFlagTSOV
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcClearFlagTSOV()
    {
      WRITE_REG(rtcx_->ISR, (~((RTC_ISR_TSOVF | RTC_ISR_INIT) & 0x0000FFFFU) | (rtcx_->ISR & RTC_ISR_INIT)));
    }

    /**
      * @brief  Clear Time-stamp flag
      * @rmtoll ISR          TSF           rtcClearFlagTS
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcClearFlagTS()
    {
      WRITE_REG(rtcx_->ISR, (~((RTC_ISR_TSF | RTC_ISR_INIT) & 0x0000FFFFU) | (rtcx_->ISR & RTC_ISR_INIT)));
    }

    /**
      * @brief  Clear Wakeup timer flag
      * @rmtoll ISR          WUTF          rtcClearFlagWUT
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcClearFlagWUT()
    {
      WRITE_REG(rtcx_->ISR, (~((RTC_ISR_WUTF | RTC_ISR_INIT) & 0x0000FFFFU) | (rtcx_->ISR & RTC_ISR_INIT)));
    }

    /**
      * @brief  Clear Alarm B flag
      * @rmtoll ISR          ALRBF         rtcClearFlagALRB
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcClearFlagALRB()
    {
      WRITE_REG(rtcx_->ISR, (~((RTC_ISR_ALRBF | RTC_ISR_INIT) & 0x0000FFFFU) | (rtcx_->ISR & RTC_ISR_INIT)));
    }

    /**
      * @brief  Clear Alarm A flag
      * @rmtoll ISR          ALRAF         rtcClearFlagALRA
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcClearFlagALRA()
    {
      WRITE_REG(rtcx_->ISR, (~((RTC_ISR_ALRAF | RTC_ISR_INIT) & 0x0000FFFFU) | (rtcx_->ISR & RTC_ISR_INIT)));
    }

    /**
      * @brief  Get Initialization flag
      * @rmtoll ISR          INITF         rtcIsActiveFlagINIT
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagINIT()
    {
      return ((READ_BIT(rtcx_->ISR, RTC_ISR_INITF) == (RTC_ISR_INITF)) ? true : false);
    }

    /**
      * @brief  Get Registers synchronization flag
      * @rmtoll ISR          RSF           rtcIsActiveFlagRS
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagRS()
    {
      return ((READ_BIT(rtcx_->ISR, RTC_ISR_RSF) == (RTC_ISR_RSF)) ? true : false);
    }

    /**
      * @brief  Clear Registers synchronization flag
      * @rmtoll ISR          RSF           rtcClearFlagRS
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcClearFlagRS()
    {
      WRITE_REG(rtcx_->ISR, (~((RTC_ISR_RSF | RTC_ISR_INIT) & 0x0000FFFFU) | (rtcx_->ISR & RTC_ISR_INIT)));
    }

    /**
      * @brief  Get Initialization status flag
      * @rmtoll ISR          INITS         rtcIsActiveFlagINITS
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagINITS()
    {
      return ((READ_BIT(rtcx_->ISR, RTC_ISR_INITS) == (RTC_ISR_INITS)) ? true : false);
    }

    /**
      * @brief  Get Shift operation pending flag
      * @rmtoll ISR          SHPF          rtcIsActiveFlagSHP
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagSHP()
    {
      return ((READ_BIT(rtcx_->ISR, RTC_ISR_SHPF) == (RTC_ISR_SHPF)) ? true : false);
    }

    /**
      * @brief  Get Wakeup timer write flag
      * @rmtoll ISR          WUTWF         rtcIsActiveFlagWUTW
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagWUTW()
    {
      return ((READ_BIT(rtcx_->ISR, RTC_ISR_WUTWF) == (RTC_ISR_WUTWF)) ? true : false);
    }

    /**
      * @brief  Get Alarm B write flag
      * @rmtoll ISR          ALRBWF        rtcIsActiveFlagALRBW
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagALRBW()
    {
      return ((READ_BIT(rtcx_->ISR, RTC_ISR_ALRBWF) == (RTC_ISR_ALRBWF)) ? true : false);
    }

    /**
      * @brief  Get Alarm A write flag
      * @rmtoll ISR          ALRAWF        rtcIsActiveFlagALRAW
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagALRAW()
    {
      return ((READ_BIT(rtcx_->ISR, RTC_ISR_ALRAWF) == (RTC_ISR_ALRAWF)) ? true : false);
    }
    #endif /* RTC_ISR_ITSF */

    #if defined(RTC_SR_ITSF)
    /**
      * @brief  Get Internal Time-stamp flag
      * @rmtoll RTC_SR          ITSF          rtcIsActiveFlagITS
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagITS()
    {
      return ((READ_BIT(rtcx_->SR, RTC_SR_ITSF) == (RTC_SR_ITSF)) ? true : false);
    }

    /**
      * @brief  Get Time-stamp overflow flag
      * @rmtoll RTC_SR          TSOVF         rtcIsActiveFlagTSOV
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagTSOV()
    {
      return ((READ_BIT(rtcx_->SR, RTC_SR_TSOVF) == (RTC_SR_TSOVF)) ? true : false);
    }

    /**
      * @brief  Get Time-stamp flag
      * @rmtoll RTC_SR          TSF           rtcIsActiveFlagTS
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagTS()
    {
      return ((READ_BIT(rtcx_->SR, RTC_SR_TSF) == (RTC_SR_TSF)) ? true : false);
    }

    /**
      * @brief  Get Wakeup timer flag
      * @rmtoll RTC_SR          WUTF          rtcIsActiveFlagWUT
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagWUT()
    {
      return ((READ_BIT(rtcx_->SR, RTC_SR_WUTF) == (RTC_SR_WUTF)) ? true : false);
    }

    /**
      * @brief  Get Alarm B flag
      * @rmtoll RTC_SR          ALRBF         rtcIsActiveFlagALRB
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagALRB()
    {
      return ((READ_BIT(rtcx_->SR, RTC_SR_ALRBF) == (RTC_SR_ALRBF)) ? true : false);
    }

    /**
      * @brief  Get Alarm A flag
      * @rmtoll RTC_SR          ALRAF         rtcIsActiveFlagALRA
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagALRA()
    {
      return ((READ_BIT(rtcx_->SR, RTC_SR_ALRAF) == (RTC_SR_ALRAF)) ? true : false);
    }
    #endif /* RTC_SR_ITSF */

    #if defined(RTC_SCR_CITSF)
    /**
      * @brief  Clear Internal Time-stamp flag
      * @rmtoll RTC_SCR          CITSF          rtcClearFlagITS
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcClearFlagITS()
    {
      SET_BIT(rtcx_->SCR, RTC_SCR_CITSF);
    }

    /**
      * @brief  Clear Time-stamp overflow flag
      * @rmtoll RTC_SCR          CTSOVF         rtcClearFlagTSOV
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcClearFlagTSOV()
    {
      SET_BIT(rtcx_->SCR, RTC_SCR_CTSOVF);
    }

    /**
      * @brief  Clear Time-stamp flag
      * @rmtoll RTC_SCR          CTSF           rtcClearFlagTS
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcClearFlagTS()
    {
      SET_BIT(rtcx_->SCR, RTC_SCR_CTSF);
    }

    /**
      * @brief  Clear Wakeup timer flag
      * @rmtoll RTC_SCR          CWUTF          rtcClearFlagWUT
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcClearFlagWUT()
    {
      SET_BIT(rtcx_->SCR, RTC_SCR_CWUTF);
    }

    /**
      * @brief  Clear Alarm B flag
      * @rmtoll RTC_SCR          CALRBF         rtcClearFlagALRB
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcClearFlagALRB()
    {
      SET_BIT(rtcx_->SCR, RTC_SCR_CALRBF);
    }

    /**
      * @brief  Clear Alarm A flag
      * @rmtoll RTC_SCR          CALRAF         rtcClearFlagALRA
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcClearFlagALRA()
    {
      SET_BIT(rtcx_->SCR, RTC_SCR_CALRAF);
    }
    #endif /* RTC_SCR_CITSF */

    #if defined(RTC_ICSR_RECALPF)
    /**
      * @brief  Get Recalibration pending Flag
      * @rmtoll RTC_ICSR          RECALPF       rtcIsActiveFlagRECALP
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagRECALP()
    {
      return ((READ_BIT(rtcx_->ICSR, RTC_ICSR_RECALPF) == (RTC_ICSR_RECALPF)) ? true : false);
    }

    /**
      * @brief  Get Initialization flag
      * @rmtoll RTC_ICSR          INITF         rtcIsActiveFlagINIT
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagINIT()
    {
      return ((READ_BIT(rtcx_->ICSR, RTC_ICSR_INITF) == (RTC_ICSR_INITF)) ? true : false);
    }

    /**
      * @brief  Get Registers synchronization flag
      * @rmtoll RTC_ICSR          RSF           rtcIsActiveFlagRS
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagRS()
    {
      return ((READ_BIT(rtcx_->ICSR, RTC_ICSR_RSF) == (RTC_ICSR_RSF)) ? true : false);
    }

    /**
      * @brief  Clear Registers synchronization flag
      * @rmtoll RTC_ICSR          RSF           rtcClearFlagRS
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcClearFlagRS()
    {
      WRITE_REG(rtcx_->ICSR, (~((RTC_ICSR_RSF | RTC_ICSR_INIT) & 0x000000FFU) | (rtcx_->ICSR & RTC_ICSR_INIT)));
    }

    /**
      * @brief  Get Initialization status flag
      * @rmtoll RTC_ICSR          INITS         rtcIsActiveFlagINITS
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagINITS()
    {
      return ((READ_BIT(rtcx_->ICSR, RTC_ICSR_INITS) == (RTC_ICSR_INITS)) ? true : false);
    }

    /**
      * @brief  Get Shift operation pending flag
      * @rmtoll RTC_ICSR          SHPF          rtcIsActiveFlagSHP
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagSHP()
    {
      return ((READ_BIT(rtcx_->ICSR, RTC_ICSR_SHPF) == (RTC_ICSR_SHPF)) ? true : false);
    }

    /**
      * @brief  Get Wakeup timer write flag
      * @rmtoll RTC_ICSR          WUTWF         rtcIsActiveFlagWUTW
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagWUTW()
    {
      return ((READ_BIT(rtcx_->ICSR, RTC_ICSR_WUTWF) == (RTC_ICSR_WUTWF)) ? true : false);
    }

    /**
      * @brief  Get Alarm B write flag
      * @rmtoll RTC_ICSR         ALRBWF        rtcIsActiveFlagALRBW
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagALRBW()
    {
      return ((READ_BIT(rtcx_->ICSR, RTC_ICSR_ALRBWF) == (RTC_ICSR_ALRBWF)) ? true : false);
    }

    /**
      * @brief  Get Alarm A write flag
      * @rmtoll RTC_ICSR         ALRAWF        rtcIsActiveFlagALRAW
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagALRAW()
    {
      return ((READ_BIT(rtcx_->ICSR, RTC_ICSR_ALRAWF) == (RTC_ICSR_ALRAWF)) ? true : false);
    }
    #endif /* RTC_ICSR_RECALPF */

    #if defined(RTC_MISR_ALRAMF)
    /**
      * @brief  Get Alarm A masked flag.
      * @rmtoll RTC_MISR          ALRAMF        rtcIsActiveFlagALRAM
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagALRAM()
    {
      return ((READ_BIT(rtcx_->MISR, RTC_MISR_ALRAMF) == (RTC_MISR_ALRAMF)) ? true : false);
    }

    /**
      * @brief  Get Alarm B masked flag.
      * @rmtoll RTC_MISR          ALRBMF        rtcIsActiveFlagALRBM
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagALRBM()
    {
      return ((READ_BIT(rtcx_->MISR, RTC_MISR_ALRBMF) == (RTC_MISR_ALRBMF)) ? true : false);
    }

    /**
      * @brief  Get Wakeup timer masked flag.
      * @rmtoll RTC_MISR          WUTMF        rtcIsActiveFlagWUTM
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagWUTM()
    {
      return ((READ_BIT(rtcx_->MISR, RTC_MISR_WUTMF) == (RTC_MISR_WUTMF)) ? true : false);
    }

    /**
      * @brief  Get Time-stamp masked flag.
      * @rmtoll RTC_MISR          TSMF        rtcIsActiveFlagTSM
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagTSM()
    {
      return ((READ_BIT(rtcx_->MISR, RTC_MISR_TSMF) == (RTC_MISR_TSMF)) ? true : false);
    }

    /**
      * @brief  Get Time-stamp overflow masked flag.
      * @rmtoll RTC_MISR          TSOVMF        rtcIsActiveFlagTSOVM
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagTSOVM()
    {
      return ((READ_BIT(rtcx_->MISR, RTC_MISR_TSOVMF) == (RTC_MISR_TSOVMF)) ? true : false);
    }

    /**
      * @brief  Get Internal Time-stamp masked flag.
      * @rmtoll RTC_MISR          ITSMF        rtcIsActiveFlagITSM
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagITSM()
    {
      return ((READ_BIT(rtcx_->MISR, RTC_MISR_ITSMF) == (RTC_MISR_ITSMF)) ? true : false);
    }
    #endif /* RTC_MISR_ALRAMF */

    #if defined(TAMP_CR1_TAMP1E)
    /**
      * @brief  Get tamper 1 detection flag.
      * @rmtoll TAMP_SR          TAMP1F        rtcIsActiveFlagTAMP1
      * @param  TAMPx TAMP Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagTAMP1()
    {
      return ((READ_BIT(tampx_->SR, TAMP_SR_TAMP1F) == (TAMP_SR_TAMP1F)) ? true : false);
    }
    #endif /* TAMP_CR1_TAMP1E */

    #if defined(TAMP_CR1_TAMP2E)
    /**
      * @brief  Get tamper 2 detection flag.
      * @rmtoll TAMP_SR          TAMP2F        rtcIsActiveFlagTAMP2
      * @param  TAMPx TAMP Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagTAMP2()
    {
      return ((READ_BIT(tampx_->SR, TAMP_SR_TAMP2F) == (TAMP_SR_TAMP2F)) ? true : false);
    }
    #endif /* TAMP_CR1_TAMP2E */

    #if defined(TAMP_CR1_TAMP3E)
    /**
      * @brief  Get tamper 3 detection flag.
      * @rmtoll TAMP_SR          TAMP3F        rtcIsActiveFlagTAMP3
      * @param  TAMPx TAMP Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagTAMP3()
    {
      return ((READ_BIT(tampx_->SR, TAMP_SR_TAMP3F) == (TAMP_SR_TAMP3F)) ? true : false);
    }
    #endif /* TAMP_CR1_TAMP3E */

    #if defined(TAMP_CR1_TAMP1E)
    /**
      * @brief  Get tamper 1 interrupt masked flag.
      * @rmtoll TAMP_MISR          TAMP1MF        rtcIsActiveFlagTAMP1M
      * @param  TAMPx TAMP Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagTAMP1M()
    {
      return ((READ_BIT(tampx_->MISR, TAMP_MISR_TAMP1MF) == (TAMP_MISR_TAMP1MF)) ? true : false);
    }
    #endif /* TAMP_CR1_TAMP1E */

    #if defined(TAMP_CR1_TAMP2E)
    /**
      * @brief  Get tamper 2 interrupt masked flag.
      * @rmtoll TAMP_MISR          TAMP2MF        rtcIsActiveFlagTAMP2M
      * @param  TAMPx TAMP Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagTAMP2M()
    {
      return ((READ_BIT(tampx_->MISR, TAMP_MISR_TAMP2MF) == (TAMP_MISR_TAMP2MF)) ? true : false);
    }
    #endif /* TAMP_CR1_TAMP2E */

    #if defined(TAMP_CR1_TAMP3E)
    /**
      * @brief  Get tamper 3 interrupt masked flag.
      * @rmtoll TAMP_MISR          TAMP3MF        rtcIsActiveFlagTAMP3M
      * @param  TAMPx TAMP Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagTAMP3M()
    {
      return ((READ_BIT(tampx_->MISR, TAMP_MISR_TAMP3MF) == (TAMP_MISR_TAMP3MF)) ? true : false);
    }
    #endif /* TAMP_CR1_TAMP3E */

    #if defined(TAMP_CR1_TAMP1E)
    /**
      * @brief  Clear tamper 1 detection flag.
      * @rmtoll TAMP_SCR          CTAMP1F         rtcClearFlagTAMP1
      * @param  TAMPx TAMP Instance
      * @retval None
      */
    inline void rtcClearFlagTAMP1()
    {
      SET_BIT(tampx_->SCR, TAMP_SCR_CTAMP1F);
    }
    #endif /* TAMP_CR1_TAMP1E */

    #if defined(TAMP_CR1_TAMP2E)
    /**
      * @brief  Clear tamper 2 detection flag.
      * @rmtoll TAMP_SCR          CTAMP2F         rtcClearFlagTAMP2
      * @param  TAMPx TAMP Instance
      * @retval None
      */
    inline void rtcClearFlagTAMP2()
    {
      SET_BIT(tampx_->SCR, TAMP_SCR_CTAMP2F);
    }
    #endif /* TAMP_CR1_TAMP2E */

    #if defined(TAMP_CR1_TAMP3E)
    /**
      * @brief  Clear tamper 3 detection flag.
      * @rmtoll TAMP_SCR          CTAMP3F         rtcClearFlagTAMP3
      * @param  TAMPx TAMP Instance
      * @retval None
      */
    inline void rtcClearFlagTAMP3()
    {
      SET_BIT(tampx_->SCR, TAMP_SCR_CTAMP3F);
    }
    #endif /* TAMP_CR1_TAMP3E */
    /** @defgroup RTC_LL_EF_IT_Management IT_Management
      * @{
      */

    /**
      * @brief  Enable Time-stamp interrupt
      * @note   Bit is write-protected. @ref rtcDisableWriteProtection function should be called before.
      * @rmtoll RTC_CR          TSIE         rtcEnableITTS
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcEnableITTS()
    {
      SET_BIT(rtcx_->CR, RTC_CR_TSIE);
    }

    /**
      * @brief  Disable Time-stamp interrupt
      * @note   Bit is write-protected. @ref rtcDisableWriteProtection function should be called before.
      * @rmtoll RTC_CR          TSIE         rtcDisableITTS
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcDisableITTS()
    {
      CLEAR_BIT(rtcx_->CR, RTC_CR_TSIE);
    }

    /**
      * @brief  Enable Wakeup timer interrupt
      * @note   Bit is write-protected. @ref rtcDisableWriteProtection function should be called before.
      * @rmtoll RTC_CR          WUTIE         rtcEnableITWUT
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcEnableITWUT()
    {
      SET_BIT(rtcx_->CR, RTC_CR_WUTIE);
    }

    /**
      * @brief  Disable Wakeup timer interrupt
      * @note   Bit is write-protected. @ref rtcDisableWriteProtection function should be called before.
      * @rmtoll RTC_CR          WUTIE         rtcDisableITWUT
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcDisableITWUT()
    {
      CLEAR_BIT(rtcx_->CR, RTC_CR_WUTIE);
    }

    /**
      * @brief  Enable Alarm B interrupt
      * @note   Bit is write-protected. @ref rtcDisableWriteProtection function should be called before.
      * @rmtoll RTC_CR           ALRBIE        rtcEnableITALRB
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcEnableITALRB()
    {
      SET_BIT(rtcx_->CR, RTC_CR_ALRBIE);
    }

    /**
      * @brief  Disable Alarm B interrupt
      * @note   Bit is write-protected. @ref rtcDisableWriteProtection function should be called before.
      * @rmtoll RTC_CR           ALRBIE        rtcDisableITALRB
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcDisableITALRB()
    {
      CLEAR_BIT(rtcx_->CR, RTC_CR_ALRBIE);
    }

    /**
      * @brief  Enable Alarm A interrupt
      * @note   Bit is write-protected. @ref rtcDisableWriteProtection function should be called before.
      * @rmtoll RTC_CR           ALRAIE        rtcEnableITALRA
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcEnableITALRA()
    {
      SET_BIT(rtcx_->CR, RTC_CR_ALRAIE);
    }

    /**
      * @brief  Disable Alarm A interrupt
      * @note   Bit is write-protected. @ref rtcDisableWriteProtection function should be called before.
      * @rmtoll RTC_CR           ALRAIE        rtcDisableITALRA
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcDisableITALRA()
    {
      CLEAR_BIT(rtcx_->CR, RTC_CR_ALRAIE);
    }

    #if defined(RTC_TAMPCR_TAMP3E)
    /**
      * @brief  Enable Tamper 3 interrupt
      * @rmtoll TAMPCR       TAMP3IE       rtcEnableITTAMP3
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcEnableITTAMP3()
    {
      SET_BIT(rtcx_->TAMPCR, RTC_TAMPCR_TAMP3IE);
    }

    /**
      * @brief  Disable Tamper 3 interrupt
      * @rmtoll TAMPCR       TAMP3IE       rtcDisableITTAMP3
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcDisableITTAMP3()
    {
      CLEAR_BIT(rtcx_->TAMPCR, RTC_TAMPCR_TAMP3IE);
    }
    #endif /* RTC_TAMPCR_TAMP3E */

    #if defined(RTC_TAMPCR_TAMP2E)
    /**
      * @brief  Enable Tamper 2 interrupt
      * @rmtoll TAMPCR       TAMP2IE       rtcEnableITTAMP2
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcEnableITTAMP2()
    {
      SET_BIT(rtcx_->TAMPCR, RTC_TAMPCR_TAMP2IE);
    }

    /**
      * @brief  Disable Tamper 2 interrupt
      * @rmtoll TAMPCR       TAMP2IE       rtcDisableITTAMP2
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcDisableITTAMP2()
    {
      CLEAR_BIT(rtcx_->TAMPCR, RTC_TAMPCR_TAMP2IE);
    }
    #endif /* RTC_TAMPCR_TAMP2E */

    #if defined(RTC_TAMPCR_TAMP1E)
    /**
      * @brief  Enable Tamper 1 interrupt
      * @rmtoll TAMPCR       TAMP1IE       rtcEnableITTAMP1
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcEnableITTAMP1()
    {
      SET_BIT(rtcx_->TAMPCR, RTC_TAMPCR_TAMP1IE);
    }

    /**
      * @brief  Disable Tamper 1 interrupt
      * @rmtoll TAMPCR       TAMP1IE       rtcDisableITTAMP1
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcDisableITTAMP1()
    {
      CLEAR_BIT(rtcx_->TAMPCR, RTC_TAMPCR_TAMP1IE);
    }
    #endif /* RTC_TAMPCR_TAMP1E */

    #if defined(RTC_TAMPCR_TAMPIE)
    /**
      * @brief  Enable all Tamper Interrupt
      * @rmtoll TAMPCR       TAMPIE        rtcEnableITTAMP
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcEnableITTAMP()
    {
      SET_BIT(rtcx_->TAMPCR, RTC_TAMPCR_TAMPIE);
    }

    /**
      * @brief  Disable all Tamper Interrupt
      * @rmtoll TAMPCR       TAMPIE        rtcDisableITTAMP
      * @param  RTCx RTC Instance
      * @retval None
      */
    inline void rtcDisableITTAMP()
    {
      CLEAR_BIT(rtcx_->TAMPCR, RTC_TAMPCR_TAMPIE);
    }
    #endif /* RTC_TAMPCR_TAMPIE */

    /**
      * @brief  Check if  Time-stamp interrupt is enabled or not
      * @rmtoll CR           TSIE          rtcIsEnabledITTS
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsEnabledITTS()
    {
      return ((READ_BIT(rtcx_->CR, RTC_CR_TSIE) == (RTC_CR_TSIE)) ? true : false);
    }

    /**
      * @brief  Check if  Wakeup timer interrupt is enabled or not
      * @rmtoll CR           WUTIE         rtcIsEnabledITWUT
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsEnabledITWUT()
    {
      return ((READ_BIT(rtcx_->CR, RTC_CR_WUTIE) == (RTC_CR_WUTIE)) ? true : false);
    }

    /**
      * @brief  Check if  Alarm B interrupt is enabled or not
      * @rmtoll CR           ALRBIE        rtcIsEnabledITALRB
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsEnabledITALRB()
    {
      return ((READ_BIT(rtcx_->CR, RTC_CR_ALRBIE) == (RTC_CR_ALRBIE)) ? true : false);
    }

    /**
      * @brief  Check if  Alarm A interrupt is enabled or not
      * @rmtoll CR           ALRAIE        rtcIsEnabledITALRA
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsEnabledITALRA()
    {
      return ((READ_BIT(rtcx_->CR, RTC_CR_ALRAIE) == (RTC_CR_ALRAIE)) ? true : false);
    }

    #if defined(RTC_TAMPCR_TAMP3E)
    /**
      * @brief  Check if  Tamper 3 interrupt is enabled or not
      * @rmtoll TAMPCR       TAMP3IE       rtcIsEnabledITTAMP3
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsEnabledITTAMP3()
    {
      return ((READ_BIT(rtcx_->TAMPCR, RTC_TAMPCR_TAMP3IE) == (RTC_TAMPCR_TAMP3IE)) ? true : false);
    }
    #endif /* RTC_TAMPCR_TAMP3E */

    #if defined(RTC_TAMPCR_TAMP2E)
    /**
      * @brief  Check if  Tamper 2 interrupt is enabled or not
      * @rmtoll TAMPCR       TAMP2IE       rtcIsEnabledITTAMP2
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsEnabledITTAMP2()
    {
      return ((READ_BIT(rtcx_->TAMPCR, RTC_TAMPCR_TAMP2IE) == (RTC_TAMPCR_TAMP2IE)) ? true : false);

    }
    #endif /* RTC_TAMPCR_TAMP2E */

    #if defined(RTC_TAMPCR_TAMP1E)
    /**
      * @brief  Check if  Tamper 1 interrupt is enabled or not
      * @rmtoll TAMPCR       TAMP1IE       rtcIsEnabledITTAMP1
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsEnabledITTAMP1()
    {
      return ((READ_BIT(rtcx_->TAMPCR, RTC_TAMPCR_TAMP1IE) == (RTC_TAMPCR_TAMP1IE)) ? true : false);
    }
    #endif /* RTC_TAMPCR_TAMP1E */

    #if defined(RTC_TAMPCR_TAMPIE)
    /**
      * @brief  Check if all the TAMPER interrupts are enabled or not
      * @rmtoll TAMPCR       TAMPIE        rtcIsEnabledITTAMP
      * @param  RTCx RTC Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsEnabledITTAMP()
    {
      return ((READ_BIT(rtcx_->TAMPCR, RTC_TAMPCR_TAMPIE) == (RTC_TAMPCR_TAMPIE)) ? true : false);
    }
    #endif /* RTC_TAMPCR_TAMPIE */

    #if defined(TAMP_CR1_TAMP1E)
    /**
      * @brief  Enable tamper 1 interrupt.
      * @rmtoll TAMP_IER           TAMP1IE          rtcEnableITTAMP1
      * @param  TAMPx TAMP Instance
      * @retval None
      */
    inline void rtcEnableITTAMP1()
    {
      SET_BIT(tampx_->IER, TAMP_IER_TAMP1IE);
    }

    /**
      * @brief  Disable tamper 1 interrupt.
      * @rmtoll TAMP_IER           TAMP1IE          rtcDisableITTAMP1
      * @param  TAMPx TAMP Instance
      * @retval None
      */
    inline void rtcDisableITTAMP1()
    {
      CLEAR_BIT(tampx_->IER, TAMP_IER_TAMP1IE);
    }
    #endif /* TAMP_CR1_TAMP1E */

    #if defined(TAMP_CR1_TAMP2E)
    /**
      * @brief  Enable tamper 2 interrupt.
      * @rmtoll TAMP_IER           TAMP2IE          rtcEnableITTAMP2
      * @param  TAMPx TAMP Instance
      * @retval None
      */
    inline void rtcEnableITTAMP2()
    {
      SET_BIT(tampx_->IER, TAMP_IER_TAMP2IE);
    }

    /**
      * @brief  Disable tamper 2 interrupt.
      * @rmtoll TAMP_IER           TAMP2IE          rtcDisableITTAMP2
      * @param  TAMPx TAMP Instance
      * @retval None
      */
    inline void rtcDisableITTAMP2()
    {
      CLEAR_BIT(tampx_->IER, TAMP_IER_TAMP2IE);
    }
    #endif /* TAMP_CR1_TAMP2E */

    #if defined(TAMP_CR1_TAMP3E)
    /**
      * @brief  Enable tamper 3 interrupt.
      * @rmtoll TAMP_IER           TAMP3IE          rtcEnableITTAMP3
      * @param  TAMPx TAMP Instance
      * @retval None
      */
    inline void rtcEnableITTAMP3()
    {
      SET_BIT(tampx_->IER, TAMP_IER_TAMP3IE);
    }

    /**
      * @brief  Disable tamper 3 interrupt.
      * @rmtoll TAMP_IER           TAMP3IE          rtcDisableITTAMP3
      * @param  TAMPx TAMP Instance
      * @retval None
      */
    inline void rtcDisableITTAMP3()
    {
      CLEAR_BIT(tampx_->IER, TAMP_IER_TAMP3IE);
    }
    #endif /* TAMP_CR1_TAMP3E */

    #if defined(TAMP_CR1_TAMP1E)
    /**
      * @brief  Check if tamper 1 interrupt is enabled or not.
      * @rmtoll TAMP_IER           TAMP1IE        rtcIsEnabledITTAMP1
      * @param  TAMPx TAMP Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsEnabledITTAMP1()
    {
      return ((READ_BIT(tampx_->IER, TAMP_IER_TAMP1IE) == (TAMP_IER_TAMP1IE)) ? true : false);
    }
    #endif /* TAMP_CR1_TAMP1E */

    #if defined(TAMP_CR1_TAMP2E)
    /**
      * @brief  Check if tamper 2 interrupt is enabled or not.
      * @rmtoll TAMP_IER           TAMP2IE        rtcIsEnabledITTAMP2
      * @param  TAMPx TAMP Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsEnabledITTAMP2()
    {
      return ((READ_BIT(tampx_->IER, TAMP_IER_TAMP2IE) == (TAMP_IER_TAMP2IE)) ? true : false);
    }
    #endif /* TAMP_CR1_TAMP2E */

    #if defined(TAMP_CR1_TAMP3E)
    /**
      * @brief  Check if tamper 3 interrupt is enabled or not.
      * @rmtoll TAMP_IER           TAMP3IE        rtcIsEnabledITTAMP3
      * @param  TAMPx TAMP Instance
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsEnabledITTAMP3()
    {
      return ((READ_BIT(tampx_->IER, TAMP_IER_TAMP3IE) == (TAMP_IER_TAMP3IE)) ? true : false);
    }
    #endif /* TAMP_CR1_TAMP3E */

    #if defined (TAMP_ATCR1_TAMP1AM)
    /** @defgroup RTC_LL_EF_Active_Tamper Active Tamper
      * @{
      */
    /**
      * @brief  Enable tamper active mode.
      * @rmtoll TAMP_ATCR1     TAMP1AM       rtcTAMPERATAMPEnableActiveMode
      * @rmtoll TAMP_ATCR1     TAMP2AM       rtcTAMPERATAMPEnableActiveMode
      * @rmtoll TAMP_ATCR1     TAMPxAM       rtcTAMPERATAMPEnableActiveMode
      * @param  Tamper to configure as active. This parameter can be a combination of the following values:
      *         @arg @ref RTC_LL_EC_ACTIVE_MODE
      *
      * @retval None
      */
    inline void rtcTAMPERATAMPEnableActiveMode(RTCTamperActiveMode Tamper)
    {
      SET_BIT(TAMP->ATCR1, Tamper);
    }

    /**
      * @brief  Disable tamper active mode.
      * @rmtoll TAMP_ATCR1     TAMP1AM       rtcTAMPERATAMPDisableActiveMode
      * @rmtoll TAMP_ATCR1     TAMP2AM       rtcTAMPERATAMPDisableActiveMode
      * @rmtoll TAMP_ATCR1     TAMPxAM       rtcTAMPERATAMPDisableActiveMode
      * @param  Tamper to configure as active. This parameter can be a combination of the following values:
      *         @arg @ref RTC_LL_EC_ACTIVE_MODE
      *
      * @retval None
      */
    inline void rtcTAMPERATAMPDisableActiveMode(RTCTamperActiveMode Tamper)
    {
      CLEAR_BIT(TAMP->ATCR1, Tamper);
    }

    /**
      * @brief  Enable active tamper filter.
      * @rmtoll TAMP_ATCR1     FLTEN         rtcTAMPERATAMPEnableFilter
      * @retval None
      */
    inline void rtcTAMPERATAMPEnableFilter(void)
    {
      SET_BIT(TAMP->ATCR1, TAMP_ATCR1_FLTEN);
    }

    /**
      * @brief  Disable active tamper filter.
      * @rmtoll TAMP_ATCR1     FLTEN         rtcTAMPERATAMPDisableFilter
      * @retval None
      */
    inline void rtcTAMPERATAMPDisableFilter(void)
    {
      CLEAR_BIT(TAMP->ATCR1, TAMP_ATCR1_FLTEN);
    }

    /**
      * @brief  Set Active tamper output change period.
      * @rmtoll TAMP_ATCR1     ATPER         rtcTAMPERATAMPSetOutputChangePeriod
      * @param  ActiveOutputChangePeriod This parameter can be a value from 0 to 7
      * @retval None
      */
    inline void rtcTAMPERATAMPSetOutputChangePeriod(uint32_t ActiveOutputChangePeriod)
    {
      MODIFY_REG(TAMP->ATCR1, TAMP_ATCR1_ATPER, (ActiveOutputChangePeriod << TAMP_ATCR1_ATPER_Pos));
    }

    /**
      * @brief  Get Active tamper output change period.
      * @rmtoll TAMP_ATCR1     ATPER         rtcTAMPERATAMPGetOutputChangePeriod
      * @retval Output change period. This parameter can be a value from 0 to 7.
      */
    inline uint32_t rtcTAMPERATAMPGetOutputChangePeriod(void)
    {
      return (READ_BIT(TAMP->ATCR1, TAMP_ATCR1_ATPER) >> TAMP_ATCR1_ATPER_Pos);
    }

    /**
      * @brief  Set Active tamper asynchronous prescaler clock selection.
      * @rmtoll TAMP_ATCR1     ATCKSEL       rtcTAMPERATAMPSetAsyncPrescaler
      * @param  ActiveAsynvPrescaler Specifies the Active Tamper asynchronous Prescaler clock.
                This parameter can be a value of the following values:
      *         @arg @ref RTC_LL_EC_ACTIVE_ASYNC_PRESCALER
      * @retval None
      */
    inline void rtcTAMPERATAMPSetAsyncPrescaler(RTCTamperAsyncPrescaler ActiveAsynvPrescaler)
    {
      MODIFY_REG(TAMP->ATCR1, TAMP_ATCR1_ATCKSEL, ActiveAsynvPrescaler);
    }

    /**
      * @brief  Get Active tamper asynchronous prescaler clock selection.
      * @rmtoll TAMP_ATCR1     ATCKSEL       rtcTAMPERATAMPGetAsyncPrescaler
      * @retval One of @arg @ref RTC_LL_EC_ACTIVE_ASYNC_PRESCALER
      */
    inline RTCTamperAsyncPrescaler rtcTAMPERATAMPGetAsyncPrescaler(void)
    {
      return (READ_BIT(TAMP->ATCR1, TAMP_ATCR1_ATCKSEL));
    }

    /**
      * @brief  Enable active tamper output sharing.
      * @rmtoll TAMP_ATCR1     ATOSHARE      rtcTAMPERATAMPEnableOutputSharing
      * @retval None
      */
    inline void rtcTAMPERATAMPEnableOutputSharing(void)
    {
      SET_BIT(TAMP->ATCR1, TAMP_ATCR1_ATOSHARE);
    }

    /**
      * @brief  Disable active tamper output sharing.
      * @rmtoll TAMP_ATCR1     ATOSHARE      rtcTAMPERATAMPDisableOutputSharing
      * @retval None
      */
    inline void rtcTAMPERATAMPDisableOutputSharing(void)
    {
      CLEAR_BIT(TAMP->ATCR1, TAMP_ATCR1_ATOSHARE);
    }

    /**
      * @brief  Set Active tamper output selection.
      * @rmtoll TAMP_ATCR1     ATCKSEL       rtcTAMPERATAMPSetSharedOuputSelection
      * @param  OutputSelection Specifies all the output selection of the Active Tamper.
                This parameter is a combinasation of the following values:
      *         One of @arg @ref RTC_LL_EC_ACTIVE_OUTPUT_SELECTION
      * @retval None
      */
    inline void rtcTAMPERATAMPSetSharedOuputSelection(RTCTamperOutputSelection OutputSelection)
    {
      MODIFY_REG(TAMP->ATCR1, (TAMP_ATCR1_ATOSEL1 | TAMP_ATCR1_ATOSEL2 | TAMP_ATCR1_ATOSEL3), \
                OutputSelection);
    }

    /**
      * @brief  Get Active tamper asynchronous prescaler clock selection.
      * @rmtoll TAMP_ATCR2     ATCKSEL       rtcTAMPERATAMPGetAsyncPrescaler
      * @retval A combination of @arg @ref RTC_LL_EC_ACTIVE_OUTPUT_SELECTION
      */
    inline RTCTamperOutputSelection rtcTAMPERATAMPGetSharedOuputSelection(void)
    {
      return (READ_BIT(TAMP->ATCR1, (TAMP_ATCR1_ATOSEL1 | TAMP_ATCR1_ATOSEL2 | TAMP_ATCR1_ATOSEL3)));
    }
    #endif /* TAMP_ATCR1_TAMP1AM */

    #if defined(ATSEEDR)
    /**
      * @brief  Write active tamper seed.
      * @rmtoll TAMP_ATSEEDR   SEED          rtcTAMPERATAMPWriteSeed
      * @param  Seed
      * @retval None
      */
    inline void rtcTAMPERATAMPWriteSeed(uint32_t Seed)
    {
      WRITE_REG(TAMP->ATSEEDR, Seed);
    }
    #endif /* ATSEEDR */

    #if defined(TAMP_ATOR_INITS)
    /**
      * @brief  Get active tamper initialization status flag.
      * @rmtoll TAMP_ATOR      INITS         rtcIsActiveFlagATAMPINITS
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagATAMPINITS(void)
    {
      return ((READ_BIT(TAMP->ATOR, TAMP_ATOR_INITS) == (TAMP_ATOR_INITS)) ? true : false);
    }

    /**
      * @brief  Get active tamper seed running status flag.
      * @rmtoll TAMP_ATOR      INITS         rtcIsActiveFlagATAMPINITS
      * @retval State of bit (1 or 0).
      */
    inline bool rtcIsActiveFlagATAMPSEEDF(void)
    {
      return ((READ_BIT(TAMP->ATOR, TAMP_ATOR_SEEDF) == (TAMP_ATOR_SEEDF)) ? true : false);
    }
    #endif /* TAMP_ATOR_INITS */

    eResult rtcDeInit()
    {
        eResult status = E_RESULT_ERROR;

        /* Disable the write protection for RTC registers */
        rtcDisableWriteProtection();

        /* Set Initialization mode */
        if (rtcEnterInitMode() != E_RESULT_ERROR)
        {
          /* Reset TR, DR and CR registers */
          WRITE_REG(rtcx_->TR, 0x00000000U);

          WRITE_REG(rtcx_->DR, (RTC_DR_WDU_0 | RTC_DR_MU_0 | RTC_DR_DU_0));

          /* Reset All CR bits except CR[2:0] */
          WRITE_REG(rtcx_->CR, (READ_REG(rtcx_->CR) & RTC_CR_WUCKSEL));

          WRITE_REG(rtcx_->WUTR,     RTC_WUTR_WUT);
          WRITE_REG(rtcx_->PRER, (RTC_PRER_PREDIV_A | RTC_SYNCH_PRESC_DEFAULT));
          WRITE_REG(rtcx_->ALRMAR,   0x00000000U);
          WRITE_REG(rtcx_->ALRMBR,   0x00000000U);
          WRITE_REG(rtcx_->SHIFTR,   0x00000000U);
          WRITE_REG(rtcx_->CALR,     0x00000000U);
          WRITE_REG(rtcx_->ALRMASSR, 0x00000000U);
          WRITE_REG(rtcx_->ALRMBSSR, 0x00000000U);

      #if defined(RTC_ICSR_ALRAWF)
          /* Reset ICSR register and exit initialization mode */
          WRITE_REG(rtcx_->ICSR,      0x00000000U);
      #endif /* RTC_ICSR_ALRAWF */
      #if defined(RTC_ISR_ALRAWF)
          /* Reset ISR register and exit initialization mode */
          WRITE_REG(rtcx_->ISR,      0x00000000U);
      #endif /* RTC_ISR_ALRAWF */

      #if defined(RTC_TAMPCR_TAMP1E)
          /* Reset Tamper and alternate functions configuration register */
          WRITE_REG(rtcx_->TAMPCR, 0x00000000U);
      #endif /* RTC_TAMPCR_TAMP1E */

      #if defined(RTC_OR_ALARMOUTTYPE)
          /* Reset Option register */
          WRITE_REG(rtcx_->OR, 0x00000000U);
      #endif /* RTC_OR_ALARMOUTTYPE */

          /* Wait till the RTC RSF flag is set */
          status = rtcWaitForSynchro();
        }

        /* Enable the write protection for RTC registers */
        rtcEnableWriteProtection();

      #if defined (TAMP_CR1_TAMP1E)
        /* DeInitialization of the TAMP */
        WRITE_REG(tampx_->CR1,      0xFFFF0000U);
        WRITE_REG(tampx_->FLTCR,    0x00000000U);
        WRITE_REG(tampx_->ATCR1,    0x00000000U);
        WRITE_REG(tampx_->IER,      0x00000000U);
        WRITE_REG(tampx_->SCR,      0xFFFFFFFFU);
      #endif /* TAMP_CR1_TAMP1E */
        return status;
    }

    eResult rtcInit(RTC_InitTypeDef *RTC_InitStruct)
    {
        eResult status = E_RESULT_ERROR;

        /* Disable the write protection for RTC registers */
        rtcDisableWriteProtection();

        /* Set Initialization mode */
        if (rtcEnterInitMode() != E_RESULT_ERROR)
        {
          /* Set Hour Format */
          rtcSetHourFormat(RTC_InitStruct->HourFormat);

          /* Configure Synchronous and Asynchronous prescaler factor */
          rtcSetSynchPrescaler(RTC_InitStruct->SynchPrescaler);
          rtcSetAsynchPrescaler(RTC_InitStruct->AsynchPrescaler);

          /* Exit Initialization mode */
          rtcDisableInitMode();

          status = E_RESULT_OK;
        }
        /* Enable the write protection for RTC registers */
        rtcEnableWriteProtection();

        return status;
    }
    eResult rtcTIMEInit(uint32_t RTC_Format, RTC_TimeTypeDef *RTC_TimeStruct)
    {
        eResult status = E_RESULT_ERROR;
        if (RTC_Format == RTC_FORMAT_BIN)
        {
          if (rtcGetHourFormat() != RTC_HOURFORMAT_24HOUR)
          {
            if(RTC_TimeStruct->Hours <= 0 || RTC_TimeStruct->Hours > 12)
            {
              return E_RESULT_INVALID_PARAM;
            }
          }
          else
          {
            RTC_TimeStruct->TimeFormat = RTC_TIME_FORMAT_AM_OR_24;
            if(RTC_TimeStruct->Hours >= 24)
            {
              return E_RESULT_INVALID_PARAM;
            }
          }
          if(RTC_TimeStruct->Minutes >= 60 || RTC_TimeStruct->Seconds >= 60)
          {
            return E_RESULT_INVALID_PARAM;
          }
        }
        else
        {
          if (rtcGetHourFormat() != RTC_HOURFORMAT_24HOUR)
          {
            if(rtcConvertBcd2Bin(RTC_TimeStruct->Hours) <= 0 || rtcConvertBcd2Bin(RTC_TimeStruct->Hours) > 12)
            {
              return E_RESULT_INVALID_PARAM;
            }
          }
          else
          {
            RTC_TimeStruct->TimeFormat = RTC_TIME_FORMAT_AM_OR_24;
            if(rtcConvertBcd2Bin(RTC_TimeStruct->Hours) >= 24)
            {
              return E_RESULT_INVALID_PARAM;
            }
          }
          if(rtcConvertBcd2Bin(RTC_TimeStruct->Minutes) >= 60 || rtcConvertBcd2Bin(RTC_TimeStruct->Seconds) >= 60)
          {
            return E_RESULT_INVALID_PARAM;
          }
        }
        /* Disable the write protection for RTC registers */
        rtcDisableWriteProtection();

        /* Set Initialization mode */
        if (rtcEnterInitMode() != E_RESULT_ERROR)
        {
          /* Check the input parameters format */
          if (RTC_Format != RTC_FORMAT_BIN)
          {
            rtcTIMEConfig((RTCTimeFormat)RTC_TimeStruct->TimeFormat, RTC_TimeStruct->Hours,
                              RTC_TimeStruct->Minutes, RTC_TimeStruct->Seconds);
          }
          else
          {
            rtcTIMEConfig((RTCTimeFormat)RTC_TimeStruct->TimeFormat, rtcConvertBin2Bcd(RTC_TimeStruct->Hours),
                              rtcConvertBin2Bcd(RTC_TimeStruct->Minutes),
                              rtcConvertBin2Bcd(RTC_TimeStruct->Seconds));
          }

          /* Exit Initialization mode */
          rtcDisableInitMode();

          /* If  RTC_CR_BYPSHAD bit = 0, wait for synchro else this check is not needed */
          if (!rtcIsShadowRegBypassEnabled())
          {
            status = rtcWaitForSynchro();
          }
          else
          {
            status = E_RESULT_OK;
          }
        }
        /* Enable the write protection for RTC registers */
        rtcEnableWriteProtection();
        return status;
    }
    eResult rtcDATEInit(uint32_t RTC_Format, RTC_DateTypeDef *RTC_DateStruct)
    {
        eResult status = E_RESULT_ERROR;

        if ((RTC_Format == RTC_FORMAT_BIN) && ((RTC_DateStruct->Month & 0x10U) == 0x10U))
        {
          RTC_DateStruct->Month = (RTCMonth)((RTC_DateStruct->Month & (uint8_t)~(0x10U)) + 0x0AU);
        }
        if (RTC_Format == RTC_FORMAT_BIN)
        {
          if(RTC_DateStruct->Year > 99)
          {
              return E_RESULT_INVALID_PARAM;
          }
          if(RTC_DateStruct->Month < 1 || RTC_DateStruct->Month > 12)
          {
            return E_RESULT_INVALID_PARAM;
          }
          if(RTC_DateStruct->Day < 1 || RTC_DateStruct->Day > 31)
          {
            return E_RESULT_INVALID_PARAM;
          }
        }
        else
        {
          if(rtcConvertBcd2Bin(RTC_DateStruct->Year) > 99)
          {
              return E_RESULT_INVALID_PARAM;
          }
          if(rtcConvertBcd2Bin(RTC_DateStruct->Month) < 1 || rtcConvertBcd2Bin(RTC_DateStruct->Month) > 12)
          {
            return E_RESULT_INVALID_PARAM;
          }
          if(rtcConvertBcd2Bin(RTC_DateStruct->Day) < 1 || rtcConvertBcd2Bin(RTC_DateStruct->Day) > 31)
          {
            return E_RESULT_INVALID_PARAM;
          }
        }

        /* Disable the write protection for RTC registers */
        rtcDisableWriteProtection();

        /* Set Initialization mode */
        if (rtcEnterInitMode() != E_RESULT_ERROR)
        {
          /* Check the input parameters format */
          if (RTC_Format != RTC_FORMAT_BIN)
          {
            rtcDATEConfig(RTC_DateStruct->WeekDay, RTC_DateStruct->Day, RTC_DateStruct->Month, RTC_DateStruct->Year);
          }
          else
          {
            rtcDATEConfig(RTC_DateStruct->WeekDay, rtcConvertBin2Bcd(RTC_DateStruct->Day),
                              rtcConvertBin2Bcd(RTC_DateStruct->Month), rtcConvertBin2Bcd(RTC_DateStruct->Year));
          }

          /* Exit Initialization mode */
          rtcDisableInitMode();

          /* If  RTC_CR_BYPSHAD bit = 0, wait for synchro else this check is not needed */
          if (!rtcIsShadowRegBypassEnabled())
          {
            status = rtcWaitForSynchro();
          }
          else
          {
            status = E_RESULT_OK;
          }
        }
        /* Enable the write protection for RTC registers */
        rtcEnableWriteProtection();

        return status;
    }
    eResult rtcALMAInit(uint32_t RTC_Format, RTC_AlarmTypeDef *RTC_AlarmStruct)
    {
        if (RTC_Format == RTC_FORMAT_BIN)
        {
          if (rtcGetHourFormat() != RTC_HOURFORMAT_24HOUR)
          {
            if(RTC_AlarmStruct->AlarmTime.Hours > 12 || RTC_AlarmStruct->AlarmTime.Hours <= 0)
            {
              return E_RESULT_INVALID_PARAM;
            }
          }
          else
          {
            RTC_AlarmStruct->AlarmTime.TimeFormat = RTC_ALMA_TIME_FORMAT_AM;
            if(RTC_AlarmStruct->AlarmTime.Hours > 23)
            {
              return E_RESULT_INVALID_PARAM;
            }
          }
          if(RTC_AlarmStruct->AlarmTime.Minutes >= 60 || RTC_AlarmStruct->AlarmTime.Seconds >= 60)
          {
            return E_RESULT_INVALID_PARAM;
          }

          if (RTC_AlarmStruct->AlarmDateWeekDaySel.A == RTC_ALMA_DATEWEEKDAYSEL_DATE)
          {
            if(RTC_AlarmStruct->AlarmDateWeekDay.day < 1 || RTC_AlarmStruct->AlarmDateWeekDay.day > 31)
            {
              return E_RESULT_INVALID_PARAM;
            }
          }
          else
          {
            if(RTC_AlarmStruct->AlarmDateWeekDay.week < RTC_WEEKDAY_MONDAY || RTC_AlarmStruct->AlarmDateWeekDay.week > RTC_WEEKDAY_SUNDAY)
            {
              return E_RESULT_INVALID_PARAM;
            }
          }
        }
        else
        {
          if (rtcGetHourFormat() != RTC_HOURFORMAT_24HOUR)
          {
            if(rtcConvertBcd2Bin(RTC_AlarmStruct->AlarmTime.Hours) > 12 || rtcConvertBcd2Bin(RTC_AlarmStruct->AlarmTime.Hours) <= 0)
            {
              return E_RESULT_INVALID_PARAM;
            }
          }
          else
          {
            RTC_AlarmStruct->AlarmTime.TimeFormat = RTC_ALMA_TIME_FORMAT_AM;
            if(rtcConvertBcd2Bin(RTC_AlarmStruct->AlarmTime.Hours) > 23)
            {
              return E_RESULT_INVALID_PARAM;
            }
          }
          if(rtcConvertBcd2Bin(RTC_AlarmStruct->AlarmTime.Minutes) >= 60 || rtcConvertBcd2Bin(RTC_AlarmStruct->AlarmTime.Seconds) >= 60)
          {
            return E_RESULT_INVALID_PARAM;
          }

          if (RTC_AlarmStruct->AlarmDateWeekDaySel.A == RTC_ALMA_DATEWEEKDAYSEL_DATE)
          {
            if(rtcConvertBcd2Bin(RTC_AlarmStruct->AlarmDateWeekDay.day) < 1 || rtcConvertBcd2Bin(RTC_AlarmStruct->AlarmDateWeekDay.day) > 31)
            {
              return E_RESULT_INVALID_PARAM;
            }
          }
          else
          {
            if(rtcConvertBcd2Bin(RTC_AlarmStruct->AlarmDateWeekDay.week) < RTC_WEEKDAY_MONDAY || rtcConvertBcd2Bin(RTC_AlarmStruct->AlarmDateWeekDay.week) > RTC_WEEKDAY_SUNDAY)
            {
              return E_RESULT_INVALID_PARAM;
            }
          }
        }

        /* Disable the write protection for RTC registers */
        rtcDisableWriteProtection();

        /* Select weekday selection */
        if (RTC_AlarmStruct->AlarmDateWeekDaySel.A == RTC_ALMA_DATEWEEKDAYSEL_DATE)
        {
          /* Set the date for ALARM */
          rtcALMADisableWeekday();
          if (RTC_Format != RTC_FORMAT_BIN)
          {
            rtcALMASetDay(RTC_AlarmStruct->AlarmDateWeekDay.day);
          }
          else
          {
            rtcALMASetDay(rtcConvertBin2Bcd(RTC_AlarmStruct->AlarmDateWeekDay.day));
          }
        }
        else
        {
          /* Set the week day for ALARM */
          rtcALMAEnableWeekday();
          rtcALMASetWeekDay(RTC_AlarmStruct->AlarmDateWeekDay.week);
        }

        /* Configure the Alarm register */
        if (RTC_Format != RTC_FORMAT_BIN)
        {
          rtcALMAConfigTime((RTCAlarmATimeFormat)RTC_AlarmStruct->AlarmTime.TimeFormat, RTC_AlarmStruct->AlarmTime.Hours,
                                RTC_AlarmStruct->AlarmTime.Minutes, RTC_AlarmStruct->AlarmTime.Seconds);
        }
        else
        {
          rtcALMAConfigTime((RTCAlarmATimeFormat)RTC_AlarmStruct->AlarmTime.TimeFormat,
                                rtcConvertBin2Bcd(RTC_AlarmStruct->AlarmTime.Hours),
                                rtcConvertBin2Bcd(RTC_AlarmStruct->AlarmTime.Minutes),
                                rtcConvertBin2Bcd(RTC_AlarmStruct->AlarmTime.Seconds));
        }
        /* Set ALARM mask */
        rtcALMASetMask(RTC_AlarmStruct->AlarmMask.A);

        /* Enable the write protection for RTC registers */
        rtcEnableWriteProtection();

        return E_RESULT_OK;
    }
  
    eResult rtcALMBInit(uint32_t RTC_Format, RTC_AlarmTypeDef *RTC_AlarmStruct)
    {
        if (RTC_Format == RTC_FORMAT_BIN)
        {
          if (rtcGetHourFormat() != RTC_HOURFORMAT_24HOUR)
          {
            if(RTC_AlarmStruct->AlarmTime.Hours > 12 || RTC_AlarmStruct->AlarmTime.Hours <= 0)
            {
              return E_RESULT_INVALID_PARAM;
            }
          }
          else
          {
            RTC_AlarmStruct->AlarmTime.TimeFormat = RTC_ALMB_TIME_FORMAT_AM;
            if(RTC_AlarmStruct->AlarmTime.Hours > 23)
            {
              return E_RESULT_INVALID_PARAM;
            }
          }
          if(RTC_AlarmStruct->AlarmTime.Minutes >= 60 || RTC_AlarmStruct->AlarmTime.Seconds >= 60)
          {
            return E_RESULT_INVALID_PARAM;
          }

          if (RTC_AlarmStruct->AlarmDateWeekDaySel.B == RTC_ALMB_DATEWEEKDAYSEL_DATE)
          {
            if(RTC_AlarmStruct->AlarmDateWeekDay.day < 1 || RTC_AlarmStruct->AlarmDateWeekDay.day > 31)
            {
              return E_RESULT_INVALID_PARAM;
            }
          }
          else
          {
            if(RTC_AlarmStruct->AlarmDateWeekDay.week < RTC_WEEKDAY_MONDAY || RTC_AlarmStruct->AlarmDateWeekDay.week > RTC_WEEKDAY_SUNDAY)
            {
              return E_RESULT_INVALID_PARAM;
            }
          }
        }
        else
        {
          if (rtcGetHourFormat() != RTC_HOURFORMAT_24HOUR)
          {
            if(rtcConvertBcd2Bin(RTC_AlarmStruct->AlarmTime.Hours) > 12 || rtcConvertBcd2Bin(RTC_AlarmStruct->AlarmTime.Hours) <= 0)
            {
              return E_RESULT_INVALID_PARAM;
            }
          }
          else
          {
            RTC_AlarmStruct->AlarmTime.TimeFormat = RTC_ALMB_TIME_FORMAT_AM;
            if(rtcConvertBcd2Bin(RTC_AlarmStruct->AlarmTime.Hours) > 23)
            {
              return E_RESULT_INVALID_PARAM;
            }
          }
          if(rtcConvertBcd2Bin(RTC_AlarmStruct->AlarmTime.Minutes) >= 60 || rtcConvertBcd2Bin(RTC_AlarmStruct->AlarmTime.Seconds) >= 60)
          {
            return E_RESULT_INVALID_PARAM;
          }

          if (RTC_AlarmStruct->AlarmDateWeekDaySel.B == RTC_ALMB_DATEWEEKDAYSEL_DATE)
          {
            if(rtcConvertBcd2Bin(RTC_AlarmStruct->AlarmDateWeekDay.day) < 1 || rtcConvertBcd2Bin(RTC_AlarmStruct->AlarmDateWeekDay.day) > 31)
            {
              return E_RESULT_INVALID_PARAM;
            }
          }
          else
          {
            if(rtcConvertBcd2Bin(RTC_AlarmStruct->AlarmDateWeekDay.week) < RTC_WEEKDAY_MONDAY || rtcConvertBcd2Bin(RTC_AlarmStruct->AlarmDateWeekDay.week) > RTC_WEEKDAY_SUNDAY)
            {
              return E_RESULT_INVALID_PARAM;
            }
          }
        }

        /* Disable the write protection for RTC registers */
        rtcDisableWriteProtection();

        /* Select weekday selection */
        if (RTC_AlarmStruct->AlarmDateWeekDaySel.B == RTC_ALMB_DATEWEEKDAYSEL_DATE)
        {
          /* Set the date for ALARM */
          rtcALMBDisableWeekday();
          if (RTC_Format != RTC_FORMAT_BIN)
          {
            rtcALMBSetDay(RTC_AlarmStruct->AlarmDateWeekDay.day);
          }
          else
          {
            rtcALMBSetDay(rtcConvertBin2Bcd(RTC_AlarmStruct->AlarmDateWeekDay.day));
          }
        }
        else
        {
          /* Set the week day for ALARM */
          rtcALMBEnableWeekday();
          rtcALMBSetWeekDay(RTC_AlarmStruct->AlarmDateWeekDay.week);
        }

        /* Configure the Alarm register */
        if (RTC_Format != RTC_FORMAT_BIN)
        {
          rtcALMBConfigTime((RTCAlarmBTimeFormat)RTC_AlarmStruct->AlarmTime.TimeFormat, RTC_AlarmStruct->AlarmTime.Hours,
                                RTC_AlarmStruct->AlarmTime.Minutes, RTC_AlarmStruct->AlarmTime.Seconds);
        }
        else
        {
          rtcALMBConfigTime((RTCAlarmBTimeFormat)RTC_AlarmStruct->AlarmTime.TimeFormat,
                                rtcConvertBin2Bcd(RTC_AlarmStruct->AlarmTime.Hours),
                                rtcConvertBin2Bcd(RTC_AlarmStruct->AlarmTime.Minutes),
                                rtcConvertBin2Bcd(RTC_AlarmStruct->AlarmTime.Seconds));
        }
        /* Set ALARM mask */
        rtcALMBSetMask(RTC_AlarmStruct->AlarmMask.B);

        /* Enable the write protection for RTC registers */
        rtcEnableWriteProtection();

        return E_RESULT_OK;
    }
    eResult rtcEnterInitMode()
    {
        __IO uint32_t timeout = RTC_INITMODE_TIMEOUT;
        eResult status = E_RESULT_OK;
        bool tmp;

        /* Check if the Initialization mode is set */
        if (!rtcIsActiveFlagINIT())
        {
          /* Set the Initialization mode */
          rtcEnableInitMode();

          /* Wait till RTC is in INIT state and if Time out is reached exit */
          tmp = rtcIsActiveFlagINIT();
          while ((timeout != 0U) && (!tmp))
          {
            if (CORTEX::getInstance()->systickIsActiveCounterFlag())
            {
              timeout --;
            }
            tmp = rtcIsActiveFlagINIT();
            if (timeout == 0U)
            {
              status = E_RESULT_ERROR;
            }
          }
        }
        return status;
    }
    eResult rtcExitInitMode()
    {
        /* Disable initialization mode */
        rtcDisableInitMode();

        return E_RESULT_OK;
    }
    eResult rtcWaitForSynchro()
    {
        __IO uint32_t timeout = RTC_SYNCHRO_TIMEOUT;
        eResult status = E_RESULT_OK;
        bool tmp;

        /* Clear RSF flag */
        rtcClearFlagRS();

        /* Wait the registers to be synchronised */
        tmp = rtcIsActiveFlagRS();
        while ((timeout != 0U) && (tmp))
        {
          if (CORTEX::getInstance()->systickIsActiveCounterFlag())
          {
            timeout--;
          }
          tmp = rtcIsActiveFlagRS();
          if (timeout == 0U)
          {
            status = E_RESULT_ERROR;
          }
        }

        if (status != E_RESULT_ERROR)
        {
          timeout = RTC_SYNCHRO_TIMEOUT;
          tmp = rtcIsActiveFlagRS();
          while ((timeout != 0U) && (!tmp))
          {
            if (CORTEX::getInstance()->systickIsActiveCounterFlag())
            {
              timeout--;
            }
            tmp = rtcIsActiveFlagRS();
            if (timeout == 0U)
            {
              status = E_RESULT_ERROR;
            }
          }
        }

        return (status);
    }

private:
    inline uint32_t rtcDateGet()
    {
      uint32_t temp;

      temp = READ_BIT(rtcx_->DR, (RTC_DR_WDU | RTC_DR_MT | RTC_DR_MU | RTC_DR_DT | RTC_DR_DU | RTC_DR_YT | RTC_DR_YU));
      return (uint32_t)((((temp & RTC_DR_WDU) >> RTC_DR_WDU_Pos) << RTC_OFFSET_WEEKDAY) | \
                        (((((temp & RTC_DR_DT) >> RTC_DR_DT_Pos) << 4U) | ((temp & RTC_DR_DU) >> RTC_DR_DU_Pos)) << RTC_OFFSET_DAY)   | \
                        (((((temp & RTC_DR_MT) >> RTC_DR_MT_Pos) << 4U) | ((temp & RTC_DR_MU) >> RTC_DR_MU_Pos)) << RTC_OFFSET_MONTH) | \
                        ((((temp & RTC_DR_YT) >> RTC_DR_YT_Pos) << 4U) | ((temp & RTC_DR_YU) >> RTC_DR_YU_Pos)));
    }
    uint8_t rtcConvertBin2Bcd(uint8_t val)
    {
        return (uint8_t)((((val) / 10U) << 4U) | ((val) % 10U));
    }
    uint8_t rtcConvertBcd2Bin(uint8_t val)
    {
        return ((uint8_t)((((uint8_t)((val) & (uint8_t)0xF0) >> (uint8_t)0x4) * 10U) + ((val) & (uint8_t)0x0F)));
    }
    RTCWeekDay rtcGetWeekDay()
    {
        return (RTCWeekDay)((((rtcDateGet()) >> RTC_OFFSET_WEEKDAY) & 0x000000FFU));
    }
    uint8_t rtcGetYear()
    {
        return ((rtcDateGet()) & 0x000000FFU);
    }
    RTCMonth rtcGetMonth()
    {
        return (RTCMonth)(((rtcDateGet()) >>RTC_OFFSET_MONTH) & 0x000000FFU);
    }
    uint8_t rtcGetDay()
    {
        return (((rtcDateGet()) >>RTC_OFFSET_DAY) & 0x000000FFU);
    }
    uint8_t rtcGetHour()
    {
        return (((rtcDateGet()) >> RTC_OFFSET_HOUR) & 0x000000FFU);
    }
    uint8_t rtcGetMinute()
    {
        return (((rtcDateGet()) >> RTC_OFFSET_MINUTE) & 0x000000FFU);
    }
    uint8_t rtcGetSecond()
    {
        return ((rtcDateGet()) & 0x000000FFU);
    }
private:
    RTC_TypeDef *rtcx_;
 #if defined (TAMP)
    TAMP_TypeDef *tampx_;
 #endif
};