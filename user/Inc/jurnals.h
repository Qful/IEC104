/*
 * jurnals.h
 *
 *  Created on: 20.10.2017
 *      Author: sagok
 */

#ifndef JURNALS_H_
#define JURNALS_H_


#if defined (MR5_500) || defined (MR5_600) || defined (MR5_700) || defined (MR741)

#define MJ_MENU_USTAVKI_CHANGE		((uint16_t)25)
#define MJ_GROUPE_USTAVKI_CHANGE	((uint16_t)31)
#define MJ_SDTU_USTAVKI_CHANGE		((uint16_t)32)

#endif

#if defined (MR771) || defined (MR761) || defined (MR762) || defined (MR763) || defined (MR761OBR)

#define MJ_USTAVKI_CHANGE			((uint16_t)03)
#define MJ_MENU_USTAVKI_CHANGE		((uint16_t)27)
#define MJ_GROUPE_USTAVKI_CHANGE	((uint16_t)45)
#define MJ_SDTU_USTAVKI_CHANGE		((uint16_t)28)

#endif

void	ResetAddrSysNote();
void	ResetAddrErrorNote();
int		SeekChangeUstavki( uint8_t* Data, uint16_t numb);		// проверка записи в журнале на изменение уставок

#endif /* JURNALS_H_ */
