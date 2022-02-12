

#include "initializes.h"



void C13_init(){

	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC , ENABLE );
	GPIO_InitTypeDef gp;
	gp.GPIO_Mode = GPIO_Mode_Out_PP;
	gp.GPIO_Pin = GPIO_Pin_13;
	gp.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init( GPIOC , &gp );
}

void usart1_init( void ) {

	RCC_APB2PeriphClockCmd ( RCC_APB2Periph_USART1 , ENABLE );
	RCC_APB2PeriphClockCmd ( RCC_APB2Periph_GPIOA , ENABLE );
	
	GPIO_InitTypeDef gp ;
	gp.GPIO_Mode = GPIO_Mode_AF_PP ;
	gp.GPIO_Pin = GPIO_Pin_2 ;
	gp.GPIO_Speed = GPIO_Speed_50MHz ;
	GPIO_Init ( GPIOA , & gp ) ;
	
	gp.GPIO_Mode = GPIO_Mode_IN_FLOATING ;
	gp.GPIO_Pin = GPIO_Pin_3 ;
	gp.GPIO_Speed = GPIO_Speed_50MHz ;
	GPIO_Init ( GPIOA , &gp );
	
	USART_InitTypeDef usar;
	usar.USART_BaudRate = 115200;
	usar.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	usar.USART_Mode = USART_Mode_Rx | USART_Mode_Tx ;
	usar.USART_Parity = USART_Parity_No ;
	usar.USART_StopBits = USART_StopBits_1 ;
	usar.USART_WordLength = USART_WordLength_8b ;
	USART_Init ( USART1 , & usar );
	USART_Cmd ( USART1 , ENABLE );
	USART_ITConfig( USART1 , USART_IT_RXNE , ENABLE );
	
	NVIC_InitTypeDef nvi;
	nvi.NVIC_IRQChannel = USART1_IRQn;
	nvi.NVIC_IRQChannelSubPriority = 0;
	nvi.NVIC_IRQChannelPreemptionPriority = 0;
	nvi.NVIC_IRQChannelCmd = ENABLE ;
	NVIC_Init ( &nvi );

}
void usart2_init( void ) {

	RCC_APB1PeriphClockCmd ( RCC_APB1Periph_USART2 , ENABLE );
	RCC_APB2PeriphClockCmd ( RCC_APB2Periph_GPIOA , ENABLE );

	GPIO_InitTypeDef gp ;
	gp.GPIO_Mode = GPIO_Mode_AF_PP ;
	gp.GPIO_Pin = GPIO_Pin_9 ;
	gp.GPIO_Speed = GPIO_Speed_50MHz ;
	GPIO_Init ( GPIOA , &gp );
	
	gp.GPIO_Mode = GPIO_Mode_IN_FLOATING ;
	gp.GPIO_Pin = GPIO_Pin_10 ;
	gp.GPIO_Speed = GPIO_Speed_50MHz ;
	GPIO_Init ( GPIOA , & gp );
	
	USART_InitTypeDef usar;
	usar.USART_BaudRate = 115200;
	usar.USART_HardwareFlowControl = USART_HardwareFlowControl_None ;
	usar.USART_Mode = USART_Mode_Rx | USART_Mode_Tx ;
	usar.USART_Parity = USART_Parity_No ;
	usar.USART_StopBits = USART_StopBits_1 ;
	usar.USART_WordLength = USART_WordLength_8b ;
	USART_Init ( USART2 , &usar );
	USART_Cmd ( USART2 , ENABLE );
	USART_ITConfig ( USART2 , USART_IT_RXNE , ENABLE );
	
	NVIC_InitTypeDef nvi ;
	nvi.NVIC_IRQChannel = USART2_IRQn ;
	nvi.NVIC_IRQChannelSubPriority = 0;
	nvi.NVIC_IRQChannelPreemptionPriority = 0;
	nvi.NVIC_IRQChannelCmd = ENABLE ;
	NVIC_Init ( & nvi );
	
}

void init_spi1_for_sd ( ){

	RCC_APB2PeriphClockCmd ( RCC_APB2Periph_SPI1 , ENABLE );
	RCC_APB2PeriphClockCmd ( RCC_APB2Periph_GPIOA , ENABLE );
	
	GPIO_InitTypeDef gp;
	gp.GPIO_Mode = GPIO_Mode_AF_PP ;
	gp.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 ; 
	gp.GPIO_Speed = GPIO_Speed_50MHz ;
	GPIO_Init ( GPIOA , &gp );
	
	gp.GPIO_Mode = GPIO_Mode_Out_PP ;
	gp.GPIO_Pin = GPIO_Pin_4 ;
	gp.GPIO_Speed = GPIO_Speed_50MHz ;
	GPIO_Init ( GPIOA , &gp );
	
	SPI_InitTypeDef sp;
	sp.SPI_BaudRatePrescaler = 8 ;
	sp.SPI_CPHA = SPI_CPHA_1Edge ;
	sp.SPI_CPOL = SPI_CPOL_Low ;
	sp.SPI_CRCPolynomial = 10;
	sp.SPI_DataSize = SPI_DataSize_8b ;
	sp.SPI_Direction = SPI_Direction_2Lines_FullDuplex ;
	sp.SPI_FirstBit = SPI_FirstBit_MSB ;
	sp.SPI_Mode = SPI_Mode_Master ;
	sp.SPI_NSS = SPI_NSS_Soft ;
	SPI_Init ( SPI1 , &sp );
	SPI_Cmd ( SPI1 , ENABLE );

	GPIO_SetBits ( GPIOA ,GPIO_Pin_4 );

}

void init_tim6 ( void ) {

TIM_TimeBaseInitTypeDef tim;
tim.TIM_ClockDivision = TIM_CKD_DIV1;
tim.TIM_CounterMode = TIM_CounterMode_Up ;
tim.TIM_Period = 2000;
tim.TIM_Prescaler = 36000;
tim.TIM_RepetitionCounter = 0;
TIM_TimeBaseInit( TIM3 , &tim );
TIM_Cmd( TIM3 , ENABLE );
TIM_ITConfig( TIM3 , TIM_IT_Update , ENABLE );

NVIC_InitTypeDef nvi;
nvi.NVIC_IRQChannel = TIM3_IRQn;
nvi.NVIC_IRQChannelSubPriority =0;
nvi.NVIC_IRQChannelPreemptionPriority = 0 ;
nvi.NVIC_IRQChannel = ENABLE ;
NVIC_Init( &nvi );

}
