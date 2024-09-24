/*
 * uart.c
 *
 *  Created on: Sep 22, 2024
 *      Author: guilherme
 */
#include "uart.h"


#include <stdint.h>
#include "stm32f1xx.h"



uint8_t *ptr;

void USART1_Init(){

	GPIOA->CRH &= 0xFFFFFF0F;
	GPIOA->CRH |= 0x000000B0;
	//enable clock access to USART1
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;

	//Transmit Enable
	USART1->CR1 |= USART_CR1_TE;

	//Set Baud Rate
	USART1->BRR = ((CPU_CLK + (BaudRate/2U))/BaudRate);

	//Enable UART
	USART1->CR1 |= USART_CR1_UE;

	//Enable USART1 interrupt in NVIC
	NVIC_EnableIRQ(USART1_IRQn);
}
void USART1_IRQHandler(void)
{
	GPIOB->ODR |= 0x00000100;
	if((USART1->SR&USART_SR_TXE))
	{
		if(*ptr)
		{
			USART1->DR	=  (*ptr & 0xFF);
			ptr++;
		}
		else
			USART1->CR1 &= ~USART_CR1_TXEIE; //At end of MSG, disable interrupt
	}
	GPIOB->ODR &= ~0x00000100;
}

void uart_write(uint8_t *ch)
{
	//Make sure the transmit data register is empty
	while(!(USART1->SR & USART_SR_TXE)){}
	//Send first byte
	USART1->DR	=  (*ch & 0xFF);
	//Update Global ptr
	ptr = ch+1;

	//Enable TXE interrupt
	USART1->CR1 |= USART_CR1_TXEIE;
}

void int_to_string(uint8_t* data, int size, uint8_t* str) {
    int index = 0;

    for (int i = 0; i < size; i++) {
        uint8_t num = data[i];
        if (num < 10) {
            str[index++] = num + '0';
        } else if (num < 100) {
            str[index++] = (num / 10) + '0';
            str[index++] = (num % 10) + '0';
        } else {
            str[index++] = (num / 100) + '0';
            str[index++] = ((num / 10) % 10) + '0';
            str[index++] = (num % 10) + '0';
        }
        if (i < size - 1) {
            str[index++] = '-';
        }
    }

    str[index] = '\0';
}

