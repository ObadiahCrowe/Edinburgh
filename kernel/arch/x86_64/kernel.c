#include "../../../lib/string.h"
#include "../../../lib/types.h"
#include "../../drivers/keyboard.h"
#include "../../drivers/power.h"
#include "../../drivers/video/video.h"

void kernel_main(void)
{
	write_string(12, "Hello World");
}
