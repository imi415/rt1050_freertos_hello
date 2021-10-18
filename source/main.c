#include <stdint.h>

#include "board.h"
#include "pin_mux.h"
#include "peripherals.h"

#include "user_tasks.h"

void start_tasks(void) {
    if(xTaskCreate(vTaskHelloWorld, "Hello Task", 256, NULL, 1, &xTaskHelloWorldHandle) != pdPASS) {
        goto dead_loop;
    }

    return;

dead_loop:
    for(;;) {
        //
    }
}

int main(void) {
    BOARD_BootClockRUN();
    BOARD_InitBootPins();
    BOARD_InitBootPeripherals();

    BOARD_ConfigMPU();

    start_tasks();

    vTaskStartScheduler();

    for(;;)  {
        //
    }

    return 0;
}