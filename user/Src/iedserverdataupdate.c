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
 * MR5_500
 *******************************************************/
#if defined (MR5_500_)
#include "static_model_MR5_500.h"

void	IedServer_PeriodicUpdateNewData(IedServer iedServer)
{

	if(IEC850TaskHandle && (iedServer != NULL)){

		IedServer_lockDataModel(iedServer);																	// захватываем управление mmsServer'ом

		currentTime = Hal_getTimeInMs();

	// PROT_IPTOC1..8 ------
						Set_IPTOC(4,currentTime);
	// PROT_I20PTOC1 ------
						Set_I2PTOC(2,currentTime);
						Set_I0PTOC(2,currentTime);
	// Set_INPTOC ------
						Set_INPTOC(2,currentTime);
	// Set_IGPTOC ------
						Set_IGPTOC(1,currentTime);
	// Set_I2I1PTOC ------
						Set_I2I1PTOC(1,currentTime);
	// PROT_VZGGIO1..8 ------
						Set_VZGGIO(8,currentTime);
	// PROT_FLSGGIO
						//Set_FLSGGIO(1,currentTime);			//??


	// PROT_RREC ------
						Set_RREC(1,currentTime);
	// PROT_FRREC ------
						Set_FRREC(1,currentTime);

	// PROT_AVRGGIO ------
						Set_AVRGGIO(1,currentTime);
	// Set_LZSHPTOC ------
						Set_LZSHPTOC(1,currentTime);
	// PROT_RBRF ------
						Set_RBRF(1,currentTime);

	// CTRL_CSWI ------
						Set_CSWI(1,currentTime);
	// CTRL_XCBR ------
						Set_XCBR(1,currentTime);
	// CTRL_PTRC ------
						Set_PTRC(1,currentTime);

	// CTRL_GGIO ------
						Set_XCBRGGIO(1,currentTime);
	// MES_MMXU ------
						Set_MMXU(1,currentTime);
	// MES_MSQI ------
						Set_MSQI(1,currentTime);

	// GGIO_IN24GGIO ------
						Set_INGGIO(16,currentTime);
						Set_OUTGGIO(8,currentTime);
						Set_LEDGGIO(12,currentTime);
						Set_SSLGGIO(24,currentTime);
						Set_VLSGGIO(8,currentTime);
						Set_LSGGIO(8,currentTime);

	// LD0 SG
						Set_SG(0,currentTime);

	    IedServer_unlockDataModel(iedServer);																// отдаём управление mmsServer'ом
	}
}
#endif
/*******************************************************
 * MR5_600
 *******************************************************/
#if defined (MR5_600_)
#include "static_model_MR5_600.h"

void	IedServer_PeriodicUpdateNewData(IedServer iedServer)
{

	/*******************************************************
	* наполняем оперативными данными структуру
	*******************************************************/

	if(IEC850TaskHandle && (iedServer != NULL)){

	IedServer_lockDataModel(iedServer);																	// захватываем управление mmsServer'ом

	currentTime = Hal_getTimeInMs();


	//			vTaskDelay(15);
	// PROT_UPTOV ------
						Set_UPTOV(4,currentTime);
	// PROT_UPTUV ------
						Set_UPTUV(4,currentTime);
	// PROT_U2PTOV ------
						Set_U2PTOV(2,currentTime);
	// PROT_U0PTOV ------
						Set_U0PTOV(4,currentTime);
	// PROT_U1PTUV ------
						Set_U1PTUV(2,currentTime);
	// PROT_UPTOF ------
						Set_PTOF(4,currentTime);
	// PROT_UPTUF ------
						Set_PTUF(4,currentTime);
	// PROT_VZGGIO1..8 ------
						Set_VZGGIO(8,currentTime);

	// CTRL_PTRC ------
						Set_PTRC(1,currentTime);

	// CTRL_GGIO ------
						Set_XCBRGGIO(1,currentTime);
	// MES_MMXU ------
						Set_MMXU(1,currentTime);
	// MES_MSQI ------
						Set_MSQI(1,currentTime);

	// GGIO_IN24GGIO ------

						Set_INGGIO(8,currentTime);
						Set_OUTGGIO(16,currentTime);
						Set_LEDGGIO(12,currentTime);
						Set_SSLGGIO(24,currentTime);
						Set_VLSGGIO(8,currentTime);
						Set_LSGGIO(8,currentTime);

	// LD0 SG
						Set_SG(0,currentTime);

		IedServer_unlockDataModel(iedServer);																// отдаём управление mmsServer'ом
	}
}
#endif

/*******************************************************
 * MR5_700
 *******************************************************/
#if defined (MR5_700_)
#include "static_model_MR5_700.h"

void	IedServer_PeriodicUpdateNewData(IedServer iedServer)
{
/*******************************************************
* наполняем оперативными данными структуру
*******************************************************/

	if(IEC850TaskHandle && (iedServer != NULL)){

				IedServer_lockDataModel(iedServer);																	// захватываем управление mmsServer'ом

				currentTime = Hal_getTimeInMs();

	// PROT_IPTOC1..8 ------
						Set_IPTOC(4,currentTime);
	// PROT_I20PTOC1 ------
						Set_I2PTOC(2,currentTime);
						Set_I0PTOC(2,currentTime);
	// Set_INPTOC ------
						Set_INPTOC(2,currentTime);
	// Set_IGPTOC ------
						Set_IGPTOC(1,currentTime);
	// Set_I2I1PTOC ------
						Set_I2I1PTOC(1,currentTime);
	// PROT_UPTOV1 ------
						Set_UPTOV(2,currentTime);
	// PROT_UPTUV1 ------
						Set_UPTUV(2,currentTime);
	// PROT_U2PTOV1 ------
						Set_U2PTOV(2,currentTime);
	// PROT_U0PTOV1 ------
						Set_U0PTOV(2,currentTime);
	// PROT_UPTOF1 ------
						Set_PTOF(2,currentTime);
	// PROT_UPTUF1 ------
						Set_PTUF(2,currentTime);
	// PROT_VZGGIO1..8 ------
						Set_VZGGIO(8,currentTime);

	// PROT_RREC ------
						Set_RREC(1,currentTime);
	// PROT_AVRGGIO ------
						Set_AVRGGIO(1,currentTime);
	// Set_LZSHPTOC ------
						Set_LZSHPTOC(1,currentTime);
	// PROT_RBRF ------
						Set_RBRF(1,currentTime);

	// CTRL_CSWI ------
						Set_CSWI(1,currentTime);
	// CTRL_XCBR ------
						Set_XCBR(1,currentTime);
	// CTRL_PTRC ------
						Set_PTRC(1,currentTime);

	// CTRL_GGIO ------
						Set_XCBRGGIO(1,currentTime);
	// MES_MMXU ------
						Set_MMXU(1,currentTime);
	// MES_MSQI ------
						Set_MSQI(1,currentTime);
	// PROT_RFLO ------
						Set_RFLO(1,currentTime);

	// GGIO_IN24GGIO ------
						Set_INGGIO(16,currentTime);
						Set_OUTGGIO(8,currentTime);
						Set_LEDGGIO(12,currentTime);
						Set_SSLGGIO(24,currentTime);
						Set_VLSGGIO(8,currentTime);
						Set_LSGGIO(8,currentTime);

	// LD0 SG
						Set_SG(0,currentTime);

		IedServer_unlockDataModel(iedServer);																// отдаём управление mmsServer'ом
	}

}
#endif

/*******************************************************
 * MR761 MR762 MR763
 *******************************************************/
#if (0)//defined	(MR761) || defined	(MR762) || defined	(MR763)
#include "static_model_MR76x.h"

void	IedServer_PeriodicUpdateNewData(IedServer iedServer)
{

	if(IEC850TaskHandle && (iedServer != NULL)){

		IedServer_lockDataModel(iedServer);																	// захватываем управление mmsServer'ом

		currentTime = Hal_getTimeInMs();

// PROT_LLN0 Health --------
			Set_LLN0(1,currentTime);
// PROT_IPTOC1..8 ------						защита по повышению тока
			Set_IPTOC(6,currentTime);
// PROT_I20PTOC1..6 ------						защита от замыкания на землю и повешения тока обратной последовательности
			Set_I20PTOC(8,currentTime);
// Set_I2I1PTOC ------
			Set_I2I1PTOC(1,currentTime);
// Set_IPTUC ------
			Set_IPTUC(1,currentTime);
// PROT_UPTOV1..4 ------						защита по повышению напряжения
			Set_UPTOV(4,currentTime);
// PROT_UPTUV1..4 ------						защита по понижению напряжения
			Set_UPTUV(4,currentTime);
// PROT_UPTOF1..4 ------						защита по повышению частоты
			Set_PTOF(4,currentTime);
// PROT_UPTUF1..4 ------						защита по понижению частоты
			Set_PTUF(4,currentTime);
// PROT_VZGGIO1..16 ------						внешняя защита
			Set_VZGGIO(16,currentTime);
// PROT_PDIS ------
			Set_PDIS(4,currentTime);
// PROT_RREC ------
			Set_RREC(1,currentTime);
// PROT_AVRGGIO ------
			Set_AVRGGIO(1,currentTime);
// PROT_NBLKGGIO ------
			Set_NBLKGGIO(1,currentTime);
// PROT_RBRF ------
			Set_RBRF(1,currentTime);
// PROT_RSYN ------
			Set_RSYN(1,currentTime);
// PROT_RPSB ------
			Set_RPSB(1,currentTime);
// PROT_RFLO ------
			Set_RFLO(1,currentTime);
// PROT_QPTTR ------
			Set_QPTTR(2,currentTime);
// PROT_BLKPTTR ------
			Set_BLKPTTR(1,currentTime);
// PROT_RFLO ------
			Set_PDPR(2,currentTime);
// PROT_IARCPTOC ------
			Set_IARCPTOC(1,currentTime);
// CTRL_CSWI ------
			Set_CSWI(1,currentTime);
// CTRL_XCBR ------
			Set_XCBR(1,currentTime);
// CTRL_PTRC ------
			Set_PTRC(1,currentTime);
// CTRL_GGIO ------
			Set_XCBRGGIO(1,currentTime);
// MES_MMXU ------
			Set_MMXU(1,currentTime);
// MES_MSQI ------
			Set_MSQI(1,currentTime);

// GGIO_IN24GGIO ------
			Set_INGGIO(40,currentTime);
			Set_OUTGGIO(34,currentTime);
			Set_LEDGGIO(16,currentTime);
			Set_SSLGGIO(32,currentTime);
			Set_VLSGGIO(16,currentTime);
			Set_LSGGIO(16,currentTime);
// LD0 SG
			Set_SG(0,currentTime);

		IedServer_unlockDataModel(iedServer);
	}
}
#endif
/*******************************************************
 * MR771 MR761 MR762 MR763
 *******************************************************/
#if defined	(MR771) || defined	(MR761) || defined	(MR762) || defined	(MR763) ||\
	defined	(MR801) ||\
	defined	(MR901) || defined	(MR902) ||\
	defined (MR5_500) || defined (MR5_600) || defined (MR5_700) || defined (MR741)
#if defined	(MR771)
#include "static_model_MR771.h"
#endif

#if defined	(MR761) || defined	(MR762) || defined	(MR763)
#include "static_model_MR76x.h"
#endif

#if defined	(MR801)
#include "static_model_MR801.h"
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
 * MR801
 *******************************************************/
#if defined	(MR801_)
#include "static_model_MR801.h"

void	IedServer_PeriodicUpdateNewData(IedServer iedServer)
{
/*******************************************************
 * наполняем оперативными данными структуру
 *******************************************************/
	if(IEC850TaskHandle && (iedServer != NULL)){
		IedServer_lockDataModel(iedServer);																	// захватываем управление mmsServer'ом

		currentTime = Hal_getTimeInMs();

// LLN0 Health --------
					Set_LLN0(1,currentTime);
					taskYIELD();
// PROT_IPTOC1..8 ------						защита по повышению тока
					Set_IPTOC(8,currentTime);
					taskYIELD();
// PROT_I20PTOC1..6 ------						защита от замыкания на землю и повешения тока обратной последовательности
					Set_I20PTOC(6,currentTime);
					taskYIELD();
// PROT_UPTOV1..4 ------						защита по повышению напряжения
					Set_UPTOV(4,currentTime);
					taskYIELD();
// PROT_UPTUV1..4 ------						защита по понижению напряжения
					Set_UPTUV(4,currentTime);
					taskYIELD();
// PROT_UPTOF1..4 ------						защита по повышению частоты
					Set_PTOF(4,currentTime);
					taskYIELD();
// PROT_UPTUF1..4 ------						защита по понижению частоты
					Set_PTUF(4,currentTime);
					taskYIELD();
// PROT_VZGGIO1..16 ------						внешняя защита
					Set_VZGGIO(16,currentTime);
					taskYIELD();
// PROT_IDPDIF ------							дифф защита
					Set_IDPDIF(1,currentTime);
					taskYIELD();
// PROT_IDDPDIF ------							дифф защита
					Set_IDDPDIF(1,currentTime);
					taskYIELD();
// PROT_IDDMPDIF ------							дифф защита
					Set_IDDMPDIF(1,currentTime);
					taskYIELD();
// PROT_ID0PDIF ------							дифф защита
					Set_ID0PDIF(3,currentTime);
					taskYIELD();
// PROT_RREC ------
					Set_RREC(1,currentTime);
					taskYIELD();
// PROT_AVRGGIO ------
					Set_AVRGGIO(1,currentTime);
					taskYIELD();
// PROT_LZSHPTOC ------									ЛЗШ
					Set_LZSHPTOC(1,currentTime);
					taskYIELD();
// PROT_RREC ------
					Set_RBRF(1,currentTime);
					taskYIELD();
// CTRL_LLN0 ------

// CTRL_CSWI ------
					Set_CSWI(1,currentTime);
					taskYIELD();
// CTRL_PTRC ------
					Set_PTRC(1,currentTime);
					taskYIELD();
// CTRL_XCBR ------
					Set_XCBR(1,currentTime);
					taskYIELD();
// CTRL_GGIO ------
					Set_XCBRGGIO(1,currentTime);
					taskYIELD();
// MES_MMXU ------
					Set_MMXU(1,currentTime);
					taskYIELD();
// MES_MSQI ------
					Set_MSQI(1,currentTime);
					taskYIELD();
// GGIO_IN24GGIO ------
					Set_INGGIO(24,currentTime);
					Set_OUTGGIO(18,currentTime);
					Set_LEDGGIO(12,currentTime);
					Set_SSLGGIO(32,currentTime);
					Set_VLSGGIO(16,currentTime);
					Set_LSGGIO(16,currentTime);
					taskYIELD();
// LD0 SG
					Set_SG(0,currentTime);
					taskYIELD();

				IedServer_unlockDataModel(iedServer);
			}
/*******************************************************
 *
 *******************************************************/
}
#endif
/*******************************************************
 * MR901 MR902
 *******************************************************/
#if defined	(MR901_) || defined	(MR902_)
#include "static_model_MR901_902.h"

void	IedServer_PeriodicUpdateNewData(IedServer iedServer)
{
/*******************************************************
 * наполняем оперативными данными структуру
 *******************************************************/
	if(IEC850TaskHandle && (iedServer != NULL)){
		IedServer_lockDataModel(iedServer);																	// захватываем управление mmsServer'ом

		currentTime = Hal_getTimeInMs();
		// LLN0 Health --------
							Set_LLN0(1,currentTime);
		// PROT_IPTOC1..8 ------						защита по повышению тока
							Set_IPTOC(32,currentTime);
		// PROT_VZGGIO1..16 ------						внешняя защита
							Set_VZGGIO(16,currentTime);
		// PROT_IDPDIF ------
							Set_IDPDIF(3,currentTime);
		// PROT_IDMPDIF ------
							Set_IDMPDIF(3,currentTime);
		// PROT_RREC ------ отличаются 901_902
							Set_RBRF(19,currentTime);

		// CTRL_LLN0 ------

		// CTRL_PTRC ------
							Set_PTRC(20,currentTime);
		// CTRL_GGIO ------
							Set_XCBRGGIO(1,currentTime);
		#if defined	(MR901)
		// MES_MMXN ------
							Set_MMXN(1,currentTime);
		#endif
		#if defined	(MR902)
		// MES_MMXU ------
							Set_MMXU(6,currentTime);
		#endif
		// GGIO_IN24GGIO ------
							Set_INGGIO(24,currentTime);
							Set_OUTGGIO(18,currentTime);
							Set_LEDGGIO(12,currentTime);
							Set_SSLGGIO(32,currentTime);
							Set_VLSGGIO(16,currentTime);
							Set_LSGGIO(16,currentTime);
		// LD0 SG
							Set_SG(0,currentTime);


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
