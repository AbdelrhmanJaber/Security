/*
    aes.h : with Key-128 bits
    Created on: Sep 15, 2024
    Author : Abdelrahman Ibrahim

*/


#include"Platform_Types.h"


#define AES_BLOCK_SIZE      16
#define KEY_ROUNDS          10


void keyscheduling(uint8_t * key , uint8_t roundKey [11][16]);

void aesEncryption(uint8_t roundKey[11][16] , uint8_t * plaintext , uint8_t * ciphertext);

void aesDecryption(uint8_t roundKey[11][16] , uint8_t * plaintext , uint8_t * ciphertext);