#include "stm32f10x.h"

void GPIOA_Config (void);

void GPIO_Config(void) {
  GPIOA_Config();
}

void GPIOA_Config (void){
  GPIOA->CRH &= ~GPIO_CRH_CNF9;   // Clear PA9;
  GPIOA->CRH &= ~GPIO_CRH_CNF10;  // Clear PA10;

  GPIOA->CRH |= GPIO_CRH_CNF9_1;  // Alternative function push pull.
  GPIOA->CRH |= GPIO_CRH_CNF10_0; // Floating input.

  GPIOA->CRH |= GPIO_CRH_MODE9_1; // Set speed for PA9 2 MHz.
}
