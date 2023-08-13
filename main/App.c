/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "user_configuration.h"

/*Pre-define*/
static inline void GetsetChipInfo();


void app_main()
{
	GetsetChipInfo();
	
    esp_restart();
}
static inline void GetsetChipInfo() 
{
	esp_chip_info_t chip_info;
	esp_chip_info(&chip_info);
	printf("This is ESP8266ex chip with %d CPU cores, WiFi, ",
		   chip_info.cores);
	printf("silicon revision %d, ", chip_info.revision);
	printf("%dMB %s flash\n", spi_flash_get_chip_size() / (1024 * 1024),
		   (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");
	//Get&set MAC address
	uint8_t mac[6];  //ESP_OK==0
	#ifdef USE_DEFAULT_EFUSE_MAC
	esp_efuse_mac_get_default(mac);
	#endif

	//printf("ESP MAC Address: ")
	fflush(stdout); //clear
}
