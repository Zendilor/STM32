#include "stm32f10x.h"

void GPIOA_Config (void);
void GPIOB_Config (void);

void GPIO_Config (void){
	GPIOA_Config();
	GPIOB_Config();
}

void GPIOA_Config (void){
	GPIOA->CRL &= ~GPIO_CRL_CNF7;		// Clear CNF7.
	GPIOA->CRL &= ~GPIO_CRL_CNF6;		// Clear CNF6.
	GPIOA->CRL &= ~GPIO_CRL_CNF5;		// Clear CNF5.
	GPIOA->CRL &= ~GPIO_CRL_CNF4;		// Clear CNF4.
	
	GPIOA->CRL |= GPIO_CRL_CNF7_1;	// Set push pull output alternative function (SPI1_MOSI).
	GPIOA->CRL |= GPIO_CRL_CNF6_1;	// Set push pull input alternative function (SPI1_MISO).
	GPIOA->CRL |= GPIO_CRL_CNF5_1;	// Set push pull output alternative function (SPI1_SCK).
	
	GPIOA->CRL |= GPIO_CRL_MODE7;		// Set 50 MHz speed for (SPI1_MISO).
	GPIOA->CRL |= GPIO_CRL_MODE5;		// Set 50 MHz speed for (SPI1_SCK).
	GPIOA->CRL |= GPIO_CRL_MODE4;		// Set 50 MHz speed for (SPI1_NSS).
	
	GPIOA->BSRR |= GPIO_BSRR_BS4;		// Set pull-up for SPI1_NSS.
	
	
	GPIOA->CRH &= ~GPIO_CRH_CNF9;		// Clear CNF9 bit.
	GPIOA->CRH &= ~GPIO_CRH_CNF10;	// Clear CNF10 bit.
	
	GPIOA->CRH |= GPIO_CRH_CNF9_1;	// Set push pull output alternaive function (USART1_TX).
	GPIOA->CRH |= GPIO_CRH_CNF10_1;	// Set puch pull input alternative function (USART1_RX).
	
	GPIOA->CRH |= GPIO_CRH_MODE9;		// Set speed for (USART1_TX) 50 MHz.
	
	GPIOA->BSRR |= GPIO_BSRR_BS9;		// Set pull-up for USART1_TX.
	GPIOA->BSRR |= GPIO_BSRR_BS10;	// Set pull-up for USART1_RX.
}

void GPIOB_Config (void){
	GPIOB->CRH &= ~GPIO_CRH_CNF15;	// Clear CNF15.
	GPIOB->CRH &= ~GPIO_CRH_CNF14;	// Clear CNF14.
	GPIOB->CRH &= ~GPIO_CRH_CNF13;	// Clear CNF13.
	GPIOB->CRH &= ~GPIO_CRH_CNF12;	// Clear CNF12.
	GPIOB->CRH &= ~GPIO_CRH_CNF11;	// Clear CNF11.
	GPIOB->CRH &= ~GPIO_CRH_CNF10;	// Clear CNF10.
	GPIOB->CRL &= ~GPIO_CRL_CNF1;		// Clear CNF1.
	GPIOB->CRL &= ~GPIO_CRL_CNF0;		// Clear CNF0.
	
	GPIOB->CRH |= GPIO_CRH_CNF15_1;	// Set push pull output alternative function (SPI2_MOSI).
	GPIOB->CRH |= GPIO_CRH_CNF14_1;	// Set push pull output alternative function (SPI2_MISO).
	GPIOB->CRH |= GPIO_CRH_CNF13_1;	// Set push pull output alternative function (SPI2_SCK).
	
	GPIOB->CRH |= GPIO_CRH_CNF11_1;	// Set push pull input (NRF2_IRQ).
	GPIOB->CRL |= GPIO_CRL_CNF1_1;	// Set push pull input (NRF1_IRQ).
	
	GPIOB->CRH |= GPIO_CRH_MODE15;	// Set 50 MHz speed for (SPI2_MISO).
	GPIOB->CRH |= GPIO_CRH_MODE13;	// Set 50 MHz speed for (SPI2_SCK).
	GPIOB->CRH |= GPIO_CRH_MODE12;	// Set 50 MHz speed for (SPI2_NSS).
	
	GPIOB->CRH |= GPIO_CRH_MODE10;	// Set 50 MHz speed for (NRF2_CE).
	GPIOB->CRL |= GPIO_CRL_MODE0;		// Set 50 MHz speed for (NRF1_CE).
	
	GPIOB->BSRR |= GPIO_BSRR_BS12;		// Set pull-up for SPI2_NSS.
}
