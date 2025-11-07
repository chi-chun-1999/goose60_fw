#include "util.h"

void enter_bootloader(void) {
    // Implementation of entering bootloader mode
    reset_usb_boot(0, 0);
}
