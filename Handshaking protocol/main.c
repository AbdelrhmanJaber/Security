#include"handshaking.h"


void main(void){
    uint8_t flag = 0;

    uint8_t pre_master_key[48];
    uint8_t master_key[32];
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
}