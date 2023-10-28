#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"

#define SCK 	GPIO_Pin_6
#define MOSI 	GPIO_Pin_7
#define SS 		GPIO_Pin_8
#define PORT	GPIOB

uint8_t dataReceive[10] = {0};

void spi_Init(void);
uint8_t receiveData(void);
void receiveArray(uint8_t data[], int size);


int main()
	{	
		spi_Init();
		
		while(1){
			receiveArray(dataReceive,10);
		} 
		return 0;
	}

void spi_Init(void)
	{		
		GPIO_InitTypeDef	gpio_Spi;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		
		gpio_Spi.GPIO_Pin 		= 	SCK|MOSI;
		gpio_Spi.GPIO_Mode 		=		GPIO_Mode_IPD;
		gpio_Spi.GPIO_Speed 	= 	GPIO_Speed_2MHz;
		GPIO_Init(PORT, &gpio_Spi);
		
		gpio_Spi.GPIO_Pin 		= 	SS;
		gpio_Spi.GPIO_Mode 		=		GPIO_Mode_IPU;
		gpio_Spi.GPIO_Speed 	= 	GPIO_Speed_2MHz;
		GPIO_Init(PORT, &gpio_Spi);
	}

void receiveArray(uint8_t data[], int size){
	int i;
	for(i = 0; i < size; i++)
	{
		data[i] = receiveData();
	}
}	
	
uint8_t receiveData(void)
	{
		uint8_t dataIn = 0;
  	uint8_t i;
		while(GPIO_ReadInputDataBit(PORT, SS) == 1){};
		for(i = 0; i < 8; i++)
			{
				while(GPIO_ReadInputDataBit(PORT, SCK) == 0){}
				if(GPIO_ReadInputDataBit(PORT, MOSI)==1)	dataIn = dataIn | (0x80 >> i);
				while(GPIO_ReadInputDataBit(PORT, SCK) == 1){}
			}
		return dataIn;
	}


	
	

