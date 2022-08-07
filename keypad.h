/*
 * KeyPad.h
 *
 * Created: 2016-10-14 5:26:22 AM
 *  Author: Abdo_Hashem
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "GPIO.h"
#include "KeyPad_Cfg.h"

typedef enum {NUMBER_RELEASED=0, NUMBER_PRESSED, NUMBER_JUST_PRESSED, NUMBER_JUST_RELEASED} Number_StateType;



void KeyPad_Init(void);

unsigned char GetNum(void);

unsigned char KeyPad_GetNum(void);



#endif /* KEYPAD_H_ */