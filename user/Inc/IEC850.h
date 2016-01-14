/*
 * IEC850.h
 *
 *  Created on: 09.12.2015
 *      Author: sagok
 */

#ifndef IEC850_H_
#define IEC850_H_

#include "stack_config.h"

#define RECEIVE_BUF_SIZE 	MMS_MAXIMUM_PDU_SIZE
#define SEND_BUF_SIZE 		MMS_MAXIMUM_PDU_SIZE

#define ISO_CON_STATE_RUNNING 1
#define ISO_CON_STATE_STOPPED 0

void StartIEC850Task(void const * argument);


#endif /* IEC850_H_ */
