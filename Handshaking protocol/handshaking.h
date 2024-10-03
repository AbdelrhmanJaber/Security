/*
    handshaking.h 
    Created on: oct 3, 2024
    Author : Abdelrahman Ibrahim

*/

#ifndef HANDSHAKING_H
#define HANDSHAKING_H

#include"Platform_Types.h"
#include"rsa.h"
#include"sha256.h"
#include"hmac.h"
#include<stdio.h>


/* * structure of digital signature message
   * the server should hash the message then encrypt using private key
   * the client should recieve data and decrypt it then compare the hash value
   * satisfy if the public key is right or not 
*/


#define SERVER_RANDOM_NUMBERS     2
#define CLIENT_RANDOM_NUMBERS     2


#define SESION_KEYS_NUMBERS       4
#define SESSION_KEY_SIZE          16 //BYTES


#define CLIENT_MAC_SESSION_KEY    0
#define SERVER_MAC_SESSION_KEY    1
#define CLIENT_AES_SESSION_KEY    2
#define SERVER_AES_SESSION_KEY    3

typedef struct{
   uint8_t client_random[16];
   uint8_t sessionID;
}client_hello_t;


typedef struct 
{
   uint64_t encrypted_hashed_message[32];
   uint8_t server_hello_message[16];
   uint8_t server_random[16];
}signature_message_server_t;


typedef struct 
{
   uint64_t decrypted_hashed_message[32];
   uint8_t server_hello_message[16];
}signature_message_client_t;



void clientHello(client_hello_t * client_hello_mes);

void servevrHello(uint8_t * serverMessage , signature_message_server_t  * server_hello_mes);

uint8_t clientCheckDigitalSignature(signature_message_server_t * server_message ,signature_message_client_t * client_message);

void generatePreMasterKey(uint8_t pre_master_key[48]);

void generateMasterKey(uint8_t pre_master_key[48] , uint8_t random_key[16] , uint8_t master_key[HMAC_BLOCK_SIZE]);


void generateSessionKeys(uint8_t master_key[HMAC_BLOCK_SIZE] , uint8_t random_seed[16] ,
 uint8_t session_keys[SESION_KEYS_NUMBERS][SESSION_KEY_SIZE]);

#endif