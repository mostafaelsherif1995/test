//
///*
 //* SEV.c
 //*
 //* Created: 01/09/2016 02:57:36 ص
 //*  Author: mostafa
 //*/ 
//#include "GPIO.h"
//#include "SEV_CFG.h"
//#include "SEV.h"
//extern const SEV_ConfigType SEV_ConfigParam[SEV_MAX_NUM];
//void Sev_Init(void){
	//unsigned char LoopIndex;
	//unsigned char LoopPinIndex;
	//GPIO_InitType SevParam;
	//GPIO_WriteType SevWrParam;
    //SevParam.IsPullupUsed = 0x00;
	//SevParam.Direction = 0xff;
	//for(LoopIndex = 0; LoopIndex < SEV_MAX_NUM; LoopIndex ++)
	//{
		//
		//for(LoopPinIndex=0;LoopPinIndex<7;LoopPinIndex++){//for seven pin seg
		//SevParam.Mask = 1 << SEV_ConfigParam[LoopIndex].SevPin[LoopPinIndex];
		//SevParam.PortName = SEV_ConfigParam[LoopIndex].SevPort[LoopPinIndex];
		//SevParam.IsPullupUsed = 0x00;
		//SevParam.Direction = 0xff;
		//GPIO_Init(&SevParam);
		//}
		//
//
		//
		//for(LoopPinIndex=0;LoopPinIndex<7;LoopPinIndex++){
			//SevWrParam.PortName = 	SEV_ConfigParam[LoopIndex].SevPort[LoopPinIndex];
	    //SevWrParam.Mask = 	1 << SEV_ConfigParam[LoopIndex].SevPin[LoopPinIndex];
		//SevWrParam.Data = SEV_ConfigParam[LoopIndex].SevConection;
		//GPIO_Write(&SevWrParam);}
	//}
	//
//}
//unsigned char Sev_Disply(unsigned int SevId,unsigned char DispParam){
	//
	//unsigned char FunState ;
	//GPIO_WriteType SevParam;
	//Sev_DataType Num_Trans[7];
	//unsigned char LoopPinIndex;
	//if(SevId < SEV_MAX_NUM)
	//{
		//Fun_transfer_number(DispParam,Num_Trans);
		//
		//for(LoopPinIndex=0;LoopPinIndex<7;LoopPinIndex++){
			//SevParam.PortName = SEV_ConfigParam[SevId].SevPort[LoopPinIndex];//to make generic in port 
		//SevParam.Mask = 1 << SEV_ConfigParam[SevId].SevPin[LoopPinIndex];
		//
		//SevParam.Data = Num_Trans[LoopPinIndex]^ SEV_ConfigParam[SevId].SevConection;
		//
//
		//GPIO_Write(&SevParam);
		//}
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
//void  Fun_transfer_number(unsigned char  Number,Sev_DataType* Num_Trans){
	//
//
	//switch(Number){
		//case 0:{
			//
		//Num_Trans[0]= on;
		//Num_Trans[1]=  on;
		//Num_Trans[2]= on;
		//Num_Trans[3]= on;
		//Num_Trans[4]= on;
		//Num_Trans[5]= on;
		//Num_Trans[6]= off;
			//
		//}
		//break;
		//case 1:{
				//Num_Trans[0]= off;
				//Num_Trans[1]= on;
				//Num_Trans[2]= on;
				//Num_Trans[3]= off;
				//Num_Trans[4]= off;
				//Num_Trans[5]= off;
				//Num_Trans[6]= off;
				//
		//
		//
		//}
		//break;
		//case 2:{
			//
			//
				//Num_Trans[0]= on;
				//Num_Trans[1]= on;
				//Num_Trans[2]= off;
				//Num_Trans[3]= on;
				//Num_Trans[4]= on;
				//Num_Trans[5]= off;
				//Num_Trans[6]= on;
				//
		//}
		//break;
		//case 3:{
		//
				//Num_Trans[0]= on;
				//Num_Trans[1]= on;
				//Num_Trans[2]= on;
				//Num_Trans[3]= on;
				//Num_Trans[4]= off;
				//Num_Trans[5]= off;
				//Num_Trans[6]= on;
				//
		//}
		//break;
		//case 4:{
		//
				//Num_Trans[0]= off;
				//Num_Trans[1]= on;
				//Num_Trans[2]= on;
				//Num_Trans[3]= off;
				//Num_Trans[4]= off;
				//Num_Trans[5]= on;
				//Num_Trans[6]= on;
				//
			//
		//}
		//break;
		//case 5:{
			//
			////1101101;
			//Num_Trans[0]= on;
			//Num_Trans[1]= off;
			//Num_Trans[2]= on;
			//Num_Trans[3]= on;
			//Num_Trans[4]= off;
			//Num_Trans[5]= on;
			//Num_Trans[6]= on;
			//
			//
		//}
		//break;
		//case 6:{
			//
			////1111101;
			//Num_Trans[0]= on;
			//Num_Trans[1]= off;
			//Num_Trans[2]= on;
			//Num_Trans[3]= on;
			//Num_Trans[4]= on;
			//Num_Trans[5]=on;
			//Num_Trans[6]= on;
			//
			//
		//}
		//break;
		//case 7:{
			//
			////0000111;
			//Num_Trans[0]= on;
			//Num_Trans[1]= on;
			//Num_Trans[2]= on;
			//Num_Trans[3]= off;
			//Num_Trans[4]= off;
			//Num_Trans[5]= off;
			//Num_Trans[6]= off;
			//
			//
		//}
		//break;
		//case 8:{
			//
			////1111111;
			//Num_Trans[0]= on;
			//Num_Trans[1]= on;
			//Num_Trans[2]= on;
			//Num_Trans[3]= on;
			//Num_Trans[4]= on;
			//Num_Trans[5]= on;
			//Num_Trans[6]= on;
			//
			//
		//}
		//break;
		//case 9:{
			//
			////1101111;
			//Num_Trans[0]= on;
			//Num_Trans[1]= on;
			//Num_Trans[2]= on;
			//Num_Trans[3]= on;
			//Num_Trans[4]= off;
			//Num_Trans[5]= on;
			//Num_Trans[6]= on;
			//
		//}
		//break;
		//default:{
			////error
		//}
		//break;
		//
	//}
	//
	//
//}