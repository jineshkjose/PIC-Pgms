#include<pic.h>
#include "delay.h"

void SPI_Init(void);

main()
{
	TRISC = 0X00;
	TRISB = 0X00;
	PORTB = 0x00;
	TRISC4 = 1;
	TRISC3 = 1;
	SPI_Init();
	
	while(1)
{
	while(!STAT_BF);
   	PORTB = SSPBUF;
}
}

void SPI_Init(void)
{
   SSPSTAT = 0x00;
   SSPCON = 0b00100101; //the config word for this register will change based on the clock polarity, and clock edge
}



