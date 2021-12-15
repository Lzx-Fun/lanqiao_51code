#include "led.h"
#include "exti.h"
#include "timer.h"
#include "seg.h"
#include "key.h"
#include "uart.h"
#include "ds1302.h"
#include "ds18b20.h"
unsigned char pucRtc[3] = {23, 59, 50};
float temper;
void main(){
		timer1_init();
		seg_init();
		while(1){
			
			temper = rd_temperature()/16.0;//Á½Î»Êý  34.67			
			seg_display( 0, temper/10, 0);//3
			seg_display( 1, (int)temper%10, 1);//4
			seg_display( 2, (int)(temper*10)%10, 0);//6
			seg_display( 3, (int)(temper*100)%10, 0);//7
		}
}

