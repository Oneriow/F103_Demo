/*****************************************************************************
 *   G32F_GPIO.h:  Header file for Gorge G32F1xx Family Microprocessors
 *
 *   Copyright(C) 2015, Gorge tech. Ltd.
 *   All rights reserved.
 *
 *   History
 *   2015  ver 1.00    Prelimnary version, first Release
 *
******************************************************************************/
#ifndef __GPIO_H 
#define __GPIO_H

#include "g32f1xx.h"


//--GPIO Registers BITS Field---------------------------------------------------------------------------------------
struct GPIO_BITS {								  // bit description: 0=not masked/LOW; 1=masked/HIGH
				uint32_t IO0:1;							// 0 PIO2_0 access control
				uint32_t IO1:1;							// 1 PIO2_1 access control
				uint32_t IO2:1;							// 2 PIO2_2 access control
				uint32_t IO3:1;							// 3 PIO2_3 access control
				uint32_t IO4:1;							// 4 PIO2_4 access control
				uint32_t IO5:1;							// 5 PIO2_5 access control
				uint32_t IO6:1;							// 6 PIO2_6 access control
				uint32_t IO7:1;							// 7 PIO2_7 access control
				uint32_t IO8:1;							// 8 PIO2_8 access control
				uint32_t IO9:1;							// 9 PIO2_9 access control
				uint32_t IO10:1;						// 10 PIO2_10 access control
				uint32_t IO11:1;						// 11 PIO2_11 access control
				uint32_t IO12:1;						// 12 PIO2_12 access control
				uint32_t IO13:1;						// 13 PIO2_13 access control
				uint32_t IO14:1;						// 14 PIO2_14 access control
				uint32_t IO15:1;						// 15 PIO2_15 access control
				uint32_t RSVD:16;						// 31:16 Reserved
};

union GPIO_MASK_REG {
				uint32_t					    all;
				struct GPIO_BITS			bit;
};

union GPIO_PIN_REG {
				uint32_t					    all;
				struct GPIO_BITS			bit;
};

union GPIO_OUT_REG {
				uint32_t					    all;
				struct GPIO_BITS			bit;
};

union GPIO_SET_REG {
				uint32_t					    all;
				struct GPIO_BITS			bit;
};

union GPIO_CLR_REG {
				uint32_t					    all;
				struct GPIO_BITS			bit;
};

union GPIO_NOT_REG {
				uint32_t					    all;
				struct GPIO_BITS			bit;
};

union GPIO_DIR_REG {
				uint32_t					    all;
				struct GPIO_BITS			bit;
};

// GPIO Interrupt Sense Register: 0=edge, 1=level, Reset=0
union GPIO_IS_REG {
				uint32_t					    all;
				struct GPIO_BITS			bit;
};

// GPIO Interrupt Both Edge Sense Register: 0=depend on IEV, 1=Both edge, Reset=0
union GPIO_IBE_REG {
				uint32_t					    all;
				struct GPIO_BITS			bit;
};

// GPIO Interrupt Event Register(depend on IS): 
//0=falling edge/LOW level, 1=rising edge/HIGH level, Reset=0
union GPIO_IEV_REG {
				uint32_t					    all;
				struct GPIO_BITS			bit;
};

// GPIO Interrupt Mask Register: 0=Masked, 1=Not masked
union GPIO_IM_REG {
				uint32_t					    all;
				struct GPIO_BITS			bit;
};

// GPIO Raw Interrupt Mask Status Register: 0=No, 1=Yes(RO)
union GPIO_RIS_REG {
				uint32_t					    all;
				struct GPIO_BITS			bit;
};

// GPIO Masked Interrupt Status Register: 0=No, 1=Yes(RO)
union GPIO_MIS_REG {
				uint32_t					    all;
				struct GPIO_BITS			bit;
};

// GPIO Interrupt Clear Register: 0=No effect, 1=Clear Flag(WO)
union GPIO_IC_REG {
				uint32_t					    all;
				struct GPIO_BITS			bit;
};

	 
/*------------- General Purpose Input/Output (GPIO) --------------------------*/
/** @addtogroup G32F_GPIO G32F1xx General Purpose Input/Output 
  @{
*/
typedef struct
{    
	__IO	union GPIO_MASK_REG		MASK;		/*!< Offset:0x000 GPIO mask register:PIN,OUT,SET,CLR,NOT (R/W) */
	__I		union GPIO_PIN_REG	  PIN;		/*!< Offset:0x004 GPIO value register (RO)                     */
	__IO	union GPIO_OUT_REG		OUT;		/*!< Offset:0x008 GPIO output value register (R/W)             */
	__O		union GPIO_SET_REG	  SET;		/*!< Offset:0x00C GPIO output value set register (WO)          */
	__O		union GPIO_CLR_REG	  CLR;		/*!< Offset:0x010 GPIO output value clear register (WO)        */
	__O		union GPIO_NOT_REG	  NOT;		/*!< Offset:0x014 GPIO output value invert register (WO)       */
	__IO	uint32_t RESERVE[2];
	__IO	union GPIO_DIR_REG		DIR;    /*!< Offset:0x020 Data direction register (R/W)                */
	__IO	union GPIO_IS_REG		  IS;		  /*!< Offset:0x024 Interrupt sense register (R/W)               */
	__IO	union GPIO_IBE_REG		IBE;		/*!< Offset:0x028 Interrupt both edges register (R/W)          */
	__IO	union GPIO_IEV_REG		IEV;		/*!< Offset:0x02C Interrupt event register (R/W)               */
	__IO	union GPIO_IM_REG		  IE;		  /*!< Offset:0x030 Interrupt mask register (R/W)                */
	__I		union GPIO_RIS_REG	  RIS;		/*!< Offset:0x034 Raw Interrupt status register (RO)           */
	__I		union GPIO_MIS_REG	  MIS;		/*!< Offset:0x038 Masked Interrupt status register (RO)        */
	__O		union GPIO_IC_REG	   IC;		  /*!< Offset:0x03C Interrupt clear register (WO)                */
} G32F_GPIO_TypeDef;

//Define GPIO
#define		GPIOA			((G32F_GPIO_TypeDef   *) GT_GPIOA_BASE )
#define		GPIOB			((G32F_GPIO_TypeDef   *) GT_GPIOB_BASE )
#define		GPIOC			((G32F_GPIO_TypeDef   *) GT_GPIOC_BASE )
#define		GPIOD			((G32F_GPIO_TypeDef   *) GT_GPIOD_BASE )
#define		GPIOE			((G32F_GPIO_TypeDef   *) GT_GPIOE_BASE )
#define		GPIOF			((G32F_GPIO_TypeDef   *) GT_GPIOF_BASE )
#define		GPIOG			((G32F_GPIO_TypeDef   *) GT_GPIOG_BASE )

#define		GPIOA			((G32F_GPIO_TypeDef   *) GT_GPIOA_BASE )
#define		GPIOB			((G32F_GPIO_TypeDef   *) GT_GPIOB_BASE )
#define		GPIOC			((G32F_GPIO_TypeDef   *) GT_GPIOC_BASE )
#define		GPIOD			((G32F_GPIO_TypeDef   *) GT_GPIOD_BASE )
#define		GPIOE			((G32F_GPIO_TypeDef   *) GT_GPIOE_BASE )
#define		GPIOF			((G32F_GPIO_TypeDef   *) GT_GPIOF_BASE )
#define		GPIOG			((G32F_GPIO_TypeDef   *) GT_GPIOG_BASE )

#define PIN_SET 				                   0x1
#define PIN_RESET 				                 0x0
#define PIN_EDGE_SENSE 				             0x0
#define PIN_LEVEL_SENSE 			             0x1
#define PIN_IEV_CTL 				               0x0
#define PIN_BOTH_EDGE_CTL 			           0x1
#define PIN_FALLEDGE_OR_LOWLEVEL_TRIGGER 	 0x0
#define PIN_RISEEDGE_OR_HIGHLEVEL_TRIGGER  0x1


void GPIO_ConfigPinsAsInput(G32F_GPIO_TypeDef*port, uint16_t pins);
void GPIO_ConfigPinsAsOutput(G32F_GPIO_TypeDef*port, uint16_t pins);
void GPIO_SetPin (G32F_GPIO_TypeDef*port, uint16_t pin);
void GPIO_ResetPin (G32F_GPIO_TypeDef*port, uint16_t pin);
void GPIO_InvertOutPin(G32F_GPIO_TypeDef*port, uint16_t pin);
uint8_t GPIO_GetPinState(G32F_GPIO_TypeDef*port, uint16_t pin);
uint16_t GPIO_GetPortState(G32F_GPIO_TypeDef*port);
void GPIO_SetPortMask(G32F_GPIO_TypeDef*port, uint16_t pins);
void GPIO_ResetPortMask(G32F_GPIO_TypeDef*port, uint16_t pins);
uint16_t GPIO_ReadPort(G32F_GPIO_TypeDef*port);
void GPIO_WritePort(G32F_GPIO_TypeDef*port, uint16_t data);
void GPIO_EnableInt(G32F_GPIO_TypeDef*port, uint16_t pin, uint8_t triggeredge);
void GPIO_DisableInt(G32F_GPIO_TypeDef *port, uint16_t pin);
void GPIO_ClrIntflag(G32F_GPIO_TypeDef *port, uint16_t pin);

#define ENABLEGPIOACLK  (SYSCON->SYSAPB2CLKCTRL.all |= (1<<2))
#define ENABLEGPIOBCLK  (SYSCON->SYSAPB2CLKCTRL.all |= (1<<3))
#define ENABLEGPIOCCLK  (SYSCON->SYSAPB2CLKCTRL.all |= (1<<4))
#define ENABLEGPIODCLK  (SYSCON->SYSAPB2CLKCTRL.all |= (1<<5))
#define ENABLEGPIOECLK  (SYSCON->SYSAPB2CLKCTRL.all |= (1<<6))
#define ENABLEGPIOFCLK  (SYSCON->SYSAPB2CLKCTRL.all |= (1<<7))
#define ENABLEGPIOGCLK  (SYSCON->SYSAPB2CLKCTRL.all |= (1<<8))

#define DISABLEGPIOACLK (SYSCON->SYSAPB2CLKCTRL.all &= ~(1<<2))
#define DISABLEGPIOBCLK (SYSCON->SYSAPB2CLKCTRL.all &= ~(1<<3))
#define DISABLEGPIOCCLK (SYSCON->SYSAPB2CLKCTRL.all &= ~(1<<4))
#define DISABLEGPIODCLK (SYSCON->SYSAPB2CLKCTRL.all &= ~(1<<5))
#define DISABLEGPIOECLK (SYSCON->SYSAPB2CLKCTRL.all &= ~(1<<6))
#define DISABLEGPIOFCLK (SYSCON->SYSAPB2CLKCTRL.all &= ~(1<<7))
#define DISABLEGPIOGCLK (SYSCON->SYSAPB2CLKCTRL.all &= ~(1<<8))

#define SETGPIOAMASK(mask) (GPIOA->MASK.all = mask)
#define SETGPIOBMASK(mask) (GPIOB->MASK.all = mask)
#define SETGPIOCMASK(mask) (GPIOC->MASK.all = mask)
#define SETGPIODMASK(mask) (GPIOD->MASK.all = mask)
#define SETGPIOEMASK(mask) (GPIOE->MASK.all = mask)
#define SETGPIOFMASK(mask) (GPIOF->MASK.all = mask)
#define SETGPIOGMASK(mask) (GPIOG->MASK.all = mask)

#define PIN0  IO_PIN0 
#define PIN1  IO_PIN1 
#define PIN2  IO_PIN2 
#define PIN3  IO_PIN3 
#define PIN4  IO_PIN4 
#define PIN5  IO_PIN5 
#define PIN6  IO_PIN6 
#define PIN7  IO_PIN7 
#define PIN8  IO_PIN8 
#define PIN9  IO_PIN9 
#define PIN10 IO_PIN10 	
#define PIN11 IO_PIN11 	
#define PIN12 IO_PIN12 	
#define PIN13 IO_PIN13 	
#define PIN14 IO_PIN14 	
#define PIN15 IO_PIN15 	

#define GPIO_Pin_0                 ((uint16_t)0x0001)  /*!< Pin 0 selected */
#define GPIO_Pin_1                 ((uint16_t)0x0002)  /*!< Pin 1 selected */
#define GPIO_Pin_2                 ((uint16_t)0x0004)  /*!< Pin 2 selected */
#define GPIO_Pin_3                 ((uint16_t)0x0008)  /*!< Pin 3 selected */
#define GPIO_Pin_4                 ((uint16_t)0x0010)  /*!< Pin 4 selected */
#define GPIO_Pin_5                 ((uint16_t)0x0020)  /*!< Pin 5 selected */
#define GPIO_Pin_6                 ((uint16_t)0x0040)  /*!< Pin 6 selected */
#define GPIO_Pin_7                 ((uint16_t)0x0080)  /*!< Pin 7 selected */
#define GPIO_Pin_8                 ((uint16_t)0x0100)  /*!< Pin 8 selected */
#define GPIO_Pin_9                 ((uint16_t)0x0200)  /*!< Pin 9 selected */
#define GPIO_Pin_10                ((uint16_t)0x0400)  /*!< Pin 10 selected */
#define GPIO_Pin_11                ((uint16_t)0x0800)  /*!< Pin 11 selected */
#define GPIO_Pin_12                ((uint16_t)0x1000)  /*!< Pin 12 selected */
#define GPIO_Pin_13                ((uint16_t)0x2000)  /*!< Pin 13 selected */
#define GPIO_Pin_14                ((uint16_t)0x4000)  /*!< Pin 14 selected */
#define GPIO_Pin_15                ((uint16_t)0x8000)  /*!< Pin 15 selected */
#define GPIO_Pin_All               ((uint16_t)0xFFFF)  /*!< All pins selected */

#define GPIO_PortSourceGPIOA       ((uint8_t)0x00)
#define GPIO_PortSourceGPIOB       ((uint8_t)0x01)
#define GPIO_PortSourceGPIOC       ((uint8_t)0x02)
#define GPIO_PortSourceGPIOD       ((uint8_t)0x03)
#define GPIO_PortSourceGPIOE       ((uint8_t)0x04)
#define GPIO_PortSourceGPIOF       ((uint8_t)0x05)
#define GPIO_PortSourceGPIOG       ((uint8_t)0x06)

#define GPIO_PinSource0            ((uint8_t)0x00)
#define GPIO_PinSource1            ((uint8_t)0x01)
#define GPIO_PinSource2            ((uint8_t)0x02)
#define GPIO_PinSource3            ((uint8_t)0x03)
#define GPIO_PinSource4            ((uint8_t)0x04)
#define GPIO_PinSource5            ((uint8_t)0x05)
#define GPIO_PinSource6            ((uint8_t)0x06)
#define GPIO_PinSource7            ((uint8_t)0x07)
#define GPIO_PinSource8            ((uint8_t)0x08)
#define GPIO_PinSource9            ((uint8_t)0x09)
#define GPIO_PinSource10           ((uint8_t)0x0A)
#define GPIO_PinSource11           ((uint8_t)0x0B)
#define GPIO_PinSource12           ((uint8_t)0x0C)
#define GPIO_PinSource13           ((uint8_t)0x0D)
#define GPIO_PinSource14           ((uint8_t)0x0E)
#define GPIO_PinSource15           ((uint8_t)0x0F)

typedef struct
{
  __IO uint32_t EVCR;
  __IO uint32_t MAPR;
  __IO uint32_t EXTICR[4];
  uint32_t RESERVED0;
  __IO uint32_t MAPR2;  
} AFIO_TypeDef;

typedef enum
{
	GPIO_Speed_10MHz = 1,
	GPIO_Speed_2MHz,
	GPIO_Speed_50MHz
}GPIOSpeed_TypeDef;

typedef enum
{ 
	GPIO_Mode_AIN = 0,
  GPIO_Mode_IN_FLOATING = 1,
  GPIO_Mode_IPD = 2,
  GPIO_Mode_IPU = 3,
  GPIO_Mode_Out_OD = 4,
  GPIO_Mode_Out_PP = 5,
  GPIO_Mode_AF_OD = 6,
  GPIO_Mode_AF_PP = 7
}GPIOMode_TypeDef;

typedef struct
{
  uint16_t GPIO_Pin;             /*!< Specifies the GPIO pins to be configured.
                                      This parameter can be any value of @ref GPIO_pins_define */

  GPIOSpeed_TypeDef GPIO_Speed;  /*!< Specifies the speed for the selected pins.
                                      This parameter can be a value of @ref GPIOSpeed_TypeDef */

  GPIOMode_TypeDef GPIO_Mode;    /*!< Specifies the operating mode for the selected pins.
                                      This parameter can be a value of @ref GPIOMode_TypeDef */
}GPIO_InitTypeDef;

typedef enum
{
	Bit_RESET = 0,
  Bit_SET
}BitAction;

void GPIO_DeInit(G32F_GPIO_TypeDef* GPIOx);
void GPIO_AFIODeInit(void);
void GPIO_Init(G32F_GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct);
void GPIO_StructInit(GPIO_InitTypeDef* GPIO_InitStruct);
uint8_t GPIO_ReadInputDataBit(G32F_GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
uint16_t GPIO_ReadInputData(G32F_GPIO_TypeDef* GPIOx);
uint8_t GPIO_ReadOutputDataBit(G32F_GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
uint16_t GPIO_ReadOutputData(G32F_GPIO_TypeDef* GPIOx);
void GPIO_SetBits(G32F_GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void GPIO_ResetBits(G32F_GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void GPIO_WriteBit(G32F_GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, BitAction BitVal);
void GPIO_Write(G32F_GPIO_TypeDef* GPIOx, uint16_t PortVal);
void GPIO_PinLockConfig(G32F_GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void GPIO_EventOutputConfig(uint8_t GPIO_PortSource, uint8_t GPIO_PinSource);
void GPIO_EXTILineConfig(uint8_t GPIO_PortSource, uint8_t GPIO_PinSource);

#endif /* end __GPIO_H */
/*****************************************************************************
**                            End Of File
******************************************************************************/
