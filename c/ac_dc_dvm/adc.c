
#include<pic.h>
#include "dd_lcd.h"

void main(void)
{
	int i;
	unsigned int res;
	//Config_IO();
	//Init_LCD();
	TRISA=0xFF;
	//TRISD=0x00;
	ADCON0=0X81;
	ADCON1=0X00;
//clr_lcd();
//	Set_LCD_Command(LCD_ROW1);
  //  lcd_puts("ADC RESULT");


while(1)
	{
	
	for (i=0;i<250;++i);
	ADGO=1;
	while(ADGO);
	//Set_LCD_Command(LCD_ROW2); 
	//PORTD=ADRESH;
	//res=ADRESH*.020;
	//Set_LCD_Num(res);
	}

	
}
