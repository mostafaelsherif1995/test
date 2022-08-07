// 
// /*
//  * I2C.c
//  *
//  * Created: 29/10/2016 02:07:51 م
//  *  Author: LENOVO
//  */ 
// 
// 
 #include "I2C.h"
 #define get_bit(reg,bitnum) ((reg & (1<<bitnum))>>bitnum) // get bit macro used to get the value of a certain bit.
#include <math.h>
 #include <avr/io.h>

 #include <util/delay.h>
 #include "LCD.h"
#define F_CPU 8000000ul




 
 //:::master mode functions:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
 /*static u8 i2c_transmit(u8 type);
 u8 i2c_start( u16 dev_addr, u8 rw_type);
 
 
 u8 i2c_transmit(u8 type) {
 	switch(type) {
 		case I2C_START:    // Send Start Condition
 		TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
 		break;
 		case I2C_DATA:     // Send Data with No-Acknowledge
 		TWCR = (1 << TWINT) | (1 << TWEN);
 		break;
 		case I2C_DATA_ACK: // Send Data with Acknowledge
 		TWCR = (1 << TWEA) | (1 << TWINT) | (1 << TWEN);
 		break;
 		case I2C_STOP:     // Send Stop Condition
 		TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
 		return 0;
 	}
 
 	 Wait for TWINT flag set on Register TWCR
 	while (!(TWCR & (1 << TWINT)));
 
 	 Return TWI Status Register, mask the prescaler bits (TWPS1,TWPS0)
 	return (TWSR & 0xF8);
 }
 u8 i2c_start( u16 dev_addr, u8 rw_type)
 {
 	u8  n = 0;
 	u8   twi_status;
 	u8 r_val = -1;
 
 	Loop:
 	if (n++ >= MAX_TRIES) return r_val;
 
 	 Transmit Start Condition
 	twi_status=i2c_transmit(I2C_START);
 
 	 Check the TWI Status
 	if (twi_status == TW_MT_ARB_LOST) goto Loop;
 	if ((twi_status != TW_START) && (twi_status != TW_REP_START)) goto Loop_quit;
 
 	 Send slave address (SLA_W)
 	TWDR =  (dev_addr & 0xFE) | rw_type;
 
 	 Transmit I2C Data
 	twi_status=i2c_transmit(I2C_DATA);
 
 	 Check the TWSR status
 	if ((twi_status == TW_MT_SLA_NACK) || (twi_status == TW_MT_ARB_LOST)) goto Loop;
 	if (twi_status != TW_MT_SLA_ACK) goto Loop_quit;
 
 	r_val=0;
 
 	Loop_quit:
 	return r_val;
 }
 void i2c_stop(void)
 {
 	unsigned char twi_status;
 
 	 Transmit I2C Data
 	twi_status=i2c_transmit(I2C_STOP);
 }
 u8 i2c_write(char data)
 {
 	unsigned char twi_status;
 	char r_val = -1;
 
 	 Send the Data to I2C Bus
 	TWDR = data;
 
 	 Transmit I2C Data
 	twi_status=i2c_transmit(I2C_DATA);
 
 	 Check the TWSR status
 	if (twi_status != TW_MT_DATA_ACK) goto LooP_quit;
 
 	r_val=0;
 
 	LooP_quit:
 	return r_val;
 }
 u8 i2c_read(char *data,char ack_type)
 {
 	unsigned char twi_status;
 	char r_val = -1;
 
 	if (ack_type) {
 		 Read I2C Data and Send Acknowledge
 		twi_status=i2c_transmit(I2C_DATA_ACK);
 
 		if (twi_status != TW_MR_DATA_ACK) goto LooP_quit;
 	} else {
 		 Read I2C Data and Send No Acknowledge
 		twi_status=i2c_transmit(I2C_DATA);
 
 		if (twi_status != TW_MR_DATA_NACK) goto LooP_quit;
 	}
 
 	 Get the Data
 	*data=TWDR;
 	r_val=0;
 
 	LooP_quit:
 	return r_val;
 }
 void DviceWrite_I2C(u8 device_adress,u8 reg_addr,u16 data)
 {
 	 Start the I2C Write Transmission
 	i2c_start(device_adress,TW_WRITE);
 
 	 Sending the Register Address
 	i2c_write(reg_addr);
 
 	 Write data to MCP23008 Register
 	i2c_write(data);
 
 	 Stop I2C Transmission
 	i2c_stop();
 }
 void SendData_I2C(u8 device_adress,u8 ID_type,u8 data)
 {
 	 Start the I2C Write Transmission
 	i2c_start(device_adress,TW_WRITE);
 
 	 Sending the Register Address
 	i2c_write(ID_type);
 
 	 Write data to MCP23008 Register
 	i2c_write(data);
 
 	 Stop I2C Transmission
 	i2c_stop();
 }
 void Send_TempData_I2C(u8 device_adress,u8 ID_type,u8 Room_id,u8 valueinteg,u8 valuefract)
 {
 	 Start the I2C Write Transmission
 	i2c_start(device_adress,TW_WRITE);
 
 	 Sending the Register Address
 	i2c_write(ID_type);
 
 	 Write data to MCP23008 Register
 	i2c_write(Room_id);
 	i2c_write(valueinteg);
 	i2c_write(valuefract);
 
 	 Stop I2C Transmission
 	i2c_stop();
 }
 void Send_RGBLightData_I2C(u8 device_adress,u8 ID_type,u8 Room_id,u8 Red_value,u8 green_value,u8 blue_value)
 {
 	 Start the I2C Write Transmission
 	i2c_start(device_adress,TW_WRITE);
 
 	 Sending the Register Address
 	i2c_write(ID_type);
 
 	 Write data to MCP23008 Register
 	i2c_write(Room_id);
 	i2c_write(Red_value);
 	i2c_write(green_value);
 	i2c_write(blue_value);
 
 	 Stop I2C Transmission
 	i2c_stop();
 }
 void Send_senseData_I2C(u8 device_adress,u8 ID_type,u8 Room_id,u8 sense_value)
 {
 	 Start the I2C Write Transmission
 	i2c_start(device_adress,TW_WRITE);
 
 	 Sending the Register Address
 	i2c_write(ID_type);
 
 	 Write data to MCP23008 Register
 	i2c_write(Room_id);
 	i2c_write(sense_value);
 	
 
 	 Stop I2C Transmission
 	i2c_stop();
 }
 
 u16 DeviceRead_I2C(u8 device_adress,u8 reg_addr)
 {
 	char data;
 
 	 Start the I2C Write Transmission
 	i2c_start(device_adress,TW_WRITE);
 
 	 Read data from device Register Address
 	i2c_write(reg_addr);
 
 	 Stop I2C Transmission
 	i2c_stop();
 
 	 Re-Start the I2C Read Transmission
 	i2c_start(device_adress,TW_READ);
 
 	i2c_read(&data,NACK);
 
 	 Stop I2C Transmission
 	i2c_stop();
 
 	return data;
 }
 u16 ReciveData_I2C(u8 device_adress,u8 ID_type)
 {
 	char data;
 
 	 Start the I2C Write Transmission
 	i2c_start(device_adress,TW_WRITE);
 
 	 Read data from device Register Address
 	i2c_write(ID_type);
 
 	 Stop I2C Transmission
 	i2c_stop();
 
 	 Re-Start the I2C Read Transmission
 	i2c_start(device_adress,TW_READ);
 
 	i2c_read(&data,NACK);
 
 	 Stop I2C Transmission
 	i2c_stop();
 
 	return data;
 }
 void i2c_init(u32 scl_frequency,u32 clock)
 {
 	unsigned int twi_value;
 	 Initial ATMega328P TWI/I2C Peripheral
 	TWSR = 0x02;         // Select Prescaler of  _16
 
 	twi_value = ((clock/ scl_frequency)-16)/(2*16);
 	TWBR = (twi_value<<0) ;
 }
 //:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
 //::::::::::::::::::slave:::::::::::::::::::::::::mode:::::::::::::::::::::::::::
 void SlaveMode_init(u32 Selve_addre){
 	TWCR=(1<<TWEA)|(1<<TWEN)|(1<<TWIE); //ack_interrupt_twi
 	TWCR = 0x45;
 	TWAR=(Selve_addre<<1);
 	TWAR=(0<<TWGCE);  //not enable global calling
 }
 ISR(TWI_vect){
 	switch(TW_STATUS) {
 		case TW_SR_SLA_ACK: // slave addressed
 		break;
 		case TW_SR_DATA_ACK: // data received
 		## اعمل اللى انت عايزه هنا<>
 		break;
 		case TW_SR_STOP: // STOP or REPEATED START condition
 		break;
 		default: // ?? unknown status (error?)
 		break;
 	}
 
 	TWCR=(1<<TWINT); // clear TWINT bit
 }
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 ///////////////////////////////////////////
 ///////////////////////////////////////////////////////////////////////////////
 /////////////another function for use slave mode reciver
 void TWI_init_slave(u16 Owen_Addr) // Function to initilaize slave
 {
 	TWAR=Owen_Addr;    // Fill slave address to TWAR
 }
 static void TWI_match_read_slave(void) //Function to match the slave address and slave dirction bit(read)
 {
 	while((TWSR & 0xF8)!= 0x60)  // Loop till correct acknoledgement have been received
 	{
 		 Get acknowlegement, Enable TWI, Clear TWI interrupt flag
 		TWCR=(1<<TWEA)|(1<<TWEN)|(1<<TWINT);
 		while (!(TWCR & (1<<TWINT)));  // Wait for TWINT flag
 	}
 }
 u8  TWI_read_slave(void)
 {
 	int recv_data;
 	TWI_match_read_slave();
 	// Clear TWI interrupt flag,Get acknowlegement, Enable TWI
 	TWCR= (1<<TWINT)|(1<<TWEA)|(1<<TWEN);
 	while (!(TWCR & (1<<TWINT)));    // Wait for TWINT flag
 	while((TWSR & 0xF8)!=0x80);        // Wait for acknowledgement
 	recv_data=TWDR;                    // Get value from TWDR
 	return recv_data;                // send the receive value on PORTB
 }*/
 /*
 void ERROR(){
 	
 }
 void TWI_Init(u32 clock){
 	TWCR|=(1<<TWEN);
 	TWSR = 0x00;  //presc 1
 	clock = ((8000000/ clock)-16)/(2*1);
 	TWBR=0x07;//clock;
 	
 }
 u8 TWI_Start(void){
 	u8 x=1;
 	TWCR |= (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
 	while(!(TWCR &(1<<TWINT)));
 	//if ((TWSR & 0xF8) !=TW_START)
 	//x=0;//ERROR();
 	return x;
 }
 u8 TWI_ReStart(void){
 	
 }
 u8 TWI_Stop(void){
 	TWCR |= (1<<TWINT)|	(1<<TWEN)|(1<<TWSTO);
 }
 u8 TWI_SLA_WR(u8 slave_writ,u8 stat){
 	u8 x=1;
 	if(stat==TW_WRITE){
 		TWDR|=(TW_WRITE<<0);
 	TWDR |= (slave_writ<<1);
 	TWCR |= (1<<TWINT)|(1<<TWEN);
 	while(!(TWCR &(1<<TWINT)));
 	if ((TWSR & 0xF8) !=TW_MT_SLA_ACK)
 	//ERROR();
 	x=0;
 	}
 	else if(stat=TW_READ){
 		TWDR|=(TW_READ<<0);
 		TWDR |= (slave_writ<<1);
 		TWCR |= (1<<TWINT)|(1<<TWEN);
 		while(!(TWCR &(1<<TWINT)));
 		if ((TWSR & 0xF8) !=TW_MR_SLA_ACK)
 		//ERROR();
 		x=0;
 	}
 	else{}
 		return x;
 }
 u8 TWI_Write(u8 byte){
 	u8 x=1;
 	TWDR=byte;
 	TWCR |= (1<<TWINT)|(1<<TWEN);
 	while(!(TWCR &(1<<TWINT)));
 	//if ((TWSR & 0xF8) !=TW_MT_DATA_ACK)
 	//x=0;//ERROR();
 	return x;
 }
 u8 WI_Read_With_NACK(u8 *byte){
 	
 	 TWCR=(1<<TWINT)|(1<<TWEN);
 	while(!(TWCR &(1<<TWINT)));
 	*byte=TWDR;	
 	
 }
 
 
 void EEPROM_Write (char data, char address){
 	 TWI_Start();
 
 	 TWI_Write(0xA8); //slave address is 1010.100 and a 0 in the 8th bit to indicate Writting.
 
 	 TWI_Write(address);
 
 	 TWI_Write(data);
 
 	 TWI_Stop();
 
 }
 void EEPROM_Read (char address, char* ptr){
 	 TWI_Start();
 
 	 TWI_Write(0xA8);
 
 	 TWI_Write(address);
 
 	 TWI_Start();
 
 	 TWI_Write(0xA9);
 
 	 WI_Read_With_NACK(ptr);
 
 	 TWI_Stop();
 
 }
*/
 void TWI_Init (double scl)

 {
  u32 TWB_value=266;
	 //set_bit(TWCR,6);
	
 u8 twps=0;
 

	 while((twps<5)&&(TWB_value>255)){
       TWB_value=(((double)F_CPU/scl)-16.0)/(2.0*((double)pow(4,twps)));
	   twps++;
	 
	 }	
	
	 
	 twps--;
	 TWSR&=~(3<<0);
	  TWSR|=(twps<<0);
	
	 
	 TWBR|=(TWB_value<<0);
	 
	 TWCR|=(1<<TWEN);

 }




 void TWI_Start (void)

 {

	 TWCR= (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);

	 while (get_bit(TWCR,TWINT)==0)

	 {

	 }

 }




 void TWI_Stop (void)

 {

	 TWCR=(1<<TWSTO)|(1<<TWEN)|(1<<TWINT);

 }




 void TWI_Write (char data)

 {

	 TWDR=data;

	 TWCR= (1<<TWINT)|(1<<TWEN);

	 while (get_bit(TWCR,TWINT)==0)

	 {

	 }

 }




 void TWI_Read_Nack (char* ptr) // The function argument is a pointer to a memory place in the MCU to store the received data in

 {

	 TWCR=(1<<TWINT)|(1<<TWEN);

	 while (get_bit(TWCR,TWINT)==0)

	 {

	 }

	 *ptr=TWDR;

 }




 void EEPROM_Write (char data, char address)

 {

	 TWI_Start();

	 TWI_Write(0xA8); //slave address is 1010.100 and a 0 in the 8th bit to indicate Writting.

	 TWI_Write(address);

	 TWI_Write(data);

	 TWI_Stop();

 }

 void EEPROM_Read (char address, char* ptr) // the function arguments are an address in the EEPROM to read from and a pointer to a memory place in the MCU to store the read data in

 {

	 TWI_Start();

	 TWI_Write(0xA8);

	 TWI_Write(address);

	 TWI_Start();

	 TWI_Write(0xA9);

	 TWI_Read_Nack(ptr);

	 TWI_Stop();




 }
