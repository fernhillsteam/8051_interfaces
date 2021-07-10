// *  Name     : main.c
// *  Purpose  : Source code for Serial EEPROM AT24C02 with AT89C51.
// *  Author   : Sunil Pawar
// *  Date     : 09-07-2021
// */
 
#include <reg51.h>
#include "lcd.h"			              
#include "i2c.h"

sbit led=P3^5;
sbit led1=P3^6;
sbit SW1=P3^7;
sbit SW2=P1^2;
sbit SW3=P1^3;
sbit SW4=P1^4;

int main()
{		
	lcd_ini();
	lcd_dataa("Sent :");
	lcd_command(0xC0);
	lcd_dataa("Read :");
	while(1)
	{
		if(SW1==0)
		{
			save();
		}
		if(SW2==0)
		{
			led1=0;
			Read();
			led1=1;
		}
		if(SW3==0)
		{
			led1=0;
			Read_dep();
			led1=1;
		}
		if(SW4==0)
		{
			led1=0;
			Read_session();
			led1=1;
		}
	}											
}