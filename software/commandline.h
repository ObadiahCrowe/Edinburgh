#ifndef COMMANDS_H
#define COMMANDS_H

#include "../lib/string.h"
#include "../lib/types.h"
#include "../kernel/drivers/power.h"
#include "../kernel/drivers/video/video.h"
#include "../kernel/fault/pagefault.c"

void startCommandLine(string str) {
    if(compareString(str, "help")) {
        printColour("\nHelp page\n", BLACK_GREY);
        printColour("=========\n", BLACK_LIGHT_AQUA);

        /* Displays help page */
        printColour("help", BLACK_GREEN);
        printColour(" | ", BLACK_GREY);
        printColour("Displays this help page\n", BLACK_BLUE);

        /* Displays helloworld test */
        printColour("helloworld", BLACK_GREEN);
        printColour(" | ", BLACK_GREY);
        printColour("Displays hello world test output\n", BLACK_BLUE);

        /* Fires a pagefault */
        printColour("pagefault", BLACK_GREEN);
        printColour(" | ", BLACK_GREY);
        printColour("Creates a pagefault\n", BLACK_BLUE);

        /* Tests graphics driver */
        printColour("gfxtest", BLACK_GREEN);
        printColour(" | ", BLACK_GREY);
        printColour("Tests graphics\n", BLACK_BLUE);

        /* Displays roadmap */
        printColour("roadmap", BLACK_GREEN);
        printColour(" | ", BLACK_GREY);
        printColour("Displays roadmap\n", BLACK_BLUE);

        /* Clears the screen */
        printColour("clearscreen", BLACK_GREEN);
        printColour(" | ", BLACK_GREY);
        printColour("Clears the screen\n", BLACK_BLUE);

        /* Reboots the computer */
        printColour("reboot", BLACK_GREEN);
        printColour(" | ", BLACK_GREY);
        printColour("Reboots the system\n", BLACK_BLUE);
    } else if(compareString(str, "helloworld")) {
        print("\nHello world!");
    } else if(compareString(str, "pagefault")) {
        createPageFault();
    } else if(compareString(str, "reboot")) {
        reboot();
    } else if(compareString(str, "clearscreen")) {
        clearScreen();
    } else if(compareString(str, "roadmap")) {
        printColour("\n==== RoadMap ====\n", BLACK_LIGHT_BLUE);
        printColour("Add FAT32 and Ext2 filesystem support\n", BLACK_GREEN);
        printColour("Add C++ support\n", BLACK_GREEN);
        printColour("Add network drivers\n", BLACK_GREEN);
        printColour("Paging system", BLACK_GREEN);
    } else if(compareString(str, "gfxtest")) {
        printColour("\nThis is a work in progress and isn't fully fleshed out\n", BLACK_LIGHT_RED);
        printGfxTest();
    } else {
        printColour("\nThe command you entered is invalid, execute 'help' for help.\n", BLACK_LIGHT_RED);
    }
}

#endif
