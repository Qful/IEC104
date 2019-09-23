/*
 * datatoGGIO.h
 *
 *  Created on: 19.04.2017
 *      Author: sagok
 *
 *
// 901
// ---------------------------------
// ������ 1 ����������
// �������			������		�������			����
// 901				�� 2.11 	0				10(1-10)
// 901T24N0D40R35	2.12 		0				10(1-10)
// ......

// ---------------------------------
// ������ 2
// �������			������		�������			����
// 901				�� 2.11 	8(1-8)			8(11-18)
// 901T24N0D40R35	2.12 		24(1-24)		8(11-18)
// 901T24N0D32R43	2.12 		16(1-16)		16(11-16)
// 901T24N0D24R51	2.12 		0				32(11-32)
// 901T20N4D32R35	2.12 		24(1-24)		8(11-18)

// ---------------------------------
// ������ 3
// �������			������		�������			����
// 901				�� 2.11 	16(9-24)		0
// 901T24N0D40R35	2.12 		16(25-40)		16(19-35)
// 901T24N0D32R43	2.12 		16(17-32)		16(17-43)
// 901T24N0D24R51	2.12 		24(1-24)		8(33-51)
// 901T20N4D40R35	2.12 		16(25-40)		16(19-35)

// ���������� ������
// ---------------------------------
// ������ 4
// �������			������		����������		���
// 901				�� 2.11 	0				8
// 901T24N0D40R35	2.12 		0				8
// 901T24N0D32R43	2.12 		0				8
// 901T24N0D24R51	2.12 		0				8
// 901T20N4D40R35	2.12 		0				8

// ---------------------------------
// ������ 5
// �������			������		����������		���
// 901				�� 2.11 	0				8
// 901T24N0D40R35	2.12 		0				8
// 901T24N0D32R43	2.12 		0				8
// 901T24N0D24R51	2.12 		0				8
// 901T20N4D40R43	2.12 		0				8

// ---------------------------------
// ������ 6
// �������			������		����������		���
// 901				�� 2.11 	-				-
// 901T24N0D40R35	2.12 		0				8
// 901T24N0D32R43	2.12 		0				8
// 901T24N0D24R51	2.12 		0				8
// 901T20N4D40R35	2.12 		4				4

// ---------------------------------

 *
 */

#ifndef DATATOGGIO_H_
#define DATATOGGIO_H_
/***********************************
 * ���� MR76xNxxxGGIO ��������.(�����)	-	15.01.2018. - ��.
 *
 ***********************************/
//CTRL
int		Set_XCBRGGIO	(uint16_t QTnum, uint64_t currentTime );

//GGIO
int		Set_INGGIO		(uint16_t QTnum, uint64_t currentTime );
int		Set_OUTGGIO		(uint16_t QTnum, uint64_t currentTime );
int		Set_LEDGGIO		(uint16_t QTnum, uint64_t currentTime );
int		Set_SSLGGIO		(uint16_t QTnum, uint64_t currentTime );
int		Set_VLSGGIO		(uint16_t QTnum, uint64_t currentTime );
int		Set_LSGGIO		(uint16_t QTnum, uint64_t currentTime );
int		Set_RSTGGIO		(uint16_t QTnum, uint64_t currentTime );

//PROT
int		Set_NBLKGGIO	(uint16_t QTnum, uint64_t currentTime );
int		Set_FLSGGIO		(uint16_t QTnum, uint64_t currentTime );
int		Set_VZGGIO		(uint16_t QTnum, uint64_t currentTime );
int		Set_AVRGGIO		(uint16_t QTnum, uint64_t currentTime );

#endif /* DATATOGGIO_H_ */
