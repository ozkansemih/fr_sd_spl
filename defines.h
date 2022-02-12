#ifndef __DEFINES_H_
#define __DEFINES_H_


#define USE_SD_INFO 1

#define WiFi_ID        "SUPERONLINE-WiFi_6394\0"
#define WiFi_PASS  "JCWJUV9N9PHL\0"


#define SEND_PERIOD_ 1
#define LED_PERIOD_ 1


#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#define END_OF_CH_1 '\r'
#define END_OF_CH_2 '\n'
#define RECEIVED_DATA_FROM_SERVER_TAG "+IPD"
#define SENSOR_CARD_DEVICE_ID_1 1 // uint8_t olmali
#define SENSOR_CARD_DEVICE_ID_2 2 // uint8_t olmali
#define SENSOR_CARD_DEVICE_ID_3 3 // uint8_t olmali
#define DATA_REQUEST_COMMAND_DEVICE_1 "DATA" STR(SENSOR_CARD_DEVICE_ID_1) "\r\n\0"
#define DATA_REQUEST_COMMAND_DEVICE_2 "DATA" STR(SENSOR_CARD_DEVICE_ID_2) "\r\n\0"
#define DATA_REQUEST_COMMAND_DEVICE_3 "DATA" STR(SENSOR_CARD_DEVICE_ID_3) "\r\n\0"



#define ATC_CONNECT_TO_NETWORK "AT+CWJAP_CUR=\"%s\",\"%s\"\r\n"








#define seSD_CS_PORT GPIOA
#define seSD_CS_PIN GPIO_Pin_4
#define seSDSPIx SPI1
#endif
