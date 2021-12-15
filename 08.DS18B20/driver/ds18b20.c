/*
  程序说明: 单总线驱动程序
  软件环境: Keil uVision 4.10 
  硬件环境: CT107单片机综合实训平台(外部晶振12MHz) STC89C52RC单片机
  日    期: 2011-8-9
*/
#include "ds18b20.h"
sbit DQ = P1^4;  //单总线接口

//单总线延时函数
void Delay_OneWire(unsigned int t)  //STC89C52RC
{
	unsigned char i;
	while(t--){
		for(i=0;i<12;i++);
	}
}

//通过单总线向DS18B20写一个字节
void Write_DS18B20(unsigned char dat)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		DQ = 0;
		DQ = dat&0x01;
		Delay_OneWire(5);
		DQ = 1;
		dat >>= 1;
	}
	
	Delay_OneWire(5);
}

//从DS18B20读取一个字节
unsigned char Read_DS18B20(void)
{
	unsigned char i;
	unsigned char dat;
  
	for(i=0;i<8;i++)
	{
		DQ = 0;
		dat >>= 1;
		DQ = 1;
		if(DQ)
		{
			dat |= 0x80;
		}	    
		Delay_OneWire(5);
	}
	return dat;
}

//DS18B20设备初始化
bit init_ds18b20(void)
{
  	bit initflag = 0;
  	DQ = 0;
  	Delay_OneWire(80);
  	DQ = 1;
  	Delay_OneWire(10); 
    initflag = DQ;     
  	return initflag;//如果为低则表示有18B20
}

unsigned int rd_temperature(void)
{
  unsigned char low, high;
	
	if(init_ds18b20()) return 0;//如果没有18B20，就跳出
  Write_DS18B20(0xCC);				// 跳过ROM
  Write_DS18B20(0x44);				// 转换温度
 
  init_ds18b20();
  Write_DS18B20(0xCC);
  Write_DS18B20(0xBE);				// 读暂存器
  low = Read_DS18B20();				// 低字节
  high = Read_DS18B20();			// 高字节
  return (high<<8)+low;
}

/*
			dat = 0xAB   1010 1011
			1.先为0
			2.做判断，如果为0，就有45us的低，如果为1，就有45us的高
			3.高电平持续至少1us
			for(i = 0; i < 8; i++){
					DQ = 0;
					delay_us(15);
					if(dat&0x01)DQ = 1;
					delay_us(30);
					DQ = 1;
					delay_us(2);
					dat = dat >> 1; 
			}
			  

			
			rec_dat = 0xAB   1010 1011
			dat = 0x00       0000 0000
							1        1000 0000 0100 0000
							1        1100 0000 0110 0000 
              0        0110 0000 0011 0000

			1.先为低，延时15us
			2.单片机发送高电平(DS18B20无法自己置高，所以要由单片机置高)，读取DQ
			3.单片机发送高电平维持一段时间
			DQ = 0;
			delay_us(15);
			DQ = 1;
			delay_us(30);
			if(DQ == 1)
					dat2 |= 0x80;
			DQ = 1;
			delay_us(1);
			dat2 >>= 1;		
			第一次   
					dat2 = 0000 0000;读取DQ为1
					dat2 = 1000 0000 
					往右移动一位
					dat2 = 0100 0000
			第二次
					dat2 = 0100 0000;读取DQ为1
					dat2 = 1100 0000;
					往右移动一位
					dat2 = 0110 0000
			第三次
					dat2 = 0110 0000;读取DQ为0
					dat2 = 0110 0000;
*/













