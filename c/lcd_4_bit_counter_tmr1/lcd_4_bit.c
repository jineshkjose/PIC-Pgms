#include <pic.h>
#include "delay.h"
#include "dd_lcd.h"

float data;
unsigned char adc,ss,mm,hh;

main()
{
	
lcd_config();
	lcd_init();
	DelayMs(20);
	lcd_clear();
	DelayMs(20);
	lcd_goto(0x00);
//lcd_puts("65757");
	DelayMs(20);
//scroll();

	DelayMs(20);
	ss=mm=hh=0;
	while(1)
	{
DelayMs(100);
//lcd_clear();
	lcd_goto(0x00);
lcd_puts("      ");
	DelayMs(2);
lcd_num_dec(hh);
lcd_puts(":");
DelayMs(50);
lcd_num_dec(mm);
lcd_puts(":");
DelayMs(50);
lcd_num_dec(ss);


ss++;
if(ss==60)
{
ss=0;
mm++;
lcd_clear();
if(mm==60)
{
mm=0;
hh++;
lcd_clear();
}
}


DelayMs(150);
//DelayMs(1000);
	
	}
}
