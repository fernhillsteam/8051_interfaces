
/*-----------8051 C Sample Program to Control Relay ON/OFF through a Switch-----*/


#include<reg51.h>		// Header Declaration
void delay_ms(unsigned int ms); 	// Delay Declaration
sbit SWT2 = P2^0;  //Switch Input
sbit RELAY = P3^4;  //RELAY Output

void main(void)
{
	SWT2 = 1;	// set P0.0 as an Input Port
	RELAY = 0;	// set P3.4 as an Output Port
	while(1)
	{
		if(SWT2 == 0)
			{
				RELAY = ~RELAY;
				while(SWT2 == 0);		//Switch Debounce Loop
				delay_ms(200);
			}
	}
}

void delay_ms(unsigned int ms)
{
   unsigned int i,j;
   for(i=0; i<ms; i++);
   for(j=0; j<711; j++); 
}   
