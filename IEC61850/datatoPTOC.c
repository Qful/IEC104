/*
 * datatoPTOC.c
 *
 *  Created on: 18.04.2017
 *      Author: sagok
 */

#include "main.h"
#include "IEC850.h"
#include "iec61850_server.h"


int16_t		GetDirGeneral(uint8_t	Currdata);
uint8_t		GetDirGeneralInSide(uint8_t		Side);
uint8_t		GetDirGeneralInSideLogic(uint8_t		Side, uint8_t		Logic);


#if defined (MR801)
#include "static_model_MR801.h"

extern uint16_t   ucConfigAWRBuf[MB_NumbConfigAWR];
extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucMUstavkiInBuf[MB_NumbUstavki];

/*******************************************************
 * Set_IPTOC наполняем оперативными данными узлы IPTOC1...8
 *******************************************************/
void	Set_IPTOC	(uint8_t num, uint64_t currentTime )
{
		//Health
					uint32_t	LLN0_Health = STVALINT32_OK;
					if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule4) || (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5)) {LLN0_Health = STVALINT32_Warning;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC1_Health_stVal, LLN0_Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC1_Health_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC2_Health_stVal, LLN0_Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC2_Health_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC3_Health_stVal, LLN0_Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC3_Health_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC4_Health_stVal, LLN0_Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC4_Health_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC5_Health_stVal, LLN0_Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC5_Health_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC6_Health_stVal, LLN0_Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC6_Health_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC7_Health_stVal, LLN0_Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC7_Health_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC8_Health_stVal, LLN0_Health))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC8_Health_t, currentTime);
		//  Mod Beh
					uint32_t	IPTOC_Mod;
					if (ucMUstavkiInBuf[MB_offset_MTZ_I1 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC1_Mod_stVal, IPTOC_Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC1_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC1_Beh_stVal, IPTOC_Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC1_Beh_t, currentTime);

					if (ucMUstavkiInBuf[MB_offset_MTZ_I2 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC2_Mod_stVal, IPTOC_Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC2_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC2_Beh_stVal, IPTOC_Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC2_Beh_t, currentTime);

					if (ucMUstavkiInBuf[MB_offset_MTZ_I3 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC3_Mod_stVal, IPTOC_Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC3_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC3_Beh_stVal, IPTOC_Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC3_Beh_t, currentTime);

					if (ucMUstavkiInBuf[MB_offset_MTZ_I4 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC4_Mod_stVal, IPTOC_Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC4_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC4_Beh_stVal, IPTOC_Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC4_Beh_t, currentTime);

					if (ucMUstavkiInBuf[MB_offset_MTZ_I5 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC5_Mod_stVal, IPTOC_Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC5_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC5_Beh_stVal, IPTOC_Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC5_Beh_t, currentTime);

					if (ucMUstavkiInBuf[MB_offset_MTZ_I6 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC6_Mod_stVal, IPTOC_Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC6_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC6_Beh_stVal, IPTOC_Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC6_Beh_t, currentTime);

					if (ucMUstavkiInBuf[MB_offset_MTZ_I7 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC7_Mod_stVal, IPTOC_Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC7_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC7_Beh_stVal, IPTOC_Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC7_Beh_t, currentTime);

					if (ucMUstavkiInBuf[MB_offset_MTZ_I8 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC8_Mod_stVal, IPTOC_Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC8_Mod_t, currentTime);

					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC8_Beh_stVal, IPTOC_Mod))
						IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC8_Beh_t, currentTime);

		//  Quality (Mod Beh)
					int	Qual = QUALITY_VALIDITY_GOOD;
					if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC1_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC1_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC1_Health_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC2_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC2_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC2_Health_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC3_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC3_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC3_Health_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC4_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC4_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC4_Health_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC5_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC5_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC5_Health_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC6_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC6_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC6_Health_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC7_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC7_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC7_Health_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC8_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC8_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC8_Health_q,Qual);

		// Str_general
					if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Str_general,  ucMDiscInBuf[MB_offset_IO_I_1] & MB_b_IO_I1))				// И0 I>1
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC2_Str_general,  ucMDiscInBuf[MB_offset_IO_I_2] & MB_b_IO_I2) > 0)			// И0 I>2
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC2_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC3_Str_general,  ucMDiscInBuf[MB_offset_IO_I_3] & MB_b_IO_I3) > 0)			// И0 I>3
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC3_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC4_Str_general,  ucMDiscInBuf[MB_offset_IO_I_4] & MB_b_IO_I4) > 0)			// И0 I>4
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC4_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC5_Str_general,  ucMDiscInBuf[MB_offset_IO_I_5] & MB_b_IO_I5) > 0)			// И0 I>5
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC5_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC6_Str_general,  ucMDiscInBuf[MB_offset_IO_I_6] & MB_b_IO_I6) > 0)			// И0 I>6
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC6_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC7_Str_general,  ucMDiscInBuf[MB_offset_IO_I_7] & MB_b_IO_I7) > 0)			// И0 I>7
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC7_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC8_Str_general,  ucMDiscInBuf[MB_offset_IO_I_8] & MB_b_IO_I8) > 0)			// И0 I>8
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC8_Str_t, currentTime);

		// Op_general
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_1] & MB_b_SRAB_I1) > 0)		// СРАБ I>1
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC2_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_2] & MB_b_SRAB_I2) > 0)		// СРАБ I>2
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC2_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC3_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_3] & MB_b_SRAB_I3) > 0)		// СРАБ I>3
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC3_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC4_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_4] & MB_b_SRAB_I4) > 0)		// СРАБ I>4
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC4_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC5_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_5] & MB_b_SRAB_I5) > 0)		// СРАБ I>5
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC5_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC6_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_6] & MB_b_SRAB_I6) > 0)		// СРАБ I>6
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC6_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC7_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_7] & MB_b_SRAB_I7) > 0)		// СРАБ I>7
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC7_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC8_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_8] & MB_b_SRAB_I8) > 0)		// СРАБ I>8
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC8_Op_t, currentTime);

		// Str_dir_general				в зависимости от стороны
					MmsValue* 	ValMMS;		//-----------
					uint8_t		Side;

					Side = (ucMUstavkiInBuf[MB_offset_MTZ_I1 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> _bSideOffset;
					ValMMS = MmsValue_newIntegerFromInt16(GetDirGeneralInSide(Side));
					IedServer_updateAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Str_dirGeneral, ValMMS);
					MmsValue_delete(ValMMS);

					Side = (ucMUstavkiInBuf[MB_offset_MTZ_I2 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> _bSideOffset;
					ValMMS = MmsValue_newIntegerFromInt16(GetDirGeneralInSide(Side));
					IedServer_updateAttributeValue(iedServer, &iedModel_PROT_IPTOC2_Str_dirGeneral, ValMMS);
					MmsValue_delete(ValMMS);

					Side = (ucMUstavkiInBuf[MB_offset_MTZ_I3 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> _bSideOffset;
					ValMMS = MmsValue_newIntegerFromInt16(GetDirGeneralInSide(Side));
					IedServer_updateAttributeValue(iedServer, &iedModel_PROT_IPTOC3_Str_dirGeneral, ValMMS);
					MmsValue_delete(ValMMS);

					Side = (ucMUstavkiInBuf[MB_offset_MTZ_I4 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> _bSideOffset;
					ValMMS = MmsValue_newIntegerFromInt16(GetDirGeneralInSide(Side));
					IedServer_updateAttributeValue(iedServer, &iedModel_PROT_IPTOC4_Str_dirGeneral, ValMMS);
					MmsValue_delete(ValMMS);

					Side = (ucMUstavkiInBuf[MB_offset_MTZ_I5 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> _bSideOffset;
					ValMMS = MmsValue_newIntegerFromInt16(GetDirGeneralInSide(Side));
					IedServer_updateAttributeValue(iedServer, &iedModel_PROT_IPTOC5_Str_dirGeneral, ValMMS);
					MmsValue_delete(ValMMS);

					Side = (ucMUstavkiInBuf[MB_offset_MTZ_I6 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> _bSideOffset;
					ValMMS = MmsValue_newIntegerFromInt16(GetDirGeneralInSide(Side));
					IedServer_updateAttributeValue(iedServer, &iedModel_PROT_IPTOC6_Str_dirGeneral, ValMMS);
					MmsValue_delete(ValMMS);

					Side = (ucMUstavkiInBuf[MB_offset_MTZ_I7 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> _bSideOffset;
					ValMMS = MmsValue_newIntegerFromInt16(GetDirGeneralInSide(Side));
					IedServer_updateAttributeValue(iedServer, &iedModel_PROT_IPTOC7_Str_dirGeneral, ValMMS);
					MmsValue_delete(ValMMS);

					Side = (ucMUstavkiInBuf[MB_offset_MTZ_I8 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Side) >> _bSideOffset;
					ValMMS = MmsValue_newIntegerFromInt16(GetDirGeneralInSide(Side));
					IedServer_updateAttributeValue(iedServer, &iedModel_PROT_IPTOC8_Str_dirGeneral, ValMMS);
					MmsValue_delete(ValMMS);


					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC1_Op_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC1_Str_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC2_Op_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC2_Str_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC3_Op_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC3_Str_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC4_Op_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC4_Str_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC5_Op_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC5_Str_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC6_Op_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC6_Str_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC7_Op_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC7_Str_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC8_Op_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC8_Str_q,0);

}

/*******************************************************
 * Set_I20PTOC наполняем оперативными данными узлы IPTOC1...8
 *******************************************************/
void	Set_I20PTOC	(uint8_t num, uint64_t currentTime )
{
		//Health
					uint32_t	LLN0_Health = STVALINT32_OK;
					if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule4) || (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5)) {LLN0_Health = STVALINT32_Warning;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC1_Health_stVal, LLN0_Health))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC1_Health_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC2_Health_stVal, LLN0_Health))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC2_Health_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC3_Health_stVal, LLN0_Health))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC3_Health_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC4_Health_stVal, LLN0_Health))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC4_Health_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC5_Health_stVal, LLN0_Health))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC5_Health_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC6_Health_stVal, LLN0_Health))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC6_Health_t, currentTime);

		//  Mod Beh
					uint32_t	IPTOC_Mod;
					if (ucMUstavkiInBuf[MB_offset_Ig_I1 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC1_Mod_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC1_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC1_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC1_Beh_t, currentTime);

					if (ucMUstavkiInBuf[MB_offset_Ig_I2 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC2_Mod_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC2_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC2_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC2_Beh_t, currentTime);

					if (ucMUstavkiInBuf[MB_offset_Ig_I3 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC3_Mod_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC3_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC3_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC3_Beh_t, currentTime);

					if (ucMUstavkiInBuf[MB_offset_Ig_I4 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC4_Mod_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC4_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC4_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC4_Beh_t, currentTime);

					if (ucMUstavkiInBuf[MB_offset_Ig_I5 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC5_Mod_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC5_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC5_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC5_Beh_t, currentTime);

					if (ucMUstavkiInBuf[MB_offset_Ig_I6 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC6_Mod_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC6_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC6_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC6_Beh_t, currentTime);


		//  Quality (Mod Beh)
					int	Qual = QUALITY_VALIDITY_GOOD;
					if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC1_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC1_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC1_Health_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC2_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC2_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC2_Health_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC3_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC3_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC3_Health_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC4_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC4_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC4_Health_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC5_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC5_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC5_Health_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC6_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC6_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC6_Health_q,Qual);


		// Str_general
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC1_Str_general,  ucMDiscInBuf[MB_offset_IO_Ig_1] & MB_b_IO_Ig1) > 0)			// И0 I>1
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC1_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC2_Str_general,  ucMDiscInBuf[MB_offset_IO_Ig_2] & MB_b_IO_Ig2) > 0)			// И0 I>2
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC2_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC3_Str_general,  ucMDiscInBuf[MB_offset_IO_Ig_3] & MB_b_IO_Ig3) > 0)			// И0 I>3
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC3_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC4_Str_general,  ucMDiscInBuf[MB_offset_IO_Ig_4] & MB_b_IO_Ig4) > 0)			// И0 I>4
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC4_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC5_Str_general,  ucMDiscInBuf[MB_offset_IO_Ig_5] & MB_b_IO_Ig5) > 0)			// И0 I>5
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC5_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC6_Str_general,  ucMDiscInBuf[MB_offset_IO_Ig_6] & MB_b_IO_Ig6) > 0)			// И0 I>6
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC6_Str_t, currentTime);

		// Op_general
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC1_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Ig_1] & MB_b_SRAB_Ig1) > 0)		// СРАБ I>1
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC1_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC2_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Ig_2] & MB_b_SRAB_Ig2) > 0)		// СРАБ I>2
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC2_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC3_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Ig_3] & MB_b_SRAB_Ig3) > 0)		// СРАБ I>3
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC3_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC4_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Ig_4] & MB_b_SRAB_Ig4) > 0)		// СРАБ I>4
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC4_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC5_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Ig_5] & MB_b_SRAB_Ig5) > 0)		// СРАБ I>5
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC5_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC6_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Ig_6] & MB_b_SRAB_Ig6) > 0)		// СРАБ I>6
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC6_Op_t, currentTime);

		// Str_dir_general				в зависимости от стороны
					MmsValue* 	ValMMS;		//-----------
					uint8_t		Side,Logic;
					uint8_t		DirGeneral;

					Side 		= (ucMUstavkiInBuf[MB_offset_Ig_I1 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Side) >> _bSideOffset;
					Logic		= (ucMUstavkiInBuf[MB_offset_Ig_I1 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Logic) >> _bLogicOffset;
					DirGeneral	= GetDirGeneralInSideLogic(Side,Logic);
					ValMMS = MmsValue_newIntegerFromInt16(DirGeneral);
					IedServer_updateAttributeValue(iedServer, &iedModel_PROT_I20PTOC1_Str_dirGeneral, ValMMS);
					MmsValue_delete(ValMMS);

					Side 		= (ucMUstavkiInBuf[MB_offset_Ig_I2 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Side) >> _bSideOffset;
					Logic		= (ucMUstavkiInBuf[MB_offset_Ig_I2 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Logic) >> _bLogicOffset;
					DirGeneral	= GetDirGeneralInSideLogic(Side,Logic);
					ValMMS = MmsValue_newIntegerFromInt16(DirGeneral);
					IedServer_updateAttributeValue(iedServer, &iedModel_PROT_I20PTOC2_Str_dirGeneral, ValMMS);
					MmsValue_delete(ValMMS);

					Side 		= (ucMUstavkiInBuf[MB_offset_Ig_I3 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Side) >> _bSideOffset;
					Logic		= (ucMUstavkiInBuf[MB_offset_Ig_I3 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Logic) >> _bLogicOffset;
					DirGeneral	= GetDirGeneralInSideLogic(Side,Logic);
					ValMMS = MmsValue_newIntegerFromInt16(DirGeneral);
					IedServer_updateAttributeValue(iedServer, &iedModel_PROT_I20PTOC3_Str_dirGeneral, ValMMS);
					MmsValue_delete(ValMMS);

					Side 		= (ucMUstavkiInBuf[MB_offset_Ig_I4 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Side) >> _bSideOffset;
					Logic		= (ucMUstavkiInBuf[MB_offset_Ig_I4 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Logic) >> _bLogicOffset;
					DirGeneral	= GetDirGeneralInSideLogic(Side,Logic);
					ValMMS = MmsValue_newIntegerFromInt16(DirGeneral);
					IedServer_updateAttributeValue(iedServer, &iedModel_PROT_I20PTOC4_Str_dirGeneral, ValMMS);
					MmsValue_delete(ValMMS);

					Side 		= (ucMUstavkiInBuf[MB_offset_Ig_I5 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Side) >> _bSideOffset;
					Logic		= (ucMUstavkiInBuf[MB_offset_Ig_I5 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Logic) >> _bLogicOffset;
					DirGeneral	= GetDirGeneralInSideLogic(Side,Logic);
					ValMMS = MmsValue_newIntegerFromInt16(DirGeneral);
					IedServer_updateAttributeValue(iedServer, &iedModel_PROT_I20PTOC5_Str_dirGeneral, ValMMS);
					MmsValue_delete(ValMMS);

					Side 		= (ucMUstavkiInBuf[MB_offset_Ig_I6 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Side) >> _bSideOffset;
					Logic		= (ucMUstavkiInBuf[MB_offset_Ig_I6 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Logic) >> _bLogicOffset;
					DirGeneral	= GetDirGeneralInSideLogic(Side,Logic);
					ValMMS = MmsValue_newIntegerFromInt16(DirGeneral);
					IedServer_updateAttributeValue(iedServer, &iedModel_PROT_I20PTOC6_Str_dirGeneral, ValMMS);
					MmsValue_delete(ValMMS);



					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC1_Op_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC1_Str_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC2_Op_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC2_Str_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC3_Op_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC3_Str_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC4_Op_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC4_Str_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC5_Op_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC5_Str_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC6_Op_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC6_Str_q,0);

}

/*******************************************************
 * Set_LZSHPTOC наполняем оперативными данными
 *******************************************************/
void	Set_LZSHPTOC	(uint8_t num, uint64_t currentTime )
{
	//Health
				uint32_t	Health = STVALINT32_OK;
				if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule4) || (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5)) {Health = STVALINT32_Warning;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_LZSHPTOC_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_LZSHPTOC_Health_t, currentTime);

	//  Mod Beh
				uint32_t	Mod;
				if (ucConfigAWRBuf[MB_offset_ConfLZSHAWR] & MB_bOffset_LZSH_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_LZSHPTOC_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_LZSHPTOC_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_LZSHPTOC_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_LZSHPTOC_Beh_t, currentTime);

	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_LZSHPTOC_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_LZSHPTOC_Beh_q,Qual);


	// Str_general
				if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_LZSHPTOC_Str_general,  ucMDiscInBuf[MB_offset_LZSH] & MB_b_Rab_LZSH))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_LZSHPTOC_Str_t, currentTime);

	// Op_general
				if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_LZSHPTOC_Op_general,  ucMDiscInBuf[MB_offset_LZSH] & MB_b_Rab_LZSH))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_LZSHPTOC_Op_t, currentTime);

}
#endif
/*******************************************************
 * MR761
 *******************************************************/
#if defined	(MR761)
#endif
/*******************************************************
 * MR762
 *******************************************************/
#if defined	(MR762)
#endif
/*******************************************************
 * MR763
 *******************************************************/
#if defined	(MR763)
#endif
/*******************************************************
 * MR901
 *******************************************************/
#if defined	(MR901)
#endif
/*******************************************************
 * MR902
 *******************************************************/
#if defined	(MR902)
#endif
/*******************************************************
 * MR771
 *******************************************************/
#if defined	(MR771)
#include "static_model_MR771.h"

extern uint16_t   ucMDiscInBuf[MB_NumbDiscreet];
extern uint16_t   ucMUstavkiInBuf[MB_NumbUstavki];

/*******************************************************
 * Set_IPTOC наполняем оперативными данными узлы IPTOC1...8
 *******************************************************/
void	Set_IPTOC	(uint8_t num, uint64_t currentTime )
{
		//Health
					uint32_t	LLN0_Health = STVALINT32_OK;
					if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule4) || (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5)) {LLN0_Health = STVALINT32_Warning;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC1_Health_stVal, LLN0_Health))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC1_Health_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC2_Health_stVal, LLN0_Health))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC2_Health_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC3_Health_stVal, LLN0_Health))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC3_Health_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC4_Health_stVal, LLN0_Health))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC4_Health_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC5_Health_stVal, LLN0_Health))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC5_Health_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC6_Health_stVal, LLN0_Health))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC6_Health_t, currentTime);

		//  Mod Beh
					uint32_t	IPTOC_Mod;
					if (ucMUstavkiInBuf[MB_offset_MTZ_I1 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC1_Mod_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC1_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC1_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC1_Beh_t, currentTime);

					if (ucMUstavkiInBuf[MB_offset_MTZ_I2 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC2_Mod_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC2_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC2_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC2_Beh_t, currentTime);

					if (ucMUstavkiInBuf[MB_offset_MTZ_I3 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC3_Mod_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC3_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC3_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC3_Beh_t, currentTime);

					if (ucMUstavkiInBuf[MB_offset_MTZ_I4 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC4_Mod_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC4_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC4_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC4_Beh_t, currentTime);

					if (ucMUstavkiInBuf[MB_offset_MTZ_I5 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC5_Mod_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC5_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC5_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC5_Beh_t, currentTime);

					if (ucMUstavkiInBuf[MB_offset_MTZ_I6 + MB_offset_MTZ_I_Config] & MB_bOffset_MTZ_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC6_Mod_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC6_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_IPTOC6_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_IPTOC6_Beh_t, currentTime);


		//  Quality (Mod Beh)
					int	Qual = QUALITY_VALIDITY_GOOD;
					if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC1_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC1_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC1_Health_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC2_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC2_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC2_Health_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC3_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC3_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC3_Health_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC4_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC4_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC4_Health_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC5_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC5_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC5_Health_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC6_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC6_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC6_Health_q,Qual);


		// Str_general
					if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Str_general,  ucMDiscInBuf[MB_offset_IO_I_1] & MB_b_IO_I1))				// И0 I>1
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC2_Str_general,  ucMDiscInBuf[MB_offset_IO_I_2] & MB_b_IO_I2) > 0)			// И0 I>2
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC2_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC3_Str_general,  ucMDiscInBuf[MB_offset_IO_I_3] & MB_b_IO_I3) > 0)			// И0 I>3
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC3_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC4_Str_general,  ucMDiscInBuf[MB_offset_IO_I_4] & MB_b_IO_I4) > 0)			// И0 I>4
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC4_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC5_Str_general,  ucMDiscInBuf[MB_offset_IO_I_5] & MB_b_IO_I5) > 0)			// И0 I>5
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC5_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC6_Str_general,  ucMDiscInBuf[MB_offset_IO_I_6] & MB_b_IO_I6) > 0)			// И0 I>6
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC6_Str_t, currentTime);


		// Op_general
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_1] & MB_b_SRAB_I1) > 0)		// СРАБ I>1
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC1_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC2_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_2] & MB_b_SRAB_I2) > 0)		// СРАБ I>2
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC2_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC3_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_3] & MB_b_SRAB_I3) > 0)		// СРАБ I>3
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC3_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC4_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_4] & MB_b_SRAB_I4) > 0)		// СРАБ I>4
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC4_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC5_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_5] & MB_b_SRAB_I5) > 0)		// СРАБ I>5
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC5_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_IPTOC6_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I_6] & MB_b_SRAB_I6) > 0)		// СРАБ I>6
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_IPTOC6_Op_t, currentTime);


		// Str_dir_general				в зависимости от стороны
					MmsValue* 	ValMMS;		//-----------

					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC1_Op_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC1_Str_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC2_Op_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC2_Str_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC3_Op_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC3_Str_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC4_Op_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC4_Str_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC5_Op_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC5_Str_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC6_Op_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_IPTOC6_Str_q,0);


}

/*******************************************************
 * Set_I20PTOC наполняем оперативными данными узлы IPTOC1...8
 *******************************************************/
void	Set_I20PTOC	(uint8_t num, uint64_t currentTime )
{
		//Health
					uint32_t	LLN0_Health = STVALINT32_OK;
					if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule4) || (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5)) {LLN0_Health = STVALINT32_Warning;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC1_Health_stVal, LLN0_Health))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC1_Health_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC2_Health_stVal, LLN0_Health))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC2_Health_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC3_Health_stVal, LLN0_Health))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC3_Health_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC4_Health_stVal, LLN0_Health))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC4_Health_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC5_Health_stVal, LLN0_Health))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC5_Health_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC6_Health_stVal, LLN0_Health))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC6_Health_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC7_Health_stVal, LLN0_Health))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC7_Health_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC8_Health_stVal, LLN0_Health))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC8_Health_t, currentTime);
		//  Mod Beh
					uint32_t	IPTOC_Mod;
					if (ucMUstavkiInBuf[MB_offset_Ig_I1 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC1_Mod_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC1_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC1_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC1_Beh_t, currentTime);

					if (ucMUstavkiInBuf[MB_offset_Ig_I2 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC2_Mod_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC2_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC2_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC2_Beh_t, currentTime);

					if (ucMUstavkiInBuf[MB_offset_Ig_I3 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC3_Mod_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC3_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC3_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC3_Beh_t, currentTime);

					if (ucMUstavkiInBuf[MB_offset_Ig_I4 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC4_Mod_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC4_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC4_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC4_Beh_t, currentTime);

					if (ucMUstavkiInBuf[MB_offset_Ig_I5 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC5_Mod_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC5_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC5_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC5_Beh_t, currentTime);

					if (ucMUstavkiInBuf[MB_offset_Ig_I6 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC6_Mod_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC6_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC6_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC6_Beh_t, currentTime);

					if (ucMUstavkiInBuf[MB_offset_Ig_I7 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC7_Mod_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC6_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC7_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC6_Beh_t, currentTime);

					if (ucMUstavkiInBuf[MB_offset_Ig_I8 + MB_offset_Ig_I_Config] & MB_bOffset_Ig_I_Config_Stat) {IPTOC_Mod = STVALINT32_ON;} else {IPTOC_Mod = STVALINT32_OFF;}
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC8_Mod_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC6_Mod_t, currentTime);
					if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I20PTOC8_Beh_stVal, IPTOC_Mod))
					IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I20PTOC6_Beh_t, currentTime);


		//  Quality (Mod Beh)
					int	Qual = QUALITY_VALIDITY_GOOD;
					if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC1_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC1_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC1_Health_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC2_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC2_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC2_Health_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC3_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC3_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC3_Health_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC4_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC4_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC4_Health_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC5_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC5_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC5_Health_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC6_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC6_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC6_Health_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC7_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC7_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC7_Health_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC8_Mod_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC8_Beh_q,Qual);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC8_Health_q,Qual);


		// Str_general
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC1_Str_general,  ucMDiscInBuf[MB_offset_IO_Ig_1] & MB_b_IO_Ig1) > 0)			// И0 I>1
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC1_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC2_Str_general,  ucMDiscInBuf[MB_offset_IO_Ig_2] & MB_b_IO_Ig2) > 0)			// И0 I>2
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC2_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC3_Str_general,  ucMDiscInBuf[MB_offset_IO_Ig_3] & MB_b_IO_Ig3) > 0)			// И0 I>3
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC3_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC4_Str_general,  ucMDiscInBuf[MB_offset_IO_Ig_4] & MB_b_IO_Ig4) > 0)			// И0 I>4
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC4_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC5_Str_general,  ucMDiscInBuf[MB_offset_IO_Ig_5] & MB_b_IO_Ig5) > 0)			// И0 I>5
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC5_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC6_Str_general,  ucMDiscInBuf[MB_offset_IO_Ig_6] & MB_b_IO_Ig6) > 0)			// И0 I>6
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC6_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC7_Str_general,  ucMDiscInBuf[MB_offset_IO_Ig_7] & MB_b_IO_Ig7) > 0)			// И0 I>7
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC7_Str_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC8_Str_general,  ucMDiscInBuf[MB_offset_IO_Ig_8] & MB_b_IO_Ig8) > 0)			// И0 I>8
						IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC8_Str_t, currentTime);

		// Op_general
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC1_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Ig_1] & MB_b_SRAB_Ig1) > 0)		// СРАБ I>1
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC1_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC2_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Ig_2] & MB_b_SRAB_Ig2) > 0)		// СРАБ I>2
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC2_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC3_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Ig_3] & MB_b_SRAB_Ig3) > 0)		// СРАБ I>3
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC3_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC4_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Ig_4] & MB_b_SRAB_Ig4) > 0)		// СРАБ I>4
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC4_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC5_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Ig_5] & MB_b_SRAB_Ig5) > 0)		// СРАБ I>5
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC5_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC6_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Ig_6] & MB_b_SRAB_Ig6) > 0)		// СРАБ I>6
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC6_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC7_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Ig_7] & MB_b_SRAB_Ig7) > 0)		// СРАБ I>6
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC7_Op_t, currentTime);
					if( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I20PTOC8_Op_general,  ucMDiscInBuf[MB_offset_SRAB_Ig_8] & MB_b_SRAB_Ig8) > 0)		// СРАБ I>6
					    IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I20PTOC8_Op_t, currentTime);

		// Str_dir_general				в зависимости от стороны
					MmsValue* 	ValMMS;		//-----------
					uint8_t		Side,Logic;
					uint8_t		DirGeneral;


					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC1_Op_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC1_Str_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC2_Op_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC2_Str_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC3_Op_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC3_Str_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC4_Op_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC4_Str_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC5_Op_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC5_Str_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC6_Op_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC6_Str_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC7_Op_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC7_Str_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC8_Op_q,0);
					IedServer_updateQuality(iedServer,&iedModel_PROT_I20PTOC8_Str_q,0);
}
/*******************************************************
 * Set_IPTUC наполняем оперативными данными узлы IPTUC1
 *******************************************************/
void	Set_IPTUC	(uint8_t num, uint64_t currentTime )
{

}
/*******************************************************
 * Set_I2I1PTOC наполняем оперативными данными узлы Set_I2I1PTOC
 *******************************************************/
void	Set_I2I1PTOC	(uint8_t num, uint64_t currentTime )
{
	//Health
				uint32_t	Health = STVALINT32_OK;
				if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule4) || (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetModule5)) {Health = STVALINT32_Warning;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I2I1PTOC1_Health_stVal, Health))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I2I1PTOC1_Health_t, currentTime);

	//  Mod Beh
				uint32_t	Mod;
				if (ucMUstavkiInBuf[MB_offsetConfigI2I1] & MB_bOffset_I2I1_Config_Stat) {Mod = STVALINT32_ON;} else {Mod = STVALINT32_OFF;}
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I2I1PTOC1_Mod_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I2I1PTOC1_Mod_t, currentTime);
				if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_PROT_I2I1PTOC1_Beh_stVal, Mod))
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_PROT_I2I1PTOC1_Beh_t, currentTime);

	//  Quality (Mod Beh)
				int	Qual = QUALITY_VALIDITY_GOOD;
				if (ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffsetUstavki) {Qual = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}

				IedServer_updateQuality(iedServer,&iedModel_PROT_I2I1PTOC1_Mod_q,Qual);
				IedServer_updateQuality(iedServer,&iedModel_PROT_I2I1PTOC1_Beh_q,Qual);

	// Str_general
				if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I2I1PTOC1_Str_general,  ucMDiscInBuf[MB_offset_IO_I2I1] & MB_b_IO_I2I1))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I2I1PTOC1_Str_t, currentTime);

	// Op_general
				if ( IedServer_updateBooleanAttributeValue(iedServer, &iedModel_PROT_I2I1PTOC1_Op_general,  ucMDiscInBuf[MB_offset_SRAB_I2I1] & MB_b_SRAB_I2I1))
					IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_PROT_I2I1PTOC1_Op_t, currentTime);

}
#endif

/*************************************************************************
 * GetDirGeneral
 * функция получения направления тока
 * прямое, оба, обратное, неизвестное
 * Currdata:
 * 	bit0 - Направление мощности по каналу Iа
 * 	bit1 - Ошибка направления мощности по каналу Ia
 * 	bit2 - Направление мощности по каналу Ib
 * 	bit3 - Ошибка направления мощности по каналу Ib
 * 	bit4 - Направление мощности по каналу Iс
 * 	bit5 - Ошибка направления мощности по каналу Iс
 *
 * 	return:
 * 	 0 - прямое
 * 	 1 - Оба
 * 	 2 - Обратное
 * 	 3 - Неизвестное
 *
 *************************************************************************/
int16_t		GetDirGeneral(uint8_t	Currdata){
bool	a,b,c,d,e,f;
bool	g,h;
bool	i,j,k,l;
int16_t	DirOut = 0;

	a = Currdata & 1;
	b = Currdata & 1<<1;
	c = Currdata & 1<<2;
	d = Currdata & 1<<3;
	e = Currdata & 1<<4;
	f = Currdata & 1<<5;

	g = (~a && ~b) || (~c && ~d) || (~e && ~f);
	h = (a && ~b) || (c && ~d) || (e && ~f);

	i = g && ~h;
	j = g && h;
	k = ~g && h;
	l = b && d && e;

		 if (i) DirOut = 0;
	else if (j) DirOut = 1;
	else if (k) DirOut = 2;
	else if (l) DirOut = 3;

return	DirOut;
}

#if defined (MR801)
/*******************************************************************************
 *
 *
 ******************************************************************************/
uint8_t	GetDirGeneralInSide(uint8_t		Side)
{
uint8_t datIn;


	switch	(Side){
	case 0://сторона 1
			datIn =  (ucMDiscInBuf[MB_offsetPTOC_Ia_Side1]>>2) & 0b111111;
		break;
	case 1://сторона 2
			datIn =  ((ucMDiscInBuf[MB_offsetPTOC_Ia_Side2]>>14) & 0b11) | ((ucMDiscInBuf[MB_offsetPTOC_Ib_Side2]<<2) & 0b111100);
		break;
	case 2://сторона 3
			datIn =  (ucMDiscInBuf[MB_offsetPTOC_Ia_Side3]>>10) & 0b111111;
		break;
	}
 return GetDirGeneral(datIn);
}
/*******************************************************************************
 *
 *
 *	DirOut = 0;	прямое
 *	DirOut = 1; оба
 *	DirOut = 2; обратное
 *	DirOut = 3; неизвестно
 ******************************************************************************/
#define Dir_up		0
#define Dir_two		1
#define Dir_down	2
#define Dir_not		3

uint8_t	GetDirGeneralInSideLogic(uint8_t		Side, uint8_t		Logic)
{
uint8_t DirOut = Dir_not;

	switch	(Side){
	case 0://сторона 1
		switch	(Logic){
			case 0://In
				if ((ucMDiscInBuf[MB_offsetPTOC_In_Side1]) & MB_b_dirError_In_Side1) 	DirOut =  Dir_not;	else
				if ((ucMDiscInBuf[MB_offsetPTOC_In_Side1]) & MB_b_direction_In_Side1) 	DirOut =  Dir_down;	else
					DirOut =  Dir_up;
			break;

			case 1://I0
				if ((ucMDiscInBuf[MB_offsetPTOC_I0_Side1]) & MB_b_dirError_I0_Side1) 	DirOut =  Dir_not;	else
				if ((ucMDiscInBuf[MB_offsetPTOC_I0_Side1]) & MB_b_direction_I0_Side1) 	DirOut =  Dir_down;	else
					DirOut =  Dir_up;
			break;

			case 2://I2
				if ((ucMDiscInBuf[MB_offsetPTOC_I2_Side1]) & MB_b_dirError_I2_Side1) 	DirOut =  Dir_not;	else
				if ((ucMDiscInBuf[MB_offsetPTOC_I2_Side1]) & MB_b_direction_I2_Side1) 	DirOut =  Dir_down;	else
					DirOut =  Dir_up;
			break;
		}
		break;

	case 1://сторона 2
		switch	(Logic){
			case 0://In
				if ((ucMDiscInBuf[MB_offsetPTOC_In_Side2]) & MB_b_dirError_In_Side2) 	DirOut =  Dir_not;	else
				if ((ucMDiscInBuf[MB_offsetPTOC_In_Side2]) & MB_b_direction_In_Side2) 	DirOut =  Dir_down;	else
					DirOut =  Dir_up;
			break;
			case 1://I0
				if ((ucMDiscInBuf[MB_offsetPTOC_I0_Side2]) & MB_b_dirError_I0_Side2) 	DirOut =  Dir_not;	else
				if ((ucMDiscInBuf[MB_offsetPTOC_I0_Side2]) & MB_b_direction_I0_Side2) 	DirOut =  Dir_down;	else
					DirOut =  Dir_up;
			break;
			case 2://I2
				if ((ucMDiscInBuf[MB_offsetPTOC_I2_Side2]) & MB_b_dirError_I2_Side2) 	DirOut =  Dir_not;	else
				if ((ucMDiscInBuf[MB_offsetPTOC_I2_Side2]) & MB_b_direction_I2_Side2) 	DirOut =  Dir_down;	else
					DirOut =  Dir_up;
			break;
		}
		break;

	case 2://сторона 3
		switch	(Logic){
			case 0://In
				if ((ucMDiscInBuf[MB_offsetPTOC_In_Side3]) & MB_b_dirError_In_Side3) 	DirOut =  Dir_not;	else
				if ((ucMDiscInBuf[MB_offsetPTOC_In_Side3]) & MB_b_direction_In_Side3) 	DirOut =  Dir_down;	else
					DirOut =  Dir_up;
			break;
			case 1://I0
				if ((ucMDiscInBuf[MB_offsetPTOC_I0_Side3]) & MB_b_dirError_I0_Side3) 	DirOut =  Dir_not;	else
				if ((ucMDiscInBuf[MB_offsetPTOC_I0_Side3]) & MB_b_direction_I0_Side3) 	DirOut =  Dir_down;	else
					DirOut =  Dir_up;
			break;
			case 2://I2
				if ((ucMDiscInBuf[MB_offsetPTOC_I2_Side3]) & MB_b_dirError_I2_Side3) 	DirOut =  Dir_not;	else
				if ((ucMDiscInBuf[MB_offsetPTOC_I2_Side3]) & MB_b_direction_I2_Side3) 	DirOut =  Dir_down;	else
					DirOut =  Dir_up;
			break;
		}
		break;
	}
 return DirOut;
}
#endif
