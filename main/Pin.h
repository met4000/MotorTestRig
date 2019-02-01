#pragma once


class Pin {
  public:
  Pin(int port) : _port(port) {};

  int GetPort() { return _port; };

  protected:
  int _port;
};

class AnalogPin : public Pin { using Pin::Pin; };
class DigitalPin : public Pin { using Pin::Pin; };
class RXPin : public DigitalPin { using DigitalPin::DigitalPin; };
class TXPin : public DigitalPin { using DigitalPin::DigitalPin; };
class PWMPin : public DigitalPin { using DigitalPin::DigitalPin; };

// Pin consts 
namespace pinmap {
  namespace ArduinoUno {
    // Digital Pins
    RXPin         Pin0(0);
    TXPin         Pin1(1);
    DigitalPin    Pin2(2);
    PWMPin        Pin3(3);
    DigitalPin    Pin4(4);
    PWMPin        Pin5(5);
    PWMPin        Pin6(6);
    DigitalPin    Pin7(7);
    DigitalPin    Pin8(8);
    PWMPin        Pin9(9);
    PWMPin        Pin10(10);
    PWMPin        Pin11(11);
    DigitalPin    Pin12(12);
    PWMPin        Pin13(13);

    // Analog Pins
    AnalogPin     PinA0(A0);
    AnalogPin     PinA1(A1);
    AnalogPin     PinA2(A2);
    AnalogPin     PinA3(A3);
    AnalogPin     PinA4(A4);
    AnalogPin     PinA5(A5);
  }
}
