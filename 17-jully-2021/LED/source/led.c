
#include<reg51.h>
void main()
{
	unsigned int i;
	while(1)
	{
		P2=0x00;
		for(i=0;i<30000;i++);
		P2=0x07;
		for(i=0;i<30000;i++);
	}
}


//  Curtain effect //
/*		
#include "REG52.h"
void delay();
void main()
{
	while(1)
	{
		P2=0x81;         //different values on LEDs
		delay();
		P2=0xC3;        //different values on LEDs
		delay();
		P2=0xE7;        //different values on LEDs
		delay();
		P2=0xFF;        //different values on LEDs
		delay();
		P2=0xE7;        //different values on LEDs
		delay();
		P2=0xC3;        //different values on LEDs
		delay();
		P2=0x81;        //different values on LEDs
		delay();
		P2=0x00;        //different values on LEDs
		delay();
	}
} 

void delay()              // delay function
{
	long int k;
	for(k=0;k<30000;k++);
}
*/