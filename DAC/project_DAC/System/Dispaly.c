#include "stm32f10x.h"                  // Device header
#include "LCD.h"

void Ui_Display(void){
	uint16_t t;
	
	LCD_Fill(0,0,800,340,WHITE);
	POINT_COLOR=GREEN;
	
	for(t  = 0; t < 180; t = t + 10){
		LCD_DrawLine(0, t, 320, t);
	}
	for(t  = 0; t < 320; t = t + 10){
		LCD_DrawLine(t,0, t, 170);
	}
	
	POINT_COLOR=BLUE;
	
	LCD_DrawLine(0, 90, 320, 90);
	LCD_DrawLine(160, 0, 160, 170);
}
