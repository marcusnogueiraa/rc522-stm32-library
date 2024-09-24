/*
 * uart.c
 *
 *  Created on: Sep 22, 2024
 *      Author: guilherme
 */
#include "uart.h"

#ifdef ENABLE_IRQ
uint8_t *ptr;

void USART1_IRQHandler(void)
{
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
}
#endif


void usartTXSetup(){
		//enable clock access to GPIOA
		RCC->APB2ENR|=RCC_APB2ENR_IOPAEN;

		/*Configure PA9(TX) as output maximum speed to 50MHz
		 * and alternate output push-pull mode for USART1*/
		GPIOA->CRH &= 0xFFFFFF0F;
		GPIOA->CRH |= 0x000000B0;

		/*USART1 configuration*/
		//Transmit Enable
		USART1->CR1 |= USART_CR1_TE;
}

void usartRXSetup(){
	/*UART1 Pin configuration*/
		//enable clock access to GPIOA
		RCC->APB2ENR|=RCC_APB2ENR_IOPAEN;

		//Configure PA10(RX) as as input floating as following
		GPIOA->CRH &= 0xFFFFF0FF;
		GPIOA->CRH |= 0x00000400;

		/*USART1 configuration*/

		//Enable receiver
		USART1->CR1 |= USART_CR1_RE;
		//Enable RXNIE interrupt
		USART1->CR1|=USART_CR1_RXNEIE;

}

void usartSetup(){
#ifdef ENABLE_TX
		usartTXSetup();
#endif

#ifdef ENABLE_RX
		usartRXSetup();
#endif

	//enable clock access to USART1
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
	//Enable receiver
	USART1->CR1 |= USART_CR1_RE;
	//Set Baud Rate
	USART1->BRR = ((CPU_CLK + (BaudRate/2U))/BaudRate);

	//Enable UART
	USART1->CR1 |= USART_CR1_UE;

#ifdef ENABLE_RX
	//Enable USART1 interrupt in NVIC
	NVIC_EnableIRQ(USART1_IRQn);
#endif
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
