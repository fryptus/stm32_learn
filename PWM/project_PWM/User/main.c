#include "stm32f10x.h"                  // Device header
#include "LED.h"
#include "Key.h"
#include "Delay.h"
#include "PWM.h"

int num;

int main(void)
{
	LED_Init();
	PWM_Init();
	
	unsigned char i;
	
	while(1){
		// LED_Set(1);
		for(i = 0; i <= 100; i++){
			PWM_SetCompare1(i);
			Delay_ms(10);
		}
		
		for(i = 0; i <= 100; i++){
			PWM_SetCompare1(100 - i);
			Delay_ms(10);
		}
	}
	
}


