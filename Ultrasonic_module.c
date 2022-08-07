/*
 * Ultrasonic_module.c
 *
 * Created: 27/07/2017 09:33:25 ص
 *  Author: LENOVO
 */ 
#define F_CPU  1000000

#include "Ultrasonic_module.h"
#include <util/delay.h>
#include <avr/interrupt.h>

extern const Ultrasonic_ConfigType  Ultrasonic_ConfigParam [Ultrasonic_MaxNUm];
static volatile int pulse = 0;
static volatile int i = 0;
void Ultrasonic_Init(unsigned char Ultrasonic_num){
	GPIO_InitParamType temp;
	INIT_GPIO_PIN(temp,(Ultrasonic_ConfigParam[Ultrasonic_num].Trig_Port), (1 << Ultrasonic_ConfigParam[Ultrasonic_num].Trig_Pin),0xff,0x00);
	INIT_GPIO_PIN(temp,(Ultrasonic_ConfigParam[Ultrasonic_num].Echo_Port), (1 << Ultrasonic_ConfigParam[Ultrasonic_num].Echo_Pin),0x00,0x00);
	
	GICR|=(1<<INT0);//enabling interrupt0

	MCUCR|=(1<<ISC00);//setting interrupt triggering logic change
	sei();
}
unsigned char Utrasonic_distance(unsigned char Ultrasonic_num){
	//unsigned int COUNTA = 0;//storing digital output
	GPIO_WriteParamType temp;
	//unsigned char data=0;
	
	WRITE_GPIO_DATA(temp,(Ultrasonic_ConfigParam[Ultrasonic_num].Trig_Port), (1 << Ultrasonic_ConfigParam[Ultrasonic_num].Trig_Pin),0xff);
	_delay_us(10); //15
	WRITE_GPIO_DATA(temp,(Ultrasonic_ConfigParam[Ultrasonic_num].Trig_Port), (1 << Ultrasonic_ConfigParam[Ultrasonic_num].Trig_Pin),0x00);
	return ((pulse)*128)/58;

}

ISR(INT0_vect)//interrupt service routine when there is a change in logic level
{

	if (i==1)//when logic from HIGH to LOW

	{

		TCCR0=0;//disabling counter
		if(TCNT0==0){
		 pulse=0;}
		 else if(TCNT0>=130){
		 pulse=0;}
         else {
		pulse=TCNT0;//count memory is updated to integer
		 }
		TCNT0=0;//resetting the counter memory

		i=0;

	}

	if (i==0)//when logic change from LOW to HIGH

	{

		TCCR0|=(1<<CS02)|(1<<CS00);//enabling counter  pres1/1024

		i=1;

	}

}
