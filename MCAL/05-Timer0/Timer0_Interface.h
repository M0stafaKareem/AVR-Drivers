#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H
typedef enum {
	enu_normal,
	enu_PWM=64,
	enu_CTC=8,
	enu_fastPWM=72
}enu_WGM0;

typedef enum{
	enu_normalOC0,
	enu_toggleOC0_onCompare=16,
	enu_clearOC0_onCompare=32,
	enu_setOC0_onCompare=48
}enu_CompareMode0;

typedef enum{
	enu_stopped,
	enu_TMR0_CLOCK_1,
	enu_TMR0_CLOCK_8,
	enu_TMR0_CLOCK_64,
	enu_TMR0_CLOCK_256,
	enu_TMR0_CLOCK_1024,
	enu_EXTERN_FALLING,
	enu_EXTERN_RISING
}enu_ClockSource0;

typedef enum{
	enu_TMR0off,
	enu_TOIE0_,
	enu_OCIE0_
}enu_InterruptState0;

void TMR0_WaveformGen_Mode(enu_WGM0 Copy_enuWaveformGenMode);
void TMR0_ClockSelect(enu_ClockSource0 Copy_enuClockSource);
void TMR0_PreloadingVal(u8 Copy_u8PreloadingValue);
void TMR0_CompareMatchVal(u8 Copy_u8CompareMatchValue);
void TMR0_InterruptState(enu_InterruptState0 Copy_enuInterruptState);
void TMR0_CompareOutpuMode(enu_CompareMode0 Copy_enuCompareOutputMode);

void TMR0_vidInit(enu_WGM0 Copy_enuWGM,enu_ClockSource0 Copy_enuClockSource,enu_InterruptState0 Copy_enuInterrupt,enu_CompareMode0 Copy_enuCompareMode);
#endif
