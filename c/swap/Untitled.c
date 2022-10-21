#include<stdio.h>
#include<pic.h>
void main(void)
{
	void swap(char *,char *);	
	char a=4,b=3;	
	swap(&a,&b);
}
void swap(char *p,char *q)
{
	char temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
