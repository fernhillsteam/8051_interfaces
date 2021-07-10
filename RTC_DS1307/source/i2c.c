
sbit scl=P2^0;
sbit sda=P2^1;
void start();
void delay();
void check();
void write(unsigned char);
unsigned char read();
void display();
void ack();
void stop();
void conversion(unsigned char);

void start()
{
	scl=1;
	sda=1;
	delay();
	sda=0;
	delay();
	scl=0;	
}
void stop()
{
	scl=1;
	sda=0;
	delay();
	sda=1;
	scl=0;
	delay();
}
void delay()
{
	_nop_();
	_nop_();
}
void write(unsigned char val)
{
	unsigned char v2=0x80,v3,v5;
	v5=val;
	for(v3=0;v3<8;v3++)
	{
		sda=v5&v2;
		scl=1;
		delay();
		scl=0;
		v5=v5<<1;	
	}
	c=sda;
	scl=1;
	delay();
	scl=0;
	if(c==1)
	{
		stop();
		while(1);		
	}	
}
unsigned char read()
{
	unsigned char v16;
	bit m=0;
	for(v16=0;v16<=7;v16++)
	{
		scl=1;	
		delay();
		m=sda;
		scl=0;
		if(m==1)
		{
			ch|=0x01;
		}
		if(v16<=6)
		ch=ch<<1;
		delay();
	}
	return ch;
}
void display()
{
	conversion(hr);
	conversion(min);
	conversion(sec);
	enter();
//	conversion(day);
//	enter();
	conversion(date);
	conversion(mon);
	conversion(yr);
	enter();
}
void conversion(unsigned char res)
{
	unsigned char v4,v5;
	v4=res&0x0f;
	v5=res&0xf0;
	v5=v5>>4;
	v4=v4|0x30;
	v5=v5|0x30;
	SBUF=v5;while(TI==0); TI=0;
	SBUF=v4;while(TI==0); TI=0;
	SBUF=':';while(TI==0); TI=0;
}
