/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "user_configuration.h"

/*Pre-define*/
static inline void GetsetChipInfo();
static inline void DeviceHardwareInit();

void app_main()
{
	GetsetChipInfo();
	
    esp_restart();
}
inline void GetsetChipInfo() 
{
	esp_chip_info_t chip_info;
	esp_chip_info(&chip_info);
	printf("This is ESP8266ex chip with %d CPU cores, WiFi, ",
		   chip_info.cores);
	printf("silicon revision %d, ", chip_info.revision);
	printf("%dMB %s flash\n", spi_flash_get_chip_size() / (1024 * 1024),
		   (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");
	//Get&set MAC address
	
	#ifdef USE_DEFAULT_EFUSE_MAC
	uint8_t mac[6];
	esp_efuse_mac_get_default(mac);
	//read mac add
	#else
	esp_base_mac_addr_set(USER_MAC_ADDR);
	#endif
	
	fflush(stdout); //clear
}


inline void DeviceHardwareInit()
{
	//Init device GPIO
	gpio_config_t gpiosetup =
		{
			0x00002820,
			GPIO_MODE_DEF_OUTPUT,
			0,0,0
		};
	gpio_config(&gpiosetup);
	//WatchDog settings, managed by RTOS 
	
	
	
}

