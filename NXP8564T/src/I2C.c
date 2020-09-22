#include "stm32f10x.h"


void I2C_Config (void){
	I2C1->CR1 &= ~I2C_CR1_SMBUS;	// Set the peripherals as I2C.
	I2C1->CR1 |= I2C_CR1_SMBTYPE;	// Set I2C as host.
	I2C1->CR2 |= 8;								// Set I2C in speed 8 MHz.
	I2C1->CCR &= ~I2C_CCR_FS;			// Set I2C speed 100 kHz.
	I2C1->CCR &= ~I2C_CCR_DUTY;		// Set Fm mode duty cycle (0).
	I2C1->TRISE &= ~I2C_TRISE_TRISE;
	I2C1->CCR |= 0x28;						// 100kHz, 1/F_CPU = 125us, 2 * 125 = 250, 10000 mks/ 250 = 40 = 0x28
	I2C1->TRISE |= 9;							// F_I2C+1 input frenquency.
	I2C1->CR1 |= I2C_CR1_PE;			// Enable I2C
}

char I2C1_Read (char ADDR_W, char REG, char ADDR_R){
	char data = 0;
	I2C1->CR1 |= I2C_CR1_START;
	while(!(I2C1->SR1 & I2C_SR1_SB));
	(void) I2C1->SR1;
	(void) I2C1->SR2;

	I2C1->DR = ADDR_W;
	while(!(I2C1->SR1 & I2C_SR1_ADDR));
	(void) I2C1->SR1;
	(void) I2C1->SR2;

	I2C1->DR = REG;
	while(!(I2C1->SR1 & I2C_SR1_TXE));

	I2C1->CR1 |= I2C_CR1_STOP;
	I2C1->CR1 |= I2C_CR1_START;
	while(!(I2C1->SR1 & I2C_SR1_SB));
	(void) I2C1->SR1;

	I2C1->DR = ADDR_R;
	while(!(I2C1->SR1 & I2C_SR1_ADDR));
	(void) I2C1->SR1;
	(void) I2C1->SR2;

	//I2C2->CR1 &= ~I2C_CR1_ACK;
	while(!(I2C1->SR1 & I2C_SR1_RXNE));
	data = I2C1->DR;
	USART1->DR = data;
	I2C1->CR1 |= I2C_CR1_STOP;
	return data;
}

void I2C1_Write (char ADDR_W, char REG, char DATA){
	I2C1->CR1 |= I2C_CR1_START;
	while(!(I2C1->SR1 & I2C_SR1_SB));
	(void) I2C1->SR1;
	(void) I2C1->SR2;

	I2C1->DR = ADDR_W;
	while(!(I2C1->SR1 & I2C_SR1_ADDR));
	(void) I2C1->SR1;
	(void) I2C1->SR2;

	I2C1->DR = REG;
	while(!(I2C1->SR1 & I2C_SR1_TXE));
	(void) I2C1->SR1;
	(void) I2C1->SR2;

	I2C1->DR = DATA;
	while(!(I2C1->SR1 & I2C_SR1_BTF));
	(void) I2C1->SR1;
	(void) I2C1->SR2;
	I2C1->CR1 |= I2C_CR1_STOP;

}
