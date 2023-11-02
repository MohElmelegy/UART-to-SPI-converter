
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI_register.h"
#include "SPI_interface.h"
#include "DIO_Interface.h"
// portB PIN5 MOSI OUTPUT//
// portB PIN6 MISO INPUT//
// portB PIN4 SS  OUTPUT MASTER INPUT IF PULLUP ACTIVE MASTER ELSE SLAVE//
// portB PIN7 SS  OUTPUT SCK//

void SPI_VidInit(void)
{
	DIO_VidSetPinDirection(PORTB, PIN5, OUTPUT); // MOSI PB5
	DIO_VidSetPinDirection(PORTB, PIN6, INPUT);	 // MISO PB6
	DIO_VidSetPinDirection(PORTB, PIN7, OUTPUT);
	//DIO_VidSetPinDirection(PORTB, PIN4, OUTPUT); //
	//SPCR = (1<<SPCR_SPE)|(1<<SPCR_MSTR)|(1<<SPCR_SPR0);

	u8 x = 0;
	SET_BIT(x, PIN6); // SPI ENABLE//

#if SPI_PRE == SPI4

	CLR_BIT(x, PIN0);	 // SPR0//
	CLR_BIT(x, PIN1);	 // SPR0 //
	CLR_BIT(SPSR, PIN0); // SPI2X//
#elif SPI_PRE == SPI16

	SET_BIT(x, PIN0);	 // SPR0//
	CLR_BIT(x, PIN1);	 // SPR0 //
	CLR_BIT(SPSR, PIN0); // SPI2X//
#elif SPI_PRE == SPI64

	CLR_BIT(x, PIN0);	 // SPR0//
	SET_BIT(x, PIN1);	 // SPR0 //
	CLR_BIT(SPSR, PIN0); // SPI2X//
#elif SPI_PRE == SPI128

	SET_BIT(x, PIN0);	 // SPR0//
	SET_BIT(x, PIN1);	 // SPR0 //
	CLR_BIT(SPSR, PIN0); // SPI2X//

#endif

#if DORD == LSB
	SET_BIT(x, PIN5); // SET the LSB SEND FIRST, CLR MSB  //

#elif DORD == MSB
	CLR_BIT(x, PIN5); // SET the LSB SEND FIRST, CLR MSB  //

#endif

#if SPI_MODE == INTERRUPT
	SET_BIT(x, PIN7); // INTERRUPT ENABLE//
#endif

#if PERIPHRAL_MODE == MASTER
	SET_BIT(x, PIN4); // SET master mode, CLR slave mode //
#elif PERIPHRAL_MODE == SLAVE
	CLR_BIT(x, PIN4); // SET master mode, CLR slave mode //
#endif

#if CLK_FUNCTIONALTY == RISING_SETUP

	CLR_BIT(x, PIN3); // leading edge is rising Cpol//
	SET_BIT(x, PIN2); // leading edge = Setup  CPhase//

#elif CLK_FUNCTIONALTY == RISING_SAMPLING

	CLR_BIT(x, PIN3); // leading edge is rising Cpol//
	CLR_BIT(x, PIN2); // leading edge = Setup  CPhase//
#elif CLK_FUNCTIONALTY == FALLING_SETUP

	SET_BIT(x, PIN3); // leading edge is rising Cpol//
	SET_BIT(x, PIN2); // leading edge = Setup  CPhase//

#elif CLK_FUNCTIONALTY == FALLING_SAMPLING

	SET_BIT(x, PIN3); // leading edge is rising Cpol//
	CLR_BIT(x, PIN2); // leading edge = Setup  CPhase//
#endif

	SPCR = x;
}
u8 SPI_u8TransmiteReceive(u8 LOC_u8TransmitedData)
{

	SPDR = LOC_u8TransmitedData; // send to slave//

	while (GET_BIT(SPSR, PIN7) == 0)
		;

	return SPDR; // send to master//
}

static void (*u8GlobalPointerSpi)(u8 Global_u8SpdrAdress);
void SPI_VidSetCallBackReceive(void (*u8LocalPointerSpi)(u8 LOC_u8SpdrAdress))
{

	if (u8LocalPointerSpi != NULL)
	{
		u8GlobalPointerSpi = u8LocalPointerSpi;
	}
}

void __vector_12(void)
{

	if (u8GlobalPointerSpi != NULL)
	{

		u8GlobalPointerSpi(SPDR);
	}
}
