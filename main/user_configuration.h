#pragma once

// Network MAC Address settings for your ESP module
// Comment this to appoint MAC Addr manually.
#define USE_DEFAULT_EFUSE_MAC

// Set MAC Address.
#ifndef USE_DEFAULT_EFUSE_MAC
uint8_t USER_MAC_ADDR[6] = {0x71, 0xBC, 0x10, 0x6A, 0xEA, 0x35};
#endif
