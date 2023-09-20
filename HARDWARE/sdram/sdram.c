#include "sdram.h"   
#if 0
SDRAM_HandleTypeDef hsdram1;			// SDRAM_HandleTypeDef 结构体变量

/*************************************************************************************************
*	函 数 名:	HAL_FMC_MspInit
*	入口参数:	无
*	返 回 值:无
*	函数功能:	初始化sdram引脚
*	说    明:
*************************************************************************************************/

static void HAL_FMC_MspInit(void)
{
  GPIO_InitTypeDef GPIO_InitStruct ={0};
  /* Peripheral clock enable */
  __HAL_RCC_FMC_CLK_ENABLE();

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();  
  __HAL_RCC_GPIOF_CLK_ENABLE();  
  __HAL_RCC_GPIOG_CLK_ENABLE();  
  __HAL_RCC_GPIOH_CLK_ENABLE();  
  
  /** FMC GPIO Configuration
  PF0   -----. FMC_A0			PD14   -----. FMC_D0			PC0    -----. FMC_SDNWE
  PF1   -----. FMC_A1        PD15   -----. FMC_D1         PG15   -----. FMC_SDNCAS 
  PF2   -----. FMC_A2        PD0    -----. FMC_D2         PF11   -----. FMC_SDNRAS
  PF3   -----. FMC_A3        PD1    -----. FMC_D3         PH3    -----. FMC_SDNE0  
  PF4   -----. FMC_A4        PE7    -----. FMC_D4         PG4    -----. FMC_BA0
  PF5   -----. FMC_A5        PE8    -----. FMC_D5         PG5    -----. FMC_BA1
  PF12  -----. FMC_A6       	PE9    -----. FMC_D6         PH2    -----. FMC_SDCKE0 
  PF13  -----. FMC_A7       	PE10   -----. FMC_D7         PG8    -----. FMC_SDCLK
  PF14  -----. FMC_A8       	PE11   -----. FMC_D8         PE1    -----. FMC_NBL1
  PF15  -----. FMC_A9       	PE12   -----. FMC_D9         PE0    -----. FMC_NBL0
  PG0   -----. FMC_A10       PE13   -----. FMC_D10
  PG1   -----. FMC_A11       PE14   -----. FMC_D11
  PG2   -----. FMC_A12       PE15   -----. FMC_D12
                              PD8    -----. FMC_D13
                              PD9    -----. FMC_D14
                              PD10   -----. FMC_D15

  */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_11|GPIO_PIN_12
                          |GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF12_FMC;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF12_FMC;
  HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_4
                          |GPIO_PIN_5|GPIO_PIN_8|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF12_FMC;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14
                          |GPIO_PIN_15|GPIO_PIN_0|GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF12_FMC;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_14
                          |GPIO_PIN_15|GPIO_PIN_0|GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF12_FMC;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  GPIO_InitStruct.Pin =  GPIO_PIN_0;                    
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF12_FMC;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
}

/*************************************************************************************************
*	函 数 名:	HAL_SDRAM_MspInit
*	入口参数:	hsdram - SDRAM_HandleTypeDef定义的变量，即表示定义的sdram
*	返 回 值:	无
*	函数功能:	初始化sdram引脚，在函数 HAL_SDRAM_Init 中被调用
*	说    明:	无		
*************************************************************************************************/

void HAL_SDRAM_MspInit(SDRAM_HandleTypeDef* hsdram)
{
	HAL_FMC_MspInit();
}

/******************************************************************************************************
*	函 数 名: SDRAM_Initialization_Sequence
*	入口参数: hsdram - SDRAM_HandleTypeDef定义的变量，即表示定义的sdram
*				 Command	- 控制指令
*	返 回 值: 无
*	函数功能: SDRAM 参数配置
*	说    明: 配置SDRAM相关时序和控制方式
*******************************************************************************************************/

HAL_StatusTypeDef SDRAM_Initialization_Sequence(SDRAM_HandleTypeDef *hsdram)
{
	 __IO uint32_t tmpmrd = 0;
    FMC_SDRAM_CommandTypeDef Command;
    HAL_StatusTypeDef status = HAL_ERROR;
  do
  {
    /* Configure a clock configuration enable command */
    Command.CommandMode 				= FMC_SDRAM_CMD_CLK_ENABLE;	// 开启SDRAM时钟 
    Command.CommandTarget 				= FMC_COMMAND_TARGET_BANK; 	// 选择要控制的区域
    Command.AutoRefreshNumber 		= 1;
    Command.ModeRegisterDefinition 	= 0;

    if((status = HAL_SDRAM_SendCommand(hsdram, &Command, SDRAM_TIMEOUT)) != HAL_OK)	// 发送控制指令
    {
      break;
    }
    HAL_Delay(1);		// 延时等待

    /* Configure a PALL (precharge all) command */ 
    Command.CommandMode 				= FMC_SDRAM_CMD_PALL;		// 预充电命令
    Command.CommandTarget 				= FMC_COMMAND_TARGET_BANK;	// 选择要控制的区域
    Command.AutoRefreshNumber 		= 1;
    Command.ModeRegisterDefinition 	= 0;

    if((status = HAL_SDRAM_SendCommand(hsdram, &Command, SDRAM_TIMEOUT)) != HAL_OK)  // 发送控制指令
    {
      break;
    }

    /* Configure a Auto-Refresh command */ 
    Command.CommandMode 				= FMC_SDRAM_CMD_AUTOREFRESH_MODE;	// 使用自动刷新
    Command.CommandTarget 				= FMC_COMMAND_TARGET_BANK;          // 选择要控制的区域
    Command.AutoRefreshNumber			= 8;                                // 自动刷新次数
    Command.ModeRegisterDefinition 	= 0;

    if((status = HAL_SDRAM_SendCommand(hsdram, &Command, SDRAM_TIMEOUT)) != HAL_OK)	// 发送控制指令
    {
      break;
    }

    /* Program the external memory mode register */
    tmpmrd = (uint32_t)SDRAM_MODEREG_BURST_LENGTH_2         |
                SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL   |
                SDRAM_MODEREG_CAS_LATENCY_3           |
                SDRAM_MODEREG_OPERATING_MODE_STANDARD |
                SDRAM_MODEREG_WRITEBURST_MODE_SINGLE;

    Command.CommandMode					= FMC_SDRAM_CMD_LOAD_MODE;	// 加载模式寄存器命令
    Command.CommandTarget 				= FMC_COMMAND_TARGET_BANK;	// 选择要控制的区域
    Command.AutoRefreshNumber 		= 1;
    Command.ModeRegisterDefinition 	= tmpmrd;

    if((status =  HAL_SDRAM_SendCommand(hsdram, &Command, SDRAM_TIMEOUT)) != HAL_OK)	// 发送控制指令
    {
      break;
    }
    
    if((status = HAL_SDRAM_ProgramRefreshRate(hsdram, 918)) != HAL_OK)  // 配置刷新率
    {
      break;
    }

  }while(0);
  return status;
}

/******************************************************************************************************
*	函 数 名: MX_FMC_Init
*	入口参数: 无
*	返 回 值: 无
*	函数功能: SDRAM初始化
*	说    明: 初始化FMC和SDRAM配置
*******************************************************************************************************/

HAL_StatusTypeDef MX_FMC_Init(void)
{
	FMC_SDRAM_TimingTypeDef SdramTiming = {0};
  HAL_StatusTypeDef status = HAL_ERROR;

	hsdram1.Instance = FMC_SDRAM_DEVICE;
	/* hsdram1.Init */
	hsdram1.Init.SDBank					 	= FMC_SDRAM_BANK1;							// 选择BANK区
	hsdram1.Init.ColumnBitsNumber 		= FMC_SDRAM_COLUMN_BITS_NUM_9;         // 行地址宽度
	hsdram1.Init.RowBitsNumber 			= FMC_SDRAM_ROW_BITS_NUM_13;           // 列地址线宽度
	hsdram1.Init.MemoryDataWidth 			= FMC_SDRAM_MEM_BUS_WIDTH_16;          // 数据宽度  
	hsdram1.Init.InternalBankNumber 		= FMC_SDRAM_INTERN_BANKS_NUM_4;        // bank数量
	hsdram1.Init.CASLatency 				= FMC_SDRAM_CAS_LATENCY_3;             //	CAS 
	hsdram1.Init.WriteProtection 			= FMC_SDRAM_WRITE_PROTECTION_DISABLE;  // 禁止写保护
	hsdram1.Init.SDClockPeriod 			= FMC_SDRAM_CLOCK_PERIOD_2;            // 分频
	hsdram1.Init.ReadBurst 					= FMC_SDRAM_RBURST_ENABLE;             // 突发模式  
	hsdram1.Init.ReadPipeDelay 			= FMC_SDRAM_RPIPE_DELAY_1;             // 读延迟
	
	/* SdramTiming */
	SdramTiming.LoadToActiveDelay 		= 2;
	SdramTiming.ExitSelfRefreshDelay 	= 7;
	SdramTiming.SelfRefreshTime 			= 4;
	SdramTiming.RowCycleDelay 				= 7;
	SdramTiming.WriteRecoveryTime 		= 3;
	SdramTiming.RPDelay 						= 2;
	SdramTiming.RCDDelay 					= 2;

	if((status = HAL_SDRAM_Init(&hsdram1, &SdramTiming)) != HAL_OK)	// 初始化FMC接口
  {
    return status;
  }
									
	if((status = SDRAM_Initialization_Sequence(&hsdram1)) != HAL_OK)//配置SDRAM
  {
    return status;
  }
  return status;
}

HAL_StatusTypeDef SDRAM_Check()
{
    int8_t data = 0;
    
    for(data = 0; data < 10; ++data)
    {
        *(__IO uint8_t*) (SDRAM_BANK_ADDR + data) = data;
    }
    for(data --; data >= 0; data --)
    {
      if(*(__IO uint8_t*) (SDRAM_BANK_ADDR + data) != data)
      {
        return HAL_ERROR;
      }
    }
    return HAL_OK;
}
#endif