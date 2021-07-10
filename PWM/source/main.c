#include<reg51.h>
sbit pwm=P0^0;
void delay();
void main()
{
	pwm=0;	// initialising t=0 for toggling purpose
	while(1)
	{
		pwm=~pwm;
		delay();
	}
}

void delay()
{
	TMOD |= 0X01;	// setting Timer0 in 16 bit mode
	TH0 = 0xFC;
	TL0 = 0x67;
	TR0 = 1;
	while(!TF0);
	TR0 = 0;
	TF0 = 0;

}