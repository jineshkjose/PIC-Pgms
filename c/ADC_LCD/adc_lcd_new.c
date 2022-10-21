#include<pic.h>
#include "dd_lcd.h"

float data;
unsigned char adc;


int main(void)

{
	
	int i;

	TRISA=0xFF;
	//TRISC=0xFF;
	ADCON0=0X81;
	ADCON1=0X00;
	Config_IO();
	Init_LCD();
	clr_lcd();
	Set_LCD_Command(LCD_ROW1);
    LCD_Scrol_String("DIGITAL VOLT METER");
	lcd_puts("Result     =");
while(1)
{
	
	for (i=0;i<250;++i);
	ADGO=1;
	while(ADGO);
Set_LCD_Command(LCD_ROW2);
adc = ADRESH;
		data = ((5.0/255)*adc);
		lcd_num_float(data);


lcd_puts(" DC Volt");
	


	
	   

}
//return 0;
}

