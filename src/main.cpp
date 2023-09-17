#include "mbed.h"
#include "eLCD_Serial.h"

eLCD_Serial LCD(D1);
string test="Score :";

int main()
{
    LCD.init();
    LCD.clear();
    LCD.cursor(false);
    LCD.moveCursor(0,0);
    LCD.print(test);
    LCD.moveCursor(test.length(),0);
    LCD.print(12345);

}
