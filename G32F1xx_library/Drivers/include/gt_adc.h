/*****************************************************************************
 *   GT_adc.h:  Header file for GORGETEK G32F1xx Family Microprocessors
 *
 *   Copyright(C) 2015, GORGETEK tech. Ltd.
 *   All rights reserved.
 *
 *   History
 *   2015  ver 2.00    Prelimnary version, first Release
 *
******************************************************************************/

#ifndef __ADC_H 
#define __ADC_H

#include "g32f1xx.h"

//--ADC Registers BITS Field---------------------------------------------------------------------------------------
struct ADC_CR_BITS	{
			uint32_t CNVEN:8;	  //		Enable ADC conversion value to DR0~DR7
			uint32_t CLKDIV:8;	// 		The APB clock (PCLK) divider 
			uint32_t BURST:1;	  // 		Burst mode control. 
			uint32_t RSVD0:7;	  // 
			uint32_t START:4;	  // 		Conversion starts control.
			uint32_t EDGE:1;	  // 		Edge control. This bit is significant only when the START field contains 010-111. 
			uint32_t SCMODE:1;	//		ADC converter sample clock selection, must be 1
			uint32_t PD:1;  	  //    ADC Power -down
	    uint32_t DMAEN:1;  	//    ADC DMA EN
};
union ADC_CR_REG {
				uint32_t				all;
				struct  ADC_CR_BITS		bit;
};

struct ADC_GDR_BITS	{
			uint32_t RESULT:12;	//		Last conversion results
			uint32_t CHN:3;	    // 		Last conversion ADC channel 
			uint32_t OVERRUN:1;	// 		Results override flag 
			uint32_t DONE:1;	  // 		Conversion complete flag
			uint32_t RSVD:15;	  // 
};
union ADC_GDR_REG {
				uint32_t				all;
				struct  ADC_GDR_BITS		bit;
};

struct ADC_CHSEL_BITS	{
			uint32_t DR0CHSEL:4;	//		Select AD channel to be converted in DR0
			uint32_t DR1CHSEL:4;	//		Select AD channel to be converted in DR1 
			uint32_t DR2CHSEL:4;	//		Select AD channel to be converted in DR2 
			uint32_t DR3CHSEL:4;	//		Select AD channel to be converted in DR3 
			uint32_t DR4CHSEL:4;	//		Select AD channel to be converted in DR4 
			uint32_t DR5CHSEL:4;	//		Select AD channel to be converted in DR5 
			uint32_t DR6CHSEL:4;	//		Select AD channel to be converted in DR6
			uint32_t DR7CHSEL:4;	//		Select AD channel to be converted in DR7 
};
union ADC_CHSEL_REG {
				uint32_t				all;
				struct  ADC_CHSEL_BITS		bit;
};

struct ADC_INTEN_BITS	{
			uint32_t INTEN:8;	   //		Eenable interrupt when Selected DRn receive conversin result
			uint32_t GINTEN:1;	 //		Eenable interrupt when every conversin complete 
			uint32_t RSVD:23;
};

union ADC_INTEN_REG {
				uint32_t				all;
				struct  ADC_INTEN_BITS		bit;
};

struct ADC_DR_BITS	{
			uint32_t RESULT:12;	//		Conversin result
			uint32_t RSVD:18;
			uint32_t OVERRUN:1;	//		Override flag 
			uint32_t DONE:1;	  //		Conversion complete flag 
};
union ADC_DR_REG {
				uint32_t				all;
				struct  ADC_DR_BITS		bit;
};

struct ADC_STAT_BITS	{
			uint32_t DONE:8;	      //These bits mirror the DONE status flags that appear in the result register for each A/D channel. 
			uint32_t OVERRUN:8;	    //These bits mirror the OVERRRUN status flags that appear in the result register for each A/D channel. 
			uint32_t ADINT:1;	      //This bit is the A/D interrupt flag.  
			uint32_t HILMTFLAG0:1;	//High limit 0 status. 
			uint32_t HILMTFLAG1:1;	//High limit 1 status. 
			uint32_t LOLMTFLAG0:1;	//Low limit 0 status.
			uint32_t LOLMTFLAG1:1;	//Low limit 1 status. 
			uint32_t ADCRDY:1;	    //The bit value 1 indicates ADC_ converter is ready to use after ADC is enable.
			uint32_t RSVD:10; 
};
union ADC_STAT_REG {
				uint32_t				all;
				struct  ADC_STAT_BITS		bit;
};

struct ADC_HILMT_BITS	{
			uint32_t HILMT0:12;	// High Limit value0
			uint32_t CHNSEL0:3;	// channel to be compared with the high limit value0
			uint32_t INTEN0:1;	// Enable High Limit0 interrupt 
			uint32_t HILMT1:12;	// High Limit value1
			uint32_t CHNSEL1:3;	// channel to be compared with the high limit value1
			uint32_t INTEN1:1;	// Enable High Limit1 interrupt
};
union ADC_HILMT_REG {
				uint32_t				all;
				struct  ADC_HILMT_BITS		bit;
};

struct ADC_LOLMT_BITS	{
			uint32_t LOLMT0:12;	// Low Limit value0
			uint32_t CHNSEL0:3;	// channel to be compared with the low limit value0
			uint32_t INTEN0:1;	// Enable low Limit0 interrupt 
			uint32_t LOLMT1:12;	// low Limit value1
			uint32_t CHNSEL1:3;	// channel to be compared with the low limit value1
			uint32_t INTEN1:1;	// Enable low Limit1 interrupt
};
union ADC_LOLMT_REG {
				uint32_t				all;
				struct  ADC_LOLMT_BITS		bit;
};

struct ADC_SSCR_BITS	{
			uint32_t ADC_TRIG:1;	// Set this bit to trigger ADC_ to do one time conversion.
			uint32_t RSVD:31;
};
union ADC_SSCR_REG {
				uint32_t				all;
				struct  ADC_SSCR_BITS		bit;
};

/* ================================================================================ */
/* ================                       ADC                      ================ */
/* ================================================================================ */


/**
  * @brief Analog-to-Digital Converter (ADC)
  */

typedef struct {                                              /*!< ADC Structure                                                         */
  __IO union  ADC_CR_REG      CR;                             /*!< ADC_ control register                                                  */
  __IO union  ADC_GDR_REG     GDR;                            /*!< ADC Global Data Register                                              */
  __IO union  ADC_CHSEL_REG   CHSEL;                          /*!< Channel select control register                                       */
  __IO union  ADC_INTEN_REG   INTEN;                          /*!< ADC Interrupt Enable Register                                         */
  __IO union  ADC_DR_REG      DR[8];                          /*!< A/D Channel 0 Data Register                                           */
  __IO union  ADC_STAT_REG    STAT;                           /*!< ADC Status Register                                                   */
  __IO union  ADC_HILMT_REG   HILMT;                          /*!< ADC High Limit Control Register                                       */
  __IO union  ADC_LOLMT_REG   LOLMT;                          /*!< ADC Low Limit Control Register                                        */
  __I  uint32_t  RESERVED0;
  __IO union  ADC_SSCR_REG   SSCR;                            /*!< ADC software trigger convert register                                 */
} G32F_ADC_TypeDef;

#define		ADC1	((G32F_ADC_TypeDef	*) GT_ADC1_BASE)
#define		ADC2	((G32F_ADC_TypeDef	*) GT_ADC2_BASE)
#define		ADC3	((G32F_ADC_TypeDef	*) GT_ADC3_BASE)

//AD channel sel
#define CHN0 	0x0f
#define CHN1 	0x01
#define CHN2 	0x02
#define CHN3 	0x03
#define CHN4 	0x04
#define CHN5 	0x05
#define CHN6 	0x06
#define CHN7 	0x07

//DR select
#define ADC_DR0SEL 	0
#define ADC_DR1SEL 	4
#define ADC_DR2SEL 	8
#define ADC_DR3SEL 	12
#define ADC_DR4SEL 	16
#define ADC_DR5SEL 	20
#define ADC_DR6SEL 	24
#define ADC_DR7SEL 	28

//DR int
#define ADC_DR0INT 	0x1
#define ADC_DR1INT 	0x2
#define ADC_DR2INT 	0x4
#define ADC_DR3INT 	0x8
#define ADC_DR4INT 	0x10
#define ADC_DR5INT 	0x20
#define ADC_DR6INT 	0x40
#define ADC_DR7INT 	0x80
#define ADC_GINT 		0x100

//DR index
#define ADC_DR0 	0x0
#define ADC_DR1 	0x1
#define ADC_DR2 	0x2
#define ADC_DR3 	0x3
#define ADC_DR4 	0x4
#define ADC_DR5 	0x5
#define ADC_DR6 	0x6
#define ADC_DR7 	0x7


#define CHN1_DR0 		0xf
#define CHN2_DR0 		0x1
#define CHN3_DR0 		0x2
#define CHN4_DR0 		0x3
#define CHN5_DR0 		0x4
#define CHN6_DR0 		0x5
#define CHN7_DR0 		0x6
#define CHN8_DR0 		0x7
#define CHN9_DR0 		0x8
#define CHN10_DR0 	0x9
#define CHN11_DR0 	0xa
#define CHN12_DR0 	0xb
#define CHN13_DR0 	0xc
#define CHN14_DR0 	0xd
#define CHN15_DR0 	0xe
#define CHN16_DR0 	0xf

#define CHN1_DR1 		(0x0<<4)
#define CHN2_DR1 		(0x1<<4)
#define CHN3_DR1 		(0x2<<4)
#define CHN4_DR1 		(0x3<<4)
#define CHN5_DR1 		(0x4<<4)
#define CHN6_DR1 		(0x5<<4)
#define CHN7_DR1 		(0x6<<4)
#define CHN8_DR1 		(0x7<<4)
#define CHN9_DR1 		(0x8<<4)
#define CHN10_DR1 	(0x9<<4)
#define CHN11_DR1 	(0xa<<4)
#define CHN12_DR1 	(0xb<<4)
#define CHN13_DR1 	(0xc<<4)
#define CHN14_DR1 	(0xd<<4)
#define CHN15_DR1 	(0xe<<4)
#define CHN16_DR1 	(0xf<<4)

#define CHN1_DR2 		(0x0<<8)
#define CHN2_DR2 		(0x1<<8)
#define CHN3_DR2 		(0x2<<8)
#define CHN4_DR2 		(0x3<<8)
#define CHN5_DR2 		(0x4<<8)
#define CHN6_DR2 		(0x5<<8)
#define CHN7_DR2 		(0x6<<8)
#define CHN8_DR2 		(0x7<<8)
#define CHN9_DR2 		(0x8<<8)
#define CHN10_DR2 	(0x9<<8)
#define CHN11_DR2 	(0xa<<8)
#define CHN12_DR2 	(0xb<<8)
#define CHN13_DR2 	(0xc<<8)
#define CHN14_DR2 	(0xd<<8)
#define CHN15_DR2 	(0xe<<8)
#define CHN16_DR2 	(0xf<<8)

#define CHN1_DR3 		(0x0<<12)
#define CHN2_DR3 		(0x1<<12)
#define CHN3_DR3		(0x2<<12)
#define CHN4_DR3 		(0x3<<12)
#define CHN5_DR3 		(0x4<<12)
#define CHN6_DR3 		(0x5<<12)
#define CHN7_DR3 		(0x6<<12)
#define CHN8_DR3 		(0x7<<12)
#define CHN9_DR3 		(0x8<<12)
#define CHN10_DR3 	(0x9<<12)
#define CHN11_DR3 	(0xa<<12)
#define CHN12_DR3 	(0xb<<12)
#define CHN13_DR3 	(0xc<<12)
#define CHN14_DR3 	(0xd<<12)
#define CHN15_DR3 	(0xe<<12)
#define CHN16_DR3 	(0xf<<12)

#define CHN1_DR4 		(0x0<<16)
#define CHN2_DR4 		(0x1<<16)
#define CHN3_DR4 		(0x2<<16)
#define CHN4_DR4 		(0x3<<16)
#define CHN5_DR4 		(0x4<<16)
#define CHN6_DR4 		(0x5<<16)
#define CHN7_DR4 		(0x6<<16)
#define CHN8_DR4 		(0x7<<16)
#define CHN9_DR4 		(0x8<<16)
#define CHN10_DR4 	(0x9<<16)
#define CHN11_DR4 	(0xa<<16)
#define CHN12_DR4 	(0xb<<16)
#define CHN13_DR4 	(0xc<<16)
#define CHN14_DR4 	(0xd<<16)
#define CHN15_DR4 	(0xe<<16)
#define CHN16_DR4 	(0xf<<16)

#define CHN1_DR5 		(0x0<<20)
#define CHN2_DR5 		(0x1<<20)
#define CHN3_DR5 		(0x2<<20)
#define CHN4_DR5 		(0x3<<20)
#define CHN5_DR5 		(0x4<<20)
#define CHN6_DR5 		(0x5<<20)
#define CHN7_DR5 		(0x6<<20)
#define CHN8_DR5 		(0x7<<20)
#define CHN9_DR5 		(0x8<<20)
#define CHN10_DR5 	(0x9<<20)
#define CHN11_DR5 	(0xa<<20)
#define CHN12_DR5 	(0xb<<20)
#define CHN13_DR5 	(0xc<<20)
#define CHN14_DR5 	(0xd<<20)
#define CHN15_DR5 	(0xe<<20)
#define CHN16_DR5 	(0xf<<20)

#define CHN1_DR6 		(0x0<<24)
#define CHN2_DR6 		(0x1<<24)
#define CHN3_DR6 		(0x2<<24)
#define CHN4_DR6 		(0x3<<24)
#define CHN5_DR6 		(0x4<<24)
#define CHN6_DR6 		(0x5<<24)
#define CHN7_DR6 		(0x6<<24)
#define CHN8_DR6 		(0x7<<24)
#define CHN9_DR6 		(0x8<<24)
#define CHN10_DR6 	(0x9<<24)
#define CHN11_DR6 	(0xa<<24)
#define CHN12_DR6 	(0xb<<24)
#define CHN13_DR6 	(0xc<<24)
#define CHN14_DR6 	(0xd<<24)
#define CHN15_DR6 	(0xe<<24)
#define CHN16_DR6 	(0xf<<24)

#define CHN1_DR7 		(0x0<<28)
#define CHN2_DR7 		(0x1<<28)
#define CHN3_DR7 		(0x2<<28)
#define CHN4_DR7 		(0x3<<28)
#define CHN5_DR7 		(0x4<<28)
#define CHN6_DR7 		(0x5<<28)
#define CHN7_DR7 		(0x6<<28)
#define CHN8_DR7 		(0x7<<28)
#define CHN9_DR7 		(0x8<<28)
#define CHN10_DR7 	(0x9<<28)
#define CHN11_DR7 	(0xa<<28)
#define CHN12_DR7 	(0xb<<28)
#define CHN13_DR7 	(0xc<<28)
#define CHN14_DR7 	(0xd<<28)
#define CHN15_DR7 	(0xe<<28)
#define CHN16_DR7 	(0xf<<28)

//ADC mode
#define TRIGGERMODE 	0x0
#define BURSTMODE 		0x1

//ADC trigger option
#define ADC_NONE_START 0x0 							//No start (this value should be used when clearing PDN to 0).
#define ADC_START_BY_SOFTWAER 0x1 			//Start conversion now.
#define ADC_START_BY_CT16B2_CAP0 0x2 		//Start conversion when the edge selected by bit 28 occurs on CT16B2_CAP0.
#define ADC_START_BY_CT16B2_CAP1 0x3 		//Start conversion when the edge selected by bit 28 occurs on CT16B2_CAP1.
#define ADC_START_BY_CT16B2_MAT0 0x4 		//Start conversion when the edge selected by bit 28 occurs on CT16B2_MAT0.
#define ADC_START_BY_CT16B2_MAT1 0x5 		//Start conversion when the edge selected by bit 28 occurs on CT16B2_MAT1.
#define ADC_START_BY_CT16B3_MAT0 0x6 		//Start conversion when the edge selected by bit 28 occurs on CT16B3_MAT0.
#define ADC_START_BY_CT16B3_MAT1 0x7 		//Start conversion when the edge selected by bit 28 occurs on CT16B3_MAT1.
#define ADC_START_BY_PWM 0x8 						//Start conversion when PWM1 cycle Reload,

//ADC trigger signal edge
#define ADC_TRIGGER_RISE_EDGE 0x0
#define ADC_TRIGGER_FALL_EDGE 0x1

#define   ADC1_IssueSoftTrigger 		(ADC1->SSCR.bit.ADC_TRIG = 1)
#define   ADC1_EnableHighCmp0Int 	  (ADC1->HILMT.bit.INTEN0 = 1)
#define   ADC1_EnableHighCmp1Int 	  (ADC1->HILMT.bit.INTEN1 = 1)
#define   ADC1_EnableLowCmp0Int 		(ADC1->LOLMT.bit.INTEN0 = 1)
#define   ADC1_EnableLowCmp1Int 		(ADC1->LOLMT.bit.INTEN1 = 1)
#define   ADC1_DisableHighCmp0Int 	(ADC1->HILMT.bit.INTEN0 = 0)
#define   ADC1_DisableHighCmp1Int 	(ADC1->HILMT.bit.INTEN1 = 0)
#define   ADC1_DisableLowCmp0Int 	  (ADC1->LOLMT.bit.INTEN0 = 0)
#define   ADC1_DisableLowCmp1Int 	  (ADC1->LOLMT.bit.INTEN1 = 0)

#define   ADC2_IssueSoftTrigger 		(ADC2->SSCR.bit.ADC_TRIG = 1)
#define   ADC2_EnableHighCmp0Int 	  (ADC2->HILMT.bit.INTEN0 = 1)
#define   ADC2_EnableHighCmp1Int 	  (ADC2->HILMT.bit.INTEN1 = 1)
#define   ADC2_EnableLowCmp0Int 		(ADC2->LOLMT.bit.INTEN0 = 1)
#define   ADC2_EnableLowCmp1Int 		(ADC2->LOLMT.bit.INTEN1 = 1)
#define   ADC2_DisableHighCmp0Int 	(ADC2->HILMT.bit.INTEN0 = 0)
#define   ADC2_DisableHighCmp1Int 	(ADC2->HILMT.bit.INTEN1 = 0)
#define   ADC2_DisableLowCmp0Int 	  (ADC2->LOLMT.bit.INTEN0 = 0)
#define   ADC2_DisableLowCmp1Int 	  (ADC2->LOLMT.bit.INTEN1 = 0)

#define   ADC3_IssueSoftTrigger 		(ADC3->SSCR.bit.ADC_TRIG = 1)
#define   ADC3_EnableHighCmp0Int 	  (ADC3->HILMT.bit.INTEN0 = 1)
#define   ADC3_EnableHighCmp1Int 	  (ADC3->HILMT.bit.INTEN1 = 1)
#define   ADC3_EnableLowCmp0Int 		(ADC3->LOLMT.bit.INTEN0 = 1)
#define   ADC3_EnableLowCmp1Int 		(ADC3->LOLMT.bit.INTEN1 = 1)
#define   ADC3_DisableHighCmp0Int 	(ADC3->HILMT.bit.INTEN0 = 0)
#define   ADC3_DisableHighCmp1Int 	(ADC3->HILMT.bit.INTEN1 = 0)
#define   ADC3_DisableLowCmp0Int 	  (ADC3->LOLMT.bit.INTEN0 = 0)
#define   ADC3_DisableLowCmp1Int 	  (ADC3->LOLMT.bit.INTEN1 = 0)


#define   ENABLEADC1CLK							SYSCON->SYSAPB2CLKCTRL.all |= (1<<9)
#define   ENABLEADC2CLK							SYSCON->SYSAPB2CLKCTRL.all |= (1<<10)
#define   ENABLEADC3CLK							SYSCON->SYSAPB2CLKCTRL.all |= (1<<15)

#define   RESETADC1							    SYSCON->APB2RESET.all &= ~(1<<9)
#define   RESETADC2							    SYSCON->APB2RESET.all &= ~(1<<10)
#define   RESETADC3							    SYSCON->APB2RESET.all &= ~(1<<15)

#define   OpenADC1_IN1              IOCON->PA0.all = 7;
#define   OpenADC1_IN2              IOCON->PA1.all = 7;
#define   OpenADC1_IN3              IOCON->PA2.all = 7;
#define   OpenADC1_IN4              IOCON->PA3.all = 7;
#define   OpenADC1_IN5              IOCON->PA4.all = 7;
#define   OpenADC1_IN6              IOCON->PA5.all = 7;
#define   OpenADC1_IN7              IOCON->PA6.all = 7;
#define   OpenADC1_IN8              IOCON->PA7.all = 7;
#define   OpenADC1_IN9              IOCON->PB0.all = 7;
#define   OpenADC1_IN10             IOCON->PB1.all = 7;
#define   OpenADC1_IN11             IOCON->PC0.all = 7;
#define   OpenADC1_IN12             IOCON->PC1.all = 7;
#define   OpenADC1_IN13             IOCON->PC2.all = 7;
#define   OpenADC1_IN14             IOCON->PC3.all = 7;
#define   OpenADC1_IN15             IOCON->PC4.all = 7;
#define   OpenADC1_IN16             IOCON->PC5.all = 7;

#define   OpenADC2_IN1              IOCON->PA0.all = 7;
#define   OpenADC2_IN2              IOCON->PA1.all = 7;
#define   OpenADC2_IN3              IOCON->PA2.all = 7;
#define   OpenADC2_IN4              IOCON->PA3.all = 7;
#define   OpenADC2_IN5              IOCON->PA4.all = 7;
#define   OpenADC2_IN6              IOCON->PA5.all = 7;
#define   OpenADC2_IN7              IOCON->PA6.all = 7;
#define   OpenADC2_IN8              IOCON->PA7.all = 7;
#define   OpenADC2_IN9              IOCON->PB0.all = 7;
#define   OpenADC2_IN10             IOCON->PB1.all = 7;
#define   OpenADC2_IN11             IOCON->PC0.all = 7;
#define   OpenADC2_IN12             IOCON->PC1.all = 7;
#define   OpenADC2_IN13             IOCON->PC2.all = 7;
#define   OpenADC2_IN14             IOCON->PC3.all = 7;
#define   OpenADC2_IN15             IOCON->PC4.all = 7;
#define   OpenADC2_IN16             IOCON->PC5.all = 7;

#define   OpenADC3_IN1              IOCON->PA0.all = 7;
#define   OpenADC3_IN2              IOCON->PA1.all = 7;
#define   OpenADC3_IN3              IOCON->PA2.all = 7;
#define   OpenADC3_IN4              IOCON->PA3.all = 7;
#define   OpenADC3_IN5              IOCON->PF6.all = 7;
#define   OpenADC3_IN6              IOCON->PF7.all = 7;
#define   OpenADC3_IN7              IOCON->PF8.all = 7;
#define   OpenADC3_IN8              IOCON->PF9.all = 7;
#define   OpenADC3_IN9              IOCON->PF10.all= 7;
#define   OpenADC3_IN11             IOCON->PC0.all = 7;
#define   OpenADC3_IN12             IOCON->PC1.all = 7;
#define   OpenADC3_IN13             IOCON->PC2.all = 7;
#define   OpenADC3_IN14             IOCON->PC3.all = 7;


void ADC_Init(G32F_ADC_TypeDef *ADC,uint32_t conversionrate);
void ADC_DeInit(G32F_ADC_TypeDef *ADC);
void ADC_SetupChannels (G32F_ADC_TypeDef *ADC,uint32_t channelassign, uint32_t triggermode);
void ADC_SetTrigger(G32F_ADC_TypeDef *ADC,uint8_t triggersrc, uint8_t edge);
void ADC_SetHighCmp0(G32F_ADC_TypeDef *ADC,uint32_t val, uint8_t selchannel);
void ADC_SetHighCmp1(G32F_ADC_TypeDef *ADC,uint32_t val, uint8_t selchannel);
void ADC_SetLowCmp0 (G32F_ADC_TypeDef *ADC,uint32_t val, uint8_t selchannel);
void ADC_SetLowCmp1 (G32F_ADC_TypeDef *ADC,uint32_t val, uint8_t selchannel);
void ADC_EnableConversionInt(G32F_ADC_TypeDef *ADC,uint32_t inttype);
uint32_t ADC_GetConversionData(G32F_ADC_TypeDef *ADC,uint8_t dr);

//typedef struct
//{
//	uint32_t ADC_Mode;
//	FunctionalState ADC_ScanConvMode;
//	FunctionalState ADC_ContinuousConvMode;
//	uint32_t ADC_ExternalTrigConv;
//	uint32_t ADC_DataAlign;
//	uint8_t ADC_NbrOfChannel;
//}ADC_InitTypeDef;

//#define ADC_Mode_Independent                       ((uint32_t)0x00000000)
//#define ADC_Mode_RegInjecSimult                    ((uint32_t)0x00010000)
//#define ADC_Mode_RegSimult_AlterTrig               ((uint32_t)0x00020000)
//#define ADC_Mode_InjecSimult_FastInterl            ((uint32_t)0x00030000)
//#define ADC_Mode_InjecSimult_SlowInterl            ((uint32_t)0x00040000)
//#define ADC_Mode_InjecSimult                       ((uint32_t)0x00050000)
//#define ADC_Mode_RegSimult                         ((uint32_t)0x00060000)
//#define ADC_Mode_FastInterl                        ((uint32_t)0x00070000)
//#define ADC_Mode_SlowInterl                        ((uint32_t)0x00080000)
//#define ADC_Mode_AlterTrig                         ((uint32_t)0x00090000)

//#define ADC_ExternalTrigConv_T1_CC1                ((uint32_t)0x00000000) /*!< For ADC1 and ADC2 */
//#define ADC_ExternalTrigConv_T1_CC2                ((uint32_t)0x00020000) /*!< For ADC1 and ADC2 */
//#define ADC_ExternalTrigConv_T2_CC2                ((uint32_t)0x00060000) /*!< For ADC1 and ADC2 */
//#define ADC_ExternalTrigConv_T3_TRGO               ((uint32_t)0x00080000) /*!< For ADC1 and ADC2 */
//#define ADC_ExternalTrigConv_T4_CC4                ((uint32_t)0x000A0000) /*!< For ADC1 and ADC2 */
//#define ADC_ExternalTrigConv_Ext_IT11_TIM8_TRGO    ((uint32_t)0x000C0000) /*!< For ADC1 and ADC2 */

//#define ADC_ExternalTrigConv_T1_CC3                ((uint32_t)0x00040000) /*!< For ADC1, ADC2 and ADC3 */
//#define ADC_ExternalTrigConv_None                  ((uint32_t)0x000E0000) /*!< For ADC1, ADC2 and ADC3 */

//#define ADC_ExternalTrigConv_T3_CC1                ((uint32_t)0x00000000) /*!< For ADC3 only */
//#define ADC_ExternalTrigConv_T2_CC3                ((uint32_t)0x00020000) /*!< For ADC3 only */
//#define ADC_ExternalTrigConv_T8_CC1                ((uint32_t)0x00060000) /*!< For ADC3 only */
//#define ADC_ExternalTrigConv_T8_TRGO               ((uint32_t)0x00080000) /*!< For ADC3 only */
//#define ADC_ExternalTrigConv_T5_CC1                ((uint32_t)0x000A0000) /*!< For ADC3 only */
//#define ADC_ExternalTrigConv_T5_CC3                ((uint32_t)0x000C0000) /*!< For ADC3 only */

//#define ADC_DataAlign_Right                        ((uint32_t)0x00000000)
//#define ADC_DataAlign_Left                         ((uint32_t)0x00000800)

//#define ADC_Channel_0                               ((uint8_t)0x00)
//#define ADC_Channel_1                               ((uint8_t)0x01)
//#define ADC_Channel_2                               ((uint8_t)0x02)
//#define ADC_Channel_3                               ((uint8_t)0x03)
//#define ADC_Channel_4                               ((uint8_t)0x04)
//#define ADC_Channel_5                               ((uint8_t)0x05)
//#define ADC_Channel_6                               ((uint8_t)0x06)
//#define ADC_Channel_7                               ((uint8_t)0x07)
//#define ADC_Channel_8                               ((uint8_t)0x08)
//#define ADC_Channel_9                               ((uint8_t)0x09)
//#define ADC_Channel_10                              ((uint8_t)0x0A)
//#define ADC_Channel_11                              ((uint8_t)0x0B)
//#define ADC_Channel_12                              ((uint8_t)0x0C)
//#define ADC_Channel_13                              ((uint8_t)0x0D)
//#define ADC_Channel_14                              ((uint8_t)0x0E)
//#define ADC_Channel_15                              ((uint8_t)0x0F)
//#define ADC_Channel_16                              ((uint8_t)0x10)
//#define ADC_Channel_17                              ((uint8_t)0x11)

//#define ADC_Channel_TempSensor                      ((uint8_t)ADC_Channel_16)
//#define ADC_Channel_Vrefint                         ((uint8_t)ADC_Channel_17)

//#define ADC_SampleTime_1Cycles5                    ((uint8_t)0x00)
//#define ADC_SampleTime_7Cycles5                    ((uint8_t)0x01)
//#define ADC_SampleTime_13Cycles5                   ((uint8_t)0x02)
//#define ADC_SampleTime_28Cycles5                   ((uint8_t)0x03)
//#define ADC_SampleTime_41Cycles5                   ((uint8_t)0x04)
//#define ADC_SampleTime_55Cycles5                   ((uint8_t)0x05)
//#define ADC_SampleTime_71Cycles5                   ((uint8_t)0x06)
//#define ADC_SampleTime_239Cycles5                  ((uint8_t)0x07)

//#define ADC_ExternalTrigInjecConv_T2_TRGO           ((uint32_t)0x00002000) /*!< For ADC1 and ADC2 */
//#define ADC_ExternalTrigInjecConv_T2_CC1            ((uint32_t)0x00003000) /*!< For ADC1 and ADC2 */
//#define ADC_ExternalTrigInjecConv_T3_CC4            ((uint32_t)0x00004000) /*!< For ADC1 and ADC2 */
//#define ADC_ExternalTrigInjecConv_T4_TRGO           ((uint32_t)0x00005000) /*!< For ADC1 and ADC2 */
//#define ADC_ExternalTrigInjecConv_Ext_IT15_TIM8_CC4 ((uint32_t)0x00006000) /*!< For ADC1 and ADC2 */

//#define ADC_ExternalTrigInjecConv_T1_TRGO           ((uint32_t)0x00000000) /*!< For ADC1, ADC2 and ADC3 */
//#define ADC_ExternalTrigInjecConv_T1_CC4            ((uint32_t)0x00001000) /*!< For ADC1, ADC2 and ADC3 */
//#define ADC_ExternalTrigInjecConv_None              ((uint32_t)0x00007000) /*!< For ADC1, ADC2 and ADC3 */

//#define ADC_ExternalTrigInjecConv_T4_CC3            ((uint32_t)0x00002000) /*!< For ADC3 only */
//#define ADC_ExternalTrigInjecConv_T8_CC2            ((uint32_t)0x00003000) /*!< For ADC3 only */
//#define ADC_ExternalTrigInjecConv_T8_CC4            ((uint32_t)0x00004000) /*!< For ADC3 only */
//#define ADC_ExternalTrigInjecConv_T5_TRGO           ((uint32_t)0x00005000) /*!< For ADC3 only */
//#define ADC_ExternalTrigInjecConv_T5_CC4            ((uint32_t)0x00006000) /*!< For ADC3 only */

//#define ADC_InjectedChannel_1                       ((uint8_t)0x14)
//#define ADC_InjectedChannel_2                       ((uint8_t)0x18)
//#define ADC_InjectedChannel_3                       ((uint8_t)0x1C)
//#define ADC_InjectedChannel_4                       ((uint8_t)0x20)

//#define ADC_AnalogWatchdog_SingleRegEnable         ((uint32_t)0x00800200)
//#define ADC_AnalogWatchdog_SingleInjecEnable       ((uint32_t)0x00400200)
//#define ADC_AnalogWatchdog_SingleRegOrInjecEnable  ((uint32_t)0x00C00200)
//#define ADC_AnalogWatchdog_AllRegEnable            ((uint32_t)0x00800000)
//#define ADC_AnalogWatchdog_AllInjecEnable          ((uint32_t)0x00400000)
//#define ADC_AnalogWatchdog_AllRegAllInjecEnable    ((uint32_t)0x00C00000)
//#define ADC_AnalogWatchdog_None                    ((uint32_t)0x00000000)

//#define ADC_IT_EOC                                 ((uint16_t)0x0220)
//#define ADC_IT_AWD                                 ((uint16_t)0x0140)
//#define ADC_IT_JEOC                                ((uint16_t)0x0480)

//#define ADC_FLAG_AWD                               ((uint8_t)0x01)
//#define ADC_FLAG_EOC                               ((uint8_t)0x02)
//#define ADC_FLAG_JEOC                              ((uint8_t)0x04)
//#define ADC_FLAG_JSTRT                             ((uint8_t)0x08)
//#define ADC_FLAG_STRT                              ((uint8_t)0x10)

//void ADC_DeInit(G32F_ADC_TypeDef* ADCx);
//void ADC_Init(G32F_ADC_TypeDef* ADCx, ADC_InitTypeDef* ADC_InitStruct);
//void ADC_StructInit(ADC_InitTypeDef* ADC_InitStruct);
//void ADC_Cmd(G32F_ADC_TypeDef* ADCx, FunctionalState NewState);
//void ADC_DMACmd(G32F_ADC_TypeDef* ADCx, FunctionalState NewState);
//void ADC_ITConfig(G32F_ADC_TypeDef* ADCx, uint16_t ADC_IT, FunctionalState NewState);
//void ADC_ResetCalibration(G32F_ADC_TypeDef* ADCx);
//FlagStatus ADC_GetResetCalibrationStatus(G32F_ADC_TypeDef* ADCx);
//void ADC_StartCalibration(G32F_ADC_TypeDef* ADCx);
//FlagStatus ADC_GetCalibrationStatus(G32F_ADC_TypeDef* ADCx);
//void ADC_SoftwareStartConvCmd(G32F_ADC_TypeDef* ADCx, FunctionalState NewState);
//FlagStatus ADC_GetSoftwareStartConvStatus(G32F_ADC_TypeDef* ADCx);
//void ADC_DiscModeChannelCountConfig(G32F_ADC_TypeDef* ADCx, uint8_t Number);
//void ADC_DiscModeCmd(G32F_ADC_TypeDef* ADCx, FunctionalState NewState);
//void ADC_RegularChannelConfig(G32F_ADC_TypeDef* ADCx, uint8_t ADC_Channel, uint8_t Rank, uint8_t ADC_SampleTime);
//void ADC_ExternalTrigConvCmd(G32F_ADC_TypeDef* ADCx, FunctionalState NewState);
//uint16_t ADC_GetConversionValue(G32F_ADC_TypeDef* ADCx);
//uint32_t ADC_GetDualModeConversionValue(void);
//void ADC_AutoInjectedConvCmd(G32F_ADC_TypeDef* ADCx, FunctionalState NewState);
//void ADC_InjectedDiscModeCmd(G32F_ADC_TypeDef* ADCx, FunctionalState NewState);
//void ADC_ExternalTrigInjectedConvConfig(G32F_ADC_TypeDef* ADCx, uint32_t ADC_ExternalTrigInjecConv);
//void ADC_ExternalTrigInjectedConvCmd(G32F_ADC_TypeDef* ADCx, FunctionalState NewState);
//void ADC_SoftwareStartInjectedConvCmd(G32F_ADC_TypeDef* ADCx, FunctionalState NewState);
//FlagStatus ADC_GetSoftwareStartInjectedConvCmdStatus(G32F_ADC_TypeDef* ADCx);
//void ADC_InjectedChannelConfig(G32F_ADC_TypeDef* ADCx, uint8_t ADC_Channel, uint8_t Rank, uint8_t ADC_SampleTime);
//void ADC_InjectedSequencerLengthConfig(G32F_ADC_TypeDef* ADCx, uint8_t Length);
//void ADC_SetInjectedOffset(G32F_ADC_TypeDef* ADCx, uint8_t ADC_InjectedChannel, uint16_t Offset);
//uint16_t ADC_GetInjectedConversionValue(G32F_ADC_TypeDef* ADCx, uint8_t ADC_InjectedChannel);
//void ADC_AnalogWatchdogCmd(G32F_ADC_TypeDef* ADCx, uint32_t ADC_AnalogWatchdog);
//void ADC_AnalogWatchdogThresholdsConfig(G32F_ADC_TypeDef* ADCx, uint16_t HighThreshold, uint16_t LowThreshold);
//void ADC_AnalogWatchdogSingleChannelConfig(G32F_ADC_TypeDef* ADCx, uint8_t ADC_Channel);
//void ADC_TempSensorVrefintCmd(FunctionalState NewState);
//FlagStatus ADC_GetFlagStatus(G32F_ADC_TypeDef* ADCx, uint8_t ADC_FLAG);
//void ADC_ClearFlag(G32F_ADC_TypeDef* ADCx, uint8_t ADC_FLAG);
//ITStatus ADC_GetITStatus(G32F_ADC_TypeDef* ADCx, uint16_t ADC_IT);
//void ADC_ClearITPendingBit(G32F_ADC_TypeDef* ADCx, uint16_t ADC_IT);

#endif /* end __ADC_H */
/*****************************************************************************
**                            End Of File
******************************************************************************/
