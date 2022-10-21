#include<pic.h>
#include "delay.h"

void SPI_Init(void);
char data;

main()
{
	TRISC = 0X00;
	TRISD=0X00;
	PORTD=0X00;
	TRISC4 = 1;
	data=0x00;
	SPI_Init();
	while(1)
{
SSPBUF=0x07;
PORTD=SSPBUF;
while(!STAT_BF);
DelayMs(1);
}
}

void SPI_Init(void)
{
  SSPSTAT = 0x00;
  SSPCON = 0b00100010; //the config word for this register will change based on the clock polarity, and clock edge
}

