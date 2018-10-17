/*
 * datatoCSWI.h
 *
 *  Created on: 20.04.2017
 *      Author: sagok
 */

#ifndef DATATOCSWI_H_
#define DATATOCSWI_H_

/***********************************
 * узел MR76xNxxxCTRL
 * 		CSWI проверен.(Ломан)	-	16.01.2018. - ок.
 *
 ***********************************/

int		Set_CSWI	(uint16_t QTnum, uint64_t currentTime );
int		Set_XCBR	(uint16_t QTnum, uint64_t currentTime );


#endif /* DATATOCSWI_H_ */
