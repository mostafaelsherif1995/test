//
///*
 //* Light_Sensor.c
 //*
 //* Created: 16/10/2016 04:39:45 ص
 //*  Author: LENOVO
 //*/ 
//#include "Light_Sensor.h"
//extern const LightSens_ConfigType  LightSens_ConigParam[Max_Num_LightSensor];
//void LightSens_init(void){
	//GPIO_InitType Gpio_initparam;
	//u32 loopindex;
	//Gpio_initparam.Direction=0x00;
	//
	//for(loopindex=0;loopindex<Max_Num_LightSensor;loopindex++){
		//Gpio_initparam.IsPullupUsed=LightSens_ConigParam[loopindex].lightconnection;
		//Gpio_initparam.PortName=LightSens_ConigParam[loopindex].LightSens_Port;
		//Gpio_initparam.Mask=(1<<(LightSens_ConigParam[loopindex].LightSens_Pin));
		//GPIO_Init(&Gpio_initparam);
		//
		//
	//}
	//
//}
//u32 LightSens_Read(u32 LightSens_id,u8 *LightSens_value){
	//GPIO_ReadType Gpio_ReadParam;
	//u8 FunStat;
	//u8 ReadValue;
	//if(LightSens_id<Max_Num_LightSensor){
		//Gpio_ReadParam.PortName=LightSens_ConigParam[LightSens_id].LightSens_Port;
		//Gpio_ReadParam.Mask = (1<<(LightSens_ConigParam[LightSens_id].LightSens_Pin));
		//ReadValue=GPIO_Read(&Gpio_ReadParam);
		//FunStat=1;
	//}
	//else{
		//
		//FunStat=0;
	//}
	//*LightSens_value=ReadValue;
	//return FunStat;
//}