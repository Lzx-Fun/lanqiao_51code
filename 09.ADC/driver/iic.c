/*
  ����˵��: IIC������������
  �������: Keil uVision 4.10 
  Ӳ������: CT107��Ƭ���ۺ�ʵѵƽ̨ 8051��12MHz
  ��    ��: 2011-8-9
*/

#include "iic.h"
#include "intrins.h"

#define DELAY_TIME 5

#define SlaveAddrW 0xA0
#define SlaveAddrR 0xA1

//�������Ŷ���
sbit SDA = P2^1;  /* ������ */
sbit SCL = P2^0;  /* ʱ���� */

void IIC_Delay(unsigned char i)
{
  do{_nop_();}
  while(i--);        
}
//������������
/*
	��SCLΪ�ߵ�ƽʱ��SDA�ɸ߱�Ϊ�ͣ���ʾ��ʼ�ź�
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

//����ֹͣ����
void IIC_Stop(void)
{
	SDA = 0;
	SCL = 1;
	IIC_Delay(DELAY_TIME);
	SDA = 1;
	IIC_Delay(DELAY_TIME);
}

//Ӧ��λ����
void IIC_SendAck(bit ackbit)
{
    SCL = 0;
    SDA = ackbit;  					// 0��Ӧ��1����Ӧ��
    IIC_Delay(DELAY_TIME);
    SCL = 1;
    IIC_Delay(DELAY_TIME);
    SCL = 0; 
    SDA = 1;
    IIC_Delay(DELAY_TIME);
}

//�ȴ�Ӧ��
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

//ͨ��I2C���߷�������
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

//��I2C�����Ͻ�������
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




#ifdef EEPROM_AT24C02 /** EEPROM AT24C02�������� */

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







