/*
 * 7-Segmant.c
 *
 * Created: 27/04/2022 03:27 am
 *  Author: Bahaa Tawfik
 */

#include "DIO.h"
#include "7-Segmant.h"
void seven_seg_vinit(unsigned char port_name)
{
	DIO_vsetPortDir(port_name,0xFF);
}


void seven_seg_write(unsigned char portname,unsigned char number)
{
unsigned char arr[]={ 0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

DIO_vwritePort(portname,arr[number]);
}

//Common cathode  use array as above  BUT with common anode use ~arr[counter]