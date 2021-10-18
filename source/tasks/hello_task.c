#include <stdint.h>

#include "fsl_common.h"
#include "fsl_gpio.h"

#include "board.h"
#include "pin_mux.h"
#include "peripherals.h"

#include "user_tasks.h"

TaskHandle_t xTaskHelloWorldHandle = NULL;
void vTaskHelloWorld(void *pvParameters) {
    for(;;) {
        GPIO_WritePinOutput(BOARD_INITPINS_LED0_GPIO, BOARD_INITPINS_LED0_GPIO_PIN, 1U);
        vTaskDelay(pdMS_TO_TICKS(500));
        GPIO_WritePinOutput(BOARD_INITPINS_LED0_GPIO, BOARD_INITPINS_LED0_GPIO_PIN, 0U);
        vTaskDelay(pdMS_TO_TICKS(500));
    }

    vTaskDelete(NULL);
}