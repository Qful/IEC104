/*
 * PrpHsr_value.h
 *
 *  Created on: 15.12.2017
 *      Author: sagok
 */

#ifndef PRPHSR_VALUE_H_
#define PRPHSR_VALUE_H_

#include "linked_list.h"
#include "mms_value.h"

#include "asm/types.h"
//#include "goose_publisher.h"

#ifdef __cplusplus
extern "C" {
#endif

#define 	LAN_Addr_0		0xA0
#define 	LAN_Addr_1		0xB0

//#define UsePRP
//#define UseHSR

#if defined (UsePRP)
typedef struct sPRPParameters {	// последовательность как в пакете
    uint16_t 	prpSeqNum;
    uint8_t 	prpIdNet;
    uint16_t 	prpIdSize;
    uint16_t 	prpHead;
} PRPParameters;
#endif

#if defined (UseHSR)
typedef struct sHSRParameters {	// последовательность как в пакете
    uint16_t 	hsrHead;
    uint8_t 	hsrIdNet;
    uint16_t 	hsrSize;
    uint16_t 	hsrSeqNum;
} HSRParameters;
#endif

#define 	PRPsuffix	0x88FB
#define 	HSRsuffix	0x892F

#define 	_Addr_hsrSeqNum			12+2+2
#define 	_Addr_hsrSize			12+2
#define 	_Addr_IdNet				12+2

#define 	_Addr_IdNetPRP			-4			// смещение от конца


#ifdef __cplusplus
}
#endif


#endif /* PRPHSR_VALUE_H_ */
