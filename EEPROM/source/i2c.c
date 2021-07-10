#include <reg51.h>
#include "i2c.h"
#include "lcd.h"
#include<intrins.h> 


sbit led=P3^5;
sbit led1=P3^6;
sbit sda=P1^0;
sbit scl=P1^1;
bit ack;
sfr output=0x90;

unsigned char reead,write,write2,i,j,k,l;
unsigned int temp;

void start()                                          // start condition
{
	sda=1;
	scl=1;
	_nop_();                                      // No operation
	_nop_();
	sda=0;
	scl=0;
}
void stop()                                           // stop condition
{
	sda=0;
	scl=1;
	_nop_();
	_nop_();
	sda=1;
	scl=0;
}
void aknowledge()                                     // acknowledge condition
{
	scl=1;
	_nop_();
	_nop_();
	scl=0;
}
void send_byte(unsigned char value)                   // send byte serially
{
	unsigned int i;
	unsigned char send;
	send=value;
	for(i=0;i<8;i++)
	{ 
		sda=send/128;                         // extracting MSB
		send=send<<1;                         // shiftng left
		scl=1;
		_nop_();
		_nop_();
		scl=0;
	}
	ack=sda;                                           // reading acknowledge
	sda=0;
}
unsigned char read_byte()                             // reading from EEPROM serially
{
	unsigned int i;
	sda=1;
	reead=0;
	for(i=0;i<8;i++)
	{
		reead=reead<<1;
		scl=1;
		_nop_();
		_nop_();
		if(sda==1)
		reead++;
		scl=0;
	}
	sda=0;
	return reead;                                 // Returns 8 bit data here
}
void save()                                           // save in EEPROM
{
	start();
	send_byte(0xA0);                              // device address
	aknowledge();
	send_byte(0x0000);                            // word address
	aknowledge();
	send_byte('F');                               // send data
	aknowledge();
	send_byte('E');
	aknowledge();
	send_byte('R');
	aknowledge();
	send_byte('N');                               // send data
	aknowledge();
	send_byte('H');
	aknowledge();
	send_byte('I');
	aknowledge();
	send_byte('L');       // send data
	aknowledge(); 
	send_byte('L');
	aknowledge();
	send_byte('S');
	aknowledge();
	stop();
	if(ack==0)
	{
		led=0;
		delay(100);
		lcd_command(0x86);
		lcd_data('F');
		lcd_command(0x87);
		lcd_data('E');
		lcd_command(0x88);
		lcd_data('R');
		lcd_command(0x89);
		lcd_data('N');
		lcd_command(0x8A);
		lcd_data('H');
		lcd_command(0x8B);
		lcd_data('I');
		lcd_command(0x8C);
		lcd_data('L');
		lcd_command(0x8D);
		lcd_data('L');
		lcd_command(0x8E);
		lcd_data('S');
		led=1;
		delay(100);
	}
	else
	led1=0;
	aknowledge();
}

void Read()
{
	start();
	send_byte(0xA0);
	aknowledge();
	send_byte(0x0000);
	aknowledge();
	start();
	send_byte(0xA1);                              // device address
	aknowledge();
	i=read_byte();
	aknowledge();
	j=read_byte();
	aknowledge();
	k=read_byte();
	aknowledge();
	l=read_byte();
	aknowledge();
	stop();
	if(i!=0xff)
	{
		led1=0;
		delay(100);
		write=i;
		lcd_command(0xC6);
		lcd_data(write);
		write=j;
		lcd_command(0xC7);
		lcd_data(write);
		write=k;
		lcd_command(0xC8);
		lcd_data(write);	
		write=l;
		lcd_command(0xC9);
		lcd_data(write);
		led1=1;
		delay(100);
			
	}
}

void Read_dep()
{
	start();
	send_byte(0xA0);
	aknowledge();
	send_byte(0x0004);
	aknowledge();
	start();
	send_byte(0xA1);                              // device address
	aknowledge();
	i=read_byte();
	aknowledge();
	j=read_byte();
	aknowledge();
	k=read_byte();
	aknowledge();
	l=read_byte();
	aknowledge();
	stop();
	if(i!=0xff)
	{
		led1=0;
		delay(100);
		write=i;
		lcd_command(0xC6);
		lcd_data(write);
		write=j;
		lcd_command(0xC7);
		lcd_data(write);
		write=k;
		lcd_command(0xC8);
		lcd_data(write);
		write=l;
		lcd_command(0xC9);
		lcd_data(write);
		led1=1;
		delay(100);					
	}
}

void Read_session()
{
	start();
	send_byte(0xA0);
	aknowledge();
	send_byte(0x0002);
	aknowledge();
	start();
	send_byte(0xA1);                              // device address
	aknowledge();
	i=read_byte();
	aknowledge();
	j=read_byte();
	aknowledge();
	k=read_byte();
	aknowledge();
	l=read_byte();
	aknowledge();
	stop();
	if(i!=0xff)
	{
		led1=0;
		delay(100);
		write=i;
		lcd_command(0xC6);
		lcd_data(write);
		write=j;
		lcd_command(0xC7);
		lcd_data(write);
		write=k;
		lcd_command(0xC8);
		lcd_data(write);
		write=l;
		lcd_command(0xC9);
		lcd_data(write);
		led1=1;
		delay(100);	
	}
}