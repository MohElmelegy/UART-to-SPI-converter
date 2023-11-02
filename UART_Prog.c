/*
 * UART_Prog.c
 *
 *  Created on: Aug 8, 2020
 *      Author: Tantawy
 */
#include "BIT_MATH.h"
#include "STD_Types.h"
#include "UART_Interface.h"
#include "UART_Register.h"


void UART_Init(void)
{
    u8 x=0;
    /* selecting 9600 baud rate */
	UBRRL=51;
	UBRRH=0;
	/*transmit Enable*/
	SET_BIT(UCSRB,3);

	/*Receive Enable*/
	SET_BIT(UCSRB,4);

	/*Setting number of data bits: 8 */
	CLR_BIT(UCSRB,UCSZ2);

	SET_BIT (x,2);
    SET_BIT (x,1);
    SET_BIT (x,7);
    UCSRC =x;






}

void UART_SendData(u8 Data)
{
	/*wait "Transmit Complete" OR "UDR is empty"  */
	while(GET_BIT(UCSRA,UDRE)==0);      		//UDRE or TXC ,  "but in TXC , u need to send 1 data atleast before checking "
	/*storing the data to UDR after making sure it's empty */
	UDR=Data;
}

u8 UART_ReceiveData(void)
{	u8 Data;

	/*wait recent Receive Complete*/
	
	while(GET_BIT(UCSRA,7)==0);
	
	/*getting the data from UDR after making sure recieve complete */
	Data=UDR;




	return Data;
}

void UART_SendString(char *str)
{
	unsigned char j=0;
	
	while (str[j]!=0)		/* Send string till null */
	{
		UART_SendData(str[j]);
		
		j++;
	}
	
}

void ReadStringData(char *str){
    
    char c;
    do{
        c=UART_ReceiveData();
        *str=c;
        str++;
    }
    while(c!='\0');
    return;
}

unsigned char * uartrecieve()
{
	//unsigned char i=0;
	 unsigned char * x;

	/* Wait for data to be received */

	//    char * ptr = &UDR;

	while ( !(UCSRA & (1<<RXC)) );

	while(UDR != '\0')
	{
		*x = UDR;
		x++;
		while ( !(UCSRA & (1<<RXC)) );
	}
	*x = UDR;

	return x;
}



/*int equal_arrays(char a1 [], char a2 [])
{
    int i;
    
    for (i=0; a1[i] !='\0'; ++i)
    if (a1[i] != a2[i])

    return 0;
    
    return 1;
}*/




