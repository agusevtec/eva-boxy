#pragma once

#include <evabScreenPage8Base.h>
#include <evabIFont.h>

namespace evab
{
    class ScreenSerialPixel: public ScreenPage8Base
    {
    public:
        ScreenSerialPixel(IFont *aFont) : ScreenPage8Base(aFont)
        {
            clear();
        }

        void clear()
        {
            for (unsigned int i = 0; i < 1024; i++)
                mBuffer[i] = 0x00;
        }

        void printToSerial()
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

        Coor Size() override { return {16, 8}; }

    protected:
        void DrawVerticalSlice(Coor aPosition, unsigned char aSliceColumn, unsigned char aSlice) override
        {
            unsigned char x = aPosition.X * 8 + aSliceColumn;
            unsigned char page = aPosition.Y;

            if (x < 128 && page < 8)
                mBuffer[page * 128 + x] = aSlice;
        }

    private:
        uint8_t mBuffer[1024]; // 8 страниц * 128 байт = 1024 байта
    };

}
