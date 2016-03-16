#!/bin/bash
echo "Creating build dirs.."
mkdir -p build/isofiles/boot/grub

echo "Building kernel.."
ld -n -T kernel/arch/x86_64/linker.ld -o build/kernel.bin $(patsubst kernel/arch/$(arch)/%.asm, \ build/arch/$(arch)/%.o, $(wildcard kernel/arch/$(arch)/*.asm))