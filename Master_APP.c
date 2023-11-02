/*
 * Master_APP.c
 *
 * Created: 10/30/2023
 *  Author: Mohamed Sami
 */
#define F_CPU 8000000
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "UART_Interface.h"
#include "SPI_interface.h"
#include <avr/delay.h>
#include <avr/io.h>

int main(void)
{

  UART_Init();
  SPI_VidInit();
  u8 data = 0;
  // master
  DIO_VidSetPinDirection(PORTB, PIN0, OUTPUT);
  DIO_VidSetPinValue(PORTB, PIN0, LOW);
  while (1)
  {
    data = UART_ReceiveData();
    SPI_u8TransmiteReceive(data);
    _delay_ms(1000);
  }
}