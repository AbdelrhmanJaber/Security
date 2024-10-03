#include"rsa.h"
#include<stdio.h>


uint32_t global_phi_n = 0;


//Function to check if the number prime or not

static uint8_t checkPrime(uint32_t n){
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


//function for generate prime random numbers to generate e

static void generate_P_Q_for_key(uint32_t * p , uint32_t * q , PRNG * randomSeeds){
    uint8_t flag_p = 0 , flag_q = 0;
    while(!flag_p){
        *p = next_prng(randomSeeds , MODULO_16); //
        flag_p = checkPrime(*p);
    }
    while(!flag_q){
        *q = next_prng(randomSeeds , MODULO_16);
        flag_q = checkPrime(*q);
    }
}


//Function to calculate the greatest common divisor

static uint32_t gcd(uint32_t a, uint32_t b) {
    uint32_t temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


//Function to check if e co prime of phi_n or noe
static uint8_t is_coprime(uint32_t e, uint32_t phi_n) {
    return gcd(e, phi_n) == 1;
}


/*
    base --> message
    exp --> e (puplic key)
    mod --> n 
*/

uint64_t modExp(uint64_t base, uint64_t exp, uint64_t mod) {
    uint64_t result = 1;
    base = base % mod;
    
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1; 
        base = (base * base) % mod;
    }
    
    return result;
}


//Function to generate public key (e) for RSA

void generate_key(uint32_t * e , uint32_t * n){
    uint8_t flag_e = 0;
    uint32_t p ,q , phi_n ;
    PRNG  randonSeeds;
    init_prng(&randonSeeds , INIT_SEEDS);
    generate_P_Q_for_key(&p , &q , &randonSeeds);
    *n = p * q;
    phi_n = (p-1) * (q-1);
    global_phi_n = phi_n;
    while (!flag_e)
    {
        *e = next_prng_e(&randonSeeds , phi_n);
        if(checkPrime(*e) == 1 && is_coprime(*e,phi_n)) flag_e = 1;
    }
}


void rsaEncryption(uint64_t * cipher , uint64_t * message , uint32_t e , uint32_t n){
    for(uint8_t i = 0 ; i < 32 ; i++){
        cipher[i] = modExp(message[i] , (uint64_t)e , (uint64_t)n);
    }
}


static uint32_t extendedGCD(uint32_t a, uint32_t b, uint32_t *x, uint32_t *y) {
    uint32_t x0 = 1, y0 = 0; 
    uint32_t x1 = 0, y1 = 1; 
    uint32_t gcd;

    while (b != 0) {
        uint32_t quotient = a / b;

        uint32_t temp = b;
        b = a % b;
        a = temp;

        temp = x0;
        x0 = x1;
        x1 = temp - quotient * x1;

        temp = y0;
        y0 = y1;
        y1 = temp - quotient * y1;
    }

    *x = x0;
    *y = y0;
    return a; 
}

static uint32_t modInverse(uint32_t a, uint32_t m) {
    uint32_t x, y;
    uint32_t gcd = extendedGCD(a, m, &x, &y);

    if (gcd != 1) {
        return 0; // Inverse doesn't exist
    }

    return (x % m + m) % m; // Ensure the result is positive
}


/*generte privte key d for decryption*/

void generatePrivateKey(uint32_t e,uint32_t *d) {
    *d = modInverse(e, global_phi_n);
}

/*decrypt the data*/
void rsadecryption(uint64_t * cipher , uint64_t * message , uint32_t d , uint32_t n){
    for(uint8_t i = 0 ; i < 32 ; i++){
        message[i] = modExp(cipher[i] , (uint64_t)d , (uint64_t)n);
    }
}




