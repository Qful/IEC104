/*
 * datatoGGIO.h
 *
 *  Created on: 19.04.2017
 *      Author: sagok
 */

#ifndef DATATOGGIO_H_
#define DATATOGGIO_H_

void	Set_VZGGIO	(uint8_t num, uint64_t currentTime );
void	Set_AVRGGIO	(uint8_t num, uint64_t currentTime );
void	Set_XCBRGGIO	(uint8_t num, uint64_t currentTime );
void	Set_INGGIO	(uint8_t num, uint64_t currentTime );
void	Set_OUTGGIO	(uint8_t num, uint64_t currentTime );
void	Set_SSLGGIO	(uint8_t num, uint64_t currentTime );
void	Set_VLSGGIO	(uint8_t num, uint64_t currentTime );
void	Set_LSGGIO	(uint8_t num, uint64_t currentTime );

void	Set_NBLKGGIO	(uint8_t num, uint64_t currentTime );


void	Set_LEDGGIO	(uint8_t num, uint64_t currentTime );
#endif /* DATATOGGIO_H_ */
