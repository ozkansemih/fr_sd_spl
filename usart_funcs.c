

#include "usart_funcs.h"

void usart1_puts ( char * s ){

	while ( *s ) {
		while ( !(USART1->SR &  0x00000040 ));
		USART_SendData ( USART1 , *s );
		s++;
	}
}

void usart1_puts_w_len ( char * s , size_t len ){

	int i=0;
	while ( i<len ) {
		while ( !(USART1->SR &  0x00000040 ));
		USART_SendData ( USART1 , *s );
		s++;
		i++;
	}
}

void usart2_puts ( char * s ) {

	while ( *s ) {
		while ( !( USART2->SR & 0x00000040 ));
		USART_SendData ( USART2 , *s );
		s++;
	}
}

void usart2_puts_w_len ( char * s ,size_t len ) {

	int i = 0;
	while ( i < len ) {
		while ( !( USART2->SR & 0x00000040 ));
		USART_SendData ( USART2 , *s );
		s++;
		i++;
	}
}


