#include "seg.h"
void seg_init(void)
{
	P0 = 0x00;//COM1为高
	P2 = P2 & 0xDF | 0xC0;
	P2 &= 0x1F;
	
	
	P0 = 0xC0;
	P2 |= 0xEF;
	P2 &= 0x1F;

	
}

void seg_display(unsigned char pos, unsigned char num, unsigned char dot)
{
	unsigned char temp;
	switch(num){
		case 0:temp = 0xC0;break;
		case 1:temp = 0xf9;break;
		case 2:temp = 0xa4;break;
		case 3:temp = 0xb0;break;
		case 4:temp = 0x99;break;
		case 5:temp = 0x92;break;
		case 6:temp = 0x82;break;
		case 7:temp = 0xf8;break;
		case 8:temp = 0x80;break;
		case 9:temp = 0x90;break;
	}
	if(dot == 1){
		temp &= 0x7f;
	}
	//消隐
	P0 = 0xFF;
	P2 |= 0xE0;
	P2 &= 0x1F;
	
	//控制位
	P0 = 1<<pos;//COM1为高
	P2 = P2 & 0xDF | 0xC0;//导通Y6
	P2 &= 0x1F;
	
	//控制段
	P0 = temp;
	P2 |= 0xE0;
	P2 &= 0x1F;

}