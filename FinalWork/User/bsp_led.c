#include "bsp_led.h"

__IO int fadeRate = 4000;             // breath light fadeRate

void LED_Configuration()
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void LED_On()
{
	GPIO_WriteBit(GPIOA, GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4, Bit_SET);
}

void LED_Off()
{
	GPIO_WriteBit(GPIOA, GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4, Bit_RESET);
}

// �����ʱ
void Delay(__IO uint32_t nCount)
{
  while(nCount--);
} 

int constrain(int num, int min, int max)
{
	if (num < min)
		return min;
	else if (num > max)
		return max;
	else
		return num;
}

/* ͨ���ߵ͵�ƽ�ı仯ʵ��ռ�ձȸı䣬�ﵽ�ı�ƽ�����������ã�ÿ�μ���ı�һ�� */
void fadeLED(int fadeRate)
{
	LED_On();
	Delay(fadeRate);
	LED_Off();
	Delay(4000 - fadeRate);
}

void ledFadeToBeat()
{
    fadeRate -= 25;                         //  set onetime LED fade value
    fadeRate = constrain(fadeRate,0,4000);  //  keep LED fade value from going into negative numbers!
    fadeLED(fadeRate);                      //  fade LED
}
