#include "BinaryInput.h"
#include "DFRobot/LCDButtonInstance.h"


using namespace DFRobot;


LCDShield *lcdShield;
BinaryInput *forwardButton;
BinaryInput *reverseButton;


void setup() {
  lcdShield = new LCDShield(0);

  forwardButton = new LCDButtonInstance(*lcdShield, btnUP);
  reverseButton = new LCDButtonInstance(*lcdShield, btnDOWN);
}

void loop() {}
