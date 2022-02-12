
#include "main.h"
#include "fatfs.h"
#include "fatfs_sd.h"

FATFS fs;
FIL fil;
FILINFO fno;
FRESULT fresult;
UINT br, bw;

FATFS *pfs;
DWORD fre_clust;
uint32_t total, free_space;


uint8_t read_semih [ 32 ];
unsigned int bytess;

char send_to_sd[ 20] = "rtos t ohello sd";
unsigned int read_byte;

int is_mount ;
extern StatusCode espState ;
extern ResponseCode response;

extern SemaphoreHandle_t parseSem ;
int main(){
	SystemInit();
	SystemCoreClockUpdate ();
	SysTick_Config(SystemCoreClock / 1000);
	parseSem =xSemaphoreCreateBinary();

	C13_init();
	usart1_init();
	usart2_init();
	init_spi1_for_sd();
	
	init_tim6();
	
	GPIO_ResetBits ( GPIOC , GPIO_Pin_13 );
	TimerHandle_t tim_C13;
	TimerHandle_t tim_usart1;
	TimerHandle_t tim_sd;
	TimerHandle_t timer_writesd;
	TimerHandle_t timer_readsd;
	tim_C13 = xTimerCreate ( "time13",   pdMS_TO_TICKS ( LED_PERIOD_ * 1000 ) , pdTRUE , NULL , toggle_13 );
	tim_usart1 = xTimerCreate ( "usart1", pdMS_TO_TICKS ( SEND_PERIOD_ * 1000 ) , pdTRUE , NULL , send1_perio );
	tim_sd = xTimerCreate ( "sd" , pdMS_TO_TICKS ( 200 ) , pdFALSE , NULL , init_sd );
	timer_writesd = xTimerCreate ( "write_sd" , pdMS_TO_TICKS ( 150000 ) , pdTRUE , NULL , write_sd );
	timer_readsd = xTimerCreate ( "read_sd ", pdMS_TO_TICKS ( 2000 ) , pdTRUE , NULL , read_sd );
	
	
	xTaskCreate ( ParseIncomingData , "parse", 120, NULL , 1, NULL );
	
	
	xTimerStart ( tim_C13 , 0 );
	xTimerStart ( tim_usart1 , 0 );
	xTimerStart ( tim_sd , 0 );
	xTimerStart ( timer_writesd , 0 );
	xTimerStart ( timer_readsd , 0 );
	xSemaphoreGive( parseSem );
	
	vTaskStartScheduler ();
	
	while ( 1 ) {
	
	
	}
	
	

}

void read_sd ( TimerHandle_t tim ) {
	fresult = f_open(&fil,"semih1031.txt",FA_OPEN_ALWAYS | FA_READ | FA_WRITE );

	fresult = f_lseek(&fil, f_size( &fil ) - 16 );

	fresult = f_read(&fil, read_semih, 10, &read_byte);
	fresult = f_close(&fil);

}

void write_sd ( TimerHandle_t tim ){
	fresult = f_open(&fil,"semih1031.txt",FA_OPEN_ALWAYS | FA_READ | FA_WRITE );

		fresult = f_lseek(&fil, f_size( &fil ) );
	if (fresult == FR_OK)
		fresult = f_write(&fil, "timer wrote this\0", 16, &bytess);
		fresult = f_close(&fil);

}

void init_sd ( TimerHandle_t tim ){

	FATFS_Init();
	fresult = f_mount( &fs, "", 1 );

	if ( fresult == FR_OK ) 
		is_mount = 1;
		
	vTaskDelay ( pdMS_TO_TICKS ( 1000 ) );
	fresult = f_open(&fil,"semih1031.txt",FA_OPEN_ALWAYS | FA_READ | FA_WRITE );
	
		fresult = f_lseek(&fil, f_size( &fil ) );
	if (fresult == FR_OK)
		fresult = f_write(&fil, "timer wrote this\0", 16, &bytess);
	
	fresult = f_lseek(&fil, f_size( &fil ) - 20 );

	fresult = f_read(&fil, read_semih, 16, &read_byte);
	fresult = f_close(&fil);
}

void HardFault_Handler(){
	__nop();


}


void TIM3_IRQHandler( ) {


if ( TIM_GetITStatus(TIM3,TIM_IT_Update ) != RESET){
	TIM_ClearITPendingBit( TIM3, TIM_IT_Update );
	GPIO_SetBits ( GPIOC , GPIO_Pin_13 );
	

}

}


