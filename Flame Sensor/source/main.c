//
// *  Name     : main.c
// *  Purpose  : Program to Flame Sensor interfacing With 8051
// *  Author   : Sunil Pawar
// *  Date     : 14-07-2021
// */
#include<reg51.h>
sbit LED_pin = P2^0;
sbit switch_pin = P2^1;
void delay(int);
void main()
{
	switch_pin =1;
	LED_pin = 1;
	while(1)
	{
		if(switch_pin ==0)
		{
			LED_pin = 0;
			delay(2000);
			LED_pin = 1;
		}
	}
}
void delay(int time)
{
	int i,j;
	for(i=0;i<time;i++);
	for(j=0;j<100;j++);
}