#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/01-DIO/Dio_Interface.h"
#include "KPD_config.h"
#include "KPD_Interface.h"


u8 KPD_u8GetPressedKey(){
	u8 Local_u8PressedKey = KEY_NOT_PRESSED;
	u8 state=5;
	u8 User_Array[4][4]= USER_NUMBERS;

	u8 KPD_u8columnArray[4]={KPD_C0_PIN,KPD_C1_PIN,KPD_C2_PIN,KPD_C3_PIN};
	u8 KPD_u8rowArray[4]={KPD_R0_PIN,KPD_R1_PIN,KPD_R2_PIN,KPD_R3_PIN};

for(u8 col=0;col<4;col++)
{
		DIO_u8SetPinValue(KPD_PORT, KPD_u8columnArray[col], pinLow);
	for(u8 row=0;row<4;row++)
	{
		DIO_u8GetPinValue(KPD_PORT, KPD_u8rowArray[row], &state);
		if(state==0)
		{
			Local_u8PressedKey = User_Array[row][col];
			while(!state)
			{
				DIO_u8GetPinValue(KPD_PORT, KPD_u8rowArray[row], &state);
			}
			DIO_u8SetPinValue(KPD_PORT, KPD_u8columnArray[col], pinHigh);
			return Local_u8PressedKey;
		}
	}
	DIO_u8SetPinValue(KPD_PORT, KPD_u8columnArray[col], pinHigh);
}
	return Local_u8PressedKey;
}
