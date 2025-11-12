#include "keyboard.h"


const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
     * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
     * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
     * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │    Shift │
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
     * │Ctrl│GUI │Alt │                        │ Alt│ GUI│Menu│Ctrl│
     * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
     */

    // Layout 0: 
    [0] = LAYOUT_goose60(\
         HID_KEY_GRAVE,  HID_KEY_1,        HID_KEY_2,        HID_KEY_3,        HID_KEY_4,        HID_KEY_5,        HID_KEY_6,        HID_KEY_7,        HID_KEY_8,        HID_KEY_9,        HID_KEY_0,        HID_KEY_MINUS,    HID_KEY_EQUAL,    HID_KEY_BACKSPACE,\
         HID_KEY_TAB,     HID_KEY_Q,        HID_KEY_W,        HID_KEY_E,        HID_KEY_R,        HID_KEY_T,        HID_KEY_Y,        HID_KEY_U,        HID_KEY_I,        HID_KEY_O,        HID_KEY_P,        HID_KEY_BRACKET_LEFT, HID_KEY_BRACKET_RIGHT, HID_KEY_BACKSLASH,\
         HID_KEY_CAPS_LOCK, HID_KEY_A,        HID_KEY_S,        HID_KEY_D,        HID_KEY_F,        HID_KEY_G,        HID_KEY_H,        HID_KEY_J,        HID_KEY_K,        HID_KEY_L,        HID_KEY_SEMICOLON, HID_KEY_APOSTROPHE, HID_KEY_ENTER,\
         HID_KEY_SHIFT_LEFT, HID_KEY_Z,        HID_KEY_X,        HID_KEY_C,        HID_KEY_V,        HID_KEY_B,        HID_KEY_N,        HID_KEY_M,        HID_KEY_COMMA,    HID_KEY_PERIOD,   HID_KEY_SLASH,     HID_KEY_SHIFT_RIGHT,\
         HID_KEY_CONTROL_LEFT, HID_KEY_GUI_LEFT, HID_KEY_ALT_LEFT,  HID_KEY_SPACE,                           HID_KEY_ALT_RIGHT, HID_KEY_GUI_RIGHT, HID_KEY_APPLICATION, HID_KEY_CONTROL_RIGHT\
    )
          
          
    
    // Layout 1:
     /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
     * │ESC│F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│ Ins   │
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
     * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
     * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │    Shift │
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
     * │Ctrl│GUI │Alt │                        │ Alt│ GUI│Menu│Ctrl│
     * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
     */
    // [1] = LAYOUT_goose60()

};


void keyboard_init(void) {
    // Any initialization code for the keyboard can go here
    
    // GPIO initialization, matrix setup, etc.
    
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        // Initialize row pins as inputs with pull-ups
        
        gpio_init((uint8_t[])MATRIX_ROW_PINS[row]);
        gpio_set_dir((uint8_t[])MATRIX_ROW_PINS[row], GPIO_OUT);
        gpio_put((uint8_t[])MATRIX_ROW_PINS[row], 1);

    }
    
    for (uint16_t col = 0; col < MATRIX_COLS; col++) {
        // Initialize column pins as outputs and set them high
        gpio_init((uint8_t[])MATRIX_COL_PINS[col]);
        gpio_set_dir((uint8_t[])MATRIX_COL_PINS[col], GPIO_OUT);
        gpio_put((uint8_t[])MATRIX_COL_PINS[col], 1);
    }
    
    // load layout from flash if needed

    
}

void keyboard_scan_task(uint8_t* modifier, uint8_t *keycode_buffer, uint8_t* keycode_count) {
    
    *keycode_count = 0;

    // Scan the keyboard matrix and update key states
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        // Set the current row low
        gpio_put((uint8_t[])MATRIX_ROW_PINS[row], 0);
        
        for (uint16_t col = 0; col < MATRIX_COLS; col++) {
            // Read the state of each column
            bool key_pressed = !gpio_get((uint8_t[])MATRIX_COL_PINS[col]);
            
            
            // Process key state (pressed/released)
            if (key_pressed) {
                
                uint8_t keycode = keymaps[0][row][col]; // Using layout 0 for now
                                                        // 
                s

                // Key at (row, col) is pressed
                // Handle key press event
                keycode_buffer[*keycode_count] = keycode;
                (*keycode_count)++;
                
                
            }
        }
        
        // Set the current row back to high
        gpio_put((uint8_t[])MATRIX_ROW_PINS[row], 1);
    }
    
    keycode_buffer[*keycode_count] = HID_KEY_NONE; // End of keycodes
    
    
    // Additional processing if needed
}