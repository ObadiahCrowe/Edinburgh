#ifndef STRING_H
#define STRING_H

#include "types.h"

void write_string( int colour, const char *string )
{
    volatile char *video = (volatile char*) 0xB8000;
    while(*string != 0)
    {
        *video++ = *string++;
        *video++ = colour;
    }
}

unint16 stringLength(string s) {
	unint16 i = 1;
	while (s[i++]);
	return --i;
}

bool compareString(string s1, string s2) {
	unint64 size = stringLength(s1);
	if (size != stringLength(s2)) {
		return false;
	} else {
		unint64 i = 0;
		for (i; i < size; i++) {
			if (s1[i] != s2[i]) {
				return false;
			}
		}
	}
}
#endif
