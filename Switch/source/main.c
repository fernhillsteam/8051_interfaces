#include<reg51.h>
sbit switch_pin=P1^3;
sbit LED = P2^0;
//sfr LED=0xB0;
#define ON 1;
#define OFF 0;
void delay();
void main()
{
			P1=0x00;
		P2=0x00;
	while(1)
	{
/*		switch_pin=OFF;
		LED=0x00;
		delay();
		switch_pin=ON;
		LED=0xFF;
		delay();*/
	if(switch_pin==1)
	{
	LED=1;
	}
	else
		LED=0;
		
		
	}
}	  
void delay()
{
unsigned int i;
for(i=0;i<1500;i++);
}