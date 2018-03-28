#include "g32f1xx.h"
#include "gt_rcc.h"
#include "gt_sys.h"

void RCC_DeInit(void)
{
	
}

void RCC_HSEConfig(uint32_t RCC_HSE)
{
}

ErrorStatus RCC_WaitForHSEStartUp(void)
{
	return SUCCESS;
}

void RCC_AdjustHSICalibrationValue(uint8_t HSICalibrationValue)
{
}

void RCC_HSICmd(FunctionalState NewState)
{
}

void RCC_PLLConfig(uint32_t RCC_PLLSource, uint32_t RCC_PLLMul)
{
}

void RCC_PLLCmd(FunctionalState NewState)
{
}

void RCC_PREDIV1Config(uint32_t RCC_PREDIV1_Source, uint32_t RCC_PREDIV1_Div)
{
}

void RCC_PREDIV2Config(uint32_t RCC_PREDIV2_Div)
{
}

void RCC_PLL2Config(uint32_t RCC_PLL2Mul)
{
}

void RCC_PLL2Cmd(FunctionalState NewState)
{
}

void RCC_PLL3Config(uint32_t RCC_PLL3Mul)
{
}

void RCC_PLL3Cmd(FunctionalState NewState)
{
}

void RCC_SYSCLKConfig(uint32_t RCC_SYSCLKSource)
{
}

//uint8_t RCC_GetSYSCLKSource(void)
//{
//}

void RCC_HCLKConfig(uint32_t RCC_SYSCLK)
{
}

void RCC_PCLK1Config(uint32_t RCC_HCLK)
{
}

void RCC_PCLK2Config(uint32_t RCC_HCLK)
{
}

void RCC_ITConfig(uint8_t RCC_IT, FunctionalState NewState)
{
}

void RCC_USBCLKConfig(uint32_t RCC_USBCLKSource)
{
}

void RCC_OTGFSCLKConfig(uint32_t RCC_OTGFSCLKSource)
{
}

void RCC_ADCCLKConfig(uint32_t RCC_PCLK2)
{
	if(RCC_PCLK2<20000000)
		SYSCON->ADCCLKDIV.bit.DIV=1;
	else if(RCC_PCLK2<40000000)
		SYSCON->ADCCLKDIV.bit.DIV=2;
	else if(RCC_PCLK2<60000000)
		SYSCON->ADCCLKDIV.bit.DIV=3;
	else
		SYSCON->ADCCLKDIV.bit.DIV=4;
}

void RCC_I2S2CLKConfig(uint32_t RCC_I2S2CLKSource)
{
}

void RCC_I2S3CLKConfig(uint32_t RCC_I2S3CLKSource)
{
}

void RCC_LSEConfig(uint8_t RCC_LSE)
{
}

void RCC_LSICmd(FunctionalState NewState)
{
}

void RCC_RTCCLKConfig(uint32_t RCC_RTCCLKSource)
{
}

void RCC_RTCCLKCmd(FunctionalState NewState)
{
}

//void RCC_GetClocksFreq(RCC_ClocksTypeDef* RCC_Clocks)
//{
//}

void RCC_AHBPeriphClockCmd(uint32_t RCC_AHBPeriph, FunctionalState NewState)
{
	
}

void RCC_APB2PeriphClockCmd(uint32_t RCC_APB2Periph, FunctionalState NewState)
{
	if(NewState != DISABLE)
	{
		SYSCON->SYSAPB2CLKCTRL.all |= RCC_APB2Periph;
	}
	else
	{
		SYSCON->SYSAPB2CLKCTRL.all &= ~RCC_APB2Periph;
	}
}

void RCC_APB1PeriphClockCmd(uint32_t RCC_APB1Periph, FunctionalState NewState)
{
	if(NewState != DISABLE)
	{
		SYSCON->SYSAPB1CLKCTRL.all |= RCC_APB1Periph;
	}
	else
	{
		SYSCON->SYSAPB1CLKCTRL.all &= ~RCC_APB1Periph;
	}
}

void RCC_AHBPeriphResetCmd(uint32_t RCC_AHBPeriph, FunctionalState NewState)
{
	
}

void RCC_APB2PeriphResetCmd(uint32_t RCC_APB2Periph, FunctionalState NewState)
{
	if(NewState != DISABLE)
	{
		SYSCON->APB2RESET.all |= RCC_APB2Periph;
	}
	else
	{
		SYSCON->APB2RESET.all &= ~RCC_APB2Periph;
	}
}

void RCC_APB1PeriphResetCmd(uint32_t RCC_APB1Periph, FunctionalState NewState)
{
	if(NewState != DISABLE)
	{
		SYSCON->APB1RESET.all |= RCC_APB1Periph;
	}
	else
	{
		SYSCON->APB1RESET.all &= ~RCC_APB1Periph;
	}
}

void RCC_BackupResetCmd(FunctionalState NewState)
{
}

void RCC_ClockSecuritySystemCmd(FunctionalState NewState)
{
}

void RCC_MCOConfig(uint8_t RCC_MCO)
{
}

//FlagStatus RCC_GetFlagStatus(uint8_t RCC_FLAG)
//{
//}

void RCC_ClearFlag(void)
{
}

//ITStatus RCC_GetITStatus(uint8_t RCC_IT)
//{
//}

void RCC_ClearITPendingBit(uint8_t RCC_IT)
{
}


