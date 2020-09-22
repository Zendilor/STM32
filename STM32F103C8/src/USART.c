#include "stm32f10x.h"
#include "USART.h"

void USART1_Config (void);

void USART_Config (void){
  USART1_Config();
}

void USART1_Config (void){
  USART1->BRR = SPEED;
  USART1->CR1 |= USART_CR1_TE;    // Enable USART1 transmitter.
  USART1->CR1 |= USART_CR1_RE;    // Enable USART1 receiver.
  USART1->CR1 |= USART_CR1_UE;    // Enable USART1.
}
void USART1_Send (char data){
  while(!(USART1->SR & USART_SR_TC));
  USART1->DR = data;
}
void USART1_Send_Buff (char *Buff, char count){
  while(count--){
    USART1_Send(*(Buff++));
  }
}
