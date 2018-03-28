/*****************************************************************************
 *   gt_crc.h:  Header file for GORGETEK G32F0
 *
 *   Copyright(C) 2015, Gorge Technology
 *   All rights reserved.
 *
 *   History
 *   2015.07.21  ver 1.01    Prelimnary version
 *
******************************************************************************/
/* Includes ------------------------------------------------------------------*/

#include "g32f1xx.h"
#include "gt_dma.h"
#include "gt_sys.h"


void DMA_SETBASEPTR(G32F1_DMA_TypeDef *DMAx,uint32_t addr)
{
	DMAx->CTRL_BASE_PTR.all = addr;
	
}

void DMA_Enable(G32F1_DMA_TypeDef *DMAx)
{
	DMAx->DMA_CFG.bit.MASTER_EN = 1;
}

void DMA_Disable(G32F1_DMA_TypeDef *DMAx)
{
	DMAx->DMA_CFG.bit.MASTER_EN = 0;
}

void DMA_SWRequest(G32F1_DMA_TypeDef *DMAx,uint32_t chnl)
{
	DMAx->CHNL_SW_REQUEST.all |= chnl;
	
}

void DMA_UseBurstSet(G32F1_DMA_TypeDef *DMAx,uint32_t chnl)
{
	DMAx->CHNL_USEBURST_SET.all |= chnl;
}

void DMA_UseBurstClr(G32F1_DMA_TypeDef *DMAx,uint32_t chnl)
{
	DMAx->CHNL_USEBURST_CLR.all |= chnl;
}

void DMA_ReqMaskSet(G32F1_DMA_TypeDef *DMAx,uint32_t chnl)
{
	DMAx->CHNL_REQ_MASK_SET.all |= chnl;
}

void DMA_ReqMaskClr(G32F1_DMA_TypeDef *DMAx,uint32_t chnl)
{
	DMAx->CHNL_REQ_MASK_CLR.all |= chnl;
}

void DMA_CHEnableSet(G32F1_DMA_TypeDef *DMAx,uint32_t chnl)
{
	DMAx->CHNL_ENABLE_SET.all |= chnl;
}

void DMA_CHEnableClr(G32F1_DMA_TypeDef *DMAx,uint32_t chnl)
{
	DMAx->CHNL_ENABLE_CLR.all |= chnl;
}

void DMA_CHPrioritySet(G32F1_DMA_TypeDef *DMAx,uint32_t chnl)
{
	DMAx->CHNL_PRIORITY_SET.all |= chnl;
}

void DMA_CHPriorityClr(G32F1_DMA_TypeDef *DMAx,uint32_t chnl)
{
	DMAx->CHNL_PRIORITY_CLR.all |= chnl;
}

int DMA_IRQStatus(G32F1_DMA_TypeDef *DMAx)
{
	return DMAx->CHNL_IRQ_STATUS.all;	
}

void DMA_IRQEnable(G32F1_DMA_TypeDef *DMAx,uint32_t chnl)
{
	DMAx->CHNL_IRQ_ENABLE.all |= chnl;
}


/******************************************************************************
**                            End Of File
******************************************************************************/
