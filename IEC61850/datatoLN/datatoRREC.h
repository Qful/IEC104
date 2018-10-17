/*
 * datatoRREC.h
 *
 *  Created on: 20.04.2017
 *      Author: sagok
 */

#ifndef DATATORREC_H_
#define DATATORREC_H_

int		Set_RREC	(uint16_t QTnum, uint64_t currentTime );
int		Set_FRREC	(uint16_t QTnum, uint64_t currentTime );
int		Set_RBRF	(uint16_t QTnum, uint64_t currentTime );
int		Set_RSYN	(uint16_t QTnum, uint64_t currentTime );
int		Set_RPSB	(uint16_t QTnum, uint64_t currentTime );

#endif /* DATATORREC_H_ */
