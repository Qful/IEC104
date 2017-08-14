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

/*******************************************************
 * MR801
 *******************************************************/
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

/*******************************************************
 * MR771 MR761 MR762 MR763
 *******************************************************/
#if defined	(MR771) || defined	(MR761) || defined	(MR762) || defined	(MR763)

#if defined	(MR771)
#include "static_model_MR771.h"
#endif

#if defined	(MR761) || defined	(MR762) || defined	(MR763)
#include "static_model_MR76x.h"
#endif


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
				bool	Str_general;
				if (ucMDiscInBuf[MB_offset_IO_Uup_1] & MB_b_IO_Uup1) Str_general = true; else Str_general = false;
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTOV1_Str_general,  Str_general) > 0)			// И0 U>1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTOV1_Str_t, currentTime);

				if (ucMDiscInBuf[MB_offset_IO_Uup_2] & MB_b_IO_Uup2) Str_general = true; else Str_general = false;
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTOV2_Str_general,  Str_general) > 0)			// И0 U>2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTOV2_Str_t, currentTime);

				if (ucMDiscInBuf[MB_offset_IO_Uup_3] & MB_b_IO_Uup3) Str_general = true; else Str_general = false;
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTOV3_Str_general,  Str_general) > 0)			// И0 U>3
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTOV3_Str_t, currentTime);

				if (ucMDiscInBuf[MB_offset_IO_Uup_4] & MB_b_IO_Uup4) Str_general = true; else Str_general = false;
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTOV4_Str_general,  Str_general) > 0)			// И0 U>4
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTOV4_Str_t, currentTime);

	// Op_general
				if (ucMDiscInBuf[MB_offset_SRAB_Uup_1] & MB_b_SRAB_Uup1) Str_general = true; else Str_general = false;
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTOV1_Op_general,  Str_general) > 0)		// СРАБ U>1
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTOV1_Op_t, currentTime);

				if (ucMDiscInBuf[MB_offset_SRAB_Uup_2] & MB_b_SRAB_Uup2) Str_general = true; else Str_general = false;
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTOV2_Op_general,  Str_general) > 0)		// СРАБ U>2
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTOV2_Op_t, currentTime);

				if (ucMDiscInBuf[MB_offset_SRAB_Uup_3] & MB_b_SRAB_Uup3) Str_general = true; else Str_general = false;
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTOV3_Op_general,  Str_general) > 0)		// СРАБ U>3
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTOV3_Op_t, currentTime);

				if (ucMDiscInBuf[MB_offset_SRAB_Uup_4] & MB_b_SRAB_Uup4) Str_general = true; else Str_general = false;
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTOV4_Op_general,  Str_general) > 0)		// СРАБ U>4
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
				bool	Str_general;
				if (ucMDiscInBuf[MB_offset_IO_Udn_1] & MB_b_IO_Udn1) Str_general = true; else Str_general = false;
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTUV1_Str_general,  Str_general) > 0)			// И0 U>1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTUV1_Str_t, currentTime);

				if (ucMDiscInBuf[MB_offset_IO_Udn_2] & MB_b_IO_Udn2) Str_general = true; else Str_general = false;
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTUV2_Str_general,  Str_general) > 0)			// И0 U>2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTUV2_Str_t, currentTime);

				if (ucMDiscInBuf[MB_offset_IO_Udn_3] & MB_b_IO_Udn3) Str_general = true; else Str_general = false;
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTUV3_Str_general,  Str_general) > 0)			// И0 U>3
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTUV3_Str_t, currentTime);

				if (ucMDiscInBuf[MB_offset_IO_Udn_4] & MB_b_IO_Udn4) Str_general = true; else Str_general = false;
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTUV4_Str_general,  Str_general) > 0)			// И0 U>4
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTUV4_Str_t, currentTime);

	// Op_general
				if (ucMDiscInBuf[MB_offset_SRAB_Udn_1] & MB_b_SRAB_Udn1) Str_general = true; else Str_general = false;
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTUV1_Op_general,  Str_general) > 0)		// СРАБ U>1
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTUV1_Op_t, currentTime);

				if (ucMDiscInBuf[MB_offset_SRAB_Udn_2] & MB_b_SRAB_Udn2) Str_general = true; else Str_general = false;
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTUV2_Op_general,  Str_general) > 0)		// СРАБ U>2
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTUV2_Op_t, currentTime);

				if (ucMDiscInBuf[MB_offset_SRAB_Udn_3] & MB_b_SRAB_Udn3) Str_general = true; else Str_general = false;
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTUV3_Op_general,  Str_general) > 0)		// СРАБ U>3
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTUV3_Op_t, currentTime);

				if (ucMDiscInBuf[MB_offset_SRAB_Udn_4] & MB_b_SRAB_Udn4) Str_general = true; else Str_general = false;
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTUV4_Op_general,  Str_general) > 0)		// СРАБ U>4
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
/*******************************************************
 * MR5_700
 *******************************************************/
#if defined (MR5_700)
#include "static_model_MR5_700.h"

extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucUstavkiInBuf[MB_NumbUstavki];
extern uint16_t   ucConfigBufU[MB_NumbConfigU];

/*******************************************************
 * Set_UPTOV наполняем оперативными данными
 *******************************************************/
void	Set_UPTOV	(uint8_t num, uint64_t currentTime )
{
	//Health
				uint32_t	Health = STVALINT32_OK;
				if (ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1a) {Health = STVALINT32_Warning;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTOV1_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTOV1_Health_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTOV2_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTOV2_Health_t, currentTime);


	//  Mod Beh
				uint32_t	Mod;
				if (ucConfigBufU[MB_offset_Uup + MB_offset_Uup_U_Config] & MB_bOffset_Uup_U_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTOV1_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTOV1_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTOV1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTOV1_Beh_t, currentTime);

				if (ucConfigBufU[MB_offset_Uup2 + MB_offset_Uup_U_Config] & MB_bOffset_Uup_U_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTOV2_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTOV2_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTOV2_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTOV2_Beh_t, currentTime);

	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTOV1_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTOV1_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTOV1_Health_q,Qual);

				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTOV2_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTOV2_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTOV2_Health_q,Qual);

	// Str_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTOV1_Str_general,  ucMDiscInBuf[MB_offset_IO_Uup] & MB_b_IO_Uup) > 0)			// И0 U>1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTOV1_Str_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTOV2_Str_general,  ucMDiscInBuf[MB_offset_IO_Uup2] & MB_b_IO_Uup2) > 0)			// И0 U>2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTOV2_Str_t, currentTime);

	// Op_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTOV1_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Uup] & MB_b_SRAB_Uup) > 0)		// СРАБ U>1
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTOV1_Op_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTOV2_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Uup2] & MB_b_SRAB_Uup2) > 0)		// СРАБ U>2
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTOV2_Op_t, currentTime);

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
}
/*******************************************************
 * Set_UPTUV наполняем оперативными данными
 *******************************************************/
void	Set_UPTUV	(uint8_t num, uint64_t currentTime )
{
	//Health
				uint32_t	Health = STVALINT32_OK;
				if (ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1a) {Health = STVALINT32_Warning;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTUV1_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTUV1_Health_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTUV2_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTUV2_Health_t, currentTime);

	//  Mod Beh
				uint32_t	Mod;
				if (ucConfigBufU[MB_offset_Udn + MB_offset_Udn_U_Config] & MB_bOffset_Udn_U_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTUV1_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTUV1_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTUV1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTUV1_Beh_t, currentTime);

				if (ucConfigBufU[MB_offset_Udn2 + MB_offset_Udn_U_Config] & MB_bOffset_Udn_U_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTUV2_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTUV2_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTUV2_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTUV2_Beh_t, currentTime);

	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTUV1_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTUV1_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTUV1_Health_q,Qual);

				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTUV2_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTUV2_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_UPTUV2_Health_q,Qual);

	// Str_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTUV1_Str_general,  ucMDiscInBuf[MB_offset_IO_Udn] & MB_b_IO_Udn) > 0)			// И0 U>1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTUV1_Str_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTUV2_Str_general,  ucMDiscInBuf[MB_offset_IO_Udn2] & MB_b_IO_Udn2) > 0)			// И0 U>2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTUV2_Str_t, currentTime);

	// Op_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTUV1_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Udn] & MB_b_SRAB_Udn) > 0)		// СРАБ U>1
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTUV1_Op_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTUV2_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Udn2] & MB_b_SRAB_Udn2) > 0)		// СРАБ U>2
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTUV2_Op_t, currentTime);


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

}
/*******************************************************
 * Set_U0PTOV наполняем оперативными данными
 *******************************************************/
void	Set_U0PTOV	(uint8_t num, uint64_t currentTime )
{
	//Health
				uint32_t	Health = STVALINT32_OK;
				if (ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1a) {Health = STVALINT32_Warning;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_U0PTOV1_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_U0PTOV1_Health_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_U0PTOV2_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_U0PTOV2_Health_t, currentTime);


	//  Mod Beh
				uint32_t	Mod;
				if (ucConfigBufU[MB_offset_U0up + MB_offset_Uup_U_Config] & MB_bOffset_Uup_U_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_U0PTOV1_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_U0PTOV1_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_U0PTOV1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_U0PTOV1_Beh_t, currentTime);

				if (ucConfigBufU[MB_offset_U0up2 + MB_offset_Uup_U_Config] & MB_bOffset_Uup_U_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_U0PTOV2_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_U0PTOV2_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_U0PTOV2_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_U0PTOV2_Beh_t, currentTime);

	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_U0PTOV1_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U0PTOV1_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U0PTOV1_Health_q,Qual);

				IedServer_updateQuality(iedServer,&iedModel_PROT_U0PTOV2_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U0PTOV2_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U0PTOV2_Health_q,Qual);

	// Str_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_U0PTOV1_Str_general,  ucMDiscInBuf[MB_offset_IO_U0up] & MB_b_IO_U0up) > 0)			// И0 U>1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_U0PTOV1_Str_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_U0PTOV2_Str_general,  ucMDiscInBuf[MB_offset_IO_U0up2] & MB_b_IO_U0up2) > 0)			// И0 U>2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_U0PTOV2_Str_t, currentTime);

	// Op_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_U0PTOV1_Op_general,  ucMDiscInBuf[MB_offset_SRAB_U0up] & MB_b_SRAB_U0up) > 0)		// СРАБ U>1
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_U0PTOV1_Op_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_U0PTOV2_Op_general,  ucMDiscInBuf[MB_offset_SRAB_U0up2] & MB_b_SRAB_U0up2) > 0)		// СРАБ U>2
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_U0PTOV2_Op_t, currentTime);

	// Str_dir_general не меняется
				/*
				MmsValue* 	ValMMS;
				uint8_t		Dir = 3;
				ValMMS = MmsValue_newIntegerFromInt16(Dir);
				IedServer_updateAttributeValue(iedServer, &iedModel_PROT_U0PTOV1_Str_dirGeneral, ValMMS);
				IedServer_updateAttributeValue(iedServer, &iedModel_PROT_U0PTOV2_Str_dirGeneral, ValMMS);
				IedServer_updateAttributeValue(iedServer, &iedModel_PROT_U0PTOV3_Str_dirGeneral, ValMMS);
				IedServer_updateAttributeValue(iedServer, &iedModel_PROT_U0PTOV4_Str_dirGeneral, ValMMS);
				MmsValue_delete(ValMMS);
				*/

				IedServer_updateQuality(iedServer,&iedModel_PROT_U0PTOV1_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U0PTOV1_Str_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U0PTOV2_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U0PTOV2_Str_q,0);
}
/*******************************************************
 * Set_U2PTOV наполняем оперативными данными
 *******************************************************/
void	Set_U2PTOV	(uint8_t num, uint64_t currentTime )
{
	//Health
				uint32_t	Health = STVALINT32_OK;
				if (ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1a) {Health = STVALINT32_Warning;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_U2PTOV1_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_U2PTOV1_Health_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_U2PTOV2_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_U2PTOV2_Health_t, currentTime);


	//  Mod Beh
				uint32_t	Mod;
				if (ucConfigBufU[MB_offset_U2up + MB_offset_Uup_U_Config] & MB_bOffset_Uup_U_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_U2PTOV1_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_U2PTOV1_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_U2PTOV1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_U2PTOV1_Beh_t, currentTime);

				if (ucConfigBufU[MB_offset_U2up2 + MB_offset_Uup_U_Config] & MB_bOffset_Uup_U_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_U2PTOV2_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_U2PTOV2_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_U2PTOV2_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_U2PTOV2_Beh_t, currentTime);

	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_U2PTOV1_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U2PTOV1_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U2PTOV1_Health_q,Qual);

				IedServer_updateQuality(iedServer,&iedModel_PROT_U2PTOV2_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U2PTOV2_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U2PTOV2_Health_q,Qual);

	// Str_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_U2PTOV1_Str_general,  ucMDiscInBuf[MB_offset_IO_U2up] & MB_b_IO_U2up) > 0)			// И0 U>1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_U2PTOV1_Str_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_U2PTOV2_Str_general,  ucMDiscInBuf[MB_offset_IO_U2up2] & MB_b_IO_U2up2) > 0)			// И0 U>2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_U2PTOV2_Str_t, currentTime);

	// Op_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_U2PTOV1_Op_general,  ucMDiscInBuf[MB_offset_SRAB_U2up] & MB_b_SRAB_U2up) > 0)		// СРАБ U>1
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_U2PTOV1_Op_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_U2PTOV2_Op_general,  ucMDiscInBuf[MB_offset_SRAB_U2up2] & MB_b_SRAB_U2up2) > 0)		// СРАБ U>2
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_U2PTOV2_Op_t, currentTime);

	// Str_dir_general не меняется
				/*
				MmsValue* 	ValMMS;
				uint8_t		Dir = 3;
				ValMMS = MmsValue_newIntegerFromInt16(Dir);
				IedServer_updateAttributeValue(iedServer, &iedModel_PROT_U2PTOV1_Str_dirGeneral, ValMMS);
				IedServer_updateAttributeValue(iedServer, &iedModel_PROT_U2PTOV2_Str_dirGeneral, ValMMS);
				IedServer_updateAttributeValue(iedServer, &iedModel_PROT_U2PTOV3_Str_dirGeneral, ValMMS);
				IedServer_updateAttributeValue(iedServer, &iedModel_PROT_U2PTOV4_Str_dirGeneral, ValMMS);
				MmsValue_delete(ValMMS);
				*/

				IedServer_updateQuality(iedServer,&iedModel_PROT_U2PTOV1_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U2PTOV1_Str_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U2PTOV2_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U2PTOV2_Str_q,0);
}
#endif
/*******************************************************
 * MR5_600
 *******************************************************/
#if defined (MR5_600)
#include "static_model_MR5_600.h"

extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucUstavkiInBuf[MB_NumbUstavki];
extern uint16_t   ucConfigBufU[MB_NumbConfigU];

/*******************************************************
 * Set_UPTOV наполняем оперативными данными
 *******************************************************/
void	Set_UPTOV	(uint8_t num, uint64_t currentTime )
{
	//Health
				uint32_t	Health = STVALINT32_OK;
				if (ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1a) {Health = STVALINT32_Warning;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTOV1_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTOV1_Health_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTOV2_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTOV2_Health_t, currentTime);


	//  Mod Beh
				uint32_t	Mod;
				if (ucConfigBufU[MB_offset_Uup + MB_offset_Uup_U_Config] & MB_bOffset_Uup_U_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTOV1_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTOV1_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTOV1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTOV1_Beh_t, currentTime);

				if (ucConfigBufU[MB_offset_Uup2 + MB_offset_Uup_U_Config] & MB_bOffset_Uup_U_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTOV2_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTOV2_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTOV2_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTOV2_Beh_t, currentTime);

				if (ucConfigBufU[MB_offset_Uup3 + MB_offset_Uup_U_Config] & MB_bOffset_Uup_U_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTOV3_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTOV3_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTOV3_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTOV3_Beh_t, currentTime);

				if (ucConfigBufU[MB_offset_Uup4 + MB_offset_Uup_U_Config] & MB_bOffset_Uup_U_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
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
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTOV1_Str_general,  ucMDiscInBuf[MB_offset_IO_Uup] & MB_b_IO_Uup) > 0)			// И0 U>1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTOV1_Str_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTOV2_Str_general,  ucMDiscInBuf[MB_offset_IO_Uup2] & MB_b_IO_Uup2) > 0)			// И0 U>2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTOV2_Str_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTOV3_Str_general,  ucMDiscInBuf[MB_offset_IO_Uup3] & MB_b_IO_Uup3) > 0)			// И0 U>2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTOV3_Str_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTOV4_Str_general,  ucMDiscInBuf[MB_offset_IO_Uup4] & MB_b_IO_Uup4) > 0)			// И0 U>2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTOV4_Str_t, currentTime);

	// Op_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTOV1_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Uup] & MB_b_SRAB_Uup) > 0)		// СРАБ U>1
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTOV1_Op_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTOV2_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Uup2] & MB_b_SRAB_Uup2) > 0)		// СРАБ U>2
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTOV2_Op_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTOV3_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Uup3] & MB_b_SRAB_Uup3) > 0)		// СРАБ U>2
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTOV3_Op_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTOV4_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Uup4] & MB_b_SRAB_Uup4) > 0)		// СРАБ U>2
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
				if (ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1a) {Health = STVALINT32_Warning;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTUV1_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTUV1_Health_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTUV2_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTUV2_Health_t, currentTime);

	//  Mod Beh
				uint32_t	Mod;
				if (ucConfigBufU[MB_offset_Udn + MB_offset_Udn_U_Config] & MB_bOffset_Udn_U_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTUV1_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTUV1_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTUV1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTUV1_Beh_t, currentTime);

				if (ucConfigBufU[MB_offset_Udn2 + MB_offset_Udn_U_Config] & MB_bOffset_Udn_U_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTUV2_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTUV2_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTUV2_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTUV2_Beh_t, currentTime);

				if (ucConfigBufU[MB_offset_Udn3 + MB_offset_Udn_U_Config] & MB_bOffset_Udn_U_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTUV3_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTUV3_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_UPTUV3_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_UPTUV3_Beh_t, currentTime);

				if (ucConfigBufU[MB_offset_Udn4 + MB_offset_Udn_U_Config] & MB_bOffset_Udn_U_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
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
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTUV1_Str_general,  ucMDiscInBuf[MB_offset_IO_Udn] & MB_b_IO_Udn) > 0)			// И0 U>1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTUV1_Str_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTUV2_Str_general,  ucMDiscInBuf[MB_offset_IO_Udn2] & MB_b_IO_Udn2) > 0)			// И0 U>2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTUV2_Str_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTUV3_Str_general,  ucMDiscInBuf[MB_offset_IO_Udn3] & MB_b_IO_Udn3) > 0)			// И0 U>2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTUV3_Str_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTUV4_Str_general,  ucMDiscInBuf[MB_offset_IO_Udn4] & MB_b_IO_Udn4) > 0)			// И0 U>2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTUV4_Str_t, currentTime);

	// Op_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTUV1_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Udn] & MB_b_SRAB_Udn) > 0)		// СРАБ U>1
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTUV1_Op_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTUV2_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Udn2] & MB_b_SRAB_Udn2) > 0)		// СРАБ U>2
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTUV2_Op_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTUV3_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Udn3] & MB_b_SRAB_Udn3) > 0)		// СРАБ U>2
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_UPTUV3_Op_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_UPTUV4_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Udn4] & MB_b_SRAB_Udn4) > 0)		// СРАБ U>2
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
/*******************************************************
 * Set_U0PTOV наполняем оперативными данными
 *******************************************************/
void	Set_U0PTOV	(uint8_t num, uint64_t currentTime )
{
	//Health
				uint32_t	Health = STVALINT32_OK;
				if (ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1a) {Health = STVALINT32_Warning;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_U0PTOV1_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_U0PTOV1_Health_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_U0PTOV2_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_U0PTOV2_Health_t, currentTime);


	//  Mod Beh
				uint32_t	Mod;
				if (ucConfigBufU[MB_offset_U0up + MB_offset_Uup_U_Config] & MB_bOffset_Uup_U_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_U0PTOV1_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_U0PTOV1_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_U0PTOV1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_U0PTOV1_Beh_t, currentTime);

				if (ucConfigBufU[MB_offset_U0up2 + MB_offset_Uup_U_Config] & MB_bOffset_Uup_U_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_U0PTOV2_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_U0PTOV2_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_U0PTOV2_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_U0PTOV2_Beh_t, currentTime);

				if (ucConfigBufU[MB_offset_U0up3 + MB_offset_Uup_U_Config] & MB_bOffset_Uup_U_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_U0PTOV3_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_U0PTOV3_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_U0PTOV3_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_U0PTOV3_Beh_t, currentTime);

				if (ucConfigBufU[MB_offset_U0up4 + MB_offset_Uup_U_Config] & MB_bOffset_Uup_U_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_U0PTOV4_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_U0PTOV4_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_U0PTOV4_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_U0PTOV4_Beh_t, currentTime);

	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_U0PTOV1_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U0PTOV1_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U0PTOV1_Health_q,Qual);

				IedServer_updateQuality(iedServer,&iedModel_PROT_U0PTOV2_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U0PTOV2_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U0PTOV2_Health_q,Qual);

				IedServer_updateQuality(iedServer,&iedModel_PROT_U0PTOV3_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U0PTOV3_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U0PTOV3_Health_q,Qual);

				IedServer_updateQuality(iedServer,&iedModel_PROT_U0PTOV4_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U0PTOV4_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U0PTOV4_Health_q,Qual);

	// Str_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_U0PTOV1_Str_general,  ucMDiscInBuf[MB_offset_IO_U0up] & MB_b_IO_U0up) > 0)			// И0 U>1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_U0PTOV1_Str_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_U0PTOV2_Str_general,  ucMDiscInBuf[MB_offset_IO_U0up2] & MB_b_IO_U0up2) > 0)			// И0 U>2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_U0PTOV2_Str_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_U0PTOV3_Str_general,  ucMDiscInBuf[MB_offset_IO_U0up3] & MB_b_IO_U0up3) > 0)			// И0 U>2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_U0PTOV3_Str_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_U0PTOV4_Str_general,  ucMDiscInBuf[MB_offset_IO_U0up4] & MB_b_IO_U0up4) > 0)			// И0 U>2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_U0PTOV4_Str_t, currentTime);

	// Op_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_U0PTOV1_Op_general,  ucMDiscInBuf[MB_offset_SRAB_U0up] & MB_b_SRAB_U0up) > 0)		// СРАБ U>1
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_U0PTOV1_Op_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_U0PTOV2_Op_general,  ucMDiscInBuf[MB_offset_SRAB_U0up2] & MB_b_SRAB_U0up2) > 0)		// СРАБ U>2
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_U0PTOV2_Op_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_U0PTOV3_Op_general,  ucMDiscInBuf[MB_offset_SRAB_U0up3] & MB_b_SRAB_U0up3) > 0)		// СРАБ U>2
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_U0PTOV3_Op_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_U0PTOV4_Op_general,  ucMDiscInBuf[MB_offset_SRAB_U0up4] & MB_b_SRAB_U0up4) > 0)		// СРАБ U>2
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_U0PTOV4_Op_t, currentTime);

	// Str_dir_general не меняется
				/*
				MmsValue* 	ValMMS;
				uint8_t		Dir = 3;
				ValMMS = MmsValue_newIntegerFromInt16(Dir);
				IedServer_updateAttributeValue(iedServer, &iedModel_PROT_U0PTOV1_Str_dirGeneral, ValMMS);
				IedServer_updateAttributeValue(iedServer, &iedModel_PROT_U0PTOV2_Str_dirGeneral, ValMMS);
				IedServer_updateAttributeValue(iedServer, &iedModel_PROT_U0PTOV3_Str_dirGeneral, ValMMS);
				IedServer_updateAttributeValue(iedServer, &iedModel_PROT_U0PTOV4_Str_dirGeneral, ValMMS);
				MmsValue_delete(ValMMS);
				*/

				IedServer_updateQuality(iedServer,&iedModel_PROT_U0PTOV1_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U0PTOV1_Str_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U0PTOV2_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U0PTOV2_Str_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U0PTOV3_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U0PTOV3_Str_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U0PTOV4_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U0PTOV4_Str_q,0);

}
/*******************************************************
 * Set_U1PTUV наполняем оперативными данными
 *******************************************************/
void	Set_U1PTUV	(uint8_t num, uint64_t currentTime )
{
	//Health
				uint32_t	Health = STVALINT32_OK;
				if (ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1a) {Health = STVALINT32_Warning;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_U1PTUV1_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_U1PTUV1_Health_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_U1PTUV2_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_U1PTUV2_Health_t, currentTime);


	//  Mod Beh
				uint32_t	Mod;
				if (ucConfigBufU[MB_offset_U1dn + MB_offset_Udn_U_Config] & MB_bOffset_Udn_U_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_U1PTUV1_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_U1PTUV1_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_U1PTUV1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_U1PTUV1_Beh_t, currentTime);

				if (ucConfigBufU[MB_offset_U1dn2 + MB_offset_Udn_U_Config] & MB_bOffset_Udn_U_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_U1PTUV2_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_U1PTUV2_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_U1PTUV2_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_U1PTUV2_Beh_t, currentTime);

	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_U1PTUV1_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U1PTUV1_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U1PTUV1_Health_q,Qual);

				IedServer_updateQuality(iedServer,&iedModel_PROT_U1PTUV2_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U1PTUV2_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U1PTUV2_Health_q,Qual);

	// Str_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_U1PTUV1_Str_general,  ucMDiscInBuf[MB_offset_IO_U1dn] & MB_b_IO_U1dn) > 0)			// И0 U>1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_U1PTUV1_Str_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_U1PTUV2_Str_general,  ucMDiscInBuf[MB_offset_IO_U1dn2] & MB_b_IO_U1dn2) > 0)			// И0 U>2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_U1PTUV2_Str_t, currentTime);

	// Op_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_U1PTUV1_Op_general,  ucMDiscInBuf[MB_offset_SRAB_U1dn] & MB_b_SRAB_U1dn) > 0)		// СРАБ U>1
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_U1PTUV1_Op_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_U1PTUV2_Op_general,  ucMDiscInBuf[MB_offset_SRAB_U1dn2] & MB_b_SRAB_U1dn2) > 0)		// СРАБ U>2
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_U1PTUV2_Op_t, currentTime);

	// Str_dir_general не меняется
				/*
				MmsValue* 	ValMMS;
				uint8_t		Dir = 3;
				ValMMS = MmsValue_newIntegerFromInt16(Dir);
				IedServer_updateAttributeValue(iedServer, &iedModel_PROT_U1PTUV1_Str_dirGeneral, ValMMS);
				IedServer_updateAttributeValue(iedServer, &iedModel_PROT_U1PTUV2_Str_dirGeneral, ValMMS);
				IedServer_updateAttributeValue(iedServer, &iedModel_PROT_U1PTUV3_Str_dirGeneral, ValMMS);
				IedServer_updateAttributeValue(iedServer, &iedModel_PROT_U1PTUV4_Str_dirGeneral, ValMMS);
				MmsValue_delete(ValMMS);
				*/

				IedServer_updateQuality(iedServer,&iedModel_PROT_U1PTUV1_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U1PTUV1_Str_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U1PTUV2_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U1PTUV2_Str_q,0);
}
/*******************************************************
 * Set_U2PTOV наполняем оперативными данными
 *******************************************************/
void	Set_U2PTOV	(uint8_t num, uint64_t currentTime )
{
	//Health
				uint32_t	Health = STVALINT32_OK;
				if (ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1a) {Health = STVALINT32_Warning;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_U2PTOV1_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_U2PTOV1_Health_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_U2PTOV2_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_U2PTOV2_Health_t, currentTime);


	//  Mod Beh
				uint32_t	Mod;
				if (ucConfigBufU[MB_offset_U2up + MB_offset_Uup_U_Config] & MB_bOffset_Uup_U_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_U2PTOV1_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_U2PTOV1_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_U2PTOV1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_U2PTOV1_Beh_t, currentTime);

				if (ucConfigBufU[MB_offset_U2up2 + MB_offset_Uup_U_Config] & MB_bOffset_Uup_U_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_U2PTOV2_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_U2PTOV2_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_U2PTOV2_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_U2PTOV2_Beh_t, currentTime);

	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_U2PTOV1_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U2PTOV1_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U2PTOV1_Health_q,Qual);

				IedServer_updateQuality(iedServer,&iedModel_PROT_U2PTOV2_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U2PTOV2_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U2PTOV2_Health_q,Qual);

	// Str_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_U2PTOV1_Str_general,  ucMDiscInBuf[MB_offset_IO_U2up] & MB_b_IO_U2up) > 0)			// И0 U>1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_U2PTOV1_Str_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_U2PTOV2_Str_general,  ucMDiscInBuf[MB_offset_IO_U2up2] & MB_b_IO_U2up2) > 0)			// И0 U>2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_U2PTOV2_Str_t, currentTime);

	// Op_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_U2PTOV1_Op_general,  ucMDiscInBuf[MB_offset_SRAB_U2up] & MB_b_SRAB_U2up) > 0)		// СРАБ U>1
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_U2PTOV1_Op_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_U2PTOV2_Op_general,  ucMDiscInBuf[MB_offset_SRAB_U2up2] & MB_b_SRAB_U2up2) > 0)		// СРАБ U>2
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_U2PTOV2_Op_t, currentTime);

	// Str_dir_general не меняется
				/*
				MmsValue* 	ValMMS;
				uint8_t		Dir = 3;
				ValMMS = MmsValue_newIntegerFromInt16(Dir);
				IedServer_updateAttributeValue(iedServer, &iedModel_PROT_U2PTOV1_Str_dirGeneral, ValMMS);
				IedServer_updateAttributeValue(iedServer, &iedModel_PROT_U2PTOV2_Str_dirGeneral, ValMMS);
				IedServer_updateAttributeValue(iedServer, &iedModel_PROT_U2PTOV3_Str_dirGeneral, ValMMS);
				IedServer_updateAttributeValue(iedServer, &iedModel_PROT_U2PTOV4_Str_dirGeneral, ValMMS);
				MmsValue_delete(ValMMS);
				*/

				IedServer_updateQuality(iedServer,&iedModel_PROT_U2PTOV1_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U2PTOV1_Str_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U2PTOV2_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_U2PTOV2_Str_q,0);
}
#endif
