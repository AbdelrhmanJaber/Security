#include"Platform_Types.h"
#include<math.h>


typedef enum{
    OK,
    NOT_PRIME_NUMBER
}RSA_STATUS_t;


uint8_t checkPrime(uint32_t n);

RSA_STATUS_t generatePublicKey(uint32_t p , uint32_t q , uint32_t * e);