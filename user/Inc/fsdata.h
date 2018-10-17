/*
 * fsdata.h
 *
 */

#ifndef __FSDATA_H__
#define __FSDATA_H__

#define	_FileSystemQueueSize		10


typedef void	(*FSAfterHandler) (void* parameter);


typedef struct
 {
	const char* 	file;			// имя файла
	uint8_t* 		Data;			// указатель на буфер
	uint16_t 		numb;			// размер буфера в байтах
	uint8_t			mode;			// режим доступа к файлу
	FSAfterHandler	handler;		// указатель на функцию
	void* 			parameter;		// параметр для функции
 }FSQueueMessage;

struct fsdata_file {
  const struct fsdata_file *next;
  const char *name;
  const char *data;
  const int len;
};

struct fsdata_file_noconst {
  struct fsdata_file *next;
  char *name;
  char *data;
  int len;
};

void StartFSTask(void const * argument);

#endif /* __FSDATA_H__ */
