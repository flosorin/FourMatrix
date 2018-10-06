#include <FourMatrix.h>
#include <TrueBool.h>

/* Pins used by the MAX7219 controlling the 4 matrices */
#define PIN_DATA_IN 10
#define PIN_CLK 9
#define PIN_LOAD 8

/* MAX7219 control provided by the library */
FourMatrix screen = FourMatrix(PIN_DATA_IN, PIN_CLK, PIN_LOAD);

void setup() {
  
  TrueBool leds1 = TrueBool(), leds2 = TrueBool();

  delay(1000);
  
  /* Flash all LEDs on screen */
  screen.setAllLED(true);
  delay(1000);
  screen.setAllLED(false);
  
  delay(1000);

  /* Flash a specific LED */
  screen.setOneLED(4, 8, true); 
  delay(1000);
  screen.setOneLED(4, 8, false);

  delay(1000);

  /* Control multiple LEDs */
  leds1.setBit(8, 4, true);
  leds2.setBit(8, 12, true);
  screen.setMultiLED(leds1 | leds2);

  delay(1000);

  /* Draw lines */
  screen.setAllLED(false);
  screen.drawLine(HORIZONTAL, 4, 4, 12);
  screen.drawLine(HORIZONTAL, 8, 6, 10);
  screen.drawLine(HORIZONTAL, 12, 4, 12);

  delay(1000);

  /* Draw all vertical lines */
  screen.setAllLED(false);
  for(int line = 0; line < 16; line++) {
    screen.drawFullLine(VERTICAL, line);
    delay(100);
  }
}

void loop() {

}
