#include "delay.h"

#define RX		GPIO_Pin_9
#define PORT	GPIOB

void configRx(void);
void waitStart(void);
void waitStop(void);
uint8_t receiveData(void);
void receiveArr(uint8_t *arr, uint8_t size);
uint8_t arr[10];

int main(){
	
	TIM2_INT_Init();
	configRx();
	
	while(1){
		receiveArr(arr, 10);
//		data = receiveData();
	}
	
}

void configRx(void){
	GPIO_InitTypeDef rxPin;
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE);
	
	rxPin.GPIO_Mode		= GPIO_Mode_IPU;
	rxPin.GPIO_Pin		= RX;
	rxPin.GPIO_Speed	= GPIO_Speed_2MHz;
	
	GPIO_Init(PORT, &rxPin);
}

void waitStart(void){
	while(GPIO_ReadInputDataBit(PORT, RX) == 1);
		delayMs(15);
}

void waitStop(void){
	while(GPIO_ReadInputDataBit(PORT, RX) == 0);
		delayMs(15);
}

uint8_t receiveData(void){
	uint8_t count = 0;
	uint16_t data = 0;
	
	waitStart();
	
	for(uint8_t i = 0; i < 9; i++){
		if(GPIO_ReadInputDataBit(PORT, RX) == 1){
			data = data | ((0x100)>>i);
			count++;
		}
		delayMs(10);
	}
	
	waitStop();
	
	if(count%2 != 0)	data = 0x06;
	data = data >> 1;
	
	return data;
}

void receiveArr(uint8_t *arr, uint8_t size)
{
	for(uint8_t i=0;i<size; i++) arr[i]= receiveData();
}

