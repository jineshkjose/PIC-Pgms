#include<pic.h>
static void interrupt seg_isr(void);
unsigned char a  = 0;
main()
{
	TRISD=0;
	PORTD=0;
	SPBRG=129;
	BRGH=1;
	SYNC=0;
	CREN=1;
	SPEN=1;
	RCIF=0;
	RCIE=1;
	GIE=1;
	PEIE=1;

	while(1)
		{
			if(a=='1')
			{
			    PORTD=0X0C;

							}
			if(a=='2')
			{
                PORTD=0XB6;
			
			}
			
				if(a=='3')
			{
			PORTD=0X9E;
				
			}	
				if(a=='4')
			{PORTD=0XCC;
				
				
			}
				if(a=='5')
			{

               PORTD= 0XDA;
				
				
			}
				if(a=='6')
			{PORTD=0XFA;
			
				
			}
				if(a=='7')
			{PORTD=0X4E;
				
				
			}
				if(a=='8')
			{
			PORTD=0XFF;
				
			}
				if(a=='9')
			{
				PORTD=0XDE;
			}
				if(a=='0')
			{
				PORTD=0X7F;
				
			}
		}
}
	
static void interrupt seg_isr(void)
{
	GIE = 0;
	if(RCIF)	
	{
		RCIF=0;
		a=RCREG;
	}
	GIE = 1;
}