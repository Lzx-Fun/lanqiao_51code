#ifndef __ULTRASONIC_H_
#define __ULTRASONIC_H_
#include "timer.h"

sbit ULTRA_TX = P1^0;
sbit ULTRA_RX = P1^1;
unsigned int wave_recv(void);
#endif