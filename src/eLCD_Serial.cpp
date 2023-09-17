#include "eLCD_Serial.h"

eLCD_Serial::eLCD_Serial(PinName txPin, PinName rxPin, int baud) :
    MySerial(txPin, rxPin, baud)
{ } 

eLCD_Serial::~eLCD_Serial()
{ }

void eLCD_Serial::init()
{
    _base_putc(0xA0);
    ThisThread::sleep_for(100ms);
}

void eLCD_Serial::clear()
{
    _base_putc(0xA3);
    //ThisThread::sleep_for(100ms);
    _base_putc(0x01);
    ThisThread::sleep_for(100ms);
    
}

void eLCD_Serial::cursor(bool state)
{
    if(state)
    {
        _base_putc(0xA3);
        //ThisThread::sleep_for(100ms);
        _base_putc(0x0E);
        ThisThread::sleep_for(100ms);
    }
    else
    {
        _base_putc(0xA3);
        //ThisThread::sleep_for(100ms);
        _base_putc(0x0C);
        ThisThread::sleep_for(100ms);
    }
}

void eLCD_Serial::moveCursor(int x, int y)
{
    if(x>15)
    {
        x=15;
    }
    else if(x<0)
    {
        x=0;
    }
    if(y>1)
    {
        y=1;
    }
    else if(y<0)
    {
        y=0;
    }
    _base_putc(0xA1);
    //ThisThread::sleep_for(100ms);
    _base_putc(x);
    //ThisThread::sleep_for(100ms);
    _base_putc(y);
    ThisThread::sleep_for(100ms);
}

void eLCD_Serial::print(string text)
{
    _base_putc(0xA2);
    //ThisThread::sleep_for(100ms);
    for(int i=0;i<text.length();i++)
    {
        _base_putc(text[i]);
        
    }
    //ThisThread::sleep_for(100ms);
    _base_putc(0x00);
    ThisThread::sleep_for(100ms);
}

void eLCD_Serial::print(int number)
{   
    std::string text = std::to_string(number);
    _base_putc(0xA2);
    //ThisThread::sleep_for(100ms);
    for(int i=0;i<text.length();i++)
    {
        _base_putc(text[i]);
        
    }
    //ThisThread::sleep_for(100ms);
    _base_putc(0x00);
    ThisThread::sleep_for(100ms);
}