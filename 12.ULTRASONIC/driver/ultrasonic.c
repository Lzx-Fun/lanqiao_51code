#include "ultrasonic.h"
unsigned int wave_recv(void)
{
		unsigned int ucDist;
		ULTRA_TX = 0;//trig管脚输出的是1
		TL0 = 0xF4;
		TH0 = 0xFF;
		TR0 = 1;
		
		while(!TF0);
		ULTRA_TX ^= 1;
		TF0 = 0;
		
		TR0 = 0;
		TL0 = 0;
		TH0 = 0;
		if(ULTRA_RX)
			TR0 = 1;
		while(ULTRA_RX && !TF0);
		TR0 = 0;
		if(TF0){
				TF0 = 0;
				ucDist = 255;
		}else{
				ucDist = ((TH0<<8)+TL0)*0.017;
		}
		return ucDist;
}


