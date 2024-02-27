#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

typedef enum {
	ParityOFF, EvenParity = 2, OddParity
} enu_ParityMode;

typedef enum {
	_5CharBits, _6CharBits, _7CharBits, _8CharBits, _9CharBits = 7
} enu_CharSize;

typedef enum {
	_1StopBit, _2StopBit
} enu_StopBits;

typedef enum {
	Asynchro, Synchro
} enu_CommunicationMode;

void USART_SendData(u16 Copy_u8Data);

u16 USART_ReceiveData();

void USART_Init(enu_CharSize Copy_enuCharSize, enu_ParityMode Copy_enuParity,
		enu_StopBits Copy_enuStopBits, enu_CommunicationMode Copy_enuCommMode);

#endif
