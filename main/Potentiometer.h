#pragma once

#include "Pin.h"
#include "DoubleInput.h"

class Potentiometer : public DoubleInput {
 public:
  Potentiometer(AnalogPin port, double maxv = 1024) : _port(port.GetPort()), _max(maxv) {};

  virtual double Get() override;

  int GetPort() { return _port; };
  double GetMax() { return _max; };

 protected:
  int _port = 0;
  double _max;
};

double Potentiometer::Get() {
  double value;

  value = analogRead(_port);
  value /= _max;

  return value;
}
