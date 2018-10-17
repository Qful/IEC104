/*
 * datatoPTOC.h
 *
 *  Created on: 18.04.2017
 *      Author: sagok
 */

#ifndef DATATOPTOC_H_
#define DATATOPTOC_H_

int16_t		GetDirGeneral(uint8_t	Currdata);

int			Set_IPTOC		(uint16_t QTnum, uint64_t currentTime );
int			Set_IPTUC		(uint16_t QTnum, uint64_t currentTime );
int			Set_I2PTOC		(uint16_t QTnum, uint64_t currentTime );
int			Set_I0PTOC		(uint16_t QTnum, uint64_t currentTime );
int			Set_I20PTOC		(uint16_t QTnum, uint64_t currentTime );
int			Set_INPTOC		(uint16_t QTnum, uint64_t currentTime );
int			Set_IGPTOC		(uint16_t QTnum, uint64_t currentTime );
int			Set_I2I1PTOC	(uint16_t QTnum, uint64_t currentTime );
int			Set_LZSHPTOC	(uint16_t QTnum, uint64_t currentTime );
int			Set_IARCPTOC	(uint16_t QTnum, uint64_t currentTime );


#endif /* DATATOPTOC_H_ */
