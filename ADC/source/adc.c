#include<reg51.h>

//ADC pin configuration
sbit A0 = P1^0; 
sbit A1 = P1^1; 
sbit A2 = P1^2;
 
sbit SOC = P1^3; // Start convert pin
sbit ALE = P1^4; // Address latch enable pin
sbit EOC = P1^5; // End of Conversion
sbit OE = P1^6;  //output enable  
sfr ADC_Output = 0x80; // Port 0

// LCD pin configuration
sfr LCD = 0xA0;// PORT 2
sbit rs = P3^0;
sbit rw = P3^1;
sbit en	= P3^2;


void lcd_init();
void message_send(unsigned char *);
void lcd_cmd(unsigned char );
void lcd_data(unsigned char);
void time_delay();
void time_delay1();
void cmd_delay();

void convert_data(unsigned char);

unsigned char mydata;

void main()
{
	   lcd_init();
		
	   EOC = 1;
	   ALE = 0;
	   OE = 0;
	   SOC = 0;
		lcd_cmd(0x80);
	  message_send("ADC init");
		cmd_delay();
		lcd_cmd(0xC5);
		message_send("done");
		cmd_delay();
	   while(1)
	   {
	   	A0 = 1; A1 = 1; A2 = 1; // if a0 = a1 = a2 = 1, IN7 pin selected so output of sensor connected to IN7 pin
			time_delay();
			ALE = 1;	//high  pulse passing
			time_delay();
			SOC = 1;   //high  pulse passing
			time_delay();
			ALE = 0;   //low pulse passing
			SOC = 0;   //low pulse passing , so total high to low pulse
		
//			while(EOC == 1);
			while(EOC == 0);
			OE = 1;
			time_delay();
			mydata = ADC_Output;
			OE = 0;
		convert_data(mydata);
	 }
}
void convert_data(unsigned char mydata)
{
	
	unsigned char z1, z2, z3 , x, y;
	
	x= mydata;   // ex  data = 145
	y = x / 10;	// 14
	z1 = x % 10; // 5 
	z2 = y % 10; // 4
	z3 = y / 10; // 1

	z1 = z1 + 0x30; // 35
	z2 = z2+ 0x30; // 34
	z3 = z3 +0x30; // 31
	
	lcd_cmd(0x80);
	   message_send("ADC value");
		cmd_delay();
		lcd_cmd(0xC5);
		message_send(" = ");
		cmd_delay(); 

	lcd_data(z3);
	lcd_data(z2);
	lcd_data(z1);
}
void lcd_init()
{
	lcd_cmd(0x38);//	2 line , 5x7 matrix activated
	time_delay1();
	lcd_cmd(0x0E); //display on cursor blinking
	time_delay1();
	lcd_cmd(0x01);	// clear screen
	time_delay1();
	//lcd_cmd(0x06);	// shift cursor to right

	time_delay1();
		lcd_cmd(0x80);
		message_send("lcd init");
		cmd_delay();
		lcd_cmd(0xC5);
		message_send("done");
		cmd_delay();
	
}
void lcd_cmd(unsigned char val1)
{
	LCD = val1;
	rs = 0;			  // for command send to display
	rw = 0;
	en = 1;
	cmd_delay();
	en = 0;
}
void message_send(unsigned char *p)
{
	while(*p !='\0')
	{
		lcd_data(*p);
		p++;
	}
}
void lcd_data(unsigned char val2)
{
  
	LCD = val2;
	rs = 1;	  // for data  send to display
	rw = 0;
	en = 1;
	cmd_delay();
	en = 0;
}
void time_delay()
{
	int i;
	for(i = 0; i<1000; i++);	
}
void time_delay1()
{
	int j;
	for(j = 0; j<100; j++);	
}

void cmd_delay()
{
	int i;
	for(i = 0; i<10000; i++);	
}
