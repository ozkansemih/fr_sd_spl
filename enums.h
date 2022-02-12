#ifndef ENUMS_H
#define ENUMS_H

typedef enum sdCardCode{
MOUNT_SUCCESFUL = 0,
MOUNT_FAIL = 1,
OPEN_SUCCESFUL = 2,
OPEN_FAIL = 3,	
CLOSE_SUCCESFUL = 4,
CLOSE_FAIL = 5,
WRITE_SUCCESFUL = 6,
WRITE_FAIL = 7,
MOVE_OFFSET_SUCCES = 8,
MOVE_OFFSET_FAIL = 9,
UPDATE_SUCCES = 10,
UPDATE_FAIL = 11,
DELETE_SUCCES = 12,
DELETE_FAIL = 13 ,
UNMOUNT_SUCCESFUL ,
UNMOUNT_FAIL 
}sdCardCode;

typedef enum StatusCode
{
	READY = 0,
	CONNECTING_NETWORK = 1,
	CONNECTED_NETWORK = 2,
	CONNECTING_SERVER = 3,
	CONNECTED_SERVER = 4,
	TRANSFERRING_DATA = 5,
	TRANSFERRED_DATA = 6,
	WAITING_COMMAND = 7,
	COMPLETED = 8,
	TIMEOUT = 9,
	FAILED = 10,
	SETUP 
}StatusCode;

typedef enum ResponseCode{
	UNDEFINED = 0,
	OK = 1,
	FAIL = 2
}ResponseCode;

static const char *RESPONSE_CODES[] = { "UNDEFINED", "OK", "FAIL"};
static const char *STATE_CODES[] = { "READY", "CONNECTING_NETWORK", "CONNECTED_NETWORK", "CONNECTING_SERVER", "CONNECTED_SERVER", "TRANSFERRING_DATA", "TRANSFERRED_DATA", "WAITING_COMMAND", "COMPLETED", "TIMEOUT", "FAILED"};

typedef enum DeviceErrorCode{
	UNKNOWN_ERROR = 0,
	TIME_MODULE,
	SD_CARD_MODULE,
	HX_ERROR
}DeviceErrorCode;

typedef enum transfer_type{
	STOP = 0,
	START
} transfer_type;

typedef enum transfer_type_time{
	NOW = 0,
	LATER 
} transfer_type_time ;

typedef enum repeat_type{
	ONCE = 0,
	REPEAT
} repeat_type ;

#endif
