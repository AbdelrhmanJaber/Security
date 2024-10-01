#include"handshaking.h"


/*
   * 1- client hello : tls version  , cryptoAlgo(RSA and AES) and hashing
   * 2- server hello : cryptoAgrement , session id and server's digital signature (hash the message then encrypt using private key)
   * 3- client check server's digital signature using server's public key
   * 4- key generation
   * 5- finish message from server and client
*/



void clientHello(uint8_t * clientMessage){
    /*this printf function will be replaced by the communication 
    protocol interface using in TLS*/
    printf("%s",clientMessage);
}

void servevrHello(uint8_t * serverMessage , signature_message_server_t  * message){
    uint64_t tempHash[32];
    uint8_t hashed_sever_message[32];
   /* for(uint8_t i = 0 ; i < 16 ; i++){
        printf("%c",serverMessage[i]);
    }*/
    for(uint8_t i = 0 ; i < 16 ; i++){
        message->server_hello_message[i] = serverMessage[i];
    }
    /*calculate the hash of the message*/
    sha256_block sha_block;
    sha256_init(&sha_block);
    sha256_update(&sha_block, (BYTE *)message->server_hello_message, 16);
    sha256_final(&sha_block, hashed_sever_message);

    for(uint8_t i = 0 ; i < 32 ; i++){
        tempHash[i] = hashed_sever_message[i];
    }

   /* encrypt the hash using RSA with private key*/
    uint32_t  e , n  , d;
    generate_key(&e , &n);
    generatePrivateKey(e , &d);
    rsaEncryption(message->encrypted_hashed_message ,  tempHash , d , n); //encrypt with the private key
}

uint8_t clientCheckDigitalSignature(signature_message_server_t * server_message ,signature_message_client_t * client_message){
    /*decrypt hash message with server public key and get the hash (suppose validation authority accept the puplic key)
    * calculate the hash of server message
    * compare the hashed value that decrypt with calculated one
    *  if the same value return 1 if not return 0
    */
   
}