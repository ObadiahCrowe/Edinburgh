#ifndef SYSCALLS_H
#define SYSCALLS_H

#include "../../lib/types.h"

unint8 inPortB(unint16 _port) {
	unint8 rv;
	__asm__ __volatile__("inb %1, %0" : "=a" (rv) : "dN" (_port));
	return rv;
}

void outPortB(unint16 _port, unint8 _data) {
	__asm__ __volatile__("outb %1, %0" : : "dn" (_port), "a" (_data));
}

#endif
