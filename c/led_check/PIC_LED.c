#include<pic.h>


void delay_start(void);
void main(void)
{

TRISA=0X00;
TRISB=0X00;
TRISC=0X00;
TRISD=0X00;
while(1)
{
PORTB=0XFF;
 delay_start();
PORTD=0X00;
delay_start();
PORTD=0XFF;
 delay_start();
PORTB=0X00;
 delay_start();
}
}

void delay_start(void)
{
unsigned int delay=0;
for(delay=0;delay<60000;delay++);
}
