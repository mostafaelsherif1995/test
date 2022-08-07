

#ifndef _ADC_H_
#define _ADC_H_
#include "GPIO.h"
#include "standio.h"
#define ADMUX      (*((volatile unsigned char *)0x27))
#define ADCSRA     (*((volatile unsigned char *)0x26))
#define ADCL       (*((volatile unsigned char *)0x24))
#define ADCH       (*((volatile unsigned char *)0x25))
#define SFIOR      (*((volatile unsigned char *)0x50))



typedef enum{
ADC_0=00000,
ADC_1=00001,
ADC_2=00010,
ADC_3=00011,
ADC_4=00100,
ADC_5=00101,
ADC_6=00110,
ADC_7=00111
//////////////BAKY REGISTERRS






}ADC_NUM;
typedef enum{
	inter_5vref=0,
	Avcc_ExtCapaci=1,
	reserved=2,
	inter_2vref=3,
	
	}verf_type;


void ADC_init(unsigned long int clock,verf_type vref);
float ADC_READ(ADC_NUM adc_num);
void InitADC();
u32 ReadADC(u8 ch);














#endif
