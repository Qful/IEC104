/**
  ******************************************************************************
  * @file    spi_diskio.c
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include <port.h>
#include <string.h>
#include "ff_gen_drv.h"
#include "libiec61850_platform_includes.h"

#include "ExtSPImem.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

#define SPIFLASH_OK         0x00
#define SPIFLASH_ERROR      0x01

#define SPIFLASH_SECTOR_START 		((uint16_t)2)						// адрес виртуального диска

#define SPIFLASH_DEVICE_ADDR  		((uint32_t)PAGE_SIZE_528 * 2)		// адрес виртуального диска
#define SPIFLASH_DEVICE_SIZE  		(4090) * PAGE_SIZE_512  			//размер диска Kбайт			4095 * 512

/* Block Size in Bytes */
#define SPIFLASH_BLOCK_SIZE     	PAGE_SIZE_512//PAGE_SIZE_512

//void*	SPIFLASH_DEVICE_ADDR;

/* Private variables ---------------------------------------------------------*/
/* Disk status */
static volatile DSTATUS Stat = STA_NOINIT;

/* Private function prototypes -----------------------------------------------*/
DSTATUS SPIFLASHDISK_initialize (void);
DSTATUS SPIFLASHDISK_status (void);
DRESULT SPIFLASHDISK_read (BYTE*, DWORD, UINT);
#if _USE_WRITE == 1
  DRESULT SPIFLASHDISK_write (const BYTE*, DWORD, UINT);
#endif /* _USE_WRITE == 1 */
#if _USE_IOCTL == 1
  DRESULT SPIFLASHDISK_ioctl (BYTE, void*);
#endif /* _USE_IOCTL == 1 */
  
Diskio_drvTypeDef  SPIFLASHDISK_Driver =
{
  SPIFLASHDISK_initialize,
  SPIFLASHDISK_status,
  SPIFLASHDISK_read,
#if  _USE_WRITE == 1
  SPIFLASHDISK_write,
#endif /* _USE_WRITE == 1 */  
#if  _USE_IOCTL == 1
  SPIFLASHDISK_ioctl,
#endif /* _USE_IOCTL == 1 */
};

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Initializes a Drive
  * @param  None
  * @retval DSTATUS: Operation status
  */
DSTATUS SPIFLASHDISK_initialize(void)
{
  Stat = STA_NOINIT;
  
  /* Configure the SRAM device */
//  BSP_SRAM_Init();
  
  // выделим память для диска размером SRAM_DEVICE_SIZE
  //SRAM_DEVICE_ADDR = GLOBAL_MALLOC(SPIFLASH_DEVICE_SIZE);

  Stat &= ~STA_NOINIT;
  return Stat;
}

/**
  * @brief  Gets Disk Status
  * @param  None
  * @retval DSTATUS: Operation status
  */
DSTATUS SPIFLASHDISK_status(void)
{
  Stat = STA_NOINIT;
  
  Stat &= ~STA_NOINIT;

  return Stat;
}

/**
  * @brief  Reads Sector(s) 
  * @param  *buff: Data buffer to store read data
  * @param  sector: Sector address (LBA)						адрес сектора
  * @param  count: Number of sectors to read (1..128)			число секторов
  * @retval DRESULT: Operation result
  *
  * int8_t 		memory_read (uint8_t *dst, uint32_t Addr, uint16_t Size);
  *
  */
DRESULT SPIFLASHDISK_read(BYTE *buff, DWORD sector, UINT count)
{
  int i;
  DRESULT res = RES_ERROR;

 // uint16_t BufferSize = (SPIFLASH_BLOCK_SIZE * count);
 // uint32_t Address = (uint32_t) (SPIFLASH_DEVICE_ADDR + (sector * SPIFLASH_BLOCK_SIZE));
 // USART_TRACE("memory_read. адрес:0x%x размер:%u\n",Address,BufferSize);
 // if (memory_read((uint8_t *)buff,Address,BufferSize) == TRUE)	  res = RES_OK;


//  USART_TRACE("memory_read. сектор:0x%x число секторов:%u\n",sector,count);
  if ( Block_memory_read((uint8_t *)buff,SPIFLASH_SECTOR_START + sector,SPIFLASH_BLOCK_SIZE,count) == TRUE)	  res = RES_OK;

//  for (i=0;i<SPIFLASH_BLOCK_SIZE*count;i++){printf("0x%.2X ",buff[i]);if ((i & 0b1111) == 15) printf("\n");} printf("\n");

  return res;
}

/**
  * @brief  Writes Sector(s)
  * @param  *buff: Data to be written
  * @param  sector: Sector address (LBA)
  * @param  count: Number of sectors to write (1..128)
  * @retval DRESULT: Operation result
  *
  * int8_t 		memory_write (uint8_t *src, uint32_t Addr, uint16_t Size);
  *
  */
#if _USE_WRITE == 1
DRESULT SPIFLASHDISK_write(const BYTE *buff, DWORD sector, UINT count)
{
  int i;
  DRESULT res = RES_ERROR;

//  uint16_t BufferSize = (SPIFLASH_BLOCK_SIZE * count);
//  uint32_t Address = (uint32_t) (SPIFLASH_DEVICE_ADDR + (sector * SPIFLASH_BLOCK_SIZE));
//  USART_TRACE("memory_write. адрес:0x%x размер:%u\n",Address,BufferSize);
//  if (memory_write((uint8_t *)buff,Address,BufferSize) == TRUE)	  res = RES_OK;

//  USART_TRACE("memory_write. сектор:0x%x число секторов:%u\n",sector,count);
//  for (i=0;i<SPIFLASH_BLOCK_SIZE*count;i++){printf("0x%.2X ",buff[i]);if ((i & 0b1111) == 15) printf("\n");} printf("\n");

 if ( Block_memory_write((uint8_t *)buff,SPIFLASH_SECTOR_START + sector,SPIFLASH_BLOCK_SIZE,count) == TRUE)	  res = RES_OK;

 return res;
}
#endif /* _USE_WRITE == 1 */

/**
  * @brief  I/O control operation
  * @param  cmd: Control code
  * @param  *buff: Buffer to send/receive control data
  * @retval DRESULT: Operation result
  */
#if _USE_IOCTL == 1
DRESULT SPIFLASHDISK_ioctl(BYTE cmd, void *buff)
{
  DRESULT res = RES_ERROR;
  
  if (Stat & STA_NOINIT) return RES_NOTRDY;
  
  switch (cmd)
  {
  /* Make sure that no pending write process */
  case CTRL_SYNC :
    res = RES_OK;
    break;
  
  /* Get number of sectors on the disk (DWORD) */
  case GET_SECTOR_COUNT :
    *(DWORD*)buff = SPIFLASH_DEVICE_SIZE / SPIFLASH_BLOCK_SIZE;
    res = RES_OK;
    break;
  
  /* Get R/W sector size (WORD) */
  case GET_SECTOR_SIZE :
    *(WORD*)buff = SPIFLASH_BLOCK_SIZE;
    res = RES_OK;
    break;
  
  /* Get erase block size in unit of sector (DWORD) */
  case GET_BLOCK_SIZE :
    *(DWORD*)buff = SPIFLASH_BLOCK_SIZE;
    break;
  
  default:
    res = RES_PARERR;
  }
  
  return res;
}
#endif /* _USE_IOCTL == 1 */
  
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

