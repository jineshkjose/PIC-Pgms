#include<stdio.h>
#include<pic.h>




#define on 0XFF
#define off 0X00


void config_io(void)
{
TRISB=0X00;
}

void delay(void)
{
unsigned int delay;
for(delay=0;delay<65000;delay++);
}



void main(void)
{
config_io();
 
while(1)
{


PORTB=off;
delay();
PORTB=0X0C;
delay();
PORTB=0XB6;
delay();
PORTB=0X9E;
delay();
PORTB=0XCC;
delay();
PORTB=0XDA;
delay();
PORTB=0XFA;
delay();
PORTB=0X4E;
delay();
PORTB=0XFF;
delay();
PORTB=0XDE;
delay();
PORTB=0X7F;
delay();

}
}
