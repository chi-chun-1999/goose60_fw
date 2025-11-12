#include "util.h"

uint32_t blink_interval_ms = BLINK_NOT_MOUNTED;

void enter_bootloader(void) {
    // Implementation of entering bootloader mode
    reset_usb_boot(0, 0);
}

void test_pin_ctl(bool state)
{
  gpio_put(TEST_PIN, state ? 1 : 0);
}

void uart_init_custom(void) {
    uart_init(UART_ID, UART_BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
}


//--------------------------------------------------------------------+
// BLINKING TASK
//--------------------------------------------------------------------+
void led_blinking_task(void)
{
  static uint32_t start_ms = 0;
  static bool led_state = false;

  // blink is disabled
  if (!blink_interval_ms) return;

  // Blink every interval ms
  if ( board_millis() - start_ms < blink_interval_ms) return; // not enough time
  start_ms += blink_interval_ms;

  board_led_write(led_state);
  led_state = 1 - led_state; // toggle
}