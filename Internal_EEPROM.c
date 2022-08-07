///*
 //* INTER_EEPROM.c
 //*
 //* Created: 14/10/2016 05:29:54 م
 //*  Author: LENOVO
 //*/ 
//#include "Internal_EEPROM.h"
//
//void EEPROM_write(u16 uiAddress, u8 ucData) {
	///* Wait for completion of previous write */
	//while(EECR & (1<<EEWE))   ;
	///* Set up address and data registers */
	//EEARL = uiAddress;
	//EEDR = ucData;
	///* Write logical one to EEMWE */
	//EECR |= (1<<EEMWE);
	///* Start eeprom write by setting EEWE */
	//EECR |= (1<<EEWE);
//}
//u8 EEPROM_read(u16 uiAddress) {
	///* Wait for completion of previous write */
	//while(EECR & (1<<EEWE))   ;
	///* Set up address register */
	//EEARL = uiAddress;
	///* Start eeprom read by writing EERE */
	//EECR |= (1<<EERE);
	///* Return data from data register */
	//return EEDR;
//}
//void EEPROM_Writ_Array(u16* Array,u16 uiAddress,u32 lenth){
	//u32 loopindex=0;
	//for(loopindex=0;loopindex<lenth;loopindex++){
	//EEPROM_write(uiAddress,Array[loopindex]);	
	//}
//}
//void EEPROM_Read_Array(u16* Array,u16 uiAddress,u32 lenth){
	//u32 loopindex=0;
	//for(loopindex=0;loopindex<lenth;loopindex++){
		//Array[loopindex]=EEPROM_read(uiAddress);
	//}
	//
//}