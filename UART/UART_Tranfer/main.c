#include "delay.h"

#define TX		GPIO_Pin_9
#define PORT	GPIOB

void configTx(void);
void startCondition(void);
void stopCondition(void);
void transmitData(uint8_t data);
void transmitArr(uint8_t *arr, uint8_t size);
uint8_t arr[10]={0,1,2,3,4,5,6,7,8,9};


int main(){
	
	TIM2_INT_Init();
	configTx();
	
	
//	delayMs(500);
	
	transmitArr(arr, 10);
	

	
}

void transmitArr(uint8_t *arr, uint8_t size)
{
	for(uint8_t i = 0; i < size; i++)
	{
		transmitData(arr[i]);
	}
}

void configTx(void){
	GPIO_InitTypeDef txPin;
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE);
	
	txPin.GPIO_Mode		= GPIO_Mode_Out_PP;
	txPin.GPIO_Pin		= TX;
	txPin.GPIO_Speed	= GPIO_Speed_2MHz;
	
	GPIO_Init(PORT, &txPin);
	GPIO_SetBits(PORT, TX);
}

void startCondition(void){
	GPIO_ResetBits(PORT, TX);
	delayMs(10);
}

void stopCondition(void){
	GPIO_SetBits(PORT, TX);
	delayMs(20);
}

void transmitData(uint8_t data){
	uint8_t count = 0;
	
	startCondition();
	
	for(uint8_t i = 0; i < 8; i++){
		if(data & (0x80>>i)){
			GPIO_SetBits(PORT, TX);
			count++;
		}
		else GPIO_ResetBits(PORT, TX);
		delayMs(10);
	}
	
	if(count%2 != 0)	GPIO_SetBits(PORT, TX);
	else							GPIO_ResetBits(PORT, TX);
	delayMs(10);
	
	stopCondition();
}
