#include "led.h"
#include "exti.h"
#include "timer.h"
#include "seg.h"
#include "key.h"
unsigned char seg_buff[8] = {10, 10, 10, 10, 10, 10, 10, 10};
void main(){
	unsigned char val;
	led_init();
	timer1_init();
	seg_init();
	while(1){
		if(key_read()){
			delay(20);
			if(val = key_read()){
				seg_buff[6] = val/10;
				seg_buff[7] = val%10;
			}else{
				seg_buff[6] = 0;
				seg_buff[7] = 0;
			}
		}else{
			seg_buff[6] = 0;
			seg_buff[7] = 0;
		}
	}
}

void timer_1(void)interrupt 3
{
	static int cnt = 0;
	if(++cnt == 8) cnt = 0;
	seg_display(cnt, seg_buff[cnt]);
}