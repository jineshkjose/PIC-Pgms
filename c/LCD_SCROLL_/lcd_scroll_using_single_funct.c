#include<pic.h>
#include"delay.h"
#include"lcd.h"
unsigned char i;
main()
{
	TRISC = 0x00;
	lcd_init();
	DelayMs(20);
	lcd_goto(0x00);
	DelayMs(20);
	lcd_clear();
	DelayMs(20);
	
	

	while(1)
	{	
		lcd_scroll_puts("Welcome To The World Of Electronics");		
	}
	
}