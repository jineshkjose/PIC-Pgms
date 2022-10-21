#include<pic.h>
#include "dd_lcd.h"


int main(void)

{
	Config_IO();
	Init_LCD();

	
while(1)
{
	
	clr_lcd();
	Set_LCD_Command(LCD_ROW1);
    lcd_puts("   WELCOME     ");
	Set_LCD_Command(LCD_ROW2);   
	lcd_puts("      to       ");
clr_lcd();
    Set_LCD_Command(LCD_ROW1);
	lcd_puts(" AMRITA VISHWA ");
	Set_LCD_Command(LCD_ROW2);
	lcd_puts(" VIDYAPEETHAM ");
clr_lcd();


	
	   

}
//return 0;
}

