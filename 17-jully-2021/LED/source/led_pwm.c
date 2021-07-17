#include<reg51.h>
sbit Pwm_Pin=P1^0;

void Pwm_Low()
{
Pwm_Pin=0;
TH0=0xFF;
TL0=0x47;
TR0=1;       //Run Timer-0
while(!TF0); //Wait for T0 Interrupt Flag
TF0=0;       //Clear Interrupt Flag
TR0=0;       //Stop Timer-0
}


void Pwm_High()
{
TR0=1;       //Run Timer-0
while(!TF0); //Wait for T0 Interrupt Flag
TF0=0;       //Clear Interrupt Flag
TR0=0;       //Stop Timer-0

Pwm_Low();
}

void main()
{
P1=0x00;

	TMOD=0x01; //Timer-0, As 16-bit Timer.

	while(1)
	{	
	Pwm_Pin=1;
	TH0=0xFF;
	TL0=0xDA; 
	Pwm_High();
	}
}