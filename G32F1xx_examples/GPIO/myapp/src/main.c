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


void dly1us(int dlytime);

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

  while(1)
	{
		GPIO_WriteBit(GPIOB, GPIO_Pin_9, Bit_SET);
		dly1us(1000000);
		GPIO_WriteBit(GPIOB, GPIO_Pin_9, Bit_RESET);
		dly1us(1000000);
	}
}

void dly1us(int dlytime) 
{
 while(dlytime--);
}
