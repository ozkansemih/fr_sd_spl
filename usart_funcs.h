#ifndef __USART_FUNCS_H_
#define __USART_FUNCS_H_

#include "stm32f10x.h"                  // Device header
#include "stm32f10x_usart.h"            // Keil::Device:StdPeriph Drivers:USART
#include "stdlib.h"

#include "usart_funcs.h"

	void usart1_puts ( char * s );
	void usart1_puts_w_len ( char * s , size_t len );

	void usart2_puts ( char * s );
	void usart2_puts_w_len ( char * s , size_t len );


#endif
