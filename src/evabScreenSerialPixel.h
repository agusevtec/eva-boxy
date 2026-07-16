#pragma once

#include <evabScreenPage8Base.h>
#include <evabIFont.h>

namespace evab
{
    class ScreenSerialPixel : public ScreenPage8Base
    {
    public:
        ScreenSerialPixel(IFont *aFont);

        void clear();
        void printToSerial();

        Coor Size() override;
        unsigned short Serialize(const Coor &aPos, const Coor &aSize, bool isFocused);
        void Deserialize(unsigned short aSerialized, Coor &aPos, Coor &aSize, bool &isFocused);

    protected:
        void DrawVerticalSlice(Coor aPosition, unsigned char aSliceColumn, unsigned char aSlice) override;

    private:
        uint8_t mBuffer[1024]; // 8 страниц * 128 байт = 1024 байта
    };
}