#include "stm32f10x.h"

void TIMER2_Config (void);
void TIMER3_Config (void);
void TIMER4_Config (void);

void TIMER_Config (void){
  TIMER2_Config();
  //TIMER3_Config();
  //TIMER4_Config();
}

void TIMER2_Config (void){
  TIM2->DIER |= TIM_DIER_UIE;    // Timer 3 interrupt enable.
	TIM2->CR1 |= TIM_CR1_ARPE;     // Timer 3 auto preload.
  TIM2->PSC = 7999;              // Timer 3 prescaler.
  TIM2->ARR = 3000;               // Timer 3 autoreload value.
  TIM2->CR1 |= TIM_CR1_CEN;      // Timer 3 enable.
}

void TIMER3_Config (void){
  TIM3->DIER |= TIM_DIER_UIE;    // Timer 3 interrupt enable.
	TIM3->CR1 |= TIM_CR1_ARPE;     // Timer 3 auto preload.
	TIM3->PSC = 7999;              // Timer 3 prescaler.
	TIM3->ARR = 100;               // Timer 3 autoreload value.
  TIM3->CR1 |= TIM_CR1_OPM;      // One pulse mode.
  TIM3->CR1 |= TIM_CR1_CEN;      // Timer 3 enable.
}

void TIMER4_Config (void){
  TIM4->DIER |= TIM_DIER_UIE;    // Timer 4 interrupt enable.
	TIM4->CR1 |= TIM_CR1_ARPE;     // Timer 4 auto preload.
	TIM4->PSC = 7;                 // Timer 4 prescaler.
	TIM4->ARR = 10;               // Timer 4 autoreload value.
  //TIM4->CR1 |= TIM_CR1_OPM;    // One pulse mode.
  TIM4->CR1 |= TIM_CR1_CEN;      // Timer 4 enable.
}
