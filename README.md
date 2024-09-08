![StarOS logo gradient512](https://avatars.githubusercontent.com/u/179967275?s=400&u=6c9b057e9f17ac51d42c932d06e1f4b376e67118&v=4)

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
