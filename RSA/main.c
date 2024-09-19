#include<stdio.h>
#include"rsa.h"

void main(void){
    uint32_t  e ;
    generatePublicKey(53 , 59 , &e);
    printf("e is = %d",e);
}