/*
 * datatoRREC.c
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
extern uint16_t   ucConfigAPWBuf[MB_NumbConfigAPW];

/*******************************************************
 * Set_RREC наполняем оперативными данными
 *******************************************************/
void	Set_RREC	(uint8_t num, uint64_t currentTime )
{
	//  Mod Beh
				uint32_t	Mod;
				if (ucConfigAPWBuf[MB_offset_ConfAPW] & MB_bOffset_APW_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_RREC_Mod_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_RREC_Mod_t, currentTime);
				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_RREC_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_RREC_Beh_t, currentTime);

	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_RREC_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_RREC_Beh_q,Qual);


	// Op_general
				if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_RREC_Op_general,  ucMDiscInBuf[MB_offset_SW_ON_APW] & MB_b_SW_ON_APW)){
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_RREC_Op_t, currentTime);
					IedServer_updateQuality(iedServer,&iedModel_PROT_RREC_Op_q,0);
				}

}
/*******************************************************
 * Set_RBRF наполняем оперативными данными
 *******************************************************/
void	Set_RBRF	(uint8_t num, uint64_t currentTime )
{
	//Health
				uint32_t	Health = STVALINT32_OK;
				if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule4) || (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5)) {Health = STVALINT32_Warning;}
				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_RBRF_Health_stVal, Health))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_RBRF_Health_t, currentTime);

	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_RBRF_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_RBRF_Beh_q,Qual);


	// OpEx_general
				if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_RBRF_OpEx_general,  ucMDiscInBuf[MB_offset_UROV] & MB_b_Rab_UROV))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_RBRF_OpEx_t, currentTime);

				IedServer_updateQuality(iedServer,&iedModel_PROT_RBRF_OpEx_q,0);

}
#endif

