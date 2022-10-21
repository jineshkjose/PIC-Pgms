#include<stdio.h>
#include<pic.h>

#define butten1 RC0
#define butten2 RC1

#define led1 RB0
#define led2 RB1


#define on 1
#define off 0

#define close 1
#define open 0

void config_io(void)
{
TRISB=0X00;
TRISC=0XFF;
}

void main(void)
{
config_io();



while(1)

	{
RB2=1;
if((butten1==close)&&(butten2==close))
{
led1=on;
led2=on;
}
else if((butten1==close)&&(butten2==open))
{
led1=on;
led2=off;
}
else if((butten1==open)&&(butten2==close))
{
led1=off;
led2=on;
}
else if ((butten1==open)&&(butten2==open))
{
led1=off;
led2=off;
}

	}
}
