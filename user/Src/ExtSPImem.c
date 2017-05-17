
/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"
#include "queue.h"

#include "main.h"
#include "time.h"
#include "stdlib.h"
#include "string.h"

#include "stm32f4xx_hal_spi.h"
#include "stm32f4xx_hal_gpio.h"
#include "ExtSPImem.h"

extern SPI_HandleTypeDef 		SpiHandle;
extern MEMDeviceIDTypeDef 		SPIMemoryID;

/* test_page - буфер для записи в память   */
//uint8_t page_Buf_In[PAGE_SIZE],page_Buf_Out[PAGE_SIZE];

static int16_t	AddrMemInFirstBuf = -1;	// номер страницы которая лежит в буфере.
static int16_t	AddrMemInSecondBuf = -1;

uint8_t 	GetFromMEM(uint8_t* dst, uint16_t AddrPage, uint16_t AddrByte, uint16_t Size);
uint8_t 	GetFromBUF1(uint8_t* dst, uint16_t AddrByte, uint16_t Size);
uint8_t 	SendToBUF1(uint8_t* src, uint16_t AddrByte, uint16_t Size);
uint8_t 	SendBUF1ToMem(uint16_t AddrPage);
uint8_t 	GetMemtoBUF1(uint16_t AddrPage);
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
//	  USART_TRACE_RED("SPI Init error.. память ad45db161d не будет подключена. \n");
	  //for(;;){}
	} else {
//	  USART_TRACE("Инит шины SPI... ok. \n");
	}

//  HAL_SPI_TransmitReceive_DMA(&SpiHandle, (uint8_t*)NULL, (uint8_t *)NULL, 0);

}
//*******************************************************************************
// uint32_t	MEM_ID_Read (void)
// чтение ID памяти
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
    	USART_TRACE_RED("Ошибка приема-передачи SPI. \n");
    }
    while (HAL_SPI_GetState(&SpiHandle) != HAL_SPI_STATE_READY){}
    MEM_Chipselect(GPIO_PIN_SET);				// выключим CS

    IDInfo->ManufacturerID = DataIn[1];
    IDInfo->FamilyCode = DataIn[2]>>5;
    IDInfo->DensityCode = DataIn[2] & 0b00011111;
    IDInfo->MLCCode = DataIn[3]>>5;
    IDInfo->ProductVersionCode = DataIn[3] & 0b00011111;
    IDInfo->ByteCount = DataIn[4];

    if (IDInfo->ManufacturerID == 0x1f) ret = TRUE; else ret = FALSE;

	USART_TRACE("-- Параметры памяти SPI ------------------------------\n");
	USART_TRACE("SPIMemory:\n");
	USART_TRACE("JEDEC Assigned Code - %.2X\n",IDInfo->ManufacturerID);
	USART_TRACE("Family Code - %.2X\n",IDInfo->FamilyCode);
	USART_TRACE("Density Code - %.2X, объем:%u страниц\n",IDInfo->DensityCode,0x40<<IDInfo->DensityCode);
	USART_TRACE("MLC Code - %.2X\n",IDInfo->MLCCode);
	USART_TRACE("Product Version Code - %.2X\n",IDInfo->ProductVersionCode);
	USART_TRACE("Byte Count - %.2X\n",IDInfo->ByteCount);
	USART_TRACE("------------------------------------------------------\n");


    return ret;
}
//*******************************************************************************
// void	MEM_Reset (void)
// чтение ID памяти
//*******************************************************************************
void MEM_Reset (void){

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

	AddrPage = 	Addr / PAGE_SIZE_528;
	AddrByte = Addr % PAGE_SIZE_528;

	AddrPageSecond = (Addr + Size) / PAGE_SIZE_528;						// номер страницы конца блока данных.
	AddrByteSecond = (Addr + Size) % PAGE_SIZE_528;						// номер ячейки конца блока данных.

	if (AddrPageSecond == AddrPage){									// вмещается в одну страницу
		if (AddrPage == AddrMemInFirstBuf){								// если в текущем буфере
			if (!GetFromBUF1(dst,AddrByte,Size)) return FALSE;
		}else{															// данные в другой странице
			if (!GetFromMEM(dst,AddrPage,AddrByte,Size)) return FALSE;	// читаем прямо из памяти
		}
	} else{																// не вмещается в одной странице, нужно читать часть из буфера а часть из остальной памяти
		if (AddrPage == AddrMemInFirstBuf){								// если начинается с текущего буфера
			if (!GetFromBUF1(dst,AddrByte,PAGE_SIZE_528-AddrByte)) return FALSE; 			// начало берём из буфера
			if (!GetFromMEM(dst +(PAGE_SIZE_528-AddrByte),AddrPage+1,0,Size-(PAGE_SIZE_528-AddrByte))) return FALSE;	// читаем прямо из памяти
		}else{															// если начинается с другой страницы памяти
			if (!GetFromMEM(dst,AddrPage,AddrByte,Size)) return FALSE;	// читаем прямо из памяти
		}
	}
/*
	if (Size != 12){
		USART_TRACE_GREEN("читаем  память: Addr = %.7u, Size = %.3u : '%s'\n",(unsigned int) Addr,(unsigned int) Size, dst);
	}else{
		USART_TRACE_GREEN("читаем  память: Addr = %.7u, Size = %.3u :", Addr, Size);
		for (i=0;i<Size;i++){printf(" 0x%.2X",dst[i]);}
		printf("\n");
	}
*/
return TRUE;
/*
	AddrPage = 	Addr / PAGE_SIZE_528;
	AddrByte = Addr % PAGE_SIZE_528;

	while(!((AT45DB_StatusRegisterRead()>>7) & 1 )){}			// подождём готовность памяти

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

	if(HAL_SPI_Transmit_DMA(&SpiHandle,DataOut,8) != HAL_OK){
		USART_TRACE_RED("Ошибка передачи SPI. \n");
		return FALSE;
	}
	while (HAL_SPI_GetState(&SpiHandle) != HAL_SPI_STATE_READY){}

	if(HAL_SPI_Receive_DMA(&SpiHandle,dst,Size) != HAL_OK){
		USART_TRACE_RED("Ошибка приема SPI. \n");
		return FALSE;
	}
	while (HAL_SPI_GetState(&SpiHandle) != HAL_SPI_STATE_READY){}

	MEM_Chipselect(GPIO_PIN_SET);

return TRUE;
*/
}
/*************************************************************************
 * memory_write_to_mem
 * просто запись данных через буфер в память не дожидаясь заполнения буфера
 * до конца.
 *
 *************************************************************************/
int8_t 	memory_write_to_mem (uint8_t *src, uint32_t Addr, uint16_t Size)
{
	uint16_t		nPage,i;
	uint16_t		AddrPage,AddrByte;
	uint16_t		AddrPageSecond,AddrByteSecond;
	uint16_t		SizeInFirstPage,SizeInSecondPage;

//	USART_TRACE_GREEN("SPIMEM. пишем в память: Addr = %.7u, Size = %.3u :", Addr, Size);
//	for (i=0;i<Size;i++){printf(" 0x%.2X",src[i]);}
//	printf("\n");

	// нужно проверить выходит ли за границы буфера, если выходит то работаем с 2-мя буферами.
	AddrPage = 	Addr / PAGE_SIZE_528;						// высчитаем номер страницы.
	AddrByte = Addr % PAGE_SIZE_528;						// адрес на странице.

	AddrPageSecond = (Addr + Size) / PAGE_SIZE_528;			// номер страницы конца блока данных.
	AddrByteSecond = (Addr + Size) % PAGE_SIZE_528;			// номер ячейки конца блока данных.

	if (AddrPageSecond == AddrPage){						// вмещается в одну страницу
		SizeInFirstPage = Size;								// тут просто льём кусок и всё.
		SizeInSecondPage = 0;

		if (!GetMemtoBUF1(AddrPage)) return FALSE;							// перекидываем из SPI в буфер1
		if (!SendToBUF1(src,AddrByte,SizeInFirstPage)) return FALSE;		// закидываем в буфер
		if (!SendBUF1ToMem(AddrPage)) return FALSE;							// перекидываем буфер в память SPI

		// все, пошли назад
		//USART_TRACE_GREEN("memory_write_to_mem.\n");

		return TRUE;
	} else{
//		USART_TRACE_RED("SPIMEM. Не вмещается в одну страницу\n");
		return FALSE;
	}

}
/*************************************************************************
 * memory_write
 * Нужно добавить обработку записи блоков более одной страницы.
 * 1. проверяем не переходит ли блок на вторую страницу, если нет
 * 		то работаем только с буфером без записи в память,
 * 		Если есть смена рабочей страницы, то читаем следующий адрес во второй буфер
 * 		и начинаем перезапись 1-го буфера в память.
 *
 * 		uint8_t		- номер активного буфера (1 или 2)
 * 		uint32_t	- адрес страницы в рабочем буфере
 * 		uint32_t	- адрес страницы в резервном буфере
 * 		кратно размеру буфера = 528 байт
 *
 *************************************************************************/
int8_t 	memory_write (uint8_t *src, uint32_t Addr, uint16_t Size)
{
	uint16_t		AddrPage,AddrByte;
	uint16_t		AddrPageSecond,AddrByteSecond;
	uint16_t		SizeInFirstPage,SizeInSecondPage;
	uint16_t		nPage,i;

	/*
	if (Size != 12){
		USART_TRACE_GREEN("пишем в память: Addr = %.7u, Size = %.3u : '%s'\n", Addr, Size,src);
	}else{
		USART_TRACE_GREEN("пишем в память: Addr = %.7u, Size = %.3u :", Addr, Size);
		for (i=0;i<Size;i++){printf(" 0x%.2X",src[i]);}
		printf("\n");
	}
*/
	// -------------------------------------------------------------------------------------------------------------
	// -------------------------------------------------------------------------------------------------------------
	// нужно проверить выходит ли за границы буфера, если выходит то работаем с 2-мя буферами.
	AddrPage = 	Addr / PAGE_SIZE_528;						// высчитаем номер страницы.
	AddrByte = Addr % PAGE_SIZE_528;						// адрес на странице.

	AddrPageSecond = (Addr + Size) / PAGE_SIZE_528;			// номер страницы конца блока данных.
	AddrByteSecond = (Addr + Size) % PAGE_SIZE_528;			// номер ячейки конца блока данных.

	if (AddrPageSecond == AddrPage){						// вмещается в одну страницу
		SizeInFirstPage = Size;								// тут просто льём кусок и всё.
		SizeInSecondPage = 0;

		if (AddrPage == AddrMemInFirstBuf){										// если в текущем буфере
			if (!SendToBUF1(src,AddrByte,SizeInFirstPage)) return FALSE;		// закидываем в буфер
		}else{																	// если в новую страницу пошли, то просто ту закидываем и вычитываем следующую

			if(AddrMemInFirstBuf >= 0)											// если первый заход
				if (!SendBUF1ToMem(AddrMemInFirstBuf)) return FALSE;			// перекидываем буфер в память SPI
			AddrMemInFirstBuf = AddrPage;										// новый адрес страницы
			if (!GetMemtoBUF1(AddrMemInFirstBuf)) return FALSE;					// перекидываем из SPI в буфер1
			if (!SendToBUF1(src,AddrByte,SizeInFirstPage)) return FALSE;		// закидываем в буфер
		}

	} else{													// не вмещаемся в одну страницу будем лить в несколько

		SizeInFirstPage = PAGE_SIZE_528 - AddrByte;			// размер блока в первой странице.
		SizeInSecondPage = AddrByteSecond;					// размер блока в последней странице.
		nPage = AddrPageSecond - AddrPage;					// число страниц

		// закончим предыдущий буфер
		if (AddrPage == AddrMemInFirstBuf){										// если начинаем в текущем буфере
			if (!SendToBUF1(src,AddrByte,SizeInFirstPage)) return FALSE;		// закидываем в буфер
			if (!SendBUF1ToMem(AddrMemInFirstBuf)) return FALSE;				// перекидываем буфер в память SPI
			AddrMemInFirstBuf++;
		}else{																	// если в новую страницу пошли, то просто ту закидываем и вычитываем следующую
			if (!SendBUF1ToMem(AddrMemInFirstBuf)) return FALSE;				// перекидываем буфер в память SPI
			AddrMemInFirstBuf = AddrPage;
		}

		src += SizeInFirstPage;													// инкрементим указатель на размер уже записанного.

		for (i = AddrMemInFirstBuf;i<AddrPageSecond;i++){						// по порядку погнали
			if (!GetMemtoBUF1(i)) return FALSE;									// перекидываем из SPI в буфер1
			if (!SendToBUF1(src,0,PAGE_SIZE_528)) return FALSE;					// закидываем в буфер
			if (!SendBUF1ToMem(i)) return FALSE;								// перекидываем буфер в память SPI
			src += PAGE_SIZE_528;												// перелиснем адрес
		}
		AddrMemInFirstBuf = AddrPageSecond;

		// последняя не законченая страница
		if (!GetMemtoBUF1(AddrMemInFirstBuf)) return FALSE;						// перекидываем из SPI в буфер1
		if (!SendToBUF1(src,0,SizeInSecondPage)) return FALSE;					// закидываем в буфер
	}
	// все, пошли назад
	return TRUE;
	// -------------------------------------------------------------------------------------------------------------
	// -------------------------------------------------------------------------------------------------------------
/*
	while(!((AT45DB_StatusRegisterRead()>>7) & 1 )){}		// подождём готовность памяти

	// читаем из памяти в буфер 1
	DataOut[0] = AT45DB_MM_PAGE_TO_B1_XFER;					// CMD
	DataOut[1] = (uint8_t)(AddrPage >> 6);					// P11-P6
	DataOut[2] = (uint8_t)(AddrPage << 2);					// P5-P0, 0, 0
	DataOut[3] = (uint8_t) 0;								// 0

	// ---------------
    MEM_Chipselect(GPIO_PIN_RESET);
    if(HAL_SPI_Transmit_DMA(&SpiHandle,DataOut,4) != HAL_OK){
    	USART_TRACE_RED("Ошибка передачи SPI. \n");
        MEM_Chipselect(GPIO_PIN_SET);
    	return FALSE;
    }
	// ---------------
    while (HAL_SPI_GetState(&SpiHandle) != HAL_SPI_STATE_READY){}
    MEM_Chipselect(GPIO_PIN_SET);

	while(!((AT45DB_StatusRegisterRead()>>7) & 1 )){}			// подождём готовность памяти


    // заливаем в буфер блок данных
	DataOut[0] = AT45DB_BUFFER_1_WRITE;				// CMD
	DataOut[1] = 0;									// xxxx
	DataOut[2] =  (uint8_t) (AddrByte >> 8);		// BFA9-8
	DataOut[3] =  (uint8_t) AddrByte;				// BFA7-0

    MEM_Chipselect(GPIO_PIN_RESET);

    if(HAL_SPI_Transmit_DMA(&SpiHandle,DataOut,4) != HAL_OK){
    	USART_TRACE_RED("Ошибка передачи команды записи в буфер памяти SPI. \n");
        MEM_Chipselect(GPIO_PIN_SET);
    	return FALSE;
    }
    while (HAL_SPI_GetState(&SpiHandle) != HAL_SPI_STATE_READY){}

    if(HAL_SPI_Transmit_DMA(&SpiHandle,src,Size) != HAL_OK){
    	USART_TRACE_RED("Ошибка передачи данных в буфер памяти SPI. \n");
        MEM_Chipselect(GPIO_PIN_SET);
    	return FALSE;
    }
    while (HAL_SPI_GetState(&SpiHandle) != HAL_SPI_STATE_READY){}

    MEM_Chipselect(GPIO_PIN_SET);

	while(!((AT45DB_StatusRegisterRead()>>7) & 1 )){}			// подождём готовность памяти

	MEM_Chipselect(GPIO_PIN_RESET);
    // переписываем буфер в main memory
	DataOut[0] = AT45DB_B1_TO_MM_PAGE_PROG_WITH_ERASE;		// CMD
	DataOut[1] = (uint8_t)(AddrPage >> 6);					// A20-A16
	DataOut[2] = (uint8_t)(AddrPage << 2);					// A15-A8
	DataOut[3] = (uint8_t) 0;								// A7-A0

	if(HAL_SPI_Transmit_DMA(&SpiHandle,DataOut,4) != HAL_OK){
		USART_TRACE_RED("Ошибка передачи команды перезаписи из буфера в память SPI. \n");
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
 * PageAddr - номер страницы
 * адрес страницы: A20-A9
 * адрес внутри страницы: A6-A0
 *************************************************************************/
int8_t 	Page_memory_read (uint8_t *dst, uint16_t PageAddr, uint16_t PageSize){

	uint8_t 	DataOut[8];

	DataOut[0] = AT45DB_MM_PAGE_READ;				// CMD
	DataOut[1] = (uint8_t)(PageAddr >> 6);			// A20-A16
	DataOut[2] = (uint8_t)(PageAddr << 2);			// A15-A8
	DataOut[3] = (uint8_t) 0;						// A7-A0

	// 	4 Dummy Bytes
	DataOut[4] = (uint8_t) 0;
	DataOut[5] = (uint8_t) 0;
	DataOut[6] = (uint8_t) 0;
	DataOut[7] = (uint8_t) 0;

    MEM_Chipselect(GPIO_PIN_RESET);

    if(HAL_SPI_Transmit_DMA(&SpiHandle,DataOut,8) != HAL_OK){
    	USART_TRACE_RED("Ошибка передачи SPI. \n");
    	return FALSE;
    }
    while (HAL_SPI_GetState(&SpiHandle) != HAL_SPI_STATE_READY){}

    if(HAL_SPI_Receive_DMA(&SpiHandle,dst,PAGE_SIZE_512) != HAL_OK){
    	USART_TRACE_RED("Ошибка приема SPI. \n");
    	return FALSE;
    }
    while (HAL_SPI_GetState(&SpiHandle) != HAL_SPI_STATE_READY){}

    MEM_Chipselect(GPIO_PIN_SET);

	return TRUE;
}
/*************************************************************************
* Block_memory_read
* PageSize - размер страницы
* NumberOfPages - число страниц
 *************************************************************************/
int8_t 	Block_memory_read (uint8_t *dst, uint16_t PageAddr, uint16_t PageSize,  uint16_t NumberOfPages){

uint16_t	i;

	for (i=0; i<NumberOfPages ;i++){
		if (!Page_memory_read(dst+i*PageSize,PageAddr,PageSize)) return FALSE;
	}

	return TRUE;
}
/*************************************************************************
* Page_memory_write
* PageAddr - адрес страницы
* PageSize - размер страницы
 *************************************************************************/
int8_t 		Page_memory_write(uint8_t *src, uint16_t PageAddr, uint16_t PageSize){

	uint8_t 	DataOut[8];

	// тут есть возможночть работать с 2-мя буферами. Пока пишутся данные в память можно
	// закинуть во второй буфер, но по освобождении памяти не забыть включить запись его в память.

	// читаем из памяти в буфер 1
	DataOut[0] = AT45DB_MM_PAGE_TO_B1_XFER;				// CMD
	DataOut[1] = (uint8_t)(PageAddr >> 6);			// A20-A16
	DataOut[2] = (uint8_t)(PageAddr << 2);			// A15-A8
	DataOut[3] = (uint8_t) 0;						// A7-A0

    MEM_Chipselect(GPIO_PIN_RESET);

    if(HAL_SPI_Transmit_DMA(&SpiHandle,DataOut,4) != HAL_OK){
    	USART_TRACE_RED("Ошибка передачи SPI. \n");
    	return FALSE;
    }
    while (HAL_SPI_GetState(&SpiHandle) != HAL_SPI_STATE_READY){}
    MEM_Chipselect(GPIO_PIN_SET);

	while(!((AT45DB_StatusRegisterRead()>>7) & 1 )){}			// подождём готовность памяти


    // заливаем в буфер блок данных
	DataOut[0] = AT45DB_BUFFER_1_WRITE;	// CMD
	DataOut[1] = 0;						// xxxx
	DataOut[2] = 0;						// BFA9-8
	DataOut[3] = 0;						// BFA7-0

    MEM_Chipselect(GPIO_PIN_RESET);

    if(HAL_SPI_Transmit_DMA(&SpiHandle,DataOut,4) != HAL_OK){
    	USART_TRACE_RED("Ошибка передачи команды записи в буфер памяти SPI. \n");
    	return FALSE;
    }
    while (HAL_SPI_GetState(&SpiHandle) != HAL_SPI_STATE_READY){}

    if(HAL_SPI_Transmit_DMA(&SpiHandle,src,PAGE_SIZE_512) != HAL_OK){
    	USART_TRACE_RED("Ошибка передачи данных в буфер памяти SPI. \n");
    	return FALSE;
    }
    while (HAL_SPI_GetState(&SpiHandle) != HAL_SPI_STATE_READY){}

    MEM_Chipselect(GPIO_PIN_SET);

	while(!((AT45DB_StatusRegisterRead()>>7) & 1 )){}			// подождём готовность памяти

	MEM_Chipselect(GPIO_PIN_RESET);
    // переписываем буфер в main memory
	DataOut[0] = AT45DB_B1_TO_MM_PAGE_PROG_WITH_ERASE;	// CMD
	DataOut[1] = (uint8_t)(PageAddr >> 6);			// A20-A16
	DataOut[2] = (uint8_t)(PageAddr << 2);			// A15-A8
	DataOut[3] = (uint8_t) 0;							// A7-A0

	if(HAL_SPI_Transmit_DMA(&SpiHandle,DataOut,4) != HAL_OK){
		USART_TRACE_RED("Ошибка передачи команды перезаписи из буфера в память SPI. \n");
		return FALSE;
	}
    while (HAL_SPI_GetState(&SpiHandle) != HAL_SPI_STATE_READY){}

    MEM_Chipselect(GPIO_PIN_SET);

	return TRUE;
}

/*************************************************************************
* Block_memory_write
* PageSize - размер страницы
* NumberOfPages - число страниц
 *************************************************************************/
int8_t 		Block_memory_write(uint8_t *src, uint16_t PageAddr, uint16_t PageSize,  uint16_t NumberOfPages){

	uint16_t	i;

		for (i=0; i<NumberOfPages ;i++){
			if (!Page_memory_write(src+i*PageSize,PageAddr,PageSize)) return FALSE;
		}

		return TRUE;
}

//*******************************************************************************
// bool Block_memory_write_noWait (uint16_t Pageaddress, uint16_t Memaddress, uint8_t *dst, uint16_t Size)
// запись памяти в банк Pageaddress с начальным адресом байта внутри страницы Memaddress
// без ожидания окончания записи
//*******************************************************************************
int8_t 		Block_memory_write_noWait(uint16_t Pageaddress, uint16_t Memaddress, uint8_t *dst, uint16_t Size){

    return TRUE;
}
//*******************************************************************************
// bool Bufer2_to_memory_write(uint16_t Pageaddress)
// чтение основной памяти по адресу Address в буфер1
//*******************************************************************************
int8_t Bufer2_to_memory_write(uint16_t Pageaddress){

	uint8_t 	DataOut[4];

	DataOut[0] = AT45DB_B2_TO_MM_PAGE_PROG_WITH_ERASE;
	DataOut[1] = ((uint8_t)(Pageaddress >> 6));
	DataOut[2] = ((uint8_t)(Pageaddress << 2));
	DataOut[3] = 0x00;

	MEM_Chipselect(GPIO_PIN_RESET);
    HAL_SPI_Transmit_DMA(&SpiHandle,(uint8_t*)&DataOut, 4);
	MEM_Chipselect(GPIO_PIN_SET);	// нужна пауза 40мс
	osDelay(40);

return TRUE;
}
//*******************************************************************************
// uint8_t memory_read (uint8_t Command, uint32_t Address)
// чтение основной памяти по адресу Address в буфер1
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
	osDelay(1);	// нужна пауза 400мкс

}
//*******************************************************************************
// uint8_t memory_read (uint8_t Command, uint32_t Address)
// чтение основной памяти по адресу Address в буфер2
//*******************************************************************************
void memory_to_buffer2_transfer (uint16_t page){

	uint8_t 	DataOut[4];

	DataOut[0] = AT45DB_MM_PAGE_TO_B2_XFER;
	DataOut[1] = ((uint8_t)(page >> 6));
	DataOut[2] = ((uint8_t)(page << 2));
	DataOut[3] = 0x00;

//TODO: Нужно сделать ожидание с таймаутом, а вдруг накрылась память.
	while(!((AT45DB_StatusRegisterRead()>>7) & 1 )){}// подождем пока чтото там закончится

	MEM_Chipselect(GPIO_PIN_RESET);
    HAL_SPI_Transmit_DMA(&SpiHandle,(uint8_t*)&DataOut, 4);
	MEM_Chipselect(GPIO_PIN_SET);

	while(!((AT45DB_StatusRegisterRead()>>7) & 1 )){}// подождем пока не прочитает в буфер

//	Delay_mks(400);
}
//*******************************************************************************
// uint8_t AT45DB_StatusRegisterRead(void)
// чтение регистра статуса памяти
//*******************************************************************************
uint8_t AT45DB_StatusRegisterRead(void)
{

	uint8_t 	DataOut[3],DataIn[3];
	DataOut[0] = AT45DB_READ_STATE_REGISTER;

    MEM_Chipselect(GPIO_PIN_RESET);
    if(HAL_SPI_TransmitReceive_DMA(&SpiHandle,(uint8_t*)&DataOut[0],(uint8_t*)&DataIn[0], 2) != HAL_OK)
      {
      	USART_TRACE_RED("Ошибка приема-передачи регистра статуса. \n");
      }
	MEM_Chipselect(GPIO_PIN_SET);
    return DataIn[1];

/*
	// медленно но без ошибок ФИФО
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
// запись байта в буфер
// указываем адрес в буфере
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
// запись байта в буфер
// указываем адрес в буфере
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
// запись байта в буфер
// указываем адрес в буфере
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
// запись буфер1 в память
// адрес указываем в основной памяти
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
// запись в SPI
//*******************************************************************************
void SPI_HostWriteByte(uint8_t Data){

	HAL_SPI_Transmit_DMA(&SpiHandle,(uint8_t*)&Data,1);
}
//*******************************************************************************
// uint8_t SPI_HostReadByte(void)
// чтение из SPI негативно
//*******************************************************************************
uint8_t SPI_HostReadByte(void){

	uint8_t 	Data;

	HAL_SPI_Receive_DMA(&SpiHandle,(uint8_t*)&Data,1);

	return Data;
}
//*******************************************************************************
// uint8_t SPI_HostReadByte(void)
// чтение из SPI прямо
//*******************************************************************************
uint8_t SPI_STATEREGISTERRead(void){

	uint8_t 	Data;

	HAL_SPI_Receive_DMA(&SpiHandle,(uint8_t*)&Data,1);

	return Data;
}
//*******************************************************************************
// void MEM_Chipselect(uint8_t select)
// дергаем выводом CS для памяти
//*******************************************************************************
void MEM_Chipselect(GPIO_PinState select){

	HAL_GPIO_WritePin(db161d_CS_GPIO_PORT,db161d_CS_PIN,select);

}

//*******************************************************************************
// GetFromMEM
// читаем из SPI в память данные
//*******************************************************************************
uint8_t GetFromMEM(uint8_t* dst, uint16_t AddrPage, uint16_t AddrByte, uint16_t Size){

uint8_t 	DataOut[9];

	while(!((AT45DB_StatusRegisterRead()>>7) & 1 )){}			// подождём готовность памяти

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
		USART_TRACE_RED("Ошибка передачи SPI. \n");
		return FALSE;
	}
	while (HAL_SPI_GetState(&SpiHandle) != HAL_SPI_STATE_READY){}

	if(HAL_SPI_Receive_DMA(&SpiHandle,dst,Size) != HAL_OK){
		USART_TRACE_RED("Ошибка приема SPI. \n");
		return FALSE;
	}
	while (HAL_SPI_GetState(&SpiHandle) != HAL_SPI_STATE_READY){}

	MEM_Chipselect(GPIO_PIN_SET);

	return TRUE;
}
//*******************************************************************************
// GetFromBUF1
// читаем из буфера в память данные
//*******************************************************************************
uint8_t GetFromBUF1(uint8_t* dst, uint16_t AddrByte, uint16_t Size){

uint8_t 	DataOut[5];

	if ((AddrByte + Size) > PAGE_SIZE_528)	{
		USART_TRACE_RED("Ошибка размера блока чтения из буфера памяти . GetFromBUF1\n");
		return FALSE;
	}

	while(!((AT45DB_StatusRegisterRead()>>7) & 1 )){}			// подождём готовность памяти

	// заливаем в буфер блок данных
	DataOut[0] = AT45DB_BUFFER_1_READ;				// CMD
	DataOut[1] = 0;									// xxxx
	DataOut[2] =  (uint8_t) (AddrByte >> 8);		// BFA9-8
	DataOut[3] =  (uint8_t) AddrByte;				// BFA7-0

	// 	1 Dummy Bytes
	DataOut[4] = (uint8_t) 0;

	MEM_Chipselect(GPIO_PIN_RESET);

	if(HAL_SPI_Transmit_DMA(&SpiHandle,DataOut,5) != HAL_OK){
		USART_TRACE_RED("Ошибка передачи SPI. \n");
		return FALSE;
	}
	while (HAL_SPI_GetState(&SpiHandle) != HAL_SPI_STATE_READY){}

	if(HAL_SPI_Receive_DMA(&SpiHandle,dst,Size) != HAL_OK){
		USART_TRACE_RED("Ошибка приема SPI. \n");
		return FALSE;
	}
	while (HAL_SPI_GetState(&SpiHandle) != HAL_SPI_STATE_READY){}

	MEM_Chipselect(GPIO_PIN_SET);

return TRUE;
}

//*******************************************************************************
// SendToBUF1
// пишем в буфер данные
//*******************************************************************************
uint8_t SendToBUF1(uint8_t* src, uint16_t AddrByte, uint16_t Size){

uint8_t 	DataOut[4];

	if ((AddrByte + Size) > PAGE_SIZE_528)	{
		USART_TRACE_RED("Ошибка размера блока записи в буфер памяти SPI. SendToBUF1\n");
		return FALSE;
	}

	while(!((AT45DB_StatusRegisterRead()>>7) & 1 )){}			// подождём готовность памяти

	// заливаем в буфер блок данных
	DataOut[0] = AT45DB_BUFFER_1_WRITE;				// CMD
	DataOut[1] = 0;									// xxxx
	DataOut[2] =  (uint8_t) (AddrByte >> 8);		// BFA9-8
	DataOut[3] =  (uint8_t) AddrByte;				// BFA7-0

	MEM_Chipselect(GPIO_PIN_RESET);
	if(HAL_SPI_Transmit_DMA(&SpiHandle,DataOut,4) != HAL_OK){							// команда
		USART_TRACE_RED("Ошибка передачи команды записи в буфер памяти SPI. \n");
		MEM_Chipselect(GPIO_PIN_SET);
		return FALSE;
	}
	while (HAL_SPI_GetState(&SpiHandle) != HAL_SPI_STATE_READY){}
	if(HAL_SPI_Transmit_DMA(&SpiHandle,src,Size) != HAL_OK){							// блок данных
		USART_TRACE_RED("Ошибка передачи данных в буфер памяти SPI. \n");
		MEM_Chipselect(GPIO_PIN_SET);
		return FALSE;
	}
	while (HAL_SPI_GetState(&SpiHandle) != HAL_SPI_STATE_READY){}
	MEM_Chipselect(GPIO_PIN_SET);
return TRUE;
}

//*******************************************************************************
// SendBUF1ToMem
// перекидываем буфер в память на страницу AddrPage
//*******************************************************************************
uint8_t SendBUF1ToMem(uint16_t AddrPage){

	uint8_t 	DataOut[4];

	while(!((AT45DB_StatusRegisterRead()>>7) & 1 )){}			// подождём готовность памяти

	MEM_Chipselect(GPIO_PIN_RESET);
	// переписываем буфер в main memory
	DataOut[0] = AT45DB_B1_TO_MM_PAGE_PROG_WITH_ERASE;		// CMD
	DataOut[1] = (uint8_t)(AddrPage >> 6);					// A20-A16
	DataOut[2] = (uint8_t)(AddrPage << 2);					// A15-A8
	DataOut[3] = (uint8_t) 0;								// A7-A0

	if(HAL_SPI_Transmit_DMA(&SpiHandle,DataOut,4) != HAL_OK){
		USART_TRACE_RED("Ошибка передачи команды перезаписи из буфера в память SPI. \n");
		MEM_Chipselect(GPIO_PIN_SET);
		return FALSE;
	}
	while (HAL_SPI_GetState(&SpiHandle) != HAL_SPI_STATE_READY){}
	MEM_Chipselect(GPIO_PIN_SET);
	return TRUE;
}

//*******************************************************************************
// GetMemtoBUF1
// перекидываем вбуфер из памяти на странице AddrPage
//*******************************************************************************
uint8_t GetMemtoBUF1(uint16_t AddrPage){

	uint8_t 	DataOut[4];

	while(!((AT45DB_StatusRegisterRead()>>7) & 1 )){}		// подождём готовность памяти

	// читаем из памяти в буфер 1
	DataOut[0] = AT45DB_MM_PAGE_TO_B1_XFER;					// CMD
	DataOut[1] = (uint8_t)(AddrPage >> 6);					// P11-P6
	DataOut[2] = (uint8_t)(AddrPage << 2);					// P5-P0, 0, 0
	DataOut[3] = (uint8_t) 0;								// 0

	// ---------------
	MEM_Chipselect(GPIO_PIN_RESET);
	if(HAL_SPI_Transmit_DMA(&SpiHandle,DataOut,4) != HAL_OK){
		USART_TRACE_RED("Ошибка передачи SPI. \n");
		MEM_Chipselect(GPIO_PIN_SET);
		return FALSE;
	}
	// ---------------
	while (HAL_SPI_GetState(&SpiHandle) != HAL_SPI_STATE_READY){}
	MEM_Chipselect(GPIO_PIN_SET);
	return TRUE;
}
