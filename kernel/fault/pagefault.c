/*
 * Programmed by Obadiah Crowe
 * Creation Date / Time: 9/05/16 at 3:11 PM
*/
#include "../syscalls/interrupts.h"

static void createPageFault() {
    sendInterrupt(0x0E);
}
