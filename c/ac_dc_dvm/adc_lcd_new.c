#include<pic.h>
#include "dd_lcd.h"

float data1=0,data2=0,datat=0;
unsigned char adc;
void read_adc_c1(void);
void read_adc_c2(void);
void read_adc_c3(void);
void read_adc_c4(void);
int flag1=0,flag2=0,flag3=0,flag4=0,i=0;

int main(void)



{
	
//	int i;

	TRISA=0xFF;
	//TRISC=0xFF;
	ADCON0=0X81;
	ADCON1=0X00;
	Config_IO();
	Init_LCD();
	clr_lcd();
Set_LCD_Command(LCD_ROW1);
LCD_Scrol_String("DIGITAL VOLT METER");
//	lcd_puts("Result     =");
while(1)
{
ADRESH=0x00;
/*clr_lcd();
for (i=0;i<250;++i);
	
clr_lcd();
ADRESH=0X00;


adc=0;
CHS2 = 0;
CHS1 = 0;
CHS0 = 1;
ADGO=1;
	while(ADGO);
	adc = ADRESH;
	data2 = ((5.0/255)*adc);
	datat=(data2*3)+data2;
	lcd_num_float(datat);

lcd_puts(" DC V");
	
adc=0;
	CHS2 = 0;
CHS1 = 0;
CHS0 = 0;


	*/


read_adc_c1();
read_adc_c2();
read_adc_c3();
read_adc_c4();
	 
if((flag1==1)&&(flag2==1)&&(flag3==1)&&(flag4==1))
  LCD_Scrol_String("input is empty");

}



	
//return 0;

}

void read_adc_c1(void)
{
	ADRESH=0x00;
	CHS2 = 0;
    CHS1 = 0;
    CHS0 = 0;
for (i=0;i<250;++i);
ADGO=1;
	while(ADGO);
	//adc=0;
	adc = ADRESH;
	
	data1 = ((5.0/255)*adc);
	if(data1!=0)
{
Set_LCD_Command(LCD_ROW1);
LCD_Scrol_String(" ADC channel 0 ");
Set_LCD_Command(LCD_ROW2);
	lcd_num_float(data1);
lcd_puts(" DC V");
;

flag1=0;

}
else
flag1=1;
}

void read_adc_c2(void)
{
ADRESH=0x00;
	CHS2 = 0;
    CHS1 = 0;
    CHS0 = 1;
for (i=0;i<250;++i);
	ADGO=1;
while(ADGO);
	adc=0;
	
	adc = ADRESH;
	data2 = ((5.0/255)*adc);
	datat=(data2*3)+data2;
if(data2!=0)

{
Set_LCD_Command(LCD_ROW1);
LCD_Scrol_String("ADC channel 1 ");
Set_LCD_Command(LCD_ROW2);
	lcd_num_float(datat);
lcd_puts(" DC V");
flag2=0;
Set_LCD_Command(LCD_ROW1);

}
else
flag2=1;
}


void read_adc_c3(void)
{
ADRESH=0x00;
	CHS2 = 0;
    CHS1 = 1;
    CHS0 = 0;
for (i=0;i<250;++i);
	ADGO=1;
while(ADGO);
	adc=0;
	
	adc = ADRESH;
	data2 = ((5.0/255)*adc);
	datat=(data2*39)+data2;
if(data2!=0)

{
Set_LCD_Command(LCD_ROW1);
LCD_Scrol_String("ADC channel 2 ");
Set_LCD_Command(LCD_ROW2);
	lcd_num_float(datat);
lcd_puts(" DC V");
flag3=0;
Set_LCD_Command(LCD_ROW1);

}
else
flag3=1;
}


void read_adc_c4(void)
{
ADRESH=0x00;
	CHS2 = 0;
    CHS1 = 1;
    CHS0 = 1;
for (i=0;i<250;++i);
	ADGO=1;
while(ADGO);
	adc=0;
	
	adc = ADRESH;
	data2 = ((5.0/255)*adc);
	datat=(data2*199)+data2;
if(data2!=0)

{
Set_LCD_Command(LCD_ROW1);
LCD_Scrol_String("ADC channel 3 ");
Set_LCD_Command(LCD_ROW2);
	lcd_num_float(datat);
lcd_puts(" DC V");
flag4=0;
Set_LCD_Command(LCD_ROW1);

}
else
flag4=1;
}
