#include "main.h"

#pragma region public
INT* mem = NULL;
INT cc = 0;
#pragma endregion

INT main(INT argc, char* argv[])
{
    INT num;
    INT num2;

    if (argc < 2) {
        printf("plz set file bro");
        return;
    }

    printf("Enter 0 or 1.\n0:Encrypt file\n1:Decrypt file(you need to put key and nonce on same dir)\n>>");

    scanf_s("%d", &num);

    NewReadFile(argv[1]);

    FILE* out = (num == 0) ? fopen("enc", "wb") : fopen("decrypted", "wb");

    if (!out) {

        free(mem);
        return;

    }

    if (num == 0) {

        printf("Delete source file? (0/1)\n>>");

        scanf_s("%d", &num2);

        if (num2 == 0) {

            remove(argv[1]);

        }

        Encrypt(out);

    }
    else if (num == 1) {

        Decrypt(out);

    }

}