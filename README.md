![StarOS logo](https://github.com/user-attachments/assets/6bf97257-f1f6-4c53-b0c1-2fa6deae657b)


Welcome to StarOS, an independent UNIX Operating System.
You're probably wondering how to boot this thing if you're reading this.

Here are compilation instructions:
(You need an i686 cross-compiler)

Git clone this repo

cd into staros/kernel

To compile:

`i686-elf-gcc -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra`

You need a bootloader for this thing, I recommend the one from OSDev.

Here's StarOS v0.0.2 pre-alpha running in QEMU
![image](https://github.com/user-attachments/assets/fd48010d-37c4-4dea-8489-d9b283be6ca3)


StarOS Team

delta, konada, na69
