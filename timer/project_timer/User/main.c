#include "stm32f10x.h"                  // Device header
#include "LED.h"
#include "Key.h"
#include "Delay.h"
#include "Timer.h"

int num;

int main(void)
{
	LED_Init();
	Timer_Init();
	
	while(1){
		LED_Set(1);
		Delay_s(num);
		LED_Set(0);
		Delay_s(num);
	}
	
}

void TIM2_IRQHandler(void){
	if(TIM_GetITStatus(TIM2, TIM_IT_Update) == SET){
		num++;
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	}
}
