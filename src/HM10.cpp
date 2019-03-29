#include "HM10.h"

HM10::HM10(uint8_t TX, uint8_t RX) : BTserial(TX,RX)
{
    BTserial.begin(9600);
    data.reserve(20);
}

void HM10::readData()
{
    while (BTserial.available())
    {
        char character = BTserial.read();
        if (character == ']' && dataRead == true)
        {
            dataRead = false;
            bufferIsEmpty = false;
        }
        if(dataRead == true) 
            data.concat(character);
        if(character == '[' && bufferIsEmpty)
            dataRead = true;
    }
}

void HM10::clearBuffer()
{
    data.remove(0);
    bufferIsEmpty = true;
}

bool HM10::bufferEmpty()
{
    return bufferIsEmpty;
}
