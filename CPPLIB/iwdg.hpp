#pragma once
#include "common.hpp"
#include <cmath>

#define IWDG_ENABLE_WRITE  0X5555
#define IWDG_RELOAD_VAL    0XAAAA
#define IWDG_START         0XCCCC

enum IWDGPREScaDivid
{
    IWDG_PRE_DIVI_4,
    IWDG_PRE_DIVI_8,
    IWDG_PRE_DIVI_16,
    IWDG_PRE_DIVI_32,
    IWDG_PRE_DIVI_64,
    IWDG_PRE_DIVI_128,
    IWDG_PRE_DIVI_256,
    IWDG_PRE_DIVI_NONE
};

class IWDG
{
public:
    static IWDG* getInstance()
    {
        static IWDG iwdg;
        return &iwdg;
    }
    //timeouttimer = ((4*(2^divi)*reloadVal))/32
    void start(IWDGPREScaDivid divi, uint16_t reloadVal)
    {
        if(divi == IWDG_PRE_DIVI_NONE)
        {
            return;
        }
        if(IWDG_PRE_DIVI_NONE != prescaldivi_)
        {
            return;
        }
        prescaldivi_ = divi;
        reloadVal_ = reloadVal;
        
        WRITE_REG(IWDG1->KR, IWDG_ENABLE_WRITE);
        WRITE_REG(IWDG1->PR, divi);
        WRITE_REG(IWDG1->RLR, reloadVal);
        WRITE_REG(IWDG1->KR, IWDG_RELOAD_VAL);
        WRITE_REG(IWDG1->KR, IWDG_START);
    }
    uint32_t getTimeOutTimerMs()
    {
        return static_cast<uint32_t>((4*((uint32_t)pow(2.0,prescaldivi_))*reloadVal_)/32);
    }
    void feedDog()
    {
        if(IWDG_PRE_DIVI_NONE != prescaldivi_)
        {
            WRITE_REG(IWDG1->KR, IWDG_RELOAD_VAL);
        }
    }
private:
    IWDG():reloadVal_(0),prescaldivi_(IWDG_PRE_DIVI_NONE)
    {

    }
    ~IWDG()
    {

    }
    IWDG(const IWDG&) = delete;
    IWDG(IWDG&&) = delete;
    IWDG& operator=(const IWDG&) = delete;
    IWDG& operator=(IWDG&&) = delete;

    uint16_t reloadVal_;
    IWDGPREScaDivid prescaldivi_;
};