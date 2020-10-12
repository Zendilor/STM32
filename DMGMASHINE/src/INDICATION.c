#include "stm32f10x.h"

void number (char number);

void INDICATION (void){
  number(0);
}

void number (char number){
  switch (number) {
    case 0:
    GPIOB->BSRR = GPIO_BSRR_BS0
    | GPIO_BSRR_BS1
    | GPIO_BSRR_BR3
    | GPIO_BSRR_BR4
    | GPIO_BSRR_BR5
    | GPIO_BSRR_BR6
    | GPIO_BSRR_BR7;
    break;
    case 1:

    break;
  }
}
