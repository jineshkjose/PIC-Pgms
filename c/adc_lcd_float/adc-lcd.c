#include <pic.h>
#include "delay.h"
#include "lcd.h"

float data;
unsigned char adc;

main()
{
	TRISA0 = 1;
	TRISC = 0x00;
	lcd_init();
	DelayMs(20);
	lcd_clear();
	DelayMs(20);
	lcd_goto(0x00);
	DelayMs(20);
	lcd_puts("A/D Convertor");
	DelayMs(20);
	ADCON1 = 0x00;
	ADCS1 = 1;
	ADCS0 = 0;
	CHS2 = 0;
	CHS1 = 0;
	CHS0 = 0;
	ADFM = 0;
	ADON = 1;
	
	while(1)
	{
		lcd_goto(0x40);
		DelayMs(20);
		ADGO = 1;
		while(ADGO);
		adc = ADRESH;
		data = ((5.0/255)*adc);
		lcd_num_float(data);
		DelayMs(20);
		lcd_puts("   ");
		DelayMs(20);
	}
}
