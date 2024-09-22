/*
 * uart.h
 *
 *  Created on: Sep 22, 2024
 *      Author: guilherme
 */

#ifndef UART_H_
#define UART_H_

#include "stm32f1xx.h"
#define CPU_CLK 	8000000
#define BaudRate	115200

void usartSetup();

#endif /* UART_H_ */
