#include "common.hpp"

static uint32_t fac_us=0;
void delayInit(uint32_t sysclk)
{
    fac_us=sysclk;
}

void delayUs(uint32_t nus)
{		
	uint32_t ticks;
	uint32_t told,tnow,tcnt=0;
	uint32_t reload=SysTick->LOAD;				    	 
	ticks=nus*fac_us; 						
	told=SysTick->VAL;        				
	while(1)
	{
		tnow=SysTick->VAL;
		if(tnow!=told)
		{	    
			if(tnow<told)tcnt+=told-tnow;
			else tcnt+=reload-tnow+told;
			told=tnow;
			if(tcnt>=ticks)break;
		}  
	};
}
void delayMs(uint16_t nms)
{
	uint16_t i;
	for(i=0;i<nms;i++) delayUs(1000);
}