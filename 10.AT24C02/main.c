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

unsigned char write_buff[10] = {89, 98, 76, 89};
unsigned char read_buff[3] = {0};
unsigned char save_address = 0;
void main(){
		//led_init();
		//exti_init();
		timer1_init();
		seg_init();
		//uart_init();
		//Set_RTC(pucRtc);
		EEPROM_Write( write_buff, save_address, sizeof(write_buff)/sizeof(write_buff[0]));
	
	
		i = i + 5;
		delay(500);
		EEPROM_Read ( read_buff, save_address, 3);
		while(1){
				seg_display(0, read_buff[0]/10, 0);
				seg_display(1, read_buff[0]%10, 0);
				seg_display(2, read_buff[1]/10, 0);
				seg_display(3, read_buff[1]%10, 0);
				seg_display(4, read_buff[2]/10, 0);
				seg_display(5, read_buff[2]%10, 0);
		}
}

