#include <pic.h>
#include "delay.h"
#include "dd_lcd.h"

void timer_init(void);
void portd_init(void);
static interrupt timer_isr(void);
unsigned int count;

float data;
unsigned char adc,ss,mm,hh;
int flag=0;

main()
{
	timer_init();
	portd_init();
	count=0;

	lcd_config();
	lcd_init();
	DelayMs(20);
	lcd_clear();

	DelayMs(20);
	ss=mm=hh=0;


	PEIE = 1;
	GIE = 1;
	TMR1ON = 1;

while(1)
{



lcd_goto(0X00);
if(hh<10)
lcd_puts("0");
lcd_num_dec(hh);
lcd_puts(":");
if(mm<10)
lcd_puts("0");
lcd_num_dec(mm);
lcd_puts(":");
if(ss<10)
lcd_puts("0");
lcd_num_dec(ss);


if(flag==1)
{
ss++;
if(ss==60)
{
ss=0;
lcd_clear();
mm++;
if(mm==60)
{
mm=0;
lcd_clear();
hh++;
if(hh==12)
{
ss=mm=hh=0;
lcd_clear();
}
}
}
flag=0;
}




}
}

void timer_init(void)
{
	T1CON = 0x00;
	TMR1L = 0x78;
	TMR1H = 0xEC;
	TMR1IE = 1;
	TMR1IF = 0;
}

void portd_init(void)
{
	TRISD = 0x00;
	PORTD = 0x00;
}

static interrupt timer_isr(void)
{
	if(TMR1IF == 0)
		{
		//return(0);
		}
	else
		{
			TMR1IF = 0;
			
if(count==2000)
{
flag=1;
count=0;
}
			TMR1L = 0x3c;
			TMR1H = 0xf6;
			count++;
			
			//return(1);
		}
}
