/*
 * datatoSPCS.h
 *
 *  Created on: 30.11.2017
 *      Author: sagok
 */

#ifndef DATATOSPCS_H_
#define DATATOSPCS_H_

int		Set_SPCSO		(uint16_t QTnum, uint64_t currentTime );

void	setControlGGIO2_SPCSOx(IedServer self);
void	controlHandlerFor_CMDGGIO(void* parameter, MmsValue* value, bool test);

#endif /* DATATOSPCS_H_ */
