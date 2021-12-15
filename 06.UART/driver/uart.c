#include "uart.h"

unsigned char recbuff[10] = 0;
unsigned char num = 0;
unsigned char recflag = 0;

void uart_init()//4800
{
	SCON = 0x50;						// 8λ����,�ɱ䲨����
  AUXR |= 0x01;						// ����1ѡ��ʱ��2Ϊ�����ʷ�����
  AUXR |= 0x04;						// ��ʱ��2ʱ��ΪFosc, ��1T
  T2L = 0x8F;						// �趨��ʱ��ֵ
  T2H = 0xFD; 						// �趨��ʱ��ֵ
  AUXR |= 0x10;						// ������ʱ��2
  ES = 1;									// �������ж�
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
//1.�ܹ����յ�1���ַ�
//2.�ܹ���ʱ�����ַ���
//3.�ܹ������ַ���
//4.�ѽ��յ������ݷ��ͻ�ȥ

void uart_0(void) interrupt 4
{
	unsigned char dat;
	
  if(RI)
  {
		recbuff[num++] = SBUF;
    RI = 0;
		recflag = 1;
  }
}

