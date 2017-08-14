/*
 * inflash.c
 *
 *  Created on: 13.01.2017
 *      Author: sagok
 */

#include "stm32f4xx_hal.h"
#include "inflash.h"

/* Private variables ---------------------------------------------------------*/
uint32_t FirstSector = 0;
uint32_t NbOfSectors = 0;
uint32_t SectorError = 0;
uint32_t OB_RDP_LEVEL;
/* Private function prototypes -----------------------------------------------*/
static uint32_t FLASH_GetSectorNumber(uint32_t Address);
static FLASH_OBProgramInitTypeDef FLASH_OBProgramInitStruct;
static FLASH_EraseInitTypeDef FLASH_EraseInitStruct;


/**
  * @brief  Unlocks the Flash to enable the flash control register access.
  * @param  None
  * @retval None
  */
void FLASH_FlashUnlock(void)
{
  HAL_FLASH_Unlock();
}

void FLASH_FlashLock(void)
{
  HAL_FLASH_Lock();
}

/**
  * @brief  Gets Flash readout protection status.
  * @param  None
  * @retval ReadOut protection status
  */
FlagStatus FLASH_ReadOutProtectionStatus(void)
{
  FlagStatus readoutstatus = RESET;

  FLASH_OBProgramInitStruct.RDPLevel = OB_RDP_LEVEL;

  HAL_FLASHEx_OBGetConfig(&FLASH_OBProgramInitStruct);

  if(OB_RDP_LEVEL == SET)
  {
    readoutstatus = SET;
  }
  else
  {
    readoutstatus = RESET;
  }

  return readoutstatus;
}

/**
  * @brief  Erases the required FLASH Sectors.
  * @param  Address: Start address for erasing data
  * @retval 0: Erase sectors done with success
  *         1: Erase error
  */
uint32_t FLASH_EraseSectors(uint32_t Address)
{
  /* Erase the user Flash area
    (area defined by APPLICATION_ADDRESS and USER_FLASH_LAST_PAGE_ADDRESS) ****/

  if(Address <= (uint32_t) USER_FLASH_LAST_PAGE_ADDRESS)
  {
    /* Get the 1st sector to erase */
    FirstSector = FLASH_GetSectorNumber(Address);
    /* Get the number of sector to erase from 1st sector */
    NbOfSectors = FLASH_GetSectorNumber(USER_FLASH_LAST_PAGE_ADDRESS) - FirstSector + 1;

    FLASH_EraseInitStruct.TypeErase = FLASH_TYPEERASE_SECTORS;
    FLASH_EraseInitStruct.Sector = FirstSector;
    FLASH_EraseInitStruct.NbSectors = NbOfSectors;
    FLASH_EraseInitStruct.VoltageRange = FLASH_VOLTAGE_RANGE_3;

    if(HAL_FLASHEx_Erase(&FLASH_EraseInitStruct, &SectorError) != HAL_OK)
      return (1);
  }
  else
  {
    return (1);
  }

  return (0);
}
/**
  * @brief  Writes Data into Memory.
  * @param  src: Pointer to the source buffer. Address to be written to.
  * @param  dest: Pointer to the destination buffer.
  * @param  Len: Number of data to be written (in bytes).
  * @retval 0 if operation is successful, MAL_FAIL else.
  */
uint16_t Flash_Write(uint8_t *src, uint8_t *dest, uint32_t Len)
{
  uint32_t i = 0;

  for(i = 0; i < Len; i+=4)
  {
    /* Device voltage range supposed to be [2.7V to 3.6V], the operation will
       be done by byte */
    if(HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, (uint32_t)(dest+i), *(uint32_t*)(src+i)) == HAL_OK)
    {
     /* Check the written value */
      if(*(uint32_t *)(src + i) != *(uint32_t*)(dest+i))
      {
        /* Flash content doesn't match SRAM content */
        return 2;
      }
    }
    else
    {
      /* Error occurred while writing data in Flash memory */
      return 1;
    }
  }
  return 0;
}

/**
  * @brief  Reads Data into Memory.
  * @param  src: Pointer to the source buffer. Address to be written to.
  * @param  dest: Pointer to the destination buffer.
  * @param  Len: Number of data to be read (in bytes).
  * @retval Pointer to the physical address where data should be read.
  */
uint8_t *Flash_Read(uint8_t *src, uint8_t *dest, uint32_t Len)
{
  uint32_t i = 0;
  uint8_t *psrc = src;

  for(i = 0; i < Len; i++)
  {
    dest[i] = *psrc++;
  }
  /* Return a valid address to avoid HardFault */
  return (uint8_t*)(dest);
}

/**
  * @brief  Demo application for IAP through USB mass storage.
  * @param  None
  * @retval None
  */
void FW_UPGRADE_Process(void)
{
      /* Control BUFFER_SIZE value */
//      USBH_USR_BufferSizeControl();

      /* Writes Flash memory */
//      COMMAND_Download();

      /* Jump to user application code located in the internal Flash memory */
//      COMMAND_Jump();

}

/**
  * @brief  IAP Write Flash memory.
  * @param  None
  * @retval None
  */

/*
void COMMAND_Download(void)
{
  // Open the binary file to be downloaded
  if(f_open(&MyFileR, DOWNLOAD_FILENAME, FA_READ) == FR_OK)
  {
    if(MyFileR.fsize > USER_FLASH_SIZE)
    {
      // No available Flash memory size for the binary file: Turn LED4 On and  Toggle LED3 in infinite loop
      BSP_LED_On(LED4);
      Fail_Handler();
    }
    else
    {
      // Download On Going: Turn LED4 On
      BSP_LED_On(LED4);

      // Erase FLASH sectors to download image
      if(FLASH_If_EraseSectors(APPLICATION_ADDRESS) != 0x00)
      {
        // Flash erase error: Turn LED4 On and Toggle LED2 and LED3 in  infinite loop
        BSP_LED_Off(LED4);
        Erase_Fail_Handler();
      }

      // Program flash memory
      COMMAND_ProgramFlashMemory();

      // Download Done: Turn LED4 Off and LED2 On
      BSP_LED_Off(LED4);
      BSP_LED_On(LED2);

      // Close file
      f_close(&MyFileR);
    }
  }
  else
  {
    // The binary file is not available: Turn LED1, LED2 and LED4 On and Toggle       LED3 in infinite loop
    BSP_LED_On(LED1);
    BSP_LED_On(LED2);
    BSP_LED_On(LED4);
    Fail_Handler();

  }
}
*/

/**
  * @brief  Returns the Flash sector Number of the address
  * @param  None
  * @retval The Flash sector Number of the address
  */
static uint32_t FLASH_GetSectorNumber(uint32_t Address)
{
  uint32_t sector = 0;

  if(Address < ADDR_FLASH_SECTOR_1 && Address >= ADDR_FLASH_SECTOR_0)
  {
    sector = FLASH_SECTOR_0;
  }
  else if(Address < ADDR_FLASH_SECTOR_2 && Address >= ADDR_FLASH_SECTOR_1)
  {
    sector = FLASH_SECTOR_1;
  }
  else if(Address < ADDR_FLASH_SECTOR_3 && Address >= ADDR_FLASH_SECTOR_2)
  {
    sector = FLASH_SECTOR_2;
  }
  else if(Address < ADDR_FLASH_SECTOR_4 && Address >= ADDR_FLASH_SECTOR_3)
  {
    sector = FLASH_SECTOR_3;
  }
  else if(Address < ADDR_FLASH_SECTOR_5 && Address >= ADDR_FLASH_SECTOR_4)
  {
    sector = FLASH_SECTOR_4;
  }
  else if(Address < ADDR_FLASH_SECTOR_6 && Address >= ADDR_FLASH_SECTOR_5)
  {
    sector = FLASH_SECTOR_5;
  }
  else if(Address < ADDR_FLASH_SECTOR_7 && Address >= ADDR_FLASH_SECTOR_6)
  {
    sector = FLASH_SECTOR_6;
  }
  else
  {
    sector = FLASH_SECTOR_7;
  }
  return sector;
}
