#include<pic.h>
#include "dd_lcd.h"

//void interrupt receive_isr();

void main(void)
{
char data,str,i;
Config_IO();
Init_LCD();
clr_lcd();
Set_LCD_Command(LCD_ROW1);
SPBRG=129;
BRGH=1;
SYNC=0;
SPEN=1;
CREN=1;
RX9=0;
RCIF=0;
RCIE=0;
while(1)
	{

if(RCIF==1)
		{
RCIF=0;
data=RCREG;
if(data=='<')
			{
lcd_puts("started");
clr_lcd();
while(data!='>')
{

if(RCIF==1)
		{

RCIF=0;
data=RCREG;
Set_LCD_Data(data);		
}
		}

clr_lcd();
lcd_puts("stopped");


			}
		}
	}
}






/*



if(data=='<')
			{
lcd_puts("started");
clr_lcd();
while(data!='>')
{
if(RCIF==1)
	{
RCIF=0;
data=RCREG;
//	}
//else if(data!='>')
Set_LCD_Data(data);
	}
lcd_puts("  stopped");
clr_lcd();
}
			}
		}
	}


}



*/

