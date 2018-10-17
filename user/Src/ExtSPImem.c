
/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"
#include "queue.h"

#include "main.h"
#include "time.h"
#include "stdlib.h"
#include "string.h"
#include <port.h>

#include "stm32f4xx_hal_spi.h"
#include "stm32f4xx_hal_gpio.h"
#include "ExtSPImem.h"

extern SPI_HandleTypeDef 		SpiHandle;
extern MEMDeviceIDTypeDef 		SPIMemoryID;

/* test_page - ����� ��� ������ � ������   */
//uint8_t page_Buf_In[PAGE_SIZE],page_Buf_Out[PAGE_SIZE];

static int16_t	AddrMemInFirstBuf = -1;	// ����� �������� ������� ����� � ������.
static int16_t	AddrMemInSecondBuf = -1;

uint8_t 	GetFromMEM(uint8_t* dst, uint16_t AddrPage, uint16_t AddrByte, uint16_t Size);
uint8_t 	GetFromBUF1(uint8_t* dst, uint16_t AddrByte, uint16_t Size);
uint8_t 	SendToBUF1(uint8_t* src, uint16_t AddrByte, uint16_t Size);
uint8_t 	SendBUF1ToMem(uint16_t AddrPage);
uint8_t 	GetMemtoBUF1(uint16_t AddrPage);

int HAL_SPI_DataInDMA_Tx(SPI_HandleTypeDef *hspi);
//*******************************************************************************
// void AT45DB161D_spi_init(void)
//
//*******************************************************************************
void AT45DB161D_spi_init(void)
{

	/* Set the SPI parameters */
	SpiHandle.Instance              	= SPI1;
	SpiHandle.Init.BaudRatePrescaler 	= SPI_BAUDRATEPRESCALER_2;
	SpiHandle.Init.Direction        	= SPI_DIRECTION_2LINES;
	SpiHandle.Init.CLKPhase          	= SPI_PHASE_1EDGE;
	SpiHandle.Init.CLKPolarity       	= SPI_POLARITY_LOW;
	SpiHandle.Init.CRCCalculation    	= SPI_CRCCALCULATION_DISABLE;
	SpiHandle.Init.CRCPolynomial     	= 7;
	SpiHandle.Init.DataSize          	= SPI_DATASIZE_8BIT;
	SpiHandle.Init.FirstBit          	= SPI_FIRSTBIT_MSB;
	SpiHandle.Init.NSS               	= SPI_NSS_SOFT;
	SpiHandle.Init.TIMode            	= SPI_TIMODE_DISABLE;
	SpiHandle.Init.Mode 			 	= SPI_MODE_MASTER;


	if(HAL_SPI_Init(&SpiHandle) != HAL_OK)
	{
//	  USART_TRACE_RED("SPI Init error.. ������ ad45db161d �� ����� ����������. \n");
	  //for(;;){}
	} else {
//	  USART_TRACE("���� ���� SPI... ok. \n");
	}

//  HAL_SPI_TransmitReceive_DMA(&SpiHandle, (uint8_t*)NULL, (uint8_t *)NULL, 0);

}
//*******************************************************************************
// uint32_t	MEM_ID_Read (void)
// ������ ID ������
//*******************************************************************************
int8_t	MEM_ID_Read (MEMDeviceIDTypeDef *IDInfo){

	uint8_t 	DataOut[5] , DataIn[5];
	int8_t		ret = TRUE;

	DataOut[0] = AT45DB_ID_READ;
	DataOut[1] = 0;
	DataOut[2] = 0;
	DataOut[3] = 0;
	DataOut[4] = 0;

    MEM_Chipselect(GPIO_PIN_RESET);

    if(HAL_SPI_TransmitReceive_DMA(&SpiHandle,DataOut,DataIn, 5) != HAL_OK)
    {
    	USART_TRACE_RED("������ ������-�������� SPI. \n");
    }
    while (HAL_SPI_GetState(&SpiHandle) != HAL_SPI_STATE_READY){}
    MEM_Chipselect(GPIO_PIN_SET);				// �������� CS

    IDInfo->ManufacturerID = DataIn[1];
    IDInfo->FamilyCode = DataIn[2]>>5;
    IDInfo->DensityCode = DataIn[2] & 0b00011111;
    IDInfo->MLCCode = DataIn[3]>>5;
    IDInfo->ProductVersionCode = DataIn[3] & 0b00011111;
    IDInfo->ByteCount = DataIn[4];

    if (IDInfo->ManufacturerID == 0x1f) ret = TRUE; else ret = FALSE;

	USART_TRACE("-- ��������� ������ SPI ------------------------------\n");
	USART_TRACE("SPIMemory:\n");
	USART_TRACE("JEDEC Assigned Code - %.2X\n",IDInfo->ManufacturerID);
	USART_TRACE("Family Code - %.2X\n",IDInfo->FamilyCode);
	USART_TRACE("Density Code - %.2X, �����:%u �������\n",IDInfo->DensityCode,0x40<<IDInfo->DensityCode);
	USART_TRACE("MLC Code - %.2X\n",IDInfo->MLCCode);
	USART_TRACE("Product Version Code - %.2X\n",IDInfo->ProductVersionCode);
	USART_TRACE("Byte Count - %.2X\n",IDInfo->ByteCount);
	USART_TRACE("------------------------------------------------------\n");


    return ret;
}
//*******************************************************************************
// void	MEM_Reset (void)
// ������ ID ������
//*******************************************************************************
void MEM_Reset (void){

}
/*************************************************************************
 * memory_Powerof2_SetMode
 * ����� ������ � ������� 512 ����
 *************************************************************************/
int8_t 		memory_Powerof2_SetMode (void){

	uint8_t 	DataOut[4];

	while(!((AT45DB_StatusRegisterRead()>>7) & 1 )){}		// ������� ���������� ������

	DataOut[0] = 0x3D;
	DataOut[1] = 0x2A;
	DataOut[2] = 0x80;
	DataOut[3] = 0xA6;

	// ---------------
	MEM_Chipselect(GPIO_PIN_RESET);
	if(HAL_SPI_Transmit_DMA(&SpiHandle,DataOut,4) != HAL_OK){
		USART_TRACE_RED("������ �������� SPI. \n");
		MEM_Chipselect(GPIO_PIN_SET);
		return FALSE;
	}
	// ---------------
	while (HAL_SPI_GetState(&SpiHandle) != HAL_SPI_STATE_READY){}
	MEM_Chipselect(GPIO_PIN_SET);
	return TRUE;

}
/*************************************************************************
 * memory_DataFlash_SetMode
 * ����� ������ � ������� 528 ����
 *************************************************************************/
int8_t 		memory_DataFlash_SetMode (void){

	uint8_t 	DataOut[4];

	while(!((AT45DB_StatusRegisterRead()>>7) & 1 )){}		// ������� ���������� ������

	DataOut[0] = 0x3D;
	DataOut[1] = 0x2A;
	DataOut[2] = 0x80;
	DataOut[3] = 0xA7;

	// ---------------
	MEM_Chipselect(GPIO_PIN_RESET);
	if(HAL_SPI_Transmit_DMA(&SpiHandle,DataOut,4) != HAL_OK){
		USART_TRACE_RED("������ �������� SPI. \n");
		MEM_Chipselect(GPIO_PIN_SET);
		return FALSE;
	}
	// ---------------
	while (HAL_SPI_GetState(&SpiHandle) != HAL_SPI_STATE_READY){}
	MEM_Chipselect(GPIO_PIN_SET);
	return TRUE;
}

/*************************************************************************
 * memory_read
 *
 *************************************************************************/
int8_t 	memory_read (uint8_t *dst, uint32_t Addr, uint16_t Size)
{
uint16_t	AddrPage,AddrByte;
uint16_t	AddrPageSecond,AddrByteSecond;
uint16_t	i;

	AddrPage = 	Addr / (uint16_t)PAGE_SIZE_528;
	AddrByte = Addr % (uint16_t)PAGE_SIZE_528;

	AddrPageSecond = (Addr + Size) / (uint16_t)PAGE_SIZE_528;						// ����� �������� ����� ����� ������.
	AddrByteSecond = (Addr + Size) % (uint16_t)PAGE_SIZE_528;						// ����� ������ ����� ����� ������.

	if (( (AddrPageSecond - 1) == AddrPage) && (AddrByteSecond == 0)){	// ���������� � ����
		AddrPageSecond = AddrPage;
	}

	if ((AddrPageSecond == AddrPage)){			// ��������� � ���� ��������
		if (AddrPage == AddrMemInFirstBuf){								// ���� � ������� ������
			if (!GetFromBUF1(dst,AddrByte,Size)) return FALSE;
		}else{															// ������ � ������ ��������
			if (!GetFromMEM(dst,AddrPage,AddrByte,Size)) return FALSE;	// ������ ����� �� ������
		}
	} else{																// �� ��������� � ����� ��������, ����� ������ ����� �� ������ � ����� �� ��������� ������
		if (AddrPage == AddrMemInFirstBuf){								// ���� ���������� � �������� ������
			if (!GetFromBUF1(dst,AddrByte,PAGE_SIZE_528-AddrByte)) return FALSE; 			// ������ ���� �� ������
			if (!GetFromMEM(dst +(PAGE_SIZE_528-AddrByte),AddrPage+1,0,Size-(PAGE_SIZE_528-AddrByte))) return FALSE;	// ������ ����� �� ������
		}else{															// ���� ���������� � ������ �������� ������
			if (!GetFromMEM(dst,AddrPage,AddrByte,Size)) return FALSE;	// ������ ����� �� ������
		}
	}
/*
	if (Size != 12){
		USART_TRACE_GREEN("������  ������: Addr = %.7u, Size = %.3u : '%s'\n",(unsigned int) Addr,(unsigned int) Size, dst);
	}else{
		USART_TRACE_GREEN("������  ������: Addr = %.7u, Size = %.3u :", Addr, Size);
		for (i=0;i<Size;i++){printf(" 0x%.2X",dst[i]);}
		printf("\n");
	}
*/
return TRUE;
}
/*************************************************************************
 * memory_write_to_mem
 * ������ ������ ������ ����� ����� � ������ �� ��������� ���������� ������
 * �� �����.
 *
 *************************************************************************/
int8_t 	memory_write_to_mem (uint8_t *src, uint32_t Addr, uint16_t Size)
{
	uint16_t		nPage,i;
	uint16_t		AddrPage,AddrByte;
	uint16_t		AddrPageSecond,AddrByteSecond;
	uint16_t		SizeInFirstPage,SizeInSecondPage;

	if (Size > PAGE_SIZE_528){
		USART_TRACE_RED("SPIMEM. �� ��������� � ���� ��������!!!\n");
		return FALSE;
	}
//	USART_TRACE_GREEN("SPIMEM. ����� � ������: Addr = %.7u, Size = %.3u :", Addr, Size);
//	for (i=0;i<Size;i++){printf(" 0x%.2X",src[i]);}
//	printf("\n");

	// ����� ��������� ������� �� �� ������� ������, ���� ������� �� �������� � 2-�� ��������.
	AddrPage = 	Addr / PAGE_SIZE_528;						// ��������� ����� ��������.
	AddrByte = Addr % PAGE_SIZE_528;						// ����� �� ��������.

	AddrPageSecond = (Addr + Size) / PAGE_SIZE_528;			// ����� �������� ����� ����� ������.
	AddrByteSecond = (Addr + Size) % PAGE_SIZE_528;			// ����� ������ ����� ����� ������.

	if (AddrPageSecond == AddrPage){						// ��������� � ���� ��������
		SizeInFirstPage = Size;								// ��� ������ ���� ����� � ��.
		SizeInSecondPage = 0;

		if (!GetMemtoBUF1(AddrPage)) return FALSE;							// ������������ �� SPI � �����1
		if (!SendToBUF1(src,AddrByte,SizeInFirstPage)) return FALSE;		// ���������� � �����
		if (!SendBUF1ToMem(AddrPage)) return FALSE;							// ������������ ����� � ������ SPI

		// ���, ����� �����
		//USART_TRACE_GREEN("memory_write_to_mem.\n");

		return TRUE;
	} else{
//		USART_TRACE_RED("SPIMEM. �� ��������� � ���� ��������\n");
		return FALSE;
	}

}
/*************************************************************************
 * memory_write
 * ����� �������� ��������� ������ ������ ����� ����� ��������.
 * 1. ��������� �� ��������� �� ���� �� ������ ��������, ���� ���
 * 		�� �������� ������ � ������� ��� ������ � ������,
 * 		���� ���� ����� ������� ��������, �� ������ ��������� ����� �� ������ �����
 * 		� �������� ���������� 1-�� ������ � ������.
 *
 * 		uint8_t		- ����� ��������� ������ (1 ��� 2)
 * 		uint32_t	- ����� �������� � ������� ������
 * 		uint32_t	- ����� �������� � ��������� ������
 * 		������ ������� ������ = 528 ����
 *
 *************************************************************************/
int8_t 	memory_write (uint8_t *src, uint32_t Addr, uint16_t Size)
{
	uint16_t		AddrPage,AddrByte;
	uint16_t		AddrPageSecond,AddrByteSecond;
	uint16_t		SizeInFirstPage,SizeInSecondPage;
	uint16_t		nPage,i;

	// -------------------------------------------------------------------------------------------------------------
	// -------------------------------------------------------------------------------------------------------------
	// ����� ��������� ������� �� �� ������� ������, ���� ������� �� �������� � 2-�� ��������.
	AddrPage = 	Addr / PAGE_SIZE_528;											// ��������� ����� ��������.
	AddrByte = Addr % PAGE_SIZE_528;											// ����� �� ��������.

	AddrPageSecond = (Addr + Size) / PAGE_SIZE_528;								// ����� �������� ����� ����� ������.
	AddrByteSecond = (Addr + Size) % PAGE_SIZE_528;								// ����� ������ ����� ����� ������.

/*
	if (( (AddrPageSecond - 1) == AddrPage) && (AddrByteSecond == 0)){			// ���������� � ����
		AddrPageSecond = AddrPage;
	}
*/
	// � ����� ��������---------------------
	if ((AddrPageSecond == AddrPage)){											// ��������� � ���� ��������
		SizeInFirstPage = Size;													// ��� ������ ���� ����� � ��.
		SizeInSecondPage = 0;

		if (AddrPage == AddrMemInFirstBuf){										// ���� � ������� ������
			if (!SendToBUF1(src,AddrByte,SizeInFirstPage)) return FALSE;		// ���������� � �����
		}else{																	// ���� � ����� �������� �����, �� ������ �� ���������� � ���������� ���������

			if(AddrMemInFirstBuf >= 0)											// ���� ������ �����
				if (!SendBUF1ToMem(AddrMemInFirstBuf)) return FALSE;			// ������������ ����� � ������ SPI, ��� ����� ������ �����

			AddrMemInFirstBuf = AddrPage;										// ����� ����� ��������
			if (!GetMemtoBUF1(AddrMemInFirstBuf)) return FALSE;					// ������������ �� SPI � �����1
			if (!SendToBUF1(src,AddrByte,SizeInFirstPage)) return FALSE;		// ���������� � �����
		}
	}
	// !� ����� ��������---------------------
	else{																		// �� ��������� � ���� �������� ����� ���� � ���������
		SizeInFirstPage = PAGE_SIZE_528 - AddrByte;								// ������ ����� � ������ ��������.
		SizeInSecondPage = AddrByteSecond;										// ������ ����� � ��������� ��������.
		nPage = AddrPageSecond - AddrPage;										// ����� �������

		if(AddrMemInFirstBuf < 0)												// ���� ������ �����, ���������� �������� �� ������
		{
			AddrMemInFirstBuf = AddrPage;
			if (!GetMemtoBUF1(AddrMemInFirstBuf)) return FALSE;					// ������������ �� SPI � �����1
		}

		// �������� ���������� �����
		if (AddrPage == AddrMemInFirstBuf){										// ���� �������� � ������� ������
			if (!SendToBUF1(src,AddrByte,SizeInFirstPage)) return FALSE;		// ���������� � �����
			if (!SendBUF1ToMem(AddrMemInFirstBuf)) return FALSE;				// ������������ ����� � ������ SPI
			AddrMemInFirstBuf++;
		}else{																	// ���� � ����� �������� �����, �� ������ �� ���������� � ���������� ���������
			if (!SendBUF1ToMem(AddrMemInFirstBuf)) return FALSE;				// ������������ ����� � ������ SPI
			AddrMemInFirstBuf = AddrPage;
		}

		src += SizeInFirstPage;													// ����������� ��������� �� ������ ��� �����������.

		for (i = AddrMemInFirstBuf;i<AddrPageSecond;i++){						// �� ������� �������
			if (!GetMemtoBUF1(i)) return FALSE;									// ������������ �� SPI � �����1
			if (!SendToBUF1(src,0,PAGE_SIZE_528)) return FALSE;					// ���������� � �����
			if (!SendBUF1ToMem(i)) return FALSE;								// ������������ ����� � ������ SPI
			src += PAGE_SIZE_528;												// ���������� �����
		}
		AddrMemInFirstBuf = AddrPageSecond;

		// ��������� �� ���������� ��������
		if (!GetMemtoBUF1(AddrMemInFirstBuf)) return FALSE;						// ������������ �� SPI � �����1
		if (!SendToBUF1(src,0,SizeInSecondPage)) return FALSE;					// ���������� � �����
	}
	// ���, ����� �����
	return TRUE;
	// -------------------------------------------------------------------------------------------------------------
	// -------------------------------------------------------------------------------------------------------------
/*
	while(!((AT45DB_StatusRegisterRead()>>7) & 1 )){}		// ������� ���������� ������

	// ������ �� ������ � ����� 1
	DataOut[0] = AT45DB_MM_PAGE_TO_B1_XFER;					// CMD
	DataOut[1] = (uint8_t)(AddrPage >> 6);					// P11-P6
	DataOut[2] = (uint8_t)(AddrPage << 2);					// P5-P0, 0, 0
	DataOut[3] = (uint8_t) 0;								// 0

	// ---------------
    MEM_Chipselect(GPIO_PIN_RESET);
    if(HAL_SPI_Transmit_DMA(&SpiHandle,DataOut,4) != HAL_OK){
    	USART_TRACE_RED("������ �������� SPI. \n");
        MEM_Chipselect(GPIO_PIN_SET);
    	return FALSE;
    }
	// ---------------
    while (HAL_SPI_GetState(&SpiHandle) != HAL_SPI_STATE_READY){}
    MEM_Chipselect(GPIO_PIN_SET);

	while(!((AT45DB_StatusRegisterRead()>>7) & 1 )){}			// ������� ���������� ������


    // �������� � ����� ���� ������
	DataOut[0] = AT45DB_BUFFER_1_WRITE;				// CMD
	DataOut[1] = 0;									// xxxx
	DataOut[2] =  (uint8_t) (AddrByte >> 8);		// BFA9-8
	DataOut[3] =  (uint8_t) AddrByte;				// BFA7-0

    MEM_Chipselect(GPIO_PIN_RESET);

    if(HAL_SPI_Transmit_DMA(&SpiHandle,DataOut,4) != HAL_OK){
    	USART_TRACE_RED("������ �������� ������� ������ � ����� ������ SPI. \n");
        MEM_Chipselect(GPIO_PIN_SET);
    	return FALSE;
    }
    while (HAL_SPI_GetState(&SpiHandle) != HAL_SPI_STATE_READY){}

    if(HAL_SPI_Transmit_DMA(&SpiHandle,src,Size) != HAL_OK){
    	USART_TRACE_RED("������ �������� ������ � ����� ������ SPI. \n");
        MEM_Chipselect(GPIO_PIN_SET);
    	return FALSE;
    }
    while (HAL_SPI_GetState(&SpiHandle) != HAL_SPI_STATE_READY){}

    MEM_Chipselect(GPIO_PIN_SET);

	while(!((AT45DB_StatusRegisterRead()>>7) & 1 )){}			// ������� ���������� ������

	MEM_Chipselect(GPIO_PIN_RESET);
    // ������������ ����� � main memory
	DataOut[0] = AT45DB_B1_TO_MM_PAGE_PROG_WITH_ERASE;		// CMD
	DataOut[1] = (uint8_t)(AddrPage >> 6);					// A20-A16
	DataOut[2] = (uint8_t)(AddrPage << 2);					// A15-A8
	DataOut[3] = (uint8_t) 0;								// A7-A0

	if(HAL_SPI_Transmit_DMA(&SpiHandle,DataOut,4) != HAL_OK){
		USART_TRACE_RED("������ �������� ������� ���������� �� ������ � ������ SPI. \n");
	    MEM_Chipselect(GPIO_PIN_SET);
		return FALSE;
	}
    while (HAL_SPI_GetState(&SpiHandle) != HAL_SPI_STATE_READY){}

    MEM_Chipselect(GPIO_PIN_SET);

	return TRUE;
*/
}
/*************************************************************************
 * Page_memory_read
 * PageAddr - ����� ��������
 * ����� ��������: A20-A9
 * ����� ������ ��������: A6-A0
 *************************************************************************/
int8_t 	Page_memory_read (uint8_t *dst, uint16_t PageAddr, uint16_t PageSize){

	uint8_t 	DataOut[8];

	while(!((AT45DB_StatusRegisterRead()>>7) & 1 )){}			// ������� ���������� ������

	DataOut[0] = AT45DB_MM_PAGE_READ;						// CMD
	DataOut[1] = (uint8_t)(PageAddr >> 6) & 0b00111111;		// A20-A16
	DataOut[2] = (uint8_t)(PageAddr << 2) & 0b11111100;		// A15-A8
	DataOut[3] = (uint8_t) 0;								// A7-A0

	// 	4 Dummy Bytes
	DataOut[4] = (uint8_t) 0;
	DataOut[5] = (uint8_t) 0;
	DataOut[6] = (uint8_t) 0;
	DataOut[7] = (uint8_t) 0;

    MEM_Chipselect(GPIO_PIN_RESET);

    if(HAL_SPI_Transmit_DMA(&SpiHandle,DataOut,8) != HAL_OK){
    	USART_TRACE_RED("������ �������� SPI. \n");
    	return FALSE;
    }
//    while (HAL_SPI_GetState(&SpiHandle) != HAL_SPI_STATE_READY){}
    while (HAL_SPI_DataInDMA_Tx(&SpiHandle)>0){}		// ��� ������������ ������

    if(HAL_SPI_Receive_DMA(&SpiHandle,dst,PageSize) != HAL_OK){
    	USART_TRACE_RED("������ ������ SPI. \n");
    	return FALSE;
    }
//    while (HAL_SPI_GetState(&SpiHandle) != HAL_SPI_STATE_READY){}
    while (HAL_SPI_DataInDMA_Tx(&SpiHandle)>0){}		// ��� ������������ ������

    MEM_Chipselect(GPIO_PIN_SET);

	return TRUE;
}
/*************************************************************************
* Block_memory_read
* PageSize - ������ ��������
* NumberOfPages - ����� �������
 *************************************************************************/
int8_t 	Block_memory_read (uint8_t *dst, uint16_t PageAddr, uint16_t PageSize,  uint16_t NumberOfPages){

uint16_t	i;

	for (i=0; i<NumberOfPages ;i++){
		if (!Page_memory_read(dst+i*PageSize,PageAddr+i,PageSize)) return FALSE;
	}

	return TRUE;
}
/*************************************************************************
* Page_memory_write
* ������ �������� � ������ ������ ����� �� ��������� ����������� ����� 2 �����
* PageAddr - ����� ��������
* PageSize - ������ ��������
*
* ps. ���� ����� ����������� ��
*  ������� 0x55 - Main Memory Page to Buffer Transfer
*  �����   0x85 - Main Memory Page Program through Buffer
*  �����   0x59 - Auto Page Rewrite
 *************************************************************************/
int8_t 		Page_memory_write(uint8_t *src, uint16_t PageAddr, uint16_t PageSize){

	uint8_t 	DataOut[8];

	while(!((AT45DB_StatusRegisterRead()>>7) & 1 )){}			// ������� ���������� ������

    // �������� � ����� ���� ������
	DataOut[0] = AT45DB_MM_PAGE_PROG_THRU_BUFFER2;		// CMD
	DataOut[1] = (uint8_t)(PageAddr >> 6) & 0b00111111;	// A20-A16
	DataOut[2] = (uint8_t)(PageAddr << 2) & 0b11111100;	// A15-A8
	DataOut[3] = (uint8_t) 0;							// A7-A0

    MEM_Chipselect(GPIO_PIN_RESET);
    if(HAL_SPI_Transmit_DMA(&SpiHandle,DataOut,4) != HAL_OK){
    	USART_TRACE_RED("������ �������� ������� ������ � ����� ������ SPI. \n");
    	goto reterr;
    }
    while (HAL_SPI_DataInDMA_Tx(&SpiHandle)>0){}		// ��� ������������ ������
//    while (HAL_SPI_GetState(&SpiHandle) != HAL_SPI_STATE_READY){}

    if(HAL_SPI_Transmit_DMA(&SpiHandle,src,PageSize) != HAL_OK){
    	USART_TRACE_RED("������ �������� ������ � ����� ������ SPI. \n");
    	goto reterr;
    }
    while (HAL_SPI_DataInDMA_Tx(&SpiHandle)>0){}
    MEM_Chipselect(GPIO_PIN_SET);
/*
	while(!((AT45DB_StatusRegisterRead()>>7) & 1 )){}			// ������� ���������� ������

    // ������������ ����� � main memory
	DataOut[0] = AT45DB_B1_TO_MM_PAGE_PROG_WITH_ERASE;	// CMD
	DataOut[1] = (uint8_t)(PageAddr >> 6) & 0b00111111;	// A20-A16
	DataOut[2] = (uint8_t)(PageAddr << 2) & 0b11111100;	// A15-A8
	DataOut[3] = (uint8_t) 0;							// A7-A0

	MEM_Chipselect(GPIO_PIN_RESET);
	if(HAL_SPI_Transmit_DMA(&SpiHandle,DataOut,4) != HAL_OK){
		USART_TRACE_RED("������ �������� ������� ���������� �� ������ � ������ SPI. \n");
    	goto reterr;
	}
    while (HAL_SPI_DataInDMA_Tx(&SpiHandle)>0){}
    MEM_Chipselect(GPIO_PIN_SET);
*/
	return TRUE;
reterr:
MEM_Chipselect(GPIO_PIN_SET);
return false;
}

/*************************************************************************
* Block_memory_write
* src ����� ���������
* PageSize - ������ ��������
* NumberOfPages - ����� �������
 *************************************************************************/
int8_t 		Block_memory_write(uint8_t *src, uint16_t PageAddr, uint16_t PageSize,  uint16_t NumberOfPages){

	uint16_t	i;

		for (i=0; i<NumberOfPages ;i++){
			if (!Page_memory_write(src+i*PageSize,PageAddr+i,PageSize)) return FALSE;
		}

		return TRUE;
}

//*******************************************************************************
// bool Block_memory_write_noWait (uint16_t Pageaddress, uint16_t Memaddress, uint8_t *dst, uint16_t Size)
// ������ ������ � ���� Pageaddress � ��������� ������� ����� ������ �������� Memaddress
// ��� �������� ��������� ������
//*******************************************************************************
int8_t 		Block_memory_write_noWait(uint16_t Pageaddress, uint16_t Memaddress, uint8_t *dst, uint16_t Size){

    return TRUE;
}
//*******************************************************************************
// bool Bufer2_to_memory_write(uint16_t Pageaddress)
// ������ �������� ������ �� ������ Address � �����1
//*******************************************************************************
int8_t Bufer2_to_memory_write(uint16_t Pageaddress){

	uint8_t 	DataOut[4];

	DataOut[0] = AT45DB_B2_TO_MM_PAGE_PROG_WITH_ERASE;
	DataOut[1] = ((uint8_t)(Pageaddress >> 6));
	DataOut[2] = ((uint8_t)(Pageaddress << 2));
	DataOut[3] = 0x00;

	MEM_Chipselect(GPIO_PIN_RESET);
    HAL_SPI_Transmit_DMA(&SpiHandle,(uint8_t*)&DataOut, 4);
	MEM_Chipselect(GPIO_PIN_SET);	// ����� ����� 40��
	osDelay(40);

return TRUE;
}
//*******************************************************************************
// uint8_t memory_read (uint8_t Command, uint32_t Address)
// ������ �������� ������ �� ������ Address � �����1
//*******************************************************************************
void memory_to_buffer1_transfer (uint16_t page){

	uint8_t 	DataOut[4];

	DataOut[0] = AT45DB_MM_PAGE_TO_B1_XFER;
	DataOut[1] = ((uint8_t)(page >> 6));
	DataOut[2] = ((uint8_t)(page << 2));
	DataOut[3] = 0x00;

	MEM_Chipselect(GPIO_PIN_RESET);
    HAL_SPI_Transmit_DMA(&SpiHandle,(uint8_t*)&DataOut, 4);
	MEM_Chipselect(GPIO_PIN_SET);
	osDelay(1);	// ����� ����� 400���

}
//*******************************************************************************
// uint8_t memory_read (uint8_t Command, uint32_t Address)
// ������ �������� ������ �� ������ Address � �����2
//*******************************************************************************
void memory_to_buffer2_transfer (uint16_t page){

	uint8_t 	DataOut[4];

	DataOut[0] = AT45DB_MM_PAGE_TO_B2_XFER;
	DataOut[1] = ((uint8_t)(page >> 6));
	DataOut[2] = ((uint8_t)(page << 2));
	DataOut[3] = 0x00;

//TODO: ����� ������� �������� � ���������, � ����� ��������� ������.
	while(!((AT45DB_StatusRegisterRead()>>7) & 1 )){}// �������� ���� ����� ��� ����������

	MEM_Chipselect(GPIO_PIN_RESET);
    HAL_SPI_Transmit_DMA(&SpiHandle,(uint8_t*)&DataOut, 4);
	MEM_Chipselect(GPIO_PIN_SET);

	while(!((AT45DB_StatusRegisterRead()>>7) & 1 )){}// �������� ���� �� ��������� � �����

//	Delay_mks(400);
}
//*******************************************************************************
// uint8_t AT45DB_StatusRegisterRead(void)
// ������ �������� ������� ������
//*******************************************************************************
uint8_t AT45DB_StatusRegisterRead(void)
{
	uint8_t		ret=0;
	uint8_t 	DataOut[3],DataIn[3];
	DataOut[0] = AT45DB_READ_STATE_REGISTER;

    MEM_Chipselect(GPIO_PIN_RESET);
    if(HAL_SPI_TransmitReceive_DMA(&SpiHandle,(uint8_t*)&DataOut[0],(uint8_t*)&DataIn[0], 2) != HAL_OK)
      {
      	USART_TRACE_RED("������ ������-�������� �������� �������. \n");
      }
	MEM_Chipselect(GPIO_PIN_SET);
	if (DataIn[0] != 0) ret = DataIn[0]; else
	if (DataIn[1] != 0) ret = DataIn[1];
	return ret;
/*
	// �������� �� ��� ������ ����
	uint8_t		Data = AT45DB_READ_STATE_REGISTER;
    MEM_Chipselect(GPIO_PIN_RESET);
    HAL_SPI_Transmit_DMA(&SpiHandle,(uint8_t*)&Data, 1);
    HAL_SPI_Receive_DMA(&SpiHandle,(uint8_t*)&Data, 1);
    MEM_Chipselect(GPIO_PIN_SET);
    return Data;
*/
}
//*******************************************************************************
// void AT45DB_buffer1_write(uint16_t addres,uint8_t data )
// ������ ����� � �����
// ��������� ����� � ������
//*******************************************************************************
void AT45DB_buffer1_write(uint16_t addres,uint8_t data )
{
	uint8_t 	DataOut[5];

	DataOut[0] = AT45DB_BUFFER_1_WRITE;
	DataOut[1] = 0x00;
	DataOut[2] = ((uint8_t)(addres >> 8));
	DataOut[3] = ((uint8_t)addres );
	DataOut[4] = data;

    MEM_Chipselect(GPIO_PIN_RESET);
    HAL_SPI_Transmit_DMA(&SpiHandle,(uint8_t*)&DataOut, 5);
	MEM_Chipselect(GPIO_PIN_SET);
}
//*******************************************************************************
// void AT45DB_buffer1_write(uint16_t addres,uint8_t data )
// ������ ����� � �����
// ��������� ����� � ������
//*******************************************************************************
uint8_t AT45DB_buffer1_read(uint16_t addres )
{
	uint8_t 	DataOut[5],DataIn;

	DataOut[0] = AT45DB_BUFFER_1_READ;
	DataOut[1] = 0x00;
	DataOut[2] = ((uint8_t)(addres >> 8));
	DataOut[3] = ((uint8_t)addres );
	DataOut[4] = 0x00;

    MEM_Chipselect(GPIO_PIN_RESET);
    HAL_SPI_Transmit_DMA(&SpiHandle,(uint8_t*)&DataOut, 5);
    HAL_SPI_Receive_DMA(&SpiHandle,(uint8_t*)&DataIn, 1);
    MEM_Chipselect(GPIO_PIN_SET);

	return DataIn;
}
//*******************************************************************************
// void AT45DB_buffer1_write(uint16_t addres,uint8_t data )
// ������ ����� � �����
// ��������� ����� � ������
//*******************************************************************************
uint8_t AT45DB_buffer2_read(uint16_t addres )
{
	uint8_t 	DataOut[5],DataIn;

	DataOut[0] = AT45DB_BUFFER_2_READ;
	DataOut[1] = 0x00;
	DataOut[2] = ((uint8_t)(addres >> 8));
	DataOut[3] = ((uint8_t)addres );
	DataOut[4] = 0x00;

    MEM_Chipselect(GPIO_PIN_RESET);
    HAL_SPI_Transmit_DMA(&SpiHandle,(uint8_t*)&DataOut, 5);
    HAL_SPI_Receive_DMA(&SpiHandle,(uint8_t*)&DataIn, 1);
    MEM_Chipselect(GPIO_PIN_SET);

	return DataIn;
}
//*******************************************************************************
// void AT45DB_buffer1_write(uint16_t addres,uint8_t data )
// ������ �����1 � ������
// ����� ��������� � �������� ������
//*******************************************************************************
void AT45DB_buffer1_to_memory(uint16_t addres)
{
	uint8_t 	Data[5];

	Data[0] = AT45DB_B1_TO_MM_PAGE_PROG_WITH_ERASE;
	Data[1] = 0x00;
	Data[2] = ((uint8_t)(addres >> 6));
	Data[3] = ((uint8_t)(addres << 2));
	Data[4] = 0x00;

    MEM_Chipselect(GPIO_PIN_RESET);
    HAL_SPI_Transmit_DMA(&SpiHandle,(uint8_t*)&Data,5);
	MEM_Chipselect(GPIO_PIN_SET);
}
//*******************************************************************************
// void SPI_HostWriteByte(uint8_t Data)
// ������ � SPI
//*******************************************************************************
void SPI_HostWriteByte(uint8_t Data){

	HAL_SPI_Transmit_DMA(&SpiHandle,(uint8_t*)&Data,1);
}
//*******************************************************************************
// uint8_t SPI_HostReadByte(void)
// ������ �� SPI ���������
//*******************************************************************************
uint8_t SPI_HostReadByte(void){

	uint8_t 	Data;

	HAL_SPI_Receive_DMA(&SpiHandle,(uint8_t*)&Data,1);

	return Data;
}
//*******************************************************************************
// uint8_t SPI_HostReadByte(void)
// ������ �� SPI �����
//*******************************************************************************
uint8_t SPI_STATEREGISTERRead(void){

	uint8_t 	Data;

	HAL_SPI_Receive_DMA(&SpiHandle,(uint8_t*)&Data,1);

	return Data;
}
//*******************************************************************************
// void MEM_Chipselect(uint8_t select)
// ������� ������� CS ��� ������
//*******************************************************************************
void MEM_Chipselect(GPIO_PinState select){

	HAL_GPIO_WritePin(db161d_CS_GPIO_PORT,db161d_CS_PIN,select);

}

//*******************************************************************************
// GetFromMEM
// ������ �� SPI � ������ ������
//*******************************************************************************
uint8_t GetFromMEM(uint8_t* dst, uint16_t AddrPage, uint16_t AddrByte, uint16_t Size){

uint8_t 	DataOut[9];
uint8_t		sta = 0;

/*
	while(!(sta & 1<<7)){
		sta = AT45DB_StatusRegisterRead();
	}

	if(sta & 1){				// ����� ������� 512

	} else{						// ����� ������� 528

	}
*/

	while(!((AT45DB_StatusRegisterRead()>>7) & 1 )){}			// ������� ���������� ������

	DataOut[0] = AT45DB_MM_PAGE_READ;									// CMD
	DataOut[1] = (uint8_t)(AddrPage >> 6);								// P11-P6
	DataOut[2] = (uint8_t)(AddrPage << 2) | (uint8_t)(AddrByte >> 8);	// P5-P0, B9, B8
	DataOut[3] = (uint8_t) AddrByte;									// B7-B0

	// 	4 Dummy Bytes
	DataOut[4] = (uint8_t) 0;
	DataOut[5] = (uint8_t) 0;
	DataOut[6] = (uint8_t) 0;
	DataOut[7] = (uint8_t) 0;

	MEM_Chipselect(GPIO_PIN_RESET);

	if(HAL_SPI_Transmit_DMA(&SpiHandle,(uint8_t *)&DataOut[0],8) != HAL_OK){
		USART_TRACE_RED("������ �������� SPI. \n");
		return FALSE;
	}
	while (HAL_SPI_GetState(&SpiHandle) != HAL_SPI_STATE_READY){}

	if(HAL_SPI_Receive_DMA(&SpiHandle,dst,Size) != HAL_OK){
		USART_TRACE_RED("������ ������ SPI. \n");
		return FALSE;
	}
	while (HAL_SPI_GetState(&SpiHandle) != HAL_SPI_STATE_READY){}

	MEM_Chipselect(GPIO_PIN_SET);

	return TRUE;

}
//*******************************************************************************
// GetFromBUF1
// ������ �� ������ � ������ ������
//*******************************************************************************
uint8_t GetFromBUF1(uint8_t* dst, uint16_t AddrByte, uint16_t Size){

uint8_t 	DataOut[5];

	if ((AddrByte + Size) > PAGE_SIZE_528)	{
		USART_TRACE_RED("������ ������� ����� ������ �� ������ ������ . GetFromBUF1\n");
		return FALSE;
	}

	while(!((AT45DB_StatusRegisterRead()>>7) & 1 )){}			// ������� ���������� ������

	// �������� � ����� ���� ������
	DataOut[0] = AT45DB_BUFFER_1_READ;				// CMD
	DataOut[1] = 0;									// xxxx
	DataOut[2] =  (uint8_t) (AddrByte >> 8);		// BFA9-8
	DataOut[3] =  (uint8_t) AddrByte;				// BFA7-0

	// 	1 Dummy Bytes
	DataOut[4] = (uint8_t) 0;

	MEM_Chipselect(GPIO_PIN_RESET);

	if(HAL_SPI_Transmit_DMA(&SpiHandle,DataOut,5) != HAL_OK){
		USART_TRACE_RED("������ �������� SPI. \n");
		return FALSE;
	}
	while (HAL_SPI_GetState(&SpiHandle) != HAL_SPI_STATE_READY){}

	if(HAL_SPI_Receive_DMA(&SpiHandle,dst,Size) != HAL_OK){
		USART_TRACE_RED("������ ������ SPI. \n");
		return FALSE;
	}
	while (HAL_SPI_GetState(&SpiHandle) != HAL_SPI_STATE_READY){}

	MEM_Chipselect(GPIO_PIN_SET);

return TRUE;
}

//*******************************************************************************
// SendToBUF1
// ����� � ����� ������
//*******************************************************************************
uint8_t SendToBUF1(uint8_t* src, uint16_t AddrByte, uint16_t Size){

uint8_t 	DataOut[4];

	if ((AddrByte + Size) > PAGE_SIZE_528)	{
		USART_TRACE_RED("������ ������� ����� ������ � ����� ������ SPI. SendToBUF1\n");
		return FALSE;
	}

	while(!((AT45DB_StatusRegisterRead()>>7) & 1 )){}			// ������� ���������� ������

	// �������� � ����� ���� ������
	DataOut[0] = AT45DB_BUFFER_1_WRITE;				// CMD
	DataOut[1] = 0;									// xxxx
	DataOut[2] =  (uint8_t) (AddrByte >> 8);		// BFA9-8
	DataOut[3] =  (uint8_t) AddrByte;				// BFA7-0

	MEM_Chipselect(GPIO_PIN_RESET);
	if(HAL_SPI_Transmit_DMA(&SpiHandle,DataOut,4) != HAL_OK){							// �������
		USART_TRACE_RED("������ �������� ������� ������ � ����� ������ SPI. \n");
		MEM_Chipselect(GPIO_PIN_SET);
		return FALSE;
	}
	while (HAL_SPI_GetState(&SpiHandle) != HAL_SPI_STATE_READY){}
	if(HAL_SPI_Transmit_DMA(&SpiHandle,src,Size) != HAL_OK){							// ���� ������
		USART_TRACE_RED("������ �������� ������ � ����� ������ SPI. \n");
		MEM_Chipselect(GPIO_PIN_SET);
		return FALSE;
	}
	while (HAL_SPI_GetState(&SpiHandle) != HAL_SPI_STATE_READY){}
	MEM_Chipselect(GPIO_PIN_SET);
return TRUE;
}

//*******************************************************************************
// SendBUF1ToMem
// ������������ ����� � ������ �� �������� AddrPage
//*******************************************************************************
uint8_t SendBUF1ToMem(uint16_t AddrPage){

	uint8_t 	DataOut[4];

	while(!((AT45DB_StatusRegisterRead()>>7) & 1 )){}			// ������� ���������� ������

	MEM_Chipselect(GPIO_PIN_RESET);
	// ������������ ����� � main memory
	DataOut[0] = AT45DB_B1_TO_MM_PAGE_PROG_WITH_ERASE;		// CMD
	DataOut[1] = (uint8_t)(AddrPage >> 6);					// A20-A16
	DataOut[2] = (uint8_t)(AddrPage << 2);					// A15-A8
	DataOut[3] = (uint8_t) 0;								// A7-A0

	if(HAL_SPI_Transmit_DMA(&SpiHandle,DataOut,4) != HAL_OK){
		USART_TRACE_RED("������ �������� ������� ���������� �� ������ � ������ SPI. \n");
		MEM_Chipselect(GPIO_PIN_SET);
		return FALSE;
	}
	while (HAL_SPI_GetState(&SpiHandle) != HAL_SPI_STATE_READY){}
	MEM_Chipselect(GPIO_PIN_SET);
	return TRUE;
}

//*******************************************************************************
// GetMemtoBUF1
// ������������ ������ �� ������ �� �������� AddrPage
//*******************************************************************************
uint8_t GetMemtoBUF1(uint16_t AddrPage){

	uint8_t 	DataOut[4];

	while(!((AT45DB_StatusRegisterRead()>>7) & 1 )){}		// ������� ���������� ������

	// ������ �� ������ � ����� 1
	DataOut[0] = AT45DB_MM_PAGE_TO_B1_XFER;					// CMD
	DataOut[1] = (uint8_t)(AddrPage >> 6);					// P11-P6
	DataOut[2] = (uint8_t)(AddrPage << 2);					// P5-P0, 0, 0
	DataOut[3] = (uint8_t) 0;								// 0

	// ---------------
	MEM_Chipselect(GPIO_PIN_RESET);
	if(HAL_SPI_Transmit_DMA(&SpiHandle,DataOut,4) != HAL_OK){
		USART_TRACE_RED("������ �������� SPI. \n");
		MEM_Chipselect(GPIO_PIN_SET);
		return FALSE;
	}
	// ---------------
	while (HAL_SPI_GetState(&SpiHandle) != HAL_SPI_STATE_READY){}
	MEM_Chipselect(GPIO_PIN_SET);
	return TRUE;
}
/*************************************************************************
  * @brief  HAL_SPI_DataInDMA_Tx
  * ������� ���� ����� � dma
  *
 *************************************************************************/

int HAL_SPI_DataInDMA_Tx(SPI_HandleTypeDef *hspi){
int		Datanumb;

Datanumb = /*hspi->TxXferSize - */hspi->hdmatx->Instance->NDTR;
return	Datanumb;
}
