#include "stm32f10x.h"

void TIMER4_Config (void);

void TIMER_Config (void){
  TIMER4_Config();
}


void TIMER4_Config (void){
  TIM4->DIER |= TIM_DIER_UIE;   // Timer 4 interrupt enable.
	TIM4->CR1 |= TIM_CR1_CEN;     // Timer 4 enable.
	TIM4->CR1 |= TIM_CR1_ARPE;    // Timer 4 auto preload.
	TIM4->PSC = 7;                // Timer 4 prescaler.
	TIM4->ARR = 6000;            // Timer 4 autoreload value.
}
