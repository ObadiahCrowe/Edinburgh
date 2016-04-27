#include "../../lib/string.h"
#include "../../lib/types.h"
#include "../../drivers/keyboard.h"

void kernel_main(void)
{
	write_string(12, "Hello World");
}
