#include<stdio.h>
#include<pic.h>

void adc_init();
unsigned char adc_convert();

void main()
{
	CCP1CON	= 0X0F;		// PWM Mode Selected
	T2CON		= 0X00;	// TMR2 Prescaler = 1:1, Turned OFF
	PR2		= 255;	// Period of PWM
	CCPR1L		= 0;	// 'ON' Time of PWM
	TRISC2		= 0X00;	
	TMR2ON		= 0X01;
TRISD0=0;
TRISD1=0;
	while(1)
	{
	RD0=0;
	RD1=1;
		while(TMR2IF)
		{
			TMR2IF	= 0x00;
			CCPR1L	= adc_convert();
		}
	}		
}

void adc_init()
{
	ADCON0		= 0X81;	// Clock = fosc/2,Channel = 0, GO_DONE = 0, A2D Module Turned 'ON'
	ADCON1		= 0X80;	// A/D Result Format Right Justified, AN0 to AN7 Configured as Analog Input, Vref = VDD
	TRISA		= 0X00;	// Port A Configured as Output
}

unsigned char adc_convert()
{
	char i;
	adc_init();		// ADC Initialized
	for (i=0; i<10; i++);	// ADC Initializing Delay
	ADGO	= 0X01;		// Conversion Initialized
	while(ADGO);		// Waiting for Conversion Completion
	ADON	= 0x00;		// ADC Turned 'OFF'
	return (ADRESL);	// Digital Value Returned
}
