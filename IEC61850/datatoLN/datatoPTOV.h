/*
 * datatoPTOV.h
 *
 *  Created on: 19.04.2017
 *      Author: sagok
 */

#ifndef DATATOPTOV_H_
#define DATATOPTOV_H_

int		Set_UPTOV	(uint16_t QTnum, uint64_t currentTime );	//600	700
int		Set_UPTUV	(uint16_t QTnum, uint64_t currentTime );	//600	700

int		Set_U0PTOV	(uint16_t QTnum, uint64_t currentTime );	//600	700
int		Set_U1PTUV	(uint16_t QTnum, uint64_t currentTime );	//600	---
int		Set_U2PTOV	(uint16_t QTnum, uint64_t currentTime );	//600	700

#endif /* DATATOPTOV_H_ */
