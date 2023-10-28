#include "stm32f10x.h"
#include "stm32f10x_rcc.h"

#define SCK 	GPIO_Pin_6
#define MOSI 	GPIO_Pin_7
#define SS 		GPIO_Pin_8
#define PORT	GPIOB

void spi_Init(void);
void transmitData(uint8_t dataTrans);
void clock(void);

int main()
	{	
		
		uint8_t data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		int i,j = 0;
		for(i = 0; i < 10000000; i++);
		
		spi_Init();
		
		while(1)
		{
			transmitData(data[j]);
			j++;			
		}
	}

void spi_Init(void)
	{
		
		GPIO_InitTypeDef	gpio_Spi;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		
		gpio_Spi.GPIO_Pin 		= 	SCK|MOSI|SS;
		gpio_Spi.GPIO_Mode 		=		GPIO_Mode_Out_PP;
		gpio_Spi.GPIO_Speed 	= 	GPIO_Speed_2MHz;
		GPIO_Init(PORT, &gpio_Spi);
		
		GPIO_ResetBits(PORT, SCK);
		GPIO_ResetBits(PORT, MOSI);
		GPIO_SetBits(PORT, SS);
		
		
	}

void transmitData(uint8_t dataTrans)
	{
		uint8_t i;
		GPIO_ResetBits(PORT, SS);
		for(i = 0; i < 8; i++)
			{
				if((dataTrans & (0x80 >> i)) == 0)	GPIO_ResetBits(PORT, MOSI);
				else	GPIO_SetBits(PORT, MOSI);
				clock();
			}		
		GPIO_SetBits(PORT, SS);
	}

	
void clock(void)
	{
		uint16_t i;
		GPIO_SetBits(PORT, SCK);
		for(i = 0; i < 10000; i++);
		GPIO_ResetBits(PORT, SCK);
		for(i = 0; i < 10000; i++);
	}
	

