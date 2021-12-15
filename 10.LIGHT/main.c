#include "led.h"
#include "exti.h"
#include "timer.h"
#include "seg.h"
#include "key.h"
#include "uart.h"
#include "ds1302.h"
#include "ds18b20.h"
#include "PCF8591.h"

void main(){
		unsigned char val;
		float val_f;
		//led_init();
		//exti_init();
		timer1_init();
		seg_init();
		//uart_init();
		//Set_RTC(pucRtc);
		while(1){
				/*
				if(recflag == 1){
						Uart_Sendstring(recbuff);
						recflag = 0;
				}
				*/
			if(time_500ms == 1){
				val = LIGHT_Adc();
				PCF8591_Dac(val);//���ģ���ѹ
				time_500ms = 0;
			}
			val_f = 5 - val * 4.9 / 255.0;//�����4.9����Ϊ����ܴﵽ4.9V������İ��ӻ�Ҫ����ȥ����
			seg_display(0, (unsigned char)val_f, 1);
			seg_display(1, (unsigned char)(val_f*10)%10, 0);
			seg_display(2, (unsigned char)(val_f*100)%10, 0);
		}
}

