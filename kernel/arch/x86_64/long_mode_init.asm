;%include "kernel/arch/x86_64/kernel.c"
global long_mode_start

section .text
bits 64

long_mode_start:
	extern kernel_main
	call kernel_main
	jmp $