#include "stm32f10x.h"                  // Device header
#include "Delay.h"

int count = 5;

void Key_Init(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
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
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource5);
	
	EXTI_InitTypeDef EXTIC_InitStructure;
	EXTIC_InitStructure.EXTI_Line = EXTI_Line5;
	EXTIC_InitStructure.EXTI_LineCmd = ENABLE;
	EXTIC_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTIC_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_Init(&EXTIC_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef NVICC_InitStructure;
	NVICC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;
	NVICC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVICC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVICC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	
	NVIC_Init(&NVICC_InitStructure);
	
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource15);
	
	EXTI_InitTypeDef EXTIA_InitStructure;
	EXTIA_InitStructure.EXTI_Line = EXTI_Line15;
	EXTIA_InitStructure.EXTI_LineCmd = ENABLE;
	EXTIA_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTIA_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_Init(&EXTIA_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef NVICA_InitStructure;
	NVICA_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
	NVICA_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVICA_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVICA_InitStructure.NVIC_IRQChannelSubPriority = 2;
	
	NVIC_Init(&NVICA_InitStructure);
	
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

void EXTI9_5_IRQHandler(void){
	if(EXTI_GetITStatus(EXTI_Line5) == SET){
		count += 5;
		EXTI_ClearITPendingBit(EXTI_Line5);
	}
}

void EXTI15_10_IRQHandler(void){
	if(EXTI_GetITStatus(EXTI_Line15) == SET){
		count -= 5;
		EXTI_ClearITPendingBit(EXTI_Line15);
	}
}

int Count_Get(void){
	return count;
}
