/*  Name     : main.c
 *  Purpose  : Source code for Interrupt Pulse counter with AT89C51.
 *  Author   : Sunil Pawar
 *  Date     : 17-07-2021
 */

#include <reg51.h>
sbit entry=P1^0;
sbit exit=P1^1;
sbit rs=P3^0;
sbit rw=P3^1;
sbit en=P3^2;
void lcd_init();
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);
void lcd_display(unsigned char *s);
void lcd_conversion(unsigned char);
void delay();

void main()
{
	unsigned char x;
	lcd_init();
	lcd_display("WELCOME TO");
	lcd_cmd(0xc0);
	delay();
	lcd_display("Interrupt Counter");
	delay();
	while(1)
	{
		if(entry==0)
		{
			lcd_cmd(0x01);
			lcd_display("COUNT IS = ");
			delay();
			x=x+1;
			lcd_conversion(x);
		}	
	}
}

void lcd_init()
{
	lcd_cmd(0x38);
	lcd_cmd(0x01);
	lcd_cmd(0x10);
	lcd_cmd(0x0c);
	lcd_cmd(0x80);
}

void lcd_cmd(unsigned char value)
{
	P2=value;
	rs=0;
	rw=0;
	en=1;
	delay();
	en=0;
}
void lcd_data(unsigned char dat)
{
	P2=dat;
	rs=1;
	rw=0;
	en=1;
	delay();
	en=0;
}
void lcd_display(unsigned char *s)
{		
	while(*s !='\0')
	{
		lcd_data(*s);
		s++;
	}
}
void lcd_conversion(unsigned char num)
{
	unsigned char p,n;
	p=num/10;
	n=num%10;
	p=p+0x30;
	n=n+0x30;
	lcd_data(p);
	lcd_data(n);	
}
void delay()
{
	unsigned int k,l;
	for(k=0;k<3000;k++);
	for(l=0;l<100;l++);
}

