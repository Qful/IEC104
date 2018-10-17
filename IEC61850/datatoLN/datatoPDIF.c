/*
 * datatoPDIF.c
 *
 *  Created on: 19.04.2017
 *      Author: sagok
 */




#include "main.h"
#include "IEC850.h"

#include "iec850.h"
#include "iec61850_server.h"

#include "datatoMMXU.h"
#include "dataDbzeroDB.h"

/*******************************************************
 * MR5_500 MR5_600 MR5_700
 *******************************************************/
#if defined (MR5_500) || defined (MR5_600) || defined (MR5_700) || defined (MR741)
#if defined (MR5_700)
#include "static_model_MR5_700.h"
#endif
#if defined (MR5_600)
#include "static_model_MR5_600.h"
#endif
#if defined (MR5_500)
#include "static_model_MR5_500.h"
#endif
#if defined (MR741)
#include "static_model_MR741.h"
#endif
/*******************************************************
 * заглушки
 *******************************************************/
int		Set_IDPDIF		(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_ID0PDIF		(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_IDDPDIF		(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_IDDMPDIF	(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_IDMPDIF		(uint16_t QTnum, uint64_t currentTime ){return false;}

#endif
/*******************************************************
 * MR851
 *******************************************************/
#if defined (MR851)
#include "static_model_MR851.h"

/*******************************************************
 * заглушки
 *******************************************************/
int		Set_IDPDIF		(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_ID0PDIF		(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_IDDPDIF		(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_IDDMPDIF	(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_IDMPDIF		(uint16_t QTnum, uint64_t currentTime ){return false;}

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

int		Set_IDPDIF		(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_ID0PDIF		(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_IDDPDIF		(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_IDDMPDIF	(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_IDMPDIF		(uint16_t QTnum, uint64_t currentTime ){return false;}
#endif

/*******************************************************
 * MR801
 *******************************************************/
#if defined (MR801)
#include "static_model_MR801.h"


extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
extern uint16_t   ucMUstavkiInBuf[MB_NumbUstavki];
extern uint16_t   ucConfigTRPWRBuf[MB_NumbConfigTRPWR];

/*******************************************************
 * заглушки
 *******************************************************/

int		Set_IDMPDIF		(uint16_t QTnum, uint64_t currentTime ){return false;}

/*******************************************************
 * Set_IDPDIF наполняем оперативными данными
 *******************************************************/
int		Set_IDPDIF	(uint16_t QTnum, uint64_t currentTime )
{
	int			ret = false;
	float		diapazon;
	float		mag;
	float		K;
	Quality 	quality;

	//Health
				uint32_t	Health = STVALINT32_OK;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule4) 		{Health = STVALINT32_Warning;}
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5) 		{Health = STVALINT32_Warning;}
				if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {Health = STVALINT32_Warning;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDPDIF_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF_Health_t, currentTime);


	//  Mod Beh
				uint32_t	Mod;
				if (ucMUstavkiInBuf[MB_offset_DIFFZ + MB_offset_DIFFZ_Config_Stat] & MB_bOffset_DIFFZ_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDPDIF_Mod_stVal, Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDPDIF_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF_Beh_t, currentTime);
				}


	//  Quality (Mod Beh)
				quality = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				if (IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF_Mod_q,quality)){
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF_Beh_q,quality);
				}

	// Str_general
				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IDPDIF_Str_general,  ucMDiscInBuf[MB_offset_IO_Diffup_1] & MB_b_IO_Diffup_1))			// И0 >1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IDPDIF_Str_t, currentTime);

	// Op_general
				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IDPDIF_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Diffup_1] & MB_b_SRAB_Diffup_1))		// СРАБ >1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IDPDIF_Op_t, currentTime);

// ----------------------
			K = 1000 * (40 * ucConfigTRPWRBuf[MB_offset_ConfigS1 + MB_offset_P_Obmotki]) / ((float)sqrt3 * 65535 * ucConfigTRPWRBuf[MB_offset_ConfigS1 + MB_offset_U_Obmotki]);
			diapazon = K * 65535;

			mag = ucMAnalogInBuf[MB_offset_Ia_Diff] * K;
			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_PROT_IDPDIF_DifACIc_phsA_db,
					&iedModel_PROT_IDPDIF_DifACIc_phsA_zeroDb,
					&iedModel_PROT_IDPDIF_DifACIc_phsA_instCVal_mag_f,
					&iedModel_PROT_IDPDIF_DifACIc_phsA_cVal_mag_f,
					&iedModel_PROT_IDPDIF_DifACIc_phsA_t,
					currentTime);

			mag = ucMAnalogInBuf[MB_offset_Ib_Diff] * K;
			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_PROT_IDPDIF_DifACIc_phsB_db,
					&iedModel_PROT_IDPDIF_DifACIc_phsB_zeroDb,
					&iedModel_PROT_IDPDIF_DifACIc_phsB_instCVal_mag_f,
					&iedModel_PROT_IDPDIF_DifACIc_phsB_cVal_mag_f,
					&iedModel_PROT_IDPDIF_DifACIc_phsB_t,
					currentTime);

			mag = ucMAnalogInBuf[MB_offset_Ic_Diff] * K;
			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_PROT_IDPDIF_DifACIc_phsC_db,
					&iedModel_PROT_IDPDIF_DifACIc_phsC_zeroDb,
					&iedModel_PROT_IDPDIF_DifACIc_phsC_instCVal_mag_f,
					&iedModel_PROT_IDPDIF_DifACIc_phsC_cVal_mag_f,
					&iedModel_PROT_IDPDIF_DifACIc_phsC_t,
					currentTime);

			K = 1000 * (40 * ucConfigTRPWRBuf[MB_offset_ConfigS1 + MB_offset_P_Obmotki]) / ((float)sqrt3 * 65535 * ucConfigTRPWRBuf[MB_offset_ConfigS1 + MB_offset_U_Obmotki]);
			diapazon = K * 65535;

			mag = ucMAnalogInBuf[MB_offset_Ita] * K;
			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_PROT_IDPDIF_RstA_phsA_db,
					&iedModel_PROT_IDPDIF_RstA_phsA_zeroDb,
					&iedModel_PROT_IDPDIF_RstA_phsA_instCVal_mag_f,
					&iedModel_PROT_IDPDIF_RstA_phsA_cVal_mag_f,
					&iedModel_PROT_IDPDIF_RstA_phsA_t,
					currentTime);

			mag = ucMAnalogInBuf[MB_offset_Itb] * K;
			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_PROT_IDPDIF_RstA_phsB_db,
					&iedModel_PROT_IDPDIF_RstA_phsB_zeroDb,
					&iedModel_PROT_IDPDIF_RstA_phsB_instCVal_mag_f,
					&iedModel_PROT_IDPDIF_RstA_phsB_cVal_mag_f,
					&iedModel_PROT_IDPDIF_RstA_phsB_t,
					currentTime);

			mag = ucMAnalogInBuf[MB_offset_Itc] * K;
			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_PROT_IDPDIF_RstA_phsC_db,
					&iedModel_PROT_IDPDIF_RstA_phsC_zeroDb,
					&iedModel_PROT_IDPDIF_RstA_phsC_instCVal_mag_f,
					&iedModel_PROT_IDPDIF_RstA_phsC_cVal_mag_f,
					&iedModel_PROT_IDPDIF_RstA_phsC_t,
					currentTime);

			quality = QUALITY_VALIDITY_GOOD;
			if (Health == STVALINT32_Warning) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

			if (IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF_DifACIc_phsA_q,quality)){
				IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF_DifACIc_phsB_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF_DifACIc_phsC_q,quality);

				IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF_RstA_phsA_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF_RstA_phsB_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF_RstA_phsC_q,quality);

				IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF_Op_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF_Str_q,quality);
			}

/*
	// DifACIc
			K = 1000 * (40 * ucConfigTRPWRBuf[MB_offset_ConfigS1 + MB_offset_P_Obmotki]) / ((float)sqrt3 * 65535 * ucConfigTRPWRBuf[MB_offset_ConfigS1 + MB_offset_U_Obmotki]);
			mag = ucMAnalogInBuf[MB_offset_Ia_Diff] * K;
			if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_PROT_IDPDIF_DifACIc_phsA_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF_DifACIc_phsA_t, currentTime);
			mag = ucMAnalogInBuf[MB_offset_Ib_Diff] * K;
			if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_PROT_IDPDIF_DifACIc_phsB_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF_DifACIc_phsB_t, currentTime);
			mag = ucMAnalogInBuf[MB_offset_Ic_Diff] * K;
			if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_PROT_IDPDIF_DifACIc_phsC_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF_DifACIc_phsC_t, currentTime);

	// RstA
			K = 1000 * (40 * ucConfigTRPWRBuf[MB_offset_ConfigS1 + MB_offset_P_Obmotki]) / ((float)sqrt3 * 65535 * ucConfigTRPWRBuf[MB_offset_ConfigS1 + MB_offset_U_Obmotki]);
			mag = ucMAnalogInBuf[MB_offset_Ita] * K;
			if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_PROT_IDPDIF_RstA_phsA_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF_RstA_phsA_t, currentTime);
			mag = ucMAnalogInBuf[MB_offset_Itb] * K;
			if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_PROT_IDPDIF_RstA_phsB_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF_RstA_phsB_t, currentTime);
			mag = ucMAnalogInBuf[MB_offset_Itc] * K;
			if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_PROT_IDPDIF_RstA_phsC_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF_RstA_phsC_t, currentTime);
*/
}
/*******************************************************
 * Set_IDDPDIF наполняем оперативными данными
 *******************************************************/
int		Set_IDDPDIF	(uint16_t QTnum, uint64_t currentTime )
{

	uint32_t	Mod;
	uint32_t	Health;
	Quality 	quality;

	//Health
				Health = STVALINT32_OK;
				if (ucMDiscInBuf[MB_offset_errorM4] & MB_bOffsetModule4) 	{Health = STVALINT32_Warning;}
				if (ucMDiscInBuf[MB_offset_errorM5] & MB_bOffsetModule5) 	{Health = STVALINT32_Warning;}
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) 	{Health = STVALINT32_Warning;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDDPDIF_Health_stVal, Health))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDDPDIF_Health_t, currentTime);
//  Mod Beh

				if (ucMUstavkiInBuf[MB_offset_DIFFOts + MB_offset_DIFFOts_Config] & MB_bOffset_DIFFOts_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDDPDIF_Mod_stVal, Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDDPDIF_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDDPDIF_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDDPDIF_Beh_t, currentTime);
				}

//  Quality (Mod Beh)
				quality = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_IDDPDIF_Mod_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_IDDPDIF_Beh_q,quality);
				//IedServer_updateQuality(iedServer,&iedModel_PROT_IDDPDIF_Health_q,Qual);

// Str_general
				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IDDPDIF_Str_general,  ucMDiscInBuf[MB_offset_IO_Diffup_2] & MB_b_IO_Diffup_2))			// И0 >1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IDDPDIF_Str_t, currentTime);
// Op_general
				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IDDPDIF_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Diffup_2] & MB_b_SRAB_Diffup_2))		// СРАБ >1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IDDPDIF_Op_t, currentTime);

				quality = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offset_errorM4] & MB_bOffsetModule4) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				if (ucMDiscInBuf[MB_offset_errorM5] & MB_bOffsetModule5) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				if (IedServer_updateQuality(iedServer,&iedModel_PROT_IDDPDIF_Op_q,quality)){
				IedServer_updateQuality(iedServer,&iedModel_PROT_IDDPDIF_Str_q,quality);
				}

}
/*******************************************************
 * Set_IDDMPDIF наполняем оперативными данными
 *******************************************************/
int		Set_IDDMPDIF	(uint16_t QTnum, uint64_t currentTime )
{
	 Quality quality;
	//Health
				uint32_t	Health = STVALINT32_OK;
				if (ucMDiscInBuf[MB_offset_errorM4] & MB_bOffsetModule4) 		{Health = STVALINT32_Warning;}
				if (ucMDiscInBuf[MB_offset_errorM5] & MB_bOffsetModule5) 		{Health = STVALINT32_Warning;}
				if (ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki) 	{Health = STVALINT32_Warning;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDDMPDIF_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDDMPDIF_Health_t, currentTime);


	//  Mod Beh
				uint32_t	Mod;
				if (
						(ucMUstavkiInBuf[MB_offset_DIFFOts + MB_offset_DIFFOts_Config] & MB_bOffset_DIFFOts_Config_Stat) &&
						(ucMUstavkiInBuf[MB_offset_DIFFOts + MB_offset_DIFFOts_Config] & MB_bOffset_DIFFOtsMgn_Config_Stat)
						) {Mod = STVALINT32_ON;}
				else {Mod = STVALINT32_OFF;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDDMPDIF_Mod_stVal, Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDDMPDIF_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDDMPDIF_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDDMPDIF_Beh_t, currentTime);
				}

	//  Quality (Mod Beh)
				quality = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_IDDMPDIF_Mod_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_IDDMPDIF_Beh_q,quality);
				//IedServer_updateQuality(iedServer,&iedModel_PROT_IDDMPDIF_Health_q,Qual);


	// Str_general
				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IDDMPDIF_Str_general,  ucMDiscInBuf[MB_offset_IO_Diffup_2] & MB_b_IO_Diffup_m))			// И0 >1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IDDMPDIF_Str_t, currentTime);
	// Op_general
				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IDDMPDIF_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Diffup_2] & MB_b_IO_Diffup_m))		// СРАБ >1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IDDMPDIF_Op_t, currentTime);


				quality = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offset_errorM4] & MB_bOffsetModule4) 		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				if (ucMDiscInBuf[MB_offset_errorM5] & MB_bOffsetModule5) 		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				if (ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				if (IedServer_updateQuality(iedServer,&iedModel_PROT_IDDMPDIF_Op_q,quality)){
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDDMPDIF_Str_q,quality);

					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IDDMPDIF_Op_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IDDMPDIF_Str_t, currentTime);
				}

}

/*******************************************************
 * Set_ID0PDIF наполняем оперативными данными
 *******************************************************/
int		Set_ID0PDIF	(uint16_t QTnum, uint64_t currentTime )
{
Quality 	quality;
uint32_t	Mod;
uint32_t	Health;
//Health
			Health = STVALINT32_OK;
			if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule4) || (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5)) {Health = STVALINT32_Warning;}
			if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) 	{Health = STVALINT32_Warning;}

			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_ID0PDIF1_Health_stVal, Health)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_ID0PDIF1_Health_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_ID0PDIF2_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_ID0PDIF2_Health_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_ID0PDIF3_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_ID0PDIF3_Health_t, currentTime);
			}

//  Mod Beh
			if (ucMUstavkiInBuf[MB_offset_DIFF0_1 + MB_offset_DIFF0_Config] & MB_bOffset_DIFF0_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_ID0PDIF1_Mod_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_ID0PDIF1_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_ID0PDIF1_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_ID0PDIF1_Beh_t, currentTime);

			if (ucMUstavkiInBuf[MB_offset_DIFF0_2 + MB_offset_DIFF0_Config] & MB_bOffset_DIFF0_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_ID0PDIF2_Mod_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_ID0PDIF2_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_ID0PDIF2_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_ID0PDIF2_Beh_t, currentTime);

			if (ucMUstavkiInBuf[MB_offset_DIFF0_3 + MB_offset_DIFF0_Config] & MB_bOffset_DIFF0_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_ID0PDIF3_Mod_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_ID0PDIF3_Mod_t, currentTime);
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_ID0PDIF3_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_ID0PDIF3_Beh_t, currentTime);

//  Quality (Mod Beh)
			quality = QUALITY_VALIDITY_GOOD;
			if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

			if (IedServer_updateQuality(iedServer,&iedModel_PROT_ID0PDIF1_Mod_q,quality)){
				IedServer_updateQuality(iedServer,&iedModel_PROT_ID0PDIF1_Beh_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_ID0PDIF2_Mod_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_ID0PDIF2_Beh_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_ID0PDIF3_Mod_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_ID0PDIF3_Beh_q,quality);

				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_ID0PDIF1_Mod_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_ID0PDIF1_Beh_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_ID0PDIF2_Mod_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_ID0PDIF2_Beh_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_ID0PDIF3_Mod_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_ID0PDIF3_Beh_t, currentTime);
			}


// Str_general
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_ID0PDIF1_Str_general,  ucMDiscInBuf[MB_offset_IO_Diff0_1] & MB_b_IO_Diff0_1))			// И0 >1
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_ID0PDIF1_Str_t, currentTime);
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_ID0PDIF2_Str_general,  ucMDiscInBuf[MB_offset_IO_Diff0_2] & MB_b_IO_Diff0_2))			// И0 >1
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_ID0PDIF2_Str_t, currentTime);
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_ID0PDIF3_Str_general,  ucMDiscInBuf[MB_offset_IO_Diff0_3] & MB_b_IO_Diff0_3))			// И0 >1
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_ID0PDIF3_Str_t, currentTime);

// Op_general
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_ID0PDIF1_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Diff0_1] & MB_b_SRAB_Diff0_1))		// СРАБ >1
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_ID0PDIF1_Op_t, currentTime);
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_ID0PDIF2_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Diff0_2] & MB_b_SRAB_Diff0_2))		// СРАБ >1
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_ID0PDIF2_Op_t, currentTime);
			if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_ID0PDIF3_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Diff0_3] & MB_b_SRAB_Diff0_3))		// СРАБ >1
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_ID0PDIF3_Op_t, currentTime);


			quality = QUALITY_VALIDITY_GOOD;
			if (ucMDiscInBuf[MB_offset_errorM4] & MB_bOffsetModule4) 		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
			if (ucMDiscInBuf[MB_offset_errorM5] & MB_bOffsetModule5) 		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
			if (ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

			if (IedServer_updateQuality(iedServer,&iedModel_PROT_ID0PDIF1_Op_q,quality)){
				IedServer_updateQuality(iedServer,&iedModel_PROT_ID0PDIF1_Str_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_ID0PDIF2_Op_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_ID0PDIF2_Str_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_ID0PDIF3_Op_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_ID0PDIF3_Str_q,quality);

				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_ID0PDIF1_Str_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_ID0PDIF2_Str_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_ID0PDIF3_Str_t, currentTime);

				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_ID0PDIF1_Op_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_ID0PDIF2_Op_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_ID0PDIF3_Op_t, currentTime);
			}
}


#endif

#if defined (MR901) || defined (MR902)
#include "static_model_MR901_902.h"


extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
extern uint16_t   ucMUstavkiInBuf[MB_NumbUstavki];
extern uint16_t   ucOtherUstavkiInBuf[MB_NumbOtherUstavki];

/*******************************************************
 * заглушки
 *******************************************************/
int		Set_ID0PDIF		(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_IDDPDIF		(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_IDDMPDIF	(uint16_t QTnum, uint64_t currentTime ){return false;}

/*******************************************************
 * Set_IDPDIF наполняем оперативными данными
 *******************************************************/
#if defined (MR901)
int		Set_IDPDIF	(uint16_t QTnum, uint64_t currentTime )
{
	int			ret = false;
	float		mag;
	float		K;
	float		Max;
	Quality 	quality;
	float		diapazon;
	uint32_t	Health;
	uint32_t	Mod;

	//Health
				Health = STVALINT32_OK;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule4) {Health = STVALINT32_Warning;}
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5) {Health = STVALINT32_Warning;}
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Health = STVALINT32_Warning;}
				if (ucMDiscInBuf[MB_offsetHardFaults1] & MB_bOffsetErrorTT1) {Health = STVALINT32_Warning;}
				if (ucMDiscInBuf[MB_offsetHardFaults1] & MB_bOffsetErrorTT2) {Health = STVALINT32_Warning;}
				if (ucMDiscInBuf[MB_offsetHardFaults1] & MB_bOffsetErrorTT3) {Health = STVALINT32_Warning;}


				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDPDIF1_Health_stVal, Health)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF1_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDPDIF2_Health_stVal, Health))
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF2_Health_t, currentTime);
						if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDPDIF3_Health_stVal, Health))
							IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF3_Health_t, currentTime);
				}


	//  Mod Beh
				if (ucMUstavkiInBuf[MB_offset_DIFFZ_1 + MB_offset_DIFFZ_Config_Stat] & MB_bOffset_DIFFZ_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDPDIF1_Mod_stVal, Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF1_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDPDIF1_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF1_Beh_t, currentTime);
				}

				if (ucMUstavkiInBuf[MB_offset_DIFFZ_2 + MB_offset_DIFFZ_Config_Stat] & MB_bOffset_DIFFZ_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDPDIF2_Mod_stVal, Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF2_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDPDIF2_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF2_Beh_t, currentTime);
				}

				if (ucMUstavkiInBuf[MB_offset_DIFFZ_3 + MB_offset_DIFFZ_Config_Stat] & MB_bOffset_DIFFZ_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDPDIF3_Mod_stVal, Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF3_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDPDIF3_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF3_Beh_t, currentTime);
				}


	//  Quality (Mod Beh)
				quality = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				if (IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF1_Mod_q,quality)){
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF1_Beh_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF2_Mod_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF2_Beh_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF3_Mod_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF3_Beh_q,quality);

					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF1_Mod_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF1_Beh_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF2_Mod_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF2_Beh_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF3_Mod_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF3_Beh_t, currentTime);
				}

	// DifACIc RstA
				quality = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule4) 		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5) 		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) 		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				if (ucMDiscInBuf[MB_offsetHardFaults1] & MB_bOffsetErrorTT1) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				if (IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF1_DifACIc_phsA_q,quality)){
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF1_RstA_phsA_q,quality);

					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF1_DifACIc_phsA_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF1_RstA_phsA_t, currentTime);

					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF1_Op_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF1_Str_q,quality);
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IDPDIF1_Str_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IDPDIF1_Op_t, currentTime);

				}

				quality = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule4) 		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5) 		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) 		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				if (ucMDiscInBuf[MB_offsetHardFaults1] & MB_bOffsetErrorTT2) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				if (IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF2_DifACIc_phsA_q,quality)){
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF2_RstA_phsA_q,quality);

					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF2_DifACIc_phsA_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF2_RstA_phsA_t, currentTime);

					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF2_Op_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF2_Str_q,quality);
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IDPDIF2_Str_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IDPDIF2_Op_t, currentTime);

				}

				quality = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule4) 		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5) 		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) 		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				if (ucMDiscInBuf[MB_offsetHardFaults1] & MB_bOffsetErrorTT3)	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				if (IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF3_DifACIc_phsA_q,quality)){
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF3_RstA_phsA_q,quality);

					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF3_DifACIc_phsA_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF3_RstA_phsA_t, currentTime);

					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF3_Op_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF3_Str_q,quality);
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IDPDIF3_Str_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IDPDIF3_Op_t, currentTime);

				}


	// Str_general
				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IDPDIF1_Str_general,  (ucMDiscInBuf[MB_offset_IO_I_d1] & MB_b_IO_I_d1)>0))			// И0 >1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IDPDIF1_Str_t, currentTime);
				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IDPDIF2_Str_general,  (ucMDiscInBuf[MB_offset_IO_I_d2] & MB_b_IO_I_d2)>0))			// И0 >2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IDPDIF2_Str_t, currentTime);
				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IDPDIF3_Str_general,  (ucMDiscInBuf[MB_offset_IO_I_d3] & MB_b_IO_I_d3)>0))			// И0 >3
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IDPDIF3_Str_t, currentTime);

	// Op_general
				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IDPDIF1_Op_general,  (ucMDiscInBuf[MB_offset_SRAB_I_d1] & MB_b_SRAB_I_d1)>0))		// СРАБ >1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IDPDIF1_Op_t, currentTime);
				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IDPDIF2_Op_general,  (ucMDiscInBuf[MB_offset_SRAB_I_d2] & MB_b_SRAB_I_d2)>0))		// СРАБ >2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IDPDIF2_Op_t, currentTime);
				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IDPDIF3_Op_general,  (ucMDiscInBuf[MB_offset_SRAB_I_d3] & MB_b_SRAB_I_d3)>0))		// СРАБ >3
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IDPDIF3_Op_t, currentTime);


				uint8_t i;
				// ищем максимум тока. можно после вычитывания уставок
				Max = ucOtherUstavkiInBuf[MB_offset_Config_Pris1 + MB_offset_KTT];
				for (i=0;i<16;i++){
					if (ucOtherUstavkiInBuf[MB_offset_Config_Pris1 + MB_offset_KTT + i*6] > Max){
						Max = ucOtherUstavkiInBuf[MB_offset_Config_Pris1 + MB_offset_KTT + i*6];
					}
				}
				K = range_maxPris * Max / 65535;
				diapazon = (float)range_maxPris * Max;
// DifACIc
				mag = ucMAnalogInBuf[MB_offset_Id1] * K;

				Set_Db_zeroDB_float( mag, diapazon,
						&iedModel_PROT_IDPDIF1_DifACIc_phsA_db,
						&iedModel_PROT_IDPDIF1_DifACIc_phsA_zeroDb,
						&iedModel_PROT_IDPDIF1_DifACIc_phsA_instCVal_mag_f,
						&iedModel_PROT_IDPDIF1_DifACIc_phsA_cVal_mag_f,
						&iedModel_PROT_IDPDIF1_DifACIc_phsA_t,
						currentTime);

				mag = ucMAnalogInBuf[MB_offset_Id2] * K;
				Set_Db_zeroDB_float(mag, diapazon,
						&iedModel_PROT_IDPDIF2_DifACIc_phsA_db,
						&iedModel_PROT_IDPDIF2_DifACIc_phsA_zeroDb,
						&iedModel_PROT_IDPDIF2_DifACIc_phsA_instCVal_mag_f,
						&iedModel_PROT_IDPDIF2_DifACIc_phsA_cVal_mag_f,
						&iedModel_PROT_IDPDIF2_DifACIc_phsA_t,
						currentTime);

				mag = ucMAnalogInBuf[MB_offset_Id3] * K;
				Set_Db_zeroDB_float(mag, diapazon,
						&iedModel_PROT_IDPDIF3_DifACIc_phsA_db,
						&iedModel_PROT_IDPDIF3_DifACIc_phsA_zeroDb,
						&iedModel_PROT_IDPDIF3_DifACIc_phsA_instCVal_mag_f,
						&iedModel_PROT_IDPDIF3_DifACIc_phsA_cVal_mag_f,
						&iedModel_PROT_IDPDIF3_DifACIc_phsA_t,
						currentTime);
// RstA
				mag = ucMAnalogInBuf[MB_offset_It1] * K;
				Set_Db_zeroDB_float(mag, diapazon,
						&iedModel_PROT_IDPDIF1_RstA_phsA_db,
						&iedModel_PROT_IDPDIF1_RstA_phsA_zeroDb,
						&iedModel_PROT_IDPDIF1_RstA_phsA_instCVal_mag_f,
						&iedModel_PROT_IDPDIF1_RstA_phsA_cVal_mag_f,
						&iedModel_PROT_IDPDIF1_RstA_phsA_t,
						currentTime);

				mag = ucMAnalogInBuf[MB_offset_It2] * K;
				Set_Db_zeroDB_float(mag, diapazon,
						&iedModel_PROT_IDPDIF2_RstA_phsA_db,
						&iedModel_PROT_IDPDIF2_RstA_phsA_zeroDb,
						&iedModel_PROT_IDPDIF2_RstA_phsA_instCVal_mag_f,
						&iedModel_PROT_IDPDIF2_RstA_phsA_cVal_mag_f,
						&iedModel_PROT_IDPDIF2_RstA_phsA_t,
						currentTime);

				mag = ucMAnalogInBuf[MB_offset_It3] * K;
				Set_Db_zeroDB_float(mag, diapazon,
						&iedModel_PROT_IDPDIF3_RstA_phsA_db,
						&iedModel_PROT_IDPDIF3_RstA_phsA_zeroDb,
						&iedModel_PROT_IDPDIF3_RstA_phsA_instCVal_mag_f,
						&iedModel_PROT_IDPDIF3_RstA_phsA_cVal_mag_f,
						&iedModel_PROT_IDPDIF3_RstA_phsA_t,
						currentTime);

/*
// DifACIc
				mag = ucMAnalogInBuf[MB_offset_Id1] * K;
				if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_PROT_IDPDIF1_DifACIc_phsA_cVal_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF1_DifACIc_phsA_t, currentTime);

				mag = ucMAnalogInBuf[MB_offset_Id2] * K;
				if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_PROT_IDPDIF2_DifACIc_phsA_cVal_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF2_DifACIc_phsA_t, currentTime);

				mag = ucMAnalogInBuf[MB_offset_Id3] * K;
				if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_PROT_IDPDIF3_DifACIc_phsA_cVal_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF3_DifACIc_phsA_t, currentTime);

// RstA
				mag = ucMAnalogInBuf[MB_offset_It1] * K;
				if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_PROT_IDPDIF1_RstA_phsA_cVal_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF1_RstA_phsA_t, currentTime);

				mag = ucMAnalogInBuf[MB_offset_It2] * K;
				if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_PROT_IDPDIF2_RstA_phsA_cVal_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF2_RstA_phsA_t, currentTime);

				mag = ucMAnalogInBuf[MB_offset_It3] * K;
				if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_PROT_IDPDIF3_RstA_phsA_cVal_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF3_RstA_phsA_t, currentTime);
*/
return ret;
}
#endif
/*******************************************************
 * Set_IDPDIF наполняем оперативными данными
 *******************************************************/
#if defined (MR902)
int		Set_IDPDIF	(uint16_t QTnum, uint64_t currentTime )
{
	int			ret = false;
	float		mag;
	float		K;
	float		Max;
	Quality 	quality;
	float		diapazon;
	uint32_t	Health;
	uint32_t	Mod;

	//Health
				Health = STVALINT32_OK;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule4) {Health = STVALINT32_Warning;}
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5) {Health = STVALINT32_Warning;}
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Health = STVALINT32_Warning;}
				if (ucMDiscInBuf[MB_offsetHardFaults1] & MB_bOffsetErrorTT1) {Health = STVALINT32_Warning;}
				if (ucMDiscInBuf[MB_offsetHardFaults1] & MB_bOffsetErrorTT2) {Health = STVALINT32_Warning;}
				if (ucMDiscInBuf[MB_offsetHardFaults1] & MB_bOffsetErrorTT3) {Health = STVALINT32_Warning;}


				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDPDIF1_Health_stVal, Health)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF1_Health_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDPDIF2_Health_stVal, Health))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF2_Health_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDPDIF3_Health_stVal, Health))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF3_Health_t, currentTime);
				}


	//  Mod Beh
				if (ucMUstavkiInBuf[MB_offset_DIFFZ_1 + MB_offset_DIFFZ_Config_Stat] & MB_bOffset_DIFFZ_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDPDIF1_Mod_stVal, Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF1_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDPDIF1_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF1_Beh_t, currentTime);
				}

				if (ucMUstavkiInBuf[MB_offset_DIFFZ_2 + MB_offset_DIFFZ_Config_Stat] & MB_bOffset_DIFFZ_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDPDIF2_Mod_stVal, Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF2_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDPDIF2_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF2_Beh_t, currentTime);
				}

				if (ucMUstavkiInBuf[MB_offset_DIFFZ_3 + MB_offset_DIFFZ_Config_Stat] & MB_bOffset_DIFFZ_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDPDIF3_Mod_stVal, Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF3_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDPDIF3_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF3_Beh_t, currentTime);
				}


	//  Quality (Mod Beh)
				quality = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				if (IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF1_Mod_q,quality)){
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF1_Beh_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF2_Mod_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF2_Beh_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF3_Mod_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF3_Beh_q,quality);

					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF1_Mod_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF1_Beh_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF2_Mod_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF2_Beh_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF3_Mod_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF3_Beh_t, currentTime);
				}

	// DifACIc RstA
				quality = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule4) 		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5) 		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) 		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				if (ucMDiscInBuf[MB_offsetHardFaults1] & MB_bOffsetErrorTT1) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				if (IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF1_DifACIc_phsA_q,quality)){
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF1_RstA_phsA_q,quality);

					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF1_DifACIc_phsB_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF1_RstA_phsB_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF1_DifACIc_phsC_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF1_RstA_phsC_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF1_Op_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF1_Str_q,quality);

					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF1_DifACIc_phsA_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF1_RstA_phsA_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF1_DifACIc_phsB_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF1_RstA_phsB_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF1_DifACIc_phsC_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF1_RstA_phsC_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF1_Str_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF1_Op_t, currentTime);

				}

				quality = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule4) 		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5) 		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) 		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				if (ucMDiscInBuf[MB_offsetHardFaults1] & MB_bOffsetErrorTT2) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				if(IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF2_DifACIc_phsA_q,quality)){
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF2_RstA_phsA_q,quality);

					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF2_DifACIc_phsB_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF2_RstA_phsB_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF2_DifACIc_phsC_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF2_RstA_phsC_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF2_Op_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF2_Str_q,quality);

					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF2_DifACIc_phsA_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF2_RstA_phsA_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF2_DifACIc_phsB_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF2_RstA_phsB_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF2_DifACIc_phsC_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF2_RstA_phsC_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IDPDIF2_Str_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IDPDIF2_Op_t, currentTime);
}

				quality = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule4) 		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5) 		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) 		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				if (ucMDiscInBuf[MB_offsetHardFaults1] & MB_bOffsetErrorTT3) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				if (IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF3_DifACIc_phsA_q,quality)){
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF3_RstA_phsA_q,quality);

					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF3_DifACIc_phsB_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF3_RstA_phsB_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF3_DifACIc_phsC_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF3_RstA_phsC_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF3_Op_q,quality);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF3_Str_q,quality);

					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF3_DifACIc_phsA_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF3_RstA_phsA_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF3_DifACIc_phsB_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF3_RstA_phsB_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF3_DifACIc_phsC_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF3_RstA_phsC_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF3_Str_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF3_Op_t, currentTime);

				}

	// Str_general
				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IDPDIF1_Str_general,  (ucMDiscInBuf[MB_offset_IO_I_d1] & MB_b_IO_I_d1)>0))			// И0 >1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IDPDIF1_Str_t, currentTime);
				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IDPDIF2_Str_general,  (ucMDiscInBuf[MB_offset_IO_I_d2] & MB_b_IO_I_d2)>0))			// И0 >2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IDPDIF2_Str_t, currentTime);
				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IDPDIF3_Str_general,  (ucMDiscInBuf[MB_offset_IO_I_d3] & MB_b_IO_I_d3)>0))			// И0 >3
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IDPDIF3_Str_t, currentTime);

	// Op_general
				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IDPDIF1_Op_general,  (ucMDiscInBuf[MB_offset_SRAB_I_d1] & MB_b_SRAB_I_d1)>0))		// СРАБ >1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IDPDIF1_Op_t, currentTime);
				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IDPDIF2_Op_general,  (ucMDiscInBuf[MB_offset_SRAB_I_d2] & MB_b_SRAB_I_d2)>0))		// СРАБ >2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IDPDIF2_Op_t, currentTime);
				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IDPDIF3_Op_general,  (ucMDiscInBuf[MB_offset_SRAB_I_d3] & MB_b_SRAB_I_d3)>0))		// СРАБ >3
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IDPDIF3_Op_t, currentTime);

	// DifACIc
				uint8_t i;
				// ищем максимум тока. можно после вычитывания уставок
				Max = ucOtherUstavkiInBuf[MB_offset_Config_Pris1 + MB_offset_KTT];
				for (i=0;i<5;i++){
					if (ucOtherUstavkiInBuf[MB_offset_Config_Pris1 + MB_offset_KTT + i*6] > Max){
						Max = ucOtherUstavkiInBuf[MB_offset_Config_Pris1 + MB_offset_KTT + i*6];
					}
				}
				K = (float)range_maxPris * Max / (float)65535;
				diapazon = (float)range_maxPris * Max;
// DifACIc A
				mag = ucMAnalogInBuf[MB_offset_Id1a] * K;
				Set_Db_zeroDB_float( mag, diapazon,
						&iedModel_PROT_IDPDIF1_DifACIc_phsA_db,
						&iedModel_PROT_IDPDIF1_DifACIc_phsA_zeroDb,
						&iedModel_PROT_IDPDIF1_DifACIc_phsA_instCVal_mag_f,
						&iedModel_PROT_IDPDIF1_DifACIc_phsA_cVal_mag_f,
						&iedModel_PROT_IDPDIF1_DifACIc_phsA_t,
						currentTime);

				mag = ucMAnalogInBuf[MB_offset_Id2a] * K;
				Set_Db_zeroDB_float( mag, diapazon,
						&iedModel_PROT_IDPDIF2_DifACIc_phsA_db,
						&iedModel_PROT_IDPDIF2_DifACIc_phsA_zeroDb,
						&iedModel_PROT_IDPDIF2_DifACIc_phsA_instCVal_mag_f,
						&iedModel_PROT_IDPDIF2_DifACIc_phsA_cVal_mag_f,
						&iedModel_PROT_IDPDIF2_DifACIc_phsA_t,
						currentTime);

				mag = ucMAnalogInBuf[MB_offset_Id3a] * K;
				Set_Db_zeroDB_float( mag, diapazon,
						&iedModel_PROT_IDPDIF3_DifACIc_phsA_db,
						&iedModel_PROT_IDPDIF3_DifACIc_phsA_zeroDb,
						&iedModel_PROT_IDPDIF3_DifACIc_phsA_instCVal_mag_f,
						&iedModel_PROT_IDPDIF3_DifACIc_phsA_cVal_mag_f,
						&iedModel_PROT_IDPDIF3_DifACIc_phsA_t,
						currentTime);

// DifACIc B
				mag = ucMAnalogInBuf[MB_offset_Id1b] * K;
				Set_Db_zeroDB_float( mag, diapazon,
						&iedModel_PROT_IDPDIF1_DifACIc_phsB_db,
						&iedModel_PROT_IDPDIF1_DifACIc_phsB_zeroDb,
						&iedModel_PROT_IDPDIF1_DifACIc_phsB_instCVal_mag_f,
						&iedModel_PROT_IDPDIF1_DifACIc_phsB_cVal_mag_f,
						&iedModel_PROT_IDPDIF1_DifACIc_phsB_t,
						currentTime);

				mag = ucMAnalogInBuf[MB_offset_Id2b] * K;
				Set_Db_zeroDB_float( mag, diapazon,
						&iedModel_PROT_IDPDIF2_DifACIc_phsB_db,
						&iedModel_PROT_IDPDIF2_DifACIc_phsB_zeroDb,
						&iedModel_PROT_IDPDIF2_DifACIc_phsB_instCVal_mag_f,
						&iedModel_PROT_IDPDIF2_DifACIc_phsB_cVal_mag_f,
						&iedModel_PROT_IDPDIF2_DifACIc_phsB_t,
						currentTime);

				mag = ucMAnalogInBuf[MB_offset_Id3b] * K;
				Set_Db_zeroDB_float( mag, diapazon,
						&iedModel_PROT_IDPDIF3_DifACIc_phsB_db,
						&iedModel_PROT_IDPDIF3_DifACIc_phsB_zeroDb,
						&iedModel_PROT_IDPDIF3_DifACIc_phsB_instCVal_mag_f,
						&iedModel_PROT_IDPDIF3_DifACIc_phsB_cVal_mag_f,
						&iedModel_PROT_IDPDIF3_DifACIc_phsB_t,
						currentTime);

// DifACIc C
				mag = ucMAnalogInBuf[MB_offset_Id1c] * K;
				Set_Db_zeroDB_float( mag, diapazon,
						&iedModel_PROT_IDPDIF1_DifACIc_phsC_db,
						&iedModel_PROT_IDPDIF1_DifACIc_phsC_zeroDb,
						&iedModel_PROT_IDPDIF1_DifACIc_phsC_instCVal_mag_f,
						&iedModel_PROT_IDPDIF1_DifACIc_phsC_cVal_mag_f,
						&iedModel_PROT_IDPDIF1_DifACIc_phsC_t,
						currentTime);

				mag = ucMAnalogInBuf[MB_offset_Id2c] * K;
				Set_Db_zeroDB_float( mag, diapazon,
						&iedModel_PROT_IDPDIF2_DifACIc_phsC_db,
						&iedModel_PROT_IDPDIF2_DifACIc_phsC_zeroDb,
						&iedModel_PROT_IDPDIF2_DifACIc_phsC_instCVal_mag_f,
						&iedModel_PROT_IDPDIF2_DifACIc_phsC_cVal_mag_f,
						&iedModel_PROT_IDPDIF2_DifACIc_phsC_t,
						currentTime);

				mag = ucMAnalogInBuf[MB_offset_Id3c] * K;
				Set_Db_zeroDB_float( mag, diapazon,
						&iedModel_PROT_IDPDIF3_DifACIc_phsC_db,
						&iedModel_PROT_IDPDIF3_DifACIc_phsC_zeroDb,
						&iedModel_PROT_IDPDIF3_DifACIc_phsC_instCVal_mag_f,
						&iedModel_PROT_IDPDIF3_DifACIc_phsC_cVal_mag_f,
						&iedModel_PROT_IDPDIF3_DifACIc_phsC_t,
						currentTime);

// RstA A
				mag = ucMAnalogInBuf[MB_offset_It1a] * K;
				Set_Db_zeroDB_float( mag, diapazon,
						&iedModel_PROT_IDPDIF1_RstA_phsA_db,
						&iedModel_PROT_IDPDIF1_RstA_phsA_zeroDb,
						&iedModel_PROT_IDPDIF1_RstA_phsA_instCVal_mag_f,
						&iedModel_PROT_IDPDIF1_RstA_phsA_cVal_mag_f,
						&iedModel_PROT_IDPDIF1_RstA_phsA_t,
						currentTime);

				mag = ucMAnalogInBuf[MB_offset_It2a] * K;
				Set_Db_zeroDB_float( mag, diapazon,
						&iedModel_PROT_IDPDIF2_RstA_phsA_db,
						&iedModel_PROT_IDPDIF2_RstA_phsA_zeroDb,
						&iedModel_PROT_IDPDIF2_RstA_phsA_instCVal_mag_f,
						&iedModel_PROT_IDPDIF2_RstA_phsA_cVal_mag_f,
						&iedModel_PROT_IDPDIF2_RstA_phsA_t,
						currentTime);

				mag = ucMAnalogInBuf[MB_offset_It3a] * K;
				Set_Db_zeroDB_float( mag, diapazon,
						&iedModel_PROT_IDPDIF3_RstA_phsA_db,
						&iedModel_PROT_IDPDIF3_RstA_phsA_zeroDb,
						&iedModel_PROT_IDPDIF3_RstA_phsA_instCVal_mag_f,
						&iedModel_PROT_IDPDIF3_RstA_phsA_cVal_mag_f,
						&iedModel_PROT_IDPDIF3_RstA_phsA_t,
						currentTime);

// RstA B
				mag = ucMAnalogInBuf[MB_offset_It1b] * K;
				Set_Db_zeroDB_float( mag, diapazon,
						&iedModel_PROT_IDPDIF1_RstA_phsB_db,
						&iedModel_PROT_IDPDIF1_RstA_phsB_zeroDb,
						&iedModel_PROT_IDPDIF1_RstA_phsB_instCVal_mag_f,
						&iedModel_PROT_IDPDIF1_RstA_phsB_cVal_mag_f,
						&iedModel_PROT_IDPDIF1_RstA_phsB_t,
						currentTime);

				mag = ucMAnalogInBuf[MB_offset_It2b] * K;
				Set_Db_zeroDB_float( mag, diapazon,
						&iedModel_PROT_IDPDIF2_RstA_phsB_db,
						&iedModel_PROT_IDPDIF2_RstA_phsB_zeroDb,
						&iedModel_PROT_IDPDIF2_RstA_phsB_instCVal_mag_f,
						&iedModel_PROT_IDPDIF2_RstA_phsB_cVal_mag_f,
						&iedModel_PROT_IDPDIF2_RstA_phsB_t,
						currentTime);

				mag = ucMAnalogInBuf[MB_offset_It3b] * K;
				Set_Db_zeroDB_float( mag, diapazon,
						&iedModel_PROT_IDPDIF3_RstA_phsB_db,
						&iedModel_PROT_IDPDIF3_RstA_phsB_zeroDb,
						&iedModel_PROT_IDPDIF3_RstA_phsB_instCVal_mag_f,
						&iedModel_PROT_IDPDIF3_RstA_phsB_cVal_mag_f,
						&iedModel_PROT_IDPDIF3_RstA_phsB_t,
						currentTime);

// RstA C
				mag = ucMAnalogInBuf[MB_offset_It1c] * K;
				Set_Db_zeroDB_float( mag, diapazon,
						&iedModel_PROT_IDPDIF1_RstA_phsC_db,
						&iedModel_PROT_IDPDIF1_RstA_phsC_zeroDb,
						&iedModel_PROT_IDPDIF1_RstA_phsC_instCVal_mag_f,
						&iedModel_PROT_IDPDIF1_RstA_phsC_cVal_mag_f,
						&iedModel_PROT_IDPDIF1_RstA_phsC_t,
						currentTime);

				mag = ucMAnalogInBuf[MB_offset_It2c] * K;
				Set_Db_zeroDB_float( mag, diapazon,
						&iedModel_PROT_IDPDIF2_RstA_phsC_db,
						&iedModel_PROT_IDPDIF2_RstA_phsC_zeroDb,
						&iedModel_PROT_IDPDIF2_RstA_phsC_instCVal_mag_f,
						&iedModel_PROT_IDPDIF2_RstA_phsC_cVal_mag_f,
						&iedModel_PROT_IDPDIF2_RstA_phsC_t,
						currentTime);

				mag = ucMAnalogInBuf[MB_offset_It3c] * K;
				Set_Db_zeroDB_float( mag, diapazon,
						&iedModel_PROT_IDPDIF3_RstA_phsC_db,
						&iedModel_PROT_IDPDIF3_RstA_phsC_zeroDb,
						&iedModel_PROT_IDPDIF3_RstA_phsC_instCVal_mag_f,
						&iedModel_PROT_IDPDIF3_RstA_phsC_cVal_mag_f,
						&iedModel_PROT_IDPDIF3_RstA_phsC_t,
						currentTime);
/*
				mag = ucMAnalogInBuf[MB_offset_Id1a] * K;
				if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_PROT_IDPDIF1_DifACIc_phsA_cVal_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF1_DifACIc_phsA_t, currentTime);
				mag = ucMAnalogInBuf[MB_offset_Id2a] * K;
				if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_PROT_IDPDIF2_DifACIc_phsA_cVal_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF2_DifACIc_phsA_t, currentTime);
				mag = ucMAnalogInBuf[MB_offset_Id3a] * K;
				if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_PROT_IDPDIF3_DifACIc_phsA_cVal_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF3_DifACIc_phsA_t, currentTime);

				mag = ucMAnalogInBuf[MB_offset_Id1b] * K;
				if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_PROT_IDPDIF1_DifACIc_phsB_cVal_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF1_DifACIc_phsB_t, currentTime);
				mag = ucMAnalogInBuf[MB_offset_Id2b] * K;
				if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_PROT_IDPDIF2_DifACIc_phsB_cVal_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF2_DifACIc_phsB_t, currentTime);
				mag = ucMAnalogInBuf[MB_offset_Id3b] * K;
				if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_PROT_IDPDIF3_DifACIc_phsB_cVal_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF3_DifACIc_phsB_t, currentTime);

				mag = ucMAnalogInBuf[MB_offset_Id1c] * K;
				if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_PROT_IDPDIF1_DifACIc_phsC_cVal_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF1_DifACIc_phsC_t, currentTime);
				mag = ucMAnalogInBuf[MB_offset_Id2c] * K;
				if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_PROT_IDPDIF2_DifACIc_phsC_cVal_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF2_DifACIc_phsC_t, currentTime);
				mag = ucMAnalogInBuf[MB_offset_Id3c] * K;
				if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_PROT_IDPDIF3_DifACIc_phsC_cVal_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF3_DifACIc_phsC_t, currentTime);

	// RstA
				mag = ucMAnalogInBuf[MB_offset_It1a] * K;
				if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_PROT_IDPDIF1_RstA_phsA_cVal_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF1_RstA_phsA_t, currentTime);
				mag = ucMAnalogInBuf[MB_offset_It2a] * K;
				if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_PROT_IDPDIF2_RstA_phsA_cVal_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF2_RstA_phsA_t, currentTime);
				mag = ucMAnalogInBuf[MB_offset_It3a] * K;
				if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_PROT_IDPDIF3_RstA_phsA_cVal_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF3_RstA_phsA_t, currentTime);

				mag = ucMAnalogInBuf[MB_offset_It1b] * K;
				if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_PROT_IDPDIF1_RstA_phsB_cVal_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF1_RstA_phsB_t, currentTime);
				mag = ucMAnalogInBuf[MB_offset_It2b] * K;
				if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_PROT_IDPDIF2_RstA_phsB_cVal_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF2_RstA_phsB_t, currentTime);
				mag = ucMAnalogInBuf[MB_offset_It3b] * K;
				if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_PROT_IDPDIF3_RstA_phsB_cVal_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF3_RstA_phsB_t, currentTime);

				mag = ucMAnalogInBuf[MB_offset_It1c] * K;
				if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_PROT_IDPDIF1_RstA_phsC_cVal_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF1_RstA_phsC_t, currentTime);
				mag = ucMAnalogInBuf[MB_offset_It2c] * K;
				if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_PROT_IDPDIF2_RstA_phsC_cVal_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF2_RstA_phsC_t, currentTime);
				mag = ucMAnalogInBuf[MB_offset_It3c] * K;
				if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_PROT_IDPDIF3_RstA_phsC_cVal_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF3_RstA_phsC_t, currentTime);
*/
return ret;
}
#endif
/*******************************************************
 * Set_IDMPDIF наполняем оперативными данными
 *******************************************************/
int		Set_IDMPDIF	(uint16_t QTnum, uint64_t currentTime )
{
	int			ret = false;
	uint32_t	Mod;
	Quality 	quality;

//Health
				uint32_t	Health = STVALINT32_OK;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule4) 		{Health = STVALINT32_Warning;}
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5) 		{Health = STVALINT32_Warning;}
				if (ucMDiscInBuf[MB_offsetHardFaults1] & MB_bOffsetErrorTT1) 	{Health = STVALINT32_Warning;}
				if (ucMDiscInBuf[MB_offsetHardFaults1] & MB_bOffsetErrorTT2) 	{Health = STVALINT32_Warning;}
				if (ucMDiscInBuf[MB_offsetHardFaults1] & MB_bOffsetErrorTT3) 	{Health = STVALINT32_Warning;}
				if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {Health = STVALINT32_Warning;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDMPDIF1_Health_stVal, Health)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDMPDIF1_Health_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDMPDIF2_Health_stVal, Health))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDMPDIF2_Health_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDMPDIF3_Health_stVal, Health))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDMPDIF3_Health_t, currentTime);
				}

	//  Mod Beh

				if (ucMUstavkiInBuf[MB_offset_DIFFZ_1m + MB_offset_DIFFZ_Config_Stat] & MB_bOffset_DIFFZ_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDMPDIF1_Mod_stVal, Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDMPDIF1_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDMPDIF1_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDMPDIF1_Beh_t, currentTime);
				}

				if (ucMUstavkiInBuf[MB_offset_DIFFZ_2m + MB_offset_DIFFZ_Config_Stat] & MB_bOffset_DIFFZ_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDMPDIF2_Mod_stVal, Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDMPDIF2_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDMPDIF2_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDMPDIF2_Beh_t, currentTime);
				}

				if (ucMUstavkiInBuf[MB_offset_DIFFZ_3m + MB_offset_DIFFZ_Config_Stat] & MB_bOffset_DIFFZ_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDMPDIF3_Mod_stVal, Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDMPDIF3_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDMPDIF3_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDMPDIF3_Beh_t, currentTime);
				}

	//  Quality (Mod Beh)
				quality = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) 		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_IDMPDIF1_Mod_q,quality)){
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDMPDIF1_Beh_q,quality);

					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDMPDIF1_Mod_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDMPDIF1_Beh_t, currentTime);
				}

				quality = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) 		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_IDMPDIF2_Mod_q,quality)){
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDMPDIF2_Beh_q,quality);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDMPDIF2_Mod_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDMPDIF2_Beh_t, currentTime);
				}

				quality = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) 		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_IDMPDIF3_Mod_q,quality)){
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDMPDIF3_Beh_q,quality);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDMPDIF3_Mod_t, currentTime);
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDMPDIF3_Beh_t, currentTime);
				}


	// Op_general
				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IDMPDIF1_Op_general,  (ucMDiscInBuf[MB_offset_SRAB_I_d1m] & MB_b_SRAB_I_d1m)>0))	// СРАБ >1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IDMPDIF1_Op_t, currentTime);
				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IDMPDIF2_Op_general,  (ucMDiscInBuf[MB_offset_SRAB_I_d2m] & MB_b_SRAB_I_d2m)>0))	// СРАБ >2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IDMPDIF2_Op_t, currentTime);
				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IDMPDIF3_Op_general,  (ucMDiscInBuf[MB_offset_SRAB_I_d3m] & MB_b_SRAB_I_d3m)>0))	// СРАБ >3
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IDMPDIF3_Op_t, currentTime);

				quality = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) 		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule4) 		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5) 		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				if (ucMDiscInBuf[MB_offsetHardFaults1] & MB_bOffsetErrorTT1) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_IDMPDIF1_Op_q,quality)){
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IDMPDIF1_Op_t, currentTime);
				}

				quality = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) 		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule4) 		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5) 		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				if (ucMDiscInBuf[MB_offsetHardFaults1] & MB_bOffsetErrorTT2) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_IDMPDIF2_Op_q,quality)){
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IDMPDIF2_Op_t, currentTime);
				}

				quality = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) 		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule4) 		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5) 		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				if (ucMDiscInBuf[MB_offsetHardFaults1] & MB_bOffsetErrorTT3) 	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
				if (IedServer_updateQuality(iedServer,&iedModel_PROT_IDMPDIF3_Op_q,quality)){
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IDMPDIF3_Op_t, currentTime);
				}
return ret;
}

#endif
