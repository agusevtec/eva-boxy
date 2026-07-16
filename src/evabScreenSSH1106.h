#pragma once

#include <evabCoor.h>
#include <evabScreenPage8Base.h>
#include <Wire.h>

namespace evab
{
    class ScreenSSH1106 : public ScreenPage8Base
    {
    public:
        ScreenSSH1106(const IFont* font, unsigned long aWireClock = 800000L);
        unsigned short Serialize(const Coor &aPos, const Coor &aSize, bool isFocused);
        void Deserialize(unsigned short aSerialized, Coor &aPos, Coor &aSize, bool &isFocused);

    protected:
        void DrawVerticalSlice(Coor aPosition, unsigned char aSliceColumn, unsigned char aSlice) override;
        void ClearTile(Coor aPosition, unsigned char aColor) override;
        Coor Size() override;

    private:
        void clearDisplay();
        void sendCommand(unsigned char cmd);
        void setPage(unsigned char page);
        void setColumn(unsigned char col);

        uint8_t mAddress;
    };
}