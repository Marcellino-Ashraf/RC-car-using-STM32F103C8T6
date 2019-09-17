typedef unsigned long int uint_32;

#define GPIO_PIN0				0
#define GPIO_PIN1				1
#define GPIO_PIN2				2
#define GPIO_PIN3				3
#define GPIO_PIN4				4
#define GPIO_PIN5				5
#define GPIO_PIN6				6
#define GPIO_PIN7				7
#define GPIO_PIN8				8
#define GPIO_PIN9				9
#define GPIO_PIN10			10
#define GPIO_PIN11			11
#define GPIO_PIN12			12
#define GPIO_PIN13			13
#define GPIO_PIN14			14
#define GPIO_PIN15			15

#define GPIO_PIN0_OUT			(3<<GPIO_PIN0)
#define GPIO_PIN1_OUT			(3<<GPIO_PIN1)
#define GPIO_PIN2_OUT			(3<<GPIO_PIN2)
#define GPIO_PIN3_OUT			(3<<GPIO_PIN3)
#define GPIO_PIN4_OUT			(3<<GPIO_PIN4)
#define GPIO_PIN5_OUT			(3<<GPIO_PIN5)
#define GPIO_PIN6_OUT			(3<<GPIO_PIN6)
#define GPIO_PIN7_OUT			(3<<GPIO_PIN7)
#define GPIO_PIN8_OUT			(3<<GPIO_PIN8)
#define GPIO_PIN9_OUT			(3<<GPIO_PIN9)
#define GPIO_PIN10_OUT		(3<<GPIO_PIN10)
#define GPIO_PIN11_OUT		(3<<GPIO_PIN11)
#define GPIO_PIN12_OUT		(3<<GPIO_PIN12)
#define GPIO_PIN13_OUT		(3<<GPIO_PIN13)
#define GPIO_PIN14_OUT		(3<<GPIO_PIN14)
#define GPIO_PIN15_OUT		(3<<GPIO_PIN15)

#define GPIO_PIN0_IN			(4<<GPIO_PIN0)
#define GPIO_PIN1_IN			(4<<GPIO_PIN1)
#define GPIO_PIN2_IN			(4<<GPIO_PIN2)
#define GPIO_PIN3_IN			(4<<GPIO_PIN3)
#define GPIO_PIN4_IN			(4<<GPIO_PIN4)
#define GPIO_PIN5_IN			(4<<GPIO_PIN5)
#define GPIO_PIN6_IN			(4<<GPIO_PIN6)
#define GPIO_PIN7_IN			(4<<GPIO_PIN7)
#define GPIO_PIN8_IN			(4<<GPIO_PIN8)
#define GPIO_PIN9_IN			(4<<GPIO_PIN9)
#define GPIO_PIN10_IN			(4<<GPIO_PIN10)
#define GPIO_PIN11_IN			(4<<GPIO_PIN11)
#define GPIO_PIN12_IN			(4<<GPIO_PIN12)
#define GPIO_PIN13_IN			(4<<GPIO_PIN13)
#define GPIO_PIN14_IN			(4<<GPIO_PIN14)
#define GPIO_PIN15_IN			(4<<GPIO_PIN15)

typedef struct
{
	uint_32 CRL;
	uint_32 CRH;
	uint_32 IDR;
	uint_32 ODR;
	uint_32 BSRR;
	uint_32 BRR;
	uint_32 LCKR;
}GPIO_TYPEDEF;

#define APB2_BASE			0x40010000
#define GPIOA_BASE		(APB2_BASE + 0x0800)
#define GPIOB_BASE		(APB2_BASE + 0x0C00)
#define GPIOC_BASE		(APB2_BASE + 0x1000)
#define GPIOD_BASE		(APB2_BASE + 0x1400)
#define GPIOE_BASE		(APB2_BASE + 0x1800)
#define GPIOF_BASE		(APB2_BASE + 0x1C00)
#define GPIOG_BASE		(APB2_BASE + 0x2000)

#define GPIOA					((GPIO_TYPEDEF *)GPIOA_BASE)
#define GPIOB					((GPIO_TYPEDEF *)GPIOB_BASE)
#define GPIOC					((GPIO_TYPEDEF *)GPIOC_BASE)
#define GPIOD					((GPIO_TYPEDEF *)GPIOD_BASE)
#define GPIOE					((GPIO_TYPEDEF *)GPIOE_BASE)
#define GPIOF					((GPIO_TYPEDEF *)GPIOF_BASE)
#define GPIOG					((GPIO_TYPEDEF *)GPIOG_BASE)

typedef struct
{
	uint_32 CR;
	uint_32 CFGR;
	uint_32 CIR;
	uint_32 APB2RSTR;
	uint_32 APB1RSTR;
	uint_32 AHBENR;
	uint_32 APB2ENR;
	uint_32 APB1ENR;
	uint_32 BDCR;
	uint_32 CSR;
}RCC_TYPEDEF;

#define RCC_BASE 		  0x40021000

#define RCC						((RCC_TYPEDEF *)RCC_BASE)

typedef struct
{
	uint_32 SR;
	uint_32 DR;
	uint_32 BRR;
	uint_32 CR1;
	uint_32 CR2;
	uint_32 CR3;
	uint_32 GTPR;	
}USART_TYPEDEF;

#define USART1_BASE		0x40013800

#define USART1				((USART_TYPEDEF *)USART1_BASE)

char portInit (GPIO_TYPEDEF * GPIO);
void portOut (GPIO_TYPEDEF * GPIO, long value);
void pinOut (GPIO_TYPEDEF * GPIO, unsigned char pinValue);
void GPIO_Set (GPIO_TYPEDEF * GPIO, unsigned char pinNumber);
void GPIO_Clear (GPIO_TYPEDEF * GPIO, unsigned char pinNumber);
void USART1_Init();
