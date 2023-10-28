#include "stm32f10x_rcc.h"
#include "stm32f10x_tim.h"
#include "delay.h"

void TIM2_INT_Init(void)
{	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
  
	/* 
	 * TIM2 initialization for overflow every 1ms
   * Update Event (Hz) = timer_clock / (TIM_Prescaler * Time_unit)
	 * Update Event (Hz) = 72MHz / (3600 * 1000) = 20Hz (1ms)
   */
	TIM_TimeBaseInitStruct.TIM_Prescaler = 3600;
	TIM_TimeBaseInitStruct.TIM_Period = 19;
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStruct);
	
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	TIM_Cmd(TIM2, ENABLE);
	
	NVIC_InitTypeDef NVIC_InitStruct;
	
	NVIC_InitStruct.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x00;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0x00;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStruct);
	
}

int milis = 0;

void TIM2_IRQHandler (void) {
	
	if (TIM_GetITStatus(TIM2, TIM_IT_Update)) {
		milis++;
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	}
}

void delayMs (int delayMilis) {
	milis = 0;
  while(milis < delayMilis);
}
