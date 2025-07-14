#include "main.h"

INT main()
{
    char file[] = "D:\\!Files\\Project\\C\\obsm\\x64\\Debug\\text.txt";

    Encrypt(file);
}

BOOL Encrypt(char* path) {

    INT c = 0;
    INT cc = 0;

    FILE* f = fopen(path, "r+");

    if (f == NULL) {
        printf("Doesn't exist %s", path);
        return FALSE;
    }

    INT* mem = malloc(1024 * sizeof(INT));
    if (!mem) {
        
        return FALSE;
    
    }

    while ((c = fgetc(f)) != EOF) {
        
        if (cc <= 1024) {
        
            INT* Nmem = realloc(mem, (cc + 1024) * sizeof(INT));
            if (!Nmem) {

                free(Nmem);
                return FALSE;

            }
            
            mem = Nmem;

        }

        mem[cc++] = (unsigned char)c;

    }

    fclose(f);

    for (int i = 0; i < cc; ++i) {
        printf("%02X ", mem[i]);
    }
    
    return TRUE;
}

UINT GenKey() {

    return 0;
}
