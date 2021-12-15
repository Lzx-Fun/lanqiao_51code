#ifndef __ONEWIRE_H
#define __ONEWIRE_H
#include "STC15F2K60S2.h"
void Delay_OneWire(unsigned int t);
void Write_DS18B20(unsigned char dat);
unsigned char Read_DS18B20(void);
bit init_ds18b20(void);
unsigned int rd_temperature(void);
#endif
