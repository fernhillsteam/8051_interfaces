#include<reg51.h>
#define lcd_port P2

sbit rs=P3^0;
sbit rw=P3^1;
sbit en=P3^2;
sbit flag=P2^7;

void busy()
{				  
	flag=1;
	rs=0;
	rw=1;
	while(flag!=0)
	{
		en=0;
		en=1;
	}
}

void lcd_cmd(unsigned char val_lcd)
{
	busy();
	lcd_port=val_lcd;
	rs=0;
	rw=0;
	en=1;
	en=0;
}

void lcd_data(unsigned char dat)
{
	busy();
	lcd_port=dat;
	rs=1;
	rw=0;
	en=1;
	en=0;
}

void lcd_string(unsigned char *string)
{
	while(*string)
		lcd_data(*string++);
}

void lcd_init(void)
{
	lcd_cmd(0x02);
lcd_cmd(0x38);
lcd_cmd(0x01);
lcd_cmd(0x0c);
lcd_cmd(0x06);
lcd_cmd(0x80);
}

void hex2lcd(unsigned char hex){
	char temp1,temp2;
	temp1 = hex;
	temp2=0;
	do{
		temp1 = temp1-100;
		if(temp1>=0)
			temp2++;
	} while(temp1>=0);
	if(temp2>0)
	lcd_data(temp2+0x30);
	temp2=0;
	temp1 = temp1+100;
	do{
		temp1 = temp1-10;
		if(temp1>=0)
			temp2++;
	} while(temp1>=0);
	lcd_data(temp2+0x30);
	temp2 = temp1+10;
	lcd_data(temp2+0x30);
}