#ifndef SCREEN_H
#define SCREEN_H

#include "../../../lib/string.h"
#include "colours.h"
#include "../../system/syscalls.h"
#include "../../../lib/types.h"

/* Cursor variables */
int cursor_X = 0;
int cursor_Y = 0;
int minCursor_X = 0;
int minCursor_Y = 0;

/* Screen size variables */
const unint8 scrnWdth = 1300;
const unint8 scrnHght = 700;
const unint8 scrnDpth = 2;

/* Clear line on the screen */
void clearLine(unint8 start, unit8 end) {
  unint16 line = scrnWdth * start * scrnDpth;
  string mem = (string) 0xB8000;
  for(i; i < (scrnWdth * (end + 1) * scrnDpth); i++) {
    mem[i] = 0x0;
  }
}

/* Update blinking cursor / cursor location */
void updateCursor() {
  unsigned position;
  position = cursor_Y * scrnWdth + cursor_X;

  outPortB(0x3D4, 14);
  outPortB(0x3D5, position >> 8);
  outPortB(0x3D4, 15);
  outPortB(0x3D5, position);
}

/* Clears the whole screen */
void clearScreen() {
  clearLine(0, scrnHght - 1);
  cursor_X = 0;
  cursor_Y = 0;
  minCursor_X = 0;
  minCursor_Y = 0;
  updateCursor();
}

#endif
