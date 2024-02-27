#ifndef TIMER_CONFIG_H
#define TIMER_CONFIG_H


#define NORMAL 	 0
#define PWM 	 1
#define CTC 	 2
#define FAST_PWM 3
/* selecct one from above*/
#define WAVEFORM_GENERATION_MODE FAST_PWM

#define STOPPED 0
#define PRESCALLED 8	/*Options : 1-8-64-256-1024*/
#define EXT_FALLING_EDGE 2
#define EXT_RISING_EDGE 3
/* selecct one from above*/
#define CLOCK_MODE PRESCALLED

#define DISABLED 0
#define ENABLED  1
/* selecct one from above*/
#define TMR_INTERRUPT DISABLED

#define NORMAL 			0
#define NON_PWM_TOGGLE 	1
#define NON_PWM_CLEAR 	2
#define NON_PWM_SET 	3

#define PWM_CLEAR_ON_COMPARE 	2
#define PWM_SET_ON_COMPARE 		3

#define FAST_PWM_CLEAR_ON_COMPARE 	2
#define FAST_PWM_SET_ON_COMPARE 	3
/* selecct one from above*/
#define COMPARE_OUTPUT_MODE FAST_PWM_CLEAR_ON_COMPARE
#endif
