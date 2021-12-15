#include "timer.h"
void timer1_init()
{
	AUXR &= 0xBF;//配置定时器1为12分频
	TMOD &= 0x0F;//配置定时器1工作在模式0，使用定时器，打开定时器
	TL1 = (65536-1000)%256;//配置定时器的低8位
	TH1 = (65536-1000)/256;//配置定时器的高8位
	TF1 = 0;//默认溢出标志清0
	TR1 = 1;//允许T1开始计数
	ET1 = 1;//允许T1中断
	EA = 1;//开启总中断
}

void timer_1(void)interrupt 3
{
	static int ms = 0;
	ms++;
	if(!(ms % 1000))
  {
    //led_display(sec);
  }
}


