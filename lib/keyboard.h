#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "config.h"
#include "class/hid/hid.h"
#include <string.h>
#include <stdint.h>
#include "pico/stdlib.h"
#include "config.h"

#define KC_NO HID_KEY_NONE

#define LAYOUT_goose60(\
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,      K2D, \
    K30,      K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B,      K3D, \
    K40, K41, K42,                K46,                K4A, K4B, K4C, K4D  \
) { \
    { K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D }, \
    { K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D }, \
    { K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, KC_NO, K2D }, \
    { K30, KC_NO, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, KC_NO, K3D }, \
    { K40, K41, K42, KC_NO, KC_NO, KC_NO, K46, KC_NO, KC_NO, KC_NO, K4A, K4B, K4C, K4D }  \
}

extern const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS];

void keyboard_init(void);
void keyboard_scan_task(uint8_t* modifier, uint8_t *keycode_buffer, uint8_t* keycode_count);

// #define KC_A HID_KEY_A
// #define KC_B HID_KEY_B
// #define KC_C HID_KEY_C
// #define KC_D HID_KEY_D
// #define KC_E HID_KEY_E
// #define KC_F HID_KEY_F
// #define KC_G HID_KEY_G
// #define KC_H HID_KEY_H
// #define KC_I HID_KEY_I
// #define KC_J HID_KEY_J
// #define KC_K HID_KEY_K
// #define KC_L HID_KEY_L
// #define KC_M HID_KEY_M
// #define KC_N HID_KEY_N
// #define KC_O HID_KEY_O
// #define KC_P HID_KEY_P
// #define KC_Q HID_KEY_Q
// #define KC_R HID_KEY_R
// #define KC_S HID_KEY_S
// #define KC_T HID_KEY_T
// #define KC_U HID_KEY_U
// #define KC_V HID_KEY_V
// #define KC_W HID_KEY_W
// #define KC_X HID_KEY_X
// #define KC_Y HID_KEY_Y
// #define KC_Z HID_KEY_Z
// #define KC_1 HID_KEY_1
// #define KC_2 HID_KEY_2
// #define KC_3 HID_KEY_3
// #define KC_4 HID_KEY_4
// #define KC_5 HID_KEY_5
// #define KC_6 HID_KEY_6
// #define KC_7 HID_KEY_7
// #define KC_8 HID_KEY_8
// #define KC_9 HID_KEY_9
// #define KC_0 HID_KEY_0
// #define KC_ENTER HID_KEY_ENTER
// #define KC_ESCAPE HID_KEY_ESCAPE
// #define KC_BSPACE HID_KEY_BACKSPACE
// #define KC_TAB HID_KEY_TAB
// #define KC_SPACE HID_KEY_SPACE
// #define KC_MINUS HID_KEY_MINUS
// #define KC_EQUAL HID_KEY_EQUAL
// #define KC_LBRACKET HID_KEY_LEFT_BRACKET
// #define KC_RBRACKET HID_KEY_RIGHT_BRACKET
// #define KC_BSLASH HID_KEY_BACKSLASH
// #define KC_SEMICOLON HID_KEY_SEMICOLON
// #define KC_APOSTROPHE HID_KEY_APOSTROPHE
// #define KC_GRAVE HID_KEY_GRAVE
// #define KC_COMMA HID_KEY_COMMA
// #define KC_DOT HID_KEY_PERIOD
// #define KC_SLASH HID_KEY_SLASH
// #define KC_CAPSLOCK HID_KEY_CAPS_LOCK
// #define KC_LSHIFT HID_KEY_LEFT_SHIFT
// #define KC_RSHIFT HID_KEY_RIGHT_SHIFT
// #define KC_LCTRL HID_KEY_LEFT_CTRL
// #define KC_RCTRL HID_KEY_RIGHT_CTRL
// #define KC_LALT HID_KEY_LEFT_ALT
// #define KC_RALT HID_KEY_RIGHT_ALT
// #define KC_LGUI HID_KEY_LEFT_GUI
// #define KC_RGUI HID_KEY_RIGHT_GUI
// #define KC_APP HID_KEY_APPLICATION


#endif