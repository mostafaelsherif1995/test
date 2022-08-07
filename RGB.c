//
///*
 //* RGB.c
 //*
 //* Created: 28/10/2016 12:43:06 م
 //*  Author: LENOVO
 //*/ 
//#include "RGB.h"
//extern const RGB_ConfigType RGB_ConfigParam[MAX_RGB_NUM];
//void Init_RGB(void){
	//
//unsigned long int LoopIndex;
//GPIO_InitType RGBParam;
//GPIO_WriteType RGBWrtParam;
//RGBParam.Direction = 0xff;
//RGBParam.IsPullupUsed = 0x00;
//for(LoopIndex = 0; LoopIndex <MAX_RGB_NUM; LoopIndex ++)
//{
	///*Init LEDs Direcion*/
	//RGBParam.Mask = 7 << RGB_ConfigParam[LoopIndex].RGBPin;
	//
	//RGBParam.PortName = RGB_ConfigParam[LoopIndex].RGBPort;
	//GPIO_Init(&RGBParam);
	///*Turn off all leds*/
	//RGBWrtParam.Data = RGB_ConfigParam[LoopIndex].RGBConnection;
	//RGBWrtParam.Mask = 	7<< RGB_ConfigParam[LoopIndex].RGBPin;
	//RGBWrtParam.PortName = 	RGB_ConfigParam[LoopIndex].RGBPort;
	//GPIO_Write(&RGBWrtParam);
//}	
	//
	//
	//
//}
////AUTO==RED;;;;;MANUAL_ON==GREEN;;;;;;MANUAL_OFF==BLUE;;;;;;
//unsigned char RGB_Writ(unsigned long int RGB_id,unsigned char R_value,unsigned char G_value,unsigned char B_value){
	//unsigned char FunState ;
	//GPIO_WriteType RGBWrtParam;
	//if(R_value){
		//R_value=0xff;
	//}
	//else {
	//R_value	=0x00;
	//}
	//if(G_value){
		//G_value=0xff;
	//}
	//else{
	//G_value	=0x00;
	//}
	//if(B_value){
	//B_value=0xff;	
	//}
	//else{
	//B_value=0x00;	
	//}
	//if(RGB_id < MAX_RGB_NUM)
	//{
		//RGBWrtParam.PortName = RGB_ConfigParam[RGB_id].RGBPort;
		//RGBWrtParam.Mask = 1<< RGB_ConfigParam[RGB_id].RGBPin;
		//
		//RGBWrtParam.Data =R_value ^ RGB_ConfigParam[RGB_id].RGBConnection;           
       //
		//GPIO_Write(&RGBWrtParam);
		//
		//RGBWrtParam.PortName = RGB_ConfigParam[RGB_id].RGBPort;
		//RGBWrtParam.Mask = 2<< RGB_ConfigParam[RGB_id].RGBPin;
		//
		//RGBWrtParam.Data =G_value ^ RGB_ConfigParam[RGB_id].RGBConnection;
		//
		//GPIO_Write(&RGBWrtParam);
		//
		//
		//RGBWrtParam.PortName = RGB_ConfigParam[RGB_id].RGBPort;
		//RGBWrtParam.Mask = 4<< RGB_ConfigParam[RGB_id].RGBPin;
		//
		//RGBWrtParam.Data =B_value ^ RGB_ConfigParam[RGB_id].RGBConnection;
		//
		//GPIO_Write(&RGBWrtParam);
		//
		//
		//FunState = 1;
	//}
	//else
	//{
		//FunState = 0;
	//}
	//return FunState;
	//
	//
//}
///*unsigned char RGB_Writ(unsigned long int RGB_id,unsigned char R_value,unsigned char G_value,unsigned char B_value){
	//unsigned char FunState ;
	//if( (R_value!=0) && (G_value==0) && (B_value==0) ){
		//RGB_setdata( RGB_id,AUTO);
		//FunState=1;
	//}
	//else if((R_value==0 )&& (G_value!=0) && (B_value==0)){
		//RGB_setdata( RGB_id,MANUAL_ON);
		//FunState=1;
	//}
	//else if((R_value==0 )&& (G_value==0) && (B_value!=0)){
		//RGB_setdata( RGB_id,MANUAL_OFF);
		//FunState=1;
	//}
	//else
	//{
		//FunState = 0;
	//}
	//return FunState;
	//
//}*/