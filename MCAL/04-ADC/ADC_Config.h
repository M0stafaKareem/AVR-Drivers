#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

#define ADC_PORT portA

#define CHANNEL ADC0

#define AREF 0
#define	AVCC 1
#define	INT  3
#define REF_VOLTAGE INT

#define PRESCALLER 128  /*SCALES: (2-4-8-16-32-64-128)*/

#define RIGHT_ADJ 0
#define LEFT_ADJ 1
#define ADJUSTMENT_MODE RIGHT_ADJ

#define SINGLE_CONVERSION 0
#define AUTO_TRIGGER 1
#define TRIGGERING_MODE SINGLE_CONVERSION


#define FREE_RUNNING 	0
#define ANALOG_COMP 	1
#define EXT_INT0 		2
#define TIMER0_COMPARE 	3
#define TIMER0_OVRF 	4
#define TIMER_COMPARE_B 5
#define TIMER1_OVRF 	6
#define TIMER1_CAPTURE 	7
#define AUTO_TRIGGER_SOURCE FREE_RUNNING

#define DISABLED 0
#define ENABLED  1
#define ConvCompInterrupt ENABLED

#endif
