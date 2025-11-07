
#ifndef CONFIG_USB_HID
#define CONFIG_USB_HID

#include "pico/bootrom.h"
#include "util.h"
#include "tusb.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>


#define REPORT_ID_CUSTOM 0xA0

#define ENTER_BOOTLOADER_COMMAND 0xFF


void usb_hid_process_report(uint8_t instance, uint8_t report_id, hid_report_type_t report_type, uint8_t const* buffer, uint16_t bufsize);



#endif