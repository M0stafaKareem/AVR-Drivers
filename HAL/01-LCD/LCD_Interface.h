#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H


void LCD_vidSendChar(u8 Copy_u8Char);

void LCD_vidSendCommand(u8 Copy_u8Command);

void LCD_vidInit();

void LCD_vidSendString(u8* pu8Array_of_char);

void LCD_vidSendNumber(u32 Copy_u8Number);

void LCD_GoToXY(u8 Copy_u8Xpos,u8 Copy_u8Ypos);
#endif
