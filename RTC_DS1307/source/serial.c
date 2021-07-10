void serial_init();
void enter();

void enter()
{
	SBUF=0x0D;
	while(TI==0);
	TI=0;
}

void serial_init()
{
	SCON=0X50;
	TMOD=0X20;
	TH1=-3;
	TR1=1;
}
