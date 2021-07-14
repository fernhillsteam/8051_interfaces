// *  Name     : main.c
// *  Purpose  : Program to sounds with AT89C52.
// *  Author   : Sunil Pawar
// *  Date     : 09-07-2021
// */

#include<reg51.h> // Header File
sbit pin_1 = P2^0; // Single bit define for pin 1
void delay(int time) // Delay Function
{
	int i,j;
	for(i=0;i<time;i++)
	for(j=0;j<1275;j++);
}

void main()
{
	while(1)
	{
		pin_1 = 0; // on
		delay(100);
		pin_1 = 1; // off
		delay(100);
	}
}