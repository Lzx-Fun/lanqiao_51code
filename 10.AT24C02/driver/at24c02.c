#include "at24c02.h"

/**
* @brief ��AT24C02(add)�ж�������da
*
* @param[in] add - AT24C02�洢��ַ
* @param[out] da - ��AT24C02��Ӧ��ַ�ж�ȡ��������
* @return - da
*/
void EEPROM_Read(unsigned char* pucBuf, unsigned char addr, unsigned char num)
{
  	IIC_Start();
  	IIC_SendByte(0xa0);
  	IIC_WaitAck();

  	IIC_SendByte(addr);
  	IIC_WaitAck();

  	IIC_Start();
  	IIC_SendByte(0xa1);
  	IIC_WaitAck();

  	while(num--)
  	{
    		*pucBuf++ = IIC_RecByte();
    		if(num) IIC_SendAck(0);
    		else IIC_SendAck(1);
  	}
  	IIC_Stop();
}
/**
* @brief ��AT24C02(add)��д������val
*
* @param[in] add - AT24C02�洢��ַ
* @param[in] val - ��д��AT24C02��Ӧ��ַ������
* @return - none
*/
void EEPROM_Write(unsigned char* pucBuf, unsigned char addr, unsigned char num)
{
   	IIC_Start();
  	IIC_SendByte(0xa0);
  	IIC_WaitAck();

  	IIC_SendByte(addr);
  	IIC_WaitAck();

  	while(num--)
  	{
    		IIC_SendByte(*pucBuf++); 
    		IIC_WaitAck();
  	   	IIC_Delay(200);
		}
  	IIC_Stop();
}






/*
RAM:	����ᶪʧ
ROM:  ���粻��ʧ
EEPROM��electrical erasable 
�����/������

*/





