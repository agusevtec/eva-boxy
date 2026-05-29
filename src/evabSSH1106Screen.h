#pragma once

#include <evabCoor.h>
#include <evabPage8ScreenBase.h>
#include <Wire.h>

namespace evab
{
    class SSH1106Screen : public Page8ScreenBase
    {
    public:
        SSH1106Screen(const IFont* font);
        
        void clearDisplay();

    protected:
        void DrawVerticalSlice(Coor aPosition, unsigned char aSliceColumn, unsigned char aSlice) override;
        void ClearTile(Coor aPosition, unsigned char aColor) override;
        Coor Size() override;

    private:
        void sendCommand(unsigned char cmd);
        void setPage(unsigned char page);
        void setColumn(unsigned char col);

        uint8_t _address;
    };
}