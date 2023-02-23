#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "hl_nvs.h"
#include "hl_ble.h"

// #include "zlog_demo.h"
// #include "ux_demo.h"

TaskHandle_t g_task1_handle;

static void task1_handle(void *arg)
{
    hl_nvs_init();
    hl_ble_init();

    // zlog_demo_init();
    // ux_demo_init();

    while (1) {
        vTaskDelay(pdMS_TO_TICKS(5000));
        // printf("this is task1\r\n");
    }
    
}

void app_main(void)
{
    xTaskCreatePinnedToCore(task1_handle, "task1_handle", 4096, NULL, 3, &g_task1_handle, tskNO_AFFINITY);
}