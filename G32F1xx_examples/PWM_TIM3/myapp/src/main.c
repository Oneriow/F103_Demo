/*******************************************************************************
*	Application: Demo code for GPIO using in G32F1xx
*	Edition:		Version:1.0
*	Company: 		GORGETEK
*	Time: 			September 2015
*******************************************************************************/
#include "g32f1xx.h"
#include "gt_sys.h"
#include "gt_gpio.h"
#include "gt_rcc.h"
#include "gt_timer.h"

extern uint32_t APB1Clock;

GPIO_InitTypeDef GPIO_InitStructure;

volatile uint32_t duty = 150;
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

	SYSCON->SYSAPB2CLKCTRL.bit.PACLK = 1;
	IOCON->PA6.bit.FUNC = 1;
	GPIOA->DIR.bit.IO6 = 1;
	IOCON->PA7.bit.FUNC = 1;
	GPIOA->DIR.bit.IO7 = 1;
	
	TIM_Init(TIM3, 150000UL);
	TIM3->CTCR.all = 0x800;
	TIM3->MR0.all = 1500;//CH1 1500/3000=50%
	TIM3->MR1.all = 1500;//CH2 1500/3000=50%
	TIM3->MR2.all = 1500;//CH3 1500/3000=50%
	TIM3->MR3.all = 3000;//¼ÆÊýÖµ
	
	TIM3->PWMC.all = 0x0F;
	
	TIM3->TCR.bit.CEN = 1;
	TIM3->TCR.all |= 0x0F << 8;
	
  while(1)
	{
	}
}
