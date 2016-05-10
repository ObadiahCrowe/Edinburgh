align 16


cpu_num_cores:
	xor eax, eax
	mov ax, [os_NumCores]
	ret
