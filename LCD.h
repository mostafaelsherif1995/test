
/*
 * LCD.h
 *
 * Created: 16/10/2016 04:40:47 ص
 *  Author: LENOVO
 */ 

#ifndef LCD_H_
#define LCD_H_
#include "GPIO.h"
/*_LCD_CLEAR    =0x01,            // Clear display
_LCD_RETURN_HOME =0x02,          //Return cursor to home position, returns a shifted display to its original position. Display data RAM is unaffected.
// _LCD_CURSOR_OFF  =0x,          //  Turn off cursor
// _LCD_UNDERLINE_ON  =0x,        // Underline cursor on
_LCD_BLINK_CURSOR_ON =0x0E,        // Blink cursor on
//  _LCD_BLINK_CURSOR_ON=0x0f
// _LCD_MOVE_CURSOR_LEFT =0x04,     // Move cursor left without changing display data RAM
// _LCD_MOVE_CURSOR_RIGHT =0x06,    //Move cursor right without changing display data RAM
// _LCD_TURN_ON     =0x,          //Turn Lcd display on
// _LCD_TURN_OFF   =0x,           //Turn Lcd display off
// _LCD_SHIFT_LEFT  =0x,          //Shift display left without changing display data RAM
// _LCD_SHIFT_RIGHT =0x        //Shift display right without changing display data RAM
_LCD_FIRST_ROW =0x80,      // Move cursor to the 1st row
_LCD_SECOND_ROW=0xC0,         //  Move cursor to the 2nd row
// _LCD_THIRD_ROW  =0x,         //Move cursor to the 3rd row
// _LCD_FOURTH_ROW =0x,          //Move cursor to the 4th row*/

typedef enum{
_LCD_Clear=0x01,
_ReturnHome=0x02,
_DecCursor=0x04,
_Shift_DispRight=0x05,
_IncrCursor=0x06,

_Shift_DispLeft=0x07,
_DispOff_CursorOff=0x08,
_DispOff_CursorOn=0x0A,
_DispOn_CursorOff=0x0C,
_DispOn_CursorBlink=0x0E,
_ShiftCursorPos_Left=0x10,
_ShiftCursorPos_Right=0x14,
_ShiftEntDisp_Left=0x18,
_ShiftEntDisp_Right=0x1C,
_2lines_5x7Matrix=0x28,
_CursorBeg_1stLine=0x80,
_CursorBeg_2ndLine=0xC0

}Type_comnd;



void LCD_Init(void);
void LCD_SendCommand(Type_comnd CmdId);
void LCD_Clear(void);
void LCD_DispChar(unsigned char CharData);
void LCD_DispString(unsigned char * StrPtr);
void LCD_GoToXy(unsigned char x, unsigned char y);
void LCD_DispStrin_axis(unsigned char * StrPtr,unsigned char row,unsigned char colum);
void LCD_DispNum(double num);
void LCD_DispNum_axis(double num,unsigned char colum,unsigned char row);
void LCD_DispChar_axis(unsigned char CharData,unsigned char row,unsigned char colum);
 
 
 
 

#endif /* LCD_H_ */