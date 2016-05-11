#ifndef SYSCALLS_H
#define SYSCALLS_H

#include "../../lib/types.h"

unint8 inPortB(unint16 port) {
	unint8 rv;
	__asm__ __volatile__("inb %1, %0" : "=a" (rv) : "dN" (port));
	return rv;
}

void outPortB(unint16 port, unint8 data) {
	__asm__ __volatile__("outb %1, %0" : : "dn" (port), "a" (data));
}

void outPortW(unint16 port, unint16 data)
{
    __asm__ __volatile__("outw %w0, %w1" : : "a" (data), "Nd" (port));
}

#endif
