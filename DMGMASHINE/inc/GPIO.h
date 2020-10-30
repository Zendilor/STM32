#define BUZZ_ON   GPIOA->BSRR = GPIO_BSRR_BR5;
#define BUZZ_OFF  GPIOA->BSRR = GPIO_BSRR_BS5;

void GPIO_Config(void);
