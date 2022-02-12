#include "stm32f10x.h"                  // Device header
#include "stm32f10x_rcc.h"              // Keil::Device:StdPeriph Drivers:RCC
#include "stm32f10x_gpio.h"             // Keil::Device:StdPeriph Drivers:GPIO
#include "stm32f10x_spi.h"              // Keil::Device:StdPeriph Drivers:SPI
#include "stm32f10x_usart.h"            // Keil::Device:StdPeriph Drivers:USART
#include "stm32f10x_exti.h"             // Keil::Device:StdPeriph Drivers:EXTI
#include "stm32f10x_adc.h"              // Keil::Device:StdPeriph Drivers:ADC
#include "stm32f10x_rtc.h"              // Keil::Device:StdPeriph Drivers:RTC
#include "misc.h"                       // Keil::Device:StdPeriph Drivers:Framework
#include "stm32f10x_tim.h"              // Keil::Device:StdPeriph Drivers:TIM


void C13_init( void );

void usart1_init( void ) ;
void usart2_init( void ) ;
void init_spi1_for_sd ( void );

void init_tim6 ( void ) ;
