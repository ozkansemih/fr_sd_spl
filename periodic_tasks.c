
#include "periodic_tasks.h"
#include "defines.h"


void toggle_13 ( TimerHandle_t tim ){

//GPIO_SetBits ( GPIOC , GPIO_Pin_13 );
GPIOC->ODR ^= 0x2000;

}

void send1_perio ( TimerHandle_t tim ){

	usart1_puts ( DATA_REQUEST_COMMAND_DEVICE_1 );
	vTaskDelay ( pdMS_TO_TICKS ( 100 ));
	usart1_puts ( DATA_REQUEST_COMMAND_DEVICE_2 );	
	vTaskDelay ( pdMS_TO_TICKS ( 100 ));
	usart1_puts ( DATA_REQUEST_COMMAND_DEVICE_3 );

}
