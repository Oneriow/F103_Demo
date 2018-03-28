/*******************************************************************************
*	Application: Demo code for GPIO using in G32F1xx
*	Edition:		Version:1.0
*	Company: 		GORGETEK
*	Time: 			September 2015
*******************************************************************************/
#include "g32f1xx.h"
#include "gt_sys.h"
#include "gt_gpio.h"
#include "gt_uart.h"

#define CHECK_MODE       //查询方式
void dly1us(int dlytime);
void UART1_IOCFG(void);
void UART2_IOCFG(void);
void UART3_IOCFG(void);


uint8_t  SendData[10]     =    {0xaa,0xbb,0xcc,0x11,0xbb};
uint8_t  ReceiveData[100] =    {0};
uint16_t SendDataLeng     =    10 ;
uint16_t ReceiveDataLeng  =     0 ;
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
	uint16_t i = 0;
	USART_InitTypeDef USART_InitStructure;
	/* --------- System initialization ------------------*/
	SystemInit();	
  UART1_IOCFG(); // 串口1的GPIO配置
	USART_InitStructure.USART_BaudRate = 115200; 
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No ;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART1, &USART_InitStructure);
  USART_Cmd(USART1, ENABLE);
	
  #ifndef CHECK_MODE  //中断模式配置
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	NVIC_EnableIRQ(UART1_IRQn); 
	#endif 
	
	
	for(i = 0 ; i <SendDataLeng ; i++)  
	USART_SendData(USART1,SendData[i]);//Send data 
	
  while(1)
	{		
		#ifdef CHECK_MODE //查询模式接收
	   if(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) != RESET)
		 { 
				ReceiveData[ReceiveDataLeng ++] = (uint8_t) USART_ReceiveData(USART1);
				if(ReceiveDataLeng>99)ReceiveDataLeng = 0;			 
		 }
		#endif 
	}
							
}

#ifndef CHECK_MODE //中断模式接收
void UART1_IRQHandler(void)
{	
	 if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
	 {
      USART_ClearITPendingBit(USART1, USART_IT_RXNE);	//clean interrupt 
		  ReceiveData[ReceiveDataLeng ++] = (uint8_t) USART_ReceiveData(USART1);
		  if(ReceiveDataLeng>99)ReceiveDataLeng = 0;
		}
}
#endif 


void UART1_IOCFG(void)
{
	/* you can config UART1 RX from PB7,
	and you can config UART1 TX to PB6 --------------------------------*/
//	IOCON->PB6.bit.FUNC  = UART1_TX_to_PB6;
//	IOCON->PB6.bit.PUE   = 1;
//	IOCON->PB7.bit.FUNC  = UART1_RX_from_PB7;
//	IOCON->PB7.bit.PUE   = 1;	
	IOCON->PA9.bit.FUNC  = UART1_TX_to_PA9;
	IOCON->PA9.bit.PUE   = 1;
	IOCON->PA10.bit.FUNC  = UART1_RX_from_PA10;
	IOCON->PA10.bit.PUE   = 1;	
}

void UART2_IOCFG(void)
{
	/* you can config UART2 RX from PA3 or PD6,
	and you can config UART2 TX to PA2 or PD5 --------------------------------*/
	#if 1
	IOCON->PA2.bit.FUNC  = UART2_TX_to_PA2;
	IOCON->PA2.bit.PUE   = 1;
	IOCON->PA3.bit.FUNC  = UART2_RX_from_PA3;
	IOCON->PA3.bit.PUE   = 1;	
  #else
	IOCON->PD5.bit.FUNC  = UART2_TX_to_PD5;
	IOCON->PD5.bit.PUE   = 1;
	IOCON->PD6.bit.FUNC  = UART2_RX_from_PD6;
	IOCON->PD6.bit.PUE   = 1;	
	#endif
}

void UART3_IOCFG(void)
{
	/* you can config UART3 RX from PB11 or PD9,
	and you can config UART3 TX to PB10 or PD8 --------------------------------*/
	#if 1
	IOCON->PB10.bit.FUNC = UART3_TX_to_PB10;
	IOCON->PB10.bit.PUE  = 1;
	IOCON->PB11.bit.FUNC = UART3_RX_from_PB11;
	IOCON->PB11.bit.PUE  = 1;	
  #else
	IOCON->PD8.bit.FUNC  = UART3_TX_to_PD8;
	IOCON->PD8.bit.PUE   = 1;
	IOCON->PD9.bit.FUNC  = UART3_RX_from_PD9;
	IOCON->PD9.bit.PUE   = 1;	
	#endif
}




