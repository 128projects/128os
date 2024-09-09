#ifndef TERMINAL_H
#define TERMINAL_H
#include <cstdint>

#define VGA_WIDTH 80
#define VGA_HEIGHT 25

static volatile uint16_t* const VGA_MEMORY = (uint16_t*)0xB8000;

void terminal_initialize();
void terminal_putchar(char c);
void terminal_write(const char* str);

#endif // TERMINAL_H
