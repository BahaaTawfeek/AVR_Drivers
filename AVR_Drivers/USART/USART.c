/*
 * USART.c
 *
 * Created: 1/05/2022 10:06
 *  Author: Bahaa Tawfik
 */


#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "std_macros.h"


/*	Function Description : Initialize the UART Communication        */
void UART_vInit(unsigned long baud)
{
	/*1 - Choose baud rate that will be used by sender and receiver by writing to UBRRL/UBRRH*/
	unsigned short UBRR ;
	UBRR=(F_CPU/(16*baud))-1 ;
	UBRRH=(unsigned char)(UBRR>>8);
	UBRRL=(unsigned char)UBRR;
	/*2 - Enable USART Sender & Receiver*/
	SetBit(UCSRB,TXEN);
	SetBit(UCSRB,RXEN);
	/*3 - Choose number of data bits to be sent,parity and stop bits from UCSRC
	, We will work with 8 bits data,1 stop bit and no parity bits*/
	UCSRC=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
}


/*	Function Description :   UART Send Data         */
void UART_vSendData(char data)
{
	/*Wait for UDR transmit buffer to be empty*/
	while(ReadBit(UCSRA,UDRE)==0);
	/*Put data to UDR transmit buffer transmit*/
	UDR=data ;
}


/*	Function Description :   UART Receive Data         */
char UART_u8ReceiveData(void)
{
	/*Wait for UDR receive buffer to be filled with data  or while(!(UCSRA & (1<<RXC)) )*/
	while(ReadBit(UCSRA,RXC)==0);
	/*Receive data from UDR receive buffer*/
	return UDR ;
}


/*	Function Description :   UART Send String         */
void UART_vSendstring( char *ptr)
{
	while(*ptr!=0)
	{
		UART_vSendData(*ptr);
		ptr++;
		_delay_ms(100);
	}
}

 