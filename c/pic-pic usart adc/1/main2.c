#include<pic.h>
#include"delay.h"
#include"lcd.h"

float data;
unsigned char adc;
int flag=0;

main()
{
	int i;
	
	TRISD = 0x00;

	


SPBRG=129;
BRGH=1;
SYNC=0;
SPEN=1;
CREN=1;
RX9=0;
RCIF=0;
RCIE=0;


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

if(RCIF==1)
{
RCIF=0;
lcd_goto(0x00);
data=RCREG;
lcd_num_float(data);
//lcd_putch(data);

}

}
	
}

