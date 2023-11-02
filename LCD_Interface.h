#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define DATA_PORT		PORTA
#define CONTROL_PORT	PORTC


void LCD_VidInit(void);
void LCD_VidSendCommand(u8 LOC_u8Command);
void LCD_VidWriteChar(u8 LOC_u8Data);
void LCD_VidWriteString(u8 LOC_u8Data[]);
void LCD_VidWriteNumber(u32 LOC_u8Number);
void LCD_VidSetPosition(u8 LOC_u8Row , u8 LOC_u8Col);
void LCD_ZigZagDisplay(u8 name);
void LCD_ClearDisplay(void);
void LCD_vidWriteExtraChar (u8 Y,u8 X ,u8 iteration2 );
void LCD_spe_char (u8 Row , u8 Col, u8 ch);




#endif
