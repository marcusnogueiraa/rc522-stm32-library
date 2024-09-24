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

#define ENABLE_RX
#define ENABLE_TX
#define ENABLE_IRQ

void usartSetup();
void uart_write(uint8_t *ch);

#endif /* UART_H_ */
