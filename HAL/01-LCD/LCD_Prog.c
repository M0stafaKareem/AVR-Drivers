#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "LCD_Interface.h"
#include "LCD_Config.h"
#include <avr/delay.h>
#include "../../MCAL/01-DIO/Dio_Interface.h"

void LCD_vidSendChar(u8 Copy_u8Char){
	/*Set RS = 1*/
	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, pinHigh);
	/*Set R/W as 0 to write*/
	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, pinLow);
	/*Send data*/
	DIO_u8SetPortValue(LCD_DATA_PORT, Copy_u8Char);
	/*Enable on */
	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, pinHigh);
	/*Delay 2ms*/
	_delay_ms(2);
	/*Enable off*/
	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, pinLow);
}

void LCD_vidSendCommand(u8 Copy_u8Command){
	/*Set RS = 0*/
	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, pinLow);
	/*Set R/W as 0 to write*/
	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, pinLow);
	/*Send command*/
	DIO_u8SetPortValue(LCD_DATA_PORT, Copy_u8Command);
	/*Enable on */
	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, pinHigh);
	/*Delay 2ms*/
	_delay_ms(2);
	/*Enable off*/
	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, pinLow);

}

void LCD_vidInit(){
	_delay_ms(30);
	/*Function set*/
	LCD_vidSendCommand(0b00111100);
	_delay_ms(1);
	/*Display ON/OFF*/
	LCD_vidSendCommand(0b00001100);
	_delay_ms(1);
	/*Display Clear*/
	LCD_vidSendCommand(0b00000001);

}

void LCD_vidSendString(u8* pu8Array_of_char){
	for(u8 i=0;i!='\0';i++)
		LCD_vidSendChar(pu8Array_of_char[i]);
}

void LCD_vidSendNumber(u32 Copy_u8Number){
	if(Copy_u8Number !=0){
		LCD_vidSendNumber( Copy_u8Number/10 );
		LCD_vidSendChar( ( (Copy_u8Number%10) + '0' ) );
	}
}

void LCD_GoToXY(u8 Copy_u8Xpos,u8 Copy_u8Ypos){
	u8 Location=0;
	if(Copy_u8Xpos == 0){
		Location = Copy_u8Ypos;
	}
	else if(Copy_u8Xpos == 1){
		Location = 0x40 + Copy_u8Ypos;
	}
	LCD_vidSendCommand( (128+Location) );
}
