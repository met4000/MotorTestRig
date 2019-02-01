#pragma once

#include "../Pin.h"

namespace DFRobot {
  enum LCDButton {
    btnNONE,
    btnRIGHT,
    btnUP,
    btnDOWN,
    btnLEFT,
    btnSELECT
  };

  enum LCDBoardVersion {
    v1_0,
    v1_1
  };

  class LCDShield {
  public:
    LCDShield(AnalogPin port, LCDBoardVersion boardVersion = v1_0) : _port(port.GetPort()), _version(boardVersion) {};

    int GetPort() { return _port; };
    LCDButton GetRawButton();
    bool GetButton(LCDButton button);

    LCDBoardVersion GetBoardVersion() { return _version; };

  private:
    int _port;
    LCDBoardVersion _version;
  };
} // ns DFRobot


DFRobot::LCDButton DFRobot::LCDShield::GetRawButton() {
  int analogKeyIn = analogRead(_port);

  if (analogKeyIn > 1000) return btnNONE;

  switch (_version) {
   case v1_0:
    if (analogKeyIn < 50)   return btnRIGHT;
    if (analogKeyIn < 195)  return btnUP;
    if (analogKeyIn < 380)  return btnDOWN;
    if (analogKeyIn < 555)  return btnLEFT;
    if (analogKeyIn < 790)  return btnSELECT;
    break;

   case v1_1:
    if (analogKeyIn < 50)   return btnRIGHT;
    if (analogKeyIn < 250)  return btnUP;
    if (analogKeyIn < 450)  return btnDOWN;
    if (analogKeyIn < 650)  return btnLEFT;
    if (analogKeyIn < 850)  return btnSELECT;
    break;
  }

  return btnNONE;
}

bool DFRobot::LCDShield::GetButton(DFRobot::LCDButton button) {
  return GetRawButton() == button;
}
