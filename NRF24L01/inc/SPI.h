#define NSS_HIGH	GPIOA->BSRR = GPIO_BSRR_BS4
#define NSS_LOW		GPIOA->BSRR = GPIO_BSRR_BR4



void SPI_Config (void);
char SPI_Send (char data);
