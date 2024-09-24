/*
 * uart.h
 *
 *  Created on: Sep 22, 2024
 *      Author: guilherme
 */

#ifndef __UART_H_
#define __UART_H_

#include "stm32f1xx.h"

#define CPU_CLK 	8000000
#define BaudRate	115200


void USART1_Init();
void uart_write(uint8_t *ch);
void int_to_string(uint8_t* data, int size, uint8_t* str);


#endif /* UART_H_ */

