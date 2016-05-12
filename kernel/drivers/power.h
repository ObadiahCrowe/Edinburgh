#ifndef POWER_H
#define POWER_H

#include "../../lib/types.h"
#include "../syscalls/ports.h"

void reboot()
{
    /* Disable interrupts */
    __asm__ __volatile__ ("cli");

    /* Pulse CPU reset */
    outPortB(0x64, 0xFE);

    loop:
      /* Pulse CPU halt */
      __asm__ __volatile__("hlt");
      goto loop;
}

void powerOff()
{
  /* TODO */
}
#endif
