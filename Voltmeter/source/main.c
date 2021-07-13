#include<reg51.h>
#define lcd P3
#define dat P2
sbit rs=P1^6;
sbit e=P1^7;


void delay (int);
void display (unsigned char);
void cmd (unsigned char);
void init (void);
void string (char *);
void intro (void);
char i=0;

	
void delay (int d)
{
	unsigned char i=0;
	for(;d>0;d--)
	{
		for(i=250;i>0;i--);
                for(i=248;i>0;i--);
	}
}
void cmd (unsigned char c)
{
	lcd=c;
	rs=0;
	e=1;
	delay(10);
	e=0;
}
void display (unsigned char c)
{
	lcd=c;
	rs=1;
	e=1;
	delay(10);
	e=0;
}
void string (char *c)
{
	while(*c)
	{
		display(*c++);
	}
}
void init (void)
{
	cmd(0x38);
	cmd(0x01);
  cmd(0x0c);
	cmd(0x80);
}
void intro (void)
{
	string("  Electronics  ");
	cmd(0xc0);
	string("      Hub      ");
	delay(2000);
	cmd(0x01);
	string("    Digital    ");
	cmd(0xc0);
	string("   Voltmeter   ");
	delay(2000);
	cmd(0x01);
	cmd(0x80);
}

void main()
{
	unsigned int temp=0;
	unsigned int temp1=0;
	float val=0.0;
	
	init();
	intro();
	dat=0xff;
	while(1)
	{
		if(i==0)
		{
			string(" Volts - ");
			i++;
		}
		val=dat*0.02;  // 0.02 is resolution of adc
		val=val/0.2;   // 0.2 is nothing but (R2/(R1+R2)) resistor values in the voltage sensor
   	cmd(0x89);
		if((val>=1.0) && (val<10.0))
		{
			display(' ');
	  	temp=val*1000;
  		temp1=((temp/1000)+48);
  		display(temp1);
			
			display('.');
		
	  	temp1=(((temp/100)%10)+48);
	  	display(temp1);
		}
		else if((val>=10.0) && (val<100.0))
		{
	 		temp=val*100;
  		temp1=((temp/1000)+48);
  		display(temp1);
		
			temp1=(((temp/100)%10)+48);
	  	display(temp1);
			
			display('.');
			
			temp1=(((temp/10)%10)+48);
	  	display(temp1);
		}
		else
		{
			display(' ');
			string("0.0");
		}
		delay(1000);
  }
	while(1);
}