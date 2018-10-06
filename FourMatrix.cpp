/*********************************************************************
 * 
 * The FourMatrix class simplify the use of 4 8x8 LEDs matrices in one
 * 16x16 panel. 
 * 
 * It uses the TrueBool type to store the LEDs state in the most 
 * efficient way, and Eberhard Fahle's LedControl library  
 * (http://wayoda.github.io/LedControl/) to control the matrices.
 * 
 *********************************************************************/

#include "FourMatrix.h"

/* Constructor: define pins and initialize the matrices */
FourMatrix::FourMatrix(int dataPinInit, int clockPinInit, int loadPinInit) {
  
  lc = LedControl(dataPinInit, clockPinInit, loadPinInit, 4);
  initMatrix();
}

void FourMatrix::initMatrix() {
  
  for (int i = 0; i < 4; i ++) {
    lc.shutdown(i, false); // Power saving off, activate chip
    lc.setIntensity(i, 4); // Luminosity to 1 (values 0~15)
    lc.clearDisplay(i); // Shutdown all LEDs
  }
}

/* Turn on/off a LED at the given coordinates */
void FourMatrix::setOneLED(int x, int y, bool onOff) {

  /* Adapt the coordinates according to the corresponding matrix */
  if (x >= 0 && x <= 7) {
    if (y >= 0 && y <= 7) {
      lc.setLed(1, x, y, onOff);
    } else if (y >= 8 && y <= 15) {
      lc.setLed(0, x, y - 8, onOff);
    }
  } else if (x >= 8 && x <= 15) {
    if (y >= 0 && y <= 7) {
      lc.setLed(2, 15 - x, 7 - y, onOff);
    } else if (y >= 8 && y <= 15) {
      lc.setLed(3, 15 - x, 15 - y, onOff);
    }
  }
}

/* Allows controlling multiple LEDs state by passing a TrueBool in argument */
void FourMatrix::setMultiLED(TrueBool screenArray) {
  
  for (int x = 0; x < 16; x++) {
    for (int y = 0; y < 16; y++) {
      setOneLED(x, y, screenArray.getBit(x, y));
    }
  }
}

/* Turn on/off all LEDs */
void FourMatrix::setAllLED(bool onOff) {
  
  for (int x = 0; x < 16; x++) {
    for (int y = 0; y < 16; y++) {
      setOneLED(x, y, onOff);
    }
  }
}

/* Draw a line from starting point to end point, in the given direction */
void FourMatrix::drawLine(lineDir dir, int lineNb, int begin, int end) {

  if((lineNb >= 0) && (lineNb < 16) && (begin >= 0) && (end < 16) && (begin < end)) {
    for (int point = begin; point <= end; point++) {
      if(dir == HORIZONTAL) {
		setOneLED(point, lineNb, true);
	  } else if (dir == VERTICAL) {
		setOneLED(lineNb, point, true);
      }
    }
  }
}

/* Draw a full line in the given direction */
void FourMatrix::drawFullLine(lineDir dir, int lineNb) {
 
  drawLine(dir, lineNb, 0, 15); 
  
}