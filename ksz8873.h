/*
 * ksz8873.h
 *
 *  Created on: 22.11.2017
 *      Author: sagok
 */

#ifndef KSZ8873_H_
#define KSZ8873_H_

typedef enum
{
	PHY_Port1,
	PHY_Port2,
	PHY_Port3
} PHY_PortNumber;

// reg 2
#define		StaticMAC_flush			0b1<<4
#define		DynamicMAC_flush		0b1<<5


// reg 14
#define		UnknownPacketEnable		0b1<<7
#define		DriveStrength16mA		0b1<<6
#define		UnknownPacketPort_1		0b1<<0
#define		UnknownPacketPort_2		0b1<<1
#define		UnknownPacketPort_3		0b1<<2

// reg 16
#define		BroadcastStormProt_ON	0b1<<7


// reg 18, 34
#define		TransmitENABLE			0b1<<2
#define		TransmitDISABLE			0
#define		ReseiveENABLE			0b1<<1
#define		ReseiveDISABLE			0
#define		LearningENABLE			0
#define		LearningDISABLE			1

// reg 29, 45
#define		Txdis					0b1<<6

// reg 121
#define		StaticMAC_Sel			0b00<<2
#define		DynamicMAC_Sel			0b10<<2
#define		ReadMAC					0b1<<4
#define		WriteMAC				0b0<<4

// static MAC table
#define		Override_ON				0b1<<4
#define		Valid_ON				0b1<<3
#define		Forvard_to_Port1		0b001
#define		Forvard_to_Port2		0b010
#define		Forvard_to_Port3		0b100

// Dynamic MAC table
#define		MAC_Empty				0b1<<2
#define		DataNotReady			0b1<<7




#define		SelfAddressFilteringEnableMACA2			1<<5
#define		SelfAddressFilteringEnableMACA1			1<<6


HAL_StatusTypeDef 	HAL_ETH_SoftSMIWrite(uint8_t	regAdr, uint16_t Data);
uint16_t 			HAL_ETH_SoftSMIRead(uint8_t	regAdr);

#endif /* KSZ8873_H_ */
