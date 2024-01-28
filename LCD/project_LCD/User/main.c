#include "stm32f10x.h"                  // Device header
#include "LED.h"
#include "Serial.h"
#include "SysDelay.h"
#include "LCD.h"
#include "USART.h"
#include "math.h"

int num;
u16 lastX,lastY;
u8 firstPoint = 1;
u16 i=0;

short int rawValue[100]={200,400,600,800,1000,1400,2000,2600,3200,3800,4400,5400,6400,7000,7800,8600,9400,10000,10400,\
	10800,11200,11400,11600,11800,12000,11000,10000,9200,8600,8000,7600,7200,6800,6400,6000,5400,5000,4600,4200,3800,3000,\
	2600,2400,2200,2000,1600,1200,1000,800,400,200,0,-200,-600,-1200,-1800,-2400,-3600,-4000,-3800,-3200,-2600,-2000,-1400,\
	-800,-400,-200,0,400,600,800,1000,1400,2000,2600,3200,3800,4400,5400,6400,7000,7800,8600,9400,10000,10400,10800,11200,11400};

	
void drawCurve(short int rawValue){
	u16 x,y;
	y = 120 - rawValue/280;
	// y = rawValue;
	if(firstPoint){
		LCD_DrawPoint(0,y);
		lastX=0;
		lastY=y;
		firstPoint=0;
	}
	else{
		x=lastX+1;
		if(x<320){
			LCD_DrawLine(lastX,lastY,x,y);
			lastX=x;
			lastY=y;
		}
		else{
			LCD_Clear(WHITE);
			LCD_DrawPoint(0,y);
			lastX=0;
			lastY=y;
		}
  }
}

 int main(void){
	u16 x=0;
	delay_init();	    	 
	uart_init(9600);	 	
	LED_Init();		  		
 	LCD_Init();
	POINT_COLOR=RED; 	
  LCD_Display_Dir(1);
	 
  while(1){
     for(x=0;x<80;x++){
			drawCurve(rawValue[x]);
			delay_ms(2);
		}
	} 
}


