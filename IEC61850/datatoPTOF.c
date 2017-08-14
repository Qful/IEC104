/*
 * datatoPTOF.c
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



extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucMUstavkiInBuf[MB_NumbUstavki];



/*******************************************************
 * Set_UPTOF наполняем оперативными данными
 *******************************************************/
void	Set_PTOF	(uint8_t num, uint64_t currentTime )
{
	//Health
				uint32_t	Health = STVALINT32_OK;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5) {Health = STVALINT32_Warning;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTOF1_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTOF1_Health_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTOF2_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTOF2_Health_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTOF3_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTOF3_Health_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTOF4_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTOF4_Health_t, currentTime);

	//  Mod Beh
				uint32_t	Mod;
				if (ucMUstavkiInBuf[MB_offset_Fup_1 + MB_offset_Fup_Config] & MB_bOffset_Fup_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTOF1_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTOF1_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTOF1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTOF1_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Fup_2 + MB_offset_Fup_Config] & MB_bOffset_Fup_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTOF2_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTOF2_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTOF2_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTOF2_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Fup_3 + MB_offset_Fup_Config] & MB_bOffset_Fup_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTOF3_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTOF3_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTOF3_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTOF3_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Fup_4 + MB_offset_Fup_Config] & MB_bOffset_Fup_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTOF4_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTOF4_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTOF4_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTOF4_Beh_t, currentTime);

	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF1_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF1_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF1_Health_q,Qual);

				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF2_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF2_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF2_Health_q,Qual);

				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF3_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF3_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF3_Health_q,Qual);

				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF4_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF4_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF4_Health_q,Qual);


	// Str_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTOF1_Str_general,  ucMDiscInBuf[MB_offset_IO_Fup_1] & MB_b_IO_Fup1) > 0)			// И0 >1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTOF1_Str_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTOF2_Str_general,  ucMDiscInBuf[MB_offset_IO_Fup_2] & MB_b_IO_Fup2) > 0)			// И0 >2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTOF2_Str_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTOF3_Str_general,  ucMDiscInBuf[MB_offset_IO_Fup_3] & MB_b_IO_Fup3) > 0)			// И0 >3
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTOF3_Str_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTOF4_Str_general,  ucMDiscInBuf[MB_offset_IO_Fup_4] & MB_b_IO_Fup4) > 0)			// И0 >4
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTOF4_Str_t, currentTime);

	// Op_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTOF1_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Fup_1] & MB_b_SRAB_Fup1) > 0)		// СРАБ >1
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTOF1_Op_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTOF2_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Fup_2] & MB_b_SRAB_Fup2) > 0)		// СРАБ >2
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTOF2_Op_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTOF3_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Fup_3] & MB_b_SRAB_Fup3) > 0)		// СРАБ >3
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTOF3_Op_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTOF4_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Fup_4] & MB_b_SRAB_Fup4) > 0)		// СРАБ >4
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTOF4_Op_t, currentTime);


				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF1_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF1_Str_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF2_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF2_Str_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF3_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF3_Str_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF4_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF4_Str_q,0);

}
/*******************************************************
 * Set_UPTUF наполняем оперативными данными
 *******************************************************/
void	Set_PTUF	(uint8_t num, uint64_t currentTime )
{
	//Health
				uint32_t	Health = STVALINT32_OK;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5) {Health = STVALINT32_Warning;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTUF1_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTUF1_Health_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTUF2_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTUF2_Health_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTUF3_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTUF3_Health_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTUF4_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTUF4_Health_t, currentTime);

//  Mod Beh
				uint32_t	Mod;
				if (ucMUstavkiInBuf[MB_offset_Fdn_1 + MB_offset_Fdn_Config] & MB_bOffset_Fdn_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTUF1_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTUF1_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTUF1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTUF1_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Fdn_2 + MB_offset_Fdn_Config] & MB_bOffset_Fdn_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTUF2_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTUF2_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTUF2_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTUF2_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Fdn_3 + MB_offset_Fdn_Config] & MB_bOffset_Fdn_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTUF3_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTUF3_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTUF3_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTUF3_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Fdn_4 + MB_offset_Fdn_Config] & MB_bOffset_Fdn_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTUF4_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTUF4_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTUF4_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTUF4_Beh_t, currentTime);


	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF1_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF1_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF1_Health_q,Qual);

				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF2_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF2_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF2_Health_q,Qual);

				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF3_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF3_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF3_Health_q,Qual);

				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF4_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF4_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF4_Health_q,Qual);

	// Str_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTUF1_Str_general,  ucMDiscInBuf[MB_offset_IO_Fdn_1] & MB_b_IO_Fdn1) > 0)			// И0 >1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTUF1_Str_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTUF2_Str_general,  ucMDiscInBuf[MB_offset_IO_Fdn_2] & MB_b_IO_Fdn2) > 0)			// И0 >2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTUF2_Str_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTUF3_Str_general,  ucMDiscInBuf[MB_offset_IO_Fdn_3] & MB_b_IO_Fdn3) > 0)			// И0 >3
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTUF3_Str_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTUF4_Str_general,  ucMDiscInBuf[MB_offset_IO_Fdn_4] & MB_b_IO_Fdn4) > 0)			// И0 >4
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTUF4_Str_t, currentTime);

	// Op_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTUF1_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Fdn_1] & MB_b_SRAB_Fdn1) > 0)		// СРАБ >1
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTUF1_Op_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTUF2_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Fdn_2] & MB_b_SRAB_Fdn2) > 0)		// СРАБ >2
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTUF2_Op_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTUF3_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Fdn_3] & MB_b_SRAB_Fdn3) > 0)		// СРАБ >3
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTUF3_Op_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTUF4_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Fdn_4] & MB_b_SRAB_Fdn4) > 0)		// СРАБ >4
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTUF4_Op_t, currentTime);



				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF1_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF1_Str_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF2_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF2_Str_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF3_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF3_Str_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF4_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF4_Str_q,0);

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
extern uint16_t   ucMUstavkiInBuf[MB_NumbUstavki];



/*******************************************************
 * Set_UPTOF наполняем оперативными данными
 *******************************************************/
void	Set_PTOF	(uint8_t num, uint64_t currentTime )
{
	//Health
				uint32_t	Health = STVALINT32_OK;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5) {Health = STVALINT32_Warning;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTOF1_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTOF1_Health_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTOF2_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTOF2_Health_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTOF3_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTOF3_Health_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTOF4_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTOF4_Health_t, currentTime);

	//  Mod Beh
				uint32_t	Mod;
				if (ucMUstavkiInBuf[MB_offset_Fup_1 + MB_offset_Fup_Config] & MB_bOffset_Fup_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTOF1_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTOF1_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTOF1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTOF1_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Fup_2 + MB_offset_Fup_Config] & MB_bOffset_Fup_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTOF2_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTOF2_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTOF2_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTOF2_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Fup_3 + MB_offset_Fup_Config] & MB_bOffset_Fup_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTOF3_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTOF3_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTOF3_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTOF3_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Fup_4 + MB_offset_Fup_Config] & MB_bOffset_Fup_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTOF4_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTOF4_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTOF4_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTOF4_Beh_t, currentTime);

	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF1_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF1_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF1_Health_q,Qual);

				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF2_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF2_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF2_Health_q,Qual);

				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF3_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF3_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF3_Health_q,Qual);

				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF4_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF4_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF4_Health_q,Qual);


	// Str_general
				bool	general;
				if (ucMDiscInBuf[MB_offset_IO_Fup_1] & MB_b_IO_Fup1) general = true; else general = false;
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTOF1_Str_general,  general) > 0)			// И0 >1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTOF1_Str_t, currentTime);

				if (ucMDiscInBuf[MB_offset_IO_Fup_2] & MB_b_IO_Fup2) general = true; else general = false;
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTOF2_Str_general,  general) > 0)			// И0 >2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTOF2_Str_t, currentTime);

				if (ucMDiscInBuf[MB_offset_IO_Fup_3] & MB_b_IO_Fup3) general = true; else general = false;
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTOF3_Str_general,  general) > 0)			// И0 >3
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTOF3_Str_t, currentTime);

				if (ucMDiscInBuf[MB_offset_IO_Fup_4] & MB_b_IO_Fup4) general = true; else general = false;
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTOF4_Str_general,  general) > 0)			// И0 >4
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTOF4_Str_t, currentTime);

	// Op_general
				if (ucMDiscInBuf[MB_offset_SRAB_Fup_1] & MB_b_SRAB_Fup1) general = true; else general = false;
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTOF1_Op_general,  general) > 0)		// СРАБ >1
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTOF1_Op_t, currentTime);

				if (ucMDiscInBuf[MB_offset_SRAB_Fup_2] & MB_b_SRAB_Fup2) general = true; else general = false;
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTOF2_Op_general,  general) > 0)		// СРАБ >2
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTOF2_Op_t, currentTime);

				if (ucMDiscInBuf[MB_offset_SRAB_Fup_3] & MB_b_SRAB_Fup3) general = true; else general = false;
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTOF3_Op_general,  general) > 0)		// СРАБ >3
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTOF3_Op_t, currentTime);

				if (ucMDiscInBuf[MB_offset_SRAB_Fup_4] & MB_b_SRAB_Fup4) general = true; else general = false;
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTOF4_Op_general,  general) > 0)		// СРАБ >4
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTOF4_Op_t, currentTime);


				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF1_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF1_Str_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF2_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF2_Str_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF3_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF3_Str_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF4_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF4_Str_q,0);

}
/*******************************************************
 * Set_UPTUF наполняем оперативными данными
 *******************************************************/
void	Set_PTUF	(uint8_t num, uint64_t currentTime )
{
	//Health
				uint32_t	Health = STVALINT32_OK;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5) {Health = STVALINT32_Warning;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTUF1_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTUF1_Health_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTUF2_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTUF2_Health_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTUF3_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTUF3_Health_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTUF4_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTUF4_Health_t, currentTime);

//  Mod Beh
				uint32_t	Mod;
				if (ucMUstavkiInBuf[MB_offset_Fdn_1 + MB_offset_Fdn_Config] & MB_bOffset_Fdn_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTUF1_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTUF1_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTUF1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTUF1_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Fdn_2 + MB_offset_Fdn_Config] & MB_bOffset_Fdn_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTUF2_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTUF2_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTUF2_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTUF2_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Fdn_3 + MB_offset_Fdn_Config] & MB_bOffset_Fdn_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTUF3_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTUF3_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTUF3_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTUF3_Beh_t, currentTime);

				if (ucMUstavkiInBuf[MB_offset_Fdn_4 + MB_offset_Fdn_Config] & MB_bOffset_Fdn_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTUF4_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTUF4_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTUF4_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTUF4_Beh_t, currentTime);


	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF1_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF1_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF1_Health_q,Qual);

				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF2_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF2_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF2_Health_q,Qual);

				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF3_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF3_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF3_Health_q,Qual);

				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF4_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF4_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF4_Health_q,Qual);

	// Str_general
				bool	general;
				if (ucMDiscInBuf[MB_offset_IO_Fdn_1] & MB_b_IO_Fdn1) general = true; else general = false;
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTUF1_Str_general,  general) > 0)			// И0 >1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTUF1_Str_t, currentTime);

				if (ucMDiscInBuf[MB_offset_IO_Fdn_2] & MB_b_IO_Fdn2) general = true; else general = false;
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTUF2_Str_general,  general) > 0)			// И0 >2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTUF2_Str_t, currentTime);

				if (ucMDiscInBuf[MB_offset_IO_Fdn_3] & MB_b_IO_Fdn3) general = true; else general = false;
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTUF3_Str_general,  general) > 0)			// И0 >3
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTUF3_Str_t, currentTime);

				if (ucMDiscInBuf[MB_offset_IO_Fdn_4] & MB_b_IO_Fdn4) general = true; else general = false;
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTUF4_Str_general,  general) > 0)			// И0 >4
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTUF4_Str_t, currentTime);

	// Op_general
				if (ucMDiscInBuf[MB_offset_SRAB_Fdn_1] & MB_b_SRAB_Fdn1) general = true; else general = false;
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTUF1_Op_general,  general) > 0)		// СРАБ >1
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTUF1_Op_t, currentTime);

				if (ucMDiscInBuf[MB_offset_SRAB_Fdn_2] & MB_b_SRAB_Fdn2) general = true; else general = false;
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTUF2_Op_general,  general) > 0)		// СРАБ >2
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTUF2_Op_t, currentTime);

				if (ucMDiscInBuf[MB_offset_SRAB_Fdn_3] & MB_b_SRAB_Fdn3) general = true; else general = false;
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTUF3_Op_general,  general) > 0)		// СРАБ >3
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTUF3_Op_t, currentTime);

				if (ucMDiscInBuf[MB_offset_SRAB_Fdn_4] & MB_b_SRAB_Fdn4) general = true; else general = false;
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTUF4_Op_general,  general) > 0)		// СРАБ >4
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTUF4_Op_t, currentTime);



				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF1_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF1_Str_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF2_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF2_Str_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF3_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF3_Str_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF4_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF4_Str_q,0);

}

#endif
/*******************************************************
 * MR5_700
 *******************************************************/
#if defined (MR5_700)
#include "static_model_MR5_700.h"


extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucUstavkiInBuf[MB_NumbUstavki];
extern uint16_t   ucConfigBufF[MB_NumbConfigF];


/*******************************************************
 * Set_UPTOF наполняем оперативными данными
 *******************************************************/
void	Set_PTOF	(uint8_t num, uint64_t currentTime )
{
	//Health
				uint32_t	Health = STVALINT32_OK;
				if (ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1a) {Health = STVALINT32_Warning;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTOF1_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTOF1_Health_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTOF2_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTOF2_Health_t, currentTime);

	//  Mod Beh
				uint32_t	Mod;
				if (ucConfigBufF[MB_offset_Fup + MB_offset_Fup_Config] & MB_bOffset_Fup_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTOF1_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTOF1_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTOF1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTOF1_Beh_t, currentTime);

				if (ucConfigBufF[MB_offset_Fup2 + MB_offset_Fup_Config] & MB_bOffset_Fup_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTOF2_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTOF2_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTOF2_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTOF2_Beh_t, currentTime);

	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF1_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF1_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF1_Health_q,Qual);

				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF2_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF2_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF2_Health_q,Qual);

	// Str_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTOF1_Str_general,  ucMDiscInBuf[MB_offset_IO_Fup] & MB_b_IO_Fup) > 0)			// И0 >1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTOF1_Str_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTOF2_Str_general,  ucMDiscInBuf[MB_offset_IO_Fup2] & MB_b_IO_Fup2) > 0)			// И0 >2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTOF2_Str_t, currentTime);

	// Op_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTOF1_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Fup] & MB_b_SRAB_Fup) > 0)		// СРАБ >1
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTOF1_Op_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTOF2_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Fup2] & MB_b_SRAB_Fup2) > 0)		// СРАБ >2
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTOF2_Op_t, currentTime);

				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF1_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF1_Str_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF2_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF2_Str_q,0);

}
/*******************************************************
 * Set_UPTUF наполняем оперативными данными
 *******************************************************/
void	Set_PTUF	(uint8_t num, uint64_t currentTime )
{
	//Health
				uint32_t	Health = STVALINT32_OK;
				if (ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1a) {Health = STVALINT32_Warning;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTUF1_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTUF1_Health_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTUF2_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTUF2_Health_t, currentTime);

//  Mod Beh
				uint32_t	Mod;
				if (ucConfigBufF[MB_offset_Fdn + MB_offset_Fdn_Config] & MB_bOffset_Fdn_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTUF1_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTUF1_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTUF1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTUF1_Beh_t, currentTime);

				if (ucConfigBufF[MB_offset_Fdn2 + MB_offset_Fdn_Config] & MB_bOffset_Fdn_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTUF2_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTUF2_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTUF2_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTUF2_Beh_t, currentTime);

	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF1_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF1_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF1_Health_q,Qual);

				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF2_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF2_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF2_Health_q,Qual);

	// Str_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTUF1_Str_general,  ucMDiscInBuf[MB_offset_IO_Fdn] & MB_b_IO_Fdn) > 0)			// И0 >1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTUF1_Str_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTUF2_Str_general,  ucMDiscInBuf[MB_offset_IO_Fdn2] & MB_b_IO_Fdn2) > 0)			// И0 >2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTUF2_Str_t, currentTime);

	// Op_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTUF1_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Fdn] & MB_b_SRAB_Fdn) > 0)		// СРАБ >1
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTUF1_Op_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTUF2_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Fdn2] & MB_b_SRAB_Fdn2) > 0)		// СРАБ >2
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTUF2_Op_t, currentTime);

				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF1_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF1_Str_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF2_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF2_Str_q,0);

}

#endif
/*******************************************************
 * MR5_600
 *******************************************************/
#if defined (MR5_600)
#include "static_model_MR5_600.h"


extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucUstavkiInBuf[MB_NumbUstavki];
extern uint16_t   ucConfigBufF[MB_NumbConfigF];


/*******************************************************
 * Set_UPTOF наполняем оперативными данными
 *******************************************************/
void	Set_PTOF	(uint8_t num, uint64_t currentTime )
{
	//Health
				uint32_t	Health = STVALINT32_OK;
				if (ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1a) {Health = STVALINT32_Warning;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTOF1_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTOF1_Health_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTOF2_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTOF2_Health_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTOF3_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTOF3_Health_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTOF4_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTOF4_Health_t, currentTime);

	//  Mod Beh
				uint32_t	Mod;
				if (ucConfigBufF[MB_offset_Fup + MB_offset_Fup_Config] & MB_bOffset_Fup_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTOF1_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTOF1_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTOF1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTOF1_Beh_t, currentTime);

				if (ucConfigBufF[MB_offset_Fup2 + MB_offset_Fup_Config] & MB_bOffset_Fup_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTOF2_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTOF2_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTOF2_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTOF2_Beh_t, currentTime);

				if (ucConfigBufF[MB_offset_Fup3 + MB_offset_Fup_Config] & MB_bOffset_Fup_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTOF3_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTOF3_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTOF3_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTOF3_Beh_t, currentTime);

				if (ucConfigBufF[MB_offset_Fup4 + MB_offset_Fup_Config] & MB_bOffset_Fup_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTOF4_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTOF4_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTOF4_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTOF4_Beh_t, currentTime);

	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF1_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF1_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF1_Health_q,Qual);

				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF2_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF2_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF2_Health_q,Qual);

				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF3_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF3_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF3_Health_q,Qual);

				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF4_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF4_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF4_Health_q,Qual);

	// Str_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTOF1_Str_general,  ucMDiscInBuf[MB_offset_IO_Fup] & MB_b_IO_Fup) > 0)			// И0 >1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTOF1_Str_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTOF2_Str_general,  ucMDiscInBuf[MB_offset_IO_Fup2] & MB_b_IO_Fup2) > 0)			// И0 >2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTOF2_Str_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTOF3_Str_general,  ucMDiscInBuf[MB_offset_IO_Fup3] & MB_b_IO_Fup3) > 0)			// И0 >2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTOF3_Str_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTOF4_Str_general,  ucMDiscInBuf[MB_offset_IO_Fup4] & MB_b_IO_Fup4) > 0)			// И0 >2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTOF4_Str_t, currentTime);

	// Op_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTOF1_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Fup] & MB_b_SRAB_Fup) > 0)		// СРАБ >1
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTOF1_Op_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTOF2_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Fup2] & MB_b_SRAB_Fup2) > 0)		// СРАБ >2
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTOF2_Op_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTOF3_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Fup3] & MB_b_SRAB_Fup3) > 0)		// СРАБ >2
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTOF3_Op_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTOF4_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Fup4] & MB_b_SRAB_Fup4) > 0)		// СРАБ >2
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTOF4_Op_t, currentTime);

				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF1_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF1_Str_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF2_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF2_Str_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF3_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF3_Str_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF4_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTOF4_Str_q,0);

}
/*******************************************************
 * Set_UPTUF наполняем оперативными данными
 *******************************************************/
void	Set_PTUF	(uint8_t num, uint64_t currentTime )
{
	//Health
				uint32_t	Health = STVALINT32_OK;
				if (ucMDiscInBuf[MB_offsetError_M1] & MB_bOffsetErrModule1a) {Health = STVALINT32_Warning;}

				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTUF1_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTUF1_Health_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTUF2_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTUF2_Health_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTUF3_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTUF3_Health_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTUF4_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTUF4_Health_t, currentTime);

//  Mod Beh
				uint32_t	Mod;
				if (ucConfigBufF[MB_offset_Fdn + MB_offset_Fdn_Config] & MB_bOffset_Fdn_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTUF1_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTUF1_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTUF1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTUF1_Beh_t, currentTime);

				if (ucConfigBufF[MB_offset_Fdn2 + MB_offset_Fdn_Config] & MB_bOffset_Fdn_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTUF2_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTUF2_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTUF2_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTUF2_Beh_t, currentTime);

				if (ucConfigBufF[MB_offset_Fdn3 + MB_offset_Fdn_Config] & MB_bOffset_Fdn_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTUF3_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTUF3_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTUF3_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTUF3_Beh_t, currentTime);

				if (ucConfigBufF[MB_offset_Fdn4+ MB_offset_Fdn_Config] & MB_bOffset_Fdn_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTUF4_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTUF4_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_PTUF4_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_PTUF4_Beh_t, currentTime);

	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF1_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF1_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF1_Health_q,Qual);

				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF2_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF2_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF2_Health_q,Qual);

				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF3_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF3_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF3_Health_q,Qual);

				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF4_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF4_Beh_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF4_Health_q,Qual);

	// Str_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTUF1_Str_general,  ucMDiscInBuf[MB_offset_IO_Fdn] & MB_b_IO_Fdn) > 0)			// И0 >1
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTUF1_Str_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTUF2_Str_general,  ucMDiscInBuf[MB_offset_IO_Fdn2] & MB_b_IO_Fdn2) > 0)			// И0 >2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTUF2_Str_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTUF3_Str_general,  ucMDiscInBuf[MB_offset_IO_Fdn3] & MB_b_IO_Fdn3) > 0)			// И0 >2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTUF3_Str_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTUF4_Str_general,  ucMDiscInBuf[MB_offset_IO_Fdn4] & MB_b_IO_Fdn4) > 0)			// И0 >2
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTUF4_Str_t, currentTime);

	// Op_general
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTUF1_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Fdn] & MB_b_SRAB_Fdn) > 0)		// СРАБ >1
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTUF1_Op_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTUF2_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Fdn2] & MB_b_SRAB_Fdn2) > 0)		// СРАБ >2
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTUF2_Op_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTUF3_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Fdn3] & MB_b_SRAB_Fdn3) > 0)		// СРАБ >2
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTUF3_Op_t, currentTime);
				if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_PTUF4_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Fdn4] & MB_b_SRAB_Fdn4) > 0)		// СРАБ >2
				    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_PTUF4_Op_t, currentTime);

				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF1_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF1_Str_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF2_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF2_Str_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF3_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF3_Str_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF4_Op_q,0);
				IedServer_updateQuality(iedServer,&iedModel_PROT_PTUF4_Str_q,0);

}

#endif
