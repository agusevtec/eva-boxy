
#pragma once

#include <evabScreenBase.h>

namespace evab
{

    class ScreenSerialText : public ScreenBase
    {
    public:
        ScreenSerialText()
        {
            clear();
        }

        void clear()
        {
            for (unsigned char i = 0; i < 128; i++)
                mBuffer[i] = '.';
        }

        void printToSerial()
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

        Coor Size() override { return {16, 8}; }

    protected:
        void DrawSymbol(Coor aPosition, Coor aSize, char aCharcode, unsigned char aColor) override
        {
            if (aPosition.X < 16 && aPosition.Y < 8)
                mBuffer[aPosition.Y * 16 + aPosition.X] = aCharcode;
        }

    private:
        char mBuffer[128];
    };

}
