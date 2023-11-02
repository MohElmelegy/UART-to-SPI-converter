

	#ifndef _SPI_INTERFACE_H_
	#define _SPI_INTERFACE_H_
	
	#define POOLING                  0
	#define INTERRUPT                1
	#define MASTER                   0
	#define SLAVE                    1
	#define SPI4                     1
	#define SPI16                    2
	#define SPI64                    3
	#define SPI128                   4
	#define LSB                      0
	#define MSB                      1
	#define RISING_SETUP             0
	#define RISING_SAMPLING          1
	#define FALLING_SETUP            2
	#define FALLING_SAMPLING         3
	#define SPI_MODE               POOLING 
	#define SPI_PRE	                SPI16
	#define DORD	                LSB
	#define PERIPHRAL_MODE	        MASTER
	#define CLK_FUNCTIONALTY	   RISING_SETUP
	
	
	
	
	
	
#define PIN0     0
#define PIN1     1
#define PIN2     2
#define PIN3     3
#define PIN4     4
#define PIN5     5
#define PIN6     6
#define PIN7     7
void SPI_VidInit(void);
u8 SPI_u8TransmiteReceive(u8 LOC_u8TransmitedData);
void SPI_VidSetCallBackReceive(void (*u8LocalPointerSpi)(u8 LOC_u8SpdrAdress));

#endif
