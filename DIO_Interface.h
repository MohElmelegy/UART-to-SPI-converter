#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
#include "STD_TYPES.h"

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

#define OUTPUT	1
#define INPUT  	0

#define OUTPUT_PORT	0XFF
#define INPUT_PORT	0X00

#define HIGH 	1
#define LOW		0

#define HIGH_PORT 	0XFF
#define LOW_PORT	0X00

// for pin
void DIO_VidSetPinDirection(u8 LOC_u8Port , u8 LOC_u8Pin , u8 LOC_u8State);
void DIO_VidSetPinValue(u8 LOC_u8Port , u8 LOC_u8Pin , u8 LOC_u8Value);
u8 DIO_u8GetPinValue(u8 LOC_u8Port , u8 LOC_u8Pin );

// For port
void DIO_VidSetPortDirection(u8 LOC_u8Port , u8 LOC_u8State);
void DIO_VidSetPortValue(u8 LOC_u8Port , u8 LOC_u8Value);



#endif
