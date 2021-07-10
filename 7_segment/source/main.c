#include<reg51.h>
sfr segment=0xA0;//port 2
void delay();
void main()
{
	 unsigned seven_seg[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67};  // common cathode(Keep always ON)
	 //unsigned seven_seg[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};  // common Anode(Keep always OFF)
	 int i;																						 
	 while(1)
	 {
	 	for(i=0;i<10;i++)
	 	{
	 		segment=seven_seg[i];
			delay();
	 	}	
	 }	 
}
void delay()
{
	unsigned j,k;
	for(j=0;j<100;j++)	
	for(k=0;k<1500;k++);
} 