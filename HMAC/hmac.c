/*
    sha256.h : Hashing
    Created on: oct 2, 2024
    Author : Abdelrahman Ibrahim

*/

#include"hmac.h"


#define I_PAD 0x36
#define O_PAD 0x5C




void hmac(uint8_t * hmac_val , uint8_t * data , uint8_t data_length
 , uint8_t * key , uint8_t key_length){
        sha256_block sha_block;
        uint8_t padded_key[64];
        /*check if key size is bigger than 64 bytes
        then hash it using sha256 to force it into 32 bytes*/
        if(key_length > 64){
            uint8_t tempKey[HMAC_BLOCK_SIZE];
            sha256_init(&sha_block);
            sha256_update(&sha_block , key , key_length);
            sha256_final(&sha_block , tempKey);
            key_length = HMAC_BLOCK_SIZE;
            key = tempKey;
        }
        /*make inner padding*/
        for(uint8_t i = 0 ; i < key_length ; i++){
            padded_key[i] = I_PAD ^ key[i];
        }
        for(uint8_t i = key_length ; i < 64 ; i++){
            padded_key[i] = I_PAD ^ 0;
        }
        /*make hashing for padded key and the data together*/
        sha256_init(&sha_block);
        sha256_update(&sha_block , padded_key , 64);
        sha256_update(&sha_block , data , data_length);
        sha256_final(&sha_block , hmac_val);

        /*make outer padding*/
        for(uint8_t i = 0 ; i < key_length ; i++){
            padded_key[i] = O_PAD ^ key[i];
        }
        for(uint8_t i = key_length ; i < 64 ; i++){
            padded_key[i] = O_PAD ^ 0;
        }

        /*make hashing for outer padded key and result of inner padded hashing together*/
        sha256_init(&sha_block);
        sha256_update(&sha_block , padded_key , 64);
        sha256_update(&sha_block , hmac_val , HMAC_BLOCK_SIZE);
        sha256_final(&sha_block , hmac_val);
 }