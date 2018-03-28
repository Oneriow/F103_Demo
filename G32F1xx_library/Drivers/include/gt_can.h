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

#include "g32f1xx.h"


#define ENABLECAN1CLK  (SYSCON->SYSAPB1CLKCTRL.all |= (1<<25))
#define ENABLECAN2CLK  (SYSCON->SYSAPB1CLKCTRL.all |= (1<<26))

#define DISABLECAN1CLK (SYSCON->SYSAPB1CLKCTRL.all &= ~(1<<25))
#define DISABLECAN2CLK (SYSCON->SYSAPB1CLKCTRL.all &= ~(1<<26))

#define CAN1_TX_PA12 0x15
#define CAN1_TX_PB9  0x15
#define CAN1_RX_PA11 0x15
#define CAN1_RX_PB8  0x15

//Mode bit
#define SleepMode				0x10
#define ACCFMode				0x08
#define SelfTestMode		0x04
#define ListenOnlyMode	0x02
#define ResetMode				0x01
#define ActiveMode			0x00

//Interrupt enable bit
#define BEIE 0x80
#define ALIE 0x40
#define EPIE 0x20
#define WUIE 0x10
#define DOIE 0x08
#define EIE  0x04
#define TIE  0x02
#define RIE  0x01


//CMD bit
#define SelfRecReq					0x10
#define	ClearDataOverrun		0x08
#define	ReleaseRecBuf				0x04
#define AbortTrans					0x02
#define	TransReq						0x01


//Status Register bit
#define BusSt		0x80
#define	ErrorSt	0x40
#define	TranSt	0x20
#define	RecSt		0x10
#define	TranComplete	0x08
#define	TranBufSt	0x04
#define	DataOvSt	0x02
#define	RecBufSt	0x01

void CAN_SetMode(uint32_t mode);
void CAN_EnableInt(uint32_t intbit);
void CAN_DisableInt(uint32_t intbit);
int CAN_GetStatus(void);
void CAN_ClearStatus(uint32_t clrbit);
void CAN_SetCMD(uint32_t cmddata);
void CAN_ClrCMD(uint32_t cmddata);

 /* end __CAN */
/*****************************************************************************
**                            End Of File
******************************************************************************/
