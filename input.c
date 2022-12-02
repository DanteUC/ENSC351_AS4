#include "input.h"
#include "morsecode.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INVALID_CHAR

char* getInputFromUser(){
    //prompt user input and do something with the result
        printf(">\n");
        char *buff = NULL;
        size_t sizeAllocated = 0;
        size_t numCh = getline(&buff, &sizeAllocated, stdin);
        // Now use buff[] and it’s numCh characters.
        // You can ignore sizeAllocated.
        // ..<your code here>..
            
        if(buff[0] == "\n"){
            exit == true;
        }else{
            // read the line and do morse stuff 
            int i = 0;
            while(buff[i]!= '\n'){
                if(buff[i]==' '){
                    //insert 7 0s into stream
                }else{
                    unsigned short morseBits = MorseCode_getFlashCode(buff[i]);
                    //insert the morsebits into stream
                    //how to store unsigned shorts back to back in one stream and read char by char?
                }
                
            }
        }
        // Cleanup from getline()
        free (buff);
        buff = NULL;
}