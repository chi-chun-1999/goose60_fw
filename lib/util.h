#ifndef UTIL_H
#define UTIL_H

#include "pico/bootrom.h"
#include "pico/stdio.h"
#include "hardware/gpio.h"
#include "hardware/uart.h"

void enter_bootloader(void);
void test_pin_ctl(bool state);
void uart_init_custom(void);

#if 1

#define BUTTON_PIN 15
#define BOOTLOADER_BUTTON_PIN 21
#define TEST_PIN 18


#define UART_TX_PIN 16
#define UART_RX_PIN 17
#define UART_BAUD_RATE 115200
#define UART_ID uart0


#endif

#endif