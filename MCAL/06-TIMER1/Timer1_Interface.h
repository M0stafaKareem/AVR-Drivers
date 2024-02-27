#ifndef TIMER1_INTERFACE_H
#define TIMER1_INTERFACE_H

typedef enum{
	STOPPED,
	TMR1_CLOCK_1,
	TMR1_CLOCK_8,
	TMR1_CLOCK_64,
	TMR1_CLOCK_256,
	TMR1_CLOCK_1024,
	EXTERN_FALLING,
	EXTERN_RISING
}enu_ClockSource1;

typedef enum{
	NORMAL_OC1,
	TOGGLE_OC1B_onCompare=16,
	CLEAR_OC1B_onFirstCompare=32,
	SET_OC1B_onFirstCompare=48,

	TOGGLE_OC1A_Compare=64,
	CLEAR_OC1A_onFirstCompare=128,
	SET_OC1A_onFirstCompare=192
}enu_CompareMode1;

typedef enum{
	Normal,
	_8bit_PWM,
	_9bit_PWM,
	_10bit_PWM,
	CTC,
	_8bit_FastPWM,
	_9bit_FastPWM,
	_10bit_FastPWM,
	ICR1_Phase_Freq_Correct,
	OCR1A_Phase_Freq_Correct,
	ICR1_Phase_Correct,
	OCR1A_Phase_Correct,
	ICR1_CTC,
	ICR1_FastPWM=14,
	OCR1A_FastPWM
}enu_WGM1;

typedef enum{
	OFF__,
	TOIE1_ =4 ,
	OCIE1B_=8 ,
	OCIE1A_=16,
	TICIE1_=32
}enu_InterruptState1;

void TMR1_WaveformGen_Mode(enu_WGM1 Copy_enuWaveformGenMode);
void TMR1_ClockSelect(enu_ClockSource1 Copy_enuClockSource);
void TMR1_PreloadingVal(u16 Copy_u8PreloadingValue);
void TMR1_CompareMatchVal(u8 Copy_u8CompareMatchValue);
void TMR1_InterruptState(enu_InterruptState1 Copy_enuInterruptState);
void TMR1_CompareOutpuMode(enu_CompareMode1 Copy_enuCompareOutputMode);
void TMR1_SetICR1Avalue(u16 Copy_u16ICRvalue);
void TMR1_SetOCR1Avalue(u16 Copy_u16OCRAvalue);
void TMR1_SetOCR1Bvalue(u16 Copy_u16OCRBvalue);
void TMR1_vidInit(enu_WGM1 Copy_enuWGM,enu_ClockSource1 Copy_enuClockSource,enu_InterruptState1 Copy_enuInterrupt,enu_CompareMode1 Copy_enuCompareMode);



#endif
