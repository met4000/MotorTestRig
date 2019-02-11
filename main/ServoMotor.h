#pragma once

#include <Servo.h>

#include "Pin.h"

class ServoMotor { // ServoMotor instead of Servo to resolve naming conflict
 public:
  ServoMotor(DigitalPin port) : _port(port.GetPort()), _servo() { _servo.attach(_port); };

  int GetPort() { return _port; };
  // void Set();
  void SetAngle(int angle);
  double GetAngle(); // The angle the servo is currently set to, not the actual servo angle

 private:
  Servo _servo;
  int _port;
};

void ServoMotor::SetAngle(int angle) {
  if (angle < 0) angle = 0;
  if (angle > 180) angle = 180;

  _servo.write(angle);
}

double ServoMotor::GetAngle() {
  return _servo.read();
}
