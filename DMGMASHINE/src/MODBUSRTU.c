#include "stm32f10x.h"
#include "USART.h"

uint16_t MODBUS_CRC (char *data, char count); // Modbus crc calculation function.


char packedge_counter= 0;
char time_err = 0;

void MASTER_SEND (char address, char command, uint16_t reg, uint16_t read_count){ // Modbus master send
  char data_buff[]= {address, command,reg >> 8, reg, read_count >> 8, read_count};
  char count = sizeof data_buff;
  uint16_t crc_modbus = MODBUS_CRC (data_buff, count);
  char buff_transf = 0;

  while(count--){
    USART1_Send(data_buff[buff_transf++]);
  }

  USART1_Send(crc_modbus);
  USART1_Send(crc_modbus >> 8);
}

void SLAVE_RECEIVING (char buff[]){
  if(time_err == 0){
    switch (packedge_counter){
      case 0:
      TIM2->CR1 &= ~TIM_CR1_CEN;      // Timer 2 disable.
      TIM2->CNT = 0;
      buff [0] = USART1->DR;
      packedge_counter = 1;
      break;

      case 1:
      TIM2->CR1 &= ~TIM_CR1_CEN;      // Timer 2 disable.
      TIM2->CNT = 0;
      buff [1] = USART1->DR;
      packedge_counter = 2;
      break;

      case 2:
      TIM2->CR1 &= ~TIM_CR1_CEN;      // Timer 2 disable.
      TIM2->CNT = 0;
      buff [2] = USART1->DR;
      packedge_counter = 3;
      break;

      case 3:
      TIM2->CR1 &= ~TIM_CR1_CEN;      // Timer 2 disable.
      TIM2->CNT = 0;
      buff [3] = USART1->DR;
      packedge_counter = 4;
      break;

      case 4:
      TIM2->CR1 &= ~TIM_CR1_CEN;      // Timer 2 disable.
      TIM2->CNT = 0;
      buff [4] = USART1->DR;
      packedge_counter = 5;
      break;

      case 5:
      TIM2->CR1 &= ~TIM_CR1_CEN;      // Timer 2 disable.
      TIM2->CNT = 0;
      buff [5] = USART1->DR;
      packedge_counter = 6;
      break;

      case 6:
      TIM2->CR1 &= ~TIM_CR1_CEN;      // Timer 2 disable.
      TIM2->CNT = 0;
      buff [6] = USART1->DR;
      packedge_counter = 7;
      break;

      case 7:
      TIM2->CR1 &= ~TIM_CR1_CEN;      // Timer 2 disable.
      TIM2->CNT = 0;
      buff [7] = USART1->DR;
      packedge_counter = 0;
      break;
    }
    TIM2->CR1 |= TIM_CR1_CEN;      // Timer 2 enable.
  }
}


uint16_t MODBUS_CRC (char *data, char count){ // Modbus CRC calculation.
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
