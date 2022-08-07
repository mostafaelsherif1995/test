/*
 * timer.h
 *
 * Created: 29/07/2017 09:04:48 ص
 *  Author: LENOVO
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "LCD.h"
typedef enum{
	timer0=0,
	timer1=1,
	timer2=2
}timer_type;
void pwm0_init();
void Duty_cyclevalue(float prec_value);
void timer1_init(unsigned int Req_tim_ms);

void timer0_init(unsigned int Req_tim_ms);


#endif /* TIMER_H_ */