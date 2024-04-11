#include "stm32f10x.h"                  // Device header
#include "LED.h"
#include "Serial.h"
#include "SysDelay.h"
#include "LCD.h"
#include "USART.h"
#include "Key.h"
#include "UsrDMA.h"

uint8_t PeriData[4] = {1, 2, 3, 4};
uint8_t MemData[4] = {0, 0, 0, 0};
uint16_t Key0Num;


int main (void){
	u8 String[20];
	uint16_t i;
	
	delay_init();
	uart_init(9600);
	LCD_Init();
	Key_Init();
	
	LCD_Clear(WHITE);
	POINT_COLOR = RED;
	
	LCD_ShowString(30, 40, 200, 24, 24, (u8*)"DMA");
	
	sprintf((char*)String, "PeriData: %d %d %d %d", PeriData[0], PeriData[1], PeriData[2], PeriData[3]);
	LCD_ShowString(30, 70, 200, 16, 16, String);
	sprintf((char*)String, "MemData: %d %d %d %d", MemData[0], MemData[1], MemData[2], MemData[3]);
	LCD_ShowString(30, 90, 200, 16, 16, String);
	
	SoftwareTrigDMA_Init((uint32_t)PeriData, (uint32_t)MemData, 4);
	
	sprintf((char*)String, "PeriData: %d %d %d %d", PeriData[0], PeriData[1], PeriData[2], PeriData[3]);
	LCD_ShowString(30, 120, 200, 16, 16, String);
	sprintf((char*)String, "MemData: %d %d %d %d", MemData[0], MemData[1], MemData[2], MemData[3]);
	LCD_ShowString(30, 140, 200, 16, 16, String);
	
	while(1){
		delay_ms(1000);
		PeriData[0]++; PeriData[1]++; PeriData[2]++; PeriData[3]++;
		
		sprintf((char*)String, "PeriData change: %d %d %d %d", PeriData[0], PeriData[1], PeriData[2], PeriData[3]);
		LCD_ShowString(30, 170, 200, 16, 16, String);
		delay_ms(1000);
		
		SoftwareTrigDMA_Transfer();
		sprintf((char*)String, "MemData: %d %d %d %d", MemData[0], MemData[1], MemData[2], MemData[3]);
		LCD_ShowString(30, 190, 200, 16, 16, String);
		
		i++;
		
		if(i == 10){
			break;
		}
	}
	
	while(1);
}

