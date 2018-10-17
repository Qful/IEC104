/*
 * datatoPDIF.h
 *
 *  Created on: 19.04.2017
 *      Author: sagok
 */

#ifndef DATATOPDIF_H_
#define DATATOPDIF_H_

int		Set_IDPDIF		(uint16_t QTnum, uint64_t currentTime );
int		Set_ID0PDIF		(uint16_t QTnum, uint64_t currentTime );
int		Set_IDDPDIF		(uint16_t QTnum, uint64_t currentTime );
int		Set_IDDMPDIF	(uint16_t QTnum, uint64_t currentTime );
int		Set_IDMPDIF		(uint16_t QTnum, uint64_t currentTime );

#endif /* DATATOPDIF_H_ */
