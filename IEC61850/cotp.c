/*
 *  cotp.c
 *
 *  ISO 8073 Connection Oriented Transport Protocol over TCP (RFC1006)
 *
 *  Partial implementation of the ISO 8073 COTP protocol for MMS.
 *
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

#include "main.h"

#include "stack_config.h"
#include "cotp.h"
#include "byte_stream.h"
#include "byte_buffer.h"

struct sSocket {
    int fd;
};

#define COTP_RFC1006_HEADER_SIZE 4

#define COTP_DATA_HEADER_SIZE 3

#ifdef CONFIG_COTP_MAX_TPDU_SIZE
#define COTP_MAX_TPDU_SIZE CONFIG_COTP_MAX_TPDU_SIZE
#else
#define COTP_MAX_TPDU_SIZE 16384
#endif

typedef struct sIsoConnection* IsoConnection;

static int	addPayloadToBuffer(CotpConnection* self, int rfc1006Length);

/*************************************************************************
 * writeOptions(CotpConnection* self)
 *************************************************************************/
static CotpIndication	writeOptions(CotpConnection* self)
{
    if (self->options.tsap_id_dst != -1) {
        // modify by sabin
        // if (ByteStream_writeUint8(self->stream, 0xc2) == -1)
        //    return ERR;
        if (ByteStream_writeUint8(self->writeBuffer, 0xc1) == -1)
            return ERR;
        if (ByteStream_writeUint8(self->writeBuffer, 0x02) == -1)
            return ERR;
        if (ByteStream_writeUint8(self->writeBuffer, (uint8_t) (self->options.tsap_id_dst / 0x100)) == -1)
            return ERR;
        if (ByteStream_writeUint8(self->writeBuffer, (uint8_t) (self->options.tsap_id_dst & 0xff)) == -1)
            return ERR;
    }

    if (self->options.tsap_id_src != -1) {
//         if (ByteStream_writeUint8(self->stream, 0xc1) == -1)
//             return ERR;
         if (ByteStream_writeUint8(self->writeBuffer, 0xc2) == -1)
            return ERR;

        if (ByteStream_writeUint8(self->writeBuffer, 0x02) == -1)
            return ERR;
        if (ByteStream_writeUint8(self->writeBuffer, (uint8_t) (self->options.tsap_id_src / 0x100)) == -1)
            return ERR;
        if (ByteStream_writeUint8(self->writeBuffer, (uint8_t) (self->options.tsap_id_src & 0xff)) == -1)
            return ERR;
    }

    if (self->options.tpdu_size != -1) {

        if (ByteStream_writeUint8(self->writeBuffer, 0xc0) == -1)
            return ERR;
        if (ByteStream_writeUint8(self->writeBuffer, 0x01) == -1)
            return ERR;
//         if (ByteStream_writeUint8(self->stream, self->options.tpdu_size) == -1)
//             return ERR;
        if (ByteStream_writeUint8(self->writeBuffer, 0x0a) == -1)
            return ERR;
    }

    return OK;
}

/*************************************************************************
 * getOptionsLength(CotpConnection* self)
 *************************************************************************/
static int	getOptionsLength(CotpConnection* self)
{
    int optionsLength = 0;
    if (self->options.tpdu_size != -1)
        optionsLength += 3;
    if (self->options.tsap_id_dst != -1)
        optionsLength += 4;
    if (self->options.tsap_id_src != -1)
        optionsLength += 4;
    return optionsLength;
}
/*************************************************************************
 * getConnectionResponseLength(CotpConnection* self)
 *************************************************************************/
static int	getConnectionResponseLength(CotpConnection* self)
{
    return 11 + getOptionsLength(self);
}
/*************************************************************************
 * writeStaticConnectResponseHeader(CotpConnection* self)
 *************************************************************************/
static CotpIndication	writeStaticConnectResponseHeader(CotpConnection* self)
{
    if (ByteStream_writeUint8(self->writeBuffer, 6 + getOptionsLength(self)) != 1)
        return ERR;
    if (ByteStream_writeUint8(self->writeBuffer, 0xd0) != 1)
        return ERR;
    if (ByteStream_writeUint8(self->writeBuffer, self->srcRef / 0x100) != 1)
        return ERR;
    if (ByteStream_writeUint8(self->writeBuffer, self->srcRef & 0xff) != 1)
        return ERR;
    if (ByteStream_writeUint8(self->writeBuffer, self->srcRef / 0x100) != 1)
        return ERR;
    if (ByteStream_writeUint8(self->writeBuffer, self->srcRef & 0xff) != 1)
        return ERR;
    if (ByteStream_writeUint8(self->writeBuffer, self->class) != 1)
        return ERR;

    return OK;
}
/*************************************************************************
 * writeRfc1006Header(CotpConnection* self, int len)
 * Пишем в буфер заголовок сообщения (TPKT) 4 байта
 * 03 00 Lenh lenl
 *************************************************************************/
static CotpIndication	writeRfc1006Header(CotpConnection* self, int len)
{
    if (ByteStream_writeUint8(self->writeBuffer, (uint8_t) 0x03) != 1)
        return ERR;
    if (ByteStream_writeUint8(self->writeBuffer, (uint8_t) 0x00) != 1)
        return ERR;
    if (ByteStream_writeUint8(self->writeBuffer, (uint8_t) (len / 0x100)) != 1)
        return ERR;
    if (ByteStream_writeUint8(self->writeBuffer, (uint8_t) (len & 0xff)) != 1)
        return ERR;

    return OK;
}
/*************************************************************************
 * writeDataTpduHeader(CotpConnection* self, int isLastUnit)
 *************************************************************************/
static CotpIndication	writeDataTpduHeader(CotpConnection* self, int isLastUnit)
{
    if (ByteStream_writeUint8(self->writeBuffer, (uint8_t) 0x02) != 1)
        return ERR;

    if (ByteStream_writeUint8(self->writeBuffer, (uint8_t) 0xf0) != 1)
        return ERR;

    if (isLastUnit) {
        if (ByteStream_writeUint8(self->writeBuffer, (uint8_t) 0x80) != 1)
            return ERR;
    }
    else {
        if (ByteStream_writeUint8(self->writeBuffer, (uint8_t) 0x00) != 1)
            return ERR;
    }

    return OK;
}
/*************************************************************************
 * CotpConnection_sendDataMessage(CotpConnection* self, ByteBuffer* payload)
 *************************************************************************/
CotpIndication	CotpConnection_sendDataMessage(CotpConnection* self, ByteBuffer* writeBuffer)
{
    int fragments = 1;
    int currentBufPos = 0;
    int currentLimit;
    int lastUnit;
    int i;

    int fragmentPayloadSize = CotpConnection_getTpduSize(self) - COTP_DATA_HEADER_SIZE;

    if (writeBuffer->currPos > fragmentPayloadSize) { 					// проверим, надо ли делить на сегменты пакет
        fragments = writeBuffer->currPos / fragmentPayloadSize;			// размер одного фрагмента
        if ((writeBuffer->currPos % fragmentPayloadSize) != 0) 			// не получилось целое число фрагментов,
            fragments += 1;
    }

    while (fragments > 0) {
        if (fragments > 1) {											// более одного фрагмента
            currentLimit = currentBufPos + fragmentPayloadSize;
            lastUnit = 0;
        }
        else {															// только один фрагмент
            currentLimit = writeBuffer->currPos;
            lastUnit = 1;												// признак EOT в TPDU
        }

        // заголовок каждого сегмента
        if (writeRfc1006Header(self, 7 + (currentLimit - currentBufPos)) == ERR) return ERR;	// 4 байта с указанием размера сегмента
        if (writeDataTpduHeader(self, lastUnit) == ERR)		return ERR;							// 3 байта с указанием признака последнего такета (EOT)

        // содержимое очередного сегмента
        for (i = currentBufPos; i < currentLimit; i++) {										// дописываем весь пакет уже подготовленный в writeBuffer
            if (ByteStream_writeUint8(self->writeBuffer, writeBuffer->buffer[i]) != 1)return ERR;
            currentBufPos++;
        }
        USART_TRACE("Send COTP fragment %i bufpos: %i\n", fragments, currentBufPos);

        ByteBuffer_send(self->writeBuffer);				// передача в TCP/IP стек
        fragments--;
    } // !while (fragments > 0)

    return OK;
}
/*************************************************************************
 * allocateWriteBuffer(CotpConnection* self)
 * выделяет буфер в памяти и указываем его потоку
 *************************************************************************/
static void		allocateWriteBuffer(CotpConnection* self)
{
    if (self->writeBuffer == NULL ) {
        self->writeBuffer = ByteBuffer_create(NULL, CotpConnection_getTpduSize(self) + COTP_RFC1006_HEADER_SIZE);
       // ByteStream_setWriteBuffer(self->stream, self->writeBuffer);
    }
}
/*************************************************************************
 * allocateWriteBuffer(CotpConnection* self)
 * выделяет буфер в памяти и указываем его потоку
 *************************************************************************/
static void		allocatePayloadBuffer(CotpConnection* self)
{
    if (self->payload == NULL ) {
        self->payload = ByteBuffer_create(NULL, CotpConnection_getTpduSize(self) + COTP_RFC1006_HEADER_SIZE);
       // ByteStream_setWriteBuffer(self->stream, self->writeBuffer);
    }
}
/*************************************************************************
 * CotpConnection_sendConnectionRequestMessage(CotpConnection* self)
 * client side
 * отправка запроса соединения серверу
 *************************************************************************/
CotpIndication		CotpConnection_sendConnectionRequestMessage(CotpConnection* self)
{
    int len = 22;
    CotpIndication indication;

    allocateWriteBuffer(self);							// выделим буфер в памяти для отправки
    if (writeRfc1006Header(self, len) == ERR)			// TPKT заголовок
        return ERR;
    													// далее пакет COTP (ISO 8073)
    /* LI */
    if (ByteStream_writeUint8(self->writeBuffer, 17) != 1)	//
        return ERR;

    /* TPDU CODE */
    if (ByteStream_writeUint8(self->writeBuffer, 0xe0) != 1)
        return ERR;

    /* DST REF */
    if (ByteStream_writeUint8(self->writeBuffer, 0x00) != 1)
        return ERR;
    if (ByteStream_writeUint8(self->writeBuffer, 0x00) != 1)
        return ERR;

    /* SRC REF */
    if (ByteStream_writeUint8(self->writeBuffer, 0x00) != 1)
        return ERR;
    if (ByteStream_writeUint8(self->writeBuffer, 0x04) != 1)
        return ERR;

    // modify by sabin
    // if (ByteStream_writeUint8(self->stream, 0x01) != 1)
    //    return ERR;

    /* Class */
    if (ByteStream_writeUint8(self->writeBuffer, 0x00) != 1)
        return ERR;

    self->options.tsap_id_dst = 1;
    //self->options.tsap_id_src = 0;
    self->options.tsap_id_src = 1;

    indication = writeOptions(self);

    ByteBuffer_send(self->writeBuffer);				// отправим буфер в сокет

    return indication;
}
/*************************************************************************
 * CotpConnection_sendConnectionResponseMessage(CotpConnection* self)
 * client side
 *************************************************************************/
CotpIndication	CotpConnection_sendConnectionResponseMessage(CotpConnection* self)
{
    int len = getConnectionResponseLength(self);

    allocateWriteBuffer(self);			// выделяет self->writeBuffer в памяти

    // готовим ответ
    if (writeRfc1006Header(self, len) == ERR)				return ERR;
    if (writeStaticConnectResponseHeader(self) != OK)		return ERR;
    if (writeOptions(self) != OK)							return ERR;

    if (ByteBuffer_send(self->writeBuffer) == -1) {
    	USART_TRACE("ERR sending buffer\n");
        return ERR;
    }

    return OK;
}
/*************************************************************************
 * cotp_parse_options(CotpConnection* self, int opt_len)
 *************************************************************************/
static int	cotp_parse_options(CotpConnection* self, int opt_len)
{
    int read_bytes = 0;
    uint8_t option_type, option_len, uint8_value;
    uint16_t uint16_value;
    int requestedTpduSize;
    int i;

    while (read_bytes < opt_len) {
        if (ByteStream_readUint8(self->readBuffer, &option_type) == -1)		goto cpo_ERR;
        if (ByteStream_readUint8(self->readBuffer, &option_len) == -1)		goto cpo_ERR;

        read_bytes += 2;
        USART_TRACE("option: %02x len: %02x\n", option_type, option_len);

        switch (option_type) {
        case 0xc0:
            if (ByteStream_readUint8(self->readBuffer, &uint8_value) == -1)		goto cpo_ERR;
            read_bytes++;

            requestedTpduSize = (1 << uint8_value);
            CotpConnection_setTpduSize(self, requestedTpduSize);
            break;

        case 0xc1:
            if (option_len == 2) {
            if (ByteStream_readUint16(self->readBuffer, &uint16_value) == -1)	goto cpo_ERR;
            read_bytes += 2;
            self->options.tsap_id_src = (int32_t) uint16_value;
            } else	goto cpo_ERR;
            break;

        case 0xc2:
            if (option_len == 2) {
                if (ByteStream_readUint16(self->readBuffer, &uint16_value) == -1)	goto cpo_ERR;
                self->options.tsap_id_dst = (int32_t) uint16_value;
                read_bytes += 2;
            } else	goto cpo_ERR;
            break;

        default:
            USART_TRACE("Unknown option %02x\n", option_type);

            for (i = 0; i < opt_len; i++)
                if (ByteStream_readUint8(self->readBuffer, &uint8_value) == -1)	goto cpo_ERR;

            read_bytes += opt_len;
            break;
        }//!switch (option_type)
    }//! while (read_bytes < opt_len)

    return 1;

    cpo_ERR:
    USART_TRACE("cotp_parse_options: ERR parsing options!\n");
    return -1;
}
/*************************************************************************
 * CotpConnection_init(CotpConnection* self, ByteBuffer* payloadBuffer)
 *
 *
 *************************************************************************/
void	CotpConnection_init(CotpConnection* self, ByteBuffer* payloadBuffer)
{
    self->state = 0;

    self->srcRef = -1;
    self->dstRef = -1;
    self->class = -1;

    self->options.tpdu_size   = 0;
    self->options.tsap_id_src = -1;
    self->options.tsap_id_dst = -1;

    self->readBuffer = payloadBuffer;							// адрес буфера

    /* default TPDU size is maximum size */
    CotpConnection_setTpduSize(self, COTP_MAX_TPDU_SIZE);		//  установим размер буфера

    self->writeBuffer = NULL;									// пока нету буфера для передачи
}
/*************************************************************************
 * CotpConnection_destroy(CotpConnection* self)
 *************************************************************************/
void	CotpConnection_destroy(CotpConnection* self)
{
    if (self->writeBuffer != NULL)
        ByteBuffer_destroy(self->writeBuffer);
}

/*************************************************************************
 * CotpConnection_destroy(CotpConnection* self)
 * in byte
 *************************************************************************/
int 	CotpConnection_getTpduSize(CotpConnection* self)
{
    return (1 << self->options.tpdu_size);
}
/*************************************************************************
 * CotpConnection_destroy(CotpConnection* self)
 *************************************************************************/
void	CotpConnection_setTpduSize(CotpConnection* self, int tpduSize /* in byte */)
{
    int newTpduSize = 1;

    if (tpduSize > COTP_MAX_TPDU_SIZE)
        tpduSize = COTP_MAX_TPDU_SIZE;

    while ((1 << newTpduSize) < tpduSize)
        newTpduSize++;

    if ((1 << newTpduSize) > tpduSize)
        newTpduSize--;

    self->options.tpdu_size = newTpduSize;
}
/*************************************************************************
 * CotpConnection_getreadBuffer(CotpConnection* self)
 *************************************************************************/
ByteBuffer*	CotpConnection_getreadBuffer(CotpConnection* self)
{
	return self->readBuffer;
}
/*************************************************************************
 * CotpConnection_getPayload(CotpConnection* self)
 *************************************************************************/
ByteBuffer*	CotpConnection_getPayload(CotpConnection* self)
{
    return self->payload;
}
/*************************************************************************
 * CotpConnection_getSrcRef(CotpConnection* self)
 *************************************************************************/
int CotpConnection_getSrcRef(CotpConnection* self)
{
    return self->srcRef;
}
/*************************************************************************
 * CotpConnection_getDstRef(CotpConnection* self)
 *************************************************************************/
int CotpConnection_getDstRef(CotpConnection* self)
{
    return self->dstRef;
}

/*
 CR TPDU (from RFC 0905):

 1    2        3        4       5   6    7    8    p  p+1...end
 +--+------+---------+---------+---+---+------+-------+---------+
 |LI|CR CDT|     DST - REF     |SRC-REF|CLASS |VARIAB.|USER     |
 |  |1110  |0000 0000|0000 0000|   |   |OPTION|PART   |DATA     |
 +--+------+---------+---------+---+---+------+-------+---------+
 */

/*************************************************************************
 * cotp_parse_CRequest_tpdu(CotpConnection* self, uint8_t len)
 *************************************************************************/
static int		cotp_parse_CRequest_tpdu(CotpConnection* self, uint8_t len)
{
    uint16_t dstRef;
    uint16_t srcRef;
    uint8_t class;

    if (ByteStream_readUint16(self->readBuffer, &dstRef) != 2)		return -1;
    else	self->dstRef = dstRef;

    if (ByteStream_readUint16(self->readBuffer, &srcRef) != 2)		return -1;
    else	self->srcRef = srcRef;

    if (ByteStream_readUint8(self->readBuffer, &class) != 1)		return -1;
    else	self->class = class;

    return cotp_parse_options(self, len - 6);
}
/*************************************************************************
 * cotp_parse_CConfirm_tpdu(CotpConnection* self, uint8_t len)
 *************************************************************************/
static int		cotp_parse_CConfirm_tpdu(CotpConnection* self, uint8_t len)
{
    uint16_t dstRef;
    uint16_t srcRef;
    uint8_t class;

    if (ByteStream_readUint16(self->readBuffer, &dstRef) != 2)		return -1;
    else	self->srcRef = dstRef;

    if (ByteStream_readUint16(self->readBuffer, &srcRef) != 2)		return -1;
    else	self->dstRef = srcRef;

    if (ByteStream_readUint8(self->readBuffer, &class) != 1)		return -1;
    else	self->class = class;

    return cotp_parse_options(self, len - 6);
}

/*************************************************************************
 * cotp_parse_DATA_tpdu(CotpConnection* self, uint8_t len)
 *************************************************************************/
static int		cotp_parse_DATA_tpdu(CotpConnection* self, uint8_t len)
{
    uint8_t eot;

    if (len != 2)       return -1;

    if (ByteStream_readUint8(self->readBuffer, &eot) != 1)			return -1;
    else {
        if (eot & 0x80)		self->eot = 1;
        else				self->eot = 0;
    }

    return 1;
}
/*************************************************************************
 * parseRFC1006Header
 *************************************************************************/
static CotpIndication	parseRFC1006Header(CotpConnection* self, uint16_t* rfc1006_length)
{
    uint8_t b;
    if (ByteStream_readUint8(self->readBuffer, &b) == -1)				return ERR;
    if (b != 3)		return ERR;

    if (ByteStream_readUint8(self->readBuffer, &b) == -1)				return ERR;
    if (b != 0)		return ERR;

    if (ByteStream_readUint16(self->readBuffer, rfc1006_length) == -1)	return ERR;

    return OK;
}

/*************************************************************************
 * parseIncomingMessage
 * парсим входящее сообщение
 *************************************************************************/
static CotpIndication	parseIncomingMessage(CotpConnection* self)
{
    uint8_t len;
    uint8_t tpduType;
    uint16_t rfc1006Length;

    if (parseRFC1006Header(self, &rfc1006Length) == ERR)		return ERR;
    if (ByteStream_readUint8(self->readBuffer, &len) != 1) 		return ERR;


    if (ByteStream_readUint8(self->readBuffer, &tpduType) == 1) {
        switch (tpduType) {
        case 0xe0:		// CR Connection (ISO DP 8073)
            if (cotp_parse_CRequest_tpdu(self, len) == 1)
                return CONNECT_INDICATION;
            else
                return ERR;
            break;

        case 0xd0:		// CC Connection (ISO DP 8073)
            self->eot = 1;
            if (cotp_parse_CConfirm_tpdu(self, len) == 1)
                return CONNECT_INDICATION;
            else
                return ERR;
            break;

        case 0xf0:		// DT DATA (ISO DP 8073)
            if (cotp_parse_DATA_tpdu(self, len) == 1) {
                if (addPayloadToBuffer(self, rfc1006Length) == 1)			// тут забирали из потока принятые данные, в буфер Payload
                    return DATA_INDICATION;
                else		return ERR;
            }
            else
                return ERR;
            break;

        default:
            return ERR;
            break;
        }//!switch (tpduType)
    }
    else
        return ERR;
}
/*************************************************************************
 * addPayloadToBuffer
 *
 *************************************************************************/
static int	addPayloadToBuffer(CotpConnection* self, int rfc1006Length)
{

    int payloadLength = rfc1006Length - 7;
    int readLength;

    if ((self->payload->currPos + payloadLength) > self->payload->maxSize)		return 0;

    readLength = ByteStream_readOctets(self->readBuffer , self->payload->buffer + self->payload->currPos,payloadLength);

    if (readLength != payloadLength) {
    	USART_TRACE("cotp: read %i bytes should have been %i\n", readLength, payloadLength);
        return 0;
    }
    else {
        self->payload->currPos += payloadLength;

        if (self->eot == 0) {
            if (parseIncomingMessage(self) == DATA_INDICATION)		return 1;
            else	return 0;
        }
        else	return 1;
    }
}

/*************************************************************************
 * CotpConnection_parseIncomingMessage
 * парсим входные данные COTP
 *************************************************************************/
CotpIndication	CotpConnection_parseIncomingMessage(CotpConnection* Cotpself)
{
	Cotpself->readBuffer->currPos = 0;			// принятый пакет
	Cotpself->payload->currPos = 0;				// payload сюда возвращает юзерданные
    return parseIncomingMessage(Cotpself);
}

