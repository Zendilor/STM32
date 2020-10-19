#include "stm32f10x.h"
#include "INDICATION.h"
#include "USART.h"


float coef = 0.000805664;
float coef_n = 3.03030303;
float coef_a = 0.305;
float data_ADC = 0;
float tara = 0;

void INTERRUPT_Config (void){
  NVIC->ISER [0] |= NVIC_ISER_SETENA_9;   // Enable interrupt for EXTI3.
  NVIC->ISER [0] |= NVIC_ISER_SETENA_18;  // Enable interrupt for ADC1.
  NVIC->ISER [0] |= NVIC_ISER_SETENA_30;  // Enable interrupt for TIMER4.

  AFIO->EXTICR [0] |= AFIO_EXTICR1_EXTI3_PA; // Set interrupt on PA3.
  EXTI->RTSR |= EXTI_RTSR_TR3;
  EXTI->IMR |= EXTI_IMR_MR3;
}

void ADC1_2_IRQHandler (void){
  if(GPIOA->IDR & GPIO_IDR_IDR2){
    tara = (ADC1->DR * coef) * coef_n;
  }

  if(GPIOA->IDR & GPIO_IDR_IDR1){
    data_ADC = ((ADC1->DR * coef) * coef_n) - tara;
  }else{
    data_ADC = ((ADC1->DR * coef) * coef_a) - tara;
  }
  INDICATION();
}

void TIM4_IRQHandler (void){
  TIM4->SR &= ~TIM_SR_UIF;  // Clear interrupt flag Timer4.
  //INDICATION();
  //USART1_Send(0x31);
}

void EXTI3_IRQHandler (void){
  EXTI->PR |= EXTI_PR_PR3;
  USART1_Send(0x31);
}
