#include"Platform_Types.h"
#include"rsa.h"
#include"sha256.h"
#include<stdio.h>


/* * structure of digital signature message
   * the server should hash the message then encrypt using private key
   * the client should recieve data and decrypt it then compare the hash value
   * satisfy if the public key is right or not 
*/


typedef struct 
{
   uint64_t encrypted_hashed_message[32];
   uint8_t server_hello_message[16];
}signature_message_server_t;


typedef struct 
{
   uint64_t encrypted_hashed_message[32];
   uint8_t server_hello_message[16];
}signature_message_client_t;



void clientHello(uint8_t * clientMessage);

void servevrHello(uint8_t * serverMessage , signature_message_server_t  * message);

uint8_t clientCheckDigitalSignature(signature_message_server_t * server_message ,signature_message_client_t * client_message);