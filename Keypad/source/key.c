#include<reg51.h>
#define msec 50
sbit rs=P0^0;   //Register select (RS   //Read write (RW) pin
sbit en=P0^1;   //Enable (EN) pin
sbit R1 = P3^0;
sbit R2 = P3^1;
sbit R3 = P3^2;
sbit R4 = P3^3;
sbit C1 = P3^4;
sbit C2 = P3^5;
sbit C3 = P3^6;
sbit C4 = P3^7;
void delay(int);
char Read_Keypad()
{
 C1=1;
 C2=1;
 C3=1;
 C4=1;
 R1=0;
 R2=1;
 R3=1;
 R4=1;
 if(C1==0){delay(100);while(C1==0);return '7';}//0
 if(C2==0){delay(100);while(C2==0);return '8';}//4
 if(C3==0){delay(100);while(C3==0);return '9';}//8
 if(C4==0){delay(100);while(C4==0);return '/';}//c
 R1=1;
 R2=0;
 R3=1;
 R4=1;
 if(C1==0){delay(100);while(C1==0);return '4';}//1
 if(C2==0){delay(100);while(C2==0);return '5';}//5
 if(C3==0){delay(100);while(C3==0);return '6';}//9
 if(C4==0){delay(100);while(C4==0);return '*';}//5
 R1=1;
 R2=1;
 R3=0;
 R4=1;
 if(C1==0){delay(100);while(C1==0);return '1';}//2
 if(C2==0){delay(100);while(C2==0);return '2';}//6
 if(C3==0){delay(100);while(C3==0);return '3';}//a
 if(C4==0){delay(100);while(C4==0);return '-';}//e
 R1=1;
 R2=1;
 R3=1;
 R4=0;
 if(C1==0){delay(100);while(C1==0);return 'c';}//3
 if(C2==0){delay(100);while(C2==0);return '0';}//7
 if(C3==0){delay(100);while(C3==0);return '=';}//b
 if(C4==0){delay(100);while(C4==0);return '+';}//f
 return 0 ;
}

void delay(int time)  //Time delay function
{
unsigned int i,j;
for(i=0;i<time;i++)
  for(j=0;j<1275;j++);
}

void lcdcmd(unsigned char value)  //Function for sending values to the command register of LCD
{
P2=value;
rs=0;
en=0;
delay(15);
en=1;
return;
}

void lcddata(unsigned char value1)  //Function for sending values to the data register of LCD
{
	rs=1;
P2=value1;
en=0;
delay(15);
en=1;
return;
}
 
void lcdstring(char *a)
{
	int i;
	for(i=0;a[i]!='\0';i++)
	 lcddata(a[i]);
}
void lcdinit(void)
{
	lcdcmd(0X30);
	delay(25);
	lcdcmd(0X30);
	delay(25);
	lcdcmd(0X30);
	delay(25);
	
	lcdcmd(0x38); //set LCD in  5x7 mode
	delay(20);
	lcdcmd(0x0c);  //Cursor blinking
	delay(20);
	lcdcmd(0x01);  // clear LCD
	delay(20);
	lcdcmd(0x06);  //set cursor on  first position of first line on LCD
	delay(20);
}
	
void main()
{ 
	int i=0;
	char a;
	char c[4];
	lcdinit();
	lcdstring("Welcome to");
	delay(5);
	lcdcmd(0xc0);
	lcdstring("rolling display");
	delay(50);
	lcdcmd(0x01);
	lcdstring("enter 5 digits");
	delay(100);
while(1)
{
	for(i=0;i<5;i++)
	{
		while(!(c[i] = Read_Keypad()));
//	Read_Keypad();
	  delay(50);
		delay(50);
		lcdcmd(0x01);
		lcddata(c[i]);
	}
	lcdinit();
	for(i=0;i<5;i++)
	{
	lcddata(c[i]);
	}
	for(i=0;i<1000000000;i++)
		{
			lcdcmd(0x1c);
			delay(30);
		
	
		}
}		
}