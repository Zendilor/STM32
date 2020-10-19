#include "stm32f10x.h"
#include "ADC.h"
#include "RCC.h"
#include "GPIO.h"
#include "INDICATION.h"
#include "INTERRUPT.h"
#include "USART.h"
#include "TIMER.h"

extern float tara;

int main (void){

  RCC_Config();
  GPIO_Config();
  INTERRUPT_Config();
  TIMER_Config();
  USART_Config();
  ADC_Config();

  while (1) {
    
  }
}
