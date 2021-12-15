#include "led.h"
#include "exti.h"
#include "timer.h"
#include "seg.h"
#include "key.h"
#include "uart.h"
#include "ds1302.h"
#include "ds18b20.h"
#include "iic.h"
#include "PCF8591.h"
#include "at24c02.h"
#include "ultrasonic.h"
char display[8];
void main(){
		unsigned int value;
		timer1_init();
		timer0_init();
		seg_init();
		while(1){
				if(time_500ms){
					value = wave_recv();
					display[0] = value/100;
					display[1] = value%100/10;
					display[2] = value%100%10;
					//seg_display(0, 1, 0);
					//seg_display(1, value%100/10, 0);
					//seg_display(2, value%100%10, 0);
					time_500ms = 0;
				}
				
				
		}
}

