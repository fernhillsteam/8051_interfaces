/*  Name     : main.c
 *  Purpose  : Source code for RTC DS1307 with AT89C52.
 *  Author   : Sunil Pawar
 *  Date     : 09-07-2021
 */

#include<reg51.h>
#include<intrins.h>

unsigned char sec,min,hr,day,date,mon,yr,ch;
bit c=0;
void main()
{
	serial_init();
	start();
	write(0xd0);	// slave address
	write(0x00);	// initial location address
	write(0x40);	// seconds
	write(0x28);	// minutes
	write(0x14);	// hours
	write(0x06);	// weekday
	write(0x09);	// date
	write(0x07);	// month 
	write(0x21);	// year
	stop();
	while(1)
	{
		serial_init();
		start();
		write(0xd0);	// slave address write mode
		write(0x00);
		start();
		write(0xd1);
		read();
		sec=ch;
		sec=sec&0x7f;
		stop();
		start();
		write(0xd0);
		write(0x01);
		start();
		write(0xd1);
		read();
		min=ch;
		min=min&0x7f;
		stop();
		start();
		write(0xd0);
		write(0x02);
		start();
		write(0xd1);
		read();
		hr=ch;
		hr=hr&0x3f;
		stop();
		start();
		write(0xd0);
		write(0x03);
		start();
		write(0xd1);
		read();
		day=ch;
		day=day&0x0f;
		stop();
		start();
		write(0xd0);
		write(0x04);
		start();
		write(0xd1);
		read();
		date=ch;
		date=date&0x03f;
		stop();
		start();
		write(0xd0);
		write(0x05);
		start();
		write(0xd1);
		read();
		mon=ch;
		mon=mon&0x0f;
		stop();
		start();
		write(0xd0);
		write(0x06);
		start();
		write(0xd1);
		read();
		yr=ch;
		yr=yr&0x3f;
		stop();
		display();
		lcd_display();		
	}
}