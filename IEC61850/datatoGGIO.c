/*
 * datatoGGIO.c
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


extern 	uint16_t   ucMUstavkiInBuf[MB_NumbUstavki];
extern  uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern	uint16_t   ucConfigAWRBuf[MB_NumbConfigAWR];



/*******************************************************
 * Set_VZGGIO наполняем оперативными данными
 *******************************************************/
void	Set_VZGGIO	(uint8_t num, uint64_t currentTime )
{

	//  Mod Beh
				uint32_t	Mod;
				if (ucMUstavkiInBuf[MB_offset_Ext_1 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO1_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO1_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Ext_2 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO2_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO2_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Ext_3 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO3_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO3_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Ext_4 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO4_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO4_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Ext_5 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO5_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO5_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Ext_6 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO6_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO6_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Ext_7 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO7_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO7_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Ext_8 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO8_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO8_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Ext_9 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO9_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO9_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO9_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO9_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Ext_10 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO10_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO10_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO10_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO10_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Ext_11 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO11_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO11_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO11_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO11_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Ext_12 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO12_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO12_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO12_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO12_Beh_t, currentTime);


				if (ucMUstavkiInBuf[MB_offset_Ext_13 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO13_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO13_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO13_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO13_Beh_t, currentTime);


				if (ucMUstavkiInBuf[MB_offset_Ext_14 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO14_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO14_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO14_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO14_Beh_t, currentTime);


				if (ucMUstavkiInBuf[MB_offset_Ext_15 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO15_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO15_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO15_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO15_Beh_t, currentTime);


				if (ucMUstavkiInBuf[MB_offset_Ext_16 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO16_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO16_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO16_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO16_Beh_t, currentTime);

	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO9_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO9_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO9_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO10_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO10_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO10_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO11_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO11_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO11_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO12_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO12_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO12_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO13_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO13_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO13_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO14_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO14_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO14_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO15_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO15_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO15_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO16_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO16_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO16_Health_q,Qual);

//				uint32_t	Alm;

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_1] & MB_b_SRAB_ext_1))		// СРАБ >1
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_2] & MB_b_SRAB_ext_2))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_3] & MB_b_SRAB_ext_3))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_4] & MB_b_SRAB_ext_4))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_5] & MB_b_SRAB_ext_5))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_6] & MB_b_SRAB_ext_6))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_7] & MB_b_SRAB_ext_7))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_8] & MB_b_SRAB_ext_8))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO9_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_9] & MB_b_SRAB_ext_9))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO9_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO9_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO10_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_10] & MB_b_SRAB_ext_10))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO10_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO10_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO11_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_11] & MB_b_SRAB_ext_11))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO11_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO11_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO12_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_12] & MB_b_SRAB_ext_12))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO12_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO12_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO13_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_13] & MB_b_SRAB_ext_13))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO13_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO13_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO14_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_14] & MB_b_SRAB_ext_14))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO14_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO14_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO15_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_15] & MB_b_SRAB_ext_15))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO15_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO15_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO16_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_16] & MB_b_SRAB_ext_16))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO16_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO16_Alm_q,0);

}

/*******************************************************
 * Set_AVRGGIO наполняем оперативными данными
 *******************************************************/
void	Set_AVRGGIO	(uint8_t num, uint64_t currentTime )
{
	//  Mod Beh

				uint32_t	Mod;
				if (ucConfigAWRBuf[MB_offset_ConfAWR] & MB_bOffset_AWR_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_AVRGGIO_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_AVRGGIO_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_AVRGGIO_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_AVRGGIO_Beh_t, currentTime);

	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_AVRGGIO_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_AVRGGIO_Beh_q,Qual);

				uint8_t	awr=0;
					if(ucMDiscInBuf[MB_offset_AWR] & MB_b_ON_AWR)  awr = 1;
					if(ucMDiscInBuf[MB_offset_AWR] & MB_b_OFF_AWR) awr = 2;
					if(ucMDiscInBuf[MB_offset_AWR] & MB_b_Blok_AWR) awr = 3;

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_AVRGGIO_IntIn_stVal, awr))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_AVRGGIO_IntIn_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_AVRGGIO_IntIn_q,0);
}

/*******************************************************
 * Set_XCBRGGIO наполняем оперативными данными
 *******************************************************/
void	Set_XCBRGGIO	(uint8_t num, uint64_t currentTime )
{
	//--------------------------------
	// сброс флагов

		if (ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetError){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_stVal,  1))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_stVal,  0))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_q,0);
		}
		if (ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetSysNote){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_stVal,  1))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_stVal,  0))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_q,0);
		}
		if (ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetErrorNote){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_stVal,  1))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_stVal,  0))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_q,0);
		}

}

/*******************************************************
 * Set_INGGIO наполняем оперативными данными
 *******************************************************/
void	Set_INGGIO	(uint8_t num, uint64_t currentTime )
{
	//  Mod Beh

				uint32_t	Mod = STVALINT32_ON;

				if (
						(ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule2) ||
						(ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule3)
					) {Mod = STVALINT32_OFF;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Beh_t, currentTime);



				if (ucMDiscInBuf[MB_offset_errorM2] & MB_errorM2){	// 8D
				    	    IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind1_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
				    	    IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind2_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
				    	    IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind3_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
				    	    IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind4_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
				    	    IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind5_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
				    	    IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind6_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
				    	    IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind7_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
				    	    IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind8_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
				} else
				{
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind1_q,0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind2_q,0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind3_q,0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind4_q,0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind5_q,0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind6_q,0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind7_q,0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind8_q,0);

				}

							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetDiscreet_1_16] & (1<<0)))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind1_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetDiscreet_1_16] & (1<<1)))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind2_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetDiscreet_1_16] & (1<<2)))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind3_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetDiscreet_1_16] & (1<<3)))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind4_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetDiscreet_1_16] & (1<<4)))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind5_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetDiscreet_1_16] & (1<<5)))
					       	     IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind6_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetDiscreet_1_16] & (1<<6)))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind7_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetDiscreet_1_16] & (1<<7)))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind8_t, currentTime);


				if (ucMDiscInBuf[MB_offset_errorM3] & MB_errorM3){	// 16D
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind9_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind10_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind11_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind12_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind13_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind14_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind15_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind16_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind17_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind18_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind19_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind20_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind21_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind22_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind23_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind24_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);

				} else{
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind9_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind10_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind11_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind12_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind13_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind14_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind15_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind16_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind17_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind18_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind19_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind20_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind21_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind22_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind23_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind24_q,0 | 0);

				}

							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind9_stVal,  ucMDiscInBuf[MB_offsetDiscreet_1_16] & (1<<8)))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind9_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind10_stVal,  ucMDiscInBuf[MB_offsetDiscreet_1_16] & (1<<9)))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind10_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind11_stVal,  ucMDiscInBuf[MB_offsetDiscreet_1_16] & (1<<10)))
					       	     IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind11_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind12_stVal,  ucMDiscInBuf[MB_offsetDiscreet_1_16] & (1<<11)))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind12_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind13_stVal,  ucMDiscInBuf[MB_offsetDiscreet_1_16] & (1<<12)))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind13_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind14_stVal,  ucMDiscInBuf[MB_offsetDiscreet_1_16] & (1<<13)))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind14_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind15_stVal,  ucMDiscInBuf[MB_offsetDiscreet_1_16] & (1<<14)))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind15_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind16_stVal,  ucMDiscInBuf[MB_offsetDiscreet_1_16] & (1<<15)))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind16_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind17_stVal,  ucMDiscInBuf[MB_offsetDiscreet_17_24] & (1<<0)))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind17_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind18_stVal,  ucMDiscInBuf[MB_offsetDiscreet_17_24] & (1<<1)))
							 	 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind18_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind19_stVal,  ucMDiscInBuf[MB_offsetDiscreet_17_24] & (1<<2)))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind19_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind20_stVal,  ucMDiscInBuf[MB_offsetDiscreet_17_24] & (1<<3)))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind20_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind21_stVal,  ucMDiscInBuf[MB_offsetDiscreet_17_24] & (1<<4)))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind21_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind22_stVal,  ucMDiscInBuf[MB_offsetDiscreet_17_24] & (1<<5)))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind22_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind23_stVal,  ucMDiscInBuf[MB_offsetDiscreet_17_24] & (1<<6)))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind23_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind24_stVal,  ucMDiscInBuf[MB_offsetDiscreet_17_24] & (1<<7)))
		       	        	     IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind24_t, currentTime);


}

/*******************************************************
 * Set_OUTGGIO наполняем оперативными данными
 *******************************************************/
void	Set_OUTGGIO	(uint8_t num, uint64_t currentTime )
{

	uint32_t	Mod = STVALINT32_OТ;

	if (
			(ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule1) ||
			(ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule2)
		) {Mod = STVALINT32_OFF;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Mod_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Mod_t, currentTime);
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Beh_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Beh_t, currentTime);


	if (ucMDiscInBuf[MB_offset_errorM1] & MB_errorM1){	// 11R
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);

		}else{
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_q,0);

		}

		if (ucMDiscInBuf[MB_offset_errorM2] & MB_errorM2) //8 реле
		{
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO15_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO16_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO17_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO18_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);

		} else{

			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO15_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO16_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO17_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO18_q,0);

		}
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_stVal,  ucMDiscInBuf[MB_offsetRelay_1] & MB_bOffset_Relay_1))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_stVal,  ucMDiscInBuf[MB_offsetRelay_2] & MB_bOffset_Relay_2))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_stVal,  ucMDiscInBuf[MB_offsetRelay_3] & MB_bOffset_Relay_3))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_stVal,  ucMDiscInBuf[MB_offsetRelay_4] & MB_bOffset_Relay_4))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_stVal,  ucMDiscInBuf[MB_offsetRelay_5] & MB_bOffset_Relay_5))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_stVal,  ucMDiscInBuf[MB_offsetRelay_6] & MB_bOffset_Relay_6))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_stVal,  ucMDiscInBuf[MB_offsetRelay_7] & MB_bOffset_Relay_7))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_stVal,  ucMDiscInBuf[MB_offsetRelay_8] & MB_bOffset_Relay_8))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_stVal,  ucMDiscInBuf[MB_offsetRelay_9] & MB_bOffset_Relay_9))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_stVal,  ucMDiscInBuf[MB_offsetRelay_10] & MB_bOffset_Relay_10))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_stVal,  ucMDiscInBuf[MB_offsetRelay_11] & MB_bOffset_Relay_11))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_stVal,  ucMDiscInBuf[MB_offsetRelay_12] & MB_bOffset_Relay_12))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_stVal,  ucMDiscInBuf[MB_offsetRelay_13] & MB_bOffset_Relay_13))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_stVal,  ucMDiscInBuf[MB_offsetRelay_14] & MB_bOffset_Relay_14))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO15_stVal,  ucMDiscInBuf[MB_offsetRelay_15] & MB_bOffset_Relay_15))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO15_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO16_stVal,  ucMDiscInBuf[MB_offsetRelay_16] & MB_bOffset_Relay_16))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO16_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO17_stVal,  ucMDiscInBuf[MB_offsetRelay_17] & MB_bOffset_Relay_17))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO17_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO18_stVal,  ucMDiscInBuf[MB_offsetRelay_18] & MB_bOffset_Relay_18))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO18_t, currentTime);
}

/*******************************************************
 * Set_LEDGGIO наполняем оперативными данными
 *******************************************************/
void	Set_LEDGGIO	(uint8_t num, uint64_t currentTime )
{

	uint32_t	Mod = STVALINT32_ON;

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Mod_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_Mod_t, currentTime);
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Beh_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_Beh_t, currentTime);


	// статус сброса нидикаторов
	if (
			(ucMDiscInBuf[MB_offsetLED_1] & MB_bOffset_LED_1) ||
			(ucMDiscInBuf[MB_offsetLED_2] & MB_bOffset_LED_2) ||
			(ucMDiscInBuf[MB_offsetLED_3] & MB_bOffset_LED_3) ||
			(ucMDiscInBuf[MB_offsetLED_4] & MB_bOffset_LED_4) ||
			(ucMDiscInBuf[MB_offsetLED_5] & MB_bOffset_LED_5) ||
			(ucMDiscInBuf[MB_offsetLED_6] & MB_bOffset_LED_6) ||
			(ucMDiscInBuf[MB_offsetLED_7] & MB_bOffset_LED_7) ||
			(ucMDiscInBuf[MB_offsetLED_8] & MB_bOffset_LED_8) ||
			(ucMDiscInBuf[MB_offsetLED_9] & MB_bOffset_LED_9) ||
			(ucMDiscInBuf[MB_offsetLED_10] & MB_bOffset_LED_10) ||
			(ucMDiscInBuf[MB_offsetLED_11] & MB_bOffset_LED_11) ||
			(ucMDiscInBuf[MB_offsetLED_12] & MB_bOffset_LED_12)
			)
	{
		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_stVal,  1))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_t, currentTime);
		IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_q,0);

	} else{
		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_stVal,  0))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_t, currentTime);
		IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_q,0);

	}

	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetLED_1] & MB_bOffset_LED_1) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetLED_2] & MB_bOffset_LED_2) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetLED_3] & MB_bOffset_LED_3) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetLED_4] & MB_bOffset_LED_4) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetLED_5] & MB_bOffset_LED_5) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetLED_6] & MB_bOffset_LED_6) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetLED_7] & MB_bOffset_LED_7) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetLED_8] & MB_bOffset_LED_8) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_stVal,  ucMDiscInBuf[MB_offsetLED_9] & MB_bOffset_LED_9) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_stVal,  ucMDiscInBuf[MB_offsetLED_10] & MB_bOffset_LED_10) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_stVal,  ucMDiscInBuf[MB_offsetLED_11] & MB_bOffset_LED_11) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_stVal,  ucMDiscInBuf[MB_offsetLED_12] & MB_bOffset_LED_12) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_t, currentTime);

	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind13_stVal,  ucMDiscInBuf[MB_offsetLED_13] & MB_bOffset_LED_13) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind13_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind14_stVal,  ucMDiscInBuf[MB_offsetLED_14] & MB_bOffset_LED_14) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind14_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind15_stVal,  ucMDiscInBuf[MB_offsetLED_15] & MB_bOffset_LED_15) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind15_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind16_stVal,  ucMDiscInBuf[MB_offsetLED_16] & MB_bOffset_LED_16) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind16_t, currentTime);


	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_q,0);

	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind13_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind14_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind15_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind16_q,0);

	//--------------------------------
	// сброс флагов

		if (ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetError){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_stVal,  1))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_stVal,  0))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_q,0);
		}
		if (ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetSysNote){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_stVal,  1))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_stVal,  0))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_q,0);
		}
		if (ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetErrorNote){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_stVal,  1))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_stVal,  0))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_q,0);
		}
}

/*******************************************************
 * Set_SSLGGIO наполняем оперативными данными
 *******************************************************/
void	Set_SSLGGIO	(uint8_t num, uint64_t currentTime )
{

	uint32_t	Mod = STVALINT32_ON;

	IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Mod_stVal, Mod);
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_Mod_t, currentTime);
	IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Beh_stVal, Mod);
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_Beh_t, currentTime);


	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetSSL_1] & MB_bOffset_SSL_1) > 0)
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind1_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetSSL_2] & MB_bOffset_SSL_2) > 0)
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind2_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetSSL_3] & MB_bOffset_SSL_3) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind3_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetSSL_4] & MB_bOffset_SSL_4) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind4_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetSSL_5] & MB_bOffset_SSL_5) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind5_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetSSL_6] & MB_bOffset_SSL_6) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind6_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetSSL_7] & MB_bOffset_SSL_7) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind7_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetSSL_8] & MB_bOffset_SSL_8) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind8_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind9_stVal,  ucMDiscInBuf[MB_offsetSSL_9] & MB_bOffset_SSL_9) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind9_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind10_stVal,  ucMDiscInBuf[MB_offsetSSL_10] & MB_bOffset_SSL_10) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind10_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind11_stVal,  ucMDiscInBuf[MB_offsetSSL_11] & MB_bOffset_SSL_11) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind11_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind12_stVal,  ucMDiscInBuf[MB_offsetSSL_12] & MB_bOffset_SSL_12) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind12_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind13_stVal,  ucMDiscInBuf[MB_offsetSSL_13] & MB_bOffset_SSL_13) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind13_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind14_stVal,  ucMDiscInBuf[MB_offsetSSL_14] & MB_bOffset_SSL_14) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind14_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind15_stVal,  ucMDiscInBuf[MB_offsetSSL_15] & MB_bOffset_SSL_15) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind15_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind16_stVal,  ucMDiscInBuf[MB_offsetSSL_16] & MB_bOffset_SSL_16) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind16_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind17_stVal,  ucMDiscInBuf[MB_offsetSSL_17] & MB_bOffset_SSL_17) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind17_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind18_stVal,  ucMDiscInBuf[MB_offsetSSL_18] & MB_bOffset_SSL_18) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind18_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind19_stVal,  ucMDiscInBuf[MB_offsetSSL_19] & MB_bOffset_SSL_19) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind19_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind20_stVal,  ucMDiscInBuf[MB_offsetSSL_20] & MB_bOffset_SSL_20) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind20_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind21_stVal,  ucMDiscInBuf[MB_offsetSSL_21] & MB_bOffset_SSL_21) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind21_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind22_stVal,  ucMDiscInBuf[MB_offsetSSL_22] & MB_bOffset_SSL_22) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind22_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind23_stVal,  ucMDiscInBuf[MB_offsetSSL_23] & MB_bOffset_SSL_23) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind23_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind24_stVal,  ucMDiscInBuf[MB_offsetSSL_24] & MB_bOffset_SSL_24) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind24_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind25_stVal,  ucMDiscInBuf[MB_offsetSSL_25] & MB_bOffset_SSL_25) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind25_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind26_stVal,  ucMDiscInBuf[MB_offsetSSL_26] & MB_bOffset_SSL_26) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind26_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind27_stVal,  ucMDiscInBuf[MB_offsetSSL_27] & MB_bOffset_SSL_27) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind27_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind28_stVal,  ucMDiscInBuf[MB_offsetSSL_28] & MB_bOffset_SSL_28) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind28_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind29_stVal,  ucMDiscInBuf[MB_offsetSSL_29] & MB_bOffset_SSL_29) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind29_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind30_stVal,  ucMDiscInBuf[MB_offsetSSL_30] & MB_bOffset_SSL_30) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind30_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind31_stVal,  ucMDiscInBuf[MB_offsetSSL_31] & MB_bOffset_SSL_31) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind31_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind32_stVal,  ucMDiscInBuf[MB_offsetSSL_32] & MB_bOffset_SSL_32) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind32_t, currentTime);


	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind1_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind2_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind3_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind4_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind5_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind6_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind7_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind8_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind9_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind10_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind11_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind12_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind13_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind14_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind15_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind16_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind17_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind18_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind19_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind20_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind21_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind22_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind23_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind24_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind25_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind26_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind27_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind28_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind29_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind30_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind31_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind32_q,0);

}

/*******************************************************
 * Set_VLSGGIO наполняем оперативными данными
 *******************************************************/
void	Set_VLSGGIO	(uint8_t num, uint64_t currentTime )
{

	uint32_t	Mod = STVALINT32_ON;

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Mod_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_Mod_t, currentTime);
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Beh_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_Beh_t, currentTime);


	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetVLS_1] & MB_bOffset_VLS_1) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind1_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetVLS_2] & MB_bOffset_VLS_2) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind2_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetVLS_3] & MB_bOffset_VLS_3) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind3_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetVLS_4] & MB_bOffset_VLS_4) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind4_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetVLS_5] & MB_bOffset_VLS_5) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind5_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetVLS_6] & MB_bOffset_VLS_6) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind6_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetVLS_7] & MB_bOffset_VLS_7) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind7_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetVLS_8] & MB_bOffset_VLS_8) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind8_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind9_stVal,  ucMDiscInBuf[MB_offsetVLS_9] & MB_bOffset_VLS_9) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind9_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind10_stVal,  ucMDiscInBuf[MB_offsetVLS_10] & MB_bOffset_VLS_10) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind10_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind11_stVal,  ucMDiscInBuf[MB_offsetVLS_11] & MB_bOffset_VLS_11) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind11_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind12_stVal,  ucMDiscInBuf[MB_offsetVLS_12] & MB_bOffset_VLS_12) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind12_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind13_stVal,  ucMDiscInBuf[MB_offsetVLS_13] & MB_bOffset_VLS_13) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind13_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind14_stVal,  ucMDiscInBuf[MB_offsetVLS_14] & MB_bOffset_VLS_14) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind14_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind15_stVal,  ucMDiscInBuf[MB_offsetVLS_15] & MB_bOffset_VLS_15) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind15_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind16_stVal,  ucMDiscInBuf[MB_offsetVLS_16] & MB_bOffset_VLS_16) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind16_t, currentTime);



	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind1_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind2_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind3_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind4_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind5_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind6_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind7_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind8_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind9_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind10_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind11_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind12_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind13_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind14_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind15_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind16_q,0);


}

/*******************************************************
 * Set_LSGGIO наполняем оперативными данными
 *******************************************************/
void	Set_LSGGIO	(uint8_t num, uint64_t currentTime )
{

	uint32_t	Mod = STVALINT32_ON;

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Mod_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_Mod_t, currentTime);
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Beh_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_Beh_t, currentTime);


	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetLS_1] & MB_bOffset_LS_1) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind1_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetLS_2] & MB_bOffset_LS_2) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind2_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetLS_3] & MB_bOffset_LS_3) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind3_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetLS_4] & MB_bOffset_LS_4) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind4_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetLS_5] & MB_bOffset_LS_5) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind5_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetLS_6] & MB_bOffset_LS_6) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind6_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetLS_7] & MB_bOffset_LS_7) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind7_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetLS_8] & MB_bOffset_LS_8) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind8_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind9_stVal,  ucMDiscInBuf[MB_offsetLS_9] & MB_bOffset_LS_9) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind9_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind10_stVal,  ucMDiscInBuf[MB_offsetLS_10] & MB_bOffset_LS_10) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind10_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind11_stVal,  ucMDiscInBuf[MB_offsetLS_11] & MB_bOffset_LS_11) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind11_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind12_stVal,  ucMDiscInBuf[MB_offsetLS_12] & MB_bOffset_LS_12) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind12_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind13_stVal,  ucMDiscInBuf[MB_offsetLS_13] & MB_bOffset_LS_13) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind13_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind14_stVal,  ucMDiscInBuf[MB_offsetLS_14] & MB_bOffset_LS_14) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind14_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind15_stVal,  ucMDiscInBuf[MB_offsetLS_15] & MB_bOffset_LS_15) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind15_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind16_stVal,  ucMDiscInBuf[MB_offsetLS_16] & MB_bOffset_LS_16) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind16_t, currentTime);



	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind1_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind2_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind3_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind4_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind5_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind6_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind7_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind8_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind9_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind10_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind11_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind12_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind13_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind14_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind15_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind16_q,0);


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

extern 	uint16_t   ucMUstavkiInBuf[MB_NumbUstavki];
extern  uint16_t   ucMDiscInBuf[MB_NumbDiscreet];


/*******************************************************
 * Set_VZGGIO наполняем оперативными данными
 *******************************************************/
void	Set_VZGGIO	(uint8_t num, uint64_t currentTime )
{

	//  Mod Beh
				uint32_t	Mod;
				if (ucMUstavkiInBuf[MB_offset_Ext_1 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO1_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO1_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Ext_2 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO2_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO2_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Ext_3 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO3_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO3_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Ext_4 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO4_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO4_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Ext_5 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO5_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO5_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Ext_6 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO6_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO6_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Ext_7 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO7_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO7_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Ext_8 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO8_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO8_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Ext_9 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO9_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO9_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO9_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO9_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Ext_10 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO10_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO10_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO10_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO10_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Ext_11 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO11_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO11_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO11_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO11_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Ext_12 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO12_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO12_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO12_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO12_Beh_t, currentTime);


				if (ucMUstavkiInBuf[MB_offset_Ext_13 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO13_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO13_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO13_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO13_Beh_t, currentTime);


				if (ucMUstavkiInBuf[MB_offset_Ext_14 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO14_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO14_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO14_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO14_Beh_t, currentTime);


				if (ucMUstavkiInBuf[MB_offset_Ext_15 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO15_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO15_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO15_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO15_Beh_t, currentTime);


				if (ucMUstavkiInBuf[MB_offset_Ext_16 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO16_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO16_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO16_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO16_Beh_t, currentTime);

	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO9_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO9_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO9_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO10_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO10_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO10_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO11_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO11_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO11_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO12_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO12_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO12_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO13_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO13_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO13_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO14_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO14_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO14_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO15_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO15_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO15_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO16_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO16_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO16_Health_q,Qual);

//				uint32_t	Alm;

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_1] & MB_b_SRAB_ext_1))		// СРАБ >1
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_2] & MB_b_SRAB_ext_2))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_3] & MB_b_SRAB_ext_3))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_4] & MB_b_SRAB_ext_4))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_5] & MB_b_SRAB_ext_5))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_6] & MB_b_SRAB_ext_6))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_7] & MB_b_SRAB_ext_7))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_8] & MB_b_SRAB_ext_8))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO9_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_9] & MB_b_SRAB_ext_9))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO9_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO9_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO10_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_10] & MB_b_SRAB_ext_10))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO10_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO10_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO11_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_11] & MB_b_SRAB_ext_11))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO11_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO11_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO12_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_12] & MB_b_SRAB_ext_12))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO12_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO12_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO13_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_13] & MB_b_SRAB_ext_13))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO13_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO13_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO14_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_14] & MB_b_SRAB_ext_14))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO14_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO14_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO15_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_15] & MB_b_SRAB_ext_15))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO15_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO15_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO16_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_16] & MB_b_SRAB_ext_16))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO16_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO16_Alm_q,0);

}
/*******************************************************
 * Set_AVRGGIO наполняем оперативными данными
 *******************************************************/
#if defined	(MR761) || defined	(MR762) || defined	(MR763)

void	Set_AVRGGIO	(uint8_t num, uint64_t currentTime )
{
	uint64_t diskreet;
	uint32_t BLKAVR,BLKAVR1;
	uint32_t	Mod;


	//  Mod Beh


				if ((ucMUstavkiInBuf[MB_StartConfigAWR + MB_offset_ConfAWR] & MB_bOffset_AWR_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}



				BLKAVR = ucMUstavkiInBuf[MB_StartConfigAWR + MB_offset_InBlok];						// номер дискрета
				if (BLKAVR) {

					diskreet = (uint64_t)ucMDiscInBuf[0] | (uint64_t)ucMDiscInBuf[1]<<16 | (uint64_t)ucMDiscInBuf[2]<<32 | (uint64_t)ucMDiscInBuf[3]<<48;

					BLKAVR1 = (BLKAVR - 1)%2;
					BLKAVR = (BLKAVR - 1)/2;

					if (BLKAVR1 > 0) {							// если не ровно поделился то инверсное состояние
						if ((diskreet & 1<<BLKAVR) == 0) Mod = STVALINT32_BLOCKED;
					} else{
						if ((diskreet & 1<<BLKAVR)>0) Mod = STVALINT32_BLOCKED;
					}
				}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_AVRGGIO_Mod_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_AVRGGIO_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_AVRGGIO_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_AVRGGIO_Beh_t, currentTime);

	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_AVRGGIO_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_AVRGGIO_Beh_q,Qual);

				uint8_t	awr=0;
					if(ucMDiscInBuf[MB_offset_AWR] & MB_b_ON_AWR)  awr = 1;
					if(ucMDiscInBuf[MB_offset_AWR] & MB_b_OFF_AWR) awr = 2;
					if(ucMDiscInBuf[MB_offset_AWR] & MB_b_Blok_AWR) awr = 3;

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_AVRGGIO_IntIn_stVal, awr))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_AVRGGIO_IntIn_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_AVRGGIO_IntIn_q,0);
}

void	Set_NBLKGGIO	(uint8_t num, uint64_t currentTime )
{
	uint64_t diskreet;
	uint32_t BLKAVR,BLKAVR1;
	uint32_t	Mod = STVALINT32_OFF;


	//  Mod Beh

				if (ucMUstavkiInBuf[MB_offset_BlkNStartMot + MB_offset_BlkNStartMot_Hot] >0) {Mod = STVALINT32_ON;}
				if (ucMUstavkiInBuf[MB_offset_BlkNStartMot + MB_offset_BlkNStartMot_Cold] >0) {Mod = STVALINT32_ON;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_NBLKGGIO1_Mod_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_NBLKGGIO1_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_NBLKGGIO1_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_NBLKGGIO1_Beh_t, currentTime);

	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				IedServer_updateQuality(iedServer,&iedModel_PROT_NBLKGGIO1_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_NBLKGGIO1_Beh_q,Qual);

				uint8_t	nblk=0;
					if(ucMDiscInBuf[MB_offset_BlkN] & MB_b_BlkQ)  nblk = 1;

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_NBLKGGIO1_IntIn_stVal, nblk))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_NBLKGGIO1_IntIn_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_NBLKGGIO1_IntIn_q,0);
}
#endif
/*******************************************************
 * Set_XCBRGGIO наполняем оперативными данными
 *******************************************************/
void	Set_XCBRGGIO	(uint8_t num, uint64_t currentTime )
{
	//--------------------------------
	// сброс флагов

		if (ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetError){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_stVal,  1))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_stVal,  0))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_q,0);
		}
		if (ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetSysNote){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_stVal,  1))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_stVal,  0))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_q,0);
		}
		if (ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetErrorNote){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_stVal,  1))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_stVal,  0))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_q,0);
		}

}

/*******************************************************
 * Set_INGGIO наполняем оперативными данными
 *******************************************************/
void	Set_INGGIO	(uint8_t num, uint64_t currentTime )
{
	//  Mod Beh

				uint32_t	Mod = STVALINT32_ON;

				if (
						(ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule2) ||
						(ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule3)
					) {Mod = STVALINT32_OFF;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Beh_t, currentTime);



				if (ucMDiscInBuf[MB_offset_errorM2] & MB_bOffsetModule2){	// 8D
				    	    IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind1_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
				    	    IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind2_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
				    	    IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind3_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
				    	    IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind4_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
				    	    IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind5_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
				    	    IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind6_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
				    	    IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind7_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
				    	    IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind8_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
				} else
				{
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind1_q,0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind2_q,0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind3_q,0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind4_q,0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind5_q,0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind6_q,0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind7_q,0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind8_q,0);

				}

							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetDiscreet_1] & MB_bOffset_Discreet_1))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind1_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetDiscreet_2] & MB_bOffset_Discreet_2))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind2_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetDiscreet_3] & MB_bOffset_Discreet_3))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind3_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetDiscreet_4] & MB_bOffset_Discreet_4))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind4_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetDiscreet_5] & MB_bOffset_Discreet_5))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind5_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetDiscreet_6] & MB_bOffset_Discreet_6))
					       	     IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind6_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetDiscreet_7] & MB_bOffset_Discreet_7))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind7_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetDiscreet_8] & MB_bOffset_Discreet_8))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind8_t, currentTime);


				if (ucMDiscInBuf[MB_offset_errorM3] & MB_bOffsetModule3){	// 16D
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind9_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind10_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind11_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind12_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind13_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind14_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind15_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind16_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind17_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind18_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind19_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind20_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind21_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind22_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind23_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind24_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);

				} else{
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind9_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind10_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind11_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind12_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind13_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind14_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind15_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind16_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind17_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind18_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind19_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind20_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind21_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind22_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind23_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind24_q,0 | 0);

				}

							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind9_stVal,  ucMDiscInBuf[MB_offsetDiscreet_9] & MB_bOffset_Discreet_9))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind9_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind10_stVal,  ucMDiscInBuf[MB_offsetDiscreet_10] & MB_bOffset_Discreet_10))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind10_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind11_stVal,  ucMDiscInBuf[MB_offsetDiscreet_11] & MB_bOffset_Discreet_11))
					       	     IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind11_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind12_stVal,  ucMDiscInBuf[MB_offsetDiscreet_12] & MB_bOffset_Discreet_12))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind12_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind13_stVal,  ucMDiscInBuf[MB_offsetDiscreet_13] & MB_bOffset_Discreet_13))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind13_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind14_stVal,  ucMDiscInBuf[MB_offsetDiscreet_14] & MB_bOffset_Discreet_14))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind14_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind15_stVal,  ucMDiscInBuf[MB_offsetDiscreet_15] & MB_bOffset_Discreet_15))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind15_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind16_stVal,  ucMDiscInBuf[MB_offsetDiscreet_16] & MB_bOffset_Discreet_16))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind16_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind17_stVal,  ucMDiscInBuf[MB_offsetDiscreet_17] & MB_bOffset_Discreet_17))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind17_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind18_stVal,  ucMDiscInBuf[MB_offsetDiscreet_18] & MB_bOffset_Discreet_18))
							 	 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind18_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind19_stVal,  ucMDiscInBuf[MB_offsetDiscreet_19] & MB_bOffset_Discreet_19))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind19_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind20_stVal,  ucMDiscInBuf[MB_offsetDiscreet_20] & MB_bOffset_Discreet_20))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind20_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind21_stVal,  ucMDiscInBuf[MB_offsetDiscreet_21] & MB_bOffset_Discreet_21))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind21_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind22_stVal,  ucMDiscInBuf[MB_offsetDiscreet_22] & MB_bOffset_Discreet_22))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind22_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind23_stVal,  ucMDiscInBuf[MB_offsetDiscreet_23] & MB_bOffset_Discreet_23))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind23_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind24_stVal,  ucMDiscInBuf[MB_offsetDiscreet_24] & MB_bOffset_Discreet_24))
		       	        	     IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind24_t, currentTime);

				if (ucMDiscInBuf[MB_offset_errorM4] & MB_bOffsetModule4){	// 16D
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind25_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind26_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind27_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind28_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind29_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind30_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind31_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind32_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind33_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind34_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind35_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind36_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind37_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind38_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind39_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind40_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind41_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind42_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);

				} else{
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind25_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind26_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind27_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind28_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind29_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind30_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind31_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind32_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind33_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind34_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind35_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind36_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind37_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind38_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind39_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind40_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind41_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind42_q,0 | 0);

				}

							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind25_stVal,  ucMDiscInBuf[MB_offsetDiscreet_25] & MB_bOffset_Discreet_25))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind25_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind26_stVal,  ucMDiscInBuf[MB_offsetDiscreet_26] & MB_bOffset_Discreet_26))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind26_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind27_stVal,  ucMDiscInBuf[MB_offsetDiscreet_27] & MB_bOffset_Discreet_27))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind27_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind28_stVal,  ucMDiscInBuf[MB_offsetDiscreet_28] & MB_bOffset_Discreet_28))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind28_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind29_stVal,  ucMDiscInBuf[MB_offsetDiscreet_29] & MB_bOffset_Discreet_29))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind29_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind30_stVal,  ucMDiscInBuf[MB_offsetDiscreet_30] & MB_bOffset_Discreet_30))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind30_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind31_stVal,  ucMDiscInBuf[MB_offsetDiscreet_31] & MB_bOffset_Discreet_31))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind31_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind32_stVal,  ucMDiscInBuf[MB_offsetDiscreet_32] & MB_bOffset_Discreet_32))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind32_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind33_stVal,  ucMDiscInBuf[MB_offsetDiscreet_33] & MB_bOffset_Discreet_33))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind33_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind34_stVal,  ucMDiscInBuf[MB_offsetDiscreet_34] & MB_bOffset_Discreet_34))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind34_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind35_stVal,  ucMDiscInBuf[MB_offsetDiscreet_35] & MB_bOffset_Discreet_35))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind35_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind36_stVal,  ucMDiscInBuf[MB_offsetDiscreet_36] & MB_bOffset_Discreet_36))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind36_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind37_stVal,  ucMDiscInBuf[MB_offsetDiscreet_37] & MB_bOffset_Discreet_37))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind37_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind38_stVal,  ucMDiscInBuf[MB_offsetDiscreet_38] & MB_bOffset_Discreet_38))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind38_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind39_stVal,  ucMDiscInBuf[MB_offsetDiscreet_39] & MB_bOffset_Discreet_39))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind39_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind40_stVal,  ucMDiscInBuf[MB_offsetDiscreet_40] & MB_bOffset_Discreet_40))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind40_t, currentTime);

							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind41_stVal,  ucMDiscInBuf[MB_offsetDiscreet_41] & MB_bOffset_Discreet_41))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind41_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind42_stVal,  ucMDiscInBuf[MB_offsetDiscreet_42] & MB_bOffset_Discreet_42))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind42_t, currentTime);


}

/*******************************************************
 * Set_OUTGGIO наполняем оперативными данными
 *******************************************************/
void	Set_OUTGGIO	(uint8_t num, uint64_t currentTime )
{

	uint32_t	Mod = STVALINT32_ON;

	if (
			(ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule1) ||
			(ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule2)
		) {Mod = STVALINT32_OFF;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Mod_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Mod_t, currentTime);
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Beh_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Beh_t, currentTime);


	if (ucMDiscInBuf[MB_offset_errorM1] & MB_bOffsetModule1){	// 11R
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);

		}else{
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_q,0);

		}

		if (ucMDiscInBuf[MB_offset_errorM2] & MB_bOffsetModule2) //8 реле
		{
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO15_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO16_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO17_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO18_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);

		} else{

			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO15_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO16_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO17_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO18_q,0);

		}
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_stVal,  ucMDiscInBuf[MB_offsetRelay_1] & MB_bOffset_Relay_1))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_stVal,  ucMDiscInBuf[MB_offsetRelay_2] & MB_bOffset_Relay_2))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_stVal,  ucMDiscInBuf[MB_offsetRelay_3] & MB_bOffset_Relay_3))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_stVal,  ucMDiscInBuf[MB_offsetRelay_4] & MB_bOffset_Relay_4))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_stVal,  ucMDiscInBuf[MB_offsetRelay_5] & MB_bOffset_Relay_5))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_stVal,  ucMDiscInBuf[MB_offsetRelay_6] & MB_bOffset_Relay_6))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_stVal,  ucMDiscInBuf[MB_offsetRelay_7] & MB_bOffset_Relay_7))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_stVal,  ucMDiscInBuf[MB_offsetRelay_8] & MB_bOffset_Relay_8))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_stVal,  ucMDiscInBuf[MB_offsetRelay_9] & MB_bOffset_Relay_9))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_stVal,  ucMDiscInBuf[MB_offsetRelay_10] & MB_bOffset_Relay_10))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_stVal,  ucMDiscInBuf[MB_offsetRelay_11] & MB_bOffset_Relay_11))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_stVal,  ucMDiscInBuf[MB_offsetRelay_12] & MB_bOffset_Relay_12))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_stVal,  ucMDiscInBuf[MB_offsetRelay_13] & MB_bOffset_Relay_13))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_stVal,  ucMDiscInBuf[MB_offsetRelay_14] & MB_bOffset_Relay_14))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO15_stVal,  ucMDiscInBuf[MB_offsetRelay_15] & MB_bOffset_Relay_15))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO15_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO16_stVal,  ucMDiscInBuf[MB_offsetRelay_16] & MB_bOffset_Relay_16))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO16_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO17_stVal,  ucMDiscInBuf[MB_offsetRelay_17] & MB_bOffset_Relay_17))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO17_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO18_stVal,  ucMDiscInBuf[MB_offsetRelay_18] & MB_bOffset_Relay_18))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO18_t, currentTime);

if (ucMDiscInBuf[MB_offset_errorM4] & MB_bOffsetModule4) //16 реле
		{
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO19_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO20_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO21_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO22_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO23_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO24_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO25_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO26_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);

			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO27_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO28_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO29_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO30_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO31_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO32_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO33_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO34_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);

		} else{

			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO19_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO20_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO21_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO22_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO23_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO24_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO25_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO26_q,0);

			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO27_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO28_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO29_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO30_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO31_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO32_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO33_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO34_q,0);

		}
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_stVal,  ucMDiscInBuf[MB_offsetRelay_1] & MB_bOffset_Relay_1))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_stVal,  ucMDiscInBuf[MB_offsetRelay_2] & MB_bOffset_Relay_2))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_stVal,  ucMDiscInBuf[MB_offsetRelay_3] & MB_bOffset_Relay_3))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_stVal,  ucMDiscInBuf[MB_offsetRelay_4] & MB_bOffset_Relay_4))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_stVal,  ucMDiscInBuf[MB_offsetRelay_5] & MB_bOffset_Relay_5))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_stVal,  ucMDiscInBuf[MB_offsetRelay_6] & MB_bOffset_Relay_6))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_stVal,  ucMDiscInBuf[MB_offsetRelay_7] & MB_bOffset_Relay_7))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_stVal,  ucMDiscInBuf[MB_offsetRelay_8] & MB_bOffset_Relay_8))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_stVal,  ucMDiscInBuf[MB_offsetRelay_9] & MB_bOffset_Relay_9))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_stVal,  ucMDiscInBuf[MB_offsetRelay_10] & MB_bOffset_Relay_10))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_stVal,  ucMDiscInBuf[MB_offsetRelay_11] & MB_bOffset_Relay_11))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_stVal,  ucMDiscInBuf[MB_offsetRelay_12] & MB_bOffset_Relay_12))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_stVal,  ucMDiscInBuf[MB_offsetRelay_13] & MB_bOffset_Relay_13))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_stVal,  ucMDiscInBuf[MB_offsetRelay_14] & MB_bOffset_Relay_14))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO15_stVal,  ucMDiscInBuf[MB_offsetRelay_15] & MB_bOffset_Relay_15))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO15_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO16_stVal,  ucMDiscInBuf[MB_offsetRelay_16] & MB_bOffset_Relay_16))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO16_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO17_stVal,  ucMDiscInBuf[MB_offsetRelay_17] & MB_bOffset_Relay_17))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO17_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO18_stVal,  ucMDiscInBuf[MB_offsetRelay_18] & MB_bOffset_Relay_18))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO18_t, currentTime);

			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO19_stVal,  ucMDiscInBuf[MB_offsetRelay_19] & MB_bOffset_Relay_19))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO19_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO20_stVal,  ucMDiscInBuf[MB_offsetRelay_20] & MB_bOffset_Relay_20))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO20_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO21_stVal,  ucMDiscInBuf[MB_offsetRelay_21] & MB_bOffset_Relay_21))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO21_t, currentTime);

			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO22_stVal,  ucMDiscInBuf[MB_offsetRelay_22] & MB_bOffset_Relay_22))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO22_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO23_stVal,  ucMDiscInBuf[MB_offsetRelay_23] & MB_bOffset_Relay_23))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO23_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO24_stVal,  ucMDiscInBuf[MB_offsetRelay_24] & MB_bOffset_Relay_24))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO24_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO25_stVal,  ucMDiscInBuf[MB_offsetRelay_25] & MB_bOffset_Relay_25))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO25_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO26_stVal,  ucMDiscInBuf[MB_offsetRelay_26] & MB_bOffset_Relay_26))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO26_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO27_stVal,  ucMDiscInBuf[MB_offsetRelay_27] & MB_bOffset_Relay_27))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO27_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO28_stVal,  ucMDiscInBuf[MB_offsetRelay_28] & MB_bOffset_Relay_28))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO28_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO29_stVal,  ucMDiscInBuf[MB_offsetRelay_29] & MB_bOffset_Relay_29))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO29_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO30_stVal,  ucMDiscInBuf[MB_offsetRelay_30] & MB_bOffset_Relay_30))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO30_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO31_stVal,  ucMDiscInBuf[MB_offsetRelay_31] & MB_bOffset_Relay_31))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO31_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO32_stVal,  ucMDiscInBuf[MB_offsetRelay_32] & MB_bOffset_Relay_32))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO32_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO33_stVal,  ucMDiscInBuf[MB_offsetRelay_33] & MB_bOffset_Relay_33))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO33_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO34_stVal,  ucMDiscInBuf[MB_offsetRelay_34] & MB_bOffset_Relay_34))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO34_t, currentTime);

}

/*******************************************************
 * Set_LEDGGIO наполняем оперативными данными
 *******************************************************/
void	Set_LEDGGIO	(uint8_t num, uint64_t currentTime )
{
	bool value;
	uint32_t	Mod = STVALINT32_ON;

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Mod_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_Mod_t, currentTime);
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Beh_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_Beh_t, currentTime);


	// статус сброса нидикаторов
	if (
			(ucMDiscInBuf[MB_offsetLED_1g] & MB_bOffset_LED_1g) ||
			(ucMDiscInBuf[MB_offsetLED_2g] & MB_bOffset_LED_2g) ||
			(ucMDiscInBuf[MB_offsetLED_3g] & MB_bOffset_LED_3g) ||
			(ucMDiscInBuf[MB_offsetLED_4g] & MB_bOffset_LED_4g) ||
			(ucMDiscInBuf[MB_offsetLED_5g] & MB_bOffset_LED_5g) ||
			(ucMDiscInBuf[MB_offsetLED_6g] & MB_bOffset_LED_6g) ||
			(ucMDiscInBuf[MB_offsetLED_7g] & MB_bOffset_LED_7g) ||
			(ucMDiscInBuf[MB_offsetLED_8g] & MB_bOffset_LED_8g) ||
			(ucMDiscInBuf[MB_offsetLED_9g] & MB_bOffset_LED_9g) ||
			(ucMDiscInBuf[MB_offsetLED_10g] & MB_bOffset_LED_10g) ||
			(ucMDiscInBuf[MB_offsetLED_11g] & MB_bOffset_LED_11g) ||
			(ucMDiscInBuf[MB_offsetLED_12g] & MB_bOffset_LED_12g) ||
			(ucMDiscInBuf[MB_offsetLED_1r] & MB_bOffset_LED_1g) ||
			(ucMDiscInBuf[MB_offsetLED_2r] & MB_bOffset_LED_2g) ||
			(ucMDiscInBuf[MB_offsetLED_3r] & MB_bOffset_LED_3g) ||
			(ucMDiscInBuf[MB_offsetLED_4r] & MB_bOffset_LED_4g) ||
			(ucMDiscInBuf[MB_offsetLED_5r] & MB_bOffset_LED_5g) ||
			(ucMDiscInBuf[MB_offsetLED_6r] & MB_bOffset_LED_6g) ||
			(ucMDiscInBuf[MB_offsetLED_7r] & MB_bOffset_LED_7g) ||
			(ucMDiscInBuf[MB_offsetLED_8r] & MB_bOffset_LED_8g) ||
			(ucMDiscInBuf[MB_offsetLED_9r] & MB_bOffset_LED_9g) ||
			(ucMDiscInBuf[MB_offsetLED_10r] & MB_bOffset_LED_10g) ||
			(ucMDiscInBuf[MB_offsetLED_11r] & MB_bOffset_LED_11g) ||
			(ucMDiscInBuf[MB_offsetLED_12r] & MB_bOffset_LED_12g)
			)
	{
		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_stVal,  1))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_t, currentTime);
		IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_q,0);

	} else{
		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_stVal,  0))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_t, currentTime);
		IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_q,0);

	}
	value = ((ucMDiscInBuf[MB_offsetLED_1g] & MB_bOffset_LED_1g) || (ucMDiscInBuf[MB_offsetLED_1r] & MB_bOffset_LED_1r));
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_stVal,  value) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_t, currentTime);
	value = ((ucMDiscInBuf[MB_offsetLED_2g] & MB_bOffset_LED_2g) || (ucMDiscInBuf[MB_offsetLED_2r] & MB_bOffset_LED_2r));
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_stVal,  value) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_t, currentTime);
	value = ((ucMDiscInBuf[MB_offsetLED_3g] & MB_bOffset_LED_3g) || (ucMDiscInBuf[MB_offsetLED_3r] & MB_bOffset_LED_3r));
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_stVal,  value) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_t, currentTime);
	value = ((ucMDiscInBuf[MB_offsetLED_4g] & MB_bOffset_LED_4g) || (ucMDiscInBuf[MB_offsetLED_4r] & MB_bOffset_LED_4r));
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_stVal,  value) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_t, currentTime);
	value = ((ucMDiscInBuf[MB_offsetLED_5g] & MB_bOffset_LED_5g) || (ucMDiscInBuf[MB_offsetLED_5r] & MB_bOffset_LED_5r));
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_stVal,  value) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_t, currentTime);
	value = ((ucMDiscInBuf[MB_offsetLED_6g] & MB_bOffset_LED_6g) || (ucMDiscInBuf[MB_offsetLED_6r] & MB_bOffset_LED_6r));
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_stVal,  value) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_t, currentTime);
	value = ((ucMDiscInBuf[MB_offsetLED_7g] & MB_bOffset_LED_7g) || (ucMDiscInBuf[MB_offsetLED_7r] & MB_bOffset_LED_7r));
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_stVal,  value) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_t, currentTime);
	value = ((ucMDiscInBuf[MB_offsetLED_8g] & MB_bOffset_LED_8g) || (ucMDiscInBuf[MB_offsetLED_8r] & MB_bOffset_LED_8r));
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_stVal,  value) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_t, currentTime);
	value = ((ucMDiscInBuf[MB_offsetLED_9g] & MB_bOffset_LED_9g) || (ucMDiscInBuf[MB_offsetLED_9r] & MB_bOffset_LED_9r));
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_stVal,  value) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_t, currentTime);
	value = ((ucMDiscInBuf[MB_offsetLED_10g] & MB_bOffset_LED_10g) || (ucMDiscInBuf[MB_offsetLED_10r] & MB_bOffset_LED_10r));
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_stVal, value) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_t, currentTime);
	value = ((ucMDiscInBuf[MB_offsetLED_11g] & MB_bOffset_LED_11g) || (ucMDiscInBuf[MB_offsetLED_11r] & MB_bOffset_LED_11r));
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_stVal, value) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_t, currentTime);
	value = ((ucMDiscInBuf[MB_offsetLED_12g] & MB_bOffset_LED_12g) || (ucMDiscInBuf[MB_offsetLED_12r] & MB_bOffset_LED_12r));
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_stVal, value) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_t, currentTime);

	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind13_stVal,  ucMDiscInBuf[MB_offsetLED_13] & MB_bOffset_LED_13) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind13_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind14_stVal,  ucMDiscInBuf[MB_offsetLED_14] & MB_bOffset_LED_14) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind14_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind15_stVal,  ucMDiscInBuf[MB_offsetLED_15] & MB_bOffset_LED_15) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind15_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind16_stVal,  ucMDiscInBuf[MB_offsetLED_16] & MB_bOffset_LED_16) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind16_t, currentTime);


	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_q,0);

	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind13_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind14_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind15_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind16_q,0);

	//--------------------------------
	// сброс флагов

		if (ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetError){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_stVal,  1))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_stVal,  0))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_q,0);
		}
		if (ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetSysNote){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_stVal,  1))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_stVal,  0))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_q,0);
		}
		if (ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetErrorNote){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_stVal,  1))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_stVal,  0))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_q,0);
		}
}

/*******************************************************
 * Set_SSLGGIO наполняем оперативными данными
 *******************************************************/
void	Set_SSLGGIO	(uint8_t num, uint64_t currentTime )
{

	uint32_t	Mod = STVALINT32_ON;

	IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Mod_stVal, Mod);
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_Mod_t, currentTime);
	IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Beh_stVal, Mod);
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_Beh_t, currentTime);


	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetSSL_1] & MB_bOffset_SSL_1) > 0)
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind1_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetSSL_2] & MB_bOffset_SSL_2) > 0)
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind2_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetSSL_3] & MB_bOffset_SSL_3) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind3_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetSSL_4] & MB_bOffset_SSL_4) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind4_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetSSL_5] & MB_bOffset_SSL_5) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind5_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetSSL_6] & MB_bOffset_SSL_6) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind6_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetSSL_7] & MB_bOffset_SSL_7) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind7_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetSSL_8] & MB_bOffset_SSL_8) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind8_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind9_stVal,  ucMDiscInBuf[MB_offsetSSL_9] & MB_bOffset_SSL_9) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind9_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind10_stVal,  ucMDiscInBuf[MB_offsetSSL_10] & MB_bOffset_SSL_10) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind10_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind11_stVal,  ucMDiscInBuf[MB_offsetSSL_11] & MB_bOffset_SSL_11) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind11_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind12_stVal,  ucMDiscInBuf[MB_offsetSSL_12] & MB_bOffset_SSL_12) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind12_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind13_stVal,  ucMDiscInBuf[MB_offsetSSL_13] & MB_bOffset_SSL_13) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind13_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind14_stVal,  ucMDiscInBuf[MB_offsetSSL_14] & MB_bOffset_SSL_14) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind14_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind15_stVal,  ucMDiscInBuf[MB_offsetSSL_15] & MB_bOffset_SSL_15) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind15_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind16_stVal,  ucMDiscInBuf[MB_offsetSSL_16] & MB_bOffset_SSL_16) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind16_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind17_stVal,  ucMDiscInBuf[MB_offsetSSL_17] & MB_bOffset_SSL_17) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind17_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind18_stVal,  ucMDiscInBuf[MB_offsetSSL_18] & MB_bOffset_SSL_18) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind18_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind19_stVal,  ucMDiscInBuf[MB_offsetSSL_19] & MB_bOffset_SSL_19) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind19_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind20_stVal,  ucMDiscInBuf[MB_offsetSSL_20] & MB_bOffset_SSL_20) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind20_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind21_stVal,  ucMDiscInBuf[MB_offsetSSL_21] & MB_bOffset_SSL_21) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind21_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind22_stVal,  ucMDiscInBuf[MB_offsetSSL_22] & MB_bOffset_SSL_22) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind22_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind23_stVal,  ucMDiscInBuf[MB_offsetSSL_23] & MB_bOffset_SSL_23) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind23_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind24_stVal,  ucMDiscInBuf[MB_offsetSSL_24] & MB_bOffset_SSL_24) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind24_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind25_stVal,  ucMDiscInBuf[MB_offsetSSL_25] & MB_bOffset_SSL_25) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind25_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind26_stVal,  ucMDiscInBuf[MB_offsetSSL_26] & MB_bOffset_SSL_26) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind26_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind27_stVal,  ucMDiscInBuf[MB_offsetSSL_27] & MB_bOffset_SSL_27) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind27_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind28_stVal,  ucMDiscInBuf[MB_offsetSSL_28] & MB_bOffset_SSL_28) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind28_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind29_stVal,  ucMDiscInBuf[MB_offsetSSL_29] & MB_bOffset_SSL_29) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind29_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind30_stVal,  ucMDiscInBuf[MB_offsetSSL_30] & MB_bOffset_SSL_30) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind30_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind31_stVal,  ucMDiscInBuf[MB_offsetSSL_31] & MB_bOffset_SSL_31) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind31_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind32_stVal,  ucMDiscInBuf[MB_offsetSSL_32] & MB_bOffset_SSL_32) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind32_t, currentTime);


	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind1_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind2_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind3_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind4_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind5_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind6_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind7_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind8_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind9_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind10_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind11_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind12_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind13_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind14_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind15_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind16_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind17_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind18_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind19_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind20_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind21_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind22_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind23_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind24_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind25_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind26_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind27_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind28_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind29_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind30_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind31_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind32_q,0);

}

/*******************************************************
 * Set_VLSGGIO наполняем оперативными данными
 *******************************************************/
void	Set_VLSGGIO	(uint8_t num, uint64_t currentTime )
{

	uint32_t	Mod = STVALINT32_ON;

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Mod_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_Mod_t, currentTime);
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Beh_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_Beh_t, currentTime);


	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetVLS_1] & MB_bOffset_VLS_1) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind1_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetVLS_2] & MB_bOffset_VLS_2) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind2_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetVLS_3] & MB_bOffset_VLS_3) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind3_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetVLS_4] & MB_bOffset_VLS_4) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind4_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetVLS_5] & MB_bOffset_VLS_5) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind5_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetVLS_6] & MB_bOffset_VLS_6) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind6_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetVLS_7] & MB_bOffset_VLS_7) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind7_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetVLS_8] & MB_bOffset_VLS_8) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind8_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind9_stVal,  ucMDiscInBuf[MB_offsetVLS_9] & MB_bOffset_VLS_9) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind9_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind10_stVal,  ucMDiscInBuf[MB_offsetVLS_10] & MB_bOffset_VLS_10) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind10_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind11_stVal,  ucMDiscInBuf[MB_offsetVLS_11] & MB_bOffset_VLS_11) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind11_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind12_stVal,  ucMDiscInBuf[MB_offsetVLS_12] & MB_bOffset_VLS_12) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind12_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind13_stVal,  ucMDiscInBuf[MB_offsetVLS_13] & MB_bOffset_VLS_13) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind13_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind14_stVal,  ucMDiscInBuf[MB_offsetVLS_14] & MB_bOffset_VLS_14) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind14_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind15_stVal,  ucMDiscInBuf[MB_offsetVLS_15] & MB_bOffset_VLS_15) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind15_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind16_stVal,  ucMDiscInBuf[MB_offsetVLS_16] & MB_bOffset_VLS_16) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind16_t, currentTime);



	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind1_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind2_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind3_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind4_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind5_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind6_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind7_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind8_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind9_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind10_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind11_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind12_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind13_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind14_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind15_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind16_q,0);


}

/*******************************************************
 * Set_LSGGIO наполняем оперативными данными
 *******************************************************/
void	Set_LSGGIO	(uint8_t num, uint64_t currentTime )
{

	uint32_t	Mod = STVALINT32_ON;

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Mod_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_Mod_t, currentTime);
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Beh_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_Beh_t, currentTime);


	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetLS_1] & MB_bOffset_LS_1) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind1_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetLS_2] & MB_bOffset_LS_2) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind2_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetLS_3] & MB_bOffset_LS_3) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind3_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetLS_4] & MB_bOffset_LS_4) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind4_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetLS_5] & MB_bOffset_LS_5) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind5_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetLS_6] & MB_bOffset_LS_6) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind6_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetLS_7] & MB_bOffset_LS_7) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind7_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetLS_8] & MB_bOffset_LS_8) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind8_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind9_stVal,  ucMDiscInBuf[MB_offsetLS_9] & MB_bOffset_LS_9) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind9_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind10_stVal,  ucMDiscInBuf[MB_offsetLS_10] & MB_bOffset_LS_10) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind10_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind11_stVal,  ucMDiscInBuf[MB_offsetLS_11] & MB_bOffset_LS_11) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind11_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind12_stVal,  ucMDiscInBuf[MB_offsetLS_12] & MB_bOffset_LS_12) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind12_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind13_stVal,  ucMDiscInBuf[MB_offsetLS_13] & MB_bOffset_LS_13) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind13_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind14_stVal,  ucMDiscInBuf[MB_offsetLS_14] & MB_bOffset_LS_14) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind14_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind15_stVal,  ucMDiscInBuf[MB_offsetLS_15] & MB_bOffset_LS_15) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind15_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind16_stVal,  ucMDiscInBuf[MB_offsetLS_16] & MB_bOffset_LS_16) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind16_t, currentTime);



	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind1_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind2_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind3_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind4_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind5_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind6_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind7_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind8_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind9_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind10_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind11_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind12_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind13_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind14_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind15_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind16_q,0);


}
#endif
/*******************************************************
 * MR901 MR901
 *******************************************************/
#if defined	(MR901) ||  defined	(MR902)
#include "static_model_MR901_902.h"


extern 	uint16_t   ucMUstavkiInBuf[MB_NumbUstavki];
extern  uint16_t   ucMDiscInBuf[MB_NumbDiscreet];


/*******************************************************
 * Set_VZGGIO наполняем оперативными данными
 *******************************************************/
void	Set_VZGGIO	(uint8_t num, uint64_t currentTime )
{

	//  Mod Beh
				uint32_t	Mod;
				if (ucMUstavkiInBuf[MB_offset_Ext_1 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO1_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO1_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Ext_2 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO2_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO2_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Ext_3 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO3_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO3_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Ext_4 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO4_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO4_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Ext_5 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO5_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO5_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Ext_6 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO6_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO6_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Ext_7 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO7_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO7_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Ext_8 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO8_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO8_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Ext_9 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO9_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO9_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO9_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO9_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Ext_10 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO10_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO10_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO10_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO10_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Ext_11 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO11_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO11_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO11_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO11_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Ext_12 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO12_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO12_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO12_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO12_Beh_t, currentTime);


				if (ucMUstavkiInBuf[MB_offset_Ext_13 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO13_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO13_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO13_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO13_Beh_t, currentTime);


				if (ucMUstavkiInBuf[MB_offset_Ext_14 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO14_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO14_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO14_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO14_Beh_t, currentTime);


				if (ucMUstavkiInBuf[MB_offset_Ext_15 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO15_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO15_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO15_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO15_Beh_t, currentTime);


				if (ucMUstavkiInBuf[MB_offset_Ext_16 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO16_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO16_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO16_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO16_Beh_t, currentTime);

	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO9_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO9_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO9_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO10_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO10_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO10_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO11_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO11_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO11_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO12_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO12_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO12_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO13_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO13_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO13_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO14_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO14_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO14_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO15_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO15_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO15_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO16_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO16_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO16_Health_q,Qual);

//				uint32_t	Alm;

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_1] & MB_b_SRAB_ext_1))		// СРАБ >1
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_2] & MB_b_SRAB_ext_2))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_3] & MB_b_SRAB_ext_3))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_4] & MB_b_SRAB_ext_4))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_5] & MB_b_SRAB_ext_5))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_6] & MB_b_SRAB_ext_6))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_7] & MB_b_SRAB_ext_7))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_8] & MB_b_SRAB_ext_8))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO9_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_9] & MB_b_SRAB_ext_9))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO9_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO9_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO10_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_10] & MB_b_SRAB_ext_10))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO10_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO10_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO11_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_11] & MB_b_SRAB_ext_11))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO11_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO11_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO12_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_12] & MB_b_SRAB_ext_12))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO12_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO12_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO13_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_13] & MB_b_SRAB_ext_13))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO13_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO13_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO14_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_14] & MB_b_SRAB_ext_14))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO14_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO14_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO15_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_15] & MB_b_SRAB_ext_15))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO15_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO15_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO16_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_16] & MB_b_SRAB_ext_16))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO16_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO16_Alm_q,0);

}

/*******************************************************
 * Set_XCBRGGIO наполняем оперативными данными
 *******************************************************/
void	Set_XCBRGGIO	(uint8_t num, uint64_t currentTime )
{
	//--------------------------------
	// сброс флагов

		if (ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetError){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_stVal,  1))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_stVal,  0))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_q,0);
		}
		if (ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetSysNote){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_stVal,  1))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_stVal,  0))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_q,0);
		}
		if (ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetErrorNote){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_stVal,  1))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_stVal,  0))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_q,0);
		}

}

/*******************************************************
 * Set_INGGIO наполняем оперативными данными
 *******************************************************/
void	Set_INGGIO	(uint8_t num, uint64_t currentTime )
{
	//  Mod Beh

				uint32_t	Mod = STVALINT32_ON;

				if (
						(ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule2) ||
						(ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule3)
					) {Mod = STVALINT32_OFF;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Beh_t, currentTime);



				if (ucMDiscInBuf[MB_offset_errorM2] & MB_bOffsetModule2){	// 8D
				    	    IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind1_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
				    	    IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind2_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
				    	    IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind3_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
				    	    IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind4_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
				    	    IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind5_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
				    	    IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind6_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
				    	    IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind7_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
				    	    IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind8_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
				} else
				{
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind1_q,0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind2_q,0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind3_q,0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind4_q,0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind5_q,0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind6_q,0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind7_q,0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind8_q,0);

				}

							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetDiscreet_1] & MB_bOffset_Discreet_1))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind1_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetDiscreet_2] & MB_bOffset_Discreet_2))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind2_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetDiscreet_3] & MB_bOffset_Discreet_3))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind3_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetDiscreet_4] & MB_bOffset_Discreet_4))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind4_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetDiscreet_5] & MB_bOffset_Discreet_5))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind5_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetDiscreet_6] & MB_bOffset_Discreet_6))
					       	     IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind6_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetDiscreet_7] & MB_bOffset_Discreet_7))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind7_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetDiscreet_8] & MB_bOffset_Discreet_8))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind8_t, currentTime);


				if (ucMDiscInBuf[MB_offset_errorM3] & MB_bOffsetModule3){	// 16D
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind9_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind10_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind11_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind12_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind13_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind14_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind15_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind16_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind17_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind18_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind19_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind20_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind21_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind22_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind23_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind24_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);

				} else{
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind9_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind10_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind11_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind12_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind13_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind14_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind15_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind16_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind17_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind18_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind19_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind20_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind21_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind22_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind23_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind24_q,0 | 0);

				}

							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind9_stVal,  ucMDiscInBuf[MB_offsetDiscreet_9] & MB_bOffset_Discreet_9))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind9_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind10_stVal,  ucMDiscInBuf[MB_offsetDiscreet_10] & MB_bOffset_Discreet_10))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind10_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind11_stVal,  ucMDiscInBuf[MB_offsetDiscreet_11] & MB_bOffset_Discreet_11))
					       	     IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind11_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind12_stVal,  ucMDiscInBuf[MB_offsetDiscreet_12] & MB_bOffset_Discreet_12))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind12_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind13_stVal,  ucMDiscInBuf[MB_offsetDiscreet_13] & MB_bOffset_Discreet_13))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind13_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind14_stVal,  ucMDiscInBuf[MB_offsetDiscreet_14] & MB_bOffset_Discreet_14))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind14_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind15_stVal,  ucMDiscInBuf[MB_offsetDiscreet_15] & MB_bOffset_Discreet_15))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind15_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind16_stVal,  ucMDiscInBuf[MB_offsetDiscreet_16] & MB_bOffset_Discreet_16))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind16_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind17_stVal,  ucMDiscInBuf[MB_offsetDiscreet_17] & MB_bOffset_Discreet_17))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind17_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind18_stVal,  ucMDiscInBuf[MB_offsetDiscreet_18] & MB_bOffset_Discreet_18))
							 	 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind18_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind19_stVal,  ucMDiscInBuf[MB_offsetDiscreet_19] & MB_bOffset_Discreet_19))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind19_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind20_stVal,  ucMDiscInBuf[MB_offsetDiscreet_20] & MB_bOffset_Discreet_20))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind20_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind21_stVal,  ucMDiscInBuf[MB_offsetDiscreet_21] & MB_bOffset_Discreet_21))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind21_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind22_stVal,  ucMDiscInBuf[MB_offsetDiscreet_22] & MB_bOffset_Discreet_22))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind22_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind23_stVal,  ucMDiscInBuf[MB_offsetDiscreet_23] & MB_bOffset_Discreet_23))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind23_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind24_stVal,  ucMDiscInBuf[MB_offsetDiscreet_24] & MB_bOffset_Discreet_24))
		       	        	     IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind24_t, currentTime);


}

/*******************************************************
 * Set_OUTGGIO наполняем оперативными данными
 *******************************************************/
void	Set_OUTGGIO	(uint8_t num, uint64_t currentTime )
{

	uint32_t	Mod = STVALINT32_ON;

	if (
			(ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule1) ||
			(ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule2)
		) {Mod = STVALINT32_OFF;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Mod_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Mod_t, currentTime);
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Beh_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Beh_t, currentTime);


	if (ucMDiscInBuf[MB_offset_errorM1] & MB_bOffsetModule1){	// 11R
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);

		}else{
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_q,0);

		}

		if (ucMDiscInBuf[MB_offset_errorM2] & MB_bOffsetModule2) //8 реле
		{
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO15_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO16_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO17_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO18_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);

		} else{

			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO15_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO16_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO17_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO18_q,0);

		}
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_stVal,  ucMDiscInBuf[MB_offsetRelay_1] & MB_bOffset_Relay_1))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_stVal,  ucMDiscInBuf[MB_offsetRelay_2] & MB_bOffset_Relay_2))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_stVal,  ucMDiscInBuf[MB_offsetRelay_3] & MB_bOffset_Relay_3))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_stVal,  ucMDiscInBuf[MB_offsetRelay_4] & MB_bOffset_Relay_4))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_stVal,  ucMDiscInBuf[MB_offsetRelay_5] & MB_bOffset_Relay_5))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_stVal,  ucMDiscInBuf[MB_offsetRelay_6] & MB_bOffset_Relay_6))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_stVal,  ucMDiscInBuf[MB_offsetRelay_7] & MB_bOffset_Relay_7))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_stVal,  ucMDiscInBuf[MB_offsetRelay_8] & MB_bOffset_Relay_8))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_stVal,  ucMDiscInBuf[MB_offsetRelay_9] & MB_bOffset_Relay_9))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_stVal,  ucMDiscInBuf[MB_offsetRelay_10] & MB_bOffset_Relay_10))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_stVal,  ucMDiscInBuf[MB_offsetRelay_11] & MB_bOffset_Relay_11))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_stVal,  ucMDiscInBuf[MB_offsetRelay_12] & MB_bOffset_Relay_12))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_stVal,  ucMDiscInBuf[MB_offsetRelay_13] & MB_bOffset_Relay_13))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_stVal,  ucMDiscInBuf[MB_offsetRelay_14] & MB_bOffset_Relay_14))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO15_stVal,  ucMDiscInBuf[MB_offsetRelay_15] & MB_bOffset_Relay_15))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO15_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO16_stVal,  ucMDiscInBuf[MB_offsetRelay_16] & MB_bOffset_Relay_16))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO16_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO17_stVal,  ucMDiscInBuf[MB_offsetRelay_17] & MB_bOffset_Relay_17))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO17_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO18_stVal,  ucMDiscInBuf[MB_offsetRelay_18] & MB_bOffset_Relay_18))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO18_t, currentTime);

/*
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_stVal,  ucMDiscInBuf[MB_offsetRelay_1] & MB_bOffset_Relay_1))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_stVal,  ucMDiscInBuf[MB_offsetRelay_2] & MB_bOffset_Relay_2))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_stVal,  ucMDiscInBuf[MB_offsetRelay_3] & MB_bOffset_Relay_3))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_stVal,  ucMDiscInBuf[MB_offsetRelay_4] & MB_bOffset_Relay_4))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_stVal,  ucMDiscInBuf[MB_offsetRelay_5] & MB_bOffset_Relay_5))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_stVal,  ucMDiscInBuf[MB_offsetRelay_6] & MB_bOffset_Relay_6))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_stVal,  ucMDiscInBuf[MB_offsetRelay_7] & MB_bOffset_Relay_7))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_stVal,  ucMDiscInBuf[MB_offsetRelay_8] & MB_bOffset_Relay_8))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_stVal,  ucMDiscInBuf[MB_offsetRelay_9] & MB_bOffset_Relay_9))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_stVal,  ucMDiscInBuf[MB_offsetRelay_10] & MB_bOffset_Relay_10))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_stVal,  ucMDiscInBuf[MB_offsetRelay_11] & MB_bOffset_Relay_11))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_stVal,  ucMDiscInBuf[MB_offsetRelay_12] & MB_bOffset_Relay_12))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_stVal,  ucMDiscInBuf[MB_offsetRelay_13] & MB_bOffset_Relay_13))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_stVal,  ucMDiscInBuf[MB_offsetRelay_14] & MB_bOffset_Relay_14))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO15_stVal,  ucMDiscInBuf[MB_offsetRelay_15] & MB_bOffset_Relay_15))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO15_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO16_stVal,  ucMDiscInBuf[MB_offsetRelay_16] & MB_bOffset_Relay_16))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO16_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO17_stVal,  ucMDiscInBuf[MB_offsetRelay_17] & MB_bOffset_Relay_17))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO17_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO18_stVal,  ucMDiscInBuf[MB_offsetRelay_18] & MB_bOffset_Relay_18))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO18_t, currentTime);
*/
}

/*******************************************************
 * Set_LEDGGIO наполняем оперативными данными
 *******************************************************/
void	Set_LEDGGIO	(uint8_t num, uint64_t currentTime )
{

	uint32_t	Mod = STVALINT32_ON;

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Mod_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_Mod_t, currentTime);
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Beh_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_Beh_t, currentTime);


	// статус сброса нидикаторов
	if (
			(ucMDiscInBuf[MB_offsetLED_1] & MB_bOffset_LED_1) ||
			(ucMDiscInBuf[MB_offsetLED_2] & MB_bOffset_LED_2) ||
			(ucMDiscInBuf[MB_offsetLED_3] & MB_bOffset_LED_3) ||
			(ucMDiscInBuf[MB_offsetLED_4] & MB_bOffset_LED_4) ||
			(ucMDiscInBuf[MB_offsetLED_5] & MB_bOffset_LED_5) ||
			(ucMDiscInBuf[MB_offsetLED_6] & MB_bOffset_LED_6) ||
			(ucMDiscInBuf[MB_offsetLED_7] & MB_bOffset_LED_7) ||
			(ucMDiscInBuf[MB_offsetLED_8] & MB_bOffset_LED_8) ||
			(ucMDiscInBuf[MB_offsetLED_9] & MB_bOffset_LED_9) ||
			(ucMDiscInBuf[MB_offsetLED_10] & MB_bOffset_LED_10) ||
			(ucMDiscInBuf[MB_offsetLED_11] & MB_bOffset_LED_11) ||
			(ucMDiscInBuf[MB_offsetLED_12] & MB_bOffset_LED_12)
			)
	{
		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_stVal,  1))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_t, currentTime);
		IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_q,0);

	} else{
		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_stVal,  0))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_t, currentTime);
		IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_q,0);

	}

	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetLED_1] & MB_bOffset_LED_1) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetLED_2] & MB_bOffset_LED_2) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetLED_3] & MB_bOffset_LED_3) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetLED_4] & MB_bOffset_LED_4) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetLED_5] & MB_bOffset_LED_5) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetLED_6] & MB_bOffset_LED_6) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetLED_7] & MB_bOffset_LED_7) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetLED_8] & MB_bOffset_LED_8) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_stVal,  ucMDiscInBuf[MB_offsetLED_9] & MB_bOffset_LED_9) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_stVal,  ucMDiscInBuf[MB_offsetLED_10] & MB_bOffset_LED_10) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_stVal,  ucMDiscInBuf[MB_offsetLED_11] & MB_bOffset_LED_11) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_stVal,  ucMDiscInBuf[MB_offsetLED_12] & MB_bOffset_LED_12) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_t, currentTime);

	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind13_stVal,  ucMDiscInBuf[MB_offsetLED_13] & MB_bOffset_LED_13) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind13_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind14_stVal,  ucMDiscInBuf[MB_offsetLED_14] & MB_bOffset_LED_14) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind14_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind15_stVal,  ucMDiscInBuf[MB_offsetLED_15] & MB_bOffset_LED_15) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind15_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind16_stVal,  ucMDiscInBuf[MB_offsetLED_16] & MB_bOffset_LED_16) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind16_t, currentTime);


	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_q,0);

	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind13_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind14_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind15_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind16_q,0);

	//--------------------------------
	// сброс флагов

		if (ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetError){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_stVal,  1))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_stVal,  0))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_q,0);
		}
		if (ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetSysNote){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_stVal,  1))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_stVal,  0))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_q,0);
		}
		if (ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetErrorNote){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_stVal,  1))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_stVal,  0))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_q,0);
		}
}

/*******************************************************
 * Set_SSLGGIO наполняем оперативными данными
 *******************************************************/
void	Set_SSLGGIO	(uint8_t num, uint64_t currentTime )
{

	uint32_t	Mod = STVALINT32_ON;

	IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Mod_stVal, Mod);
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_Mod_t, currentTime);
	IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Beh_stVal, Mod);
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_Beh_t, currentTime);


	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetSSL_1] & MB_bOffset_SSL_1) > 0)
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind1_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetSSL_2] & MB_bOffset_SSL_2) > 0)
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind2_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetSSL_3] & MB_bOffset_SSL_3) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind3_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetSSL_4] & MB_bOffset_SSL_4) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind4_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetSSL_5] & MB_bOffset_SSL_5) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind5_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetSSL_6] & MB_bOffset_SSL_6) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind6_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetSSL_7] & MB_bOffset_SSL_7) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind7_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetSSL_8] & MB_bOffset_SSL_8) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind8_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind9_stVal,  ucMDiscInBuf[MB_offsetSSL_9] & MB_bOffset_SSL_9) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind9_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind10_stVal,  ucMDiscInBuf[MB_offsetSSL_10] & MB_bOffset_SSL_10) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind10_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind11_stVal,  ucMDiscInBuf[MB_offsetSSL_11] & MB_bOffset_SSL_11) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind11_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind12_stVal,  ucMDiscInBuf[MB_offsetSSL_12] & MB_bOffset_SSL_12) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind12_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind13_stVal,  ucMDiscInBuf[MB_offsetSSL_13] & MB_bOffset_SSL_13) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind13_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind14_stVal,  ucMDiscInBuf[MB_offsetSSL_14] & MB_bOffset_SSL_14) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind14_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind15_stVal,  ucMDiscInBuf[MB_offsetSSL_15] & MB_bOffset_SSL_15) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind15_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind16_stVal,  ucMDiscInBuf[MB_offsetSSL_16] & MB_bOffset_SSL_16) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind16_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind17_stVal,  ucMDiscInBuf[MB_offsetSSL_17] & MB_bOffset_SSL_17) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind17_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind18_stVal,  ucMDiscInBuf[MB_offsetSSL_18] & MB_bOffset_SSL_18) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind18_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind19_stVal,  ucMDiscInBuf[MB_offsetSSL_19] & MB_bOffset_SSL_19) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind19_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind20_stVal,  ucMDiscInBuf[MB_offsetSSL_20] & MB_bOffset_SSL_20) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind20_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind21_stVal,  ucMDiscInBuf[MB_offsetSSL_21] & MB_bOffset_SSL_21) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind21_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind22_stVal,  ucMDiscInBuf[MB_offsetSSL_22] & MB_bOffset_SSL_22) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind22_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind23_stVal,  ucMDiscInBuf[MB_offsetSSL_23] & MB_bOffset_SSL_23) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind23_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind24_stVal,  ucMDiscInBuf[MB_offsetSSL_24] & MB_bOffset_SSL_24) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind24_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind25_stVal,  ucMDiscInBuf[MB_offsetSSL_25] & MB_bOffset_SSL_25) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind25_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind26_stVal,  ucMDiscInBuf[MB_offsetSSL_26] & MB_bOffset_SSL_26) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind26_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind27_stVal,  ucMDiscInBuf[MB_offsetSSL_27] & MB_bOffset_SSL_27) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind27_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind28_stVal,  ucMDiscInBuf[MB_offsetSSL_28] & MB_bOffset_SSL_28) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind28_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind29_stVal,  ucMDiscInBuf[MB_offsetSSL_29] & MB_bOffset_SSL_29) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind29_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind30_stVal,  ucMDiscInBuf[MB_offsetSSL_30] & MB_bOffset_SSL_30) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind30_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind31_stVal,  ucMDiscInBuf[MB_offsetSSL_31] & MB_bOffset_SSL_31) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind31_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind32_stVal,  ucMDiscInBuf[MB_offsetSSL_32] & MB_bOffset_SSL_32) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind32_t, currentTime);


	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind1_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind2_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind3_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind4_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind5_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind6_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind7_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind8_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind9_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind10_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind11_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind12_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind13_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind14_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind15_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind16_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind17_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind18_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind19_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind20_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind21_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind22_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind23_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind24_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind25_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind26_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind27_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind28_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind29_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind30_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind31_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind32_q,0);

}

/*******************************************************
 * Set_VLSGGIO наполняем оперативными данными
 *******************************************************/
void	Set_VLSGGIO	(uint8_t num, uint64_t currentTime )
{

	uint32_t	Mod = STVALINT32_ON;

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Mod_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_Mod_t, currentTime);
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Beh_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_Beh_t, currentTime);


	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetVLS_1] & MB_bOffset_VLS_1) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind1_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetVLS_2] & MB_bOffset_VLS_2) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind2_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetVLS_3] & MB_bOffset_VLS_3) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind3_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetVLS_4] & MB_bOffset_VLS_4) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind4_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetVLS_5] & MB_bOffset_VLS_5) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind5_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetVLS_6] & MB_bOffset_VLS_6) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind6_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetVLS_7] & MB_bOffset_VLS_7) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind7_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetVLS_8] & MB_bOffset_VLS_8) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind8_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind9_stVal,  ucMDiscInBuf[MB_offsetVLS_9] & MB_bOffset_VLS_9) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind9_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind10_stVal,  ucMDiscInBuf[MB_offsetVLS_10] & MB_bOffset_VLS_10) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind10_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind11_stVal,  ucMDiscInBuf[MB_offsetVLS_11] & MB_bOffset_VLS_11) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind11_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind12_stVal,  ucMDiscInBuf[MB_offsetVLS_12] & MB_bOffset_VLS_12) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind12_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind13_stVal,  ucMDiscInBuf[MB_offsetVLS_13] & MB_bOffset_VLS_13) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind13_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind14_stVal,  ucMDiscInBuf[MB_offsetVLS_14] & MB_bOffset_VLS_14) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind14_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind15_stVal,  ucMDiscInBuf[MB_offsetVLS_15] & MB_bOffset_VLS_15) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind15_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind16_stVal,  ucMDiscInBuf[MB_offsetVLS_16] & MB_bOffset_VLS_16) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind16_t, currentTime);



	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind1_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind2_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind3_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind4_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind5_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind6_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind7_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind8_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind9_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind10_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind11_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind12_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind13_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind14_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind15_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind16_q,0);


}

/*******************************************************
 * Set_LSGGIO наполняем оперативными данными
 *******************************************************/
void	Set_LSGGIO	(uint8_t num, uint64_t currentTime )
{

	uint32_t	Mod = STVALINT32_ON;

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Mod_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_Mod_t, currentTime);
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Beh_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_Beh_t, currentTime);


	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetLS_1] & MB_bOffset_LS_1) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind1_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetLS_2] & MB_bOffset_LS_2) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind2_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetLS_3] & MB_bOffset_LS_3) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind3_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetLS_4] & MB_bOffset_LS_4) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind4_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetLS_5] & MB_bOffset_LS_5) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind5_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetLS_6] & MB_bOffset_LS_6) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind6_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetLS_7] & MB_bOffset_LS_7) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind7_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetLS_8] & MB_bOffset_LS_8) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind8_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind9_stVal,  ucMDiscInBuf[MB_offsetLS_9] & MB_bOffset_LS_9) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind9_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind10_stVal,  ucMDiscInBuf[MB_offsetLS_10] & MB_bOffset_LS_10) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind10_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind11_stVal,  ucMDiscInBuf[MB_offsetLS_11] & MB_bOffset_LS_11) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind11_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind12_stVal,  ucMDiscInBuf[MB_offsetLS_12] & MB_bOffset_LS_12) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind12_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind13_stVal,  ucMDiscInBuf[MB_offsetLS_13] & MB_bOffset_LS_13) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind13_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind14_stVal,  ucMDiscInBuf[MB_offsetLS_14] & MB_bOffset_LS_14) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind14_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind15_stVal,  ucMDiscInBuf[MB_offsetLS_15] & MB_bOffset_LS_15) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind15_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind16_stVal,  ucMDiscInBuf[MB_offsetLS_16] & MB_bOffset_LS_16) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind16_t, currentTime);



	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind1_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind2_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind3_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind4_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind5_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind6_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind7_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind8_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind9_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind10_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind11_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind12_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind13_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind14_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind15_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind16_q,0);
}
#endif

/*******************************************************
 * MR851
 *******************************************************/
#if defined	(MR851)
#include "static_model_MR851.h"

extern 	uint16_t   ucMUstavkiInBuf[MB_NumbUstavki];
extern  uint16_t   ucMDiscInBuf[MB_NumbDiscreet];


/*******************************************************
 * Set_XCBRGGIO наполняем оперативными данными
 *******************************************************/
void	Set_XCBRGGIO	(uint8_t num, uint64_t currentTime )
{
	//--------------------------------
	// сброс флагов

		if (ucMDiscInBuf[MB_offset_ErrorSDTU] & MB_bOffsetErrorSDTU){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_stVal,  1))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_stVal,  0))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_q,0);
		}

		if (ucMDiscInBuf[MB_offset_NewJurnalMs] & MB_bOffseNewJurnalMs){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_stVal,  1))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_stVal,  0))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_q,0);
		}

		if (ucMDiscInBuf[MB_offset_BLK] & MB_bOffsetDriveDNTMove){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_stVal,  1))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_stVal,  0))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_q,0);
		}


		if (ucMDiscInBuf[MB_offset_NewMsJurnalError] & MB_bOffseNewMsJurnalError)
		{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_stVal,  1))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_q,0);

		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_stVal,  0))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_q,0);

		}


}

/*******************************************************
 * Set_INGGIO наполняем оперативными данными
 *******************************************************/
void	Set_INGGIO	(uint8_t num, uint64_t currentTime )
{
	//  Mod Beh

				uint32_t	Mod = STVALINT32_ON;

				if (
						(ucMDiscInBuf[MB_offsetError_M3] & MB_bOffsetErrModule3)
					) {Mod = STVALINT32_Warning;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Beh_t, currentTime);



				if (ucMDiscInBuf[MB_offsetError_M3] & MB_bOffsetErrModule3a){	// 8D
				    	    IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind1_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
				    	    IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind2_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
				    	    IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind3_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
				    	    IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind4_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
				    	    IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind5_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
				    	    IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind6_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
				    	    IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind7_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
				    	    IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind8_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);

				} else
				{
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind1_q,0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind2_q,0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind3_q,0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind4_q,0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind5_q,0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind6_q,0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind7_q,0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind8_q,0);

				}

							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetDiscreet_1] & MB_bOffset_Discreet_1))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind1_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetDiscreet_2] & MB_bOffset_Discreet_2))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind2_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetDiscreet_3] & MB_bOffset_Discreet_3))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind3_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetDiscreet_4] & MB_bOffset_Discreet_4))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind4_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetDiscreet_5] & MB_bOffset_Discreet_5))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind5_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetDiscreet_6] & MB_bOffset_Discreet_6))
					       	     IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind6_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetDiscreet_7] & MB_bOffset_Discreet_7))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind7_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetDiscreet_8] & MB_bOffset_Discreet_8))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind8_t, currentTime);


				if (ucMDiscInBuf[MB_offsetError_M3] & MB_bOffsetErrModule3b){	// 16D
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind9_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind10_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind11_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind12_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind13_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind14_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind15_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind16_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);


				} else{
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind9_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind10_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind11_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind12_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind13_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind14_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind15_q,0 | 0);
							IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind16_q,0 | 0);

				}

							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind9_stVal,  ucMDiscInBuf[MB_offsetDiscreet_9] & MB_bOffset_Discreet_9))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind9_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind10_stVal,  ucMDiscInBuf[MB_offsetDiscreet_10] & MB_bOffset_Discreet_10))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind10_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind11_stVal,  ucMDiscInBuf[MB_offsetDiscreet_11] & MB_bOffset_Discreet_11))
					       	     IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind11_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind12_stVal,  ucMDiscInBuf[MB_offsetDiscreet_12] & MB_bOffset_Discreet_12))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind12_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind13_stVal,  ucMDiscInBuf[MB_offsetDiscreet_13] & MB_bOffset_Discreet_13))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind13_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind14_stVal,  ucMDiscInBuf[MB_offsetDiscreet_14] & MB_bOffset_Discreet_14))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind14_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind15_stVal,  ucMDiscInBuf[MB_offsetDiscreet_15] & MB_bOffset_Discreet_15))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind15_t, currentTime);
							if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind16_stVal,  ucMDiscInBuf[MB_offsetDiscreet_16] & MB_bOffset_Discreet_16))
								 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind16_t, currentTime);
}

/*******************************************************
 * Set_OUTGGIO наполняем оперативными данными
 *******************************************************/
void	Set_OUTGGIO	(uint8_t num, uint64_t currentTime )
{

	uint32_t	Mod = STVALINT32_ON;

	if 	(ucMDiscInBuf[MB_offsetError_M2] & MB_bOffsetErrModule2)  {Mod = STVALINT32_OFF;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Mod_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Mod_t, currentTime);
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Beh_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Beh_t, currentTime);


	if (ucMDiscInBuf[MB_offsetError_M2] & MB_bOffsetErrModule2){	// 11R
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			//IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO15_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);

		}else{
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_q,0);
			//IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO15_q,0);
		}

			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_stVal,  ucMDiscInBuf[MB_offsetRelay_1] & MB_bOffset_Relay_1))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_stVal,  ucMDiscInBuf[MB_offsetRelay_2] & MB_bOffset_Relay_2))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_stVal,  ucMDiscInBuf[MB_offsetRelay_3] & MB_bOffset_Relay_3))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_stVal,  ucMDiscInBuf[MB_offsetRelay_4] & MB_bOffset_Relay_4))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_stVal,  ucMDiscInBuf[MB_offsetRelay_5] & MB_bOffset_Relay_5))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_stVal,  ucMDiscInBuf[MB_offsetRelay_6] & MB_bOffset_Relay_6))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_stVal,  ucMDiscInBuf[MB_offsetRelay_7] & MB_bOffset_Relay_7))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_stVal,  ucMDiscInBuf[MB_offsetRelay_8] & MB_bOffset_Relay_8))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_stVal,  ucMDiscInBuf[MB_offsetRelay_9] & MB_bOffset_Relay_9))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_stVal,  ucMDiscInBuf[MB_offsetRelay_10] & MB_bOffset_Relay_10))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_stVal,  ucMDiscInBuf[MB_offsetRelay_11] & MB_bOffset_Relay_11))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_stVal,  ucMDiscInBuf[MB_offsetRelay_12] & MB_bOffset_Relay_12))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_stVal,  ucMDiscInBuf[MB_offsetRelay_13] & MB_bOffset_Relay_13))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_t, currentTime);
			if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_stVal,  ucMDiscInBuf[MB_offsetRelay_14] & MB_bOffset_Relay_14))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_t, currentTime);
			//if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO15_stVal,  ucMDiscInBuf[MB_offsetRelay_15] & MB_bOffset_Relay_15))
			//	IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO15_t, currentTime);
}

/*******************************************************
 * Set_LEDGGIO наполняем оперативными данными
 *******************************************************/
void	Set_LEDGGIO	(uint8_t num, uint64_t currentTime )
{

	uint32_t	Mod = STVALINT32_ON;

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Mod_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_Mod_t, currentTime);
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Beh_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_Beh_t, currentTime);



	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetLED_1] & MB_bOffset_LED_1) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetLED_2] & MB_bOffset_LED_2) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetLED_3] & MB_bOffset_LED_3) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetLED_4] & MB_bOffset_LED_4) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetLED_5] & MB_bOffset_LED_5) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetLED_6] & MB_bOffset_LED_6) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetLED_7] & MB_bOffset_LED_7) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetLED_8] & MB_bOffset_LED_8) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_stVal,  ucMDiscInBuf[MB_offsetLED_9] & MB_bOffset_LED_9) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_stVal,  ucMDiscInBuf[MB_offsetLED_10] & MB_bOffset_LED_10) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_stVal,  ucMDiscInBuf[MB_offsetLED_11] & MB_bOffset_LED_11) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_stVal,  ucMDiscInBuf[MB_offsetLED_12] & MB_bOffset_LED_12) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_t, currentTime);


	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_q,0);

}
#endif


/*******************************************************
 * MR5_700
 *******************************************************/
#if defined	(MR5_700)
#include "static_model_MR5_700.h"

extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucAutomatBuf[MB_NumbAutomat];
extern uint16_t   ucUstavkiInBuf[MB_NumbUstavki];
extern uint16_t   ucConfigBufExZ[MB_NumbConfigExZ];
/*******************************************************
 * Set_VZGGIO наполняем оперативными данными
 *******************************************************/
void	Set_VZGGIO	(uint8_t num, uint64_t currentTime )
{

	//  Mod Beh
				uint32_t	Mod;
				if (ucConfigBufExZ[MB_offset_Ext_1 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO1_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO1_Beh_t, currentTime);

				if (ucConfigBufExZ[MB_offset_Ext_2 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO2_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO2_Beh_t, currentTime);

				if (ucConfigBufExZ[MB_offset_Ext_3 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO3_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO3_Beh_t, currentTime);

				if (ucConfigBufExZ[MB_offset_Ext_4 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO4_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO4_Beh_t, currentTime);

				if (ucConfigBufExZ[MB_offset_Ext_5 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO5_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO5_Beh_t, currentTime);

				if (ucConfigBufExZ[MB_offset_Ext_6 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO6_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO6_Beh_t, currentTime);

				if (ucConfigBufExZ[MB_offset_Ext_7 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO7_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO7_Beh_t, currentTime);

				if (ucConfigBufExZ[MB_offset_Ext_8 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO8_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO8_Beh_t, currentTime);


	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Health_q,Qual);

//				uint32_t	Alm;

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_1] & MB_b_SRAB_ext_1))		// СРАБ >1
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_2] & MB_b_SRAB_ext_2))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_3] & MB_b_SRAB_ext_3))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_4] & MB_b_SRAB_ext_4))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_5] & MB_b_SRAB_ext_5))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_6] & MB_b_SRAB_ext_6))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_7] & MB_b_SRAB_ext_7))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_8] & MB_b_SRAB_ext_8))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Alm_q,0);

}

/*******************************************************
 * Set_AVRGGIO наполняем оперативными данными
 *******************************************************/
void	Set_AVRGGIO	(uint8_t num, uint64_t currentTime )
{
	//  Mod Beh

				uint32_t	Mod;
				if (ucAutomatBuf[MB_offset_ConfAWR] & MB_bOffset_AWR_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_AVRGGIO_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_AVRGGIO_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_AVRGGIO_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_AVRGGIO_Beh_t, currentTime);

	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_AVRGGIO_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_AVRGGIO_Beh_q,Qual);

				uint8_t	awr=0;
					if(ucMDiscInBuf[MB_offset_AWR] & MB_b_ON_AWR)  awr = 1;
					if(ucMDiscInBuf[MB_offset_AWR] & MB_b_OFF_AWR) awr = 2;
					if(ucMDiscInBuf[MB_offset_AWR] & MB_b_Blok_AWR) awr = 3;

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_AVRGGIO_IntIn_stVal, awr))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_AVRGGIO_IntIn_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_AVRGGIO_IntIn_q,0);
}
/*******************************************************
 * Set_XCBRGGIO наполняем оперативными данными
 *******************************************************/
void	Set_XCBRGGIO	(uint8_t num, uint64_t currentTime )
{
	//--------------------------------
	// сброс флагов

		if (ucMDiscInBuf[MB_offset_ErrorSDTU] & MB_bOffsetErrorSDTU){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_stVal,  1))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_stVal,  0))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_q,0);
		}

		if (ucMDiscInBuf[MB_offset_NewJurnalMs] & MB_bOffsetNewJurnalMs){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_stVal,  1))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_stVal,  0))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_q,0);
		}

		if (ucMDiscInBuf[MB_offset_NewMsJurnalError] & MB_bOffsetNewMsJurnalError){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_stVal,  1))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_stVal,  0))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_q,0);
		}


		// все индикаторы
		if (ucMDiscInBuf[MB_offset_AllLEDs] & MB_bOffsetLedsStats)
		{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_stVal,  1))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_q,0);

		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_stVal,  0))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_q,0);
		}
}
/*******************************************************
 * Set_INGGIO наполняем оперативными данными
 *******************************************************/
void	Set_INGGIO	(uint8_t num, uint64_t currentTime )
{
	//  Mod Beh

	uint32_t	Mod = STVALINT32_ON;

	if (
			(ucMDiscInBuf[MB_offsetError_M3] & MB_bOffsetErrModule3)
		) {Mod = STVALINT32_OFF;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Mod_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Mod_t, currentTime);
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Beh_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Beh_t, currentTime);



	if (ucMDiscInBuf[MB_offsetError_M3] & MB_bOffsetErrModule3a){	// 8D
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind1_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind2_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind3_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind4_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind5_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind6_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind7_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind8_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
	} else
	{
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind1_q,0);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind2_q,0);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind3_q,0);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind4_q,0);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind5_q,0);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind6_q,0);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind7_q,0);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind8_q,0);
	}

	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetDiscreet_1] & MB_bOffset_Discreet_1))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind1_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetDiscreet_2] & MB_bOffset_Discreet_2))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind2_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetDiscreet_3] & MB_bOffset_Discreet_3))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind3_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetDiscreet_4] & MB_bOffset_Discreet_4))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind4_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetDiscreet_5] & MB_bOffset_Discreet_5))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind5_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetDiscreet_6] & MB_bOffset_Discreet_6))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind6_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetDiscreet_7] & MB_bOffset_Discreet_7))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind7_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetDiscreet_8] & MB_bOffset_Discreet_8))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind8_t, currentTime);


	if (ucMDiscInBuf[MB_offsetError_M3] & MB_bOffsetErrModule3b){	// 16D
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind9_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind10_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind11_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind12_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind13_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind14_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind15_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind16_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
	} else{
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind9_q,0 | 0);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind10_q,0 | 0);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind11_q,0 | 0);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind12_q,0 | 0);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind13_q,0 | 0);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind14_q,0 | 0);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind15_q,0 | 0);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind16_q,0 | 0);
	}

	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind9_stVal,  ucMDiscInBuf[MB_offsetDiscreet_9] & MB_bOffset_Discreet_9))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind9_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind10_stVal,  ucMDiscInBuf[MB_offsetDiscreet_10] & MB_bOffset_Discreet_10))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind10_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind11_stVal,  ucMDiscInBuf[MB_offsetDiscreet_11] & MB_bOffset_Discreet_11))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind11_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind12_stVal,  ucMDiscInBuf[MB_offsetDiscreet_12] & MB_bOffset_Discreet_12))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind12_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind13_stVal,  ucMDiscInBuf[MB_offsetDiscreet_13] & MB_bOffset_Discreet_13))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind13_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind14_stVal,  ucMDiscInBuf[MB_offsetDiscreet_14] & MB_bOffset_Discreet_14))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind14_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind15_stVal,  ucMDiscInBuf[MB_offsetDiscreet_15] & MB_bOffset_Discreet_15))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind15_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind16_stVal,  ucMDiscInBuf[MB_offsetDiscreet_16] & MB_bOffset_Discreet_16))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind16_t, currentTime);
}

/*******************************************************
 * Set_OUTGGIO наполняем оперативными данными
 *******************************************************/
void	Set_OUTGGIO	(uint8_t num, uint64_t currentTime )
{

	uint32_t	Mod = STVALINT32_ON;

	if 	(ucMDiscInBuf[MB_offsetError_M2] & MB_bOffsetErrModule2)  {Mod = STVALINT32_OFF;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Mod_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_Mod_t, currentTime);
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Beh_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_Beh_t, currentTime);

	if (ucMDiscInBuf[MB_offsetError_M2] & MB_bOffsetErrModule2){	// 11R
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		}else{
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_q,0);
		}

	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_stVal,  ucMDiscInBuf[MB_offsetRelay_1] & MB_bOffset_Relay_1))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_stVal,  ucMDiscInBuf[MB_offsetRelay_2] & MB_bOffset_Relay_2))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_stVal,  ucMDiscInBuf[MB_offsetRelay_3] & MB_bOffset_Relay_3))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_stVal,  ucMDiscInBuf[MB_offsetRelay_4] & MB_bOffset_Relay_4))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_stVal,  ucMDiscInBuf[MB_offsetRelay_5] & MB_bOffset_Relay_5))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_stVal,  ucMDiscInBuf[MB_offsetRelay_6] & MB_bOffset_Relay_6))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_stVal,  ucMDiscInBuf[MB_offsetRelay_7] & MB_bOffset_Relay_7))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_stVal,  ucMDiscInBuf[MB_offsetRelay_8] & MB_bOffset_Relay_8))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_t, currentTime);
}

/*******************************************************
 * Set_LEDGGIO наполняем оперативными данными
 *******************************************************/
void	Set_LEDGGIO	(uint8_t num, uint64_t currentTime )
{

	uint32_t	Mod = STVALINT32_ON;

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Mod_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_Mod_t, currentTime);
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Beh_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_Beh_t, currentTime);

	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetLED_1] & MB_bOffset_LED_1) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetLED_2] & MB_bOffset_LED_2) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetLED_3] & MB_bOffset_LED_3) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetLED_4] & MB_bOffset_LED_4) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetLED_5] & MB_bOffset_LED_5) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetLED_6] & MB_bOffset_LED_6) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetLED_7] & MB_bOffset_LED_7) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetLED_8] & MB_bOffset_LED_8) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_stVal,  ucMDiscInBuf[MB_offsetLED_9] & MB_bOffset_LED_9) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_stVal,  ucMDiscInBuf[MB_offsetLED_10] & MB_bOffset_LED_10) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_stVal,  ucMDiscInBuf[MB_offsetLED_11] & MB_bOffset_LED_11) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_stVal,  ucMDiscInBuf[MB_offsetLED_12] & MB_bOffset_LED_12) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_t, currentTime);

	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_q,0);
}
/*******************************************************
 * Set_SSLGGIO наполняем оперативными данными
 *******************************************************/
void	Set_SSLGGIO	(uint8_t num, uint64_t currentTime )
{

	uint32_t	Mod = STVALINT32_ON;

	IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Mod_stVal, Mod);
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_Mod_t, currentTime);
	IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Beh_stVal, Mod);
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_Beh_t, currentTime);

	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetSSL_1] & MB_bOffset_SSL_1) > 0)
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind1_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetSSL_2] & MB_bOffset_SSL_2) > 0)
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind2_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetSSL_3] & MB_bOffset_SSL_3) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind3_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetSSL_4] & MB_bOffset_SSL_4) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind4_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetSSL_5] & MB_bOffset_SSL_5) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind5_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetSSL_6] & MB_bOffset_SSL_6) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind6_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetSSL_7] & MB_bOffset_SSL_7) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind7_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetSSL_8] & MB_bOffset_SSL_8) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind8_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind9_stVal,  ucMDiscInBuf[MB_offsetSSL_9] & MB_bOffset_SSL_9) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind9_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind10_stVal,  ucMDiscInBuf[MB_offsetSSL_10] & MB_bOffset_SSL_10) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind10_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind11_stVal,  ucMDiscInBuf[MB_offsetSSL_11] & MB_bOffset_SSL_11) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind11_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind12_stVal,  ucMDiscInBuf[MB_offsetSSL_12] & MB_bOffset_SSL_12) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind12_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind13_stVal,  ucMDiscInBuf[MB_offsetSSL_13] & MB_bOffset_SSL_13) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind13_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind14_stVal,  ucMDiscInBuf[MB_offsetSSL_14] & MB_bOffset_SSL_14) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind14_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind15_stVal,  ucMDiscInBuf[MB_offsetSSL_15] & MB_bOffset_SSL_15) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind15_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind16_stVal,  ucMDiscInBuf[MB_offsetSSL_16] & MB_bOffset_SSL_16) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind16_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind17_stVal,  ucMDiscInBuf[MB_offsetSSL_17] & MB_bOffset_SSL_17) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind17_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind18_stVal,  ucMDiscInBuf[MB_offsetSSL_18] & MB_bOffset_SSL_18) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind18_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind19_stVal,  ucMDiscInBuf[MB_offsetSSL_19] & MB_bOffset_SSL_19) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind19_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind20_stVal,  ucMDiscInBuf[MB_offsetSSL_20] & MB_bOffset_SSL_20) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind20_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind21_stVal,  ucMDiscInBuf[MB_offsetSSL_21] & MB_bOffset_SSL_21) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind21_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind22_stVal,  ucMDiscInBuf[MB_offsetSSL_22] & MB_bOffset_SSL_22) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind22_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind23_stVal,  ucMDiscInBuf[MB_offsetSSL_23] & MB_bOffset_SSL_23) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind23_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind24_stVal,  ucMDiscInBuf[MB_offsetSSL_24] & MB_bOffset_SSL_24) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind24_t, currentTime);

	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind1_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind2_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind3_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind4_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind5_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind6_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind7_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind8_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind9_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind10_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind11_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind12_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind13_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind14_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind15_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind16_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind17_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind18_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind19_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind20_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind21_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind22_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind23_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind24_q,0);
}

/*******************************************************
 * Set_VLSGGIO наполняем оперативными данными
 *******************************************************/
void	Set_VLSGGIO	(uint8_t num, uint64_t currentTime )
{

	uint32_t	Mod = STVALINT32_ON;

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Mod_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_Mod_t, currentTime);
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Beh_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_Beh_t, currentTime);

	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetVLS_1] & MB_bOffset_VLS_1) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind1_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetVLS_2] & MB_bOffset_VLS_2) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind2_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetVLS_3] & MB_bOffset_VLS_3) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind3_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetVLS_4] & MB_bOffset_VLS_4) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind4_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetVLS_5] & MB_bOffset_VLS_5) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind5_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetVLS_6] & MB_bOffset_VLS_6) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind6_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetVLS_7] & MB_bOffset_VLS_7) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind7_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetVLS_8] & MB_bOffset_VLS_8) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind8_t, currentTime);

	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind1_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind2_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind3_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind4_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind5_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind6_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind7_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind8_q,0);
}
/*******************************************************
 * Set_LSGGIO наполняем оперативными данными
 *******************************************************/
void	Set_LSGGIO	(uint8_t num, uint64_t currentTime )
{

	uint32_t	Mod = STVALINT32_ON;

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Mod_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_Mod_t, currentTime);
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Beh_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_Beh_t, currentTime);

	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetLS_1] & MB_bOffset_LS_1) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind1_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetLS_2] & MB_bOffset_LS_2) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind2_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetLS_3] & MB_bOffset_LS_3) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind3_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetLS_4] & MB_bOffset_LS_4) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind4_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetLS_5] & MB_bOffset_LS_5) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind5_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetLS_6] & MB_bOffset_LS_6) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind6_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetLS_7] & MB_bOffset_LS_7) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind7_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetLS_8] & MB_bOffset_LS_8) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind8_t, currentTime);

	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind1_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind2_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind3_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind4_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind5_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind6_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind7_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind8_q,0);
}
#endif
/*******************************************************
 * MR5_600
 *******************************************************/
#if defined	(MR5_600)
#include "static_model_MR5_600.h"

extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucUstavkiInBuf[MB_NumbUstavki];
extern uint16_t   ucConfigBufExZ[MB_NumbConfigExZ];
/*******************************************************
 * Set_VZGGIO наполняем оперативными данными
 *******************************************************/
void	Set_VZGGIO	(uint8_t num, uint64_t currentTime )
{

	//  Mod Beh
				uint32_t	Mod;
				if (ucConfigBufExZ[MB_offset_Ext_1 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO1_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO1_Beh_t, currentTime);

				if (ucConfigBufExZ[MB_offset_Ext_2 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO2_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO2_Beh_t, currentTime);

				if (ucConfigBufExZ[MB_offset_Ext_3 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO3_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO3_Beh_t, currentTime);

				if (ucConfigBufExZ[MB_offset_Ext_4 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO4_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO4_Beh_t, currentTime);

				if (ucConfigBufExZ[MB_offset_Ext_5 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO5_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO5_Beh_t, currentTime);

				if (ucConfigBufExZ[MB_offset_Ext_6 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO6_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO6_Beh_t, currentTime);

				if (ucConfigBufExZ[MB_offset_Ext_7 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO7_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO7_Beh_t, currentTime);

				if (ucConfigBufExZ[MB_offset_Ext_8 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO8_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO8_Beh_t, currentTime);


	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Health_q,Qual);

//				uint32_t	Alm;

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_1] & MB_b_SRAB_ext_1))		// СРАБ >1
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_2] & MB_b_SRAB_ext_2))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_3] & MB_b_SRAB_ext_3))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_4] & MB_b_SRAB_ext_4))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_5] & MB_b_SRAB_ext_5))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_6] & MB_b_SRAB_ext_6))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_7] & MB_b_SRAB_ext_7))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Alm_q,0);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_8] & MB_b_SRAB_ext_8))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Alm_t, currentTime);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Alm_q,0);

}
/*******************************************************
 * Set_XCBRGGIO наполняем оперативными данными
 *******************************************************/
void	Set_XCBRGGIO	(uint8_t num, uint64_t currentTime )
{
	//--------------------------------
	// сброс флагов

		if (ucMDiscInBuf[MB_offset_ErrorSDTU] & MB_bOffsetErrorSDTU){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_stVal,  1))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_stVal,  0))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_q,0);
		}

		if (ucMDiscInBuf[MB_offset_NewJurnalMs] & MB_bOffsetNewJurnalMs){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_stVal,  1))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_stVal,  0))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_q,0);
		}

		if (ucMDiscInBuf[MB_offset_NewMsJurnalError] & MB_bOffsetNewMsJurnalError){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_stVal,  1))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_stVal,  0))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_t, currentTime);
		    IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_q,0);
		}


		// все индикаторы
		if (ucMDiscInBuf[MB_offset_AllLEDs] & MB_bOffsetLedsStats)
		{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_stVal,  1))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_q,0);

		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_stVal,  0))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_q,0);
		}
}
/*******************************************************
 * Set_INGGIO наполняем оперативными данными
 *******************************************************/
void	Set_INGGIO	(uint8_t num, uint64_t currentTime )
{
	//  Mod Beh

	uint32_t	Mod = STVALINT32_ON;

	if (
			(ucMDiscInBuf[MB_offsetError_M3] & MB_bOffsetErrModule3)
		) {Mod = STVALINT32_OFF;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Mod_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Mod_t, currentTime);
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Beh_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Beh_t, currentTime);



	if (ucMDiscInBuf[MB_offsetError_M3] & MB_bOffsetErrModule3a){	// 8D
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind1_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind2_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind3_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind4_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind5_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind6_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind7_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind8_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
	} else
	{
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind1_q,0);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind2_q,0);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind3_q,0);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind4_q,0);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind5_q,0);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind6_q,0);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind7_q,0);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind8_q,0);
	}

	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetDiscreet_1] & MB_bOffset_Discreet_1))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind1_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetDiscreet_2] & MB_bOffset_Discreet_2))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind2_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetDiscreet_3] & MB_bOffset_Discreet_3))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind3_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetDiscreet_4] & MB_bOffset_Discreet_4))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind4_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetDiscreet_5] & MB_bOffset_Discreet_5))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind5_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetDiscreet_6] & MB_bOffset_Discreet_6))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind6_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetDiscreet_7] & MB_bOffset_Discreet_7))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind7_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetDiscreet_8] & MB_bOffset_Discreet_8))
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind8_t, currentTime);

}

/*******************************************************
 * Set_OUTGGIO наполняем оперативными данными
 *******************************************************/
void	Set_OUTGGIO	(uint8_t num, uint64_t currentTime )
{

	uint32_t	Mod;

	Mod = STVALINT32_ON;
	if 	((ucMDiscInBuf[MB_offsetError_M2] & MB_bOffsetErrModule2a)&&(ucMDiscInBuf[MB_offsetError_M2] & MB_bOffsetErrModule2b))  {Mod = STVALINT32_OFF;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Mod_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_Mod_t, currentTime);
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Beh_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_Beh_t, currentTime);

	if (ucMDiscInBuf[MB_offsetError_M2] & MB_bOffsetErrModule2a){	// 11R
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		}else{
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_q,0);
		}
	if (ucMDiscInBuf[MB_offsetError_M2] & MB_bOffsetErrModule2b){	// 11R
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO15_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO16_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		}else{
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO15_q,0);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO16_q,0);
		}

	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_stVal,  ucMDiscInBuf[MB_offsetRelay_1] & MB_bOffset_Relay_1))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_stVal,  ucMDiscInBuf[MB_offsetRelay_2] & MB_bOffset_Relay_2))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_stVal,  ucMDiscInBuf[MB_offsetRelay_3] & MB_bOffset_Relay_3))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_stVal,  ucMDiscInBuf[MB_offsetRelay_4] & MB_bOffset_Relay_4))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_stVal,  ucMDiscInBuf[MB_offsetRelay_5] & MB_bOffset_Relay_5))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_stVal,  ucMDiscInBuf[MB_offsetRelay_6] & MB_bOffset_Relay_6))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_stVal,  ucMDiscInBuf[MB_offsetRelay_7] & MB_bOffset_Relay_7))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_stVal,  ucMDiscInBuf[MB_offsetRelay_8] & MB_bOffset_Relay_8))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_stVal,  ucMDiscInBuf[MB_offsetRelay_9] & MB_bOffset_Relay_9))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_stVal,  ucMDiscInBuf[MB_offsetRelay_10] & MB_bOffset_Relay_10))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_stVal,  ucMDiscInBuf[MB_offsetRelay_11] & MB_bOffset_Relay_11))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_stVal,  ucMDiscInBuf[MB_offsetRelay_12] & MB_bOffset_Relay_12))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_stVal,  ucMDiscInBuf[MB_offsetRelay_13] & MB_bOffset_Relay_13))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_stVal,  ucMDiscInBuf[MB_offsetRelay_14] & MB_bOffset_Relay_14))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO15_stVal,  ucMDiscInBuf[MB_offsetRelay_15] & MB_bOffset_Relay_15))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO15_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO16_stVal,  ucMDiscInBuf[MB_offsetRelay_15] & MB_bOffset_Relay_16))
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO16_t, currentTime);

}

/*******************************************************
 * Set_LEDGGIO наполняем оперативными данными
 *******************************************************/
void	Set_LEDGGIO	(uint8_t num, uint64_t currentTime )
{

	uint32_t	Mod = STVALINT32_ON;

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Mod_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_Mod_t, currentTime);
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Beh_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_Beh_t, currentTime);

	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetLED_1] & MB_bOffset_LED_1) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetLED_2] & MB_bOffset_LED_2) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetLED_3] & MB_bOffset_LED_3) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetLED_4] & MB_bOffset_LED_4) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetLED_5] & MB_bOffset_LED_5) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetLED_6] & MB_bOffset_LED_6) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetLED_7] & MB_bOffset_LED_7) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetLED_8] & MB_bOffset_LED_8) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_stVal,  ucMDiscInBuf[MB_offsetLED_9] & MB_bOffset_LED_9) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_stVal,  ucMDiscInBuf[MB_offsetLED_10] & MB_bOffset_LED_10) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_stVal,  ucMDiscInBuf[MB_offsetLED_11] & MB_bOffset_LED_11) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_stVal,  ucMDiscInBuf[MB_offsetLED_12] & MB_bOffset_LED_12) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_t, currentTime);

	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_q,0);
}
/*******************************************************
 * Set_SSLGGIO наполняем оперативными данными
 *******************************************************/
void	Set_SSLGGIO	(uint8_t num, uint64_t currentTime )
{

	uint32_t	Mod = STVALINT32_ON;

	IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Mod_stVal, Mod);
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_Mod_t, currentTime);
	IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Beh_stVal, Mod);
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_Beh_t, currentTime);

	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetSSL_1] & MB_bOffset_SSL_1) > 0)
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind1_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetSSL_2] & MB_bOffset_SSL_2) > 0)
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind2_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetSSL_3] & MB_bOffset_SSL_3) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind3_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetSSL_4] & MB_bOffset_SSL_4) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind4_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetSSL_5] & MB_bOffset_SSL_5) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind5_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetSSL_6] & MB_bOffset_SSL_6) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind6_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetSSL_7] & MB_bOffset_SSL_7) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind7_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetSSL_8] & MB_bOffset_SSL_8) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind8_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind9_stVal,  ucMDiscInBuf[MB_offsetSSL_9] & MB_bOffset_SSL_9) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind9_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind10_stVal,  ucMDiscInBuf[MB_offsetSSL_10] & MB_bOffset_SSL_10) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind10_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind11_stVal,  ucMDiscInBuf[MB_offsetSSL_11] & MB_bOffset_SSL_11) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind11_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind12_stVal,  ucMDiscInBuf[MB_offsetSSL_12] & MB_bOffset_SSL_12) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind12_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind13_stVal,  ucMDiscInBuf[MB_offsetSSL_13] & MB_bOffset_SSL_13) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind13_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind14_stVal,  ucMDiscInBuf[MB_offsetSSL_14] & MB_bOffset_SSL_14) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind14_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind15_stVal,  ucMDiscInBuf[MB_offsetSSL_15] & MB_bOffset_SSL_15) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind15_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind16_stVal,  ucMDiscInBuf[MB_offsetSSL_16] & MB_bOffset_SSL_16) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind16_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind17_stVal,  ucMDiscInBuf[MB_offsetSSL_17] & MB_bOffset_SSL_17) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind17_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind18_stVal,  ucMDiscInBuf[MB_offsetSSL_18] & MB_bOffset_SSL_18) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind18_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind19_stVal,  ucMDiscInBuf[MB_offsetSSL_19] & MB_bOffset_SSL_19) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind19_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind20_stVal,  ucMDiscInBuf[MB_offsetSSL_20] & MB_bOffset_SSL_20) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind20_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind21_stVal,  ucMDiscInBuf[MB_offsetSSL_21] & MB_bOffset_SSL_21) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind21_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind22_stVal,  ucMDiscInBuf[MB_offsetSSL_22] & MB_bOffset_SSL_22) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind22_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind23_stVal,  ucMDiscInBuf[MB_offsetSSL_23] & MB_bOffset_SSL_23) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind23_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind24_stVal,  ucMDiscInBuf[MB_offsetSSL_24] & MB_bOffset_SSL_24) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind24_t, currentTime);

	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind1_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind2_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind3_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind4_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind5_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind6_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind7_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind8_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind9_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind10_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind11_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind12_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind13_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind14_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind15_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind16_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind17_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind18_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind19_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind20_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind21_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind22_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind23_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind24_q,0);
}

/*******************************************************
 * Set_VLSGGIO наполняем оперативными данными
 *******************************************************/
void	Set_VLSGGIO	(uint8_t num, uint64_t currentTime )
{

	uint32_t	Mod = STVALINT32_ON;

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Mod_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_Mod_t, currentTime);
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Beh_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_Beh_t, currentTime);

	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetVLS_1] & MB_bOffset_VLS_1) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind1_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetVLS_2] & MB_bOffset_VLS_2) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind2_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetVLS_3] & MB_bOffset_VLS_3) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind3_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetVLS_4] & MB_bOffset_VLS_4) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind4_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetVLS_5] & MB_bOffset_VLS_5) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind5_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetVLS_6] & MB_bOffset_VLS_6) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind6_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetVLS_7] & MB_bOffset_VLS_7) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind7_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetVLS_8] & MB_bOffset_VLS_8) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind8_t, currentTime);

	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind1_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind2_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind3_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind4_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind5_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind6_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind7_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind8_q,0);
}
/*******************************************************
 * Set_LSGGIO наполняем оперативными данными
 *******************************************************/
void	Set_LSGGIO	(uint8_t num, uint64_t currentTime )
{

	uint32_t	Mod = STVALINT32_ON;

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Mod_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_Mod_t, currentTime);
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Beh_stVal, Mod))
	IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_Beh_t, currentTime);

	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind1_stVal,  ucMDiscInBuf[MB_offsetLS_1] & MB_bOffset_LS_1) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind1_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind2_stVal,  ucMDiscInBuf[MB_offsetLS_2] & MB_bOffset_LS_2) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind2_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind3_stVal,  ucMDiscInBuf[MB_offsetLS_3] & MB_bOffset_LS_3) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind3_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind4_stVal,  ucMDiscInBuf[MB_offsetLS_4] & MB_bOffset_LS_4) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind4_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind5_stVal,  ucMDiscInBuf[MB_offsetLS_5] & MB_bOffset_LS_5) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind5_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind6_stVal,  ucMDiscInBuf[MB_offsetLS_6] & MB_bOffset_LS_6) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind6_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind7_stVal,  ucMDiscInBuf[MB_offsetLS_7] & MB_bOffset_LS_7) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind7_t, currentTime);
	if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind8_stVal,  ucMDiscInBuf[MB_offsetLS_8] & MB_bOffset_LS_8) > 0)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind8_t, currentTime);

	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind1_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind2_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind3_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind4_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind5_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind6_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind7_q,0);
	IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind8_q,0);
}
#endif
