/*
  ����˵��: ��������������
  �������: Keil uVision 4.10 
  Ӳ������: CT107��Ƭ���ۺ�ʵѵƽ̨(�ⲿ����12MHz) STC89C52RC��Ƭ��
  ��    ��: 2011-8-9
*/
#include "ds18b20.h"
sbit DQ = P1^4;  //�����߽ӿ�

//��������ʱ����
void Delay_OneWire(unsigned int t)  //STC89C52RC
{
	unsigned char i;
	while(t--){
		for(i=0;i<12;i++);
	}
}

//ͨ����������DS18B20дһ���ֽ�
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

//��DS18B20��ȡһ���ֽ�
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

//DS18B20�豸��ʼ��
bit init_ds18b20(void)
{
  	bit initflag = 0;
  	DQ = 0;
  	Delay_OneWire(80);
  	DQ = 1;
  	Delay_OneWire(10); 
    initflag = DQ;     
  	return initflag;//���Ϊ�����ʾ��18B20
}

unsigned int rd_temperature(void)
{
  unsigned char low, high;
	
	if(init_ds18b20()) return 0;//���û��18B20��������
  Write_DS18B20(0xCC);				// ����ROM
  Write_DS18B20(0x44);				// ת���¶�
 
  init_ds18b20();
  Write_DS18B20(0xCC);
  Write_DS18B20(0xBE);				// ���ݴ���
  low = Read_DS18B20();				// ���ֽ�
  high = Read_DS18B20();			// ���ֽ�
  return (high<<8)+low;
}

/*
			dat = 0xAB   1010 1011
			1.��Ϊ0
			2.���жϣ����Ϊ0������45us�ĵͣ����Ϊ1������45us�ĸ�
			3.�ߵ�ƽ��������1us
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

			1.��Ϊ�ͣ���ʱ15us
			2.��Ƭ�����͸ߵ�ƽ(DS18B20�޷��Լ��øߣ�����Ҫ�ɵ�Ƭ���ø�)����ȡDQ
			3.��Ƭ�����͸ߵ�ƽά��һ��ʱ��
			DQ = 0;
			delay_us(15);
			DQ = 1;
			delay_us(30);
			if(DQ == 1)
					dat2 |= 0x80;
			DQ = 1;
			delay_us(1);
			dat2 >>= 1;		
			��һ��   
					dat2 = 0000 0000;��ȡDQΪ1
					dat2 = 1000 0000 
					�����ƶ�һλ
					dat2 = 0100 0000
			�ڶ���
					dat2 = 0100 0000;��ȡDQΪ1
					dat2 = 1100 0000;
					�����ƶ�һλ
					dat2 = 0110 0000
			������
					dat2 = 0110 0000;��ȡDQΪ0
					dat2 = 0110 0000;
*/













