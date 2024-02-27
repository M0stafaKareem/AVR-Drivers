#ifndef ADC_REGISTER_H
#define ADC_REGISTER_H

#define ADMUX *((volatile u8*)0x27)
#define ADMUX_0 0
#define ADMUX_1 1
#define ADMUX_2 2
#define ADMUX_3 3
#define ADMUX_4 4
#define ADMUX_ADLAR 5
#define ADMUX_REFS0 6
#define ADMUX_REFS1 7


#define ADCSRA *((volatile u8*)0x26)
#define ADCSRA_ADEN  7
#define ADCSRA_ADSC  6
#define ADCSRA_ADATE 5
#define ADCSRA_ADIF  4                 /* interrupt flag*/
#define ADCSRA_ADIE  3                 /* interrupt flag*/
#define ADCSRA_ADPS2 2                 /*prescaler Bits*/
#define ADCSRA_ADPS1 1                 /*prescaler Bits*/
#define ADCSRA_ADPS0 0                 /*prescaler Bits*/


#define SFIOR *((volatile u8*)0x50)
#define SFIOR_ADTS2 7
#define SFIOR_ADTS1 6
#define SFIOR_ADTS0 5

#define ADCH *((volatile u8*)0x25)
#define ADCL *((volatile u8*)0x24)


#endif
