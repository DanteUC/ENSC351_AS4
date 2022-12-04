//This module handles user input for the morse code program for ENSC 351 

#ifndef INPUT_H
#define INPUT_H
#include <stdbool.h>

//calls getline to get a message from user and returns a char array 
//of its morse code equivilent as X and _
int input_getInputFromUser();
void input_printBuffer();

#endif