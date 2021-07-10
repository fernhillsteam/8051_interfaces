#include<reg51.h>
sbit CLK = P3^0;
sbit ACLK = P3^1;
void delay(int n);

void main()
{
	while(1)
	{
		if(CLK == 0)	
		{
			P2 = 0x66;
			delay(50);
			P2 = 0xCC;
			delay(50);
			P2 = 0x99;
			delay(50);
			P2 = 0x33;
			delay(50);
		}
		
		if(ACLK == 0)	
		{
			P2 = 0x66;
			delay(50);
			P2 = 0x33;
			delay(50);
			P2 = 0x99;
			delay(50);
			P2 = 0xCC;
			delay(100);
		}
	}
}
void delay(int n)
{
	unsigned int i,j;
	for(i=0;i<1275;i++)
	for(j=0;j<n;j++);
}