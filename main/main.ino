#include <Math.h>

#include "Pin.h"

#include "BinaryInput.h"
#include "DoubleInput.h"
// #include "DFRobot/LCDButtonInstance.h"
#include "Button.h"
#include "Potentiometer.h"

#include "PWMController.h"


#define DEBUG true


using namespace pinmap::ArduinoUno;
// using namespace DFRobot;


// LCDShield *lcdShield;
BinaryInput *forwardButton;
BinaryInput *reverseButton;

DoubleInput *speedInput;

PWMController *motorController;


void setup() {
  #if DEBUG
  Serial.begin(9600);
  #endif

  // lcdShield = new LCDShield(PinA0);

  // forwardButton = new LCDButtonInstance(*lcdShield, btnUP);
  // reverseButton = new LCDButtonInstance(*lcdShield, btnDOWN);
  forwardButton = new Button(Pin13);
  reverseButton = new Button(Pin12);

  speedInput = new Potentiometer(PinA0);

  motorController = new PWMController(Pin9);
}

void loop() {
  #if DEBUG
  Serial.print("Forward Button: ");
  Serial.println(forwardButton->Get());
  Serial.print("Reverse Button: ");
  Serial.println(reverseButton->Get());
  #endif

  double power = speedInput->Get();
  power *= fabs(power);

  #if DEBUG
  Serial.print("Speed: ");
  Serial.println(power);
  #endif

  if (forwardButton->Get()) motorController->Set(power);
  else if (reverseButton->Get()) motorController->Set(-power);
  else motorController->Set(0);

  #if DEBUG
  Serial.println();
  #endif
}
