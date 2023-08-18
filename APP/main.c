/*
 * main.c
 *
 *  Created on: Aug 15, 2023
 *      Author: Mostafa Hisham
 */

#include"../LIB/Registers.h"
#include"../LIB/Std_Types.h"
#include"../LIB/Macros.h"
#include"../MCAL/DIO.h"
#include"../HAL/Ssd.h"
#include<util/delay.h>
void main (void)
{
	SSD_Init(DIO_PORTC);
	SSD_Init(DIO_PORTD);
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN0,PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN1,PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN2,PIN_OUTPUT);
	while(1)
	{
		SSD_DisplayNumber(DIO_PORTD,0);
		for(u8 j = 1;j<=2;j++)
		{
		for(u8 i = 0 ;i < 10;i++)
		{
			SSD_DisplayNumber(DIO_PORTC,i);
			DIO_SetPinLevel(DIO_PORTA,DIO_PIN0,PIN_HIGH);
			_delay_ms(500);
		}
		SSD_DisplayNumber(DIO_PORTD,j);
		}
		DIO_SetPinLevel(DIO_PORTA,DIO_PIN0,PIN_LOW);
		//YELLOW
		SSD_DisplayNumber(DIO_PORTD,0);
		for(u8 j = 1;j<2;j++)
			{
			for(u8 i = 0 ;i < 10;i++)
			{
				SSD_DisplayNumber(DIO_PORTC,i);
				DIO_SetPinLevel(DIO_PORTA,DIO_PIN1,PIN_HIGH);
				_delay_ms(500);
			}
			SSD_DisplayNumber(DIO_PORTD,j);
			}
			DIO_SetPinLevel(DIO_PORTA,DIO_PIN1,PIN_LOW);
			//GREEN
			SSD_DisplayNumber(DIO_PORTD,0);
			for(u8 j = 1;j<=3;j++)
			{
			for(u8 i = 0 ;i < 10;i++)
			{
			SSD_DisplayNumber(DIO_PORTC,i);
			DIO_SetPinLevel(DIO_PORTA,DIO_PIN2,PIN_HIGH);
			_delay_ms(500);
			}
			SSD_DisplayNumber(DIO_PORTD,j);
			}
				DIO_SetPinLevel(DIO_PORTA,DIO_PIN2,PIN_LOW);

	}
}
