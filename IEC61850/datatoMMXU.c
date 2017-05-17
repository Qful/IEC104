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
