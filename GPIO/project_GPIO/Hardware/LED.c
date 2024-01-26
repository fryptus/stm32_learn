#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Key.h"

void LED_Init(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOD, &GPIO_InitStructure);
	
	GPIO_SetBits(GPIOD, GPIO_Pin_2);
}

void LED_Set(unsigned char set){
	if(set == 1){
		GPIO_ResetBits(GPIOD, GPIO_Pin_2);
	}
	else if(set == 0){
		GPIO_SetBits(GPIOD, GPIO_Pin_2);
	}
}

void LED_Turn(void){
	if(GPIO_ReadOutputDataBit(GPIOD, GPIO_Pin_2) == 0){
		GPIO_SetBits(GPIOD, GPIO_Pin_2);
	}
	else{
		GPIO_ResetBits(GPIOD, GPIO_Pin_2);
	}
}

void LED_Breathing(unsigned char vel){
	unsigned char count = vel;
	unsigned char MODE;
	unsigned char Key0Num;
	unsigned char Key1Num;
	
	Key_Init();
	
	int t,i;
	MODE = 0;
	t = 1;
	while(1){
		Key0Num = Key0_GetNum();
		Key1Num = Key1_GetNum();
		
		if(Key0Num == 1){
			count += 5;
		}
		
		if(Key1Num == 1){
			count -= 5;
		}
		
		if(count == 0){
			count = 5;
		}
		
		if(count == 45){
			count = 5;
		}
		
		if(MODE == 0){ 
			for(i = 0; i < count; i++){
				LED_Set(1); 
				Delay_us(t); 
				LED_Set(0);
				Delay_us(501-t); 
			}
			
			t++;
			
			if(t == 500){
				MODE = 1;
			}
		}
		
		if(MODE == 1){ 
			for(i = 0; i < count; i++){
				LED_Set(1); 
				Delay_us(t); 
				LED_Set(0); 
				Delay_us(501-t); 
			}
			
			t--;
			
			if(t==1){
				MODE = 0;
			}
		}		
	}
}
