
/*
 * LCD.c
 *
 * Created: 16/10/2016 04:41:07 ص
 *  Author: LENOVO
 */ 
#define F_CPU 1000000UL
#include <util/delay.h>
#include "LCD_Cfg.h"
#include "LCD.h"
#include "GPIO.h"

#define RS_MASK 1 << RS_PIN_NUMBER
#define RW_MASK 1 << RW_PIN_NUMBER
#define EN_MASK 1 << EN_PIN_NUMBER
#define DATA_MASK 0x0f << DATA_PIN_NUMBER




													 
static void SendCommand(unsigned char CmdId);
static void SendData(unsigned char DataId);
 static void double_to_str(double num,char str[]);
void LCD_Init(void)
{
	GPIO_InitParamType Temp;
	/*Init Rs direction*/
INIT_GPIO_PIN(Temp,CTRL_PORT,RS_MASK,0xff,0x00);
	/*Init Rw direction*/
INIT_GPIO_PIN(Temp,CTRL_PORT,RW_MASK,0xff,0x00);	
	/*Init En direction*/
INIT_GPIO_PIN(Temp,CTRL_PORT,EN_MASK,0xff,0x00);	
	/*Init Data Direction*/
INIT_GPIO_PIN(Temp,DATA_PORT,DATA_MASK,0xff,0x00);	
	_delay_ms(15);
	/*Send the commands 0x33,0x32,0x28,0x0e,0x02,0x01*/
SendCommand(0x33);
SendCommand(0x32);
SendCommand(0x28);
SendCommand(0x0e);
SendCommand(0x02);
SendCommand(0x01);
	
}
void LCD_Clear(void)
{
	/*Send the Clear Command*/
	SendCommand(0x01);
}











void LCD_DispChar(unsigned char CharData)
{
	/*Send Data*/
	SendData(CharData);
}
void LCD_DispString(unsigned char * StrPtr)
{
	/*Loop on Send data till null charecter*/
	while(*(StrPtr) != '\0')
	{
		SendData(*StrPtr);
		StrPtr ++;
	}
}
void LCD_GoToXy(unsigned char x, unsigned char y)
{
	/*Check the y position 0 or 1 then set the start 
	command Id with line 1 address or line 2 address*/
	if(y == 0)
	{
		SendCommand(0x80 +x);
	}
	else
	{
		SendCommand(0xc0 + x);
	}
	/*Add the x position to the line address*/ 
}
static void SendCommand(unsigned char CmdId)
{
	GPIO_WriteParamType Temp;
	unsigned char TempChar;
	/*Set RS to 0*/
	WRITE_GPIO_DATA(Temp,CTRL_PORT,RS_MASK,0x00);
	/*Set Rw to 0*/
	WRITE_GPIO_DATA(Temp,CTRL_PORT,RW_MASK,0x00);	
	/*Get High nipple of Command*/
   	TempChar = CmdId >> 4;  
	/*Set High nipple on data Bus*/
	WRITE_GPIO_DATA(Temp,DATA_PORT,DATA_MASK,(TempChar << DATA_PIN_NUMBER));
	/*Set Enable to 1*/
	WRITE_GPIO_DATA(Temp,CTRL_PORT,EN_MASK,0xff);
	/*Wait for 10 us*/
	_delay_us(10);
	/*Set Enable to 0*/
	WRITE_GPIO_DATA(Temp,CTRL_PORT,EN_MASK,0x00);
	/*Get Low nipple of Command*/
	TempChar = CmdId & 0x0f;
	/*Set Low nipple on data Bus*/
	WRITE_GPIO_DATA(Temp,DATA_PORT,DATA_MASK,(TempChar << DATA_PIN_NUMBER));
	/*Set Enable to 1*/
	WRITE_GPIO_DATA(Temp,CTRL_PORT,EN_MASK,0xff);
	/*Wait for 10 us*/
	_delay_us(10);
	/*Set Enable to 0*/
	WRITE_GPIO_DATA(Temp,CTRL_PORT,EN_MASK,0x00);
	
	/*Wait for 2ms*/
	_delay_ms(2);
	
}
void LCD_SendCommand(Type_comnd CmdId){
	SendCommand( CmdId);
	
}
static void SendData(unsigned char DataId)
{
	GPIO_WriteParamType Temp;
	unsigned char TempChar;
	/*Set RS to 0*/
	WRITE_GPIO_DATA(Temp,CTRL_PORT,RS_MASK,0xff);
	/*Set Rw to 0*/
	WRITE_GPIO_DATA(Temp,CTRL_PORT,RW_MASK,0x00);
	/*Get High nipple of Command*/
	TempChar = DataId >> 4;
	/*Set High nipple on data Bus*/
	WRITE_GPIO_DATA(Temp,DATA_PORT,DATA_MASK,(TempChar << DATA_PIN_NUMBER));
	/*Set Enable to 1*/
	WRITE_GPIO_DATA(Temp,CTRL_PORT,EN_MASK,0xff);
	/*Wait for 10 us*/
	_delay_us(10);
	/*Set Enable to 0*/
	WRITE_GPIO_DATA(Temp,CTRL_PORT,EN_MASK,0x00);
	/*Get Low nipple of Command*/
	TempChar = DataId & 0x0f;
	/*Set Low nipple on data Bus*/
	WRITE_GPIO_DATA(Temp,DATA_PORT,DATA_MASK,(TempChar << DATA_PIN_NUMBER));
	/*Set Enable to 1*/
	WRITE_GPIO_DATA(Temp,CTRL_PORT,EN_MASK,0xff);
	/*Wait for 10 us*/
	_delay_us(10);
	/*Set Enable to 0*/
	WRITE_GPIO_DATA(Temp,CTRL_PORT,EN_MASK,0x00);
	
	/*Wait for 2ms*/
	_delay_us(10);
}




	
 static void double_to_str(double num,char str[]){
	 long long int_num;
	 unsigned int length=0,lenght_f=0,dot_pos=0,sign=0,dot=0;
	 int index=0;
	 double f_num;

	 if(num < 0){
		 sign='-';
		 num *=-1;
	 }
	 else{
		 
	 }
	 f_num=num;
	 int_num= num;
	 while((f_num-(double)int_num)!=0.0 && !((f_num - (double)int_num) < 0.0) ){
		 lenght_f++;
		 f_num *=10;
		 int_num=f_num;
		 
	 }
 
	 for (length = (num > 1) ? 0 : 1; num > 1; length++){
		 if(num==10){
			 length++;
		 }
		 else	{}
			 
		  num/= 10;
	 }

	 if(lenght_f){
		 dot=1;
		 dot_pos=length;
	 }
	 else{
		 dot=0;
	 }

	 length=length + dot + lenght_f;
	 if(sign=='-'&&dot==1){
		 length++;
		 dot_pos++;
	 }
	 else if(sign=='-'){
		 length++;
	 }
 else{}////dont make any thing

 for (index= length; index >= 0; index--)
 {
	 if (index == length)
	 str[index] = '\0';
	 else if (index == (dot_pos)&&dot==1)
	 str[index] = '.';
	 else if (sign == '-' && index == 0)
	 str[index] = '-';
	 else
	 {
		 str[index] = (int_num%10) + '0';
		 
			
			
		int_num /= 10;
		
	 }
 }

}
void LCD_DispStrin_axis(unsigned char * StrPtr,unsigned char row,unsigned char colum){
	LCD_GoToXy(row, colum);
	LCD_DispString(StrPtr);
}

void LCD_DispNum_axis(double num,unsigned char colum,unsigned char row){
	 char str[12];
	
	double_to_str(num, str);
	LCD_DispStrin_axis(str,row,colum);
	
}
void LCD_DispNum(double num){
	char str[12];
	double_to_str(num, str);
	LCD_DispString(str);
}
void LCD_DispChar_axis(unsigned char CharData,unsigned char row,unsigned char colum){
	LCD_GoToXy(row, colum);
	LCD_DispChar(CharData);
}


