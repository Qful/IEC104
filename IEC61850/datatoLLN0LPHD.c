/*
 * datatoLLN0LPHD.c
 *
 *  Created on: 20.04.2017
 *      Author: sagok
 */


#include "main.h"
#include "IEC850.h"

#include "iec850.h"
#include "iec61850_server.h"

#include "datatoMMXU.h"

#if defined (MR801)
#include "static_model_MR801.h"
#endif
#if defined (MR901) || defined (MR902)
#include "static_model_MR901_902.h"
#endif
#if defined (MR771)
#include "static_model_MR771.h"
#endif
#if defined (MR761) || defined (MR762) || defined (MR763)
#include "static_model_MR76x.h"
#endif

extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];

/*******************************************************
 * Set_LLN0 наполняем оперативными данными
 *******************************************************/
void	Set_LLN0	(uint8_t num, uint64_t currentTime ){

		uint32_t	LLN0_Health = STVALINT32_OK;

// PROT
		if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule4) || (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5)) {LLN0_Health = STVALINT32_Warning;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_LLN0_Health_stVal, LLN0_Health))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_LLN0_Health_t, currentTime);


}

