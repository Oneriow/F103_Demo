/*******************************************************************************
*	Application: Demo code for PWM using in G32F0xx
*	Edition:		Version:1.0
*	Company: 		GORGETEK
*	Time: 			September 2015
*******************************************************************************/
#include "g32f1xx.h"
#include "gt_pwm.h"
#include "gt_sys.h"
#include "gt_rcc.h"

extern uint32_t APB2Clock;

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
	/* ------------- System initialization -----------------------------------*/
	SystemInit();	
	
	/* ------------- Config TIM1/PWM channel I/O assignment ------------------*/
	GT_AFIO->PA7  = 0x16;
	GT_AFIO->PA8  = 0x16;
	GT_AFIO->PB0  = 0x16;
	GT_AFIO->PA9  = 0x16;
	GT_AFIO->PB1  = 0x16;
	GT_AFIO->PA10  = 0x16;
	
	/* ------------- initial PWM output for test -----------------------------*/
	SYSCON->SYSAPB2CLKCTRL.bit.TIM1CLK = 1;
	
	TIM1->CTRL.bit.PRSC = 0;
	TIM1->CNFG.bit.NDEP01 = 1;
	TIM1->CNFG.bit.NDEP23 = 1;
	TIM1->CNFG.bit.NDEP45 = 1;
	
	TIM1->CNFG.bit.TOPNEG01 = PWM_POSITIVE;
	TIM1->CNFG.bit.BOTNEG01 = 0;
	TIM1->CNFG.bit.TOPNEG23 = PWM_POSITIVE;
	TIM1->CNFG.bit.BOTNEG23 = 0;
	TIM1->CNFG.bit.TOPNEG45 = PWM_POSITIVE;
	TIM1->CNFG.bit.BOTNEG45 = 0;
	
	TIM1->CNFG.bit.EDG = PWM_CENTER;
//	TIM1->CMOD.all = APB2Clock/20000;//PWM_EDGE
//	TIM1->CTRL.bit.HALF = 0;//PWM_EDGE
	TIM1->CMOD.all = APB2Clock/2/20000;//PWM_CENTER
	TIM1->CTRL.bit.HALF = 1;//PWM_CENTER
	
	TIM1->PSCR.bit.CINV0 = PWM_POSITIVE;
	TIM1->PSCR.bit.CINV1 = PWM_POSITIVE;
	TIM1->PSCR.bit.CINV2 = PWM_POSITIVE;
	TIM1->PSCR.bit.CINV3 = PWM_POSITIVE;
	TIM1->PSCR.bit.CINV4 = PWM_POSITIVE;
	TIM1->PSCR.bit.CINV5 = PWM_POSITIVE;
	
	TIM1->CTRL.bit.IPOL0 = 1;
	TIM1->CTRL.bit.IPOL1 = 1;
	TIM1->CTRL.bit.IPOL2 = 1;
	
	TIM1->CNTRINI.bit.INITVAL = 0;
	TIM1->CTRL.bit.LDOK = 1;
	
	
	/* ------------- Set PWM Duty --------------------------------------------*/
	TIM1->VAL0.all = TIM1->CMOD.all*15*30/3000;//TIM1_CH1N
	TIM1->VAL1.all = TIM1->CMOD.all*30*30/3000;//TIM1_CH1
	TIM1->VAL2.all = TIM1->CMOD.all*45*30/3000;//TIM1_CH2N
	TIM1->VAL3.all = TIM1->CMOD.all*60*30/3000;//TIM1_CH2
	TIM1->VAL4.all = TIM1->CMOD.all*75*30/3000;//TIM1_CH3N
	TIM1->VAL5.all = TIM1->CMOD.all*90*30/3000;//TIM1_CH3
	
	/* ------------- Start PWM timer -----------------------------------------*/
	PWM_Start(TIM1);

	while (1) 
	{
	}
}
