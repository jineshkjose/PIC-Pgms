#include<stdio.h>
#include<pic.h>

void main(void)
{	
	TRISA		= 0X01;
	TRISD		= 0x00;
	ADCON0		= 0X81;			// Clock = fosc/2,Channel = 0, GO_DONE = 0, A2D Module Turned 'ON'
	ADCON1		= 0X80;			// A/D Result Format Right Justified, AN0 to AN7 Configured Analog Input, Vref = VDD
	//ADGO=1;
	ADON=1;	

while(1)
{
ADGO=1;
	if(ADGO==0)	
	PORTD	= ADRESL;
}
}

	
	



	
