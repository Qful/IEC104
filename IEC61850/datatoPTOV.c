/*
 * datatoPTOV.c
 *
 *  Created on: 19.04.2017
 *      Author: sagok
 */
#include "main.h"
#include "IEC850.h"

#include "iec850.h"
#include "iec61850_server.h"

#if defined (MR801)
#include "static_model_MR801.h"


extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucMUstavkiInBuf[MB_NumbUstavki];




/*******************************************************
 * Set_UPTOV наполняем оперативными данными
 *******************************************************/
void	Set_UPTOV	(uint8_t num, uint64_t currentTime )
{
	//Health
				uint32_t	Health = STVALINT32_OK;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5) {Health = STVALINT32_Warning;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTOV1_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTOV1_Health_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTOV2_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTOV2_Health_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTOV3_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTOV3_Health_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTOV4_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTOV4_Health_t, currentTime);

	//  Mod Beh
				uint32_t	Mod;
				if (ucMUstavkiInBuf[MB_offset_Uup_U1 + MB_offset_Uup_U_Config] & MB_bOffset_Uup_U_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTOV1_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTOV1_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTOV1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTOV1_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Uup_U2 + MB_offset_Uup_U_Config] & MB_bOffset_Uup_U_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTOV2_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTOV2_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTOV2_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTOV2_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Uup_U3 + MB_offset_Uup_U_Config] & MB_bOffset_Uup_U_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTOV3_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTOV3_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTOV3_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTOV3_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Uup_U4 + MB_offset_Uup_U_Config] & MB_bOffset_Uup_U_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTOV4_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTOV4_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTOV4_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTOV4_Beh_t, currentTime);

	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTOV1_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTOV1_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTOV1_Health_q,Qual);

				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTOV2_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTOV2_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTOV2_Health_q,Qual);

				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTOV3_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTOV3_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTOV3_Health_q,Qual);

				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTOV4_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTOV4_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTOV4_Health_q,Qual);




	// Str_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTOV1_Str_general,  ucMDiscInBuf[MB_offset_IO_Uup_1] & MB_b_IO_Uup1) > 0)			// И0 U>1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTOV1_Str_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTOV2_Str_general,  ucMDiscInBuf[MB_offset_IO_Uup_2] & MB_b_IO_Uup2) > 0)			// И0 U>2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTOV2_Str_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTOV3_Str_general,  ucMDiscInBuf[MB_offset_IO_Uup_3] & MB_b_IO_Uup3) > 0)			// И0 U>3
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTOV3_Str_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTOV4_Str_general,  ucMDiscInBuf[MB_offset_IO_Uup_4] & MB_b_IO_Uup4) > 0)			// И0 U>4
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTOV4_Str_t, currentTime);

	// Op_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTOV1_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Uup_1] & MB_b_SRAB_Uup1) > 0)		// СРАБ U>1
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTOV1_Op_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTOV2_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Uup_2] & MB_b_SRAB_Uup2) > 0)		// СРАБ U>2
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTOV2_Op_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTOV3_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Uup_3] & MB_b_SRAB_Uup3) > 0)		// СРАБ U>3
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTOV3_Op_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTOV4_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Uup_4] & MB_b_SRAB_Uup4) > 0)		// СРАБ U>4
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTOV4_Op_t, currentTime);


	// Str_dir_general не меняется
				/*
				MmsValue* 	ValMMS;
				uint8_t		Dir = 3;
				ValMMS = MmsValue_newIntegerFromInt16(Dir);
				IedServer_updateAttributeValue(iedServer, &iedModel_PROT_UPTOV1_Str_dirGeneral, ValMMS);
				IedServer_updateAttributeValue(iedServer, &iedModel_PROT_UPTOV2_Str_dirGeneral, ValMMS);
				IedServer_updateAttributeValue(iedServer, &iedModel_PROT_UPTOV3_Str_dirGeneral, ValMMS);
				IedServer_updateAttributeValue(iedServer, &iedModel_PROT_UPTOV4_Str_dirGeneral, ValMMS);
				MmsValue_delete(ValMMS);
				*/


				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTOV1_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTOV1_Str_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTOV2_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTOV2_Str_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTOV3_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTOV3_Str_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTOV4_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTOV4_Str_q,0);

}
/*******************************************************
 * Set_UPTUV наполняем оперативными данными
 *******************************************************/
void	Set_UPTUV	(uint8_t num, uint64_t currentTime )
{
	//Health
				uint32_t	Health = STVALINT32_OK;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5) {Health = STVALINT32_Warning;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTUV1_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTUV1_Health_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTUV2_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTUV2_Health_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTUV3_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTUV3_Health_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTUV4_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTUV4_Health_t, currentTime);

	//  Mod Beh
				uint32_t	Mod;
				if (ucMUstavkiInBuf[MB_offset_Udn_U1 + MB_offset_Udn_U_Config] & MB_bOffset_Udn_U_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTUV1_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTUV1_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTUV1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTUV1_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Udn_U2 + MB_offset_Udn_U_Config] & MB_bOffset_Udn_U_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTUV2_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTUV2_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTUV2_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTUV2_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Udn_U3 + MB_offset_Udn_U_Config] & MB_bOffset_Udn_U_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTUV3_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTUV3_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTUV3_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTUV3_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Udn_U4 + MB_offset_Udn_U_Config] & MB_bOffset_Udn_U_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTUV4_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTUV4_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTUV4_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTUV4_Beh_t, currentTime);

	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTUV1_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTUV1_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTUV1_Health_q,Qual);

				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTUV2_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTUV2_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTUV2_Health_q,Qual);

				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTUV3_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTUV3_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTUV3_Health_q,Qual);

				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTUV4_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTUV4_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTUV4_Health_q,Qual);


	// Str_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTUV1_Str_general,  ucMDiscInBuf[MB_offset_IO_Udn_1] & MB_b_IO_Udn1) > 0)			// И0 U>1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTUV1_Str_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTUV2_Str_general,  ucMDiscInBuf[MB_offset_IO_Udn_2] & MB_b_IO_Udn2) > 0)			// И0 U>2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTUV2_Str_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTUV3_Str_general,  ucMDiscInBuf[MB_offset_IO_Udn_3] & MB_b_IO_Udn3) > 0)			// И0 U>3
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTUV3_Str_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTUV4_Str_general,  ucMDiscInBuf[MB_offset_IO_Udn_4] & MB_b_IO_Udn4) > 0)			// И0 U>4
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTUV4_Str_t, currentTime);

	// Op_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTUV1_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Udn_1] & MB_b_SRAB_Udn1) > 0)		// СРАБ U>1
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTUV1_Op_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTUV2_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Udn_2] & MB_b_SRAB_Udn2) > 0)		// СРАБ U>2
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTUV2_Op_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTUV3_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Udn_3] & MB_b_SRAB_Udn3) > 0)		// СРАБ U>3
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTUV3_Op_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTUV4_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Udn_4] & MB_b_SRAB_Udn4) > 0)		// СРАБ U>4
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTUV4_Op_t, currentTime);


	// Str_dir_general не меняется
				/*
				MmsValue* 	ValMMS;
				uint8_t		Dir = 3;
				ValMMS = MmsValue_newIntegerFromInt16(Dir);
				IedServer_updateAttributeValue(iedServer, &iedModel_PROT_UPTUV1_Str_dirGeneral, ValMMS);
				IedServer_updateAttributeValue(iedServer, &iedModel_PROT_UPTUV2_Str_dirGeneral, ValMMS);
				IedServer_updateAttributeValue(iedServer, &iedModel_PROT_UPTUV3_Str_dirGeneral, ValMMS);
				IedServer_updateAttributeValue(iedServer, &iedModel_PROT_UPTUV4_Str_dirGeneral, ValMMS);
				MmsValue_delete(ValMMS);
				*/


				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTUV1_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTUV1_Str_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTUV2_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTUV2_Str_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTUV3_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTUV3_Str_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTUV4_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTUV4_Str_q,0);

}

#endif
