#include "stm32f10x.h"
#include "INTERRUPT.h"
#include "NRF24L01.h"
#include "GPIO.h"
#include "RCC.h"
#include "SPI.h"
#include "TIMER.h"

int main (void){
	RCC_Config();
	GPIO_Config();
	SPI_Config();
	INTERRUPT_Config();
	TIMER_Config();

	while(1){

	}
}
