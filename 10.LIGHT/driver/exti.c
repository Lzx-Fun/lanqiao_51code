#include "exti.h"

void exti_init()
{
	EX1 = 1;//开启外部中断1
	IT1 = 1;//配置成下降沿触发模式
	
	EX0 = 1;
	IT0 = 1;
	
	EA = 1;//开启总中断
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

