arch ?= x86_64
kernel := build/kernel.bin
iso := build/edinburgh.iso

linker_script := kernel/arch/$(arch)/linker.ld
grub_cfg := kernel/arch/$(arch)/grub.cfg
assembly_source_files := $(wildcard kernel/arch/$(arch)/*.asm)
assembly_object_files := $(patsubst kernel/arch/$(arch)/%.asm, \
	build/arch/$(arch)/%.o, $(assembly_source_files))
c_sources = $(wildcard kernel/arch/$(arch)/*.c)
c_headers = $(wildcard kernel/arch/$(arch)/*.h)
obj = ${c_sources:.c=.o} 

CC = /home/obadiah/Documents/OSDev/crosscompiler/bin/x86_64-elf-gcc
GDB = /home/obadiah/Documents/OSDev/crosscompiler/bin/x86_64-elf-gdb
CFLAGS = "-ffreestanding -mcmodel=large -mno-red-zone -mno-mmx -mno-sse -mno-sse2 -c"

.PHONY: run edinburgh

edinburgh: $(build/arch/$(arch)/%.o)
	@$(%.o)
	@$(%.bin)
	@$(build/arch/$(arch)/%.o)
	@ld -n -T $(linker_script) -o $(kernel) $(assembly_object_files) kernel/arch/$(arch)/kernel.o
	ld -n --gc-sections -T $(linker_script) -o $(kernel) $(assembly_object_files) $(c_sources) $(c_headers) $(obj)
	@mkdir -p build/isofiles/boot/grub
	@cp $(kernel) build/isofiles/boot/kernel.bin
	@cp $(grub_cfg) build/isofiles/boot/grub
	@grub-mkrescue -o $(iso) build/isofiles

run: $(iso)
	@qemu-system-x86_64 -cdrom $(iso)

kernel/arch/$(arch)/%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -c $< -o $@

kernel/arch/$(arch)/%.o: %.asm
	nasm $< -f elf -o $@

kernel/arch/$(arch)/%.bin: %.asm
	nasm $< -f bin -o $@