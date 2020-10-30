#include "stm32f10x.h"
#include "INDICATION.h"
#include "USART.h"
#include "TIMER.h"
#include "GPIO.h"
#include "MODBUSRTU.h"

float coef = 0.000805664;
float coef_n = 3.03030303;
float coef_a = 0.305;
float data_ADC = 0;
float tara = 0;

char data [] = {0x0A, 0x01, 0x00, 0x06, 0x00, 0x01, 0x1C, 0xB0};

void INTERRUPT_Config (void){
  NVIC->ISER [0] |= NVIC_ISER_SETENA_8;       // Enable interrupt for EXTI2.
  NVIC->ISER [0] |= NVIC_ISER_SETENA_9;       // Enable interrupt for EXTI3.
  NVIC->ISER [0] |= NVIC_ISER_SETENA_10;      // Enable interrupt for EXTI4.
  NVIC->ISER [0] |= NVIC_ISER_SETENA_18;      // Enable interrupt for ADC1.
  NVIC->ISER [0] |= NVIC_ISER_SETENA_28;      // Enable interrupt for TIMER2.
  NVIC->ISER [0] |= NVIC_ISER_SETENA_29;      // Enable interrupt for TIMER3.
  NVIC->ISER [0] |= NVIC_ISER_SETENA_30;      // Enable interrupt for TIMER4.

  AFIO->EXTICR [0] |= AFIO_EXTICR1_EXTI2_PA;  // Set interrupt on PA2.
  AFIO->EXTICR [0] |= AFIO_EXTICR1_EXTI3_PA;  // Set interrupt on PA3.
  AFIO->EXTICR [1] |= AFIO_EXTICR2_EXTI4_PA;  // Set interrupt on PA4.

  EXTI->RTSR |= EXTI_RTSR_TR2;                // Interrupt on rising trigger.
  EXTI->RTSR |= EXTI_RTSR_TR3;                // Interrupt on rising trigger.
  EXTI->RTSR |= EXTI_RTSR_TR4;                // Interrupt on rising trigger.

  EXTI->IMR |= EXTI_IMR_MR2;                  // Set mask on interrupt.
  EXTI->IMR |= EXTI_IMR_MR3;                  // Set mask on interrupt.
  EXTI->IMR |= EXTI_IMR_MR4;                  // Set mask on interrupt.
}

void ADC1_2_IRQHandler (void){
  if(GPIOA->IDR & GPIO_IDR_IDR1){
    data_ADC = ((ADC1->DR * coef) * coef_n) - tara;
  }else{
    data_ADC = ((ADC1->DR * coef) * coef_a) - tara;
  }
}

void USART2_IRQHandler(void){

}

void TIM2_IRQHandler (void){
  TIM2->SR &= ~TIM_SR_UIF;  // Clear interrupt flag Timer4.
  USART1_Send(data [0]);
  USART1_Send(data [1]);
  USART1_Send(data [2]);
  USART1_Send(data [3]);
  USART1_Send(data [4]);
  USART1_Send(data [5]);
  USART1_Send(data [6]);
  USART1_Send(data [7]);
}

void TIM3_IRQHandler (void){
  TIM3->SR &= ~TIM_SR_UIF;  // Clear interrupt flag Timer4.
  BUZZ_OFF;
}

void TIM4_IRQHandler (void){
  TIM4->SR &= ~TIM_SR_UIF;            // Clear interrupt flag Timer4.
  ADC1->CR2 |= ADC_CR2_SWSTART;       // ADC1 Start conversion.
  INDICATION();
}

void EXTI2_IRQHandler (void){
  EXTI->PR |= EXTI_PR_PR2;
  BUZZ_ON;
  TIM3->CR1 |= TIM_CR1_CEN;      // Timer 3 enable.
}

void EXTI3_IRQHandler (void){
  EXTI->PR |= EXTI_PR_PR3;
  BUZZ_ON;
  TIM3->CR1 |= TIM_CR1_CEN;      // Timer 3 enable.
  tara = (ADC1->DR * coef) * coef_n;
}

void EXTI4_IRQHandler (void){
  EXTI->PR |= EXTI_PR_PR4;
  BUZZ_ON;
  TIM3->CR1 |= TIM_CR1_CEN;      // Timer 3 enable.
}
