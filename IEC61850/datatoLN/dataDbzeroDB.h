/*
 * dataDbzeroDB.h
 *
 *  Created on: 18.01.2018
 *      Author: sagok
 */

#ifndef DATADBZERODB_H_
#define DATADBZERODB_H_

#define _Default_PDIF_db				150
#define _Default_PDIF_Zerodb			150

#define _Default_DifAngCIc_db			250
#define _Default_DifAngCIc_Zerodb		250

#define _Default_totPF_db				1000
#define _Default_totPF_Zerodb			1000
//MR5
#define _Default_db_TotPF				2000
#define _Default_Zerodb_TotPF			1000

#define _Default_db						50
#define _Default_Zerodb					50

#define _Default_db_In					400
#define _Default_Zerodb_In				400

#define _Default_db_Hz					200
#define _Default_Zerodb_Hz				200

#define _Default_db_W					50
#define _Default_Zerodb_W				50

#define _Default_db_Z					0
#define _Default_Zerodb_Z				0

#define _Default_db_Km					0
#define _Default_Zerodb_Km				0

#define _Default_db_difHZ				8000
#define _Default_Zerodb_difHZ			8000

#define _Default_MMXU_db				100
#define _Default_MMXU_Zerodb			100


#define		DbPercent		100000		// 0,001%

int	Set_Db_zeroDB_float(float mag, float diapazon, DataAttribute*	modelDb, DataAttribute*	modelzeroDb, DataAttribute*	modelinstMag, DataAttribute*	modelmag, DataAttribute*	modelT, uint64_t currentTime);

#endif /* DATADBZERODB_H_ */
