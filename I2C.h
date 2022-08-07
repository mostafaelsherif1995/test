
#ifndef I2C_H_
#define I2C_H_
 #include "standio.h"
/*#define TW_STATUS_MASK  (1<<TWS4)|(1<<TWS3)|(1<<TWS3)|(1<<TWS1)|(1<<TWS0)
#define TW_STATUS		(TWSR & TW_STATUS_MASK)


//MASTER MODE
#define MAX_TRIES 50
  //   #define I2C_START 0
  //   #define I2C_DATA 1
  //   #define I2C_DATA_ACK 2
  //   #define I2C_STOP 3
  //   #define ACK 1
  //   #define NACK 0
  //     
  //     //functio use in master mode
  //     void i2c_init(u32 scl_frequency,u32 clock);     //to initialize scl and prescaler
  //     
  //     u8 i2c_write(char data);                       //to send data byte
  //     u8 i2c_start( u16 dev_addr, u8 rw_type);      //to send start condition and stat read or writ type
  //     void i2c_stop(void);                         //to send stop condition
  //    
  //    
  //     void SendData_I2C(u8 device_adress,u8 ID_type,u8 data) ;   // to send datat with id_type
  //     
  //     
  //     void Send_TempData_I2C(u8 device_adress,u8 ID_type,u8 Room_id,u8 valueinteg,u8 valuefract);   //to send temp values  
  //     
  //     
  //      void Send_RGBLightData_I2C(u8 device_adress,u8 ID_type,u8 Room_id,u8 Red_value,u8 green_value,u8 blue_value);  //to send rgp value
  //      
  //      
  //      void Send_senseData_I2C(u8 device_adress,u8 ID_type,u8 Room_id,u8 sense_value); // to send value of sense with room id
  //     
  //     
  //     
  //     
  //     
  //     u16 ReciveData_I2C(u8 device_adress,u8 ID_type);                
  //     u16 DeviceRead_I2C(u8 device_adress,u8 reg_addr);                //to read data  
  //     void DeviceWrite_I2C(u8 device_adress,u8 reg_addr,u16 data);      //to writ data
  //     void SlaveMode_init(u32 Selve_addre);
  //   ///////////////////////////////////
  //   ////////////////////////////////
  //   ///////////////////
  //  void TWI_init_slave(u16 Owen_Addr) ;
  //  u8  TWI_read_slave(void);
  //  
  //  */
#define TW_START	    	0x08
#define TW_REP_START		0x10
#define TW_MT_SLA_ACK		0x18
#define TW_MT_SLA_NACK		0x20
#define TW_MT_DATA_ACK		0x28
#define TW_MT_DATA_NACK		0x30
#define TW_MT_ARB_LOST		0x38
#define TW_MR_ARB_LOST		0x38
#define TW_MR_SLA_ACK		0x40
#define TW_MR_SLA_NACK		0x48
#define TW_MR_DATA_ACK		0x50
#define TW_MR_DATA_NACK		0x58
#define TW_ST_SLA_ACK		0xA8
#define TW_ST_ARB_LOST_SLA_ACK	0xB0
#define TW_ST_DATA_ACK		0xB8
#define TW_ST_DATA_NACK		0xC0
#define TW_ST_LAST_DATA		0xC8
#define TW_SR_SLA_ACK		0x60
#define TW_SR_ARB_LOST_SLA_ACK	0x68
#define TW_SR_GCALL_ACK		0x70
#define TW_SR_ARB_LOST_GCALL_ACK 0x78
#define TW_SR_DATA_ACK		0x80
#define TW_SR_DATA_NACK		0x88
#define TW_SR_GCALL_DATA_ACK	0x90
#define TW_SR_GCALL_DATA_NACK	0x98
#define TW_SR_STOP		0xA0
#define TW_NO_INFO		0xF8
#define TW_BUS_ERROR		0x00
#define TW_READ		1
#define TW_WRITE	0
     
                    
   void TWI_Init (double scl);

    void TWI_Start (void);

    void TWI_Stop (void);

    void TWI_Write (char data);

    void TWI_Read_Nack (char* ptr);

    void EEPROM_Write (char data, char address);

    void EEPROM_Read (char address, char* ptr);
                
     
                    
     
                    
     
     
                    
     #endif