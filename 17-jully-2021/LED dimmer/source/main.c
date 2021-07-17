#include<reg51.h>
sbit Pwm_Pin=P1^0;
char h1=0xEB,l1=0xFF;

void Pwm_High()
{
	Pwm_Pin=1;    //High signal
	while(!TF0);  //Wait for T0 Interrupt Flag
	TF0=0;        //Clear Interrupt Flag
	TH0=h1;     //Load new TH0 Value
	TL0=l1;     //Load new TL0 value

	Pwm_Pin=0;   //Low signal 
	while(!TF0); //Wait for T0 Interrupt Flag
	TF0=0;       //Clear Interrupt Flag
}

void main()
{
	char high,low;
	int i=0,j=0;
	P1=0x00;  //**** Port-1 Declared Output
	TMOD=0x01; //Timer-0, As 16-bit Timer.
	while(1)
	{
		high=0xFF;
		low=0xFF;
		h1=0xEB;
		l1=0xFF;
		i=0;
		TR0=1;       //Run Timer-0

		for(i=0;i<=20;i++)
		{
			for(j=0;j<=50;j++)
			{
				TH0=high;
				TL0=low;
				Pwm_High();
			}
			high--;
			h1++;
		}		
	}
}