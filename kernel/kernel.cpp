#include <stdint.h>
#include "io.h"
#include "terminal.h"
#include "keyboard.h"

void test_virtual_memory() {
    volatile uint32_t *ptr = (uint32_t *)0x1000;  
    *ptr = 0xDEADBEEF;                            
    uint32_t value = *ptr;                        

    if (value == 0xDEADBEEF) {
        terminal_write("Virtual memory test passed.\n");
    } else {
        terminal_write("Virtual memory test failed.\n");
    }
}

extern "C" void kernel_main() {
    terminal_initialize();

    terminal_write("Testing virtual memory...\n");
    test_virtual_memory();

    terminal_write("Initializing keyboard...\n");
    keyboard_init();

    
    terminal_write("Echo terminal (press 'Enter' to stop):\n");  // This part doesn't work yet
    while (1) {
        char c = keyboard_getchar();
        if (c == '\n') break;
        terminal_putchar(c);  
    }

    terminal_write("\nExiting kernel...\n");
    while (1);
}
