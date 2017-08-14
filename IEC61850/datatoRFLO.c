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

#include "datatoRFLO.h"

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
 * Set_RFLO наполняем оперативными данными
 *******************************************************/
void	Set_RFLO	(uint8_t num, uint64_t currentTime )
{
	uint32_t	Health = STVALINT32_OK;
	float	mag;
	float	K;

	//  Mod Beh
				uint32_t	Mod;
				if (ucMUstavkiInBuf[MB_StartConfig_Z_CrashDetect + MB_offset_Z_CrashDetect_Config] & MB_bOffset_Z_CrashDetect_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_RFLO1_Mod_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_RFLO1_Mod_t, currentTime);
				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_RFLO1_Beh_stVal, Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_RFLO1_Beh_t, currentTime);

	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
//				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_MES_RFLO1_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_MES_RFLO1_Beh_q,Qual);

		Health = STVALINT32_OK;

			if (ucMDiscInBuf[MB_offset_errorM5] & MB_bOffsetModule5) {Health = STVALINT32_Warning;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_RFLO1_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_RFLO1_Health_t, currentTime);

	// Fltz
	//		(страница памяти 0Eh 31-е слово)*(141E hex 0-е слово+1-е слово+..+4е слово)/(256*1000)

			K = (float)ucMUstavkiInBuf[MB_offset_Z_CrashDetect_X1f] + (float)ucMUstavkiInBuf[MB_offset_Z_CrashDetect_X2f] +
				(float)ucMUstavkiInBuf[MB_offset_Z_CrashDetect_X3f] + (float)ucMUstavkiInBuf[MB_offset_Z_CrashDetect_X4f] +
				(float)ucMUstavkiInBuf[MB_offset_Z_CrashDetect_X5f];
			K = K/(float)(256*0x8000);

			mag = (float)ucMAnalogInBuf[MB_offset_OMP] * K;
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_RFLO1_Fltz_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_RFLO1_Fltz_t, currentTime);

			mag = (float)ucMAnalogInBuf[MB_offset_OMP] / 256;
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_RFLO1_FltDiskm_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_RFLO1_FltDiskm_t, currentTime);


}

#endif
/*******************************************************
 * MR5_700
 *******************************************************/
#if defined	(MR5_700)

#include "static_model_MR5_700.h"

extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucMAnalogInBuf[MB_NumbAnalog];
extern uint16_t   ucUstavkiInBuf[MB_NumbUstavki];

//	MMXU1  MB_bOffsetModule4
//	MMXU2  MB_bOffsetModule4
//	MMXU3  MB_bOffsetModule5
//	MMXU4  MB_bOffsetModule5

/*******************************************************
 * Set_RFLO наполняем оперативными данными
 *******************************************************/
void	Set_RFLO	(uint8_t num, uint64_t currentTime )
{
	float	mag,premag,level,dbLevel=0,zeroDbLevel=0;

	uint32_t	Health = STVALINT32_OK;
	float	K;

	//  Mod Beh
			uint32_t	Mod;
			if (ucUstavkiInBuf[MB_StartConfig_OMP + MB_offset_OMP_Config] & MB_bOffset_OMP_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
			if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_RFLO1_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_RFLO1_Mod_t, currentTime);
			if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_RFLO1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_RFLO1_Beh_t, currentTime);

	//  Quality (Mod Beh)
			int	Qual = QUALITY_VALIDITY_GOOD;
//				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
			IedServer_updateQuality(iedServer,&iedModel_MES_RFLO1_Mod_q,Qual);
			IedServer_updateQuality(iedServer,&iedModel_MES_RFLO1_Beh_q,Qual);

			Health = STVALINT32_OK;
			if (ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1) {Health = STVALINT32_Warning;}
			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_MES_RFLO1_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_MES_RFLO1_Health_t, currentTime);

	// Fltz
			K = (float)ucUstavkiInBuf[MB_StartConfig_OMP + MB_offset_OMP_Rline]/(float)(256*1000);

//			dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_RFLO1_Fltz_db)*1000 /(float)DbPercent;
//			zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_RFLO1_Fltz_zeroDb)*1000  / (float)DbPercent;

			mag = (float)ucMAnalogInBuf[MB_offset_OMP] * K;
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_RFLO1_Fltz_cVal_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_RFLO1_Fltz_t, currentTime);
/*
			premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_RFLO1_Fltz_cVal_mag_f);
			if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}
			if (level > dbLevel) {
				if (mag<zeroDbLevel) mag = 0;
				IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_RFLO1_Fltz_cVal_mag_f,mag);
			}else{
				if (mag<zeroDbLevel) IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_RFLO1_Fltz_cVal_mag_f,0);
			}
*/

    // FltDiskm
//			dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_RFLO1_FltDiskm_db) /(float)DbPercent;
//			zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_MES_RFLO1_FltDiskm_zeroDb)  / (float)DbPercent;

			mag = (float)ucMAnalogInBuf[MB_offset_OMP] / 256;
			if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_RFLO1_FltDiskm_mag_f,mag))
				IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_MES_RFLO1_FltDiskm_t, currentTime);
/*
			premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_MES_RFLO1_FltDiskm_mag_f);
			if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}
			if (level > dbLevel) {
				if (mag<zeroDbLevel) mag = 0;
				IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_RFLO1_FltDiskm_mag_f,mag);
			}else{
				if (mag<zeroDbLevel) IedServer_updateFloatAttributeValue(iedServer,&iedModel_MES_RFLO1_FltDiskm_mag_f,0);
			}
*/
}

#endif

