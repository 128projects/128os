Welcome to StarOS, an independent UNIX Operating System.
You probably are wondering how do I boot this thing if you are here

Here are compilation instructions:

Git clone this repo

Go to kernel

You need an i686 cross-compiler

To compile:

i686-elf-gcc -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

You need an bootloader for this thing, I recommend the one from OSDev


StarOS Team

delta, konada, na69
