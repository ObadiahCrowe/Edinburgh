#include "../lib/string.h"
#include "../software/commandline.h"
#include "drivers/filesystems/filesystem.c"
#include "drivers/input/keyboard.h"

void kernel_main(void)
{
    clearScreen();
    printColour("Welcome to ", BLACK_GREY);
	printColour("Edinburgh ", BLACK_LIGHT_BLUE);
	printColour("64-bit.\n", BLACK_GREY);
	printColour("Programmed by Obadiah Crowe", BLACK_GREEN);
	printColour("\n\nCommand Line has been initialised!", BLACK_GREY);
	listDisks();
	while(true) {
		printColour("\n>", BLACK_LIGHT_RED);
		printColour(" ", BLACK_GREY);
		minCursor_X = cursor_X;
		minCursor_Y = cursor_Y;
		startCommandLine(readString());
	}
}
