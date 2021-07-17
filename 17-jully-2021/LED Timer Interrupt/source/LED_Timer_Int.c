/// timer interrupt programming using Timer0 model for blinking LED using interrupt method

#include<reg51.h>
sbit LED = P2^0; // this will be blinking every 50ms

void timer0_isr() interrupt 1
{
    TH0  = 0X4B;        //ReLoad the timer value
    TL0  = 0XFD;
    LED =!LED;        // Toggle the LED pin 
}

void main()
{
    TMOD = 0x01;       //Timer0 mode 1 
    TH0 = 0X4B;        //Load the timer value
    TL0 = 0XFD;
    TR0 = 1;           //turn ON Timer zero
    ET0 = 1;           //Enable TImer0 Interrupt
    EA = 1;            //Enable Global Interrupt bit
    while(1){} 
}