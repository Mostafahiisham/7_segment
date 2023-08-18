/*
 * DIO.h
 *
 *  Created on: Aug 15, 2023
 *      Author: Mostafa Hisham
 *      Layer : MCAL
 *      SWC   : DIO
 */

#ifndef INCLUDE_DIO_H_
#define INCLUDE_DIO_H_

/*port type */
#define	DIO_PORTA 			 0
#define	DIO_PORTB 			 1
#define	DIO_PORTC 			 2
#define	DIO_PORTD 			 3

/* pin Direction */
#define	PIN_INPUT 			 0
#define	PIN_OUTPUT    		 1
#define	PIN_INPUT_PULLUP 	 2


/*pin value */
#define	PIN_LOW				 0
#define	PIN_HIGH			 1

/* port direction */
#define	PORT_MODE_INPUT		 0
#define	PORT_MODE_OUTPUT  0XFF


/* port level*/
#define	PORT_LEVEL_LOW	 0
#define	PORT_LEVEL_HIGH  0XFF

/* pin type*/
#define	DIO_PIN0			 0
#define	DIO_PIN1             1
#define	DIO_PIN2			 2
#define	DIO_PIN3             3
#define	DIO_PIN4			 4
#define	DIO_PIN5			 5
#define	DIO_PIN6			 6
#define	DIO_PIN7			 7


void DIO_SetPinDirection(u8 DIO_PortType ,u8 DIO_PinType,u8 PIN_Mode);//1
void DIO_SetPinLevel(u8 DIO_PortType,u8 DIO_PinType,u8 PIN_Level);//2
void DIO_SetPortDirection(u8 DIO_PortType,u8 PORT_Mode);//3
void DIO_SetPortLevel(u8 DIO_PortType,u8 PORT_Level);//4
u8 DIO_TogglePinLevel (u8 DIO_PortType,u8 DIO_PinType);//5
u8 DIO_ReadPinLevel (u8 DIO_PortType,u8 DIO_PinType);//6
u8 DIO_ReadPortlevel(u8 DIO_PortType,u8 PORT_Level);//7


#endif /* INCLUDE_DIO_H_ */
