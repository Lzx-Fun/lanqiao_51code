#include "led.h"
void led_init()
{
		//Ĭ��Ϊ�ر�״̬
		P0 = 0xFF;
		//��������ͨ
		P25 = 0;
		P26 = 0;
		P27 = 1;
		//����������
		P25 = 0;
		P26 = 0;
		P27 = 0;
}
/*
		P25 = 0;
		P26 = 0;
		P27 = 0;//����
	
		P0 = 0;
		P2 = P2 & 0x1F | 0xA0;			// P27~P25���㣬�ٶ�λY5C
		P2 &= 0x1F;						// P27~P25����
*/
void led_display(unsigned char num)
{
		P0 = ~num;
	

	
}
/*
		P25 = 0;
		P26 = 0;
		P27 = 1;//��ͨ
	
		P25 = 0;
		P26 = 0;
		P27 = 0;//����
*/
void delay(unsigned int num)
{
  unsigned int i;
  while(num--)
    for(i=0; i<628; i++);
}