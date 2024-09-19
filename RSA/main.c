#include<stdio.h>
#include"rsa.h"

void main(void){
    uint32_t  e , n ;
    generate_key(&e , &n);
    uint64_t  m[20] = {'H','e','l','l','o',' ', 'R' , 'S' ,'A',' ','E','n','c' ,'r','y','p' , 't' , 'i' , 'o' , 'n'};
    uint64_t  c[20];
    rsaEncryption(c ,  m , e , n);
    printf("\nmessage is\n");
    for(int i = 0 ; i < 20 ; i++){
        printf("%c",m[i]);
    }
    printf("\n\n\nencrypted message is\n");
    for(int i = 0 ; i < 20 ; i++){
        printf("%c",c[i]);
    }
}