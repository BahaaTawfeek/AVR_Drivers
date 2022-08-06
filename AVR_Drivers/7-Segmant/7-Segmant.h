/*
 * 7-Segmant.h
 *
 * Created: 27/04/2022 03:22 am
 *  Author: Bahaa Tawfik
 */

#ifndef 7-SEGMENT_H_
#define 7-SEGMENT_H_


/*
Function Name        : seven_seg_vinit
Function Returns     : void
Function Arguments   : unsigned char port_name
Function Description : define the given port as output port
*/
void seven_seg_vinit(unsigned char port_name);


/*
Function Name        : seven_seg_write
Function Returns     : void
Function Arguments   : unsigned char portname,unsigned char number
Function Description : write value of elements of array on the given port 
*/

void seven_seg_write(unsigned char portname,unsigned char number);



#endif 