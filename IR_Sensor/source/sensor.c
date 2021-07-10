#include<reg51.h>
sbit rs=P2^0; //register select
sbit rw=P2^1; //RW
sbit en=P2^2; //enable
#define lcd P3
sbit ir=P1^0;
sbit relay=P2^3;

void lcd_init();
void lcd_display(char *s);
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);
void delay();

void main()
{
	lcd_init();
	lcd_display("AUTOMATIC ROOM");
	lcd_cmd(0xc0);
	lcd_display("LIGHT CONTROL IR");
	while(1)
	{
		if(ir==1)
		{
			lcd_cmd(0x01);
			lcd_display("SENSOR DETECTED");
			lcd_cmd(0xc0);
			lcd_display("LIGHT ON");
			relay = 0;
			while(ir==1);					
		}
		else
		{
			lcd_cmd(0x01);
			lcd_display("NO SENSOR DETECTED");
			lcd_cmd(0xc0);
			lcd_display("LIGHT OFF");
			relay = 1;
		}
	}
}
void lcd_init()
{
    lcd_cmd(0x38);
    lcd_cmd(0x0e);
    lcd_cmd(0x06);
    lcd_cmd(0x01);
    lcd_cmd(0x80);
}
void lcd_cmd(unsigned char val)
{
    P3 =val;
    rs=0;
    rw=0;
    en=1;
    delay();
    en=0;
}

void lcd_data(unsigned char val)
{
    P3=val;
    rs=1;
    rw=0;
    en=1;
    delay();
    en=0;
}
void lcd_display(unsigned char *s)
{
//    unsigned char i;
//	for(i=0; s[i]!='\0';i++)
//	{
//       lcd_data(s[i]);
 //    }
	    while(*s) {
       lcd_data(*s++);
     }
}
void delay()
{
    unsigned int i;
    for(i=0;i<20000;i++);
}

