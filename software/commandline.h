#ifndef COMMANDS_H
#define COMMANDS_H

#include "../lib/string.h"
#include "../lib/types.h"
#include "../kernel/drivers/video/video.h"
#include "../kernel/drivers/video/colours.h"

void startCommandLine(string str) {
  if(compareString(str, "help")) {
    printColour("\nList of commands:\n", BLACK_GREY);
    printColour("help - Displays the help page (this)\n", BLACK_GREEN);
    printColour("helloworld - Says hello world\n", BLACK_GREEN);
  } else if(compareString(str, "helloworld")) {
    clearScreen();
    printColour("Hello, world\n", BLACK_GREY);
  } else {
    printColour("\nThis command is invalid, execute 'help' for help\n", BLACK_LIGHT_RED);
  }
}

#endif
