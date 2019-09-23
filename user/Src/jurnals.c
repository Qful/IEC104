/*
 * jurnals.c
 *
 *  Created on: 20.10.2017
 *      Author: sagok
 */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"
#include "queue.h"
#include "signal.h"

#include "stm32f4xx_hal.h"

#include "main.h"
#include "time.h"
#include "stdlib.h"
#include "string.h"

#include "jurnals.h"


extern uint16_t   usErrorNoteStart;
extern uint16_t   usSysNoteStart;
extern uint16_t   usWrSysNoteStart;

extern uint16_t	GlobalAddrSysNote;
extern uint16_t	GlobalAddrErrorNote;
extern uint16_t	GlobalAddrOscNote;
/***********************************************************************
 * ResetAddrSysNote
 * обнулим указатель и число новых записей
 ***********************************************************************/
void	ResetAddrSysNote(){
#if defined (MR5_500) || defined (MR5_600) || defined (MR5_700) || defined (MR741)
	usSysNoteStart = MB_Addr_SysNote;
	GlobalAddrSysNote = 0;
#endif
}
void	ResetAddrErrorNote(){
#if defined (MR5_500) || defined (MR5_600) || defined (MR5_700) || defined (MR741)
	usErrorNoteStart = MB_Addr_ErrorNote;
	GlobalAddrErrorNote = 0;
#endif

}
/***********************************************************************
 * SeekChangeUstavki
 * проверка записи в журнале на изменение уставок
 * numb - число байт
 ***********************************************************************/
int		SeekChangeUstavki( uint8_t* Data, uint16_t numb){

int			ret = 0;
uint16_t	codeMessage;


#if defined (MR5_500) || defined (MR5_600) || defined (MR5_700) || defined (MR741)

codeMessage = (uint16_t)Data[0] | (uint16_t)Data[1]<<8;

	switch(codeMessage){
		case 	MJ_MENU_USTAVKI_CHANGE:
		case	MJ_GROUPE_USTAVKI_CHANGE:
		case	MJ_SDTU_USTAVKI_CHANGE:
			ret = 1;
			break;

		default:
			ret = 0;
			break;
	}
#endif
/***********************************************************************************
 * MR771 MR761 MR762 MR763
 ***********************************************************************************/
#if defined (MR771) || defined (MR761) || defined (MR762) || defined (MR763) || defined (MR761OBR)

codeMessage = (uint16_t)Data[MB_OffsetSysNoteMessage*2] | (uint16_t)Data[MB_OffsetSysNoteMessage*2 + 1]<<8;

	switch(codeMessage){
		case	MJ_USTAVKI_CHANGE:
		case 	MJ_MENU_USTAVKI_CHANGE:
		case	MJ_GROUPE_USTAVKI_CHANGE:
		case	MJ_SDTU_USTAVKI_CHANGE:
			ret = 1;
			break;

		default:
			ret = 0;
			break;
	}

#endif


return	ret;
}


