/*
 * timer.c
 *
 * Created: 29/07/2017 09:05:06 ص
 *  Author: LENOVO
 */ 
#include "timer.h"
#include <math.h>

#define calc(time_coun,time_req,pres)  (time_coun)=((time_req)/1000);\
(time_coun)/=((pres)/F_CPU);\
(time_coun)-1

static void timer0_PrescSet(timer_type  timer_num,unsigned int Req_tim_ms,unsigned char *regist,unsigned long int *ocr ){
	 unsigned long int time_count=70000,value_over_flow=255;
	 unsigned char index=0;
	
	if(timer_num==timer1){
		value_over_flow=65535;
	}
	else{
		value_over_flow=255;
	}
	
while((time_count >= 65535) && (index<=5)){
		index++;
	
		switch(index){
		case 1:{  //1
					time_count=(unsigned long int)((((double)Req_tim_ms/1000.0)/(1.0/(double)F_CPU))-1);
				//calc(time_count,Req_tim_ms,1);
				
			}break;  
	case 2:{ //8
		time_count=(unsigned long int)((((double)Req_tim_ms/1000.0)/(8.0/(double)F_CPU))-1);
		
		//calc(time_count,Req_tim_ms,8);
		}break;  
	case 3:{  //64
		time_count=(unsigned long int)((((double)Req_tim_ms/1000.0)/(64.0/(double)F_CPU))-1);
		//calc(time_count,Req_tim_ms,64);
	}break;   
	case 4:{  //256
		time_count=(unsigned long int)((((double)Req_tim_ms/1000.0)/(256.0/(double)F_CPU))-1);

             //calc(time_count,Req_tim_ms,256); 
			  }break;  
     case 5:{ //1024
			time_count=(unsigned long int)((((double)Req_tim_ms/1000.0)/(256.0/(double)F_CPU))-1);
			//calc(time_count,Req_tim_ms,1024);		
			}break;	//1024
	default:{}break;
		
	}
	
	}
	 	
	 	

	*regist=index;
	*ocr=time_count;
	}
void pwm0_init()
{
	// initialize TCCR0 as per requirement, say as follows
	TCCR0 |= (1<<WGM00)|(1<<COM01)|(1<<WGM01)|(1<<CS00)|(1<<CS01);
	// make sure to make OC0 pin (pin PB3 for atmega32) as output pin
	DDRB |= (1<<PB3);
}
void Duty_cyclevalue(float prec_value){
	
	prec_value=((prec_value/100)*255)+1;
	OCR0=(int)prec_value;
}
void timer1_init(unsigned int Req_tim_ms)
{
	unsigned char regist;
	unsigned long int ocr;
	
	
	// set up timer with prescaler = 64 and CTC mode
	timer0_PrescSet(timer1,Req_tim_ms,&regist,&ocr);
	TCCR1B |= (1 << WGM12);
	TCCR1B|=(regist << 0);
	
 	
	// initialize counter
	TCNT1 = 0;
	// initialize compare value
	OCR1A =ocr; //15624;   //1sec
	// enable compare interrupt
	TIMSK |= (1 << OCIE1A);
	// enable global interrupts
	sei();
}


// typedef enum{
// 	disable=0,
// 	enable=1
// }timer_stata;



/*#include <avr/io.h>
#include <avr/interrupt.h>
// global variable to count the number of overflows
volatile uint8_t tot_overflow;
// initialize timer, interrupt and variable
void timer1_init()
{
	// set up timer with prescaler = 8
	TCCR1B |= (1 << CS11);
	// initialize counter
	TCNT1 = 0;
	// enable overflow interrupt
	TIMSK |= (1 << TOIE1);
	// enable global interrupts
	sei();
	// initialize overflow counter variable
	tot_overflow = 0;
}
// TIMER1 overflow interrupt service routine
// called whenever TCNT1 overflows
ISR(TIMER1_OVF_vect)
{
	// keep a track of number of overflows
	tot_overflow++;
	// check for number of overflows here itself
	// 61 overflows = 2 seconds delay (approx.)
	if	(tot_overflow >= 61)	// NOTE: '>=' used instead of '=='
	{
		PORTC ^= (1 << 0);
		// toggles the led
		// no timer reset required here as the timer
		// is reset every time it overflows
		tot_overflow = 0;
		// reset overflow counter
	}
}
int main(void)
{
	// connect led to pin PC0
	DDRC |= (1 << 0);
	// initialize timer
	timer1_init();
	// loop forever
	while(1)	{
		// do nothing
		// comparison is done in the ISR itself
	}
}*/

void timer0_init(unsigned int Req_tim_ms){
	unsigned char regist;
	unsigned long int ocr;
	
	
	// set up timer with prescaler = 256and CTC mode
	//timer0_PrescSet(timer1,Req_tim_ms,&regist,&ocr);
	TCCR0|=(1<<WGM01)|(1<<2);
	OCR0|=(61<<0);
	TIMSK |=(1<<1);
	sei();
}