//#ifndef INTERNAL_EEPROM_H_
//#define INTERNAL_EEPROM_H_
//
//
//#include "standio.h"
//
//
//#include <avr/eeprom.h>
//// defines for eeprom access
//#define read_eeprom_byte(address) eeprom_read_byte ((const uint8_t*)address)
//#define write_eeprom_byte(address,value) eeprom_write_byte ((uint8_t*)address,(uint8_t)value)
//#define read_eeprom_word(address) eeprom_read_word ((const uint16_t*)address)
//#define write_eeprom_word(address,value) eeprom_write_word ((uint16_t*)address,(uint16_t)value)
//#define read_eeprom_dword(address) eeprom_read_dword ((const uint32_t*)address)
//#define write_eeprom_dword(address,value) eeprom_write_dword ((uint32_t*)address,(uint32_t)value)
//#define read_eeprom_float(address) eeprom_read_float ((const float *)address)
//#define write_eeprom_float(address,value) eeprom_write_float ((float*)address,(float)value)
//#define read_eeprom_array(address,value_p,length) eeprom_read_block ((void *)value_p, (const void *)address, length)
//#define write_eeprom_array(address,value_p,length) eeprom_write_block ((const void *)value_p, (void *)address, length)
//
//
//
//
//
//void EEPROM_write(u16 uiAddress, u8 ucData);
//u8 EEPROM_read(u16 uiAddress);
//void EEPROM_Writ_Array(u16* Array,u16 uiAddress,u32 lenth);
//void EEPROM_Read_Array(u16* Array,u16 uiAddress,u32 lenth);
//#endif