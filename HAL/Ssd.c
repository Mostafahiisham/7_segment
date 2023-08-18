/*
 * Ssd.c
 *
 *  Created on: Aug 15, 2023
 *      Author: Mostafa Hisham
 *      Layer : HAL
 */
#include"../LIB/Std_Types.h"
#include"../LIB/Registers.h"
#include"../LIB/Macros.h"
#include"../MCAL/DIO.h"
#include<Ssd.h>
#include<util/delay.h>

static const u8 SSD[10]={
		//		   gfedcba
				0b00111111,//0
				0b00000110,//1
				0b01011011,//2
				0b01001111,//3
				0b01100110,//4
				0b01101101,//5
				0b01111101,//6
				0b00000111,//7
				0b01111111,//8
				0b01101111//9
};
void SSD_Init(u8 SSD_PORT)
{
	DIO_SetPortDirection(SSD_PORT,PORT_MODE_OUTPUT);
}
void SSD_DisplayNumber(u8 SSD_PORT, u8 number)
{
	if(number <= 9)
	{
#if SSD_TYPE == 1
DIO_SetPortLevel(SSD_PORT,SSD[number]);
#elif SSD_TYPE ==2
DIO_SetPortLevel(SSD_PORT,~SSD[number]);
#else
	#error INVALID SSD TYPE
#endif
	}
}
void SSD_TurnOff(u8 SSD_PORT)
{
#if SSD_TYPE == 1
	DIO_SetPortLevel(SSD_PORT,0);
#elif SSD_TYPE == 2
	DIO_SetPortLevel(SSD_PORT,0xff);
#else
	#error INVALID SSD TYPE
#endif
}
void SSD_UPCounter(u8 SSD_PORT,u8 number)
{

	if(number  <=  9)
	{
	for(u8 counter = number ; counter <= 9 ; counter++)
		{
		SSD_DisplayNumber(SSD_PORT,counter);
		_delay_ms(500);
		}
	}
}
void SSD_DOWNCounter(u8 SSD_PORT,u8 number)
{
	if(number  <=  9)
	{
	for(u8 counter = 9 ; counter >= number ; counter--)
		{
		SSD_DisplayNumber(SSD_PORT,counter);
		_delay_ms(500);
		}
	}
}

