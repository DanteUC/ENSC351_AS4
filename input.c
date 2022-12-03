#include "input.h"
#include "morsecode.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_BUFF_SIZE 2048
#define WHITESPACE_CHARS 7

bool morseRepresentationBuffer[MAX_BUFF_SIZE]={0};
int charsWritten = 0;

void input_getInputFromUser(){
    int bufferPosition = 0;
    //prompt user input and do something with the result
    printf(">\n");
    char *buff = NULL;
    for(int i = 0; i< MAX_BUFF_SIZE;i++){

    }
    size_t sizeAllocated = 0;
    size_t numCh = getline(&buff, &sizeAllocated, stdin);
    // Now use buff[] and it’s numCh characters.
    // You can ignore sizeAllocated.
    // ..<your code here>..
    
    if(buff[0] == '\n'){
        //exit = true;
    }else{
        // read the line and do morse stuff 

        //while not end of buffer
        for(int i = 0; i<numCh; i++){

            if(buff[i]==' '){
                for(int j = 0;j<WHITESPACE_CHARS;j++){
                    morseRepresentationBuffer[bufferPosition] = false;
                    bufferPosition++;
                }
            }else{
                char* morseBits = MorseCode_getFlashCode(buff[i]);
                size_t numBits = strlen(morseBits);
                for(int j=0; i< numBits; i++){
                    morseRepresentationBuffer[bufferPosition] = morseBits[j];
                    bufferPosition++;
                }
            }
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
        //only print 20 chars per line
        if(i%40 == 0){
            printf("\n");
        }
    }
}