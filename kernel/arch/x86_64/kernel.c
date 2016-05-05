#include "../../../lib/string.h"
#include "../../../lib/types.h"
#include "../../drivers/keyboard.h"
#include "../../drivers/power.h"
#include "../../drivers/video/video.h"
#include "../../drivers/video/colours.h"
#include "../../../software/commandline.h"

void kernel_main(void)
{
	clearScreen();
	printColour("Welcome to ", BLACK_GREY);
	printColour("Edinburgh ", BLACK_LIGHT_BLUE);
	printColour("64-bit.\n", BLACK_GREY);
	printColour("Programmed by Obadiah Crowe", BLACK_GREEN);
	printColour("\n\nCommand Line has been initialised!", BLACK_GREY);
	while(true) {
		printColour("\n>", BLACK_LIGHT_RED);
		printColour(" ", BLACK_GREY);
		minCursor_X = cursor_X;
		minCursor_Y = cursor_Y;
		startCommandLine(readString());
	}
}
