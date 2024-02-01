#pragma once
#include "common.hpp"
/* Exported constants --------------------------------------------------------*/
/** @defgroup EXTI_LL_Exported_Constants EXTI Exported Constants
  * @{
  */

/** @defgroup EXTI_LL_EC_LINE LINE
  * @{
  */
enum EXTILinex_0_31
{
    EXTI_LINE_0          =      EXTI_IMR1_IM0,           /*!< Extended line 0 */
    EXTI_LINE_1          =      EXTI_IMR1_IM1,           /*!< Extended line 1 */
    EXTI_LINE_2          =      EXTI_IMR1_IM2,           /*!< Extended line 2 */
    EXTI_LINE_3          =      EXTI_IMR1_IM3,           /*!< Extended line 3 */
    EXTI_LINE_4          =      EXTI_IMR1_IM4,           /*!< Extended line 4 */
    EXTI_LINE_5          =      EXTI_IMR1_IM5,           /*!< Extended line 5 */
    EXTI_LINE_6          =      EXTI_IMR1_IM6,           /*!< Extended line 6 */
    EXTI_LINE_7          =      EXTI_IMR1_IM7,           /*!< Extended line 7 */
    EXTI_LINE_8          =      EXTI_IMR1_IM8,           /*!< Extended line 8 */
    EXTI_LINE_9          =      EXTI_IMR1_IM9,           /*!< Extended line 9 */
    EXTI_LINE_10         =      EXTI_IMR1_IM10,          /*!< Extended line 10 */
    EXTI_LINE_11         =      EXTI_IMR1_IM11,          /*!< Extended line 11 */
    EXTI_LINE_12         =      EXTI_IMR1_IM12,          /*!< Extended line 12 */
    EXTI_LINE_13         =      EXTI_IMR1_IM13,          /*!< Extended line 13 */
    EXTI_LINE_14         =      EXTI_IMR1_IM14,          /*!< Extended line 14 */
    EXTI_LINE_15         =      EXTI_IMR1_IM15,          /*!< Extended line 15 */
    EXTI_LINE_16         =      EXTI_IMR1_IM16,          /*!< Extended line 16 */
    EXTI_LINE_17         =      EXTI_IMR1_IM17,          /*!< Extended line 17 */
    EXTI_LINE_18         =      EXTI_IMR1_IM18,          /*!< Extended line 18 */
    EXTI_LINE_19         =      EXTI_IMR1_IM19,          /*!< Extended line 19 */
    EXTI_LINE_20         =      EXTI_IMR1_IM20,          /*!< Extended line 20 */
    EXTI_LINE_21         =      EXTI_IMR1_IM21,          /*!< Extended line 21 */
    EXTI_LINE_22         =      EXTI_IMR1_IM22,          /*!< Extended line 22 */
    EXTI_LINE_23         =      EXTI_IMR1_IM23,          /*!< Extended line 23 */
    EXTI_LINE_24         =      EXTI_IMR1_IM24,          /*!< Extended line 24 */
    EXTI_LINE_25         =      EXTI_IMR1_IM25,          /*!< Extended line 25 */
    EXTI_LINE_26         =      EXTI_IMR1_IM26,          /*!< Extended line 26 */
    EXTI_LINE_27         =      EXTI_IMR1_IM27,          /*!< Extended line 27 */
    EXTI_LINE_28         =      EXTI_IMR1_IM28,          /*!< Extended line 28 */
    EXTI_LINE_29         =      EXTI_IMR1_IM29,          /*!< Extended line 29 */
    EXTI_LINE_30         =      EXTI_IMR1_IM30,          /*!< Extended line 30 */
    EXTI_LINE_31         =      EXTI_IMR1_IM31,          /*!< Extended line 31 */
    EXTI_LINE_ALL_0_31   =      EXTI_IMR1_IM  ,          /*!< All Extended line not reserved*/
    EXTI_LINE_NONE_0_31       =       (0x00000000U),  /*!< None Extended line */
};
enum EXTILinex_32_63
{
    EXTI_LINE_32         =      EXTI_IMR2_IM32,          /*!< Extended line 32 */
    EXTI_LINE_33         =      EXTI_IMR2_IM33,          /*!< Extended line 33 */
    EXTI_LINE_34         =      EXTI_IMR2_IM34,          /*!< Extended line 34 */
    EXTI_LINE_35         =      EXTI_IMR2_IM35,          /*!< Extended line 35 */
    EXTI_LINE_36         =      EXTI_IMR2_IM36,          /*!< Extended line 36 */
    EXTI_LINE_37         =      EXTI_IMR2_IM37,          /*!< Extended line 37 */
    EXTI_LINE_38         =      EXTI_IMR2_IM38,          /*!< Extended line 38 */
    EXTI_LINE_39         =      EXTI_IMR2_IM39,          /*!< Extended line 39 */
    EXTI_LINE_40         =      EXTI_IMR2_IM40,          /*!< Extended line 40 */
    EXTI_LINE_41         =      EXTI_IMR2_IM41,          /*!< Extended line 41 */
    EXTI_LINE_42         =      EXTI_IMR2_IM42,          /*!< Extended line 42 */
    EXTI_LINE_43         =      EXTI_IMR2_IM43,          /*!< Extended line 43 */
    #if defined(USB2_OTG_FS)
    EXTI_LINE_44         =      EXTI_IMR2_IM44,          /*!< Extended line 44 */
    #endif /* USB2_OTG_FS */
    #if defined(DSI)
    EXTI_LINE_46         =      EXTI_IMR2_IM46,          /*!< Extended line 46 */
    #endif /* DSI */
    EXTI_LINE_47         =      EXTI_IMR2_IM47,          /*!< Extended line 47 */
    EXTI_LINE_48         =      EXTI_IMR2_IM48,          /*!< Extended line 48 */
    EXTI_LINE_49         =      EXTI_IMR2_IM49,          /*!< Extended line 49 */
    EXTI_LINE_50         =      EXTI_IMR2_IM50,          /*!< Extended line 50 */
    EXTI_LINE_51         =      EXTI_IMR2_IM51,          /*!< Extended line 51 */
    EXTI_LINE_52         =      EXTI_IMR2_IM52,          /*!< Extended line 52 */
    EXTI_LINE_53         =      EXTI_IMR2_IM53,          /*!< Extended line 53 */
    EXTI_LINE_54         =      EXTI_IMR2_IM54,          /*!< Extended line 54 */
    EXTI_LINE_55         =      EXTI_IMR2_IM55,          /*!< Extended line 55 */
    EXTI_LINE_56         =      EXTI_IMR2_IM56,          /*!< Extended line 56 */
    #if defined(EXTI_IMR2_IM57)
    EXTI_LINE_57         =       EXTI_IMR2_IM57,          /*!< Extended line 57 */
    #endif /*EXTI_IMR2_IM57*/
    EXTI_LINE_58         =       EXTI_IMR2_IM58,          /*!< Extended line 58 */
    #if defined(EXTI_IMR2_IM59)
    EXTI_LINE_59         =       EXTI_IMR2_IM59,          /*!< Extended line 59 */
    #endif /*EXTI_IMR2_IM59*/
    EXTI_LINE_60         =       EXTI_IMR2_IM60,          /*!< Extended line 60 */
    EXTI_LINE_61         =       EXTI_IMR2_IM61,          /*!< Extended line 61 */
    EXTI_LINE_62         =       EXTI_IMR2_IM62,          /*!< Extended line 62 */
    EXTI_LINE_63         =       EXTI_IMR2_IM63,          /*!< Extended line 63 */
    EXTI_LINE_ALL_32_63  =       EXTI_IMR2_IM,            /*!< All Extended line not reserved*/
    EXTI_LINE_NONE_32_63       =       (0x00000000U),  /*!< None Extended line */
};
enum EXTILinex_64_95
{
    EXTI_LINE_64         =       EXTI_IMR3_IM64,          /*!< Extended line 64 */
    EXTI_LINE_65         =       EXTI_IMR3_IM65,          /*!< Extended line 65 */
    EXTI_LINE_66         =       EXTI_IMR3_IM66,          /*!< Extended line 66 */
    EXTI_LINE_67         =       EXTI_IMR3_IM67,          /*!< Extended line 67 */
    EXTI_LINE_68         =       EXTI_IMR3_IM68,          /*!< Extended line 68 */
    EXTI_LINE_69         =       EXTI_IMR3_IM69,          /*!< Extended line 69 */
    EXTI_LINE_70         =       EXTI_IMR3_IM70,          /*!< Extended line 70 */
    EXTI_LINE_71         =       EXTI_IMR3_IM71,          /*!< Extended line 71 */
    EXTI_LINE_72         =       EXTI_IMR3_IM72,          /*!< Extended line 72 */
    EXTI_LINE_73         =       EXTI_IMR3_IM73,          /*!< Extended line 73 */
    EXTI_LINE_74         =       EXTI_IMR3_IM74,          /*!< Extended line 74 */
    #if defined(ADC3)
    EXTI_LINE_75         =       EXTI_IMR3_IM75,          /*!< Extended line 75 */
    #endif /* ADC3 */
    #if defined(SAI4)
    EXTI_LINE_76         =       EXTI_IMR3_IM76,          /*!< Extended line 76 */
    #endif /* SAI4 */
    #if defined(DUAL_CORE)
    EXTI_LINE_77         =       EXTI_IMR3_IM77,          /*!< Extended line 77 */
    EXTI_LINE_78         =       EXTI_IMR3_IM78,          /*!< Extended line 78 */
    EXTI_LINE_79         =       EXTI_IMR3_IM79,          /*!< Extended line 79 */
    EXTI_LINE_80         =       EXTI_IMR3_IM80,          /*!< Extended line 80 */
    EXTI_LINE_82         =       EXTI_IMR3_IM82,          /*!< Extended line 82 */
    EXTI_LINE_84         =       EXTI_IMR3_IM84,          /*!< Extended line 84 */
    #endif /* DUAL_CORE */
    EXTI_LINE_85         =       EXTI_IMR3_IM85,          /*!< Extended line 85 */
    #if defined(ETH)
    EXTI_LINE_86         =       EXTI_IMR3_IM86,          /*!< Extended line 86 */
    #endif /* ETH */
    EXTI_LINE_87         =       EXTI_IMR3_IM87,          /*!< Extended line 87 */
    #if defined(DTS)
    EXTI_LINE_88         =       EXTI_IMR3_IM88,          /*!< Extended line 88 */
    #endif /* DTS */
    #if defined(EXTI_IMR3_IM89)
    EXTI_LINE_89         =       EXTI_IMR3_IM89,          /*!< Extended line 89 */
    #endif /* EXTI_IMR3_IM89 */
    #if defined(EXTI_IMR3_IM90)
    EXTI_LINE_90         =       EXTI_IMR3_IM90,          /*!< Extended line 90 */
    #endif /* EXTI_IMR3_IM90 */
    #if defined(I2C5)
    EXTI_LINE_91         =       EXTI_IMR3_IM91,          /*!< Extended line 91 */
    #endif /* I2C5 */
    EXTI_LINE_ALL_64_95  =       EXTI_IMR3_IM,            /*!< All Extended line not reserved*/
    EXTI_LINE_NONE_64_95       =       (0x00000000U),  /*!< None Extended line */
};

/** @defgroup EXTI_LL_EC_MODE Mode
  * @{
  */
enum EXTIMode
{
    EXTI_MODE_IT           =    ((uint8_t)0x01U),      /*!< Cortex-M7 Interrupt Mode  */
    EXTI_MODE_EVENT        =    ((uint8_t)0x02U),      /*!< Cortex-M7 Event Mode */
    EXTI_MODE_IT_EVENT     =    ((uint8_t)0x03U),      /*!< Cortex-M7 Interrupt & Event Mode */

#if defined(DUAL_CORE)
    EXTI_MODE_C1_IT        =    EXTI_MODE_IT,          /*!< Cortex-M7 Interrupt Mode */
    EXTI_MODE_C1_EVENT     =    EXTI_MODE_EVENT,       /*!< Cortex-M7 Event Mode */
    EXTI_MODE_C1_IT_EVENT  =    EXTI_MODE_IT_EVENT,    /*!< Cortex-M7 Interrupt & Event Mode */  
    EXTI_MODE_C2_IT        =    ((uint8_t)0x10U),      /*!< Cortex-M4 Interrupt Mode  */
    EXTI_MODE_C2_EVENT     =    ((uint8_t)0x20U),      /*!< Cortex-M4 Event Mode  */
    EXTI_MODE_C2_IT_EVENT  =    ((uint8_t)0x30U),      /*!< Cortex-M4 Interrupt & Event Mode */
#endif /* DUAL_CORE */
};

/** @defgroup EXTI_LL_EC_TRIGGER Edge Trigger
  * @{
  */
enum EXTITrigger
{
    EXTI_TRIGGER_NONE             =   ((uint8_t)0x00U), /*!< No Trigger Mode */
    EXTI_TRIGGER_RISING           =   ((uint8_t)0x01U), /*!< Trigger Rising Mode */
    EXTI_TRIGGER_FALLING          =   ((uint8_t)0x02U), /*!< Trigger Falling Mode */
    EXTI_TRIGGER_RISING_FALLING   =   ((uint8_t)0x03U), /*!< Trigger Rising & Falling Mode */
};

/** @defgroup EXTI_LL_D3_PEND_CLR D3 Pend Clear Source
  * @{
  */
enum EXTID3PendClr
{
    EXTI_D3_PEND_CLR_DMACH6   =  ((uint8_t)0x00U), /*!< DMA ch6 event selected as D3 domain pendclear source */
    EXTI_D3_PEND_CLR_DMACH7   =  ((uint8_t)0x01U), /*!< DMA ch7 event selected as D3 domain pendclear source */
    #if defined (LPTIM4)
    EXTI_D3_PEND_CLR_LPTIM4   =  ((uint8_t)0x02U), /*!< LPTIM4 out selected as D3 domain pendclear source */
    #else
    EXTI_D3_PEND_CLR_LPTIM2   =  ((uint8_t)0x02U), /*!< LPTIM2 out selected as D3 domain pendclear source */
    #endif /*LPTIM4*/
    #if defined (LPTIM5)
    EXTI_D3_PEND_CLR_LPTIM5   =  ((uint8_t)0x03U), /*!< LPTIM5 out selected as D3 domain pendclear source */
    #else
    EXTI_D3_PEND_CLR_LPTIM3   =  ((uint8_t)0x02U), /*!< LPTIM3 out selected as D3 domain pendclear source */
    #endif /*LPTIM5*/
};

class EXTIx
{
public:
    static EXTIx* getInstance()
    {
        static EXTIx extix;
        return &extix;
    }
    /**
     * @brief  Enable ExtiLine Interrupt request for Lines in range 0 to 31
     * @rmtoll IMR1         IMx           EXTI_EnableIT_0_31
     * @param  ExtiLine This parameter can be one of the following values:
     *         @arg @ref EXTI_LINE_0
     *         @arg @ref EXTI_LINE_1
     *         @arg @ref EXTI_LINE_2
     *         @arg @ref EXTI_LINE_3
     *         @arg @ref EXTI_LINE_4
     *         @arg @ref EXTI_LINE_5
     *         @arg @ref EXTI_LINE_6
     *         @arg @ref EXTI_LINE_7
     *         @arg @ref EXTI_LINE_8
     *         @arg @ref EXTI_LINE_9
     *         @arg @ref EXTI_LINE_10
     *         @arg @ref EXTI_LINE_11
     *         @arg @ref EXTI_LINE_12
     *         @arg @ref EXTI_LINE_13
     *         @arg @ref EXTI_LINE_14
     *         @arg @ref EXTI_LINE_15
     *         @arg @ref EXTI_LINE_16
     *         @arg @ref EXTI_LINE_17
     *         @arg @ref EXTI_LINE_18
     *         @arg @ref EXTI_LINE_19
     *         @arg @ref EXTI_LINE_20
     *         @arg @ref EXTI_LINE_21
     *         @arg @ref EXTI_LINE_22
     *         @arg @ref EXTI_LINE_23
     *         @arg @ref EXTI_LINE_24
     *         @arg @ref EXTI_LINE_25
     *         @arg @ref EXTI_LINE_26
     *         @arg @ref EXTI_LINE_27
     *         @arg @ref EXTI_LINE_28
     *         @arg @ref EXTI_LINE_29
     *         @arg @ref EXTI_LINE_30
     *         @arg @ref EXTI_LINE_31
     *         @arg @ref EXTI_LINE_ALL_0_31
     * @retval None
     */
    inline void extiEnableIT_0_31(EXTILinex_0_31 ExtiLine)
    {
        SET_BIT(EXTI->IMR1, ExtiLine);
    }

    /**
     * @brief  Enable ExtiLine Interrupt request for Lines in range 32 to 63
     * @rmtoll IMR2         IMx           EXTI_EnableIT_32_63
     * @param  ExtiLine This parameter can be one of the following values:
     *         @arg @ref EXTI_LINE_32
     *         @arg @ref EXTI_LINE_33
     *         @arg @ref EXTI_LINE_34
     *         @arg @ref EXTI_LINE_35
     *         @arg @ref EXTI_LINE_36
     *         @arg @ref EXTI_LINE_37
     *         @arg @ref EXTI_LINE_38
     *         @arg @ref EXTI_LINE_39
     *         @arg @ref EXTI_LINE_40
     *         @arg @ref EXTI_LINE_41
     *         @arg @ref EXTI_LINE_42
     *         @arg @ref EXTI_LINE_43
     *         @arg @ref EXTI_LINE_44 (*)
     *         @arg @ref EXTI_LINE_46 (*)
     *         @arg @ref EXTI_LINE_47
     *         @arg @ref EXTI_LINE_48
     *         @arg @ref EXTI_LINE_49
     *         @arg @ref EXTI_LINE_50
     *         @arg @ref EXTI_LINE_51
     *         @arg @ref EXTI_LINE_52
     *         @arg @ref EXTI_LINE_53
     *         @arg @ref EXTI_LINE_54
     *         @arg @ref EXTI_LINE_55
     *         @arg @ref EXTI_LINE_56
     *         @arg @ref EXTI_LINE_57 (*)
     *         @arg @ref EXTI_LINE_58
     *         @arg @ref EXTI_LINE_59 (*)
     *         @arg @ref EXTI_LINE_60
     *         @arg @ref EXTI_LINE_61
     *         @arg @ref EXTI_LINE_62
     *         @arg @ref EXTI_LINE_63
     *         @arg @ref EXTI_LINE_ALL_32_63
     *
     *         (*) value not defined in all devices.
     * @retval None
     */
    inline void extiEnableIT_32_63(EXTILinex_32_63 ExtiLine)
    {
    SET_BIT(EXTI->IMR2, ExtiLine);
    }


    /**
     * @brief  Enable ExtiLine Interrupt request for Lines in range 64 to 95
     * @rmtoll IMR3         IMx           EXTI_EnableIT_64_95
     * @param  ExtiLine This parameter can be one of the following values:
     *         @arg @ref EXTI_LINE_64
     *         @arg @ref EXTI_LINE_65
     *         @arg @ref EXTI_LINE_66
     *         @arg @ref EXTI_LINE_67
     *         @arg @ref EXTI_LINE_68
     *         @arg @ref EXTI_LINE_69
     *         @arg @ref EXTI_LINE_70
     *         @arg @ref EXTI_LINE_71
     *         @arg @ref EXTI_LINE_72
     *         @arg @ref EXTI_LINE_73
     *         @arg @ref EXTI_LINE_74
     *         @arg @ref EXTI_LINE_75 (*)
     *         @arg @ref EXTI_LINE_76 (*)
     *         @arg @ref EXTI_LINE_77 (**)
     *         @arg @ref EXTI_LINE_78 (**)
     *         @arg @ref EXTI_LINE_79 (**)
     *         @arg @ref EXTI_LINE_80 (**)
     *         @arg @ref EXTI_LINE_82 (**)
     *         @arg @ref EXTI_LINE_84 (**)
     *         @arg @ref EXTI_LINE_85
     *         @arg @ref EXTI_LINE_86 (*)
     *         @arg @ref EXTI_LINE_87
     *         @arg @ref EXTI_LINE_88 (*)
     *         @arg @ref EXTI_LINE_89 (*) 
     *         @arg @ref EXTI_LINE_90 (*)
     *         @arg @ref EXTI_LINE_91 (*)
     *         @arg @ref EXTI_LINE_ALL_64_95
     *
     *         (*) value not defined in all devices.
     *         (**) value only defined in dual core devices.
     * @retval None
     */
    inline void extiEnableIT_64_95(EXTILinex_64_95 ExtiLine)
    {
        SET_BIT(EXTI->IMR3, ExtiLine);
    }


    /**
     * @brief  Disable ExtiLine Interrupt request for Lines in range 0 to 31
     * @rmtoll IMR1         IMx           EXTI_DisableIT_0_31
     * @param  ExtiLine This parameter can be one of the following values:
     *         @arg @ref EXTI_LINE_0
     *         @arg @ref EXTI_LINE_1
     *         @arg @ref EXTI_LINE_2
     *         @arg @ref EXTI_LINE_3
     *         @arg @ref EXTI_LINE_4
     *         @arg @ref EXTI_LINE_5
     *         @arg @ref EXTI_LINE_6
     *         @arg @ref EXTI_LINE_7
     *         @arg @ref EXTI_LINE_8
     *         @arg @ref EXTI_LINE_9
     *         @arg @ref EXTI_LINE_10
     *         @arg @ref EXTI_LINE_11
     *         @arg @ref EXTI_LINE_12
     *         @arg @ref EXTI_LINE_13
     *         @arg @ref EXTI_LINE_14
     *         @arg @ref EXTI_LINE_15
     *         @arg @ref EXTI_LINE_16
     *         @arg @ref EXTI_LINE_17
     *         @arg @ref EXTI_LINE_18
     *         @arg @ref EXTI_LINE_19
     *         @arg @ref EXTI_LINE_20
     *         @arg @ref EXTI_LINE_21
     *         @arg @ref EXTI_LINE_22
     *         @arg @ref EXTI_LINE_23
     *         @arg @ref EXTI_LINE_24
     *         @arg @ref EXTI_LINE_25
     *         @arg @ref EXTI_LINE_26
     *         @arg @ref EXTI_LINE_27
     *         @arg @ref EXTI_LINE_28
     *         @arg @ref EXTI_LINE_29
     *         @arg @ref EXTI_LINE_30
     *         @arg @ref EXTI_LINE_31
     *         @arg @ref EXTI_LINE_ALL_0_31
     * @retval None
     */
    inline void extiDisableIT_0_31(EXTILinex_0_31 ExtiLine)
    {
        CLEAR_BIT(EXTI->IMR1, ExtiLine);
    }


    /**
     * @brief  Disable ExtiLine Interrupt request for Lines in range 32 to 63
     * @rmtoll IMR2         IMx           EXTI_DisableIT_32_63
     * @param  ExtiLine This parameter can be one of the following values:
     *         @arg @ref EXTI_LINE_32
     *         @arg @ref EXTI_LINE_33
     *         @arg @ref EXTI_LINE_34
     *         @arg @ref EXTI_LINE_35
     *         @arg @ref EXTI_LINE_36
     *         @arg @ref EXTI_LINE_37
     *         @arg @ref EXTI_LINE_38
     *         @arg @ref EXTI_LINE_39
     *         @arg @ref EXTI_LINE_40
     *         @arg @ref EXTI_LINE_41
     *         @arg @ref EXTI_LINE_42
     *         @arg @ref EXTI_LINE_43
     *         @arg @ref EXTI_LINE_44 (*)
     *         @arg @ref EXTI_LINE_46 (*)
     *         @arg @ref EXTI_LINE_47
     *         @arg @ref EXTI_LINE_48
     *         @arg @ref EXTI_LINE_49
     *         @arg @ref EXTI_LINE_50
     *         @arg @ref EXTI_LINE_51
     *         @arg @ref EXTI_LINE_52
     *         @arg @ref EXTI_LINE_53
     *         @arg @ref EXTI_LINE_54
     *         @arg @ref EXTI_LINE_55
     *         @arg @ref EXTI_LINE_56
     *         @arg @ref EXTI_LINE_57 (*)
     *         @arg @ref EXTI_LINE_58
     *         @arg @ref EXTI_LINE_59 (*)
     *         @arg @ref EXTI_LINE_60
     *         @arg @ref EXTI_LINE_61
     *         @arg @ref EXTI_LINE_62
     *         @arg @ref EXTI_LINE_63
     *         @arg @ref EXTI_LINE_ALL_32_63
     *
     *         (*) value not defined in all devices.
     * @retval None
     */
    inline void extiDisableIT_32_63(EXTILinex_32_63 ExtiLine)
    {
        CLEAR_BIT(EXTI->IMR2, ExtiLine);
    }

    /**
     * @brief  Disable ExtiLine Interrupt request for Lines in range 64 to 95
     * @rmtoll IMR3         IMx           EXTI_DisableIT_64_95
     * @param  ExtiLine This parameter can be one of the following values:
     *         @arg @ref EXTI_LINE_64
     *         @arg @ref EXTI_LINE_65
     *         @arg @ref EXTI_LINE_66
     *         @arg @ref EXTI_LINE_67
     *         @arg @ref EXTI_LINE_68
     *         @arg @ref EXTI_LINE_69
     *         @arg @ref EXTI_LINE_70
     *         @arg @ref EXTI_LINE_71
     *         @arg @ref EXTI_LINE_72
     *         @arg @ref EXTI_LINE_73
     *         @arg @ref EXTI_LINE_74
     *         @arg @ref EXTI_LINE_75 (*)
     *         @arg @ref EXTI_LINE_76 (*)
     *         @arg @ref EXTI_LINE_77 (**)
     *         @arg @ref EXTI_LINE_78 (**)
     *         @arg @ref EXTI_LINE_79 (**)
     *         @arg @ref EXTI_LINE_80 (**)
     *         @arg @ref EXTI_LINE_82 (**)
     *         @arg @ref EXTI_LINE_84 (**)
     *         @arg @ref EXTI_LINE_85
     *         @arg @ref EXTI_LINE_86 (*)
     *         @arg @ref EXTI_LINE_87
     *         @arg @ref EXTI_LINE_88 (*)
     *         @arg @ref EXTI_LINE_89 (*) 
     *         @arg @ref EXTI_LINE_90 (*)
     *         @arg @ref EXTI_LINE_91 (*)
     *         @arg @ref EXTI_LINE_ALL_64_95
     *
     *         (*) value not defined in all devices.
     *         (**) value only defined in dual core devices.
     * @retval None
     */
    inline void extiDisableIT_64_95(EXTILinex_64_95 ExtiLine)
    {
        CLEAR_BIT(EXTI->IMR3, ExtiLine);
    }


    /**
     * @brief  Indicate if ExtiLine Interrupt request is enabled for Lines in range 0 to 31
     * @rmtoll IMR1         IMx           extiIsEnabledIT_0_31
     * @param  ExtiLine This parameter can be one of the following values:
     *         @arg @ref EXTI_LINE_0
     *         @arg @ref EXTI_LINE_1
     *         @arg @ref EXTI_LINE_2
     *         @arg @ref EXTI_LINE_3
     *         @arg @ref EXTI_LINE_4
     *         @arg @ref EXTI_LINE_5
     *         @arg @ref EXTI_LINE_6
     *         @arg @ref EXTI_LINE_7
     *         @arg @ref EXTI_LINE_8
     *         @arg @ref EXTI_LINE_9
     *         @arg @ref EXTI_LINE_10
     *         @arg @ref EXTI_LINE_11
     *         @arg @ref EXTI_LINE_12
     *         @arg @ref EXTI_LINE_13
     *         @arg @ref EXTI_LINE_14
     *         @arg @ref EXTI_LINE_15
     *         @arg @ref EXTI_LINE_16
     *         @arg @ref EXTI_LINE_17
     *         @arg @ref EXTI_LINE_18
     *         @arg @ref EXTI_LINE_19
     *         @arg @ref EXTI_LINE_20
     *         @arg @ref EXTI_LINE_21
     *         @arg @ref EXTI_LINE_22
     *         @arg @ref EXTI_LINE_23
     *         @arg @ref EXTI_LINE_24
     *         @arg @ref EXTI_LINE_25
     *         @arg @ref EXTI_LINE_26
     *         @arg @ref EXTI_LINE_27
     *         @arg @ref EXTI_LINE_28
     *         @arg @ref EXTI_LINE_29
     *         @arg @ref EXTI_LINE_30
     *         @arg @ref EXTI_LINE_31
     *         @arg @ref EXTI_LINE_ALL_0_31
     * @retval State of bit (1 or 0).
     */
    inline bool extiIsEnabledIT_0_31(EXTILinex_0_31 ExtiLine)
    {
        return ((READ_BIT(EXTI->IMR1, ExtiLine) == (ExtiLine)) ? true : false);
    }


    /**
     * @brief  Indicate if ExtiLine Interrupt request is enabled for Lines in range 32 to 63
     * @rmtoll IMR2         IMx           extiIsEnabledIT_32_63
     * @param  ExtiLine This parameter can be one of the following values:
     *         @arg @ref EXTI_LINE_32
     *         @arg @ref EXTI_LINE_33
     *         @arg @ref EXTI_LINE_34
     *         @arg @ref EXTI_LINE_35
     *         @arg @ref EXTI_LINE_36
     *         @arg @ref EXTI_LINE_37
     *         @arg @ref EXTI_LINE_38
     *         @arg @ref EXTI_LINE_39
     *         @arg @ref EXTI_LINE_40
     *         @arg @ref EXTI_LINE_41
     *         @arg @ref EXTI_LINE_42
     *         @arg @ref EXTI_LINE_43
     *         @arg @ref EXTI_LINE_44 (*)
     *         @arg @ref EXTI_LINE_46 (*)
     *         @arg @ref EXTI_LINE_47
     *         @arg @ref EXTI_LINE_48
     *         @arg @ref EXTI_LINE_49
     *         @arg @ref EXTI_LINE_50
     *         @arg @ref EXTI_LINE_51
     *         @arg @ref EXTI_LINE_52
     *         @arg @ref EXTI_LINE_53
     *         @arg @ref EXTI_LINE_54
     *         @arg @ref EXTI_LINE_55
     *         @arg @ref EXTI_LINE_56
     *         @arg @ref EXTI_LINE_57 (*)
     *         @arg @ref EXTI_LINE_58
     *         @arg @ref EXTI_LINE_59 (*)
     *         @arg @ref EXTI_LINE_60
     *         @arg @ref EXTI_LINE_61
     *         @arg @ref EXTI_LINE_62
     *         @arg @ref EXTI_LINE_63
     *         @arg @ref EXTI_LINE_ALL_32_63
     *
     *         (*) value not defined in all devices.
     * @retval State of bit (1 or 0).
     */
    inline bool extiIsEnabledIT_32_63(EXTILinex_32_63 ExtiLine)
    {
        return ((READ_BIT(EXTI->IMR2, ExtiLine) == (ExtiLine)) ? true : false);
    }


    /**
     * @brief  Indicate if ExtiLine Interrupt request is enabled for Lines in range 64 to 95
     * @rmtoll IMR3         IMx           extiIsEnabledIT_64_95
     * @param  ExtiLine This parameter can be one of the following values:
     *         @arg @ref EXTI_LINE_64
     *         @arg @ref EXTI_LINE_65
     *         @arg @ref EXTI_LINE_66
     *         @arg @ref EXTI_LINE_67
     *         @arg @ref EXTI_LINE_68
     *         @arg @ref EXTI_LINE_69
     *         @arg @ref EXTI_LINE_70
     *         @arg @ref EXTI_LINE_71
     *         @arg @ref EXTI_LINE_72
     *         @arg @ref EXTI_LINE_73
     *         @arg @ref EXTI_LINE_74
     *         @arg @ref EXTI_LINE_75 (*)
     *         @arg @ref EXTI_LINE_76 (*)
     *         @arg @ref EXTI_LINE_77 (**)
     *         @arg @ref EXTI_LINE_78 (**)
     *         @arg @ref EXTI_LINE_79 (**)
     *         @arg @ref EXTI_LINE_80 (**)
     *         @arg @ref EXTI_LINE_82 (**)
     *         @arg @ref EXTI_LINE_84 (**)
     *         @arg @ref EXTI_LINE_85
     *         @arg @ref EXTI_LINE_86 (*)
     *         @arg @ref EXTI_LINE_87
     *         @arg @ref EXTI_LINE_88 (*)
     *         @arg @ref EXTI_LINE_89 (*) 
     *         @arg @ref EXTI_LINE_90 (*)
     *         @arg @ref EXTI_LINE_91 (*)
     *         @arg @ref EXTI_LINE_ALL_64_95
     *
     *         (*) value not defined in all devices.
     *         (**) value only defined in dual core devices.
     * @retval State of bit (1 or 0).
     */
    inline bool extiIsEnabledIT_64_95(EXTILinex_64_95 ExtiLine)
    {
        return ((READ_BIT(EXTI->IMR3, ExtiLine) == (ExtiLine)) ? true : false);
    }

    #if defined(DUAL_CORE)
    /**
     * @brief  Enable ExtiLine Interrupt request for Lines in range 0 to 31 for cpu2
     * @rmtoll C2IMR1         IMx           c2EXTIEnableIT_0_31
     * @param  ExtiLine This parameter can be one of the following values:
     *         @arg @ref EXTI_LINE_0
     *         @arg @ref EXTI_LINE_1
     *         @arg @ref EXTI_LINE_2
     *         @arg @ref EXTI_LINE_3
     *         @arg @ref EXTI_LINE_4
     *         @arg @ref EXTI_LINE_5
     *         @arg @ref EXTI_LINE_6
     *         @arg @ref EXTI_LINE_7
     *         @arg @ref EXTI_LINE_8
     *         @arg @ref EXTI_LINE_9
     *         @arg @ref EXTI_LINE_10
     *         @arg @ref EXTI_LINE_11
     *         @arg @ref EXTI_LINE_12
     *         @arg @ref EXTI_LINE_13
     *         @arg @ref EXTI_LINE_14
     *         @arg @ref EXTI_LINE_15
     *         @arg @ref EXTI_LINE_16
     *         @arg @ref EXTI_LINE_17
     *         @arg @ref EXTI_LINE_18
     *         @arg @ref EXTI_LINE_19
     *         @arg @ref EXTI_LINE_20
     *         @arg @ref EXTI_LINE_21
     *         @arg @ref EXTI_LINE_22
     *         @arg @ref EXTI_LINE_23
     *         @arg @ref EXTI_LINE_24
     *         @arg @ref EXTI_LINE_25
     *         @arg @ref EXTI_LINE_26
     *         @arg @ref EXTI_LINE_27
     *         @arg @ref EXTI_LINE_28
     *         @arg @ref EXTI_LINE_29
     *         @arg @ref EXTI_LINE_30
     *         @arg @ref EXTI_LINE_31
     *         @arg @ref EXTI_LINE_ALL_0_31
     * @retval None
     */
    inline void c2EXTIEnableIT_0_31(EXTILinex_0_31 ExtiLine)
    {
        SET_BIT(EXTI->C2IMR1, ExtiLine);
    }


    /**
     * @brief  Enable ExtiLine Interrupt request for Lines in range 32 to 63 for cpu2
     * @rmtoll C2IMR2         IMx           c2EXTIEnableIT_32_63
     * @param  ExtiLine This parameter can be one of the following values:
     *         @arg @ref EXTI_LINE_32
     *         @arg @ref EXTI_LINE_33
     *         @arg @ref EXTI_LINE_34
     *         @arg @ref EXTI_LINE_35
     *         @arg @ref EXTI_LINE_36
     *         @arg @ref EXTI_LINE_37
     *         @arg @ref EXTI_LINE_38
     *         @arg @ref EXTI_LINE_39
     *         @arg @ref EXTI_LINE_40
     *         @arg @ref EXTI_LINE_41
     *         @arg @ref EXTI_LINE_42
     *         @arg @ref EXTI_LINE_43
     *         @arg @ref EXTI_LINE_44
     *         @arg @ref EXTI_LINE_46
     *         @arg @ref EXTI_LINE_47
     *         @arg @ref EXTI_LINE_48
     *         @arg @ref EXTI_LINE_49
     *         @arg @ref EXTI_LINE_50
     *         @arg @ref EXTI_LINE_51
     *         @arg @ref EXTI_LINE_52
     *         @arg @ref EXTI_LINE_53
     *         @arg @ref EXTI_LINE_54
     *         @arg @ref EXTI_LINE_55
     *         @arg @ref EXTI_LINE_56
     *         @arg @ref EXTI_LINE_57
     *         @arg @ref EXTI_LINE_58
     *         @arg @ref EXTI_LINE_59
     *         @arg @ref EXTI_LINE_60
     *         @arg @ref EXTI_LINE_61
     *         @arg @ref EXTI_LINE_62
     *         @arg @ref EXTI_LINE_63
     *         @arg @ref EXTI_LINE_ALL_32_63
     * @retval None
     */
    inline void c2EXTIEnableIT_32_63(EXTILinex_32_63 ExtiLine)
    {
        SET_BIT(EXTI->C2IMR2, ExtiLine);
    }


    /**
     * @brief  Enable ExtiLine Interrupt request for Lines in range 64 to 95
     * @rmtoll C2IMR3         IMx           c2EXTIEnableIT_64_95
     * @param  ExtiLine This parameter can be one of the following values:
     *         @arg @ref EXTI_LINE_64
     *         @arg @ref EXTI_LINE_65
     *         @arg @ref EXTI_LINE_66
     *         @arg @ref EXTI_LINE_67
     *         @arg @ref EXTI_LINE_68
     *         @arg @ref EXTI_LINE_69
     *         @arg @ref EXTI_LINE_70
     *         @arg @ref EXTI_LINE_71
     *         @arg @ref EXTI_LINE_72
     *         @arg @ref EXTI_LINE_73
     *         @arg @ref EXTI_LINE_74
     *         @arg @ref EXTI_LINE_75
     *         @arg @ref EXTI_LINE_76
     *         @arg @ref EXTI_LINE_77
     *         @arg @ref EXTI_LINE_78
     *         @arg @ref EXTI_LINE_79
     *         @arg @ref EXTI_LINE_80
     *         @arg @ref EXTI_LINE_82
     *         @arg @ref EXTI_LINE_84
     *         @arg @ref EXTI_LINE_85
     *         @arg @ref EXTI_LINE_86
     *         @arg @ref EXTI_LINE_87
     *         @arg @ref EXTI_LINE_ALL_64_95
     * @retval None
     */
    inline void c2EXTIEnableIT_64_95(EXTILinex_64_95 ExtiLine)
    {
        SET_BIT(EXTI->C2IMR3, ExtiLine);
    }


    /**
     * @brief  Disable ExtiLine Interrupt request for Lines in range 0 to 31 for cpu2
     * @rmtoll C2IMR1         IMx           c2EXTIDisableIT_0_31
     * @param  ExtiLine This parameter can be one of the following values:
     *         @arg @ref EXTI_LINE_0
     *         @arg @ref EXTI_LINE_1
     *         @arg @ref EXTI_LINE_2
     *         @arg @ref EXTI_LINE_3
     *         @arg @ref EXTI_LINE_4
     *         @arg @ref EXTI_LINE_5
     *         @arg @ref EXTI_LINE_6
     *         @arg @ref EXTI_LINE_7
     *         @arg @ref EXTI_LINE_8
     *         @arg @ref EXTI_LINE_9
     *         @arg @ref EXTI_LINE_10
     *         @arg @ref EXTI_LINE_11
     *         @arg @ref EXTI_LINE_12
     *         @arg @ref EXTI_LINE_13
     *         @arg @ref EXTI_LINE_14
     *         @arg @ref EXTI_LINE_15
     *         @arg @ref EXTI_LINE_16
     *         @arg @ref EXTI_LINE_17
     *         @arg @ref EXTI_LINE_18
     *         @arg @ref EXTI_LINE_19
     *         @arg @ref EXTI_LINE_20
     *         @arg @ref EXTI_LINE_21
     *         @arg @ref EXTI_LINE_22
     *         @arg @ref EXTI_LINE_23
     *         @arg @ref EXTI_LINE_24
     *         @arg @ref EXTI_LINE_25
     *         @arg @ref EXTI_LINE_26
     *         @arg @ref EXTI_LINE_27
     *         @arg @ref EXTI_LINE_28
     *         @arg @ref EXTI_LINE_29
     *         @arg @ref EXTI_LINE_30
     *         @arg @ref EXTI_LINE_31
     *         @arg @ref EXTI_LINE_ALL_0_31
     * @retval None
     */
    inline void c2EXTIDisableIT_0_31(EXTILinex_0_31 ExtiLine)
    {
        CLEAR_BIT(EXTI->C2IMR1, ExtiLine);
    }



    /**
     * @brief  Disable ExtiLine Interrupt request for Lines in range 32 to 63 for cpu2
     * @rmtoll C2IMR2         IMx           c2EXTIDisableIT_32_63
     * @param  ExtiLine This parameter can be one of the following values:
     *         @arg @ref EXTI_LINE_32
     *         @arg @ref EXTI_LINE_33
     *         @arg @ref EXTI_LINE_34
     *         @arg @ref EXTI_LINE_35
     *         @arg @ref EXTI_LINE_36
     *         @arg @ref EXTI_LINE_37
     *         @arg @ref EXTI_LINE_38
     *         @arg @ref EXTI_LINE_39
     *         @arg @ref EXTI_LINE_40
     *         @arg @ref EXTI_LINE_41
     *         @arg @ref EXTI_LINE_42
     *         @arg @ref EXTI_LINE_43
     *         @arg @ref EXTI_LINE_44
     *         @arg @ref EXTI_LINE_46
     *         @arg @ref EXTI_LINE_47
     *         @arg @ref EXTI_LINE_48
     *         @arg @ref EXTI_LINE_49
     *         @arg @ref EXTI_LINE_50
     *         @arg @ref EXTI_LINE_51
     *         @arg @ref EXTI_LINE_52
     *         @arg @ref EXTI_LINE_53
     *         @arg @ref EXTI_LINE_54
     *         @arg @ref EXTI_LINE_55
     *         @arg @ref EXTI_LINE_56
     *         @arg @ref EXTI_LINE_57
     *         @arg @ref EXTI_LINE_58
     *         @arg @ref EXTI_LINE_59
     *         @arg @ref EXTI_LINE_60
     *         @arg @ref EXTI_LINE_61
     *         @arg @ref EXTI_LINE_62
     *         @arg @ref EXTI_LINE_63
     *         @arg @ref EXTI_LINE_ALL_32_63
     * @retval None
     */
    inline void c2EXTIDisableIT_32_63(EXTILinex_32_63 ExtiLine)
    {
        CLEAR_BIT(EXTI->C2IMR2, ExtiLine);
    }


    /**
     * @brief  Disable ExtiLine Interrupt request for Lines in range 64 to 95 for cpu2
     * @rmtoll C2IMR3         IMx           c2EXTIDisableIT_64_95
     * @param  ExtiLine This parameter can be one of the following values:
     *         @arg @ref EXTI_LINE_64
     *         @arg @ref EXTI_LINE_65
     *         @arg @ref EXTI_LINE_66
     *         @arg @ref EXTI_LINE_67
     *         @arg @ref EXTI_LINE_68
     *         @arg @ref EXTI_LINE_69
     *         @arg @ref EXTI_LINE_70
     *         @arg @ref EXTI_LINE_71
     *         @arg @ref EXTI_LINE_72
     *         @arg @ref EXTI_LINE_73
     *         @arg @ref EXTI_LINE_74
     *         @arg @ref EXTI_LINE_75
     *         @arg @ref EXTI_LINE_76
     *         @arg @ref EXTI_LINE_77
     *         @arg @ref EXTI_LINE_78
     *         @arg @ref EXTI_LINE_79
     *         @arg @ref EXTI_LINE_80
     *         @arg @ref EXTI_LINE_82
     *         @arg @ref EXTI_LINE_84
     *         @arg @ref EXTI_LINE_85
     *         @arg @ref EXTI_LINE_86
     *         @arg @ref EXTI_LINE_87
     *         @arg @ref EXTI_LINE_ALL_64_95
     * @retval None
     */
    inline void c2EXTIDisableIT_64_95(EXTILinex_64_95 ExtiLine)
    {
        CLEAR_BIT(EXTI->C2IMR3, ExtiLine);
    }


    /**
     * @brief  Indicate if ExtiLine Interrupt request is enabled for Lines in range 0 to 31 for cpu2
     * @rmtoll C2IMR1         IMx           c2EXTIIsEnabledIT_0_31
     * @param  ExtiLine This parameter can be one of the following values:
     *         @arg @ref EXTI_LINE_0
     *         @arg @ref EXTI_LINE_1
     *         @arg @ref EXTI_LINE_2
     *         @arg @ref EXTI_LINE_3
     *         @arg @ref EXTI_LINE_4
     *         @arg @ref EXTI_LINE_5
     *         @arg @ref EXTI_LINE_6
     *         @arg @ref EXTI_LINE_7
     *         @arg @ref EXTI_LINE_8
     *         @arg @ref EXTI_LINE_9
     *         @arg @ref EXTI_LINE_10
     *         @arg @ref EXTI_LINE_11
     *         @arg @ref EXTI_LINE_12
     *         @arg @ref EXTI_LINE_13
     *         @arg @ref EXTI_LINE_14
     *         @arg @ref EXTI_LINE_15
     *         @arg @ref EXTI_LINE_16
     *         @arg @ref EXTI_LINE_17
     *         @arg @ref EXTI_LINE_18
     *         @arg @ref EXTI_LINE_19
     *         @arg @ref EXTI_LINE_20
     *         @arg @ref EXTI_LINE_21
     *         @arg @ref EXTI_LINE_22
     *         @arg @ref EXTI_LINE_23
     *         @arg @ref EXTI_LINE_24
     *         @arg @ref EXTI_LINE_25
     *         @arg @ref EXTI_LINE_26
     *         @arg @ref EXTI_LINE_27
     *         @arg @ref EXTI_LINE_28
     *         @arg @ref EXTI_LINE_29
     *         @arg @ref EXTI_LINE_30
     *         @arg @ref EXTI_LINE_31
     *         @arg @ref EXTI_LINE_ALL_0_31
     * @retval State of bit (1 or 0).
     */
    inline bool c2EXTIIsEnabledIT_0_31(EXTILinex_0_31 ExtiLine)
    {
        return ((READ_BIT(EXTI->C2IMR1, ExtiLine) == (ExtiLine)) ? true : false);
    }


    /**
     * @brief  Indicate if ExtiLine Interrupt request is enabled for Lines in range 32 to 63 for cpu2
     * @rmtoll C2IMR2         IMx           c2EXTIIsEnabledIT_32_63
     * @param  ExtiLine This parameter can be one of the following values:
     *         @arg @ref EXTI_LINE_32
     *         @arg @ref EXTI_LINE_33
     *         @arg @ref EXTI_LINE_34
     *         @arg @ref EXTI_LINE_35
     *         @arg @ref EXTI_LINE_36
     *         @arg @ref EXTI_LINE_37
     *         @arg @ref EXTI_LINE_38
     *         @arg @ref EXTI_LINE_39
     *         @arg @ref EXTI_LINE_40
     *         @arg @ref EXTI_LINE_41
     *         @arg @ref EXTI_LINE_42
     *         @arg @ref EXTI_LINE_43
     *         @arg @ref EXTI_LINE_44
     *         @arg @ref EXTI_LINE_46
     *         @arg @ref EXTI_LINE_47
     *         @arg @ref EXTI_LINE_48
     *         @arg @ref EXTI_LINE_49
     *         @arg @ref EXTI_LINE_50
     *         @arg @ref EXTI_LINE_51
     *         @arg @ref EXTI_LINE_52
     *         @arg @ref EXTI_LINE_53
     *         @arg @ref EXTI_LINE_54
     *         @arg @ref EXTI_LINE_55
     *         @arg @ref EXTI_LINE_56
     *         @arg @ref EXTI_LINE_57
     *         @arg @ref EXTI_LINE_58
     *         @arg @ref EXTI_LINE_59
     *         @arg @ref EXTI_LINE_60
     *         @arg @ref EXTI_LINE_61
     *         @arg @ref EXTI_LINE_62
     *         @arg @ref EXTI_LINE_63
     *         @arg @ref EXTI_LINE_ALL_32_63
     * @retval State of bit (1 or 0).
     */
    inline bool c2EXTIIsEnabledIT_32_63(EXTILinex_32_63 ExtiLine)
    {
        return ((READ_BIT(EXTI->C2IMR2, ExtiLine) == (ExtiLine))? true : false);
    }


    /**
     * @brief  Indicate if ExtiLine Interrupt request is enabled for Lines in range 64 to 95
     * @rmtoll C2IMR3         IMx           c2EXTIIsEnabledIT_64_95
     * @param  ExtiLine This parameter can be one of the following values:
     *         @arg @ref EXTI_LINE_64
     *         @arg @ref EXTI_LINE_65
     *         @arg @ref EXTI_LINE_66
     *         @arg @ref EXTI_LINE_67
     *         @arg @ref EXTI_LINE_68
     *         @arg @ref EXTI_LINE_69
     *         @arg @ref EXTI_LINE_70
     *         @arg @ref EXTI_LINE_71
     *         @arg @ref EXTI_LINE_72
     *         @arg @ref EXTI_LINE_73
     *         @arg @ref EXTI_LINE_74
     *         @arg @ref EXTI_LINE_75
     *         @arg @ref EXTI_LINE_76
     *         @arg @ref EXTI_LINE_77
     *         @arg @ref EXTI_LINE_78
     *         @arg @ref EXTI_LINE_79
     *         @arg @ref EXTI_LINE_80
     *         @arg @ref EXTI_LINE_82
     *         @arg @ref EXTI_LINE_84
     *         @arg @ref EXTI_LINE_85
     *         @arg @ref EXTI_LINE_86
     *         @arg @ref EXTI_LINE_87
     *         @arg @ref EXTI_LINE_ALL_64_95
     * @retval State of bit (1 or 0).
     */
    inline bool c2EXTIIsEnabledIT_64_95(EXTILinex_64_95 ExtiLine)
    {
        return ((READ_BIT(EXTI->C2IMR3, ExtiLine) == (ExtiLine)) ? true : false);
    }

    #endif /* DUAL_CORE */

    /** @defgroup EXTI_LL_EF_Event_Management Event_Management
     * @{
     */

    /**
     * @brief  Enable ExtiLine Event request for Lines in range 0 to 31
     * @rmtoll EMR1         EMx           extiEnableEvent_0_31
     * @param  ExtiLine This parameter can be one of the following values:
     *         @arg @ref EXTI_LINE_0
     *         @arg @ref EXTI_LINE_1
     *         @arg @ref EXTI_LINE_2
     *         @arg @ref EXTI_LINE_3
     *         @arg @ref EXTI_LINE_4
     *         @arg @ref EXTI_LINE_5
     *         @arg @ref EXTI_LINE_6
     *         @arg @ref EXTI_LINE_7
     *         @arg @ref EXTI_LINE_8
     *         @arg @ref EXTI_LINE_9
     *         @arg @ref EXTI_LINE_10
     *         @arg @ref EXTI_LINE_11
     *         @arg @ref EXTI_LINE_12
     *         @arg @ref EXTI_LINE_13
     *         @arg @ref EXTI_LINE_14
     *         @arg @ref EXTI_LINE_15
     *         @arg @ref EXTI_LINE_16
     *         @arg @ref EXTI_LINE_17
     *         @arg @ref EXTI_LINE_18
     *         @arg @ref EXTI_LINE_19
     *         @arg @ref EXTI_LINE_20
     *         @arg @ref EXTI_LINE_21
     *         @arg @ref EXTI_LINE_22
     *         @arg @ref EXTI_LINE_23
     *         @arg @ref EXTI_LINE_24
     *         @arg @ref EXTI_LINE_25
     *         @arg @ref EXTI_LINE_26
     *         @arg @ref EXTI_LINE_27
     *         @arg @ref EXTI_LINE_28
     *         @arg @ref EXTI_LINE_29
     *         @arg @ref EXTI_LINE_30
     *         @arg @ref EXTI_LINE_31
     *         @arg @ref EXTI_LINE_ALL_0_31
     * @retval None
     */
    inline void extiEnableEvent_0_31(EXTILinex_0_31 ExtiLine)
    {
        SET_BIT(EXTI->EMR1, ExtiLine);
    }

    /**
     * @brief  Enable ExtiLine Event request for Lines in range 32 to 63
     * @rmtoll EMR2         EMx           extiEnableEvent_32_63
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_32
     *         @arg @ref EXTI_LINE_33
     *         @arg @ref EXTI_LINE_34
     *         @arg @ref EXTI_LINE_35
     *         @arg @ref EXTI_LINE_36
     *         @arg @ref EXTI_LINE_37
     *         @arg @ref EXTI_LINE_38
     *         @arg @ref EXTI_LINE_39
     *         @arg @ref EXTI_LINE_40
     *         @arg @ref EXTI_LINE_41
     *         @arg @ref EXTI_LINE_42
     *         @arg @ref EXTI_LINE_43
     *         @arg @ref EXTI_LINE_44 (*)
     *         @arg @ref EXTI_LINE_46 (*)
     *         @arg @ref EXTI_LINE_47
     *         @arg @ref EXTI_LINE_48
     *         @arg @ref EXTI_LINE_49
     *         @arg @ref EXTI_LINE_50
     *         @arg @ref EXTI_LINE_51
     *         @arg @ref EXTI_LINE_52
     *         @arg @ref EXTI_LINE_53
     *         @arg @ref EXTI_LINE_54
     *         @arg @ref EXTI_LINE_55
     *         @arg @ref EXTI_LINE_56
     *         @arg @ref EXTI_LINE_57 (*)
     *         @arg @ref EXTI_LINE_58
     *         @arg @ref EXTI_LINE_59 (*)
     *         @arg @ref EXTI_LINE_60
     *         @arg @ref EXTI_LINE_61
     *         @arg @ref EXTI_LINE_62
     *         @arg @ref EXTI_LINE_63
     *         @arg @ref EXTI_LINE_ALL_32_63
     *
     *         (*) value not defined in all devices.
     * @retval None
     */
    inline void extiEnableEvent_32_63(EXTILinex_32_63 ExtiLine)
    {
        SET_BIT(EXTI->EMR2, ExtiLine);
    }

    /**
     * @brief  Enable ExtiLine Event request for Lines in range 64 to 95
     * @rmtoll EMR3         EMx           extiEnableEvent_64_95
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_64
     *         @arg @ref EXTI_LINE_65
     *         @arg @ref EXTI_LINE_66
     *         @arg @ref EXTI_LINE_67
     *         @arg @ref EXTI_LINE_68
     *         @arg @ref EXTI_LINE_69
     *         @arg @ref EXTI_LINE_70
     *         @arg @ref EXTI_LINE_71
     *         @arg @ref EXTI_LINE_72
     *         @arg @ref EXTI_LINE_73
     *         @arg @ref EXTI_LINE_74
     *         @arg @ref EXTI_LINE_75 (*)
     *         @arg @ref EXTI_LINE_76 (*)
     *         @arg @ref EXTI_LINE_77 (**)
     *         @arg @ref EXTI_LINE_78 (**)
     *         @arg @ref EXTI_LINE_79 (**)
     *         @arg @ref EXTI_LINE_80 (**)
     *         @arg @ref EXTI_LINE_82 (**)
     *         @arg @ref EXTI_LINE_84 (**)
     *         @arg @ref EXTI_LINE_85
     *         @arg @ref EXTI_LINE_86 (*)
     *         @arg @ref EXTI_LINE_87
     *         @arg @ref EXTI_LINE_88 (*)
     *         @arg @ref EXTI_LINE_89 (*)
     *         @arg @ref EXTI_LINE_90 (*)
     *         @arg @ref EXTI_LINE_91 (*)
     *         @arg @ref EXTI_LINE_ALL_64_95
     *
     *         (*) value not defined in all devices.
     *         (**) value only defined in dual core devices.
     * @retval None
     */
    inline void extiEnableEvent_64_95(EXTILinex_64_95 ExtiLine)
    {
        SET_BIT(EXTI->EMR3, ExtiLine);
    }

    /**
     * @brief  Disable ExtiLine Event request for Lines in range 0 to 31
     * @rmtoll EMR1         EMx           extiDisableEvent_0_31
     * @param  ExtiLine This parameter can be one of the following values:
     *         @arg @ref EXTI_LINE_0
     *         @arg @ref EXTI_LINE_1
     *         @arg @ref EXTI_LINE_2
     *         @arg @ref EXTI_LINE_3
     *         @arg @ref EXTI_LINE_4
     *         @arg @ref EXTI_LINE_5
     *         @arg @ref EXTI_LINE_6
     *         @arg @ref EXTI_LINE_7
     *         @arg @ref EXTI_LINE_8
     *         @arg @ref EXTI_LINE_9
     *         @arg @ref EXTI_LINE_10
     *         @arg @ref EXTI_LINE_11
     *         @arg @ref EXTI_LINE_12
     *         @arg @ref EXTI_LINE_13
     *         @arg @ref EXTI_LINE_14
     *         @arg @ref EXTI_LINE_15
     *         @arg @ref EXTI_LINE_16
     *         @arg @ref EXTI_LINE_17
     *         @arg @ref EXTI_LINE_18
     *         @arg @ref EXTI_LINE_19
     *         @arg @ref EXTI_LINE_20
     *         @arg @ref EXTI_LINE_21
     *         @arg @ref EXTI_LINE_22
     *         @arg @ref EXTI_LINE_23
     *         @arg @ref EXTI_LINE_24
     *         @arg @ref EXTI_LINE_25
     *         @arg @ref EXTI_LINE_26
     *         @arg @ref EXTI_LINE_27
     *         @arg @ref EXTI_LINE_28
     *         @arg @ref EXTI_LINE_29
     *         @arg @ref EXTI_LINE_30
     *         @arg @ref EXTI_LINE_31
     *         @arg @ref EXTI_LINE_ALL_0_31
     * @retval None
     */
    inline void extiDisableEvent_0_31(EXTILinex_0_31 ExtiLine)
    {
        CLEAR_BIT(EXTI->EMR1, ExtiLine);
    }

    /**
     * @brief  Disable ExtiLine Event request for Lines in range 32 to 63
     * @rmtoll EMR2         EMx           extiDisableEvent_32_63
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_32
     *         @arg @ref EXTI_LINE_33
     *         @arg @ref EXTI_LINE_34
     *         @arg @ref EXTI_LINE_35
     *         @arg @ref EXTI_LINE_36
     *         @arg @ref EXTI_LINE_37
     *         @arg @ref EXTI_LINE_38
     *         @arg @ref EXTI_LINE_39
     *         @arg @ref EXTI_LINE_40
     *         @arg @ref EXTI_LINE_41
     *         @arg @ref EXTI_LINE_42
     *         @arg @ref EXTI_LINE_43
     *         @arg @ref EXTI_LINE_44 (*)
     *         @arg @ref EXTI_LINE_46 (*)
     *         @arg @ref EXTI_LINE_47
     *         @arg @ref EXTI_LINE_48
     *         @arg @ref EXTI_LINE_49
     *         @arg @ref EXTI_LINE_50
     *         @arg @ref EXTI_LINE_51
     *         @arg @ref EXTI_LINE_52
     *         @arg @ref EXTI_LINE_53
     *         @arg @ref EXTI_LINE_54
     *         @arg @ref EXTI_LINE_55
     *         @arg @ref EXTI_LINE_56
     *         @arg @ref EXTI_LINE_57 (*)
     *         @arg @ref EXTI_LINE_58
     *         @arg @ref EXTI_LINE_59 (*)
     *         @arg @ref EXTI_LINE_60
     *         @arg @ref EXTI_LINE_61
     *         @arg @ref EXTI_LINE_62
     *         @arg @ref EXTI_LINE_63
     *         @arg @ref EXTI_LINE_ALL_32_63
     *
     *         (*) value not defined in all devices.
     * @retval None
     */
    inline void extiDisableEvent_32_63(EXTILinex_32_63 ExtiLine)
    {
        CLEAR_BIT(EXTI->EMR2, ExtiLine);
    }

    /**
     * @brief  Disable ExtiLine Event request for Lines in range 64 to 95
     * @rmtoll EMR3         EMx           extiDisableEvent_64_95
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_64
     *         @arg @ref EXTI_LINE_65
     *         @arg @ref EXTI_LINE_66
     *         @arg @ref EXTI_LINE_67
     *         @arg @ref EXTI_LINE_68
     *         @arg @ref EXTI_LINE_69
     *         @arg @ref EXTI_LINE_70
     *         @arg @ref EXTI_LINE_71
     *         @arg @ref EXTI_LINE_72
     *         @arg @ref EXTI_LINE_73
     *         @arg @ref EXTI_LINE_74
     *         @arg @ref EXTI_LINE_75 (*)
     *         @arg @ref EXTI_LINE_76 (*)
     *         @arg @ref EXTI_LINE_77 (**)
     *         @arg @ref EXTI_LINE_78 (**)
     *         @arg @ref EXTI_LINE_79 (**)
     *         @arg @ref EXTI_LINE_80 (**)
     *         @arg @ref EXTI_LINE_82 (**)
     *         @arg @ref EXTI_LINE_84 (**)
     *         @arg @ref EXTI_LINE_85
     *         @arg @ref EXTI_LINE_86 (*)
     *         @arg @ref EXTI_LINE_87
     *         @arg @ref EXTI_LINE_88 (*)
     *         @arg @ref EXTI_LINE_89 (*)
     *         @arg @ref EXTI_LINE_90 (*)
     *         @arg @ref EXTI_LINE_91 (*)
     *         @arg @ref EXTI_LINE_ALL_64_95
     *
     *         (*) value not defined in all devices.
     *         (**) value only defined in dual core devices.
     * @retval None
     */
    inline void extiDisableEvent_64_95(EXTILinex_64_95 ExtiLine)
    {
        CLEAR_BIT(EXTI->EMR3, ExtiLine);
    }

    /**
     * @brief  Indicate if ExtiLine Event request is enabled for Lines in range 0 to 31
     * @rmtoll EMR1         EMx           EXTI_IsEnabledEvent_0_31
     * @param  ExtiLine This parameter can be one of the following values:
     *         @arg @ref EXTI_LINE_0
     *         @arg @ref EXTI_LINE_1
     *         @arg @ref EXTI_LINE_2
     *         @arg @ref EXTI_LINE_3
     *         @arg @ref EXTI_LINE_4
     *         @arg @ref EXTI_LINE_5
     *         @arg @ref EXTI_LINE_6
     *         @arg @ref EXTI_LINE_7
     *         @arg @ref EXTI_LINE_8
     *         @arg @ref EXTI_LINE_9
     *         @arg @ref EXTI_LINE_10
     *         @arg @ref EXTI_LINE_11
     *         @arg @ref EXTI_LINE_12
     *         @arg @ref EXTI_LINE_13
     *         @arg @ref EXTI_LINE_14
     *         @arg @ref EXTI_LINE_15
     *         @arg @ref EXTI_LINE_16
     *         @arg @ref EXTI_LINE_17
     *         @arg @ref EXTI_LINE_18
     *         @arg @ref EXTI_LINE_19
     *         @arg @ref EXTI_LINE_20
     *         @arg @ref EXTI_LINE_21
     *         @arg @ref EXTI_LINE_22
     *         @arg @ref EXTI_LINE_23
     *         @arg @ref EXTI_LINE_24
     *         @arg @ref EXTI_LINE_25
     *         @arg @ref EXTI_LINE_26
     *         @arg @ref EXTI_LINE_27
     *         @arg @ref EXTI_LINE_28
     *         @arg @ref EXTI_LINE_29
     *         @arg @ref EXTI_LINE_30
     *         @arg @ref EXTI_LINE_31
     *         @arg @ref EXTI_LINE_ALL_0_31
     * @note   Please check each device line mapping for EXTI Line availability
     * @retval State of bit (1 or 0).
     */
    inline bool extiIsEnabledEvent_0_31(EXTILinex_0_31 ExtiLine)
    {
        return ((READ_BIT(EXTI->EMR1, ExtiLine) == (ExtiLine)) ? true : false);
    }

    /**
     * @brief  Indicate if ExtiLine Event request is enabled for Lines in range 32 to 63
     * @rmtoll EMR2         EMx           EXTI_IsEnabledEvent_32_63
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_32
     *         @arg @ref EXTI_LINE_33
     *         @arg @ref EXTI_LINE_34
     *         @arg @ref EXTI_LINE_35
     *         @arg @ref EXTI_LINE_36
     *         @arg @ref EXTI_LINE_37
     *         @arg @ref EXTI_LINE_38
     *         @arg @ref EXTI_LINE_39
     *         @arg @ref EXTI_LINE_40
     *         @arg @ref EXTI_LINE_41
     *         @arg @ref EXTI_LINE_42
     *         @arg @ref EXTI_LINE_43
     *         @arg @ref EXTI_LINE_44 (*)
     *         @arg @ref EXTI_LINE_46 (*)
     *         @arg @ref EXTI_LINE_47
     *         @arg @ref EXTI_LINE_48
     *         @arg @ref EXTI_LINE_49
     *         @arg @ref EXTI_LINE_50
     *         @arg @ref EXTI_LINE_51
     *         @arg @ref EXTI_LINE_52
     *         @arg @ref EXTI_LINE_53
     *         @arg @ref EXTI_LINE_54
     *         @arg @ref EXTI_LINE_55
     *         @arg @ref EXTI_LINE_56
     *         @arg @ref EXTI_LINE_57 (*)
     *         @arg @ref EXTI_LINE_58
     *         @arg @ref EXTI_LINE_59 (*)
     *         @arg @ref EXTI_LINE_60
     *         @arg @ref EXTI_LINE_61
     *         @arg @ref EXTI_LINE_62
     *         @arg @ref EXTI_LINE_63
     *         @arg @ref EXTI_LINE_ALL_32_63
     *
     *         (*) value not defined in all devices.
     * @retval State of bit (1 or 0).
     */
    inline bool extiIsEnabledEvent_32_63(EXTILinex_32_63 ExtiLine)
    {
        return ((READ_BIT(EXTI->EMR2, ExtiLine) == (ExtiLine)) ? true : false);
    }

    /**
     * @brief  Indicate if ExtiLine Event request is enabled for Lines in range 64 to 95
     * @rmtoll EMR3         EMx           EXTI_IsEnabledEvent_64_95
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_64
     *         @arg @ref EXTI_LINE_65
     *         @arg @ref EXTI_LINE_66
     *         @arg @ref EXTI_LINE_67
     *         @arg @ref EXTI_LINE_68
     *         @arg @ref EXTI_LINE_69
     *         @arg @ref EXTI_LINE_70
     *         @arg @ref EXTI_LINE_71
     *         @arg @ref EXTI_LINE_72
     *         @arg @ref EXTI_LINE_73
     *         @arg @ref EXTI_LINE_74
     *         @arg @ref EXTI_LINE_75 (*)
     *         @arg @ref EXTI_LINE_76 (*)
     *         @arg @ref EXTI_LINE_77 (**)
     *         @arg @ref EXTI_LINE_78 (**)
     *         @arg @ref EXTI_LINE_79 (**)
     *         @arg @ref EXTI_LINE_80 (**)
     *         @arg @ref EXTI_LINE_82 (**)
     *         @arg @ref EXTI_LINE_84 (**)
     *         @arg @ref EXTI_LINE_85
     *         @arg @ref EXTI_LINE_86 (*)
     *         @arg @ref EXTI_LINE_87
     *         @arg @ref EXTI_LINE_88 (*)
     *         @arg @ref EXTI_LINE_89 (*)
     *         @arg @ref EXTI_LINE_90 (*)
     *         @arg @ref EXTI_LINE_91 (*)
     *         @arg @ref EXTI_LINE_ALL_64_95
     *
     *         (*) value not defined in all devices.
     *         (**) value only defined in dual core devices.
     * @retval State of bit (1 or 0).
     */
    inline bool extiIsEnabledEvent_64_95(EXTILinex_64_95 ExtiLine)
    {
        return ((READ_BIT(EXTI->EMR3, ExtiLine) == (ExtiLine)) ? true : false);
    }

    #if defined(DUAL_CORE)

    /**
     * @brief  Enable ExtiLine Event request for Lines in range 0 to 31 for cpu2
     * @rmtoll C2EMR1         EMx           c2EXTIEnableEvent_0_31
     * @param  ExtiLine This parameter can be one of the following values:
     *         @arg @ref EXTI_LINE_0
     *         @arg @ref EXTI_LINE_1
     *         @arg @ref EXTI_LINE_2
     *         @arg @ref EXTI_LINE_3
     *         @arg @ref EXTI_LINE_4
     *         @arg @ref EXTI_LINE_5
     *         @arg @ref EXTI_LINE_6
     *         @arg @ref EXTI_LINE_7
     *         @arg @ref EXTI_LINE_8
     *         @arg @ref EXTI_LINE_9
     *         @arg @ref EXTI_LINE_10
     *         @arg @ref EXTI_LINE_11
     *         @arg @ref EXTI_LINE_12
     *         @arg @ref EXTI_LINE_13
     *         @arg @ref EXTI_LINE_14
     *         @arg @ref EXTI_LINE_15
     *         @arg @ref EXTI_LINE_16
     *         @arg @ref EXTI_LINE_17
     *         @arg @ref EXTI_LINE_18
     *         @arg @ref EXTI_LINE_19
     *         @arg @ref EXTI_LINE_20
     *         @arg @ref EXTI_LINE_21
     *         @arg @ref EXTI_LINE_22
     *         @arg @ref EXTI_LINE_23
     *         @arg @ref EXTI_LINE_24
     *         @arg @ref EXTI_LINE_25
     *         @arg @ref EXTI_LINE_26
     *         @arg @ref EXTI_LINE_27
     *         @arg @ref EXTI_LINE_28
     *         @arg @ref EXTI_LINE_29
     *         @arg @ref EXTI_LINE_30
     *         @arg @ref EXTI_LINE_31
     *         @arg @ref EXTI_LINE_ALL_0_31
     * @retval None
     */
    inline void c2EXTIEnableEvent_0_31(EXTILinex_0_31 ExtiLine)
    {
        SET_BIT(EXTI->C2EMR1, ExtiLine);
    }


    /**
     * @brief  Enable ExtiLine Event request for Lines in range 32 to 63 for cpu2
     * @rmtoll C2EMR2         EMx           c2EXTIEnableEvent_32_63
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_32
     *         @arg @ref EXTI_LINE_33
     *         @arg @ref EXTI_LINE_34
     *         @arg @ref EXTI_LINE_35
     *         @arg @ref EXTI_LINE_36
     *         @arg @ref EXTI_LINE_37
     *         @arg @ref EXTI_LINE_38
     *         @arg @ref EXTI_LINE_39
     *         @arg @ref EXTI_LINE_40
     *         @arg @ref EXTI_LINE_41
     *         @arg @ref EXTI_LINE_42
     *         @arg @ref EXTI_LINE_43
     *         @arg @ref EXTI_LINE_44
     *         @arg @ref EXTI_LINE_46
     *         @arg @ref EXTI_LINE_47
     *         @arg @ref EXTI_LINE_48
     *         @arg @ref EXTI_LINE_49
     *         @arg @ref EXTI_LINE_50
     *         @arg @ref EXTI_LINE_51
     *         @arg @ref EXTI_LINE_52
     *         @arg @ref EXTI_LINE_53
     *         @arg @ref EXTI_LINE_54
     *         @arg @ref EXTI_LINE_55
     *         @arg @ref EXTI_LINE_56
     *         @arg @ref EXTI_LINE_57
     *         @arg @ref EXTI_LINE_58
     *         @arg @ref EXTI_LINE_59
     *         @arg @ref EXTI_LINE_60
     *         @arg @ref EXTI_LINE_61
     *         @arg @ref EXTI_LINE_62
     *         @arg @ref EXTI_LINE_63
     *         @arg @ref EXTI_LINE_ALL_32_63
     * @retval None
     */
    inline void c2EXTIEnableEvent_32_63(EXTILinex_32_63 ExtiLine)
    {
        SET_BIT(EXTI->C2EMR2, ExtiLine);
    }

    /**
     * @brief  Enable ExtiLine Event request for Lines in range 64 to 95 for cpu2
     * @rmtoll C2EMR3         EMx           c2EXTIEnableEvent_64_95
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_64
     *         @arg @ref EXTI_LINE_65
     *         @arg @ref EXTI_LINE_66
     *         @arg @ref EXTI_LINE_67
     *         @arg @ref EXTI_LINE_68
     *         @arg @ref EXTI_LINE_69
     *         @arg @ref EXTI_LINE_70
     *         @arg @ref EXTI_LINE_71
     *         @arg @ref EXTI_LINE_72
     *         @arg @ref EXTI_LINE_73
     *         @arg @ref EXTI_LINE_74
     *         @arg @ref EXTI_LINE_75
     *         @arg @ref EXTI_LINE_76
     *         @arg @ref EXTI_LINE_77
     *         @arg @ref EXTI_LINE_78
     *         @arg @ref EXTI_LINE_79
     *         @arg @ref EXTI_LINE_80
     *         @arg @ref EXTI_LINE_82
     *         @arg @ref EXTI_LINE_84
     *         @arg @ref EXTI_LINE_85
     *         @arg @ref EXTI_LINE_86
     *         @arg @ref EXTI_LINE_87
     *         @arg @ref EXTI_LINE_ALL_64_95
     * @retval None
     */
    inline void c2EXTIEnableEvent_64_95(EXTILinex_64_95 ExtiLine)
    {
        SET_BIT(EXTI->C2EMR3, ExtiLine);
    }


    /**
     * @brief  Disable ExtiLine Event request for Lines in range 0 to 31 for cpu2
     * @rmtoll C2EMR1         EMx           c2EXTIDisableEvent_0_31
     * @param  ExtiLine This parameter can be one of the following values:
     *         @arg @ref EXTI_LINE_0
     *         @arg @ref EXTI_LINE_1
     *         @arg @ref EXTI_LINE_2
     *         @arg @ref EXTI_LINE_3
     *         @arg @ref EXTI_LINE_4
     *         @arg @ref EXTI_LINE_5
     *         @arg @ref EXTI_LINE_6
     *         @arg @ref EXTI_LINE_7
     *         @arg @ref EXTI_LINE_8
     *         @arg @ref EXTI_LINE_9
     *         @arg @ref EXTI_LINE_10
     *         @arg @ref EXTI_LINE_11
     *         @arg @ref EXTI_LINE_12
     *         @arg @ref EXTI_LINE_13
     *         @arg @ref EXTI_LINE_14
     *         @arg @ref EXTI_LINE_15
     *         @arg @ref EXTI_LINE_16
     *         @arg @ref EXTI_LINE_17
     *         @arg @ref EXTI_LINE_18
     *         @arg @ref EXTI_LINE_19
     *         @arg @ref EXTI_LINE_20
     *         @arg @ref EXTI_LINE_21
     *         @arg @ref EXTI_LINE_22
     *         @arg @ref EXTI_LINE_23
     *         @arg @ref EXTI_LINE_24
     *         @arg @ref EXTI_LINE_25
     *         @arg @ref EXTI_LINE_26
     *         @arg @ref EXTI_LINE_27
     *         @arg @ref EXTI_LINE_28
     *         @arg @ref EXTI_LINE_29
     *         @arg @ref EXTI_LINE_30
     *         @arg @ref EXTI_LINE_31
     *         @arg @ref EXTI_LINE_ALL_0_31
     * @retval None
     */
    inline void c2EXTIDisableEvent_0_31(EXTILinex_0_31 ExtiLine)
    {
        CLEAR_BIT(EXTI->C2EMR1, ExtiLine);
    }


    /**
     * @brief  Disable ExtiLine Event request for Lines in range 32 to 63 for cpu2
     * @rmtoll C2EMR2         EMx           c2EXTIDisableEvent_32_63
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_32
     *         @arg @ref EXTI_LINE_33
     *         @arg @ref EXTI_LINE_34
     *         @arg @ref EXTI_LINE_35
     *         @arg @ref EXTI_LINE_36
     *         @arg @ref EXTI_LINE_37
     *         @arg @ref EXTI_LINE_38
     *         @arg @ref EXTI_LINE_39
     *         @arg @ref EXTI_LINE_40
     *         @arg @ref EXTI_LINE_41
     *         @arg @ref EXTI_LINE_42
     *         @arg @ref EXTI_LINE_43
     *         @arg @ref EXTI_LINE_44
     *         @arg @ref EXTI_LINE_46
     *         @arg @ref EXTI_LINE_47
     *         @arg @ref EXTI_LINE_48
     *         @arg @ref EXTI_LINE_49
     *         @arg @ref EXTI_LINE_50
     *         @arg @ref EXTI_LINE_51
     *         @arg @ref EXTI_LINE_52
     *         @arg @ref EXTI_LINE_53
     *         @arg @ref EXTI_LINE_54
     *         @arg @ref EXTI_LINE_55
     *         @arg @ref EXTI_LINE_56
     *         @arg @ref EXTI_LINE_57
     *         @arg @ref EXTI_LINE_58
     *         @arg @ref EXTI_LINE_59
     *         @arg @ref EXTI_LINE_60
     *         @arg @ref EXTI_LINE_61
     *         @arg @ref EXTI_LINE_62
     *         @arg @ref EXTI_LINE_63
     *         @arg @ref EXTI_LINE_ALL_32_63
     * @retval None
     */
    inline void c2EXTIDisableEvent_32_63(EXTILinex_32_63 ExtiLine)
    {
        CLEAR_BIT(EXTI->C2EMR2, ExtiLine);
    }


    /**
     * @brief  Disable ExtiLine Event request for Lines in range 64 to 95 for cpu2
     * @rmtoll C2EMR3         EMx           c2EXTIDisableEvent_64_95
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_64
     *         @arg @ref EXTI_LINE_65
     *         @arg @ref EXTI_LINE_66
     *         @arg @ref EXTI_LINE_67
     *         @arg @ref EXTI_LINE_68
     *         @arg @ref EXTI_LINE_69
     *         @arg @ref EXTI_LINE_70
     *         @arg @ref EXTI_LINE_71
     *         @arg @ref EXTI_LINE_72
     *         @arg @ref EXTI_LINE_73
     *         @arg @ref EXTI_LINE_74
     *         @arg @ref EXTI_LINE_75
     *         @arg @ref EXTI_LINE_76
     *         @arg @ref EXTI_LINE_77
     *         @arg @ref EXTI_LINE_78
     *         @arg @ref EXTI_LINE_79
     *         @arg @ref EXTI_LINE_80
     *         @arg @ref EXTI_LINE_82
     *         @arg @ref EXTI_LINE_84
     *         @arg @ref EXTI_LINE_85
     *         @arg @ref EXTI_LINE_86
     *         @arg @ref EXTI_LINE_87
     *         @arg @ref EXTI_LINE_ALL_64_95
     * @retval None
     */
    inline void c2EXTIDisableEvent_64_95(EXTILinex_64_95 ExtiLine)
    {
        CLEAR_BIT(EXTI->C2EMR3, ExtiLine);
    }


    /**
     * @brief  Indicate if ExtiLine Event request is enabled for Lines in range 0 to 31 for cpu2
     * @rmtoll C2EMR1         EMx           c2EXTIIsEnabledEvent_0_31
     * @param  ExtiLine This parameter can be one of the following values:
     *         @arg @ref EXTI_LINE_0
     *         @arg @ref EXTI_LINE_1
     *         @arg @ref EXTI_LINE_2
     *         @arg @ref EXTI_LINE_3
     *         @arg @ref EXTI_LINE_4
     *         @arg @ref EXTI_LINE_5
     *         @arg @ref EXTI_LINE_6
     *         @arg @ref EXTI_LINE_7
     *         @arg @ref EXTI_LINE_8
     *         @arg @ref EXTI_LINE_9
     *         @arg @ref EXTI_LINE_10
     *         @arg @ref EXTI_LINE_11
     *         @arg @ref EXTI_LINE_12
     *         @arg @ref EXTI_LINE_13
     *         @arg @ref EXTI_LINE_14
     *         @arg @ref EXTI_LINE_15
     *         @arg @ref EXTI_LINE_16
     *         @arg @ref EXTI_LINE_17
     *         @arg @ref EXTI_LINE_18
     *         @arg @ref EXTI_LINE_19
     *         @arg @ref EXTI_LINE_20
     *         @arg @ref EXTI_LINE_21
     *         @arg @ref EXTI_LINE_22
     *         @arg @ref EXTI_LINE_23
     *         @arg @ref EXTI_LINE_24
     *         @arg @ref EXTI_LINE_25
     *         @arg @ref EXTI_LINE_26
     *         @arg @ref EXTI_LINE_27
     *         @arg @ref EXTI_LINE_28
     *         @arg @ref EXTI_LINE_29
     *         @arg @ref EXTI_LINE_30
     *         @arg @ref EXTI_LINE_31
     *         @arg @ref EXTI_LINE_ALL_0_31
     * @note   Please check each device line mapping for EXTI Line availability
     * @retval State of bit (1 or 0).
     */
    inline bool c2EXTIIsEnabledEvent_0_31(EXTILinex_0_31 ExtiLine)
    {
        return ((READ_BIT(EXTI->C2EMR1, ExtiLine) == (ExtiLine)) ? true : false);
    }


    /**
     * @brief  Indicate if ExtiLine Event request is enabled for Lines in range 32 to 63 for cpu2
     * @rmtoll C2EMR2         EMx           c2EXTIIsEnabledEvent_32_63
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_32
     *         @arg @ref EXTI_LINE_33
     *         @arg @ref EXTI_LINE_34
     *         @arg @ref EXTI_LINE_35
     *         @arg @ref EXTI_LINE_36
     *         @arg @ref EXTI_LINE_37
     *         @arg @ref EXTI_LINE_38
     *         @arg @ref EXTI_LINE_39
     *         @arg @ref EXTI_LINE_40
     *         @arg @ref EXTI_LINE_41
     *         @arg @ref EXTI_LINE_42
     *         @arg @ref EXTI_LINE_43
     *         @arg @ref EXTI_LINE_44
     *         @arg @ref EXTI_LINE_46
     *         @arg @ref EXTI_LINE_47
     *         @arg @ref EXTI_LINE_48
     *         @arg @ref EXTI_LINE_49
     *         @arg @ref EXTI_LINE_50
     *         @arg @ref EXTI_LINE_51
     *         @arg @ref EXTI_LINE_52
     *         @arg @ref EXTI_LINE_53
     *         @arg @ref EXTI_LINE_54
     *         @arg @ref EXTI_LINE_55
     *         @arg @ref EXTI_LINE_56
     *         @arg @ref EXTI_LINE_57
     *         @arg @ref EXTI_LINE_58
     *         @arg @ref EXTI_LINE_59
     *         @arg @ref EXTI_LINE_60
     *         @arg @ref EXTI_LINE_61
     *         @arg @ref EXTI_LINE_62
     *         @arg @ref EXTI_LINE_63
     *         @arg @ref EXTI_LINE_ALL_32_63
     * @retval State of bit (1 or 0).
     */
    inline bool c2EXTIIsEnabledEvent_32_63(EXTILinex_32_63 ExtiLine)
    {
        return ((READ_BIT(EXTI->C2EMR2, ExtiLine) == (ExtiLine)) ? true : false);
    }


    /**
     * @brief  Indicate if ExtiLine Event request is enabled for Lines in range 64 to 95 for cpu2
     * @rmtoll C2EMR3         EMx           c2EXTIIsEnabledEvent_64_95
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_64
     *         @arg @ref EXTI_LINE_65
     *         @arg @ref EXTI_LINE_66
     *         @arg @ref EXTI_LINE_67
     *         @arg @ref EXTI_LINE_68
     *         @arg @ref EXTI_LINE_69
     *         @arg @ref EXTI_LINE_70
     *         @arg @ref EXTI_LINE_71
     *         @arg @ref EXTI_LINE_72
     *         @arg @ref EXTI_LINE_73
     *         @arg @ref EXTI_LINE_74
     *         @arg @ref EXTI_LINE_75
     *         @arg @ref EXTI_LINE_76
     *         @arg @ref EXTI_LINE_77
     *         @arg @ref EXTI_LINE_78
     *         @arg @ref EXTI_LINE_79
     *         @arg @ref EXTI_LINE_80
     *         @arg @ref EXTI_LINE_82
     *         @arg @ref EXTI_LINE_84
     *         @arg @ref EXTI_LINE_85
     *         @arg @ref EXTI_LINE_86
     *         @arg @ref EXTI_LINE_87
     *         @arg @ref EXTI_LINE_ALL_64_95
     * @retval State of bit (1 or 0).
     */
    inline bool c2EXTIIsEnabledEvent_64_95(EXTILinex_64_95 ExtiLine)
    {
        return ((READ_BIT(EXTI->C2EMR3, ExtiLine) == (ExtiLine)) ? true : false);
    }


    #endif /* DUAL_CORE */

    /** @defgroup EXTI_LL_EF_Rising_Trigger_Management Rising_Trigger_Management
     * @{
     */

    /**
     * @brief  Enable ExtiLine Rising Edge Trigger for Lines in range 0 to 31
     * @note The configurable wakeup lines are edge-triggered. No glitch must be
     *       generated on these lines. If a rising edge on a configurable interrupt
     *       line occurs during a write operation in the EXTI_RTSR register, the
     *       pending bit is not set.
     *       Rising and falling edge triggers can be set for
     *       the same interrupt line. In this case, both generate a trigger
     *       condition.
     * @rmtoll RTSR1        RTx           extiEnableRisingTrig_0_31
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_0
     *         @arg @ref EXTI_LINE_1
     *         @arg @ref EXTI_LINE_2
     *         @arg @ref EXTI_LINE_3
     *         @arg @ref EXTI_LINE_4
     *         @arg @ref EXTI_LINE_5
     *         @arg @ref EXTI_LINE_6
     *         @arg @ref EXTI_LINE_7
     *         @arg @ref EXTI_LINE_8
     *         @arg @ref EXTI_LINE_9
     *         @arg @ref EXTI_LINE_10
     *         @arg @ref EXTI_LINE_11
     *         @arg @ref EXTI_LINE_12
     *         @arg @ref EXTI_LINE_13
     *         @arg @ref EXTI_LINE_14
     *         @arg @ref EXTI_LINE_15
     *         @arg @ref EXTI_LINE_16
     *         @arg @ref EXTI_LINE_17
     *         @arg @ref EXTI_LINE_18
     *         @arg @ref EXTI_LINE_19
     *         @arg @ref EXTI_LINE_20
     *         @arg @ref EXTI_LINE_21
     * @retval None
     */
    inline void extiEnableRisingTrig_0_31(EXTILinex_0_31 ExtiLine)
    {
        SET_BIT(EXTI->RTSR1, ExtiLine);
    }

    /**
     * @brief  Enable ExtiLine Rising Edge Trigger for Lines in range 32 to 63
     * @note The configurable wakeup lines are edge-triggered. No glitch must be
     *       generated on these lines. If a rising edge on a configurable interrupt
     *       line occurs during a write operation in the EXTI_RTSR register, the
     *       pending bit is not set.Rising and falling edge triggers can be set for
     *       the same interrupt line. In this case, both generate a trigger
     *       condition.
     * @rmtoll RTSR2        RTx           extiEnableRisingTrig_32_63
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_49
     *         @arg @ref EXTI_LINE_51
     * @retval None
     */
    inline void extiEnableRisingTrig_32_63(EXTILinex_32_63 ExtiLine)
    {
        SET_BIT(EXTI->RTSR2, ExtiLine);
    }

    /**
     * @brief  Enable ExtiLine Rising Edge Trigger for Lines in range 64 to 95
     * @note The configurable wakeup lines are edge-triggered. No glitch must be
     *       generated on these lines. If a rising edge on a configurable interrupt
     *       line occurs during a write operation in the EXTI_RTSR register, the
     *       pending bit is not set.Rising and falling edge triggers can be set for
     *       the same interrupt line. In this case, both generate a trigger
     *       condition.
     * @rmtoll RTSR3        RTx           extiEnableRisingTrig_64_95
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_82 (*)
     *         @arg @ref EXTI_LINE_84 (*)
     *         @arg @ref EXTI_LINE_85
     *         @arg @ref EXTI_LINE_86 (**)
     *
     *         (*) value only defined in dual core devices.
     *         (**) value not defined in all devices.
     * @retval None
     */
    inline void extiEnableRisingTrig_64_95(EXTILinex_64_95 ExtiLine)
    {
        SET_BIT(EXTI->RTSR3, ExtiLine);
    }

    /**
     * @brief  Disable ExtiLine Rising Edge Trigger for Lines in range 0 to 31
     * @note The configurable wakeup lines are edge-triggered. No glitch must be
     *       generated on these lines. If a rising edge on a configurable interrupt
     *       line occurs during a write operation in the EXTI_RTSR register, the
     *       pending bit is not set.
     *       Rising and falling edge triggers can be set for
     *       the same interrupt line. In this case, both generate a trigger
     *       condition.
     * @rmtoll RTSR1        RTx           extiDisableRisingTrig_0_31
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_0
     *         @arg @ref EXTI_LINE_1
     *         @arg @ref EXTI_LINE_2
     *         @arg @ref EXTI_LINE_3
     *         @arg @ref EXTI_LINE_4
     *         @arg @ref EXTI_LINE_5
     *         @arg @ref EXTI_LINE_6
     *         @arg @ref EXTI_LINE_7
     *         @arg @ref EXTI_LINE_8
     *         @arg @ref EXTI_LINE_9
     *         @arg @ref EXTI_LINE_10
     *         @arg @ref EXTI_LINE_11
     *         @arg @ref EXTI_LINE_12
     *         @arg @ref EXTI_LINE_13
     *         @arg @ref EXTI_LINE_14
     *         @arg @ref EXTI_LINE_15
     *         @arg @ref EXTI_LINE_16
     *         @arg @ref EXTI_LINE_17
     *         @arg @ref EXTI_LINE_18
     *         @arg @ref EXTI_LINE_19
     *         @arg @ref EXTI_LINE_20
     *         @arg @ref EXTI_LINE_21
     * @retval None
     */
    inline void extiDisableRisingTrig_0_31(EXTILinex_0_31 ExtiLine)
    {
        CLEAR_BIT(EXTI->RTSR1, ExtiLine);
    }

    /**
     * @brief  Disable ExtiLine Rising Edge Trigger for Lines in range 32 to 63
     * @note The configurable wakeup lines are edge-triggered. No glitch must be
     *       generated on these lines. If a rising edge on a configurable interrupt
     *       line occurs during a write operation in the EXTI_RTSR register, the
     *       pending bit is not set.
     *       Rising and falling edge triggers can be set for
     *       the same interrupt line. In this case, both generate a trigger
     *       condition.
     * @rmtoll RTSR2        RTx           extiDisableRisingTrig_32_63
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_49
     *         @arg @ref EXTI_LINE_51
     * @retval None
     */
    inline void extiDisableRisingTrig_32_63(EXTILinex_32_63 ExtiLine)
    {
        CLEAR_BIT(EXTI->RTSR2, ExtiLine);
    }

    /**
     * @brief  Disable ExtiLine Rising Edge Trigger for Lines in range 64 to 95
     * @note The configurable wakeup lines are edge-triggered. No glitch must be
     *       generated on these lines. If a rising edge on a configurable interrupt
     *       line occurs during a write operation in the EXTI_RTSR register, the
     *       pending bit is not set.
     *       Rising and falling edge triggers can be set for
     *       the same interrupt line. In this case, both generate a trigger
     *       condition.
     * @rmtoll RTSR3        RTx           extiDisableRisingTrig_64_95
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_82 (*)
     *         @arg @ref EXTI_LINE_84 (*)
     *         @arg @ref EXTI_LINE_85
     *         @arg @ref EXTI_LINE_86 (**)
     *
     *         (*) value only defined in dual core devices.
     *         (**) value not defined in all devices.
     * @retval None
     */
    inline void extiDisableRisingTrig_64_95(EXTILinex_64_95 ExtiLine)
    {
        CLEAR_BIT(EXTI->RTSR3, ExtiLine);
    }

    /**
     * @brief  Check if rising edge trigger is enabled for Lines in range 0 to 31
     * @rmtoll RTSR1        RTx           EXTI_IsEnabledRisingTrig_0_31
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_0
     *         @arg @ref EXTI_LINE_1
     *         @arg @ref EXTI_LINE_2
     *         @arg @ref EXTI_LINE_3
     *         @arg @ref EXTI_LINE_4
     *         @arg @ref EXTI_LINE_5
     *         @arg @ref EXTI_LINE_6
     *         @arg @ref EXTI_LINE_7
     *         @arg @ref EXTI_LINE_8
     *         @arg @ref EXTI_LINE_9
     *         @arg @ref EXTI_LINE_10
     *         @arg @ref EXTI_LINE_11
     *         @arg @ref EXTI_LINE_12
     *         @arg @ref EXTI_LINE_13
     *         @arg @ref EXTI_LINE_14
     *         @arg @ref EXTI_LINE_15
     *         @arg @ref EXTI_LINE_16
     *         @arg @ref EXTI_LINE_17
     *         @arg @ref EXTI_LINE_18
     *         @arg @ref EXTI_LINE_19
     *         @arg @ref EXTI_LINE_20
     *         @arg @ref EXTI_LINE_21
     * @retval State of bit (1 or 0).
     */
    inline bool extiIsEnabledRisingTrig_0_31(EXTILinex_0_31 ExtiLine)
    {
        return ((READ_BIT(EXTI->RTSR1, ExtiLine) == (ExtiLine)) ? true : false);
    }


    /**
     * @brief  Check if rising edge trigger is enabled for Lines in range 32 to 63
     * @rmtoll RTSR2        RTx           EXTI_IsEnabledRisingTrig_32_63
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_49
     *         @arg @ref EXTI_LINE_51
     * @retval State of bit (1 or 0).
     */
    inline bool extiIsEnabledRisingTrig_32_63(EXTILinex_32_63 ExtiLine)
    {
        return ((READ_BIT(EXTI->RTSR2, ExtiLine) == (ExtiLine)) ? true : false);
    }

    /**
     * @brief  Check if rising edge trigger is enabled for Lines in range 64 to 95
     * @rmtoll RTSR3        RTx           EXTI_IsEnabledRisingTrig_64_95
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_82 (*)
     *         @arg @ref EXTI_LINE_84 (*)
     *         @arg @ref EXTI_LINE_85
     *         @arg @ref EXTI_LINE_86 (**)
     *
     *         (*) value only defined in dual core devices.
     *         (**) value not defined in all devices.
     * @retval State of bit (1 or 0).
     */
    inline bool extiIsEnabledRisingTrig_64_95(EXTILinex_64_95 ExtiLine)
    {
        return ((READ_BIT(EXTI->RTSR3, ExtiLine) == (ExtiLine)) ? true : false);
    }

    /**
     * @}
     */

    /** @defgroup EXTI_LL_EF_Falling_Trigger_Management Falling_Trigger_Management
     * @{
     */

    /**
     * @brief  Enable ExtiLine Falling Edge Trigger for Lines in range 0 to 31
     * @note The configurable wakeup lines are edge-triggered. No glitch must be
     *       generated on these lines. If a falling edge on a configurable interrupt
     *       line occurs during a write operation in the EXTI_FTSR register, the
     *       pending bit is not set.
     *       Rising and falling edge triggers can be set for
     *       the same interrupt line. In this case, both generate a trigger
     *       condition.
     * @rmtoll FTSR1        FTx           extiEnableFallingTrig_0_31
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_0
     *         @arg @ref EXTI_LINE_1
     *         @arg @ref EXTI_LINE_2
     *         @arg @ref EXTI_LINE_3
     *         @arg @ref EXTI_LINE_4
     *         @arg @ref EXTI_LINE_5
     *         @arg @ref EXTI_LINE_6
     *         @arg @ref EXTI_LINE_7
     *         @arg @ref EXTI_LINE_8
     *         @arg @ref EXTI_LINE_9
     *         @arg @ref EXTI_LINE_10
     *         @arg @ref EXTI_LINE_11
     *         @arg @ref EXTI_LINE_12
     *         @arg @ref EXTI_LINE_13
     *         @arg @ref EXTI_LINE_14
     *         @arg @ref EXTI_LINE_15
     *         @arg @ref EXTI_LINE_16
     *         @arg @ref EXTI_LINE_18
     *         @arg @ref EXTI_LINE_19
     *         @arg @ref EXTI_LINE_20
     *         @arg @ref EXTI_LINE_21
     * @note   Please check each device line mapping for EXTI Line availability
     * @retval None
     */
    inline void extiEnableFallingTrig_0_31(EXTILinex_0_31 ExtiLine)
    {
        SET_BIT(EXTI->FTSR1, ExtiLine);
    }

    /**
     * @brief  Enable ExtiLine Falling Edge Trigger for Lines in range 32 to 63
     * @note The configurable wakeup lines are edge-triggered. No glitch must be
     *       generated on these lines. If a Falling edge on a configurable interrupt
     *       line occurs during a write operation in the EXTI_FTSR register, the
     *       pending bit is not set.
     *       Rising and falling edge triggers can be set for
     *       the same interrupt line. In this case, both generate a trigger
     *       condition.
     * @rmtoll FTSR2        FTx           extiEnableFallingTrig_32_63
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_49
     *         @arg @ref EXTI_LINE_51
     * @retval None
     */
    inline void extiEnableFallingTrig_32_63(EXTILinex_32_63 ExtiLine)
    {
        SET_BIT(EXTI->FTSR2, ExtiLine);
    }

    /**
     * @brief  Enable ExtiLine Falling Edge Trigger for Lines in range 64 to 95
     * @note The configurable wakeup lines are edge-triggered. No glitch must be
     *       generated on these lines. If a Falling edge on a configurable interrupt
     *       line occurs during a write operation in the EXTI_FTSR register, the
     *       pending bit is not set.
     *       Rising and falling edge triggers can be set for
     *       the same interrupt line. In this case, both generate a trigger
     *       condition.
     * @rmtoll FTSR3        FTx           extiEnableFallingTrig_64_95
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_82 (*)
     *         @arg @ref EXTI_LINE_84 (*)
     *         @arg @ref EXTI_LINE_85
     *         @arg @ref EXTI_LINE_86 (**)
     *
     *         (*) value only defined in dual core devices.
     *         (**) value not defined in all devices.
     * @retval None
     */
    inline void extiEnableFallingTrig_64_95(EXTILinex_64_95 ExtiLine)
    {
        SET_BIT(EXTI->FTSR3, ExtiLine);
    }


    /**
     * @brief  Disable ExtiLine Falling Edge Trigger for Lines in range 0 to 31
     * @note The configurable wakeup lines are edge-triggered. No glitch must be
     *       generated on these lines. If a Falling edge on a configurable interrupt
     *       line occurs during a write operation in the EXTI_FTSR register, the
     *       pending bit is not set.
     *       Rising and falling edge triggers can be set for the same interrupt line.
     *       In this case, both generate a trigger condition.
     * @rmtoll FTSR1        FTx           extiDisableFallingTrig_0_31
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_0
     *         @arg @ref EXTI_LINE_1
     *         @arg @ref EXTI_LINE_2
     *         @arg @ref EXTI_LINE_3
     *         @arg @ref EXTI_LINE_4
     *         @arg @ref EXTI_LINE_5
     *         @arg @ref EXTI_LINE_6
     *         @arg @ref EXTI_LINE_7
     *         @arg @ref EXTI_LINE_8
     *         @arg @ref EXTI_LINE_9
     *         @arg @ref EXTI_LINE_10
     *         @arg @ref EXTI_LINE_11
     *         @arg @ref EXTI_LINE_12
     *         @arg @ref EXTI_LINE_13
     *         @arg @ref EXTI_LINE_14
     *         @arg @ref EXTI_LINE_15
     *         @arg @ref EXTI_LINE_16
     *         @arg @ref EXTI_LINE_18
     *         @arg @ref EXTI_LINE_19
     *         @arg @ref EXTI_LINE_20
     *         @arg @ref EXTI_LINE_21
     * @note   Please check each device line mapping for EXTI Line availability
     * @retval None
     */
    inline void extiDisableFallingTrig_0_31(EXTILinex_0_31 ExtiLine)
    {
        CLEAR_BIT(EXTI->FTSR1, ExtiLine);
    }

    /**
     * @brief  Disable ExtiLine Falling Edge Trigger for Lines in range 32 to 63
     * @note The configurable wakeup lines are edge-triggered. No glitch must be
     *       generated on these lines. If a Falling edge on a configurable interrupt
     *       line occurs during a write operation in the EXTI_FTSR register, the
     *       pending bit is not set.
     *       Rising and falling edge triggers can be set for the same interrupt line.
     *       In this case, both generate a trigger condition.
     * @rmtoll FTSR2        FTx           extiDisableFallingTrig_32_63
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_49
     *         @arg @ref EXTI_LINE_51
     * @retval None
     */
    inline void extiDisableFallingTrig_32_63(EXTILinex_32_63 ExtiLine)
    {
        CLEAR_BIT(EXTI->FTSR2, ExtiLine);
    }

    /**
     * @brief  Disable ExtiLine Falling Edge Trigger for Lines in range 64 to 95
     * @note The configurable wakeup lines are edge-triggered. No glitch must be
     *       generated on these lines. If a Falling edge on a configurable interrupt
     *       line occurs during a write operation in the EXTI_FTSR register, the
     *       pending bit is not set.
     *       Rising and falling edge triggers can be set for the same interrupt line.
     *       In this case, both generate a trigger condition.
     * @rmtoll FTSR3        FTx           extiDisableFallingTrig_64_95
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_82 (*)
     *         @arg @ref EXTI_LINE_84 (*)
     *         @arg @ref EXTI_LINE_85
     *         @arg @ref EXTI_LINE_86 (**)
     *
     *         (*) value only defined in dual core devices.
     *         (**) value not defined in all devices.
     * @retval None
     */
    inline void extiDisableFallingTrig_64_95(EXTILinex_64_95 ExtiLine)
    {
        CLEAR_BIT(EXTI->FTSR3, ExtiLine);
    }


    /**
     * @brief  Check if falling edge trigger is enabled for Lines in range 0 to 31
     * @rmtoll FTSR1        FTx           EXTI_IsEnabledFallingTrig_0_31
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_0
     *         @arg @ref EXTI_LINE_1
     *         @arg @ref EXTI_LINE_2
     *         @arg @ref EXTI_LINE_3
     *         @arg @ref EXTI_LINE_4
     *         @arg @ref EXTI_LINE_5
     *         @arg @ref EXTI_LINE_6
     *         @arg @ref EXTI_LINE_7
     *         @arg @ref EXTI_LINE_8
     *         @arg @ref EXTI_LINE_9
     *         @arg @ref EXTI_LINE_10
     *         @arg @ref EXTI_LINE_11
     *         @arg @ref EXTI_LINE_12
     *         @arg @ref EXTI_LINE_13
     *         @arg @ref EXTI_LINE_14
     *         @arg @ref EXTI_LINE_15
     *         @arg @ref EXTI_LINE_16
     *         @arg @ref EXTI_LINE_18
     *         @arg @ref EXTI_LINE_19
     *         @arg @ref EXTI_LINE_20
     *         @arg @ref EXTI_LINE_21
     * @note   Please check each device line mapping for EXTI Line availability
     * @retval State of bit (1 or 0).
     */
    inline bool extiIsEnabledFallingTrig_0_31(EXTILinex_0_31 ExtiLine)
    {
        return ((READ_BIT(EXTI->FTSR1, ExtiLine) == (ExtiLine)) ? true : false);
    }

    /**
     * @brief  Check if falling edge trigger is enabled for Lines in range 32 to 63
     * @rmtoll FTSR2        FTx           EXTI_IsEnabledFallingTrig_32_63
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_49
     *         @arg @ref EXTI_LINE_51
     * @retval State of bit (1 or 0).
     */
    inline bool extiIsEnabledFallingTrig_32_63(EXTILinex_32_63 ExtiLine)
    {
        return ((READ_BIT(EXTI->FTSR2, ExtiLine) == (ExtiLine)) ? true : false);
    }

    /**
     * @brief  Check if falling edge trigger is enabled for Lines in range 64 to 95
     * @rmtoll FTSR3        FTx           EXTI_IsEnabledFallingTrig_64_95
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_82 (*)
     *         @arg @ref EXTI_LINE_84 (*)
     *         @arg @ref EXTI_LINE_85
     *         @arg @ref EXTI_LINE_86 (**)
     *
     *         (*) value only defined in dual core devices.
     *         (**) value not defined in all devices.
     * @retval State of bit (1 or 0).
     */
    inline bool extiIsEnabledFallingTrig_64_95(EXTILinex_64_95 ExtiLine)
    {
        return ((READ_BIT(EXTI->FTSR3, ExtiLine) == (ExtiLine)) ? true : false);
    }

    /** @defgroup EXTI_LL_EF_Software_Interrupt_Management Software_Interrupt_Management
     * @{
     */

    /**
     * @brief  Generate a software Interrupt Event for Lines in range 0 to 31
     * @note If the interrupt is enabled on this line in the EXTI_C1IMR1, writing a 1 to
     *       this bit when it is at '0' sets the corresponding pending bit in EXTI_PR1
     *       resulting in an interrupt request generation.
     *       This bit is cleared by clearing the corresponding bit in the EXTI_PR1
     *       register (by writing a 1 into the bit)
     * @rmtoll SWIER1       SWIx          extiGenerateSWI_0_31
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_0
     *         @arg @ref EXTI_LINE_1
     *         @arg @ref EXTI_LINE_2
     *         @arg @ref EXTI_LINE_3
     *         @arg @ref EXTI_LINE_4
     *         @arg @ref EXTI_LINE_5
     *         @arg @ref EXTI_LINE_6
     *         @arg @ref EXTI_LINE_7
     *         @arg @ref EXTI_LINE_8
     *         @arg @ref EXTI_LINE_9
     *         @arg @ref EXTI_LINE_10
     *         @arg @ref EXTI_LINE_11
     *         @arg @ref EXTI_LINE_12
     *         @arg @ref EXTI_LINE_13
     *         @arg @ref EXTI_LINE_14
     *         @arg @ref EXTI_LINE_15
     *         @arg @ref EXTI_LINE_16
     *         @arg @ref EXTI_LINE_18
     *         @arg @ref EXTI_LINE_19
     *         @arg @ref EXTI_LINE_20
     *         @arg @ref EXTI_LINE_21
     * @note   Please check each device line mapping for EXTI Line availability
     * @retval None
     */
    inline void extiGenerateSWI_0_31(EXTILinex_0_31 ExtiLine)
    {
        SET_BIT(EXTI->SWIER1, ExtiLine);
    }

    /**
     * @brief  Generate a software Interrupt Event for Lines in range 32 to 63
     * @note If the interrupt is enabled on this line in the EXTI_IMR2, writing a 1 to
     *       this bit when it is at '0' sets the corresponding pending bit in EXTI_PR2
     *       resulting in an interrupt request generation.
     *       This bit is cleared by clearing the corresponding bit in the EXTI_PR2
     *       register (by writing a 1 into the bit)
     * @rmtoll SWIER2       SWIx          extiGenerateSWI_32_63
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_49
     *         @arg @ref EXTI_LINE_51
     * @retval None
     */
    inline void extiGenerateSWI_32_63(EXTILinex_32_63 ExtiLine)
    {
        SET_BIT(EXTI->SWIER2, ExtiLine);
    }

    /**
     * @brief  Generate a software Interrupt Event for Lines in range 64 to 95
     * @note If the interrupt is enabled on this line in the EXTI_IMR2, writing a 1 to
     *       this bit when it is at '0' sets the corresponding pending bit in EXTI_PR2
     *       resulting in an interrupt request generation.
     *       This bit is cleared by clearing the corresponding bit in the EXTI_PR3
     *       register (by writing a 1 into the bit)
     * @rmtoll SWIER3       SWIx          extiGenerateSWI_64_95
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_82 (*)
     *         @arg @ref EXTI_LINE_84 (*)
     *         @arg @ref EXTI_LINE_85
     *         @arg @ref EXTI_LINE_86 (**)
     *
     *         (*) value only defined in dual core devices.
     *         (**) value not defined in all devices.
     * @retval None
     */
    inline void extiGenerateSWI_64_95(EXTILinex_64_95 ExtiLine)
    {
        SET_BIT(EXTI->SWIER3, ExtiLine);
    }

    /** @defgroup EXTI_LL_EF_Flag_Management Flag_Management
     * @{
     */

    /**
     * @brief  Check if the ExtLine Flag is set or not for Lines in range 0 to 31
     * @note This bit is set when the selected edge event arrives on the interrupt
     *       line. This bit is cleared by writing a 1 to the bit.
     * @rmtoll PR1          PIFx           EXTI_IsActiveFlag_0_31
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_0
     *         @arg @ref EXTI_LINE_1
     *         @arg @ref EXTI_LINE_2
     *         @arg @ref EXTI_LINE_3
     *         @arg @ref EXTI_LINE_4
     *         @arg @ref EXTI_LINE_5
     *         @arg @ref EXTI_LINE_6
     *         @arg @ref EXTI_LINE_7
     *         @arg @ref EXTI_LINE_8
     *         @arg @ref EXTI_LINE_9
     *         @arg @ref EXTI_LINE_10
     *         @arg @ref EXTI_LINE_11
     *         @arg @ref EXTI_LINE_12
     *         @arg @ref EXTI_LINE_13
     *         @arg @ref EXTI_LINE_14
     *         @arg @ref EXTI_LINE_15
     *         @arg @ref EXTI_LINE_16
     *         @arg @ref EXTI_LINE_17
     *         @arg @ref EXTI_LINE_18
     *         @arg @ref EXTI_LINE_19
     *         @arg @ref EXTI_LINE_20
     *         @arg @ref EXTI_LINE_21
     *         @arg @ref EXTI_LINE_ALL_0_31
     * @retval State of bit (1 or 0).
     */
    inline bool extiIsActiveFlag_0_31(EXTILinex_0_31 ExtiLine)
    {
        return ((READ_BIT(EXTI->PR1, ExtiLine) == (ExtiLine)) ? true : false);
    }

    /**
     * @brief  Check if the ExtLine Flag is set or not for  Lines in range 32 to 63
     * @note This bit is set when the selected edge event arrives on the interrupt
     *       line. This bit is cleared by writing a 1 to the bit.
     * @rmtoll PR2          PIFx           EXTI_IsActiveFlag_32_63
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_49
     *         @arg @ref EXTI_LINE_51
     *         @arg @ref EXTI_LINE_ALL_32_63
     * @retval State of bit (1 or 0).
     */
    inline bool extiIsActiveFlag_32_63(EXTILinex_32_63 ExtiLine)
    {
        return ((READ_BIT(EXTI->PR2, ExtiLine) == (ExtiLine)) ? true : false);
    }

    /**
     * @brief  Check if the ExtLine Flag is set or not for  Lines in range 64 to 95
     * @note This bit is set when the selected edge event arrives on the interrupt
     *       line. This bit is cleared by writing a 1 to the bit.
     * @rmtoll PR3          PIFx           EXTI_IsActiveFlag_64_95
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_82 (*)
     *         @arg @ref EXTI_LINE_84 (*)
     *         @arg @ref EXTI_LINE_85
     *         @arg @ref EXTI_LINE_86 (**)
     *
     *         (*) value only defined in dual core devices.
     *         (**) value not defined in all devices.
     * @retval State of bit (1 or 0).
     */
    inline bool extiIsActiveFlag_64_95(EXTILinex_64_95 ExtiLine)
    {
        return ((READ_BIT(EXTI->PR3, ExtiLine) == (ExtiLine)) ? true : false);
    }


    /**
     * @brief  Read ExtLine Combination Flag for Lines in range 0 to 31
     * @note This bit is set when the selected edge event arrives on the interrupt
     *       line. This bit is cleared by writing a 1 to the bit.
     * @rmtoll PR1          PIFx           extiReadFlag_0_31
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_0
     *         @arg @ref EXTI_LINE_1
     *         @arg @ref EXTI_LINE_2
     *         @arg @ref EXTI_LINE_3
     *         @arg @ref EXTI_LINE_4
     *         @arg @ref EXTI_LINE_5
     *         @arg @ref EXTI_LINE_6
     *         @arg @ref EXTI_LINE_7
     *         @arg @ref EXTI_LINE_8
     *         @arg @ref EXTI_LINE_9
     *         @arg @ref EXTI_LINE_10
     *         @arg @ref EXTI_LINE_11
     *         @arg @ref EXTI_LINE_12
     *         @arg @ref EXTI_LINE_13
     *         @arg @ref EXTI_LINE_14
     *         @arg @ref EXTI_LINE_15
     *         @arg @ref EXTI_LINE_16
     *         @arg @ref EXTI_LINE_17
     *         @arg @ref EXTI_LINE_18
     *         @arg @ref EXTI_LINE_19
     *         @arg @ref EXTI_LINE_20
     *         @arg @ref EXTI_LINE_21
     * @retval @note This bit is set when the selected edge event arrives on the interrupt
     */
    inline uint32_t extiReadFlag_0_31(EXTILinex_0_31 ExtiLine)
    {
        return (uint32_t)(READ_BIT(EXTI->PR1, ExtiLine));
    }


    /**
     * @brief  Read ExtLine Combination Flag for  Lines in range 32 to 63
     * @note This bit is set when the selected edge event arrives on the interrupt
     *       line. This bit is cleared by writing a 1 to the bit.
     * @rmtoll PR2          PIFx           extiReadFlag_32_63
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_49
     *         @arg @ref EXTI_LINE_51
     * @retval @note This bit is set when the selected edge event arrives on the interrupt
     */
    inline uint32_t extiReadFlag_32_63(EXTILinex_32_63 ExtiLine)
    {
        return (uint32_t)(READ_BIT(EXTI->PR2, ExtiLine));
    }


    /**
     * @brief  Read ExtLine Combination Flag for  Lines in range 64 to 95
     * @note This bit is set when the selected edge event arrives on the interrupt
     *       line. This bit is cleared by writing a 1 to the bit.
     * @rmtoll PR3          PIFx           extiReadFlag_64_95
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_82 (*)
     *         @arg @ref EXTI_LINE_84 (*)
     *         @arg @ref EXTI_LINE_85
     *         @arg @ref EXTI_LINE_86 (**)
     *
     *         (*) value only defined in dual core devices.
     *         (**) value not defined in all devices.
     * @retval @note This bit is set when the selected edge event arrives on the interrupt
     */
    inline uint32_t extiReadFlag_64_95(EXTILinex_64_95 ExtiLine)
    {
        return (uint32_t)(READ_BIT(EXTI->PR3, ExtiLine));
    }

    /**
     * @brief  Clear ExtLine Flags for Lines in range 0 to 31
     * @note This bit is set when the selected edge event arrives on the interrupt
     *       line. This bit is cleared by writing a 1 to the bit.
     * @rmtoll PR1          PIFx           extiClearFlag_0_31
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_0
     *         @arg @ref EXTI_LINE_1
     *         @arg @ref EXTI_LINE_2
     *         @arg @ref EXTI_LINE_3
     *         @arg @ref EXTI_LINE_4
     *         @arg @ref EXTI_LINE_5
     *         @arg @ref EXTI_LINE_6
     *         @arg @ref EXTI_LINE_7
     *         @arg @ref EXTI_LINE_8
     *         @arg @ref EXTI_LINE_9
     *         @arg @ref EXTI_LINE_10
     *         @arg @ref EXTI_LINE_11
     *         @arg @ref EXTI_LINE_12
     *         @arg @ref EXTI_LINE_13
     *         @arg @ref EXTI_LINE_14
     *         @arg @ref EXTI_LINE_15
     *         @arg @ref EXTI_LINE_16
     *         @arg @ref EXTI_LINE_17
     *         @arg @ref EXTI_LINE_18
     *         @arg @ref EXTI_LINE_19
     *         @arg @ref EXTI_LINE_20
     *         @arg @ref EXTI_LINE_21
     * @retval None
     */
    inline void extiClearFlag_0_31(EXTILinex_0_31 ExtiLine)
    {
        WRITE_REG(EXTI->PR1, ExtiLine);
    }

    /**
     * @brief  Clear ExtLine Flags for Lines in range 32 to 63
     * @note This bit is set when the selected edge event arrives on the interrupt
     *       line. This bit is cleared by writing a 1 to the bit.
     * @rmtoll PR2          PIFx           extiClearFlag_32_63
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_49
     *         @arg @ref EXTI_LINE_51
     * @retval None
     */
    inline void extiClearFlag_32_63(EXTILinex_32_63 ExtiLine)
    {
        WRITE_REG(EXTI->PR2, ExtiLine);
    }

    /**
     * @brief  Clear ExtLine Flags for Lines in range 64 to 95
     * @note This bit is set when the selected edge event arrives on the interrupt
     *       line. This bit is cleared by writing a 1 to the bit.
     * @rmtoll PR3          PIFx           extiClearFlag_64_95
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_82 (*)
     *         @arg @ref EXTI_LINE_84 (*)
     *         @arg @ref EXTI_LINE_85
     *         @arg @ref EXTI_LINE_86 (**)
     *
     *         (*) value only defined in dual core devices.
     *         (**) value not defined in all devices.
     * @retval None
     */
    inline void extiClearFlag_64_95(EXTILinex_64_95 ExtiLine)
    {
        WRITE_REG(EXTI->PR3, ExtiLine);
    }

    #if defined(DUAL_CORE)

    /**
     * @brief  Check if the ExtLine Flag is set or not for Lines in range 0 to 31 for cpu2
     * @note This bit is set when the selected edge event arrives on the interrupt
     *       line. This bit is cleared by writing a 1 to the bit.
     * @rmtoll C2PR1          PIFx           c2EXTIIsActiveFlag_0_31
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_0
     *         @arg @ref EXTI_LINE_1
     *         @arg @ref EXTI_LINE_2
     *         @arg @ref EXTI_LINE_3
     *         @arg @ref EXTI_LINE_4
     *         @arg @ref EXTI_LINE_5
     *         @arg @ref EXTI_LINE_6
     *         @arg @ref EXTI_LINE_7
     *         @arg @ref EXTI_LINE_8
     *         @arg @ref EXTI_LINE_9
     *         @arg @ref EXTI_LINE_10
     *         @arg @ref EXTI_LINE_11
     *         @arg @ref EXTI_LINE_12
     *         @arg @ref EXTI_LINE_13
     *         @arg @ref EXTI_LINE_14
     *         @arg @ref EXTI_LINE_15
     *         @arg @ref EXTI_LINE_16
     *         @arg @ref EXTI_LINE_17
     *         @arg @ref EXTI_LINE_18
     *         @arg @ref EXTI_LINE_19
     *         @arg @ref EXTI_LINE_20
     *         @arg @ref EXTI_LINE_21
     *         @arg @ref EXTI_LINE_ALL_0_31
     * @retval State of bit (1 or 0).
     */
    inline bool c2EXTIIsActiveFlag_0_31(EXTILinex_0_31 ExtiLine)
    {
        return ((READ_BIT(EXTI->C2PR1, ExtiLine) == (ExtiLine)) ? true : false);
    }

    /**
     * @brief  Check if the ExtLine Flag is set or not for  Lines in range 32 to 63 for cpu2
     * @note This bit is set when the selected edge event arrives on the interrupt
     *       line. This bit is cleared by writing a 1 to the bit.
     * @rmtoll C2PR2          PIFx           c2EXTIIsActiveFlag_32_63
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_49
     *         @arg @ref EXTI_LINE_51
     *         @arg @ref EXTI_LINE_ALL_32_63
     * @retval State of bit (1 or 0).
     */
    inline bool c2EXTIIsActiveFlag_32_63(EXTILinex_32_63 ExtiLine)
    {
        return ((READ_BIT(EXTI->C2PR2, ExtiLine) == (ExtiLine)) ? true : false);
    }

    /**
     * @brief  Check if the ExtLine Flag is set or not for  Lines in range 64 to 95 for cpu2
     * @note This bit is set when the selected edge event arrives on the interrupt
     *       line. This bit is cleared by writing a 1 to the bit.
     * @rmtoll C2PR3          PIFx           c2EXTIIsActiveFlag_64_95
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_82
     *         @arg @ref EXTI_LINE_84
     *         @arg @ref EXTI_LINE_85
     *         @arg @ref EXTI_LINE_86
     *         @arg @ref EXTI_LINE_ALL_64_95
     * @retval State of bit (1 or 0).
     */
    inline bool c2EXTIIsActiveFlag_64_95(EXTILinex_64_95 ExtiLine)
    {
        return ((READ_BIT(EXTI->C2PR3, ExtiLine) == (ExtiLine)) ? true : false);
    }

    /**
     * @brief  Read ExtLine Combination Flag for Lines in range 0 to 31 for cpu2
     * @note This bit is set when the selected edge event arrives on the interrupt
     *       line. This bit is cleared by writing a 1 to the bit.
     * @rmtoll C2PR1          PIFx           c2EXTIReadFlag_0_31
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_0
     *         @arg @ref EXTI_LINE_1
     *         @arg @ref EXTI_LINE_2
     *         @arg @ref EXTI_LINE_3
     *         @arg @ref EXTI_LINE_4
     *         @arg @ref EXTI_LINE_5
     *         @arg @ref EXTI_LINE_6
     *         @arg @ref EXTI_LINE_7
     *         @arg @ref EXTI_LINE_8
     *         @arg @ref EXTI_LINE_9
     *         @arg @ref EXTI_LINE_10
     *         @arg @ref EXTI_LINE_11
     *         @arg @ref EXTI_LINE_12
     *         @arg @ref EXTI_LINE_13
     *         @arg @ref EXTI_LINE_14
     *         @arg @ref EXTI_LINE_15
     *         @arg @ref EXTI_LINE_16
     *         @arg @ref EXTI_LINE_17
     *         @arg @ref EXTI_LINE_18
     *         @arg @ref EXTI_LINE_19
     *         @arg @ref EXTI_LINE_20
     *         @arg @ref EXTI_LINE_21
     * @retval @note This bit is set when the selected edge event arrives on the interrupt
     */
    inline uint32_t c2EXTIReadFlag_0_31(EXTILinex_0_31 ExtiLine)
    {
        return (uint32_t)(READ_BIT(EXTI->C2PR1, ExtiLine));
    }

    /**
     * @brief  Read ExtLine Combination Flag for  Lines in range 32 to 63 for cpu2
     * @note This bit is set when the selected edge event arrives on the interrupt
     *       line. This bit is cleared by writing a 1 to the bit.
     * @rmtoll C2PR2          PIFx           c2EXTIReadFlag_32_63
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_49
     *         @arg @ref EXTI_LINE_51
     * @retval @note This bit is set when the selected edge event arrives on the interrupt
     */
    inline uint32_t c2EXTIReadFlag_32_63(EXTILinex_32_63 ExtiLine)
    {
        return (uint32_t)(READ_BIT(EXTI->C2PR2, ExtiLine));
    }


    /**
     * @brief  Read ExtLine Combination Flag for  Lines in range 64 to 95 for cpu2
     * @note This bit is set when the selected edge event arrives on the interrupt
     *       line. This bit is cleared by writing a 1 to the bit.
     * @rmtoll C2PR3          PIFx           c2EXTIReadFlag_64_95
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_82
     *         @arg @ref EXTI_LINE_84
     *         @arg @ref EXTI_LINE_85
     *         @arg @ref EXTI_LINE_86
     * @retval @note This bit is set when the selected edge event arrives on the interrupt
     */
    inline uint32_t c2EXTIReadFlag_64_95(EXTILinex_64_95 ExtiLine)
    {
        return (uint32_t)(READ_BIT(EXTI->C2PR3, ExtiLine));
    }
    /**
     * @brief  Clear ExtLine Flags for Lines in range 0 to 31 for cpu2
     * @note This bit is set when the selected edge event arrives on the interrupt
     *       line. This bit is cleared by writing a 1 to the bit.
     * @rmtoll C2PR1          PIFx           c2EXTIClearFlag_0_31
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_0
     *         @arg @ref EXTI_LINE_1
     *         @arg @ref EXTI_LINE_2
     *         @arg @ref EXTI_LINE_3
     *         @arg @ref EXTI_LINE_4
     *         @arg @ref EXTI_LINE_5
     *         @arg @ref EXTI_LINE_6
     *         @arg @ref EXTI_LINE_7
     *         @arg @ref EXTI_LINE_8
     *         @arg @ref EXTI_LINE_9
     *         @arg @ref EXTI_LINE_10
     *         @arg @ref EXTI_LINE_11
     *         @arg @ref EXTI_LINE_12
     *         @arg @ref EXTI_LINE_13
     *         @arg @ref EXTI_LINE_14
     *         @arg @ref EXTI_LINE_15
     *         @arg @ref EXTI_LINE_16
     *         @arg @ref EXTI_LINE_17
     *         @arg @ref EXTI_LINE_18
     *         @arg @ref EXTI_LINE_19
     *         @arg @ref EXTI_LINE_20
     *         @arg @ref EXTI_LINE_21
     * @retval None
     */
    inline void c2EXTIClearFlag_0_31(EXTILinex_0_31 ExtiLine)
    {
        WRITE_REG(EXTI->C2PR1, ExtiLine);
    }

    /**
     * @brief  Clear ExtLine Flags for Lines in range 32 to 63 for cpu2
     * @note This bit is set when the selected edge event arrives on the interrupt
     *       line. This bit is cleared by writing a 1 to the bit.
     * @rmtoll C2PR2          PIFx           c2EXTIClearFlag_32_63
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_49
     *         @arg @ref EXTI_LINE_51
     * @retval None
     */
    inline void c2EXTIClearFlag_32_63(EXTILinex_32_63 ExtiLine)
    {
        WRITE_REG(EXTI->C2PR2, ExtiLine);
    }

    /**
     * @brief  Clear ExtLine Flags for Lines in range 64 to 95 for cpu2
     * @note This bit is set when the selected edge event arrives on the interrupt
     *       line. This bit is cleared by writing a 1 to the bit.
     * @rmtoll C2PR3          PIFx           c2EXTIClearFlag_64_95
     * @param  ExtiLine This parameter can be a combination of the following values:
     *         @arg @ref EXTI_LINE_82
     *         @arg @ref EXTI_LINE_84
     *         @arg @ref EXTI_LINE_85
     *         @arg @ref EXTI_LINE_86
     * @retval None
     */
    inline void c2EXTIClearFlag_64_95(EXTILinex_64_95 ExtiLine)
    {
        WRITE_REG(EXTI->C2PR3, ExtiLine);
    }

    #endif /* DUAL_CORE */

    /**
     * @brief  Enable ExtiLine D3 Pending Mask for Lines in range 0 to 31
     * @rmtoll D3PMR1         MRx           d3EXTIEnablePendMask_0_31
     * @param  ExtiLine This parameter can be one of the following values:
     *         @arg @ref EXTI_LINE_0
     *         @arg @ref EXTI_LINE_1
     *         @arg @ref EXTI_LINE_2
     *         @arg @ref EXTI_LINE_3
     *         @arg @ref EXTI_LINE_4
     *         @arg @ref EXTI_LINE_5
     *         @arg @ref EXTI_LINE_6
     *         @arg @ref EXTI_LINE_7
     *         @arg @ref EXTI_LINE_8
     *         @arg @ref EXTI_LINE_9
     *         @arg @ref EXTI_LINE_10
     *         @arg @ref EXTI_LINE_11
     *         @arg @ref EXTI_LINE_12
     *         @arg @ref EXTI_LINE_13
     *         @arg @ref EXTI_LINE_14
     *         @arg @ref EXTI_LINE_15
     *         @arg @ref EXTI_LINE_19
     *         @arg @ref EXTI_LINE_20
     *         @arg @ref EXTI_LINE_21
     *         @arg @ref EXTI_LINE_25
     * @retval None
     */
    inline void d3EXTIEnablePendMask_0_31(EXTILinex_0_31 ExtiLine)
    {
        SET_BIT(EXTI->D3PMR1, ExtiLine);
    }

    /**
     * @brief  Enable ExtiLine D3 Pending Mask for Lines in range 32 to 63
     * @rmtoll D3PMR2         MRx           d3EXTIEnablePendMask_32_63
     * @param  ExtiLine This parameter can be one of the following values:
     *         @arg @ref EXTI_LINE_34
     *         @arg @ref EXTI_LINE_35
     *         @arg @ref EXTI_LINE_41
     *         @arg @ref EXTI_LINE_48
     *         @arg @ref EXTI_LINE_49
     *         @arg @ref EXTI_LINE_50
     *         @arg @ref EXTI_LINE_51
     *         @arg @ref EXTI_LINE_52
     *         @arg @ref EXTI_LINE_53
     * @retval None
     */
    inline void d3EXTIEnablePendMask_32_63(EXTILinex_32_63 ExtiLine)
    {
        SET_BIT(EXTI->D3PMR2, ExtiLine);
    }

    /**
     * @brief  Disable ExtiLine D3 Pending Mask for Lines in range 0 to 31
     * @rmtoll D3PMR1         MRx           d3EXTIDisablePendMask_0_31
     * @param  ExtiLine This parameter can be one of the following values:
     *         @arg @ref EXTI_LINE_0
     *         @arg @ref EXTI_LINE_1
     *         @arg @ref EXTI_LINE_2
     *         @arg @ref EXTI_LINE_3
     *         @arg @ref EXTI_LINE_4
     *         @arg @ref EXTI_LINE_5
     *         @arg @ref EXTI_LINE_6
     *         @arg @ref EXTI_LINE_7
     *         @arg @ref EXTI_LINE_8
     *         @arg @ref EXTI_LINE_9
     *         @arg @ref EXTI_LINE_10
     *         @arg @ref EXTI_LINE_11
     *         @arg @ref EXTI_LINE_12
     *         @arg @ref EXTI_LINE_13
     *         @arg @ref EXTI_LINE_14
     *         @arg @ref EXTI_LINE_15
     *         @arg @ref EXTI_LINE_19
     *         @arg @ref EXTI_LINE_20
     *         @arg @ref EXTI_LINE_21
     *         @arg @ref EXTI_LINE_25
     * @retval None
     */
    inline void d3EXTIDisablePendMask_0_31(EXTILinex_0_31 ExtiLine)
    {
        CLEAR_BIT(EXTI->D3PMR1, ExtiLine);
    }

    /**
     * @brief  Disable ExtiLine D3 Pending Mask for Lines in range 32 to 63
     * @rmtoll D3PMR2         MRx           d3EXTIDisablePendMask_32_63
     * @param  ExtiLine This parameter can be one of the following values:
     *         @arg @ref EXTI_LINE_34
     *         @arg @ref EXTI_LINE_35
     *         @arg @ref EXTI_LINE_41
     *         @arg @ref EXTI_LINE_48
     *         @arg @ref EXTI_LINE_49
     *         @arg @ref EXTI_LINE_50
     *         @arg @ref EXTI_LINE_51
     *         @arg @ref EXTI_LINE_52
     *         @arg @ref EXTI_LINE_53
     * @retval None
     */
    inline void d3EXTIDisablePendMask_32_63(EXTILinex_32_63 ExtiLine)
    {
        CLEAR_BIT(EXTI->D3PMR2, ExtiLine);
    }

    /**
     * @brief  Indicate if ExtiLine D3 Pending Mask is enabled for Lines in range 0 to 31
     * @rmtoll D3PMR1         MRx           d3EXTIIsEnabledPendMask_0_31
     * @param  ExtiLine This parameter can be one of the following values:
     *         @arg @ref EXTI_LINE_0
     *         @arg @ref EXTI_LINE_1
     *         @arg @ref EXTI_LINE_2
     *         @arg @ref EXTI_LINE_3
     *         @arg @ref EXTI_LINE_4
     *         @arg @ref EXTI_LINE_5
     *         @arg @ref EXTI_LINE_6
     *         @arg @ref EXTI_LINE_7
     *         @arg @ref EXTI_LINE_8
     *         @arg @ref EXTI_LINE_9
     *         @arg @ref EXTI_LINE_10
     *         @arg @ref EXTI_LINE_11
     *         @arg @ref EXTI_LINE_12
     *         @arg @ref EXTI_LINE_13
     *         @arg @ref EXTI_LINE_14
     *         @arg @ref EXTI_LINE_15
     *         @arg @ref EXTI_LINE_19
     *         @arg @ref EXTI_LINE_20
     *         @arg @ref EXTI_LINE_21
     *         @arg @ref EXTI_LINE_25
     * @retval State of bit (1 or 0).
     */
    inline bool d3EXTIIsEnabledPendMask_0_31(EXTILinex_0_31 ExtiLine)
    {
        return ((READ_BIT(EXTI->D3PMR1, ExtiLine) == (ExtiLine)) ? true : false);
    }

    /**
     * @brief  Indicate if ExtiLine D3 Pending Mask is enabled for Lines in range 32 to 63
     * @rmtoll D3PMR2         MRx           d3EXTIIsEnabledPendMask_32_63
     * @param  ExtiLine This parameter can be one of the following values:
     *         @arg @ref EXTI_LINE_34
     *         @arg @ref EXTI_LINE_35
     *         @arg @ref EXTI_LINE_41
     *         @arg @ref EXTI_LINE_48
     *         @arg @ref EXTI_LINE_49
     *         @arg @ref EXTI_LINE_50
     *         @arg @ref EXTI_LINE_51
     *         @arg @ref EXTI_LINE_52
     *         @arg @ref EXTI_LINE_53
     * @retval State of bit (1 or 0).
     */
    inline bool d3EXTIIsEnabledPendMask_32_63(EXTILinex_32_63 ExtiLine)
    {
        return ((READ_BIT(EXTI->D3PMR2, ExtiLine) == (ExtiLine)) ? true : false);
    }

    /**
     * @brief  Set ExtLine D3 Domain Pend Clear Source selection for Lines in range 0 to 15
     * @rmtoll D3PCR1L          PCSx           d3EXTISetPendClearSel_0_15
     * @param  ExtiLine This parameter can be one of the following values:
     *         @arg @ref EXTI_LINE_0
     *         @arg @ref EXTI_LINE_1
     *         @arg @ref EXTI_LINE_2
     *         @arg @ref EXTI_LINE_3
     *         @arg @ref EXTI_LINE_4
     *         @arg @ref EXTI_LINE_5
     *         @arg @ref EXTI_LINE_6
     *         @arg @ref EXTI_LINE_7
     *         @arg @ref EXTI_LINE_8
     *         @arg @ref EXTI_LINE_9
     *         @arg @ref EXTI_LINE_10
     *         @arg @ref EXTI_LINE_11
     *         @arg @ref EXTI_LINE_12
     *         @arg @ref EXTI_LINE_13
     *         @arg @ref EXTI_LINE_14
     *         @arg @ref EXTI_LINE_15
     * @param  ClrSrc This parameter can be one of the following values:
     *         @arg @ref EXTI_D3_PEND_CLR_DMACH6
     *         @arg @ref EXTI_D3_PEND_CLR_DMACH7
     *         @arg @ref EXTI_D3_PEND_CLR_LPTIM4 (*)
     *         @arg @ref EXTI_D3_PEND_CLR_LPTIM5 (*)
     *         @arg @ref EXTI_D3_PEND_CLR_LPTIM2 (*)
     *         @arg @ref EXTI_D3_PEND_CLR_LPTIM3 (*)
     *
     *         (*) value not defined in all devices.
     * @retval None
     */
    inline void d3EXTISetPendClearSel_0_15(int32_t ExtiLine, EXTID3PendClr ClrSrc)
    {
        MODIFY_REG(EXTI->D3PCR1L, ((ExtiLine * ExtiLine) * 3UL), ((ExtiLine * ExtiLine) * ClrSrc));
    }

    /**
     * @brief  Set ExtLine D3 Domain Pend Clear Source selection for Lines in range 16 to 31
     * @rmtoll D3PCR1H          PCSx           d3EXTISetPendClearSel_16_31
     * @param  ExtiLine This parameter can be one of the following values:
     *         @arg @ref EXTI_LINE_19
     *         @arg @ref EXTI_LINE_20
     *         @arg @ref EXTI_LINE_21
     *         @arg @ref EXTI_LINE_25
     * @param  ClrSrc This parameter can be one of the following values:
     *         @arg @ref EXTI_D3_PEND_CLR_DMACH6
     *         @arg @ref EXTI_D3_PEND_CLR_DMACH7
     *         @arg @ref EXTI_D3_PEND_CLR_LPTIM4 (*)
     *         @arg @ref EXTI_D3_PEND_CLR_LPTIM5 (*)
     *         @arg @ref EXTI_D3_PEND_CLR_LPTIM2 (*)
     *         @arg @ref EXTI_D3_PEND_CLR_LPTIM3 (*)
     *
     *         (*) value not defined in all devices.
     * @retval None
     */
    inline void d3EXTISetPendClearSel_16_31(uint32_t ExtiLine, EXTID3PendClr ClrSrc)
    {
        MODIFY_REG(EXTI->D3PCR1H, (((ExtiLine >> EXTI_IMR1_IM16_Pos) * (ExtiLine >> EXTI_IMR1_IM16_Pos)) * 3UL), (((ExtiLine >> EXTI_IMR1_IM16_Pos) * (ExtiLine >> EXTI_IMR1_IM16_Pos)) * ClrSrc));
    }


    /**
     * @brief  Set ExtLine D3 Domain Pend Clear Source selection for Lines in range 32 to 47
     * @rmtoll D3PCR2L          PCSx           d3EXTISetPendClearSel_32_47
     * @param  ExtiLine This parameter can be one of the following values:
     *         @arg @ref EXTI_LINE_34
     *         @arg @ref EXTI_LINE_35
     *         @arg @ref EXTI_LINE_41
     * @param  ClrSrc This parameter can be one of the following values:
     *         @arg @ref EXTI_D3_PEND_CLR_DMACH6
     *         @arg @ref EXTI_D3_PEND_CLR_DMACH7
     *         @arg @ref EXTI_D3_PEND_CLR_LPTIM4 (*)
     *         @arg @ref EXTI_D3_PEND_CLR_LPTIM5 (*)
     *         @arg @ref EXTI_D3_PEND_CLR_LPTIM2 (*)
     *         @arg @ref EXTI_D3_PEND_CLR_LPTIM3 (*)
     *
     *         (*) value not defined in all devices.
     * @retval None
     */
    inline void d3EXTISetPendClearSel_32_47(uint32_t ExtiLine, EXTID3PendClr ClrSrc)
    {
        MODIFY_REG(EXTI->D3PCR2L, ((ExtiLine * ExtiLine) * 3UL), ((ExtiLine * ExtiLine) * ClrSrc));
    }

    /**
     * @brief  Set ExtLine D3 Domain Pend Clear Source selection for Lines in range 48 to 63
     * @rmtoll D3PCR2H          PCSx           d3EXTISetPendClearSel_48_63
     * @param  ExtiLine This parameter can be one of the following values:
     *         @arg @ref EXTI_LINE_48
     *         @arg @ref EXTI_LINE_49
     *         @arg @ref EXTI_LINE_50
     *         @arg @ref EXTI_LINE_51
     *         @arg @ref EXTI_LINE_52
     *         @arg @ref EXTI_LINE_53
     * @param  ClrSrc This parameter can be one of the following values:
     *         @arg @ref EXTI_D3_PEND_CLR_DMACH6
     *         @arg @ref EXTI_D3_PEND_CLR_DMACH7
     *         @arg @ref EXTI_D3_PEND_CLR_LPTIM4 (*)
     *         @arg @ref EXTI_D3_PEND_CLR_LPTIM5 (*)
     *         @arg @ref EXTI_D3_PEND_CLR_LPTIM2 (*)
     *         @arg @ref EXTI_D3_PEND_CLR_LPTIM3 (*)
     *
     *         (*) value not defined in all devices.
     * @retval None
     */
    inline void d3EXTISetPendClearSel_48_63(uint32_t ExtiLine, EXTID3PendClr ClrSrc)
    {
        MODIFY_REG(EXTI->D3PCR2H, (((ExtiLine >> EXTI_IMR2_IM48_Pos) * (ExtiLine >> EXTI_IMR2_IM48_Pos)) * 3UL), (((ExtiLine >> EXTI_IMR2_IM48_Pos) * (ExtiLine >> EXTI_IMR2_IM48_Pos)) * ClrSrc));
    }

    /**
     * @brief  Get ExtLine D3 Domain Pend Clear Source selection for Lines in range 0 to 15
     * @rmtoll D3PCR1L          PCSx           d3EXTIGetPendClearSel_0_15
     * @param  ExtiLine This parameter can be one of the following values:
     *         @arg @ref EXTI_LINE_0
     *         @arg @ref EXTI_LINE_1
     *         @arg @ref EXTI_LINE_2
     *         @arg @ref EXTI_LINE_3
     *         @arg @ref EXTI_LINE_4
     *         @arg @ref EXTI_LINE_5
     *         @arg @ref EXTI_LINE_6
     *         @arg @ref EXTI_LINE_7
     *         @arg @ref EXTI_LINE_8
     *         @arg @ref EXTI_LINE_9
     *         @arg @ref EXTI_LINE_10
     *         @arg @ref EXTI_LINE_11
     *         @arg @ref EXTI_LINE_12
     *         @arg @ref EXTI_LINE_13
     *         @arg @ref EXTI_LINE_14
     *         @arg @ref EXTI_LINE_15
     * @retval Returned value can be one of the following values:
     *         @arg @ref EXTI_D3_PEND_CLR_DMACH6
     *         @arg @ref EXTI_D3_PEND_CLR_DMACH7
     *         @arg @ref EXTI_D3_PEND_CLR_LPTIM4 (*)
     *         @arg @ref EXTI_D3_PEND_CLR_LPTIM5 (*)
     *         @arg @ref EXTI_D3_PEND_CLR_LPTIM2 (*)
     *         @arg @ref EXTI_D3_PEND_CLR_LPTIM3 (*)
     *
     *         (*) value not defined in all devices.
     */
    inline EXTID3PendClr d3EXTIGetPendClearSel_0_15(uint32_t ExtiLine)
    {
        return (EXTID3PendClr)(READ_BIT(EXTI->D3PCR1L, ((ExtiLine * ExtiLine) * 3UL)) / (ExtiLine * ExtiLine));
    }

    /**
     * @brief  Get ExtLine D3 Domain Pend Clear Source selection for Lines in range 16 to 31
     * @rmtoll D3PCR1H          PCSx           d3EXTIGetPendClearSel_16_31
     * @param  ExtiLine This parameter can be one of the following values:
     *         @arg @ref EXTI_LINE_19
     *         @arg @ref EXTI_LINE_20
     *         @arg @ref EXTI_LINE_21
     *         @arg @ref EXTI_LINE_25
     * @retval Returned value can be one of the following values:
     *         @arg @ref EXTI_D3_PEND_CLR_DMACH6
     *         @arg @ref EXTI_D3_PEND_CLR_DMACH7
     *         @arg @ref EXTI_D3_PEND_CLR_LPTIM4 (*)
     *         @arg @ref EXTI_D3_PEND_CLR_LPTIM5 (*)
     *         @arg @ref EXTI_D3_PEND_CLR_LPTIM2 (*)
     *         @arg @ref EXTI_D3_PEND_CLR_LPTIM3 (*)
     *
     *         (*) value not defined in all devices.
     */
    inline EXTID3PendClr d3EXTIGetPendClearSel_16_31(uint32_t ExtiLine)
    {
        return (EXTID3PendClr)(READ_BIT(EXTI->D3PCR1H, (((ExtiLine >> EXTI_IMR1_IM16_Pos) * (ExtiLine >> EXTI_IMR1_IM16_Pos)) * 3UL)) / ((ExtiLine >> EXTI_IMR1_IM16_Pos) * (ExtiLine >> EXTI_IMR1_IM16_Pos)));
    }

    /**
     * @brief  Get ExtLine D3 Domain Pend Clear Source selection for Lines in range 32 to 47
     * @rmtoll D3PCR2L          PCSx           d3EXTIGetPendClearSel_32_47
     * @param  ExtiLine This parameter can be one of the following values:
     *         @arg @ref EXTI_LINE_34
     *         @arg @ref EXTI_LINE_35
     *         @arg @ref EXTI_LINE_41
     * @retval Returned value can be one of the following values:
     *         @arg @ref EXTI_D3_PEND_CLR_DMACH6
     *         @arg @ref EXTI_D3_PEND_CLR_DMACH7
     *         @arg @ref EXTI_D3_PEND_CLR_LPTIM4 (*)
     *         @arg @ref EXTI_D3_PEND_CLR_LPTIM5 (*)
     *         @arg @ref EXTI_D3_PEND_CLR_LPTIM2 (*)
     *         @arg @ref EXTI_D3_PEND_CLR_LPTIM3 (*)
     *
     *         (*) value not defined in all devices.
     */
    inline EXTID3PendClr d3EXTIGetPendClearSel_32_47(uint32_t ExtiLine)
    {
        return (EXTID3PendClr)(READ_BIT(EXTI->D3PCR2L, ((ExtiLine * ExtiLine) * 3UL)) / (ExtiLine * ExtiLine));
    }

    /**
     * @brief  Get ExtLine D3 Domain Pend Clear Source selection for Lines in range 48 to 63
     * @rmtoll D3PCR2H          PCSx           d3EXTIGetPendClearSel_48_63
     * @param  ExtiLine This parameter can be one of the following values:
     *         @arg @ref EXTI_LINE_48
     *         @arg @ref EXTI_LINE_49
     *         @arg @ref EXTI_LINE_50
     *         @arg @ref EXTI_LINE_51
     *         @arg @ref EXTI_LINE_52
     *         @arg @ref EXTI_LINE_53
     * @retval Returned value can be one of the following values:
     *         @arg @ref EXTI_D3_PEND_CLR_DMACH6
     *         @arg @ref EXTI_D3_PEND_CLR_DMACH7
     *         @arg @ref EXTI_D3_PEND_CLR_LPTIM4 (*)
     *         @arg @ref EXTI_D3_PEND_CLR_LPTIM5 (*)
     *         @arg @ref EXTI_D3_PEND_CLR_LPTIM2 (*)
     *         @arg @ref EXTI_D3_PEND_CLR_LPTIM3 (*)
     *
     *         (*) value not defined in all devices.
     */
    inline EXTID3PendClr d3EXTIGetPendClearSel_48_63(uint32_t ExtiLine)
    {
    return (EXTID3PendClr)(READ_BIT(EXTI->D3PCR2H, (((ExtiLine >> EXTI_IMR2_IM48_Pos) * (ExtiLine >> EXTI_IMR2_IM48_Pos)) * 3UL)) / ((ExtiLine >> EXTI_IMR2_IM48_Pos) * (ExtiLine >> EXTI_IMR2_IM48_Pos)));
    }

    eResult extiInit(EXTILinex_0_31  line_0_31, EXTILinex_32_63  line_32_63, EXTILinex_64_95  line_64_95, uint32_t mode, EXTITrigger trig, bool bLineCommand)
    {
        eResult status = E_RESULT_OK;

        /* ENABLE LineCommand */
        if (bLineCommand)
        {
            /* Configure EXTI Lines in range from 0 to 31 */
            if (line_0_31 != EXTI_LINE_NONE_0_31)
            {
                if((mode & EXTI_MODE_IT) == EXTI_MODE_IT)
                {
                    /* Enable IT on provided Lines for Cortex-M7*/
                    extiEnableIT_0_31(line_0_31);
                }
                else
                {
                    /* Disable IT on provided Lines for Cortex-M7*/
                    extiDisableIT_0_31(line_0_31);
                }

                if((mode & EXTI_MODE_EVENT) == EXTI_MODE_EVENT)
                {
                    /* Enable event on provided Lines for Cortex-M7 */
                    extiEnableEvent_0_31(line_0_31);
                }
                else
                {
                    /* Disable event on provided Lines for Cortex-M7 */
                    extiDisableEvent_0_31(line_0_31);
                }
            #if defined(DUAL_CORE)
                if((mode & EXTI_MODE_C2_IT) == EXTI_MODE_C2_IT)
                {
                    /* Enable IT on provided Lines for Cortex-M4 */
                    c2EXTIEnableIT_0_31 (line_0_31);
                }
                else
                {
                    /* Disable IT on provided Lines for Cortex-M4*/
                    c2EXTIDisableIT_0_31(line_0_31);
                }

                if((mode & EXTI_MODE_C2_EVENT) == EXTI_MODE_C2_EVENT)
                {
                    /* Enable event on provided Lines for Cortex-M4 */
                    c2EXTIEnableEvent_0_31(line_0_31);
                }
                else
                {
                    /* Disable event on provided Lines for Cortex-M4*/
                    c2EXTIDisableEvent_0_31(line_0_31);
                }
            #endif /* DUAL_CORE */

                if (trig != EXTI_TRIGGER_NONE)
                {
                    switch (trig)
                    {
                        case EXTI_TRIGGER_RISING:
                            /* First Disable Falling Trigger on provided Lines */
                            extiDisableFallingTrig_0_31(line_0_31);
                            /* Then Enable Rising Trigger on provided Lines */
                            extiEnableRisingTrig_0_31(line_0_31);
                            break;
                        case EXTI_TRIGGER_FALLING:
                            /* First Disable Rising Trigger on provided Lines */
                            extiDisableRisingTrig_0_31(line_0_31);
                            /* Then Enable Falling Trigger on provided Lines */
                            extiEnableFallingTrig_0_31(line_0_31);
                            break;
                        case EXTI_TRIGGER_RISING_FALLING:
                            extiEnableRisingTrig_0_31(line_0_31);
                            extiEnableFallingTrig_0_31(line_0_31);
                            break;
                        default:
                            status = E_RESULT_ERROR;
                            break;
                    }
                }
            }
            /* Configure EXTI Lines in range from 32 to 63 */
            if (line_32_63 != EXTI_LINE_NONE_32_63)
            {
                if((mode & EXTI_MODE_IT) == EXTI_MODE_IT)
                {
                    /* Enable IT on provided Lines for Cortex-M7*/
                    extiEnableIT_32_63(line_32_63);
                }
                else
                {
                    /* Disable IT on provided Lines for Cortex-M7*/
                    extiDisableIT_32_63(line_32_63);
                }

                if((mode & EXTI_MODE_EVENT) == EXTI_MODE_EVENT)
                {
                    /* Enable event on provided Lines for Cortex-M7 */
                    extiEnableEvent_32_63(line_32_63);
                }
                else
                {
                    /* Disable event on provided Lines for Cortex-M7 */
                    extiDisableEvent_32_63(line_32_63);
                }
            #if defined(DUAL_CORE)
                if((mode & EXTI_MODE_C2_IT) == EXTI_MODE_C2_IT)
                {
                    /* Enable IT on provided Lines for Cortex-M4 */
                    c2EXTIEnableIT_32_63 (line_32_63);
                }
                else
                {
                    /* Disable IT on provided Lines for Cortex-M4 */
                    c2EXTIDisableIT_32_63 (line_32_63);
                }

                if((mode & EXTI_MODE_C2_EVENT) == EXTI_MODE_C2_EVENT)
                {
                    /* Enable event on provided Lines for Cortex-M4 */
                    c2EXTIEnableEvent_32_63(line_32_63);
                }
                else
                {
                    /* Disable event on provided Lines for Cortex-M4 */
                    c2EXTIDisableEvent_32_63(line_32_63);
                }
            #endif /* DUAL_CORE */

                if (trig != EXTI_TRIGGER_NONE)
                {
                    switch (trig)
                    {
                    case EXTI_TRIGGER_RISING:
                        /* First Disable Falling Trigger on provided Lines */
                        extiDisableFallingTrig_32_63(line_32_63);
                        /* Then Enable IT on provided Lines */
                        extiEnableRisingTrig_32_63(line_32_63);
                        break;
                    case EXTI_TRIGGER_FALLING:
                        /* First Disable Rising Trigger on provided Lines */
                        extiDisableRisingTrig_32_63(line_32_63);
                        /* Then Enable Falling Trigger on provided Lines */
                        extiEnableFallingTrig_32_63(line_32_63);
                        break;
                    case EXTI_TRIGGER_RISING_FALLING:
                        extiEnableRisingTrig_32_63(line_32_63);
                        extiEnableFallingTrig_32_63(line_32_63);
                        break;
                    default:
                        status = E_RESULT_ERROR;
                        break;
                    }
                }
                }
                /* Configure EXTI Lines in range from 64 to 95 */
                if (line_64_95 != EXTI_LINE_NONE_64_95)
                {
                if((mode & EXTI_MODE_IT) == EXTI_MODE_IT)
                {
                    /* Enable IT on provided Lines for Cortex-M7*/
                    extiEnableIT_64_95(line_64_95);
                }
                else
                {
                    /* Disable IT on provided Lines for Cortex-M7*/
                    extiDisableIT_64_95(line_64_95);
                }

                if((mode & EXTI_MODE_EVENT) == EXTI_MODE_EVENT)
                {
                    /* Enable event on provided Lines for Cortex-M7 */
                    extiEnableEvent_64_95(line_64_95);
                }
                else
                {
                    /* Disable event on provided Lines for Cortex-M7 */
                    extiDisableEvent_64_95(line_64_95);
                }

            #if defined(DUAL_CORE)
                if((mode & EXTI_MODE_C2_IT) == EXTI_MODE_C2_IT)
                {
                    /* Enable IT on provided Lines for Cortex-M4 */
                    c2EXTIEnableIT_64_95 (line_64_95);
                }
                else
                {
                    /* Disable IT on provided Lines for Cortex-M4 */
                    c2EXTIDisableIT_64_95 (line_64_95);
                }

                if((mode & EXTI_MODE_C2_EVENT) == EXTI_MODE_C2_EVENT)
                {
                    /* Enable event on provided Lines for Cortex-M4 */
                    c2EXTIEnableEvent_64_95(line_64_95);
                }
                else
                {
                    /* Disable event on provided Lines for Cortex-M4 */
                    c2EXTIDisableEvent_64_95(line_64_95);
                }
            #endif /* DUAL_CORE */

                if (trig != EXTI_TRIGGER_NONE)
                {
                    switch (trig)
                    {
                    case EXTI_TRIGGER_RISING:
                        /* First Disable Falling Trigger on provided Lines */
                        extiDisableFallingTrig_64_95(line_64_95);
                        /* Then Enable IT on provided Lines */
                        extiEnableRisingTrig_64_95(line_64_95);
                        break;
                    case EXTI_TRIGGER_FALLING:
                        /* First Disable Rising Trigger on provided Lines */
                        extiDisableRisingTrig_64_95(line_64_95);
                        /* Then Enable Falling Trigger on provided Lines */
                        extiEnableFallingTrig_64_95(line_64_95);
                        break;
                    case EXTI_TRIGGER_RISING_FALLING:
                        extiEnableRisingTrig_64_95(line_64_95);
                        extiEnableFallingTrig_64_95(line_64_95);
                        break;
                    default:
                        status = E_RESULT_ERROR;
                        break;
                    }
                }
            }
        }
        else /* DISABLE LineCommand */
        {
            /* Disable IT on provided Lines for Cortex-M7*/
            extiDisableIT_0_31(line_0_31);
            extiDisableIT_32_63(line_32_63);
            extiDisableIT_64_95(line_64_95);

            /* Disable event on provided Lines for Cortex-M7 */
            extiDisableEvent_0_31(line_0_31);
            extiDisableEvent_32_63(line_32_63);
            extiDisableEvent_64_95(line_64_95);

        #if defined(DUAL_CORE)
            /* Disable IT on provided Lines for Cortex-M4*/
            c2EXTIDisableIT_0_31(line_0_31);
            c2EXTIDisableIT_32_63(line_32_63);
            c2EXTIDisableIT_64_95(line_64_95);

            /* Disable event on provided Lines for Cortex-M4 */
            c2EXTIDisableEvent_0_31(line_0_31);
            c2EXTIDisableEvent_32_63(line_32_63);
            c2EXTIDisableEvent_64_95(line_64_95);
        #endif /* DUAL_CORE */
        }
        return status;
    }
    eResult extiDeInit(void)
    {
        /* Rising Trigger selection register set to default reset values */
        WRITE_REG(EXTI->RTSR1,  0x00000000U);
        WRITE_REG(EXTI->RTSR2,  0x00000000U);
        WRITE_REG(EXTI->RTSR3,  0x00000000U);

        /* Falling Trigger selection register set to default reset values */
        WRITE_REG(EXTI->FTSR1,  0x00000000U);
        WRITE_REG(EXTI->FTSR2,  0x00000000U);
        WRITE_REG(EXTI->FTSR3,  0x00000000U);

        /* Software interrupt event register set to default reset values */
        WRITE_REG(EXTI->SWIER1, 0x00000000U);
        WRITE_REG(EXTI->SWIER2, 0x00000000U);
        WRITE_REG(EXTI->SWIER3, 0x00000000U);

        /* D3 Pending register set to default reset values */
        WRITE_REG(EXTI->D3PMR1, 0x00000000U);
        WRITE_REG(EXTI->D3PMR2, 0x00000000U);
        WRITE_REG(EXTI->D3PMR3, 0x00000000U);

        /* D3 Pending clear selection register low to default reset values */
        WRITE_REG(EXTI->D3PCR1L, 0x00000000U);
        WRITE_REG(EXTI->D3PCR2L, 0x00000000U);
        WRITE_REG(EXTI->D3PCR3L, 0x00000000U);

        /* D3 Pending clear selection register high to default reset values */
        WRITE_REG(EXTI->D3PCR1H, 0x00000000U);
        WRITE_REG(EXTI->D3PCR2H, 0x00000000U);
        WRITE_REG(EXTI->D3PCR3H, 0x00000000U);

        /* Interrupt mask register reset */
        WRITE_REG(EXTI->IMR1, 0x00000000U);
        WRITE_REG(EXTI->IMR2, 0x00000000U);
        WRITE_REG(EXTI->IMR3, 0x00000000U);

        /*  Event mask register reset */
        WRITE_REG(EXTI->EMR1, 0x00000000U);
        WRITE_REG(EXTI->EMR2, 0x00000000U);
        WRITE_REG(EXTI->EMR3, 0x00000000U);

        /* Clear Pending requests */
        WRITE_REG(EXTI->PR1, EXTI_PR1_PR_Msk);
        WRITE_REG(EXTI->PR2, EXTI_PR2_PR_Msk);
        WRITE_REG(EXTI->PR3, EXTI_PR3_PR_Msk);

        #if defined(DUAL_CORE)
        /* Interrupt mask register set to default reset values  for Core 2 (Coretx-M4)*/
        WRITE_REG(EXTI->C2IMR1, 0x00000000U);
        WRITE_REG(EXTI->C2IMR2, 0x00000000U);
        WRITE_REG(EXTI->C2IMR3, 0x00000000U);

        /*  Event mask register set to default reset values */
        WRITE_REG(EXTI->C2EMR1, 0x00000000U);
        WRITE_REG(EXTI->C2EMR2, 0x00000000U);
        WRITE_REG(EXTI->C2EMR3, 0x00000000U);

        /* Clear Pending requests */
        WRITE_REG(EXTI->C2PR1, EXTI_PR1_PR_Msk);
        WRITE_REG(EXTI->C2PR2, EXTI_PR2_PR_Msk);
        WRITE_REG(EXTI->C2PR3, EXTI_PR3_PR_Msk);

        #endif /* DUAL_CORE*/
        return E_RESULT_OK;
    }
private:
    EXTIx()
    {

    }
    ~EXTIx()
    {

    }
    EXTIx(const EXTIx&) = delete;
    EXTIx(EXTIx&&) = delete;
    EXTIx& operator=(const EXTIx&) = delete;
    EXTIx& operator=(EXTIx&&) = delete;
};