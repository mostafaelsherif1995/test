/*
 * Interupt.h
 *
 * Created: 06/07/2017 07:16:05 م
 *  Author: LENOVO
 */ 


#ifndef INTERUPT_H_
#define INTERUPT_H_
#include <avr/interrupt.h>
///////////there no     Low_level=0,Logic_Change, in int3
#include "GPIO.h"

typedef enum{
	 INT0_PD2=0,
	INT1_PD3,
	INT2_PB2
	
	}EXT_NUMInterupt;

typedef enum{
	Low_level=0,
	Logic_Change,
	Falling_Edge,
	Rising_Edge
	}Type_action;

void init_ExtInterupt(EXT_NUMInterupt Int_num,Type_action action,unsigned char type_res);





#endif /* INTERUPT_H_ */