#include "stm32f10x.h"

void RCC_Config (void){
  RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;   // Enable clock for PORTA.
  RCC->APB2ENR |= RCC_APB2ENR_USART1EN; // Enable clock for USART1.
}
