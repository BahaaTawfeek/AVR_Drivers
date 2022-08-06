/*
 * button.c
 *
 * Created: 27/04/2022 03:11 am
 *  Author: Bahaa Tawfik
 */
 
#include "DIO.h"
void button_vInit(unsigned char portname,unsigned char pinnumber)
{
	DIO_vsetPinDir(portname,pinnumber,0);
}
unsigned char button_u8read(unsigned char portname,unsigned char pinnumber)
{
	unsigned char x;
	x=DIO_u8readPin(portname,pinnumber);
	return x ;
}

