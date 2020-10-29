/*
 * spi_drive.h
 *
 *  Created on: 27 окт. 2020 г.
 *      Author: admin
 */

#ifndef SPI_DRIVESLAVE_H_
#define SPI_DRIVESLAVE_H_

#include "stm32f1xx_hal.h"
#include "main.h"

extern SPI_HandleTypeDef hspi1;


uint8_t spiRecBuf[1];

#define SPI_SEND_8_BIT(val) HAL_SPI_Transmit(&hspi1, (uint8_t*)val, 1, 0);
#define SPI_RECEIVE_8_BIT  HAL_SPI_Receive(&hspi1, (uint8_t*) 1, (uint8_t *)spiBuf, 1, 5);



typedef struct {
	uint8_t bit0: 1;
	uint8_t bit1: 1;
	uint8_t bit2: 1;
	uint8_t bit3: 1;
	uint8_t bit4: 1;
	uint8_t bit5: 1;
	uint8_t bit6: 1;
	uint8_t bit7: 1;
} bits;

typedef union
{
	bits bits;
	uint8_t all;
} byte;

typedef struct {
	byte start;
	byte dataHi;
	byte dataLow;
	byte crcHi;
	byte crcLow;
} spi_msg_w;

spi_msg_w msg_write;



void delay_us(int value);

void spi_read(uint8_t adr_reg, uint8_t numbers);

void spi_write(uint8_t adr_reg, uint16_t val);



#endif /* SPI_DRIVESLAVE_H_ */
