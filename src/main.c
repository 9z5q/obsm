#include "main.h"

int main(int argc, char* argv[])
{
    Seeds((DWORD)__rdtsc());

    encdecrypt(argv[1],1);

    getchar();
}

BOOL encdecrypt(char* path, INT selection) {

    INT c = 0;
    INT cc = 0;

    FILE* f = fopen(path, "rb");

    if (f == NULL) {
        return FALSE;
    }

    INT* mem = malloc(1024 * sizeof(INT));
    if (!mem) {
        
        return FALSE;
    
    }

    while ((c = fgetc(f)) != EOF) {
        
        if (cc >= 1024) {
        
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

    FILE* o = NULL;
    if (selection == 0) {
        o = fopen("enc", "wb"); 
    }
    else {
        o = fopen("decrypted", "wb"); 
    }


    if (!o) {

        free(mem);
        return 0;

    }

    UINT32 key;
    
    switch (selection) {

        case 0:

            key = Xorshift();

            printf("%u", key);

            for (INT x = 0; x < cc; x++) {

                UINT hashed = mem[x] ^ key;

                fputc((unsigned char)hashed, o);
            }

            break;

        case 1:
            scanf_s("%u", &key);
            
            UINT tobyte = key & 0xFF;

            for (INT x = 0; x < cc; x++) {

                UINT Dec = mem[x] ^ tobyte;

                fputc((unsigned char)Dec, o);
            }

            break;

        default:

            break;

    }

    fclose(o);
    free(mem);
    
    return TRUE;
}