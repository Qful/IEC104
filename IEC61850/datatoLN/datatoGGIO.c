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
 * заглушки
 *******************************************************/

int		Set_NBLKGGIO	(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_FLSGGIO		(uint16_t QTnum, uint64_t currentTime ){return false;}

/*******************************************************
 * Set_VZGGIO наполняем оперативными данными
 *******************************************************/

int	Set_VZGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	int			ret = false;
	uint32_t	Mod;
	uint32_t	Health;
	Quality 	quality;

			Health = STVALINT32_OK;
			if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {Health = STVALINT32_Warning;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Health_stVal, Health)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO1_Health_t, currentTime);
			}

//  Mod Beh

			if ((ucMUstavkiInBuf[MB_offset_Ext_1 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Mod_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO1_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO1_Beh_t, currentTime);
			}

			if ((ucMUstavkiInBuf[MB_offset_Ext_2 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Mod_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO2_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO2_Beh_t, currentTime);
			}

			if ((ucMUstavkiInBuf[MB_offset_Ext_3 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Mod_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO3_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO3_Beh_t, currentTime);
			}

			if ((ucMUstavkiInBuf[MB_offset_Ext_4 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Mod_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO4_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO4_Beh_t, currentTime);
			}

			if ((ucMUstavkiInBuf[MB_offset_Ext_5 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Mod_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO5_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO5_Beh_t, currentTime);
			}

			if ((ucMUstavkiInBuf[MB_offset_Ext_6 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Mod_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO6_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO6_Beh_t, currentTime);
			}

			if ((ucMUstavkiInBuf[MB_offset_Ext_7 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Mod_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO7_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO7_Beh_t, currentTime);
			}

			if ((ucMUstavkiInBuf[MB_offset_Ext_8 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Mod_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO8_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO8_Beh_t, currentTime);
			}

			if ((ucMUstavkiInBuf[MB_offset_Ext_9 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO9_Mod_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO9_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO9_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO9_Beh_t, currentTime);
			}

			if ((ucMUstavkiInBuf[MB_offset_Ext_10 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO10_Mod_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO10_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO10_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO10_Beh_t, currentTime);
			}

			if ((ucMUstavkiInBuf[MB_offset_Ext_11 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO11_Mod_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO11_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO11_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO11_Beh_t, currentTime);
			}

			if ((ucMUstavkiInBuf[MB_offset_Ext_12 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO12_Mod_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO12_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO12_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO12_Beh_t, currentTime);
			}


			if ((ucMUstavkiInBuf[MB_offset_Ext_13 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO13_Mod_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO13_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO13_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO13_Beh_t, currentTime);
			}


			if ((ucMUstavkiInBuf[MB_offset_Ext_14 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO14_Mod_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO14_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO14_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO14_Beh_t, currentTime);
			}


			if ((ucMUstavkiInBuf[MB_offset_Ext_15 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO15_Mod_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO15_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO15_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO15_Beh_t, currentTime);
			}

			if ((ucMUstavkiInBuf[MB_offset_Ext_16 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO16_Mod_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO16_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO16_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO16_Beh_t, currentTime);
			}

//  Quality (Mod Beh)
			quality = QUALITY_VALIDITY_GOOD;
			if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

			if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Mod_q,quality)){
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Beh_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Mod_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Beh_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Mod_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Beh_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Mod_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Beh_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Mod_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Beh_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Mod_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Beh_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Mod_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Beh_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Mod_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Beh_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO9_Mod_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO9_Beh_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO10_Mod_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO10_Beh_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO11_Mod_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO11_Beh_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO12_Mod_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO12_Beh_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO13_Mod_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO13_Beh_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO14_Mod_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO14_Beh_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO15_Mod_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO15_Beh_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO16_Mod_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO16_Beh_q,quality);
			}

//				uint32_t	Alm;

			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_1] & MB_b_SRAB_ext_1))		// СРАБ >1
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Alm_t, currentTime);

			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_2] & MB_b_SRAB_ext_2))		// СРАБ
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Alm_t, currentTime);

			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_3] & MB_b_SRAB_ext_3))		// СРАБ
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Alm_t, currentTime);

			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_4] & MB_b_SRAB_ext_4))		// СРАБ
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Alm_t, currentTime);

			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_5] & MB_b_SRAB_ext_5))		// СРАБ
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Alm_t, currentTime);

			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_6] & MB_b_SRAB_ext_6))		// СРАБ
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Alm_t, currentTime);

			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_7] & MB_b_SRAB_ext_7))		// СРАБ
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Alm_t, currentTime);

			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_8] & MB_b_SRAB_ext_8))		// СРАБ
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Alm_t, currentTime);


			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO9_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_9] & MB_b_SRAB_ext_9))		// СРАБ
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO9_Alm_t, currentTime);


			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO10_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_10] & MB_b_SRAB_ext_10))		// СРАБ
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO10_Alm_t, currentTime);


			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO11_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_11] & MB_b_SRAB_ext_11))		// СРАБ
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO11_Alm_t, currentTime);


			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO12_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_12] & MB_b_SRAB_ext_12))		// СРАБ
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO12_Alm_t, currentTime);


			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO13_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_13] & MB_b_SRAB_ext_13))		// СРАБ
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO13_Alm_t, currentTime);


			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO14_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_14] & MB_b_SRAB_ext_14))		// СРАБ
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO14_Alm_t, currentTime);


			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO15_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_15] & MB_b_SRAB_ext_15))		// СРАБ
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO15_Alm_t, currentTime);


			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO16_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_16] & MB_b_SRAB_ext_16))		// СРАБ
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO16_Alm_t, currentTime);

			quality = QUALITY_VALIDITY_GOOD;
			if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

			if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Alm_q,quality)){
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Alm_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Alm_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Alm_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Alm_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Alm_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Alm_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Alm_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO9_Alm_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO10_Alm_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO11_Alm_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO12_Alm_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO13_Alm_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO14_Alm_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO15_Alm_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO16_Alm_q,quality);

				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Alm_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Alm_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Alm_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Alm_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Alm_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Alm_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Alm_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Alm_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO9_Alm_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO10_Alm_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO11_Alm_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO12_Alm_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO13_Alm_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO14_Alm_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO15_Alm_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO16_Alm_t, currentTime);

			}
}

/*******************************************************
 * Set_AVRGGIO наполняем оперативными данными
 *******************************************************/

int	Set_AVRGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	uint32_t	Mod;
	uint32_t	Health;
	Quality 	quality;
	uint8_t		awr;

			Health = STVALINT32_OK;
			if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {Health = STVALINT32_Warning;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_AVRGGIO_Health_stVal, Health)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_AVRGGIO_Health_t, currentTime);
			}

//  Mod Beh

			if ((ucConfigAWRBuf[MB_offset_ConfAWR] & MB_bOffset_AWR_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}

			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_AVRGGIO_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_AVRGGIO_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_AVRGGIO_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_AVRGGIO_Beh_t, currentTime);
			}

//  Quality (Mod Beh)
			quality = QUALITY_VALIDITY_GOOD;
			if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

			if (IedServer_updateQuality(iedServer,&iedModel_PROT_AVRGGIO_Mod_q,quality)){
				IedServer_updateQuality(iedServer,&iedModel_PROT_AVRGGIO_Beh_q,quality);

				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_AVRGGIO_Mod_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_AVRGGIO_Beh_t, currentTime);
			}

			awr=0;
			if(ucMDiscInBuf[MB_offset_AWR] & MB_b_ON_AWR)  awr = 1;
			if(ucMDiscInBuf[MB_offset_AWR] & MB_b_OFF_AWR) awr = 2;
			if(ucMDiscInBuf[MB_offset_AWR] & MB_b_Blok_AWR) awr = 3;

			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_AVRGGIO_IntIn_stVal, awr))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_AVRGGIO_IntIn_t, currentTime);

			quality = QUALITY_VALIDITY_GOOD;
			if (STVALINT32_Warning == Health) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
			 if (IedServer_updateQuality(iedServer,&iedModel_PROT_AVRGGIO_IntIn_q,quality)){
				 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_AVRGGIO_IntIn_t, currentTime);
			 }
}
/*******************************************************
 * Set_XCBRGGIO наполняем оперативными данными
 *******************************************************/
int	Set_XCBRGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	//--------------------------------
	// сброс флагов
/*
		if ((ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetError)>0){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_stVal,  1))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_stVal,  0))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_q,0);
		}
		if ((ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetSysNote)>0){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_stVal,  1))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_stVal,  0))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_q,0);
		}
		if ((ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetErrorNote)>0){
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_stVal,  1))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_q,0);
		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_stVal,  0))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_q,0);
		}
*/
}

/*******************************************************
 * Set_INGGIO наполняем оперативными данными
 *******************************************************/
uint16_t INBuf[MB_MaxNumbDiscreet][2] ={
		(uint16_t)MB_offsetDiscreet_1,		(uint16_t)MB_bOffset_Discreet_1,
		(uint16_t)MB_offsetDiscreet_2,		(uint16_t)MB_bOffset_Discreet_2,
		(uint16_t)MB_offsetDiscreet_3,		(uint16_t)MB_bOffset_Discreet_3,
		(uint16_t)MB_offsetDiscreet_4,		(uint16_t)MB_bOffset_Discreet_4,
		(uint16_t)MB_offsetDiscreet_5,		(uint16_t)MB_bOffset_Discreet_5,
		(uint16_t)MB_offsetDiscreet_6,		(uint16_t)MB_bOffset_Discreet_6,
		(uint16_t)MB_offsetDiscreet_7,		(uint16_t)MB_bOffset_Discreet_7,
		(uint16_t)MB_offsetDiscreet_8,		(uint16_t)MB_bOffset_Discreet_8,
		(uint16_t)MB_offsetDiscreet_9,		(uint16_t)MB_bOffset_Discreet_9,
		(uint16_t)MB_offsetDiscreet_10,		(uint16_t)MB_bOffset_Discreet_10,
		(uint16_t)MB_offsetDiscreet_11,		(uint16_t)MB_bOffset_Discreet_11,
		(uint16_t)MB_offsetDiscreet_12,		(uint16_t)MB_bOffset_Discreet_12,
		(uint16_t)MB_offsetDiscreet_13,		(uint16_t)MB_bOffset_Discreet_13,
		(uint16_t)MB_offsetDiscreet_14,		(uint16_t)MB_bOffset_Discreet_14,
		(uint16_t)MB_offsetDiscreet_15,		(uint16_t)MB_bOffset_Discreet_15,
		(uint16_t)MB_offsetDiscreet_16,		(uint16_t)MB_bOffset_Discreet_16,
		(uint16_t)MB_offsetDiscreet_17,		(uint16_t)MB_bOffset_Discreet_17,
		(uint16_t)MB_offsetDiscreet_18,		(uint16_t)MB_bOffset_Discreet_18,
		(uint16_t)MB_offsetDiscreet_19,		(uint16_t)MB_bOffset_Discreet_19,
		(uint16_t)MB_offsetDiscreet_20,		(uint16_t)MB_bOffset_Discreet_20,
		(uint16_t)MB_offsetDiscreet_21,		(uint16_t)MB_bOffset_Discreet_21,
		(uint16_t)MB_offsetDiscreet_22,		(uint16_t)MB_bOffset_Discreet_22,
		(uint16_t)MB_offsetDiscreet_23,		(uint16_t)MB_bOffset_Discreet_23,
		(uint16_t)MB_offsetDiscreet_24,		(uint16_t)MB_bOffset_Discreet_24
};
DataAttribute* iedModel_GGIO_INGGIO1_Ind_q[MB_MaxNumbDiscreet] = {
		&iedModel_GGIO_INGGIO1_Ind1_q,		&iedModel_GGIO_INGGIO1_Ind2_q,
		&iedModel_GGIO_INGGIO1_Ind3_q,		&iedModel_GGIO_INGGIO1_Ind4_q,
		&iedModel_GGIO_INGGIO1_Ind5_q,		&iedModel_GGIO_INGGIO1_Ind6_q,
		&iedModel_GGIO_INGGIO1_Ind7_q,		&iedModel_GGIO_INGGIO1_Ind8_q,
		&iedModel_GGIO_INGGIO1_Ind9_q,		&iedModel_GGIO_INGGIO1_Ind10_q,
		&iedModel_GGIO_INGGIO1_Ind11_q,		&iedModel_GGIO_INGGIO1_Ind12_q,
		&iedModel_GGIO_INGGIO1_Ind13_q,		&iedModel_GGIO_INGGIO1_Ind14_q,
		&iedModel_GGIO_INGGIO1_Ind15_q,		&iedModel_GGIO_INGGIO1_Ind16_q,
		&iedModel_GGIO_INGGIO1_Ind17_q,		&iedModel_GGIO_INGGIO1_Ind18_q,
		&iedModel_GGIO_INGGIO1_Ind19_q,		&iedModel_GGIO_INGGIO1_Ind20_q,
		&iedModel_GGIO_INGGIO1_Ind21_q,		&iedModel_GGIO_INGGIO1_Ind22_q,
		&iedModel_GGIO_INGGIO1_Ind23_q,		&iedModel_GGIO_INGGIO1_Ind24_q
};
DataAttribute* iedModel_GGIO_INGGIO1_Ind_t[MB_MaxNumbDiscreet] = {
		&iedModel_GGIO_INGGIO1_Ind1_t,		&iedModel_GGIO_INGGIO1_Ind2_t,
		&iedModel_GGIO_INGGIO1_Ind3_t,		&iedModel_GGIO_INGGIO1_Ind4_t,
		&iedModel_GGIO_INGGIO1_Ind5_t,		&iedModel_GGIO_INGGIO1_Ind6_t,
		&iedModel_GGIO_INGGIO1_Ind7_t,		&iedModel_GGIO_INGGIO1_Ind8_t,
		&iedModel_GGIO_INGGIO1_Ind9_t,		&iedModel_GGIO_INGGIO1_Ind10_t,
		&iedModel_GGIO_INGGIO1_Ind11_t,		&iedModel_GGIO_INGGIO1_Ind12_t,
		&iedModel_GGIO_INGGIO1_Ind13_t,		&iedModel_GGIO_INGGIO1_Ind14_t,
		&iedModel_GGIO_INGGIO1_Ind15_t,		&iedModel_GGIO_INGGIO1_Ind16_t,
		&iedModel_GGIO_INGGIO1_Ind17_t,		&iedModel_GGIO_INGGIO1_Ind18_t,
		&iedModel_GGIO_INGGIO1_Ind19_t,		&iedModel_GGIO_INGGIO1_Ind20_t,
		&iedModel_GGIO_INGGIO1_Ind21_t,		&iedModel_GGIO_INGGIO1_Ind22_t,
		&iedModel_GGIO_INGGIO1_Ind23_t,		&iedModel_GGIO_INGGIO1_Ind24_t
};
DataAttribute* iedModel_GGIO_INGGIO1_Ind_stVal[MB_MaxNumbDiscreet] = {
		&iedModel_GGIO_INGGIO1_Ind1_stVal,		&iedModel_GGIO_INGGIO1_Ind2_stVal,
		&iedModel_GGIO_INGGIO1_Ind3_stVal,		&iedModel_GGIO_INGGIO1_Ind4_stVal,
		&iedModel_GGIO_INGGIO1_Ind5_stVal,		&iedModel_GGIO_INGGIO1_Ind6_stVal,
		&iedModel_GGIO_INGGIO1_Ind7_stVal,		&iedModel_GGIO_INGGIO1_Ind8_stVal,
		&iedModel_GGIO_INGGIO1_Ind9_stVal,		&iedModel_GGIO_INGGIO1_Ind10_stVal,
		&iedModel_GGIO_INGGIO1_Ind11_stVal,		&iedModel_GGIO_INGGIO1_Ind12_stVal,
		&iedModel_GGIO_INGGIO1_Ind13_stVal,		&iedModel_GGIO_INGGIO1_Ind14_stVal,
		&iedModel_GGIO_INGGIO1_Ind15_stVal,		&iedModel_GGIO_INGGIO1_Ind16_stVal,
		&iedModel_GGIO_INGGIO1_Ind17_stVal,		&iedModel_GGIO_INGGIO1_Ind18_stVal,
		&iedModel_GGIO_INGGIO1_Ind19_stVal,		&iedModel_GGIO_INGGIO1_Ind20_stVal,
		&iedModel_GGIO_INGGIO1_Ind21_stVal,		&iedModel_GGIO_INGGIO1_Ind22_stVal,
		&iedModel_GGIO_INGGIO1_Ind23_stVal,		&iedModel_GGIO_INGGIO1_Ind24_stVal
};
// --------------------------------------------------------------------------
int	Set_INGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	uint32_t	Health = STVALINT32_OK;
	uint32_t	Mod = STVALINT32_ON;
	uint8_t 	i;
	int			ret = false;
// Качество и время меняем по надобности ---------------------------------------
	Quality		quality = QUALITY_VALIDITY_GOOD;
	Quality		qualityM2 = QUALITY_VALIDITY_GOOD;
	Quality		qualityM3 = QUALITY_VALIDITY_GOOD;
	bool		Q,T;
	uint16_t	num;
	num = QTnum & 0b0000111111111111;						// номер элемента
	if (QTnum & QUALITY_mask) Q = true; else Q = false;		// менять ли качество
	if (QTnum & TIME_mask) T = true; else T = false;		// менять ли время
//	if(num > MB_MaxNumbDiscreet)	return ret;
// -----------------------------------------------------------------------------

	Health = STVALINT32_OK;
	if ((ucMDiscInBuf[MB_offset_errorM2] & MB_bOffsetModule2)>0)		{Health = STVALINT32_Warning;}
	if ((ucMDiscInBuf[MB_offset_errorM3] & MB_bOffsetModule3)>0)		{Health = STVALINT32_Warning;}
	if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)>0) 	{Health = STVALINT32_Warning;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Health_stVal, Health)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Health_t, currentTime);
	}

	// одинаковые всегда если не изменился то быстрее проверить только один
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Beh_t, currentTime);
	}

	if (Q) {
		if ((ucMDiscInBuf[MB_offset_errorM2] & MB_bOffsetModule2)>0)		qualityM2 = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
		if ((ucMDiscInBuf[MB_offset_errorM3] & MB_bOffsetModule3)>0)		qualityM3 = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
	}

	// прогнали по всем
	for (i = 0; i < MB_MaxNumbDiscreet; i++) {
		if ((num == 0) || (num == i+1)){
			// GOOSE отсылается сразу, надо бы проверить весь датасет сначала
			// сказать функции не отсылать пока не разрешу
			if ( IedServer_updateBooleanAttributeValue(iedServer, iedModel_GGIO_INGGIO1_Ind_stVal[i],  ucMDiscInBuf[INBuf[i][0]] & INBuf[i][1]) > 0)
				{
					if (T) IedServer_updateUTCTimeAttributeValue(iedServer, iedModel_GGIO_INGGIO1_Ind_t[i], currentTime);
					ret = true;
				}

			if (Q) {
				if (i>=0 && i<8)  quality = qualityM2; else
				if (i>7 && i<24) quality = qualityM3;
				if (IedServer_updateQuality(iedServer, iedModel_GGIO_INGGIO1_Ind_q[i],quality)){
					if (T) IedServer_updateUTCTimeAttributeValue(iedServer, iedModel_GGIO_INGGIO1_Ind_t[i], currentTime);
					ret = true;
				}
			}
		}
	}

return	ret;
}

/*******************************************************
 * Set_OUTGGIO наполняем оперативными данными
 *******************************************************/
uint16_t OUTBuf[MB_MaxNumbRelay][2] ={
		MB_offsetRelay_1,		MB_bOffset_Relay_1,
		MB_offsetRelay_2,		MB_bOffset_Relay_2,
		MB_offsetRelay_3,		MB_bOffset_Relay_3,
		MB_offsetRelay_4,		MB_bOffset_Relay_4,
		MB_offsetRelay_5,		MB_bOffset_Relay_5,
		MB_offsetRelay_6,		MB_bOffset_Relay_6,
		MB_offsetRelay_7,		MB_bOffset_Relay_7,
		MB_offsetRelay_8,		MB_bOffset_Relay_8,
		MB_offsetRelay_9,		MB_bOffset_Relay_9,
		MB_offsetRelay_10,		MB_bOffset_Relay_10,
		MB_offsetRelay_11,		MB_bOffset_Relay_11,
		MB_offsetRelay_12,		MB_bOffset_Relay_12,
		MB_offsetRelay_13,		MB_bOffset_Relay_13,
		MB_offsetRelay_14,		MB_bOffset_Relay_14,
		MB_offsetRelay_15,		MB_bOffset_Relay_15,
		MB_offsetRelay_16,		MB_bOffset_Relay_16,
		MB_offsetRelay_17,		MB_bOffset_Relay_17,
		MB_offsetRelay_18,		MB_bOffset_Relay_18
};
DataAttribute* iedModel_GGIO_OUTGGIO1_SPCSO_q[MB_MaxNumbRelay] = {
		&iedModel_GGIO_OUTGGIO1_SPCSO1_q,		&iedModel_GGIO_OUTGGIO1_SPCSO2_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO3_q,		&iedModel_GGIO_OUTGGIO1_SPCSO4_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO5_q,		&iedModel_GGIO_OUTGGIO1_SPCSO6_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO7_q,		&iedModel_GGIO_OUTGGIO1_SPCSO8_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO9_q,		&iedModel_GGIO_OUTGGIO1_SPCSO10_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO11_q,		&iedModel_GGIO_OUTGGIO1_SPCSO12_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO13_q,		&iedModel_GGIO_OUTGGIO1_SPCSO14_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO15_q,		&iedModel_GGIO_OUTGGIO1_SPCSO16_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO17_q,		&iedModel_GGIO_OUTGGIO1_SPCSO18_q
};
DataAttribute* iedModel_GGIO_OUTGGIO1_SPCSO_t[MB_MaxNumbRelay] = {
		&iedModel_GGIO_OUTGGIO1_SPCSO1_t,		&iedModel_GGIO_OUTGGIO1_SPCSO2_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO3_t,		&iedModel_GGIO_OUTGGIO1_SPCSO4_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO5_t,		&iedModel_GGIO_OUTGGIO1_SPCSO6_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO7_t,		&iedModel_GGIO_OUTGGIO1_SPCSO8_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO9_t,		&iedModel_GGIO_OUTGGIO1_SPCSO10_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO11_t,		&iedModel_GGIO_OUTGGIO1_SPCSO12_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO13_t,		&iedModel_GGIO_OUTGGIO1_SPCSO14_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO15_t,		&iedModel_GGIO_OUTGGIO1_SPCSO16_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO17_t,		&iedModel_GGIO_OUTGGIO1_SPCSO18_t
};
DataAttribute* iedModel_GGIO_OUTGGIO1_SPCSO_stVal[MB_MaxNumbRelay] = {
		&iedModel_GGIO_OUTGGIO1_SPCSO1_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO2_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO3_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO4_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO5_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO6_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO7_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO8_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO9_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO10_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO11_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO12_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO13_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO14_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO15_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO16_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO17_stVal,	&iedModel_GGIO_OUTGGIO1_SPCSO18_stVal
};
//------------------------------------------------------------------------
int	Set_OUTGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	uint32_t	Mod = STVALINT32_ON;
	uint32_t	Health = STVALINT32_ON;
	uint8_t		i;
	int	ret = false;
// Качество и время меняем по надобности ---------------------------------------
	Quality		quality  = QUALITY_VALIDITY_GOOD;
	Quality		qualityM1 = QUALITY_VALIDITY_GOOD;
	Quality		qualityM2 = QUALITY_VALIDITY_GOOD;
	bool		Q;
	bool		T;
	uint16_t	num;
	num = QTnum & 0b0000111111111111;						// номер элемента
	if (QTnum & QUALITY_mask) Q = true; else Q = false;		// менять ли качество
	if (QTnum & TIME_mask) T = true; else T = false;		// менять ли время
	if(num > MB_MaxNumbRelay)	return ret;
// -----------------------------------------------------------------------------

	if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule1)>0)  {Health = STVALINT32_Warning;}
	if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule2)>0)  {Health = STVALINT32_Warning;}
	if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {Health = STVALINT32_Warning;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Health_stVal, Health)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_Health_t, currentTime);
	}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_Beh_t, currentTime);
	}

	if (Q) {
		if ((ucMDiscInBuf[MB_offset_errorM1] & MB_bOffsetModule1)>0)		qualityM1 = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
		if ((ucMDiscInBuf[MB_offset_errorM2] & MB_bOffsetModule2)>0)		qualityM2 = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
	}

	// ~2K программного кода меньше чем старая реализация
	// прогнали по всем
	for (i = 0; i < MB_MaxNumbRelay; i++) {
		if (num == 0 || num == i+1){
			if ( IedServer_updateBooleanAttributeValue(iedServer, iedModel_GGIO_OUTGGIO1_SPCSO_stVal[i],  ucMDiscInBuf[OUTBuf[i][0]] & OUTBuf[i][1]) > 0)
				{
					if (T) IedServer_updateUTCTimeAttributeValue(iedServer, iedModel_GGIO_OUTGGIO1_SPCSO_t[i], currentTime);
					ret = true;
				}
			if (Q) {
				if (i>=0 && i<10)  quality = qualityM1; else
				if (i>9  && i<19) quality = qualityM2;
				if (IedServer_updateQuality(iedServer, iedModel_GGIO_OUTGGIO1_SPCSO_q[i],quality)) {
					if (T) IedServer_updateUTCTimeAttributeValue(iedServer, iedModel_GGIO_OUTGGIO1_SPCSO_t[i], currentTime);
					ret = true;
				}
			}
		}
	}
return	ret;
}

/*******************************************************
 * Set_LEDGGIO наполняем оперативными данными
 *******************************************************/
int	Set_LEDGGIO	(uint16_t QTnum, uint64_t currentTime )
{


	bool value;
	uint32_t	Mod = STVALINT32_ON;
	int	ret = false;
// Качество и время меняем по надобности ---------------------------------------
	Quality		quality = QUALITY_VALIDITY_GOOD;
	bool		Q;
	bool		T;
	uint16_t	num;
	num = QTnum & 0b0000111111111111;						// номер элемента
	if (QTnum & QUALITY_mask) Q = true; else Q = false;		// менять ли качество
	if (QTnum & TIME_mask) T = true; else T = false;		// менять ли время
	if(num > MB_MaxNumbLED)	return ret;
// -----------------------------------------------------------------------------

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_Beh_t, currentTime);
	}


	if (num == 0 || num == 1){
		value = ((ucMDiscInBuf[MB_offsetLED_1] & MB_bOffset_LED_1));
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_stVal,  value) > 0)
			{
			ret = true;
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_t, currentTime);
			}
	}
	if (num == 0 || num == 2){
		value = ((ucMDiscInBuf[MB_offsetLED_2] & MB_bOffset_LED_2));
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_stVal,  value) > 0)
			{
			ret = true;
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_t, currentTime);
			}
	}
	if (num == 0 || num == 3){
		value = ((ucMDiscInBuf[MB_offsetLED_3] & MB_bOffset_LED_3));
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_stVal,  value) > 0)
			{
			ret = true;
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_t, currentTime);
			}
	}
	if (num == 0 || num == 4){
		value = ((ucMDiscInBuf[MB_offsetLED_4] & MB_bOffset_LED_4));
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_stVal,  value) > 0)
			{
			ret = true;
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_t, currentTime);
			}
	}
	if (num == 0 || num == 5){
		value = ((ucMDiscInBuf[MB_offsetLED_5] & MB_bOffset_LED_5));
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_stVal,  value) > 0)
			{
			ret = true;
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_t, currentTime);
			}
	}
	if (num == 0 || num == 6){
		value = ((ucMDiscInBuf[MB_offsetLED_6] & MB_bOffset_LED_6));
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_stVal,  value) > 0)
			{
			ret = true;
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_t, currentTime);
			}
	}
	if (num == 0 || num == 7){
		value = ((ucMDiscInBuf[MB_offsetLED_7] & MB_bOffset_LED_7));
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_stVal,  value) > 0)
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_t, currentTime);
	}
	if (num == 0 || num == 8){
		value = ((ucMDiscInBuf[MB_offsetLED_8] & MB_bOffset_LED_8));
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_stVal,  value) > 0)
			{
			ret = true;
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_t, currentTime);
			}
	}
	if (num == 0 || num == 9){
		value = ((ucMDiscInBuf[MB_offsetLED_9] & MB_bOffset_LED_9));
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_stVal,  value) > 0)
			{
			ret = true;
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_t, currentTime);
			}
	}
	if (num == 0 || num == 10){
		value = ((ucMDiscInBuf[MB_offsetLED_10] & MB_bOffset_LED_10));
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_stVal, value) > 0)
			{
			ret = true;
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_t, currentTime);
			}
	}
	if (num == 0 || num == 11){
		value = ((ucMDiscInBuf[MB_offsetLED_11] & MB_bOffset_LED_11));
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_stVal, value) > 0)
			{
			ret = true;
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_t, currentTime);
			}
	}
	if (num == 0 || num == 12){
		value = ((ucMDiscInBuf[MB_offsetLED_12] & MB_bOffset_LED_12));
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_stVal, value) > 0)
			{
			ret = true;
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_t, currentTime);
			}
	}
	if (num == 0 || num == 13){
		value = ((ucMDiscInBuf[MB_offsetLED_13] & MB_bOffset_LED_13));
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind13_stVal, value) > 0)
			{
			ret = true;
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind13_t, currentTime);
			}
	}
	if (num == 0 || num == 14){
		value = ((ucMDiscInBuf[MB_offsetLED_14] & MB_bOffset_LED_14));
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind14_stVal, value) > 0)
			{
			ret = true;
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind14_t, currentTime);
			}
	}
	if (num == 0 || num == 15){
		value = ((ucMDiscInBuf[MB_offsetLED_15] & MB_bOffset_LED_15));
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind15_stVal, value) > 0)
			{
			ret = true;
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind15_t, currentTime);
			}
	}
	if (num == 0 || num == 16){
		value = ((ucMDiscInBuf[MB_offsetLED_16] & MB_bOffset_LED_16));
		if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind16_stVal, value) > 0)
			{
			ret = true;
			if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind16_t, currentTime);
			}
	}

	quality = QUALITY_VALIDITY_GOOD;
	if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

	// никогда не меняется, смысл его постоянно обновлять
	if (Q) {
		if (num == 0 || num == 1)	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_q, quality);
		if (num == 0 || num == 2)	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_q, quality);
		if (num == 0 || num == 3)	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_q, quality);
		if (num == 0 || num == 4)	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_q, quality);
		if (num == 0 || num == 5)	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_q, quality);
		if (num == 0 || num == 6)	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_q, quality);
		if (num == 0 || num == 7)	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_q, quality);
		if (num == 0 || num == 8)	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_q, quality);
		if (num == 0 || num == 9)	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_q, quality);
		if (num == 0 || num == 10)	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_q,quality);
		if (num == 0 || num == 11)	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_q,quality);
		if (num == 0 || num == 12)	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_q,quality);
		if (num == 0 || num == 13)	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind13_q,quality);
		if (num == 0 || num == 14)	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind14_q,quality);
		//if (num == 0 || num == 15)	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind15_q,quality);
		//if (num == 0 || num == 16)	IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind16_q,quality);

		if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_t, currentTime);
		if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_t, currentTime);
		if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_t, currentTime);
		if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_t, currentTime);
		if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_t, currentTime);
		if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_t, currentTime);
		if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_t, currentTime);
		if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_t, currentTime);
		if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_t, currentTime);
		if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_t, currentTime);
		if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_t, currentTime);
		if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_t, currentTime);
		if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind13_t, currentTime);
		if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind14_t, currentTime);
		//if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind15_t, currentTime);
		//if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind16_t, currentTime);

	}

return	ret;
}
/*******************************************************
 * Set_SSLGGIO наполняем оперативными данными
 *******************************************************/
uint16_t SSLBuf[MB_MaxNumbSSL][2] ={
		MB_offsetSSL_1,		MB_bOffset_SSL_1,
		MB_offsetSSL_2,		MB_bOffset_SSL_2,
		MB_offsetSSL_3,		MB_bOffset_SSL_3,
		MB_offsetSSL_4,		MB_bOffset_SSL_4,
		MB_offsetSSL_5,		MB_bOffset_SSL_5,
		MB_offsetSSL_6,		MB_bOffset_SSL_6,
		MB_offsetSSL_7,		MB_bOffset_SSL_7,
		MB_offsetSSL_8,		MB_bOffset_SSL_8,
		MB_offsetSSL_9,		MB_bOffset_SSL_9,
		MB_offsetSSL_10,	MB_bOffset_SSL_10,
		MB_offsetSSL_11,	MB_bOffset_SSL_11,
		MB_offsetSSL_12,	MB_bOffset_SSL_12,
		MB_offsetSSL_13,	MB_bOffset_SSL_13,
		MB_offsetSSL_14,	MB_bOffset_SSL_14,
		MB_offsetSSL_15,	MB_bOffset_SSL_15,
		MB_offsetSSL_16,	MB_bOffset_SSL_16,
		MB_offsetSSL_17,	MB_bOffset_SSL_17,
		MB_offsetSSL_18,	MB_bOffset_SSL_18,
		MB_offsetSSL_19,	MB_bOffset_SSL_19,
		MB_offsetSSL_20,	MB_bOffset_SSL_20,
		MB_offsetSSL_21,	MB_bOffset_SSL_21,
		MB_offsetSSL_22,	MB_bOffset_SSL_22,
		MB_offsetSSL_23,	MB_bOffset_SSL_23,
		MB_offsetSSL_24,	MB_bOffset_SSL_24,
		MB_offsetSSL_25,	MB_bOffset_SSL_25,
		MB_offsetSSL_26,	MB_bOffset_SSL_26,
		MB_offsetSSL_27,	MB_bOffset_SSL_27,
		MB_offsetSSL_28,	MB_bOffset_SSL_28,
		MB_offsetSSL_29,	MB_bOffset_SSL_29,
		MB_offsetSSL_30,	MB_bOffset_SSL_30,
		MB_offsetSSL_31,	MB_bOffset_SSL_31,
		MB_offsetSSL_32,	MB_bOffset_SSL_32
};
DataAttribute* iedModel_GGIO_SSLGGIO_Ind_q[MB_MaxNumbSSL] = {
		&iedModel_GGIO_SSLGGIO1_Ind1_q,		&iedModel_GGIO_SSLGGIO1_Ind2_q,
		&iedModel_GGIO_SSLGGIO1_Ind3_q,		&iedModel_GGIO_SSLGGIO1_Ind4_q,
		&iedModel_GGIO_SSLGGIO1_Ind5_q,		&iedModel_GGIO_SSLGGIO1_Ind6_q,
		&iedModel_GGIO_SSLGGIO1_Ind7_q,		&iedModel_GGIO_SSLGGIO1_Ind8_q,
		&iedModel_GGIO_SSLGGIO1_Ind9_q,		&iedModel_GGIO_SSLGGIO1_Ind10_q,
		&iedModel_GGIO_SSLGGIO1_Ind11_q,	&iedModel_GGIO_SSLGGIO1_Ind12_q,
		&iedModel_GGIO_SSLGGIO1_Ind13_q,	&iedModel_GGIO_SSLGGIO1_Ind14_q,
		&iedModel_GGIO_SSLGGIO1_Ind15_q,	&iedModel_GGIO_SSLGGIO1_Ind16_q,
		&iedModel_GGIO_SSLGGIO1_Ind17_q,	&iedModel_GGIO_SSLGGIO1_Ind18_q,
		&iedModel_GGIO_SSLGGIO1_Ind19_q,	&iedModel_GGIO_SSLGGIO1_Ind20_q,
		&iedModel_GGIO_SSLGGIO1_Ind21_q,	&iedModel_GGIO_SSLGGIO1_Ind22_q,
		&iedModel_GGIO_SSLGGIO1_Ind23_q,	&iedModel_GGIO_SSLGGIO1_Ind24_q,
		&iedModel_GGIO_SSLGGIO1_Ind25_q,	&iedModel_GGIO_SSLGGIO1_Ind26_q,
		&iedModel_GGIO_SSLGGIO1_Ind27_q,	&iedModel_GGIO_SSLGGIO1_Ind28_q,
		&iedModel_GGIO_SSLGGIO1_Ind29_q,	&iedModel_GGIO_SSLGGIO1_Ind30_q,
		&iedModel_GGIO_SSLGGIO1_Ind31_q,	&iedModel_GGIO_SSLGGIO1_Ind32_q

};
DataAttribute* iedModel_GGIO_SSLGGIO_Ind_t[MB_MaxNumbSSL] = {
		&iedModel_GGIO_SSLGGIO1_Ind1_t,		&iedModel_GGIO_SSLGGIO1_Ind2_t,
		&iedModel_GGIO_SSLGGIO1_Ind3_t,		&iedModel_GGIO_SSLGGIO1_Ind4_t,
		&iedModel_GGIO_SSLGGIO1_Ind5_t,		&iedModel_GGIO_SSLGGIO1_Ind6_t,
		&iedModel_GGIO_SSLGGIO1_Ind7_t,		&iedModel_GGIO_SSLGGIO1_Ind8_t,
		&iedModel_GGIO_SSLGGIO1_Ind9_t,		&iedModel_GGIO_SSLGGIO1_Ind10_t,
		&iedModel_GGIO_SSLGGIO1_Ind11_t,	&iedModel_GGIO_SSLGGIO1_Ind12_t,
		&iedModel_GGIO_SSLGGIO1_Ind13_t,	&iedModel_GGIO_SSLGGIO1_Ind14_t,
		&iedModel_GGIO_SSLGGIO1_Ind15_t,	&iedModel_GGIO_SSLGGIO1_Ind16_t,
		&iedModel_GGIO_SSLGGIO1_Ind17_t,	&iedModel_GGIO_SSLGGIO1_Ind18_t,
		&iedModel_GGIO_SSLGGIO1_Ind19_t,	&iedModel_GGIO_SSLGGIO1_Ind20_t,
		&iedModel_GGIO_SSLGGIO1_Ind21_t,	&iedModel_GGIO_SSLGGIO1_Ind22_t,
		&iedModel_GGIO_SSLGGIO1_Ind23_t,	&iedModel_GGIO_SSLGGIO1_Ind24_t,
		&iedModel_GGIO_SSLGGIO1_Ind25_t,	&iedModel_GGIO_SSLGGIO1_Ind26_t,
		&iedModel_GGIO_SSLGGIO1_Ind27_t,	&iedModel_GGIO_SSLGGIO1_Ind28_t,
		&iedModel_GGIO_SSLGGIO1_Ind29_t,	&iedModel_GGIO_SSLGGIO1_Ind30_t,
		&iedModel_GGIO_SSLGGIO1_Ind31_t,	&iedModel_GGIO_SSLGGIO1_Ind32_t
};
DataAttribute* iedModel_GGIO_SSLGGIO_Ind_stVal[MB_MaxNumbSSL] = {
		&iedModel_GGIO_SSLGGIO1_Ind1_stVal,		&iedModel_GGIO_SSLGGIO1_Ind2_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind3_stVal,		&iedModel_GGIO_SSLGGIO1_Ind4_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind5_stVal,		&iedModel_GGIO_SSLGGIO1_Ind6_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind7_stVal,		&iedModel_GGIO_SSLGGIO1_Ind8_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind9_stVal,		&iedModel_GGIO_SSLGGIO1_Ind10_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind11_stVal,	&iedModel_GGIO_SSLGGIO1_Ind12_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind13_stVal,	&iedModel_GGIO_SSLGGIO1_Ind14_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind15_stVal,	&iedModel_GGIO_SSLGGIO1_Ind16_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind17_stVal,	&iedModel_GGIO_SSLGGIO1_Ind18_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind19_stVal,	&iedModel_GGIO_SSLGGIO1_Ind20_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind21_stVal,	&iedModel_GGIO_SSLGGIO1_Ind22_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind23_stVal,	&iedModel_GGIO_SSLGGIO1_Ind24_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind25_stVal,	&iedModel_GGIO_SSLGGIO1_Ind26_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind27_stVal,	&iedModel_GGIO_SSLGGIO1_Ind28_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind29_stVal,	&iedModel_GGIO_SSLGGIO1_Ind30_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind31_stVal,	&iedModel_GGIO_SSLGGIO1_Ind32_stVal
};
/*******************************************************
 *******************************************************/
int	Set_SSLGGIO	(uint16_t QTnum, uint64_t currentTime )
{

	uint8_t	i;
	int	ret = false;
	// Качество и время меняем по надобности ---------------------------------------
		Quality		quality = QUALITY_VALIDITY_GOOD;
		bool		Q;
		bool		T;
		uint16_t	num;
		num = QTnum & 0b0000111111111111;						// номер элемента
		if (QTnum & QUALITY_mask) Q = true; else Q = false;		// менять ли качество
		if (QTnum & TIME_mask) T = true; else T = false;		// менять ли время
		if(num > MB_MaxNumbSSL)	return ret;
	// -----------------------------------------------------------------------------
		uint32_t	Mod 	= STVALINT32_OFF;
		uint32_t	Health 	= STVALINT32_OK;

		if (ucMDiscInBuf[MB_offset_LogicError] & MB_bOffsetALLLogicError) 	{Health  = STVALINT32_Warning;quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
		if (ucMDiscInBuf[MB_offset_LogicMod] & MB_bOffsetLogicMod_ON)		Mod	= STVALINT32_ON;

//Health
/*
		if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {Health = STVALINT32_Warning;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Health_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_Health_t, currentTime);
		}
*/

#if defined (MR801) && (_REVISION_DEVICE<=207)		//2.07		ошибка в приборе. не верно выставляет этот флаг
		Mod	= STVALINT32_ON;
#endif

		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Health_stVal, Health))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_Health_t, currentTime);

		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Mod_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_Beh_t, currentTime);
		}


	// прогнали по всем
	for (i = 0; i < MB_MaxNumbSSL; i++) {
		if (num == 0 || num == i+1){
			if ( IedServer_updateBooleanAttributeValue(iedServer, iedModel_GGIO_SSLGGIO_Ind_stVal[i],  ucMDiscInBuf[SSLBuf[i][0]] & SSLBuf[i][1]) > 0)
				{
					if (T) IedServer_updateUTCTimeAttributeValue(iedServer, iedModel_GGIO_SSLGGIO_Ind_t[i], currentTime);
					ret = true;
				}
			if (Q) if (IedServer_updateQuality(iedServer, iedModel_GGIO_SSLGGIO_Ind_q[i],quality))
					{
						if (T) IedServer_updateUTCTimeAttributeValue(iedServer, iedModel_GGIO_SSLGGIO_Ind_t[i], currentTime);
						ret = true;
					}
		}
	}
return ret;
}
/*******************************************************
 * Set_VLSGGIO наполняем оперативными данными
 *******************************************************/
uint16_t VLSBuf[MB_MaxNumbVLS][2] ={
		MB_offsetVLS_1,		MB_bOffset_VLS_1,
		MB_offsetVLS_2,		MB_bOffset_VLS_2,
		MB_offsetVLS_3,		MB_bOffset_VLS_3,
		MB_offsetVLS_4,		MB_bOffset_VLS_4,
		MB_offsetVLS_5,		MB_bOffset_VLS_5,
		MB_offsetVLS_6,		MB_bOffset_VLS_6,
		MB_offsetVLS_7,		MB_bOffset_VLS_7,
		MB_offsetVLS_8,		MB_bOffset_VLS_8,
		MB_offsetVLS_9,		MB_bOffset_VLS_9,
		MB_offsetVLS_10,	MB_bOffset_VLS_10,
		MB_offsetVLS_11,	MB_bOffset_VLS_11,
		MB_offsetVLS_12,	MB_bOffset_VLS_12,
		MB_offsetVLS_13,	MB_bOffset_VLS_13,
		MB_offsetVLS_14,	MB_bOffset_VLS_14,
		MB_offsetVLS_15,	MB_bOffset_VLS_15,
		MB_offsetVLS_16,	MB_bOffset_VLS_16,
};
DataAttribute* iedModel_GGIO_VLSGGIO_Ind_q[MB_MaxNumbVLS] = {
		&iedModel_GGIO_VLSGGIO1_Ind1_q,		&iedModel_GGIO_VLSGGIO1_Ind2_q,
		&iedModel_GGIO_VLSGGIO1_Ind3_q,		&iedModel_GGIO_VLSGGIO1_Ind4_q,
		&iedModel_GGIO_VLSGGIO1_Ind5_q,		&iedModel_GGIO_VLSGGIO1_Ind6_q,
		&iedModel_GGIO_VLSGGIO1_Ind7_q,		&iedModel_GGIO_VLSGGIO1_Ind8_q,
		&iedModel_GGIO_VLSGGIO1_Ind9_q,		&iedModel_GGIO_VLSGGIO1_Ind10_q,
		&iedModel_GGIO_VLSGGIO1_Ind11_q,	&iedModel_GGIO_VLSGGIO1_Ind12_q,
		&iedModel_GGIO_VLSGGIO1_Ind13_q,	&iedModel_GGIO_VLSGGIO1_Ind14_q,
		&iedModel_GGIO_VLSGGIO1_Ind15_q,	&iedModel_GGIO_VLSGGIO1_Ind16_q,

};
DataAttribute* iedModel_GGIO_VLSGGIO_Ind_t[MB_MaxNumbVLS] = {
		&iedModel_GGIO_VLSGGIO1_Ind1_t,		&iedModel_GGIO_VLSGGIO1_Ind2_t,
		&iedModel_GGIO_VLSGGIO1_Ind3_t,		&iedModel_GGIO_VLSGGIO1_Ind4_t,
		&iedModel_GGIO_VLSGGIO1_Ind5_t,		&iedModel_GGIO_VLSGGIO1_Ind6_t,
		&iedModel_GGIO_VLSGGIO1_Ind7_t,		&iedModel_GGIO_VLSGGIO1_Ind8_t,
		&iedModel_GGIO_VLSGGIO1_Ind9_t,		&iedModel_GGIO_VLSGGIO1_Ind10_t,
		&iedModel_GGIO_VLSGGIO1_Ind11_t,	&iedModel_GGIO_VLSGGIO1_Ind12_t,
		&iedModel_GGIO_VLSGGIO1_Ind13_t,	&iedModel_GGIO_VLSGGIO1_Ind14_t,
		&iedModel_GGIO_VLSGGIO1_Ind15_t,	&iedModel_GGIO_VLSGGIO1_Ind16_t,
};
DataAttribute* iedModel_GGIO_VLSGGIO_Ind_stVal[MB_MaxNumbVLS] = {
		&iedModel_GGIO_VLSGGIO1_Ind1_stVal,		&iedModel_GGIO_VLSGGIO1_Ind2_stVal,
		&iedModel_GGIO_VLSGGIO1_Ind3_stVal,		&iedModel_GGIO_VLSGGIO1_Ind4_stVal,
		&iedModel_GGIO_VLSGGIO1_Ind5_stVal,		&iedModel_GGIO_VLSGGIO1_Ind6_stVal,
		&iedModel_GGIO_VLSGGIO1_Ind7_stVal,		&iedModel_GGIO_VLSGGIO1_Ind8_stVal,
		&iedModel_GGIO_VLSGGIO1_Ind9_stVal,		&iedModel_GGIO_VLSGGIO1_Ind10_stVal,
		&iedModel_GGIO_VLSGGIO1_Ind11_stVal,	&iedModel_GGIO_VLSGGIO1_Ind12_stVal,
		&iedModel_GGIO_VLSGGIO1_Ind13_stVal,	&iedModel_GGIO_VLSGGIO1_Ind14_stVal,
		&iedModel_GGIO_VLSGGIO1_Ind15_stVal,	&iedModel_GGIO_VLSGGIO1_Ind16_stVal,
};
/*******************************************************
 *******************************************************/
int	Set_VLSGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	uint8_t	i;
	int	ret = false;
	// Качество и время меняем по надобности ---------------------------------------
		bool		Q;
		bool		T;
		uint16_t	num;
		num = QTnum & 0b0000111111111111;						// номер элемента
		if (QTnum & QUALITY_mask) Q = true; else Q = false;		// менять ли качество
		if (QTnum & TIME_mask) T = true; else T = false;		// менять ли время
		if(num > MB_MaxNumbVLS)	return ret;
	// -----------------------------------------------------------------------------
	uint32_t	Health = STVALINT32_OK;
	uint32_t	Mod = STVALINT32_ON;
	Quality 	quality;

//Mod
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_Beh_t, currentTime);
	}
//Health
	if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {Health = STVALINT32_Warning;}
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Health_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_Health_t, currentTime);
	}

//quality
	quality = QUALITY_VALIDITY_GOOD;
	if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

	// прогнали по всем
	for (i = 0; i < MB_MaxNumbVLS; i++) {
		if (num == 0 || num == i+1){
			if ( IedServer_updateBooleanAttributeValue(iedServer, iedModel_GGIO_VLSGGIO_Ind_stVal[i],  ucMDiscInBuf[VLSBuf[i][0]] & VLSBuf[i][1]) > 0)
				{
					if (T) IedServer_updateUTCTimeAttributeValue(iedServer, iedModel_GGIO_VLSGGIO_Ind_t[i], currentTime);
					ret = true;
				}
			if (Q) if (IedServer_updateQuality(iedServer, iedModel_GGIO_VLSGGIO_Ind_q[i],quality))
					{
						if (T) IedServer_updateUTCTimeAttributeValue(iedServer, iedModel_GGIO_VLSGGIO_Ind_t[i], currentTime);
						ret = true;
					}
		}
	}

return ret;
}

/*******************************************************
 * Set_LSGGIO наполняем оперативными данными
 *******************************************************/
uint16_t LSBuf[MB_MaxNumbLS][2] ={
		MB_offsetLS_1,		MB_bOffset_LS_1,
		MB_offsetLS_2,		MB_bOffset_LS_2,
		MB_offsetLS_3,		MB_bOffset_LS_3,
		MB_offsetLS_4,		MB_bOffset_LS_4,
		MB_offsetLS_5,		MB_bOffset_LS_5,
		MB_offsetLS_6,		MB_bOffset_LS_6,
		MB_offsetLS_7,		MB_bOffset_LS_7,
		MB_offsetLS_8,		MB_bOffset_LS_8,
		MB_offsetLS_9,		MB_bOffset_LS_9,
		MB_offsetLS_10,		MB_bOffset_LS_10,
		MB_offsetLS_11,		MB_bOffset_LS_11,
		MB_offsetLS_12,		MB_bOffset_LS_12,
		MB_offsetLS_13,		MB_bOffset_LS_13,
		MB_offsetLS_14,		MB_bOffset_LS_14,
		MB_offsetLS_15,		MB_bOffset_LS_15,
		MB_offsetLS_16,		MB_bOffset_LS_16
};
DataAttribute* iedModel_GGIO_LSGGIO_Ind_q[MB_MaxNumbLS] = {
		&iedModel_GGIO_LSGGIO1_Ind1_q,		&iedModel_GGIO_LSGGIO1_Ind2_q,
		&iedModel_GGIO_LSGGIO1_Ind3_q,		&iedModel_GGIO_LSGGIO1_Ind4_q,
		&iedModel_GGIO_LSGGIO1_Ind5_q,		&iedModel_GGIO_LSGGIO1_Ind6_q,
		&iedModel_GGIO_LSGGIO1_Ind7_q,		&iedModel_GGIO_LSGGIO1_Ind8_q,
		&iedModel_GGIO_LSGGIO1_Ind9_q,		&iedModel_GGIO_LSGGIO1_Ind10_q,
		&iedModel_GGIO_LSGGIO1_Ind11_q,		&iedModel_GGIO_LSGGIO1_Ind12_q,
		&iedModel_GGIO_LSGGIO1_Ind13_q,		&iedModel_GGIO_LSGGIO1_Ind14_q,
		&iedModel_GGIO_LSGGIO1_Ind15_q,		&iedModel_GGIO_LSGGIO1_Ind16_q

};
DataAttribute* iedModel_GGIO_LSGGIO_Ind_t[MB_MaxNumbLS] = {
		&iedModel_GGIO_LSGGIO1_Ind1_t,		&iedModel_GGIO_LSGGIO1_Ind2_t,
		&iedModel_GGIO_LSGGIO1_Ind3_t,		&iedModel_GGIO_LSGGIO1_Ind4_t,
		&iedModel_GGIO_LSGGIO1_Ind5_t,		&iedModel_GGIO_LSGGIO1_Ind6_t,
		&iedModel_GGIO_LSGGIO1_Ind7_t,		&iedModel_GGIO_LSGGIO1_Ind8_t,
		&iedModel_GGIO_LSGGIO1_Ind9_t,		&iedModel_GGIO_LSGGIO1_Ind10_t,
		&iedModel_GGIO_LSGGIO1_Ind11_t,		&iedModel_GGIO_LSGGIO1_Ind12_t,
		&iedModel_GGIO_LSGGIO1_Ind13_t,		&iedModel_GGIO_LSGGIO1_Ind14_t,
		&iedModel_GGIO_LSGGIO1_Ind15_t,		&iedModel_GGIO_LSGGIO1_Ind16_t
};
DataAttribute* iedModel_GGIO_LSGGIO_Ind_stVal[MB_MaxNumbLS] = {
		&iedModel_GGIO_LSGGIO1_Ind1_stVal,		&iedModel_GGIO_LSGGIO1_Ind2_stVal,
		&iedModel_GGIO_LSGGIO1_Ind3_stVal,		&iedModel_GGIO_LSGGIO1_Ind4_stVal,
		&iedModel_GGIO_LSGGIO1_Ind5_stVal,		&iedModel_GGIO_LSGGIO1_Ind6_stVal,
		&iedModel_GGIO_LSGGIO1_Ind7_stVal,		&iedModel_GGIO_LSGGIO1_Ind8_stVal,
		&iedModel_GGIO_LSGGIO1_Ind9_stVal,		&iedModel_GGIO_LSGGIO1_Ind10_stVal,
		&iedModel_GGIO_LSGGIO1_Ind11_stVal,		&iedModel_GGIO_LSGGIO1_Ind12_stVal,
		&iedModel_GGIO_LSGGIO1_Ind13_stVal,		&iedModel_GGIO_LSGGIO1_Ind14_stVal,
		&iedModel_GGIO_LSGGIO1_Ind15_stVal,		&iedModel_GGIO_LSGGIO1_Ind16_stVal
};
/*******************************************************
 *******************************************************/
int	Set_LSGGIO	(uint16_t QTnum, uint64_t currentTime )
{
uint8_t	i;
int	ret = false;
// Качество и время меняем по надобности ---------------------------------------
	bool		Q;
	bool		T;
	uint16_t	num;
	num = QTnum & 0b0000111111111111;						// номер элемента
	if (QTnum & QUALITY_mask) Q = true; else Q = false;		// менять ли качество
	if (QTnum & TIME_mask) T = true; else T = false;		// менять ли время
	if(num > MB_MaxNumbLS)	return ret;
// -----------------------------------------------------------------------------
	uint32_t	Health = STVALINT32_OK;
	uint32_t	Mod = STVALINT32_ON;
	Quality 	quality;


	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_Beh_t, currentTime);
	}
//Health
	if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {Health = STVALINT32_Warning;}
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Health_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_Health_t, currentTime);
	}

//quality
	quality = QUALITY_VALIDITY_GOOD;
	if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

	// прогнали по всем
	for (i = 0; i < MB_MaxNumbLS; i++) {
		if (num == 0 || num == i+1){
			if ( IedServer_updateBooleanAttributeValue(iedServer, iedModel_GGIO_LSGGIO_Ind_stVal[i],  ucMDiscInBuf[LSBuf[i][0]] & LSBuf[i][1]) > 0)
				{
					if (T) IedServer_updateUTCTimeAttributeValue(iedServer, iedModel_GGIO_LSGGIO_Ind_t[i], currentTime);
					ret = true;
				}

			if (Q) if (IedServer_updateQuality(iedServer, iedModel_GGIO_LSGGIO_Ind_q[i],quality)) {
				if (T) IedServer_updateUTCTimeAttributeValue(iedServer, iedModel_GGIO_LSGGIO_Ind_t[i], currentTime);
				ret = true;
			}
		}
	}

return ret;
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
 * заглушки
 *******************************************************/
#if defined	(MR771)
int		Set_AVRGGIO		(uint16_t QTnum, uint64_t currentTime ){return false;}
#endif
#if defined	(MR771) || defined	(MR801)
int		Set_NBLKGGIO	(uint16_t QTnum, uint64_t currentTime ){return false;}
#endif
int		Set_FLSGGIO		(uint16_t QTnum, uint64_t currentTime ){return false;}


/*******************************************************
 * Set_VZGGIO наполняем оперативными данными
 *******************************************************/
uint16_t VZBufCFG[MB_MaxNumbVZ] ={
		MB_offset_Ext_1,
		MB_offset_Ext_2,
		MB_offset_Ext_3,
		MB_offset_Ext_4,
		MB_offset_Ext_5,
		MB_offset_Ext_6,
		MB_offset_Ext_7,
		MB_offset_Ext_8,
		MB_offset_Ext_9,
		MB_offset_Ext_10,
		MB_offset_Ext_11,
		MB_offset_Ext_12,
		MB_offset_Ext_13,
		MB_offset_Ext_14,
		MB_offset_Ext_15,
		MB_offset_Ext_16
};

uint16_t VZBuf[MB_MaxNumbVZ][2] ={
		MB_offset_SRAB_ext_1,	MB_b_SRAB_ext_1,
		MB_offset_SRAB_ext_2,	MB_b_SRAB_ext_2,
		MB_offset_SRAB_ext_3,	MB_b_SRAB_ext_3,
		MB_offset_SRAB_ext_4,	MB_b_SRAB_ext_4,
		MB_offset_SRAB_ext_5,	MB_b_SRAB_ext_5,
		MB_offset_SRAB_ext_6,	MB_b_SRAB_ext_6,
		MB_offset_SRAB_ext_7,	MB_b_SRAB_ext_7,
		MB_offset_SRAB_ext_8,	MB_b_SRAB_ext_8,
		MB_offset_SRAB_ext_9,	MB_b_SRAB_ext_9,
		MB_offset_SRAB_ext_10,	MB_b_SRAB_ext_10,
		MB_offset_SRAB_ext_11,	MB_b_SRAB_ext_11,
		MB_offset_SRAB_ext_12,	MB_b_SRAB_ext_12,
		MB_offset_SRAB_ext_13,	MB_b_SRAB_ext_13,
		MB_offset_SRAB_ext_14,	MB_b_SRAB_ext_14,
		MB_offset_SRAB_ext_15,	MB_b_SRAB_ext_15,
		MB_offset_SRAB_ext_16,	MB_b_SRAB_ext_16
};
DataAttribute* iedModel_GGIO_VZGGIO_Ind_q[MB_MaxNumbVZ] = {
		&iedModel_PROT_VZGGIO1_Alm_q,	&iedModel_PROT_VZGGIO2_Alm_q,
		&iedModel_PROT_VZGGIO3_Alm_q,	&iedModel_PROT_VZGGIO4_Alm_q,
		&iedModel_PROT_VZGGIO5_Alm_q,	&iedModel_PROT_VZGGIO6_Alm_q,
		&iedModel_PROT_VZGGIO7_Alm_q,	&iedModel_PROT_VZGGIO8_Alm_q,
		&iedModel_PROT_VZGGIO9_Alm_q,	&iedModel_PROT_VZGGIO10_Alm_q,
		&iedModel_PROT_VZGGIO11_Alm_q,	&iedModel_PROT_VZGGIO12_Alm_q,
		&iedModel_PROT_VZGGIO13_Alm_q,	&iedModel_PROT_VZGGIO14_Alm_q,
		&iedModel_PROT_VZGGIO15_Alm_q,	&iedModel_PROT_VZGGIO16_Alm_q
};
DataAttribute* iedModel_GGIO_VZGGIO_Ind_t[MB_MaxNumbVZ] = {
		&iedModel_PROT_VZGGIO1_Alm_t,	&iedModel_PROT_VZGGIO2_Alm_t,
		&iedModel_PROT_VZGGIO3_Alm_t,	&iedModel_PROT_VZGGIO4_Alm_t,
		&iedModel_PROT_VZGGIO5_Alm_t,	&iedModel_PROT_VZGGIO6_Alm_t,
		&iedModel_PROT_VZGGIO7_Alm_t,	&iedModel_PROT_VZGGIO8_Alm_t,
		&iedModel_PROT_VZGGIO9_Alm_t,	&iedModel_PROT_VZGGIO10_Alm_t,
		&iedModel_PROT_VZGGIO11_Alm_t,	&iedModel_PROT_VZGGIO12_Alm_t,
		&iedModel_PROT_VZGGIO13_Alm_t,	&iedModel_PROT_VZGGIO14_Alm_t,
		&iedModel_PROT_VZGGIO15_Alm_t,	&iedModel_PROT_VZGGIO16_Alm_t
};
DataAttribute* iedModel_GGIO_VZGGIO_Ind_stVal[MB_MaxNumbVZ] = {
		&iedModel_PROT_VZGGIO1_Alm_stVal,	&iedModel_PROT_VZGGIO2_Alm_stVal,
		&iedModel_PROT_VZGGIO3_Alm_stVal,	&iedModel_PROT_VZGGIO4_Alm_stVal,
		&iedModel_PROT_VZGGIO5_Alm_stVal,	&iedModel_PROT_VZGGIO6_Alm_stVal,
		&iedModel_PROT_VZGGIO7_Alm_stVal,	&iedModel_PROT_VZGGIO8_Alm_stVal,
		&iedModel_PROT_VZGGIO9_Alm_stVal,	&iedModel_PROT_VZGGIO10_Alm_stVal,
		&iedModel_PROT_VZGGIO11_Alm_stVal,	&iedModel_PROT_VZGGIO12_Alm_stVal,
		&iedModel_PROT_VZGGIO13_Alm_stVal,	&iedModel_PROT_VZGGIO14_Alm_stVal,
		&iedModel_PROT_VZGGIO15_Alm_stVal,	&iedModel_PROT_VZGGIO16_Alm_stVal
};
int	Set_VZGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	int	ret = false;
// Качество и время меняем по надобности ---------------------------------------
	Quality		quality;
	bool		Q;
	bool		T;
	uint16_t	num;
	num = QTnum & 0b0000111111111111;						// номер элемента
	if (QTnum & QUALITY_mask) Q = true; else Q = false;		// менять ли качество
	if (QTnum & TIME_mask) T = true; else T = false;		// менять ли время
	if(num > MB_MaxNumbVZ)	return ret;
// -----------------------------------------------------------------------------

uint32_t	Mod;


	quality = QUALITY_VALIDITY_GOOD;
	if (ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}


	// прогнали по всем
	int	i;
	for (i = 0; i < MB_MaxNumbVZ; i++) {
		if (num == 0 || num == i+1){

			if (Q) if (IedServer_updateQuality(iedServer, iedModel_GGIO_VZGGIO_Ind_q[i],quality)) ret = true;

			bool value = ucMDiscInBuf[VZBuf[i][0]] & VZBuf[i][1];
			// если нужна метка времени, то сначала меняется время а потом данные, иначе в отчет идёт старое время
			if (T) {ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, iedModel_GGIO_VZGGIO_Ind_stVal[i],iedModel_GGIO_VZGGIO_Ind_t[i],currentTime,  value);}
			// если время не нужно (для гусов) то меняем только данные
			else   {ret |= IedServer_updateBooleanAttributeValue(iedServer, iedModel_GGIO_VZGGIO_Ind_stVal[i],  value);}

		}
	}

//  Mod Beh
	if (num == 0 || num == 1){
			if (ucMUstavkiInBuf[MB_offset_Ext_1 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO1_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO1_Beh_t, currentTime);
			}
			//Health
			uint32_t	Health = STVALINT32_OK;
			if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {Health = STVALINT32_Warning;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Health_stVal, Health)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO1_Health_t, currentTime);
			}

			/*
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_1] & MB_b_SRAB_ext_1))		// СРАБ >1
				{
				ret = true;
				if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Alm_t, currentTime);
				}
			*/
			if (Q){
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Mod_q,quality)) 	ret = true;
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Beh_q,quality)) 	ret = true;
				//if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Health_q,quality)) ret = true;
			}
			//if (Q) IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Alm_q,0);
	}
	if (num == 0 || num == 2){
			if (ucMUstavkiInBuf[MB_offset_Ext_2 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO2_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO2_Beh_t, currentTime);
			}
			//Health
			uint32_t	Health = STVALINT32_OK;
			if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {Health = STVALINT32_Warning;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Health_stVal, Health)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO2_Health_t, currentTime);
			}
			/*
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_2] & MB_b_SRAB_ext_2))		// СРАБ
				{
				ret = true;
				if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Alm_t, currentTime);
				}
			*/
			if (Q){
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Mod_q,quality)) ret = true;
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Beh_q,quality)) ret = true;
				//if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Health_q,quality)) ret = true;
			}
			//if (Q) IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Alm_q,0);
	}
	if (num == 0 || num == 3){
			if (ucMUstavkiInBuf[MB_offset_Ext_3 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO3_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO3_Beh_t, currentTime);
			}
			//Health
			uint32_t	Health = STVALINT32_OK;
			if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {Health = STVALINT32_Warning;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Health_stVal, Health)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO3_Health_t, currentTime);
			}
			/*
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_3] & MB_b_SRAB_ext_3))		// СРАБ
				{
				ret = true;
				if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Alm_t, currentTime);
				}
			*/
			if (Q){
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Mod_q,quality)) ret = true;
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Beh_q,quality)) ret = true;
				//if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Health_q,quality)) ret = true;
			}
			//if (Q) IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Alm_q,0);
	}
	if (num == 0 || num == 4){
			if (ucMUstavkiInBuf[MB_offset_Ext_4 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO4_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO4_Beh_t, currentTime);
			}
			//Health
			uint32_t	Health = STVALINT32_OK;
			if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {Health = STVALINT32_Warning;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Health_stVal, Health)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO4_Health_t, currentTime);
			}
			/*
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_4] & MB_b_SRAB_ext_4))		// СРАБ
				{
				ret = true;
				if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Alm_t, currentTime);
				}
			*/
			if (Q){
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Mod_q,quality)) ret = true;
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Beh_q,quality)) ret = true;
				//if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Health_q,quality)) ret = true;
			}
			//if (Q) IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Alm_q,0);
	}
	if (num == 0 || num == 5){
			if (ucMUstavkiInBuf[MB_offset_Ext_5 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO5_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO5_Beh_t, currentTime);
			}
			//Health
			uint32_t	Health = STVALINT32_OK;
			if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {Health = STVALINT32_Warning;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Health_stVal, Health)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO5_Health_t, currentTime);
			}
			/*
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_5] & MB_b_SRAB_ext_5))		// СРАБ
				{
				ret = true;
				if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Alm_t, currentTime);
				}
			*/
			if (Q){
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Mod_q,quality)) ret = true;
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Beh_q,quality)) ret = true;
				//if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Health_q,quality)) ret = true;
			}
			//if (Q) IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Alm_q,0);
	}
	if (num == 0 || num == 6){
			if (ucMUstavkiInBuf[MB_offset_Ext_6 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO6_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO6_Beh_t, currentTime);
			}
			//Health
			uint32_t	Health = STVALINT32_OK;
			if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {Health = STVALINT32_Warning;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Health_stVal, Health)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO6_Health_t, currentTime);
			}
			/*
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_6] & MB_b_SRAB_ext_6))		// СРАБ
				{
				ret = true;
				if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Alm_t, currentTime);
				}
			*/
			if (Q){
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Mod_q,quality)) ret = true;
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Beh_q,quality)) ret = true;
				//if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Health_q,quality)) ret = true;
			}
			//if (Q) IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Alm_q,0);
	}
	if (num == 0 || num == 7){
			if (ucMUstavkiInBuf[MB_offset_Ext_7 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO7_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO7_Beh_t, currentTime);
			}
			//Health
			uint32_t	Health = STVALINT32_OK;
			if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {Health = STVALINT32_Warning;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Health_stVal, Health)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO7_Health_t, currentTime);
			}
			/*
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_7] & MB_b_SRAB_ext_7))		// СРАБ
				{
				ret = true;
				if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Alm_t, currentTime);
				}
			*/
			if (Q){
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Mod_q,quality)) ret = true;
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Beh_q,quality)) ret = true;
				//if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Health_q,quality)) ret = true;
			}
			//if (Q) IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Alm_q,0);
	}
	if (num == 0 || num == 8){
			if (ucMUstavkiInBuf[MB_offset_Ext_8 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO8_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO8_Beh_t, currentTime);
			}
			//Health
			uint32_t	Health = STVALINT32_OK;
			if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {Health = STVALINT32_Warning;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Health_stVal, Health)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO8_Health_t, currentTime);
			}
			/*
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_8] & MB_b_SRAB_ext_8))		// СРАБ
				{
				ret = true;
				if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Alm_t, currentTime);
				}
			*/
			if (Q){
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Mod_q,quality)) ret = true;
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Beh_q,quality)) ret = true;
				//if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Health_q,quality)) ret = true;
			}
			//if (Q) IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Alm_q,0);
	}
	if (num == 0 || num == 9){
			if (ucMUstavkiInBuf[MB_offset_Ext_9 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO9_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO9_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO9_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO9_Beh_t, currentTime);
			}
			//Health
			uint32_t	Health = STVALINT32_OK;
			if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {Health = STVALINT32_Warning;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO9_Health_stVal, Health)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO9_Health_t, currentTime);
			}
			/*
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO9_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_9] & MB_b_SRAB_ext_9))		// СРАБ
				{
				ret = true;
				if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO9_Alm_t, currentTime);
				}
			*/
			if (Q){
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO9_Mod_q,quality)) ret = true;
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO9_Beh_q,quality)) ret = true;
				//if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO9_Health_q,quality)) ret = true;
			}
			//if (Q) IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO9_Alm_q,0);
	}
	if (num == 0 || num == 10){
			if (ucMUstavkiInBuf[MB_offset_Ext_10 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO10_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO10_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO10_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO10_Beh_t, currentTime);
			}
			//Health
			uint32_t	Health = STVALINT32_OK;
			if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {Health = STVALINT32_Warning;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO10_Health_stVal, Health)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO10_Health_t, currentTime);
			}

			/*
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO10_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_10] & MB_b_SRAB_ext_10))		// СРАБ
				{
				ret = true;
				if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO10_Alm_t, currentTime);
				}
			*/
			if (Q){
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO10_Mod_q,quality)) ret = true;
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO10_Beh_q,quality)) ret = true;
				//if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO10_Health_q,quality)) ret = true;
			}
			//if (Q) IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO10_Alm_q,0);
	}
	if (num == 0 || num == 11){
			if (ucMUstavkiInBuf[MB_offset_Ext_11 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO11_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO11_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO11_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO11_Beh_t, currentTime);
			}
			//Health
			uint32_t	Health = STVALINT32_OK;
			if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {Health = STVALINT32_Warning;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO11_Health_stVal, Health)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO11_Health_t, currentTime);
			}
			/*
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO11_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_11] & MB_b_SRAB_ext_11))		// СРАБ
				{
				ret = true;
				if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO11_Alm_t, currentTime);
				}
			*/
			if (Q){
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO11_Mod_q,quality)) ret = true;
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO11_Beh_q,quality)) ret = true;
				//if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO11_Health_q,quality)) ret = true;
			}
			//if (Q) IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO11_Alm_q,0);
	}
	if (num == 0 || num == 12){
			if (ucMUstavkiInBuf[MB_offset_Ext_12 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO12_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO12_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO12_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO12_Beh_t, currentTime);
			}
			//Health
			uint32_t	Health = STVALINT32_OK;
			if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {Health = STVALINT32_Warning;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO12_Health_stVal, Health)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO12_Health_t, currentTime);
			}
			/*
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO12_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_12] & MB_b_SRAB_ext_12))		// СРАБ
				{
				ret = true;
				if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO12_Alm_t, currentTime);
				}
			*/
			if (Q){
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO12_Mod_q,quality)) ret = true;
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO12_Beh_q,quality)) ret = true;
				//if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO12_Health_q,quality)) ret = true;
			}
			//if (Q) IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO12_Alm_q,0);
	}
	if (num == 0 || num == 13){
			if (ucMUstavkiInBuf[MB_offset_Ext_13 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO13_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO13_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO13_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO13_Beh_t, currentTime);
			}
			//Health
			uint32_t	Health = STVALINT32_OK;
			if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {Health = STVALINT32_Warning;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO13_Health_stVal, Health)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO13_Health_t, currentTime);
			}
			/*
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO13_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_13] & MB_b_SRAB_ext_13))		// СРАБ
				{
				ret = true;
				if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO13_Alm_t, currentTime);
				}
			*/
			if (Q){
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO13_Mod_q,quality)) ret = true;
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO13_Beh_q,quality)) ret = true;
				//if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO13_Health_q,quality)) ret = true;
			}
			//if (Q) IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO13_Alm_q,0);
	}
	if (num == 0 || num == 14){
			if (ucMUstavkiInBuf[MB_offset_Ext_14 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO14_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO14_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO14_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO14_Beh_t, currentTime);
			}
			//Health
			uint32_t	Health = STVALINT32_OK;
			if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {Health = STVALINT32_Warning;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO14_Health_stVal, Health)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO14_Health_t, currentTime);
			}
			/*
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO14_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_14] & MB_b_SRAB_ext_14))		// СРАБ
				{
				ret = true;
				if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO14_Alm_t, currentTime);
				}
			*/
			if (Q){
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO14_Mod_q,quality)) ret = true;
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO14_Beh_q,quality)) ret = true;
				//if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO14_Health_q,quality)) ret = true;
			}
//			if (Q) IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO14_Alm_q,0);
	}
	if (num == 0 || num == 15){
			if (ucMUstavkiInBuf[MB_offset_Ext_15 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO15_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO15_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO15_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO15_Beh_t, currentTime);
			}
			//Health
			uint32_t	Health = STVALINT32_OK;
			if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {Health = STVALINT32_Warning;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO15_Health_stVal, Health)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO15_Health_t, currentTime);
			}
/*
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO15_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_15] & MB_b_SRAB_ext_15))		// СРАБ
				{
				ret = true;
				if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO15_Alm_t, currentTime);
				}
*/

			if (Q){
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO15_Mod_q,quality)) ret = true;
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO15_Beh_q,quality)) ret = true;
				//if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO15_Health_q,quality)) ret = true;
			}
//			if (Q) IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO15_Alm_q,0);
	}
	if (num == 0 || num == 16){
			if (ucMUstavkiInBuf[MB_offset_Ext_16 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO16_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO16_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO16_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO16_Beh_t, currentTime);
			}
			//Health
			uint32_t	Health = STVALINT32_OK;
			if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {Health = STVALINT32_Warning;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO16_Health_stVal, Health)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO16_Health_t, currentTime);
			}
/*
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO16_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_16] & MB_b_SRAB_ext_16))		// СРАБ
				{
				ret = true;
				if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO16_Alm_t, currentTime);
				}
*/
			if (Q){
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO16_Mod_q,quality)) ret = true;
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO16_Beh_q,quality)) ret = true;
				//if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO16_Health_q,quality)) ret = true;
			}
//			if (Q) IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO16_Alm_q,0);
	}

	return ret;
}
/*******************************************************
 * Set_AVRGGIO наполняем оперативными данными
 *******************************************************/
#if defined	(MR761) || defined	(MR762) || defined	(MR763) || defined	(MR801)
int	Set_AVRGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	int	ret = false;

	uint64_t 	diskreet;
	uint32_t 	BLKAVR,BLKAVR1;
	uint32_t	Mod;
	uint32_t	Health;

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
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_AVRGGIO_Mod_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_AVRGGIO_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_AVRGGIO_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_AVRGGIO_Beh_t, currentTime);
		}
//Health
Health = STVALINT32_OK;
		if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {Health = STVALINT32_Warning;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_AVRGGIO_Health_stVal, Health)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_AVRGGIO_Health_t, currentTime);
		}

	//  Quality (Mod Beh)
		int	Qual = QUALITY_VALIDITY_GOOD;
		if (ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

		IedServer_updateQuality(iedServer,&iedModel_PROT_AVRGGIO_Mod_q,Qual);
		IedServer_updateQuality(iedServer,&iedModel_PROT_AVRGGIO_Beh_q,Qual);

		uint8_t	awr=0;
			if(ucMDiscInBuf[MB_offset_AWR] & MB_b_ON_AWR)  awr = 1;
			if(ucMDiscInBuf[MB_offset_AWR] & MB_b_OFF_AWR) awr = 2;
			if(ucMDiscInBuf[MB_offset_AWR] & MB_b_Blok_AWR) awr = 3;

		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_AVRGGIO_IntIn_stVal, awr)){
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_AVRGGIO_IntIn_t, currentTime);
			ret = true;
		}
		IedServer_updateQuality(iedServer,&iedModel_PROT_AVRGGIO_IntIn_q,Qual);
return ret;
}
#endif

#if defined	(MR761) || defined	(MR762) || defined	(MR763)
int	Set_NBLKGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	uint64_t diskreet;
	uint32_t BLKAVR,BLKAVR1;
	uint32_t	Mod = STVALINT32_OFF;


	//  Mod Beh

		if (ucMUstavkiInBuf[MB_offset_BlkNStartMot + MB_offset_BlkNStartMot_Hot] >0) {Mod = STVALINT32_ON;}
		if (ucMUstavkiInBuf[MB_offset_BlkNStartMot + MB_offset_BlkNStartMot_Cold] >0) {Mod = STVALINT32_ON;}

		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_NBLKGGIO1_Mod_stVal, Mod)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_NBLKGGIO1_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_NBLKGGIO1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_NBLKGGIO1_Beh_t, currentTime);
		}

		//Health
		uint32_t	Health = STVALINT32_OK;
		if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {Health = STVALINT32_Warning;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_NBLKGGIO1_Health_stVal, Health)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_NBLKGGIO1_Health_t, currentTime);
		}

	//  Quality (Mod Beh)
		int	Qual = QUALITY_VALIDITY_GOOD;
		if (ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
		IedServer_updateQuality(iedServer,&iedModel_PROT_NBLKGGIO1_Mod_q,Qual);
		IedServer_updateQuality(iedServer,&iedModel_PROT_NBLKGGIO1_Beh_q,Qual);

		uint8_t	nblk=0;
			if(ucMDiscInBuf[MB_offset_BlkN] & MB_b_BlkN)  nblk = 1;

		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_NBLKGGIO1_IntIn_stVal, nblk)){
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_NBLKGGIO1_IntIn_t, currentTime);
		}
		IedServer_updateQuality(iedServer,&iedModel_PROT_NBLKGGIO1_IntIn_q,Qual);
}
#endif
/*******************************************************
 * Set_XCBRGGIO наполняем оперативными данными
 * повторяет Set_SPCSO
 *******************************************************/
int	Set_XCBRGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	/*
	bool		Val;
	int	ret = false;
// Качество и время меняем по надобности ---------------------------------------
	Quality		quality = QUALITY_VALIDITY_GOOD;
	bool		Q;
	bool		T;
	uint16_t	num;
	num = QTnum & 0b0000111111111111;						// номер элемента
	if (QTnum & QUALITY_mask) Q = true; else Q = false;		// менять ли качество
	if (QTnum & TIME_mask) T = true; else T = false;		// менять ли время
//	if(num > MB_MaxNumbLED)	return;
// -----------------------------------------------------------------------------

	if (num == 0 || num == 1){
		if (ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetError)	 Val = true; else Val = false;
		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_stVal,  Val))
			{
				if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_t, currentTime);
				ret = true;
			}
		if (Q) IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO1_q,0);
	}
	if (num == 0 || num == 2){
		if (ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetSysNote)	 Val = true; else Val = false;
		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_stVal,  Val))
			{
				if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_t, currentTime);
				ret = true;
			}
		if (Q) IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO2_q,0);
	}
	if (num == 0 || num == 3){
		if (ucMDiscInBuf[MB_offset_Jurnals] & MB_bOffsetErrorNote)	 Val = true; else Val = false;
		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_stVal,  Val))
			{
				if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_t, currentTime);
				ret = true;
			}
		if (Q) IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO3_q,0);
	}
	if (
			(ucMDiscInBuf[MB_offsetLED_1g]  & MB_bOffset_LED_1g) ||
			(ucMDiscInBuf[MB_offsetLED_2g]  & MB_bOffset_LED_2g) ||
			(ucMDiscInBuf[MB_offsetLED_3g]  & MB_bOffset_LED_3g) ||
			(ucMDiscInBuf[MB_offsetLED_4g]  & MB_bOffset_LED_4g) ||
			(ucMDiscInBuf[MB_offsetLED_5g]  & MB_bOffset_LED_5g) ||
			(ucMDiscInBuf[MB_offsetLED_6g]  & MB_bOffset_LED_6g) ||
			(ucMDiscInBuf[MB_offsetLED_7g]  & MB_bOffset_LED_7g) ||
			(ucMDiscInBuf[MB_offsetLED_8g]  & MB_bOffset_LED_8g) ||
			(ucMDiscInBuf[MB_offsetLED_9g]  & MB_bOffset_LED_9g) ||
			(ucMDiscInBuf[MB_offsetLED_10g] & MB_bOffset_LED_10g)||
			(ucMDiscInBuf[MB_offsetLED_11g] & MB_bOffset_LED_11g)||
			(ucMDiscInBuf[MB_offsetLED_12g] & MB_bOffset_LED_12g)||
			(ucMDiscInBuf[MB_offsetLED_1r]  & MB_bOffset_LED_1g) ||
			(ucMDiscInBuf[MB_offsetLED_2r]  & MB_bOffset_LED_2g) ||
			(ucMDiscInBuf[MB_offsetLED_3r]  & MB_bOffset_LED_3g) ||
			(ucMDiscInBuf[MB_offsetLED_4r]  & MB_bOffset_LED_4g) ||
			(ucMDiscInBuf[MB_offsetLED_5r]  & MB_bOffset_LED_5g) ||
			(ucMDiscInBuf[MB_offsetLED_6r]  & MB_bOffset_LED_6g) ||
			(ucMDiscInBuf[MB_offsetLED_7r]  & MB_bOffset_LED_7g) ||
			(ucMDiscInBuf[MB_offsetLED_8r]  & MB_bOffset_LED_8g) ||
			(ucMDiscInBuf[MB_offsetLED_9r]  & MB_bOffset_LED_9g) ||
			(ucMDiscInBuf[MB_offsetLED_10r] & MB_bOffset_LED_10g)||
			(ucMDiscInBuf[MB_offsetLED_11r] & MB_bOffset_LED_11g)||
			(ucMDiscInBuf[MB_offsetLED_12r] & MB_bOffset_LED_12g)
			)
	{
		Val = true;
	}else Val = false;

		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_stVal,  Val))
			{
				if (T) IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_t, currentTime);
				ret = true;
			}
		if (Q) IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_q,0);

return	ret;
*/
}

/*******************************************************
 * Set_INGGIO наполняем оперативными данными
 *
 * узел проверен.(Ломан)
 * MR761	-	12.01.2018	 - ок
 *
 *******************************************************/
uint16_t INBuf[MB_MaxNumbDiscreet][2] ={	//42
		MB_offsetDiscreet_1,		MB_bOffset_Discreet_1,
		MB_offsetDiscreet_2,		MB_bOffset_Discreet_2,
		MB_offsetDiscreet_3,		MB_bOffset_Discreet_3,
		MB_offsetDiscreet_4,		MB_bOffset_Discreet_4,
		MB_offsetDiscreet_5,		MB_bOffset_Discreet_5,
		MB_offsetDiscreet_6,		MB_bOffset_Discreet_6,
		MB_offsetDiscreet_7,		MB_bOffset_Discreet_7,
		MB_offsetDiscreet_8,		MB_bOffset_Discreet_8,
		MB_offsetDiscreet_9,		MB_bOffset_Discreet_9,
		MB_offsetDiscreet_10,		MB_bOffset_Discreet_10,
		MB_offsetDiscreet_11,		MB_bOffset_Discreet_11,
		MB_offsetDiscreet_12,		MB_bOffset_Discreet_12,
		MB_offsetDiscreet_13,		MB_bOffset_Discreet_13,
		MB_offsetDiscreet_14,		MB_bOffset_Discreet_14,
		MB_offsetDiscreet_15,		MB_bOffset_Discreet_15,
		MB_offsetDiscreet_16,		MB_bOffset_Discreet_16,
		MB_offsetDiscreet_17,		MB_bOffset_Discreet_17,
		MB_offsetDiscreet_18,		MB_bOffset_Discreet_18,
		MB_offsetDiscreet_19,		MB_bOffset_Discreet_19,
		MB_offsetDiscreet_20,		MB_bOffset_Discreet_20,
		MB_offsetDiscreet_21,		MB_bOffset_Discreet_21,
		MB_offsetDiscreet_22,		MB_bOffset_Discreet_22,
		MB_offsetDiscreet_23,		MB_bOffset_Discreet_23,
		MB_offsetDiscreet_24,		MB_bOffset_Discreet_24,
		MB_offsetDiscreet_25,		MB_bOffset_Discreet_25,
		MB_offsetDiscreet_26,		MB_bOffset_Discreet_26,
		MB_offsetDiscreet_27,		MB_bOffset_Discreet_27,
		MB_offsetDiscreet_28,		MB_bOffset_Discreet_28,
		MB_offsetDiscreet_29,		MB_bOffset_Discreet_29,
		MB_offsetDiscreet_30,		MB_bOffset_Discreet_30,
		MB_offsetDiscreet_31,		MB_bOffset_Discreet_31,
		MB_offsetDiscreet_32,		MB_bOffset_Discreet_32,
		MB_offsetDiscreet_33,		MB_bOffset_Discreet_33,
		MB_offsetDiscreet_34,		MB_bOffset_Discreet_34,
		MB_offsetDiscreet_35,		MB_bOffset_Discreet_35,
		MB_offsetDiscreet_36,		MB_bOffset_Discreet_36,
		MB_offsetDiscreet_37,		MB_bOffset_Discreet_37,
		MB_offsetDiscreet_38,		MB_bOffset_Discreet_38,
		MB_offsetDiscreet_39,		MB_bOffset_Discreet_39,
		MB_offsetDiscreet_40,		MB_bOffset_Discreet_40,
		MB_offsetDiscreet_41,		MB_bOffset_Discreet_41,
		MB_offsetDiscreet_42,		MB_bOffset_Discreet_42,
};
DataAttribute* iedModel_GGIO_INGGIO1_Ind_q[MB_MaxNumbDiscreet] = {
		&iedModel_GGIO_INGGIO1_Ind1_q,
		&iedModel_GGIO_INGGIO1_Ind2_q,
		&iedModel_GGIO_INGGIO1_Ind3_q,
		&iedModel_GGIO_INGGIO1_Ind4_q,
		&iedModel_GGIO_INGGIO1_Ind5_q,
		&iedModel_GGIO_INGGIO1_Ind6_q,
		&iedModel_GGIO_INGGIO1_Ind7_q,
		&iedModel_GGIO_INGGIO1_Ind8_q,
		&iedModel_GGIO_INGGIO1_Ind9_q,
		&iedModel_GGIO_INGGIO1_Ind10_q,
		&iedModel_GGIO_INGGIO1_Ind11_q,
		&iedModel_GGIO_INGGIO1_Ind12_q,
		&iedModel_GGIO_INGGIO1_Ind13_q,
		&iedModel_GGIO_INGGIO1_Ind14_q,
		&iedModel_GGIO_INGGIO1_Ind15_q,
		&iedModel_GGIO_INGGIO1_Ind16_q,
		&iedModel_GGIO_INGGIO1_Ind17_q,
		&iedModel_GGIO_INGGIO1_Ind18_q,
		&iedModel_GGIO_INGGIO1_Ind19_q,
		&iedModel_GGIO_INGGIO1_Ind20_q,
		&iedModel_GGIO_INGGIO1_Ind21_q,
		&iedModel_GGIO_INGGIO1_Ind22_q,
		&iedModel_GGIO_INGGIO1_Ind23_q,
		&iedModel_GGIO_INGGIO1_Ind24_q,
		&iedModel_GGIO_INGGIO1_Ind25_q,
		&iedModel_GGIO_INGGIO1_Ind26_q,
		&iedModel_GGIO_INGGIO1_Ind27_q,
		&iedModel_GGIO_INGGIO1_Ind28_q,
		&iedModel_GGIO_INGGIO1_Ind29_q,
		&iedModel_GGIO_INGGIO1_Ind30_q,
		&iedModel_GGIO_INGGIO1_Ind31_q,
		&iedModel_GGIO_INGGIO1_Ind32_q,
		&iedModel_GGIO_INGGIO1_Ind33_q,
		&iedModel_GGIO_INGGIO1_Ind34_q,
		&iedModel_GGIO_INGGIO1_Ind35_q,
		&iedModel_GGIO_INGGIO1_Ind36_q,
		&iedModel_GGIO_INGGIO1_Ind37_q,
		&iedModel_GGIO_INGGIO1_Ind38_q,
		&iedModel_GGIO_INGGIO1_Ind39_q,
		&iedModel_GGIO_INGGIO1_Ind40_q,
		&iedModel_GGIO_INGGIO1_Ind41_q,
		&iedModel_GGIO_INGGIO1_Ind42_q
};
DataAttribute* iedModel_GGIO_INGGIO1_Ind_t[MB_MaxNumbDiscreet] = {
		&iedModel_GGIO_INGGIO1_Ind1_t,
		&iedModel_GGIO_INGGIO1_Ind2_t,
		&iedModel_GGIO_INGGIO1_Ind3_t,
		&iedModel_GGIO_INGGIO1_Ind4_t,
		&iedModel_GGIO_INGGIO1_Ind5_t,
		&iedModel_GGIO_INGGIO1_Ind6_t,
		&iedModel_GGIO_INGGIO1_Ind7_t,
		&iedModel_GGIO_INGGIO1_Ind8_t,
		&iedModel_GGIO_INGGIO1_Ind9_t,
		&iedModel_GGIO_INGGIO1_Ind10_t,
		&iedModel_GGIO_INGGIO1_Ind11_t,
		&iedModel_GGIO_INGGIO1_Ind12_t,
		&iedModel_GGIO_INGGIO1_Ind13_t,
		&iedModel_GGIO_INGGIO1_Ind14_t,
		&iedModel_GGIO_INGGIO1_Ind15_t,
		&iedModel_GGIO_INGGIO1_Ind16_t,
		&iedModel_GGIO_INGGIO1_Ind17_t,
		&iedModel_GGIO_INGGIO1_Ind18_t,
		&iedModel_GGIO_INGGIO1_Ind19_t,
		&iedModel_GGIO_INGGIO1_Ind20_t,
		&iedModel_GGIO_INGGIO1_Ind21_t,
		&iedModel_GGIO_INGGIO1_Ind22_t,
		&iedModel_GGIO_INGGIO1_Ind23_t,
		&iedModel_GGIO_INGGIO1_Ind24_t,
		&iedModel_GGIO_INGGIO1_Ind25_t,
		&iedModel_GGIO_INGGIO1_Ind26_t,
		&iedModel_GGIO_INGGIO1_Ind27_t,
		&iedModel_GGIO_INGGIO1_Ind28_t,
		&iedModel_GGIO_INGGIO1_Ind29_t,
		&iedModel_GGIO_INGGIO1_Ind30_t,
		&iedModel_GGIO_INGGIO1_Ind31_t,
		&iedModel_GGIO_INGGIO1_Ind32_t,
		&iedModel_GGIO_INGGIO1_Ind33_t,
		&iedModel_GGIO_INGGIO1_Ind34_t,
		&iedModel_GGIO_INGGIO1_Ind35_t,
		&iedModel_GGIO_INGGIO1_Ind36_t,
		&iedModel_GGIO_INGGIO1_Ind37_t,
		&iedModel_GGIO_INGGIO1_Ind38_t,
		&iedModel_GGIO_INGGIO1_Ind39_t,
		&iedModel_GGIO_INGGIO1_Ind40_t,
		&iedModel_GGIO_INGGIO1_Ind41_t,
		&iedModel_GGIO_INGGIO1_Ind42_t
};
DataAttribute* iedModel_GGIO_INGGIO1_Ind_stVal[MB_MaxNumbDiscreet] = {
		&iedModel_GGIO_INGGIO1_Ind1_stVal,
		&iedModel_GGIO_INGGIO1_Ind2_stVal,
		&iedModel_GGIO_INGGIO1_Ind3_stVal,
		&iedModel_GGIO_INGGIO1_Ind4_stVal,
		&iedModel_GGIO_INGGIO1_Ind5_stVal,
		&iedModel_GGIO_INGGIO1_Ind6_stVal,
		&iedModel_GGIO_INGGIO1_Ind7_stVal,
		&iedModel_GGIO_INGGIO1_Ind8_stVal,
		&iedModel_GGIO_INGGIO1_Ind9_stVal,
		&iedModel_GGIO_INGGIO1_Ind10_stVal,
		&iedModel_GGIO_INGGIO1_Ind11_stVal,
		&iedModel_GGIO_INGGIO1_Ind12_stVal,
		&iedModel_GGIO_INGGIO1_Ind13_stVal,
		&iedModel_GGIO_INGGIO1_Ind14_stVal,
		&iedModel_GGIO_INGGIO1_Ind15_stVal,
		&iedModel_GGIO_INGGIO1_Ind16_stVal,
		&iedModel_GGIO_INGGIO1_Ind17_stVal,
		&iedModel_GGIO_INGGIO1_Ind18_stVal,
		&iedModel_GGIO_INGGIO1_Ind19_stVal,
		&iedModel_GGIO_INGGIO1_Ind20_stVal,
		&iedModel_GGIO_INGGIO1_Ind21_stVal,
		&iedModel_GGIO_INGGIO1_Ind22_stVal,
		&iedModel_GGIO_INGGIO1_Ind23_stVal,
		&iedModel_GGIO_INGGIO1_Ind24_stVal,
		&iedModel_GGIO_INGGIO1_Ind25_stVal,
		&iedModel_GGIO_INGGIO1_Ind26_stVal,
		&iedModel_GGIO_INGGIO1_Ind27_stVal,
		&iedModel_GGIO_INGGIO1_Ind28_stVal,
		&iedModel_GGIO_INGGIO1_Ind29_stVal,
		&iedModel_GGIO_INGGIO1_Ind30_stVal,
		&iedModel_GGIO_INGGIO1_Ind31_stVal,
		&iedModel_GGIO_INGGIO1_Ind32_stVal,
		&iedModel_GGIO_INGGIO1_Ind33_stVal,
		&iedModel_GGIO_INGGIO1_Ind34_stVal,
		&iedModel_GGIO_INGGIO1_Ind35_stVal,
		&iedModel_GGIO_INGGIO1_Ind36_stVal,
		&iedModel_GGIO_INGGIO1_Ind37_stVal,
		&iedModel_GGIO_INGGIO1_Ind38_stVal,
		&iedModel_GGIO_INGGIO1_Ind39_stVal,
		&iedModel_GGIO_INGGIO1_Ind40_stVal,
		&iedModel_GGIO_INGGIO1_Ind41_stVal,
		&iedModel_GGIO_INGGIO1_Ind42_stVal
};
// --------------------------------------------------------------------------
int		Set_INGGIO	(uint16_t QTnum, uint64_t currentTime )
{
uint32_t	Mod = STVALINT32_ON;
uint32_t	Health = STVALINT32_OK;
uint8_t 	i;
int			ret = false;
// Качество и время меняем по надобности ---------------------------------------
	Quality		quality   = QUALITY_VALIDITY_GOOD;
	Quality		qualityM1 = QUALITY_VALIDITY_GOOD;
	Quality		qualityM2 = QUALITY_VALIDITY_GOOD;
	Quality		qualityM3 = QUALITY_VALIDITY_GOOD;
	Quality		qualityM4 = QUALITY_VALIDITY_GOOD;
	bool		Q;
	bool		T;
	uint16_t	num;
	num = QTnum & 0b0000111111111111;						// номер элемента
	if (QTnum & QUALITY_mask) Q = true; else Q = false;		// менять ли качество
	if (QTnum & TIME_mask) T = true; else T = false;		// менять ли время
	if(num > MB_MaxNumbDiscreet)	return ret;
// -----------------------------------------------------------------------------

	//  Mod Beh
	if (
			(ucMDiscInBuf[MB_offset_errorM1] & MB_bOffsetModule1) ||
			(ucMDiscInBuf[MB_offset_errorM2] & MB_bOffsetModule2) ||
			(ucMDiscInBuf[MB_offset_errorM3] & MB_bOffsetModule3) ||
			(ucMDiscInBuf[MB_offset_errorM4] & MB_bOffsetModule4)
		) {Health = STVALINT32_Warning;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Beh_t, currentTime);
	}
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Health_stVal, Health)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Health_t, currentTime);
	}

	if (Q) {
		if (ucMDiscInBuf[MB_offset_errorM1] & MB_bOffsetModule1)		qualityM1 = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
		if (ucMDiscInBuf[MB_offset_errorM2] & MB_bOffsetModule2)		qualityM2 = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
		if (ucMDiscInBuf[MB_offset_errorM3] & MB_bOffsetModule3)		qualityM3 = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
		if (ucMDiscInBuf[MB_offset_errorM4] & MB_bOffsetModule4)		qualityM4 = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;

/*
		if (ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)	{
			qualityM1 = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
			qualityM2 = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
			qualityM3 = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
			qualityM4 = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
		}
*/
	}
	// прогнали по всем
	for (i = 0; i < MB_MaxNumbDiscreet; i++) {
		if ((num == 0) || (num == i+1)){
			// GOOSE отсылается сразу, надо бы проверить весь датасет сначала
			// сказать функции не отсылать пока не разрешу
/*
			if ( IedServer_updateBooleanAttributeValue(iedServer, iedModel_GGIO_INGGIO1_Ind_stVal[i],  ucMDiscInBuf[INBuf[i][0]] & INBuf[i][1]) > 0)
				{
					if (T) IedServer_updateUTCTimeAttributeValue(iedServer, iedModel_GGIO_INGGIO1_Ind_t[i], currentTime);
					ret = true;
				}
*/
			if (Q) {
				if (i>=0 && i<8)  quality = qualityM2; else
				if (i>7  && i<24) quality = qualityM3; else
				if (i>23 && i<40) quality = qualityM4; else
				if (i>39 && i<41) quality = qualityM1;

				if (IedServer_updateQuality(iedServer, iedModel_GGIO_INGGIO1_Ind_q[i],quality))
					ret = true;
			}
			bool	value = ucMDiscInBuf[INBuf[i][0]] & INBuf[i][1];
			// если нужна метка времени, то сначала меняется время а потом данные, иначе в отчет идёт старое время
			if (T) {ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, iedModel_GGIO_INGGIO1_Ind_stVal[i],iedModel_GGIO_INGGIO1_Ind_t[i],currentTime,  value);}
			// если время не нужно (для гусов) то меняем только данные
			else   {ret |= IedServer_updateBooleanAttributeValue(iedServer, iedModel_GGIO_INGGIO1_Ind_stVal[i],  value);}

		}
	}

return	ret;
}
/*******************************************************
 * Set_OUTGGIO наполняем оперативными данными
 *******************************************************/
uint16_t OUTBuf[MB_MaxNumbRelay][2] ={	//42
		MB_offsetRelay_1,		MB_bOffset_Relay_1,
		MB_offsetRelay_2,		MB_bOffset_Relay_2,
		MB_offsetRelay_3,		MB_bOffset_Relay_3,
		MB_offsetRelay_4,		MB_bOffset_Relay_4,
		MB_offsetRelay_5,		MB_bOffset_Relay_5,
		MB_offsetRelay_6,		MB_bOffset_Relay_6,
		MB_offsetRelay_7,		MB_bOffset_Relay_7,
		MB_offsetRelay_8,		MB_bOffset_Relay_8,
		MB_offsetRelay_9,		MB_bOffset_Relay_9,
		MB_offsetRelay_10,		MB_bOffset_Relay_10,
		MB_offsetRelay_11,		MB_bOffset_Relay_11,
		MB_offsetRelay_12,		MB_bOffset_Relay_12,
		MB_offsetRelay_13,		MB_bOffset_Relay_13,
		MB_offsetRelay_14,		MB_bOffset_Relay_14,
		MB_offsetRelay_15,		MB_bOffset_Relay_15,
		MB_offsetRelay_16,		MB_bOffset_Relay_16,
		MB_offsetRelay_17,		MB_bOffset_Relay_17,
		MB_offsetRelay_18,		MB_bOffset_Relay_18,
		MB_offsetRelay_19,		MB_bOffset_Relay_19,
		MB_offsetRelay_20,		MB_bOffset_Relay_20,
		MB_offsetRelay_21,		MB_bOffset_Relay_21,
		MB_offsetRelay_22,		MB_bOffset_Relay_22,
		MB_offsetRelay_23,		MB_bOffset_Relay_23,
		MB_offsetRelay_24,		MB_bOffset_Relay_24,
		MB_offsetRelay_25,		MB_bOffset_Relay_25,
		MB_offsetRelay_26,		MB_bOffset_Relay_26,
		MB_offsetRelay_27,		MB_bOffset_Relay_27,
		MB_offsetRelay_28,		MB_bOffset_Relay_28,
		MB_offsetRelay_29,		MB_bOffset_Relay_29,
		MB_offsetRelay_30,		MB_bOffset_Relay_30,
		MB_offsetRelay_31,		MB_bOffset_Relay_31,
		MB_offsetRelay_32,		MB_bOffset_Relay_32,
		MB_offsetRelay_33,		MB_bOffset_Relay_33,
		MB_offsetRelay_34,		MB_bOffset_Relay_34,
};
DataAttribute* iedModel_GGIO_OUTGGIO1_SPCSO_q[MB_MaxNumbRelay] = {
		&iedModel_GGIO_OUTGGIO1_SPCSO1_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO2_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO3_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO4_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO5_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO6_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO7_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO8_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO9_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO10_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO11_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO12_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO13_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO14_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO15_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO16_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO17_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO18_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO19_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO20_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO21_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO22_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO23_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO24_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO25_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO26_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO27_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO28_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO29_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO30_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO31_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO32_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO33_q,
		&iedModel_GGIO_OUTGGIO1_SPCSO34_q,
};
DataAttribute* iedModel_GGIO_OUTGGIO1_SPCSO_t[MB_MaxNumbRelay] = {
		&iedModel_GGIO_OUTGGIO1_SPCSO1_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO2_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO3_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO4_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO5_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO6_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO7_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO8_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO9_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO10_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO11_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO12_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO13_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO14_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO15_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO16_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO17_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO18_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO19_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO20_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO21_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO22_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO23_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO24_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO25_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO26_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO27_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO28_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO29_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO30_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO31_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO32_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO33_t,
		&iedModel_GGIO_OUTGGIO1_SPCSO34_t,
};
DataAttribute* iedModel_GGIO_OUTGGIO1_SPCSO_stVal[MB_MaxNumbRelay] = {
		&iedModel_GGIO_OUTGGIO1_SPCSO1_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO2_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO3_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO4_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO5_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO6_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO7_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO8_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO9_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO10_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO11_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO12_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO13_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO14_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO15_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO16_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO17_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO18_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO19_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO20_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO21_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO22_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO23_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO24_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO25_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO26_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO27_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO28_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO29_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO30_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO31_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO32_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO33_stVal,
		&iedModel_GGIO_OUTGGIO1_SPCSO34_stVal,
};
int	Set_OUTGGIO	(uint16_t QTnum, uint64_t currentTime )
{

	uint32_t	Mod = STVALINT32_ON;
	uint32_t	Health = STVALINT32_ON;
	uint8_t		i;
	int	ret = false;
// Качество и время меняем по надобности ---------------------------------------
	Quality		quality  = QUALITY_VALIDITY_GOOD;
	Quality		qualityM1 = QUALITY_VALIDITY_GOOD;
	Quality		qualityM2 = QUALITY_VALIDITY_GOOD;
	Quality		qualityM4 = QUALITY_VALIDITY_GOOD;
	bool		Q;
	bool		T;
	uint16_t	num;
	num = QTnum & 0b0000111111111111;						// номер элемента
	if (QTnum & QUALITY_mask) Q = true; else Q = false;		// менять ли качество
	if (QTnum & TIME_mask) T = true; else T = false;		// менять ли время
	if(num > MB_MaxNumbRelay)	return ret;
// -----------------------------------------------------------------------------

	if (
			(ucMDiscInBuf[MB_offset_errorM1] & MB_bOffsetModule1) ||
			(ucMDiscInBuf[MB_offset_errorM2] & MB_bOffsetModule2) ||
			(ucMDiscInBuf[MB_offset_errorM4] & MB_bOffsetModule4)
		) {Health = STVALINT32_Warning;}
	if (ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)	{Health = STVALINT32_Warning;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Health_stVal, Health)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_Health_t, currentTime);
	}


	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_Beh_t, currentTime);
	}


	if (Q) {
		if (ucMDiscInBuf[MB_offset_errorM1] & MB_bOffsetModule1)		qualityM1 = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
		if (ucMDiscInBuf[MB_offset_errorM2] & MB_bOffsetModule2)		qualityM2 = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
		if (ucMDiscInBuf[MB_offset_errorM4] & MB_bOffsetModule4)		qualityM4 = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;

		if (ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)	{
			qualityM1 = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
			qualityM2 = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
			qualityM4 = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
		}


	}

	// ~2K программного кода меньше чем старая реализация
	// прогнали по всем
	for (i = 0; i < MB_MaxNumbRelay; i++) {
		if (num == 0 || num == i+1){
/*
			if ( IedServer_updateBooleanAttributeValue(iedServer, iedModel_GGIO_OUTGGIO1_SPCSO_stVal[i],  ucMDiscInBuf[OUTBuf[i][0]] & OUTBuf[i][1]) > 0)
				{
					if (T) IedServer_updateUTCTimeAttributeValue(iedServer, iedModel_GGIO_OUTGGIO1_SPCSO_t[i], currentTime);
					ret = true;
				}
*/
			if (Q) {
				if (i>=0 && i<10) quality = qualityM1; else
				if (i>9  && i<18) quality = qualityM2; else
				if (i>17 && i<34) quality = qualityM4;
				if (IedServer_updateQuality(iedServer, iedModel_GGIO_OUTGGIO1_SPCSO_q[i],quality)) ret = true;
			}

			// если нужна метка времени, то сначала меняется время а потом данные, иначе в отчет идёт старое время
			if (T) {ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, iedModel_GGIO_OUTGGIO1_SPCSO_stVal[i],iedModel_GGIO_OUTGGIO1_SPCSO_t[i],currentTime,  ucMDiscInBuf[OUTBuf[i][0]] & OUTBuf[i][1]);}
			// если время не нужно (для гусов) то меняем только данные
			else   {ret |= IedServer_updateBooleanAttributeValue(iedServer, iedModel_GGIO_OUTGGIO1_SPCSO_stVal[i],  ucMDiscInBuf[OUTBuf[i][0]] & OUTBuf[i][1]);}

		}
	}
	return	ret;
}

/*******************************************************
 * Set_LEDGGIO наполняем оперативными данными
 *
 * узел проверен.(Ломан)
 * MR761	-	12.01.2018	 - ок
 *
 *******************************************************/
uint16_t LED_G_Buf[MB_MaxNumbLED][2] ={
		MB_offsetLED_1g,		MB_bOffset_LED_1g,
		MB_offsetLED_2g,		MB_bOffset_LED_2g,
		MB_offsetLED_3g,		MB_bOffset_LED_3g,
		MB_offsetLED_4g,		MB_bOffset_LED_4g,
		MB_offsetLED_5g,		MB_bOffset_LED_5g,
		MB_offsetLED_6g,		MB_bOffset_LED_6g,
		MB_offsetLED_7g,		MB_bOffset_LED_7g,
		MB_offsetLED_8g,		MB_bOffset_LED_8g,
		MB_offsetLED_9g,		MB_bOffset_LED_9g,
		MB_offsetLED_10g,		MB_bOffset_LED_10g,
		MB_offsetLED_11g,		MB_bOffset_LED_11g,
		MB_offsetLED_12g,		MB_bOffset_LED_12g,
		MB_offsetLED_13,		MB_bOffset_LED_13,
		MB_offsetLED_14,		MB_bOffset_LED_14,
		MB_offsetLED_15,		MB_bOffset_LED_15,
		MB_offsetLED_16,		MB_bOffset_LED_16
};
uint16_t LED_R_Buf[MB_MaxNumbLED][2] ={
		MB_offsetLED_1r,		MB_bOffset_LED_1r,
		MB_offsetLED_2r,		MB_bOffset_LED_2r,
		MB_offsetLED_3r,		MB_bOffset_LED_3r,
		MB_offsetLED_4r,		MB_bOffset_LED_4r,
		MB_offsetLED_5r,		MB_bOffset_LED_5r,
		MB_offsetLED_6r,		MB_bOffset_LED_6r,
		MB_offsetLED_7r,		MB_bOffset_LED_7r,
		MB_offsetLED_8r,		MB_bOffset_LED_8r,
		MB_offsetLED_9r,		MB_bOffset_LED_9r,
		MB_offsetLED_10r,		MB_bOffset_LED_10r,
		MB_offsetLED_11r,		MB_bOffset_LED_11r,
		MB_offsetLED_12r,		MB_bOffset_LED_12r,
		MB_offsetLED_13,		MB_bOffset_LED_13,
		MB_offsetLED_14,		MB_bOffset_LED_14,
		MB_offsetLED_15,		MB_bOffset_LED_15,
		MB_offsetLED_16,		MB_bOffset_LED_16
};

DataAttribute* iedModel_GGIO_LEDGGIO1_Ind_q[MB_MaxNumbLED] = {
		&iedModel_GGIO_LEDGGIO1_Ind1_q,
		&iedModel_GGIO_LEDGGIO1_Ind2_q,
		&iedModel_GGIO_LEDGGIO1_Ind3_q,
		&iedModel_GGIO_LEDGGIO1_Ind4_q,
		&iedModel_GGIO_LEDGGIO1_Ind5_q,
		&iedModel_GGIO_LEDGGIO1_Ind6_q,
		&iedModel_GGIO_LEDGGIO1_Ind7_q,
		&iedModel_GGIO_LEDGGIO1_Ind8_q,
		&iedModel_GGIO_LEDGGIO1_Ind9_q,
		&iedModel_GGIO_LEDGGIO1_Ind10_q,
		&iedModel_GGIO_LEDGGIO1_Ind11_q,
		&iedModel_GGIO_LEDGGIO1_Ind12_q,
		&iedModel_GGIO_LEDGGIO1_Ind13_q,
		&iedModel_GGIO_LEDGGIO1_Ind14_q,
		&iedModel_GGIO_LEDGGIO1_Ind15_q,
		&iedModel_GGIO_LEDGGIO1_Ind16_q
};
DataAttribute* iedModel_GGIO_LEDGGIO1_Ind_t[MB_MaxNumbLED] = {
		&iedModel_GGIO_LEDGGIO1_Ind1_t,
		&iedModel_GGIO_LEDGGIO1_Ind2_t,
		&iedModel_GGIO_LEDGGIO1_Ind3_t,
		&iedModel_GGIO_LEDGGIO1_Ind4_t,
		&iedModel_GGIO_LEDGGIO1_Ind5_t,
		&iedModel_GGIO_LEDGGIO1_Ind6_t,
		&iedModel_GGIO_LEDGGIO1_Ind7_t,
		&iedModel_GGIO_LEDGGIO1_Ind8_t,
		&iedModel_GGIO_LEDGGIO1_Ind9_t,
		&iedModel_GGIO_LEDGGIO1_Ind10_t,
		&iedModel_GGIO_LEDGGIO1_Ind11_t,
		&iedModel_GGIO_LEDGGIO1_Ind12_t,
		&iedModel_GGIO_LEDGGIO1_Ind13_t,
		&iedModel_GGIO_LEDGGIO1_Ind14_t,
		&iedModel_GGIO_LEDGGIO1_Ind15_t,
		&iedModel_GGIO_LEDGGIO1_Ind16_t
};
DataAttribute* iedModel_GGIO_LEDGGIO1_Ind_stVal[MB_MaxNumbLED] = {
		&iedModel_GGIO_LEDGGIO1_Ind1_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind2_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind3_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind4_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind5_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind6_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind7_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind8_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind9_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind10_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind11_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind12_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind13_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind14_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind15_stVal,
		&iedModel_GGIO_LEDGGIO1_Ind16_stVal
};
int	Set_LEDGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	bool value;
	uint32_t	Mod = STVALINT32_ON;
	uint32_t	Health = STVALINT32_ON;
	uint8_t		i;
	int	ret = false;
// Качество и время меняем по надобности ---------------------------------------
	Quality		quality = QUALITY_VALIDITY_GOOD;
	bool		Q;
	bool		T;
	uint16_t	num;
	num = QTnum & 0b0000111111111111;						// номер элемента
	if (QTnum & QUALITY_mask) Q = true; else Q = false;		// менять ли качество
	if (QTnum & TIME_mask) T = true; else T = false;		// менять ли время
	if(num > MB_MaxNumbLED)	return ret;
// -----------------------------------------------------------------------------

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_Beh_t, currentTime);
	}

	if (ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)	{Health = STVALINT32_Warning;}
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Health_stVal, Health)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_Health_t, currentTime);
	}
	if (Health == STVALINT32_Warning){
		quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
	}

	for (i = 0; i < MB_MaxNumbLED; i++) {
		if (num == 0 || num == i+1){

			if (Q) if (IedServer_updateQuality(iedServer, iedModel_GGIO_LEDGGIO1_Ind_q[i],quality)) ret = true;

			value = ((ucMDiscInBuf[LED_G_Buf[i][0]] & LED_G_Buf[i][1]) || (ucMDiscInBuf[LED_R_Buf[i][0]] & LED_R_Buf[i][1]));
			// если нужна метка времени, то сначала меняется время а потом данные, иначе в отчет идёт старое время
			if (T) {ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, iedModel_GGIO_LEDGGIO1_Ind_stVal[i],iedModel_GGIO_LEDGGIO1_Ind_t[i],currentTime,  value);}
			// если время не нужно (для гусов) то меняем только данные
			else   {ret |= IedServer_updateBooleanAttributeValue(iedServer, iedModel_GGIO_LEDGGIO1_Ind_stVal[i],  value);}

		}
	}
return	ret;
}

/*******************************************************
 * Set_SSLGGIO наполняем оперативными данными
 *******************************************************/
uint16_t SSLBuf[MB_MaxNumbSSL][2] ={
		MB_offsetSSL_1,		MB_bOffset_SSL_1,
		MB_offsetSSL_2,		MB_bOffset_SSL_2,
		MB_offsetSSL_3,		MB_bOffset_SSL_3,
		MB_offsetSSL_4,		MB_bOffset_SSL_4,
		MB_offsetSSL_5,		MB_bOffset_SSL_5,
		MB_offsetSSL_6,		MB_bOffset_SSL_6,
		MB_offsetSSL_7,		MB_bOffset_SSL_7,
		MB_offsetSSL_8,		MB_bOffset_SSL_8,
		MB_offsetSSL_9,		MB_bOffset_SSL_9,
		MB_offsetSSL_10,	MB_bOffset_SSL_10,
		MB_offsetSSL_11,	MB_bOffset_SSL_11,
		MB_offsetSSL_12,	MB_bOffset_SSL_12,
		MB_offsetSSL_13,	MB_bOffset_SSL_13,
		MB_offsetSSL_14,	MB_bOffset_SSL_14,
		MB_offsetSSL_15,	MB_bOffset_SSL_15,
		MB_offsetSSL_16,	MB_bOffset_SSL_16,
		MB_offsetSSL_17,	MB_bOffset_SSL_17,
		MB_offsetSSL_18,	MB_bOffset_SSL_18,
		MB_offsetSSL_19,	MB_bOffset_SSL_19,
		MB_offsetSSL_20,	MB_bOffset_SSL_20,
		MB_offsetSSL_21,	MB_bOffset_SSL_21,
		MB_offsetSSL_22,	MB_bOffset_SSL_22,
		MB_offsetSSL_23,	MB_bOffset_SSL_23,
		MB_offsetSSL_24,	MB_bOffset_SSL_24,
		MB_offsetSSL_25,	MB_bOffset_SSL_25,
		MB_offsetSSL_26,	MB_bOffset_SSL_26,
		MB_offsetSSL_27,	MB_bOffset_SSL_27,
		MB_offsetSSL_28,	MB_bOffset_SSL_28,
		MB_offsetSSL_29,	MB_bOffset_SSL_29,
		MB_offsetSSL_30,	MB_bOffset_SSL_30,
		MB_offsetSSL_31,	MB_bOffset_SSL_31,
		MB_offsetSSL_32,	MB_bOffset_SSL_32
};
DataAttribute* iedModel_GGIO_SSLGGIO_Ind_q[MB_MaxNumbSSL] = {
		&iedModel_GGIO_SSLGGIO1_Ind1_q,		&iedModel_GGIO_SSLGGIO1_Ind2_q,
		&iedModel_GGIO_SSLGGIO1_Ind3_q,		&iedModel_GGIO_SSLGGIO1_Ind4_q,
		&iedModel_GGIO_SSLGGIO1_Ind5_q,		&iedModel_GGIO_SSLGGIO1_Ind6_q,
		&iedModel_GGIO_SSLGGIO1_Ind7_q,		&iedModel_GGIO_SSLGGIO1_Ind8_q,
		&iedModel_GGIO_SSLGGIO1_Ind9_q,		&iedModel_GGIO_SSLGGIO1_Ind10_q,
		&iedModel_GGIO_SSLGGIO1_Ind11_q,		&iedModel_GGIO_SSLGGIO1_Ind12_q,
		&iedModel_GGIO_SSLGGIO1_Ind13_q,		&iedModel_GGIO_SSLGGIO1_Ind14_q,
		&iedModel_GGIO_SSLGGIO1_Ind15_q,		&iedModel_GGIO_SSLGGIO1_Ind16_q,
		&iedModel_GGIO_SSLGGIO1_Ind17_q,		&iedModel_GGIO_SSLGGIO1_Ind18_q,
		&iedModel_GGIO_SSLGGIO1_Ind19_q,		&iedModel_GGIO_SSLGGIO1_Ind20_q,
		&iedModel_GGIO_SSLGGIO1_Ind21_q,		&iedModel_GGIO_SSLGGIO1_Ind22_q,
		&iedModel_GGIO_SSLGGIO1_Ind23_q,		&iedModel_GGIO_SSLGGIO1_Ind24_q,
		&iedModel_GGIO_SSLGGIO1_Ind25_q,		&iedModel_GGIO_SSLGGIO1_Ind26_q,
		&iedModel_GGIO_SSLGGIO1_Ind27_q,		&iedModel_GGIO_SSLGGIO1_Ind28_q,
		&iedModel_GGIO_SSLGGIO1_Ind29_q,		&iedModel_GGIO_SSLGGIO1_Ind30_q,
		&iedModel_GGIO_SSLGGIO1_Ind31_q,		&iedModel_GGIO_SSLGGIO1_Ind32_q,

};
DataAttribute* iedModel_GGIO_SSLGGIO_Ind_t[MB_MaxNumbSSL] = {
		&iedModel_GGIO_SSLGGIO1_Ind1_t,		&iedModel_GGIO_SSLGGIO1_Ind2_t,
		&iedModel_GGIO_SSLGGIO1_Ind3_t,		&iedModel_GGIO_SSLGGIO1_Ind4_t,
		&iedModel_GGIO_SSLGGIO1_Ind5_t,		&iedModel_GGIO_SSLGGIO1_Ind6_t,
		&iedModel_GGIO_SSLGGIO1_Ind7_t,		&iedModel_GGIO_SSLGGIO1_Ind8_t,
		&iedModel_GGIO_SSLGGIO1_Ind9_t,		&iedModel_GGIO_SSLGGIO1_Ind10_t,
		&iedModel_GGIO_SSLGGIO1_Ind11_t,		&iedModel_GGIO_SSLGGIO1_Ind12_t,
		&iedModel_GGIO_SSLGGIO1_Ind13_t,		&iedModel_GGIO_SSLGGIO1_Ind14_t,
		&iedModel_GGIO_SSLGGIO1_Ind15_t,		&iedModel_GGIO_SSLGGIO1_Ind16_t,
		&iedModel_GGIO_SSLGGIO1_Ind17_t,		&iedModel_GGIO_SSLGGIO1_Ind18_t,
		&iedModel_GGIO_SSLGGIO1_Ind19_t,		&iedModel_GGIO_SSLGGIO1_Ind20_t,
		&iedModel_GGIO_SSLGGIO1_Ind21_t,		&iedModel_GGIO_SSLGGIO1_Ind22_t,
		&iedModel_GGIO_SSLGGIO1_Ind23_t,		&iedModel_GGIO_SSLGGIO1_Ind24_t,
		&iedModel_GGIO_SSLGGIO1_Ind25_t,		&iedModel_GGIO_SSLGGIO1_Ind26_t,
		&iedModel_GGIO_SSLGGIO1_Ind27_t,		&iedModel_GGIO_SSLGGIO1_Ind28_t,
		&iedModel_GGIO_SSLGGIO1_Ind29_t,		&iedModel_GGIO_SSLGGIO1_Ind30_t,
		&iedModel_GGIO_SSLGGIO1_Ind31_t,		&iedModel_GGIO_SSLGGIO1_Ind32_t,
};
DataAttribute* iedModel_GGIO_SSLGGIO_Ind_stVal[MB_MaxNumbSSL] = {
		&iedModel_GGIO_SSLGGIO1_Ind1_stVal,		&iedModel_GGIO_SSLGGIO1_Ind2_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind3_stVal,		&iedModel_GGIO_SSLGGIO1_Ind4_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind5_stVal,		&iedModel_GGIO_SSLGGIO1_Ind6_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind7_stVal,		&iedModel_GGIO_SSLGGIO1_Ind8_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind9_stVal,		&iedModel_GGIO_SSLGGIO1_Ind10_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind11_stVal,		&iedModel_GGIO_SSLGGIO1_Ind12_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind13_stVal,		&iedModel_GGIO_SSLGGIO1_Ind14_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind15_stVal,		&iedModel_GGIO_SSLGGIO1_Ind16_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind17_stVal,		&iedModel_GGIO_SSLGGIO1_Ind18_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind19_stVal,		&iedModel_GGIO_SSLGGIO1_Ind20_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind21_stVal,		&iedModel_GGIO_SSLGGIO1_Ind22_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind23_stVal,		&iedModel_GGIO_SSLGGIO1_Ind24_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind25_stVal,		&iedModel_GGIO_SSLGGIO1_Ind26_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind27_stVal,		&iedModel_GGIO_SSLGGIO1_Ind28_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind29_stVal,		&iedModel_GGIO_SSLGGIO1_Ind30_stVal,
		&iedModel_GGIO_SSLGGIO1_Ind31_stVal,		&iedModel_GGIO_SSLGGIO1_Ind32_stVal,
};
int	Set_SSLGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	uint8_t	i;
	int	ret = false;
	// Качество и время меняем по надобности ---------------------------------------
		Quality		quality = QUALITY_VALIDITY_GOOD;
		bool		Q;
		bool		T;
		uint16_t	num;
		num = QTnum & 0b0000111111111111;						// номер элемента
		if (QTnum & QUALITY_mask) Q = true; else Q = false;		// менять ли качество
		if (QTnum & TIME_mask) T = true; else T = false;		// менять ли время
		if(num > MB_MaxNumbSSL)	return ret;
	// -----------------------------------------------------------------------------
	uint32_t	Mod 	= STVALINT32_OFF;
	uint32_t	Health 	= STVALINT32_OK;

	if (ucMDiscInBuf[MB_offset_LogicError] & MB_bOffsetALLLogicError) 	{Health  = STVALINT32_Warning;quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
	if (ucMDiscInBuf[MB_offset_LogicMod] & MB_bOffsetLogicMod_ON)		Mod	= STVALINT32_ON;

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Health_stVal, Health))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_Health_t, currentTime);

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_Beh_t, currentTime);
	}

	// прогнали по всем
	for (i = 0; i < MB_MaxNumbSSL; i++) {
		if (num == 0 || num == i+1){

			/*
			if ( IedServer_updateBooleanAttributeValue(iedServer, iedModel_GGIO_SSLGGIO_Ind_stVal[i],  ucMDiscInBuf[SSLBuf[i][0]] & SSLBuf[i][1]) > 0)
				{
					if (T) IedServer_updateUTCTimeAttributeValue(iedServer, iedModel_GGIO_SSLGGIO_Ind_t[i], currentTime);
					ret = true;
				}
			*/
			if (Q) if (IedServer_updateQuality(iedServer, iedModel_GGIO_SSLGGIO_Ind_q[i],quality)) ret = true;

			bool value = ucMDiscInBuf[SSLBuf[i][0]] & SSLBuf[i][1];
			// если нужна метка времени, то сначала меняется время а потом данные, иначе в отчет идёт старое время
			if (T) {ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, iedModel_GGIO_SSLGGIO_Ind_stVal[i],iedModel_GGIO_SSLGGIO_Ind_t[i],currentTime,  value);}
			// если время не нужно (для гусов) то меняем только данные
			else   {ret |= IedServer_updateBooleanAttributeValue(iedServer, iedModel_GGIO_SSLGGIO_Ind_stVal[i],  value);}

		}
	}
return ret;
}
/*******************************************************
 * Set_VLSGGIO наполняем оперативными данными
 *******************************************************/
uint16_t VLSBuf[MB_MaxNumbVLS][2] ={
		MB_offsetVLS_1,		MB_bOffset_VLS_1,
		MB_offsetVLS_2,		MB_bOffset_VLS_2,
		MB_offsetVLS_3,		MB_bOffset_VLS_3,
		MB_offsetVLS_4,		MB_bOffset_VLS_4,
		MB_offsetVLS_5,		MB_bOffset_VLS_5,
		MB_offsetVLS_6,		MB_bOffset_VLS_6,
		MB_offsetVLS_7,		MB_bOffset_VLS_7,
		MB_offsetVLS_8,		MB_bOffset_VLS_8,
		MB_offsetVLS_9,		MB_bOffset_VLS_9,
		MB_offsetVLS_10,	MB_bOffset_VLS_10,
		MB_offsetVLS_11,	MB_bOffset_VLS_11,
		MB_offsetVLS_12,	MB_bOffset_VLS_12,
		MB_offsetVLS_13,	MB_bOffset_VLS_13,
		MB_offsetVLS_14,	MB_bOffset_VLS_14,
		MB_offsetVLS_15,	MB_bOffset_VLS_15,
		MB_offsetVLS_16,	MB_bOffset_VLS_16
};
DataAttribute* iedModel_GGIO_VLSGGIO_Ind_q[MB_MaxNumbVLS] = {
		&iedModel_GGIO_VLSGGIO1_Ind1_q,		&iedModel_GGIO_VLSGGIO1_Ind2_q,
		&iedModel_GGIO_VLSGGIO1_Ind3_q,		&iedModel_GGIO_VLSGGIO1_Ind4_q,
		&iedModel_GGIO_VLSGGIO1_Ind5_q,		&iedModel_GGIO_VLSGGIO1_Ind6_q,
		&iedModel_GGIO_VLSGGIO1_Ind7_q,		&iedModel_GGIO_VLSGGIO1_Ind8_q,
		&iedModel_GGIO_VLSGGIO1_Ind9_q,		&iedModel_GGIO_VLSGGIO1_Ind10_q,
		&iedModel_GGIO_VLSGGIO1_Ind11_q,	&iedModel_GGIO_VLSGGIO1_Ind12_q,
		&iedModel_GGIO_VLSGGIO1_Ind13_q,	&iedModel_GGIO_VLSGGIO1_Ind14_q,
		&iedModel_GGIO_VLSGGIO1_Ind15_q,	&iedModel_GGIO_VLSGGIO1_Ind16_q

};
DataAttribute* iedModel_GGIO_VLSGGIO_Ind_t[MB_MaxNumbVLS] = {
		&iedModel_GGIO_VLSGGIO1_Ind1_t,		&iedModel_GGIO_VLSGGIO1_Ind2_t,
		&iedModel_GGIO_VLSGGIO1_Ind3_t,		&iedModel_GGIO_VLSGGIO1_Ind4_t,
		&iedModel_GGIO_VLSGGIO1_Ind5_t,		&iedModel_GGIO_VLSGGIO1_Ind6_t,
		&iedModel_GGIO_VLSGGIO1_Ind7_t,		&iedModel_GGIO_VLSGGIO1_Ind8_t,
		&iedModel_GGIO_VLSGGIO1_Ind9_t,		&iedModel_GGIO_VLSGGIO1_Ind10_t,
		&iedModel_GGIO_VLSGGIO1_Ind11_t,	&iedModel_GGIO_VLSGGIO1_Ind12_t,
		&iedModel_GGIO_VLSGGIO1_Ind13_t,	&iedModel_GGIO_VLSGGIO1_Ind14_t,
		&iedModel_GGIO_VLSGGIO1_Ind15_t,	&iedModel_GGIO_VLSGGIO1_Ind16_t
};
DataAttribute* iedModel_GGIO_VLSGGIO_Ind_stVal[MB_MaxNumbVLS] = {
		&iedModel_GGIO_VLSGGIO1_Ind1_stVal,		&iedModel_GGIO_VLSGGIO1_Ind2_stVal,
		&iedModel_GGIO_VLSGGIO1_Ind3_stVal,		&iedModel_GGIO_VLSGGIO1_Ind4_stVal,
		&iedModel_GGIO_VLSGGIO1_Ind5_stVal,		&iedModel_GGIO_VLSGGIO1_Ind6_stVal,
		&iedModel_GGIO_VLSGGIO1_Ind7_stVal,		&iedModel_GGIO_VLSGGIO1_Ind8_stVal,
		&iedModel_GGIO_VLSGGIO1_Ind9_stVal,		&iedModel_GGIO_VLSGGIO1_Ind10_stVal,
		&iedModel_GGIO_VLSGGIO1_Ind11_stVal,	&iedModel_GGIO_VLSGGIO1_Ind12_stVal,
		&iedModel_GGIO_VLSGGIO1_Ind13_stVal,	&iedModel_GGIO_VLSGGIO1_Ind14_stVal,
		&iedModel_GGIO_VLSGGIO1_Ind15_stVal,	&iedModel_GGIO_VLSGGIO1_Ind16_stVal
};
int	Set_VLSGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	uint32_t	Mod = STVALINT32_ON;
	uint32_t	Health = STVALINT32_ON;

	int		ret = false;
	// Качество и время меняем по надобности ---------------------------------------
		Quality		quality = QUALITY_VALIDITY_GOOD;
		bool		Q;
		bool		T;
		uint16_t	num;
		num = QTnum & 0b0000111111111111;						// номер элемента
		if (QTnum & QUALITY_mask) Q = true; else Q = false;		// менять ли качество
		if (QTnum & TIME_mask) T = true; else T = false;		// менять ли время
		if(num > MB_MaxNumbVLS)	return ret;
	// -----------------------------------------------------------------------------

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_Beh_t, currentTime);
	}

	if (ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)	{Health = STVALINT32_Warning;}
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Health_stVal, Health)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_Health_t, currentTime);
	}
	if (Health == STVALINT32_Warning){
		quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
	}

	// прогнали по всем
	int	i;
	for (i = 0; i < MB_MaxNumbVLS; i++) {
		if (num == 0 || num == i+1){

			if (Q) if (IedServer_updateQuality(iedServer, iedModel_GGIO_VLSGGIO_Ind_q[i],quality)) ret = true;

			bool value = ucMDiscInBuf[VLSBuf[i][0]] & VLSBuf[i][1];
			// если нужна метка времени, то сначала меняется время а потом данные, иначе в отчет идёт старое время
			if (T) {ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, iedModel_GGIO_VLSGGIO_Ind_stVal[i],iedModel_GGIO_VLSGGIO_Ind_t[i],currentTime,  value);}
			// если время не нужно (для гусов) то меняем только данные
			else   {ret |= IedServer_updateBooleanAttributeValue(iedServer, iedModel_GGIO_VLSGGIO_Ind_stVal[i],  value);}

		}
	}
return ret;
}
/*******************************************************
 * Set_LSGGIO наполняем оперативными данными
 *******************************************************/
uint16_t LSBuf[MB_MaxNumbLS][2] ={
		MB_offsetLS_1,	MB_bOffset_LS_1,
		MB_offsetLS_2,	MB_bOffset_LS_2,
		MB_offsetLS_3,	MB_bOffset_LS_3,
		MB_offsetLS_4,	MB_bOffset_LS_4,
		MB_offsetLS_5,	MB_bOffset_LS_5,
		MB_offsetLS_6,	MB_bOffset_LS_6,
		MB_offsetLS_7,	MB_bOffset_LS_7,
		MB_offsetLS_8,	MB_bOffset_LS_8,
		MB_offsetLS_9,	MB_bOffset_LS_9,
		MB_offsetLS_10,	MB_bOffset_LS_10,
		MB_offsetLS_11,	MB_bOffset_LS_11,
		MB_offsetLS_12,	MB_bOffset_LS_12,
		MB_offsetLS_13,	MB_bOffset_LS_13,
		MB_offsetLS_14,	MB_bOffset_LS_14,
		MB_offsetLS_15,	MB_bOffset_LS_15,
		MB_offsetLS_16,	MB_bOffset_LS_16
};
DataAttribute* iedModel_GGIO_LSGGIO_Ind_q[MB_MaxNumbLS] = {
		&iedModel_GGIO_LSGGIO1_Ind1_q,	&iedModel_GGIO_LSGGIO1_Ind2_q,
		&iedModel_GGIO_LSGGIO1_Ind3_q,	&iedModel_GGIO_LSGGIO1_Ind4_q,
		&iedModel_GGIO_LSGGIO1_Ind5_q,	&iedModel_GGIO_LSGGIO1_Ind6_q,
		&iedModel_GGIO_LSGGIO1_Ind7_q,	&iedModel_GGIO_LSGGIO1_Ind8_q,
		&iedModel_GGIO_LSGGIO1_Ind9_q,	&iedModel_GGIO_LSGGIO1_Ind10_q,
		&iedModel_GGIO_LSGGIO1_Ind11_q,	&iedModel_GGIO_LSGGIO1_Ind12_q,
		&iedModel_GGIO_LSGGIO1_Ind13_q,	&iedModel_GGIO_LSGGIO1_Ind14_q,
		&iedModel_GGIO_LSGGIO1_Ind15_q,	&iedModel_GGIO_LSGGIO1_Ind16_q

};
DataAttribute* iedModel_GGIO_LSGGIO_Ind_t[MB_MaxNumbLS] = {
		&iedModel_GGIO_LSGGIO1_Ind1_t,	&iedModel_GGIO_LSGGIO1_Ind2_t,
		&iedModel_GGIO_LSGGIO1_Ind3_t,	&iedModel_GGIO_LSGGIO1_Ind4_t,
		&iedModel_GGIO_LSGGIO1_Ind5_t,	&iedModel_GGIO_LSGGIO1_Ind6_t,
		&iedModel_GGIO_LSGGIO1_Ind7_t,	&iedModel_GGIO_LSGGIO1_Ind8_t,
		&iedModel_GGIO_LSGGIO1_Ind9_t,	&iedModel_GGIO_LSGGIO1_Ind10_t,
		&iedModel_GGIO_LSGGIO1_Ind11_t,	&iedModel_GGIO_LSGGIO1_Ind12_t,
		&iedModel_GGIO_LSGGIO1_Ind13_t,	&iedModel_GGIO_LSGGIO1_Ind14_t,
		&iedModel_GGIO_LSGGIO1_Ind15_t,	&iedModel_GGIO_LSGGIO1_Ind16_t
};
DataAttribute* iedModel_GGIO_LSGGIO_Ind_stVal[MB_MaxNumbLS] = {
		&iedModel_GGIO_LSGGIO1_Ind1_stVal,	&iedModel_GGIO_LSGGIO1_Ind2_stVal,
		&iedModel_GGIO_LSGGIO1_Ind3_stVal,	&iedModel_GGIO_LSGGIO1_Ind4_stVal,
		&iedModel_GGIO_LSGGIO1_Ind5_stVal,	&iedModel_GGIO_LSGGIO1_Ind6_stVal,
		&iedModel_GGIO_LSGGIO1_Ind7_stVal,	&iedModel_GGIO_LSGGIO1_Ind8_stVal,
		&iedModel_GGIO_LSGGIO1_Ind9_stVal,	&iedModel_GGIO_LSGGIO1_Ind10_stVal,
		&iedModel_GGIO_LSGGIO1_Ind11_stVal,	&iedModel_GGIO_LSGGIO1_Ind12_stVal,
		&iedModel_GGIO_LSGGIO1_Ind13_stVal,	&iedModel_GGIO_LSGGIO1_Ind14_stVal,
		&iedModel_GGIO_LSGGIO1_Ind15_stVal,	&iedModel_GGIO_LSGGIO1_Ind16_stVal
};
int	Set_LSGGIO	(uint16_t QTnum, uint64_t currentTime )
{

	uint32_t	Mod = STVALINT32_ON;
	uint32_t	Health = STVALINT32_ON;

	int	ret = false;
	// Качество и время меняем по надобности ---------------------------------------
		Quality		quality = QUALITY_VALIDITY_GOOD;
		bool		Q;
		bool		T;
		uint16_t	num;
		num = QTnum & 0b0000111111111111;						// номер элемента
		if (QTnum & QUALITY_mask) Q = true; else Q = false;		// менять ли качество
		if (QTnum & TIME_mask) T = true; else T = false;		// менять ли время
		if(num > MB_MaxNumbLS)	return ret;
	// -----------------------------------------------------------------------------

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_Beh_t, currentTime);
	}

	if (ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)	{Health = STVALINT32_Warning;}
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Health_stVal, Health)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_Health_t, currentTime);
	}
	if (Health == STVALINT32_Warning){
		quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
	}

	// прогнали по всем
	int	i;
	for (i = 0; i < MB_MaxNumbLS; i++) {
		if (num == 0 || num == i+1){

			if (Q) if (IedServer_updateQuality(iedServer, iedModel_GGIO_LSGGIO_Ind_q[i],quality)) ret = true;

			bool value = ucMDiscInBuf[LSBuf[i][0]] & LSBuf[i][1];
			// если нужна метка времени, то сначала меняется время а потом данные, иначе в отчет идёт старое время
			if (T) {ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, iedModel_GGIO_LSGGIO_Ind_stVal[i],iedModel_GGIO_LSGGIO_Ind_t[i],currentTime,  value);}
			// если время не нужно (для гусов) то меняем только данные
			else   {ret |= IedServer_updateBooleanAttributeValue(iedServer, iedModel_GGIO_LSGGIO_Ind_stVal[i],  value);}

		}
	}
return ret;
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
 * заглушки
 *******************************************************/
int		Set_AVRGGIO		(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_NBLKGGIO	(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_FLSGGIO		(uint16_t QTnum, uint64_t currentTime ){return false;}

/*******************************************************
 * Set_VZGGIO наполняем оперативными данными
 *******************************************************/
int	Set_VZGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	Quality 	quality;
	uint32_t	Health;

				Health = STVALINT32_OK;
				if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) 					{Health = STVALINT32_Warning;}

				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Health_stVal, Health)){

					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Health_stVal, Health);
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Health_stVal, Health);
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Health_stVal, Health);
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Health_stVal, Health);
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Health_stVal, Health);
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Health_stVal, Health);
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Health_stVal, Health);
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO9_Health_stVal, Health);
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO10_Health_stVal, Health);
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO11_Health_stVal, Health);
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO12_Health_stVal, Health);
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO13_Health_stVal, Health);
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO14_Health_stVal, Health);
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO15_Health_stVal, Health);
					IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO16_Health_stVal, Health);

					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO1_Health_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO2_Health_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO3_Health_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO4_Health_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO5_Health_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO6_Health_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO7_Health_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO8_Health_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO9_Health_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO10_Health_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO11_Health_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO12_Health_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO13_Health_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO14_Health_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO15_Health_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO16_Health_t, currentTime);
				}

	//  Mod Beh
				uint32_t	Mod;
				if (ucMUstavkiInBuf[MB_offset_Ext_1 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO1_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO1_Beh_t, currentTime);
				}

				if (ucMUstavkiInBuf[MB_offset_Ext_2 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO2_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO2_Beh_t, currentTime);
				}

				if (ucMUstavkiInBuf[MB_offset_Ext_3 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO3_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO3_Beh_t, currentTime);
				}

				if (ucMUstavkiInBuf[MB_offset_Ext_4 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO4_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO4_Beh_t, currentTime);
				}

				if (ucMUstavkiInBuf[MB_offset_Ext_5 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO5_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO5_Beh_t, currentTime);
				}

				if (ucMUstavkiInBuf[MB_offset_Ext_6 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO6_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO6_Beh_t, currentTime);
				}

				if (ucMUstavkiInBuf[MB_offset_Ext_7 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO7_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO7_Beh_t, currentTime);
				}

				if (ucMUstavkiInBuf[MB_offset_Ext_8 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO8_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO8_Beh_t, currentTime);
				}

				if (ucMUstavkiInBuf[MB_offset_Ext_9 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO9_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO9_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO9_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO9_Beh_t, currentTime);
				}

				if (ucMUstavkiInBuf[MB_offset_Ext_10 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO10_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO10_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO10_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO10_Beh_t, currentTime);
				}

				if (ucMUstavkiInBuf[MB_offset_Ext_11 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO11_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO11_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO11_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO11_Beh_t, currentTime);
				}

				if (ucMUstavkiInBuf[MB_offset_Ext_12 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO12_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO12_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO12_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO12_Beh_t, currentTime);
				}


				if (ucMUstavkiInBuf[MB_offset_Ext_13 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO13_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO13_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO13_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO13_Beh_t, currentTime);
				}


				if (ucMUstavkiInBuf[MB_offset_Ext_14 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO14_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO14_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO14_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO14_Beh_t, currentTime);
				}


				if (ucMUstavkiInBuf[MB_offset_Ext_15 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO15_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO15_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO15_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO15_Beh_t, currentTime);
				}


				if (ucMUstavkiInBuf[MB_offset_Ext_16 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO16_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO16_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO16_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO16_Beh_t, currentTime);
				}

	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Mod_q,Qual)){
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO9_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO9_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO10_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO10_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO11_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO11_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO12_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO12_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO13_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO13_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO14_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO14_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO15_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO15_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO16_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO16_Beh_q,Qual);
				}

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_1] & MB_b_SRAB_ext_1))		// СРАБ >1
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Alm_t, currentTime);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_2] & MB_b_SRAB_ext_2))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Alm_t, currentTime);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_3] & MB_b_SRAB_ext_3))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Alm_t, currentTime);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_4] & MB_b_SRAB_ext_4))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Alm_t, currentTime);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_5] & MB_b_SRAB_ext_5))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Alm_t, currentTime);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_6] & MB_b_SRAB_ext_6))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Alm_t, currentTime);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_7] & MB_b_SRAB_ext_7))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Alm_t, currentTime);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_8] & MB_b_SRAB_ext_8))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Alm_t, currentTime);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO9_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_9] & MB_b_SRAB_ext_9))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO9_Alm_t, currentTime);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO10_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_10] & MB_b_SRAB_ext_10))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO10_Alm_t, currentTime);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO11_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_11] & MB_b_SRAB_ext_11))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO11_Alm_t, currentTime);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO12_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_12] & MB_b_SRAB_ext_12))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO12_Alm_t, currentTime);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO13_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_13] & MB_b_SRAB_ext_13))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO13_Alm_t, currentTime);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO14_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_14] & MB_b_SRAB_ext_14))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO14_Alm_t, currentTime);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO15_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_15] & MB_b_SRAB_ext_15))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO15_Alm_t, currentTime);

				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO16_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_16] & MB_b_SRAB_ext_16))		// СРАБ
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO16_Alm_t, currentTime);


				quality = QUALITY_VALIDITY_GOOD;
				if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Alm_q,quality)){
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Alm_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Alm_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Alm_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Alm_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Alm_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Alm_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Alm_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO9_Alm_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO10_Alm_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO11_Alm_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO12_Alm_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO13_Alm_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO14_Alm_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO15_Alm_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO16_Alm_q,quality);

				}

}

/*******************************************************
 * Set_XCBRGGIO наполняем оперативными данными
 *******************************************************/
int	Set_XCBRGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	//--------------------------------
	// сброс флагов
/*
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
*/
}

/*******************************************************
 * Set_INGGIO наполняем оперативными данными
 *******************************************************/
int	Set_INGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	int	ret = false;
	uint32_t	Mod = STVALINT32_ON;
	uint32_t	Health	= STVALINT32_OK;
	Quality quality;

	if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule2) {Health = STVALINT32_Warning;}
	if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule3) {Health = STVALINT32_Warning;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Health_stVal, Health)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Health_t, currentTime);
	}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Beh_stVal, Mod))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Beh_t, currentTime);
	}

	quality = QUALITY_VALIDITY_GOOD;
	if (ucMDiscInBuf[MB_offset_errorM2] & MB_bOffsetModule2){quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
		if (IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind1_q,quality)){
			IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind2_q,quality);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind3_q,quality);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind4_q,quality);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind5_q,quality);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind6_q,quality);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind7_q,quality);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind8_q,quality);

			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind1_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind2_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind3_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind4_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind5_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind6_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind7_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind8_t, currentTime);
		}

	quality = QUALITY_VALIDITY_GOOD;
	if (ucMDiscInBuf[MB_offset_errorM3] & MB_bOffsetModule3){quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

		if (IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind9_q,quality)){
			IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind10_q,quality);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind11_q,quality);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind12_q,quality);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind13_q,quality);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind14_q,quality);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind15_q,quality);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind16_q,quality);

			IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind17_q,quality);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind18_q,quality);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind19_q,quality);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind20_q,quality);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind21_q,quality);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind22_q,quality);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind23_q,quality);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind24_q,quality);

			 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind9_t, currentTime);
			 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind10_t, currentTime);
			 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind11_t, currentTime);
			 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind12_t, currentTime);
			 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind13_t, currentTime);
			 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind14_t, currentTime);
			 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind15_t, currentTime);
			 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind16_t, currentTime);

			 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind17_t, currentTime);
			 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind18_t, currentTime);
			 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind19_t, currentTime);
			 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind20_t, currentTime);
			 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind21_t, currentTime);
			 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind22_t, currentTime);
			 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind23_t, currentTime);
			 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind24_t, currentTime);

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
// ----------
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

return ret;
}

/*******************************************************
 * Set_OUTGGIO наполняем оперативными данными
 *******************************************************/
int	Set_OUTGGIO	(uint16_t QTnum, uint64_t currentTime )
{

	int		ret = false;
	uint32_t	Mod 	= STVALINT32_ON;
	uint32_t	Health	= STVALINT32_OK;
	Quality quality;

	if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule1)>0) 		{Health = STVALINT32_Warning;}
	if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule2)>0) 		{Health = STVALINT32_Warning;}
	if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)>0)	{Health = STVALINT32_Warning;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Health_stVal, Health)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_Health_t, currentTime);
	}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_Beh_t, currentTime);
	}


	quality = QUALITY_VALIDITY_GOOD;
	if (ucMDiscInBuf[MB_offset_errorM1] & MB_bOffsetModule1)			{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
	if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

		if (IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_q,quality)){
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_q,quality);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_q,quality);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_q,quality);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_q,quality);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_q,quality);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_q,quality);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_q,quality);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_q,quality);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_q,quality);

			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_t, currentTime);

		}

	quality = QUALITY_VALIDITY_GOOD;
	if (ucMDiscInBuf[MB_offset_errorM2] & MB_bOffsetModule2)			{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
	if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

		if (IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_q,quality)){
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_q,quality);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_q,quality);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_q,quality);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO15_q,quality);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO16_q,quality);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO17_q,quality);
			IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO18_q,quality);

			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO15_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO16_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO17_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO18_t, currentTime);

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

return ret;
}

/*******************************************************
 * Set_LEDGGIO наполняем оперативными данными
 *******************************************************/
int	Set_LEDGGIO	(uint16_t QTnum, uint64_t currentTime )
{

	uint32_t	Mod = STVALINT32_ON;
	Quality 	quality;
	uint32_t	Health;

//Health
	Health = STVALINT32_OK;
	if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) 		{Health = STVALINT32_Warning;}

	if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Health_stVal, Health))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_Health_t, currentTime);


	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Beh_stVal, Mod))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_Beh_t, currentTime);
	}


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


	quality = QUALITY_VALIDITY_GOOD;
	if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

	if (IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_q,quality)){
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_q,quality);

		//IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind13_q,quality);
		//IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind14_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind15_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind16_q,quality);

		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind15_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind16_t, currentTime);

	}

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
int	Set_SSLGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	int	ret = false;
	Quality		quality = QUALITY_VALIDITY_GOOD;
	uint32_t	Mod 	= STVALINT32_OFF;
	uint32_t	Health 	= STVALINT32_OK;

	if (ucMDiscInBuf[MB_offset_LogicError] & MB_bOffsetALLLogicError)   {Health  = STVALINT32_Warning;quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
	if (ucMDiscInBuf[MB_offset_LogicError1] & MB_bOffsetALLLogicError1) {Health  = STVALINT32_Warning;quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

	if (ucMDiscInBuf[MB_offset_LogicMod] & MB_bOffsetLogicMod_ON)		Mod	= STVALINT32_ON;

#if defined (MR901) && (_REVISION_DEVICE<=206)		//2.06		ошибка в приборе. не верно выставляет этот флаг
	Mod	= STVALINT32_ON;
#endif

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Health_stVal, Health))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_Health_t, currentTime);

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_Beh_t, currentTime);
	}


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


	if (IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind1_q,quality)){
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind2_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind3_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind4_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind5_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind6_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind7_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind8_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind9_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind10_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind11_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind12_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind13_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind14_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind15_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind16_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind17_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind18_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind19_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind20_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind21_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind22_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind23_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind24_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind25_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind26_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind27_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind28_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind29_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind30_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind31_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind32_q,quality);

		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind1_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind2_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind3_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind4_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind5_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind6_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind7_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind8_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind9_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind10_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind11_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind12_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind13_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind14_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind15_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind16_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind17_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind18_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind19_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind20_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind21_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind22_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind23_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind24_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind25_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind26_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind27_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind28_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind29_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind30_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind31_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind32_t, currentTime);
	}
return ret;
}

/*******************************************************
 * Set_VLSGGIO наполняем оперативными данными
 *******************************************************/
int	Set_VLSGGIO	(uint16_t QTnum, uint64_t currentTime )
{

	uint32_t	Mod = STVALINT32_ON;
	uint32_t	Health = STVALINT32_OK;
	Quality quality;

//Health
	Health = STVALINT32_OK;
	if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) 		{Health = STVALINT32_Warning;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Health_stVal, Health))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_Health_t, currentTime);


	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Beh_stVal, Mod))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_Beh_t, currentTime);
	}

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


	quality = QUALITY_VALIDITY_GOOD;
	if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) 		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

	if (IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind1_q,quality)){
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind2_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind3_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind4_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind5_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind6_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind7_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind8_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind9_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind10_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind11_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind12_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind13_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind14_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind15_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind16_q,quality);

		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind1_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind2_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind3_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind4_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind5_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind6_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind7_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind8_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind9_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind10_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind11_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind12_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind13_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind14_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind15_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Ind16_t, currentTime);

	}
}

/*******************************************************
 * Set_LSGGIO наполняем оперативными данными
 *******************************************************/
int	Set_LSGGIO	(uint16_t QTnum, uint64_t currentTime )
{

	uint32_t	Mod = STVALINT32_ON;
	uint32_t	Health;
	Quality 	quality;

//Health
	Health = STVALINT32_OK;
	if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) 		{Health = STVALINT32_Warning;}

	if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Health_stVal, Health))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_Health_t, currentTime);


	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Beh_stVal, Mod))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_Beh_t, currentTime);
	}

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


	quality = QUALITY_VALIDITY_GOOD;
	if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

	if (IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind1_q,quality)){
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind2_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind3_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind4_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind5_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind6_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind7_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind8_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind9_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind10_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind11_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind12_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind13_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind14_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind15_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind16_q,quality);

		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind1_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind2_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind3_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind4_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind5_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind6_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind7_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind8_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind9_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind10_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind11_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind12_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind13_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind14_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind15_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Ind16_t, currentTime);
	}
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
 * заглушки
 *******************************************************/
int		Set_VZGGIO		(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_AVRGGIO		(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_SSLGGIO		(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_VLSGGIO		(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_LSGGIO		(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_NBLKGGIO	(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_FLSGGIO		(uint16_t QTnum, uint64_t currentTime ){return false;}

/*******************************************************
 * Set_XCBRGGIO наполняем оперативными данными
 *******************************************************/
int	Set_XCBRGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	//--------------------------------
	// сброс флагов
/*
		if (ucMDiscInBuf[MB_offset_ErrorSDTU] & MB_bOffsetErrorSDTU){
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

*/
}

/*******************************************************
 * Set_INGGIO наполняем оперативными данными
 *******************************************************/
int	Set_INGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	//  Mod Beh

	uint32_t	Mod = STVALINT32_ON;
	uint32_t 	Health = STVALINT32_OK;
	Quality quality;

	//Health
		if ((ucMDiscInBuf[MB_offsetError_M3] & MB_bOffsetErrModule3)) 		{Health = STVALINT32_Warning;}

		if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Health_stVal, Health))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Health_t, currentTime);


	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Beh_stVal, Mod))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Beh_t, currentTime);
	}
	quality = QUALITY_VALIDITY_GOOD;
	if (ucMDiscInBuf[MB_offsetError_M3] & MB_bOffsetErrModule3a)	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
	if (IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind1_q,quality)){
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind2_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind3_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind4_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind5_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind6_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind7_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind8_q,quality);

		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind1_t, currentTime);
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind2_t, currentTime);
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind3_t, currentTime);
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind4_t, currentTime);
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind5_t, currentTime);
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind6_t, currentTime);
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind7_t, currentTime);
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind8_t, currentTime);
	}

	quality = QUALITY_VALIDITY_GOOD;
	if (ucMDiscInBuf[MB_offsetError_M3] & MB_bOffsetErrModule3b){quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

	if (IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind9_q,quality)){
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind10_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind11_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind12_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind13_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind14_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind15_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_INGGIO1_Ind16_q,quality);

		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind9_t, currentTime);
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind10_t, currentTime);
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind11_t, currentTime);
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind12_t, currentTime);
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind13_t, currentTime);
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind14_t, currentTime);
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind15_t, currentTime);
		 IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Ind16_t, currentTime);
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
// -----
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
int	Set_OUTGGIO	(uint16_t QTnum, uint64_t currentTime )
{

	uint32_t	Mod = STVALINT32_ON;
	uint32_t	Health = STVALINT32_OK;
	Quality quality;

	if 	((ucMDiscInBuf[MB_offset_errorM2] & MB_bOffsetErrModule2)>0)  {Health = STVALINT32_Warning;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_Beh_t, currentTime);
	}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Health_stVal, Health)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_Health_t, currentTime);
	}

	quality = QUALITY_VALIDITY_GOOD;
	if (ucMDiscInBuf[MB_offset_errorM2] & MB_bOffsetErrModule2){quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
	if (IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_q,quality)){
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_q,quality);

		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_t, currentTime);

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
}

/*******************************************************
 * Set_LEDGGIO наполняем оперативными данными
 *******************************************************/
int	Set_LEDGGIO	(uint16_t QTnum, uint64_t currentTime )
{

	uint32_t	Mod = STVALINT32_ON;

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Beh_stVal, Mod))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_Beh_t, currentTime);
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


	if (IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_q,0)){
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

}
#endif


/*******************************************************
 * MR5_700
 *******************************************************/
#if defined	(MR5_700) || defined (MR5_500) || defined (MR5_600) ||  defined (MR741)

#if defined	(MR5_500)
#include "static_model_MR5_500.h"
#endif
#if defined	(MR5_600)
#include "static_model_MR5_600.h"
#endif
#if defined	(MR5_700)
#include "static_model_MR5_700.h"
#endif
#if defined	(MR741)
#include "static_model_MR741.h"
#endif

extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucMAutomatBuf[MB_NumbAutomat];
extern uint16_t   ucConfigBufExZ[MB_NumbConfigExZ];


/*******************************************************
 * заглушки
 *******************************************************/
int		Set_NBLKGGIO		(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_FLSGGIO		(uint16_t QTnum, uint64_t currentTime ){return false;}
#if defined	(MR5_600)
int		Set_AVRGGIO		(uint16_t QTnum, uint64_t currentTime ){return false;}
#endif

/*******************************************************
 * Set_VZGGIO наполняем оперативными данными
 *******************************************************/
int	Set_VZGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	int			ret = false;
	uint32_t	Mod = STVALINT32_ON;
	uint32_t	Health = STVALINT32_OK;
	Quality 	quality;

	if 	(ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki)	 	{Health = STVALINT32_Warning;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Health_stVal, Health)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO1_Health_t, currentTime);

		IedServer_updateInt32AttributeValue  (iedServer,&iedModel_PROT_VZGGIO2_Health_stVal, Health);
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO2_Health_t, currentTime);
		IedServer_updateInt32AttributeValue  (iedServer,&iedModel_PROT_VZGGIO3_Health_stVal, Health);
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO3_Health_t, currentTime);
		IedServer_updateInt32AttributeValue  (iedServer,&iedModel_PROT_VZGGIO4_Health_stVal, Health);
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO4_Health_t, currentTime);
		IedServer_updateInt32AttributeValue  (iedServer,&iedModel_PROT_VZGGIO5_Health_stVal, Health);
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO5_Health_t, currentTime);
		IedServer_updateInt32AttributeValue  (iedServer,&iedModel_PROT_VZGGIO6_Health_stVal, Health);
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO6_Health_t, currentTime);
		IedServer_updateInt32AttributeValue  (iedServer,&iedModel_PROT_VZGGIO7_Health_stVal, Health);
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO7_Health_t, currentTime);
		IedServer_updateInt32AttributeValue  (iedServer,&iedModel_PROT_VZGGIO8_Health_stVal, Health);
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO8_Health_t, currentTime);
	}
	//  Mod Beh

		if ((ucConfigBufExZ[MB_offset_Ext_1 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Beh_stVal, Mod))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO1_Beh_t, currentTime);
		}

		if ((ucConfigBufExZ[MB_offset_Ext_2 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO2_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Beh_stVal, Mod))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO2_Beh_t, currentTime);
		}

		if ((ucConfigBufExZ[MB_offset_Ext_3 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO3_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Beh_stVal, Mod))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO3_Beh_t, currentTime);
		}

		if ((ucConfigBufExZ[MB_offset_Ext_4 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO4_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Beh_stVal, Mod))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO4_Beh_t, currentTime);
		}

		if ((ucConfigBufExZ[MB_offset_Ext_5 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO5_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Beh_stVal, Mod))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO5_Beh_t, currentTime);
		}

		if ((ucConfigBufExZ[MB_offset_Ext_6 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO6_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Beh_stVal, Mod))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO6_Beh_t, currentTime);
		}

		if ((ucConfigBufExZ[MB_offset_Ext_7 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO7_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Beh_stVal, Mod))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO7_Beh_t, currentTime);
		}

		if ((ucConfigBufExZ[MB_offset_Ext_8 + MB_offset_Ext_Config] & MB_bOffset_Ext_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO8_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Beh_stVal, Mod))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_VZGGIO8_Beh_t, currentTime);
		}

//  Quality (Mod Beh)
		quality = QUALITY_VALIDITY_GOOD;
		if 	(ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki)	 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

		if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Mod_q,quality)){
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Beh_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Mod_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Beh_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Mod_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Beh_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Mod_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Beh_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Mod_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Beh_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Mod_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Beh_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Mod_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Beh_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Mod_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Beh_q,quality);
		}

//				uint32_t	Alm;

		quality = QUALITY_VALIDITY_GOOD;
		if 	(ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki)	 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
		if (IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO1_Alm_q,quality)){
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO2_Alm_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO3_Alm_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO4_Alm_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO5_Alm_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO6_Alm_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO7_Alm_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_VZGGIO8_Alm_q,quality);

			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Alm_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Alm_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Alm_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Alm_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Alm_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Alm_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Alm_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Alm_t, currentTime);
		}


		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_1] & MB_b_SRAB_ext_1))		// СРАБ >1
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO1_Alm_t, currentTime);

		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_2] & MB_b_SRAB_ext_2))		// СРАБ
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO2_Alm_t, currentTime);

		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_3] & MB_b_SRAB_ext_3))		// СРАБ
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO3_Alm_t, currentTime);

		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_4] & MB_b_SRAB_ext_4))		// СРАБ
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO4_Alm_t, currentTime);

		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_5] & MB_b_SRAB_ext_5))		// СРАБ
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO5_Alm_t, currentTime);

		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_6] & MB_b_SRAB_ext_6))		// СРАБ
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO6_Alm_t, currentTime);

		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_7] & MB_b_SRAB_ext_7))		// СРАБ
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO7_Alm_t, currentTime);

		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Alm_stVal,  ucMDiscInBuf[MB_offset_SRAB_ext_8] & MB_b_SRAB_ext_8))		// СРАБ
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_VZGGIO8_Alm_t, currentTime);

return ret;
}

/*******************************************************
 * Set_AVRGGIO наполняем оперативными данными
 *******************************************************/
#if !defined	(MR5_600)
int	Set_AVRGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	int 		ret = false;
	uint32_t	Mod;
	uint32_t	Health;

//  Mod Beh
				if ((ucMAutomatBuf[MB_offset_ConfAWR] & MB_bOffset_AWR_Config_Stat)>0) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_AVRGGIO_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_AVRGGIO_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_AVRGGIO_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_AVRGGIO_Beh_t, currentTime);
				}
//Health
				Health = STVALINT32_OK;
				if 	(ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki)	 	{Health = STVALINT32_Warning;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_AVRGGIO_Health_stVal, Health)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_AVRGGIO_Health_t, currentTime);
				}
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

				Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				if(IedServer_updateQuality(iedServer,&iedModel_PROT_AVRGGIO_IntIn_q,Qual)){
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_AVRGGIO_IntIn_t, currentTime);
				}
return ret;
}
#endif
/*******************************************************
 * Set_XCBRGGIO наполняем оперативными данными
 *******************************************************/
int	Set_XCBRGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	int ret = false;
/*
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
		if ((ucMDiscInBuf[MB_offset_AllLEDs] & MB_bOffsetLedsStats)>0)
		{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_stVal,  1))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_q,0);

		} else{
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_stVal,  0))
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_t, currentTime);
			IedServer_updateQuality(iedServer, &iedModel_CTRL_GGIO1_SPCSO4_q,0);
		}
*/
return ret;
}
/*******************************************************
 * Set_INGGIO наполняем оперативными данными
 *******************************************************/
int	Set_INGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	uint32_t	Mod = STVALINT32_ON;
	uint32_t	Health;
	int			ret = false;
// Качество и время меняем по надобности ---------------------------------------
	Quality		quality   = QUALITY_VALIDITY_GOOD;
	Quality		qualityM1 = QUALITY_VALIDITY_GOOD;
	Quality		qualityM2 = QUALITY_VALIDITY_GOOD;
	Quality		qualityM3 = QUALITY_VALIDITY_GOOD;
	bool		Q;
	bool		T;
	uint16_t	num;
	num = QTnum & 0b0000111111111111;						// номер элемента
	if (QTnum & QUALITY_mask) Q = true; else Q = false;		// менять ли качество
	if (QTnum & TIME_mask) T = true; else T = false;		// менять ли время
//	if(num > MB_MaxNumbDiscreet)	return ret;
// -----------------------------------------------------------------------------


	Health = STVALINT32_OK;
	if 	(ucMDiscInBuf[MB_offset_errorM3] & MB_bOffsetModule3)	 			{Health = STVALINT32_Warning;}
	IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_GGIO_INGGIO1_Health_stVal,&iedModel_GGIO_INGGIO1_Health_t,currentTime,Health);
	//  Mod Beh
	if(IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_GGIO_INGGIO1_Mod_stVal,&iedModel_GGIO_INGGIO1_Mod_t,currentTime,Mod)){
		IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_GGIO_INGGIO1_Beh_stVal,&iedModel_GGIO_INGGIO1_Beh_t,currentTime,Mod);
	}
/*

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Beh_t, currentTime);
	}
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_INGGIO1_Health_stVal, Health)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_INGGIO1_Health_t, currentTime);
	}
*/
	quality   = QUALITY_VALIDITY_GOOD;
	if (ucMDiscInBuf[MB_offset_errorM3] & MB_bOffsetErrModule3a)		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

	if (IedServer_updateQualityWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind1_q,&iedModel_GGIO_INGGIO1_Ind1_t,currentTime,quality)){
		IedServer_updateQualityWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind2_q,&iedModel_GGIO_INGGIO1_Ind2_t,currentTime,quality);
		IedServer_updateQualityWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind3_q,&iedModel_GGIO_INGGIO1_Ind3_t,currentTime,quality);
		IedServer_updateQualityWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind4_q,&iedModel_GGIO_INGGIO1_Ind4_t,currentTime,quality);
		IedServer_updateQualityWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind5_q,&iedModel_GGIO_INGGIO1_Ind5_t,currentTime,quality);
		IedServer_updateQualityWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind6_q,&iedModel_GGIO_INGGIO1_Ind6_t,currentTime,quality);
		IedServer_updateQualityWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind7_q,&iedModel_GGIO_INGGIO1_Ind7_t,currentTime,quality);
		IedServer_updateQualityWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind8_q,&iedModel_GGIO_INGGIO1_Ind8_t,currentTime,quality);
	}

		ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind1_stVal,&iedModel_GGIO_INGGIO1_Ind1_t,currentTime,  (ucMDiscInBuf[MB_offsetDiscreet_1] & MB_bOffset_Discreet_1) > 0);
		ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind2_stVal,&iedModel_GGIO_INGGIO1_Ind2_t,currentTime,  (ucMDiscInBuf[MB_offsetDiscreet_2] & MB_bOffset_Discreet_2) > 0);
		ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind3_stVal,&iedModel_GGIO_INGGIO1_Ind3_t,currentTime,  (ucMDiscInBuf[MB_offsetDiscreet_3] & MB_bOffset_Discreet_3) > 0);
		ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind4_stVal,&iedModel_GGIO_INGGIO1_Ind4_t,currentTime,  (ucMDiscInBuf[MB_offsetDiscreet_4] & MB_bOffset_Discreet_4) > 0);
		ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind5_stVal,&iedModel_GGIO_INGGIO1_Ind5_t,currentTime,  (ucMDiscInBuf[MB_offsetDiscreet_5] & MB_bOffset_Discreet_5) > 0);
		ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind6_stVal,&iedModel_GGIO_INGGIO1_Ind6_t,currentTime,  (ucMDiscInBuf[MB_offsetDiscreet_6] & MB_bOffset_Discreet_6) > 0);
		ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind7_stVal,&iedModel_GGIO_INGGIO1_Ind7_t,currentTime,  (ucMDiscInBuf[MB_offsetDiscreet_7] & MB_bOffset_Discreet_7) > 0);
		ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind8_stVal,&iedModel_GGIO_INGGIO1_Ind8_t,currentTime,  (ucMDiscInBuf[MB_offsetDiscreet_8] & MB_bOffset_Discreet_8) > 0);

#if !defined	(MR5_600)

	quality   = QUALITY_VALIDITY_GOOD;
	if (ucMDiscInBuf[MB_offset_errorM3] & MB_bOffsetErrModule3b)		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

	if (IedServer_updateQualityWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind9_q,&iedModel_GGIO_INGGIO1_Ind9_t,currentTime,quality)){
		IedServer_updateQualityWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind10_q,&iedModel_GGIO_INGGIO1_Ind10_t,currentTime,quality);
		IedServer_updateQualityWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind11_q,&iedModel_GGIO_INGGIO1_Ind11_t,currentTime,quality);
		IedServer_updateQualityWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind12_q,&iedModel_GGIO_INGGIO1_Ind12_t,currentTime,quality);
		IedServer_updateQualityWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind13_q,&iedModel_GGIO_INGGIO1_Ind13_t,currentTime,quality);
		IedServer_updateQualityWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind14_q,&iedModel_GGIO_INGGIO1_Ind14_t,currentTime,quality);
		IedServer_updateQualityWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind15_q,&iedModel_GGIO_INGGIO1_Ind15_t,currentTime,quality);
		IedServer_updateQualityWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind16_q,&iedModel_GGIO_INGGIO1_Ind16_t,currentTime,quality);

	}
#if defined	(MR741)
	IedServer_updateQualityWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind17_q,&iedModel_GGIO_INGGIO1_Ind17_t,currentTime,quality);
	IedServer_updateQualityWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind18_q,&iedModel_GGIO_INGGIO1_Ind18_t,currentTime,quality);
#endif

	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind9_stVal,&iedModel_GGIO_INGGIO1_Ind9_t,currentTime,  (ucMDiscInBuf[MB_offsetDiscreet_9] & MB_bOffset_Discreet_9) > 0);
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind10_stVal,&iedModel_GGIO_INGGIO1_Ind10_t,currentTime,  (ucMDiscInBuf[MB_offsetDiscreet_10] & MB_bOffset_Discreet_10) > 0);
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind11_stVal,&iedModel_GGIO_INGGIO1_Ind11_t,currentTime,  (ucMDiscInBuf[MB_offsetDiscreet_11] & MB_bOffset_Discreet_11) > 0);
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind12_stVal,&iedModel_GGIO_INGGIO1_Ind12_t,currentTime,  (ucMDiscInBuf[MB_offsetDiscreet_12] & MB_bOffset_Discreet_12) > 0);
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind13_stVal,&iedModel_GGIO_INGGIO1_Ind13_t,currentTime,  (ucMDiscInBuf[MB_offsetDiscreet_13] & MB_bOffset_Discreet_13) > 0);
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind14_stVal,&iedModel_GGIO_INGGIO1_Ind14_t,currentTime,  (ucMDiscInBuf[MB_offsetDiscreet_14] & MB_bOffset_Discreet_14) > 0);
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind15_stVal,&iedModel_GGIO_INGGIO1_Ind15_t,currentTime,  (ucMDiscInBuf[MB_offsetDiscreet_15] & MB_bOffset_Discreet_15) > 0);
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind16_stVal,&iedModel_GGIO_INGGIO1_Ind16_t,currentTime,  (ucMDiscInBuf[MB_offsetDiscreet_16] & MB_bOffset_Discreet_16) > 0);

#if defined	(MR741)
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind17_stVal,&iedModel_GGIO_INGGIO1_Ind17_t,currentTime,  (ucMDiscInBuf[MB_offsetDiscreet_17] & MB_bOffset_Discreet_17) > 0);
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_INGGIO1_Ind18_stVal,&iedModel_GGIO_INGGIO1_Ind18_t,currentTime,  (ucMDiscInBuf[MB_offsetDiscreet_18] & MB_bOffset_Discreet_18) > 0);
#endif

#endif
	return	ret;
}

/*******************************************************
 * Set_OUTGGIO наполняем оперативными данными
 *******************************************************/

int	Set_OUTGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	int 		ret = false;
	uint32_t	Mod = STVALINT32_ON;
	uint32_t	Health = STVALINT32_ON;
	Quality 	quality;

	Health = STVALINT32_ON;
	if (ucMDiscInBuf[MB_offset_errorM2] & MB_bOffsetModule2)		{Health = STVALINT32_Warning;}
	if 	(ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki)	{Health = STVALINT32_Warning;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Health_stVal, Health)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_Health_t, currentTime);
	}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_OUTGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_OUTGGIO1_Beh_t, currentTime);
	}


	quality = QUALITY_VALIDITY_GOOD;
	if (ucMDiscInBuf[MB_offset_errorM2] & MB_bOffsetModule2a)			{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
	if 	(ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki)	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

	if (IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO1_q,quality)){
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO2_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO3_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO4_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO5_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO6_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO7_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO8_q,quality);
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

#if defined	(MR741)
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

#endif

#if defined	(MR5_600)
	quality = QUALITY_VALIDITY_GOOD;
	if (ucMDiscInBuf[MB_offset_errorM2] & MB_bOffsetModule2b)			{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
	if 	(ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki)	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

	if (IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO9_q,quality)){
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO10_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO11_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO12_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO13_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO14_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO15_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_OUTGGIO1_SPCSO16_q,quality);
	}

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
#endif
	return ret;
}

/*******************************************************
 * Set_LEDGGIO наполняем оперативными данными
 *******************************************************/
int	Set_LEDGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	int 		ret = false;
	uint32_t	Mod = STVALINT32_ON;
	uint32_t	Health = STVALINT32_ON;
	Quality 	quality;

	Health = STVALINT32_ON;
	if 	(ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki)	{Health = STVALINT32_Warning;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Health_stVal, Health)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_Health_t, currentTime);
	}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LEDGGIO1_Beh_t, currentTime);
	}

	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_stVal,&iedModel_GGIO_LEDGGIO1_Ind1_t,currentTime,  (ucMDiscInBuf[MB_offsetLED_1] & MB_bOffset_LED_1) > 0);
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_stVal,&iedModel_GGIO_LEDGGIO1_Ind2_t,currentTime,  (ucMDiscInBuf[MB_offsetLED_2] & MB_bOffset_LED_2) > 0);
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_stVal,&iedModel_GGIO_LEDGGIO1_Ind3_t,currentTime,  (ucMDiscInBuf[MB_offsetLED_3] & MB_bOffset_LED_3) > 0);
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_stVal,&iedModel_GGIO_LEDGGIO1_Ind4_t,currentTime,  (ucMDiscInBuf[MB_offsetLED_4] & MB_bOffset_LED_4) > 0);
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_stVal,&iedModel_GGIO_LEDGGIO1_Ind5_t,currentTime,  (ucMDiscInBuf[MB_offsetLED_5] & MB_bOffset_LED_5) > 0);
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_stVal,&iedModel_GGIO_LEDGGIO1_Ind6_t,currentTime,  (ucMDiscInBuf[MB_offsetLED_6] & MB_bOffset_LED_6) > 0);
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_stVal,&iedModel_GGIO_LEDGGIO1_Ind7_t,currentTime,  (ucMDiscInBuf[MB_offsetLED_7] & MB_bOffset_LED_7) > 0);
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_stVal,&iedModel_GGIO_LEDGGIO1_Ind8_t,currentTime,  (ucMDiscInBuf[MB_offsetLED_8] & MB_bOffset_LED_8) > 0);
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_stVal,&iedModel_GGIO_LEDGGIO1_Ind9_t,currentTime,  (ucMDiscInBuf[MB_offsetLED_9] & MB_bOffset_LED_9) > 0);
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_stVal,&iedModel_GGIO_LEDGGIO1_Ind10_t,currentTime,  (ucMDiscInBuf[MB_offsetLED_10] & MB_bOffset_LED_10) > 0);
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_stVal,&iedModel_GGIO_LEDGGIO1_Ind11_t,currentTime,  (ucMDiscInBuf[MB_offsetLED_11] & MB_bOffset_LED_11) > 0);
	ret |= IedServer_updateBooleanAttributeValueWithTime(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_stVal,&iedModel_GGIO_LEDGGIO1_Ind12_t,currentTime,  (ucMDiscInBuf[MB_offsetLED_12] & MB_bOffset_LED_12) > 0);

	quality = QUALITY_VALIDITY_GOOD;

	if (IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_q,quality)){
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_q,quality);

		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind11_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind12_t, currentTime);

	}

	if 	(ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki)	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

	if (IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_q,quality)){
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_q,quality);

		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind1_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind2_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind3_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind4_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind5_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind6_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind7_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind8_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind9_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_LEDGGIO1_Ind10_t, currentTime);

	}
	return ret;
}
/*******************************************************
 * Set_SSLGGIO наполняем оперативными данными
 *******************************************************/
int	Set_SSLGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	int			ret = false;
	Quality		quality = QUALITY_VALIDITY_GOOD;
	uint32_t	Mod 	= STVALINT32_OFF;
	uint32_t	Health 	= STVALINT32_OK;

	if (ucMDiscInBuf[MB_offset_LogicError] & MB_bOffsetALLLogicError) 	{Health  = STVALINT32_Warning;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Health_stVal, Health))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_Health_t, currentTime);

	if (ucMDiscInBuf[MB_offset_LogicMod] & MB_bOffsetLogicMod_ON)		Mod	= STVALINT32_ON;

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_SSLGGIO1_Beh_t, currentTime);
	}

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

	quality = QUALITY_VALIDITY_GOOD;
	if 	((ucMDiscInBuf[MB_offset_LogicError] & MB_bOffsetALLLogicError)>0)	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

	if (IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind1_q,quality)){
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind2_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind3_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind4_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind5_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind6_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind7_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind8_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind9_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind10_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind11_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind12_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind13_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind14_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind15_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind16_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind17_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind18_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind19_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind20_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind21_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind22_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind23_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_SSLGGIO1_Ind24_q,quality);

		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind1_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind2_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind3_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind4_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind5_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind6_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind7_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind8_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind9_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind10_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind11_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind12_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind13_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind14_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind15_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind16_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind17_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind18_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind19_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind20_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind21_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind22_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind23_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_GGIO_SSLGGIO1_Ind24_t, currentTime);

	}
	return ret;
}

/*******************************************************
 * Set_VLSGGIO наполняем оперативными данными
 *******************************************************/
int	Set_VLSGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	int ret = false;
	uint32_t	Mod = STVALINT32_ON;
	uint32_t	Health = STVALINT32_ON;
	Quality 	quality;

	Health = STVALINT32_ON;
	if 	(ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki)	{Health = STVALINT32_Warning;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Health_stVal, Health)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_Health_t, currentTime);
	}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_VLSGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_VLSGGIO1_Beh_t, currentTime);
	}

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

	quality = QUALITY_VALIDITY_GOOD;
	if 	(ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki)	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

	if (IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind1_q,quality)){
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind2_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind3_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind4_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind5_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind6_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind7_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_VLSGGIO1_Ind8_q,quality);
	}
	return ret;
}
/*******************************************************
 * Set_LSGGIO наполняем оперативными данными
 *******************************************************/
int	Set_LSGGIO	(uint16_t QTnum, uint64_t currentTime )
{
	int ret = false;
	uint32_t	Mod = STVALINT32_ON;
	uint32_t	Health = STVALINT32_ON;
	Quality 	quality;

	Health = STVALINT32_ON;
	if 	(ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki)	{Health = STVALINT32_Warning;}
	if 	(ucMDiscInBuf[MB_offset_errorM3] & MB_bOffsetErrModule3)		{Health = STVALINT32_Warning;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Health_stVal, Health)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_Health_t, currentTime);
	}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_Mod_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_GGIO_LSGGIO1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_GGIO_LSGGIO1_Beh_t, currentTime);
	}

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

	quality = QUALITY_VALIDITY_GOOD;
	if 	(ucMDiscInBuf[MB_offsetError_Ustavki] & MB_bOffsetErrUstavki)	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
	if 	(ucMDiscInBuf[MB_offset_errorM3] & MB_bOffsetErrModule3)		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

	if (IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind1_q,quality)){
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind2_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind3_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind4_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind5_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind6_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind7_q,quality);
		IedServer_updateQuality(iedServer, &iedModel_GGIO_LSGGIO1_Ind8_q,quality);
	}
	return ret;
}

#endif

