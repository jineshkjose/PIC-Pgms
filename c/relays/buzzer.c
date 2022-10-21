#include<pic.h>


#define on 1
#define off 0
#define sw1 RB0
#define sw2 RB1
#define open 0
#define close 1
#define buzzer RB5

void config(void);

void main(void)
{
unsigned int i;
config();
while(1)
{

for(i=0;i<65000;i++)
{

PORTB=0X00;
}
for(i=0;i<65000;i++)
{

PORTB=0XFF;
}
}
}


void config(void)
{
TRISB=0x00;
PORTB=0X00;
}
