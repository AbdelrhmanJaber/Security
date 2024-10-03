#include"prng.h"
#include<stdio.h>


// Function to initialize the PRNG with a seed
void init_prng(PRNG *prng, uint32_t seed) {
    prng->seed = seed;
}

// Function to generate general random number with modulo 16
uint32_t next_prng(PRNG *prng, uint32_t modulo) {
    // Parameters for the LCG
    uint32_t a = 1664525; // Multiplier
    uint32_t c = 12345;   // Increment
    // Update seed
    prng->seed = (a * prng->seed + c) % modulo; 
    return prng->seed; 
}
// Function to generate the next random number for public key in rsa
uint32_t next_prng_e(PRNG *prng , uint32_t phi_n) {
    // Parameters for the LCG
    uint32_t a = 1664525; // Multiplier
    uint32_t c = 12345; // Increment
    prng->seed = (a * prng->seed + c) % phi_n; // Update seed
    return prng->seed; 
}
