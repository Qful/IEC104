/*
 *  ethernet_linux.c
 *
 *  Copyright 2013 Michael Zillgith
 *
 *  This file is part of libIEC61850.
 *
 *  libIEC61850 is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  libIEC61850 is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with libIEC61850.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  See COPYING file for the complete license text.
 */

#include "ethernetif.h"
#include "lwip/tcpip.h"
#include "lwip/init.h"
#include "lwip/netif.h"
#include "lwip/api.h"
#include "lwip/sys.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ethernet.h"

struct sEthernetSocket {
    int rawSocket;
    bool isBind;
  //  struct sockaddr_ll socketAddress;
};

static int	getInterfaceIndex(int sock, char* deviceName)
{

}


void	Ethernet_getInterfaceMACAddress(char* interfaceId, uint8_t* addr)
{

}


EthernetSocket	Ethernet_createSocket(char* interfaceId, uint8_t* destAddress)
{

}

void	Ethernet_setProtocolFilter(EthernetSocket ethSocket, uint16_t etherType)
{

}


/* non-blocking receive */
int	Ethernet_receivePacket(EthernetSocket self, uint8_t* buffer, int bufferSize)
{
}

void	Ethernet_sendPacket(EthernetSocket ethSocket, uint8_t* buffer, int packetSize)
{

}

void	Ethernet_destroySocket(EthernetSocket ethSocket)
{

}

