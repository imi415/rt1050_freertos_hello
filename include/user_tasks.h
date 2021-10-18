#ifndef USER_TASKS_H
#define USER_TASKS_H

#include "FreeRTOS.h"
#include "task.h"

extern TaskHandle_t xTaskHelloWorldHandle;
void vTaskHelloWorld(void *pvParameters);

#endif