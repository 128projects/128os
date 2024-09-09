#include "io.h"
#include "keyboard.h"

#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64

static const char scancode_table[] = {
    0, 27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',
    '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',
    0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', 0, '\\',
    'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0, '*', 0, ' '
};

void keyboard_init() {
    // Reset the keyboard
    outb(KEYBOARD_STATUS_PORT, 0xFF);
}

char keyboard_getchar() {
    char scancode = 0;
    
    while (1) {
        // Check if the keyboard has sent data
        if (inb(KEYBOARD_STATUS_PORT) & 0x01) {
            scancode = inb(KEYBOARD_DATA_PORT);
            if (scancode > 0 && scancode < 58) {
                return scancode_table[scancode];
            }
        }
    }
    return 0;  
}
