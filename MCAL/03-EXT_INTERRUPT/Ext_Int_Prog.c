#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "Ext_Int_Config.h"
#include "Ext_Int_Register.h"
#include "Ext_Int_Interface.h"

void ExtInterrupt_State(enu_ExtInterrupt Copy_enuExtInt,
		enu_interruptState Copy_enuInterruptState) {
	if (Copy_enuExtInt == enu_extInterrupt0) {
		GICR &= 0b10111111;
		GICR |= (Copy_enuInterruptState << GICR_INT0);
		SET_BIT(DDRD, 2); /*configuring pin as pull up status*/
		SET_BIT(PORTD, 2);
	}
	if (Copy_enuExtInt == enu_extInterrupt1) {
		GICR &= 0b01111111;
		GICR |= (Copy_enuInterruptState << GICR_INT1);
		SET_BIT(DDRD, 3); /*configuring pin as pull up status*/
		SET_BIT(PORTD, 3);
	}
	if (Copy_enuExtInt == enu_extInterrupt2) {
		GICR &= 0b11011111;
		GICR |= (Copy_enuInterruptState << GICR_INT2);
		SET_BIT(DDRB, 2); /*configuring pin as pull up status*/
		SET_BIT(PORTB, 2);
	}
}

void ExtInterrupt_ClearFlag(enu_ExtInterrupt Copy_enuExtInt) {
	if (Copy_enuExtInt == enu_extInterrupt0) {
		GIFR &= 0b10111111;
		GIFR |= (1 << GIFR_INT0);
	}
	if (Copy_enuExtInt == enu_extInterrupt1) {
		GIFR &= 0b01111111;
		GIFR |= (1 << GIFR_INT1);
	}
	if (Copy_enuExtInt == enu_extInterrupt2) {
		GIFR &= 0b11011111;
		GIFR |= (1 << GIFR_INT2);
	}
}

void ExtInterrupt_Sence(enu_ExtInterrupt Copy_enuExtInt,
		enu_SenseControl Copy_enuSenseControl) {
	if (Copy_enuExtInt == enu_extInterrupt0) {
		MCUCR &= 0b11111100;
		MCUCR |= Copy_enuSenseControl;
	} else if (Copy_enuExtInt == enu_extInterrupt1) {
		MCUCR &= 0b11110011;
		MCUCR |= (Copy_enuSenseControl << MCUCR_ISC10);
	} else if (Copy_enuExtInt == enu_extInterrupt2) {
		ExtInterrupt_State(enu_extInterrupt2, enu_interruptDisabled);
		MCUCSR |= ((Copy_enuSenseControl % 2) << MCUCSR_ISC2);
		ExtInterrupt_ClearFlag(enu_extInterrupt2);
	}
}
