#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../01-DIO/Dio_Interface.h"
#include "../01-DIO/Dio_Register.h"

/*Set pin's direction at any port */
u8 DIO_u8SetPinDirection(enu_port Copy_enuPort, enu_pin Copy_enuPin,
		enu_direction Copy_enudirection) {
	/*case input*/
	if (Copy_enudirection == enu_output) {
		switch (Copy_enuPort) {
		case enu_portA:
			SET_BIT(DDRA, Copy_enuPin);
			break;
		case enu_portB:
			SET_BIT(DDRB, Copy_enuPin);
			break;
		case enu_portC:
			SET_BIT(DDRC, Copy_enuPin);
			break;
		case enu_portD:
			SET_BIT(DDRD, Copy_enuPin);
			break;
		}
	} else
	/*case output*/
	if (Copy_enudirection == enu_input) {
		switch (Copy_enuPort) {
		case enu_portA:
			CLR_BIT(DDRA, Copy_enuPin);
			break;
		case enu_portB:
			CLR_BIT(DDRB, Copy_enuPin);
			break;
		case enu_portC:
			CLR_BIT(DDRC, Copy_enuPin);
			break;
		case enu_portD:
			CLR_BIT(DDRD, Copy_enuPin);
			break;
		}
	}
}

/*Set pin's value at any port*/
u8 DIO_u8SetPinValue(enu_port Copy_enuPort, enu_pin Copy_enuPin,
		enu_value Copy_enuValue) {
	/*case high*/
	if (Copy_enuValue == enu_pinHigh) {
		switch (Copy_enuPort) {
		case enu_portA:
			SET_BIT(PORTA, Copy_enuPin);
			break;
		case enu_portB:
			SET_BIT(PORTB, Copy_enuPin);
			break;
		case enu_portC:
			SET_BIT(PORTC, Copy_enuPin);
			break;
		case enu_portD:
			SET_BIT(PORTD, Copy_enuPin);
			break;
		}
	} else
	/*case low*/
	if (Copy_enuValue == enu_pinLow) {
		switch (Copy_enuPort) {
		case enu_portA:
			CLR_BIT(PORTA, Copy_enuPin);
			break;
		case enu_portB:
			CLR_BIT(PORTB, Copy_enuPin);
			break;
		case enu_portC:
			CLR_BIT(PORTC, Copy_enuPin);
			break;
		case enu_portD:
			CLR_BIT(PORTD, Copy_enuPin);
			break;
		}
	}
}

/*read pin's value at any port*/
u8 DIO_u8GetPinValue(enu_port Copy_enuPort, enu_pin Copy_enuPin, u8* pu8Value) {
	switch (Copy_enuPort) {
	case enu_portA:
		*pu8Value = GET_BIT(PINA, Copy_enuPin);
		break;
	case enu_portB:
		*pu8Value = GET_BIT(PINB, Copy_enuPin);
		break;
	case enu_portC:
		*pu8Value = GET_BIT(PINC, Copy_enuPin);
		break;
	case enu_portD:
		*pu8Value = GET_BIT(PIND, Copy_enuPin);
		break;
	}
}

/*Set port's direction*/
u8 DIO_u8SetPortDirection(enu_port Copy_enuPort, u8 Copy_u8Port_Direction) {

	switch (Copy_enuPort) {
	case enu_portA:
		DDRA = Copy_u8Port_Direction;
		break;
	case enu_portB:
		DDRB = Copy_u8Port_Direction;
		break;
	case enu_portC:
		DDRC = Copy_u8Port_Direction;
		break;
	case enu_portD:
		DDRD = Copy_u8Port_Direction;
		break;
	}
}

/*Set port's value*/
u8 DIO_u8SetPortValue(enu_port Copy_enuPort, u8 Copy_u8Port_Value) {

	switch (Copy_enuPort) {
	case enu_portA:
		PORTA = Copy_u8Port_Value;
		break;
	case enu_portB:
		PORTB = Copy_u8Port_Value;
		break;
	case enu_portC:
		PORTC = Copy_u8Port_Value;
		break;
	case enu_portD:
		PORTD = Copy_u8Port_Value;
		break;
	}
}

u8 DIO_u8GetPortValue(enu_port Copy_enuPort, u8* pu8Value) {
	switch (Copy_enuPort) {
	case enu_portA:
		*pu8Value = PINA;
		break;
	case enu_portB:
		*pu8Value = PINB;
		break;
	case enu_portC:
		*pu8Value = PINC;
		break;
	case enu_portD:
		*pu8Value = PIND;
		break;
	}
}

