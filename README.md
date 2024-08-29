Welcome to StarOS, an independent UNIX Operating System.
You're probably wondering how to boot this thing if you're reading this.

Here are compilation instructions:
(You need an i686 cross-compiler)

Git clone this repo

cd into staros/kernel

To compile:

i686-elf-gcc -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

You need a bootloader for this thing, I recommend the one from OSDev.


StarOS Team

delta, konada, na69
