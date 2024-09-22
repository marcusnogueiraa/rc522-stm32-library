/*
 * uart.c
 *
 *  Created on: Sep 22, 2024
 *      Author: guilherme
 */
#include "uart.h"

void usartSetup(){
	//enable clock access to USART1
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
	//Enable receiver
	USART1->CR1 |= USART_CR1_RE;
	//Set Baud Rate
	USART1->BRR = ((CPU_CLK + (BaudRate/2U))/BaudRate);
	//Enable RXNIE interrupt
	USART1->CR1|=USART_CR1_RXNEIE;

	//Enable USART1 interrupt in NVIC
	NVIC_EnableIRQ(USART1_IRQn);

	//Enable UART
	USART1->CR1 |= USART_CR1_UE;
}
