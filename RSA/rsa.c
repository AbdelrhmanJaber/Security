#include"rsa.h"
#include<stdio.h>




// Function to initialize the PRNG with a seed
static void init_prng(PRNG *prng, uint32_t seed) {
    prng->seed = seed;
}

// Function to generate the next random number
static uint32_t next_prng_p_q(PRNG *prng ) {
    // Parameters for the LCG
    uint32_t a = 1664525; // Multiplier
    uint32_t c = 12345; // Increment
    uint32_t m = 2147483647; // Modulus (2^31 -1)

    prng->seed = (a * prng->seed + c) % m; // Update seed
    return prng->seed; // Return the generated random number
}

// Function to generate the next random number for public key in rsa
static uint32_t next_prng_e(PRNG *prng , uint32_t phi_n) {
    // Parameters for the LCG
    uint32_t a = 1664525; // Multiplier
    uint32_t c = 12345; // Increment
    uint32_t m = phi_n; // Modulus (phi_n)

    prng->seed = (a * prng->seed + c) % m; // Update seed
    return prng->seed; // Return the generated random number
}


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
        *p = next_prng_p_q(randomSeeds); //
        flag_p = checkPrime(*p);
    }
    while(!flag_q){
        *q = next_prng_p_q(randomSeeds);
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
    while (!flag_e)
    {
        *e = next_prng_e(&randonSeeds , phi_n);
        if(checkPrime(*e) == 1 && is_coprime(*e,phi_n)) flag_e = 1;
    }
}


void rsaEncryption(uint64_t * cipher , uint64_t * message , uint32_t e , uint32_t n){
    for(uint8_t i = 0 ; i < 16 ; i++){
        cipher[i] = modExp(message[i] , (uint64_t)e , (uint64_t)n);
    }
}




