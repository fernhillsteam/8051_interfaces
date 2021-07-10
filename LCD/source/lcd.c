#include<reg51.h>
sbit rs=P3^0;
sbit rw=P3^1;
sbit e=P3^2;
sfr lcd=0xA0; //port 2

void lcd_cmd(unsigned char value);
void lcd_data(unsigned char dat);
void delay(unsigned int time);


void main()
{
	unsigned int i=0,j=0,k;
	unsigned char str[]={"Wel_Come To"};
	unsigned char arr[]={"FERNHILL TECH"};

	lcd_cmd(0x38);
	delay(6);
	lcd_cmd(0x0E);
	delay(6);
	lcd_cmd(0x01);
	delay(6);
	lcd_cmd(0x06);
	delay(6);
	lcd_cmd(0x80);      // Force cursor to beginning of 1st line
	delay(6);

	lcd_cmd(0x0C);

	for(k=0;k<1000;k++)
	{
	   while(str[i]!='\0')
	   {
		   lcd_data(str[i]);
		   delay(6);
	     i++; 
	   }
		 //lcd_cmd(0x1E);	// Shift display to right 
		 
     delay(10);      
	   lcd_cmd(0xC0);	   // Force cursor to beginning of 2nd line
		 
	   for(j=0;arr[j]!='\0';j++)
		 {
			lcd_data(arr[j]);
		 }
	   delay(6);
		 //lcd_cmd(0x18);	// Shift display to left 
	}
}

void delay(unsigned int time)
{
	unsigned int i,j;
	for(i=0;i<=time;i++)
	for(j=0;j<1200;j++);
}

void lcd_cmd(unsigned char value)
{
	lcd=value;
	rs=0;
	rw=0;
	e=1;
	delay(6);
	e=0;
	delay(6);
}
void lcd_data(unsigned char dat)
{
	lcd=dat;
	rs=1;
	rw=0;
	e=1;
	delay(6);
	e=0;
	delay(6);
}