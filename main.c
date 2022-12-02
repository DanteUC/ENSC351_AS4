#include "morsecode.h"
#include "matrix.h"
#include "input.h"
#include "sharedDataStruct.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool stopping = false;

int main (){
    //thread init
    printf("Beginning Morse Code!!\n");
    
    while(!stopping){
        char* morseString = getInputFromUser();
    }

    //thread cleanup
    return 0;
}