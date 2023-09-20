#pragma once
#include "common.hpp"

enum MPURegionSize
{
    MPU_REGION_SIZE_32B   = ((uint8_t)0x04),
    MPU_REGION_SIZE_64B   = ((uint8_t)0x05),
    MPU_REGION_SIZE_128B  = ((uint8_t)0x06),
    MPU_REGION_SIZE_256B  = ((uint8_t)0x07),
    MPU_REGION_SIZE_512B  = ((uint8_t)0x08),
    MPU_REGION_SIZE_1KB   = ((uint8_t)0x09),
    MPU_REGION_SIZE_2KB   = ((uint8_t)0x0A),
    MPU_REGION_SIZE_4KB   = ((uint8_t)0x0B),
    MPU_REGION_SIZE_8KB   = ((uint8_t)0x0C),
    MPU_REGION_SIZE_16KB  = ((uint8_t)0x0D),
    MPU_REGION_SIZE_32KB  = ((uint8_t)0x0E),
    MPU_REGION_SIZE_64KB  = ((uint8_t)0x0F),
    MPU_REGION_SIZE_128KB = ((uint8_t)0x10),
    MPU_REGION_SIZE_256KB = ((uint8_t)0x11),
    MPU_REGION_SIZE_512KB = ((uint8_t)0x12),
    MPU_REGION_SIZE_1MB   = ((uint8_t)0x13),
    MPU_REGION_SIZE_2MB   = ((uint8_t)0x14),
    MPU_REGION_SIZE_4MB   = ((uint8_t)0x15),
    MPU_REGION_SIZE_8MB   = ((uint8_t)0x16),
    MPU_REGION_SIZE_16MB  = ((uint8_t)0x17),
    MPU_REGION_SIZE_32MB  = ((uint8_t)0x18),
    MPU_REGION_SIZE_64MB  = ((uint8_t)0x19),
    MPU_REGION_SIZE_128MB = ((uint8_t)0x1A),
    MPU_REGION_SIZE_256MB = ((uint8_t)0x1B),
    MPU_REGION_SIZE_512MB = ((uint8_t)0x1C),
    MPU_REGION_SIZE_1GB   = ((uint8_t)0x1D),
    MPU_REGION_SIZE_2GB   = ((uint8_t)0x1E),
    MPU_REGION_SIZE_4GB   = ((uint8_t)0x1F)
};

enum MPURegionNum
{
    MPU_REGION_NUMBER0  = ((uint8_t)0x00),
    MPU_REGION_NUMBER1  = ((uint8_t)0x01),
    MPU_REGION_NUMBER2  = ((uint8_t)0x02),
    MPU_REGION_NUMBER3  = ((uint8_t)0x03),
    MPU_REGION_NUMBER4  = ((uint8_t)0x04),
    MPU_REGION_NUMBER5  = ((uint8_t)0x05),
    MPU_REGION_NUMBER6  = ((uint8_t)0x06),
    MPU_REGION_NUMBER7  = ((uint8_t)0x07),
#if !defined(CORE_CM4)
    MPU_REGION_NUMBER8  = ((uint8_t)0x08),
    MPU_REGION_NUMBER9  = ((uint8_t)0x09),
    MPU_REGION_NUMBER10 = ((uint8_t)0x0A),
    MPU_REGION_NUMBER11 = ((uint8_t)0x0B),
    MPU_REGION_NUMBER12 = ((uint8_t)0x0C),
    MPU_REGION_NUMBER13 = ((uint8_t)0x0D),
    MPU_REGION_NUMBER14 = ((uint8_t)0x0E),
    MPU_REGION_NUMBER15 = ((uint8_t)0x0F)
#endif /* !defined(CORE_CM4) */
};

enum MPURegionPermission
{
    //定义MPU->RASR寄存器AP[26:24]位的设置值
    MPU_REGION_NO_ACCESS    = 	((uint8_t)0x00U),		//无访问（特权&用户都不可访问）
    MPU_REGION_PRIV_RW      = 	((uint8_t)0x01U), 		//仅支持特权读写访问
    MPU_REGION_PRIV_RW_URO  = 	((uint8_t)0x02U),  		//禁止用户写访问（特权可读写访问）
    MPU_REGION_FULL_ACCESS  = 	((uint8_t)0x03U),  		//全访问（特权&用户都可访问）
    MPU_REGION_PRIV_RO      = 	((uint8_t)0x05U), 		//仅支持特权读访问
    MPU_REGION_PRIV_RO_URO  = 	((uint8_t)0x06U)		//只读（特权&用户都不可以写）
};
enum MPURegionEnable
{
    MPU_REGION_ENABLE   =  ((uint8_t)0x01),
    MPU_REGION_DISABLE  =  ((uint8_t)0x00)
};
enum MPUDisableExec
{
    MPU_INSTRUCTION_ACCESS_ENABLE   =   ((uint8_t)0x00),
    MPU_INSTRUCTION_ACCESS_DISABLE  =   ((uint8_t)0x01)
};
enum MPUAccessShareable
{
    MPU_ACCESS_NOT_SHAREABLE  =  ((uint8_t)0x00),
    MPU_ACCESS_SHAREABLE      =   ((uint8_t)0x01)
};
enum MPUAccessCacheable
{
    MPU_ACCESS_NOT_CACHEABLE  =   ((uint8_t)0x00),
    MPU_ACCESS_CACHEABLE      =   ((uint8_t)0x01)
};
enum MPUAccessBufferable
{
    MPU_ACCESS_NOT_BUFFERABLE   =  ((uint8_t)0x00),
    MPU_ACCESS_BUFFERABLE       =  ((uint8_t)0x01)
};
enum MPUTexLevel
{
    MPU_TEX_LEVEL0  =  ((uint8_t)0x00),
    MPU_TEX_LEVEL1  =  ((uint8_t)0x01),
    MPU_TEX_LEVEL2  =  ((uint8_t)0x02)
};
enum MPUHfnmiPrivdef
{
    MPU_HFNMI_PRIVDEF_NONE   =   ((uint32_t)0x00000000),
    MPU_HARDFAULT_NMI        =   ((uint32_t)0x00000002),
    MPU_PRIVILEGED_DEFAULT   =   ((uint32_t)0x00000004),
    MPU_HFNMI_PRIVDEF        =   ((uint32_t)0x00000006)
};


namespace CORTEXM7MPU
{
    void mpuDisable(void)
    {
        /* Make sure outstanding transfers are done */
        __DMB();

        /* Disable fault exceptions */
        SCB->SHCSR &= ~SCB_SHCSR_MEMFAULTENA_Msk;

        /* Disable the MPU and clear the control register*/
        MPU->CTRL = 0;
    }
    void mpuEnable(MPUHfnmiPrivdef MPU_Control)
    {
        /* Enable the MPU */
        MPU->CTRL = MPU_Control | MPU_CTRL_ENABLE_Msk;

        /* Enable fault exceptions */
        SCB->SHCSR |= SCB_SHCSR_MEMFAULTENA_Msk;

        /* Ensure MPU setting take effects */
        __DSB();
        __ISB();
    }
    uint8_t mpuSetProtection(uint32_t baseaddr, MPURegionSize size, MPURegionNum regionNum, 
                MPUDisableExec disableExec,MPURegionPermission access,MPUAccessShareable shareable,
                MPUAccessCacheable cachable,MPUAccessBufferable buffable, MPUTexLevel texLevel = MPU_TEX_LEVEL0, bool benable = true)
    {
        MPU->RNR = regionNum;
        if(benable)
        {
            MPU->RBAR = baseaddr;
            MPU->RASR = ((uint32_t)disableExec   << MPU_RASR_XN_Pos)   |
                        ((uint32_t)access	     << MPU_RASR_AP_Pos)   |
                        ((uint32_t)texLevel 	 << MPU_RASR_TEX_Pos)  |
                        ((uint32_t)shareable     << MPU_RASR_S_Pos)    |
                        ((uint32_t)cachable	     << MPU_RASR_C_Pos)    |
                        ((uint32_t)buffable	     << MPU_RASR_B_Pos)    |
                        ((uint32_t)0		     << MPU_RASR_SRD_Pos)  |
                        ((uint32_t)size			 << MPU_RASR_SIZE_Pos) |
                        ((uint32_t)1             << MPU_RASR_ENABLE_Pos);
        }
        else
        {
            MPU->RBAR = 0x00;
            MPU->RASR = 0x00;
        }
        return 0;
    }
};

















