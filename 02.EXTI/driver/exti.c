#include "exti.h"
void exti_init()
{
	//�Ĵ����������⹦�ܵ��ڴ棬������ڴ���и�ֵ���Ϳ�������MCU�Ĳ���
	EX1 = 1;//�����ⲿ�ж�1    
	IT1 = 1;//���ó��½��ش���ģʽ
	
	EX0 = 1;
	IT0 = 1;
	
	EA = 1;//�������ж�
}

void exti_0(void) interrupt 0
{
	static int i = 0;
	i++;
	if(i%2)
		led_display(0xFF);
	else 
		led_display(0x00);
}	

void exti_1(void) interrupt 2
{
	static int i = 0;
	i++;
	if(i%2)
		led_display(0xFF);
	else 
		led_display(0x00);
}	

