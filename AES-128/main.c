/*
    main.c : for testing AES-128 bits
    Created on: Sep 15, 2024
    Author : Abdelrahman Ibrahim

*/


#include<stdio.h>

#include"aes.h"


int main(void){
     uint8_t key[] = {
		0xfd , 0xff , 0x56 , 0x3a , 0xae , 0x30 , 0x53 , 0x22 ,
        0xaa , 0xd2 , 0x96 , 0x10 , 0x43 , 0x35 , 0xaf , 0xee
	};

	uint8_t plaintext[] = {
		1, 2, 3, 4, 5, 6, 7, 8,
		9, 10, 11, 12, 13, 14, 15, 16,
	};

    uint8_t decryptedPlaintext[16];
    uint8_t ciphertext[16];

    uint8_t roundKey[11][16];

    printf("\n======================= test AES-128 Encryption and Decryption=======================\n");
    printf("\n\nplaintext before encryption : \n");
    for(int i = 0 ; i < 16 ; i++){
        printf("%X ",plaintext[i]);
    }
    keyscheduling(key , roundKey);
    aesEncryption(roundKey , plaintext , ciphertext);
    printf("\n\nplaintext after encryption : \n");
    for(int i = 0 ; i < 16 ; i++){
        printf("%X ",ciphertext[i]);
    }
   aesDecryption(roundKey , decryptedPlaintext , ciphertext);
   printf("\n\nplaintext after decryption : \n");
   for(int i = 0 ; i < 16 ; i++){
        printf("%X ",decryptedPlaintext[i]);
    }
}