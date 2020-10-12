#include "RCC.h"
#include "GPIO.h"
#include "USART.h"

int main (void){
  RCC_Config();
  GPIO_Config();
  USART_Config();

  USART1_Send(0x31);
  
  while (1) {

  }
}
