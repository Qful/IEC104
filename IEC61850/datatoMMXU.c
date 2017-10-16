/*
 * datatoMMXU.c
 *
 *  Created on: 20.04.2017
 *      Author: sagok
 */



#include "main.h"
#include "IEC850.h"

#include "iec850.h"
#include "iec61850_server.h"

#include "datatoMMXU.h"


/*************************************************************************
 * GetRealU
 * ktn - коэффициент ТН прочитанные из таблицы уставок
 *************************************************************************/
float		GetRealU(uint16_t	Currdata, uint16_t	ktn){

float	DirOut = 0;
float	K;

	if(ktn & 1<<15){
		K = ( ((float)ktn - (float)32768)* (float)1000) /(float)256;
	} else{
		K = (float)ktn/(float)256;
	}
	DirOut = ((float)Currdata * K)/(float)256;

return	DirOut;
//return	(float)Currdata;
}
/*************************************************************************
 * GetRealP
 * ktn - коэффициент ТН 	прочитанные из таблицы уставок 0x1009(МР5ПО70)
 * Ittf- первичный ток ТТ	прочитанные из таблицы уставок 0x1001(МР5ПО70)
 *************************************************************************/
float		GetRealP(float	Currdata, uint16_t	ktn,  uint16_t	Ittf){

float	realP = 0;
float	K;

	if(ktn & 1<<15){
		K = ( ((float)ktn - (float)32768)* (float)1000) /(float)256;
	} else{
		K = (float)ktn/(float)256;
	}
	realP = (float)Currdata/65536*Ittf*K*1.25;

return	realP;
}
/*******************************************************
 * MR801
 *******************************************************/
#if defined (MR801)
#include "static_model_MR801.h"


extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
extern uint16_t   ucConfigTRMeasBuf[MB_NumbConfigTRMeas];
extern uint16_t   ucConfigTRPWRBuf[MB_NumbConfigTRPWR];


//	MMXU1  MB_bOffsetModule4
//	MMXU2  MB_bOffsetModule4
//	MMXU3  MB_bOffsetModule5
//	MMXU4  MB_bOffsetModule5

/*******************************************************
 * Set_MMXU наполняем оперативными данными
 *******************************************************/
void	Set_MMXU	(uint8_t num, uint64_t currentTime )
{
	uint32_t	Health = STVALINT32_OK;

	// Health

//				if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule4) || (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5)) {Health = STVALINT32_Warning;}
//				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_MMXU1_Health_stVal, Health))
//				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_MMXU1_Health_t, currentTime);

		if (ucMDiscInBuf[MB_offset_errorM4] & MB_bOffsetModule4) {Health = STVALINT32_Warning;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_MMXU1_Health_stVal, Health))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_MMXU1_Health_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_MMXU2_Health_stVal, Health))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_MMXU2_Health_t, currentTime);

		Health = STVALINT32_OK;

		if (ucMDiscInBuf[MB_offset_errorM5] & MB_bOffsetModule5) {Health = STVALINT32_Warning;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_MMXU3_Health_stVal, Health))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_MMXU3_Health_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_MMXU4_Health_stVal, Health))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_MMXU4_Health_t, currentTime);


/*************************************************************************
 * 4 аналоговый модуль модуль
 *************************************************************************/
		if (ucMDiscInBuf[MB_offset_errorM4] & MB_errorM4){
			// токи
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsA_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsB_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsC_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_neut_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);

			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU2_A_phsA_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU2_A_phsB_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU2_A_phsC_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU2_A_neut_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);

		}
		else{
			float	mag;
			float	K;

// Ток на стороне 1
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsA_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsB_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsC_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_neut_q,0);
//  Ток на стороне 2
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU2_A_phsA_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU2_A_phsB_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU2_A_phsC_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU2_A_neut_q,0);

// Ток на стороне 1
			K = 1000 * (40 * ucConfigTRPWRBuf[MB_offset_ConfigS1 + MB_offset_P_Obmotki]) / ((float)sqrt3 * 65535 * ucConfigTRPWRBuf[MB_offset_ConfigS1 + MB_offset_U_Obmotki]);
			mag = ucMAnalogInBuf[MB_offset_Is1a] * K;
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_A_phsA_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_phsA_t, currentTime);

			mag = ucMAnalogInBuf[MB_offset_Is1b] * K;
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_A_phsB_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_phsB_t, currentTime);

			mag = ucMAnalogInBuf[MB_offset_Is1c] * K;
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_A_phsC_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_phsC_t, currentTime);

			mag = ucMAnalogInBuf[MB_offset_Is1n] * K;
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_A_neut_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_neut_t, currentTime);

// Ток на стороне 2
			K = 1000 * (40 * ucConfigTRPWRBuf[MB_offset_ConfigS2 + MB_offset_P_Obmotki]) / ((float)sqrt3 * 65535 * ucConfigTRPWRBuf[MB_offset_ConfigS2 + MB_offset_U_Obmotki]);
			mag = ucMAnalogInBuf[MB_offset_Is2a] * K;
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU2_A_phsA_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU2_A_phsA_t, currentTime);

			mag = ucMAnalogInBuf[MB_offset_Is2b] * K;
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU2_A_phsB_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU2_A_phsB_t, currentTime);

			mag = ucMAnalogInBuf[MB_offset_Is2c] * K;
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU2_A_phsC_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU2_A_phsC_t, currentTime);

			mag = ucMAnalogInBuf[MB_offset_Is2n] * K;
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU2_A_neut_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU2_A_neut_t, currentTime);

		}




/*************************************************************************
 * 5 аналоговый модуль модуль
 *************************************************************************/
// токи --------------------------
		if (ucMDiscInBuf[MB_offset_errorM5] & MB_errorM5){

			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU3_A_phsA_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU3_A_phsB_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU3_A_phsC_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU3_A_neut_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);

		}else{
			float	mag;
			float	K;

//  Ток на стороне 3
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU3_A_phsA_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU3_A_phsB_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU3_A_phsC_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU3_A_neut_q,0);

// Ток на стороне 3
			K = 1000 * (40 * ucConfigTRPWRBuf[MB_offset_ConfigS3 + MB_offset_P_Obmotki]) / ((float)sqrt3 * 65535 * ucConfigTRPWRBuf[MB_offset_ConfigS3 + MB_offset_U_Obmotki]);
			mag = ucMAnalogInBuf[MB_offset_Is3a] * K;
			if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU3_A_phsA_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU3_A_phsA_t, currentTime);

			mag = ucMAnalogInBuf[MB_offset_Is3b] * K;
			if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU3_A_phsB_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU3_A_phsB_t, currentTime);

			mag = ucMAnalogInBuf[MB_offset_Is3c] * K;
			if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU3_A_phsC_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU3_A_phsC_t, currentTime);

			mag = ucMAnalogInBuf[MB_offset_Is3n] * K;
			if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU3_A_neut_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU3_A_neut_t, currentTime);

		}


// напряжения --------------------------
//MMXU1_PPV
		if (ucMDiscInBuf[MB_offset_errorM5] & MB_errorM5){
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU4_PPV_phsA_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU4_PPV_phsB_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU4_PPV_phsC_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU4_phV_phsA_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU4_phV_phsB_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU4_phV_phsC_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU4_phV_neut_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU4_Hz_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		}
		else{
			// напряжения
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU4_PPV_phsA_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU4_PPV_phsB_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU4_PPV_phsC_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU4_phV_phsA_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU4_phV_phsB_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU4_phV_phsC_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU4_phV_neut_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU4_Hz_q,0);

			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU4_PPV_phsA_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_Uab],ucConfigTRMeasBuf[MB_offset_KTHL])))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU4_PPV_phsA_t, currentTime);

			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU4_PPV_phsB_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_Ubc],ucConfigTRMeasBuf[MB_offset_KTHL])))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU4_PPV_phsB_t, currentTime);

			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU4_PPV_phsC_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_Ucd],ucConfigTRMeasBuf[MB_offset_KTHL])))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU4_PPV_phsC_t, currentTime);

			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU4_phV_phsA_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_Ua],ucConfigTRMeasBuf[MB_offset_KTHL])))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU4_phV_phsA_t, currentTime);

			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU4_phV_phsB_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_Ub],ucConfigTRMeasBuf[MB_offset_KTHL])))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU4_phV_phsB_t, currentTime);

			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU4_phV_phsC_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_Uc],ucConfigTRMeasBuf[MB_offset_KTHL])))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU4_phV_phsC_t, currentTime);

			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU4_phV_neut_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_Un],ucConfigTRMeasBuf[MB_offset_KTHX])))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU4_phV_neut_t, currentTime);


			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU4_Hz_mag_f,(float)ucMAnalogInBuf[MB_offset_Hz]/256))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU4_Hz_t, currentTime);

		}



/*
	    //мощность ----------------------------------------------------
		if ((ucMDiscInBuf[MB_offset_errorM5] & MB_errorM5)){

			IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_totW_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_totVAr_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_totPF_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		}else{
			IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_totW_q,0);
			IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_totVAr_q,0);
			IedServer_updateQuality(iedServer,IEDMODEL_MES_MMXU1_totPF_q,0);



			float 	totW = (float)(int32_t)(((uint32_t)ucMAnalogInBuf[MB_offset_TotW+1]<<16) + (uint32_t)ucMAnalogInBuf[MB_offset_TotW]);
			float 	TotVAr = (float)(int32_t)(((uint32_t)ucMAnalogInBuf[MB_offset_TotVAr+1]<<16) + (uint32_t)ucMAnalogInBuf[MB_offset_TotVAr]);

			IedServer_updateFloatAttributeValue(iedServer,IEDMODEL_MES_MMXU1_totW_mag_f,GetRealP(totW,ucMConfigBufTrans[MB_offset_Ktnf],ucMConfigBufTrans[MB_offset_Kttf]));
			IedServer_updateFloatAttributeValue(iedServer,IEDMODEL_MES_MMXU1_totVAr_mag_f,GetRealP(TotVAr,ucMConfigBufTrans[MB_offset_Ktnf],ucMConfigBufTrans[MB_offset_Kttf]));
			IedServer_updateFloatAttributeValue(iedServer,IEDMODEL_MES_MMXU1_totPF_mag_f,(float)(int16_t)ucMAnalogInBuf[MB_offset_TotPF]/256);

		}
	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_MMXU1_totW_t, currentTime);
	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_MMXU1_totVAr_t, currentTime);
	    IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_MES_MMXU1_totPF_t, currentTime);
*/
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
extern uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
extern uint16_t   ucMUstavkiInBuf[MB_NumbUstavki];

//	MMXU1  MB_bOffsetModule4
//	MMXU2  MB_bOffsetModule4
//	MMXU3  MB_bOffsetModule5
//	MMXU4  MB_bOffsetModule5

/*******************************************************
 * Set_MMXU наполняем оперативными данными
 *******************************************************/
void	Set_MMXU	(uint8_t num, uint64_t currentTime )
{
	uint32_t	Health = STVALINT32_OK;

	// Health

//				if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule4) || (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5)) {Health = STVALINT32_Warning;}
//				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_MMXU1_Health_stVal, Health))
//				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_MMXU1_Health_t, currentTime);

		if (ucMDiscInBuf[MB_offset_errorM5] & MB_bOffsetModule5) {Health = STVALINT32_Warning;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_MMXU1_Health_stVal, Health))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_MMXU1_Health_t, currentTime);



/*************************************************************************
 * 5 аналоговый модуль модуль
 *************************************************************************/
		if (ucMDiscInBuf[MB_offset_errorM5] & MB_bOffsetModule5){
			// токи
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsA_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsB_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsC_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
#if !defined	(MR763)
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_neut_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
#endif
#if defined	(MR762)
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_neut1_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
#endif
		}
		else{
			float	mag;
			float	K;

// Ток на стороне 1
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsA_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsB_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsC_q,0);
#if !defined	(MR763)
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_neut_q,0);
#endif
#if defined	(MR762)
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_neut1_q,0);
#endif
// Ток на стороне 1
			K = (40 * (float)ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Kttf]) /  65535;
			mag = (float)ucMAnalogInBuf[MB_offset_Ia] * K;
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_A_phsA_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_phsA_t, currentTime);

			mag = (float)ucMAnalogInBuf[MB_offset_Ib] * K;
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_A_phsB_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_phsB_t, currentTime);

			mag = (float)ucMAnalogInBuf[MB_offset_Ic] * K;
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_A_phsC_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_phsC_t, currentTime);

#if !defined	(MR763)
			K = (40 * (float)ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Kttn]) /  65535;
			mag = (float)ucMAnalogInBuf[MB_offset_In] * K;
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_A_neut_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_neut_t, currentTime);
#endif
#if defined	(MR762)
			K = (40 * (float)ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Kttn]) /  65535;
			mag = (float)ucMAnalogInBuf[MB_offset_In1] * K;
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_A_neut1_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_neut1_t, currentTime);

#endif
		}

/*************************************************************************
 * 5 аналоговый модуль модуль
 *************************************************************************/
// напряжения --------------------------
//MMXU1_phV
		if (ucMDiscInBuf[MB_offset_errorM5] & MB_bOffsetModule5){
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_PPV_phsA_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_PPV_phsB_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_PPV_phsC_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_phsA_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_phsB_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_phsC_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
#if !defined	(MR762)
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_neut_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
#endif
#if defined	(MR763)
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_neut1_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
#endif
#if defined	(MR771)
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_neut1_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
#endif
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_Hz_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		}
		else{
			// напряжения
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_PPV_phsA_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_PPV_phsB_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_PPV_phsC_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_phsA_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_phsB_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_phsC_q,0);
#if !defined	(MR762)
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_neut_q,0);
#endif
#if defined	(MR763)
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_neut1_q,0);
#endif
#if defined	(MR771)
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_neut1_q,0);
#endif
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_Hz_q,0);

			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsA_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_Uab],ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Ktnf])))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_PPV_phsA_t, currentTime);

			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsB_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_Ubc],ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Ktnf])))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_PPV_phsB_t, currentTime);

			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsC_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_Ucd],ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Ktnf])))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_PPV_phsC_t, currentTime);

			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsA_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_Ua],ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Ktnf])))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_phV_phsA_t, currentTime);

			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsB_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_Ub],ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Ktnf])))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_phV_phsB_t, currentTime);

			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsC_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_Uc],ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Ktnf])))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_phV_phsC_t, currentTime);
#if !defined	(MR762)
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_neut_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_Un],ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Ktnnp])))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_phV_neut_t, currentTime);
#endif
#if defined	(MR763)
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_neut1_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_Un1],ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Ktnnp])))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_phV_neut1_t, currentTime);
#endif
#if defined	(MR771)
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_neut1_cVal_mag_f,GetRealU(ucMAnalogInBuf[MB_offset_Un1],ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Ktnnp1])))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_phV_neut1_t, currentTime);
#endif
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_Hz_mag_f,(float)ucMAnalogInBuf[MB_offset_Hz]/256))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_Hz_t, currentTime);
		}

	    //мощность ----------------------------------------------------
		if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffsetModule5)){

			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_totW_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_totVAr_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_totPF_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		}else{
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_totW_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_totVAr_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_totPF_q,0);

			float 	totW = (float)(int32_t)(((uint32_t)ucMAnalogInBuf[MB_offset_TotW+1]<<16) + (uint32_t)ucMAnalogInBuf[MB_offset_TotW]);
			float 	TotVAr = (float)(int32_t)(((uint32_t)ucMAnalogInBuf[MB_offset_TotVAr+1]<<16) + (uint32_t)ucMAnalogInBuf[MB_offset_TotVAr]);

			if(IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totW_mag_f,GetRealP(totW,ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Ktnf],ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Kttf])))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_totW_t, currentTime);

		    if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totVAr_mag_f,GetRealP(TotVAr,ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Ktnf],ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Kttf])))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_totVAr_t, currentTime);

		    if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totPF_mag_f,(float)(int16_t)ucMAnalogInBuf[MB_offset_TotPF]/256))
		    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_totPF_t, currentTime);
		}
}
#endif

/*******************************************************
 * MR901 MR902
 *******************************************************/
#if defined	(MR901) || defined	(MR902)

#include "static_model_MR901_902.h"


extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
extern uint16_t   ucMUstavkiInBuf[MB_NumbUstavki];
extern uint16_t   ucOtherUstavkiInBuf[MB_NumbOtherUstavki];

//	MMXU1  MB_bOffsetModule4
//	MMXU2  MB_bOffsetModule4
//	MMXU3  MB_bOffsetModule5
//	MMXU4  MB_bOffsetModule5

#if defined	(MR901)
/*******************************************************
 * Set_MMXN наполняем оперативными данными
 *******************************************************/
void	Set_MMXN	(uint8_t num, uint64_t currentTime )
{
	uint32_t	Health = STVALINT32_OK;
	float	mag,K;

	// Health
		if (ucMDiscInBuf[MB_offset_errorM5] & MB_bOffsetModule5) {Health = STVALINT32_Warning;}
		if (ucMDiscInBuf[MB_offset_errorM4] & MB_bOffsetModule4) {Health = STVALINT32_Warning;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_MMXN1_Health_stVal, Health))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_MMXN1_Health_t, currentTime);


/*************************************************************************
 * 4 аналоговый модуль модуль
 *************************************************************************/
		if (ucMDiscInBuf[MB_offset_errorM4] & MB_bOffsetModule4){

			IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp1_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp2_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp3_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp4_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp5_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp6_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp7_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp8_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		} else{
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp1_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp2_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp3_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp4_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp5_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp6_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp7_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp8_q,0);
		}


		mag = (float)ucMAnalogInBuf[MB_offset_I1] * (float)40 * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris1 + MB_offset_KTT] / (float)65535;
		if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXN1_Amp1_mag_f,mag))
		  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp1_t, currentTime);

		mag = (float)ucMAnalogInBuf[MB_offset_I2] * (float)40 * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris2 + MB_offset_KTT] / (float)65535;
		if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXN1_Amp2_mag_f,mag))
		  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp2_t, currentTime);

		mag = (float)ucMAnalogInBuf[MB_offset_I3] * (float)40 * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris3 + MB_offset_KTT] / (float)65535;
//		mag = (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris1 + MB_offset_KTT];

		if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXN1_Amp3_mag_f,mag))
		  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp3_t, currentTime);

		mag = (float)ucMAnalogInBuf[MB_offset_I4] * (float)40 * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris4 + MB_offset_KTT] / (float)65535;
		if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXN1_Amp4_mag_f,mag))
		  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp4_t, currentTime);

		mag = (float)ucMAnalogInBuf[MB_offset_I5] * (float)40 * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris5 + MB_offset_KTT] / (float)65535;
		if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXN1_Amp5_mag_f,mag))
		  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp5_t, currentTime);

		mag = (float)ucMAnalogInBuf[MB_offset_I6] * (float)40 * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris6 + MB_offset_KTT] / (float)65535;
		if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXN1_Amp6_mag_f,mag))
		  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp6_t, currentTime);

		mag = (float)ucMAnalogInBuf[MB_offset_I7] * (float)40 * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris7 + MB_offset_KTT] / (float)65535;
		if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXN1_Amp7_mag_f,mag))
		  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp7_t, currentTime);

		mag = (float)ucMAnalogInBuf[MB_offset_I8] * (float)40 * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris8 + MB_offset_KTT] / (float)65535;
		if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXN1_Amp8_mag_f,mag))
		  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp8_t, currentTime);


/*************************************************************************
 * 5 аналоговый модуль модуль
 *************************************************************************/
		if (ucMDiscInBuf[MB_offset_errorM5] & MB_bOffsetModule5){

			IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp9_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp10_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp11_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp12_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp13_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp14_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp15_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp16_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		}else{
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp9_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp10_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp11_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp12_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp13_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp14_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp15_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp16_q,0);
		}

		mag = (float)ucMAnalogInBuf[MB_offset_I9] * (float)40 * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris9 + MB_offset_KTT] / (float)65535;
		if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXN1_Amp9_mag_f,mag))
		  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp9_t, currentTime);

		mag = (float)ucMAnalogInBuf[MB_offset_I10] * (float)40 * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris10 + MB_offset_KTT] / (float)65535;
		if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXN1_Amp10_mag_f,mag))
		  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp10_t, currentTime);

		mag = (float)ucMAnalogInBuf[MB_offset_I11] * (float)40 * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris11 + MB_offset_KTT] / (float)65535;
		if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXN1_Amp11_mag_f,mag))
		  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp11_t, currentTime);

		mag = (float)ucMAnalogInBuf[MB_offset_I12] * (float)40 * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris12 + MB_offset_KTT] / (float)65535;
		if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXN1_Amp12_mag_f,mag))
		  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp12_t, currentTime);

		mag = (float)ucMAnalogInBuf[MB_offset_I13] * (float)40 * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris13 + MB_offset_KTT] / (float)65535;
		if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXN1_Amp13_mag_f,mag))
		  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp13_t, currentTime);

		mag = (float)ucMAnalogInBuf[MB_offset_I14] * (float)40 * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris14 + MB_offset_KTT] / (float)65535;
		if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXN1_Amp14_mag_f,mag))
		  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp14_t, currentTime);

		mag = (float)ucMAnalogInBuf[MB_offset_I15] * (float)40 * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris15 + MB_offset_KTT] / (float)65535;
		if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXN1_Amp15_mag_f,mag))
		  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp15_t, currentTime);

		mag = (float)ucMAnalogInBuf[MB_offset_I16] * (float)40 * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris16 + MB_offset_KTT] / (float)65535;
		if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXN1_Amp16_mag_f,mag))
		  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp16_t, currentTime);
}
#endif

#if defined	(MR902)
/*******************************************************
 * Set_MMXU наполняем оперативными данными
 *******************************************************/
void	Set_MMXU	(uint8_t num, uint64_t currentTime )
{
	uint32_t	Health = STVALINT32_OK;
	float	mag,K;

	// Health
		if (ucMDiscInBuf[MB_offset_errorM5] & MB_bOffsetModule5) {Health = STVALINT32_Warning;}
		if (ucMDiscInBuf[MB_offset_errorM4] & MB_bOffsetModule4) {Health = STVALINT32_Warning;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_MMXU1_Health_stVal, Health))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_MMXU1_Health_t, currentTime);

		if (ucMDiscInBuf[MB_offset_errorM4] & MB_bOffsetModule4){

			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsA_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsB_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsC_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);

			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU2_A_phsA_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU2_A_phsB_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU2_A_phsC_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);

			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU3_A_phsA_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU3_A_phsB_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);

		} else{
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsA_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsB_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsC_q,0);

			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU2_A_phsA_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU2_A_phsB_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU2_A_phsC_q,0);

			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU3_A_phsA_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU3_A_phsB_q,0);
		}
		if (ucMDiscInBuf[MB_offset_errorM5] & MB_bOffsetModule5){

			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU3_A_phsC_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);

			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU4_A_phsA_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU4_A_phsB_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU4_A_phsC_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);

			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU5_A_phsA_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU5_A_phsB_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU5_A_phsC_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);

			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU6_A_In_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);

		} else{
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU3_A_phsC_q,0);

			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU4_A_phsA_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU4_A_phsB_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU4_A_phsC_q,0);

			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU5_A_phsA_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU5_A_phsB_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU5_A_phsC_q,0);

			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU6_A_In_q,0);
		}


/*************************************************************************
 * 4 аналоговый модуль модуль
 *************************************************************************/

			K = ((float)40 * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris1 + MB_offset_KTT]) /  (float)65535;
			mag = (float)ucMAnalogInBuf[MB_offset_I1a] * K;
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_A_phsA_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_phsA_t, currentTime);

			mag = (float)ucMAnalogInBuf[MB_offset_I1b] * K;
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_A_phsB_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_phsB_t, currentTime);
			mag = (float)ucMAnalogInBuf[MB_offset_I1c] * K;
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_A_phsC_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_phsC_t, currentTime);

			K = ((float)40 * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris2 + MB_offset_KTT]) /  (float)65535;
			mag = (float)ucMAnalogInBuf[MB_offset_I2a] * K;
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU2_A_phsA_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU2_A_phsA_t, currentTime);
			mag = (float)ucMAnalogInBuf[MB_offset_I2b] * K;
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU2_A_phsB_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU2_A_phsB_t, currentTime);
			mag = (float)ucMAnalogInBuf[MB_offset_I2c] * K;
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU2_A_phsC_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU2_A_phsC_t, currentTime);

			K = ((float)40 * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris3 + MB_offset_KTT]) /  (float)65535;
			mag = (float)ucMAnalogInBuf[MB_offset_I3a] * K;
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU3_A_phsA_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU3_A_phsA_t, currentTime);
			mag = (float)ucMAnalogInBuf[MB_offset_I3b] * K;
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU3_A_phsB_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU3_A_phsB_t, currentTime);
			mag = (float)ucMAnalogInBuf[MB_offset_I3c] * K;
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU3_A_phsC_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU3_A_phsC_t, currentTime);

			K = ((float)40 * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris4 + MB_offset_KTT]) /  (float)65535;
			mag = (float)ucMAnalogInBuf[MB_offset_I4a] * K;
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU4_A_phsA_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU4_A_phsA_t, currentTime);
			mag = (float)ucMAnalogInBuf[MB_offset_I4b] * K;
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU4_A_phsB_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU4_A_phsB_t, currentTime);
			mag = (float)ucMAnalogInBuf[MB_offset_I4c] * K;
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU4_A_phsC_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU4_A_phsC_t, currentTime);

			K = ((float)40 * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris5 + MB_offset_KTT]) /  (float)65535;
			mag = (float)ucMAnalogInBuf[MB_offset_I5a] * K;
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU5_A_phsA_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU5_A_phsA_t, currentTime);
			mag = (float)ucMAnalogInBuf[MB_offset_I5b] * K;
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU5_A_phsB_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU5_A_phsB_t, currentTime);
			mag = (float)ucMAnalogInBuf[MB_offset_I5c] * K;
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU5_A_phsC_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU5_A_phsC_t, currentTime);

			K = ((float)40 * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris6 + MB_offset_KTT]) /  (float)65535;
			mag = (float)ucMAnalogInBuf[MB_offset_In] * K;
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU6_A_In_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU6_A_In_t, currentTime);

/*************************************************************************
 *
 *************************************************************************/
}
#endif
#endif

/*******************************************************
 * MR5_700
 *******************************************************/
#if defined	(MR5_700) || defined	(MR5_500)

#if defined	(MR5_700)
#include "static_model_MR5_700.h"
#endif

#if defined	(MR5_500)
#include "static_model_MR5_500.h"
#endif

extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
extern uint16_t   ucUstavkiInBuf[MB_NumbUstavki];

//	MMXU1  MB_bOffsetModule4
//	MMXU2  MB_bOffsetModule4
//	MMXU3  MB_bOffsetModule5
//	MMXU4  MB_bOffsetModule5

/*******************************************************
 * Set_MMXU наполняем оперативными данными
 *******************************************************/
void	Set_MMXU	(uint8_t num, uint64_t currentTime )
{
	float	mag,premag,level,dbLevel=0,zeroDbLevel=0;
	float	K;

	uint32_t	Health = STVALINT32_OK;


		if (ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1) {Health = STVALINT32_Warning;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_MMXU1_Health_stVal, Health))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_MMXU1_Health_t, currentTime);

/*************************************************************************
 * аналоговый токовый модуль
 *************************************************************************/
		if (ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1b)
		//if (0)
		{
			// токи
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsA_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsB_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsC_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_neut_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		}
		else{
// Ток
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsA_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsB_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsC_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_neut_q,0);

			// диапазон.
			// Lim I  40 * Itt
			// Lim I0 40 * Iн *Itt
			// Lim In 5 * Iн *Ittn
			K = (float)range_maxIphs * (float)ucUstavkiInBuf[MB_offset_Itt]/(float)65535;

	// phsA
			dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_A_phsA_db)*(float)range_maxIphs * (float)ucUstavkiInBuf[MB_offset_Itt] /(float)DbPercent;
			zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_A_phsA_zeroDb)*(float)range_maxIphs * (float)ucUstavkiInBuf[MB_offset_Itt]  / (float)DbPercent;
			mag = (float)ucMAnalogInBuf[MB_offset_Ia] * K;
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_A_phsA_instCVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_phsA_t, currentTime);

			premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_A_phsA_cVal_mag_f);
			if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}
			if (level > dbLevel) {
				if (mag<zeroDbLevel) mag = 0;
				IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_A_phsA_cVal_mag_f,mag);
			}else{
				if (mag<zeroDbLevel) IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_A_phsA_cVal_mag_f,0);
			}


	// phsB
			dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_A_phsB_db)*(float)range_maxIphs * (float)ucUstavkiInBuf[MB_offset_Itt]  / (float)DbPercent;
			zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_A_phsB_zeroDb)*(float)range_maxIphs * (float)ucUstavkiInBuf[MB_offset_Itt]  / (float)DbPercent;
			mag = (float)ucMAnalogInBuf[MB_offset_Ib] * K;
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_A_phsB_instCVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_phsB_t, currentTime);

			premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_A_phsB_cVal_mag_f);
			if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}
			if (level > dbLevel) {
				if (mag<zeroDbLevel) mag = 0;
				IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_A_phsB_cVal_mag_f,mag);
			}else{
				if (mag<zeroDbLevel) IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_A_phsB_cVal_mag_f,0);
			}

	// phsC
			dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_A_phsC_db)*(float)range_maxIphs * (float)ucUstavkiInBuf[MB_offset_Itt]  / (float)DbPercent;
			zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_A_phsC_zeroDb)*(float)range_maxIphs * (float)ucUstavkiInBuf[MB_offset_Itt]  / (float)DbPercent;
			mag = (float)ucMAnalogInBuf[MB_offset_Ic] * K;
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_A_phsC_instCVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_phsC_t, currentTime);

			premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_A_phsC_cVal_mag_f);
			if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}
			if (level > dbLevel) {
				if (mag<zeroDbLevel) mag = 0;
				IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_A_phsC_cVal_mag_f,mag);
			}else{
				if (mag<zeroDbLevel) IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_A_phsC_cVal_mag_f,0);
			}

	// n

			dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_A_neut_db)*(float)range_maxIn * (float)ucUstavkiInBuf[MB_offset_Ittnp]  / (float)DbPercent;
			zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_A_neut_zeroDb)*(float)range_maxIn * (float)ucUstavkiInBuf[MB_offset_Ittnp]  / (float)DbPercent;

			K = (float)range_maxIn * (float)ucUstavkiInBuf[MB_offset_Ittnp]/(float)65535;
			mag = (float)ucMAnalogInBuf[MB_offset_In] * K;
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_A_neut_instCVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_neut_t, currentTime);

			premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_A_neut_cVal_mag_f);
			if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}
			if (level > dbLevel) {
				if (mag<zeroDbLevel) mag = 0;
				IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_A_neut_cVal_mag_f,mag);
			}else{
				if (mag<zeroDbLevel) IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_A_neut_cVal_mag_f,0);
			}

		}
#if defined	(MR5_700)
/*************************************************************************
 * аналоговый модуль напряжения
 *************************************************************************/
		if (ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1a){
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_PPV_phsA_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_PPV_phsB_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_PPV_phsC_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_phsA_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_phsB_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_phsC_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_neut_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_Hz_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		}
		else{
// напряжения
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_PPV_phsA_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_PPV_phsB_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_PPV_phsC_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_phsA_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_phsB_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_phsC_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_neut_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_Hz_q,0);

	// Uab
			dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsA_db)*(float)range_maxU * GetRealU(256,ucUstavkiInBuf[MB_offset_Ktn])  / (float)DbPercent;
			zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsA_zeroDb)*(float)range_maxU * GetRealU(256,ucUstavkiInBuf[MB_offset_Ktn])  / (float)DbPercent;
			mag = GetRealU(ucMAnalogInBuf[MB_offset_Uab],ucUstavkiInBuf[MB_offset_Ktn]);
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsA_instCVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_PPV_phsA_t, currentTime);

			premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsA_cVal_mag_f);
			if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}
			if (level > dbLevel) {
				if (mag<zeroDbLevel) mag = 0;
				IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsA_cVal_mag_f,mag);
			}else{
				if (mag<zeroDbLevel) IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsA_cVal_mag_f,0);
			}

	// Ubc
			dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsB_db)*(float)range_maxU * GetRealU(256,ucUstavkiInBuf[MB_offset_Ktn])  / (float)DbPercent;
			zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsB_zeroDb)*(float)range_maxU * GetRealU(256,ucUstavkiInBuf[MB_offset_Ktn])  / (float)DbPercent;
			mag = GetRealU(ucMAnalogInBuf[MB_offset_Ubc],ucUstavkiInBuf[MB_offset_Ktn]);
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsB_instCVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_PPV_phsB_t, currentTime);

			premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsB_cVal_mag_f);
			if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}
			if (level > dbLevel) {
				if (mag<zeroDbLevel) mag = 0;
				IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsB_cVal_mag_f,mag);
			}else{
				if (mag<zeroDbLevel) IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsB_cVal_mag_f,0);
			}

	// Uca
			dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsC_db)*(float)range_maxU * GetRealU(256,ucUstavkiInBuf[MB_offset_Ktn]) / (float)DbPercent;
			zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsC_zeroDb)*(float)range_maxU * GetRealU(256,ucUstavkiInBuf[MB_offset_Ktn])  / (float)DbPercent;
			mag = GetRealU(ucMAnalogInBuf[MB_offset_Uca],ucUstavkiInBuf[MB_offset_Ktn]);
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsC_instCVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_PPV_phsC_t, currentTime);

			premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsC_cVal_mag_f);
			if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}
			if (level > dbLevel) {
				if (mag<zeroDbLevel) mag = 0;
				IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsC_cVal_mag_f,mag);
			}else{
				if (mag<zeroDbLevel) IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsC_cVal_mag_f,0);
			}

	// Ua
			dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsA_db)*(float)range_maxU * GetRealU(256,ucUstavkiInBuf[MB_offset_Ktn])  / (float)DbPercent;
			zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsA_zeroDb)*(float)range_maxU * GetRealU(256,ucUstavkiInBuf[MB_offset_Ktn])  / (float)DbPercent;
			mag = GetRealU(ucMAnalogInBuf[MB_offset_Ua],ucUstavkiInBuf[MB_offset_Ktn]);
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsA_instCVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_phV_phsA_t, currentTime);

			premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsA_cVal_mag_f);
			if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}
			if (level > dbLevel) {
				if (mag<zeroDbLevel) mag = 0;
				IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsA_cVal_mag_f,mag);
			}else{
				if (mag<zeroDbLevel) IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsA_cVal_mag_f,0);
			}

	// Ub
			dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsB_db)*(float)range_maxU * GetRealU(256,ucUstavkiInBuf[MB_offset_Ktn])  / (float)DbPercent;
			zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsB_zeroDb)*(float)range_maxU * GetRealU(256,ucUstavkiInBuf[MB_offset_Ktn]) / (float)DbPercent;
			mag = GetRealU(ucMAnalogInBuf[MB_offset_Ub],ucUstavkiInBuf[MB_offset_Ktn]);
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsB_instCVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_phV_phsB_t, currentTime);

			premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsB_cVal_mag_f);
			if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}
			if (level > dbLevel) {
				if (mag<zeroDbLevel) mag = 0;
				IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsB_cVal_mag_f,mag);
			}else{
				if (mag<zeroDbLevel) IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsB_cVal_mag_f,0);
			}

	// Uc
			dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsC_db)*(float)range_maxU * GetRealU(256,ucUstavkiInBuf[MB_offset_Ktn])  / (float)DbPercent;
			zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsC_zeroDb)*(float)range_maxU * GetRealU(256,ucUstavkiInBuf[MB_offset_Ktn])  / (float)DbPercent;
			mag = GetRealU(ucMAnalogInBuf[MB_offset_Uc],ucUstavkiInBuf[MB_offset_Ktn]);
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsC_instCVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_phV_phsC_t, currentTime);

			premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsC_cVal_mag_f);
			if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}
			if (level > dbLevel) {
				if (mag<zeroDbLevel) mag = 0;
				IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsC_cVal_mag_f,mag);
			}else{
				if (mag<zeroDbLevel) IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsC_cVal_mag_f,0);
			}

	// Un
			//dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_phV_neut_db)*(float)(range_maxU-range_minU)/256 * (float)ucUstavkiInBuf[MB_offset_Ktn]   / (float)DbPercent;
			//zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_phV_neut_zeroDb)*(float)(range_maxU-range_minU)/256 * (float)ucUstavkiInBuf[MB_offset_Ktn]    / (float)DbPercent;

			dbLevel 	= 256*256*GetRealU(IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_phV_neut_db),ucUstavkiInBuf[MB_offset_Ktnnp]) / (float)DbPercent;
			zeroDbLevel = 256*256*GetRealU(IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_phV_neut_zeroDb),ucUstavkiInBuf[MB_offset_Ktnnp]) / (float)DbPercent;;


			mag = GetRealU(ucMAnalogInBuf[MB_offset_Un],ucUstavkiInBuf[MB_offset_Ktnnp]);
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_neut_instCVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_phV_neut_t, currentTime);

			premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_neut_cVal_mag_f);
			if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}
			if (level > dbLevel) {
				if (mag<zeroDbLevel) mag = 0;
				IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_neut_cVal_mag_f,mag);
			}else{
				if (mag<zeroDbLevel) IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_neut_cVal_mag_f,0);
			}

// частота
			dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_Hz_db)*(float)(range_maxF-range_minF) / (float)DbPercent;
			zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_Hz_zeroDb)*(float)(range_maxF-range_minF) / (float)DbPercent;
			mag = (float)ucMAnalogInBuf[MB_offset_Hz]/256;
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_Hz_instMag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_Hz_t, currentTime);

			premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_Hz_mag_f);
			if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}

			if ( (mag > (50 - zeroDbLevel)) && (mag < (50 + zeroDbLevel))) mag = 50;

			if (level > dbLevel) {
				IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_Hz_mag_f,mag);
			}else{
				if (mag == 50) IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_Hz_mag_f, 50);
			}

		}

//мощность ----------------------------------------------------
		// диапазон - 40*5*256*ki*Ku

		if ((ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1)){
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_totW_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_totVAr_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_totPF_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		}else{
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_totW_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_totVAr_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_totPF_q,0);

	//TotW
			dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_totW_db)*(float)(256*40)/(float)1000 * GetRealU(256,ucUstavkiInBuf[MB_offset_Ktn]) * (float)ucUstavkiInBuf[MB_offset_Itt] / (float)DbPercent;
			zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_totW_zeroDb)*(float)(256*40)/(float)1000 * GetRealU(256,ucUstavkiInBuf[MB_offset_Ktn]) * (float)ucUstavkiInBuf[MB_offset_Itt] / (float)DbPercent;

			mag = (float)(ucMAnalogInBuf[MB_offset_TotW]);
			if (ucMDiscInBuf[MB_offsetPTOC] & MB_bTotWZ) {mag = -mag;}
			IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totW_instMag_f,mag);

			premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totW_mag_f);
			if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}

			if ( (mag > - zeroDbLevel) && (mag < zeroDbLevel)) mag = 0;


			if (level > dbLevel) {
				IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totW_mag_f,mag);
			}else{
				if (mag == 0) IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totW_mag_f, 0);
			}


	//TotVAr
			dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_totVAr_db)*(float)(256*40)/(float)1000 * GetRealU(256,ucUstavkiInBuf[MB_offset_Ktn]) * (float)ucUstavkiInBuf[MB_offset_Itt] / (float)DbPercent;
			zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_totVAr_zeroDb)*(float)(256*40)/(float)1000 * GetRealU(256,ucUstavkiInBuf[MB_offset_Ktn]) * (float)ucUstavkiInBuf[MB_offset_Itt] / (float)DbPercent;
			mag = (float)(ucMAnalogInBuf[MB_offset_TotVAr]);
			if (ucMDiscInBuf[MB_offsetPTOC] & MB_bTotVAZ) {mag = -mag;}
			IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totVAr_instMag_f,mag);

			premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totVAr_mag_f);
			if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}

			if ( (mag > - zeroDbLevel) && (mag < zeroDbLevel)) mag = 0;

			if (level > dbLevel) {
				IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totVAr_mag_f,mag);
			}else{
				if (mag == 0) IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totVAr_mag_f, 0);
			}

	//totPF
			dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_totPF_db)*(float)(range_maxCosF - range_minCosF) / (float)DbPercent;
			zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_totPF_zeroDb)*(float)(range_maxCosF - range_minCosF) / (float)DbPercent;
			mag = (float)ucMAnalogInBuf[MB_offset_TotPF]/256;
			IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totPF_instMag_f,mag);

			premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totPF_mag_f);
			if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}
			if (level > dbLevel) {
				if (mag < zeroDbLevel) mag = 0;
				IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totPF_mag_f,mag);
			}else{
				if (mag<zeroDbLevel) IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totPF_mag_f, 0);
			}

		}
#endif
}
#endif

/*******************************************************
 * MR5_600
 *******************************************************/
#if defined	(MR5_600)

#include "static_model_MR5_600.h"


extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
extern uint16_t   ucUstavkiInBuf[MB_NumbUstavki];

//	MMXU1  MB_bOffsetModule4
//	MMXU2  MB_bOffsetModule4
//	MMXU3  MB_bOffsetModule5
//	MMXU4  MB_bOffsetModule5

/*******************************************************
 * Set_MMXU наполняем оперативными данными
 *******************************************************/
void	Set_MMXU	(uint8_t num, uint64_t currentTime )
{
	float	mag,premag,level,dbLevel=0,zeroDbLevel=0;
	float	K;

	uint32_t	Health = STVALINT32_OK;


		if (ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1) {Health = STVALINT32_Warning;}
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_MMXU1_Health_stVal, Health))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_MMXU1_Health_t, currentTime);


/*************************************************************************
 * аналоговый модуль напряжения
 *************************************************************************/

		if (ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1a){
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_PPV_phsA_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_PPV_phsB_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_PPV_phsC_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_phsA_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_phsB_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_phsC_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_neut_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_Hz_q,QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE);
		}
		else{
// напряжения
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_PPV_phsA_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_PPV_phsB_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_PPV_phsC_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_phsA_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_phsB_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_phsC_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_neut_q,0);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_Hz_q,0);

	// Uab
			dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsA_db)*(float)range_maxU * GetRealU(256,ucUstavkiInBuf[MB_offset_Ktn])  / (float)DbPercent;
			zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsA_zeroDb)*(float)range_maxU * GetRealU(256,ucUstavkiInBuf[MB_offset_Ktn])  / (float)DbPercent;
			mag = GetRealU(ucMAnalogInBuf[MB_offset_Uab],ucUstavkiInBuf[MB_offset_Ktn]);
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsA_instCVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_PPV_phsA_t, currentTime);

			premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsA_cVal_mag_f);
			if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}
			if (level > dbLevel) {
				if (mag<zeroDbLevel) mag = 0;
				IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsA_cVal_mag_f,mag);
			}else{
				if (mag<zeroDbLevel) IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsA_cVal_mag_f,0);
			}

	// Ubc
			dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsB_db)*(float)range_maxU * GetRealU(256,ucUstavkiInBuf[MB_offset_Ktn])  / (float)DbPercent;
			zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsB_zeroDb)*(float)range_maxU * GetRealU(256,ucUstavkiInBuf[MB_offset_Ktn])  / (float)DbPercent;
			mag = GetRealU(ucMAnalogInBuf[MB_offset_Ubc],ucUstavkiInBuf[MB_offset_Ktn]);
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsB_instCVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_PPV_phsB_t, currentTime);

			premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsB_cVal_mag_f);
			if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}
			if (level > dbLevel) {
				if (mag<zeroDbLevel) mag = 0;
				IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsB_cVal_mag_f,mag);
			}else{
				if (mag<zeroDbLevel) IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsB_cVal_mag_f,0);
			}

	// Uca
			dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsC_db)*(float)range_maxU * GetRealU(256,ucUstavkiInBuf[MB_offset_Ktn]) / (float)DbPercent;
			zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsC_zeroDb)*(float)range_maxU * GetRealU(256,ucUstavkiInBuf[MB_offset_Ktn])  / (float)DbPercent;
			mag = GetRealU(ucMAnalogInBuf[MB_offset_Uca],ucUstavkiInBuf[MB_offset_Ktn]);
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsC_instCVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_PPV_phsC_t, currentTime);

			premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsC_cVal_mag_f);
			if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}
			if (level > dbLevel) {
				if (mag<zeroDbLevel) mag = 0;
				IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsC_cVal_mag_f,mag);
			}else{
				if (mag<zeroDbLevel) IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_PPV_phsC_cVal_mag_f,0);
			}

	// Ua
			dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsA_db)*(float)range_maxU * GetRealU(256,ucUstavkiInBuf[MB_offset_Ktn])  / (float)DbPercent;
			zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsA_zeroDb)*(float)range_maxU * GetRealU(256,ucUstavkiInBuf[MB_offset_Ktn])  / (float)DbPercent;
			mag = GetRealU(ucMAnalogInBuf[MB_offset_Ua],ucUstavkiInBuf[MB_offset_Ktn]);
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsA_instCVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_phV_phsA_t, currentTime);

			premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsA_cVal_mag_f);
			if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}
			if (level > dbLevel) {
				if (mag<zeroDbLevel) mag = 0;
				IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsA_cVal_mag_f,mag);
			}else{
				if (mag<zeroDbLevel) IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsA_cVal_mag_f,0);
			}

	// Ub
			dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsB_db)*(float)range_maxU * GetRealU(256,ucUstavkiInBuf[MB_offset_Ktn])  / (float)DbPercent;
			zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsB_zeroDb)*(float)range_maxU * GetRealU(256,ucUstavkiInBuf[MB_offset_Ktn]) / (float)DbPercent;
			mag = GetRealU(ucMAnalogInBuf[MB_offset_Ub],ucUstavkiInBuf[MB_offset_Ktn]);
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsB_instCVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_phV_phsB_t, currentTime);

			premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsB_cVal_mag_f);
			if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}
			if (level > dbLevel) {
				if (mag<zeroDbLevel) mag = 0;
				IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsB_cVal_mag_f,mag);
			}else{
				if (mag<zeroDbLevel) IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsB_cVal_mag_f,0);
			}

	// Uc
			dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsC_db)*(float)range_maxU * GetRealU(256,ucUstavkiInBuf[MB_offset_Ktn])  / (float)DbPercent;
			zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsC_zeroDb)*(float)range_maxU * GetRealU(256,ucUstavkiInBuf[MB_offset_Ktn])  / (float)DbPercent;
			mag = GetRealU(ucMAnalogInBuf[MB_offset_Uc],ucUstavkiInBuf[MB_offset_Ktn]);
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsC_instCVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_phV_phsC_t, currentTime);

			premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsC_cVal_mag_f);
			if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}
			if (level > dbLevel) {
				if (mag<zeroDbLevel) mag = 0;
				IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsC_cVal_mag_f,mag);
			}else{
				if (mag<zeroDbLevel) IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_phsC_cVal_mag_f,0);
			}

	// Un
			//dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_phV_neut_db)*(float)(range_maxU-range_minU)/256 * (float)ucUstavkiInBuf[MB_offset_Ktn]   / (float)DbPercent;
			//zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_phV_neut_zeroDb)*(float)(range_maxU-range_minU)/256 * (float)ucUstavkiInBuf[MB_offset_Ktn]    / (float)DbPercent;

			dbLevel 	= 256*256*GetRealU(IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_phV_neut_db),ucUstavkiInBuf[MB_offset_Ktnnp]) / (float)DbPercent;
			zeroDbLevel = 256*256*GetRealU(IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_phV_neut_zeroDb),ucUstavkiInBuf[MB_offset_Ktnnp]) / (float)DbPercent;;


			mag = GetRealU(ucMAnalogInBuf[MB_offset_Un],ucUstavkiInBuf[MB_offset_Ktnnp]);
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_neut_instCVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_phV_neut_t, currentTime);

			premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_neut_cVal_mag_f);
			if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}
			if (level > dbLevel) {
				if (mag<zeroDbLevel) mag = 0;
				IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_neut_cVal_mag_f,mag);
			}else{
				if (mag<zeroDbLevel) IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_phV_neut_cVal_mag_f,0);
			}

// частота
			dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_Hz_db)*(float)(range_maxF-range_minF) / (float)DbPercent;
			zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_Hz_zeroDb)*(float)(range_maxF-range_minF) / (float)DbPercent;
			mag = (float)ucMAnalogInBuf[MB_offset_Hz]/256;
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_Hz_instMag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_Hz_t, currentTime);

			premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_Hz_mag_f);
			if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}

			if ( (mag > (50 - zeroDbLevel)) && (mag < (50 + zeroDbLevel))) mag = 50;

			if (level > dbLevel) {
				IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_Hz_mag_f,mag);
			}else{
				if (mag == 50) IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_Hz_mag_f, 50);
			}

		}
}
#endif
