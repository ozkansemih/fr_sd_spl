

#ifndef __PRIO_TASKS_
#define __PRIO_TASKS_

#include "enums.h"

#include "FreeRTOS.h"                  // Device header

#include "FreeRTOSConfig.h"
#include "task.h"
#include "timers.h"
#include "semphr.h"
#include "queue.h"

void ParseIncomingData ( void * param );

#endif
