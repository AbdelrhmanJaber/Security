#include"handshaking.h"


void main(void){
    signature_message_server_t message ;
    uint8_t helloMessage[16] = {'A','g','r','e','e' , 'C' , 'r' , 'y' , 'p' , 't' , 'o' , 'S' , '2','0' , '2' , '4'};
    servevrHello(helloMessage , &message);
    printf("\ntest encypted hash\n");
    for(uint8_t i = 0 ; i < 32 ; i++){
        printf("%x ",message.encrypted_hashed_message[i]);
    }
}