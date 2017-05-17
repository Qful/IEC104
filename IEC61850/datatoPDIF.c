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

#if defined (MR801)
#include "static_model_MR801.h"


extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
extern uint16_t   ucMUstavkiInBuf[MB_NumbUstavki];
extern uint16_t   ucConfigTRPWRBuf[MB_NumbConfigTRPWR];


/*******************************************************
 * Set_IDPDIF наполняем оперативными данными
 *******************************************************/
void	Set_IDPDIF	(uint8_t num, uint64_t currentTime )
{
	float	mag;
	float	K;

	//Health
				uint32_t	Health = STVALINT32_OK;
				if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule4) || (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5)) {Health = STVALINT32_Warning;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDPDIF_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF_Health_t, currentTime);


	//  Mod Beh
				uint32_t	Mod;
				if (ucMUstavkiInBuf[MB_offset_DIFFZ + MB_offset_DIFFZ_Config_Stat] & MB_bOffset_DIFFZ_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDPDIF_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDPDIF_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDPDIF_Beh_t, currentTime);


	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}


				IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF_Health_q,Qual);

	// DifACIc
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF_DifACIc_phsA_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF_DifACIc_phsB_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF_DifACIc_phsC_q,Qual);
	// RstA
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF_RstA_phsA_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF_RstA_phsB_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF_RstA_phsC_q,Qual);

	// Str_general
				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IDPDIF_Str_general,  ucMDiscInBuf[MB_offset_IO_Diffup_1] & MB_b_IO_Diffup_1))			// И0 >1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IDPDIF_Str_t, currentTime);

	// Op_general
				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IDPDIF_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Diffup_1] & MB_b_SRAB_Diffup_1))		// СРАБ >1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IDPDIF_Op_t, currentTime);

				IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_IDPDIF_Str_q,0);

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
}
/*******************************************************
 * Set_IDDPDIF наполняем оперативными данными
 *******************************************************/
void	Set_IDDPDIF	(uint8_t num, uint64_t currentTime )
{


	//Health
				uint32_t	Health = STVALINT32_OK;
				if ((ucMDiscInBuf[MB_offset_errorM4] & MB_bOffsetModule4) || (ucMDiscInBuf[MB_offset_errorM5] & MB_bOffsetModule5)) {Health = STVALINT32_Warning;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDDPDIF_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDDPDIF_Health_t, currentTime);


//  Mod Beh
				uint32_t	Mod;
				if (ucMUstavkiInBuf[MB_offset_DIFFOts + MB_offset_DIFFOts_Config] & MB_bOffset_DIFFOts_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDDPDIF_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDDPDIF_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDDPDIF_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDDPDIF_Beh_t, currentTime);

//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_IDDPDIF_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_IDDPDIF_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_IDDPDIF_Health_q,Qual);


// Str_general
				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IDDPDIF_Str_general,  ucMDiscInBuf[MB_offset_IO_Diffup_2] & MB_b_IO_Diffup_2))			// И0 >1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IDDPDIF_Str_t, currentTime);
// Op_general
				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IDDPDIF_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Diffup_2] & MB_b_SRAB_Diffup_2))		// СРАБ >1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IDDPDIF_Op_t, currentTime);

				IedServer_updateQuality(iedServer,&iedModel_PROT_IDDPDIF_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_IDDPDIF_Str_q,0);

}
/*******************************************************
 * Set_IDDMPDIF наполняем оперативными данными
 *******************************************************/
void	Set_IDDMPDIF	(uint8_t num, uint64_t currentTime )
{
	//Health
				uint32_t	Health = STVALINT32_OK;
				if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule4) || (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5)) {Health = STVALINT32_Warning;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDDMPDIF_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDDMPDIF_Health_t, currentTime);


	//  Mod Beh
				uint32_t	Mod;
				if (
						(ucMUstavkiInBuf[MB_offset_DIFFOts + MB_offset_DIFFOts_Config] & MB_bOffset_DIFFOts_Config_Stat) &&
						(ucMUstavkiInBuf[MB_offset_DIFFOts + MB_offset_DIFFOts_Config] & MB_bOffset_DIFFOtsMgn_Config_Stat)
						) {Mod = STVALINT32_ON;}
				else {Mod = STVALINT32_OFF;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDDMPDIF_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDDMPDIF_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IDDMPDIF_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IDDMPDIF_Beh_t, currentTime);

	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_IDDMPDIF_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_IDDMPDIF_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_IDDMPDIF_Health_q,Qual);


	// Str_general
				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IDDMPDIF_Str_general,  ucMDiscInBuf[MB_offset_IO_Diffup_2] & MB_b_IO_Diffup_m))			// И0 >1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IDDMPDIF_Str_t, currentTime);
	// Op_general
				if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IDDMPDIF_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Diffup_2] & MB_b_IO_Diffup_m))		// СРАБ >1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IDDMPDIF_Op_t, currentTime);

				IedServer_updateQuality(iedServer,&iedModel_PROT_IDDMPDIF_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_IDDMPDIF_Str_q,0);

}

/*******************************************************
 * Set_ID0PDIF наполняем оперативными данными
 *******************************************************/
void	Set_ID0PDIF	(uint8_t num, uint64_t currentTime )
{
	//Health
				uint32_t	Health = STVALINT32_OK;
				if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule4) || (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5)) {Health = STVALINT32_Warning;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_ID0PDIF1_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_ID0PDIF1_Health_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_ID0PDIF2_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_ID0PDIF2_Health_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_ID0PDIF3_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_ID0PDIF3_Health_t, currentTime);

	//  Mod Beh
				uint32_t	Mod;
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
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_ID0PDIF1_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_ID0PDIF1_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_ID0PDIF1_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_ID0PDIF2_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_ID0PDIF2_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_ID0PDIF2_Health_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_ID0PDIF3_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_ID0PDIF3_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_ID0PDIF3_Health_q,Qual);





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


				IedServer_updateQuality(iedServer,&iedModel_PROT_ID0PDIF1_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_ID0PDIF1_Str_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_ID0PDIF2_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_ID0PDIF2_Str_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_ID0PDIF3_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_ID0PDIF3_Str_q,0);
}


#endif
