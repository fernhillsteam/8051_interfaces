#include<reg51.h>
sbit a=P3^0;
sbit b=P3^1;
sbit c=P3^2;
sbit d=P3^3;

void delay();

void main()
{
	while(1)
	{

		a=0;
		b=1;
		c=1;
		d=1;
		delay();
		a=1;
		b=0;
		c=1;
		d=1;
		delay();
		a=1;
		b=1;
		c=0;
		d=1;
		delay();
		a=1;
		b=1;
		c=1;
		d=0;

	}
}

void delay()
{

unsigned char i,j,k;
for(i=0;i<6;i++)
for(j=0;j<255;j++)
for(k=0;k<255;k++);

}