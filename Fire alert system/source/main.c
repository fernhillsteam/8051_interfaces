//
// *  Name     : main.c
// *  Purpose  : Program to Flame Sensor interfacing With 8051
// *  Author   : Sunil Pawar
// *  Date     : 14-07-2021
// */
#include<reg51.h>
sbit sensor = P1^0;
sbit buzzer = P1^1;
sbit rs=P3^0;
sbit rw=P3^1;
sbit en=P3^2;

void lcd_init();
void lcdcmd(unsigned char);
void lcddat(unsigned char);
void lcddisplay(unsigned char *);
void delay();
void main()
{
	buzzer =0;
	sensor =0;
	back:lcd_init();
	lcddisplay(" FIRE ALERT ");
	lcdcmd(0xc4);
	lcddisplay("SYSTEM");
	delay();
	while(1)
	{
		if(sensor == 1)
		{
			lcdcmd(0x01);
			lcddisplay("FIRE OCCURED");
			buzzer = 1;
			//delay();
			//buzzer =0;
		}
		goto back;
	}
}
void lcd_init()
{
	lcdcmd(0x38);
	lcdcmd(0x01);
	lcdcmd(0x10);
	lcdcmd(0x0c);
	lcdcmd(0x80);
}
void lcdcmd(unsigned char val)
{
	P2=val;
	rs=0;
	rw=0;
	en=1;
	delay();
	en=0;
}
void lcddat(unsigned char dat)
{
	P2=dat;
	rs=1;
	rw=0;
	en=1;
	delay();
	en=0;
}
void lcddisplay(unsigned char *s)
{
	unsigned char i;
	for(i=0;s[i]!='\0';i++)
	{
		lcddat(s[i]);
	}
}
void delay()
{
	int i;
	for(i=0;i<10000;i++);
}