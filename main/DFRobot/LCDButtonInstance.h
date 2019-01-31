#pragma once

#include "../BinaryInput.h"
#include "LCDShield.h"

namespace DFRobot {
  class LCDButtonInstance : public BinaryInput {
   public:
    LCDButtonInstance(LCDShield &shield, LCDButton button) : _shield(shield), _button(button) {};

    virtual bool Get() override { return _shield.GetButton(_button); };

   private:
    LCDShield &_shield;
    LCDButton _button;
  };
} // ns DFRobot
