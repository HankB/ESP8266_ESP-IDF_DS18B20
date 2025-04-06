#include "zh_ds18b20.h"

void app_main(void)
{
    esp_log_level_set("zh_onewire", ESP_LOG_NONE);
    esp_log_level_set("zh_ds18b20", ESP_LOG_NONE);
    uint8_t *rom = NULL;
    float temperature = 0.0;
    zh_onewire_init(GPIO_NUM_4);
    if (zh_onewire_reset() != ESP_OK)
    {
        printf("There are no 1-Wire devices available on the bus.\n");
    }
    else
    {
        zh_onewire_search_rom_init();
        for (;;)
        {
            rom = zh_onewire_search_rom_next();
            if (rom == NULL)
            {
                break;
            }
            printf("Found device ROM: ");
            for (uint8_t i = 0; i < 8; ++i)
            {
                printf("%X ", *(rom++));
            }
            printf("\n");
            rom -= 8;
            zh_ds18b20_read(rom, &temperature);
            printf("Temperature: %0.2f\n", temperature);
        }
    }
}