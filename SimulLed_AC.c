//
///*
 //* SimulLed_AC.c
 //*
 //* Created: 28/10/2016 12:41:45 م
 //*  Author: LENOVO
 //*/ 
//#include "SimulLed_AC.h"
//extern const AC_ConfigType  AC_ConfigParam[MAX_ACLed_Num];
//void Init_SimulLed_AC(void)
//{
	//unsigned long int LoopIndex;
	//GPIO_InitType ACParam;
	//GPIO_WriteType ACWrtParam;
	//ACParam.Direction = 0xff;
	//ACParam.IsPullupUsed = 0x00;
	//for(LoopIndex = 0; LoopIndex <MAX_ACLed_Num; LoopIndex ++)
	//{
		///*Init LEDs Direcion*/
		//ACParam.Mask = 1 << AC_ConfigParam[LoopIndex].ACPin;
		//ACParam.PortName = AC_ConfigParam[LoopIndex].ACPort;
		//GPIO_Init(&ACParam);
		///*Turn off all leds*/
		//ACWrtParam.Data = AC_ConfigParam[LoopIndex].ACConnection;
		//ACWrtParam.Mask = 	1 << AC_ConfigParam[LoopIndex].ACPin;
		//ACWrtParam.PortName = 	AC_ConfigParam[LoopIndex].ACPort;
		//GPIO_Write(&ACWrtParam);
	//}
	//
//}
//unsigned char SimulLed_AC_Writ(unsigned long int AC_id,AC_DataType data)
//{
	//unsigned char FunState ;
	//GPIO_WriteType ACWrtParam;
	//if(AC_id < MAX_ACLed_Num)
	//{
		//ACWrtParam.PortName = AC_ConfigParam[AC_id].ACPort;
		//ACWrtParam.Mask = 1 << AC_ConfigParam[AC_id].ACPin;
		//ACWrtParam.Data = data ^ AC_ConfigParam[AC_id].ACConnection;
//
		//GPIO_Write(&ACWrtParam);
		//FunState = 1;
	//}
	//else
	//{
		//FunState = 0;
	//}
	//return FunState;
//}