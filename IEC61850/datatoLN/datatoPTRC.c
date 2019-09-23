/*
 * datatoPTRC.c
 *
 *  Created on: 20.04.2017
 *      Author: sagok
 */



#include "main.h"
#include "IEC850.h"

#include "iec850.h"
#include "iec61850_server.h"
/*******************************************************
 * MR851
 *******************************************************/
#if defined (MR851)
#include "static_model_MR851.h"

/*******************************************************
 * заглушки
 *******************************************************/
int		Set_PTRC	(uint16_t QTnum, uint64_t currentTime ){return false;}

#endif
/*******************************************************
 * MR801
 *******************************************************/
#if defined (MR801)

#if defined	(MR801) && defined (OLD)
#include "static_model_MR801.h"
#endif

#if defined	(MR801) && defined (T12N5D58R51)
#include "static_model_MR801_T12N5D58R51.h"
#endif

extern uint16_t   ucMDiscInBuf[MB_Size_Discreet];


/*******************************************************
 * Set_PTRC наполняем оперативными данными
 *******************************************************/
int		Set_PTRC	(uint16_t QTnum, uint64_t currentTime )
{
	uint32_t	Mod = STVALINT32_OFF;
	uint32_t	Op = 0;
	Quality 	quality = QUALITY_VALIDITY_GOOD;

//Health
			uint32_t	Health = STVALINT32_OK;
			if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {Health = STVALINT32_Warning;}

			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_PTRC_Health_stVal, Health)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_CTRL_PTRC_Health_t, currentTime);
			}


//  Mod Beh
	if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_PTRC_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_CTRL_PTRC_Mod_t, currentTime);
		if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_PTRC_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_CTRL_PTRC_Beh_t, currentTime);
	}

// Op
//	if (ucMDiscInBuf[MB_offset_ErrorOFF] & MB_bOffsetErrorOFF)  Op = 1;

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op_general, Op)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op_t, currentTime);
//		quality = QUALITY_VALIDITY_GOOD;
	}

	quality = QUALITY_VALIDITY_GOOD;
	if (Health == STVALINT32_Warning)	quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
	IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op_q,quality);


}
#endif
/*******************************************************
 * MR761OBR
 *******************************************************/
#if defined (MR761OBR)

/*******************************************************
 * заглушки
 *******************************************************/

int		Set_PTRC	(uint16_t QTnum, uint64_t currentTime ){return false;}

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

extern uint16_t   ucMDiscInBuf[MB_Size_Discreet];


/*******************************************************
 * Set_PTRC наполняем оперативными данными
 *******************************************************/
int		Set_PTRC	(uint16_t QTnum, uint64_t currentTime )
{
	uint32_t	Mod = STVALINT32_OFF;
	uint32_t	Op = 0;
	Quality 	quality = QUALITY_VALIDITY_GOOD;//QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;

//Health
			uint32_t	Health = STVALINT32_OK;
			if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {Health = STVALINT32_Warning;}

			if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_PTRC_Health_stVal, Health)){
				IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_CTRL_PTRC_Health_t, currentTime);
			}


//  Mod Beh
	if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_PTRC_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_CTRL_PTRC_Mod_t, currentTime);
		if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_PTRC_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_CTRL_PTRC_Beh_t, currentTime);
	}

// Op
//	if (ucMDiscInBuf[MB_offset_ErrorOFF] & MB_bOffsetErrorOFF)  Op = 1;

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op_general, Op)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op_t, currentTime);
//		quality = QUALITY_VALIDITY_GOOD;
	}

	quality = QUALITY_VALIDITY_GOOD;
	if (Health == STVALINT32_Warning)	quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
	IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op_q,quality);

}
#endif

/*******************************************************
 * MR901 MR902
 *******************************************************/
#if defined	(MR901) || defined	(MR902)
#include "static_model_MR901_902.h"

extern uint16_t   ucMDiscInBuf[MB_Size_Discreet];

/*******************************************************
 * Set_PTRC наполняем оперативными данными
 *******************************************************/
int		Set_PTRC	(uint16_t QTnum, uint64_t currentTime )
{
	uint32_t	Mod = false;
	Quality 	quality;
	uint32_t	Health;

//Health
		Health = STVALINT32_OK;
		if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) 		{Health = STVALINT32_Warning;}

		if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_PTRC_Health_stVal, Health))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_CTRL_PTRC_Health_t, currentTime);


	quality = QUALITY_VALIDITY_GOOD;
	if ((ucMDiscInBuf[MB_offset_errorUstavki] & MB_bOffset_errorUstavki)) {quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;}
	if (IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op1_q,quality)){
		IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op2_q,quality);
		IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op3_q,quality);
		IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op4_q,quality);
		IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op5_q,quality);
		IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op6_q,quality);
		IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op7_q,quality);
		IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op8_q,quality);
		IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op9_q,quality);
		IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op10_q,quality);
		IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op11_q,quality);
		IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op12_q,quality);
		IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op13_q,quality);
		IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op14_q,quality);
		IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op15_q,quality);
		IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op16_q,quality);
		IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op17_q,quality);
		IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op18_q,quality);
		IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op19_q,quality);
		IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op20_q,quality);

#if  defined (T24N0D24R51) || defined (T24N0D32R43) || defined (T24N0D40R35) || defined (T20N4D40R35)
		IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op21_q,quality);
		IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op22_q,quality);
		IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op23_q,quality);
		IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op24_q,quality);
#endif
#if  defined (T24N0D24R51) || defined (T24N0D32R43) || defined (T24N0D40R35)
		IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op25_q,quality);
		IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op26_q,quality);
		IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op27_q,quality);
		IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op28_q,quality);
#endif

		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op1_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op2_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op3_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op4_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op5_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op6_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op7_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op8_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op9_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op10_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op11_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op12_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op13_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op14_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op15_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op16_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op17_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op18_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op19_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op20_t, currentTime);

#if  defined (T24N0D24R51) || defined (T24N0D32R43) || defined (T24N0D40R35) || defined (T20N4D40R35)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op21_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op22_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op23_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op24_t, currentTime);
#endif
#if  defined (T24N0D24R51) || defined (T24N0D32R43) || defined (T24N0D40R35)
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op25_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op26_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op27_t, currentTime);
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op28_t, currentTime);
#endif
	}

// Op
//	if (ucMDiscInBuf[MB_offset_ErrorOFF] & MB_bOffsetErrorOFF)  Mod = true;

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op1_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op1_t, currentTime);

	}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op2_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op2_t, currentTime);
	}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op3_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op3_t, currentTime);
	}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op4_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op4_t, currentTime);
	}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op5_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op5_t, currentTime);
	}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op6_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op6_t, currentTime);
	}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op7_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op7_t, currentTime);
	}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op8_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op8_t, currentTime);
	}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op9_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op9_t, currentTime);
	}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op10_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op10_t, currentTime);
	}
#if defined	(MR901)
	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op11_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op11_t, currentTime);
	}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op12_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op12_t, currentTime);
	}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op13_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op13_t, currentTime);
	}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op14_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op14_t, currentTime);
	}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op15_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op15_t, currentTime);
	}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op16_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op16_t, currentTime);
	}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op17_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op17_t, currentTime);
	}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op18_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op18_t, currentTime);
	}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op19_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op19_t, currentTime);
	}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op20_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op20_t, currentTime);
	}

#if  defined (T24N0D24R51) || defined (T24N0D32R43) || defined (T24N0D40R35) || defined (T20N4D40R35)

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op21_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op21_t, currentTime);
	}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op22_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op22_t, currentTime);
	}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op23_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op23_t, currentTime);
	}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op24_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op24_t, currentTime);
	}
#endif
#if  defined (T24N0D24R51) || defined (T24N0D32R43) || defined (T24N0D40R35)
	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op25_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op25_t, currentTime);
	}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op26_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op26_t, currentTime);
	}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op27_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op27_t, currentTime);
	}

	if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op28_general, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op28_t, currentTime);
	}
#endif

#endif

}
#endif
/*******************************************************
 * MR5_700, MR5_500
 *******************************************************/
#if defined (MR5_700) || defined (MR5_600) || defined (MR5_500) || defined (MR741)

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
extern uint16_t   ucMDiscInBuf[MB_Size_Discreet];


/*******************************************************
 * Set_PTRC наполняем оперативными данными
 *******************************************************/
int		Set_PTRC	(uint16_t QTnum, uint64_t currentTime )
{
	uint32_t	Mod = STVALINT32_OFF;
	uint32_t	Op = 0;
	Quality 	quality = QUALITY_VALIDITY_GOOD;//QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;

//Health
	uint32_t	Health = STVALINT32_OK;
	if ((ucMDiscInBuf[MB_offsetHardFaults] & MB_bOffset_errorALLModul)) {Health = STVALINT32_Warning;}

	if (IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_PTRC_Health_stVal, Health)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_CTRL_PTRC_Health_t, currentTime);
	}

//  Mod Beh
	if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_PTRC_Mod_stVal, Mod)){
		IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_CTRL_PTRC_Mod_t, currentTime);
		if ( IedServer_updateInt32AttributeValue(iedServer, &iedModel_CTRL_PTRC_Beh_stVal, Mod))
			IedServer_updateUTCTimeAttributeValue(iedServer,&iedModel_CTRL_PTRC_Beh_t, currentTime);
	}

	// Op
		if (ucMDiscInBuf[MB_offset_ErrorOFF] & MB_bOffsetErrorOFF)  Op = 1;

		if (IedServer_updateBooleanAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op_general, Op)){
			IedServer_updateUTCTimeAttributeValue(iedServer, &iedModel_CTRL_PTRC_Op_t, currentTime);
		}

		quality = QUALITY_VALIDITY_GOOD;
		if (Health == STVALINT32_Warning)	quality = QUALITY_VALIDITY_INVALID | QUALITY_DETAIL_FAILURE;
		IedServer_updateQuality(iedServer,&iedModel_CTRL_PTRC_Op_q,quality);

}
#endif
