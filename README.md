![128os Logo](https://github.com/user-attachments/assets/4047cf31-b409-4fb3-ad28-64306c692780)


Welcome to 128OS, an independent UNIX Operating System.
Current newest version of 128OS is StarOS/128OS Prealpha 0.0.3
You're probably wondering how to boot this thing if you're reading this.


Here are compilation instructions:
(You need an i686 cross-compiler)

Git clone this repo

cd into 128os/kernel

To compile:

`i686-elf-gcc -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra`

You need a bootloader for this thing, I recommend the one from OSDev.

128OS Team

delta, konada
