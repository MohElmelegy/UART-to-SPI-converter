#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Register.h"

void DIO_VidSetPinDirection(u8 LOC_u8Port , u8 LOC_u8Pin , u8 LOC_u8State)
{
	if(LOC_u8State == 1)
	{
		switch(LOC_u8Port)
		{
		    //port A == 0 (in case)
			case 0: SET_BIT(DDRA,LOC_u8Pin); break;
			//port B == 2
			case 1: SET_BIT(DDRB,LOC_u8Pin); break;
			//port c == 3
			case 2: SET_BIT(DDRC,LOC_u8Pin); break;
			case 3: SET_BIT(DDRD,LOC_u8Pin); break;
		}
	}
	else if(LOC_u8State == 0)
	{
		switch(LOC_u8Port)
		{
			case 0: CLR_BIT(DDRA,LOC_u8Pin); break;
			case 1: CLR_BIT(DDRB,LOC_u8Pin); break;
			case 2: CLR_BIT(DDRC,LOC_u8Pin); break;
			case 3: CLR_BIT(DDRD,LOC_u8Pin); break;
		}
	}
}


void DIO_VidSetPinValue(u8 LOC_u8Port , u8 LOC_u8Pin , u8 LOC_u8Value)
{
	if(LOC_u8Value == 1)
	{
		switch(LOC_u8Port)
		{
			case 0: SET_BIT(PORTA,LOC_u8Pin); break;
			case 1: SET_BIT(PORTB,LOC_u8Pin); break;
			case 2: SET_BIT(PORTC,LOC_u8Pin); break;
			case 3: SET_BIT(PORTD,LOC_u8Pin); break;
		}
	}
	else if(LOC_u8Value == 0)
	{
		switch(LOC_u8Port)
		{
			case 0: CLR_BIT(PORTA,LOC_u8Pin); break;
			case 1: CLR_BIT(PORTB,LOC_u8Pin); break;
			case 2: CLR_BIT(PORTC,LOC_u8Pin); break;
			case 3: CLR_BIT(PORTD,LOC_u8Pin); break;
		}
	}
}

u8 DIO_u8GetPinValue(u8 LOC_u8Port , u8 LOC_u8Pin )
{
	u8 PinValue = 0;
	switch(LOC_u8Port)
		{
			case 0: PinValue = GET_BIT(PINA,LOC_u8Pin); break;
			case 1: PinValue = GET_BIT(PINB,LOC_u8Pin); break;
			case 2: PinValue = GET_BIT(PINC,LOC_u8Pin); break;
			case 3: PinValue = GET_BIT(PIND,LOC_u8Pin); break;
		}
		return PinValue;
}

void DIO_VidSetPortDirection(u8 LOC_u8Port , u8 LOC_u8State)
{

	switch(LOC_u8Port)
		{
			case 0: DDRA = LOC_u8State; break;
			case 1: DDRB = LOC_u8State; break;
			case 2: DDRC = LOC_u8State; break;
			case 3: DDRD = LOC_u8State; break;
		}

}

void DIO_VidSetPortValue(u8 LOC_u8Port , u8 LOC_u8Value)
{
	switch(LOC_u8Port)
		{
			case 0: PORTA = LOC_u8Value; break;
			case 1: PORTB = LOC_u8Value; break;
			case 2: PORTC = LOC_u8Value; break;
			case 3: PORTD = LOC_u8Value; break;
		}
}
