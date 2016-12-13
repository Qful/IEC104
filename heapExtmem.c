/*
 * SPIAddrmap.c
 *
 *  Created on: 27.04.2016
 *      Author: sagok
 */

#include <stdlib.h>
//#include "at45db161d.h"
#include "ExtSPImem.h"
#include "heapExmem.h"

/* Defining MPU_WRAPPERS_INCLUDED_FROM_API_FILE prevents task.h from redefining
all the API functions to use the MPU wrappers.  That should only be done when
task.h is included from an application file. */
//#define MPU_WRAPPERS_INCLUDED_FROM_API_FILE

#include "FreeRTOS.h"
#include "task.h"
#include "main.h"

//#undef MPU_WRAPPERS_INCLUDED_FROM_API_FILE

// размер должен быть не очень маленьким
#define SPIheapMINIMUM_BLOCK_SIZE	( ( size_t ) ( SPIHeapStructSize * 2 ) )

/* Assumes 8bit bytes! */
#define BITS_PER_BYTE		( ( size_t ) 8 )


// структура списка в памяти
typedef struct SPI_Mem_Block
{
	uint32_t	pxAddresBlock;			// адрес текущего блока
	uint32_t	pxNextFreeBlock;		// следующий свободный блок в списке
	uint32_t 	xBlockSize;				// размер блока  The size of the free block.
} SPI_BlockLink_t;

/*-----------------------------------------------------------*/

/*
 * Inserts a block of memory that is being freed into the correct position in
 * the list of free memory blocks.  The block being freed will be merged with
 * the block in front it and/or the block behind it if the memory blocks are
 * adjacent to each other.
 */
static void SPIInsertBlockIntoFreeList( SPI_BlockLink_t SPIBlockToInsert );


// используется для первого инита кучи в SPIпамяти, вызывается в SPIPortMalloc()
static void SPIHeapInit( void );

/*-----------------------------------------------------------*/

// Размер структуры размещен в начале каждой выделенной памяти.
static const size_t SPIHeapStructSize	= ( ( sizeof( SPI_BlockLink_t ) + ( portBYTE_ALIGNMENT - 1 ) ) & ~portBYTE_ALIGNMENT_MASK );

// 2-е ссылки на начало и конец списка в памяти SPI
static SPI_BlockLink_t SPIStart, SPIEnd;

// Отслеживает число свободных оставшихся байт
static size_t SPIFreeBytesRemaining = 0U;
static size_t SPIMinimumEverFreeBytesRemaining = 0U;

// Когда этот бит в элементе BlockSize из структуры BlockLink_t установлен, то блок принадлежит приложению.
// Когда бит свободен блок все еще является частью свободной памяти в куче
static size_t SPIBlockAllocatedBit = 0;

/*-----------------------------------------------------------*/
uint8_t 	SPIPortWrite(uint32_t addres, uint8_t *data, size_t Size )
{
	if(!memory_write(data,addres,Size)) {
		return FALSE;
	}
	return TRUE;
}
/*************************************************************************
 * SPIPortRead
 *  Size - размер блока для чтения. Если = 0 то читаем из
 *  заголовка размер и вычитывем до конца диапазон.
 *************************************************************************/
uint8_t		SPIPortRead(uint32_t addres, uint8_t *data, size_t Size )
{
	SPI_BlockLink_t		SPIHeap;
	if (Size == 0) {										// если размер = 0 то нужно из головы блока прочитать размер и прочитать весь блок до конца.
		if(!memory_read((uint8_t *)&SPIHeap, addres - SPIHeapStructSize , SPIHeapStructSize)) {
				return FALSE;
			}															// возможно нужно вернуть его размер.
		Size = SPIHeap.xBlockSize & ~SPIBlockAllocatedBit;				// откинем бит принадлежности к занятой памяти.
	}
	if(!memory_read(data,addres,Size)) {
		return FALSE;
	}
	return TRUE;
}
/*-----------------------------------------------------------*/

uint32_t 	SPIPortMalloc( size_t xWantedSize )
{
SPI_BlockLink_t SPIBlock, SPIPreviousBlock, SPINewBlockLink;
uint32_t Return = 0;
int8_t	ret;


//TODO: возможно критическая секция, или доступ к SPI надо мониторить
// добавить контроль или блокировку
	vTaskSuspendAll();
	{
		if( SPIEnd.pxAddresBlock == 0 )	SPIHeapInit();							// первый инит кучи.


		if( ( xWantedSize & SPIBlockAllocatedBit ) == 0 )						// проверим, этот блок свободен ??
		{

			if( xWantedSize > 0 )
			{
				xWantedSize += SPIHeapStructSize;								// добавим память для структуры кучи (заголовка)

				if( ( xWantedSize & portBYTE_ALIGNMENT_MASK ) != 0x00 )			// Убедитесь, что блоки всегда выровнены к требуемому числу байтов
				{
					// надо выровнять
					xWantedSize += ( portBYTE_ALIGNMENT - ( xWantedSize & portBYTE_ALIGNMENT_MASK ) );
					configASSERT( ( xWantedSize & portBYTE_ALIGNMENT_MASK ) == 0 );
				}
			}


			if( ( xWantedSize > 0 ) && ( xWantedSize <= SPIFreeBytesRemaining ) )									// если есть ещё память нужного размера
			{

				ret = memory_read((uint8_t *)&SPIPreviousBlock,0,sizeof(SPI_BlockLink_t));
				if (!ret) return 0;
				ret = memory_read((uint8_t *)&SPIBlock, SPIPreviousBlock.pxNextFreeBlock, sizeof(SPI_BlockLink_t));		// вычитываем следующий элемент (только заголовок)
				if (!ret) return 0;
				while( (( SPIBlock.xBlockSize < xWantedSize ) && ( SPIBlock.pxNextFreeBlock != 0 )) )				// если
				{
					SPIPreviousBlock.pxAddresBlock 		= SPIBlock.pxAddresBlock;									// берём первый элемент кучи
					SPIPreviousBlock.pxNextFreeBlock 	= SPIBlock.pxNextFreeBlock;
					SPIPreviousBlock.xBlockSize 		= SPIBlock.xBlockSize;
					ret = memory_read((uint8_t *)&SPIBlock, SPIPreviousBlock.pxNextFreeBlock, sizeof(SPI_BlockLink_t));	// вычитываем следующий элемент (только заголовок)
					if (!ret) return 0;
				}
																													// если долисталь до конца то подходящего блока не осталось, уходим.
				if( SPIBlock.pxAddresBlock != SPIEnd.pxAddresBlock )
				{
					// перепрыгиваем через структуру кучи (xHeapStructSize) получаем адрес самого блока данных он нужен чтобы вернуть из функции
					Return =  SPIBlock.pxAddresBlock + (uint32_t)SPIHeapStructSize;

					if( ( SPIBlock.xBlockSize - xWantedSize ) > SPIheapMINIMUM_BLOCK_SIZE )							// Если блок больше, чем требуется его можно разделить на две части. Но часть должна быть больше heapMINIMUM_BLOCK_SIZE
					{
						SPINewBlockLink.pxAddresBlock = SPIBlock.pxAddresBlock  + xWantedSize;						// указатель на второй блок(оставшийся) после разделения.
						configASSERT( (SPINewBlockLink.pxAddresBlock  & portBYTE_ALIGNMENT_MASK ) == 0 );
						SPINewBlockLink.pxNextFreeBlock = 0;

						// Расчет размеров двух блоков отколовшихся от одного блока.
						SPINewBlockLink.xBlockSize = SPIBlock.xBlockSize - xWantedSize;								// размер оставшегося блока
						SPIBlock.xBlockSize = xWantedSize;															// размер выделенного для нас блока

						// я добавил
						SPIBlock.pxNextFreeBlock = SPINewBlockLink.pxAddresBlock;

						// Включить новый(отделённый) блок в список свободных блоков.
						SPIInsertBlockIntoFreeList( SPINewBlockLink );
					}

					// Этот блок берём для использования, поэтому удаляем из списка свободных блоков
					// т.е. адрес следующего присваисаем адресу предыдущего.
					//SPIPreviousBlock.pxNextFreeBlock = SPIBlock.pxAddresBlock  + xWantedSize;//SPIBlock.pxNextFreeBlock; // так не правильно, возможно что и не надо разбивать блок на части тогда адрес следующего будет прежним
					SPIPreviousBlock.pxNextFreeBlock = SPIBlock.pxNextFreeBlock;

					SPIFreeBytesRemaining -= SPIBlock.xBlockSize;												// оставшаяся свободная память
					if( SPIFreeBytesRemaining < SPIMinimumEverFreeBytesRemaining )
						SPIMinimumEverFreeBytesRemaining = SPIFreeBytesRemaining;								// минимум достигнутый за время работы

					// Блок возвращается - он выделяется и принадлежит приложению и не имеет следующего блока.
					SPIBlock.xBlockSize |= SPIBlockAllocatedBit;												// устанавливаем старший бит (блок принадлежит приложению.)
					SPIBlock.pxNextFreeBlock = 0;																// укажем что после нас в списке нету никого

					ret = memory_write((uint8_t *)&SPIPreviousBlock,SPIPreviousBlock.pxAddresBlock,sizeof(SPI_BlockLink_t));
					if (!ret) return 0;
					ret = memory_write((uint8_t *)&SPIBlock,SPIBlock.pxAddresBlock,sizeof(SPI_BlockLink_t));
					if (!ret) return 0;
				}
			}
		}

	}
	( void ) xTaskResumeAll();

	configASSERT( ( ( uint32_t ) Return  & portBYTE_ALIGNMENT_MASK ) == 0 );

	USART_TRACE_BLUE("Осталось память SPI:%u\n",(unsigned int)SPIFreeBytesRemaining);

	return Return;
}
/*-----------------------------------------------------------*/
void SPIPortFree( uint32_t pv )
{
	uint32_t 		puc = pv;
	SPI_BlockLink_t pxLink;
	int8_t	ret;

	if( pv != 0 )
	{
		puc -= SPIHeapStructSize;

		ret = memory_read((uint8_t *)&pxLink,puc,sizeof(SPI_BlockLink_t));
		if (!ret) {USART_TRACE_RED("Ошибка освобождения памяти SPI.\n");}
		// проверим, был ли на самом деле выделен блок памяти
		configASSERT( ( pxLink.xBlockSize & SPIBlockAllocatedBit ) != 0 );
		configASSERT( pxLink.pxNextFreeBlock == 0 );

		if( ( pxLink.xBlockSize & SPIBlockAllocatedBit ) != 0 )
		{
			if( pxLink.pxNextFreeBlock == 0 )
			{
				//Блок возвращается в кучу - он больше не выделен
				pxLink.xBlockSize &= ~SPIBlockAllocatedBit;

				vTaskSuspendAll();
				{
					// Добавить этот блок в список свободных блоков.
					SPIFreeBytesRemaining += pxLink.xBlockSize;
					SPIInsertBlockIntoFreeList(pxLink);
				}
				( void ) xTaskResumeAll();
			}
		}
	}
	USART_TRACE_BLUE("Осталось память SPI:%u\n",(unsigned int)SPIFreeBytesRemaining);

}
/*-----------------------------------------------------------*/

size_t SPIPortGetFreeHeapSize( void )
{
	return SPIFreeBytesRemaining;
}
/*-----------------------------------------------------------*/

size_t SPIPortGetMinimumEverFreeHeapSize( void )
{
	return SPIMinimumEverFreeBytesRemaining;
}
/*-----------------------------------------------------------*/

void SPIPortInitialiseBlocks( void )
{
	/* This just exists to keep the linker quiet. */
}
/*-----------------------------------------------------------*/

static void SPIHeapInit( void )
{
SPI_BlockLink_t 	SPIFirstFreeBlock;

/*
 *  нужно прочитать при первом ините из SPI:
 * 	SPIStart 	- адрес начала блока данных
 * 	SPIEnd		- адрес конца блока данных
 *
 */
	AT45DB161D_spi_init();

	// SPIStart пустой блок используется для хранения указателя на первый элемент в списке свободных блоков.
	SPIStart.pxAddresBlock = 0;
	SPIStart.pxNextFreeBlock = SPIHeapStructSize;		// адрес начала данных.
	SPIStart.xBlockSize =  0;							// размер блока.

	memory_write((uint8_t *)&SPIStart,SPIStart.pxAddresBlock ,sizeof(SPI_BlockLink_t));

	// конец блока данных
	SPIEnd.pxAddresBlock = SPI_DEVICE_SIZE - SPIHeapStructSize;
	SPIEnd.pxNextFreeBlock = 0;
	SPIEnd.xBlockSize = SPIHeapStructSize;

	memory_write((uint8_t *)&SPIEnd,SPIEnd.pxAddresBlock,sizeof(SPI_BlockLink_t));

	// Для начала есть один свободный блок, который имеет такие размеры, чтобы занять всю пространство кучи, минус пространство, принятое pxEnd.
	SPIFirstFreeBlock.pxAddresBlock = SPIStart.pxNextFreeBlock;
	SPIFirstFreeBlock.xBlockSize = SPI_DEVICE_SIZE - SPIFirstFreeBlock.pxAddresBlock - SPIHeapStructSize;
	SPIFirstFreeBlock.pxNextFreeBlock = SPIEnd.pxAddresBlock;

	memory_write((uint8_t *)&SPIFirstFreeBlock,SPIFirstFreeBlock.pxAddresBlock,sizeof(SPI_BlockLink_t));

	SPIMinimumEverFreeBytesRemaining = SPIFirstFreeBlock.xBlockSize;
	SPIFreeBytesRemaining = SPIFirstFreeBlock.xBlockSize;

	USART_TRACE_BLUE("Объем свободной памяти SPI: %u\n",SPIFreeBytesRemaining);

	SPIBlockAllocatedBit = ( ( size_t ) 1 ) << ( ( sizeof( size_t ) * BITS_PER_BYTE ) - 1 );

}
/*-----------------------------------------------------------*/
static void SPIInsertBlockIntoFreeList( SPI_BlockLink_t SPIBlockToInsert )
{
SPI_BlockLink_t 	SPIIterator,SPINextIterator;
uint32_t 			puc;
int8_t		ret;
SPI_BlockLink_t		SPIBlockToInsertTmp;

	SPIBlockToInsertTmp.pxAddresBlock 	= SPIBlockToInsert.pxAddresBlock;
	SPIBlockToInsertTmp.pxNextFreeBlock = SPIBlockToInsert.pxNextFreeBlock;
	SPIBlockToInsertTmp.xBlockSize 		= SPIBlockToInsert.xBlockSize;

	ret = memory_read((uint8_t *)&SPIIterator,0,sizeof(SPI_BlockLink_t));
	if (!ret) {USART_TRACE_RED("Ошибка добавления свободного блока памяти SPI.\n");}

	// Ищем последний свободный блок, который находится перед нашим блоком SPIBlockToInsert
	while( SPIIterator.pxNextFreeBlock < SPIBlockToInsertTmp.pxAddresBlock ){
		ret = memory_read((uint8_t *)&SPIIterator, SPIIterator.pxNextFreeBlock, sizeof(SPI_BlockLink_t));
		if (!ret) {USART_TRACE_RED("Ошибка добавления свободного блока памяти SPI.\n");}

	}

	// -------------------------------------------------------------------------------------
	// [ SPIIterator(другой пустой блок) ] [ SPIBlockToInsert]
	// если наш блок равен размеру в который вставляем блок,
	// и он находится в конце другого пустого блока то делаем один непрерывный блок.
	// -------------------------------------------------------------------------------------
	puc = SPIIterator.pxAddresBlock;
	if( ( puc + SPIIterator.xBlockSize ) ==  SPIBlockToInsertTmp.pxAddresBlock )		// если предыдущий перед этим блоком пустой и между нашим и этим блоком нету блоков
	{
		SPIIterator.xBlockSize += SPIBlockToInsertTmp.xBlockSize;						// увеличим предыдущий блок

		SPIBlockToInsertTmp.xBlockSize = SPIIterator.xBlockSize;						// и присвоим его новому объединенному уже большему блоку.
		SPIBlockToInsertTmp.pxAddresBlock = SPIIterator.pxAddresBlock;
		SPIBlockToInsertTmp.pxNextFreeBlock = SPIIterator.pxNextFreeBlock;
	}

	// -------------------------------------------------------------------------------------
	// [ SPIBlockToInsert ] [ SPIIterator(другой пустой блок)]
	//  [ SPIIterator(другой пустой блок)] [ SPIBlockToInsert ] [ SPIIterator(другой пустой блок)] - тоже прокатывает
	// если наш блок равен размеру в который вставляем блок,
	// и он находится в начале другого пустого блока то делаем один непрерывный блок.
	// -------------------------------------------------------------------------------------
	puc = SPIBlockToInsertTmp.pxAddresBlock;
	if( ( puc + SPIBlockToInsertTmp.xBlockSize ) == SPIIterator.pxNextFreeBlock )		// если следующий блоком пустой и между нашим и этим блоком нету блоков
	{
		if( SPIIterator.pxNextFreeBlock != SPIEnd.pxAddresBlock )
		{
			ret = memory_read((uint8_t *)&SPINextIterator, SPIIterator.pxNextFreeBlock, sizeof(SPI_BlockLink_t));
			if (!ret) {USART_TRACE_RED("Ошибка добавления свободного блока памяти SPI.\n");}

			SPIBlockToInsertTmp.xBlockSize += SPINextIterator.xBlockSize;
			SPIBlockToInsertTmp.pxNextFreeBlock = SPINextIterator.pxNextFreeBlock;
		}
		else
		{
			SPIBlockToInsertTmp.pxNextFreeBlock = SPIEnd.pxAddresBlock;
		}
	}
	else
	{
		SPIBlockToInsertTmp.pxNextFreeBlock = SPIIterator.pxNextFreeBlock;
	}

	// -------------------------------------------------------------------------------------

	if( SPIIterator.pxAddresBlock != SPIBlockToInsertTmp.pxAddresBlock )
	{
		SPIIterator.pxNextFreeBlock = SPIBlockToInsertTmp.pxAddresBlock;
	}

	ret = memory_write((uint8_t *)&SPIIterator,SPIIterator.pxAddresBlock,sizeof(SPI_BlockLink_t));
	if (!ret) {USART_TRACE_RED("Ошибка добавления свободного блока памяти SPI.\n");}
	ret = memory_write((uint8_t *)&SPIBlockToInsertTmp,SPIBlockToInsertTmp.pxAddresBlock,sizeof(SPI_BlockLink_t));
	if (!ret) {USART_TRACE_RED("Ошибка добавления свободного блока памяти SPI.\n");}

}

