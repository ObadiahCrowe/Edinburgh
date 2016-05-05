;%include "../kernel/kernel.c"
global long_mode_start

section .text
bits 64

long_mode_start:
	extern jump
	call jump
	jmp $
