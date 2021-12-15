#include "led.h"
void led_init()
{
		P0 = 0xFF;
		P25 = 0;
		P26 = 0;
		P27 = 1;//导通
	
		P25 = 0;
		P26 = 0;
		P27 = 0;//锁存
}

void led_display(unsigned char num)
{
		P0 = ~num;
	
		P25 = 0;
		P26 = 0;
		P27 = 1;//导通
	
		P25 = 0;
		P26 = 0;
		P27 = 0;//锁存
}

void delay(unsigned int num)
{
  unsigned int i;
  while(num--)
    for(i=0; i<628; i++);
}

