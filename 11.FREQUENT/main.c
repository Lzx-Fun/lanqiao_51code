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

unsigned int fre_val = 0;
void main(){
		
		timer1_init();
		timer0_init();
		seg_init();
		while(1){
				seg_display(0, fre_val/10000, 0);
				seg_display(1, fre_val/1000%10, 0);
				seg_display(2, fre_val/100%10, 0);
				seg_display(3, fre_val/10%10, 0);
				seg_display(4, fre_val%10, 0);
		}
}

