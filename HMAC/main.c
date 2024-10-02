#include"hmac.h"
#include<stdio.h>
#include<string.h>


void main(void){
    uint8_t hmac_val[32];
    uint8_t *data = "Hello world";
    uint8_t *key = "private key For Hash Mac";
    hmac(hmac_val , data , strlen(data) , key , strlen(key));
    for(uint8_t i = 0 ; i < 32 ; i++){
        printf("%x",hmac_val[i]);
    }
}