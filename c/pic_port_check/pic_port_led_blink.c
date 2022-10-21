#include<stdio.h>
#include<pic.h>


#define led_array1 PORTA
#define led_array2 PORTB
#define led_array3 PORTC
#define led_array4 PORTD

#define on 0XFF
#define off 0X00


void config_io(void)
{
ADCON1=0X06;
TRISA=0X00;
TRISB=0X00;
TRISC=0X00;
TRISD=0X00;
}

void delay(void)
{
unsigned int delay;
for(delay=0;delay<60000;delay++);

}
void main(void)
{
config_io();
led_array1=off; 
led_array2=off; 
led_array3=off; 
led_array4=off; 
while(1)
{
led_array1=on; 
delay();
led_array1=off; 
delay();
led_array2=on; 
delay();
led_array2=off; 
delay();
led_array3=on; 
delay();
led_array3=off;
delay();
led_array4=on; 
delay();
led_array4=off; 
delay();

}
}
