#!/bin/bash
echo "Building Edinburgh-x86-64"
#Make build dir
echo "Creating build dirs.."
mkdir -p build/arch/x86_64
#Compile kernel files
echo "Creating kernel objects.."
nasm -felf64 kernel/arch/x86_64/boot.asm -o build/arch/x86_64/boot.o
nasm -felf64 kernel/arch/x86_64/long_mode_init.asm -o build/arch/x86_64/long_mode_init.o
nasm -felf64 kernel/arch/x86_64/multiboot_header.asm -o build/arch/x86_64/multiboot_header.o
/home/obadiah/Documents/OSDev/crosscompiler/bin/x86_64-elf-gcc -ffreestanding -mcmodel=large -mno-red-zone -mno-mmx -mno-sse -mno-sse2 -c kernel/arch/x86_64/kernel.c -o build/arch/x86_64/kernel.o
#Link kernel
echo "Linking kernel"
ld -n --gc-sections -T kernel/arch/x86_64/linker.ld -o build/kernel.bin build/arch/x86_64/boot.o build/arch/x86_64/long_mode_init.o build/arch/x86_64/multiboot_header.o build/arch/x86_64/kernel.o
#Make ISO building dirs
echo "Building ISO"
mkdir -p build/isofiles/boot/grub
cp build/kernel.bin build/isofiles/boot/kernel.bin
cp kernel/arch/x86_64/grub.cfg build/isofiles/boot/grub
cp efi.img build/isofiles
grub-mkrescue -o Edinburgh-x86_64.iso build/isofiles
echo "Done!"