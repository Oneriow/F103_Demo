/*****************************************************************************
 *   gt_iap.h:  Header file for Gorgetek G32F1
 *
 *   Copyright(C) 2015, Gorge Technology
 *   All rights reserved.
 *
 *   History
 *   2015.02.21  ver 1.01    Prelimnary version
 *
******************************************************************************/
/* Includes ------------------------------------------------------------------*/

#include "g32f1xx.h"
#include "gt_sys.h"
#include "gt_iap.h"
extern uint32_t MainClock;
/*****************************************************************************
Function Name	IAP_Init
Function Definition	void IAP_Init (void)
Function Description	Initial IAP module
Input Parameters	No 
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			
*****************************************************************************/
void IAP_Init (void)
{
	//enable Flash HCLK
	SYSCON->SYSAHBCLKCTRL.bit.FLASHCLK = 1;
	
	return;
}
/*****************************************************************************
Function Name	IAP_Deinit
Function Definition	void IAP_Deinit (void)
Function Description	De-Initial IAP module
Input Parameters	No 
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12	
*****************************************************************************/
void IAP_Deinit(void)
{
	//disable Flash HCLK
	SYSCON->SYSAHBCLKCTRL.bit.FLASHCLK = 0;	
	return;
}

/*****************************************************************************
Function Name	IAP_Flash_Erase
Function Definition	void IAP_Flash_Erase (uint32_t addr)
Function Description	IAP Flash Erase module
Input Parameters	No 
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12		
*****************************************************************************/
void IAP_Flash_Erase(uint32_t addr)
{
  GT_FMC->FLASHADDR = addr;
	GT_FMC->FLASHCTRL = 0x04;
}

/*****************************************************************************
Function Name	IAP_Flash_Program
Function Definition	void IAP_Flash_Program (uint32_t addr,uint32_t data)
Function Description	IAP Flash program module
Input Parameters	No 
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12		
*****************************************************************************/
void IAP_Flash_Program(uint32_t addr,uint32_t data)
{
  GT_FMC->FLASHADDR = addr;
	GT_FMC->PRGDATA   = data;
	GT_FMC->FLASHCTRL = 0x02;
}

