#include<reg51.h>
sbit switch1=P1^0;
sbit switch2=P1^1;
sbit switch3=P1^2;
sbit switch4=P1^3;
sbit switch5=P1^4;

void main()
{
	P1=0x00;
	P2=0x00;
	while(1)
	{
		if(switch1==1)
		{
			P2=0x09;	//1001
		}
		if(switch2==1)
		{
			P2=0x04;		//0100	motor2 reverse
//			P2=0x02;	//0010 motor1 reverse
		}
		if(switch3==1)
		{
			P2=0x01;	//0001
		}
		if(switch4==1)
		{
			P2=0x06;	//0101
		}
		if(switch5==1)
		{
			P2=0x00;//0000
		}
	}	
}