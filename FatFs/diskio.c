/*-----------------------------------------------------------------------*/
/* Low level disk I/O module skeleton for FatFs     (C)ChaN, 2013        */
/*                                                                       */
/*   Portions COPYRIGHT 2014 STMicroelectronics                          */
/*   Portions Copyright (C) 2012, ChaN, all right reserved               */
/*-----------------------------------------------------------------------*/
/* If a working storage control module is available, it should be        */
/* attached to the FatFs via a glue function rather than modifying it.   */
/* This is an example of glue functions to attach various exsisting      */
/* storage control module to the FatFs module with a defined API.        */
/*-----------------------------------------------------------------------*/

/**
  ******************************************************************************
  * @file    diskio.c 
  * @author  MCD Application Team
  * @version V1.2.1
  * @date    20-November-2014
  * @brief   FatFs low level disk I/O module.
  ******************************************************************************
  * @attention
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
#include "diskio.h"
#include "ff_gen_drv.h"

#include "stm32f4xx_hal.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
extern Disk_drvTypeDef  disk;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Initializes a Drive
  * @param  pdrv: Physical drive number (0..)
  * @retval DSTATUS: Operation status
  */
DSTATUS disk_initialize(BYTE pdrv)
{
  DSTATUS stat = RES_OK;
  
  if(disk.is_initialized[pdrv] == 0)
  { 
    disk.is_initialized[pdrv] = 1;
    stat = disk.drv[pdrv]->disk_initialize();
  }
  return stat;
}

/**
  * @brief  Gets Disk Status 
  * @param  pdrv: Physical drive number (0..)
  * @retval DSTATUS: Operation status
  */
DSTATUS disk_status(BYTE pdrv)
{
  DSTATUS stat;
  
  stat = disk.drv[pdrv]->disk_status();
  return stat;
}

/**
  * @brief  Reads Sector(s) 
  * @param  pdrv: Physical drive number (0..)
  * @param  *buff: Data buffer to store read data
  * @param  sector: Sector address (LBA)
  * @param  count: Number of sectors to read (1..128)
  * @retval DRESULT: Operation result
  */
DRESULT disk_read(BYTE pdrv, BYTE *buff, DWORD sector, UINT count)
{
  DRESULT res;
 
  res = disk.drv[pdrv]->disk_read(buff, sector, count);
  return res;
}

/**
  * @brief  Writes Sector(s)  
  * @param  pdrv: Physical drive number (0..)
  * @param  *buff: Data to be written
  * @param  sector: Sector address (LBA)
  * @param  count: Number of sectors to write (1..128)
  * @retval DRESULT: Operation result
  */
#if _USE_WRITE == 1
DRESULT disk_write(BYTE pdrv, const BYTE *buff, DWORD sector, UINT count)
{
  DRESULT res;
  
  res = disk.drv[pdrv]->disk_write(buff, sector, count);
  return res;
}
#endif /* _USE_WRITE == 1 */

/**
  * @brief  I/O control operation  
  * @param  pdrv: Physical drive number (0..)
  * @param  cmd: Control code
  * @param  *buff: Buffer to send/receive control data
  * @retval DRESULT: Operation result
  */
#if _USE_IOCTL == 1
DRESULT disk_ioctl(BYTE pdrv, BYTE cmd, void *buff)
{
  DRESULT res;

  res = disk.drv[pdrv]->disk_ioctl(cmd, buff);
  return res;
}
#endif /* _USE_IOCTL == 1 */

/**
  * @brief  Gets Time from RTC 
  * @param  None
  * @retval Time in DWORD
  *
 * информаци€ о файле, размер и врем€ изменени€
 *
 * биты 0Ч4 Ч счЄтчик секунд (по две), допустимы значени€ 0Ч29, то есть 0Ч58 секунд;
 * биты 5Ч10 Ч минуты, допустимы значени€ 0Ч59;
 * биты 11Ч15 Ч часы, допустимы значени€ 0Ч23.
  *
  */
DWORD get_fattime (void)
{
	RTC_TimeTypeDef sTime;
	DWORD	sectmp=0;

	extern 	RTC_HandleTypeDef hrtc;

	HAL_RTC_GetTime(&hrtc, &sTime, 0);			// „итаем врем€

	 sectmp |= (DWORD)sTime.Seconds/2;
	 sectmp |= (DWORD)sTime.Minutes<<5;
	 sectmp |= (DWORD)sTime.Hours<<11;

	return	sectmp;

}
/**
* ƒвухбайтова€ отметка даты имеет следующий формат:
* биты 0Ч4 Ч день мес€ца, допускаютс€ значени€ 1Ч31;
* биты 5Ч8 Ч мес€ц года, допускаютс€ значени€ 1Ч12;
* биты 9Ч15 Ч год, счита€ от 1980 года (Ђэпоха MS-DOSї), возможны значени€ от 0 до 127 включительно, то есть 1980Ч2107 годы.
*
* ƒва байта, отвечающие отметке времени, распредел€ютс€ так:
* биты 0Ч4 Ч счЄтчик секунд (по две), допустимы значени€ 0Ч29, то есть 0Ч58 секунд;
* биты 5Ч10 Ч минуты, допустимы значени€ 0Ч59;
* биты 11Ч15 Ч часы, допустимы значени€ 0Ч23.
*/

DWORD get_fatdate (void)
{
	RTC_DateTypeDef sDate;
	DWORD	sectmp=0;

	extern 	RTC_HandleTypeDef hrtc;

	HAL_RTC_GetDate(&hrtc, &sDate, 0);			// „итаем врем€

	 sectmp |= (DWORD)sDate.Date;
	 sectmp |= (DWORD)(sDate.Month)<<5;
	 sectmp |= (DWORD)(sDate.Year)<<9;

	return	sectmp;
}

FRESULT set_timestampFile (char *obj, int year, int month, int mday, int hour, int min, int sec)
{
    FILINFO fno;
//    fno.fdate = (WORD)((year * 512U) | month * 32U | (mday+1));
    fno.fdate = ((WORD)(year * 512U) & 0b1111111000000000) | (WORD)((month * 32U) & 0b111100000) | (WORD)((mday)&0b11111);
    fno.ftime = (WORD)(hour * 2048U | min * 32U | sec / 2U);
    return f_utime(obj, &fno);
}
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

