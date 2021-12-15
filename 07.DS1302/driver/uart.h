#ifndef __UART_H
#define __UART_H
#include "STC15F2K60S2.h"
extern unsigned char recbuff[10];
extern unsigned char num;
extern unsigned char recflag;
void uart_init();
void Uart_Sendstring(unsigned char *pucStr);

#endif