/*****************************************************************************
 *   gt_spi.h:  Header file for Gorgetek G32F1xx Family Microprocessors
 *
 *   Copyright(C) 2015, GORGE tech. Ltd.
 *   All rights reserved.
 *
 *   History
 *   2015  ver 1.00    Prelimnary version, first Release
 *
******************************************************************************/
#ifndef __SPI_H 
#define __SPI_H

#include "g32f1xx.h"

//--SPI Registers BITS Field---------------------------------------------------------------------------------------
struct SPI_CR0_BITS	{
			uint32_t DSS:4;			//Data Size Select. 
			uint32_t FRF:2;			//Frame Format
			uint32_t CPOL:1;		//Clock Out Polarity. This bit is only used in SPI mode. 
			uint32_t CPHA:1;			//Clock Out Phase. This bit is only used in SPI mode. 
			uint32_t RSVD:24;	// 
};
union SPI_CR0_REG {
				uint32_t				all;
				struct  SPI_CR0_BITS		bit;
};
struct SPI_CR1_BITS	{
			uint32_t LBM:1;			//Loop Back Mode. 
			uint32_t SSE:1;			//SPI Enable. 
			uint32_t MS:1;			//Master/Slave Mode. 
			uint32_t SOD:1;			//Slave Output Disable. T
			uint32_t CSFL:1;			//SSEL control
			uint32_t RSFR:1;			//Clear receive FIFO
			uint32_t FILTEN:1;			//Enable SPI data line filter
			uint32_t RSVD:25;	// 
};
union SPI_CR1_REG {
				uint32_t				all;
				struct  SPI_CR1_BITS		bit;
};
struct SPI_DR_BITS	{
			uint32_t DATA:16;			//SPI Data Register 
			uint32_t RSVD:16;	// 
};
union SPI_DR_REG {
				uint32_t				all;
				struct  SPI_DR_BITS		bit;
};
struct SPI_SR_BITS	{
			uint32_t TFE:1;			//Transmit FIFO Empty. This bit is 1 is the Transmit FIFO is empty, 0 if not. 
			uint32_t TNF:1;			//Transmit FIFO Not Full. This bit is 0 if the Tx FIFO is full, 1 if not.
			uint32_t RNE:1;			//Receive FIFO Not Empty. This bit is 0 if Receive FIFO is empty, 1 if not. 
			uint32_t RFF:1;			//Receive FIFO Full. This bit is 1 if Receive FIFO is full, 0 if not. 
			uint32_t BSY:1;			//Busy. This bit is 0 if the SPI controller is idle, or 1 if it is currently sending/receiving a frame and/or the Tx FIFO is not empty. 
			uint32_t RSVD:27;	// 
};
union SPI_SR_REG {
				uint32_t				all;
				struct  SPI_SR_BITS		bit;
};
struct SPI_CPSR_BITS	{
			uint32_t CPSDVSR:8;			//SPI Clock Prescale Register 
			uint32_t RSVD:24;	// 
};
union SPI_CPSR_REG {
				uint32_t				all;
				struct  SPI_CPSR_BITS		bit;
};
struct SPI_IMSC_BITS	{
			uint32_t RORIM:1;			//Software should set this bit to enable interrupt when a Receive Overrun occurs, that is, when the Rx FIFO is full and another frame is completely received. The ARM spec implies that the preceding frame data is overwritten by the new frame data when this occurs.
			uint32_t RTIM:1;			//Software should set this bit to enable interrupt when a Receive Time-out condition occurs. A Receive Time-out occurs when the Rx FIFO is not empty, and no has not been read for a “time-out period”. The time-out period is the same for master and slave modes and is determined by the SPI bit rate: 32 bits at PCLK / (CPSDVSR [SCR+1]).
			uint32_t RXIM:1;			//Software should set this bit to enable interrupt when the Rx FIFO is at least half full. 
			uint32_t TXIM:1;			//Software should set this bit to enable interrupt when the Tx FIFO is at least half empty. 
			uint32_t RSVD:28;	// 
};
union SPI_IMSC_REG {
				uint32_t				all;
				struct  SPI_IMSC_BITS		bit;
};
struct SPI_RIS_BITS	{
			uint32_t RORRIS:1;			//This bit is 1 if another frame was completely received while the Rx FIFO was full. The ARM spec implies that the preceding frame data is overwritten by the new frame data when this occurs. 
			uint32_t RTRIS:1;			//This bit is 1 if the Rx FIFO is not empty, and has not been read for a “time-out period”. The time-out period is the same for master and slave modes and is determined by the SPI bit rate: 32 bits at PCLK / (CPSDVSR × [SCR+1]). 
			uint32_t RXRIS:1;			//This bit is 1 if the Rx FIFO is at least half full. 
			uint32_t TXRIS:1;			//This bit is 1 if the Tx FIFO is at least half empty. 
			uint32_t RSVD:28;	// 
};
union SPI_RIS_REG {
				uint32_t				all;
				struct  SPI_RIS_BITS		bit;
};
struct SPI_MIS_BITS	{
			uint32_t RORMIS:1;			//This bit is 1 if another frame was completely received while the RxFIFO was full, and this interrupt is enabled. 
			uint32_t RTMIS:1;			//This bit is 1 if the Rx FIFO is not empty, has not been read for a “time-out period”, and this interrupt is enabled. The time-out period is the same for master and slave modes and is determined by the SPI bit rate: 32 bits at PCLK / (CPSDVSR × [SCR+1]). 
			uint32_t RXMIS:1;			//This bit is 1 if the Rx FIFO is at least half full, and this interrupt is enabled. 
			uint32_t TXMIS:1;			//This bit is 1 if the Tx FIFO is at least half empty, and this interrupt is enabled. 
			uint32_t RSVD:28;	// 
};
union SPI_MIS_REG {
				uint32_t				all;
				struct  SPI_MIS_BITS		bit;
};
struct SPI_ICR_BITS	{
			uint32_t RORIC:1;			//Writing a 1 to this bit clears the “frame was received when Rx FIFO was full” interrupt. 
			uint32_t RTIC:1;			//Writing a 1 to this bit clears the “Rx FIFO was not empty and has not been read for a time-out period” interrupt. 
			uint32_t RSVD:30;	// 
};
union SPI_ICR_REG {
				uint32_t				all;
				struct  SPI_ICR_BITS		bit;
};

/* ================================================================================ */
/* ================                       SPI                      ================ */
/* ================================================================================ */


/**
  * @brief Serial peripheral interface (SPI)
  */

typedef struct {                                    /*!< SPI Structure                                                         */
  __IO union SPI_CR0_REG  CR0;                               /*!< SPI control register0                                                 */
  __IO union SPI_CR1_REG  CR1;                               /*!< SPI control register1                                                 */
  __IO union SPI_DR_REG  DR;                                /*!< SPI data register                                                     */
  __I  union SPI_SR_REG  SR;                                /*!< SPI status register                                                   */
  __IO union SPI_CPSR_REG  CPSR;                              /*!< SPI Clock Prescale Register                                           */
  __IO union SPI_IMSC_REG  IMSC;                              /*!< Interrupt Mask Set and Clear Register                                 */
  __I  union SPI_RIS_REG  RIS;                               /*!< Raw Interrupt Status Register                                         */
  __I  union SPI_MIS_REG  MIS;                               /*!< Masked Interrupt Status Register                                      */
  __O  union SPI_ICR_REG  ICR;                               /*!< SPI Interrupt Clear Register                                          */
} G32F1_SPI_TypeDef;

//#define SPI1                             ((G32F1_SPI_TypeDef                *) GT_SPI1_BASE)
//#define SPI2                             ((G32F1_SPI_TypeDef                *) GT_SPI2_BASE)
//#define SPI3                             ((G32F1_SPI_TypeDef                *) GT_SPI3_BASE)


#define SPI_FRAME	0
#define SSI_FRAME	1

#define SPI_RX_FIFO_FULL	1
#define SPI_RX_FIFO_NOT_EMPTY	2
#define SPI_RX_FIFO_HALF_FULL	4
#define SPI_TX_FIFO_HALF_EMPTY	8

#define SPI_MODE0	0
#define SPI_MODE1	1
#define SPI_MODE2	2
#define SPI_MODE3	3
#define SPI_MASTER	0
#define SPI_SLAVE	1


// #define SPI_Set_SSEL_High (SPI->CR1.bit.CSFL = 1)
// #define SPI_Reset_SSEL_Low (SPI->CR1.bit.CSFL = 0)
// #define SPI_Write_FIFO(data) (SPI->DR.bit.DATA=data)
// #define SPI_TX_FIFO_Not_Empty ((SPI->SR.all&0x11)!=1)
// #define SPI_Read_FIFO(data) (data=SPI->DR.bit.DATA)
//#define SPI_CLR_FIFO (SPI->CR1.bit.RSFR =1; SPI->CR1.bit.RSFR =0)

void SPI_Open(G32F1_SPI_TypeDef *SPI,uint8_t framemode, uint8_t bitwidth, uint8_t master, uint8_t spionlymode);
void SPI_Close(G32F1_SPI_TypeDef *SPI);
void SPI_SetClk(G32F1_SPI_TypeDef *SPI,uint32_t freq);
void SPI_ClearFIFO(G32F1_SPI_TypeDef *SPI);
void SPI_SingleWriteRead(G32F1_SPI_TypeDef *SPI,uint16_t *data);
void SPI_WritetoFIFO (G32F1_SPI_TypeDef *SPI,uint16_t *src, uint8_t *noofdata);
void SPI_ReadFIFOData (G32F1_SPI_TypeDef *SPI,uint16_t *dst, uint8_t *noofdata);
void SPI_ClrInt(G32F1_SPI_TypeDef *SPI);
void SPI_EnableInt(G32F1_SPI_TypeDef *SPI,uint8_t inttype);


void SPI_Set_SSEL_High(G32F1_SPI_TypeDef *SPI);
void SPI_Reset_SSEL_Low(G32F1_SPI_TypeDef *SPI);
void SPI_Write_FIFO(G32F1_SPI_TypeDef *SPI,uint32_t data);
int SPI_TX_FIFO_Not_Empty(G32F1_SPI_TypeDef *SPI);
int SPI_Read_FIFO(G32F1_SPI_TypeDef *SPI);
void POLL_RXFIFO_NOTEMPTY(G32F1_SPI_TypeDef *SPI);


#define	SPI1_SSEL_PA4  (GT_AFIO->PA4 = 0x2)
#define	SPI1_SCK_PA5	 (GT_AFIO->PA5 = 0x2)	
#define	SPI1_MISO_PA6	 (GT_AFIO->PA6 = 0x2)
#define	SPI1_MOSI_PA7	 (GT_AFIO->PA7 = 0x2)	

#define	SPI1_SSEL_PA15 (GT_AFIO->JTDI_PA15  = 0x2)
#define	SPI1_SCK_PB3	 (GT_AFIO->JTDO_PB3   = 0x5)	
#define	SPI1_MISO_PB4	 (GT_AFIO->JNRST_PB4  = 0x5)
#define	SPI1_MOSI_PB5	 (GT_AFIO->PB5        = 0x5)	

#define	SPI2_SSEL_PB12 (GT_AFIO->PB12 = 0x5)
#define	SPI2_SCK_PB13  (GT_AFIO->PB13 = 0x5)	
#define	SPI2_MISO_PB14 (GT_AFIO->PB14 = 0x5)
#define	SPI2_MOSI_PB15 (GT_AFIO->PB15 = 0x5)	

//#define	SPI3_SSEL_PA15 (GT_AFIO->JTDI_PA15  = 0x1)
//#define	SPI3_SCK_PB3	 (GT_AFIO->JTDO_PB3   = 0x1)	
//#define	SPI3_MISO_PB4	 (GT_AFIO->JNRST_PB4  = 0x1)
//#define	SPI3_MOSI_PB5	 (GT_AFIO->PB5        = 0x1)	



////////////////////////////////ST///////////////////////////////////////////

#define SPI1                             ((SPI_TypeDef                *) GT_SPI1_BASE)
#define SPI2                             ((SPI_TypeDef                *) GT_SPI2_BASE)
#define SPI3                             ((SPI_TypeDef                *) GT_SPI3_BASE)

#define SPI_Mode_Master                 ((uint16_t)0x0104)
#define SPI_Mode_Slave                  ((uint16_t)0x0000)


#define SPI_Direction_2Lines_FullDuplex ((uint16_t)0x0000)
#define SPI_Direction_2Lines_RxOnly     ((uint16_t)0x0400)
#define SPI_Direction_1Line_Rx          ((uint16_t)0x8000)
#define SPI_Direction_1Line_Tx          ((uint16_t)0xC000)

#define SPI_NSS_Soft                    ((uint16_t)0x0200)
#define SPI_NSS_Hard                    ((uint16_t)0x0000)

#define SPI_FirstBit_MSB                ((uint16_t)0x0000)
#define SPI_FirstBit_LSB                ((uint16_t)0x0080)

#define SPI_DataSize_4b                 ((uint16_t)0x3)
#define SPI_DataSize_5b                 ((uint16_t)0x4)
#define SPI_DataSize_6b                 ((uint16_t)0x5)
#define SPI_DataSize_7b                 ((uint16_t)0x6)
#define SPI_DataSize_8b                 ((uint16_t)0x7)
#define SPI_DataSize_9b                 ((uint16_t)0x8)
#define SPI_DataSize_10b                ((uint16_t)0x9)
#define SPI_DataSize_11b                ((uint16_t)0xA)
#define SPI_DataSize_12b                ((uint16_t)0xB)
#define SPI_DataSize_13b                ((uint16_t)0xC)
#define SPI_DataSize_14b                ((uint16_t)0xD)
#define SPI_DataSize_15b                ((uint16_t)0xE)
#define SPI_DataSize_16b                ((uint16_t)0xF)


#define SPI_CPOL_Low                    0
#define SPI_CPOL_High                   1

#define SPI_CPHA_1Edge                  0
#define SPI_CPHA_2Edge                  1

#define SPI_BaudRatePrescaler_2         4
#define SPI_BaudRatePrescaler_4         8
#define SPI_BaudRatePrescaler_8         16
#define SPI_BaudRatePrescaler_16        32
#define SPI_BaudRatePrescaler_32        64
#define SPI_BaudRatePrescaler_64        128
#define SPI_BaudRatePrescaler_128       256
#define SPI_BaudRatePrescaler_256       512


//#define SPI_I2S_FLAG_RXNE               ((uint16_t)0x0001)
//#define SPI_I2S_FLAG_TXE                ((uint16_t)0x0002)
//#define I2S_FLAG_CHSIDE                 ((uint16_t)0x0004)
//#define I2S_FLAG_UDR                    ((uint16_t)0x0008)
//#define SPI_FLAG_CRCERR                 ((uint16_t)0x0010)
//#define SPI_FLAG_MODF                   ((uint16_t)0x0020)
//#define SPI_I2S_FLAG_OVR                ((uint16_t)0x0040)
//#define SPI_I2S_FLAG_BSY                ((uint16_t)0x0080)

#define SPI_I2S_FLAG_TFE                ((uint16_t)0x0001)
#define SPI_I2S_FLAG_TNF                ((uint16_t)0x0002)
#define SPI_I2S_FLAG_RNE                ((uint16_t)0x0004)
#define SPI_I2S_FLAG_RFF                ((uint16_t)0x0008)
#define SPI_I2S_FLAG_BSY                ((uint16_t)0x0010)


typedef struct
{
	
	__IO union SPI_CR0_REG  CR0;                               /*!< SPI control register0                                                 */
  __IO union SPI_CR1_REG  CR1;                               /*!< SPI control register1                                                 */
  __IO union SPI_DR_REG  DR;                                /*!< SPI data register                                                     */
  __I  union SPI_SR_REG  SR;                                /*!< SPI status register                                                   */
  __IO union SPI_CPSR_REG  CPSR;                              /*!< SPI Clock Prescale Register                                           */
  __IO union SPI_IMSC_REG  IMSC;                              /*!< Interrupt Mask Set and Clear Register                                 */
  __I  union SPI_RIS_REG  RIS;                               /*!< Raw Interrupt Status Register                                         */
  __I  union SPI_MIS_REG  MIS;                               /*!< Masked Interrupt Status Register                                      */
  __O  union SPI_ICR_REG  ICR;                               /*!< SPI Interrupt Clear Register                                          */

} SPI_TypeDef;

/** 
  * @brief  SPI Init structure definition  
  */

typedef struct
{
  uint16_t SPI_Direction;           /*!< Specifies the SPI unidirectional or bidirectional data mode.
                                         This parameter can be a value of @ref SPI_data_direction */

  uint16_t SPI_Mode;                /*!< Specifies the SPI operating mode.
                                         This parameter can be a value of @ref SPI_mode */

  uint16_t SPI_DataSize;            /*!< Specifies the SPI data size.
                                         This parameter can be a value of @ref SPI_data_size */

  uint16_t SPI_CPOL;                /*!< Specifies the serial clock steady state.
                                         This parameter can be a value of @ref SPI_Clock_Polarity */

  uint16_t SPI_CPHA;                /*!< Specifies the clock active edge for the bit capture.
                                         This parameter can be a value of @ref SPI_Clock_Phase */

  uint16_t SPI_NSS;                 /*!< Specifies whether the NSS signal is managed by
                                         hardware (NSS pin) or by software using the SSI bit.
                                         This parameter can be a value of @ref SPI_Slave_Select_management */
 
  uint16_t SPI_BaudRatePrescaler;   /*!< Specifies the Baud Rate prescaler value which will be
                                         used to configure the transmit and receive SCK clock.
                                         This parameter can be a value of @ref SPI_BaudRate_Prescaler.
                                         @note The communication clock is derived from the master
                                               clock. The slave clock does not need to be set. */

  uint16_t SPI_FirstBit;            /*!< Specifies whether data transfers start from MSB or LSB bit.
                                         This parameter can be a value of @ref SPI_MSB_LSB_transmission */

  uint16_t SPI_CRCPolynomial;       /*!< Specifies the polynomial used for the CRC calculation. */
}SPI_InitTypeDef;

void SPI_StructInit(SPI_InitTypeDef* SPI_InitStruct);
void SPI_Cmd(SPI_TypeDef* SPIx, FunctionalState NewState);
void SPI_Init(SPI_TypeDef* SPIx, SPI_InitTypeDef* SPI_InitStruct);
void SPI_I2S_SendData(SPI_TypeDef* SPIx, uint16_t Data);
uint16_t SPI_I2S_ReceiveData(SPI_TypeDef* SPIx);
FlagStatus SPI_I2S_GetFlagStatus(SPI_TypeDef* SPIx, uint16_t SPI_I2S_FLAG);
void SPI_StructInit(SPI_InitTypeDef* SPI_InitStruct);
void SPI_SSEL_LOW(SPI_TypeDef *SPI);
void SPI_SSEL_HIGH(SPI_TypeDef *SPI);
u8 SPI1_TransReceive(u8 senddata);
u8 SPI2_TransReceive(u8 senddata);

#endif /* end __SPI_H */
/*****************************************************************************
**                            End Of File
******************************************************************************/

