#ifndef _IIC_H
#define _IIC_H
#include "STC15F2K60S2.h"
//º¯ÊýÉùÃ÷
void IIC_Delay(unsigned char i);
void IIC_Start(void); 
void IIC_Stop(void);  
bit IIC_WaitAck(void);  
void IIC_SendAck(bit ackbit); 
void IIC_SendByte(unsigned char byt); 
unsigned char IIC_RecByte(void); 


void EEPROM_Read(unsigned char* pucBuf, unsigned char addr, unsigned char num);
void EEPROM_Write(unsigned char* pucBuf, unsigned char addr, unsigned char num);
#endif
