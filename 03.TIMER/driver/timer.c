#include "timer.h"
void timer1_init()
{
	AUXR &= 0xBF;//���ö�ʱ��1Ϊ12��Ƶ
	TMOD &= 0x0F;//���ö�ʱ��1������ģʽ0��ʹ�ö�ʱ�����򿪶�ʱ��
	TL1 = (65536-1000)%256;
	TH1 = (65536-1000)/256;
	TF1 = 0;
	TR1 = 1;//������ʱ��1�ļ�������
	//TCON = TCON & 0x7F | 0x40;
	//IE |= 1<<3;
	ET1 = 1;//��������ж�
	EA = 1;
}

void timer_1(void)interrupt 3
{
	static int ms = 0;
	static int sec = 0;
	ms++;
	
	if(!(ms % 1000))
  {
    sec++;
    led_display(sec);
  }
}


