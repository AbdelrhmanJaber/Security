#include <stdio.h>
#include <string.h>
#include "sha256.h"

int main() {
    sha256_block sha_block;
    sha256_init(&sha_block);

    const char input[] = "test hashing";
    sha256_update(&sha_block, (BYTE *)input, strlen(input));

    BYTE hash[32];
    sha256_final(&sha_block, hash);

    printf("SHA-256 hash of '%s': \n", input);
    for (int i = 0; i < 32; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}
