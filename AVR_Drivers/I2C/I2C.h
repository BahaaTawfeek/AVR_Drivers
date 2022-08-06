/*
 * I2C.h
 *
 * Created: 1/05/2022 11:04 
 *  Author: Bahaa Tawfik
 */

#ifndef I2C_H_
#define I2C_H_

/*********************************************************************************************************/
/*	Function Name        : I2C_Master_init								*/
/*	Function Returns     : void								   */
/*	Function Arguments   : unsigned long SCL_Clock    					  */
/*	Function Description : Initialize the I2C Communication as a Master and initialize the clock         */
/*********************************************************************************************************/

void I2C_Master_init(unsigned long SCL_Clock);


/*********************************************************************************************************/
/*	Function Name        : I2C_start*/
/*	Function Returns     : void									   */
/*	Function Arguments   : void    								          */
/*	Function Description : Send start condition of I2C Communication          */
/*********************************************************************************************************/
void I2C_start(void);


/*********************************************************************************************************/
/*	Function Name        : RepeatedStart*/
/*	Function Returns     : void				                   			     */
/*	Function Arguments   : unsigned char address_R_W   								                     */
/*	Function Description : send repeated start condition the Address with read write condition           */
/*********************************************************************************************************/
void I2C_RepeatedStart(uint_8 address_R_W);

/*********************************************************************************************************/
/*	Function Name        : I2C_write_address			*/
/*	Function Returns     : void									 */
/*	Function Arguments   : unsigned char address						 */
/*	Function Description : Send the slave address, data direction bit (write) and wait for the ACK signal   */
/*********************************************************************************************************/
void I2C_write_address(unsigned char address);

/*********************************************************************************************************/
/*	Function Name        : I2C_write_data			*/
/*	Function Returns     : void										 */
/*	Function Arguments   : unsigned char data						  */
/*	Function Description : Send Send the 8-bit data and wait for the ACK   */
/*********************************************************************************************************/
void I2C_write_data(unsigned char data);

/*********************************************************************************************************/
/*	Function Name        : I2C_write_address_and_read			*/
/*	Function Returns     : void									     */
/*	Function Arguments   : unsigned char address									          */
/*	Function Description : write address and read */
/*********************************************************************************************************/
void I2C_write_address_and_read(unsigned char address);


/*********************************************************************************************************/
/*	Function Name        : I2C_read_with_NACK			*/
/*	Function Returns     : unsigned char									     */
/*	Function Arguments   :  void								          */
/*	Function Description :  read with Non Acknowledge */
/*********************************************************************************************************/
unsigned char I2C_read_with_NACK(void);

/*********************************************************************************************************/
/*	Function Name        : I2C_stop			*/
/*	Function Returns     : void									     */
/*	Function Arguments   : void								          */
/*	Function Description : Send stop condition of I2C Communication   */
/*********************************************************************************************************/
void I2C_stop(void);



/*********************************************************************************************************/
/*	Function Name        : I2C_set_Slaveaddress*/
/*	Function Returns     : void							 */
/*	Function Arguments   : unsigned char address			*/
/*	Function Description : SeT slave address   */
/*********************************************************************************************************/
void I2C_set_Slaveaddress(unsigned char address);

/*********************************************************************************************************/
/*	Function Name        : I2C_slave_read		*/
/*	Function Returns     : unsigned char		   			     */
/*	Function Arguments   : void					*/
/*	Function Description : read the TWDR*/
/*********************************************************************************************************/

unsigned char I2C_slave_read(void);

#endif /* I2C_H_ */