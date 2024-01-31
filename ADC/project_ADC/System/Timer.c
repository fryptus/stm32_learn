#include "stm32f10x.h"                  // Device header

void Timer_Init(void){
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	// RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	/*
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	*/
	
	// GPIO_SetBits(GPIOA, GPIO_Pin_8);
	
	TIM_InternalClockConfig(TIM2);
	// TIM_ETRClockMode2Config(TIM2, TIM_ExtTRGPSC_OFF, TIM_ExtTRGPolarity_NonInverted, 0x00);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = 10000 - 1;
	TIM_TimeBaseInitStructure.TIM_Prescaler = 7200 - 1;
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);
	
	TIM_ClearFlag(TIM2, TIM_FLAG_Update);
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_Cmd(TIM2, ENABLE);
	
}

void TIM3_Init(void){
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	
	TIM_TimeBaseInitTypeDef TIM3_InitStructure;

	TIM3_InitStructure.TIM_Period = 10;
	TIM3_InitStructure.TIM_CounterMode = TIM_CounterMode_Up ;
	TIM3_InitStructure.TIM_Prescaler = 7199;
	TIM3_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1 ;
	TIM_TimeBaseInit (TIM3, &TIM3_InitStructure);
		
	TIM_ITConfig (TIM3, TIM_IT_Update, ENABLE);
	
	NVIC_InitTypeDef NVIC_TIM3_InitStructure;
	
	NVIC_TIM3_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
	NVIC_TIM3_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_TIM3_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_TIM3_InitStructure.NVIC_IRQChannelCmd = ENABLE ;
	NVIC_Init(&NVIC_TIM3_InitStructure);
	
	TIM_Cmd (TIM3,ENABLE);
}

unsigned int Timer_GetCounter(void){
	return TIM_GetCounter(TIM2);
}

unsigned int TIM3_GetCounter(void){
	return TIM_GetCounter(TIM3);
}

/*
void TIM2_IRQHandler(void){
	if(TIM_GetITStatus(TIM2, TIM_IT_Update) == SET){
		
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	}
}
*/

/*
void TIM3_IRQHandler(void){
	if(TIM_GetITStatus(TIM3, TIM_IT_Update) == SET){
		
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
	}
}
*/
