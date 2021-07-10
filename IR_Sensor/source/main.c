#include<reg51.h>
#define lcd P3

sbit IR=P1^0;

sbit rs=P2^0; //register select
sbit rw=P2^1; //RW
sbit en=P2^2; //enable

void lcd_init();
void cmd(unsigned char);
void dat(unsigned char);
void delay();
void lcd_string(char *s);

void main()
{
    lcd_init();
    lcd_string("  EmbeTronicX   ");
    while(1) {
        if(IR == 0) {
            cmd(0xc0);
            lcd_string("Obstacle Detected");
            delay();
        } else {
            cmd(0xc0);
            lcd_string("                ");
        }
    }
}

void lcd_init()
{
    cmd(0x38);
    cmd(0x0e);
    cmd(0x06);
    cmd(0x01);
    cmd(0x80);
}

void cmd(unsigned char a)
{
    lcd=a;
    rs=0;
    rw=0;
    en=1;
    delay();
    en=0;
}

void dat(unsigned char b)
{
    lcd=b;
    rs=1;
    rw=0;
    en=1;
    delay();
    en=0;
}

void lcd_string(char *s)
{
    while(*s) {
       dat(*s++);
     }
}

void delay()
{
    unsigned int i;
    for(i=0;i<20000;i++);
}