#ifndef USART_CONFIG_H
#define USART_CONFIG_H

#define USART_PORT portD
#define USART_RX_PIN 0
#define USART_TX_PIN 1

#define SYSTEM_FREQUENCY 8000000L
#define BAUD 9600L

#define UBRR() ((SYSTEM_FREQUENCY/(16*BAUD))-1)

#endif
