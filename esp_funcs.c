


#include "string.h"
#include "stdio.h"

#include "esp_funcs.h"
#include "usart_funcs.h"
#include "prio_tasks.h"
#include "defines.h"



extern StatusCode espState ;
extern ResponseCode response;

char ssid[32] = WiFi_ID;
char password[32] = WiFi_PASS;

void esp_connect_to_network( void ){


	#if ! USE_SD_INFO
		espState = CONNECTING_NETWORK;
		
		send_to_esp(&huart1, ATC_CONNECT_TO_NETWORK, strlen(ATC_CONNECT_TO_NETWORK), CONNECT_NETWORK_TIMEOUT);
	#else
		char command[100];
		sprintf(command, ATC_CONNECT_TO_NETWORK, ssid, password);
		espState = CONNECTING_NETWORK;
		usart1_puts( command );
	#endif

}

void disable_esp_echo( void ){

		usart1_puts ( "ATE0\0" );

}