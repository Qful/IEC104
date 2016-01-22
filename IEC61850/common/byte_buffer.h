/*
 *  byte_buffer.h
 *
 *  Copyright 2016 Alex Godulevich
 *
 */

#ifndef BYTE_BUFFER_H_
#define BYTE_BUFFER_H_

#include "stdlib.h"
#include "stdarg.h"
#include "string.h"
#include "stdio.h"
#include "stdbool.h"
#include "stdint.h"

typedef struct {
	uint8_t* buffer;			// адрес данных
	int maxSize;				// размер данных
	int currPos;				// позиция чля чтения/записи
} ByteBuffer;

ByteBuffer*	ByteBuffer_create(ByteBuffer* self, int maxSize);								//выделение памяти для буфера с размером maxSize
void		ByteBuffer_destroy(ByteBuffer* self);											//освобождение памяти от буфера
void		ByteBuffer_wrap(ByteBuffer* self, uint8_t* buf, int size, int maxSize);			//конфиг буфера в структуре

int			ByteBuffer_append(ByteBuffer* self, uint8_t* data, int dataSize);				//запись в буфер блока начиная с текущей позиции currPos размером dataSize
int			ByteBuffer_appendByte(ByteBuffer* self, uint8_t byte);							//запись в буфер байта начиная с текущей позиции currPos
int			ByteBuffer_readByteUint8(ByteBuffer* self, uint8_t* byte);						//чтение из буфера байта начиная с текущей позиции currPos
int			ByteBuffer_readByteUint16(ByteBuffer* self, uint16_t* word);					//чтение из буфера слова начиная с текущей позиции currPos

uint8_t*	ByteBuffer_getBuffer(ByteBuffer* self);											//получение адреса буфера
int			ByteBuffer_getcurrPos(ByteBuffer* self);										//получение текущей позиции
int			ByteBuffer_getMaxSize(ByteBuffer* self);										//получение размера буфера

int			ByteBuffer_setcurrPos(ByteBuffer* self, int size);								//перевод каретки в позицию size

int			ByteBuffer_send(ByteBuffer* self);												//физич. передача в ethernet через TCP/IP


#endif /* BYTE_BUFFER_H_ */
