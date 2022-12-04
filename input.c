#include "input.h"
#include "morsecode.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFF_SIZE 2048
#define WHITESPACE_CHARS 7
#define CHAR_SPACE 3
#define CHAR_TO_INT 48

bool morseRepresentationBuffer[MAX_BUFF_SIZE] = {0};
int bufferPosition = 0;

void clearBuffer(){
    for(int i = 0; i<MAX_BUFF_SIZE;i++){
        morseRepresentationBuffer[i] = 0;
    }
}

int input_getInputFromUser(){
    bufferPosition = 0;
    clearBuffer();
    //prompt user input and do something with the result
    printf(">");
    char *buff = NULL;
    char* morseBits = NULL;

    size_t sizeAllocated = 0;
    size_t numCh = getline(&buff, &sizeAllocated, stdin);
    // Now use buff[] and it’s numCh characters.
    // You can ignore sizeAllocated.
    // ..<your code here>..

    
    if(buff[0] == '\n'){
        printf("exit\n");
        return 0;
    }else{
        
        for(int i = 0; i<numCh-1; i++){

            printf("i = %i\n",i);

            if(buff[i]==' '){
                printf("read whitespace \n");
                for(int j = 0; j<WHITESPACE_CHARS; j++){
                    morseRepresentationBuffer[bufferPosition] = false;
                    bufferPosition++;
                }

            }else{

                printf("read %c from buffer\n", buff[i]);
                morseBits = MorseCode_getFlashCode(buff[i]);
                size_t numBits = strlen(morseBits);
            
                for(int j = 0; j < numBits; j++){
                    morseRepresentationBuffer[bufferPosition] =  (morseBits[j] - CHAR_TO_INT);
                    bufferPosition++;
                }

                //add in 3 empty dots after a character
                for(int j = 0; j < CHAR_SPACE;j++){
                    morseRepresentationBuffer[bufferPosition] = 0;
                    bufferPosition++;
                }
                
            }
            
        }

    }
    // Cleanup from getline()
    free (buff);
    buff = NULL;

    return 1;
}

void input_printBuffer(){
    for(int i = 0; i < bufferPosition; i++){
        if(morseRepresentationBuffer[i] == 1){
            printf("X");
        }else{
            printf("_");
        }
        //only print 80 chars per line
        if(i%80 == 0 && i != 0){
            printf("\n");
        }
    }
    printf("\n");
}

