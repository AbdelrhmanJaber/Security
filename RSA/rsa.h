#include"Platform_Types.h"
#include<math.h>


typedef struct {
    uint32_t seed; // Seed for the PRNG
}PRNG;


#define INIT_SEEDS   12345

void generate_key(uint32_t * e , uint32_t * n);

void rsaEncryption(uint64_t * cipher , uint64_t * message , uint32_t e , uint32_t n);

void generatePrivateKey(uint32_t e,uint32_t *d);

void rsadecryption(uint64_t * cipher , uint64_t * message , uint32_t d , uint32_t n);