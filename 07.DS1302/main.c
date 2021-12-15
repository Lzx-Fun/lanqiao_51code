#include "led.h"
#include "exti.h"
#include "timer.h"
#include "seg.h"
#include "key.h"
#include "uart.h"
#include "ds1302.h"
unsigned char pucRtc[3] = {23, 59, 50};
unsigned char recvBuff[3];
void main(){
		timer1_init();
		seg_init();
		Set_RTC(pucRtc);
		while(1){
			seg_display( 0, recvBuff[0]/10);
			seg_display( 1, recvBuff[0]%10);
			seg_display( 2, recvBuff[1]/10);
			seg_display( 3, recvBuff[1]%10);
			seg_display( 4, recvBuff[2]/10);
			seg_display( 5, recvBuff[2]%10);
		}
}

