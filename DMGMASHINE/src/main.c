#include "RCC.h"
#include "GPIO.h"
#include "INDICATION.h"
#include "USART.h"

int main (void){
  RCC_Config();
  GPIO_Config();
  USART_Config();
  
  INDICATION();
  while (1) {

  }
}
