#include<stdio.h>
#include<pic.h>

#define butten RC0
#define led PORTB

#define on 0XFF
#define off 0X00

#define close 1
#define open 0

void config_io(void)
{
TRISB=0X00;
}

void main(void)
{
config_io();
led=on;
while(1)
{
if(butten==1)
led=on;
else
led=off;
}
}
