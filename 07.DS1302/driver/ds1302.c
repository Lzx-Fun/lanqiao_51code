/*
  程序说明: DS1302驱动程序
  软件环境: Keil uVision 4.10 
  硬件环境: CT107单片机综合实训平台 8051，12MHz
  日    期: 2011-8-9
*/

#include <reg52.h>
#include <intrins.h>

sbit SCK=P1^7;		
sbit SDA=P2^3;		
sbit RST = P1^3;   // DS1302复位												

void Write_Ds1302(unsigned  char temp) 
{
	unsigned char i;
	for(i=0;i<8;i++)     	
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
// 设置时钟
void Set_RTC(unsigned char* pucRtc)
{
  unsigned char temp;
  Write_Ds1302_Byte(0x8E, 0); 	//7						// WP=0：允许写操作
  temp = ((pucRtc[0]/10)<<4)+pucRtc[0]%10;
  Write_Ds1302_Byte(0x84, temp);	//2					// 设置时
  temp = ((pucRtc[1]/10)<<4)+pucRtc[1]%10;
  Write_Ds1302_Byte(0x82, temp);	//1					// 设置分
  temp = ((pucRtc[2]/10)<<4)+pucRtc[2]%10;
  Write_Ds1302_Byte(0x80, temp);		//0				// 设置秒
  Write_Ds1302_Byte(0x8E, 0x80);  						// WP=1：禁止写操作
}
// 读取时钟
//strcmp,strcpy
void Read_RTC(unsigned char* pucRtc)
{
  unsigned char temp;

  temp = Read_Ds1302_Byte(0x85);						// 读取时
  pucRtc[0] = (temp>>4)*10+(temp&0xf);
  temp = Read_Ds1302_Byte(0x83);						// 读取分
  pucRtc[1] = (temp>>4)*10+(temp&0xf);
  temp = Read_Ds1302_Byte(0x81);						// 读取秒
  pucRtc[2] = (temp>>4)*10+(temp&0xf);
}

/*
		addr = 0x3A;// 0011 1010   0001 1101
		dat
		CE = 0;
		CE = 1;

		for(i = 0; i < 8; i++){
				SCLK = 0;
				IO = addr & 0x01;
				SCLK = 1;
				addr >>= 1;
		}

		for(i = 0; i < 8; i++){
				SCLK = 0;
				IO = dat & 0x01;
				SCLK = 1;
				dat >>= 1;
		}
		CE = 0;
		SCLK = 0;
*/

/*
		addr = 0x3A;
		

*/













/*
		CE-Chip Enable
		CS-Chip Select
		SCLK/CLK/CK 产生时钟
		I/O 数据传输端口
		CE = 0;
		CE = 1;
		if(i = 0; i<8;i++){
				SCLK = 0;
				if(address & 0x01)
					IO = 1;
				else
					IO = 0;
				SCLK = 1;
				address >>= 1;
		}
		if(i = 0; i<8;i++){
				SCLK = 0;
				if(dat & 0x01)
					IO = 1;
				else
					IO = 0;
				SCLK = 1;
				dat >>= 1;
		}
		CE = 0;

*/
/*
		void send_byte(unsigned char dat)
		{
				for(i = 0; i < 8; i++){
						SCLK = 0;
						SDA = dat & 0x01;
						SCLK = 1;
						dat >>= 1;
				}
		}
		
		
		数据为dat1 = 0xAC   10101100
		CE = 0;
		CE = 1;
		send_byte(dat1);
		send_byte(dat2);
		CE = 0;




*/
/*
		10101100    
		0  0  1   1   0   1   0   1
		unsigned char temp = 0;
		CE = 0;
		CE = 1;
		send_byte(address);
		for(i = 0; i < 8; i++){
				temp >>= 1;
				SCLK = 0;
				if(SDA)
					temp |= 0x80;
				SCLK = 1;
		}
		

		CE = 0;
*/



