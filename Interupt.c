/*
 * Interupt.c
 *
 * Created: 06/07/2017 07:15:41 م
 *  Author: LENOVO
 */ 
#include "Interupt.h"
#include <avr/interrupt.h>
void init_ExtInterupt(EXT_NUMInterupt Int_num,Type_action action,unsigned char type_res){
	 GPIO_InitParamType temp_init;
	 
	 
	switch(Int_num){
		case  INT0_PD2:{
			 INIT_GPIO_PIN(temp_init,PD,(1<<2),0x00,type_res);
			GICR |=(1<<6);
			MCUCR|=(action<<0);
			}break;
		case  INT1_PD3:{
			INIT_GPIO_PIN(temp_init,PD,(1<<3),0x00,type_res);
			GICR |=(1<<7);
			MCUCR|=(action<<2);
			}break;
		case  INT2_PB2:{
			INIT_GPIO_PIN(temp_init,PB,(1<<2),0x00,type_res);
			GICR |=(1<<5);
			if(action==Falling_Edge){
				MCUCSR &=~(1<<6);
			}
			else if(action==Rising_Edge){
				MCUCSR |=(1<<6);
			}
			}break;
		
	}
	
	
	
	
	
	
	sei();
	
}
