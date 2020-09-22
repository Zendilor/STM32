#include "stm32f10x.h"

void USART1_Config (void);

void USART_Config (void){
	USART1_Config();
}

void USART1_Config (void){
	USART1->BRR = 0x34D;
	USART1->CR1 |= USART_CR1_TE;
	USART1->CR1 |= USART_CR1_RE;
	USART1->CR1 |= USART_CR1_UE;
}
