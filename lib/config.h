#pragma once

// General Purpose IO pins
#define GP0 0
#define GP1 1
#define GP2 2
#define GP3 3
#define GP4 4
#define GP5 5
#define GP6 6
#define GP7 7
#define GP8 8
#define GP9 9
#define GP10 10
#define GP11 11
#define GP12 12
#define GP13 13
#define GP14 14
#define GP15 15
#define GP16 16 // Used for UART TX
#define GP17 17 // Used for UART RX
#define GP18 18
#define GP19 19
#define GP20 20
#define GP21 21
#define GP22 22
#define GP23 23
#define GP24 24
#define GP25 25
#define GP26 26
#define GP27 27
#define GP28 28


// 
#define MATRIX_ROWS 5
#define MATRIX_COLS 14
#define KEYBOARD_LAYER 2

#define MATRIX_ROW_PINS { GP0, GP1, GP2, GP3, GP4 }
//                ROW     1    2    3    4    5
#define MATRIX_COL_PINS { GP5, GP6, GP7, GP8, GP9, GP10, GP11, GP12, GP13, GP14, GP15, GP20, GP21, GP22 }
//                COL     1    2    3    4    5     6     7     8     9     10    11    12    13   14


