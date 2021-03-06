#include "uart.h"

unsigned char recbuff[10] = 0;
unsigned char num = 0;
unsigned char recflag = 0;
void uart_init()
{
	SCON = 0x50;						// 8位数据,可变波特率
  AUXR |= 0x01;						// 串口1选择定时器2为波特率发生器
  AUXR |= 0x04;						// 定时器2时钟为Fosc, 即1T
  T2L = 0x8F;						// 设定定时初值
  T2H = 0xFD; 						// 设定定时初值
  AUXR |= 0x10;						// 启动定时器2
  ES = 1;									// 允许串口中断
	EA = 1;
}

void Uart_Sendstring(unsigned char *pucStr)
{
  while(*pucStr != '\0')
  {
    SBUF = *pucStr;
    while(TI == 0);
    TI = 0;
    pucStr++;
  }
}


void uart_0(void) interrupt 4
{
  if(RI)
  {
		recbuff[num++] = SBUF;
    RI = 0;
		recflag = 1;
  }
}

