/*********************************************************************
 * 
 * The TrueBool type is an array of 16 16-bit words.
 * 
 * It allows using "real" booleans (i.e. with a size of one bit)
 * to store the state of the LEDs on the 16x16 LED matrices panel.
 * 
 *********************************************************************/

#ifndef TRUE_BOOL_H
#define TRUE_BOOL_H

#include "Arduino.h"

class TrueBool {

public:
    TrueBool(); // Constructor
    TrueBool(const TrueBool &tb); // Copy constructor
    bool getBit (int arrayPos, int wordPos); // Return the requested boolean
	void setBit (int arrayPos, int wordPos, bool value); // Set the requested boolean
    friend TrueBool operator| (TrueBool boolA, TrueBool boolB); // Define operator | for the TrueBool type
    friend bool operator== (TrueBool boolA, TrueBool boolB); // Define operator == for the TrueBool type

private :
    word realBool[16] = {0};
};

#endif // TRUE_BOOL_H
