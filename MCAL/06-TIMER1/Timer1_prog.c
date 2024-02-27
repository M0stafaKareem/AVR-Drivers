#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../01-DIO/Dio_Interface.h"
#include "Timer1_Regster.h"
#include "Timer1_Interface.h"

void TMR1_WaveformGen_Mode(enu_WGM1 Copy_enuWaveformGenMode){
	TCCR1A &= 0b11111100;
	TCCR1B &= 0b11100111;
	TCCR1A |=  (Copy_enuWaveformGenMode%4);
	TCCR1B |=( (Copy_enuWaveformGenMode/4) <<3 );
}
void TMR1_ClockSelect(enu_ClockSource1 Copy_enuClockSource){
	TCCR1B &= 0b11111000;
	TCCR1B |= Copy_enuClockSource ;
}
void TMR1_PreloadingVal(u16 Copy_u8PreloadingValue){
	TCNT1L = Copy_u8PreloadingValue;
}
void TMR1_InterruptState(enu_InterruptState1 Copy_enuInterruptState){
	TIMSK &= 0b11000011;
	TIMSK |= Copy_enuInterruptState ;
}
void TMR1_CompareOutpuMode(enu_CompareMode1 Copy_enuCompareOutputMode){
	TCCR1A &= 0b00001111;
	TCCR1A |= Copy_enuCompareOutputMode ;
}

void TMR1_SetICR1Avalue(u16 Copy_u16ICRvalue) {
	ICR1L = Copy_u16ICRvalue;
}
void TMR1_SetOCR1Avalue(u16 Copy_u16OCRAvalue){
	OCR1AL = Copy_u16OCRAvalue;
}
void TMR1_SetOCR1Bvalue(u16 Copy_u16OCRBvalue){
	OCR1BL = Copy_u16OCRBvalue;
}
void TMR1_vidInit(enu_WGM1 Copy_enuWGM,enu_ClockSource1 Copy_enuClockSource,enu_InterruptState1 Copy_enuInterrupt,enu_CompareMode1 Copy_enuCompareMode){
	TMR1_WaveformGen_Mode(Copy_enuWGM);
	TMR1_CompareOutpuMode(Copy_enuCompareMode);
	TMR1_ClockSelect(Copy_enuClockSource);
	TMR1_InterruptState(Copy_enuInterrupt);
}
