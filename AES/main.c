#include<stdio.h>

#include"aes.h"




int main(void){
     uint8_t key[] = {
		17 , 18 , 19 , 20 , 21 , 22 , 23 , 24 ,
        25 , 26 , 27 , 28 , 29 , 30 , 31 , 32
	};

	uint8_t plaintext[] = {
		1, 2, 3, 4, 5, 6, 7, 8,
		9, 10, 11, 12, 13, 14, 15, 16,
	};

    uint8_t ciphertext[16];

    uint8_t roundKey[11][16];
   keyscheduling(key , roundKey);
    aesEncryption(roundKey , plaintext , ciphertext);
    for(int i = 0 ; i < 16 ; i++){
        printf("%X ",ciphertext[i]);
    }
   
}