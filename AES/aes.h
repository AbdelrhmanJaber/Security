#include"Platform_Types.h"


#define AES_BLOCK_SIZE     16
#define KEY_ROUND          10


void subBytes(uint8_t * tempCipherText , uint8_t * cipherText);

uint8_t multiBy2(uint8_t elem);

void shiftRowEncryption(uint8_t * tempCipherText);

void shiftRowDecryption(uint8_t * tempCipherText);

void keyscheduling(uint8_t * key , uint8_t roundKey [11][16]);


void aesEncryption(uint8_t roundKey[11][16] , uint8_t * plaintext , uint8_t * ciphertext);