#include <reg51.h> 
void scan(void); 
void get_key(void); 
void display(void); 
void delay(int); 
unsigned char scan_code[16] = { 0xEE, 0xDE, 0xBE, 0x7E, 0xED, 0xDD, 0xBD, 0x7D, 0xEB, 0xDB, 0xBB, 0x7B, 0xE7, 0xD7, 0xB7, 0x77 };
unsigned char led_code[16] = { 0x3f, 0x66, 0x7f, 0x39, 0x06, 0x6d, 0x6f, 0x5e, 0x5b, 0x7d, 0x77, 0x79, 0x4f, 0x07, 0x7c, 0x71};
unsigned char row, col, key, result; 
int temp3=0;
bit flag = 0; 
void main () 
{ 
	while(1) 
		{ 
			get_key(); 
			display();
			
		}
} 
void get_key(void)
{
	int i;
	flag=0;
	while(flag==0)
	{
		for(i=0;i<4;i++)
		{
			if(i==0) row=0xFE;
			else if(i==1) row = 0xFD;
			else if(i==2) row=0xFB;
			else if(i==3) row=0xF7;
			P0=row;
			scan();
			
			if(flag==1) break;
		}
		if(flag==1) break;
	}
	P3=0x00;
	for(i=0;i<16;i++)
	{
		if(scan_code[i]==key)
		{
			result=led_code[i];
			break;
		}
	}
}
void scan(void)
{
	col=P0;
	col&=0xF0;
	if(col!=0xF0)
	{
		delay(30);
		delay(30);
		col=P0;
		col=col&0xF0;
		if(col!=0xF0)
		{
			flag=1;
			key=col|(row&0x0F);
		}
		else flag=0x00;
	}
}
void display(void)
{
	P1=result;
}
void delay(int i)
{
	int j;
	for(j=0;j<i;j++);
}