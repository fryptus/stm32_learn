#include "stm32f10x.h"                  // Device header
#include "Delay.h"

void Key_Init(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	GPIO_InitTypeDef GPIOC_InitStructure;
	GPIOC_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIOC_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIOC_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIOC_InitStructure);
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	GPIO_InitTypeDef GPIOA_InitStructure;
	GPIOA_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIOA_InitStructure.GPIO_Pin = GPIO_Pin_15;
	GPIOA_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIOA_InitStructure);
	
}

unsigned char Key0_GetNum(void){
	unsigned char Key0Num = 0;
	if(GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_5) == 0){
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_5) == 0);
		Delay_ms(20);
		Key0Num = 1;
	}
	
	return Key0Num;
}

unsigned char Key1_GetNum(void){
	unsigned char Key1Num = 0;
	if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_15) == 0){
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_15) == 0);
		Delay_ms(20);
		Key1Num = 1;
	}
	
	return Key1Num;
}
