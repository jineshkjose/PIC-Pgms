#include<pic.h>
void timer_init(void);
void portd_init(void);
static interrupt timer_isr(void);
unsigned int count;
main()
{
	timer_init();
	portd_init();
	count=0;
	PEIE = 1;
	GIE = 1;
	TMR1ON = 1;
loop:
	goto loop;
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
			//PORTD = ~PORTD;

if(count==1000)
{
PORTD = ~PORTD;
count=0;
}
			TMR1L = 0x3c;
			TMR1H = 0xf6;
			count++;
			
			//return(1);
		}
}
