/*
 * ExtSPImem.h
 *
 *  Created on: 27.04.2016
 *      Author: sagok
 */

#ifndef EXTSPIMEM_H_
#define EXTSPIMEM_H_


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define PAGE_SIZE_512							0x200	//0x200			//512
#define PAGE_SIZE_528							0x210	//0x210			//528


#define	SPI_DEVICE_SIZE							4096 * PAGE_SIZE_528
//#define	SECTOR_COUNT							4096				= 0x40<<SPIMemoryID.DensityCode;

#define AT45DB_BUFFER_1_WRITE                 	0x84    // Buffer 1 Write
#define AT45DB_BUFFER_2_WRITE                 	0x87    // Buffer 2 Write
#define AT45DB_BUFFER_1_READ                  	0xD4    // Buffer 1 Read
#define AT45DB_BUFFER_2_READ                  	0xD6    // Buffer 2 Read
#define AT45DB_B1_TO_MM_PAGE_PROG_WITH_ERASE  	0x83    // Buffer 1 to Main Memory Page Program with Built-in Erase
#define AT45DB_B2_TO_MM_PAGE_PROG_WITH_ERASE  	0x86    // Buffer 2 to Main Memory Page Program with Built-in Erase
#define AT45DB_MM_PAGE_TO_B1_XFER             	0x53    // Main Memory Page to Buffer 1 Transfer
#define AT45DB_MM_PAGE_TO_B2_XFER             	0x55    // Main Memory Page to Buffer 2 Transfer
#define AT45DB_PAGE_ERASE                     	0x81    // Page Erase
#define AT45DB_SECTOR_ERASE                   	0x7C    // Sector Erase
#define AT45DB_READ_STATE_REGISTER            	0xD7	// чтение регистра статуса
#define AT45DB_MM_PAGE_READ                   	0xD2    // Main Memory Page Read
#define AT45DB_MM_PAGE_PROG_THRU_BUFFER1      	0x82  	// Main Memory Page Program Through Buffer 1
#define AT45DB_ID_READ            			  	0x9F	// чтение ID


/* Definition for SPIx clock resources */
#define SPIx                             SPI1
#define SPIx_CLK_ENABLE()                __HAL_RCC_SPI1_CLK_ENABLE()
#define DMAx_CLK_ENABLE()                __HAL_RCC_DMA2_CLK_ENABLE()
#define SPIx_SCK_GPIO_CLK_ENABLE()       __HAL_RCC_GPIOA_CLK_ENABLE()
#define SPIx_MISO_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOA_CLK_ENABLE()
#define SPIx_MOSI_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOB_CLK_ENABLE()

//#define SPIx_CS_GPIO_CLK_ENABLE()       __HAL_RCC_GPIOA_CLK_ENABLE()


/* Definition for SPIx's DMA */
#define SPIx_TX_DMA_CHANNEL              DMA_CHANNEL_3
#define SPIx_TX_DMA_STREAM               DMA2_Stream3
#define SPIx_RX_DMA_CHANNEL              DMA_CHANNEL_3
#define SPIx_RX_DMA_STREAM               DMA2_Stream0

/* Definition for SPIx's NVIC */
#define SPIx_DMA_TX_IRQn                 DMA2_Stream3_IRQn
#define SPIx_DMA_RX_IRQn                 DMA2_Stream0_IRQn
#define SPIx_DMA_TX_IRQHandler           DMA2_Stream3_IRQHandler
#define SPIx_DMA_RX_IRQHandler           DMA2_Stream0_IRQHandler



typedef struct
{
  uint8_t 	ManufacturerID;				// Manufacturer ID 1FH = Atmel
  uint8_t 	FamilyCode;					// Family Code 001 = DataFlash
  uint8_t 	DensityCode;				// Density Code 00110 = 16-Mbit
  uint8_t 	MLCCode;					// MLC Code 000 = 1-bit/Cell Technology
  uint8_t 	ProductVersionCode;			// Product Version 00000 = Initial Version
  uint8_t	ByteCount;					// Byte Count 00H = 0 Bytes of Information
  uint16_t	PageSize;					// размер страницы

}MEMDeviceIDTypeDef;

#include "stm32f4xx_hal_gpio.h"

void 		AT45DB161D_spi_init(void);
int8_t		MEM_ID_Read (MEMDeviceIDTypeDef *IDInfo );
void 		MEM_Reset (void);

int8_t 		memory_write_to_mem (uint8_t *src, uint32_t Addr, uint16_t Size);			// запись прямо в память

int8_t 		memory_read (uint8_t *dst, uint32_t Addr, uint16_t Size);
int8_t 		memory_write (uint8_t *src, uint32_t Addr, uint16_t Size);					// запись в буфер до заполнения его. После этого в память.

int8_t 		Page_memory_read(uint8_t *dst, uint16_t PageAddr, uint16_t PageSize);
int8_t 		Block_memory_read(uint8_t *dst, uint16_t PageAddr, uint16_t PageSize,  uint16_t NumberOfPages);

int8_t 		Page_memory_write(uint8_t *src, uint16_t PageAddr, uint16_t PageSize);
int8_t 		Block_memory_write(uint8_t *src, uint16_t PageAddr, uint16_t PageSize,  uint16_t NumberOfPages);

int8_t 		Block_memory_write_noWait(uint16_t Pageaddress, uint16_t Memaddress, uint8_t *dst, uint16_t Size);
int8_t 		Bufer2_to_memory_write(uint16_t Pageaddress);

void 		memory_to_buffer1_transfer (uint16_t page);
void 		memory_to_buffer2_transfer (uint16_t page);
uint8_t 	AT45DB_StatusRegisterRead(void);
void 		AT45DB_buffer1_write(uint16_t addres,uint8_t data );
uint8_t 	AT45DB_buffer1_read(uint16_t addres );
uint8_t 	AT45DB_buffer2_read(uint16_t addres );
void 		AT45DB_buffer1_to_memory(uint16_t addres);

void 		SPI_HostWriteByte(uint8_t Data);
uint8_t 	SPI_HostReadByte(void);
uint8_t 	SPI_STATEREGISTERRead(void);
void 		MEM_Chipselect(GPIO_PinState select);



#endif /* EXTSPIMEM_H_ */
