/*   Copyright(C) 2015, Gorge Technology
 *   All rights reserved.
 *
 *   History
 *   2015.07  ver 1.01    Prelimnary version
 *
******************************************************************************/
/*----------- This driver is for general SPI usage ----------------*/
/* Includes ------------------------------------------------------------------*/
#include "g32f1xx.h"
#include "gt_sys.h"
#include "gt_spi.h"

extern uint32_t SystemCoreClock;
/*****************************************************************************
Function Name	SPI_Open
Function Definition	void SPI_Open(uint8_t framemode, uint8_t bitwidth, uint8_t master)
Function Description	Initial SPI infterface 
Input Parameters	Framemode: SPI_FRAME/SSI_FRAME, current support SPI_FRAME only
Bitwidth: data size, from 4-bit to 16-bit
Master: selection of master or slave, SPI_MASTER/SPI_SLAVE
spionlymode: SPI_MODE0~SPI_MODE3
Return Value	No
Condition	No
Function called	-


Last Chang Date: 2015/09/12			
*****************************************************************************/

# if 0

void SPI_Open(G32F1_SPI_TypeDef *SPI,uint8_t framemode, uint8_t bitwidth, uint8_t master, uint8_t spionlymode)
{
	//enable SPI clock
	if(SPI==SPI1)
		SYSCON->SYSAPB2CLKCTRL.bit.SPI1CLK=1;
	else if(SPI==SPI2)
		SYSCON->SYSAPB1CLKCTRL.bit.SPI2CLK=1;
	else if(SPI==SPI3)
		SYSCON->SYSAPB1CLKCTRL.bit.SPI3CLK=1;
	
	//set spi frame SPI/SSI selcetion
	SPI->CR0.bit.FRF=framemode;
	//select bit width
	SPI->CR0.bit.DSS=bitwidth;
	//Set master/slave
	if (master==SPI_MASTER)
		SPI->CR1.bit.MS=0;
	else
		SPI->CR1.bit.MS=1;
	//set SPI mode
	SPI->CR0.bit.CPOL=spionlymode;
	SPI->CR0.bit.CPHA=spionlymode>>1;
	//enable SPIcontroller
	SPI->CR1.bit.SSE=1;
	
	return;
}
/*****************************************************************************
Function Name	SPI_Close
Function Definition	void SPI_Close(void)
Function Description	De-Initial SPI interface 
Input Parameters	No
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			
*****************************************************************************/
void SPI_Close(G32F1_SPI_TypeDef *SPI)
{
	//Disable SPI clock
	if(SPI==SPI1)
		SYSCON->SYSAPB2CLKCTRL.bit.SPI1CLK=0;
	else if(SPI==SPI2)
		SYSCON->SYSAPB1CLKCTRL.bit.SPI2CLK=0;
	else if(SPI==SPI3)
		SYSCON->SYSAPB1CLKCTRL.bit.SPI3CLK=0;
	return;
}
/*****************************************************************************
Function Name	SPI_SetClk
Function Definition	void SPI_SetClk(uint32_t freq)
Function Description	Setup SPI clock. In Master mode, SPI frequency set no more than system clock divide by 7; 
												in Slave mode, the frequency set no more than system clock divide by 12.
Input Parameters	No
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			
*****************************************************************************/
void SPI_SetClk(G32F1_SPI_TypeDef *SPI,uint32_t freq)
{
	uint32_t div;
	
	div=SystemCoreClock/freq;
	
	if (SPI->CR1.bit.MS)
	{
		//slave mode
		if (div<12)
			div=12;
	}else
	{
		//master mode
		if (div<7)
			div=7;
		
	}
	//set up divider
	SPI->CPSR.bit.CPSDVSR=div;
	return;
}
/*****************************************************************************
Function Name	SPI_ClearFIFO
Function Definition	void SPI_ClearFIFO(void)
Function Description	Clear SPI TX and RX FIFO.
Input Parameters	No
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			
*****************************************************************************/
void SPI_ClearFIFO(G32F1_SPI_TypeDef *SPI)
{
	//wait untile TX FIFO empty
	while(!SPI->SR.bit.TFE);
	//clear RX FIFO
	SPI->ICR.bit.RTIC=1;
	SPI->ICR.bit.RTIC=0;
	return;
}
/*****************************************************************************
Function Name	SPI_SingleWriteRead
Function Definition	void SPI_SingleWriteRead(uint16_t *data)
Function Description	Write data to external SPI device and same time read same size data back from SPI device.
Input Parameters	No
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			
*****************************************************************************/
void SPI_SingleWriteRead(G32F1_SPI_TypeDef *SPI,uint16_t *data)
{
	//wait untile TX FIFO empty
	while(!SPI->SR.bit.TFE);
	//clear RX FIFO
	SPI->ICR.bit.RTIC=1;
	SPI->ICR.bit.RTIC=0;
	//Write data to FIFO
	SPI->DR.bit.DATA=*data;
	//wait untile TX FIFO empty
	while(!SPI->SR.bit.TFE);
	//Read data from FIFO	
	*data=SPI->DR.bit.DATA;
	return;
}
/*****************************************************************************
Function Name	SPI_WritetoFIFO
Function Definition	void SPI_WritetoFIFO (uint16_t *src, uint8_t *noofdata)
Function Description	Write data to SPI FIFO, if FIFO full, stop with rest number of data and current data pointer
Input Parameters	*src: pointer to data
*noofdata: number of data to send
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			
*****************************************************************************/
void SPI_WritetoFIFO (G32F1_SPI_TypeDef *SPI,uint16_t *src, uint8_t *noofdata)
{
	while((SPI->SR.bit.TNF)&&(*noofdata!=0))
	{
		//Write data to FIFO
		SPI->DR.bit.DATA=*src;	
		(*noofdata)--;
	}
	return;
}
/*****************************************************************************
Function Name	SPI_ReadFIFOData
Function Definition	void SPI_ReadFIFOData (uint16_t *dst, uint8_t *noofdata)
Function Description	Read data from SPI FIFO.
Input Parameters	*dst: pointer to destination
*noofdata: number of data read
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			
*****************************************************************************/
void SPI_ReadFIFOData (G32F1_SPI_TypeDef *SPI,uint16_t *dst, uint8_t *noofdata)
{
	while((SPI->SR.bit.RNE)&&(*noofdata!=0))
	{
		*dst++=SPI->DR.bit.DATA;
		noofdata--;
		
	}
	return;
}
/*****************************************************************************
Function Name	SPI_ClrInt(may not need)
Function Definition	void SPI_ClrInt(void)
Function Description	Clear SPI interrupt
Input Parameters	No
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			
*****************************************************************************/
void SPI_ClrInt(G32F1_SPI_TypeDef *SPI)
{
	SPI->ICR.bit.RORIC;
}
/*****************************************************************************
Function Name	SPI_EnableInt
Function Definition	void SPI_EnableInt(uint8_t inttype)
Function Description	Setup SPI interrupt
Input Parameters	Inttype: combination of 
					SPI_RX_FIFO_FULL	1
					SPI_RX_FIFO_NOT_EMPTY	2
					SPI_RX_FIFO_HALF_FULL	4
					SPI_TX_FIFO_HALF_EMPTY	8
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			
*****************************************************************************/
void SPI_EnableInt(G32F1_SPI_TypeDef *SPI,uint8_t inttype)
{
	SPI->IMSC.all |= inttype;
	return;
}
/*****************************************************************************
Function Name	SPI_DisableInt
Function Definition	void SPI_DisableInt(uint8_t inttype)
Function Description	Setup SPI interrupt
Input Parameters	Inttype: combination of 
					SPI_RX_FIFO_FULL	1
					SPI_RX_FIFO_NOT_EMPTY	2
					SPI_RX_FIFO_HALF_FULL	4
					SPI_TX_FIFO_HALF_EMPTY	8
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			
*****************************************************************************/
void SPI_DisableInt(G32F1_SPI_TypeDef *SPI,uint8_t inttype)
{
	SPI->IMSC.all &= ~inttype;
	
	return;
}


/*****************************************************************************
Function Name	SPI_Set_SSEL_High
Function Definition	void SPI_Set_SSEL_High(uint8_t inttype)
Function Description	Setup SPI SSEL High
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			
*****************************************************************************/
void SPI_Set_SSEL_High(G32F1_SPI_TypeDef *SPI)
{
	SPI->CR1.bit.CSFL = 1;
}


/*****************************************************************************
Function Name	SPI_Reset_SSEL_Low
Function Definition	void SPI_Reset_SSEL_Low(uint8_t inttype)
Function Description	Setup SPI SSEL Low
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			
*****************************************************************************/
void SPI_Reset_SSEL_Low(G32F1_SPI_TypeDef *SPI)
{
	SPI->CR1.bit.CSFL = 0;
}


/*****************************************************************************
Function Name	SPI_Reset_SSEL_Low
Function Definition	void SPI_Reset_SSEL_Low(uint8_t inttype)
Function Description	Setup SPI SSEL Low
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			
*****************************************************************************/
void SPI_Write_FIFO(G32F1_SPI_TypeDef *SPI,uint32_t data)
{
	SPI->DR.bit.DATA=data;
}


/*****************************************************************************
Function Name	SPI_TX_FIFO_Not_Empty
Function Definition	void SPI_TX_FIFO_Not_Empty(uint8_t inttype)
Function Description	
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			
*****************************************************************************/
int SPI_TX_FIFO_Not_Empty(G32F1_SPI_TypeDef *SPI)
{
	return((SPI->SR.all&0x11)!=1);
}


/*****************************************************************************
Function Name	SPI_TX_FIFO_Not_Empty
Function Definition	void SPI_TX_FIFO_Not_Empty(uint8_t inttype)
Function Description	
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			
*****************************************************************************/
void POLL_RXFIFO_NOTEMPTY(G32F1_SPI_TypeDef *SPI)
{
	while(SPI1->SR.bit.RNE==0);
}

/*****************************************************************************
Function Name	SPI_Read_FIFO
Function Definition	void SPI_Read_FIFO(uint8_t inttype)
Function Description	
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12			
*****************************************************************************/
int SPI_Read_FIFO(G32F1_SPI_TypeDef *SPI)
{
	return (SPI->DR.bit.DATA);
}
#endif
//////////////////////////ST////////////////////////////

/**
  * @brief  Fills each SPI_InitStruct member with its default value.
  * @param  SPI_InitStruct : pointer to a SPI_InitTypeDef structure which will be initialized.
  * @retval None
  */
void SPI_StructInit(SPI_InitTypeDef* SPI_InitStruct)
{
/*--------------- Reset SPI init structure parameters values -----------------*/
  /* Initialize the SPI_Direction member */
  SPI_InitStruct->SPI_Direction = SPI_Direction_2Lines_FullDuplex;
  /* initialize the SPI_Mode member */
  SPI_InitStruct->SPI_Mode = SPI_Mode_Master;
  /* initialize the SPI_DataSize member */
  SPI_InitStruct->SPI_DataSize = SPI_DataSize_8b;
  /* Initialize the SPI_CPOL member */
  SPI_InitStruct->SPI_CPOL = SPI_CPOL_Low;
  /* Initialize the SPI_CPHA member */
  SPI_InitStruct->SPI_CPHA = SPI_CPHA_1Edge;
  /* Initialize the SPI_NSS member */
  SPI_InitStruct->SPI_NSS = SPI_NSS_Hard;
  /* Initialize the SPI_BaudRatePrescaler member */
  SPI_InitStruct->SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_16;
  /* Initialize the SPI_FirstBit member */
  SPI_InitStruct->SPI_FirstBit = SPI_FirstBit_MSB;
  /* Initialize the SPI_CRCPolynomial member */
  SPI_InitStruct->SPI_CRCPolynomial = 7;
}

/**
  * @brief  Initializes the SPIx peripheral according to the specified 
  *         parameters in the SPI_InitStruct.
  * @param  SPIx: where x can be 1, 2 or 3 to select the SPI peripheral.
  * @param  SPI_InitStruct: pointer to a SPI_InitTypeDef structure that
  *         contains the configuration information for the specified SPI peripheral.
  * @retval None
  */
void SPI_Init(SPI_TypeDef* SPIx, SPI_InitTypeDef* SPI_InitStruct)
{

	//SPI_InitStruct->SPI_Direction       not used
	//SPI_InitStruct->SPI_CRCPolynomial   not used
	//SPI_InitStruct->SPI_SPI_FirstBit    not used
	//SPI_InitStruct->SPI_NSS             not used
	
	//enable SPI clock
	if(SPIx==SPI1)		    SYSCON->SYSAPB2CLKCTRL.bit.SPI1CLK=1;
  else if(SPIx==SPI2)		SYSCON->SYSAPB1CLKCTRL.bit.SPI2CLK=1;
  else if(SPIx==SPI3)		SYSCON->SYSAPB1CLKCTRL.bit.SPI3CLK=1;
	//Set master/slave
	if(SPI_InitStruct->SPI_Mode ==SPI_Mode_Master)
		SPIx->CR1.bit.MS=0;
	else if (SPI_InitStruct->SPI_Mode ==SPI_Mode_Slave)
		SPIx->CR1.bit.MS=1;
	//Select bit width
	SPIx->CR0.bit.DSS = SPI_InitStruct->SPI_DataSize;
	//Set SPI mode
	SPIx->CR0.bit.CPOL = SPI_InitStruct->SPI_CPOL;
	SPIx->CR0.bit.CPHA = SPI_InitStruct->SPI_CPHA;
	//Set SPI BaudRate
	SPIx->CPSR.bit.CPSDVSR = SPI_InitStruct->SPI_BaudRatePrescaler;	
}

/**
  * @brief  Enables or disables the specified SPI peripheral.
  * @param  SPIx: where x can be 1, 2 or 3 to select the SPI peripheral.
  * @param  NewState: new state of the SPIx peripheral. 
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void SPI_Cmd(SPI_TypeDef* SPIx, FunctionalState NewState)
{
   if (NewState != DISABLE)
  {
    /* Enable the selected SPI peripheral */
     SPIx->CR1.bit.SSE=1;
  }
  else
  {
    /* Disable the selected SPI peripheral */
    SPIx->CR1.bit.SSE=0;
  }
}

void SPI_I2S_SendData(SPI_TypeDef* SPIx, uint16_t Data)
{
  
  /* Write in the DR register the data to be sent */
	 SPIx->CR1.bit.RSFR  = 1 ;
	 SPIx->CR1.bit.RSFR  = 0 ;
   SPIx->DR.bit.DATA = Data;
}

/**
  * @brief  Returns the most recent received data by the SPIx/I2Sx peripheral. 
  * @param  SPIx: where x can be
  *   - 1, 2 or 3 in SPI mode 
  *   - 2 or 3 in I2S mode
  * @retval The value of the received data.
  */
uint16_t SPI_I2S_ReceiveData(SPI_TypeDef* SPIx)
{
	
  /* Return the data in the DR register */
    return  SPIx->DR.bit.DATA;
}



FlagStatus SPI_I2S_GetFlagStatus(SPI_TypeDef* SPIx, uint16_t SPI_I2S_FLAG)
{
  FlagStatus bitstatus = RESET;
	
  /* Check the status of the specified SPI/I2S flag */
  if ((SPIx->SR.all & SPI_I2S_FLAG) != (uint16_t)RESET)
  {
    /* SPI_I2S_FLAG is set */
    bitstatus = SET;
  }
  else
  {
    /* SPI_I2S_FLAG is reset */
    bitstatus = RESET;
  }
  /* Return the SPI_I2S_FLAG status */
  return  bitstatus;
}

void SPI_SSEL_LOW(SPI_TypeDef *SPI)
{
	SPI->CR1.bit.CSFL = 1;
}

void SPI_SSEL_HIGH(SPI_TypeDef *SPI)
{
	SPI->CR1.bit.CSFL = 0;
}

u8 SPI1_TransReceive(u8 Data)
{
	while(SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_BSY) == SET);   //空闲时BSY为0，等待发送或者接收完成
	SPI_I2S_SendData(SPI1, Data); 
	while(SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_TFE) == RESET); //发送FIFO为空时TFE为0，等待发送结束
	while(SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_RNE) == RESET);//如果接收FIFO不为空，则RNE为1，等待回复
	return (u8)SPI_I2S_ReceiveData(SPI1);
	 
}

u8 SPI2_TransReceive(u8 Data)
{
	while(SPI_I2S_GetFlagStatus(SPI2,SPI_I2S_FLAG_BSY) == SET);   //空闲时BSY为0，等待发送或者接收完成
	SPI_I2S_SendData(SPI2, Data); 
	while(SPI_I2S_GetFlagStatus(SPI2,SPI_I2S_FLAG_TFE) == RESET); //发送FIFO为空时TFE为0，等待发送结束
	while(SPI_I2S_GetFlagStatus(SPI2,SPI_I2S_FLAG_RNE) == RESET);//如果接收FIFO不为空，则RNE为1，等待回复
	return (u8)SPI_I2S_ReceiveData(SPI2);
}	 



/******************************************************************************
**                            End Of File
******************************************************************************/
