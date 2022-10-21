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
		lcd_init_cursor_left_end();
		DelayMs(20);
		
		lcd_puts("Welcome to world");
		DelayMs(100);
			
		for(i=0;i<32;i++)
		{
			lcd_scroll_right();
			DelayMs(100);
		}
		
	}
	
}