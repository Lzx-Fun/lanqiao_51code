/*
  程序说明: IIC总线驱动程序
  软件环境: Keil uVision 4.10 
  硬件环境: CT107单片机综合实训平台 8051，12MHz
  日    期: 2011-8-9
*/

#include "iic.h"
#include "intrins.h"

#define DELAY_TIME 5

#define SlaveAddrW 0xA0
#define SlaveAddrR 0xA1

//总线引脚定义
sbit SDA = P2^1;  /* 数据线 */
sbit SCL = P2^0;  /* 时钟线 */

void IIC_Delay(unsigned char i)
{
  do{_nop_();}
  while(i--);        
}
//总线启动条件
/*
	当SCL为高电平时，SDA由高变为低，表示起始信号
*/
//git  linus
//github
void IIC_Start(void)
{
	SDA = 1;
	SCL = 1;
  IIC_Delay(DELAY_TIME);
	SDA = 0;
  IIC_Delay(DELAY_TIME);
}

//总线停止条件
void IIC_Stop(void)
{
	SDA = 0;
	SCL = 1;
	IIC_Delay(DELAY_TIME);
	SDA = 1;
	IIC_Delay(DELAY_TIME);
}

//应答位控制
void IIC_SendAck(bit ackbit)
{
    SCL = 0;
    SDA = ackbit;  					// 0：应答，1：非应答
    IIC_Delay(DELAY_TIME);
    SCL = 1;
    IIC_Delay(DELAY_TIME);
    SCL = 0; 
    SDA = 1;
    IIC_Delay(DELAY_TIME);
}

//等待应答
bit IIC_WaitAck(void)
{
		bit ackbit;
    SCL  = 1;
    IIC_Delay(DELAY_TIME);
    ackbit = SDA;
    SCL = 0;
    IIC_Delay(DELAY_TIME);
    return ackbit;
}

//通过I2C总线发送数据
void IIC_SendByte(unsigned char byt)
{
    unsigned char i;

		for(i=0; i<8; i++)
		{
        SCL  = 0;
        IIC_Delay(DELAY_TIME);
        if(byt & 0x80) SDA  = 1;
        else SDA  = 0;
        IIC_Delay(DELAY_TIME);
        SCL = 1;
        byt <<= 1;
        IIC_Delay(DELAY_TIME);
    }
		
    SCL  = 0;  
}

//从I2C总线上接收数据
unsigned char IIC_RecByte(void)
{
	unsigned char i, da;
	for(i=0; i<8; i++)
	{   
		SCL = 1;
		IIC_Delay(DELAY_TIME);
		da <<= 1;
		if(SDA) da |= 1;
		SCL = 0;
		IIC_Delay(DELAY_TIME);
	}
	return da;    
}




#ifdef EEPROM_AT24C02 /** EEPROM AT24C02操作函数 */

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
#endif

/*
		dat = 0x34   0011 0100
		
		SCL = 0;
		if(dat & 0x80)SDA = 1;
		else SDA = 0;
		IIC_Delay();
		SCL = 1;
		IIC_Delay();
		dat <<= 1;
		

		rev_num = 0;


		SCL = 0;
		IIC_Delay();
		SCL = 1;
		IIC_Delay();
		rev_num <<= 1;
		if(SDA)rev_num |= 0x01;
		


		dat = 0x57; 0101 0111
		            1000 0000

		SCL = 0;
		if(dat & 0x80)SDA = 1;
		else SDA = 0;
		SCL = 1;
		delay_IIC();
		dat <<= 1;





*/







