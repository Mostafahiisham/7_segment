/*
 * Ssd.h
 *
 *  Created on: Aug 15, 2023
 *      Author: Mostafa Hisham
 */

#ifndef HAL_SSD_H_
#define HAL_SSD_H_

#define COMMON_Cathode  1
#define COMMON_Anode    2
#define SSD_TYPE  COMMON_Cathode


#define zero	0
#define one 	1
#define two 	2
#define three	3
#define four  	4
#define five 	5
#define six  	6
#define seven 	7
#define eight 	8
#define nine  	9
void SSD_Init(u8 SSD_PORT);
void SSD_DisplayNumber(u8 SSD_PORT,u8 number);
void SSD_TurnOff(u8 SSD_PORT);
void SSD_UPCounter(u8 SSD_PORT,u8 number);
void SSD_DOWNCounter(u8 SSD_PORT,u8 number);
#endif /* HAL_SSD_H_ */
