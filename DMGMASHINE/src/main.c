#include "stm32f10x.h"
#include "ADC.h"
#include "RCC.h"
#include "GPIO.h"
#include "INDICATION.h"
#include "INTERRUPT.h"
#include "USART.h"
#include "TIMER.h"
#include "MODBUSRTU.h"


int main (void){

  RCC_Config();
  GPIO_Config();
  INTERRUPT_Config();
  USART_Config();
  //ADC_Config();
  TIMER_Config();

  while (1) {

  }
}
