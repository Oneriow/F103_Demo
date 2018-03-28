/*****************************************************************************
 *   gt_uart.h:  Header file for Gorgetek G32F1xx
 *
 *   Copyright(C) 2015, Gorge Technology
 *   All rights reserved.
 *
 *   History
 *   2015.01.21  ver 1.0    Prelimnary version
 *
******************************************************************************/
/* Includes ------------------------------------------------------------------*/

#include "g32f1xx.h"
#include "gt_uart.h"
#include "gt_sys.h"


extern uint32_t MainClock;
/**
  * @brief  Initializes the USARTx peripheral according to the specified
  *         parameters in the USART_InitStruct .
  * @param  USARTx: Select the USART or the UART peripheral. 
  *   This parameter can be one of the following values:
  *   USART1, USART2, USART3, UART4 or UART5.
  * @param  USART_InitStruct: pointer to a USART_InitTypeDef structure
  *         that contains the configuration information for the specified USART 
  *         peripheral.
  * @retval None
  */
void USART_Init(USART_TypeDef* USARTx, USART_InitTypeDef* USART_InitStruct)
{
	//All Uarts use same divider.
	SYSCON->UARTCLKDIV.bit.DIV = 0x1;     	/* uart_div_divided by 1 */	
	
	if (USARTx == USART1)
	{
		//disable UART1 IRQ during setup
		NVIC_DisableIRQ(UART1_IRQn);
		//Enable UART1 clock
		SYSCON->SYSAPB2CLKCTRL.bit.UART1CLK=1;	//enable UART1 PCLK
		//reset UART1
		SYSCON->APB2RESET.bit.UART1RSTN=1;
		SYSCON->APB2RESET.bit.UART1RSTN=0;

	}else if (USARTx==USART2)
	{
		//disable UART2 IRQ during setup
		NVIC_DisableIRQ(UART2_IRQn);
		/* Enable UART2 clock */
		SYSCON->SYSAPB1CLKCTRL.bit.UART2CLK=1;	//enable UART2 PCLK
		//reset UART2
		SYSCON->APB1RESET.bit.UART2RSTN=1;
		SYSCON->APB1RESET.bit.UART2RSTN=0;
	}else if (USARTx==USART3)
	{
		//disable UART3 IRQ during setup
		NVIC_DisableIRQ(UART3_IRQn);
		/* Enable UART3 clock */
		SYSCON->SYSAPB1CLKCTRL.bit.UART3CLK=1;	//enable UART3 PCLK
		//reset UART3
		SYSCON->APB1RESET.bit.UART3RSTN=1;
		SYSCON->APB1RESET.bit.UART3RSTN=0;
	}else return ;
	
	  //set up baudrate
  USARTx->BAUDDIV.bit.BAUDDIV = MainClock/USART_InitStruct->USART_BaudRate; /*Config the USART communication baud rate*/	
	
	//Set_Parity
	if (USART_InitStruct->USART_Parity==USART_Parity_Odd)     //Odd_Parity
	 {
		 USARTx->CTRL.bit.PARIEN  = 1;
		 USARTx->CTRL.bit.PARISEL = 1;
	 }
	else if (USART_InitStruct->USART_Parity==USART_Parity_Even)//Even_Parity
	 {
		 USARTx->CTRL.bit.PARIEN  =  1;
		 USARTx->CTRL.bit.PARISEL =  0;
	 }
	else if (USART_InitStruct->USART_Parity!=USART_Parity_No)  //No_Parity
		 USARTx->CTRL.bit.PARIEN  =  0;
	
	
	//enable rx,tx function	
	  if((USART_InitStruct->USART_Mode & USART_Mode_Rx) == USART_Mode_Rx)
		USARTx->CTRL.bit.RXEN=1;
		if((USART_InitStruct->USART_Mode & USART_Mode_Tx) == USART_Mode_Tx)
    USARTx->CTRL.bit.TXEN=1; 

	//clr FIFO
	  USARTx->FIFOCLR.all=0xFF;
	
	
}


/**
  * @brief  Enables or disables the specified USART peripheral.
  * @param  USARTx: Select the USART or the UART peripheral. 
  *         This parameter can be one of the following values:
  *           USART1, USART2, USART3, UART4 or UART5.
  * @param  NewState: new state of the USARTx peripheral.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void USART_Cmd(USART_TypeDef* USARTx, FunctionalState NewState)
{
  
  if (NewState != DISABLE)
  {
		USARTx->CTRL.bit.RXEN=1;
    USARTx->CTRL.bit.TXEN=1; 
  }
  else
  {
    USARTx->CTRL.bit.RXEN=0;
    USARTx->CTRL.bit.TXEN=0; 
  }
}



/**
  * @brief  Transmits single data through the USARTx peripheral.
  * @param  USARTx: Select the USART or the UART peripheral. 
  *   This parameter can be one of the following values:
  *   USART1, USART2, USART3, UART4 or UART5.
  * @param  Data: the data to transmit.
  * @retval None
  */
void USART_SendData(USART_TypeDef* USARTx, uint16_t Data)
{
  /* Transmit Data */
	  while (USARTx->STAT.bit.TXF);  //Waiting to send FIFO is not full.
    USARTx->DAT.bit.DATA = (Data & (uint16_t)0x01FF); //Send Data
}

/**
  * @brief  Returns the most recent received data by the USARTx peripheral.
  * @param  USARTx: Select the USART or the UART peripheral. 
  *   This parameter can be one of the following values:
  *   USART1, USART2, USART3, UART4 or UART5.
  * @retval The received data.
  */
uint16_t USART_ReceiveData(USART_TypeDef* USARTx)
{  
  /* Receive Data */
	  if (USARTx->STAT.bit.RXNE)
		{
	    return (uint16_t)(USARTx->DAT.bit.DATA& (uint16_t)0x01FF) ;
		}
    else 
			 return 0 ;
}


/**
  * @brief  Checks whether the specified USART interrupt has occurred or not.
  * @param  USARTx: Select the USART or the UART peripheral. 
  *   This parameter can be one of the following values:
  *   USART1, USART2, USART3
  */
ITStatus USART_GetITStatus(USART_TypeDef* USARTx, uint16_t USART_IT)
{
  ITStatus bitstatus = RESET;
	if((USARTx->INTSTATUS.all& USART_IT)  == USART_IT)
	  bitstatus = SET;
	else
		bitstatus = RESET; 
  
  return		bitstatus;  
}


/**
  * @brief  Clears the USARTx's interrupt pending bits.
  * @param  USARTx: Select the USART or the UART peripheral. 
  *   This parameter can be one of the following values:
  *   USART1, USART2, USART3
  * @retval None
  */
void USART_ClearITPendingBit(USART_TypeDef* USARTx, uint16_t USART_IT)
{
  USARTx->INTSTATUS.all=(USARTx->INTSTATUS.all| USART_IT); 
}



/**
  * @brief  Enables or disables the specified USART interrupts.
  * @param  USARTx: Select the USART or the UART peripheral. 
  *   This parameter can be one of the following values:
  *   USART1, USART2, USART3
  */
void USART_ITConfig(USART_TypeDef* USARTx, uint16_t USART_IT, FunctionalState NewState)
{
	if(NewState==ENABLE)
	{
		 if(USART_IT == USART_IT_RXNE)
		  USARTx->CTRL.bit.RXNEIE   =   1 ;
	}
	else
	{
			if(USART_IT == USART_IT_RXNE)
		  USARTx->CTRL.bit.RXNEIE   =   0 ;
	}
  
}

/**
  * @brief  Checks whether the specified USART flag is set or not.
  * @param  USARTx: Select the USART or the UART peripheral. 
  *   This parameter can be one of the following values:
  *   USART1, USART2, USART3
  * @retval The new state of USART_FLAG (SET or RESET).
  */
FlagStatus USART_GetFlagStatus(USART_TypeDef* USARTx, uint16_t USART_FLAG)
{
  FlagStatus bitstatus = RESET;
	
	if((USARTx->STAT.all& USART_FLAG)  == USART_FLAG)
	  bitstatus = SET;
	else
		bitstatus = RESET; 
  
  return		bitstatus;  
}
/******************************************************************************
**                            End Of File
******************************************************************************/
