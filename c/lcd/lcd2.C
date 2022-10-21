#include<pic.h>
void en(void);
void send_command(void);
void send_data(void);
void clr1(void);
int i;
main()

{
	TRISD=0X00;
	TRISC=0X00;

	
inf:

	send_command();
	PORTD=0X38;
	en();
	send_command();
	PORTD=0X0C;
	en();
	send_command();
	PORTD=0X01;
	en();
	send_command();
	PORTD=0X06;
	en();

	send_command();
	PORTD=0X80;
	en();
	send_data();  
    PORTD='J';
	en();
	send_data();  
    PORTD='I';
	en();
	send_data();  
    PORTD='N';
	en();
	send_data();  
    PORTD='E';
	en();
	send_data();  
    PORTD='S';
	en();
	send_data();  
    PORTD='H';
	en();

/*	en();
	send_command();
    PORTD=0XC0;
	en();
	send_data();
    PORTD='2';



	/*send_data();
	PORTD='F';
	en();
	send_data();
	PORTD='O';
	en();
	send_data();
	PORTD='C';
	en();
	send_data();
	PORTD='U';
	en();
	delay2();
	PORTD='Z';
	en();
	delay2();
	PORTD=' ';
	en();
	delay2();
	PORTD='I';
	en();
	delay2();
	PORTD='N';
	en();
	delay2();
	PORTD='F';
	en();
	delay2();
	PORTD='O';
	en();
delay2();
	PORTD='T';
	en();
	delay2();
	PORTD='E';
	en();
	delay2();
	PORTD='C';
	en();
	delay2();
	PORTD='H';
	en();
	delay2();
	PORTD=' ';
	en();
	delay2();
    PORTD=' ';
	en();
	delay2();
	PORTD='M';
	en();
	send_command();
	PORTD=0XC0;
	en();
	delay2();
	PORTD='a';
	en();
	delay2();
	PORTD='m';
	en();
	delay2();
	PORTD='a';
	en();
	delay2();
	PORTD='n';
	en();
delay2();
	PORTD='g';
	en();
	delay2();
	PORTD='a';
	en();
	delay2();
	PORTD='l';
	en();
	delay2();
	PORTD='a';
	en();
	delay2();
	PORTD='m';
	en();
delay2();
	PORTD=',';
	en();
	PORTD='E';
	en();
	delay2();
	PORTD='r';
	en();
	delay2();
	PORTD='n';
	en();
	delay2();
	PORTD='a';
	en();
delay2();
	PORTD='k';
	en();
	delay2();
	PORTD='u';
	en();
	delay2();
	PORTD='l';
	en();
	delay2();
	PORTD='a';
	en();
	delay2();
	PORTD='m';*/
	//en();
	//for(i=0;i<25000;i++);
	
goto inf;
}


void en(void)
{
RC2=1;
for(i=0;i<250;i++);
RC2=0;
for(i=0;i<25000;i++);
}

void send_command(void)  //FOR COMMAND
{
RC0=0;
RC1=0;
}
void send_data(void)   //FOR DATA
{
RC0=1;
RC1=0;
}


void clr1(void)
{
send_command();
PORTD=0X01;
en();
}
	
