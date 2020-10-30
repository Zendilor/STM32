#include "stm32f10x.h"


void AFIO_Config (void);
void GPIOA_Config (void);
void GPIOB_Config (void);

void GPIO_Config(void){
  AFIO_Config();
  GPIOA_Config();
  GPIOB_Config();
}

void AFIO_Config (void){
  AFIO->MAPR |= AFIO_MAPR_SWJ_CFG_JTAGDISABLE;  // Disable JTAG.
}

void GPIOA_Config (void){
  GPIOA->CRL &= ~GPIO_CRL_CNF0;   // Clear PA0.
  GPIOA->CRL &= ~GPIO_CRL_CNF1;   // Clear PA1.
  GPIOA->CRL &= ~GPIO_CRL_CNF2;   // Clear PA2.
  GPIOA->CRL &= ~GPIO_CRL_CNF3;   // Clear PA3.
  GPIOA->CRL &= ~GPIO_CRL_CNF4;   // Clear PA4.
  GPIOA->CRL &= ~GPIO_CRL_CNF5;   // Clear PA5.
  GPIOA->CRL &= ~GPIO_CRL_CNF6;   // Clear PA6.

  GPIOA->CRL |= GPIO_CRL_CNF1_0;  // Set PA1 float mode.

  GPIOA->CRL |= GPIO_CRL_CNF2_1;  // Input PA2 push pull.
  GPIOA->CRL |= GPIO_CRL_CNF3_1;  // Input PA3 push pull.
  GPIOA->CRL |= GPIO_CRL_CNF4_1;  // Input PA4 push pull.

  GPIOA->CRL |= GPIO_CRL_MODE5_1;   // Set speed for PA5 2 MHz;
  GPIOA->CRL |= GPIO_CRL_MODE6_1;   // Set speed for PA6 2 MHz;

  GPIOA->ODR &= ~GPIO_ODR_ODR2;   // PA2 pull down.
  GPIOA->ODR &= ~GPIO_ODR_ODR3;   // PA3 pull down.
  GPIOA->ODR &= ~GPIO_ODR_ODR4;   // PA4 pull down.

  GPIOA->ODR |= GPIO_ODR_ODR5;    // Set BIT PA5 to UP.
  GPIOA->ODR |= GPIO_ODR_ODR6;    // Set BIT PA6 to UP.

  GPIOA->CRH &= ~GPIO_CRH_CNF9;   // Clear PA9;
  GPIOA->CRH &= ~GPIO_CRH_CNF10;  // Clear PA10;

  GPIOA->CRH |= GPIO_CRH_CNF9_1;  // Alternative function push pull.
  GPIOA->CRH |= GPIO_CRH_CNF10_0; // Floating input.

  GPIOA->CRH |= GPIO_CRH_MODE9_1; // Set speed for PA9 2 MHz.
}

void GPIOB_Config (void){
  GPIOB->CRL &= ~GPIO_CRL_CNF0;   // Clear PB0.
  GPIOB->CRL &= ~GPIO_CRL_CNF1;   // Clear PB1.
  GPIOB->CRL &= ~GPIO_CRL_CNF3;   // Clear PB3.
  GPIOB->CRL &= ~GPIO_CRL_CNF4;   // Clear PB4.
  GPIOB->CRL &= ~GPIO_CRL_CNF5;   // Clear PB5.
  GPIOB->CRL &= ~GPIO_CRL_CNF6;   // Clear PB6.
  GPIOB->CRL &= ~GPIO_CRL_CNF7;   // Clear PB7.
  GPIOB->CRH &= ~GPIO_CRH_CNF8;   // Clear PB8.
  GPIOB->CRH &= ~GPIO_CRH_CNF9;   // Clear PB9.
  GPIOB->CRH &= ~GPIO_CRH_CNF10;  // Clear PB10.
  GPIOB->CRH &= ~GPIO_CRH_CNF11;  // Clear PB11.

  GPIOB->CRL |= GPIO_CRL_MODE0_1;   // Set speed for PB0 2 MHz.
  GPIOB->CRL |= GPIO_CRL_MODE1_1;   // Set speed for PB1 2 MHz.
  GPIOB->CRL |= GPIO_CRL_MODE3_1;   // Set speed for PB3 2 MHz.
  GPIOB->CRL |= GPIO_CRL_MODE4_1;   // Set speed for PB4 2 MHz.
  GPIOB->CRL |= GPIO_CRL_MODE5_1;   // Set speed for PB5 2 MHz.
  GPIOB->CRL |= GPIO_CRL_MODE6_1;   // Set speed for PB6 2 MHz.
  GPIOB->CRL |= GPIO_CRL_MODE7_1;   // Set speed for PB7 2 MHz.
  GPIOB->CRH |= GPIO_CRH_MODE8_1;   // Set speed for PB8 2 MHz.
  GPIOB->CRH |= GPIO_CRH_MODE9_1;   // Set speed for PB9 2 MHz.
  GPIOB->CRH |= GPIO_CRH_MODE10_1;  // Set speed for PB10 2 MHz.
  GPIOB->CRH |= GPIO_CRH_MODE11_1;  // Set speed for PB11 2 MHz.

  GPIOB->BSRR = GPIO_BSRR_BR0;      // PB0 clear.
  GPIOB->BSRR = GPIO_BSRR_BR1;      // PB1 clear.
  GPIOB->BSRR = GPIO_BSRR_BR3;      // PB3 clear.
  GPIOB->BSRR = GPIO_BSRR_BR4;      // PB4 clear.
  GPIOB->BSRR = GPIO_BSRR_BR5;      // PB5 clear.
  GPIOB->BSRR = GPIO_BSRR_BR6;      // PB6 clear.
  GPIOB->BSRR = GPIO_BSRR_BR7;      // PB7 clear.
  GPIOB->BSRR = GPIO_BSRR_BR8;      // PB8 clear.
  GPIOB->BSRR = GPIO_BSRR_BR9;      // PB0 clear.
  GPIOB->BSRR = GPIO_BSRR_BS10;     // PB0 clear.
  GPIOB->BSRR = GPIO_BSRR_BS11;     // PB0 clear.
}
