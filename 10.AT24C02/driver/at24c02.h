#ifndef __AT24C02_H_
#define __AT24C02_H_
#include "iic.h"


void EEPROM_Read(unsigned char* pucBuf, unsigned char addr, unsigned char num);
void EEPROM_Write(unsigned char* pucBuf, unsigned char addr, unsigned char num);


#endif
