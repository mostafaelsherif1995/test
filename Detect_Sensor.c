//
//
///*
 //* Detect_Sensor.c
 //*
 //* Created: 16/10/2016 04:33:01 ص
 //*  Author: LENOVO
 //*/ 
//#include "Detect_Sensor.h"
//extern const DetSens_ConfigType  DetSens_ConigParam[Max_Num_DetectSensor];
//void DetectSens_init(void){
	//GPIO_InitType Gpio_initparam;
	//u32 loopindex;
	//Gpio_initparam.Direction=0x00; 
	//
	//for(loopindex=0;loopindex<Max_Num_DetectSensor;loopindex++){
		//Gpio_initparam.PortName=DetSens_ConigParam[loopindex].DetecSensPort;
		//Gpio_initparam.Mask=1<<DetSens_ConigParam[loopindex].DetectSensPin;
		//Gpio_initparam.IsPullupUsed=DetSens_ConigParam[loopindex].DetectConnection;
		//GPIO_Init(&Gpio_initparam);
		//
	//}
	//
//}
//u32 DetectSens_Read(u32 Detectsens_id,u8 *Detect_value){
	//GPIO_ReadType Gpio_ReadParam;
	//u8 FunStat;
	//u8 ReadValue;
	//if(Detectsens_id<Max_Num_DetectSensor){
		//Gpio_ReadParam.PortName=DetSens_ConigParam[Detectsens_id].DetecSensPort;
		//Gpio_ReadParam.Mask = (1<<(DetSens_ConigParam[Detectsens_id].DetectSensPin));
		//ReadValue=GPIO_Read(&Gpio_ReadParam);
		//FunStat=1;
	//}
	//else{
		//
		//FunStat=0;
	//}
	//*Detect_value=(ReadValue>>DetSens_ConigParam[Detectsens_id].DetectSensPin);
	//return FunStat;
//}