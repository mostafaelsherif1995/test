
#define F_CPU 8000000ul
#include <util/delay.h>
//#include <avr/io.h>
 #include <avr/interrupt.h>
 #include "standio.h"
// #include "Interupt.h"
 #include "ADC.h"
 #include "LCD.h"
 #include "LED.h"
 //#include "Ultrasonic_module.h"
// #include "I2C.h"
#include "timer.h"
/*// 
// 
// 
// 
// 
// void main(){
// 	
// 	int x;
// 	
// 	
// 	
// 	
// 	
// 	
// 	
// 	
// LCD_Init();
// //ADC_init(F_CPU,inter_2vref);
// //LED_Init();
// //init_ExtInterupt(INT0_PD2,Rising_Edge,0xff);
// //init_ExtInterupt(INT1_PD3,Rising_Edge,0xff);
// Ultrasonic_Init(0);
// while(1){
// // x=ADC_READ(ADC_0);
// // x*=100;
// 
// 
// LCD_DispString(" distanc:");
// x=Utrasonic_distance(0);
// if(x>0){
// LCD_DispNum(x);
// LCD_DispString("CM");}
// else{
// LCD_DispString("erro");	
// }
// 
// _delay_ms(1000);
// LCD_Clear();
// 
// 
// 
// 
// 
// }
// 
// 
// 
// }
// 


#include <avr/io.h>
#include <avr/interrupt.h>
// initialize timer, interrupt and variable

// this ISR is fired whenever a match occurs
// hence, toggle led here itself..
unsigned int sec=0,min=29,hour=9,day=29,month=7;
unsigned long int year=2017;
ISR (TIMER1_COMPA_vect)
{
	// toggle led here
	//PORTC ^= (1 << 0);
	sec++;
	if(sec==60){
		min++;
		sec=0;
	}
	if(min==60){
		hour++;
		min=0;
	}
	if(hour==24){
		day++;
		hour=0;
	}
	if(day==30){
		month++;
		day=0;
	}
	if(month==12){
		year++;
		month=0;
	}
	    LCD_DispNum_axis(sec,0,1); //2
	    LCD_DispStrin_axis(":",3,0);  //3
	    LCD_DispNum_axis(min,0,4);//5
	    LCD_DispStrin_axis(":",6,0); //6
	    LCD_DispNum_axis(hour,0,7);
	    LCD_DispNum_axis(day,1,1); //2
	    LCD_DispStrin_axis(":",3,1);  //3
	    LCD_DispNum_axis(month,1,4);//5
	    LCD_DispStrin_axis(":",6,1); //6
	    LCD_DispNum_axis(year,1,7);
	    
}	
#define rightforw 0
#define rightback  1
#define leftforw   2
#define leftback   3
int	main(void){
		
			// connect led to pin PC0
			//DDRC |= (1 << 0);
			// initialize timer
			LCD_Init();
			timer1_init(1000);
			Ultrasonic_Init(0);
			LED_Init();
			
			// loop forever
while(1)
{
	     
		if( Utrasonic_distance(0)<20){
			LED_SetData(rightforw,LED_OFF);
			LED_SetData(rightback,LED_ON);
		 LED_SetData(leftforw,LED_ON);
		 LED_SetData(leftback,LED_OFF);
		 _delay_ms(100);
		          
			}
			else{
				LED_SetData(rightforw,LED_ON);
				 LED_SetData(leftforw,LED_ON);
			}
		}}*/
/*





int main(void)

{

	char R;


	LCD_Init();

	TWI_Init(400000);

while(1){

		EEPROM_Write('a',0x00);

		_delay_ms(1000); // You must allow suffcent delay for the EEPROM to complete the its internal write cycle
    EEPROM_Write('b',0x01);
      _delay_ms(1000);
   EEPROM_Write('c',0x02);
      _delay_ms(1000);
      EEPROM_Write('d',0x03);
          _delay_ms(1000);
         EEPROM_Write('e',0x04);
	  _delay_ms(1000);
	  
	  
	  
 		EEPROM_Read(0x00,&R);
  		LCD_DispChar(R);
  		_delay_ms(1000);
  		EEPROM_Read(0x01,&R);
  		LCD_DispChar(R);
  		_delay_ms(1000);
  		EEPROM_Read(0x02,&R);
  		LCD_DispChar(R);
  		_delay_ms(1000);
  		EEPROM_Read(0x03,&R);
  		LCD_DispChar(R);
  		_delay_ms(1000);
  		EEPROM_Read(0x04,&R);
  		LCD_DispChar(R);
  		_delay_ms(1000);
 		
}
		

}*/


ADC_NUM pulsePin = ADC_0;
//int blinkPin = 13;
int fadePin = 5;
int fadeRate = 0;
volatile int BPM;
volatile int Signal;
volatile int IBI = 600;
volatile boolean Pulse = false;
volatile boolean QS = false;   volatile int rate[10];
volatile unsigned long sampleCounter = 0;
volatile unsigned long lastBeatTime = 0;
volatile int P =512;
volatile int T = 512;
volatile int thresh = 512;
volatile int amp = 100;
volatile boolean firstBeat = true;
volatile boolean secondBeat = false;
//unsigned int runningTotal;
void main(){
	LED_Init();
	LCD_Init();
	timer0_init(2);
	InitADC();
	//LCD_DispString("HEART RATE DEVICE ");
	
	while(1){
		//Signal = ADC_READ(ADC_0);
		//Signal=ReadADC(0);
		//LCD_DispNum(Signal);
		//_delay_ms(500);
		//LCD_SendCommand(_LCD_Clear);
		 if (QS == true){
			// sendDataToProcessing('B',BPM);
			// sendDataToProcessing('Q',IBI);
			LCD_SendCommand(_LCD_Clear);
			//LCD_DispString("hear_rate= ");
			LCD_DispNum(BPM);
			
			 fadeRate = 255;
			 QS = false;
		 }
		 //ledFadeToBeat();
		 _delay_ms(10);
	 }
	}
	



ISR(TIMER0_COMP_vect){
	Signal=ReadADC(0);
	
	
	sampleCounter += 2;
	int N = sampleCounter - lastBeatTime;
	if(Signal < thresh && N > (IBI/5)*3){

		if (Signal < T){

			T = Signal;

		}

	}

	if(Signal > thresh && Signal > P){

		P = Signal;

	}
	if (N > 250){

		if ( (Signal > thresh) && (Pulse == false) && (N > ((IBI/5)*3) )){
			Pulse = true;
			LED_SetData(0,LED_ON);
			LED_SetData(1,LED_ON);
			LED_SetData(2,LED_ON);
			IBI = sampleCounter - lastBeatTime;
			lastBeatTime = sampleCounter;
			if(secondBeat){

				secondBeat = false;

				for(int i=0; i<=9; i++){

					rate[i] = IBI;

				}

			}

			if(firstBeat){
				firstBeat = false;

				secondBeat = true;

				sei();
				return;
			}
			unsigned int   runningTotal = 0;
			for(int i=0; i<=8; i++){
				rate[i] = rate[i+1];
				runningTotal += rate[i];
			}
			rate[9] = IBI;
			runningTotal += rate[9];
			runningTotal /= 10;
			BPM = 60000/runningTotal;
			QS = true;
		}

	}
	if (Signal < thresh && Pulse == true){
			LED_SetData(0,LED_OFF);
			LED_SetData(1,LED_OFF);
			LED_SetData(2,LED_OFF);
		Pulse = false;
		amp = P - T;
		thresh = amp/2 + T;
		P = thresh;
		T = thresh;
	}
	if (N > 2500){
		thresh = 512;
		P = 512;
		T = 512;
		firstBeat = true;
		secondBeat = false;
		lastBeatTime = sampleCounter;
	}
}
