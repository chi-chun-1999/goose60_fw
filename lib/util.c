#include "util.h"

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