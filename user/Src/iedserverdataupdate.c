/*
 * iedserverdataupdate.c
 *
 *  Created on: 16.10.2017
 *      Author: sagok
 */

#include "main.h"
#include "IEC850.h"

#include "iec850.h"
#include "iec61850_server.h"

#include "datatoPTOC.h"					// модификация данных в PTOC
#include "datatoPTOV.h"					// модификация данных в PTOV PTUV
#include "datatoPTOF.h"					// модификация данных в PTOF PTUF
#include "datatoGGIO.h"					// модификация данных в
#include "datatoPDIF.h"					// модификация данных в
#include "datatoPDIS.h"
#include "datatoPTTR.h"
#include "datatoRREC.h"					// модификация данных в
#include "datatoCSWI.h"					// модификация данных в
#include "datatoPTRC.h"					// модификация данных в
#include "datatoMMXU.h"
#include "datatoMSQI.h"
#include "datatoRFLO.h"
#include "datatoPDPR.h"
#include "datatoATTC.h"
#include "datatoLLN0LPHD.h"
#include "datatoSG.h"					// изменения группы уставок
#include "datatoRDRE.h"
#include "datatoSPCS.h"

#include "port.h"
#include "dataUpdateFromBase.h"

uint64_t 				currentTime;
uint16_t				PeriodicUpdateNewDataCurr=0;
extern	osThreadId 		IEC850TaskHandle;

extern	IedDataUpdateHandler IedDataUpdateFuncHandlers[IDU_FUNC_HANDLERS_MAX];

/*******************************************************
 * MR....
 *******************************************************/
#if defined	(MR771) || defined	(MR761) || defined	(MR762) || defined	(MR763) || defined	(MR761OBR) ||\
	defined	(MR801) ||\
	defined	(MR901) || defined	(MR902) ||\
	defined (MR5_500) || defined (MR5_600) || defined (MR5_700) || defined (MR741)
#if defined	(MR771)
#include "static_model_MR771.h"
#endif

#if defined	(MR761) || defined	(MR762) || defined	(MR763)
#include "static_model_MR76x.h"
#endif
#if  defined (MR761OBR)
#include "static_model_MR761OBR.h"
#endif
#if defined	(MR801) && defined (OLD)
#include "static_model_MR801.h"
#endif
#if defined	(MR801) && defined (T12N5D58R51)
#include "static_model_MR801_T12N5D58R51.h"
#endif
#if defined	(MR901) || defined	(MR902)
#include "static_model_MR901_902.h"
#endif

#if defined	(MR5_500)
#include "static_model_MR5_500.h"
#endif

#if defined	(MR5_600)
#include "static_model_MR5_600.h"
#endif

#if defined	(MR5_700)
#include "static_model_MR5_700.h"
#endif

#if defined	(MR741)
#include "static_model_MR741.h"
#endif

void	IedServer_PeriodicUpdateNewData(IedServer iedServer)
{
	uint16_t	i;
/*******************************************************
 * наполняем оперативными данными структуру
 * сначала был цикл с освобождением задачи через taskYIELD(); после каждой функции
 * 25062018 переделал на глобальный указатель. Иначе надолго застревала функция на обновлении данных
 * и очень медренно начинала выполнять остальные задачи в таске. Отвечать на MMS запросы и слать сообщения в сеть.
 *******************************************************/
if(IEC850TaskHandle && (iedServer != NULL)){
	IedServer_lockDataModel(iedServer);	// захватываем управление mmsServer'ом

	currentTime = Hal_getTimeInMs();

	i = PeriodicUpdateNewDataCurr;
//	for (i = 0; i < IDU_FUNC_HANDLERS_MAX; i++)														// ищем функцию обработчик
		{
			if (IedDataUpdateFuncHandlers[i].usFunctionCode == 0){
//				break;														// дальше нет обработчиков функций, выходим из поиска обработчика.
			}
			else
			{
				IedDataUpdateFuncHandlers[i].pxHandler(0 | QUALITY_mask | TIME_mask, currentTime);	// обработчик для конкретной функции.
//				taskYIELD();
			}
		}
		PeriodicUpdateNewDataCurr++;
		if (PeriodicUpdateNewDataCurr>=IDU_FUNC_HANDLERS_MAX) PeriodicUpdateNewDataCurr = 0;

	IedServer_unlockDataModel(iedServer);
}
/*******************************************************
 *
 *******************************************************/
}
#endif

/*******************************************************
 * MR851
 *******************************************************/
#if defined	(MR851)
#include "static_model_MR851.h"

void	IedServer_PeriodicUpdateNewData(IedServer iedServer)
{
/*******************************************************
 * наполняем оперативными данными структуру
 *******************************************************/
	if(IEC850TaskHandle && (iedServer != NULL)){
		IedServer_lockDataModel(iedServer);																	// захватываем управление mmsServer'ом

		currentTime = Hal_getTimeInMs();
// RPN_LLN0 Health --------
					Set_LLN0(1,currentTime);
// RPN_ATCC ------
					Set_ATCC(1,currentTime);

// CTRL_GGIO ------
					Set_XCBRGGIO(1,currentTime);


// GGIO_IN24GGIO ------
					Set_INGGIO(16,currentTime);
					Set_OUTGGIO(15,currentTime);
					Set_LEDGGIO(12,currentTime);

// LD0 SG
					Set_SG(0,currentTime);

				IedServer_unlockDataModel(iedServer);
			}
/*******************************************************
 *
 *******************************************************/
}
#endif
