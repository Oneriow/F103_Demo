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
//#define __UART0

#ifndef __UART_H 
#define __UART_H
#include "g32f1xx.h"
//stauts and int bit
#define UART_NO_PARITY    0x0 
#define UART_EVEN_PARITY  0x1
#define UART_ODD_PARITY   0x2
#define UART_RX_NO_INT    0x0
#define UART_TX_EMPTY     0x1
#define UART_RX_NOT_EMPTY 0x2
#define UART_TX_FULL      0x4 
#define UART_RX_FULL      0x8
#define UART_TX_HALF_FULL 0x10 
#define UART_RX_HALF_FULL 0x20
#define UART_PARIERRINT   0x40 
#define UART_OVERRUNINT   0x80

//--UART Registers BITS Field---------------------------------------------------------------------------------------
struct UARTDAT_BITS	{
				uint32_t DATA:8;							// 7:0 UART receiver buffer register
				uint32_t RSVD:24;						  // 31:8 reserved
};
union UARTDAT_REG {
				uint32_t					all;
				struct  UARTDAT_BITS		bit;
};

struct UARTSTATE_BITS {
				uint32_t TXE:1; 		          //Transmit FIFO  empty flag
				uint32_t RXNE:1;		          //Receiver FIFO not empty flag
				uint32_t TXF:1; 		          //Transmit FIFO full flag
				uint32_t RXF:1;		            //Receiver FIFO full flag
				uint32_t TXHLF:1;		          //Transmit FIFO half full flag
				uint32_t RXHLF:1;		          //Receiver FIFO half full flag
				uint32_t PARIERR:1;		        //Receiver parity error flag
				uint32_t OVERRUN:1;		        //Receiver overrun error flag
				uint32_t RSVD3:24;						// 31:8 reserved
};
union UARTSTATE_REG {
				uint32_t					all;
				struct UARTSTATE_BITS		bit;
};

struct UARTCTRL_BITS {
				uint32_t TXEIE:1;		          //TX FIFO empty interrupt enable
				uint32_t RXNEIE:1;		        //RX FIFO not empty interrupt enable
				uint32_t TXFIE:1;		          //TX FIFO full interrupt enable
				uint32_t RXFIE:1;		          //RX FIFO full interrupt enable
				uint32_t TXHLFIE:1;		        //TX FIFO half full interrupt enable
				uint32_t RXHLFIE:1;		        //RX FIFO half full interrupt enable
				uint32_t PARIERRIE:1;		      //Parity error interrupt enable
				uint32_t OVERRUNIE:1;		      //Overrun interrupt enable
				uint32_t PARISEL:1;		        //Parity selection
				uint32_t PARIEN:1;		        //Enable parity
				uint32_t IRDEN:1;		          //Enable IrDN
				uint32_t RSVD0:11;		
				uint32_t RXEN:1;		          //Enable UART RX
				uint32_t TXEN:1;		          //Enable UART TX
				uint32_t RSVD1:8;
};
union UARTCTRL_REG {
				uint32_t					all;
				struct UARTCTRL_BITS		bit;
};

struct UARTINTSTATUS_BITS {
				uint32_t TXEINT:1;		//Interrupt status. The interrupt occurs when data transmit completed. 
				uint32_t RXNEINT:1;		//Interrupt status. The interrupt occurs when received data. 
				uint32_t TXFINT:1;		//Interrupt status. The interrupt occurs when TX FIFO is full. 
				uint32_t RXFINT:1;		//Interrupt status. The interrupt occurs when RX FIFO is full. 
				uint32_t TXHLFINT:1;	//Interrupt status. The interrupt occurs when TX FIFO is half full. 
				uint32_t RXHLFINT:1;	//Interrupt status. The interrupt occurs when RX FIFO is half full.
				uint32_t PARIERRINT:1;//Interrupt status. The interrupt occurs when RX parity check error is detected
				uint32_t OVERRUNINT:1;//Interrupt status. The interrupt occurs when RX overrun error is detected
				uint32_t RSVD:24;	
};
union UARTINTSTATUS_REG {
				uint32_t									all; 
				struct UARTINTSTATUS_BITS	bit;
};

struct UARTBAUDDIV_BITS {
				uint32_t  BAUDDIV:20;					// 19:0 baud-rate generation pre-scalar divisor value  0x10
				uint32_t  RSVD1:12;						// 31:20  reserved
};
union UARTBAUDDIV_REG {
				uint32_t									all; 
				struct  UARTBAUDDIV_BITS	bit;
};

struct UARTFIFOCLR_BITS {
				uint32_t  TXFIFOCLR:1;			  // Write 1 to clear TX FIFO
				uint32_t  RXFIFOCLR:1;				// Write 1 to clear RX FIFO
				uint32_t  RSVD:30;						// 31:20  reserved
};
union UARTFIFOCLR_REG {
				uint32_t					all; 
				struct  UARTFIFOCLR_BITS	bit;
};

typedef struct
{
	__IO   union UARTDAT_REG				DAT;				/*!< Offset: 0x000 Data Register    (R/W) 				 */
	__IO   union UARTSTATE_REG			STAT;				/*!< Offset: 0x004 Status Register  (R/W) 				 */
	__IO   union UARTCTRL_REG				CTRL;				/*!< Offset: 0x008 Control Register (R/W) 				 */
	__IO   union UARTINTSTATUS_REG	INTSTATUS;	/*!< Offset: 0x00C Interrupt Status Register (R/W )*/
	__IO   union UARTBAUDDIV_REG		BAUDDIV;		/*!< Offset: 0x010 Baudrate Divider Register (R/W) */
	__IO   union UARTFIFOCLR_REG		FIFOCLR;		/*!< Offset: 0x014 Clear TX and RX FIFO 					 */
} G32F1_UART_TypeDef;


typedef struct
{
  uint32_t USART_BaudRate;            /*!< This member configures the USART communication baud rate.
                                           The baud rate is computed using the following formula:
                                            - IntegerDivider = ((PCLKx) / (16 * (USART_InitStruct->USART_BaudRate)))
                                            - FractionalDivider = ((IntegerDivider - ((u32) IntegerDivider)) * 16) + 0.5 */

  uint16_t USART_WordLength;          /*!< Specifies the number of data bits transmitted or received in a frame.
                                           This parameter can be a value of @ref USART_Word_Length */

  uint16_t USART_StopBits;            /*!< Specifies the number of stop bits transmitted.
                                           This parameter can be a value of @ref USART_Stop_Bits */

  uint16_t USART_Parity;              /*!< Specifies the parity mode.
                                           This parameter can be a value of @ref USART_Parity
                                           @note When parity is enabled, the computed parity is inserted
                                                 at the MSB position of the transmitted data (9th bit when
                                                 the word length is set to 9 data bits; 8th bit when the
                                                 word length is set to 8 data bits). */ 
  uint16_t USART_Mode;                /*!< Specifies wether the Receive or Transmit mode is enabled or disabled.
                                           This parameter can be a value of @ref USART_Mode */

  uint16_t USART_HardwareFlowControl; /*!< Specifies wether the hardware flow control mode is enabled
                                           or disabled.
                                           This parameter can be a value of @ref USART_Hardware_Flow_Control */
} USART_InitTypeDef;

typedef struct
{
	__IO   union UARTDAT_REG				DAT;				/*!< Offset: 0x000 Data Register    (R/W) 				 */
	__IO   union UARTSTATE_REG			STAT;				/*!< Offset: 0x004 Status Register  (R/W) 				 */
	__IO   union UARTCTRL_REG				CTRL;				/*!< Offset: 0x008 Control Register (R/W) 				 */
	__IO   union UARTINTSTATUS_REG	INTSTATUS;	/*!< Offset: 0x00C Interrupt Status Register (R/W )*/
	__IO   union UARTBAUDDIV_REG		BAUDDIV;		/*!< Offset: 0x010 Baudrate Divider Register (R/W) */
	__IO   union UARTFIFOCLR_REG		FIFOCLR;		/*!< Offset: 0x014 Clear TX and RX FIFO 					 */
} USART_TypeDef;

#define USART1       ((USART_TypeDef     *) GT_UART1_BASE)
#define USART2       ((USART_TypeDef     *) GT_UART2_BASE)
#define USART3       ((USART_TypeDef     *) GT_UART3_BASE)


#define USART_Parity_No                      ((uint16_t)0x0000)
#define USART_Parity_Even                    ((uint16_t)0x0400)
#define USART_Parity_Odd                     ((uint16_t)0x0600) 

#define USART_WordLength_8b                  ((uint16_t)0x0000)
#define USART_WordLength_9b                  ((uint16_t)0x1000)


/** @defgroup USART_Stop_Bits 
  * @{
  */ 
  
#define USART_StopBits_1                     ((uint16_t)0x0000)
#define USART_StopBits_0_5                   ((uint16_t)0x1000)
#define USART_StopBits_2                     ((uint16_t)0x2000)
#define USART_StopBits_1_5                   ((uint16_t)0x3000)

/** @defgroup USART_Hardware_Flow_Control 
  * @{
  */ 
#define USART_HardwareFlowControl_None       ((uint16_t)0x0000)
#define USART_HardwareFlowControl_RTS        ((uint16_t)0x0100)
#define USART_HardwareFlowControl_CTS        ((uint16_t)0x0200)
#define USART_HardwareFlowControl_RTS_CTS    ((uint16_t)0x0300)


/** @defgroup USART_Interrupt_definition 
  * @{
  */

#define USART_IT_RXNE                        ((uint16_t)0x0002)
#define USART_IT_PE                          ((uint16_t)0x0028)
#define USART_IT_TXE                         ((uint16_t)0x0727)
#define USART_IT_TC                          ((uint16_t)0x0626)
#define USART_IT_IDLE                        ((uint16_t)0x0424)
#define USART_IT_LBD                         ((uint16_t)0x0846)
#define USART_IT_CTS                         ((uint16_t)0x096A)
#define USART_IT_ERR                         ((uint16_t)0x0060)
#define USART_IT_ORE                         ((uint16_t)0x0360)
#define USART_IT_NE                          ((uint16_t)0x0260)
#define USART_IT_FE                          ((uint16_t)0x0160)


/** @defgroup USART_Flags 
  * @{
  */
#define USART_FLAG_RXNE                      ((uint16_t)0x0002)
#define USART_FLAG_CTS                       ((uint16_t)0x0200)
#define USART_FLAG_LBD                       ((uint16_t)0x0100)
#define USART_FLAG_TXE                       ((uint16_t)0x0080)
#define USART_FLAG_TC                        ((uint16_t)0x0040)
#define USART_FLAG_IDLE                      ((uint16_t)0x0010)
#define USART_FLAG_ORE                       ((uint16_t)0x0008)
#define USART_FLAG_NE                        ((uint16_t)0x0004)
#define USART_FLAG_FE                        ((uint16_t)0x0002)
#define USART_FLAG_PE                        ((uint16_t)0x0001)

#define USART_Mode_Rx                        ((uint16_t)0x0004)
#define USART_Mode_Tx                        ((uint16_t)0x0008)
/////////////////////////按照ST的库来改///////////////////////////////// 

#define UART1       ((G32F1_UART_TypeDef     *) GT_UART1_BASE)
#define UART2       ((G32F1_UART_TypeDef     *) GT_UART2_BASE)
#define UART3       ((G32F1_UART_TypeDef     *) GT_UART3_BASE)


#define UART1_TX_to_PB6 	 0x1;
#define UART1_RX_from_PB7  0x1;
#define UART1_TX_to_PA9 	 0x1;
#define UART1_RX_from_PA10 0x1;

#define UART2_TX_to_PA2 	 0x1;
#define UART2_RX_from_PA3  0x1;
#define UART2_TX_to_PD5 	 0x1;
#define UART2_RX_from_PD6  0x1;

#define UART3_TX_to_PB10	 0x1;
#define UART3_RX_from_PB11 0x1;
#define UART3_TX_to_PD8 	 0x1;
#define UART3_RX_from_PD9  0x1;
#define UART3_TX_to_PC10	 0x6;
#define UART3_RX_from_PC11 0x6;




void USART_Init(USART_TypeDef* USARTx, USART_InitTypeDef* USART_InitStruct);
void USART_StructInit(USART_InitTypeDef* USART_InitStruct);
void USART_Cmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_SendData(USART_TypeDef* USARTx, uint16_t Data);
ITStatus USART_GetITStatus(USART_TypeDef* USARTx, uint16_t USART_IT);
void USART_ClearITPendingBit(USART_TypeDef* USARTx, uint16_t USART_IT);
uint16_t USART_ReceiveData(USART_TypeDef* USARTx);
void USART_ITConfig(USART_TypeDef* USARTx, uint16_t USART_IT, FunctionalState NewState);
FlagStatus USART_GetFlagStatus(USART_TypeDef* USARTx, uint16_t USART_FLAG);

#endif /* end __UART_H */
/*****************************************************************************
**                            End Of File
******************************************************************************/
