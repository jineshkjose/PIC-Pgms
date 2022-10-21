/*
 *	LCD interface example
 *	Uses routines from delay.c
 *	This code will interface to a standard LCD controller
 *	like the Hitachi HD44780. It uses it in 4 bit mode, with
 *	the hardware connected as follows (the standard 14 pin 
 *	LCD connector is used):
 *	
 *	DATA bits 0-3 are connected to the LCD data bits 4-7 (high nibble)
 *	PORTA bit 2 is connected to the LCD RS input (register select)
 *	PORTA bit 3 is connected to the LCD EN bit (enable)
 *	
 *	To use these routines, set up the port I/O (TRISA, TRISB) then
 *	call lcd_init(), then other routines as required.
 *	
 */

#include	<pic.h>
#include	"lcd.h"
#include	"delay.h"
#include 	<stdio.h>

#define		DATA	PORTC

static bit LCD_RS	@ ((unsigned)&PORTC*8+4);	// Register select
static bit LCD_EN	@ ((unsigned)&PORTC*8+5);	// Enable

#define	LCD_STROBE		LCD_EN = 1;\
						DelayUs(100);\
						LCD_EN=0;\
						DelayUs(100);


/* write a byte to the LCD in 4 bit mode */

void
lcd_write(unsigned char c)
{
	DATA = (DATA & 0xF0) |  (c >> 4);
	LCD_STROBE;
	DATA = (DATA & 0xF0) |  (c & 0x0F);
	LCD_STROBE;
	DelayUs(250);
}

/*
 * 	Clear and home the LCD
 */

void
lcd_clear(void)
{
	LCD_RS = 0;
	lcd_write(0x1);
	DelayMs(20);
}

/* write a string of chars to the LCD */

void
lcd_puts(const char * s)
{
	LCD_RS = 1;	// write characters
	while(*s)
		lcd_write(*s++);
}

/* write one character to the LCD */

void
lcd_putch(char c)
{
	LCD_RS = 1;	// write characters
	DATA = (DATA & 0xF0) |  (c >> 4);
	LCD_STROBE;
	DATA = (DATA & 0xF0) |  (c & 0x0F);
	LCD_STROBE;
	DelayUs(250);
}


/*
 * Go to the specified position
 */

void
lcd_goto(unsigned char pos)
{
	LCD_RS = 0;
	lcd_write(0x80+pos);
}

void
lcd_num_float(float num)
{
float temp[6];
sprintf(temp,"%0.3f",num);
lcd_puts(temp);
DelayMs(20);
}

void
lcd_num_dec(int num)
{
char temp[6];
sprintf(temp,"%d",num);
lcd_puts(temp);
DelayMs(20);
}

	
/* initialise the LCD - put into 4 bit mode */

void
lcd_init(void)
{
	LCD_RS = 0;	// write control bytes
	DelayMs(15);	// power on delay
	DATA = 0x3;	// attention!
	LCD_STROBE;
	DelayMs(5);
	LCD_STROBE;
	DelayUs(100);
	LCD_STROBE;
	DelayMs(5);
	DATA = 0x2;	// set 4 bit mode
	LCD_STROBE;
	DelayUs(40);
	lcd_write(0x28);	// 4 bit mode, 1/16 duty, 5x8 font
	lcd_write(0x08);	// display off
	lcd_write(0x0C);	// display on, blink curson on
	lcd_write(0x06);	// entry mode
}

