/*******************************************************************************
*	Application: Demo code for ADC using in G32F0xx
*	Edition:		Version:1.0
*	Company: 		GORGETEK
*	Time: 			September 2015
*******************************************************************************/
#include "g32f1xx.h"
#include "gt_sys.h"
#include "gt_adc.h"
#include "gt_rcc.h"


uint8_t ADC_Flag;
uint32_t ADC_Value[8] = {0};
float ADC_Volt[8] = {0};

void delay1us(uint32_t time);
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

  /* -------------- System initialization ---------------------------------*/	
	SystemInit();
	SystemCoreClockUpdate();

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
	
	OpenADC1_IN1;
	OpenADC1_IN2;
	
	/* -------------- Initialise ADC1,and set Sample speed ------------------*/
	ADC_Init(ADC1,100000);
	
	ADC1->CR.bit.CNVEN = (0x1 | 0x2);
	
	ADC1->CR.bit.BURST = TRIGGERMODE;
	ADC1->CR.bit.START = ADC_START_BY_SOFTWAER;
	ADC1->CR.bit.EDGE = ADC_TRIGGER_RISE_EDGE;
	
	ADC1->CHSEL.all = 0x00000010;
	while(!ADC1->STAT.bit.ADCRDY);
	
	ADC1->INTEN.all = 0x3;
	while(!ADC1->STAT.bit.ADCRDY);
	NVIC_EnableIRQ(ADC1_2_IRQn);

	while (1) 
	{
		ADC_Flag = 1;
		ADC1_IssueSoftTrigger;
		while(ADC_Flag == 1);
		ADC_Volt[0] = ADC_Value[0]*3.3/4096;
		ADC_Volt[1] = ADC_Value[1]*3.3/4096;
  }		
}

void delay1us(uint32_t time)
{
			while(time--);
}

void ADC1_2_IRQHandler()
{
	volatile uint8_t stat;
	uint8_t i;
	stat = ADC1->STAT.all;
	for(i=0; i<8; i++)
	{
		if(stat & (0x01<<i))
			ADC_Value[i] = ADC1->DR[i].all & 0xFFF;
	}
	ADC_Flag = 0;
}
