#include "main.h"

VOID Readfile(char* path) {

    INT c = 0;

    FILE* f = fopen(path, "rb");

    if (f == NULL) {

        return;

    }

    mem = malloc(1024 * sizeof(INT));

    if (!mem) {

        fclose(f);
        return;

    }

    while ((c = fgetc(f)) != EOF) {

        if (cc >= 1024) {

            INT* Nmem = realloc(mem, (cc + 1024) * sizeof(INT));
            if (!Nmem) {

                free(Nmem);
                return;

            }

            mem = Nmem;

        }

        mem[cc++] = (unsigned char)c;

    }
    fclose(f);
}