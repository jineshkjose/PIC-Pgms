#include<pic.h>
#include "dd_lcd.h"



#define ac_dc_relay RD2
#define sw1 RD3
#define led_green RD4
#define led_red RD5

#define on 1
#define off 0


#define open 0
#define close 1




float data=0,data1=0,datat=0,datar=0,temp=0;
unsigned char adc;

void read_adc_1(void);
int ac_flag=0,dc_flag=0,flag3=0,flag4=0,i=0;

int main(void)
{
	TRISA=0xFF;
	//TRISC=0xFF;
	//TRISD=0X00;
TRISD0=TRISD1=TRISD2=TRISD4=TRISD5=0;
TRISD3=1;
ac_dc_relay=off;
led_green=off;
led_red=on;

//	PORTD=0X00;
	ADCON0=0X81;
	ADCON1=0X00;
	Config_IO();
	Init_LCD();
Set_LCD_Command(LCD_ROW1);
//LCD_Scrol_String(" DIGITAL VOLT METER ");
	clr_lcd();



while(1)
{

if(sw1==on)
{
ac_dc_relay=on;
led_green=on;
ac_flag=1;
dc_flag=0;
}
else
{
ac_dc_relay=off;
led_green=off;
ac_flag=0;
dc_flag=1;
}


read_adc_1();
}

}


void read_adc_1(void)
{
ADRESH=0x00;
	CHS2 = 0;
    CHS1 = 0;
    CHS0 = 0;
for (i=0;i<250;++i);
	ADGO=1;
while(ADGO);
	adc=0;
	
	adc = ADRESH;
	data = ((5.0/255)*adc);
	datat=(data*199)+data;
Set_LCD_Command(LCD_ROW2);
//	lcd_num_float(datat);
//lcd_puts(" ");
//lcd_num_float(data);
//lcd_puts(" ");

if(temp!=datat)
{
temp=datat;
if(data<0.10)
{
RD0=1;
RD1=0;



ADRESH=0x00;
	CHS2 = 0;
    CHS1 = 0;
    CHS0 = 1;
for (i=0;i<250;++i);
	ADGO=1;
while(ADGO);
	adc=0;	
	adc = ADRESH;
	data1 = ((5.0/255)*adc);
	datar=(data1*3)+data1;
	lcd_num_float(datar);

if(ac_flag==1)
lcd_puts(" AC V");
else if(dc_flag==1)
lcd_puts(" DC V");


RD0=0;

}
else if((data>0.10)&&(data<1.01))
{
RD1=1;
RD0=0;

ADRESH=0x00;
	CHS2 = 0;
    CHS1 = 0;
    CHS0 = 1;
for (i=0;i<250;++i);
	ADGO=1;
while(ADGO);
	adc=0;	
	adc = ADRESH;
	data1 = ((5.0/255)*adc);
	datar=(data1*39)+data1;
	lcd_num_float(datar);
if(ac_flag==1)
lcd_puts(" AC V");
else if(dc_flag==1)
lcd_puts(" DC V");
RD1=0;
}

else if(data>1.01)
{

RD0=RD1=0;

	lcd_num_float(datat);
if(ac_flag==1)
lcd_puts(" AC V");
else if(dc_flag==1)
lcd_puts(" DC V");


}

}


}
