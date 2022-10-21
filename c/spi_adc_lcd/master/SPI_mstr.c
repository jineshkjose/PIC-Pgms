#include<pic.h>
#include "delay.h"
#include"lcd.h"


void SPI_Init(void);


float data,data1;
unsigned char adc;
int i;
char rec;

main()
{
	TRISA=0xFF;
	TRISC = 0X00;
	TRISD=0X00;
	PORTD=0X00;
	TRISC4 = 1;
	ADCON0=0X81;
	ADCON1=0X00;
	
	SPI_Init();

lcd_init();
	DelayMs(20);
	lcd_goto(0x00);
	DelayMs(20);
	lcd_clear();
	DelayMs(20);
	lcd_puts("..:: MASTER PIC :..");
	DelayMs(10000);

	lcd_clear();
	while(1)
{
 
	for (i=0;i<250;++i);
	ADGO=1;
	while(ADGO);
	adc = ADRESH;
SSPBUF=adc;
while(!STAT_BF);
	data = ((5.0/255)*adc);	
	lcd_goto(0x00);
	lcd_num_float(data);
DelayMs(1);

/*while(!STAT_BF);
   	rec = SSPBUF;
lcd_goto(0x40);
if(rec=='a')
lcd_puts("data rexd");
else
lcd_puts("2222222222");*/



}
}

void SPI_Init(void)
{
  SSPSTAT = 0x00;
  SSPCON = 0b00100010; //the config word for this register will change based on the clock polarity, and clock edge
}

