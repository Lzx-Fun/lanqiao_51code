#include "led.h"
#include "exti.h"
#include "timer.h"
#include "seg.h"


void main(){
		int i = 0;
		seg_init();
		while(1){
			for(i = 0; i < 8; i++)
				seg_display(i, i);
			
		}
}

