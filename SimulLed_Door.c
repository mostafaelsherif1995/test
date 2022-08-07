//
///*
 //* SimulLed_Door.c
 //*
 //* Created: 28/10/2016 12:35:23 م
 //*  Author: LENOVO
 //*/ 
//#include "SimulLed_Door.h"
//extern const DOOR_ConfigType  Door_ConfigParam[MAX_DoorLed_Num];
//void Init_SimulLed_Door(void)
//{
	//unsigned long int LoopIndex;
	//GPIO_InitType DoorParam;
	//GPIO_WriteType DoorWrtParam;
	//DoorParam.Direction = 0xff;
	//DoorParam.IsPullupUsed = 0x00;
	//for(LoopIndex = 0; LoopIndex <MAX_DoorLed_Num; LoopIndex ++)
	//{
		///*Init LEDs Direcion*/
		//DoorParam.Mask = 1 << Door_ConfigParam[LoopIndex].DoorPin;
		//DoorParam.PortName = Door_ConfigParam[LoopIndex].DoorPort;
		//GPIO_Init(&DoorParam);
		///*Turn off all leds*/
		//DoorWrtParam.Data = Door_ConfigParam[LoopIndex].DoorConnection;
		//DoorWrtParam.Mask = 	1 << Door_ConfigParam[LoopIndex].DoorPin;
		//DoorWrtParam.PortName = 	Door_ConfigParam[LoopIndex].DoorPort;
		//GPIO_Write(&DoorWrtParam);
	//}
	//
//}
//unsigned char SimulLed_Door_Writ(unsigned long int Door_id,DOOR_DataType data)
//{
	//unsigned char FunState ;
	//GPIO_WriteType DoorWrtParam;
	//if(Door_id < MAX_DoorLed_Num)
	//{
		//DoorWrtParam.PortName = Door_ConfigParam[Door_id].DoorPort;
		//DoorWrtParam.Mask = 1 << Door_ConfigParam[Door_id].DoorPin;
		//DoorWrtParam.Data = data ^ Door_ConfigParam[Door_id].DoorConnection;
//
		//GPIO_Write(&DoorWrtParam);
		//FunState = 1;
	//}
	//else
	//{
		//FunState = 0;
	//}
	//return FunState;
//}