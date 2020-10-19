#include "stm32f10x.h"
#include "INDICATION.h"

void ADC1_Config (void);

void ADC_Config (void){
  ADC1_Config();
}

void ADC1_Config (void){
  ADC1->CR1 |= ADC_CR1_EOCIE;   // ADC1 interrupt enable.
  ADC1->CR2 |= ADC_CR2_CONT;    // ADC1 continuous conversion mode.
  ADC1->CR2 |= ADC_CR2_ADON;    // ADC1 enable.
  ADC1->CR2 |= ADC_CR2_EXTSEL | ADC_CR2_EXTTRIG;
  ADC1->CR2 |= ADC_CR2_SWSTART;
}
