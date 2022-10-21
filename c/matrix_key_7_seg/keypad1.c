#include<pic.h>


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

void main (void)
{

int i=0;
TRISD3=TRISD4=TRISD5=TRISD6=TRISD7=0;
TRISD0=TRISD1=TRISD2=1;
TRISB=0X00;
//key=0XFF;

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


/*row1=1;
RD7=1;
if(col1==1)
PORTB=0X0C;
else if(col2==1)
PORTB=0XB6;
else if(col3==1) 
PORTB=0X9E;
RD7=0;
row1=0;


row2=1;
RD7=1;
if(col1==1)
PORTB=0XCC;
else if(col2==1)
PORTB=0XDA;
else if(col3==1) 
PORTB=0XFA;
RD7=0;
row2=0;



row3=1;
RD7=1;
if(col1==1)
PORTB=0X4E;
else if(col2==1)
PORTB=0XFF;
else if(col3==1) 
PORTB=0XDE;
RD7=0;
row3=0;


row4=1;
if(col1==1)
key='*';
else if(col2==1)
PORTB=0X7F;
else if(col3==1)
key='#';
RD7=0;
row4=0;*/

 
}
}
void delay(void)
{
unsigned int delay;
for(delay=0;delay<65000;delay++);
}
