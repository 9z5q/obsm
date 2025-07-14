#include "main.h"

VOID Seeds(DWORD i) {
	xs = i;
}

DWORD Xorshift(VOID) {
	xs ^= xs << 13;
	xs ^= xs >> 17;
	xs ^= xs << 5;
	return xs;
}