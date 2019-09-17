#include "STM32F103Cx.h"
#include "driver.h"

void SystemInit(){};

int main()
{
	//Setup
	//portInit(GPIOB);
	USART1_Init();
	GPIOA->CRH = 0x33333433;
	GPIOA->CRL = 0x33333333;
//	
//	GPIOB->CRH = 0x33333333;
//	GPIOB->CRL = 0x33333333;
//	
//	GPIOC->CRH = 0x33333333;
//	GPIOC->CRL = 0x33333333;
	
	//GPIOA->ODR = 
	Robot_Start();
	
	//Loop
	while (1)
	{
//		Robot_Forward();
//		Robot_Backward();
//		Robot_Right();
//		Robot_Left();
//		GPIOA->ODR = 0;
//		USART1->DR = 0;
		if (USART1->DR == 'F')
		{
			Robot_Forward();
			USART1->DR = 0;
		}
		else if (USART1->DR == 'B')
		{
			Robot_Backward();
			USART1->DR = 0;
		}
		else if (USART1->DR == 'R')
		{
			Robot_Right();
			USART1->DR = 0;
		}
		else if (USART1->DR == 'L')
		{
			Robot_Left();
			USART1->DR = 0;
		}
	}
}
