#include "curtinfrc/Pin.h"
#include "BinaryInput.h"
#include "DFRobot/LCDButtonInstance.h"

#define DEBUG (bool)1


using namespace curtinfrc;
using namespace curtinfrc::pinmap::ArduinoUno;
using namespace DFRobot;


LCDShield *lcdShield;
BinaryInput *forwardButton;
BinaryInput *reverseButton;


void setup() {
  #if DEBUG
  Serial.begin(9600);
  #endif

  lcdShield = new LCDShield(PinA0);

  forwardButton = new LCDButtonInstance(*lcdShield, btnUP);
  reverseButton = new LCDButtonInstance(*lcdShield, btnDOWN);
}

void loop() {
  #if DEBUG
  Serial.print("Forward Button: ");
  Serial.println(forwardButton->Get());
  Serial.print("Reverse Button: ");
  Serial.println(reverseButton->Get());
  Serial.println();
  #endif
}
