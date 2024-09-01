#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


enum vga_color {
    VGA_COLOR_BLACK = 0,
    VGA_COLOR_BLUE = 1,
    VGA_COLOR_GREEN = 2,
    VGA_COLOR_CYAN = 3,
    VGA_COLOR_RED = 4,
    VGA_COLOR_MAGENTA = 5,
    VGA_COLOR_BROWN = 6,
    VGA_COLOR_LIGHT_GREY = 7,
    VGA_COLOR_DARK_GREY = 8,
    VGA_COLOR_LIGHT_BLUE = 9,
    VGA_COLOR_LIGHT_GREEN = 10,
    VGA_COLOR_LIGHT_CYAN = 11,
    VGA_COLOR_LIGHT_RED = 12,
    VGA_COLOR_LIGHT_MAGENTA = 13,
    VGA_COLOR_LIGHT_BROWN = 14,
    VGA_COLOR_WHITE = 15,
};

static inline uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg) 
{
    return fg | bg << 4;
}

static inline uint16_t vga_entry(unsigned char uc, uint8_t color) 
{
    return (uint16_t) uc | (uint16_t) color << 8;
}

size_t strlen(const char* str) 
{
    size_t len = 0;
    while (str[len])
        len++;
    return len;
}

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer;

void terminal_initialize(void) 
{
    terminal_row = 0;
    terminal_column = 0;
    terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
    terminal_buffer = (uint16_t*) 0xB8000;
    for (size_t y = 0; y < VGA_HEIGHT; y++) {
        for (size_t x = 0; x < VGA_WIDTH; x++) {
            const size_t index = y * VGA_WIDTH + x;
            terminal_buffer[index] = vga_entry(' ', terminal_color);
        }
    }
}

void terminal_setcolor(uint8_t color) 
{
    terminal_color = color;
}

void terminal_putentryat(char c, uint8_t color, size_t x, size_t y) 
{
    const size_t index = y * VGA_WIDTH + x;
    terminal_buffer[index] = vga_entry(c, color);
}

void terminal_putchar(char c) 
{
    terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
    if (++terminal_column == VGA_WIDTH) {
        terminal_column = 0;
        if (++terminal_row == VGA_HEIGHT)
            terminal_row = 0;
    }
}

void terminal_write(const char* data, size_t size) 
{
    for (size_t i = 0; i < size; i++)
        terminal_putchar(data[i]);
}

void terminal_writestring(const char* data) 
{
    terminal_write(data, strlen(data));
}

static unsigned int seed = 12345;
unsigned int rand(void) {
    seed = seed * 1103515245 + 12345;
    return (seed / 65536) % 32768;
}

char random_char(void) {
    const char charset[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxy";
    return charset[rand() % (sizeof(charset) - 1)];
}

void cmatrix_effect(void) {
    size_t col_positions[VGA_WIDTH];
    size_t col_speeds[VGA_WIDTH];

    for (size_t i = 0; i < VGA_WIDTH; i++) {
        col_positions[i] = 0;
        col_speeds[i] = 0;
    }

    for (size_t i = 0; i < VGA_WIDTH; i++) {
        col_positions[i] = rand() % VGA_HEIGHT;
        col_speeds[i] = rand() % 5 + 1;  
    }

    const char* message = "STAROS PREALPHA";
    size_t message_len = strlen(message);
    size_t message_x = (VGA_WIDTH - message_len) / 2;
    size_t message_y = VGA_HEIGHT / 2;

    while (true) {
        for (size_t x = 0; x < VGA_WIDTH; x++) {
            if (x >= message_x && x < message_x + message_len && col_positions[x] == message_y) {
                terminal_putentryat(message[x - message_x], vga_entry_color(VGA_COLOR_GREEN, VGA_COLOR_BLACK), x, col_positions[x]);
            } else {
                terminal_putentryat(' ', terminal_color, x, (col_positions[x] + VGA_HEIGHT - col_speeds[x]) % VGA_HEIGHT);
                col_positions[x] = (col_positions[x] + 1) % VGA_HEIGHT;
                terminal_putentryat(random_char(), vga_entry_color(VGA_COLOR_GREEN, VGA_COLOR_BLACK), x, col_positions[x]);
            }
        }

        for (volatile int i = 0; i < 100000; i++);
    }
}

void kernel_main(void) 
{
    terminal_initialize();

    cmatrix_effect();
}

