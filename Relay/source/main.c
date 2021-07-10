
/*-----------8051 C Sample Program to Control Relay ON/OFF through a Switch-----*/


#include<reg51.h>		// Header Declaration
void delay_ms(unsigned int ms); 	// Delay Declaration
sbit SWT2 = P2^0;  //Switch Input
sbit RELAY = P3^4;  //RELAY Output

void main(void)
{
	while(1)
	{
		if(SWT2 == 0)
		{
			RELAY = 1;
		}
		else
		{
			RELAY = 0;
		}
	}
}
 
