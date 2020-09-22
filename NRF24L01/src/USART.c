#include "stm32f10x.h"
#include "USART.h"

void USART1_Config (void);

void USART_Config (void){
	USART1_Config();
}

void USART1_Config (void){
	USART1->CR1 |= USART_CR1_TE;			// Transmitter enable.
	USART1->CR1 |= USART_CR1_RE;			// Receiver enable.
	USART1->CR1 |= USART_CR1_UE;			// USART enable.
	USART1->CR1 |= USART_CR1_RXNEIE;	// Enable RX interrupt.
	USART1->BRR = BOUD_RATE;					// Set BOUD rate.
}

void USART1_Send (char data){
	while(!(USART1->SR & USART_SR_TC));
	USART1->DR = data;
}

void USART1_Send_Buff(char *buff, char count){
	while(count--){
		USART1_Send(*(buff++));
	}
}
