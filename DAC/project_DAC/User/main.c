#include "stm32f10x.h"                  // Device header
#include "LED.h"
#include "Serial.h"
#include "SysDelay.h"
#include "LCD.h"
#include "USART.h"
#include "Key.h"
#include "UsrDMA.h"
#include "Display.h"
#include "AD.h"
#include "DA.h"


int main (void){
	
	u8 String[20];
	u16 ADC_Data;
	u16 DAC_Data;
	
	delay_init();
	uart_init(9600);
	LCD_Init();
	AD_Init();
	DA_Init();
	
	LCD_Clear(WHITE);
	POINT_COLOR = RED;
	
	LCD_ShowString(30, 40, 200, 24, 24, "DAC");
	
	while(1){
		ADC_Data = AD_GetValue();
		DAC_Data = DAC_GetDataOutputValue(DAC_Channel_1);
		
		sprintf((char*)String, "ADC: %d", ADC_Data);
		LCD_ShowString(30, 110, 200, 16, 16, String);
		
		sprintf((char*)String, "DAC: %d", DAC_Data);
		LCD_ShowString(30, 130, 200, 16, 16, String);
	}
}

