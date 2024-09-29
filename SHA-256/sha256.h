/*
    sha256.h : Hashing
    Created on: Sep 29, 2024
    Author : Abdelrahman Ibrahim

*/

#ifndef SHA256_H
#define SHA256_H

#include"Platform_Types.h"


#define HASH_BLOCK_SIZE     32 //32-bit word (word = 4 Bytes => 256 bit)

typedef uint8_t       BYTE;             
typedef uint32_t      WORD;            

typedef struct {
	BYTE data[64]; 
	WORD datalen;
	uint64_t bitlen;
	WORD state[8];
} sha256_block;


void sha256_init(sha256_block *sha_block);


void sha256_update(sha256_block *sha_block, const BYTE data[], uint32_t len);


void sha256_final(sha256_block *sha_block, BYTE hash[]);


#endif