// Morse Code Encodings (from http://en.wikipedia.org/wiki/Morse_code)
//   Encoding created by Brian Fraser. Released under GPL.
//
// Encoding description:
// - msb to be output first, followed by 2nd msb... (left to right)
// - each bit gets one "dot" time.
// - "dashes" are encoded here as being 3 times as long as "dots". Therefore
//   a single dash will be the bits: 111.
// - ignore trailing 0's (once last 1 output, rest of 0's ignored).
// - Space between dashes and dots is one dot time, so is therefore encoded
//   as a 0 bit between two 1 bits.
//
// Example:
//   R = dot   dash   dot       -- Morse code
//     =  1  0 111  0  1        -- 1=LED on, 0=LED off
//     =  1011 101              -- Written together in groups of 4 bits.
//     =  1011 1010 0000 0000   -- Pad with 0's on right to make 16 bits long.
//     =  B    A    0    0      -- Convert to hex digits
//     = 0xBA00                 -- Full hex value (see value in table below)
//
// Between characters, must have 3-dot times (total) of off (0's) (not encoded here)
// Between words, must have 7-dot times (total) of off (0's) (not encoded here).
//

#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define WHITESPACE "0000000"


static char* morsecode_codes[] = {
		"10111",		// A 0xB80
		"111010101",	// B 0xEA80
		"11101011101",	// C 0xEBA0
		"1110101",		// D 0xEA00
		"1",			// E 0x8000
		"101011101", 	// F 0xAE80
		"111011101",	// G 0xEE80
		"1010101", 		// H 0xAA00
		"101", 			// I 0xA000
		"1011101110111",// J 0xBBB8
		"111010111",	// K 0xEB80
		"101110101",	// L 0xBA80
		"1110111",		// M 0xEE00
		"11101",		// N 0xE800
		"11101110111",	// O 0xEEE0
		"10111011101" ,	// P 0xBBA0
		"1110111010111",// Q 0xEEB8
		"1011101",		// R 0xBA00
		"10101",		// S 0xA800
		"111",			// T 0xE000
		"1010111",		// U 0xAE00
		"101010111",	// V 0xAB80 
		"101110111",	// W 0xBB80
		"11101010111",	// X 0xEAE0 
		"1110101110111",// Y 0xEBB8
		"11101110101"	// Z 0xEEA0
};

// Return the flash code based on the input character.
// Returns 0 if not a-z or A-Z.
//cannot take non-whitespace or alpha chars
char* MorseCode_getFlashCode(char ch)
{

	char* flashCode = malloc(15*sizeof(char));
	if(ch == ' '){
		return WHITESPACE;
	}
	// Convert to lower case:
	char upperCase = toupper(ch);

	// If valid letter, look it up in the array:
	if (ch >= 'A' && upperCase <= 'Z') {
		flashCode = morsecode_codes[upperCase - 'A'];
	}
	for(int i = 0; i < strlen(flashCode);i++){
		printf("flashcode: %c\n",flashCode[i]);
	}
	return flashCode;
}