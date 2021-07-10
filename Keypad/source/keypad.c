#include<reg51.h>

sbit r1=P1^0;
sbit r2=P1^1;
sbit r3=P1^2;
sbit r4=P1^3;
sbit c1=P1^4;
sbit c2=P1^5;
sbit c3=P1^6;
sbit c4=P1^7;
//sfr lcd=0xA0;
sbit rs=P3^0;
sbit rw=P3^1;
sbit en=P3^2;
void delay();

				void lcd_cmd(unsigned char value);
				void lcd_data(unsigned char value);
				void lcd_init();
				
void main()
{	
	char dat;
	lcd_init();
//	lcd_data('4');
	delay();


/*	r1=0; r2=r3=r4=1;
	if(c1==0)
	{
		delay();
		while(c1==0)
		{
			lcd_data='0';
		}
	}
*/
r1=0; r2=r3=r4=1;

if(c1==0){delay(); while(c1==0) {dat =0 ;lcd_data(dat+48);} }
if(c2==0){delay(); while(c2==0) {dat =1 ;lcd_data(dat+48);} }
if(c3==0){delay(); while(c3==0) {dat =2 ;lcd_data(dat+48);} }
if(c4==0){delay(); while(c4==0) {dat =3 ;lcd_data(dat+48);} }

r2=0; r1=r3=r4=1;

if(c1==0){delay(); while(c1==0) {dat =4 ;lcd_data(dat+48);} }
if(c2==0){delay(); while(c2==0) {dat =5 ;lcd_data(dat+48);} }
if(c3==0){delay(); while(c3==0) {dat =6 ;lcd_data(dat+48);} }
if(c4==0){delay(); while(c4==0) {dat =7 ;lcd_data(dat+48);} }

r3=0; r1=r2=r4=1;

if(c1==0){delay(); while(c1==0) {dat =8 ;lcd_data(dat+48);} }
if(c2==0){delay(); while(c2==0) {dat =9 ;lcd_data(dat+48);} }
if(c3==0){delay(); while(c3==0) {dat ='A' ;lcd_data(dat+48);} }
if(c4==0){delay(); while(c4==0) {dat ='B' ;lcd_data(dat+48);} }

r4=0; r1=r2=r3=1;

if(c1==0){delay(); while(c1==0) {dat ='C' ;lcd_data(dat+48);} }
if(c2==0){delay(); while(c2==0) {dat ='D' ;lcd_data(dat+48);} }
if(c3==0){delay(); while(c3==0) {dat ='E' ;lcd_data(dat+48);} }
if(c4==0){delay(); while(c4==0) {dat ='F' ;lcd_data(dat+48);} }
}

void delay(unsigned int time)
{
	unsigned int i,j;
	for(i=0;i<time;i++)
	for(j=0;j<1200;j++);
}

void lcd_cmd(unsigned char value)
{
	P2=value;
	rs=0;
	rw=0;
	en=1;
	delay(2);
	en=0;
	delay(2);
}
void lcd_data(unsigned char value)
{
	P2=value;
	rs=1;
	rw=0;
	en=1;
	delay(2);
	en=0;
	delay(2);
}