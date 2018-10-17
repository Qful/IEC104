/*
 * datatoPDPR.c
 *
 *  Created on: 29.05.2017
 *      Author: sagok
 */


#include "main.h"
#include "IEC850.h"

#include "iec850.h"
#include "iec61850_server.h"

#include "datatoPDPR.h"

/*******************************************************
 * MR771 MR761 MR762 MR763
 *******************************************************/
#if defined	(MR761) || defined	(MR762) || defined	(MR763)
#include "static_model_MR76x.h"


extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
extern uint16_t   ucMUstavkiInBuf[MB_NumbUstavki];

/*******************************************************
 * Set_PDPR наполняем оперативными данными
 *******************************************************/
int		Set_PDPR	(uint16_t QTnum, uint64_t currentTime )
{
	//Health
				uint32_t	Health = STVALINT32_OK;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5) {Health = STVALINT32_Warning;}
				if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {Health = STVALINT32_Warning;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDPR1_Health_stVal, Health)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PDPR1_Health_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDPR2_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PDPR2_Health_t, currentTime);
				}

	//  Mod Beh
				uint32_t	Mod;
				if ((ucMUstavkiInBuf[MB_offset_P_1 + MB_offset_P_Config] & MB_bOffset_P_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDPR1_Mod_stVal, Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PDPR1_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDPR1_Beh_stVal, Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PDPR1_Beh_t, currentTime);
				}

				if ((ucMUstavkiInBuf[MB_offset_P_2 + MB_offset_P_Config] & MB_bOffset_P_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDPR2_Mod_stVal, Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PDPR2_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDPR2_Beh_stVal, Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PDPR2_Beh_t, currentTime);
				}


	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_PDPR1_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PDPR1_Beh_q,Qual);
				//IedServer_updateQuality(iedServer,&iedModel_PROT_PDPR1_Health_q,Qual);

				IedServer_updateQuality(iedServer,&iedModel_PROT_PDPR2_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PDPR2_Beh_q,Qual);
				//IedServer_updateQuality(iedServer,&iedModel_PROT_PDPR2_Health_q,Qual);

	// Str_general
				bool	Str_general;
				if (ucMDiscInBuf[MB_IO_offsetP_1] & MB_P1_IO) Str_general = true; else Str_general = false;
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PDPR1_Str_general,  Str_general) > 0)			// И0 P>1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PDPR1_Str_t, currentTime);

				if (ucMDiscInBuf[MB_IO_offsetP_2] & MB_P2_IO) Str_general = true; else Str_general = false;
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PDPR2_Str_general,  Str_general) > 0)			// И0 P>2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PDPR2_Str_t, currentTime);

	// Op_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PDPR1_Op_general,  ucMDiscInBuf[MB_IO_offsetP_1] & MB_P1) > 0)
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PDPR1_Op_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PDPR2_Op_general,  ucMDiscInBuf[MB_IO_offsetP_2] & MB_P2) > 0)
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PDPR2_Op_t, currentTime);


				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDPR1_Str_dirGeneral, 0)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PDPR1_Str_t, currentTime);
					if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PDPR2_Str_dirGeneral, 0))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PDPR2_Str_t, currentTime);
				}

				Quality quality = QUALITY_VALIDITY_GOOD;
				if (Health == STVALINT32_Warning){
					quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
				}
				IedServer_updateQuality(iedServer,&iedModel_PROT_PDPR1_Str_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PDPR1_Op_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PDPR2_Str_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PDPR2_Op_q,quality);

}
#else
/*******************************************************
 * заглушки
 *******************************************************/
int	Set_PDPR	(uint16_t QTnum, uint64_t currentTime ){return false;}

#endif

