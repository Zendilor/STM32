#include "stm32f10x.h"
#include "INTERRUPT.h"
#include "USART.h"

char data [3];
char seg = 0;

extern float data_ADC;


void number (char number);

void INDICATION (void){
  data [0] = data_ADC;
  data [1] = data_ADC * 10;
  data [1] = data [1] % 10;
  data [2] = data_ADC * 100;
  data [2] = data [2] % 10;

  GPIOB->BRR = GPIO_BRR_BR0;
  GPIOB->BRR = GPIO_BRR_BR1;
  GPIOB->BRR = GPIO_BRR_BR3;
  GPIOB->BRR = GPIO_BRR_BR4;
  GPIOB->BRR = GPIO_BRR_BR5;
  GPIOB->BRR = GPIO_BRR_BR6;
  GPIOB->BRR = GPIO_BRR_BR7;
  GPIOB->BRR = GPIO_BRR_BR8;

  GPIOB->BSRR = GPIO_BSRR_BS9;
  GPIOB->BSRR = GPIO_BSRR_BS10;
  GPIOB->BSRR = GPIO_BSRR_BS11;

  switch (seg) {
    case 0:
    GPIOB->BSRR = GPIO_BSRR_BR9;
    number(data[0]);
    if(GPIOA->IDR & GPIO_IDR_IDR1){
      GPIOB->BSRR = GPIO_BSRR_BS8;
    }
    seg = 1;
    break;

    case 1:
    GPIOB->BSRR = GPIO_BSRR_BR10;
    number(data[1]);
    if(!(GPIOA->IDR & GPIO_IDR_IDR1)){
      GPIOB->BSRR = GPIO_BSRR_BS8;
    }
    seg = 2;
    break;

    case 2:
    GPIOB->BSRR = GPIO_BSRR_BR11;
    number(data[2]);
    seg = 0;
    break;
  }
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
    GPIOB->BSRR = GPIO_BSRR_BS1
    | GPIO_BSRR_BS3;
    break;

    case 2:
    GPIOB->BSRR = GPIO_BSRR_BS0
    | GPIO_BSRR_BS1
    | GPIO_BSRR_BS4
    | GPIO_BSRR_BS5
    | GPIO_BSRR_BS7;
    break;

    case 3:
    GPIOB->BSRR = GPIO_BSRR_BS0
    | GPIO_BSRR_BS1
    | GPIO_BSRR_BS3
    | GPIO_BSRR_BS4
    | GPIO_BSRR_BS7;
    break;

    case 4:
    GPIOB->BSRR = GPIO_BSRR_BS1
    | GPIO_BSRR_BS3
    | GPIO_BSRR_BS6
    | GPIO_BSRR_BS7;
    break;

    case 5:
    GPIOB->BSRR = GPIO_BSRR_BS0
    | GPIO_BSRR_BS3
    | GPIO_BSRR_BS4
    | GPIO_BSRR_BS6
    | GPIO_BSRR_BS7;
    break;

    case 6:
    GPIOB->BSRR = GPIO_BSRR_BS0
    | GPIO_BSRR_BS3
    | GPIO_BSRR_BS4
    | GPIO_BSRR_BS5
    | GPIO_BSRR_BS6
    | GPIO_BSRR_BS7;
    break;

    case 7:
    GPIOB->BSRR = GPIO_BSRR_BS0
    | GPIO_BSRR_BS1
    | GPIO_BSRR_BS3;
    break;

    case 8:
    GPIOB->BSRR = GPIO_BSRR_BS0
    | GPIO_BSRR_BS1
    | GPIO_BSRR_BS3
    | GPIO_BSRR_BS4
    | GPIO_BSRR_BS5
    | GPIO_BSRR_BS6
    | GPIO_BSRR_BS7;
    break;

    case 9:
    GPIOB->BSRR = GPIO_BSRR_BS0
    | GPIO_BSRR_BS1
    | GPIO_BSRR_BS3
    | GPIO_BSRR_BS4
    | GPIO_BSRR_BS6
    | GPIO_BSRR_BS7;
    break;
  }
}
