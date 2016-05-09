#!/bin/bash
echo "=== Building Edinburgh-x86-64 ==="

#Clear build dir
echo "Clearing temporary build files..."
if [ -f build ]; then
      rm -r build
fi

#Make build dir
if [ ! -d build/boot ];
then
	echo "Creating build directories..."
	mkdir -p build/boot
fi

#Compile kernel files
echo "Creating kernel objects..."
x86_64-elf-gcc -ffreestanding -mcmodel=large -mno-red-zone -mno-mmx -mno-sse -mno-sse2 -c kernel/boot/kerneljump.c -o build/kernel.o
nasm -felf64 kernel/boot/boot.asm -o build/boot/boot.o
nasm -felf64 kernel/boot/long_mode_init.asm -o build/boot/long_mode_init.o
nasm -felf64 kernel/boot/multiboot_header.asm -o build/boot/multiboot_header.o

#Link kernel
echo "Linking kernel..."
ld -n -o build/kernel.bin -T kernel/boot/linker.ld build/boot/boot.o build/boot/long_mode_init.o build/boot/multiboot_header.o build/kernel.o

#Make ISO building dirs
echo "Building ISO..."
mkdir -p build/isofiles/boot/grub
cp build/kernel.bin build/isofiles/boot/kernel.bin
cp kernel/boot/grub/grub.cfg build/isofiles/boot/grub
cp efi.img build/isofiles
grub-mkrescue -o Edinburgh-x86_64.iso build/isofiles
echo "Done!"
