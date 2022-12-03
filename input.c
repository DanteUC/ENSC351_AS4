#include "input.h"
#include "morsecode.h"
#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#define MAX_BUFF_SIZE 2048
#define WHITESPACE_CHARS 7

bool morseRepresentationBuffer[MAX_BUFF_SIZE]={0};


void clearBuffer(){
    for(int i = 0; i<MAX_BUFF_SIZE;i++){
        morseRepresentationBuffer[i] = 0;
    }
}

void input_getInputFromUser(){
    int bufferPosition = 0;
    clearBuffer();
    //prompt user input and do something with the result
    printf(">\n");
    char *buff = NULL;

    size_t sizeAllocated = 0;
    size_t numCh = getline(&buff, &sizeAllocated, stdin);
    // Now use buff[] and it’s numCh characters.
    // You can ignore sizeAllocated.
    // ..<your code here>..

    printf("numCh value: %i\n", numCh);
    if(buff[0] == '\n'){
        printf("exit\n");
        //stopping = true;
    }else{
        int i = 0;
        while(buff[i] != '\n'){

            printf("i = %i\n",i);

            if(buff[i]==' '){
                printf("read whitespace \n");
                for(int j = 0; j<WHITESPACE_CHARS; j++){
                    morseRepresentationBuffer[bufferPosition] = false;
                    bufferPosition++;
                }

            }else{

                printf("read %c from buffer\n", buff[i]);
                char* morseBits = MorseCode_getFlashCode(buff[i]);
                size_t numBits = strlen(morseBits);
            
                
                for(int j = 0; j < numBits; j++){
                    printf("inserting %i into position %i\n",morseBits[j],bufferPosition);
                    morseRepresentationBuffer[bufferPosition] = morseBits[j];
                    
                    bufferPosition++;
                }
                
                free(morseBits);
            }
            i++;
        }

    }
    // Cleanup from getline()
    free (buff);
    buff = NULL;
}

void input_printBuffer(){
    for(int i = 0; i<MAX_BUFF_SIZE;i++){
        if(morseRepresentationBuffer[i] == 1){
            printf("X");
        }else{
            printf("_");
        }
        //only print 40 chars per line
        if(i%40 == 0){
            printf("\n");
        }
    }
}

