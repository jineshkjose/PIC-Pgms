#include<pic.h>
#include"delay.h"
#include"lcd.h"

float data,data1;
unsigned char adc;


main()
{
	int i;	
	TRISA=0xFF;
	TRISD = 0x00;
	ADCON0=0X81;
	ADCON1=0X00;

SPBRG=129;
BRGH=1;
SYNC=0;
SPEN=1;
CREN=1;
RX9=0;
RCIF=0;
RCIE=0;
TXEN=1;


	lcd_init();
	DelayMs(20);
	lcd_goto(0x00);
	DelayMs(20);
	lcd_clear();
	DelayMs(20);
	lcd_puts("..:: PIC 1 ::..");
	DelayMs(10000);

	lcd_clear();
	while(1)
	{	
	for (i=0;i<250;++i);
	ADGO=1;
	while(ADGO);
	adc = ADRESH;

	while(!TXIF);
	TXREG=adc;
	while(TRMT==0);
	data = ((5.0/255)*adc);	
	lcd_goto(0x00);
lcd_puts("PIC 1: ");
	lcd_num_float(data);


if(RCIF==1)
{
RCIF=0;
data1=RCREG;
data1 = ((5.0/255)*data1);
lcd_goto(0x40);
lcd_puts("PIC 2: ");
lcd_num_float(data1);
}

}
	
}

