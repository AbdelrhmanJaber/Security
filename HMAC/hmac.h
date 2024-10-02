/*
    sha256.h : Hashing
    Created on: oct 3, 2024
    Author : Abdelrahman Ibrahim

*/

#ifndef HMAC_H
#define HMAC_H

#include"Platform_Types.h"
#include"sha256.h"

#define HMAC_BLOCK_SIZE            32 //32 Bytes --> 256 bits

 



void hmac(uint8_t * hmac_val , uint8_t * data , uint8_t data_length
 , uint8_t * key , uint8_t key_length);


#endif