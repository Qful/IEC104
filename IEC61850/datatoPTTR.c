/*
 * datatoPTTR.c
 *
 *  Created on: 25.05.2017
 *      Author: sagok
 */



#include "main.h"
#include "IEC850.h"

#include "iec850.h"
#include "iec61850_server.h"

#include "datatoPTTR.h"

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
void	Set_QPTTR	(uint8_t num, uint64_t currentTime )
{
	//Health
				uint32_t	Health = STVALINT32_OK;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5) {Health = STVALINT32_Warning;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_QPTTR1_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_QPTTR1_Health_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_QPTTR2_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_QPTTR2_Health_t, currentTime);

	//  Mod Beh
				uint32_t	Mod;
				if (ucMUstavkiInBuf[MB_offset_Qup_1 + MB_offset_Qup_Config] & MB_bOffset_Qup_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_QPTTR1_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_QPTTR1_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_QPTTR1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_QPTTR1_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Qup_2 + MB_offset_Qup_Config] & MB_bOffset_Qup_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_QPTTR2_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_QPTTR2_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_QPTTR2_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_QPTTR2_Beh_t, currentTime);


	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_QPTTR1_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_QPTTR1_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_QPTTR1_Health_q,Qual);

				IedServer_updateQuality(iedServer,&iedModel_PROT_QPTTR2_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_QPTTR2_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_QPTTR2_Health_q,Qual);

	// Str_general
				bool	Str_general;
				if (ucMDiscInBuf[MB_offset_IO_Qup_1] & MB_b_IO_Qup_1) Str_general = true; else Str_general = false;
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_QPTTR1_Str_general,  Str_general) > 0)			// И0 U>1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_QPTTR1_Str_t, currentTime);
				if (ucMDiscInBuf[MB_offset_IO_Qup_2] & MB_b_IO_Qup_2) Str_general = true; else Str_general = false;
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_QPTTR2_Str_general,  Str_general) > 0)			// И0 U>1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_QPTTR2_Str_t, currentTime);

	// Op_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_QPTTR1_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Qup_1] & MB_b_SRAB_Qup_1) > 0)		// СРАБ I>1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_QPTTR1_Op_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_QPTTR2_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Qup_2] & MB_b_SRAB_Qup_2) > 0)		// СРАБ I>2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_QPTTR2_Op_t, currentTime);


				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_QPTTR1_Str_dirGeneral, 0))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_QPTTR1_Str_t, currentTime);
				if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_QPTTR2_Str_dirGeneral, 0))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_QPTTR2_Str_t, currentTime);

	// TmpRI
				float mag = (float)ucMAnalogInBuf[MB_offset_Q_stats] * 256/65535;
				if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_PROT_QPTTR1_TmpRI_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_QPTTR1_TmpRI_t, currentTime);
				if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_PROT_QPTTR2_TmpRI_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_QPTTR2_TmpRI_t, currentTime);

}
/*******************************************************
 * Set_QPTTR наполняем оперативными данными
 *******************************************************/
void	Set_BLKPTTR	(uint8_t num, uint64_t currentTime )
{
	float	mag;
	float	K;

	//Health
				uint32_t	Health = STVALINT32_OK;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5) {Health = STVALINT32_Warning;}
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
				IedServer_updateQuality(iedServer,&iedModel_PROT_BLKPTTR1_Health_q,Qual);


	// Op_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_BLKPTTR1_Op_general,  ucMDiscInBuf[MB_offset_SRAB_BlkQ] & MB_b_SRAB_BlkQ) > 0)		// СРАБ I>1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_BLKPTTR1_Op_t, currentTime);

	// TmpRI
				mag = (float)ucMAnalogInBuf[MB_offset_Q_stats] * 256/65535;
				if ( IedServer_updateFloatAttributeValue(iedServer,&iedModel_PROT_BLKPTTR1_TmpRI_mag_f,mag))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_BLKPTTR1_TmpRI_t, currentTime);



}
#endif
