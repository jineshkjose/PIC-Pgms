#include<stdio.h>
#include<pic.h>
	void swap(char *,char *);
void main(void)
{
	
	char a=4,b=3;	
	swap(&a,&b);
}
void swap(char *p,char *q)
{
	char temp;
	temp=*p;
	*p=*q;
	*q=temp;
}
