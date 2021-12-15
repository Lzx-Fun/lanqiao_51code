#include "PCF8591.h"

unsigned char PCF8591_Adc(void)
{
  unsigned char temp;

  IIC_Start();
  IIC_SendByte(0x90);
  if(IIC_WaitAck()) return 0;

  IIC_SendByte(0x03); 				// ����DAC��ADCͨ��3
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

  IIC_SendByte(0x43);				// ����DAC��ADCͨ��3
  IIC_WaitAck();

  IIC_SendByte(dat);   			// dat-�����ģת��������
  IIC_WaitAck();
  IIC_Stop();
}
/*
1.�ܷ�����IIC��I2C����ȡ�����ֽڵ���������
2.�ܷ�����IIC��ȡ���ֽڵĹ���
3.IIC��ͨ���ٶ���ʲô����  SCLʱ�� 100k-3M
4.IIC�����ܷ�任
5.I2Cһ������ܹ��ض����豸   112
6.I2C��ʱ�� ����ʱSCL�ĵ�ƽ


*/


/*
		IIC��ʱ����̣�
		1.��ʼ�ź�
		2.������ַ
		3.�ȴ�Ӧ���źţ�ACK��

		4.оƬ�ļĴ�����ַ
		5.�ȴ�Ӧ���źţ�ACK��

		6.������ַ
		7.�ȴ�Ӧ���źţ�ACK��
		
		8.��������
		9.������Ӧ���źţ�No ACK��
		10.����ֹͣ�ź�
*/














