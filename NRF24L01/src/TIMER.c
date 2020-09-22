#include "stm32f10x.h"

void TIMER4_Config (void);

void TIMER_Config (void){
	TIMER4_Config();
}

void TIMER4_Config (void){
	TIM4->DIER |= TIM_DIER_UIE;	// Timer4 interrupt enable.
	TIM4->CR1 |= TIM_CR1_CEN;
	TIM4->CR1 |= TIM_CR1_ARPE;
	TIM4->CR1 |= TIM_CR1_OPM;
	TIM4->PSC = 8;
	TIM4->ARR = 8;
}
