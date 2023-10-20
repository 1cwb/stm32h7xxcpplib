#pragma once
#include "stm32h7xx.h"
#include "isrcommon.h"

enum NVICPriorityGroup
{
    NVIC_PRIORITYGROUP_0    =   ((uint32_t)0x00000007),  /*!< 0 bits for pre-emption priority 4 bits for subpriority */  
    NVIC_PRIORITYGROUP_1    =   ((uint32_t)0x00000006),  /*!< 1 bits for pre-emption priority 3 bits for subpriority */
    NVIC_PRIORITYGROUP_2    =   ((uint32_t)0x00000005),  /*!< 2 bits for pre-emption priority 2 bits for subpriority */   
    NVIC_PRIORITYGROUP_3    =   ((uint32_t)0x00000004),  /*!< 3 bits for pre-emption priority 1 bits for subpriority */
    NVIC_PRIORITYGROUP_4    =   ((uint32_t)0x00000003)   /*!< 4 bits for pre-emption priority 0 bits for subpriority */
};

enum eResult
{
    E_RESULT_ERROR = -1,
    E_RESULT_OK,
    E_RESULT_TIMEOUT,
    E_RESULT_BAD_INIT_FLOW,
    E_RESULT_INVALID_PARAM,
    E_RESULT_OUT_OF_RANGE,
    E_RESULT_WRONG_STATUS
};
#define CHECK_RETURN(param, result) \
    if(!(param))\
    {\
        return (result);\
    }

#define CHECK_RETURN_WITH_INFO(param, str) \
{\
    eResult result =  (param);\
    if((result != E_RESULT_OK))\
    {\
        printf("%s()%d ErrID:(%d) Error Reasion: %s\r\n",__FUNCTION__,__LINE__,result, str);\
        return (result);\
    }\
}

// #define SET_BIT(add, bit)  ((add) |= BIT(bit))
// #define CLEAR_BIT(add, bit) ((add) &= (~BIT(bit)))
// #define GET_BIT(add, bit) ((add) & BIT(bit))
