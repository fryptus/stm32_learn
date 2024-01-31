#include "stm32f10x.h"                  // Device header
#include "LED.h"
#include "Timer.h"
#include "AD.h"
#include "SysDelay.h"
#include "LCD.h"
#include "USART.h"
#include "Key.h"
#include "UsrDMA.h"
#include "Display.h"



int main (void){
	
	u8 String[20];
	u16 ADC_Data;
	float voltage;
	
	delay_init();
	uart_init(9600);
	LCD_Init();
	AD_Init();
	
	LCD_Clear(WHITE);
	POINT_COLOR = RED;
	
	LCD_ShowString(30, 40, 200, 24, 24, "ADC");
	
	while(1){
		ADC_Data = AD_GetValue();
		voltage = (float)ADC_Data / 4095 * 3.3;
		
		sprintf((char*)String, "ADC: %d", ADC_Data);
		LCD_ShowString(30, 110, 200, 16, 16, String);
		
		sprintf((char*)String, "voltage: %d", (u16)voltage);
		LCD_ShowString(30, 130, 200, 16, 16, String);
	}
}

