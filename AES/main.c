#include<stdio.h>

#include"aes.h"




int main(void){
     uint8_t key[] = {
		0x2b , 0x7e , 0x15 , 0x16 , 0x28 , 0xae , 0xd2 , 0xa6 ,
        0xab , 0xf7 , 0x15 , 0x88 , 0x09 , 0xcf , 0x4f , 0x3c
	};

	uint8_t plaintext[] = {
		0x87, 0xEC, 0x4A, 0x8C, 0xF2, 0x6E, 0xC3, 0xD8,
		0x4D, 0x4C, 0x46, 0x95, 0x97, 0x90, 0xE7, 0xA6,
	};

    uint8_t roundKey[11][16];
   keyscheduling(key , roundKey);

    printf("\nfirst column after round 0 (key) : \n");
    for (int i = 0; i < 16; i++)
    {
        /* code */
        printf("%X ",roundKey[0][i]);
    }

   printf("\nfirst column after round 1 : \n");
    for (int i = 0; i < 16; i++)
    {
        /* code */
        printf("%X ",roundKey[1][i]);
    }
    printf("\nfirst column after round 2 : \n");
    for (int i = 0; i < 16; i++)
    {
        /* code */
        printf("%X ",roundKey[2][i]);
    }
    printf("\nfirst column after round 3 : \n");
    for (int i = 0; i < 16; i++)
    {
        /* code */
        printf("%X ",roundKey[3][i]);
    }

    printf("\nfirst column after round 10 : \n");
    for (int i = 0; i < 16; i++)
    {
        /* code */
        printf("%X ",roundKey[10][i]);
    }
}