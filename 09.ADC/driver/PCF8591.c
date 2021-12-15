#include "PCF8591.h"

unsigned char PCF8591_Adc(void)
{
  unsigned char temp;

  IIC_Start();
  IIC_SendByte(0x90);
  if(IIC_WaitAck()) return 0;

  IIC_SendByte(0x03); 				// 允许DAC，ADC通道3
  if(IIC_WaitAck()) return 0;

  IIC_Start();
  IIC_SendByte(0x91);
  if(IIC_WaitAck()) return 0;

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

  IIC_SendByte(0x43);				// 允许DAC，ADC通道3
  IIC_WaitAck();

  IIC_SendByte(dat);   			// dat-输出数模转换的数据
  IIC_WaitAck();
  IIC_Stop();
}
/*
1.能否描述IIC（I2C）读取单个字节的整个过程
2.能否描述IIC读取多字节的过程
3.IIC的通信速度由什么决定  SCL时钟 100k-3M
4.IIC主从能否变换
5.I2C一次最多能挂载多少设备   112
6.I2C的时序 空闲时SCL的电平


*/


/*
		IIC读时序过程：
		1.起始信号
		2.器件地址
		3.等待应答信号（ACK）

		4.芯片的寄存器地址
		5.等待应答信号（ACK）

		6.器件地址
		7.等待应答信号（ACK）
		
		8.接收数据
		9.发送无应答信号（No ACK）
		10.发送停止信号
*/














