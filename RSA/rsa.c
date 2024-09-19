#include"rsa.h"
#include<stdio.h>


static uint32_t gcd(uint32_t  e , uint32_t  phi_n){
     uint32_t temp ;
    while (1)
    {
       temp = e % phi_n;
        if(temp == 0) break;
        e = phi_n ;
        phi_n = temp;
    }
    return phi_n;
}


uint8_t checkPrime(uint32_t n){
    uint8_t flag = 1;
    if(n <= 1) flag = 0;
    else{
        for(uint32_t i = 2 ; i <= sqrt(n) ; i++){
            if(n%i == 0){
                flag = 0;
                break;
            } 
        }
    }
    return flag;
}


static RSA_STATUS_t generate_phi_n(uint32_t p , uint32_t q , uint32_t * phi_n){
    RSA_STATUS_t status ;
    /*check if p , q prime*/
    if(checkPrime(p) && checkPrime(q)){
        status = OK;
        *(phi_n) = (p-1) * (q-1);
    }else{
        status = NOT_PRIME_NUMBER;
    }
    return status;   
}


RSA_STATUS_t generatePublicKey(uint32_t p , uint32_t q , uint32_t * e){
    RSA_STATUS_t status = OK ;
    uint32_t  phi_n;
    status = generate_phi_n(p , q , &phi_n);
    if(status == OK){
        for(*e = 2 ; *e < (phi_n) ; (*e) = (*e)+3){
            if(gcd(*e , phi_n)){
                *e = gcd(*e, phi_n);
                break;
            } 
        }
    }
    return status;
}