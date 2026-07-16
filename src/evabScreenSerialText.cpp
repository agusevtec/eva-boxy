#include <evabScreenSerialText.h>

using namespace evab;
#include <evabSerializers.h>

ScreenSerialText::ScreenSerialText()
{
    clear();
}

void ScreenSerialText::clear()
{
    for (unsigned char i = 0; i < 128; i++)
        mBuffer[i] = '.';
}

void ScreenSerialText::printToSerial()
{
    for (unsigned char y = 0; y < 8; y++)
    {
        for (unsigned char x = 0; x < 16; x++)
        {
            Serial.print(mBuffer[y * 16 + x]);
        }
        Serial.println();
    }
    Serial.println();
}

Coor ScreenSerialText::Size()
{
    return {16, 8};
}

void ScreenSerialText::DrawSymbol(Coor aPosition, Coor aSize, char aCharcode, unsigned char aColor)
{
    if (aPosition.X < 16 && aPosition.Y < 8)
        mBuffer[aPosition.Y * 16 + aPosition.X] = aCharcode;
}



unsigned short ScreenSerialText::Serialize(const Coor &aPos, const Coor &aSize, bool isFocused)
{
    return serialize_16x8(aPos, aSize, isFocused);
}

void ScreenSerialText::Deserialize(unsigned short aSerialized, Coor &aPos, Coor &aSize, bool &isFocused)
{
    deserialize_16x8(aSerialized, aPos, aSize, isFocused);
}
