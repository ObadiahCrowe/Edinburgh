#ifndef COMMANDS_H
#define COMMANDS_H

#include "../lib/string.h"
#include "../lib/types.h"
#include "../kernel/drivers/power.h"
#include "../kernel/drivers/video/video.h"

void startCommandLine(string str) {
  print("[");
  print(str);
  print(" + ");
  unint64 i;
  for(i = 0; i < stringLength(str); i++) {
    print(".");
  }
  print("]\n");
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
  } else if(compareString(str, "helloworld")) {
    print("\nHello world!");
  } else {
    printColour("\nThe command you entered is invalid, execute 'help' for help.\n", BLACK_LIGHT_RED);
  }
}

#endif
