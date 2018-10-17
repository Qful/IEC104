/*
 * datatoPTTR.c
 *
 *  Created on: 25.05.2017
 *      Author: sagok
 */



#include "main.h"

#include "iec850.h"
#include "iec61850_server.h"

#include "datatoPTTR.h"

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
int		Set_QPTTR		(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_BLKPTTR		(uint16_t QTnum, uint64_t currentTime ){return false;}

#endif
/*******************************************************
 * MR851
 *******************************************************/
#if defined (MR851)
#include "static_model_MR851.h"

/*******************************************************
 * заглушки
 *******************************************************/
int		Set_QPTTR	(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_BLKPTTR	(uint16_t QTnum, uint64_t currentTime ){return false;}

#endif
/*******************************************************
 * MR901 MR902
 *******************************************************/
#if defined (MR901) || defined (MR902)
#include "static_model_MR901_902.h"
/*******************************************************
 * заглушки
 *******************************************************/
int		Set_QPTTR	(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_BLKPTTR	(uint16_t QTnum, uint64_t currentTime ){return false;}

#endif
/*******************************************************
 * MRMR801
 *******************************************************/
#if defined	(MR801)

/*******************************************************
 * заглушки
 *******************************************************/
int		Set_QPTTR	(uint16_t QTnum, uint64_t currentTime ){return false;}
int		Set_BLKPTTR	(uint16_t QTnum, uint64_t currentTime ){return false;}

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
 * Set_QPTTR наполняем оперативными данными
 *******************************************************/
int		Set_QPTTR	(uint16_t QTnum, uint64_t currentTime )
{
	int	ret = false;
	//Health
				uint32_t	Health = STVALINT32_OK;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5) {Health = STVALINT32_Warning;}
				if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {Health = STVALINT32_Warning;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_QPTTR1_Health_stVal, Health)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_QPTTR1_Health_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_QPTTR2_Health_stVal, Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_QPTTR2_Health_t, currentTime);
				}

	//  Mod Beh
				uint32_t	Mod;
				if (ucMUstavkiInBuf[MB_offset_Qup_1 + MB_offset_Qup_Config] & MB_bOffset_Qup_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_QPTTR1_Mod_stVal, Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_QPTTR1_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_QPTTR1_Beh_stVal, Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_QPTTR1_Beh_t, currentTime);
				}

				if (ucMUstavkiInBuf[MB_offset_Qup_2 + MB_offset_Qup_Config] & MB_bOffset_Qup_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_QPTTR2_Mod_stVal, Mod)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_QPTTR2_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_QPTTR2_Beh_stVal, Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_QPTTR2_Beh_t, currentTime);
				}


	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_QPTTR1_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_QPTTR1_Beh_q,Qual);
				//IedServer_updateQuality(iedServer,&iedModel_PROT_QPTTR1_Health_q,Qual);

				IedServer_updateQuality(iedServer,&iedModel_PROT_QPTTR2_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_QPTTR2_Beh_q,Qual);
				//IedServer_updateQuality(iedServer,&iedModel_PROT_QPTTR2_Health_q,Qual);

	// Str_general
				bool	Str_general;
				if (ucMDiscInBuf[MB_offset_IO_Qup_1] & MB_b_IO_Qup_1) Str_general = true; else Str_general = false;
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_QPTTR1_Str_general,  Str_general) > 0)			// И0 U>1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_QPTTR1_Str_t, currentTime);
				if (ucMDiscInBuf[MB_offset_IO_Qup_2] & MB_b_IO_Qup_2) Str_general = true; else Str_general = false;
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_QPTTR2_Str_general,  Str_general) > 0)			// И0 U>1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_QPTTR2_Str_t, currentTime);

	// Op_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_QPTTR1_Op_general,  ucMDiscInBuf[MB_offset_IO_Qup_1] & MB_b_IO_Qup_1) > 0)		// IO I>1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_QPTTR1_Op_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_QPTTR2_Op_general,  ucMDiscInBuf[MB_offset_IO_Qup_2] & MB_b_IO_Qup_2) > 0)		// IO I>2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_QPTTR2_Op_t, currentTime);


				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_QPTTR1_Str_dirGeneral, 0)){
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_QPTTR1_Str_t, currentTime);
					if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_QPTTR2_Str_dirGeneral, 0))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_QPTTR2_Str_t, currentTime);
				}

	// TmpRI
				float mag = (float)ucMAnalogInBuf[MB_offset_Q_stats] * (float)256/(float)65535;
/*
				if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_PROT_QPTTR1_TmpRI_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_QPTTR1_TmpRI_t, currentTime);
				if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_PROT_QPTTR2_TmpRI_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_QPTTR2_TmpRI_t, currentTime);
*/

				ret |= 	Set_Db_zeroDB_float(mag, 256,
						&iedModel_PROT_QPTTR1_TmpRI_db,
						&iedModel_PROT_QPTTR1_TmpRI_zeroDb,
						&iedModel_PROT_QPTTR1_TmpRI_instMag_f,
						&iedModel_PROT_QPTTR1_TmpRI_mag_f,
						&iedModel_PROT_QPTTR1_TmpRI_t,
						currentTime);
				ret |= 	Set_Db_zeroDB_float(mag, 256,
						&iedModel_PROT_QPTTR2_TmpRI_db,
						&iedModel_PROT_QPTTR2_TmpRI_zeroDb,
						&iedModel_PROT_QPTTR2_TmpRI_instMag_f,
						&iedModel_PROT_QPTTR2_TmpRI_mag_f,
						&iedModel_PROT_QPTTR2_TmpRI_t,
						currentTime);

			Quality quality = QUALITY_VALIDITY_GOOD;
			if (Health == STVALINT32_Warning)	quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;

			IedServer_updateQuality(iedServer,&iedModel_PROT_QPTTR1_Str_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_QPTTR1_Op_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_QPTTR1_TmpRI_q,quality);


			IedServer_updateQuality(iedServer,&iedModel_PROT_QPTTR2_Str_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_QPTTR2_Op_q,quality);
			IedServer_updateQuality(iedServer,&iedModel_PROT_QPTTR2_TmpRI_q,quality);

return	ret;
}
/*******************************************************
 * Set_QPTTR наполняем оперативными данными
 *******************************************************/
int		Set_BLKPTTR	(uint16_t QTnum, uint64_t currentTime )
{
	int		ret = false;
	float	mag,premag,level;
	float	dbLevel=0;
	float	zeroDbLevel=0;
	float	K,K_dbLevel;

	//Health
				uint32_t	Health = STVALINT32_OK;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5) {Health = STVALINT32_Warning;}
				if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffsetUstavki)) {Health = STVALINT32_Warning;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_BLKPTTR1_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_BLKPTTR1_Health_t, currentTime);


	//  Mod Beh
				uint32_t	Mod;
				if (ucMUstavkiInBuf[MB_offset_BlkQ + MB_offset_BlkQ_Config] & MB_bOffset_BlkQ_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_BLKPTTR1_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_BLKPTTR1_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_BLKPTTR1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_BLKPTTR1_Beh_t, currentTime);


	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_BLKPTTR1_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_BLKPTTR1_Beh_q,Qual);
				//IedServer_updateQuality(iedServer,&iedModel_PROT_BLKPTTR1_Health_q,Qual);


	// Op_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_BLKPTTR1_Op_general,  ucMDiscInBuf[MB_offset_IO_BlkQ] & MB_b_IO_BlkQ) > 0)		// СРАБ I>1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_BLKPTTR1_Op_t, currentTime);

	// TmpRI
/*
				K_dbLevel = (float)256 /(float)DbPercent;		// 0,00001%
				dbLevel 	= (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_PROT_BLKPTTR1_TmpRI_db)* K_dbLevel;
				zeroDbLevel = (float)IedServer_getUInt32AttributeValue(iedServer,&iedModel_PROT_BLKPTTR1_TmpRI_zeroDb)* K_dbLevel;

				mag = (float)ucMAnalogInBuf[MB_offset_Q_stats] * 256/65535;

				if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_PROT_BLKPTTR1_TmpRI_instMag_f,mag)){
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_BLKPTTR1_TmpRI_t, currentTime);

				}
				premag = IedServer_getFloatAttributeValue(iedServer,&iedModel_PROT_BLKPTTR1_TmpRI_mag_f);
				if (premag > mag) 	{level = premag - mag;} else {level = mag - premag;}
				if (level > dbLevel) {
					if (mag<zeroDbLevel) mag = 0;
					IedServer_updateFloatAttributeValue(iedServer,&iedModel_PROT_BLKPTTR1_TmpRI_mag_f,mag);
				}else{
					if (mag<zeroDbLevel) IedServer_updateFloatAttributeValue(iedServer,&iedModel_PROT_BLKPTTR1_TmpRI_mag_f,0);
				}
*/
/*
				mag = (float)ucMAnalogInBuf[MB_offset_Q_stats] * 256/65535;
				if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_PROT_BLKPTTR1_TmpRI_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_BLKPTTR1_TmpRI_t, currentTime);
*/

				mag = (float)ucMAnalogInBuf[MB_offset_Q_stats] * (float)256/(float)65535;
				ret |= 	Set_Db_zeroDB_float(mag, 256,
						&iedModel_PROT_BLKPTTR1_TmpRI_db,
						&iedModel_PROT_BLKPTTR1_TmpRI_zeroDb,
						&iedModel_PROT_BLKPTTR1_TmpRI_instMag_f,
						&iedModel_PROT_BLKPTTR1_TmpRI_mag_f,
						&iedModel_PROT_BLKPTTR1_TmpRI_t,
						currentTime);

				Quality quality = QUALITY_VALIDITY_GOOD;
				if (Health == STVALINT32_Warning)	quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;

				IedServer_updateQuality(iedServer,&iedModel_PROT_BLKPTTR1_Op_q,quality);
				IedServer_updateQuality(iedServer,&iedModel_PROT_BLKPTTR1_TmpRI_q,quality);



return ret;
}
#endif
