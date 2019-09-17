#include "driver.h"
#include "STM32F103Cx.h"

void
Robot_Start()
{
	GPIO_Set(GPIOA, EN1);
	GPIO_Set(GPIOA, EN2);
}

void
Robot_Forward()
{
	//WHEEL RIGHT CW
	GPIO_Set(GPIOA, IN11);
	GPIO_Clear(GPIOA, IN12);
	//WHEEL LEFT CCW
	GPIO_Clear(GPIOA, IN21);
	GPIO_Set(GPIOA, IN22);
}

void
Robot_Backward()
{
	//WHEEL RIGHT CCW
	GPIO_Clear(GPIOA, IN11);
	GPIO_Set(GPIOA, IN12);
	//WHEEL LEFT CW
	GPIO_Set(GPIOA, IN21);
	GPIO_Clear(GPIOA, IN22);
}

void
Robot_Right()
{
	//WHEEL RIGHT STOP
	GPIO_Clear(GPIOA, IN11);
	GPIO_Clear(GPIOA, IN12);
	//WHEEL LEFT CCW (FORWARD)
	GPIO_Set(GPIOA, IN22);
	GPIO_Clear(GPIOA, IN21);
}

void
Robot_Left()
{
	//WHEEL RIGHT CW (FORWARD)
	GPIO_Set(GPIOA, IN11);
	GPIO_Clear(GPIOA, IN12);
	//WHEEL LEFT STOP
	GPIO_Clear(GPIOA, IN21);
	GPIO_Clear(GPIOA, IN22);
}
