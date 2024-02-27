#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "ADC_Register.h"
#include "ADC_Config.h"
#include "ADC_Interface.h"


void ADC_ChannelSelect(enu_Channel Copy_enuChannel){
	ADMUX &= 0b11100000;
	ADMUX |= Copy_enuChannel;
}

void ADC_RefVoltage(enu_RefVolt Copy_enuRefVolt){
	ADMUX &= 0b00111111;
	ADMUX |= Copy_enuRefVolt;
}

void ADC_Prescaller(enu_Prescaller Copy_enuPrescaller){
	ADCSRA &= 0b11111000;
	ADCSRA |= Copy_enuPrescaller;
}

void ADC_TriggerMode(enu_TriggerMode Copy_enuTriggerMode,enu_AutoTriggerSource Copy_enuAutoTriggerSource){
	if (Copy_enuTriggerMode == SingleConversion)
		CLR_BIT(ADCSRA,ADCSRA_ADATE);
	else
		if (Copy_enuTriggerMode == AutoTrigger){
			SET_BIT(ADCSRA,ADCSRA_ADATE);
			SFIOR &= 0b00011111;
			SFIOR |= Copy_enuAutoTriggerSource;
		}
}

void ADC_ConversionResult(u16* pu16ConvResult,enu_Adjustment Copy_enuAdjustment){
if (Copy_enuAdjustment==LeftAdj){
	SET_BIT(ADMUX,ADMUX_ADLAR);
	*pu16ConvResult = (ADCL>>6) | (ADCH<<2);
	}
else
	if (Copy_enuAdjustment == RightAdj){
	CLR_BIT(ADMUX,ADMUX_ADLAR);
	*pu16ConvResult = (ADCL) | (ADCH<<8);
	}
}

void ADC_StartConversion(){
	SET_BIT(ADCSRA,ADCSRA_ADEN);
	SET_BIT(ADCSRA,ADCSRA_ADSC);
	while( GET_BIT(ADCSRA,ADCSRA_ADIF)==0 );
	SET_BIT(ADCSRA,ADCSRA_ADIF);
}

void ADC_ConvCompInterruptEnable(enu_Interupt Copy_enuInterruptEnable){
if(Copy_enuInterruptEnable == Disabled)
		CLR_BIT(ADCSRA,ADCSRA_ADIE);
else
	if(Copy_enuInterruptEnable == Enabled)
		SET_BIT(ADCSRA,ADCSRA_ADIE);
}

void ADC_init(enu_Channel x0,enu_RefVolt x1,enu_Prescaller x2,enu_TriggerMode x3,enu_AutoTriggerSource x4,enu_Interupt x5){

	ADC_Prescaller(x2);
	ADC_RefVoltage(x1);
	ADC_ChannelSelect(x0);
	ADC_TriggerMode(x3, x4);
	ADC_ConvCompInterruptEnable(x5);
}
