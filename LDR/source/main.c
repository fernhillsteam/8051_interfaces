/*  Name     : main.c
 *  Purpose  : Source code for LDR with AT89C51.
 *  Author   : Sunil Pawar
 *  Date     : 10-07-2021
 */

#include <reg51.h>
#include "lcd.h"

sbit ldr = P1^0;		///*** MONITORING FOR DAY/NIGHT TIME   ****///
sbit ir1 = P1^2;		//**** TO DETECT THE MOVEMENT OF VEHICLE OR OBJECT ***///
sbit ir2 = P1^3;
sbit led1 = P1^4;		///*** STRRET LIGHTS		*********///
sbit led2 = P1^5;
void main()
{
	led1=led2=0;
	lcd_init();
	lcd_cmd(0x80);
	lcd_string("STREET LIGHT");
	lcd_cmd(0xc0);
	lcd_string("control system");
	delay(500);
	lcd_cmd(0x01);
	lcd_cmd(0x80);
	lcd_string("status:      ");
	lcd_cmd(0xc0);
	lcd_string("light:       ");
	while(1)
	{
		if(ldr==1)	// Night time
		{
				lcd_cmd(0x88);
				lcd_string("NIGHT");
				lcd_cmd(0xc7);
				lcd_string("OFF");
				if(ir1==0)							// if anr object detects
				{
						lcd_cmd(0xc7);
						lcd_string("ON ");	// street light-1 is ON
						led1=1;
						delay(1000);
						led1=0;
						delay(5);							
				}
				if(ir2==0)
				{
						lcd_cmd(0xc7);
						lcd_string("ON ");	// street light-2 is ON
						led2=1;
						delay(1000);
						led2=0;
						delay(5);							
				}
		}
		else				// Day time
		{
			lcd_cmd(0x87);
			lcd_string("DAY      ");
			lcd_cmd(0xc7);
			lcd_string("OFF      ");
			led1=led2=0;								// both street lights are off
			delay(5);		
		}
	}
}



