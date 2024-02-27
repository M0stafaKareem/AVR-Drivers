#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

/*Port Enum*/
typedef enum {
	enu_portA, enu_portB, enu_portC, enu_portD

} enu_port;

/*Pin Enum*/
typedef enum {
	pin0__, pin1__, pin2__, pin3__, pin4__, pin5__, pin6__, pin7__
} enu_pin;

/*direction Enum*/
typedef enum {
	enu_input, enu_output, enu_portInput = 0x00, enu_portOutput = 0xff
} enu_direction;

/*values Enum*/
typedef enum {
	enu_pinLow, enu_pinHigh, enu_portLow = 0x00, enu_portHigh = 0xff
} enu_value;

/*Set pin's direction at any port */
u8 DIO_u8SetPinDirection(enu_port Copy_enuPort, enu_pin Copy_enuPin,
		enu_direction Copy_enuDirection);
/*Set pin's value at any port*/
u8 DIO_u8SetPinValue(enu_port Copy_enuPort, enu_pin Copy_enuPin,
		enu_value Copy_enuValue);
/*read pin's value at any port*/
u8 DIO_u8GetPinValue(enu_port Copy_enuPort, enu_pin Copy_enuPin, u8* pu8Value);

/*Set Port's Direction*/
u8 DIO_u8SetPortDirection(enu_port Copy_enuPort, u8 Copy_u8Port_Direction);
/*Set port's value*/
u8 DIO_u8SetPortValue(enu_port Copy_enuPort, u8 Copy_u8Port_Value);
/*Get port's Value*/
u8 DIO_u8GetPortValue(enu_port Copy_enuPort, u8* pu8Value);

#endif
