#include "timer.h"
void timer1_init()
{
	AUXR &= 0xBF;//���ö�ʱ��1Ϊ12��Ƶ
	TMOD &= 0x0F;//���ö�ʱ��1������ģʽ0��ʹ�ö�ʱ�����򿪶�ʱ��
	TL1 = (65536-1000)%256;//���ö�ʱ���ĵ�8λ
	TH1 = (65536-1000)/256;//���ö�ʱ���ĸ�8λ
	TF1 = 0;//Ĭ�������־��0
	TR1 = 1;//����T1��ʼ����
	ET1 = 1;//����T1�ж�
	EA = 1;//�������ж�
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


