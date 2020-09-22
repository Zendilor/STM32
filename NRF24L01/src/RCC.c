#include "stm32f10x.h"

void RCC_Config (void){
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;		// Enable clock for alternative functions.
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;		// Enable clock for PORTA.
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;		// Enable clock for PORTB.
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;	// Enable clock for USART1.
	RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;		// Enable clock for SPI1.
	RCC->APB1ENR |= RCC_APB1ENR_SPI2EN;		// Enable clock for SPI2.
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;		// Enable clock for TIMER4.
}
