#pragma once
#include <Windows.h>
#include <stdio.h>
#include <stdint.h>
#include <bcrypt.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>
#include "Chacha20.h"
#pragma warning( disable:4996 )
#pragma comment(lib, "bcrypt.lib")
VOID Readfile(char* path);
VOID Encrypt(FILE* stream);
VOID Decrypt(FILE* stream);

#pragma region public
INT num;
INT num2;
extern INT* mem;
extern INT cc;
uint8_t key[32];
uint8_t nonce[12];
#pragma endregion