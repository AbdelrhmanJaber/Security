#ifndef RSA_H
#define RSA_H

#include"Platform_Types.h"
#include"prng.h"
#include<math.h>




void generate_key(uint32_t * e , uint32_t * n);

void rsaEncryption(uint64_t * cipher , uint64_t * message , uint32_t e , uint32_t n);

void generatePrivateKey(uint32_t e,uint32_t *d);

void rsadecryption(uint64_t * cipher , uint64_t * message , uint32_t d , uint32_t n);

#endif