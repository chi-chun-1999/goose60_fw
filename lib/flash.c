
#include "flash.h"

keyboard_config_t keyboard_config;

void load_keyboard_config()
{
  memcpy(&keyboard_config, (const void*)(XIP_BASE + FLASH_TARGET_OFFSET), sizeof(keyboard_config));
//   if (keyboard_config.version != 1)
//   {
//     // set default layout
//     memset(&keyboard_config, 0, sizeof(keyboard_config));
//     // keyboard_config.version = 1;
//   }
}

void save_keyboard_config()
{
  // keyboard_config.version = 1;
  uint32_t interrupts = save_and_disable_interrupts();
  flash_range_erase(FLASH_TARGET_OFFSET, FLASH_SECTOR_SIZE);
  flash_range_program(FLASH_TARGET_OFFSET, (const uint8_t*)&keyboard_config, sizeof(keyboard_config));
  restore_interrupts(interrupts);
}