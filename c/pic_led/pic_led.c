#include<stdio.h>
#include<pic.h>

#define butten1 RC0
#define butten2 RC0

#define led1 RB0
#define led2 RB1


#define on 1
#define off 0

#define close 1
#define open 0

void main(void)
{

TRISC=0XFF;
TRISB=0X00;


while(1)
{

if(butten1==close)
{
led1=on;
led2=on;
}
else
{
led1=off;
led2=off;
}
}
}
