#include<stdio.h>
#include<pic.h>




#define on 0XFF
#define off 0X00

#define row1 RD3
#define row2 RD4
#define row3 RD5
#define row4 RD6

#define col1 RD0
#define col2 RD1
#define col3 RD2

#define key PORTB

#define on 0XFF
#define off 0X00


void config_io(void)
{
TRISB=0X00;
TRISD3=TRISD4=TRISD5=TRISD6=TRISD7=0;
TRISD0=TRISD1=TRISD2=1;
key=0x00;
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


/*key=off;
delay();
key=0X0C;
delay();
key=0XB6;
delay();
key=0X9E;
delay();
key=0XCC;
delay();
key=0XDA;
delay();
key=0XFA;
delay();
key=0X4E;
delay();
key=0XFF;
delay();
key=0XDE;
delay();
key=0X7F;
delay();*/


row1=1;
RD7=1;
if(col1==1)
key=0X0C;
else if(col2==1)
key=0XB6;
else if(col3==1) 
key=0X9E;
RD7=0;
row1=0;


row2=1;
RD7=1;
if(col1==1)
key=0XCC;
else if(col2==1)
key=0XDA;
else if(col3==1) 
key=0XFA;
RD7=0;
row2=0;



row3=1;
RD7=1;
if(col1==1)
key=0X4E;
else if(col2==1)
key=0XFF;
else if(col3==1) 
key=0XDE;
RD7=0;
row3=0;


row4=1;
if(col1==1)
{

key=0X7F;
delay();
key=0XDE;
delay();
key=0XFF;
delay();
key=0X4E;
delay();
key=0XFA;
delay();
key=0XDA;
delay();
key=0XCC;
delay();
key=0X9E;
delay();
key=0XB6;
delay();
key=0X0C;
delay();

}
else if(col2==1)
key=0X7F;
else if(col3==1)
{

key=off;
delay();
key=0X0C;
delay();
key=0XB6;
delay();
key=0X9E;
delay();
key=0XCC;
delay();
key=0XDA;
delay();
key=0XFA;
delay();
key=0X4E;
delay();
key=0XFF;
delay();
key=0XDE;
delay();
key=0X7F;
delay();

}
RD7=0;
row4=0;

}
}
