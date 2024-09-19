#include<stdio.h>
#include"rsa.h"

void main(void){
    uint32_t  e , n  , d;
    generate_key(&e , &n);
    uint64_t  m[16] = {'c','r','y','p','A','n', 'a' , 'l' ,'y','s','I','s','D' ,'u','m','p'};
    uint64_t  c[16];
    uint64_t original[16];
    printf("\nmessage is\n");
    for(int i = 0 ; i < 16 ; i++){
        printf("%c",m[i]);
    }
    
    rsaEncryption(c ,  m , e , n);
    printf("\n\n\nencrypted message is\n");
    for(int i = 0 ; i < 16 ; i++){
        printf("%c",c[i]);
    }

    generatePrivateKey(e , &d);
    rsadecryption(c , original , d , n);

    printf("\n\n\ndecrypted message is\n");
    for(int i = 0 ; i < 16 ; i++){
        printf("%c",original[i]);
    }
}