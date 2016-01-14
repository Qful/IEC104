
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

extern SPI_HandleTypeDef SpiHandle;


/* test_page - буфер для записи в память   */
uint8_t page_Buf_In[PAGE_SIZE],page_Buf_Out[PAGE_SIZE];

//*******************************************************************************
// void AT45DB161D_spi_init(void)
//
//*******************************************************************************
void AT45DB161D_spi_init(void)
{

	/* Set the SPI parameters */
	SpiHandle.Instance              	= SPI1;
	SpiHandle.Init.BaudRatePrescaler 	= SPI_BAUDRATEPRESCALER_64;
	SpiHandle.Init.Direction        	= SPI_DIRECTION_2LINES;
	SpiHandle.Init.CLKPhase          	= SPI_PHASE_1EDGE;
	SpiHandle.Init.CLKPolarity       	= SPI_POLARITY_HIGH;
	SpiHandle.Init.CRCCalculation    	= SPI_CRCCALCULATION_DISABLE;
	SpiHandle.Init.CRCPolynomial     	= 7;
	SpiHandle.Init.DataSize          	= SPI_DATASIZE_8BIT;
	SpiHandle.Init.FirstBit          	= SPI_FIRSTBIT_MSB;
	SpiHandle.Init.NSS               	= SPI_NSS_HARD_OUTPUT;
	SpiHandle.Init.TIMode            	= SPI_TIMODE_DISABLE;
	SpiHandle.Init.Mode 			 	= SPI_MODE_MASTER;


	if(HAL_SPI_Init(&SpiHandle) != HAL_OK)
	{
	  USART_TRACE("SPI Init error.. память ad45db161d не будет подключена. \n");
	  for(;;){}
	} else
	  USART_TRACE("SPI Init ok. \n");

//  HAL_SPI_TransmitReceive_DMA(&SpiHandle, (uint8_t*)page_Buf_Out, (uint8_t *)page_Buf_In, PAGE_SIZE);

}
//*******************************************************************************
// uint32_t	MEM_ID_Read (void)
// чтение ID памяти
//*******************************************************************************
uint32_t	MEM_ID_Read (void){

	uint8_t 	DataOut = AT45DB_ID_READ , DataIn[4];
	uint32_t	ID;

    MEM_Chipselect(TRUE);
    HAL_SPI_Transmit_DMA(&SpiHandle,(uint8_t*)&DataOut, 1);
    while (HAL_SPI_GetState(&SpiHandle) != HAL_SPI_STATE_READY){}
    HAL_SPI_Receive_DMA(&SpiHandle,(uint8_t*)&DataIn, 4);
	MEM_Chipselect(FALSE);

	ID = (DataIn[0]<<24) + (DataIn[1]<<16) + (DataIn[2]<<8) + DataIn[3];

    return ID;
}
//*******************************************************************************
// void	MEM_Reset (void)
// чтение ID памяти
//*******************************************************************************
void MEM_Reset (void){

}
//*******************************************************************************
// bool Block_memory_read (uint16_t Pageaddress, uint16_t Memaddress, uint8_t *dst, uint16_t Size)
// чтение памяти из банка Pageaddress с начальным адресом байта внутри страницы Memaddress
// после чтения до конца страницы начинает читать с начала тойже страницы.
//*******************************************************************************
int8_t Block_memory_read (uint16_t Pageaddress, uint16_t Memaddress, uint8_t *dst, uint16_t Size){

	return TRUE;
}
//*******************************************************************************
// bool Block_memory_write (uint16_t Pageaddress, uint16_t Memaddress, uint8_t *dst, uint16_t Size)
// запись памяти в банк Pageaddress с начальным адресом байта внутри страницы Memaddress
//*******************************************************************************
int8_t Block_memory_write(uint16_t Pageaddress, uint16_t Memaddress, uint8_t *dst, uint16_t Sizew){

    return TRUE;
}

//*******************************************************************************
// bool Block_memory_write_noWait (uint16_t Pageaddress, uint16_t Memaddress, uint8_t *dst, uint16_t Size)
// запись памяти в банк Pageaddress с начальным адресом байта внутри страницы Memaddress
// без ожидания окончания записи
//*******************************************************************************
int8_t Block_memory_write_noWait(uint16_t Pageaddress, uint16_t Memaddress, uint8_t *dst, uint16_t Size){

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

	MEM_Chipselect(TRUE);
    HAL_SPI_Transmit_DMA(&SpiHandle,(uint8_t*)&DataOut, 4);
	MEM_Chipselect(FALSE);	// нужна пауза 40мс
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

	MEM_Chipselect(TRUE);
    HAL_SPI_Transmit_DMA(&SpiHandle,(uint8_t*)&DataOut, 4);
	MEM_Chipselect(FALSE);
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

	MEM_Chipselect(TRUE);
    HAL_SPI_Transmit_DMA(&SpiHandle,(uint8_t*)&DataOut, 4);
	MEM_Chipselect(FALSE);

	while(!((AT45DB_StatusRegisterRead()>>7) & 1 )){}// подождем пока не прочитает в буфер

//	Delay_mks(400);
}
//*******************************************************************************
// uint8_t AT45DB_StatusRegisterRead(void)
// чтение регистра статуса памяти
//*******************************************************************************
uint8_t AT45DB_StatusRegisterRead(void)
{
	uint8_t 	DataOut = AT45DB_READ_STATE_REGISTER,DataIn;

    MEM_Chipselect(TRUE);
    HAL_SPI_Transmit_DMA(&SpiHandle,(uint8_t*)&DataOut, 1);
    HAL_SPI_Receive_DMA(&SpiHandle,(uint8_t*)&DataIn, 1);
	MEM_Chipselect(FALSE);

    return DataIn;
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

    MEM_Chipselect(TRUE);
    HAL_SPI_Transmit_DMA(&SpiHandle,(uint8_t*)&DataOut, 5);
	MEM_Chipselect(FALSE);
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

    MEM_Chipselect(TRUE);
    HAL_SPI_Transmit_DMA(&SpiHandle,(uint8_t*)&DataOut, 5);
    HAL_SPI_Receive_DMA(&SpiHandle,(uint8_t*)&DataIn, 1);
    MEM_Chipselect(FALSE);

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

    MEM_Chipselect(TRUE);
    HAL_SPI_Transmit_DMA(&SpiHandle,(uint8_t*)&DataOut, 5);
    HAL_SPI_Receive_DMA(&SpiHandle,(uint8_t*)&DataIn, 1);
    MEM_Chipselect(FALSE);

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

    MEM_Chipselect(TRUE);
    HAL_SPI_Transmit_DMA(&SpiHandle,(uint8_t*)&Data,5);
	MEM_Chipselect(FALSE);
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
void MEM_Chipselect(uint8_t select){

}


