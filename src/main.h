#pragma once
#include <Windows.h>
#include <stdio.h>
#include <stdint.h>
#pragma warning( disable:4996 );
DWORD xs;

BOOL encdecrypt(char* path, INT selection);
DWORD Xorshift(VOID);
VOID Seeds(DWORD i);