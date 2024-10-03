#include"handshaking.h"


void main(void){
    uint8_t flag = 0;
    uint8_t pre_master_key[48];
    uint8_t master_key[32];
    uint8_t session_keys[SESION_KEYS_NUMBERS][SESSION_KEY_SIZE];
    signature_message_server_t message ;
    signature_message_client_t clientMessage;
    client_hello_t client_hello;

    client_hello.sessionID = 25;
    clientHello(&client_hello);

    uint8_t helloMessage[16] = {'A','g','r','e','e' , 'C' , 'r' , 'y' , 'p' , 't' , 'o' , 'v' , 'e','r' , '2' , '5'};
    servevrHello(helloMessage , &message);
    flag = clientCheckDigitalSignature(&message , &clientMessage);
    if(flag == 1) printf("\n\nsignature is right\nverification is done correctly\n\n");
    else printf("\nNot done\n");
    generatePreMasterKey(pre_master_key);
    generateMasterKey(pre_master_key , client_hello.client_random , master_key);
    generateSessionKeys(master_key , message.server_random , session_keys);
    /*test print session keys*/
    printf("\n\ntest print client mac session key :\n");
    for(uint8_t i = 0 ; i < 16 ; i++){
        printf("%c",session_keys[CLIENT_MAC_SESSION_KEY][i]);
    }
    printf("\n\ntest print server mac session key :\n");
    for(uint8_t i = 0 ; i < 16 ; i++){
        printf("%c",session_keys[SERVER_MAC_SESSION_KEY][i]);
    }
    printf("\n\ntest print client AES session key :\n");
    for(uint8_t i = 0 ; i < 16 ; i++){
        printf("%c",session_keys[CLIENT_AES_SESSION_KEY][i]);
    }
    printf("\n\ntest print server aes session key :\n");
    for(uint8_t i = 0 ; i < 16 ; i++){
        printf("%c",session_keys[SERVER_AES_SESSION_KEY][i]);
    }
}