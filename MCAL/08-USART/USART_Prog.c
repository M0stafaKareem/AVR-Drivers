#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../01-DIO/Dio_Interface.h"
#include "USART_Register.h"
#include "USART_Interface.h"
#include "USART_Config.h"

void USART_Init(enu_CharSize Copy_enuCharSize, enu_ParityMode Copy_enuParity,
		enu_StopBits Copy_enuStopBits, enu_CommunicationMode Copy_enuCommMode) {

	DIO_u8SetPinDirection(USART_PORT, USART_TX_PIN, output);
	DIO_u8SetPinDirection(USART_PORT, USART_RX_PIN, input);
	UBRRH = (0 << UBRRH_URSEL) | ((u8)( UBRR() >> 8) & 0x0f);
	UBRRL = ( UBRR() & 0xff);

	UCSRC = (1 << UCSRC_URSEL) | (Copy_enuCommMode << UCSRC_UMSEL)
			| (Copy_enuParity << UCSRC_UPM0)
			| (Copy_enuCharSize & 0x03) << UCSRC_UCSZ0
			| (Copy_enuStopBits << UCSRC_USBS);

	UCSRB = (1 << UCSRB_TXEN) | (1 << UCSRB_RXEN)
			| ((Copy_enuCharSize / 4) << UCSRB_UCSZ2);
}
void USART_SendData(u16 Copy_u9Data) {
	while (GET_BIT(UCSRA, UCSRA_UDRE) == 0)
		;
	UCSRB &= ~(1 << UCSRB_TXB8);
	UCSRB |= (Copy_u9Data % 0x100) << UCSRB_TXB8;
	UDR = (Copy_u9Data & 0xff);
}
u16 USART_ReceiveData() {
	while ( GET_BIT(UCSRA,UCSRA_RXC) == 0)
		;
	return (((UCSRB & (1 << UCSRB_RXB8)) << 8) | UDR);
}
