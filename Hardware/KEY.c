#include "stm32f10x.h"                  // Device header
#include "Delay.h"
void KEY_Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15 | GPIO_Pin_13 |GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
}
uint8_t Key_GetNum()
{
	uint8_t KeyNum= 0;
	if (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_15) == 1)
	{
		KeyNum = 1;
	}
	else if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13) == 1){
		KeyNum = 2;
	}
	else if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12) == 1){
		KeyNum = 3;
	}
		return KeyNum;
}
