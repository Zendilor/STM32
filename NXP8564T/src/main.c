#include "RCC.h"
#include "I2C.h"
#include "GPIO.h"
#include "USART.h"
#include "NXP8563T.h"


int main (void){
	RCC_Config();
	GPIO_Config();
	I2C_Config();
	USART_Config();
	NXP8563T_Config();
	
	while(1){
		
	}
}
