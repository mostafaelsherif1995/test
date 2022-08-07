///*
 //* BTN.c
 //*
 //* Created: 8/30/2016 9:24:00 PM
 //*  Author: mostafa
 //*/
//#include "GPIO.h"
//#include "BTN.h"
//#include "BTN_Cfg.h" 
//extern const BTN_ConfigType BTN_ConfigParam[BTN_MAX_NUM];
//static BTN_StateType BtnState[BTN_MAX_NUM];
//void BTN_Init(void)
//{
	//unsigned long int LoopIndex;
	//GPIO_InitType BtnParam;
		  //BtnParam.Direction = 0x00;
	//for(LoopIndex=0; LoopIndex < BTN_MAX_NUM; LoopIndex++){
	 //
		//BtnParam.IsPullupUsed = BTN_ConfigParam[LoopIndex].BtnConnection;
		//BtnParam.Mask = 1 << BTN_ConfigParam[LoopIndex].BtnPin;
		//BtnParam.PortName = BTN_ConfigParam[LoopIndex].BtnPort;
		//GPIO_Init(&BtnParam);
		//BtnState[LoopIndex] = BTN_OFF;
	//}
//}
//unsigned char BTN_GetState(unsigned long int BtnId,BTN_StateType*  BtnStatePtr)
//{
	//unsigned char FunStat;
	//GPIO_ReadType  BtnParam;
	//unsigned char BtnRead=0;
	//
	//if(BtnId < BTN_MAX_NUM){
		//BtnParam.PortName=BTN_ConfigParam[BtnId].BtnPort;
		//BtnParam.Mask= 1  << BTN_ConfigParam[BtnId].BtnPin;
          //BtnRead= GPIO_Read(&BtnParam);
   //if((BtnRead!=0)&&(BtnState[BtnId])== BTN_OFF){
						//*BtnStatePtr=BTN_JUST_PRESSED;
						             //}
	 //if((BtnRead!=0)&& BtnState[BtnId]==BTN_JUST_PRESSED){
						//*BtnStatePtr=BTN_ON;
						//
	//}		
 //if(BtnRead==0&& BtnState[BtnId]==BTN_ON){  
				  //
                         //*BtnStatePtr=BTN_JUST_RELEASED;
	//
	                         //}                           
					//
 //if(BtnRead==0&&BtnState[BtnId]== BTN_JUST_RELEASED){
			//*BtnStatePtr=BTN_OFF;
						//
					  //}
					  		//
	  //else{}//else to make program good
		//
	//FunStat=1;	
	//}	
	//else{
		//FunStat=0;
	//}
	//
	//BtnState[BtnId]=*BtnStatePtr;
	//return FunStat;
//}