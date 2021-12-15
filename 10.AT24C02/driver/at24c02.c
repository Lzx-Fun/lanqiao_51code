#include "at24c02.h"

/**
* @brief 从AT24C02(add)中读出数据da
*
* @param[in] add - AT24C02存储地址
* @param[out] da - 从AT24C02相应地址中读取到的数据
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
* @brief 向AT24C02(add)中写入数据val
*
* @param[in] add - AT24C02存储地址
* @param[in] val - 待写入AT24C02相应地址的数据
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
RAM:	掉电会丢失
ROM:  掉电不丢失
EEPROM：electrical erasable 
随机读/连续读

*/





