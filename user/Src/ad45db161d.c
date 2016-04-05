
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
#include "at45db161d.h"

extern SPI_HandleTypeDef 		SpiHandle;
extern MEMDeviceIDTypeDef 		SPIMemoryID;

/* test_page - буфер для записи в память   */
//uint8_t page_Buf_In[PAGE_SIZE],page_Buf_Out[PAGE_SIZE];

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
	  USART_TRACE("SPI Init error.. память ad45db161d не будет подключена. \n");
	  //for(;;){}
	} else {
	  USART_TRACE("Инит шины SPI... ok. \n");

	}

//  HAL_SPI_TransmitReceive_DMA(&SpiHandle, (uint8_t*)page_Buf_Out, (uint8_t *)page_Buf_In, PAGE_SIZE);

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
	uint8_t 	DataOut = AT45DB_READ_STATE_REGISTER,DataIn[2];

    MEM_Chipselect(GPIO_PIN_RESET);
    if(HAL_SPI_TransmitReceive_DMA(&SpiHandle,(uint8_t*)&DataOut,(uint8_t*)&DataIn[0], 2) != HAL_OK)
      {
      	USART_TRACE_RED("Ошибка приема-передачи регистра статуса. \n");
      }
 //   HAL_SPI_Transmit_DMA(&SpiHandle,(uint8_t*)&DataOut, 1);
 //   HAL_SPI_Receive_DMA(&SpiHandle,(uint8_t*)&DataIn, 1);
	MEM_Chipselect(GPIO_PIN_SET);

    return DataIn[1];
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


