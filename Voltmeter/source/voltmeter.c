#include<reg51.h>
#define lcd_port P2

sbit rs=P3^0;
sbit rw=P3^1;
sbit en=P3^2;
sbit flag=P2^7;

void busy()
{				  
	flag=1;
	rs=0;
	rw=1;
	while(flag!=0)
	{
		en=0;
		en=1;
	}
}

void lcd_cmd(unsigned char val_lcd)
{
	busy();
	lcd_port=val_lcd;
	rs=0;
	rw=0;
	en=1;
	en=0;
}

void lcd_data(unsigned char dat)
{
	busy();
	lcd_port=dat;
	rs=1;
	rw=0;
	en=1;
	en=0;
}

void lcd_string(unsigned char *string)
{
	while(*string)
		lcd_data(*string++);
}

void lcd_init(void)
{
	lcd_cmd(0x02);
lcd_cmd(0x38);
lcd_cmd(0x01);
lcd_cmd(0x0c);
lcd_cmd(0x06);
lcd_cmd(0x80);
}

void hex2lcd(unsigned char hex)
{
	char temp1,temp2;
	temp1 = hex;
	temp2=0;
	do{
		temp1 = temp1-100;
		if(temp1>=0)
			temp2++;
	} while(temp1>=0);
	if(temp2>0)
	lcd_data(temp2+0x30);
	temp2=0;
	temp1 = temp1+100;
	do{
		temp1 = temp1-10;
		if(temp1>=0)
			temp2++;
	} while(temp1>=0);
	lcd_data(temp2+0x30);
	temp2 = temp1+10;
	lcd_data(temp2+0x30);
}

#define adc_port P1              //ADC Port

sbit rd=P3^7;                  //Read signal P3.7
sbit wr=P3^6;                 //Write signal P3.6
sbit cs=P3^5;                  //Chip Select P3.5
sbit intr=P3^4;                //INTR signal P3.4

unsigned int adc_avg,adc;

void conv()
{
	cs = 0;			//Make CS low
	wr = 0;			//Make WR low
	wr = 1;			//Make WR high
	cs = 1;			//Make CS high
	while(intr);	//Wait for INTR to go low
}

void read()
{
	cs = 0;			//Make CS low
	rd = 0;			//Make RD low
	adc = adc_port;	//Read ADC port
	rd = 1;			//Make RD high
	cs = 1;			//Make CS high
}

void main()
{
	char i;
	lcd_init();
	lcd_string("Voltmeter Prj");
	while(1)
		{				//Forever loop
		adc_avg = 0;
		for(i=0;i<10;i++)
		{
			conv();                  //Start conversion
			read();                  //Read ADC
			adc_avg += adc;
		}
		adc_avg = adc_avg/10;
		lcd_cmd(0xc0);
		lcd_string("DC: ");
		adc = adc_avg * 59;

		hex2lcd((unsigned char)(adc/1000));
		lcd_data('.');
		adc = adc%1000;
		hex2lcd((unsigned char)(adc/10));

		lcd_data('V');
	}
}

