#include "timer.h"
unsigned char time_500ms = 0;
void timer1_init()
{
	AUXR &= 0xBF;//���ö�ʱ��1Ϊ12��Ƶ
	TMOD &= 0x0F;//���ö�ʱ��1������ģʽ0��ʹ�ö�ʱ�����򿪶�ʱ��
	TL1 = (65536-1000)%256;
	TH1 = (65536-1000)/256;
	TF1 = 0;
	TR1 = 1;
	//TCON = TCON & 0x7F | 0x40;
	//IE |= 1<<3;
	ET1 = 1;
	EA = 1;
}

void timer_1(void)interrupt 3
{
	static int ms = 0;
	static int sec = 0;
	char arr[10] = "Hello\n";
	ms++;
	
	if(!(ms % 500))
  {
    sec++;
		time_500ms = 1;
  }
}


