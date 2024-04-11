#ifndef __Serial_H
#define __Serial_H

void Serial_Init(void);
void Serial_SendByte(uint8_t Byte);
void Serial_SendArray(uint8_t *Array, uint16_t Length);
uint8_t Serial_GetData(void);



#endif
