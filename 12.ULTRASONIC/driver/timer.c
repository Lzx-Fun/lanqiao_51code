#include "timer.h"
unsigned char time_500ms = 0;
void timer1_init()
{
		AUXR &= 0xBF;//配置定时器1为12分频
		TMOD &= 0x0F;//配置定时器1工作在模式0，使用定时器，打开定时器
		TL1 = (65536-1000)%256;
		TH1 = (65536-1000)/256;
		TF1 = 0;
		TR1 = 1;
		//TCON = TCON & 0x7F | 0x40;
		//IE |= 1<<3;
		ET1 = 1;
		EA = 1;
}


//超声波的定时器
void timer0_init()
{
		AUXR &= 0x7F;
		TMOD &= 0xF0;
		TL0 = 0xF4;
		TH0 = 0xFF;
		TF0 = 0;
		TR0 = 0;
}

void timer_1(void)interrupt 3
{
	static int ms = 0;
	static int sec = 0;
	static int cnt = 0;
	ms++;
	if(++cnt == 8) cnt = 0;
	if(!(ms % 500))
  {
    
		time_500ms = 1;
  }
	seg_display(cnt, display[cnt], 0);
}


