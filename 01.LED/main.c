#include "led.h"

void main(){
		int i = 0;
		led_init();

		while(1){
			for( i = 0; i < 21; i++){
					led_display(0xFF);
					delay(20-i);
					led_display(0x00);
					delay(i);
			}
		}
}



