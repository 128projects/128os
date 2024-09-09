#include <stdint.h>
#include "../drivers/io.h"
#include "../drivers/terminal.h"
#include "../drivers/keyboard.h"

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

    terminal_write("Echo terminal:\n");

    while (1) {
        char c = keyboard_getchar();  

        terminal_putchar(c);

        if (c == '\n') {
            terminal_write("Enter pressed. You can keep typing...\n");
        }
    }

    while (1);
}
