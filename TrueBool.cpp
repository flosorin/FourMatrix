/*********************************************************************
 * 
 * The TrueBool type is an array of 16 16-bit words.
 * 
 * It allows using "real" booleans (i.e. with a size of one bit)
 * to store the state of the LEDs on the 16x16 LED matrices panel.
 * 
 *********************************************************************/
 
#include "TrueBool.h"

/* Constructor */
TrueBool::TrueBool() {

}

/* Copy constructor */
TrueBool::TrueBool(const TrueBool &tb) {
   for(int x = 0; x < 16; x++) {
    for (int y = 0; y < 16; y++) {
      setBit(x, y, tb.getBit(x, y));
    }
  }
}

/* Return the requested boolean */
bool TrueBool::getBit (int arrayPos, int wordPos) {
  return bitRead(realBool[arrayPos], wordPos);
}

/* Set the requested boolean */
void TrueBool::setBit (int arrayPos, int wordPos, bool value) {
  bitWrite(realBool[arrayPos], wordPos, value);
}

/* Define operator | for the TrueBool type */
TrueBool operator| (TrueBool boolA, TrueBool boolB) {
  
  TrueBool boolC = TrueBool();
  
  for(int x = 0; x < 16; x++) {
    for (int y = 0; y < 16; y++) {
      boolC.setBit(x, y, (boolA.getBit(x, y) | boolB.getBit(x, y)));
    }
  }

  return boolC;
}

/* Define operator == for the TrueBool type */
bool operator== (TrueBool boolA, TrueBool boolB) {
  
  for(int x = 0; x < 16; x++) {
    for (int y = 0; y < 16; y++) {
      if(boolA.getBit(x, y) != boolB.getBit(x, y)) {
        return false;
      }
    }
  }

  return true;
}
