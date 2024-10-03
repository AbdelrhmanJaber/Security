#ifndef PRNG_H
#define PRNG_H

#include"Platform_Types.h"

typedef struct {
    uint32_t seed; // Seed for the PRNG
}PRNG;


#define INIT_SEEDS        12345
#define CLIENT_INIT_SEED  4569876
#define SERVER_INIT_SEED  7961452
#define PRE_MASTER_SEED   4563127 


#define MODULO_8         255
#define MODULO_16        65535
#define MODULO_32        4294967295

void init_prng(PRNG *prng, uint32_t seed);

uint32_t next_prng(PRNG *prng , uint32_t modulo);

uint32_t next_prng_e(PRNG *prng , uint32_t phi_n); 

#endif