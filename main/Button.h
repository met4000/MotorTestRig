#pragma once

#include <Arduino.h>
#include "Pin.h"
#include "BinaryInput.h"

class Button : public BinaryInput {
 public:
  Button(DigitalPin port);

  int GetPort() { return _port; };
  virtual bool Get() override;

 protected:
  int _port;
};

Button::Button(DigitalPin port) : _port(port.GetPort()) {
  pinMode(_port, INPUT);
  digitalWrite(_port, HIGH);
}

bool Button::Get() {
  return !digitalRead(_port);
}
