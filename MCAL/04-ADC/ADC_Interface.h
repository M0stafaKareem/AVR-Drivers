#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H
typedef enum{				/*Channel*/
	ADC0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7,
	x10_ADC0_ADC0,
	x10_ADC1_ADC0,
	x200_ADC0_ADC0,
	x200_ADC1_ADC0,
	x10_ADC2_ADC2,
	x10_ADC3_ADC2,
	x200_ADC2_ADC2,
	x200_ADC3_ADC2,
	ADC0_ADC1,
	ADC1_ADC1,
	ADC2_ADC1,
	ADC3_ADC1,
	ADC4_ADC1,
	ADC5_ADC1,
	ADC6_ADC1,
	ADC7_ADC1,
	ADC0_ADC2,
	ADC1_ADC2,
	ADC2_ADC2,
	ADC3_ADC2,
	ADC4_ADC2,
	ADC5_ADC2,
	Vbg,
	GND
}enu_Channel;
typedef enum{				/*Ref voltage*/
	Areff,
	Avcc=64,
	Internal=192
}enu_RefVolt;
typedef enum{				/*Prescaller*/
	_2=1,
	_4,
	_8,
	_16,
	_32,
	_64,
	_128
}enu_Prescaller;
typedef enum{				/*AutoTriggerSource*/
	FreeRunning,
	AnalogComparator=32,
	ExtInterrupt=64,
	Timer0_CompareMatch=96,
	Timer0_Overflow=128,
	TimerB_CompareMatch=160,
	Timer1_Overflow=192,
	Timer1_CaptureEvent=224
}enu_AutoTriggerSource;
typedef enum{				/*triggerMode*/
	SingleConversion,
	AutoTrigger
}enu_TriggerMode;
typedef enum{				/*Adjustment*/
	RightAdj,
	LeftAdj
}enu_Adjustment;
typedef enum{
	Disabled,
	Enabled
}enu_Interupt;

void ADC_ConvCompInterruptEnable(enu_Interupt Copy_enuInterruptEnable);
void ADC_TriggerMode(enu_TriggerMode Copy_enuTriggerMode,enu_AutoTriggerSource Copy_enuAutoTriggerSource);
void ADC_ChannelSelect(enu_Channel Copy_enuChannel);
void ADC_RefVoltage(enu_RefVolt Copy_enuRefVolt);
void ADC_Prescaller(enu_Prescaller Copy_enuPrescaller);
void ADC_StartConversion();
void ADC_ConversionResult(u16* pu16ConvResult,enu_Adjustment Copy_enuAdjustment);
void ADC_init(enu_Channel x0,enu_RefVolt x1,enu_Prescaller x2,enu_TriggerMode x3,enu_AutoTriggerSource x4,enu_Interupt x5);

#endif
