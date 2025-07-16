#include "main.h"

VOID Encrypt(FILE* stream) {

	(VOID)BCryptGenRandom(NULL, key, sizeof(key), BCRYPT_USE_SYSTEM_PREFERRED_RNG);
	(VOID)BCryptGenRandom(NULL, nonce, sizeof(nonce), BCRYPT_USE_SYSTEM_PREFERRED_RNG);

	FILE* CreateKey = fopen("key", "wb");
	FILE* CreateNonce = fopen("nonce", "wb");

	if (!CreateKey || !CreateNonce) {

		free(mem);
		return;

	}

	fwrite(key, 1, sizeof(key), CreateKey);
	fwrite(nonce, 1, sizeof(nonce), CreateNonce);
	fclose(CreateKey);
	fclose(CreateNonce);

	struct chacha20_context ctx;

	chacha20_init_context(&ctx, key, nonce, 0);
	chacha20_xor(&ctx, (UINT8*)mem, cc);

	fwrite(mem, 1, cc, stream);

	fclose(stream);
	return;

}

VOID Decrypt(FILE* stream) {

	FILE* keyfile = fopen("key", "rb");
	FILE* noncefile = fopen("nonce", "rb");

	if (!keyfile || !noncefile) {

		free(mem);
		return;

	}

	fread(key, 1, sizeof(key), keyfile);
	fread(nonce, 1, sizeof(nonce), noncefile);
	fclose(noncefile);
	fclose(keyfile);

	struct chacha20_context ctx;

	chacha20_init_context(&ctx, key, nonce, 0);
	chacha20_xor(&ctx, (UINT8*)mem, cc);

	fwrite(mem, 1, cc, stream);

	fclose(stream);

}