/**
  ******************************************************************************
  * @file    sram_diskio.c
  * @author  MCD Application Team
  * @version V1.2.1
  * @date    20-November-2014
  * @brief   SRAM Disk I/O driver
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2014 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include <string.h>
#include "ff_gen_drv.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

// размер блока = 8 страницам
//#define BLOCK_SIZE                 PAGE_SIZE //*8

/* Private variables ---------------------------------------------------------*/
MEMDeviceIDTypeDef 		SPIMemoryID;
//uint16_t				SPIPageSize = PAGE_SIZE_512;					// размер страницы памяти
/* Disk status */
static volatile DSTATUS Stat = STA_NOINIT;

/* Private function prototypes -----------------------------------------------*/
DSTATUS SPIDISK_initialize (void);
DSTATUS SPIDISK_status (void);
DRESULT SPIDISK_read (BYTE*, DWORD, UINT);
#if _USE_WRITE == 1
  DRESULT SPIDISK_write (const BYTE*, DWORD, UINT);
#endif /* _USE_WRITE == 1 */
#if _USE_IOCTL == 1
  DRESULT SPIDISK_ioctl (BYTE, void*);
#endif /* _USE_IOCTL == 1 */
  
Diskio_drvTypeDef  SPIDISK_Driver =
{
		SPIDISK_initialize,
		SPIDISK_status,
		SPIDISK_read,
#if  _USE_WRITE == 1
		SPIDISK_write,
#endif /* _USE_WRITE == 1 */  
#if  _USE_IOCTL == 1
		SPIDISK_ioctl,
#endif /* _USE_IOCTL == 1 */
};

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Initializes a Drive
  * @param  None
  * @retval DSTATUS: Operation status
  */
DSTATUS SPIDISK_initialize(void)
{

  Stat = STA_NOINIT;
  
  /* Configure the SPI device */
  AT45DB161D_spi_init();			// Инит SPI памяти
  MEM_ID_Read(&SPIMemoryID);
  if (AT45DB_StatusRegisterRead() & 1 ) SPIMemoryID.PageSize = PAGE_SIZE_512; else SPIMemoryID.PageSize = PAGE_SIZE_528;
  Stat &= ~STA_NOINIT;
  return Stat;
}

/*************************************************************************
 * SPIDISK_status
 * читаем статус диска
 * и защиту от записи
 * в 0ом бите можно узнать размер страницы. 0 - 512байт ; 1 - 528байт
 *************************************************************************/
DSTATUS SPIDISK_status(void)
{
  Stat = STA_NOINIT;
  uint8_t	statreg;
  
  statreg = AT45DB_StatusRegisterRead();
  if((statreg>>7) & 1)		// проверим RDY флаг
	  Stat &= ~STA_NOINIT;

  if((statreg>>1) & 1)		// проверим защиту от записи
	  Stat &= STA_PROTECT;

  return Stat;
}

/**
  * @brief  Reads Sector(s) 
  * @param  *buff: буфер для сохранения данных
  * @param  sector: номер сектора(512байт) для чтения (LBA)
  * @param  count: количество секторов(512байт) для чтения (1..128)
  * @retval DRESULT: Operation result
  */
DRESULT SPIDISK_read(BYTE *buff, DWORD sector, UINT count)
{
	  DRESULT res = RES_OK;

	  if(!Block_memory_read((uint8_t*)buff,sector ,PAGE_SIZE_512/*SPIMemoryID.PageSize*/,count))
	  //if(BSP_SD_ReadBlocks((uint32_t*)buff, (uint64_t) (sector * BLOCK_SIZE),BLOCK_SIZE, count) != MSD_OK)
	  {
	    res = RES_ERROR;
	  }
	  return res;
}

/**
  * @brief  Writes Sector(s)
  * @param  *buff: Data to be written
  * @param  sector: Sector address (LBA)
  * @param  count: Number of sectors to write (1..128)
  * @retval DRESULT: Operation result
  */
#if _USE_WRITE == 1
DRESULT SPIDISK_write(const BYTE *buff, DWORD sector, UINT count)
{
	  DRESULT res = RES_OK;

	  if(!Block_memory_write((uint8_t*)buff,sector ,PAGE_SIZE_512/*SPIMemoryID.PageSize*/,count))
//	  if(BSP_SD_WriteBlocks((uint32_t*)buff, (uint64_t)(sector * BLOCK_SIZE), BLOCK_SIZE, count) != MSD_OK)
	  {
	    res = RES_ERROR;
	  }
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
DRESULT SPIDISK_ioctl(BYTE cmd, void *buff)
{
  DRESULT res = RES_ERROR;
  
  if (Stat & STA_NOINIT) return RES_NOTRDY;
  
  switch (cmd)
  {
  /* Make sure that no pending write process */
  case CTRL_SYNC :
    res = RES_OK;
    break;
  
  // Get number of sectors on the disk (DWORD)
  // Число секторов на диске
  case GET_SECTOR_COUNT :
    *(DWORD*)buff = 0x40<<SPIMemoryID.DensityCode;//SECTOR_COUNT;//SPI_DEVICE_SIZE/SPIPageSize;				// 4096
    res = RES_OK;
    break;
  
  /* Get R/W sector size (WORD) */
  case GET_SECTOR_SIZE :
    *(WORD*)buff = PAGE_SIZE_512/*SPIMemoryID.PageSize*/;								// пишем блоками по 512
    res = RES_OK;
    break;
  
  /* Get erase block size in unit of sector (DWORD) */
  case GET_BLOCK_SIZE :
    *(DWORD*)buff = PAGE_SIZE_512/*SPIMemoryID.PageSize*/;								// стирать можно и странично=512, блочно=4096, секторами=128Kbyte
    break;
  
  default:
    res = RES_PARERR;
  }
  
  return res;
}
#endif /* _USE_IOCTL == 1 */
  
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

