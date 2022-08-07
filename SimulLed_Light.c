//
///*
 //* SimulLed_Light.c
 //*
 //* Created: 28/10/2016 12:40:36 م
 //*  Author: LENOVO
 //*/ 
//#include "SimulLed_Light.h"
//extern const Light_ConfigType  Light_ConfigParam[MAX_LightLed_NUM];
//void Init_SimulLed_Light(void)
//{
	//unsigned long int LoopIndex;
	//GPIO_InitType LightParam;
	//GPIO_WriteType LightWrtParam;
	//LightParam.Direction = 0xff;
	//LightParam.IsPullupUsed = 0x00;
	//for(LoopIndex = 0; LoopIndex <MAX_LightLed_NUM; LoopIndex ++)
	//{
		///*Init LEDs Direcion*/
		//LightParam.Mask = 1 << Light_ConfigParam[LoopIndex].LightPin;
		//LightParam.PortName = Light_ConfigParam[LoopIndex].LightPort;
		//GPIO_Init(&LightParam);
		///*Turn off all leds*/
		//LightWrtParam.Data = Light_ConfigParam[LoopIndex].LightConnection;
		//LightWrtParam.Mask = 	1 << Light_ConfigParam[LoopIndex].LightPin;
		//LightWrtParam.PortName = 	Light_ConfigParam[LoopIndex].LightPort;
		//GPIO_Write(&LightWrtParam);
	//}
	//
//}
//unsigned char SimulLed_Light_Writ(unsigned long int Light_id,Light_DataType data)
//{
	//unsigned char FunState ;
	//GPIO_WriteType LightWrtParam;
	//if(Light_id < MAX_LightLed_NUM)
	//{
		//LightWrtParam.PortName = Light_ConfigParam[Light_id].LightPort;
		//LightWrtParam.Mask = 1 << Light_ConfigParam[Light_id].LightPin;
		//LightWrtParam.Data = data ^ Light_ConfigParam[Light_id].LightConnection;
//
		//GPIO_Write(&LightWrtParam);
		//FunState = 1;
	//}
	//else
	//{
		//FunState = 0;
	//}
	//return FunState;
//}