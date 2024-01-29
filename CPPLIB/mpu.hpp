#pragma once
#include "cortex.hpp"

namespace CORTEXM7MPU
{
    void mpuDisable(void)
    {
        CORTEX::getInstance()->mpuDisable();
    }
    void mpuEnable(MPUHfnmiPrivdef MPU_Control)
    {
        CORTEX::getInstance()->mpuEnable(MPU_Control);
    }
    uint8_t mpuSetProtection(uint32_t baseaddr, MPURegionSize size, MPURegionNum regionNum, 
                MPUDisableExec disableExec,MPURegionPermission access,MPUAccessShareable shareable,
                MPUAccessCacheable cachable,MPUAccessBufferable buffable, MPUTexLevel texLevel = MPU_TEX_LEVEL0)
    {
        CORTEX::getInstance()->mpuConfigRegion(regionNum, 0, baseaddr, disableExec|access|texLevel|shareable|cachable|buffable|size);
        return 0;
    }
};

















