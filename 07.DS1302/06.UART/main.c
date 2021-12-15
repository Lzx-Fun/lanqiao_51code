#include "led.h"
#include "exti.h"
#include "timer.h"
#include "seg.h"
#include "key.h"
#include "uart.h"


void main(){
		
		led_init();
		//exti_init();
		timer1_init();
		seg_init();
		uart_init();
		
		while(1){
				
				if(recflag == 1){
						Uart_Sendstring(recbuff);
						num = 0;
						recflag = 0;
				}
				
		}
}

