#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "WDT_Interface.h"
#include "WDT_Register.h"


void WDT_PrescallerSelect(enu_WDTtime Copy_enuWDTime){
	WDTCR &= 0b11111000;
	WDTCR |= Copy_enuWDTime;
}

void WDT_TimerEnable(){
	SET_BIT(WDTCR,WDTCR_WDE);
}
void WDT_TimerDisable(){
	WDTCR |= (1<<WDTCR_WDE) | (1<<WDTCR_WDE) ;
}

