#include "terminal.h"
#include <stdint.h>
#include <cstddef>
#include <cstdint>

static uint16_t terminal_row = 0;
static uint16_t terminal_column = 0;
static uint8_t terminal_color = 0x0F;

void terminal_initialize() {
    for (uint16_t y = 0; y < VGA_HEIGHT; y++) {
        for (uint16_t x = 0; x < VGA_WIDTH; x++) {
            const size_t index = y * VGA_WIDTH + x;
            VGA_MEMORY[index] = (terminal_color << 8) | ' ';
        }
    }
}

void terminal_putchar(char c) {
    if (c == '\n') {
        terminal_row++;
        terminal_column = 0;
    } else {
        const size_t index = terminal_row * VGA_WIDTH + terminal_column;
        VGA_MEMORY[index] = (terminal_color << 8) | c;
        terminal_column++;
        if (terminal_column >= VGA_WIDTH) {
            terminal_column = 0;
            terminal_row++;
        }
    }
}

void terminal_write(const char* str) {
    for (size_t i = 0; str[i] != '\0'; i++) {
        terminal_putchar(str[i]);
    }
}
