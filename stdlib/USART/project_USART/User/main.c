#include "stm32f10x.h"                  // Device header
#include "LED.h"
#include "Serial.h"
#include "Delay.h"
#include "PWM.h"

int num;

int main(void)
{
	LED_Init();
	Serial_Init();
	
	Serial_SendByte(0x41);
	
	while(1){
		if(Serial_GetData()){
			LED_IBreathing();
		}
	}
}
	



