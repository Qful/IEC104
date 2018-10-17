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

#include "dataDbzeroDB.h"
/*************************************************************************
 * GetRealU
 * ktn - коэффициент ТН прочитанные из таблицы уставок
 * чтобы получить чистый коэффициент для далбнейших пересчётов без
 * привязки к данным считается: Currdata = 256
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
 * MR851
 *******************************************************/
#if defined (MR851)
#include "static_model_MR851.h"

/*******************************************************
 * заглушки
 *******************************************************/
int		Set_MMXN	(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_MMXU	(uint16_t QTnum, uint64_t currentTime ){return false;}

#endif
/*******************************************************
 * MR801
 *******************************************************/
#if defined (MR801)
#include "static_model_MR801.h"


extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
extern uint16_t   ucConfigTRMeasBuf[MB_NumbConfigTRMeas];
extern uint16_t   ucConfigTRPWRBuf[MB_NumbConfigTRPWR];


/*******************************************************
 * заглушки
 *******************************************************/
int		Set_MMXN	(uint16_t QTnum, uint64_t currentTime ){return false;}

//	MMXU1  MB_bOffsetModule4
//	MMXU2  MB_bOffsetModule4
//	MMXU3  MB_bOffsetModule5
//	MMXU4  MB_bOffsetModule5

/*******************************************************
 * Set_MMXU наполняем оперативными данными
 *******************************************************/
int	Set_MMXU	(uint16_t QTnum, uint64_t currentTime )
{
	int			ret = false;
	uint32_t	Health1,Health2,Health3,Health4;
	Quality 	quality;
	float		diapazon;
	float		mag;
	float		K;

	bool		Em4=0,Em5=0,Eust=0;							// ошибки модулей,уставок
	bool		Ek1=0,Ek2=0,Ek3=0;

	bool		Ek1S1=0,Ek2S1=0,Ek3S1=0;
	bool		Ek1S2=0,Ek2S2=0,Ek3S2=0;
	bool		Ek1S3=0,Ek2S3=0,Ek3S3=0;

	bool		En1S1=0,En2S1=0,En3S1=0;
	bool		En1S2=0,En2S2=0,En3S2=0;
	bool		En1S3=0,En2S3=0,En3S3=0;

	uint8_t		M1Side=0,M2Side=0,M3Side=0;					// привязка к стороне
	uint8_t		M1neutSide=0,M2neutSide=0,M3neutSide=0;		// привязка к стороне
	portCHAR 	pagehits[200];

// Health

	Eust=0; if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)>0) 		{Eust=1;}
	Em4=0; if ((ucMDiscInBuf[MB_offset_errorM4] & MB_bOffsetModule4)>0) 			{Em4=1;}
	Em5=0; if ((ucMDiscInBuf[MB_offset_errorM5] & MB_bOffsetModule5)>0) 			{Em5=1;}

	Ek1S1=0; if ((ucConfigTRMeasBuf[MB_offset_SideTT_CH1] & MB_bOffset_SideTT) == 1)	{Ek1S1=1;}
	Ek2S1=0; if ((ucConfigTRMeasBuf[MB_offset_SideTT_CH2] & MB_bOffset_SideTT) == 1)	{Ek2S1=1;}
	Ek3S1=0; if ((ucConfigTRMeasBuf[MB_offset_SideTT_CH3] & MB_bOffset_SideTT) == 1)	{Ek3S1=1;}

	Ek1S2=0; if ((ucConfigTRMeasBuf[MB_offset_SideTT_CH1] & MB_bOffset_SideTT) == 2)	{Ek1S2=1;}
	Ek2S2=0; if ((ucConfigTRMeasBuf[MB_offset_SideTT_CH2] & MB_bOffset_SideTT) == 2)	{Ek2S2=1;}
	Ek3S2=0; if ((ucConfigTRMeasBuf[MB_offset_SideTT_CH3] & MB_bOffset_SideTT) == 2)	{Ek3S2=1;}

	Ek1S3=0; if ((ucConfigTRMeasBuf[MB_offset_SideTT_CH1] & MB_bOffset_SideTT) == 3)	{Ek1S3=1;}
	Ek2S3=0; if ((ucConfigTRMeasBuf[MB_offset_SideTT_CH2] & MB_bOffset_SideTT) == 3)	{Ek2S3=1;}
	Ek3S3=0; if ((ucConfigTRMeasBuf[MB_offset_SideTT_CH3] & MB_bOffset_SideTT) == 3)	{Ek3S3=1;}

	En1S1=0; if ((ucConfigTRPWRBuf[MB_offset_ConfigS1 + MB_offset_Meas_Ground] & MB_bOffset_SideTT) == 1) {En1S1=1;}
	En2S1=0; if ((ucConfigTRPWRBuf[MB_offset_ConfigS1 + MB_offset_Meas_Ground] & MB_bOffset_SideTT) == 2) {En2S1=1;}
	En3S1=0; if ((ucConfigTRPWRBuf[MB_offset_ConfigS1 + MB_offset_Meas_Ground] & MB_bOffset_SideTT) == 3) {En3S1=1;}

	En1S2=0; if ((ucConfigTRPWRBuf[MB_offset_ConfigS2 + MB_offset_Meas_Ground] & MB_bOffset_SideTT) == 1) {En1S2=1;}
	En2S2=0; if ((ucConfigTRPWRBuf[MB_offset_ConfigS2 + MB_offset_Meas_Ground] & MB_bOffset_SideTT) == 2) {En2S2=1;}
	En3S2=0; if ((ucConfigTRPWRBuf[MB_offset_ConfigS2 + MB_offset_Meas_Ground] & MB_bOffset_SideTT) == 3) {En3S2=1;}

	En1S3=0; if ((ucConfigTRPWRBuf[MB_offset_ConfigS3 + MB_offset_Meas_Ground] & MB_bOffset_SideTT) == 1) {En1S3=1;}
	En2S3=0; if ((ucConfigTRPWRBuf[MB_offset_ConfigS3 + MB_offset_Meas_Ground] & MB_bOffset_SideTT) == 2) {En2S3=1;}
	En3S3=0; if ((ucConfigTRPWRBuf[MB_offset_ConfigS3 + MB_offset_Meas_Ground] & MB_bOffset_SideTT) == 3) {En3S3=1;}
/*
	sprintf(pagehits,"MMXU1. M4=%u, K1S1=%u, K2S1=%u, K3S1=%u, M5=%u, Ust=%u\n",Em4, En1S1, En2S1, En3S1, Em5, Eust);
	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_MES_MMXU1_NamPlt_vendor , pagehits);

	sprintf(pagehits,"MMXU2. M4=%u, K1S2=%u, K2S2=%u, K3S2=%u, M5=%u, Ust=%u\n",Em4, En1S2, En2S2, En3S2, Em5, Eust);
	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_MES_MMXU2_NamPlt_vendor , pagehits);

	sprintf(pagehits,"MMXU3. M4=%u, K1S3=%u, K2S3=%u, K3S3=%u, M5=%u, Ust=%u\n",Em4, En1S3, En2S3, En3S3, Em5, Eust);
	IedServer_updateVisibleStringAttributeValue(iedServer,&iedModel_MES_MMXU3_NamPlt_vendor , pagehits);
*/
// MMXU1 ---------------------------------------------------

	Health1 = STVALINT32_OK;
	if (Eust) 						{Health1 = STVALINT32_Warning;}
	if (Em4 && (Ek1S1 || Ek2S1))	{Health1 = STVALINT32_Warning;}
	if (Em5 && Ek3S1)				{Health1 = STVALINT32_Warning;}
	if (Em4 && (En1S1 || En2S1))	{Health1 = STVALINT32_Warning;}
	if (Em5 && En3S1)				{Health1 = STVALINT32_Warning;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_MMXU1_Health_stVal, Health1))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_MMXU1_Health_t, currentTime);

// MMXU2 ---------------------------------------------------
	Health2 = STVALINT32_OK;
	if (Eust) 						{Health2 = STVALINT32_Warning;}
	if (Em4 && (Ek1S2 || Ek2S2))	{Health2 = STVALINT32_Warning;}
	if (Em5 && Ek3S2)				{Health2 = STVALINT32_Warning;}
	if (Em4 && (En1S2 || En2S2))	{Health2 = STVALINT32_Warning;}
	if (Em5 && En3S2)				{Health2 = STVALINT32_Warning;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_MMXU2_Health_stVal, Health2))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_MMXU2_Health_t, currentTime);

// MMXU3 ---------------------------------------------------
	Health3 = STVALINT32_OK;
	if (Eust) 						{Health3 = STVALINT32_Warning;}
	if (Em4 && (Ek1S3 || Ek2S3))	{Health3 = STVALINT32_Warning;}
	if (Em5 && Ek3S3)				{Health3 = STVALINT32_Warning;}
	if (Em4 && (En1S3 || En2S3))	{Health3 = STVALINT32_Warning;}
	if (Em5 && En3S3)				{Health3 = STVALINT32_Warning;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_MMXU3_Health_stVal, Health3))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_MMXU3_Health_t, currentTime);

// MMXU4 ---------------------------------------------------
	Health4 = STVALINT32_OK;
	if (Em5)					{Health4 = STVALINT32_Warning;}
	if (Eust) 					{Health4 = STVALINT32_Warning;}
	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_MMXU4_Health_stVal, Health4))
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_MMXU4_Health_t, currentTime);


		// Ток на стороне 1
//					K = ((float)40 * (float)ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Kttf]) /  (float)65535;
//					diapazon = (float)range_maxIphs * (float)ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Kttf];
//					mag = (float)ucMAnalogInBuf[MB_offset_Ia] * K;

			K = 1000 * (40 * ucConfigTRPWRBuf[MB_offset_ConfigS1 + MB_offset_P_Obmotki]) / ((float)sqrt3 * 65535 * ucConfigTRPWRBuf[MB_offset_ConfigS1 + MB_offset_U_Obmotki]);
			diapazon = K * 65535;
// Ток на стороне 1
			mag = ucMAnalogInBuf[MB_offset_Is1a] * K;
			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU1_A_phsA_db,
					&iedModel_MES_MMXU1_A_phsA_zeroDb,
					&iedModel_MES_MMXU1_A_phsA_instCVal_mag_f,
					&iedModel_MES_MMXU1_A_phsA_cVal_mag_f,
					&iedModel_MES_MMXU1_A_phsA_t,
					currentTime);

			mag = ucMAnalogInBuf[MB_offset_Is1b] * K;
			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU1_A_phsB_db,
					&iedModel_MES_MMXU1_A_phsB_zeroDb,
					&iedModel_MES_MMXU1_A_phsB_instCVal_mag_f,
					&iedModel_MES_MMXU1_A_phsB_cVal_mag_f,
					&iedModel_MES_MMXU1_A_phsB_t,
					currentTime);

			mag = ucMAnalogInBuf[MB_offset_Is1c] * K;
			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU1_A_phsC_db,
					&iedModel_MES_MMXU1_A_phsC_zeroDb,
					&iedModel_MES_MMXU1_A_phsC_instCVal_mag_f,
					&iedModel_MES_MMXU1_A_phsC_cVal_mag_f,
					&iedModel_MES_MMXU1_A_phsC_t,
					currentTime);

			mag = ucMAnalogInBuf[MB_offset_Is1n] * K;
			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU1_A_neut_db,
					&iedModel_MES_MMXU1_A_neut_zeroDb,
					&iedModel_MES_MMXU1_A_neut_instCVal_mag_f,
					&iedModel_MES_MMXU1_A_neut_cVal_mag_f,
					&iedModel_MES_MMXU1_A_neut_t,
					currentTime);

// Ток на стороне 2
			K = 1000 * (40 * ucConfigTRPWRBuf[MB_offset_ConfigS2 + MB_offset_P_Obmotki]) / ((float)sqrt3 * 65535 * ucConfigTRPWRBuf[MB_offset_ConfigS2 + MB_offset_U_Obmotki]);
			diapazon = K * 65535;

			mag = ucMAnalogInBuf[MB_offset_Is2a] * K;
			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU2_A_phsA_db,
					&iedModel_MES_MMXU2_A_phsA_zeroDb,
					&iedModel_MES_MMXU2_A_phsA_instCVal_mag_f,
					&iedModel_MES_MMXU2_A_phsA_cVal_mag_f,
					&iedModel_MES_MMXU2_A_phsA_t,
					currentTime);

			mag = ucMAnalogInBuf[MB_offset_Is2b] * K;
			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU2_A_phsB_db,
					&iedModel_MES_MMXU2_A_phsB_zeroDb,
					&iedModel_MES_MMXU2_A_phsB_instCVal_mag_f,
					&iedModel_MES_MMXU2_A_phsB_cVal_mag_f,
					&iedModel_MES_MMXU2_A_phsB_t,
					currentTime);

			mag = ucMAnalogInBuf[MB_offset_Is2c] * K;
			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU2_A_phsC_db,
					&iedModel_MES_MMXU2_A_phsC_zeroDb,
					&iedModel_MES_MMXU2_A_phsC_instCVal_mag_f,
					&iedModel_MES_MMXU2_A_phsC_cVal_mag_f,
					&iedModel_MES_MMXU2_A_phsC_t,
					currentTime);

			mag = ucMAnalogInBuf[MB_offset_Is2n] * K;
			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU2_A_neut_db,
					&iedModel_MES_MMXU2_A_neut_zeroDb,
					&iedModel_MES_MMXU2_A_neut_instCVal_mag_f,
					&iedModel_MES_MMXU2_A_neut_cVal_mag_f,
					&iedModel_MES_MMXU2_A_neut_t,
					currentTime);

// Ток на стороне 3
			K = 1000 * (40 * ucConfigTRPWRBuf[MB_offset_ConfigS3 + MB_offset_P_Obmotki]) / ((float)sqrt3 * 65535 * ucConfigTRPWRBuf[MB_offset_ConfigS3 + MB_offset_U_Obmotki]);
			diapazon = K * 65535;

			mag = ucMAnalogInBuf[MB_offset_Is3a] * K;
			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU3_A_phsA_db,
					&iedModel_MES_MMXU3_A_phsA_zeroDb,
					&iedModel_MES_MMXU3_A_phsA_instCVal_mag_f,
					&iedModel_MES_MMXU3_A_phsA_cVal_mag_f,
					&iedModel_MES_MMXU3_A_phsA_t,
					currentTime);

			mag = ucMAnalogInBuf[MB_offset_Is3b] * K;
			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU3_A_phsB_db,
					&iedModel_MES_MMXU3_A_phsB_zeroDb,
					&iedModel_MES_MMXU3_A_phsB_instCVal_mag_f,
					&iedModel_MES_MMXU3_A_phsB_cVal_mag_f,
					&iedModel_MES_MMXU3_A_phsB_t,
					currentTime);

			mag = ucMAnalogInBuf[MB_offset_Is3c] * K;
			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU3_A_phsC_db,
					&iedModel_MES_MMXU3_A_phsC_zeroDb,
					&iedModel_MES_MMXU3_A_phsC_instCVal_mag_f,
					&iedModel_MES_MMXU3_A_phsC_cVal_mag_f,
					&iedModel_MES_MMXU3_A_phsC_t,
					currentTime);

			mag = ucMAnalogInBuf[MB_offset_Is3n] * K;
			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU3_A_neut_db,
					&iedModel_MES_MMXU3_A_neut_zeroDb,
					&iedModel_MES_MMXU3_A_neut_instCVal_mag_f,
					&iedModel_MES_MMXU3_A_neut_cVal_mag_f,
					&iedModel_MES_MMXU3_A_neut_t,
					currentTime);

// напряжения --------------------------
//MMXU1_PPV

			diapazon = (float)range_maxU * GetRealU(256,ucConfigTRMeasBuf[MB_offset_KTHL]);

			mag = GetRealU(ucMAnalogInBuf[MB_offset_Uab],ucConfigTRMeasBuf[MB_offset_KTHL]);
			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU4_PPV_phsA_db,
					&iedModel_MES_MMXU4_PPV_phsA_zeroDb,
					&iedModel_MES_MMXU4_PPV_phsA_instCVal_mag_f,
					&iedModel_MES_MMXU4_PPV_phsA_cVal_mag_f,
					&iedModel_MES_MMXU4_PPV_phsA_t,
					currentTime);

			mag = GetRealU(ucMAnalogInBuf[MB_offset_Ubc],ucConfigTRMeasBuf[MB_offset_KTHL]);
			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU4_PPV_phsB_db,
					&iedModel_MES_MMXU4_PPV_phsB_zeroDb,
					&iedModel_MES_MMXU4_PPV_phsB_instCVal_mag_f,
					&iedModel_MES_MMXU4_PPV_phsB_cVal_mag_f,
					&iedModel_MES_MMXU4_PPV_phsB_t,
					currentTime);

			mag = GetRealU(ucMAnalogInBuf[MB_offset_Ucd],ucConfigTRMeasBuf[MB_offset_KTHL]);
			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU4_PPV_phsC_db,
					&iedModel_MES_MMXU4_PPV_phsC_zeroDb,
					&iedModel_MES_MMXU4_PPV_phsC_instCVal_mag_f,
					&iedModel_MES_MMXU4_PPV_phsC_cVal_mag_f,
					&iedModel_MES_MMXU4_PPV_phsC_t,
					currentTime);
//----
			mag = GetRealU(ucMAnalogInBuf[MB_offset_Ua],ucConfigTRMeasBuf[MB_offset_KTHL]);
			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU4_phV_phsA_db,
					&iedModel_MES_MMXU4_phV_phsA_zeroDb,
					&iedModel_MES_MMXU4_phV_phsA_instCVal_mag_f,
					&iedModel_MES_MMXU4_phV_phsA_cVal_mag_f,
					&iedModel_MES_MMXU4_phV_phsA_t,
					currentTime);

			mag = GetRealU(ucMAnalogInBuf[MB_offset_Ub],ucConfigTRMeasBuf[MB_offset_KTHL]);
			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU4_phV_phsB_db,
					&iedModel_MES_MMXU4_phV_phsB_zeroDb,
					&iedModel_MES_MMXU4_phV_phsB_instCVal_mag_f,
					&iedModel_MES_MMXU4_phV_phsB_cVal_mag_f,
					&iedModel_MES_MMXU4_phV_phsB_t,
					currentTime);

			mag = GetRealU(ucMAnalogInBuf[MB_offset_Uc],ucConfigTRMeasBuf[MB_offset_KTHL]);
			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU4_phV_phsC_db,
					&iedModel_MES_MMXU4_phV_phsC_zeroDb,
					&iedModel_MES_MMXU4_phV_phsC_instCVal_mag_f,
					&iedModel_MES_MMXU4_phV_phsC_cVal_mag_f,
					&iedModel_MES_MMXU4_phV_phsC_t,
					currentTime);

			diapazon = (float)range_maxU * GetRealU(256,ucConfigTRMeasBuf[MB_offset_KTHX]);
			mag = GetRealU(ucMAnalogInBuf[MB_offset_Un],ucConfigTRMeasBuf[MB_offset_KTHX]);
			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU4_phV_neut_db,
					&iedModel_MES_MMXU4_phV_neut_zeroDb,
					&iedModel_MES_MMXU4_phV_neut_instCVal_mag_f,
					&iedModel_MES_MMXU4_phV_neut_cVal_mag_f,
					&iedModel_MES_MMXU4_phV_neut_t,
					currentTime);

			// частота
			{
				float level;
				float dbLevel;
				float zeroDbLevel;
				float premag;

				dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU4_Hz_db)*(float)(range_maxF-range_minF) / (float)DbPercent;
				zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU4_Hz_zeroDb)*(float)(range_maxF-range_minF) / (float)DbPercent;
				mag = (float)ucMAnalogInBuf[MB_offset_Hz]/256;
				if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU4_Hz_instMag_f,mag)){
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU4_Hz_t, currentTime);
				}
				premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_MMXU4_Hz_mag_f);

				if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}

				if ( (mag > (50 - zeroDbLevel)) && (mag < (50 + zeroDbLevel))) mag = 50;

				if (level > dbLevel) {
					IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU4_Hz_mag_f,mag);
				}else{
					if (mag == 50) IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU4_Hz_mag_f, 50);
				}
			}
/*************************************************************************
 *q
 *************************************************************************/
		quality = QUALITY_VALIDITY_GOOD;
		if (Eust) 						{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
		if (Em4 && (Ek1S1 || Ek2S1))	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
		if (Em5 && Ek3S1)				{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

		if (IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsA_q,quality)){
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsB_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsC_q,quality);

			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_phsA_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_phsB_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_phsC_t, currentTime);
		}
// q neut
		quality = QUALITY_VALIDITY_GOOD;
		if (Eust) 						{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
		if (Em4 && (En1S1 || En2S1))	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
		if (Em5 && En3S1)				{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

		if (IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_neut_q,quality)){
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_neut_t, currentTime);
		}


		quality = QUALITY_VALIDITY_GOOD;
		if (Eust) 						{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
		if (Em4 && (Ek1S2 || Ek2S2))	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
		if (Em5 && Ek3S2)				{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

		if (IedServer_updateQuality(iedServer,&iedModel_MES_MMXU2_A_phsA_q,quality)){
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU2_A_phsB_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU2_A_phsC_q,quality);

			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU2_A_phsA_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU2_A_phsB_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU2_A_phsC_t, currentTime);
		}
// q neut
		quality = QUALITY_VALIDITY_GOOD;
		if (Eust) 						{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
		if (Em4 && (En1S2 || En2S2))	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
		if (Em5 && En3S2)				{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

		if (IedServer_updateQuality(iedServer,&iedModel_MES_MMXU2_A_neut_q,quality)){
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU2_A_neut_t, currentTime);
		}


		quality = QUALITY_VALIDITY_GOOD;
		if (Eust) 						{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
		if (Em4 && (Ek1S3 || Ek2S3))	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
		if (Em5 && Ek3S3)				{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

			if (IedServer_updateQuality(iedServer,&iedModel_MES_MMXU3_A_phsA_q,quality)){
				IedServer_updateQuality(iedServer,&iedModel_MES_MMXU3_A_phsB_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_MES_MMXU3_A_phsC_q,quality);

				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU3_A_phsA_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU3_A_phsB_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU3_A_phsC_t, currentTime);
			}
// q neut
		quality = QUALITY_VALIDITY_GOOD;
		if (Eust) 						{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
		if (Em4 && (En1S3 || En2S3))	{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
		if (Em5 && En3S3)				{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

		if (IedServer_updateQuality(iedServer,&iedModel_MES_MMXU3_A_neut_q,quality)){
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU3_A_neut_t, currentTime);
		}


		quality = QUALITY_VALIDITY_GOOD;
		if (Health4 == STVALINT32_Warning) 		{ quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

			if (IedServer_updateQuality(iedServer,&iedModel_MES_MMXU4_PPV_phsA_q,quality)){
				IedServer_updateQuality(iedServer,&iedModel_MES_MMXU4_PPV_phsB_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_MES_MMXU4_PPV_phsC_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_MES_MMXU4_phV_phsA_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_MES_MMXU4_phV_phsB_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_MES_MMXU4_phV_phsC_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_MES_MMXU4_phV_neut_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_MES_MMXU4_Hz_q,quality);

				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU4_PPV_phsA_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU4_PPV_phsB_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU4_PPV_phsC_t, currentTime);

				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU4_phV_phsA_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU4_phV_phsB_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU4_phV_phsC_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU4_phV_neut_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU4_Hz_t, currentTime);

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


extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
extern uint16_t   ucMUstavkiInBuf[MB_NumbUstavki];

//	MMXU1  MB_bOffsetModule4
//	MMXU2  MB_bOffsetModule4
//	MMXU3  MB_bOffsetModule5
//	MMXU4  MB_bOffsetModule5

/*******************************************************
 * заглушки
 *******************************************************/
int	Set_MMXN	(uint16_t QTnum, uint64_t currentTime ){return false;}

/*******************************************************
 * Set_MMXU наполняем оперативными данными
 *
 * узел проверен.(Ломан)
 * MR761	-	12.01.2018
 * MMXU (проверка без db) - ок
 * переключение уставок - ок
 *
 *******************************************************/
int	Set_MMXU	(uint16_t QTnum, uint64_t currentTime )
{
	uint32_t	Health = STVALINT32_OK;
	float	mag,premag;
	float	level,dbLevel=0,zeroDbLevel=0;
	float	K,K_dbLevel;
	float 	diapazon;
	Quality quality = QUALITY_VALIDITY_GOOD;

	// Health
		if (ucMDiscInBuf[MB_offset_errorM5] & MB_bOffsetModule5) {Health = STVALINT32_Warning;}
		if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {Health = STVALINT32_Warning;}

		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_MMXU1_Health_stVal, Health))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_MMXU1_Health_t, currentTime);



/*************************************************************************
 * 5 аналоговый модуль модуль
 *************************************************************************/
		if (Health == STVALINT32_Warning)	quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;

		if (IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsA_q,quality)){
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsB_q,quality);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsC_q,quality);

		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_phsA_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_phsB_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_phsC_t, currentTime);

#if !defined	(MR763)
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_neut_q,quality);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_neut_t, currentTime);
#endif
#if defined	(MR762)
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_neut1_q,quality);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_neut1_t, currentTime);
#endif

//MMXU1_phV
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_PPV_phsA_q,quality);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_PPV_phsB_q,quality);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_PPV_phsC_q,quality);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_phsA_q,quality);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_phsB_q,quality);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_phsC_q,quality);

		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_PPV_phsA_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_PPV_phsB_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_PPV_phsC_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_phV_phsA_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_phV_phsB_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_phV_phsC_t, currentTime);

#if !defined	(MR762)
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_neut_q,quality);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_phV_neut_t, currentTime);
#endif
#if defined	(MR763)  || \
	(defined (MR761) && defined (T4N5))
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_neut1_q,quality);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_phV_neut1_t, currentTime);
#endif
#if defined	(MR771)
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_neut1_q,quality);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_phV_neut1_t, currentTime);
#endif
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_Hz_q,quality);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_totW_q,quality);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_totVAr_q,quality);
		IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_totPF_q,quality);

		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_Hz_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_totW_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_totVAr_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_totPF_t, currentTime);

		}

		if (Health == STVALINT32_OK){
// Ток на стороне 1
			K = ((float)40 * (float)ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Kttf]) /  (float)65535;
			diapazon = (float)range_maxIphs * (float)ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Kttf];
//Ia -------------
			mag = (float)ucMAnalogInBuf[MB_offset_Ia] * K;

			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU1_A_phsA_db,
					&iedModel_MES_MMXU1_A_phsA_zeroDb,
					&iedModel_MES_MMXU1_A_phsA_instCVal_mag_f,
					&iedModel_MES_MMXU1_A_phsA_cVal_mag_f,
					&iedModel_MES_MMXU1_A_phsA_t,
					currentTime);
//Ib -------------
			mag = (float)ucMAnalogInBuf[MB_offset_Ib] * K;

			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU1_A_phsB_db,
					&iedModel_MES_MMXU1_A_phsB_zeroDb,
					&iedModel_MES_MMXU1_A_phsB_instCVal_mag_f,
					&iedModel_MES_MMXU1_A_phsB_cVal_mag_f,
					&iedModel_MES_MMXU1_A_phsB_t,
					currentTime);
//Ic -------------
			mag = (float)ucMAnalogInBuf[MB_offset_Ic] * K;

			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU1_A_phsC_db,
					&iedModel_MES_MMXU1_A_phsC_zeroDb,
					&iedModel_MES_MMXU1_A_phsC_instCVal_mag_f,
					&iedModel_MES_MMXU1_A_phsC_cVal_mag_f,
					&iedModel_MES_MMXU1_A_phsC_t,
					currentTime);

#if !defined	(MR763)
			K = ((float)40 * (float)ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Kttn]) /  (float)65535;
			diapazon = (float)range_maxIn * (float)ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Kttn];
//In -------------
			mag = (float)ucMAnalogInBuf[MB_offset_In] * K;

			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU1_A_neut_db,
					&iedModel_MES_MMXU1_A_neut_zeroDb,
					&iedModel_MES_MMXU1_A_neut_instCVal_mag_f,
					&iedModel_MES_MMXU1_A_neut_cVal_mag_f,
					&iedModel_MES_MMXU1_A_neut_t,
					currentTime);
#endif
#if defined	(MR762)
			K = ((float)40 * (float)ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Kttn1]) /  (float)65535;
			diapazon = (float)range_maxIn * (float)ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Kttn1];
//In1 -------------
			mag = (float)ucMAnalogInBuf[MB_offset_In1] * K;

			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU1_A_neut1_db,
					&iedModel_MES_MMXU1_A_neut1_zeroDb,
					&iedModel_MES_MMXU1_A_neut1_instCVal_mag_f,
					&iedModel_MES_MMXU1_A_neut1_cVal_mag_f,
					&iedModel_MES_MMXU1_A_neut1_t,
					currentTime);
#endif
		}
/*************************************************************************
 * 5 аналоговый модуль модуль
 *************************************************************************/
		if (Health == STVALINT32_OK){

			diapazon = (float)range_maxU * GetRealU(256,ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Ktnf]);
// Uab --------------
			mag = GetRealU(ucMAnalogInBuf[MB_offset_Uab],ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Ktnf]);

			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU1_PPV_phsA_db,
					&iedModel_MES_MMXU1_PPV_phsA_zeroDb,
					&iedModel_MES_MMXU1_PPV_phsA_instCVal_mag_f,
					&iedModel_MES_MMXU1_PPV_phsA_cVal_mag_f,
					&iedModel_MES_MMXU1_PPV_phsA_t,
					currentTime);
// Ubc --------------
			mag = GetRealU(ucMAnalogInBuf[MB_offset_Ubc],ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Ktnf]);

			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU1_PPV_phsB_db,
					&iedModel_MES_MMXU1_PPV_phsB_zeroDb,
					&iedModel_MES_MMXU1_PPV_phsB_instCVal_mag_f,
					&iedModel_MES_MMXU1_PPV_phsB_cVal_mag_f,
					&iedModel_MES_MMXU1_PPV_phsB_t,
					currentTime);
// Uca --------------
			mag = GetRealU(ucMAnalogInBuf[MB_offset_Uca],ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Ktnf]);

			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU1_PPV_phsC_db,
					&iedModel_MES_MMXU1_PPV_phsC_zeroDb,
					&iedModel_MES_MMXU1_PPV_phsC_instCVal_mag_f,
					&iedModel_MES_MMXU1_PPV_phsC_cVal_mag_f,
					&iedModel_MES_MMXU1_PPV_phsC_t,
					currentTime);
// Ua --------------
			mag = GetRealU(ucMAnalogInBuf[MB_offset_Ua],ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Ktnf]);

			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU1_phV_phsA_db,
					&iedModel_MES_MMXU1_phV_phsA_zeroDb,
					&iedModel_MES_MMXU1_phV_phsA_instCVal_mag_f,
					&iedModel_MES_MMXU1_phV_phsA_cVal_mag_f,
					&iedModel_MES_MMXU1_phV_phsA_t,
					currentTime);
// Ub --------------
			mag = GetRealU(ucMAnalogInBuf[MB_offset_Ub],ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Ktnf]);

			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU1_phV_phsB_db,
					&iedModel_MES_MMXU1_phV_phsB_zeroDb,
					&iedModel_MES_MMXU1_phV_phsB_instCVal_mag_f,
					&iedModel_MES_MMXU1_phV_phsB_cVal_mag_f,
					&iedModel_MES_MMXU1_phV_phsB_t,
					currentTime);
// Uc --------------
			mag = GetRealU(ucMAnalogInBuf[MB_offset_Uc],ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Ktnf]);

			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU1_phV_phsC_db,
					&iedModel_MES_MMXU1_phV_phsC_zeroDb,
					&iedModel_MES_MMXU1_phV_phsC_instCVal_mag_f,
					&iedModel_MES_MMXU1_phV_phsC_cVal_mag_f,
					&iedModel_MES_MMXU1_phV_phsC_t,
					currentTime);
#if !defined	(MR762)
// Un --------------
			diapazon = (float)range_maxU * GetRealU(256,ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Ktnnp]);
			mag = GetRealU(ucMAnalogInBuf[MB_offset_Un],ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Ktnnp]);

			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU1_phV_neut_db,
					&iedModel_MES_MMXU1_phV_neut_zeroDb,
					&iedModel_MES_MMXU1_phV_neut_instCVal_mag_f,
					&iedModel_MES_MMXU1_phV_neut_cVal_mag_f,
					&iedModel_MES_MMXU1_phV_neut_t,
					currentTime);
#endif
#if defined	(MR763)  || \
	(defined (MR761) && defined (T4N5))
// Un1 --------------
			diapazon = (float)range_maxU * GetRealU(256,ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Ktnnp1]);
			mag = GetRealU(ucMAnalogInBuf[MB_offset_Un1],ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Ktnnp1]);

			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU1_phV_neut1_db,
					&iedModel_MES_MMXU1_phV_neut1_zeroDb,
					&iedModel_MES_MMXU1_phV_neut1_instCVal_mag_f,
					&iedModel_MES_MMXU1_phV_neut1_cVal_mag_f,
					&iedModel_MES_MMXU1_phV_neut1_t,
					currentTime);
#endif
#if defined	(MR771)
// Un1 --------------
			diapazon = (float)range_maxU * GetRealU(256,ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Ktnnp1]);
			mag = GetRealU(ucMAnalogInBuf[MB_offset_Un1],ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Ktnnp1]);

			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU1_phV_neut1_db,
					&iedModel_MES_MMXU1_phV_neut1_zeroDb,
					&iedModel_MES_MMXU1_phV_neut1_instCVal_mag_f,
					&iedModel_MES_MMXU1_phV_neut1_cVal_mag_f,
					&iedModel_MES_MMXU1_phV_neut1_t,
					currentTime);
#endif
// частота
			dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_Hz_db)*(float)(range_maxF-range_minF) / (float)DbPercent;
			zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_Hz_zeroDb)*(float)(range_maxF-range_minF) / (float)DbPercent;
			mag = (float)ucMAnalogInBuf[MB_offset_Hz]/256;
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_Hz_instMag_f,mag)){
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_Hz_t, currentTime);
			}
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
		// диапазон - 40*5*65535*ki*Ku

			if (Health == STVALINT32_OK){

			K_dbLevel = (float)(range_P) * GetRealU(256,ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Ktnf]) * (float)ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Kttf] / (float)DbPercent;
	//TotW
			dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_totW_db) * K_dbLevel;
			zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_totW_zeroDb) * K_dbLevel;

			mag = (float)(int32_t)(((uint32_t)ucMAnalogInBuf[MB_offset_TotW+1]<<16) + (uint32_t)ucMAnalogInBuf[MB_offset_TotW]);

			mag = GetRealP(mag,ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Ktnf],ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Kttf]);

			if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totW_instMag_f,mag)){
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_totW_t, currentTime);

			}

			premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totW_mag_f);

			if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}
			if ( (mag > - zeroDbLevel) && (mag < zeroDbLevel)) mag = 0;
			if (level > dbLevel) {
				IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totW_mag_f,mag);
			}else{
				if (mag == 0) IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totW_mag_f, 0);
			}
	//TotVAr
			dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_totVAr_db) * K_dbLevel;
			zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_totVAr_zeroDb) * K_dbLevel;

			mag = (float)(int32_t)(((uint32_t)ucMAnalogInBuf[MB_offset_TotVAr+1]<<16) + (uint32_t)ucMAnalogInBuf[MB_offset_TotVAr]);
			mag = GetRealP(mag,ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Ktnf],ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Kttf]);

			if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totVAr_instMag_f,mag)){
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_totVAr_t, currentTime);
			}

			premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totVAr_mag_f);
			if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}
			if ( (mag > - zeroDbLevel) && (mag < zeroDbLevel)) mag = 0;
			if (level > dbLevel) {
				IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totVAr_mag_f,mag);
			}else{
				if (mag == 0) IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totVAr_mag_f, 0);
			}

	//totPF При изменении угла в отрицательную сторону	срабатывает db и zeroDb даже если изменения были не большие.

			dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_totPF_db)*(float)(range_maxCosF - range_minCosF) / (float)DbPercent;
			zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_totPF_zeroDb)*(float)(range_maxCosF - range_minCosF) / (float)DbPercent;
			int16_t* TotPF = (int16_t*)&ucMAnalogInBuf[MB_offset_TotPF];
			mag = (float)*TotPF / (float)256;
			if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totPF_instMag_f,mag)){
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_totPF_t, currentTime);
			}

			//zeroDbLevel DbLevel -----------------------------------------
			if ( ((mag>0)&&(mag<zeroDbLevel)) ||((mag<0)&&(mag>-zeroDbLevel)) ){
				IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totPF_mag_f, 0);
			}
			else{
			//DbLevel
				premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totPF_mag_f);
				if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}
				if (level > dbLevel) {
					IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totPF_mag_f,mag);
				}
			}
			// -----------------------------------------------------------
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
 * заглушки
 *******************************************************/
int		Set_MMXU	(uint16_t QTnum, uint64_t currentTime ){return false;}

/*******************************************************
 * Set_MMXN наполняем оперативными данными
 * время меняется + от качества
 *******************************************************/
int	Set_MMXN	(uint16_t QTnum, uint64_t currentTime )
{
	uint32_t	Health = STVALINT32_OK;
	float		mag,K;
	float		diapazon;
	Quality 	quality;
	bool		timeModify = false;
	int 		ret = false;

	// Health
		if (ucMDiscInBuf[MB_offset_errorM5] & MB_bOffsetModule5) 		{Health = STVALINT32_Warning;}
		if (ucMDiscInBuf[MB_offset_errorM4] & MB_bOffsetModule4) 		{Health = STVALINT32_Warning;}
		if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {Health = STVALINT32_Warning;}

		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_MMXN1_Health_stVal, Health))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_MMXN1_Health_t, currentTime);


/*************************************************************************
 * 4 аналоговый модуль модуль
 *************************************************************************/
		timeModify = false;
		quality = QUALITY_VALIDITY_GOOD;
		if (ucMDiscInBuf[MB_offset_errorM4] & MB_bOffsetModule4)		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
		if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

			if (IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp1_q,quality)){
				IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp2_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp3_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp4_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp5_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp6_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp7_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp8_q,quality);

				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp1_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp2_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp3_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp4_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp5_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp6_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp7_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp8_t, currentTime);

				timeModify = true;
			}


		K = ((float)range_maxPris * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris1 + MB_offset_KTT]) /  (float)65535;
		diapazon = (float)range_maxPris * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris1 + MB_offset_KTT];
		mag = (float)ucMAnalogInBuf[MB_offset_I1] * K;
		Set_Db_zeroDB_float(mag, diapazon,
				&iedModel_MES_MMXN1_Amp1_db,
				&iedModel_MES_MMXN1_Amp1_zeroDb,
				&iedModel_MES_MMXN1_Amp1_instMag_f,
				&iedModel_MES_MMXN1_Amp1_mag_f,
				&iedModel_MES_MMXN1_Amp1_t,
				currentTime);

		K = ((float)range_maxPris * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris2 + MB_offset_KTT]) /  (float)65535;
		diapazon = (float)range_maxPris * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris2 + MB_offset_KTT];
		mag = (float)ucMAnalogInBuf[MB_offset_I2] * K;
		Set_Db_zeroDB_float(mag, diapazon,
				&iedModel_MES_MMXN1_Amp2_db,
				&iedModel_MES_MMXN1_Amp2_zeroDb,
				&iedModel_MES_MMXN1_Amp2_instMag_f,
				&iedModel_MES_MMXN1_Amp2_mag_f,
				&iedModel_MES_MMXN1_Amp2_t,
				currentTime);

		K = ((float)range_maxPris * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris3 + MB_offset_KTT]) /  (float)65535;
		diapazon = (float)range_maxPris * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris3 + MB_offset_KTT];
		mag = (float)ucMAnalogInBuf[MB_offset_I3] * K;
		Set_Db_zeroDB_float(mag, diapazon,
				&iedModel_MES_MMXN1_Amp3_db,
				&iedModel_MES_MMXN1_Amp3_zeroDb,
				&iedModel_MES_MMXN1_Amp3_instMag_f,
				&iedModel_MES_MMXN1_Amp3_mag_f,
				&iedModel_MES_MMXN1_Amp3_t,
				currentTime);

		K = ((float)range_maxPris * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris4 + MB_offset_KTT]) /  (float)65535;
		diapazon = (float)range_maxPris * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris4 + MB_offset_KTT];
		mag = (float)ucMAnalogInBuf[MB_offset_I4] * K;
		Set_Db_zeroDB_float(mag, diapazon,
				&iedModel_MES_MMXN1_Amp4_db,
				&iedModel_MES_MMXN1_Amp4_zeroDb,
				&iedModel_MES_MMXN1_Amp4_instMag_f,
				&iedModel_MES_MMXN1_Amp4_mag_f,
				&iedModel_MES_MMXN1_Amp4_t,
				currentTime);

		K = ((float)range_maxPris * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris5 + MB_offset_KTT]) /  (float)65535;
		diapazon = (float)range_maxPris * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris5 + MB_offset_KTT];
		mag = (float)ucMAnalogInBuf[MB_offset_I5] * K;
		Set_Db_zeroDB_float(mag, diapazon,
				&iedModel_MES_MMXN1_Amp5_db,
				&iedModel_MES_MMXN1_Amp5_zeroDb,
				&iedModel_MES_MMXN1_Amp5_instMag_f,
				&iedModel_MES_MMXN1_Amp5_mag_f,
				&iedModel_MES_MMXN1_Amp5_t,
				currentTime);

		K = ((float)range_maxPris * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris6 + MB_offset_KTT]) /  (float)65535;
		diapazon = (float)range_maxPris * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris6 + MB_offset_KTT];
		mag = (float)ucMAnalogInBuf[MB_offset_I6] * K;
		Set_Db_zeroDB_float(mag, diapazon,
				&iedModel_MES_MMXN1_Amp6_db,
				&iedModel_MES_MMXN1_Amp6_zeroDb,
				&iedModel_MES_MMXN1_Amp6_instMag_f,
				&iedModel_MES_MMXN1_Amp6_mag_f,
				&iedModel_MES_MMXN1_Amp6_t,
				currentTime);

		K = ((float)range_maxPris * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris7 + MB_offset_KTT]) /  (float)65535;
		diapazon = (float)range_maxPris * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris7 + MB_offset_KTT];
		mag = (float)ucMAnalogInBuf[MB_offset_I7] * K;
		Set_Db_zeroDB_float(mag, diapazon,
				&iedModel_MES_MMXN1_Amp7_db,
				&iedModel_MES_MMXN1_Amp7_zeroDb,
				&iedModel_MES_MMXN1_Amp7_instMag_f,
				&iedModel_MES_MMXN1_Amp7_mag_f,
				&iedModel_MES_MMXN1_Amp7_t,
				currentTime);

		K = ((float)range_maxPris * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris8 + MB_offset_KTT]) /  (float)65535;
		diapazon = (float)range_maxPris * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris8 + MB_offset_KTT];
		mag = (float)ucMAnalogInBuf[MB_offset_I8] * K;
		Set_Db_zeroDB_float(mag, diapazon,
				&iedModel_MES_MMXN1_Amp8_db,
				&iedModel_MES_MMXN1_Amp8_zeroDb,
				&iedModel_MES_MMXN1_Amp8_instMag_f,
				&iedModel_MES_MMXN1_Amp8_mag_f,
				&iedModel_MES_MMXN1_Amp8_t,
				currentTime);

/*
		mag = (float)ucMAnalogInBuf[MB_offset_I1] * (float)40 * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris1 + MB_offset_KTT] / (float)65535;
		if ((IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXN1_Amp1_instMag_f,mag)) || timeModify)
		  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp1_t, currentTime);

		mag = (float)ucMAnalogInBuf[MB_offset_I2] * (float)40 * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris2 + MB_offset_KTT] / (float)65535;
		if ((IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXN1_Amp2_instMag_f,mag)) || timeModify)
		  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp2_t, currentTime);

		mag = (float)ucMAnalogInBuf[MB_offset_I3] * (float)40 * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris3 + MB_offset_KTT] / (float)65535;
		if (( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXN1_Amp3_instMag_f,mag)) || timeModify)
		  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp3_t, currentTime);

		mag = (float)ucMAnalogInBuf[MB_offset_I4] * (float)40 * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris4 + MB_offset_KTT] / (float)65535;
		if (( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXN1_Amp4_instMag_f,mag)) || timeModify)
		  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp4_t, currentTime);

		mag = (float)ucMAnalogInBuf[MB_offset_I5] * (float)40 * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris5 + MB_offset_KTT] / (float)65535;
		if (( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXN1_Amp5_instMag_f,mag)) || timeModify)
		  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp5_t, currentTime);

		mag = (float)ucMAnalogInBuf[MB_offset_I6] * (float)40 * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris6 + MB_offset_KTT] / (float)65535;
		if (( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXN1_Amp6_instMag_f,mag)) || timeModify)
		  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp6_t, currentTime);

		mag = (float)ucMAnalogInBuf[MB_offset_I7] * (float)40 * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris7 + MB_offset_KTT] / (float)65535;
		if (( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXN1_Amp7_instMag_f,mag)) || timeModify)
		  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp7_t, currentTime);

		mag = (float)ucMAnalogInBuf[MB_offset_I8] * (float)40 * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris8 + MB_offset_KTT] / (float)65535;
		if (( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXN1_Amp8_instMag_f,mag)) || timeModify)
		  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp8_t, currentTime);
*/

/*************************************************************************
 * 5 аналоговый модуль модуль
 *************************************************************************/
		timeModify = false;
		quality = QUALITY_VALIDITY_GOOD;
		if (ucMDiscInBuf[MB_offset_errorM5] & MB_bOffsetModule5) 		{quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
		if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

			if (IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp9_q,quality)){
				IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp10_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp11_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp12_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp13_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp14_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp15_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_MES_MMXN1_Amp16_q,quality);

				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp9_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp10_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp11_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp12_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp13_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp14_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp15_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp16_t, currentTime);

				timeModify = true;
			}

			K = ((float)range_maxPris * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris9 + MB_offset_KTT]) /  (float)65535;
			diapazon = (float)range_maxPris * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris9 + MB_offset_KTT];
			mag = (float)ucMAnalogInBuf[MB_offset_I9] * K;
			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXN1_Amp9_db,
					&iedModel_MES_MMXN1_Amp9_zeroDb,
					&iedModel_MES_MMXN1_Amp9_instMag_f,
					&iedModel_MES_MMXN1_Amp9_mag_f,
					&iedModel_MES_MMXN1_Amp9_t,
					currentTime);

			K = ((float)range_maxPris * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris10 + MB_offset_KTT]) /  (float)65535;
			diapazon = (float)range_maxPris * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris10 + MB_offset_KTT];
			mag = (float)ucMAnalogInBuf[MB_offset_I10] * K;
			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXN1_Amp10_db,
					&iedModel_MES_MMXN1_Amp10_zeroDb,
					&iedModel_MES_MMXN1_Amp10_instMag_f,
					&iedModel_MES_MMXN1_Amp10_mag_f,
					&iedModel_MES_MMXN1_Amp10_t,
					currentTime);

			K = ((float)range_maxPris * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris11 + MB_offset_KTT]) /  (float)65535;
			diapazon = (float)range_maxPris * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris11 + MB_offset_KTT];
			mag = (float)ucMAnalogInBuf[MB_offset_I11] * K;
			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXN1_Amp11_db,
					&iedModel_MES_MMXN1_Amp11_zeroDb,
					&iedModel_MES_MMXN1_Amp11_instMag_f,
					&iedModel_MES_MMXN1_Amp11_mag_f,
					&iedModel_MES_MMXN1_Amp11_t,
					currentTime);

			K = ((float)range_maxPris * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris12 + MB_offset_KTT]) /  (float)65535;
			diapazon = (float)range_maxPris * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris12 + MB_offset_KTT];
			mag = (float)ucMAnalogInBuf[MB_offset_I12] * K;
			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXN1_Amp12_db,
					&iedModel_MES_MMXN1_Amp12_zeroDb,
					&iedModel_MES_MMXN1_Amp12_instMag_f,
					&iedModel_MES_MMXN1_Amp12_mag_f,
					&iedModel_MES_MMXN1_Amp12_t,
					currentTime);

			K = ((float)range_maxPris * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris13 + MB_offset_KTT]) /  (float)65535;
			diapazon = (float)range_maxPris * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris13 + MB_offset_KTT];
			mag = (float)ucMAnalogInBuf[MB_offset_I13] * K;
			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXN1_Amp13_db,
					&iedModel_MES_MMXN1_Amp13_zeroDb,
					&iedModel_MES_MMXN1_Amp13_instMag_f,
					&iedModel_MES_MMXN1_Amp13_mag_f,
					&iedModel_MES_MMXN1_Amp13_t,
					currentTime);

			K = ((float)range_maxPris * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris14 + MB_offset_KTT]) /  (float)65535;
			diapazon = (float)range_maxPris * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris14 + MB_offset_KTT];
			mag = (float)ucMAnalogInBuf[MB_offset_I14] * K;
			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXN1_Amp14_db,
					&iedModel_MES_MMXN1_Amp14_zeroDb,
					&iedModel_MES_MMXN1_Amp14_instMag_f,
					&iedModel_MES_MMXN1_Amp14_mag_f,
					&iedModel_MES_MMXN1_Amp14_t,
					currentTime);

			K = ((float)range_maxPris * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris15 + MB_offset_KTT]) /  (float)65535;
			diapazon = (float)range_maxPris * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris15 + MB_offset_KTT];
			mag = (float)ucMAnalogInBuf[MB_offset_I15] * K;
			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXN1_Amp15_db,
					&iedModel_MES_MMXN1_Amp15_zeroDb,
					&iedModel_MES_MMXN1_Amp15_instMag_f,
					&iedModel_MES_MMXN1_Amp15_mag_f,
					&iedModel_MES_MMXN1_Amp15_t,
					currentTime);

			K = ((float)range_maxPris * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris16 + MB_offset_KTT]) /  (float)65535;
			diapazon = (float)range_maxPris * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris16 + MB_offset_KTT];
			mag = (float)ucMAnalogInBuf[MB_offset_I16] * K;
			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXN1_Amp16_db,
					&iedModel_MES_MMXN1_Amp16_zeroDb,
					&iedModel_MES_MMXN1_Amp16_instMag_f,
					&iedModel_MES_MMXN1_Amp16_mag_f,
					&iedModel_MES_MMXN1_Amp16_t,
					currentTime);
/*
		mag = (float)ucMAnalogInBuf[MB_offset_I9] * (float)40 * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris9 + MB_offset_KTT] / (float)65535;
		if (( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXN1_Amp9_instMag_f,mag)) || timeModify)
		  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp9_t, currentTime);

		mag = (float)ucMAnalogInBuf[MB_offset_I10] * (float)40 * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris10 + MB_offset_KTT] / (float)65535;
		if (( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXN1_Amp10_instMag_f,mag)) || timeModify)
		  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp10_t, currentTime);

		mag = (float)ucMAnalogInBuf[MB_offset_I11] * (float)40 * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris11 + MB_offset_KTT] / (float)65535;
		if (( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXN1_Amp11_instMag_f,mag)) || timeModify)
		  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp11_t, currentTime);

		mag = (float)ucMAnalogInBuf[MB_offset_I12] * (float)40 * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris12 + MB_offset_KTT] / (float)65535;
		if (( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXN1_Amp12_instMag_f,mag)) || timeModify)
		  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp12_t, currentTime);

		mag = (float)ucMAnalogInBuf[MB_offset_I13] * (float)40 * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris13 + MB_offset_KTT] / (float)65535;
		if (( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXN1_Amp13_instMag_f,mag)) || timeModify)
		  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp13_t, currentTime);

		mag = (float)ucMAnalogInBuf[MB_offset_I14] * (float)40 * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris14 + MB_offset_KTT] / (float)65535;
		if (( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXN1_Amp14_instMag_f,mag)) || timeModify)
		  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp14_t, currentTime);

		mag = (float)ucMAnalogInBuf[MB_offset_I15] * (float)40 * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris15 + MB_offset_KTT] / (float)65535;
		if (( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXN1_Amp15_instMag_f,mag)) || timeModify)
		  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp15_t, currentTime);

		mag = (float)ucMAnalogInBuf[MB_offset_I16] * (float)40 * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris16 + MB_offset_KTT] / (float)65535;
		if (( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXN1_Amp16_instMag_f,mag)) || timeModify)
		  IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXN1_Amp16_t, currentTime);
*/
return ret;
}
#endif

#if defined	(MR902)
/*******************************************************
 * заглушки
 *******************************************************/
int		Set_MMXN	(uint16_t QTnum, uint64_t currentTime )
{
	int			ret = false;
	uint32_t	Health = STVALINT32_OK;
	float	mag,K;
	float	diapazon;
	Quality quality = QUALITY_VALIDITY_GOOD;

	// Health
		if (ucMDiscInBuf[MB_offset_errorM5] & MB_bOffsetModule5) 		{Health = STVALINT32_Warning;}
		if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {Health = STVALINT32_Warning;}

		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_INMMXN1_Health_stVal, Health))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_INMMXN1_Health_t, currentTime);

// 6
		K = ((float)range_maxIn * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris6 + MB_offset_KTT]) /  (float)65535;
		diapazon = (float)range_maxIn * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris6 + MB_offset_KTT];
		mag = (float)ucMAnalogInBuf[MB_offset_In] * K;
		ret = Set_Db_zeroDB_float(mag, diapazon,
				&iedModel_MES_INMMXN1_Amp1_db,
				&iedModel_MES_INMMXN1_Amp1_zeroDb,
				&iedModel_MES_INMMXN1_Amp1_instMag_f,
				&iedModel_MES_INMMXN1_Amp1_mag_f,
				&iedModel_MES_INMMXN1_Amp1_t,
				currentTime);


		quality = QUALITY_VALIDITY_GOOD;
	if (ucMDiscInBuf[MB_offset_errorM5] & MB_bOffsetModule5)		{ quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
	if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

	if (IedServer_updateQuality(iedServer,&iedModel_MES_INMMXN1_Amp1_q,quality)){
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_INMMXN1_Amp1_t, currentTime);
	}
	return ret;
}

/*******************************************************
 * Set_MMXU наполняем оперативными данными
 *******************************************************/
int	Set_MMXU	(uint16_t QTnum, uint64_t currentTime )
{
	uint32_t	Health = STVALINT32_OK;
	float	mag,K;
	float	diapazon;
	Quality quality = QUALITY_VALIDITY_GOOD;

// Health MMXU 1,2
	    Health = STVALINT32_OK;
		if (ucMDiscInBuf[MB_offset_errorM4] & MB_bOffsetModule4) 		{Health = STVALINT32_Warning;}
		if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {Health = STVALINT32_Warning;}

		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_MMXU1_Health_stVal, Health)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_MMXU1_Health_t, currentTime);
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_MMXU2_Health_stVal, Health))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_MMXU2_Health_t, currentTime);
		}

// Health MMXU3
		Health = STVALINT32_OK;
		if (ucMDiscInBuf[MB_offset_errorM4] & MB_bOffsetModule4) 		{Health = STVALINT32_Warning;}
		if (ucMDiscInBuf[MB_offset_errorM5] & MB_bOffsetModule5) 		{Health = STVALINT32_Warning;}
		if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {Health = STVALINT32_Warning;}

		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_MMXU3_Health_stVal, Health)){
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_MMXU3_Health_t, currentTime);
		}

// Health MMXU 4,5
		Health = STVALINT32_OK;
		if (ucMDiscInBuf[MB_offset_errorM5] & MB_bOffsetModule5) 		{Health = STVALINT32_Warning;}
		if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {Health = STVALINT32_Warning;}

		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_MMXU4_Health_stVal, Health)){
			IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_MMXU5_Health_stVal, Health);
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_MMXU4_Health_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_MMXU5_Health_t, currentTime);
		}

// quality MMXU 1,2
		quality = QUALITY_VALIDITY_GOOD;
		if (ucMDiscInBuf[MB_offset_errorM4] & MB_bOffsetModule4) 		{ quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
		if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) { quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

			if (IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsA_q,quality)){
				IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsB_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsC_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_MES_MMXU2_A_phsA_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_MES_MMXU2_A_phsB_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_MES_MMXU2_A_phsC_q,quality);

				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_phsA_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_phsB_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_phsC_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU2_A_phsA_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU2_A_phsB_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU2_A_phsC_t, currentTime);
			}
// quality MMXU3
		quality = QUALITY_VALIDITY_GOOD;
		if (ucMDiscInBuf[MB_offset_errorM4] & MB_bOffsetModule4) 		{ quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
		if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) { quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

			if (IedServer_updateQuality(iedServer,&iedModel_MES_MMXU3_A_phsA_q,quality)){
				IedServer_updateQuality(iedServer,&iedModel_MES_MMXU3_A_phsB_q,quality);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU3_A_phsA_t, currentTime);
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU3_A_phsB_t, currentTime);
			}

		quality = QUALITY_VALIDITY_GOOD;
		if (ucMDiscInBuf[MB_offset_errorM5] & MB_bOffsetModule5)		{ quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
		if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) { quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

		if (IedServer_updateQuality(iedServer,&iedModel_MES_MMXU3_A_phsC_q,quality)){
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU4_A_phsA_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU4_A_phsB_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU4_A_phsC_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU5_A_phsA_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU5_A_phsB_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU5_A_phsC_q,quality);

			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU3_A_phsC_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU4_A_phsA_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU4_A_phsB_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU4_A_phsC_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU5_A_phsA_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU5_A_phsB_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU5_A_phsC_t, currentTime);
		}

/*************************************************************************
 * 4 аналоговый модуль модуль
 *************************************************************************/

		K = ((float)range_maxIphs * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris1 + MB_offset_KTT]) /  (float)65535;
		diapazon = (float)range_maxIphs * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris1 + MB_offset_KTT];
		mag = (float)ucMAnalogInBuf[MB_offset_I1a] * K;
		Set_Db_zeroDB_float(mag, diapazon,
				&iedModel_MES_MMXU1_A_phsA_db,
				&iedModel_MES_MMXU1_A_phsA_zeroDb,
				&iedModel_MES_MMXU1_A_phsA_instCVal_mag_f,
				&iedModel_MES_MMXU1_A_phsA_cVal_mag_f,
				&iedModel_MES_MMXU1_A_phsA_t,
				currentTime);

		mag = (float)ucMAnalogInBuf[MB_offset_I1b] * K;
		Set_Db_zeroDB_float(mag, diapazon,
				&iedModel_MES_MMXU1_A_phsB_db,
				&iedModel_MES_MMXU1_A_phsB_zeroDb,
				&iedModel_MES_MMXU1_A_phsB_instCVal_mag_f,
				&iedModel_MES_MMXU1_A_phsB_cVal_mag_f,
				&iedModel_MES_MMXU1_A_phsB_t,
				currentTime);

		mag = (float)ucMAnalogInBuf[MB_offset_I1c] * K;
		Set_Db_zeroDB_float(mag, diapazon,
				&iedModel_MES_MMXU1_A_phsC_db,
				&iedModel_MES_MMXU1_A_phsC_zeroDb,
				&iedModel_MES_MMXU1_A_phsC_instCVal_mag_f,
				&iedModel_MES_MMXU1_A_phsC_cVal_mag_f,
				&iedModel_MES_MMXU1_A_phsC_t,
				currentTime);

		K = ((float)range_maxIphs * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris2 + MB_offset_KTT]) /  (float)65535;
		diapazon = (float)range_maxIphs * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris2 + MB_offset_KTT];
		mag = (float)ucMAnalogInBuf[MB_offset_I2a] * K;
		Set_Db_zeroDB_float(mag, diapazon,
				&iedModel_MES_MMXU2_A_phsA_db,
				&iedModel_MES_MMXU2_A_phsA_zeroDb,
				&iedModel_MES_MMXU2_A_phsA_instCVal_mag_f,
				&iedModel_MES_MMXU2_A_phsA_cVal_mag_f,
				&iedModel_MES_MMXU2_A_phsA_t,
				currentTime);

		mag = (float)ucMAnalogInBuf[MB_offset_I2b] * K;
		Set_Db_zeroDB_float(mag, diapazon,
				&iedModel_MES_MMXU2_A_phsB_db,
				&iedModel_MES_MMXU2_A_phsB_zeroDb,
				&iedModel_MES_MMXU2_A_phsB_instCVal_mag_f,
				&iedModel_MES_MMXU2_A_phsB_cVal_mag_f,
				&iedModel_MES_MMXU2_A_phsB_t,
				currentTime);

		mag = (float)ucMAnalogInBuf[MB_offset_I2c] * K;
		Set_Db_zeroDB_float(mag, diapazon,
				&iedModel_MES_MMXU2_A_phsC_db,
				&iedModel_MES_MMXU2_A_phsC_zeroDb,
				&iedModel_MES_MMXU2_A_phsC_instCVal_mag_f,
				&iedModel_MES_MMXU2_A_phsC_cVal_mag_f,
				&iedModel_MES_MMXU2_A_phsC_t,
				currentTime);

		K = ((float)range_maxIphs * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris3 + MB_offset_KTT]) /  (float)65535;
		diapazon = (float)range_maxIphs * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris3 + MB_offset_KTT];
		mag = (float)ucMAnalogInBuf[MB_offset_I3a] * K;
		Set_Db_zeroDB_float(mag, diapazon,
				&iedModel_MES_MMXU3_A_phsA_db,
				&iedModel_MES_MMXU3_A_phsA_zeroDb,
				&iedModel_MES_MMXU3_A_phsA_instCVal_mag_f,
				&iedModel_MES_MMXU3_A_phsA_cVal_mag_f,
				&iedModel_MES_MMXU3_A_phsA_t,
				currentTime);

		mag = (float)ucMAnalogInBuf[MB_offset_I3b] * K;
		Set_Db_zeroDB_float(mag, diapazon,
				&iedModel_MES_MMXU3_A_phsB_db,
				&iedModel_MES_MMXU3_A_phsB_zeroDb,
				&iedModel_MES_MMXU3_A_phsB_instCVal_mag_f,
				&iedModel_MES_MMXU3_A_phsB_cVal_mag_f,
				&iedModel_MES_MMXU3_A_phsB_t,
				currentTime);

		mag = (float)ucMAnalogInBuf[MB_offset_I3c] * K;
		Set_Db_zeroDB_float(mag, diapazon,
				&iedModel_MES_MMXU3_A_phsC_db,
				&iedModel_MES_MMXU3_A_phsC_zeroDb,
				&iedModel_MES_MMXU3_A_phsC_instCVal_mag_f,
				&iedModel_MES_MMXU3_A_phsC_cVal_mag_f,
				&iedModel_MES_MMXU3_A_phsC_t,
				currentTime);
// 4
		K = ((float)range_maxIphs * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris4 + MB_offset_KTT]) /  (float)65535;
		diapazon = (float)range_maxIphs * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris4 + MB_offset_KTT];
		mag = (float)ucMAnalogInBuf[MB_offset_I4a] * K;
		Set_Db_zeroDB_float(mag, diapazon,
				&iedModel_MES_MMXU4_A_phsA_db,
				&iedModel_MES_MMXU4_A_phsA_zeroDb,
				&iedModel_MES_MMXU4_A_phsA_instCVal_mag_f,
				&iedModel_MES_MMXU4_A_phsA_cVal_mag_f,
				&iedModel_MES_MMXU4_A_phsA_t,
				currentTime);

		mag = (float)ucMAnalogInBuf[MB_offset_I4b] * K;
		Set_Db_zeroDB_float(mag, diapazon,
				&iedModel_MES_MMXU4_A_phsB_db,
				&iedModel_MES_MMXU4_A_phsB_zeroDb,
				&iedModel_MES_MMXU4_A_phsB_instCVal_mag_f,
				&iedModel_MES_MMXU4_A_phsB_cVal_mag_f,
				&iedModel_MES_MMXU4_A_phsB_t,
				currentTime);

		mag = (float)ucMAnalogInBuf[MB_offset_I4c] * K;
		Set_Db_zeroDB_float(mag, diapazon,
				&iedModel_MES_MMXU4_A_phsC_db,
				&iedModel_MES_MMXU4_A_phsC_zeroDb,
				&iedModel_MES_MMXU4_A_phsC_instCVal_mag_f,
				&iedModel_MES_MMXU4_A_phsC_cVal_mag_f,
				&iedModel_MES_MMXU4_A_phsC_t,
				currentTime);
// 5
		K = ((float)range_maxIphs * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris5 + MB_offset_KTT]) /  (float)65535;
		diapazon = (float)range_maxIphs * (float)ucOtherUstavkiInBuf[MB_offset_Config_Pris5 + MB_offset_KTT];
		mag = (float)ucMAnalogInBuf[MB_offset_I5a] * K;
		Set_Db_zeroDB_float(mag, diapazon,
				&iedModel_MES_MMXU5_A_phsA_db,
				&iedModel_MES_MMXU5_A_phsA_zeroDb,
				&iedModel_MES_MMXU5_A_phsA_instCVal_mag_f,
				&iedModel_MES_MMXU5_A_phsA_cVal_mag_f,
				&iedModel_MES_MMXU5_A_phsA_t,
				currentTime);

		mag = (float)ucMAnalogInBuf[MB_offset_I5b] * K;
		Set_Db_zeroDB_float(mag, diapazon,
				&iedModel_MES_MMXU5_A_phsB_db,
				&iedModel_MES_MMXU5_A_phsB_zeroDb,
				&iedModel_MES_MMXU5_A_phsB_instCVal_mag_f,
				&iedModel_MES_MMXU5_A_phsB_cVal_mag_f,
				&iedModel_MES_MMXU5_A_phsB_t,
				currentTime);

		mag = (float)ucMAnalogInBuf[MB_offset_I5c] * K;
		Set_Db_zeroDB_float(mag, diapazon,
				&iedModel_MES_MMXU5_A_phsC_db,
				&iedModel_MES_MMXU5_A_phsC_zeroDb,
				&iedModel_MES_MMXU5_A_phsC_instCVal_mag_f,
				&iedModel_MES_MMXU5_A_phsC_cVal_mag_f,
				&iedModel_MES_MMXU5_A_phsC_t,
				currentTime);

}
#endif
#endif

/*******************************************************
 * MR5_700
 *******************************************************/
#if defined	(MR5_700)|| defined	(MR5_600) || defined (MR5_500) ||  defined (MR741)

#if defined	(MR5_700)
#include "static_model_MR5_700.h"
#endif

#if defined	(MR5_600)
#include "static_model_MR5_600.h"
#endif

#if defined	(MR5_500)
#include "static_model_MR5_500.h"
#endif

#if defined	(MR741)
#include "static_model_MR741.h"
#endif

extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
extern uint16_t   ucMUstavkiInBuf[MB_NumbUstavki];

//	MMXU1  MB_bOffsetModule4
//	MMXU2  MB_bOffsetModule4
//	MMXU3  MB_bOffsetModule5
//	MMXU4  MB_bOffsetModule5

/*******************************************************
 * заглушки
 *******************************************************/
int		Set_MMXN		(uint16_t QTnum, uint64_t currentTime ){return false;}

/*******************************************************
 * Set_MMXU наполняем оперативными данными
 *******************************************************/
int	Set_MMXU	(uint16_t QTnum, uint64_t currentTime )
{
	int			ret = false;
	float		mag,premag,level,dbLevel=0,zeroDbLevel=0;
	float		K;
	float 		diapazon;
	Quality 	quality = QUALITY_VALIDITY_GOOD;
	uint32_t	Health = STVALINT32_OK;


		if ((ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1)>0) 	{Health = STVALINT32_Warning;}
		if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)>0) 	{Health = STVALINT32_Warning;}

		IedServer_updateInt32AttributeValueWithTime(iedServer, &iedModel_MES_MMXU1_Health_stVal,&iedModel_MES_MMXU1_Health_t,currentTime,Health);
/*
		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_MMXU1_Health_stVal, Health))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_MMXU1_Health_t, currentTime);
*/
/*************************************************************************
 * аналоговый токовый модуль
 *************************************************************************/
#if defined	(MR5_700) || defined (MR5_500) ||  defined (MR741)

		if (ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1b)	quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
		if (ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki) 	quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;

		if (IedServer_updateQualityWithTime(iedServer, &iedModel_MES_MMXU1_A_phsA_q,&iedModel_MES_MMXU1_A_phsA_t,currentTime,quality)){
			IedServer_updateQualityWithTime(iedServer, &iedModel_MES_MMXU1_A_phsB_q,&iedModel_MES_MMXU1_A_phsB_t,currentTime,quality);
			IedServer_updateQualityWithTime(iedServer, &iedModel_MES_MMXU1_A_phsC_q,&iedModel_MES_MMXU1_A_phsC_t,currentTime,quality);
			IedServer_updateQualityWithTime(iedServer, &iedModel_MES_MMXU1_A_neut_q,&iedModel_MES_MMXU1_A_neut_t,currentTime,quality);
		}
/*
		if (IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsA_q,quality)){
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsB_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_phsC_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_A_neut_q,quality);

			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_phsA_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_phsB_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_phsC_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_A_neut_t, currentTime);
		}
*/
		{
// Ток
			// диапазон.
			// Lim I  40 * Itt
			// Lim I0 40 * Iн *Itt
			// Lim In 5 * Iн *Ittn
			K = (float)range_maxIphs * (float)ucMUstavkiInBuf[MB_offset_Itt]/(float)65535;
			diapazon = (float)range_maxIphs * (float)ucMUstavkiInBuf[MB_offset_Itt];

//Ia -------------
			mag = (float)ucMAnalogInBuf[MB_offset_Ia] * K;

			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU1_A_phsA_db,
					&iedModel_MES_MMXU1_A_phsA_zeroDb,
					&iedModel_MES_MMXU1_A_phsA_instCVal_mag_f,
					&iedModel_MES_MMXU1_A_phsA_cVal_mag_f,
					&iedModel_MES_MMXU1_A_phsA_t,
					currentTime);
//Ib -------------
			mag = (float)ucMAnalogInBuf[MB_offset_Ib] * K;

			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU1_A_phsB_db,
					&iedModel_MES_MMXU1_A_phsB_zeroDb,
					&iedModel_MES_MMXU1_A_phsB_instCVal_mag_f,
					&iedModel_MES_MMXU1_A_phsB_cVal_mag_f,
					&iedModel_MES_MMXU1_A_phsB_t,
					currentTime);
//Ic -------------
			mag = (float)ucMAnalogInBuf[MB_offset_Ic] * K;

			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU1_A_phsC_db,
					&iedModel_MES_MMXU1_A_phsC_zeroDb,
					&iedModel_MES_MMXU1_A_phsC_instCVal_mag_f,
					&iedModel_MES_MMXU1_A_phsC_cVal_mag_f,
					&iedModel_MES_MMXU1_A_phsC_t,
					currentTime);

			K = ((float)range_maxIn * (float)ucMUstavkiInBuf[MB_offset_Ittnp]) /  (float)65535;
			diapazon = (float)range_maxIn * (float)ucMUstavkiInBuf[MB_offset_Ittnp];
//In -------------
			mag = (float)ucMAnalogInBuf[MB_offset_In] * K;

			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU1_A_neut_db,
					&iedModel_MES_MMXU1_A_neut_zeroDb,
					&iedModel_MES_MMXU1_A_neut_instCVal_mag_f,
					&iedModel_MES_MMXU1_A_neut_cVal_mag_f,
					&iedModel_MES_MMXU1_A_neut_t,
					currentTime);
		}
#endif
/*************************************************************************
 * аналоговый модуль напряжения
 *************************************************************************/
#if  defined	(MR5_600) || defined (MR5_700) ||  defined (MR741)

		quality = QUALITY_VALIDITY_GOOD;
		if (ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1a)	quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
		if (ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki) 	quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;

		if (IedServer_updateQualityWithTime(iedServer, &iedModel_MES_MMXU1_PPV_phsA_q,&iedModel_MES_MMXU1_PPV_phsA_t,currentTime,quality)){
			IedServer_updateQualityWithTime(iedServer, &iedModel_MES_MMXU1_PPV_phsB_q,&iedModel_MES_MMXU1_PPV_phsB_t,currentTime,quality);
			IedServer_updateQualityWithTime(iedServer, &iedModel_MES_MMXU1_PPV_phsC_q,&iedModel_MES_MMXU1_PPV_phsC_t,currentTime,quality);
			IedServer_updateQualityWithTime(iedServer, &iedModel_MES_MMXU1_phV_phsA_q,&iedModel_MES_MMXU1_phV_phsA_t,currentTime,quality);
			IedServer_updateQualityWithTime(iedServer, &iedModel_MES_MMXU1_phV_phsB_q,&iedModel_MES_MMXU1_phV_phsB_t,currentTime,quality);
			IedServer_updateQualityWithTime(iedServer, &iedModel_MES_MMXU1_phV_phsC_q,&iedModel_MES_MMXU1_phV_phsC_t,currentTime,quality);
			IedServer_updateQualityWithTime(iedServer, &iedModel_MES_MMXU1_phV_neut_q,&iedModel_MES_MMXU1_phV_neut_t,currentTime,quality);
			IedServer_updateQualityWithTime(iedServer, &iedModel_MES_MMXU1_Hz_q,&iedModel_MES_MMXU1_Hz_t,currentTime,quality);
		}

/*
		if (IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_PPV_phsA_q,quality)){
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_PPV_phsB_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_PPV_phsC_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_phsA_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_phsB_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_phsC_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_phV_neut_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_Hz_q,quality);

			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_PPV_phsA_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_PPV_phsB_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_PPV_phsC_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_phV_phsA_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_phV_phsB_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_phV_phsC_t, currentTime);

			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_phV_neut_t, currentTime);
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_Hz_t, currentTime);
		}
*/
		{
// напряжения
			diapazon = (float)range_maxU * GetRealU(256,ucMUstavkiInBuf[MB_offset_Ktn]);

// Uab --------------
			mag = GetRealU(ucMAnalogInBuf[MB_offset_Uab],ucMUstavkiInBuf[MB_offset_Ktn]);

			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU1_PPV_phsA_db,
					&iedModel_MES_MMXU1_PPV_phsA_zeroDb,
					&iedModel_MES_MMXU1_PPV_phsA_instCVal_mag_f,
					&iedModel_MES_MMXU1_PPV_phsA_cVal_mag_f,
					&iedModel_MES_MMXU1_PPV_phsA_t,
					currentTime);
// Ubc --------------
			mag = GetRealU(ucMAnalogInBuf[MB_offset_Ubc],ucMUstavkiInBuf[MB_offset_Ktn]);

			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU1_PPV_phsB_db,
					&iedModel_MES_MMXU1_PPV_phsB_zeroDb,
					&iedModel_MES_MMXU1_PPV_phsB_instCVal_mag_f,
					&iedModel_MES_MMXU1_PPV_phsB_cVal_mag_f,
					&iedModel_MES_MMXU1_PPV_phsB_t,
					currentTime);
// Uca --------------
			mag = GetRealU(ucMAnalogInBuf[MB_offset_Uca],ucMUstavkiInBuf[MB_offset_Ktn]);

			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU1_PPV_phsC_db,
					&iedModel_MES_MMXU1_PPV_phsC_zeroDb,
					&iedModel_MES_MMXU1_PPV_phsC_instCVal_mag_f,
					&iedModel_MES_MMXU1_PPV_phsC_cVal_mag_f,
					&iedModel_MES_MMXU1_PPV_phsC_t,
					currentTime);
// Ua --------------
			mag = GetRealU(ucMAnalogInBuf[MB_offset_Ua],ucMUstavkiInBuf[MB_offset_Ktn]);

			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU1_phV_phsA_db,
					&iedModel_MES_MMXU1_phV_phsA_zeroDb,
					&iedModel_MES_MMXU1_phV_phsA_instCVal_mag_f,
					&iedModel_MES_MMXU1_phV_phsA_cVal_mag_f,
					&iedModel_MES_MMXU1_phV_phsA_t,
					currentTime);
// Ub --------------
			mag = GetRealU(ucMAnalogInBuf[MB_offset_Ub],ucMUstavkiInBuf[MB_offset_Ktn]);

			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU1_phV_phsB_db,
					&iedModel_MES_MMXU1_phV_phsB_zeroDb,
					&iedModel_MES_MMXU1_phV_phsB_instCVal_mag_f,
					&iedModel_MES_MMXU1_phV_phsB_cVal_mag_f,
					&iedModel_MES_MMXU1_phV_phsB_t,
					currentTime);
// Uc --------------
			mag = GetRealU(ucMAnalogInBuf[MB_offset_Uc],ucMUstavkiInBuf[MB_offset_Ktn]);

			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU1_phV_phsC_db,
					&iedModel_MES_MMXU1_phV_phsC_zeroDb,
					&iedModel_MES_MMXU1_phV_phsC_instCVal_mag_f,
					&iedModel_MES_MMXU1_phV_phsC_cVal_mag_f,
					&iedModel_MES_MMXU1_phV_phsC_t,
					currentTime);

// Un --------------
			//dbLevel 	= 256*256*GetRealU(IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_phV_neut_db),ucMUstavkiInBuf[MB_offset_Ktnnp]) / (float)DbPercent;
			//zeroDbLevel = 256*256*GetRealU(IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_phV_neut_zeroDb),ucMUstavkiInBuf[MB_offset_Ktnnp]) / (float)DbPercent;;

			diapazon = (float)range_maxU * GetRealU(256,ucMUstavkiInBuf[MB_offset_Ktnnp]);
			mag = GetRealU(ucMAnalogInBuf[MB_offset_Un],ucMUstavkiInBuf[MB_offset_Ktnnp]);

			Set_Db_zeroDB_float(mag, diapazon,
					&iedModel_MES_MMXU1_phV_neut_db,
					&iedModel_MES_MMXU1_phV_neut_zeroDb,
					&iedModel_MES_MMXU1_phV_neut_instCVal_mag_f,
					&iedModel_MES_MMXU1_phV_neut_cVal_mag_f,
					&iedModel_MES_MMXU1_phV_neut_t,
					currentTime);


// частота
			dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_Hz_db)*(float)(range_maxF-range_minF) / (float)DbPercent;
			zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_Hz_zeroDb)*(float)(range_maxF-range_minF) / (float)DbPercent;
			mag = (float)ucMAnalogInBuf[MB_offset_Hz]/256;

			//ret |=	IedServer_updateFloatAttributeValueWithTime(iedServer, &iedModel_MES_MMXU1_Hz_instMag_f, &iedModel_MES_MMXU1_Hz_t, currentTime, mag);
			 IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_Hz_instMag_f,mag);

			premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_Hz_mag_f);
			if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}

			if ( (mag > (50 - zeroDbLevel)) && (mag < (50 + zeroDbLevel))) mag = 50;

			if (level > dbLevel) {
				//IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_Hz_mag_f,mag);
				ret |=	IedServer_updateFloatAttributeValueWithTime(iedServer, &iedModel_MES_MMXU1_Hz_mag_f, &iedModel_MES_MMXU1_Hz_t, currentTime, mag);

			}else{
				if (mag == 50) {
					//IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_Hz_mag_f, 50);
					ret |=	IedServer_updateFloatAttributeValueWithTime(iedServer, &iedModel_MES_MMXU1_Hz_mag_f, &iedModel_MES_MMXU1_Hz_t, currentTime, 50);
				}
			}

		}
#endif
/*************************************************************************
 * мощность
 *************************************************************************/
#if defined	(MR5_700) ||  defined (MR741)
		// диапазон - 40*5*256*ki*Ku

		quality = QUALITY_VALIDITY_GOOD;
		if (ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1)	quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
		if (ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki) 	quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;

		if (IedServer_updateQualityWithTime(iedServer, &iedModel_MES_MMXU1_totW_q,&iedModel_MES_MMXU1_totW_t,currentTime,quality)){
			IedServer_updateQualityWithTime(iedServer, &iedModel_MES_MMXU1_totVAr_q,&iedModel_MES_MMXU1_totVAr_t,currentTime,quality);
			IedServer_updateQualityWithTime(iedServer, &iedModel_MES_MMXU1_totPF_q,&iedModel_MES_MMXU1_totPF_t,currentTime,quality);
		}
		/*
		if (IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_totW_q,quality)){
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_totVAr_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_MES_MMXU1_totPF_q,quality);
		}
*/


			diapazon = range_maxW;
	//TotW
			dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_totW_db)*diapazon / (float)DbPercent;
			zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_totW_zeroDb)*diapazon / (float)DbPercent;

			mag = 1000 * (float)(ucMAnalogInBuf[MB_offset_TotW]);
			if (ucMDiscInBuf[MB_offsetPTOC] & MB_bTotWZ) {mag = -mag;}

			//ret |=	IedServer_updateFloatAttributeValueWithTime(iedServer, &iedModel_MES_MMXU1_totW_instMag_f, &iedModel_MES_MMXU1_totW_t, currentTime, mag);
			IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totW_instMag_f,mag);
			//	IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_totW_t, currentTime);
			//}

			premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totW_mag_f);
			if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}

			if ( (mag > - zeroDbLevel) && (mag < zeroDbLevel)) mag = 0;


			if (level > dbLevel) {
				//IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totW_mag_f,mag);
				ret |=	IedServer_updateFloatAttributeValueWithTime(iedServer, &iedModel_MES_MMXU1_totW_mag_f, &iedModel_MES_MMXU1_totW_t, currentTime, mag);
			}else{
				if (mag == 0) {
					//IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totW_mag_f, 0);
					ret |=	IedServer_updateFloatAttributeValueWithTime(iedServer, &iedModel_MES_MMXU1_totW_mag_f, &iedModel_MES_MMXU1_totW_t, currentTime, 0);
				}
			}


	//TotVAr
			dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_totVAr_db)*diapazon / (float)DbPercent;
			zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_totVAr_zeroDb)*diapazon / (float)DbPercent;
			mag = 1000 * (float)(ucMAnalogInBuf[MB_offset_TotVAr]);
			if (ucMDiscInBuf[MB_offsetPTOC] & MB_bTotVAZ) {mag = -mag;}
			//ret |=	IedServer_updateFloatAttributeValueWithTime(iedServer, &iedModel_MES_MMXU1_totVAr_instMag_f, &iedModel_MES_MMXU1_totVAr_t, currentTime, mag);
			IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totVAr_instMag_f,mag);
			//	IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_totVAr_t, currentTime);
			//}

			premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totVAr_mag_f);
			if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}

			if ( (mag > - zeroDbLevel) && (mag < zeroDbLevel)) mag = 0;

			if (level > dbLevel) {
//				IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totVAr_mag_f,mag);
				ret |=	IedServer_updateFloatAttributeValueWithTime(iedServer, &iedModel_MES_MMXU1_totVAr_mag_f, &iedModel_MES_MMXU1_totVAr_t, currentTime, mag);
			}else{
				if (mag == 0) {
//					IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totVAr_mag_f, 0);
					ret |=	IedServer_updateFloatAttributeValueWithTime(iedServer, &iedModel_MES_MMXU1_totVAr_mag_f, &iedModel_MES_MMXU1_totVAr_t, currentTime, 0);
				}
			}

	//totPF
			dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_totPF_db)*(float)(range_maxCosF - range_minCosF) / (float)DbPercent;
			zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_MMXU1_totPF_zeroDb)*(float)(range_maxCosF - range_minCosF) / (float)DbPercent;
			mag = (float)ucMAnalogInBuf[MB_offset_TotPF]/256;
			//ret |=	IedServer_updateFloatAttributeValueWithTime(iedServer, &iedModel_MES_MMXU1_totPF_instMag_f, &iedModel_MES_MMXU1_totPF_t, currentTime, mag);
			IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totPF_instMag_f,mag);
			//	IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_MMXU1_totPF_t, currentTime);
			//}

			premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totPF_mag_f);
			if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}
			if (level > dbLevel) {
				if (mag < zeroDbLevel) mag = 0;
//				IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totPF_mag_f,mag);
				ret |=	IedServer_updateFloatAttributeValueWithTime(iedServer, &iedModel_MES_MMXU1_totPF_mag_f, &iedModel_MES_MMXU1_totPF_t, currentTime, mag);
			}else{
//				if (mag<zeroDbLevel) IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_MMXU1_totPF_mag_f, 0);
				if (mag<zeroDbLevel) {ret |= IedServer_updateFloatAttributeValueWithTime(iedServer, &iedModel_MES_MMXU1_totPF_mag_f, &iedModel_MES_MMXU1_totPF_t, currentTime, 0);}
			}
#endif
return ret;
}
#endif

