/*
 * datatoPTOC.h
 *
 *  Created on: 18.04.2017
 *      Author: sagok
 */

#ifndef DATATOPTOC_H_
#define DATATOPTOC_H_

int16_t		GetDirGeneral(uint8_t	Currdata);

#if defined	(MR901) || defined	(MR902)
void		Set_IPTOC		(uint8_t num, uint64_t currentTime );
#endif
#if defined	(MR801)
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

#if defined	(MR761) || defined	(MR762) || defined	(MR763)
void		Set_IPTUC		(uint8_t num, uint64_t currentTime );
void		Set_I2I1PTOC	(uint8_t num, uint64_t currentTime );
void		Set_IPTOC		(uint8_t num, uint64_t currentTime );
void		Set_I20PTOC		(uint8_t num, uint64_t currentTime );
void		Set_IARCPTOC	(uint8_t num, uint64_t currentTime );
#endif

#if defined	(MR5_700)
void		Set_IPTOC		(uint8_t num, uint64_t currentTime );
void		Set_LZSHPTOC	(uint8_t num, uint64_t currentTime );
void		Set_I2I1PTOC	(uint8_t num, uint64_t currentTime );
void		Set_I2PTOC		(uint8_t num, uint64_t currentTime );
void		Set_I0PTOC		(uint8_t num, uint64_t currentTime );
void		Set_INPTOC		(uint8_t num, uint64_t currentTime );
void		Set_IGPTOC		(uint8_t num, uint64_t currentTime );

#endif

#endif /* DATATOPTOC_H_ */
