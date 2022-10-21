#include<pic.h>
#include "delay.h"
#include "lcd.h"


float adc;
unsigned char data;

void SPI_Init(void);

main()
{
	TRISC = 0X00;
	TRISD = 0X00;
	PORTD = 0x00;
	TRISC4 = 1;
	TRISC3 = 1;
	SPI_Init();

lcd_init();
	DelayMs(20);
	lcd_goto(0x00);
	DelayMs(20);
	lcd_clear();
	DelayMs(20);
	lcd_puts("..:: SLAVE PIC:..");
	DelayMs(10000);
	lcd_clear();
	
	while(1)
{


	while(!STAT_BF);
   	data = SSPBUF;
adc = ((5.0/255)*data);
lcd_goto(0x00);
lcd_num_float(adc);
 
//SSPBUF='a';
//while(!STAT_BF);

}
}

void SPI_Init(void)
{
   SSPSTAT = 0x00;
   SSPCON = 0b00100101; //the config word for this register will change based on the clock polarity, and clock edge
}



