#ifndef STRING_H
#define STRING_H

#include "types.h"

unint64 stringLength(string s) {
	unint64 i = 1;
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
	return true;
}
#endif
