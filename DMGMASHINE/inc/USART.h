#define F_CPU 8000000
#define BAUD  9600
#define SPEED (F_CPU/BAUD)

void USART_Config (void);
void USART1_Send (char data);
void USART1_Send_Buff (char *Buff, char count);
