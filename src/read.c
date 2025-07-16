#include "main.h"

VOID NewReadFile(char* path) {

    INT c = 0;

    FILE* f = fopen(path, "rb");

    if (!f) {

        perror("error:");
        return;

    }

    fseek(f, 0, SEEK_END);
    LONG size = ftell(f);
    rewind(f);

    mem = malloc(size * sizeof(unsigned char));

    if (!mem) {

        fclose(f);
        perror("mem error");
        return;

    }

    cc = (INT)fread(mem, 1, size, f);
    fclose(f);
    return;

}