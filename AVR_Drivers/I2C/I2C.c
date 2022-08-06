/*
 * I2C.c
 *
 * Created: 1/05/2022 11:04 
 *  Author: Bahaa Tawfik
 */
	#include <avr/io.h>
	#include "std_macros.h"
	#include "I2C.h"
	#define F_CPU 8000000UL
	#define prescalar 1


/*     // Define bit rate 
#define BITRATE(TWSR)	((F_CPU/SCL_CLK)-16)/(2*pow(4,(TWSR&((1<<TWPS0)|(1<<TWPS1)))))
Now load this value in the TWBR register

void I2C_Init()			//  I2C initialize function 
{
    TWBR = BITRATE(TWSR=0x00);	//   Get bit rate register value by formula 
}
*/


/* Function Description : Initialize the I2C Communication as a Master and initialize the clock         */
	void I2C_Master_init(unsigned long SCL_Clock)
	{
		TWBR= (unsigned char) (((F_CPU/SCL_Clock)-16) / (2*prescalar));
		if (prescalar==1)
		{
			TWSR=0;
		}
		else if (prescalar==4)
		{
			TWSR=1;
		}
		else if (prescalar==16)
		{
			TWSR=2;
		}
		else if (prescalar==64)
		{
			TWSR=3;
		}
		
	}




/*	Function Description : Send start condition of I2C Communication          */
	
	void I2C_start(void)
	{
		// Clear TWI interrupt flag, Enable TWI, Put start condition on SDA
		TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
//wait to finish or use ...while(!(TWCR & (1<<TWINT) ) );... // Wait till start condition is transmitted
		while(ReadBit(TWCR,TWINT)==0); 
		while ((TWSR & 0XF8) != 0x08); // Check for the acknowledgement that start condition has been transmitted
	}


/*	Function Description : send repeated start condition the Address with read write condition           */
void I2C_RepeatedStart(uint_8 address_R_W)
{
		
// Clear TWI interrupt flag, Enable TWI, Put start condition on SDA
		TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
		while(!(TWCR & (1<<TWINT))); // Wait till start condition is transmitted
		while ((TWSR & 0XF8) != 0x10); // Check for the acknowledgement that REstart condition has been transmitted
	
}



/*	Function Description : Send the slave address, data direction bit (write) and wait for the ACK signal   */
	
	void I2C_write_address(unsigned char address)
	{
		TWDR=address;	// Address and read instruction
		TWCR=(1<<TWINT)|(1<<TWEN);	// Clear TWI interrupt flag,Enable TWI
		while(ReadBit(TWCR,TWINT)==0); //wait to finish .. or .. Wait till complete TWDR byte received
		while ((TWSR & 0XF8) != 0x18); // SLA+write has been transmitted and ACK has been received 
	}


/*	Function Description : Send Send the 8-bit data and wait for the ACK   */
	
	void I2C_write_data(unsigned char data)
	{
		TWDR=data;		// put data in TWDR
		TWCR=(1<<TWINT)|(1<<TWEN);	// Clear TWI interrupt flag,Enable TWI
		while(ReadBit(TWCR,TWINT)==0); //wait to finish .. or .. Wait till complete TWDR byte received
		while ((TWSR & 0XF8) != 0x28); // data has been transmitted and ACK has been received
	}
	

/*	Function Description : write address and read */

void I2C_write_address_and_read(unsigned char address)
{
	TWDR=address;
	// Clear TWI interrupt flag, Enable TWI, 
	TWCR=(1<<TWINT)|(1<<TWEN);
	while(ReadBit(TWCR,TWINT)==0));  // Wait till finish
	while ((TWSR & 0XF8) != 0x40); // own SLA+read has been transmitted and ACK has been received
	
}

/*	Function Description :  read with Non Acknowledge */
unsigned char I2C_read_with_NACK(void)
{
		// Clear TWI interrupt flag, Enable TWI,
		TWCR=(1<<TWINT)|(1<<TWEN);
		while(ReadBit(TWCR,TWINT)==0));  // Wait till finish
		while ((TWSR & 0XF8) != 0x58); //data byte has been received  and ACK has been returned
		return TWDR;
}


/*	Function Description : Send stop condition of I2C Communication   */
	void I2C_stop(void)
	{
// Clear TWI interrupt flag, Enable TWI, Put stop condition on SDA
		TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
		while(!(TWCR & (1<<TWSTO)));  // Wait till stop condition is transmitted
	}


/*	Function Description : Send slave address   */
	
	void I2C_set_Slaveaddress(unsigned char address)
	{
		TWAR=address;		// Address and read instruction
	}


/*	Function Description : read the TWDR*/
	unsigned char I2C_slave_read(void)
	{
		// Clear TWI interrupt flag, Enable TWI, Enable ACk
		TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
		while(ReadBit(TWCR,TWINT)==0);// Wait till complete TWDR byte transmitted
		while ((TWSR & 0XF8) != 0x60); // own SLA+W has been received and ACK has been returned (receive address)
		TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
		while(ReadBit(TWCR,TWINT)==0);
		while ((TWSR & 0XF8) != 0x80); // previously addressed with own SLA+W : data has been received : ACK has been returned (receive data)
		return TWDR ;
	}