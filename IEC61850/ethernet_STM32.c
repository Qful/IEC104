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

#include <lwip/sockets.h>
//#include <sys/ioctl.h>
#include <linux/if_packet.h>
//#include <linux/if_ether.h>
//#include <linux/if_arp.h>
#include <linux/inet.h>
#include <unistd.h>

#include <linux/bpf.h>
#include <linux/ioctl.h>

#include <fcntl.h>

#include <lwip/api.h>

#include <string.h>

#include "iec61850_server.h"
#include "libiec61850_platform_includes.h"
#include "hal_ethernet.h"
#include "hal_socket.h"

#include "hsr_prp_main.h"

#include "goose_publisher.h"

#define ETH_ALEN		6		/* Octets in one ethernet addr	 */
#define ETH_P_ALL		0x0003		/* Every packet (be careful!!!) */
#define ETH_P_IP		0x0800		/* Internet Protocol packet	*/

#define ARPHRD_ETHER 	1		/* Ethernet 10Mbps		*/

#define	IFNAMSIZ		16
#define	IFF_PROMISC		0x100		/* receive all packets		*/

#define SIOCGIFINDEX	0x8933
#define SIOCGIFFLAGS	0x8913
#define SIOCGIFHWADDR	0x8927
#define SIOCSIFFLAGS	0x8914

#define AF_PACKET	17	/* Packet family		*/
#define PF_PACKET	AF_PACKET


extern IedServer iedServer;

/* Global Ethernet handle*/
extern ETH_HandleTypeDef heth;


int	ioctl __P((int, unsigned long, ...));

//BSD
/*
struct sEthernetSocket {
    int bpf;                        // BPF device handle.
    uint8_t *bpfBuffer;             // Pointer to the BPF reception buffer.
    int bpfBufferSize;              // Actual size of the BPF reception buffer.
    uint8_t *bpfPositon;            // Actual read pointer on the BPF reception buffer.
    uint8_t *bpfEnd;                // Pointer to the end of the BPF reception buffer.
    struct bpf_program bpfProgram;  // BPF filter machine code program.
};
*/

struct sEthernetSocket {
    int rawSocket;
    bool isBind;
    //struct sockaddr_in socketAddress;
    struct sockaddr socketAddress;
    //struct sockaddr_ll socketAddress;
};

/*************************************************************************
 * getInterfaceIndex
 *************************************************************************/
static int
getInterfaceIndex(int sock, const char* deviceName)
{
    struct ifreq ifr;

    strncpy(ifr.ifr_name, deviceName, IFNAMSIZ);

    int interfaceIndex = ifr.ifr_ifindex;

    return interfaceIndex;
}
/*************************************************************************
 * Ethernet_getInterfaceMACAddress
 *************************************************************************/
void
Ethernet_getInterfaceMACAddress(const char* interfaceId, uint8_t* addr)
{
    struct ifreq buffer;

//    int sock = socket(PF_INET, SOCK_GOOSE, 0);//SOCK_GOOSE

    memset(&buffer, 0x00, sizeof(buffer));

    strcpy(buffer.ifr_name, interfaceId);

//    ioctl(sock, SIOCGIFHWADDR, &buffer);

//    close(sock);

    int i;

    for(i = 0; i < 6; i++ )
    {
        addr[i] = (unsigned char)buffer.ifr_hwaddr.sa_data[i];
    }
}
/*************************************************************************
 * Ethernet_createSocket
 * тут работаем с MAC адресами.
 *************************************************************************/
EthernetSocket
Ethernet_createSocket(const char* interfaceId, uint8_t* destAddress)
{
    EthernetSocket ethernetSocket = GLOBAL_CALLOC(1, sizeof(struct sEthernetSocket));
    ethernetSocket->rawSocket = socket(AF_INET, SOCK_GOOSE, htons(ETH_P_ALL));//AF_PACKET

    if (ethernetSocket->rawSocket == -1) {
        printf("Error creating raw socket!\n");
        GLOBAL_FREEMEM(ethernetSocket);
        return NULL;
    }
/*
    ethernetSocket->socketAddress.sll_family = PF_PACKET;
    ethernetSocket->socketAddress.sll_protocol = htons(ETH_P_IP);

    ethernetSocket->socketAddress.sll_ifindex = getInterfaceIndex(ethernetSocket->rawSocket, interfaceId);

    ethernetSocket->socketAddress.sll_hatype =  ARPHRD_ETHER;
    ethernetSocket->socketAddress.sll_pkttype = PACKET_OTHERHOST;

    ethernetSocket->socketAddress.sll_halen = ETH_ALEN;

    memset(ethernetSocket->socketAddress.sll_addr, 0, 8);

    if (destAddress != NULL)
        memcpy(ethernetSocket->socketAddress.sll_addr, destAddress, 6);
*/
/*
    ethernetSocket->socketAddress.sa_family = AF_INET;//PF_PACKET;

    memset(ethernetSocket->socketAddress.sa_data, 0, 14);
    ethernetSocket->socketAddress.sa_len = 6;

    if (destAddress != NULL) {
        memcpy(ethernetSocket->socketAddress.sa_data, destAddress, 6);
        ethernetSocket->socketAddress.sa_len = 6;
    }

*/
//    struct sockaddr_in GooseServerAddress;
//    prepareServerAddress((const char*)destAddress,0,&GooseServerAddress);
//    memcpy((void*)&ethernetSocket->socketAddress,(void*)&GooseServerAddress, sizeof(struct sockaddr_in));
    ethernetSocket->socketAddress.sa_family = AF_INET;
    memset(ethernetSocket->socketAddress.sa_data, 0, 14);
    ethernetSocket->socketAddress.sa_len = 6;

    ethernetSocket->isBind = false;

    return ethernetSocket;
}

/*************************************************************************
 * Ethernet_setProtocolFilter
 * настройка фильтра свича
 *************************************************************************/
void
Ethernet_setProtocolFilter(EthernetSocket ethSocket, uint16_t etherType)
{

//	ethSocket->socketAddress.sa_len = 6;
//    ethSocket->socketAddress.sa_family = htons(etherType);
}

/*************************************************************************
 * Ethernet_receivePacket
 * non-blocking receive
 * у этого сокета нет не адреса ни порта. ѕринимаем широковещательные пакеты.
 * ¬озможно у нас должен быть порт открыт а адрес нужно вбить мак ожидаемого пакета
 *************************************************************************/
int		Ethernet_receivePacket(EthernetSocket self, uint8_t* buffer, int bufferSize)
{

    if (self->isBind == false) {
       if (bind(self->rawSocket, (struct sockaddr*) &self->socketAddress, sizeof(struct sockaddr_in)) == 0)

            self->isBind = true;
        else
            return 0;
    }

    return recvfrom(self->rawSocket, buffer, bufferSize, MSG_DONTWAIT, 0, 0);
}
/*************************************************************************
 * Ethernet_sendPacket
 * отправка сообщени€ пр€мо в netif напр€мую
 *************************************************************************/
#if (1)
void Ethernet_sendPacket(EthernetSocket self, uint8_t* buffer, int packetSize)
{

}
#else
void Ethernet_sendPacket(EthernetSocket ethSocket, GoosePublisher buffer, int packetSize)
{
	uint8_t*	out = Goose_getbufferAddr(buffer);
	if (Goose_output(out, packetSize) != ERR_OK){
		 USART_TRACE_RED("Goose_output Error!!!\n");
	 }
}
#endif
/*************************************************************************
 * HAL_ETH_TxCpltCallback
 * конец передачи в сеть
 *************************************************************************/
void HAL_ETH_TxCpltCallback(ETH_HandleTypeDef *heth){
	// нужно организовать семафор и таск обрабатывающий окончание передачи в порт,
	// переключа€ нужный режим
#if defined (UseHSR) || defined (UsePRP)
	IsoServer IsoServ = IedServer_getIsoServer(iedServer);

	switch (IsoServer_getPHYTransmitport(IsoServ)){
		// была передача только в PORT1, включим порт2
	case PHY_PORT_1:

		break;
	case PHY_PORT_2:

		break;
	case PHY_PORT_1_2:

		break;
	}

#endif
}

/*************************************************************************
 * Ethernet_destroySocket
 *************************************************************************/
void
Ethernet_destroySocket(EthernetSocket ethSocket)
{
	if (ethSocket){
		close(ethSocket->rawSocket);
		GLOBAL_FREEMEM(ethSocket);
	}
}

bool
Ethernet_isSupported()
{
    return true;
}
