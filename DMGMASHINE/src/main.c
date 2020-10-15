#include "stm32f10x.h"
#include "RCC.h"
#include "GPIO.h"
#include "INDICATION.h"
#include "USART.h"

int main (void){
  RCC_Config();
  //GPIO_Config();
  //USART_Config();
  GPIOB->CRL &= ~GPIO_CRL_CNF3;

  GPIOB->CRL |= GPIO_CRL_MODE3;

  GPIOB->ODR |= GPIO_ODR_ODR3;
  //INDICATION();
  while (1) {

  }
}
