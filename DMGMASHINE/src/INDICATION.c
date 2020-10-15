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
    | GPIO_BSRR_BS3
    | GPIO_BSRR_BS4
    | GPIO_BSRR_BS5
    | GPIO_BSRR_BS6;
    break;
    case 1:

    break;
  }
}
