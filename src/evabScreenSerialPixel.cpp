#include <evabScreenSerialPixel.h>
#include <evabSerializers.h>

using namespace evab;

    ScreenSerialPixel::ScreenSerialPixel(IFont *aFont) 
        : ScreenPage8Base(aFont)
    {
        clear();
    }

    void ScreenSerialPixel::clear()
    {
        for (unsigned int i = 0; i < 1024; i++)
            mBuffer[i] = 0x00;
    }

    void ScreenSerialPixel::printToSerial()
    {
        for (unsigned char page = 0; page < 8; page++)
        {
            for (unsigned char y = 0; y < 8; y++)
            {
                for (unsigned char x = 0; x < 128; x++)
                {
                    unsigned int idx = page * 128 + x;
                    unsigned char bit = (mBuffer[idx] >> y) & 1;
                    Serial.print(bit ? '#' : '.');
                }
                Serial.println();
            }
        }
    }

    Coor ScreenSerialPixel::Size()
    { 
        return {16, 8}; 
    }

    void ScreenSerialPixel::DrawVerticalSlice(Coor aPosition, unsigned char aSliceColumn, unsigned char aSlice)
    {
        unsigned char x = aPosition.X * 8 + aSliceColumn;
        unsigned char page = aPosition.Y;

        if (x < 128 && page < 8)
            mBuffer[page * 128 + x] = aSlice;
    }


unsigned short ScreenSerialPixel::Serialize(const Coor &aPos, const Coor &aSize, bool isFocused)
{
    return serialize_16x8(aPos, aSize, isFocused);
}

void ScreenSerialPixel::Deserialize(unsigned short aSerialized, Coor &aPos, Coor &aSize, bool &isFocused)
{
    deserialize_16x8(aSerialized, aPos, aSize, isFocused);
}