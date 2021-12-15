#ifndef __TIMER_H
#define __TIMER_H
#include "STC15F2K60S2.h"
#include "led.h"
#include "uart.h"
#include "ds1302.h"
#include "ds18b20.h"
#include "seg.h"
void timer1_init();
void timer0_init();
extern unsigned char time_500ms;
extern char display[8];
#endif

