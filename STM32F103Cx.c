#include "STM32F103Cx.h"

char
portInit
(GPIO_TYPEDEF * GPIO)
{
	char check = 0;
	if (GPIO == GPIOA)
		RCC->APB2ENR |= (1<<2);
	else
		if (GPIO == GPIOB)
			RCC->APB2ENR |= (1<<3);
		else
			if (GPIO == GPIOC)
				RCC->APB2ENR |= (1<<4);
			else
				if (GPIO == GPIOD)
					RCC->APB2ENR |= (1<<5);
				else
					if (GPIO == GPIOE)
						RCC->APB2ENR |= (1<<6);
					else
						if (GPIO == GPIOF)
							RCC->APB2ENR |= (1<<7);
						else
							if (GPIO == GPIOG)
								RCC->APB2ENR |= (1<<8);
	check = 1;
	if (check == 1)
		return 1;
	else
		return 0;
}

void
portOut
(GPIO_TYPEDEF * GPIO,
long int value)
{
	GPIO->ODR |= value;
}

void
pinOut
(GPIO_TYPEDEF * GPIO,
 unsigned char pinValue)
{
	GPIO->ODR |= pinValue;
}	 

void
GPIO_Set
(GPIO_TYPEDEF * GPIO,
 unsigned char pinNumber)
{
	GPIO->ODR |= (1<<pinNumber);
}	 

void
GPIO_Clear
(GPIO_TYPEDEF * GPIO,
 unsigned char pinNumber)
{
	GPIO->ODR &= ~(1<<pinNumber);
}	

void
USART1_Init
()
{
	RCC->APB2ENR =  (1<<14)|(1<<2)|(1<<0);						//Enable CLK to USART1 (1<<14), GPIOA (1<<2) and AFIO (1<<0)
//	USART1->CR1 = 0;
//	USART1->CR2 = 0;
//	USART1->CR3 = 0;
	USART1->CR1  |=  (1<<13);													//Enable  the USART by writing  the UE bit in USART_CR1 register to 1.
	USART1->CR1  &= ~(1<<12);													//Program the M bit in USART_CR1 to define the word length. (8 BITS)
	USART1->CR2  &= ~(3<<12);													//Program the number of stop bits in USART_CR2. (1 STOP)
	USART1->CR3  &= ~(1<<7);													//Select DMA enable (DMAT) in USART_CR3 if Multi buffer Communication is to take place. Configure the DMA register as explained in multibuffer communication.
	USART1->BRR   =   8000000/9600;									//Select the desired baud rate using the USART_BRR register.
	USART1->CR1  |=  (1<<3)|(1<<2);										//Set the TE bit in USART_CR1 to send an idle frame as first transmission.
	//After writing the last data into the USART_DR register, wait until TC=1.
	//This indicates that the transmission of the last frame is complete. This is required for instance when the USART is disabled or enters the Halt mode to avoid corrupting the last transmission.
	
	GPIOA->CRH |= (0xB<<4);			//PA9 as alternate function output push-pull
	GPIOA->CRH |= (4<<8);				//PA10 as floating input
}
