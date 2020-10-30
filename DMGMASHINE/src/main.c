#include "stm32f10x.h"
#include "ADC.h"
#include "RCC.h"
#include "GPIO.h"
#include "INDICATION.h"
#include "INTERRUPT.h"
#include "USART.h"
#include "TIMER.h"
#include "MODBUSRTU.h"

uint16_t MODBUS_CRC (char *data, char count);

int crc = 0;

int main (void){

  RCC_Config();
  GPIO_Config();
  INTERRUPT_Config();
  USART_Config();
  //ADC_Config();
  TIMER_Config();


  /*USART1_Send(MODBUS_CRC(data, sizeof data) >> 8);
  crc = MODBUS_CRC(data, sizeof data);
  USART1_Send(crc);*/
  while (1) {

  }
}

uint16_t MODBUS_CRC (char *data, char count){
	register int j;
	register unsigned int reg_crc = 0xFFFF;
	while (count--){
	  reg_crc ^= *data++;
	  for(j=0;j<8;j++){
		 if(reg_crc & 0x01){
		    reg_crc = (reg_crc >> 1) ^ 0xA001;
      }
		else{
		    reg_crc = reg_crc >> 1;
      }
    }
	}
	return reg_crc;
}
