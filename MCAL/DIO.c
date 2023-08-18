/*
 * DIO.c
 *
 *  Created on: Aug 15, 2023
 *      Author: Mostafa Hisham
 *      Layer : MCAL
 *      SWC   : DIO
 */
#include<Std_Types.h>
#include<Macros.h>
#include<Registers.h>
#include<DIO.h>
// FUNCTION TO DETECT WHETHER THE PIN IS INPUT OR OUTPUT OR INPUT PULLUP
/*
 * THE FUNCTION TAKES THE PORT TYPE AND THE PIN WHICH IS REQUIRED FOR THE FUNCTION AND IT'S MODE
 */
void DIO_SetPinDirection(u8 DIO_PortType ,u8 Pin,u8 PIN_Mode)//1
{
	if(PIN_Mode == PIN_INPUT)
	{
	switch(DIO_PortType)
		{
	case DIO_PORTA:
		CLR_BIT(DDRA,Pin);
		CLR_BIT(PORTA,Pin);
		break;
	case DIO_PORTB:
		CLR_BIT(DDRB,Pin);
		CLR_BIT(PORTB,Pin);
		break;
	case DIO_PORTC:
		CLR_BIT(DDRC,Pin);
		CLR_BIT(PORTC,Pin);
		break;
	case DIO_PORTD:
		CLR_BIT(DDRD,Pin);
		CLR_BIT(PORTD,Pin);
		break;
	default:
		break;
		}
	}
	else if(PIN_Mode == PIN_OUTPUT)
	{
		switch(DIO_PortType)
		{
			case DIO_PORTA:
				SET_BIT(DDRA,Pin);
				break;
			case DIO_PORTB:
				SET_BIT(DDRB,Pin);
				break;
			case DIO_PORTC:
				SET_BIT(DDRC,Pin);
				break;
			case DIO_PORTD:
				SET_BIT(DDRD,Pin);
				break;
			default:
				break;
				}
	}
	else if (PIN_Mode == PIN_INPUT_PULLUP)
	{
		switch(PIN_Mode)
					{
					case DIO_PORTA:
						CLR_BIT(DDRA,Pin);
						SET_BIT(PORTA,Pin);
						break;
					case DIO_PORTB:
						CLR_BIT(DDRB,Pin);
						SET_BIT(PORTB,Pin);
						break;
					case DIO_PORTC:
						CLR_BIT(DDRC,Pin);
						SET_BIT(PORTC,Pin);
						break;
					case DIO_PORTD:
						CLR_BIT(DDRD,Pin);
						SET_BIT(PORTD,Pin);
						break;
					default:
						break;
						}
	}

	}
//A FUNCTION TO DETECT WHETHER THE PIN IS OUTPUT HIGH OR OUTPUT LOW
/*
 * If the previous function detected the pin mode output then we have to choose the pin level in this function
 */
void DIO_SetPinLevel(u8 DIO_PortType,u8 DIO_PinType,u8 PIN_Level)//2
{
	if(PIN_Level == PIN_HIGH )
	{
		switch(DIO_PortType)
		{
			case DIO_PORTA:
			SET_BIT(PORTA,DIO_PinType);
			break;

			case DIO_PORTB:
			SET_BIT(PORTB,DIO_PinType);
			break;
			case DIO_PORTC:
			SET_BIT(PORTC,DIO_PinType);
			break;
			case DIO_PORTD :
			SET_BIT(PORTD,DIO_PinType);
			break;
			default:
				break;
			}
	}
	else if (PIN_Level == PIN_LOW)
	{
		switch(DIO_PortType)
		{
			case DIO_PORTA:
			CLR_BIT(PORTA,DIO_PinType);
			break;
			case DIO_PORTB:
			CLR_BIT(PORTB,DIO_PinType);
			break;
			case DIO_PORTC:
			CLR_BIT(PORTC,DIO_PinType);
			break;
			case DIO_PORTD :
			CLR_BIT(PORTD,DIO_PinType);
			break;

		default:
			break;
		}
	}

}

// A FUNCTION TO TOGGLE THE PIN LEVEL
/*
 * input the port type then the required pin to be flip it's state
 */
u8 DIO_TogglePinLevel (u8 DIO_PortType, u8 DIO_PinType)//3
{
	u8 PIN_Level = 50; // declaration and intilization of the level (output)
	switch(DIO_PortType)
	{
	case DIO_PORTA:
		TOGGLE_BIT(PORTA,DIO_PinType);
		PIN_Level = GET_BIT(PORTA,DIO_PinType);
		break;
	case DIO_PORTB:
		TOGGLE_BIT(PORTB,DIO_PinType);
		PIN_Level = GET_BIT(PORTB,DIO_PinType);
		break;
	case DIO_PORTC:
		TOGGLE_BIT(PORTC,DIO_PinType);
		PIN_Level = GET_BIT(PORTC,DIO_PinType);
		break;
	case DIO_PORTD:
		TOGGLE_BIT(PORTD,DIO_PinType);
		PIN_Level = GET_BIT(PORTD,DIO_PinType);
		break;
	default:
		break;
	}
	return PIN_Level;
}
//A FUNCTION TO RETURN THE PIN LEVEL
/*
 *  so you have to input the port type then the required pin and return it through then pin level.
 */
u8 DIO_ReadPinLevel (u8 DIO_PortType,u8 DIO_PinType)//4
{	u8 PIN_Level = 50;
	switch(DIO_PortType)
		{
		case DIO_PORTA:
			PIN_Level=GET_BIT(PINA,DIO_PinType);
			break;
		case DIO_PORTB:
			PIN_Level=GET_BIT(PINB,DIO_PinType);
			break;
		case DIO_PORTC:
			PIN_Level=GET_BIT(PINC,DIO_PinType);
			break;
		case DIO_PORTD:
			PIN_Level=GET_BIT(PIND,DIO_PinType);
			break;
		default:
			break;
		}
	return PIN_Level;
}
// A FUNCTION TO DETECT WHETHER THE DIRECTION OF THE WHOLE PORT IS INPUT OR OUTPUT
/*
 * the inputs of the function will be the port type  then whether it's input or output mode
 */
void DIO_SetPortDirection(u8 DIO_PortType,u8 PORT_Mode )//5
{
	switch(DIO_PortType)
	{
	case DIO_PORTA:
		DDRA = PORT_Mode;
		break;
	case DIO_PORTB:
		DDRB =  PORT_Mode;
		break;
	case DIO_PORTC:
		DDRC =  PORT_Mode;
		break;
	case DIO_PORTD:
		DDRD =  PORT_Mode;
		break;
	default:
		break;
	}

}
//  A FUNCTION TO DETECT WHETHER THE PORT IS HIGH OR LOW
/* The inputs of the function is the port type and it's level whether high or low after choosing it's mode in the previous function
 *
 */
void DIO_SetPortLevel(u8 DIO_PortType,u8 PORT_Level)//6
{
	switch(DIO_PortType)
	{
	case DIO_PORTA:
		PORTA = PORT_Level;
	break;
	case DIO_PORTB:
		PORTB = PORT_Level;
	break;
	case DIO_PORTC:
		PORTC = PORT_Level;
	break;
	case DIO_PORTD:
		PORTD = PORT_Level;
	break;
	default:
		break;
	}
}
u8 DIO_ReadPortLevel(u8 DIO_PortType,u8 PORT_Level)//7
{
	PORT_Level = 50;
	    switch (DIO_PortType)
	    {
	    case DIO_PORTA:
	        PORT_Level = PINA;
	        break;
	    case DIO_PORTB:
	        PORT_Level = PINB;
	        break;
	    case DIO_PORTC:
	        PORT_Level = PINC;
	        break;
	    case DIO_PORTD:
	        PORT_Level = PIND;
	        break;
	    default:
	        break;
	    }
	    return PORT_Level;
}
