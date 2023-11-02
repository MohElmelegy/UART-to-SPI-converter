/*
 * Slave_APP.c
 *
 * Created: 10/30/2023
 *  Author: Mohamed Samy
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

// Slave
int main(void)
{

    UART_Init();
    LCD_VidInit();
    SPI_VidInit();
    u8 data = 0;
    u8 data_send = 5;
    while (1)
    {
        data = SPI_u8TransmiteReceive(data);
        LCD_ClearDisplay();
        LCD_VidWriteChar(data);
        _delay_ms(1000);
    }
}