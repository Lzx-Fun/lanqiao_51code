#include "led.h"
void led_init()
{
		//默认为关闭状态
		P0 = 0xFF;
		//锁存器导通
		P25 = 0;
		P26 = 0;
		P27 = 1;
		//锁存器锁存
		P25 = 0;
		P26 = 0;
		P27 = 0;
}
/*
		P25 = 0;
		P26 = 0;
		P27 = 0;//锁存
	
		P0 = 0;
		P2 = P2 & 0x1F | 0xA0;			// P27~P25清零，再定位Y5C
		P2 &= 0x1F;						// P27~P25清零
*/
void led_display(unsigned char num)
{
		P0 = ~num;
	

	
}
/*
		P25 = 0;
		P26 = 0;
		P27 = 1;//导通
	
		P25 = 0;
		P26 = 0;
		P27 = 0;//锁存
*/
void delay(unsigned int num)
{
  unsigned int i;
  while(num--)
    for(i=0; i<628; i++);
}