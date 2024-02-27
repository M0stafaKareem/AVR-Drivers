#ifndef EXT_INT_INTERFACE_H
#define EXT_INT_INTERFACE_H

typedef enum {
	enu_interruptDisabled, enu_interruptEnbled
} enu_interruptState;

typedef enum {
	enu_extInterrupt0, enu_extInterrupt1, enu_extInterrupt2
} enu_ExtInterrupt;

typedef enum {
	enu_lowLevel, enu_anyChange, enu_fallingEdge, enu_risingEdge
} enu_SenseControl;

void ExtInterrupt_State(enu_ExtInterrupt Copy_enuExtInt,
		enu_interruptState Copy_enuInterruptState);

void ExtInterrupt_Sence(enu_ExtInterrupt Copy_enuExtInt,
		enu_SenseControl Copy_enuSenseControl);

void ExtInterrupt_ClearFlag(enu_ExtInterrupt Copy_enuExtInt);
#endif

/* 			Interrupt Survice routne (ISR) Syntax
 *
 void __vector_3 (void) __attribute__((signal));

 void __vector_1 (void){

 code body
 }*/
