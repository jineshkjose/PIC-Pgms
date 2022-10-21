#include<pic.h>

void main(void)
{
PR2=0X27;	//0X7F
CCPR1L=0X14;//0X3F
CCP1CON=0X0F;
TRISC2=0X00;
T2CON=0X00;
TMR2ON=0X00;
while(1);
}
