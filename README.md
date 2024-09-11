![128os Logo](https://github.com/user-attachments/assets/afeb8fdd-37b9-45e0-a8e2-38c9e8a0f1ac)

Welcome to 128OS, an independent Operating System.

Current newest version of 128OS is 128OS Prealpha 0.10.0.

You're probably wondering how to boot this thing if you're reading this.


Here are compilation instructions:
(GCC and i686-elf-tools required)

Git clone this repo

cd into 128os/kernel

To compile the kernel:

`gcc -m32 -ffreestanding -fno-exceptions -fno-rtti -nostdlib -c kernel.cpp -o kernel.o`

Now go back a directory and cd into the drivers directory

To compile:

`gcc -m32 -ffreestanding -fno-exceptions -fno-rtti -nostdlib -c terminal.cpp -o terminal.o`
`gcc -m32 -ffreestanding -fno-exceptions -fno-rtti -nostdlib -c keyboard.cpp -o keyboard.o`

Now go back a directory again and cd into the bootloader directory

`i686-elf-as -nostdlib boot.s -o boot.o`

Go back a directory again, stay here

`gcc -T link.ld -m32 -o kernel.bin bootloader/boot.o ~/128os/kernel/128os/kernel/128os/128os/kernel/kernel.o drivers/terminal.o drivers/keyboard.o -nostdlib -lc`

128OS Team

delta, micheal, noogai5, arthurus36
