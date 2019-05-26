#include<reg51.h>
unsigned char dig1=0x00,dig2=0x00;
unsigned char temp1=0x00,temp2=0x00,dig_count=0x00;
int count=0x00;
unsigned char led_code[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
int tmr0_flg=0,one_sec_flg=0;
void display();
void timer0_init(void);
void main(void)
{
	
		timer0_init();
		while(1)
		{
			while(tmr0_flg==0)
				tmr0_flg=0;
			dig_count++;
			if(dig_count==0x02)
			dig_count=0x02;
			if(one_sec_flg==1)
			{
				one_sec_flg=0;
				dig1++;
				if(dig1==0x0A)
				{
					dig1=0;
					dig2++;
					if(dig2==0x0A)
						dig2=0;
				}
			}
			display();
		}
}
void timer0_isr(void)interrupt 1
{
	TL0=0xCC;
	TH0=0xF8;
	TF0=0;
	tmr0_flg=1;
	if(count==500)
	{
		one_sec_flg=1;
		count=0x00;
	}
	else count++;
}
void timer0_init(void)
{
	TMOD=0x01;
	TL0=0xCC;
	TH0=0xF8;
	TCON=0x00;
	ET0=1;
	TR0=1;
	EA=1;
}
void display(void)
{
	if(dig_count==0x00)
	{
		temp1=dig1;
		P0=0x30;
	}
	else if(dig_count==0x01)
	{
		temp1=dig2;
		P0=0x20;
	}
	temp1&=0x0f;
	temp2=led_code[temp1];
	P1=temp2;
}
	