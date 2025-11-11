#!/bin/bash
# In this project, I use the raspberry pi 5 as the development machine. Therefore, I use the built-in UART to log the debug messages.
# The following script will configure the UART log at 115200 baud rate.
# You can run this script in a separate terminal window to see the log messages from the pico device.

minicom -b 115200 -o -D /dev/ttyAMA0