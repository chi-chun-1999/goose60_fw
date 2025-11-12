/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 Ha Thach (tinyusb.org)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "bsp/board_api.h"
#include "pico/stdlib.h"
#include "tusb.h"
#include "pico/bootrom.h"

#include "util.h"
#include "flash.h"
#include "tud_cb.h"


#include "usb_descriptors.h"

//--------------------------------------------------------------------+
// MACRO CONSTANT TYPEDEF PROTYPES
//--------------------------------------------------------------------+




/*------------- MAIN -------------*/
int main(void)
{
  stdio_init_all();
  board_init();
  gpio_init(BUTTON_PIN);
  gpio_set_dir(BUTTON_PIN, GPIO_IN);
  gpio_pull_up(BUTTON_PIN);

  gpio_init(BOOTLOADER_BUTTON_PIN);
  gpio_set_dir(BOOTLOADER_BUTTON_PIN, GPIO_IN);
  gpio_pull_up(BOOTLOADER_BUTTON_PIN);
  
  gpio_init(TEST_PIN);
  gpio_set_dir(TEST_PIN, GPIO_OUT);
  gpio_put(TEST_PIN, 0);
  
  uart_init_custom();
  
  load_keyboard_config();

  // init device stack on configured roothub port
  tud_init(BOARD_TUD_RHPORT);

  if (board_init_after_tusb) {
    board_init_after_tusb();
  }

  while (1)
  {
    tud_task(); // tinyusb device task
    led_blinking_task();
    // send_hid_report((uint8_t)REPORT_ID_KEYBOARD, HID_KEY_A);
    
    board_button_read();

    
    hid_task();
    
    printf("UART Test: Keyboard Config Version: %d\r\n", keyboard_config.version);
    
    // Enter bootloader if BOOTLOADER_BUTTON_PIN is pressed
    // if (!gpio_get(BOOTLOADER_BUTTON_PIN)) {
    //   enter_bootloader();
    // }
    
  }

}





