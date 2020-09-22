#define F_CPU 8000000
#define USART_BOUD 9600
#define BOUD_RATE (F_CPU/USART_BOUD)


void USART_Config (void);
void USART1_Send (char data);
void USART1_Send_Buff(char *buff, char count);
