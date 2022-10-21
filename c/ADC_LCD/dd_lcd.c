
#include <pic.h>
#include "dd_lcd.h"
#include <stdio.h>

#define	LCD_STROBE	((LCD_EN = 1),(LCD_EN=0))

void Config_IO(void)
{
//ADCON1=0X06;
    TRISB=0X00;
	TRISC=0X00;



	
}


   
void LCD_Scrol_String(const char *str)
{
Set_LCD_Command(0x8f);
 while(*str)
  {
    Set_LCD_Data(*str++);
    Set_LCD_Command(0x1C);	 
LCD_Delay_Scrol();
   }	 
LCD_Delay_Scrol();
Set_LCD_Command(LCD_CLEAR);




}


void LCD_Delay_Scrol(void)
{
 signed int ctr;
 for(ctr=0;ctr<=4000;ctr++);

}

void Set_LCD_Command(unsigned char lcd_cmd)
{

  	LCD_COMMAND_DATA=lcd_cmd;
  	LCD_RS=0;
  	lcd_en();
 
}

void Set_LCD_Data(char lcd_data)
{
	
    LCD_COMMAND_DATA=lcd_data;
    LCD_RS=1;
    lcd_en();
}

void Init_LCD(void)
{
	Set_LCD_Command(LCD_INIT);
	Set_LCD_Command(LCD_DISPLAY_ON);
	Set_LCD_Command(LCD_CLEAR);
}

 void LCD_Delay(void)
{
 	unsigned int lcd_dly_ctr;
 	for(lcd_dly_ctr=0;lcd_dly_ctr <=60000;lcd_dly_ctr++);
}

void lcd_en(void)
{   
	LCD_EN=0;
	LCD_EN=1;
	LCD_Delay();
	LCD_EN=0;
	
}



void clr_lcd(void)
{

	Set_LCD_Command(LCD_CLEAR);
	lcd_en();
}


void lcd_puts(const char * s)
{
	//LCD_RS = 1;	// write characters
//	lcd_en();
	while(*s)
		Set_LCD_Data(*s++);
}

void lcd_goto(unsigned char pos)
{
	LCD_RS = 0;
	Set_LCD_Data(0x80+pos);
}


void Set_LCD_Num(int num)
{
unsigned char d1,d2,d3;

	d1=(num/100)|0X30;
  num=num%100;

  d2=(num/10)|0X30;
  d3=(num%10)|0X30;


  Set_LCD_Data(d1);
  Set_LCD_Data(d2);
  Set_LCD_Data(d3);


}


void lcd_write(unsigned char c)
{
	PORTD = (PORTD & 0xF0) |  (c >> 4);
	LCD_STROBE;
	PORTD = (PORTD & 0xF0) |  (c & 0x0F);
	LCD_STROBE;
	LCD_Delay();
}

void lcd_num_float(float num)
{
float temp[6];
sprintf(temp,"%0.2f",num);
lcd_puts(temp);

}
