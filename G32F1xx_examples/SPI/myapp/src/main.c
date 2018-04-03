//G32f0xx SPI flash demo Main Program

#include "g32f1xx.h"
#include "gt_sys.h"
#include "gt_spi.h"

uint16_t Temp = 0;
void delay(void)
{
	uint32_t i=0;
	while (i++ < 0xfff);
}

void SPI_IOCONFIG(void);	

int main(void)
{
  SPI_InitTypeDef  SPI_InitStructure;	
	/* ----------- System Initialization ---------------------- */
	SystemInit();	
	/* ----------- SPI GPIO configuration --------------------- */
	SPI_IOCONFIG();	
	SPI_StructInit(&SPI_InitStructure);
	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_16;
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
	SPI_Init(SPI1, &SPI_InitStructure);	
	SPI_Cmd(SPI1, ENABLE);
	
	SPI_SSEL_LOW(SPI1);
	SPI1_TransReceive(0x90);
	SPI1_TransReceive(0x00);
	SPI1_TransReceive(0x00);
	SPI1_TransReceive(0x00);
	Temp|=SPI1_TransReceive(0xFF)<<8;
	Temp|=SPI1_TransReceive(0xFF);
	SPI_SSEL_HIGH(SPI1);
	
	while(1)
	{

  }
		
}
	



void SPI_IOCONFIG(void)
{
	#if 1			//SPI1, SSEL-> PA4, SCK-> PA5, MISO-> PA6, MOSI-> PA7
	SPI1_SSEL_PA4;
	SPI1_SCK_PA5;	
	SPI1_MISO_PA6;
	SPI1_MOSI_PA7;	
	#endif

	#if 0			//SPI1, SSEL-> PA15, SCK-> PB3, MISO-> PB4, MOSI-> PB5
	SPI1_SSEL_PA15;
	SPI1_SCK_PB3;	
	SPI1_MISO_PB4;
	SPI1_MOSI_PB5;	
	#endif

	#if 0			//SPI2, SSEL-> PB12, SCK-> PB13, MISO-> PB14, MOSI-> PB15
	SPI2_SSEL_PB12;
	SPI2_SCK_PB13;	
	SPI2_MISO_PB14;
	SPI2_MOSI_PB15;	
	#endif
}	

