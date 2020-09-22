#include "SPI.h"
#include "stm32f10x.h"

void SPI1_Config (void);

void SPI_Config (void){
	SPI1_Config();
}

void SPI1_Config (void){
	SPI1->CR1 |= SPI_CR1_MSTR;	// Set SPI master.
	SPI1->CR1	|= SPI_CR1_SSM;		// Sowtware slave management.
	SPI1->CR1	|= SPI_CR1_SSI;		// Iternal slave select.
	SPI1->CR1 |= SPI_CR1_SPE;		// SPI enable.
}

char SPI_Send (char data){		// SPI1 Send data.
	//while(!(SPI1->SR & SPI_SR_TXE));
	SPI1->DR = data;
	//while(SPI1->SR & SPI_SR_BSY);
	while(!(SPI1->SR & SPI_SR_RXNE));
	return SPI1->DR;
}

