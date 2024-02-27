#ifndef MCAL_07_WDT_WDT_INTERFACE_H_
#define MCAL_07_WDT_WDT_INTERFACE_H_

typedef enum{
	  _16ms,
	  _32ms,
	  _65ms,
	 _130ms,
	 _260ms,
	 _520ms,
	 _1sec,
	 _2sec

}enu_WDTtime;

void WDT_PrescallerSelect(enu_WDTtime Copy_enuWDTtime);
void WDT_TimerEnable();
void WDT_TimerDisable();

#endif
