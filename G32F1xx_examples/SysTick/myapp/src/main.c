/*******************************************************************************
*	Application: Demo code for GPIO using in G32F1xx
*	Edition:		Version:1.0
*	Company: 		GORGETEK
*	Time: 			September 2015
*******************************************************************************/
#include "gt_sys.h"
#include "gt_gpio.h"
#include "main.h"
#include "gt_rcc.h"

static __IO uint32_t TimingDelay;
void Delay(__IO uint32_t nTime);

GPIO_InitTypeDef GPIO_InitStructure;
/*****************************************************************************
* Function name:    Main Function
*
* Descriptions:     Initial device
*
* parameters:       None
* Returned value:   None
* 
*****************************************************************************/
int main(void)
{

	/* --------- System initialization ------------------*/
	SystemInit();
	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	SysTick_Config(SystemCoreClock / 1000);
	
  while(1)
	{
		GPIO_WriteBit(GPIOB, GPIO_Pin_9, Bit_SET);
		Delay(500);
		GPIO_WriteBit(GPIOB, GPIO_Pin_9, Bit_RESET);
		Delay(500);
	}
}

void Delay(__IO uint32_t nTime)
{
	TimingDelay = nTime;
	while(TimingDelay != 0);
}

void TimingDelay_Decrement(void)
{
	if(TimingDelay != 0x00)
	{
		TimingDelay--;
	}
}
