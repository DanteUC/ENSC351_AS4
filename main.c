#include "morsecode.h"
#include "matrix.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main (){

    _Bool stopping = false;

    //thread init
    
    printf("Beginning Morse Code!!\n");
    
    while(!stopping){
        if(input_getInputFromUser()) {
            input_printBuffer();
        }
        else {
            stopping = true;
        }
        
    }
    
    //thread cleanup
    return 0;
}