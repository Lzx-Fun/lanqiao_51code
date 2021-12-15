/*
  ����˵��: DS1302��������
  �������: Keil uVision 4.10 
  Ӳ������: CT107��Ƭ���ۺ�ʵѵƽ̨ 8051��12MHz
  ��    ��: 2011-8-9
*/

#include "ds1302.h"
#include "STC15F2K60S2.h"
#include <intrins.h>

sbit SCK=P1^7;		
sbit SDA=P2^3;		
sbit RST = P1^3;   // DS1302��λ												

void Write_Ds1302(unsigned  char temp) 
{
	unsigned char i;
	for (i=0;i<8;i++)     	
	{
		SCK=0;
		SDA=temp&0x01;
		temp>>=1; 
		SCK=1;
	}
}   

void Write_Ds1302_Byte( unsigned char address,unsigned char dat )     
{
 	RST=0;	_nop_();
 	SCK=0;	_nop_();
 	RST=1; 	_nop_();  
 	Write_Ds1302(address);	
 	Write_Ds1302(dat);		
 	RST=0; 
}

unsigned char Read_Ds1302_Byte ( unsigned char address )
{
 	unsigned char i,temp=0x00;
 	RST=0;	_nop_();
 	SCK=0;	_nop_();
 	RST=1;	_nop_();
 	Write_Ds1302(address);
 	for (i=0;i<8;i++) 	
 	{		
		SCK=0;
		temp>>=1;	
 		if(SDA)
 		temp|=0x80;	
 		SCK=1;
	} 
 	RST=0;	_nop_();
	SCK=0;	_nop_();
	SDA=0;	_nop_();
	return (temp);			
}
// ����ʱ��
void Set_RTC(unsigned char* pucRtc)
{
  unsigned char temp;

  Write_Ds1302_Byte(0x8E, 0); 							// WP=0������д����
  temp = ((pucRtc[0]/10)<<4)+pucRtc[0]%10;
  Write_Ds1302_Byte(0x84, temp);						// ����ʱ
  temp = ((pucRtc[1]/10)<<4)+pucRtc[1]%10;
  Write_Ds1302_Byte(0x82, temp);						// ���÷�
  temp = ((pucRtc[2]/10)<<4)+pucRtc[2]%10;
  Write_Ds1302_Byte(0x80, temp);						// ������
  Write_Ds1302_Byte(0x8E, 0x80);  						// WP=1����ֹд����
}
// ��ȡʱ��
void Read_RTC(unsigned char* pucRtc)
{
  unsigned char temp;

  temp = Read_Ds1302_Byte(0x85);						// ��ȡʱ
  pucRtc[0] = (temp>>4)*10+(temp&0xf);
  temp = Read_Ds1302_Byte(0x83);						// ��ȡ��
  pucRtc[1] = (temp>>4)*10+(temp&0xf);
  temp = Read_Ds1302_Byte(0x81);						// ��ȡ��
  pucRtc[2] = (temp>>4)*10+(temp&0xf);
}
