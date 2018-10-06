/*********************************************************************

   The FourMatrix class simplify the use of 4 LEDs matrices in one
   16x16 panel.

   It uses the TrueBool type to store the LEDs state in the most
   efficient way, and Eberhard Fahle's LedControl library
   (http://wayoda.github.io/LedControl/) to control the matrices.

 *********************************************************************/

#ifndef FOUR_MATRIX_H
#define FOUR_MATRIX_H

#include "Arduino.h"
#include "TrueBool.h"
#include <LedControl.h>

typedef enum {HORIZONTAL, VERTICAL} lineDir;

class FourMatrix {

public:
  FourMatrix(int dataPinInit, int clockPinInit, int loadPinInit); // Constructor: define pins and initialize the matrices
  void setOneLED(int x, int y, bool onOff); // Turn on/off a LED at the given coordinates
  void setMultiLED(TrueBool screenArray); // Allows controlling multiple LEDs state by passing a TrueBool in argument
  void setAllLED(bool onOff); // Turn on/off all LEDs
  void drawLine(lineDir dir, int lineNb, int begin, int end); // Draw a line from starting point to end point, in the given direction
  void drawFullLine(lineDir dir, int lineNb); // Draw a full line in the given direction

private :
  LedControl lc = LedControl(13, 12, 11, 4); // Matrices control given by the library
  void initMatrix();
};

#endif // FOUR_MATRIX_H
