/*
 * datatoGGIO.h
 *
 *  Created on: 19.04.2017
 *      Author: sagok
 */

#ifndef DATATOGGIO_H_
#define DATATOGGIO_H_
/***********************************
 * узел MR76xNxxxGGIO проверен.(Ломан)	-	15.01.2018. - ок.
 *
 ***********************************/
//CTRL
int		Set_XCBRGGIO	(uint16_t QTnum, uint64_t currentTime );

//GGIO
int		Set_INGGIO		(uint16_t QTnum, uint64_t currentTime );
int		Set_OUTGGIO		(uint16_t QTnum, uint64_t currentTime );
int		Set_LEDGGIO		(uint16_t QTnum, uint64_t currentTime );
int		Set_SSLGGIO		(uint16_t QTnum, uint64_t currentTime );
int		Set_VLSGGIO		(uint16_t QTnum, uint64_t currentTime );
int		Set_LSGGIO		(uint16_t QTnum, uint64_t currentTime );

//PROT
int		Set_NBLKGGIO	(uint16_t QTnum, uint64_t currentTime );
int		Set_FLSGGIO		(uint16_t QTnum, uint64_t currentTime );
int		Set_VZGGIO		(uint16_t QTnum, uint64_t currentTime );
int		Set_AVRGGIO		(uint16_t QTnum, uint64_t currentTime );

#endif /* DATATOGGIO_H_ */
