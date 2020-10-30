#include "stm32f10x.h"
#include "INDICATION.h"
#include "USART.h"

void ADC1_Config (void);

void ADC_Config (void){
  ADC1_Config();
}

void ADC1_Config (void){
  ADC1->SMPR2 |= ADC_SMPR2_SMP0;      // ADC1 Channel sample time selection.
  ADC1->CR1 |= ADC_CR1_EOCIE;         // ADC1 interrupt enable.
  //ADC1->CR2 |= ADC_CR2_CONT;          // ADC1 continuous conversion mode.
  ADC1->CR2 |= ADC_CR2_CAL;           // ADC1 start calibration.
  while(!(ADC1->CR2 & ADC_CR2_CAL));  // ADC1 Calibration.
  ADC1->CR2 |= ADC_CR2_ADON;          // ADC1 enable.
  ADC1->CR2 |= ADC_CR2_EXTTRIG;       // ADC1 start conversion on external trigger.
  ADC1->CR2 |= ADC_CR2_EXTSEL;        // ADC1 external event select for regular group.
  ADC1->CR2 |= ADC_CR2_SWSTART;       // ADC1 Start conversion.
}
