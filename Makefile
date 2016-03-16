arch ?= x86_64
kernel := build/kernel.bin
iso := build/edinburgh.iso

linker_script := kernel/arch/$(arch)/linker.ld
grub_cfg := kernel/arch/$(arch)/grub.cfg
assembly_source_files := $(wildcard kernel/arch/$(arch)/*.asm)
assembly_object_files := $(patsubst kernel/arch/$(arch)/%.asm, \
	build/arch/$(arch)/%.o, $(assembly_source_files))

.PHONY: all clean run iso

all: $(kernel)

clean:
	@rm -r build

run: $(iso)
	@qemu-system-x86_64 -cdrom $(iso)

iso: $(iso)

$(iso): $(ckernel) $(kernel) $(grub_cfg)
	@mkdir -p build/isofiles/boot/grub
	@cp $(kernel) build/isofiles/boot/kernel.bin
	@cp $(grub_cfg) build/isofiles/boot/grub
	@grub-mkrescue -o $(iso) build/isofiles

$(ckernel):
	@/home/obadiah/Documents/OSDev/Edinburgh64/crosscompiler/bin/x86_64-elf-gcc -ffreestanding -mcmodel=large -mno-red-zone -mno-mmx -mno-sse -mno-sse2 -c kernel.c -o kernel.o

$(kernel): $(assembly_object_files) $(linker_script)
	@ld -n -T $(linker_script) -o $(kernel) $(assembly_object_files) kernel/arch/$(arch)/kernel.o

# compile assembly files
build/arch/$(arch)/%.o: kernel/arch/$(arch)/%.asm
	@mkdir -p $(shell dirname $@)
	@nasm -felf64 $< -o $@
