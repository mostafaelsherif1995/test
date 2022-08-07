#include "ADC.h"

#include <avr/io.h>
/*volatile verf_type vref_value ;

void ADC_init(unsigned long int clock,verf_type vref){
	unsigned int value=0;
	
	vref_value=vref;
	ADMUX|=(vref<<6)|(1<<5);   //enable vcc as ref and enable from h 8_bit to low 2 bit
	
	ADCSRA |=(1<<7);  // enable adc
	
	while(clock>200000){
		value++;
		clock/=2;
	}
	
	ADCSRA |=(value<<0);                //enable adc  disable 
}
float ADC_READ(ADC_NUM adc_num){
	  float value;
	 
	  ADMUX|=(adc_num<<0);  //enable number of adc
	ADCSRA|=(1<<6);    //start conversion
	
	while(!(ADCSRA & (1<<6))); //conversion complete
	value=((float)ADCH)/(256.0)*1024.0;
	
	
	switch(vref_value){
	case inter_5vref:{
	value=(value/256)*5;
	}break;
	case Avcc_ExtCapaci:{ ///mesh a3arf a3mal aih
	
	}break;
	case inter_2vref:{
	value=(value/256)*2.56;
	}break;
	default:{}break;
	}

	return value;
	
}*/







void InitADC()
{
	ADMUX=(1<<REFS0);                         // For Aref=AVcc;
	ADCSRA=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1); //Rrescalar div factor =64
}

u32 ReadADC(u8 ch)
{
	//Select ADC Channel ch must be 0-7
	ch=ch&0b00000111;
	ADMUX|=ch;

	//Start Single conversion
	ADCSRA|=(1<<ADSC);

	//Wait for conversion to complete
	while(!(ADCSRA & (1<<ADIF)));

	//Clear ADIF by writing one to it
	//Note you may be wondering why we have write one to clear it
	//This is standard way of clearing bits in io as said in datasheets.
	//The code writes '1' but it result in setting bit to '0' !!!

	ADCSRA|=(1<<ADIF);

	return(ADC);
}
