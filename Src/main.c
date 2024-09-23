#include <stdint.h>
#include "stm32f1xx.h"

void SPI_Init() {
	RCC->APB2ENR |= (1 << 12);      // Enable SPI1 CLock
	SPI1->CR1 &= ~(1 << 0) | (1 << 1);  // CPOL=0, CPHA=0
	SPI1->CR1 |= (1 << 2);        // Master Mode
	SPI1->CR1 |= (2 << 3);        // BR[2:0] = 010: fPCLK/8, PCLK2 = 72MHz, SPI clk = 9MHz
	SPI1->CR1 &= ~(1 << 7);        // LSBFIRST = 0, MSB first
	SPI1->CR1 |= (1 << 8) | (1 << 9);    // SSM=1, SSi=1 -> Software Slave Management
	SPI1->CR1 &= ~(1 << 10);        // RXONLY = 0, full-duplex
	SPI1->CR1 &= ~(1 << 11);        // DFF=0, 8 bit data
	SPI1->CR1 |= (1 << 6);        // SPE=1, Peripheral enabled
}

int main(void)
{

	while(1){}
}
