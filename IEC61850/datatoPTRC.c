/*
 * datatoPTRC.c
 *
 *  Created on: 20.04.2017
 *      Author: sagok
 */



#include "main.h"
#include "IEC850.h"

#include "iec850.h"
#include "iec61850_server.h"

#if defined (MR801)
#include "static_model_MR801.h"


extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];


/*******************************************************
 * Set_RREC наполняем оперативными данными
 *******************************************************/
void	Set_PTRC	(uint8_t num, uint64_t currentTime )
{
	uint32_t	Mod = 0;

	// Op
	if (ucMDiscInBuf[MB_offset_ErrorOFF] & MB_bOffsetErrorOFF)  Mod = 1;

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op_t, currentTime);
		IedServer_updateQuality(iedServer,&iedModel_PROT_IDDMPDIF_Op_q,QUALITY_VALIDITY_GOOD);
	}


}
#endif




