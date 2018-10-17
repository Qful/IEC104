/*
 * datatoRFLO.c
 *
 *  Created on: 24.05.2017
 *      Author: sagok
 */



#include "main.h"
#include "IEC850.h"

#include "iec850.h"
#include "iec61850_server.h"

#include "dataDbzeroDB.h"
#include "datatoRFLO.h"
#include "datatoMMXU.h"

/*******************************************************
 * MR5_600
 *******************************************************/
#if defined (MR5_600)
#include "static_model_MR5_600.h"

/*******************************************************
 * заглушки
 *******************************************************/
int		Set_RFLO	(uint16_t QTnum, uint64_t currentTime ){return false;}

#endif
/*******************************************************
 * MR851
 *******************************************************/
#if defined (MR851)
#include "static_model_MR851.h"

/*******************************************************
 * заглушки
 *******************************************************/
int		Set_RFLO	(uint16_t QTnum, uint64_t currentTime ){return false;}

#endif
/*******************************************************
 * MR901 MR902
 *******************************************************/
#if defined (MR901) || defined (MR902)
#include "static_model_MR901_902.h"
/*******************************************************
 * заглушки
 *******************************************************/
int		Set_RFLO	(uint16_t QTnum, uint64_t currentTime ){return false;}

#endif
/*******************************************************
 * MR801
 *******************************************************/
#if defined	(MR801)

/*******************************************************
 * заглушки
 *******************************************************/
int		Set_RFLO	(uint16_t QTnum, uint64_t currentTime ){return false;}

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

/*******************************************************
 * Set_RFLO наполняем оперативными данными
 *
 * узел проверен.(Ломан)
 * MR761	-	11.01.2018.
 * RFLO (проверка с db) - ок.
 *******************************************************/
int		Set_RFLO	(uint16_t QTnum, uint64_t currentTime )
{
	int		ret = false;
	uint32_t	Health = STVALINT32_OK;
	uint32_t	Mod = STVALINT32_OFF;

	float	mag,premag,level;

	float	dbLevel=0;
	float	zeroDbLevel=0;
	float	K,K_dbLevel;

	int		Qual;
	int 	i;
	int		Ln;
	int		Lnerr;
	float 	pos;

	float	Xl[5],L[5];

	//  Mod Beh

				if (ucMUstavkiInBuf[MB_StartConfig_Z_CrashDetect + MB_offset_Z_CrashDetect_Config] & MB_bOffset_Z_CrashDetect_Config_Stat) {Mod = STVALINT32_ON;}
				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_RFLO1_Mod_stVal, Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_RFLO1_Mod_t, currentTime);
					if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_RFLO1_Beh_stVal, Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_RFLO1_Beh_t, currentTime);
				}

			Health = STVALINT32_OK;

				if (ucMDiscInBuf[MB_offset_errorM5] & MB_bOffsetModule5) {Health = STVALINT32_Warning;}
				if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {Health = STVALINT32_Warning;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_RFLO1_Health_stVal, Health))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_RFLO1_Health_t, currentTime);


	//  Quality (Mod Beh)
				Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_MES_RFLO1_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_MES_RFLO1_Beh_q,Qual);
//				IedServer_updateQuality(iedServer,&iedModel_MES_RFLO1_Health_q,Qual);

				if (Mod != STVALINT32_ON) {
					IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_RFLO1_Fltz_cVal_mag_f,0);
					if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_RFLO1_Fltz_instCVal_mag_f,0)){
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_RFLO1_Fltz_t, currentTime);
					}

					IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_RFLO1_FltDiskm_mag_f,0);
					if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_RFLO1_FltDiskm_instMag_f,0)){
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_RFLO1_FltDiskm_t, currentTime);
					}
					return ret;
				}

	// Fltz
	//		(страница памяти 0Eh 31-е слово)*(141E hex 0-е слово+1-е слово+..+4е слово)/(256*1000)

			Xl[0] = (float)ucMUstavkiInBuf[MB_offset_Z_CrashDetect_X1f];
			Xl[1] = (float)ucMUstavkiInBuf[MB_offset_Z_CrashDetect_X2f];
			Xl[2] = (float)ucMUstavkiInBuf[MB_offset_Z_CrashDetect_X3f];
			Xl[3] = (float)ucMUstavkiInBuf[MB_offset_Z_CrashDetect_X4f];
			Xl[4] = (float)ucMUstavkiInBuf[MB_offset_Z_CrashDetect_X5f];
			L[0] = 0;
			L[1] = ucMUstavkiInBuf[MB_offset_Z_CrashDetect_L1];
			L[2] = ucMUstavkiInBuf[MB_offset_Z_CrashDetect_L2];
			L[3] = ucMUstavkiInBuf[MB_offset_Z_CrashDetect_L3];
			L[4] = ucMUstavkiInBuf[MB_offset_Z_CrashDetect_L4];

			// число введённых участков
			Ln = ucMUstavkiInBuf[MB_StartConfig_Z_CrashDetect + MB_offset_Z_CrashDetect_Config] & MB_bOffset_Z_CrashDetect_Config_Stat;

			mag = 0;
			pos = 0;			// сумма предыдущих линий до повреждения
			if (Ln>0){
				if (Ln>1){
					for (i=0;i<Ln-1;i++){
						if (ucMAnalogInBuf[MB_offset_OMP] < (pos + (float)ucMUstavkiInBuf[MB_offset_Z_CrashDetect_L1+i])) break;
						pos = pos + (float)ucMUstavkiInBuf[MB_offset_Z_CrashDetect_L1+i];
					}
					Lnerr = i+1;			// нашли участок с повреждением
				} else{
					Lnerr = 1;
				}

				mag =  (float)ucMAnalogInBuf[MB_offset_OMP] - pos;
				mag *= (float)ucMUstavkiInBuf[MB_offset_Z_CrashDetect_X1f+Lnerr-1];

				float	sum=0;	// сумма предыдущих сопротивлений
				if (Lnerr>1){		// если сложили хоть чтото.
					for (i=0;i<Lnerr-1;i++) sum = sum + ((float)ucMUstavkiInBuf[MB_offset_Z_CrashDetect_X1f+i] * (float)ucMUstavkiInBuf[MB_offset_Z_CrashDetect_L1+i]);
				}
				mag += sum;
			}

			K = GetRealU(256,ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Ktnf]);
			K = K / (float)ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Kttf];
			if (ucMUstavkiInBuf[MB_StartConfigTRMeas + MB_offset_Ktt] & MB_bOffset_Ktt_I_Input ) K = K*5;
			mag =  mag * K / (float)(256*0x8000);

			K_dbLevel = (float)range_maxZ * K /(float)DbPercent;		// 0,00001%
			dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_RFLO1_Fltz_db)* K_dbLevel;
			zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_RFLO1_Fltz_zeroDb)* K_dbLevel;

//Fltz
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_RFLO1_Fltz_instCVal_mag_f,mag)){
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_RFLO1_Fltz_t, currentTime);
				// качество меняем на момент изменения данных
				Qual = QUALITY_VALIDITY_GOOD;
				if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
				if (ucMDiscInBuf[MB_offset_errorM5] & MB_bOffsetModule5) 		Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
				IedServer_updateQuality(iedServer,&iedModel_MES_RFLO1_Fltz_q,Qual);

//			USART_TRACE_BLUE("RFLO. K=%f, K_dbLevel=%f, instMag=%f, zeroDbLevel=%f, dbLevel=%f\n", K, K_dbLevel, mag, zeroDbLevel, dbLevel);
			}

			premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_RFLO1_Fltz_cVal_mag_f);
			if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}
			if (level > dbLevel) {
				if (mag<zeroDbLevel) mag = 0;
				IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_RFLO1_Fltz_cVal_mag_f,mag);
			}else{
				if (mag<zeroDbLevel) IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_RFLO1_Fltz_cVal_mag_f,0);
			}

//Fltz
//			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_RFLO1_Fltz_mag_f,mag))
//				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_RFLO1_Fltz_t, currentTime);

			K_dbLevel = (float)range_maxZ /(float)DbPercent;		// 0,00001%
			dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_RFLO1_FltDiskm_db)* K_dbLevel;
			zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_RFLO1_FltDiskm_zeroDb)* K_dbLevel;

			mag = (float)ucMAnalogInBuf[MB_offset_OMP] / 256;

			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_RFLO1_FltDiskm_instMag_f,mag)){
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_RFLO1_FltDiskm_t, currentTime);
				// качество меняем на момент изменения данных
				Qual = QUALITY_VALIDITY_GOOD;
				if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
				if (ucMDiscInBuf[MB_offset_errorM5] & MB_bOffsetModule5) 		Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
					IedServer_updateQuality(iedServer,&iedModel_MES_RFLO1_FltDiskm_q,Qual);
			}
			premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_RFLO1_FltDiskm_mag_f);
			if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}
			if (level > dbLevel) {
				if (mag<zeroDbLevel) mag = 0;
				IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_RFLO1_FltDiskm_mag_f,mag);
			}else{
				if (mag<zeroDbLevel) IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_RFLO1_FltDiskm_mag_f,0);
			}

//FltDiskm
//			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_RFLO1_FltDiskm_mag_f,mag))
//				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_RFLO1_FltDiskm_t, currentTime);

	return ret;
}

#endif
/*******************************************************
 * MR5_500
 *******************************************************/
#if defined	(MR5_500)

#include "static_model_MR5_500.h"

/*******************************************************
 * заглушки
 *******************************************************/
int		Set_RFLO		(uint16_t QTnum, uint64_t currentTime ){return false;}

#endif
/*******************************************************
 * MR5_700
 *******************************************************/
#if defined	(MR5_700) || defined (MR741)

#include "static_model_MR5_700.h"

extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
extern uint16_t   ucMUstavkiInBuf[MB_NumbUstavki];

//	MMXU1  MB_bOffsetModule4
//	MMXU2  MB_bOffsetModule4
//	MMXU3  MB_bOffsetModule5
//	MMXU4  MB_bOffsetModule5

/*******************************************************
 * Set_RFLO наполняем оперативными данными
 *******************************************************/
int		Set_RFLO	(uint16_t QTnum, uint64_t currentTime )
{
	int	ret = false;
	float	mag,premag,level,dbLevel=0,zeroDbLevel=0;
	uint32_t	Health = STVALINT32_OK;
	uint32_t	Mod = STVALINT32_OFF;

	float	K;

//  Mod Beh
		if (ucMUstavkiInBuf[MB_StartConfig_OMP + MB_offset_OMP_Config] & MB_bOffset_OMP_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_RFLO1_Mod_stVal, Mod)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_RFLO1_Mod_t, currentTime);
				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_RFLO1_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_RFLO1_Beh_t, currentTime);
		}

		Health = STVALINT32_OK;
		if ((ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1)>0) {Health = STVALINT32_Warning;}
		if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)>0) {Health = STVALINT32_Warning;}

		if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_RFLO1_Health_stVal, Health))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_RFLO1_Health_t, currentTime);

//  Quality (Mod Beh)
		int	Qual = QUALITY_VALIDITY_GOOD;
		if (ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

		IedServer_updateQuality(iedServer,&iedModel_MES_RFLO1_Mod_q,Qual);
		IedServer_updateQuality(iedServer,&iedModel_MES_RFLO1_Beh_q,Qual);

		if (Mod != STVALINT32_ON) {
			IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_RFLO1_Fltz_cVal_mag_f,0);
			if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_RFLO1_Fltz_instCVal_mag_f,0)){
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_RFLO1_Fltz_t, currentTime);
			}

			IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_RFLO1_FltDiskm_mag_f,0);
			if (IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_RFLO1_FltDiskm_instMag_f,0)){
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_RFLO1_FltDiskm_t, currentTime);
			}
			return ret;
		}

// Fltz

			K = (float)ucMUstavkiInBuf[MB_StartConfig_OMP + MB_offset_OMP_Rline]/((float)256 * (float)1000);
			mag = (float)ucMAnalogInBuf[MB_offset_OMP] * K;

			int rt = Set_Db_zeroDB_float(mag, (float)range_maxZ * (float)1000,
					&iedModel_MES_RFLO1_Fltz_db,
					&iedModel_MES_RFLO1_Fltz_zeroDb,
					&iedModel_MES_RFLO1_Fltz_instCVal_mag_f,
					&iedModel_MES_RFLO1_Fltz_cVal_mag_f,
					&iedModel_MES_RFLO1_Fltz_t,
					currentTime);
			ret  |= rt;
			if (rt){
				// качество меняем на момент изменения данных
				Qual = QUALITY_VALIDITY_GOOD;
				if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
				if (ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetModule1) 		Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
				IedServer_updateQuality(iedServer,&iedModel_MES_RFLO1_Fltz_q,Qual);
	//			USART_TRACE_BLUE("RFLO. K=%f, K_dbLevel=%f, instMag=%f, zeroDbLevel=%f, dbLevel=%f\n", K, K_dbLevel, mag, zeroDbLevel, dbLevel);
			}

// FltDiskm
			mag = (float)ucMAnalogInBuf[MB_offset_OMP] / 256;

			rt = Set_Db_zeroDB_float(mag, (float)range_maxZ,
					&iedModel_MES_RFLO1_FltDiskm_db,
					&iedModel_MES_RFLO1_FltDiskm_zeroDb,
					&iedModel_MES_RFLO1_FltDiskm_instMag_f,
					&iedModel_MES_RFLO1_FltDiskm_mag_f,
					&iedModel_MES_RFLO1_FltDiskm_t,
					currentTime);
			ret  |= rt;
			if (rt) {
				// качество меняем на момент изменения данных
				Qual = QUALITY_VALIDITY_GOOD;
				if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
				if (ucMDiscInBuf[MB_offset_errorM1] & MB_bOffsetModule1) 		Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
					IedServer_updateQuality(iedServer,&iedModel_MES_RFLO1_FltDiskm_q,Qual);

			}
return	ret;
}
#endif

