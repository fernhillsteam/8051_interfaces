sbit rs=P2^0;
sbit e=P2^1;
sbit rw=P2^2;

void delay(int time)
{
	unsigned int i,j;
	for(i=0;i<=time;i++)
	for(j=0;j<1200;j++);
}

void lcd_cmd(char ch)
{
	P2 =ch&(0xf0);
	rs=0;
	rw=0;
	e=1;
	delay(5);
	e=0;
	P2 =((ch<<4)&(0xf0));
	rs=0;
	rw=0;
	e=1;
	delay(5);
	e=0;
}
void lcd_data(char ch)
{
	P2 =ch&(0xf0);
	rs=1;
	rw=0;
	e=1;
	delay(5);
	e=0;
	P2 =((ch<<4)&(0xf0));
	rs=1;
	rw=0;
	e=1;
	delay(5);
	e=0;
}
void lcd_init()
{
	lcd_cmd(0x02);
	lcd_cmd(0x28);
	lcd_cmd(0x0e);
	lcd_cmd(0x06);
	lcd_cmd(0x01);
	lcd_cmd(0x80);
}
void lcd_string(char *p)
{
	while(*p!='\0')
	{
		lcd_data(*p++);
	}
}