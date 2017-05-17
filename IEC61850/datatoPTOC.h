/*
 * datatoPTOC.h
 *
 *  Created on: 18.04.2017
 *      Author: sagok
 */

#ifndef DATATOPTOC_H_
#define DATATOPTOC_H_

#if defined	(MR801)
int16_t		GetDirGeneral	(uint8_t	Currdata);
void		Set_IPTOC		(uint8_t num, uint64_t currentTime );
void		Set_I20PTOC		(uint8_t num, uint64_t currentTime );
void		Set_LZSHPTOC	(uint8_t num, uint64_t currentTime );
#endif

#if defined	(MR771)
void		Set_IPTUC		(uint8_t num, uint64_t currentTime );
void		Set_I2I1PTOC	(uint8_t num, uint64_t currentTime );
void		Set_IPTOC		(uint8_t num, uint64_t currentTime );
void		Set_I20PTOC		(uint8_t num, uint64_t currentTime );

#endif

#endif /* DATATOPTOC_H_ */
