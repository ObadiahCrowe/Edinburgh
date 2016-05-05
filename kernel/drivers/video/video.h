#ifndef SCREEN_H
#define SCREEN_H

#include "../../../lib/string.h"
#include "colours.h"
#include "../../../lib/types.h"

/* Cursor variables */
int cursor_X = 0;
int cursor_Y = 0;
int minCursor_X = 0;
int minCursor_Y = 0;

/* Screen size variables */
const unint16 scrnWdth = 80;
const unint16 scrnHght = 25;
const unint16 scrnDpth = 2;

/* Clear line on the screen */
void clearLine(unint16 start, unint16 end) {
	unint16 i = scrnWdth * start * scrnDpth;
	string mem = (string) 0xb8000;
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

void scrollUp(unint8 lineNum) {
	string mem = (string) 0xb8000;
	unint16 i = 0;
	for (i; i < scrnWdth * (scrnHght - 1) * scrnDpth; i++) {
		mem[i] = mem[i + scrnHght * scrnDpth * lineNum];
	}
	clearLine(scrnHght - 1 - lineNum, scrnHght - 1);
	if (cursor_Y - lineNum < 0) {
		cursor_Y = 0;
		cursor_X = 0;
	} else {
		cursor_Y -= lineNum;
	}
	updateCursor();
}

void checkNewLine() {
	if (cursor_Y >= scrnHght - 1) {
		scrollUp(1);
	}
	minCursor_Y = cursor_Y;
}

void printChar(char ch) {
	string mem = (string) 0xb8000;
	switch (ch) {
		case (0x08):
			if (cursor_X > 0) {
				cursor_X--;
				mem[(cursor_Y * scrnWdth + cursor_X) * scrnDpth] = 0x00;
			}
			break;
		case (0x09):
			cursor_X = (cursor_X + 8) & ~ (8 - 1);
			break;
		case ('\r'):
			cursor_X = 0;
			break;
		case ('\n'):
			cursor_X = 0;
			cursor_Y++;
			break;
		default:
			mem[(cursor_Y * scrnWdth + cursor_X) * scrnDpth] = ch;
			mem[(cursor_Y * scrnWdth + cursor_X) * scrnDpth + 1] = BLACK_LIGHT_WHITE;
			cursor_X++;
			break;
	}
	if (cursor_X >= scrnWdth) {
		cursor_X = 0;
		cursor_Y++;
	}
	checkNewLine();
	updateCursor();
}

void printCharColour(char ch, color col) {
	string mem = (string) 0xb8000;
	switch (ch) {
		case (0x08):
			if (cursor_X > 0) {
				cursor_X--;
				mem[(cursor_Y * scrnWdth + cursor_X) * scrnDpth] = 0x00;
			}
			break;
		case (0x09):
			cursor_X = (cursor_X + 8) & ~ (8 - 1);
			break;
		case ('\r'):
			cursor_X = 0;
			break;
		case ('\n'):
			cursor_X = 0;
			cursor_Y++;
			break;
		default:
			mem[(cursor_Y * scrnWdth + cursor_X) * scrnDpth] = ch;
			mem[(cursor_Y * scrnWdth + cursor_X) * scrnDpth + 1] = col;
			cursor_X++;
			break;
	}
	if (cursor_X >= scrnWdth) {
		cursor_X = 0;
		cursor_Y++;
	}
	checkNewLine();
	updateCursor();
}

void print(string s) {
	unint16 i = 0;
	unint16 len = stringLength(s);
	for (i; i < len; i++) {
		printChar(s[i]);
	}
}

void printColour(string s, color col) {
	unint64 i = 0;
	unint64 len = stringLength(s);
	for (i; i < len; i++) {
		printCharColour(s[i], col);
	}
}

#endif
