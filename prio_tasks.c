
#include "prio_tasks.h"

#include "esp_funcs.h"

SemaphoreHandle_t parseSem = NULL;


StatusCode espState  = SETUP;
ResponseCode response;
int isNetworkConnected;
int isServerConnected ;
int network_timout_cnt ;
int fail_network ;
int server_timout_cnt ;



void ParseIncomingData ( void * param ) {

	while ( 1 ) {
		xSemaphoreTake(parseSem, pdMS_TO_TICKS ( 10000 ) );
	//add_log_statistics(LOG_FILE, "ParseIncomingData", fail_network, fail_server, RESPONSE_CODES[response], espState_CODES[espState]);
	if ( espState == SETUP){
		isNetworkConnected = 0;
		isServerConnected = 0;
		espState = READY;
		disable_esp_echo();
	}
	else if(espState == READY){
		isNetworkConnected = 0;
		isServerConnected = 0;
		esp_connect_to_network();
	}
	else if(espState == CONNECTING_NETWORK){
		if(response == OK){
			network_timout_cnt =0;
			fail_network = 0;
			espState = CONNECTED_NETWORK;
		}
		else if(response == FAIL){
			isNetworkConnected =0; //
			espState = READY;
			fail_network++;
		}
	}else if(espState == CONNECTED_NETWORK){
		isNetworkConnected = 1;
//		send_to_esp_connect_to_server();
	}
	else if(espState == CONNECTING_SERVER){
		if(response == OK){
			server_timout_cnt = 0;
//			fail_server = 0;
			espState = CONNECTED_SERVER;
			isServerConnected = 1;
			server_timout_cnt=0;
//			encode_general_res_pkg(device_id, TIME_PACKAGE, 1, add_to_tx_buffer);

		}
		else if(response == FAIL){
			espState = READY;
			isServerConnected = 0;
//			fail_server++;
		}
	}
	else if(espState == CONNECTED_SERVER){
		if(response == OK){
			isServerConnected = 1;
		}
		else if(response == FAIL){
			espState = READY;
		}
	}
	else if(espState == TRANSFERRING_DATA){
		if(response == OK){
//			transferring_timout_cnt = 0;
//			ServerDataPtr server_data;
//			uint8_t res = 0;			
//			do{
//				DELAY(10);
//				res = get_tx_buf_ptr(&server_data);
//			}while(res == 0);			

//			if(res == 1){
//				espState = TRANSFERRED_DATA;
//				tx_counter++;					
//				send_to_esp(&huart1, server_data.data_arr, server_data.size, DEFAULT_NETWORK_TIMEOUT);					
//			}
		}
		else if(response == FAIL){
			espState = READY;
		}
	}else if(espState == TRANSFERRED_DATA){
		if(response == OK){
//			transferred_timout_cnt =0;
			espState = CONNECTED_SERVER;
		}
		else if(response == FAIL){
			espState = READY;
		}
	}
	else if(espState == FAILED){

	}

	//Cihazin RESET atmasini istedigimizde RESET_BOARD_ENABLE 1 yapilir
#if RESET_BOARD_ENABLE
	if((fail_network + 1) % RETRY_CONNECTION_RESET_BOARD == 0){
		ResetBoard();
	}else if ((fail_server + 1)% RETRY_CONNECTION_RESET_BOARD == 0){
		ResetBoard();
	}
#endif



	}


}
