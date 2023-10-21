#ifndef eLCD_Serial_h
#define eLCD_Serial_h

#include "mbed.h"

#define DISPLAY_SIZE_X 16
#define DISPLAY_SIZE_Y 2 

class MySerial :
    public SerialBase
{
public:
    MySerial(PinName txPin, PinName rxPin, int baud) :
    SerialBase(txPin, rxPin, baud)
    { }

    using SerialBase::_base_putc;
};

class eLCD_Serial
    : public MySerial
{
public:
    eLCD_Serial(PinName txPin, PinName rxPin=NC, int baud=19200);
    ~eLCD_Serial();

    void init();
    void clear();
    void cursor(bool state);
    void moveCursor(int x, int y);
    void print(string text);
    void print(int number);
    void scroll(int number);
};



#endif