#include<reg52.h>

//sbit r0=P2^0;   //Rows Declared
//sbit r1=P2^1;
//sbit r2=P2^2;
//sbit r3=P2^3;
//sbit c0=P2^5;   //Coulombs declared
//sbit c1=P2^6;
//sbit c2=P2^7;

sbit r0=P1^0;
sbit r1=P1^1;
sbit r2=P1^2;
sbit r3=P1^3;
sbit c0=P1^4;
sbit c1=P1^5;
sbit c2=P1^6;

sbit rs=P3^0;
sbit rw=P3^1;
sbit en=P3^2;

//sbit en=P3^6;   //Lcd control pins declared
//sbit rs=P3^5;
//sbit rw=P3^7;

char t1[]="KEYPAD WITH LCD";  //String displayed on 16x2 lcd screen

void delay(unsigned int n)   //Delay function generating variable delay
{
	unsigned int i,j;
	for(j=0; j<= n;j++);
	for(i=0; i<=10;i++); 
}

void lcdcmd(unsigned int  command)
{  //Lcd command function
	P2=command;
	rw=0;
	rs=0;
	en=0;
	delay(3000);
	en=1;
	delay(3000);
	en=0;
}

void lcddata(char data1)     //Lcd data function
{
	P2=data1;
	rw=0;
	rs=1;
	en=0;
	delay(3000);
	en=1;
	delay(3000);
	en=0;
}

void lcdint()  // Lcd initializing function
{
lcdcmd(0x30);	delay(3000);	lcdcmd(0x30);	delay(3000);	lcdcmd(0x30);	delay(3000);
lcdcmd(0x30);	delay(3000);	lcdcmd(0x30);	delay(3000);	lcdcmd(0x38);	delay(3000);
lcdcmd(0x01);	delay(3000);	lcdcmd(0x0F);	delay(3000);	lcdcmd(0x80);	delay(3000);
}

void keypad()  //Lcd keypad scanning function
{
//char c='a';
//while(c!='s'){
r0=0;r1=1;r2=1;r3=1;
//if(c0==0){lcddata('1');P0=0xF0;delay(20000);c='s';}
// if(c1==0){lcddata('2');P0=0xF0;delay(20000);c='s';}
// if(c2==0){lcddata('3');P0=0xF0;delay(20000);c='s';}
 
 
 
 if(c0==0){lcddata('1');delay(20000);}
 if(c1==0){lcddata('2');delay(20000);}
 if(c2==0){lcddata('3');delay(20000);}

r0=1;r1=0;r2=1;r3=1;
//if(c0==0){lcddata('4');P0=0xF0;delay(20000);c='s';}
// if(c1==0){lcddata('5');P0=0xF0;delay(20000);c='s';}
// if(c2==0){lcddata('6');P0=0xF0;delay(20000);c='s';}
 
  if(c0==0){lcddata('4');delay(20000);}
 if(c1==0){lcddata('5');delay(20000);}
 if(c2==0){lcddata('6');delay(20000);}

r0=1;r1=1;r2=0;r3=1;
//if(c0==0){lcddata('7');P0=0xF0;delay(20000);c='s';}
// if(c1==0){lcddata('8');P0=0xF0;delay(20000);c='s';}
// if(c2==0){lcddata('9');P0=0xF0;delay(20000);c='s';}
 
 
  if(c0==0){lcddata('7');delay(20000);}
 if(c1==0){lcddata('8');delay(20000);}
 if(c2==0){lcddata('9');delay(20000);}

r0=1;r1=1;r2=1;r3=0;
//if(c0==0){lcddata('*');P0=0xF0;delay(20000);c='s';}
// if(c1==0){lcddata('0');P0=0xF0;delay(20000);c='s';}
// if(c2==0){lcddata('#');P0=0xF0;delay(20000);c='s';}
 
  if(c0==0){lcddata('*');delay(20000);}
 if(c1==0){lcddata('0');delay(20000);}
 if(c2==0){lcddata('#');delay(20000);}

}
//}

void main() //Projecct main function
{
	unsigned int i=0;
	P1=0x00;
	P2=0xF0;
	P3=0x00;

	lcdint();   //Initialize 16x2 Lcd

	while(t1[i]!='\0')  //Display well come message on 16x2 lcd sccreen
	{
		lcddata(t1[i]);
		i++;
	}
	i=0;

	lcdcmd(0xC0);       //Control transfer to second row of lcd

//	for(i=0;i<=15;i++)
	keypad();
}