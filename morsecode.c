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
static unsigned short morsecode_codes[] = {
		0b10111,	// A 1011 1
		0b111010101,	// B 1110 1010 1
		0b11101011101,	// C 1110 1011 101
		0b1110101,	// D 1110 101
		0b1,	// E 1
		0b101011101, // F 1010 1110 1
		0b111011101,	// G 1110 1110 1
		0b101,	// I 101
		0b1011101110111,	// J 1011 1011 1011 1
		0b111010111,	// K 0xEB80
		0b101110101,	// L 0xBA80
		0b1110111,	// M 0xEE00
		0b11101,	// N 0xE800
		0b11101110111,	// O 0xEEE0
		0b10111011101 ,	// P 0xBBA0
		0b1110111010111, // Q 0xEEB8
		0b1011101,	// R 0xBA00
		0b10101,	// S 0xA800
		0b111 ,	// T 0xE000
		0b1010111,	// U 0xAE00
		0b101010111,	// V 0xAB80 
		0b101110111,	// W 0xBB80
		0b11101010111,	// X 0xEAE0 
		0b1110101110111,	// Y 0xEBB8
		0b11101110101	// Z 0xEEA0
};

// Return the flash code based on the input character.
// Returns 0 if not a-z or A-Z.
unsigned short MorseCode_getFlashCode(char ch)
{
	unsigned short flashCode = 0;

	// Convert to lower case:
	// Lower case has an extra bit (0x20) set. Remove that bit.
	ch &= ~(0b00100000); //0x20

	// If valid letter, look it up in the array:
	if (ch >= 'A' && ch <= 'Z') {
		flashCode = morsecode_codes[ch - 'A'];
	}
	
	return flashCode;
}