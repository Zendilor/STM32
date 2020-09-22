#include "stm32f10x.h"
/* Init I2C1
	Use B6 (SCL)
	USE B7 (SDA)
*/

void GPIOA_Config (void);
void GPIOB_Config (void);

void GPIO_Config (void){
	GPIOA_Config();
	GPIOB_Config();
}

void GPIOA_Config (void){
	GPIOA->CRH &= ~GPIO_CRH_CNF9;		// Clear PA9.
	GPIOA->CRH &= ~GPIO_CRH_CNF10;	// Clear PA10.
	
	GPIOA->CRH |= GPIO_CRH_CNF9_1;	// Set PA9 push pull alternative function.
	GPIOA->CRH |= GPIO_CRH_CNF10_0;	// Set PA10 input push pull.
	
	GPIOA->CRH |= GPIO_CRH_MODE9_1;	// Set speed PA9 2MHz.
}

void GPIOB_Config (void){
	GPIOB->CRL &= ~GPIO_CRL_CNF6;	// Clear PB6.
	GPIOB->CRL &= ~GPIO_CRL_CNF7;	// Clear PB7.
	
	GPIOB->CRL |= GPIO_CRL_CNF6;	// Set PB6 push pull alternative function.
	GPIOB->CRL |= GPIO_CRL_CNF7;	// Set PB7 push pull alternative function.
	
	GPIOB->CRL |= GPIO_CRL_MODE6_1;	// Set speed PB6 2MHz.
	GPIOB->CRL |= GPIO_CRL_MODE7_1;	// Set speed PB7 2MHz.
}
