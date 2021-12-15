#ifndef __TIMER_H
#define __TIMER_H
#include "STC15F2K60S2.h"
#include "led.h"
#include "uart.h"
#include "ds1302.h"
void timer1_init();
extern unsigned char recvBuff[3];

#endif

