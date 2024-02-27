#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../01-DIO/Dio_Interface.h"
#include "Timer0_Interface.h"
#include "Timer0_Register.h"

void TMR0_WaveformGen_Mode(enu_WGM0 Copy_enuWaveformGenMode){
	TCCR0 &= 0b10110111;
	TCCR0 |= Copy_enuWaveformGenMode ;
}
void TMR0_ClockSelect(enu_ClockSource0 Copy_enuClockSource){
	TCCR0 &= 0b11111000;
	TCCR0 |= Copy_enuClockSource ;
}
void TMR0_PreloadingVal(u8 Copy_u8PreloadingValue){
	TCNT0 = Copy_u8PreloadingValue;
}
void TMR0_CompareMatchVal(u8 Copy_u8CompareMatchValue){
	OCR0 = Copy_u8CompareMatchValue;
}
void TMR0_InterruptState(enu_InterruptState0 Copy_enuInterruptState){
	TIMSK &= 0b11111100;
	TIMSK |= Copy_enuInterruptState ;
}
void TMR0_CompareOutpuMode(enu_CompareMode0 Copy_enuCompareOutputMode){
	TCCR0 &= 0b11001111;
TCCR0 |= Copy_enuCompareOutputMode ;
}

void TMR0_vidInit(enu_WGM0 Copy_enuWGM,enu_ClockSource0 Copy_enuClockSource,enu_InterruptState0 Copy_enuInterrupt,enu_CompareMode0 Copy_enuCompareMode){
TMR0_WaveformGen_Mode(Copy_enuWGM);
TMR0_ClockSelect(Copy_enuClockSource);
TMR0_CompareOutpuMode(Copy_enuCompareMode);
TMR0_InterruptState(Copy_enuInterrupt);
}
