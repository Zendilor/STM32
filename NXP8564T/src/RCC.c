#include "stm32f10x.h"

void RCC_Config (void){
	RCC->CR |= RCC_CR_HSEON;							// Enable HSE.
	while(!(RCC->CR & RCC_CR_HSERDY));		// Wait HSERDY.
	RCC->CFGR |= RCC_CFGR_SW_HSE;					// Switch system clock on HSE.
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;		// Enable clock for PORT A.
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;		// Enable clock for PORT B.
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;	// Enable clock for USART1.
	RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;		// Enable clock for I2C1.
}
