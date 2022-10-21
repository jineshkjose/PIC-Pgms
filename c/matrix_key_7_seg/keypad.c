#include<pic.h>


#define row1 RD3
#define row2 RD4
#define row3 RD5
#define row4 RD6

#define col1 RD0
#define col2 RD1
#define col3 RD2

#define key PORTB

void main (void)
{

int i=0;
TRISD3=TRISD4=TRISD5=TRISD6=TRISD7=0;
TRISD0=TRISD1=TRISD2=1;
//PORTD=0X00;
key=0X00;

while(1)
{



row1=1;
RD7=1;
if(col1==1)
{
key='1';
for(i=0;i<30000;i++);
}
else if(col2==1)
{
key='2';
for(i=0;i<30000;i++);
}
else if(col3==1) 
{
key='3';
for(i=0;i<30000;i++);
}
RD7=0;
row1=0;

for(i=0;i<30000;i++);
row2=1;
RD7=1;
if(col1==1)
{
key='4';
for(i=0;i<30000;i++);
}
else if(col2==1)
{
key='5';
for(i=0;i<30000;i++);
}
else if(col3==1) 
{
key='6';
for(i=0;i<30000;i++);
}
RD7=0;
row2=0;


for(i=0;i<30000;i++);
row3=1;
RD7=1;
if(col1==1)
{
key='7';
for(i=0;i<30000;i++);
}
else if(col2==1)
{
key='8';
for(i=0;i<30000;i++);
}
else if(col3==1) 
{
key='9';
for(i=0;i<30000;i++);
}
RD7=0;
row3=0;

for(i=0;i<30000;i++);
row4=1;
if(col1==1)
{
key='*';
for(i=0;i<30000;i++);
}
else if(col2==1)
{
key='0';
for(i=0;i<30000;i++);
}
else if(col3==1) 
{
key='#';
for(i=0;i<30000;i++);
}
RD7=0;
row4=0;
for(i=0;i<30000;i++);

 
}
}
