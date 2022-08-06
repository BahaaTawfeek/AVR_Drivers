/*
 * USART.h
 *
 * Created: 1/05/2022 10:06
 *  Author: Bahaa Tawfik
 */ 


#ifndef USART_H_
#define USART_H_

/**********************************************************************************************************/
/*	Function Name        : UART_vInit								*/
/*	Function Returns     : void								   */
/*	Function Arguments   : unsigned long baud 					  */
/*	Function Description : Initialize the UART Communication        */
/*********************************************************************************************************/
void UART_vInit(unsigned long baud);


/**********************************************************************************************************/
/*	Function Name        : UART_vSendData								*/
/*	Function Returns     : void								   */
/*	Function Arguments   : char data				  */
/*	Function Description :   UART Send Data         */
/*********************************************************************************************************/

void UART_vSendData(char data);


/**********************************************************************************************************/
/*	Function Name        : UART_u8ReceiveData								*/
/*	Function Returns     : char								   */
/*	Function Arguments   : void				  */
/*	Function Description :   UART Receive Data         */
/*********************************************************************************************************/

char UART_u8ReceiveData(void);



/**********************************************************************************************************/
/*	Function Name        : UART_u8ReceiveData								*/
/*	Function Returns     : void								   */
/*	Function Arguments   : char *ptr				  */
/*	Function Description :   UART Send String         */
/*********************************************************************************************************/
void UART_vSendstring( char *ptr);



#endif /* USART_H_ */
