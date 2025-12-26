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
     * │Ctrl│GUI │Alt │                        │ Alt│ GUI│Menu│ FN │
     * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
     */

    // Layout 0: 
    [0] = LAYOUT_goose60(\
         HID_KEY_GRAVE,  HID_KEY_1,        HID_KEY_2,        HID_KEY_3,        HID_KEY_4,        HID_KEY_5,        HID_KEY_6,        HID_KEY_7,        HID_KEY_8,        HID_KEY_9,        HID_KEY_0,        HID_KEY_MINUS,    HID_KEY_EQUAL,    HID_KEY_BACKSPACE,\
         HID_KEY_TAB,     HID_KEY_Q,        HID_KEY_W,        HID_KEY_E,        HID_KEY_R,        HID_KEY_T,        HID_KEY_Y,        HID_KEY_U,        HID_KEY_I,        HID_KEY_O,        HID_KEY_P,        HID_KEY_BRACKET_LEFT, HID_KEY_BRACKET_RIGHT, HID_KEY_BACKSLASH,\
         HID_KEY_CAPS_LOCK, HID_KEY_A,        HID_KEY_S,        HID_KEY_D,        HID_KEY_F,        HID_KEY_G,        HID_KEY_H,        HID_KEY_J,        HID_KEY_K,        HID_KEY_L,        HID_KEY_SEMICOLON, HID_KEY_APOSTROPHE, HID_KEY_ENTER,\
         HID_KEY_SHIFT_LEFT, HID_KEY_Z,        HID_KEY_X,        HID_KEY_C,        HID_KEY_V,        HID_KEY_B,        HID_KEY_N,        HID_KEY_M,        HID_KEY_COMMA,    HID_KEY_PERIOD,   HID_KEY_SLASH,     HID_KEY_SHIFT_RIGHT,\
         HID_KEY_CONTROL_LEFT, HID_KEY_GUI_LEFT, HID_KEY_ALT_LEFT,  HID_KEY_SPACE,                           HID_KEY_ALT_RIGHT, HID_KEY_GUI_RIGHT, HID_KEY_APPLICATION, FN_KEY\
    ),
          
          
    
    // Layout 1:
     /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
     * │ESC│F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│ Ins   │
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
     * │ Caps │ A │ S │ D │ F │ G │ ← │ ↑ │ ↓ │ → │ ; │ ' │  Enter │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
     * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │    Shift │
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
     * │Ctrl│GUI │Alt │                        │ Alt│ GUI│Menu│ FN │
     * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
     */
    [1] = LAYOUT_goose60(\
            HID_KEY_ESCAPE, HID_KEY_F1,       HID_KEY_F2,       HID_KEY_F3,       HID_KEY_F4,       HID_KEY_F5,       HID_KEY_F6,       HID_KEY_F7,       HID_KEY_F8,       HID_KEY_F9,       HID_KEY_F10,      HID_KEY_F11,      HID_KEY_F12,      HID_KEY_INSERT,\
            HID_KEY_TAB,     HID_KEY_Q,        HID_KEY_W,        HID_KEY_E,        HID_KEY_R,        HID_KEY_T,        HID_KEY_Y,        HID_KEY_U,        HID_KEY_I,        HID_KEY_O,        HID_KEY_P,        HID_KEY_BRACKET_LEFT, HID_KEY_BRACKET_RIGHT, HID_KEY_BACKSLASH,\
            HID_KEY_CAPS_LOCK, HID_KEY_A,        HID_KEY_S,        HID_KEY_D,        HID_KEY_F,        HID_KEY_G,        HID_KEY_ARROW_LEFT,        HID_KEY_ARROW_UP,        HID_KEY_ARROW_DOWN,        HID_KEY_ARROW_RIGHT,        HID_KEY_SEMICOLON, HID_KEY_APOSTROPHE, HID_KEY_ENTER,\
            HID_KEY_SHIFT_LEFT, HID_KEY_Z,        HID_KEY_X,        HID_KEY_C,        HID_KEY_V,        HID_KEY_B,        HID_KEY_N,        HID_KEY_M,        HID_KEY_COMMA,    HID_KEY_PERIOD,   HID_KEY_SLASH,     HID_KEY_SHIFT_RIGHT,\
            HID_KEY_CONTROL_LEFT, HID_KEY_GUI_LEFT, HID_KEY_ALT_LEFT,  HID_KEY_SPACE,                           HID_KEY_ALT_RIGHT, HID_KEY_GUI_RIGHT, HID_KEY_APPLICATION, FN_KEY\
    )

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
    // printf("Scanning keyboard matrix...\r\n");

    bool done = false;
    
    int layer = 0; // Default layer
    
    //Scan fn key state
    gpio_put((uint8_t[])MATRIX_ROW_PINS[FN_ROW], 0);
    sleep_ms(10);
    bool fn_pressed = !gpio_get((uint8_t[])MATRIX_COL_PINS[FN_COL]); // Assuming FN key is at last column
    gpio_put((uint8_t[])MATRIX_ROW_PINS[FN_ROW], 1);

                                                                              // 
    if (fn_pressed) {
        layer = 1; // Switch to layer 1 when FN is pressed
        printf("FN key pressed, switching to layer 1\r\n");
    }
    else{
        layer = 0; // Default layer
        // printf("FN key not pressed, using layer 0\r\n");
    }
    // printf("Using layer %d\r\n", layer);

    
    // Scan the keyboard matrix and update key states
    for (uint8_t row = 0; row < MATRIX_ROWS && !done; row++) {
        // Set the current row low
        
        gpio_put((uint8_t[])MATRIX_ROW_PINS[row], 0);
        
        for (uint16_t col = 0; col < MATRIX_COLS; col++) {
            // printf("Checking row %d, col %d\r\n", row, col);
            // Read the state of each column
            bool key_pressed = !gpio_get((uint8_t[])MATRIX_COL_PINS[col]);
            
            
            
            // // Process key state (pressed/released)
            if (key_pressed) {
                
                uint8_t keycode = keymaps[layer][row][col]; // Using layout 0 for now
                printf("FN key detected at row %d, col %d and layer %d\r\n", row, col, fn_pressed);
                
                if (keycode == FN_KEY) {
                    // printf("FN key detected at row %d, col %d\r\n", row, col);
                    continue; // No key assigned to this position
                }
                                                        // 
                // if (keycode == HID_KEY_CONTROL_LEFT || keycode == HID_KEY_CONTROL_RIGHT) {
                //     *modifier |= CTRL_MASK;
                // } else if (keycode == HID_KEY_SHIFT_LEFT || keycode == HID_KEY_SHIFT_RIGHT) {
                //     *modifier |= SHIFT_MASK;
                // } else if (keycode == HID_KEY_ALT_LEFT || keycode == HID_KEY_ALT_RIGHT) {
                //     *modifier |= ALT_MASK;
                // } else if (keycode == HID_KEY_GUI_LEFT || keycode == HID_KEY_GUI_RIGHT) {
                //     *modifier |= GUI_MASK;
                // }
                
                // printf("Keycode pressed: %x\r\n", keycode);

                // Key at (row, col) is pressed
                // Handle key press event
                keycode_buffer[*keycode_count] = keycode;
                (*keycode_count)++;
                if(*keycode_count >= 6) {
                    // Maximum 6 keycodes in HID report
                    done = true;
                    break;
                }
                
                
            }

        }
        
        // Set the current row back to high
        gpio_put((uint8_t[])MATRIX_ROW_PINS[row], 1);

    }
    
    keycode_buffer[*keycode_count] = HID_KEY_NONE; // End of keycodes
    
    
    // Additional processing if needed
}