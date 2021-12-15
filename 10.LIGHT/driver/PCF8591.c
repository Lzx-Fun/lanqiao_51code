#include "PCF8591.h"

unsigned char LIGHT_Adc(void)
{
  unsigned char temp;

  IIC_Start();
  IIC_SendByte(0x90);
  IIC_WaitAck();

  IIC_SendByte(0x01); 				// ʹ��AIN1��������DAC
  IIC_WaitAck();

  IIC_Start();
  IIC_SendByte(0x91);
  IIC_WaitAck();

  temp = IIC_RecByte();
  IIC_SendAck(1);
  IIC_Stop();
  return temp;
}


void PCF8591_Dac(unsigned char dat)
{
  IIC_Start();
  IIC_SendByte(0x90);
  IIC_WaitAck();

  IIC_SendByte(0x43);				
  IIC_WaitAck();

  IIC_SendByte(dat);   			// dat-�����ģת��������
  IIC_WaitAck();
  IIC_Stop();
}


