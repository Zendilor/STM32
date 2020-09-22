#include "stm32f10x.h"
#include "NRF24L01.h"

void INTERRUPT_Config (void){
	NVIC->ISER [0] |= NVIC_ISER_SETENA_30;	// Enable interrupt for TIMER4.
	NVIC->ISER [1] |= NVIC_ISER_SETENA_5;		// Enable interrupt for USART1.
}

void USART1_IRQHandler (void){
	USART1->SR &= ~USART_SR_RXNE;
	//NRF_SEND(TX74_ADDR, sizeof TX74_ADDR);
}

void TIM4_IRQHandler (void){
	TIM4->SR &= ~TIM_SR_UIF;	// Clear interrupt flag Timer4.
	GPIOB->BSRR = GPIO_BSRR_BR0;
	
}
