#pragma once

#include "Pin.h"
#include "../FRCmotor/FRCmotor.h"

namespace curtinfrc {
  class PWMController : public FRCmotor {
   public:
    PWMController(PWMPin port) : FRCmotor(port.GetPort()) {};
  };
}
