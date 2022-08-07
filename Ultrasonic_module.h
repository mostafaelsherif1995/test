/*
 * Ultrasonic_module.h
 *
 * Created: 27/07/2017 09:32:27 ص
 *  Author: LENOVO
 */ 


#ifndef ULTRASONIC_MODULE_H_
#define ULTRASONIC_MODULE_H_
#include "GPIO.h"
#include "Utlrasonic_CFG.h"

#define TCCR0      (*((volatile unsigned char *)0x45))
#define TCNT0   (*((volatile unsigned char *)0x44))


typedef struct
{
	GPIO_PortType Trig_Port;
	unsigned char Trig_Pin;
	GPIO_PortType Echo_Port;
	unsigned char Echo_Pin;
	
}Ultrasonic_ConfigType;

void Ultrasonic_Init(unsigned char Ultrasonic_num);
unsigned char Utrasonic_duration(unsigned char Ultrasonic_num);



#endif /* ULTRASONIC_MODULE_H_ */