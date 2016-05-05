#ifndef COMMANDS_H
#define COMMANDS_H

#include "../lib/string.h"
#include "../lib/types.h"
#include "../kernel/drivers/power.h"
#include "../kernel/drivers/video/video.h"

void startCommandLine(string str) {
  if(compareString(str, "help")) {
    printColour("Help page", BLACK_GREY);
  } else if(compareString(str, "helloword")) {
    print("\nHello World");
  } else if(compareString(str, "helloworld")) {
    print("\nHello world!");
  } else {
    printColour("\nThe command you entered is invalid, execute 'help' for help.\n", BLACK_LIGHT_RED);
  }
}

#endif
