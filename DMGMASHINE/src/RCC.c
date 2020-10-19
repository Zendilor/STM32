#include "stm32f10x.h"

void RCC_Config (void){
  RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;   // Enable clock for TIMER 4.
  RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;   // Enable alternative function.
  RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;   // Enable clock for PORTA.
  RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;   // Enable clock for PORTB.
  RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;   // Enable clock for ADC1.
  RCC->APB2ENR |= RCC_APB2ENR_USART1EN; // Enable clock for USART1.
}
