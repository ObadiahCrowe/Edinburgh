#ifndef POWER_H
#define POWER_H

#include "../../lib/types.h"

void killCPU(void)
{
  asm volatile ("cli");
}
#endif
