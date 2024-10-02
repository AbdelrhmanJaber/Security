#include"handshaking.h"


void main(void){
    uint8_t flag = 0;
    signature_message_server_t message ;
    signature_message_client_t clientMessage;
    uint8_t helloMessage[16] = {'A','g','r','e','e' , 'C' , 'r' , 'y' , 'p' , 't' , 'o' , 'S' , '2','0' , '2' , '4'};
    servevrHello(helloMessage , &message);
    flag = clientCheckDigitalSignature(&message , &clientMessage);
    if(flag == 1) printf("\ndone\n");
    else printf("\nNot done\n");
}