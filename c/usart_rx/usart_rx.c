#include<pic.h>

static interrupt receive_isr();

void main(void)
{
TRISD=0X00;

PORTD=0X00;
SPBRG=129;
BRGH=1;
SYNC=0;
SPEN=1;
CREN=1;
RX9=0;
RCIF=0;
RCIE=1;
GIE=1;
PEIE=1;
while(1)
{
}
}


static interrupt receive_isr()
{
if(!RCIF);
else
{
RCIF=0;
PORTD=RCREG;
}
}
