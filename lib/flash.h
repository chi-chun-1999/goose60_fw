#ifndef FLASH_H
#define FLASH_H

#include <stdint.h>
#include <string.h>

#include "hardware/flash.h"
#include "pico/stdlib.h"
#include "hardware/sync.h"



#define FLASH_TARGET_OFFSET (1024 * 1023) // Offset to use for writing data in flash

typedef struct{
  uint8_t layout[61];
  uint8_t version;
}keyboard_config_t;

extern keyboard_config_t keyboard_config;


void load_keyboard_config();
void save_keyboard_config();


#endif
