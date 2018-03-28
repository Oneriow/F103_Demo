/*****************************************************************************
 *   GT_GPIO:  Sourse file for Gorge MCU GPIO application
 *
 *   Copyright(C) 2015, Gorge Technology
 *   All rights reserved.
 *
 *   History
 *   2015.08.14  ver 1.00
 *
******************************************************************************/
#include "gt_can.h"
#include "gt_sys.h"


/*****************************************************************************
Function Name	CAN_SetMode
Function Definition	void CAN_SetMode(uint32_t mod)
Function Description	Set CAN mode
Input Parameters	
Condition	#include sys.h
Function called	-

Last Change Date: 2015/12/12			
*****************************************************************************/
void CAN_SetMode(uint32_t mode)
{

	GT_CAN -> MOD  = mode ; 

	return;
}

/*****************************************************************************
Function Name	CAN_GetStatus
Function Definition	int CAN_GetStatus()
Function Description	Get CAN SR status register
Input Parameters	
Condition	#include sys.h
Function called	-

Last Change Date: 2015/12/12			
*****************************************************************************/
int CAN_GetStatus(void)
{
	return (GT_CAN -> SR);
}


/*****************************************************************************
Function Name	CAN_ClearStatus
Function Definition	int CAN_ClearStatus()
Function Description	Clear CAN SR status register
Input Parameters	
Condition	#include sys.h
Function called	-

Last Change Date: 2015/12/12			
*****************************************************************************/
void CAN_ClearStatus(uint32_t clrbit)
{
	GT_CAN -> SR &= ~clrbit;
	return ;
}


/*****************************************************************************
Function Name	CAN_SetCMD
Function Definition	int CAN_SetCMD()
Function Description	Set CAN command register
Input Parameters	
Condition	#include sys.h
Function called	-

Last Change Date: 2015/12/12			
*****************************************************************************/
void CAN_SetCMD(uint32_t cmddata)
{
	GT_CAN -> CMR |= cmddata;
	return;
}

/*****************************************************************************
Function Name	CAN_ClrCMD
Function Definition	int CAN_ClrCMD()
Function Description	CAN command register
Input Parameters	
Condition	#include sys.h
Function called	-

Last Change Date: 2015/12/12			
*****************************************************************************/
void CAN_ClrCMD(uint32_t cmddata)
{
	GT_CAN -> CMR &= ~cmddata;
	return;
}

/*****************************************************************************
Function Name	CAN_EnableInt
Function Definition	void CAN_EnableInt(uint32_t intbit)
Function Description	Setup CAN interrupt
Input Parameters	
Condition	#include sys.h
Function called	-

Last Change Date: 2015/12/12			
*****************************************************************************/
void CAN_EnableInt(uint32_t intbit)
{

	GT_CAN -> IER  |= intbit ; ///int enable
	NVIC_EnableIRQ(CAN_IRQn);
	return;
}

/*****************************************************************************
Function Name	CAN_DisableInt
Function Definition	void CAN_DisableInt(uint32_t intbit)
Condition	#include sys.h
Function called	-

Last Chang Date: 2015/12/12			
*****************************************************************************/
void CAN_DisableInt(uint32_t intbit)
{
	GT_CAN -> IER  &= ~intbit ; ///int disable
	NVIC_DisableIRQ(CAN_IRQn);
	return;
}

