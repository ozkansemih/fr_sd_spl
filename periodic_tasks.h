
#ifndef  __PERIODIC_FUNCS_
#define __PERIODIC_FUNCS_

#include "FreeRTOS.h"                  // Device header

#include "FreeRTOSConfig.h"
#include "task.h"
#include "timers.h"
#include "stm32f10x_gpio.h"             // Keil::Device:StdPeriph Drivers:GPIO

#include "usart_funcs.h"

void toggle_13 ( TimerHandle_t tim );
void send1_perio ( TimerHandle_t tim );

#endif
