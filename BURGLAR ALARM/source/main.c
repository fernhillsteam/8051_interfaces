//
// *  Name     : main.c
// *  Purpose  : Program to BURGLAR ALARM USING 8051 MICROCONTROLLER AND PIR SENSOR (Passive Infra Red )
// *  Author   : Sunil Pawar
// *  Date     : 14-07-2021
// */
#include<reg51.h>
sbit PIR = P1^0;
sbit buzzer = P1^1;
sbit rs=P2^0;
sbit rw=P2^1;
sbit en=P2^2;

void lcd_init();
void lcdcmd(unsigned char);
void lcddat(unsigned char);
void lcddisplay(unsigned char *s);
void delay();
void main()
{
	int i;
	lcd_init();
	lcddisplay(" ALARM DETECTOR ");
	lcdcmd(0xc0);
	lcddisplay("USING PIR SENSOR");
	while(1)
	{
		if(PIR == 1)
		{
			lcdcmd(0xc0);
			lcddisplay("intruder detect");
			delay();
		}
		else
		{
			lcdcmd(0xc0);
			lcddisplay("                      ");
		}
	}
}
void lcd_init()
{
	lcdcmd(0x38);
	lcdcmd(0x0c);
	lcdcmd(0x06);
	lcdcmd(0x01);
	lcdcmd(0x80);
}
void lcdcmd(unsigned char val)
{
	P3=val;
	rs=0;
	rw=0;
	en=1;
	delay();
	en=0;
}
void lcddat(unsigned char dat)
{
	P3=dat;
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
	for(i=0;i<20000;i++);
}