#include<pic.h>
#include"delay.h"
#include"lcd.h"

float data;
unsigned char adc;
main()
{
	int i;
	TRISA=0xFF;
	TRISD = 0x00;
	ADCON0=0X81;
	ADCON1=0X00;

	lcd_init();
	DelayMs(20);
	lcd_goto(0x00);
	DelayMs(20);
	lcd_clear();
	DelayMs(20);
	lcd_puts("..:: ADC ::..");
	lcd_clear();
	while(1)
	{	
	for (i=0;i<250;++i);
	ADGO=1;
	while(ADGO);
	
	lcd_goto(0x00);	
	adc = ADRESH;
		data = ((5.0/255)*adc);
lcd_num_float(data);
			
		
		
	}
	
}
