//
//// 
	//// 
	//// /*
	////  * UART.c
	////  *
	////  * Created: 14/10/2016 06:01:55 م
	////  *  Author: LENOVO
	////  */ 
	 //#define F_CPU 8000000 
	 //#include <math.h>
	//#include "uart.h"
//
	//
	//void UART_init(unsigned long int baud_rate )
	//{
		//uint16_t UBRR_Value= lrint ( (F_CPU / (16L * baud_rate) ) -1);
		//UBRRL= (uint8_t) UBRR_Value;
		//UBRRH= (uint8_t) (UBRR_Value >> 8);
		//UCSRB= (1<<RXEN) | (1<<TXEN);
		//UCSRC|= (3<<UCSZ0);
	//}
//unsigned char UART_receive()
	//{
		//while(! (UCSRA & (1 << RXC) ) );
		//return UDR;
	//}
//void UART_send_(char data)
//{
	//while( ! (UCSRA & (1<<UDRE) ) );
	//UDR = data;
//}
//
//void UART_send_string(char *data)
//{
	//while(*data > 0)
	//UART_send_(*data++);
	//UART_send_('\0');
	//}
	//// void UART_WritArray(u16 *ArrayWrit,u32 num_data){
	//// 	u32 loopindex=0;
	//// 	for(loopindex=0;loopindex<num_data;loopindex++){
	//// 		UART_Writ(ArrayWrit[loopindex]);
	//// 	}
	//// 	
	//// 	
	//// }
	//// void UART_ReadArray(u16 *Arrayread,u32 num_data){
	//// 	u32 loopindex=0;
	//// 	for(loopindex=0;loopindex<num_data;loopindex++){
	//// 		Arrayread[loopindex]=UART_Read();
	//// 	}
	//// 	}	