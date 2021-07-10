#include <reg51.h>
#include "lcd.h"

sfr lcd_data_pin=0xA0;
sbit rs=P3^2;
sbit rw=P3^3;
sbit en=P3^4;

void lcd_ini()
{
	lcd_command(0x38);                            // for using 8-bit 2 row LCD
	delay(5);
	lcd_command(0x0F);                            // for display on, cursor blinking
	delay(5);
	lcd_command(0x80);
	delay(5);
}
void lcd_command(unsigned char comm)
{
	lcd_data_pin=comm;
	en=1;
	rs=0;
	rw=0;
	delay(1);
	en=0;
}
void lcd_data(unsigned char disp)
{
	lcd_data_pin=disp;
	en=1;
	rs=1;
	rw=0;
	delay(1);
	en=0;
}
void lcd_dataa(unsigned char *disp)
{
	int x;
	for(x=0;disp[x]!=0;x++)
	{
		lcd_data(disp[x]);
	}
}
void delay(unsigned int count)
{
	int i,j;
	for(i=0;i<count;i++)
	for(j=0;j<1275;j++);
}