
#include "KeyPad.h"


static Number_StateType Number_State = NUMBER_RELEASED;

unsigned char temp_1,temp_2=-1;

void KeyPad_Init(void)
{
	GPIO_InitParamType temp_init;
	
	INIT_GPIO_PIN(temp_init,KEYPAD_COLOUMN_PORT,(15<<KEYPAD_COLOUMN_PIN),0xff,0x00);
	
	INIT_GPIO_PIN(temp_init,KEYPAD_ROW_PORT,15<<KEYPAD_ROW_PIN,0x00,0xff);
}

unsigned char KeyPad_GetNum(void)
{
	unsigned char Number=255;
	
	temp_1=GetNum();
	
		if ((0<=temp_1 && temp_1<=9) || temp_1=='*' || temp_1=='#' || temp_1=='A' || temp_1=='B' || temp_1=='C' || temp_1=='D')
		{
			switch (Number_State)
			{
				case NUMBER_RELEASED:
				Number_State = NUMBER_JUST_PRESSED;
				break;
				
				case NUMBER_JUST_PRESSED:
				Number_State = NUMBER_PRESSED;
				break;
				
				case NUMBER_PRESSED:
				Number_State = NUMBER_PRESSED;
				break;
				
				case NUMBER_JUST_RELEASED:
				Number_State = NUMBER_JUST_PRESSED;
				break;
				
				default:
				break;
			}
		}
		
		
		if (!((0<=temp_1 && temp_1<=9) || temp_1=='*' || temp_1=='#' || temp_1=='A' || temp_1=='B' || temp_1=='C' || temp_1=='D'))
		{
			switch (Number_State)
			{
				case NUMBER_RELEASED:
				Number_State = NUMBER_RELEASED;
				break;
				
				case NUMBER_JUST_PRESSED:
				Number_State = NUMBER_JUST_RELEASED;
				break;
				
				case NUMBER_PRESSED:
				Number_State = NUMBER_JUST_RELEASED;
				break;
				
				case NUMBER_JUST_RELEASED:
				Number_State = NUMBER_RELEASED;
				break;
				
				default:
				break;
			}
		}

	
	if (Number_State==NUMBER_JUST_PRESSED)
	{
		Number = temp_1;
	}
	
	return Number;
}

unsigned char GetNum(void)
{
	GPIO_WriteParamType temp_write;
	GPIO_ReadParamType temp_read;
	unsigned char temp_data;
	unsigned char number=-1;
	
	WRITE_GPIO_DATA(temp_write,KEYPAD_COLOUMN_PORT,0x0F<<KEYPAD_COLOUMN_PIN,0x0E<<KEYPAD_COLOUMN_PIN);
	READ_GPIO_DATA(temp_read,KEYPAD_ROW_PORT,0x0F<<KEYPAD_ROW_PIN,temp_data);
	switch (temp_data>>KEYPAD_ROW_PIN)
	{
		case  0x0E:
		number=1;
		break;
		
		case  0x0D:
		number=2;
		break;
		
		case  0x0B:
		number=3;
		break;
		
		case  0x07:
		number='A';
		break;
		
		default:
		//do nothing
		break;
	}
	
	WRITE_GPIO_DATA(temp_write,KEYPAD_COLOUMN_PORT,0x0F<<KEYPAD_COLOUMN_PIN,0x0D<<KEYPAD_COLOUMN_PIN);
	READ_GPIO_DATA(temp_read,KEYPAD_ROW_PORT,0x0F<<KEYPAD_ROW_PIN,temp_data);
	switch (temp_data>>KEYPAD_ROW_PIN)
	{
		case  0x0E:
		number=4;
		break;
		
		case  0x0D:
		number=5;
		break;
		
		case  0x0B:
		number=6;
		break;
		
		case  0x07:
		number='B';
		break;
		
		default:
		//do nothing
		break;
	}
	
	WRITE_GPIO_DATA(temp_write,KEYPAD_COLOUMN_PORT,0x0F<<KEYPAD_COLOUMN_PIN,0x0B<<KEYPAD_COLOUMN_PIN);
	READ_GPIO_DATA(temp_read,KEYPAD_ROW_PORT,0x0F<<KEYPAD_ROW_PIN,temp_data);
	switch (temp_data>>KEYPAD_ROW_PIN)
	{
		case  0x0E:
		number=7;
		break;
		
		case  0x0D:
		number=8;
		break;
		
		case  0x0B:
		number=9;
		break;
		
		case  0x07:
		number='C';
		break;
		
		default:
		//do nothing
		break;
	}
	
	WRITE_GPIO_DATA(temp_write,KEYPAD_COLOUMN_PORT,0x0F<<KEYPAD_COLOUMN_PIN,0x07<<KEYPAD_COLOUMN_PIN);
	READ_GPIO_DATA(temp_read,KEYPAD_ROW_PORT,0x0F<<KEYPAD_ROW_PIN,temp_data);
	switch (temp_data>>KEYPAD_ROW_PIN)
	{
		case  0x0E:
		number='*';
		break;
		
		case  0x0D:
		number=0;
		break;
		
		case  0x0B:
		number='#';
		break;
		
		case  0x07:
		number='D';
		break;
		
		default:
		//do nothing
		break;
	}
	WRITE_GPIO_DATA(temp_write,KEYPAD_COLOUMN_PORT,0x0F<<KEYPAD_COLOUMN_PIN,0xff);
	
	return number;
}