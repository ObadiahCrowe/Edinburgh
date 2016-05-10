align 16


cpu_num_cores:
	xor eax, eax
	mov ax, [os_CPU_Cores]
	ret
