
sbit rs=P2^2;
sbit rw=P2^3;
sbit en=P2^4;

void lcd_display();
void lcd_init();
void lcddisp(unsigned char *);
void lcdcmd(unsigned char);
void lcddat(unsigned char);
void delay2();

void lcd_init()
{
	lcdcmd(0x38);
	lcdcmd(0x01);
	lcdcmd(0x10);
	lcdcmd(0x0c);
	lcdcmd(0x80);
}
void lcddat(unsigned char val)
{
	P1=val;
	rs=1;
	rw=0;
	en=1;
	delay2();
	en=0;
}
void lcdcmd(unsigned char val)
{
	P1=val;
	rs=0;
	rw=0;
	en=1;
	delay2();
	en=0;
}
void lcddisp(unsigned char *m)
{	
	while(*m !='\0')
	{
		lcddat(*m);
		m++;
	}
}
void delay2()
{
	unsigned int v1;
	for(v1=0;v1<2000;v1++);
}
void delay3()
{
	unsigned int v11;
	for(v11=0;v11<32000;v11++);
	
}
void lcd_display()
{
	unsigned char v9,v10;
	lcd_init();
	lcddisp("TIME");
	lcdcmd(0xc0);
	lcddisp("DATE");
	v9=hr&0x0f;
	v10=(hr&0xf0)>>4;
	lcdcmd(0x86);
	lcddat(v10|0x30);
	lcddat(v9|0x30);
	lcddat(":");
	v9=min&0x0f;
	v10=(min&0xf0)>>4;
	lcddat(v10|0x30);
	lcddat(v9|0x30);
	lcddat(":");
	v9=sec&0x0f;
	v10=(sec&0xf0)>>4;
	lcddat(v10|0x30);
	lcddat(v9|0x30);
	lcdcmd(0xc6);
	v9=date&0x0f;
	v10=(date&0xf0)>>4;
	lcddat(v10|0x30);
	lcddat(v9|0x30);
	lcddat(":");
	v9=mon&0x0f;
	v10=(mon&0xf0)>>4;
	lcddat(v10|0x30);
	lcddat(v9|0x30);
	lcddat(":");
	v9=yr&0x0f;
	v10=(yr&0xf0)>>4;
	lcddat(v10|0x30);
	lcddat(v9|0x30);
	delay3();
}