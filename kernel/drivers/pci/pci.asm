os_pci_read_reg:
	push rdx
	push rcx
	push rbx

	shl ebx, 16			; Move Bus number to bits 23 - 16
	shl ecx, 8			; Move Device/Slot/Fuction number to bits 15 - 8
	mov bx, cx
	shl edx, 2
	mov bl, dl
	and ebx, 0x00ffffff		; Clear bits 31 - 24
	or ebx, 0x80000000		; Set bit 31
	mov eax, ebx
	mov dx, 0x0CF8
	out dx, eax
	mov dx, 0x0CFC
	in eax, dx

	pop rbx
	pop rcx
	pop rdx
ret